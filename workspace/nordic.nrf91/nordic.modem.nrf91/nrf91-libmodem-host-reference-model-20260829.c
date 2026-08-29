/*
 * nRF91 / nRF9151 MODEM HOST REFERENCE MODEL
 * ===========================================
 *
 * Date: 2026-08-29
 * Status: change-control reference / semantic reconstruction
 *
 * PURPOSE
 * -------
 * This is a C-like semantic reconstruction of the host-side behavior needed
 * to reproduce the Nordic nRF91 libmodem path exercised by the current UDP
 * reference workload:
 *
 *   - modem startup / shared-memory handshake
 *   - RPC transport
 *   - ordered modem->host RX dispatch
 *   - AT initialization and AT request/response traffic
 *   - IPv4 UDP socket()
 *   - connect()
 *   - SO_RAI / RAI_LAST handling
 *   - connected 20-byte send()
 *   - close / shutdown-relevant machinery
 *   - the NCS LTE-link-control AT sequence used by the reference workload
 *
 * ORACLE
 * ------
 * Reconstructed from the linked Zephyr ELF/disassembly and symbol/map files
 * for the NCS 3.0.2 nRF9120 soft-float libmodem build used in this project,
 * plus live shared-memory / Ozone observations already captured against that
 * same reference.
 *
 * THIS IS NOT NORDIC SOURCE CODE.
 * -------------------------------
 * Original source spelling, private typedef names, macro names, comments,
 * compiler-elided branches, and some host-only structure field names cannot
 * be recovered exactly from a binary.  This file intentionally uses readable
 * reconstructed names.  The goal is executable semantics and modem-visible
 * behavior, not textual source recovery.
 *
 * CONFIDENCE TAGS
 * ---------------
 * [P] PROVEN     direct disassembly and/or matching live observation.
 * [H] HIGH       strong semantic reconstruction from disassembly.
 * [I] INFERRED   readable abstraction where exact original C form is lost.
 * [O] OUTSIDE    behavior beyond the host boundary; closed modem firmware.
 *
 * IMPORTANT STOP CONDITION
 * ------------------------
 * For the fixed workload above, this model is intended to replace further
 * assembly-level exploration.  Anything that remains after reproducing this
 * model is either:
 *
 *   (1) an implementation mismatch against this reference,
 *   (2) runtime/timing state that can be compared at the shared-memory boundary,
 *   (3) NCS application-layer behavior above libmodem, or
 *   (4) closed-modem behavior below the RPC boundary.
 *
 * No BSD/ZVFS compatibility layer is required by the modem protocol itself.
 */


#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


/* =========================================================================
 * 1. FIXED MEMORY / IPC CONTRACT
 * =========================================================================
 */

/* [P] Shared-memory layout in the working Zephyr image. */
#define SHM_CTRL_ADDR       0x20008000u
#define SHM_CTRL_SIZE       0x000004E8u

#define SHM_TX_ADDR         0x200084E8u
#define SHM_TX_SIZE         0x00002000u

#define SHM_PAD_ADDR        0x2000A4E8u
#define SHM_PAD_SIZE        0x00000080u

#define SHM_RX_ADDR         0x2000A568u
#define SHM_RX_SIZE         0x00002000u

#define SHM_END_ADDR        0x2000C568u

/* [P] CTRL sub-layout. */
#define CTRL_HOST_OFF       0x000u
#define CTRL_MODEM_OFF      0x020u
#define CTRL_LIST_A_OFF     0x060u
#define CTRL_LIST_B_OFF     0x0A4u
#define CTRL_MSGS_A_OFF     0x0E8u
#define CTRL_MSGS_B_OFF     0x2E8u

#define CTRL_VERSION        0x00010000u
#define RPC_DESC_COUNT      8u
#define RPC_MSG_BYTES       0x40u
#define RPC_MSG_WORDS       16u

/*
 * [P] Descriptor state is low 8 bits.
 *
 * Allocation/send lifecycle:
 *   FREE(3) -> ALLOC(0) -> BUSY(1)
 *
 * Modem completion changes host-TX descriptor BUSY -> ALLOC.
 * Host allocator/free bookkeeping later returns ALLOC -> FREE.
 *
 * The upper 16 bits carry the transport sequence number once sent.
 */
enum {
    DESC_ALLOC = 0,
    DESC_BUSY  = 1,
    DESC_DONE  = 2, /* observed historically; not the steady data-TX return state */
    DESC_FREE  = 3
};

typedef struct {
    volatile uint32_t state_seq; /* high16 = sequence, low8 = state */
    volatile uint32_t msg_ptr;
} RpcDesc;

/* [P] Two 8-entry lists, each 4-byte count + 8*8 bytes = 0x44. */
typedef struct {
    volatile uint32_t count;
    RpcDesc desc[RPC_DESC_COUNT];
} RpcList;

/*
 * [P] Host header first six words are known exactly.
 * Remaining words exist in the 0x20-byte header but are not required by the
 * fixed workload and are represented as reserved.
 */
typedef struct {
    volatile uint32_t version;       /* +0x00 = 0x00010000 */
    volatile uint32_t data_base;     /* +0x04 = RX base */
    volatile uint32_t data_size;     /* +0x08 = 0x2000 */
    volatile uint32_t list_a;        /* +0x0C */
    volatile uint32_t list_b;        /* +0x10 */
    volatile uint32_t modem_hdr;     /* +0x14 */
    volatile uint32_t reserved18;
    volatile uint32_t reserved1c;
} HostHdr;

/*
 * [P] First three modem-header words after STARTN:
 *   state = 1
 *   ptr0  = 0x2000A568
 *   ptr1  = 0x2000A5EC
 *
 * ptr0/ptr1 designate modem-owned incoming RPC list structures.
 */
typedef struct {
    volatile uint32_t state;
    volatile uint32_t ptr0;
    volatile uint32_t ptr1;
    volatile uint32_t reserved[13];
} ModemHdr;

typedef struct {
    HostHdr host;                    /* +0x000 */
    ModemHdr modem;                  /* +0x020 */
    RpcList list_a;                  /* +0x060 */
    RpcList list_b;                  /* +0x0A4 */
    uint8_t msgs_a[8][RPC_MSG_BYTES];/* +0x0E8 */
    uint8_t msgs_b[8][RPC_MSG_BYTES];/* +0x2E8 */
} CtrlArea;


/* =========================================================================
 * 2. REGISTER-LEVEL MODEM STARTUP CONTRACT
 * =========================================================================
 */

/*
 * [P] These are semantic register operations, not literal C declarations.
 *
 * POWER_NS + 0x68 = 1
 *   pre-init command, followed by ~200 us delay
 *
 * POWER_NS + 0x6C = 1
 *   post-platform-init command
 *
 * STARTN at POWER LTEMODEM task
 *
 * Do not invent symbolic names for +0x68 / +0x6C if the device headers/SVD
 * do not define them.
 */
#define POWER_NS_BASE          0x40005000u
#define POWER_PREP_ADDR        (POWER_NS_BASE + 0x68u)
#define POWER_POST_ADDR        (POWER_NS_BASE + 0x6Cu)

/* [P] IPC routing. */
enum {
    IPC_SEND_CTRL = 1, /* TASKS_SEND[1] */
    IPC_SEND_RPC  = 3, /* TASKS_SEND[3] */
    IPC_SEND_MISC = 5
};

enum {
    IPC_RECV_0 = 0,
    IPC_RECV_STARTUP = 2,
    IPC_RECV_RPC = 4,
    IPC_RECV_6 = 6,
    IPC_RECV_7 = 7
};

/*
 * [P]
 * SEND_CNF[1] = 0x02
 * SEND_CNF[3] = 0x08
 * SEND_CNF[5] = 0x20
 *
 * RECEIVE_CNF[0] = 0x01
 * RECEIVE_CNF[2] = 0x04
 * RECEIVE_CNF[4] = 0x10
 * RECEIVE_CNF[6] = 0x40
 * RECEIVE_CNF[7] = 0x80
 *
 * INTENSET = 0xD5
 * GPMEM0   = 0x20008000
 * GPMEM1   = 0 initially
 */


/* =========================================================================
 * 3. TRANSPORT GLOBAL STATE
 * =========================================================================
 */

/*
 * [P] There are TWO independent 16-bit sequence domains:
 *
 *   tx_sequence_num
 *       one global outgoing sequence shared by DATA and CONTROL TX.
 *
 *   expected_rx_sequence_num
 *       one global incoming sequence shared across modem ptr1 and ptr0 lists.
 *
 * In the inspected ELF, expected_rx_sequence_num and tx_sequence_num are
 * adjacent 16-bit globals (observed around 0x2000DE88 / 0x2000DE8A).
 */
static uint16_t expected_rx_sequence_num;
static uint16_t tx_sequence_num;

/*
 * [I] Zephyr/libmodem maintains pointer globals for:
 *   host list A + message pool A
 *   host list B + message pool B
 *   modem ptr0
 *   modem ptr1
 *
 * This reference uses direct pointers instead.
 */
static CtrlArea *const CTRL = (CtrlArea *)SHM_CTRL_ADDR;


/* =========================================================================
 * 4. GENERIC 64-BYTE RPC MESSAGE VIEW
 * =========================================================================
 */

/*
 * [H] Many RPC objects are generated as a small internal wrapper whose public
 * RPC words begin after wrapper metadata.  For this model we expose the modem-
 * visible 64-byte payload directly as 16 words.
 */
typedef struct {
    volatile uint32_t w[RPC_MSG_WORDS];
} RpcMsg;


/* =========================================================================
 * 5. TRANSPORT ALLOCATOR
 * =========================================================================
 */

/*
 * [P] rpc_transport_ipc_msg_alloc(list, msg_pool)
 *
 * Scans descriptors in order.
 * Claims low-byte FREE(3) -> ALLOC(0) atomically.
 * Clears exactly 0x40 bytes of the corresponding message.
 * Stores message pointer into the descriptor.
 * Returns message pointer, or NULL if none free.
 */
static RpcMsg *transport_msg_alloc(RpcList *list, RpcMsg *msg_pool)
{
    for (uint32_t i = 0; i < list->count; ++i) {
        uint32_t s = list->desc[i].state_seq;

        if ((s & 0xFFu) != DESC_FREE)
            continue;

        /* Atomic compare/exchange in real libmodem. */
        list->desc[i].state_seq = (s & 0xFFFFFF00u) | DESC_ALLOC;

        RpcMsg *m = &msg_pool[i];
        memset((void *)m, 0, RPC_MSG_BYTES);
        list->desc[i].msg_ptr = (uint32_t)(uintptr_t)m;
        return m;
    }

    return NULL;
}


/* =========================================================================
 * 6. OUTGOING DATA-RPC SEND
 * =========================================================================
 */

/*
 * [P] rpc_transport_ipc_data_msg_send(msg)
 *
 * Exact semantics from disassembly:
 *   1. msg word at +4: replace low byte with 2
 *   2. derive descriptor index from message address
 *   3. atomically fetch-and-increment global tx_sequence_num
 *   4. preserve descriptor low16, place old sequence in high16
 *   5. change descriptor low state byte to BUSY
 *   6. busywait 3 us
 *   7. TASKS_SEND[3] = 1
 *
 * The same sequence_num is used by control sends.
 */
static void transport_data_send(RpcList *list, RpcMsg *pool, RpcMsg *msg)
{
    msg->w[1] = (msg->w[1] & 0xFFFFFF00u) | 2u;

    uint32_t idx = (uint32_t)(msg - pool);
    uint16_t seq = tx_sequence_num++;
    uint32_t s = list->desc[idx].state_seq;

    s = (s & 0x0000FFFFu) | ((uint32_t)seq << 16);
    list->desc[idx].state_seq = s;

    s = list->desc[idx].state_seq;
    s = (s & 0xFFFFFF00u) | DESC_BUSY;
    list->desc[idx].state_seq = s;

    /* busywait_us(3); */
    /* IPC.TASKS_SEND[IPC_SEND_RPC] = 1; */
}


/* =========================================================================
 * 7. OUTGOING CONTROL-RPC SEND
 * =========================================================================
 */

/*
 * [P] rpc_transport_ipc_ctrl_msg_send(msg)
 *
 * Same transport sequence machinery as data send, except:
 *   msg->w[1] low byte = 1
 *   TASKS_SEND[1] = 1
 */
static void transport_ctrl_send(RpcList *list, RpcMsg *pool, RpcMsg *msg)
{
    msg->w[1] = (msg->w[1] & 0xFFFFFF00u) | 1u;

    uint32_t idx = (uint32_t)(msg - pool);
    uint16_t seq = tx_sequence_num++;
    uint32_t s = list->desc[idx].state_seq;

    s = (s & 0x0000FFFFu) | ((uint32_t)seq << 16);
    list->desc[idx].state_seq = s;

    s = list->desc[idx].state_seq;
    s = (s & 0xFFFFFF00u) | DESC_BUSY;
    list->desc[idx].state_seq = s;

    /* busywait_us(3); */
    /* IPC.TASKS_SEND[IPC_SEND_CTRL] = 1; */
}


/* =========================================================================
 * 8. MODEM->HOST ORDERED RX DISPATCH
 * =========================================================================
 */

/*
 * [P] This is one of the most important transport rules.
 *
 * rpc_message_handler():
 *
 *     for (;;) {
 *         while (handle_modem_rpc_msg(ptr1, 2))
 *             ;
 *
 *         if (handle_modem_rpc_msg(ptr0, 1))
 *             continue;
 *
 *         break;
 *     }
 *
 * Therefore:
 *   - ptr1 is tried first
 *   - ptr0 is tried second
 *   - both share the SAME expected_rx_sequence_num
 *   - after consuming anything from ptr0, ptr1 gets priority again
 */

/*
 * [P] Incoming descriptor eligibility:
 *   low state byte must be BUSY
 *   descriptor high16 must equal expected_rx_sequence_num
 *
 * After message processing:
 *   state = (old_state & 0xFFFFFF00) | FREE
 *   expected_rx_sequence_num++
 *
 * Sequence history is preserved in the descriptor.
 */


/* =========================================================================
 * 9. MODEM->HOST CONTROL MESSAGES
 * =========================================================================
 */

/*
 * [P] rpc_handle_ctrl_message(msg, type)
 *
 * type comes from high16(msg->w[0]).
 *
 * Relevant behavior:
 *
 *   type == 1:
 *       no action
 *
 *   type == 2:
 *       if (msg->w[2] != 0)
 *           nrf_modem_os_shm_tx_free((void *)msg->w[2]);
 *
 *   type == 4:
 *       no action in this build/path
 *
 * default:
 *       same effective path as type 2 in the compact compiled switch,
 *       but only known protocol values should be generated/accepted.
 *
 * Crucial point:
 * nrf_modem_os_shm_tx_free() is HOST-ONLY k_heap_free() bookkeeping.
 * It sends no RPC and changes no modem-visible register.
 */
static void handle_ctrl_message(RpcMsg *msg)
{
    uint16_t type = (uint16_t)(msg->w[0] >> 16);

    if (type == 1)
        return;

    if (type == 2) {
        void *p = (void *)(uintptr_t)msg->w[2];
        if (p != NULL) {
            /* host_shared_tx_heap_free(p); */
        }
        return;
    }

    if (type == 4)
        return;
}


/* =========================================================================
 * 10. HOST->MODEM RX-DATA-FREE CONTROL MESSAGE
 * =========================================================================
 */

/*
 * [P] When the modem supplies RX payload memory to the host (AT data, socket
 * receive data, etc.), the host returns ownership with:
 *
 *   list_a / msgs_a
 *   w0 = 0x00020001
 *   w1 = 1 after transport framing
 *   w2 = modem RX-data pointer
 *   descriptor sequence = next GLOBAL tx_sequence_num
 *   descriptor state = BUSY
 *   busywait 3 us
 *   IPC SEND1
 */
static void modem_rx_data_free(uint32_t modem_rx_ptr)
{
    RpcList *list = &CTRL->list_a;
    RpcMsg *pool = (RpcMsg *)CTRL->msgs_a;
    RpcMsg *m = transport_msg_alloc(list, pool);

    if (!m)
        return; /* real library waits/retries via OS machinery */

    m->w[0] = 0x00020001u;
    m->w[1] = 1u;
    m->w[2] = modem_rx_ptr;

    transport_ctrl_send(list, pool, m);
}


/* =========================================================================
 * 11. RPC DATA-MESSAGE DISPATCH
 * =========================================================================
 */

/*
 * [H] rpc_handle_data_message() dispatches by the operation/event preamble
 * family into subsystem handlers:
 *
 *   AT    -> rpc_at_event_handler()
 *   IP    -> rpc_ip_event_handler()
 *   GNSS  -> rpc_gnss_event_handler()
 *   etc.
 *
 * The fixed workload needs AT + IP.
 */
static void handle_at_event(RpcMsg *msg);
static void handle_ip_event(RpcMsg *msg);

static void handle_data_message(RpcMsg *msg)
{
    /*
     * Exact original dispatch table organization is compiler/library detail.
     * Semantically, the modem-visible event family selects the registered
     * subsystem event handler.
     */
    uint16_t opcode = (uint16_t)(msg->w[5] & 0xFFFFu);

    if ((opcode & 0xFFu) == 0xA7u) {
        handle_at_event(msg);
        return;
    }

    handle_ip_event(msg);
}


/* =========================================================================
 * 12. ORDERED RX PUMP — SEMANTIC REFERENCE
 * =========================================================================
 */

static bool consume_expected_from_list(RpcList *list, bool is_data_list)
{
    if (!list)
        return false;

    for (uint32_t i = 0; i < list->count; ++i) {
        uint32_t s = list->desc[i].state_seq;

        if ((s & 0xFFu) != DESC_BUSY)
            continue;

        if ((uint16_t)(s >> 16) != expected_rx_sequence_num)
            continue;

        RpcMsg *m = (RpcMsg *)(uintptr_t)list->desc[i].msg_ptr;

        if (is_data_list)
            handle_data_message(m);
        else
            handle_ctrl_message(m);

        list->desc[i].state_seq =
            (s & 0xFFFFFF00u) | DESC_FREE;

        expected_rx_sequence_num++;
        return true;
    }

    return false;
}

static void rpc_rx_pump(void)
{
    ModemHdr *mh = &CTRL->modem;
    RpcList *ptr0 = (RpcList *)(uintptr_t)mh->ptr0;
    RpcList *ptr1 = (RpcList *)(uintptr_t)mh->ptr1;

    for (;;) {
        while (consume_expected_from_list(ptr1, true))
            ;

        if (consume_expected_from_list(ptr0, false))
            continue;

        break;
    }
}


/* =========================================================================
 * 13. RPC CLIENT WRAPPER
 * =========================================================================
 */

/*
 * [P/H] rpc_client_msg_alloc(control_size, tx_payload_size):
 *
 *   if tx_payload_size != 0:
 *       payload = nrf_modem_os_shm_tx_alloc(tx_payload_size)
 *
 *   transport_msg = rpc_transport_msg_alloc(control_size)
 *   if allocation failed:
 *       free payload if allocated
 *       notify waiters
 *       return NULL
 *
 *   store wrapper metadata:
 *       payload pointer
 *       payload size
 *       control size
 *
 *   return pointer to the public RPC-message area
 *
 * The fixed specialized implementation does not need a general heap if one
 * outstanding transaction is guaranteed.  Static payload/control buffers are
 * semantically equivalent if their ownership rules are preserved.
 */


/*
 * [P] rpc_client_msg_send(preamble_low, opcode, rpc_msg):
 *
 * The function combines its arguments into the message header and hands the
 * wrapper back to rpc_transport_msg_send().
 *
 * Transport later rewrites w1 low byte to 2 for a data RPC.
 */


/* =========================================================================
 * 14. REQUEST / RESULT FORWARDING
 * =========================================================================
 */

/*
 * [H] _req_forward(opcode, request, result_cookie):
 *
 * Used by nrf_socket(), nrf_connect(), nrf_close(), and generic socket calls.
 *
 * Semantic flow:
 *
 *   result.status = PENDING
 *   associate result/cookie with request
 *   rpc_client_msg_send(... opcode ...)
 *   wait until subsystem RX event handler forwards the matching response
 *   translate RPC error -> nrf errno
 *   return 0 or error
 *
 * The result/cookie pointer appears in request w5 on the wire and is echoed by
 * the modem response.  res_cookie_get() and res_forward() are tiny helpers.
 *
 * For a single-outstanding specialized implementation, this generic result
 * registry/wait layer can collapse to one static result object plus polling.
 */


/* =========================================================================
 * 15. AT PROTOCOL
 * =========================================================================
 */

#define RPC_AT_OPCODE 0xA7u

/*
 * [P] rpc_at_init()
 *
 * host-only:
 *   initialize semaphore
 *   initialize mutex
 *   initialize result state
 *
 * modem-visible:
 *   at_cmd_send(0, 0, 5, 1)
 *   control size = 4
 *   tx payload size = 0
 *   opcode low byte = 0xA7
 *   DATA transport / SEND3
 */
static void rpc_at_init_model(void)
{
    RpcList *list = &CTRL->list_b;
    RpcMsg *pool = (RpcMsg *)CTRL->msgs_b;
    RpcMsg *m = transport_msg_alloc(list, pool);

    if (!m)
        return;

    /*
     * The exact pre-transport wrapper words are library-internal.
     * Observed modem-visible response preamble for this init exchange:
     *   0x00020003
     */
    m->w[0] = 0x00010003u; /* request-family preamble used by AT client */
    m->w[4] = 4u;
    m->w[5] = RPC_AT_OPCODE;

    transport_data_send(list, pool, m);
}


/*
 * [P] Ordinary AT request shape:
 *
 *   w0 = 0x00010003
 *   w1 = 2 after transport framing
 *   w2 = shared TX payload pointer
 *   w3 = payload length
 *   w4 = 4
 *   w5 low byte = 0xA7
 *
 * Payload is the ASCII AT command bytes.
 */
typedef struct {
    uint32_t data_ptr;
    uint32_t data_len;
    int32_t completion_status;
    bool completion_seen;
    bool data_seen;
} AtTransaction;

static AtTransaction at_txn;


/*
 * [P/H] rpc_at_event_handler() recognizes modem AT event types.
 *
 * The event number is high16(w0).
 *
 * Observed relevant events:
 *
 *   event 2:
 *       completion/result event
 *       status/result in response fields
 *
 *   event 3:
 *       response/notification data
 *       w2 = modem RX-data pointer
 *       w3 = data length
 *       consumer must eventually issue modem_rx_data_free(w2)
 *
 *   event 4:
 *       auxiliary AT event/notification seen in live traffic
 *
 * The full generic library can route unsolicited notifications through a
 * registered callback; the fixed workload only needs to consume/parse the
 * commands/URCs that influence registration and link state.
 */
static void handle_at_event(RpcMsg *m)
{
    uint16_t event = (uint16_t)(m->w[0] >> 16);

    switch (event) {
    case 2:
        at_txn.completion_status = (int32_t)m->w[6];
        at_txn.completion_seen = true;
        break;

    case 3:
        at_txn.data_ptr = m->w[2];
        at_txn.data_len = m->w[3];
        at_txn.data_seen = true;

        /*
         * Real nrf_modem_at_cmd() copies/parses the data first, then calls
         * rpc_client_msg_data_rx_free(), which becomes modem_rx_data_free().
         */
        break;

    case 4:
        /* Generic library performs event-specific bookkeeping/callbacks. */
        break;

    default:
        break;
    }
}


/*
 * [P] nrf_modem_at_cmd() / AT data ownership:
 *
 *   allocate host shared-TX buffer for formatted command
 *   send A7 request
 *   wait for AT events
 *   copy/parse modem RX response
 *   rpc_client_msg_data_rx_free(response_ptr)
 *   free host TX allocation locally
 *
 * Both frees are important but different:
 *
 *   modem RX data free:
 *       HOST -> MODEM control RPC, consumes a TX sequence number
 *
 *   host TX payload free:
 *       local heap bookkeeping after modem TX-free notification / ownership
 */


/* =========================================================================
 * 16. NCS REFERENCE NETWORK-BRING-UP SEQUENCE
 * =========================================================================
 */

/*
 * [P from reference Zephyr/NCS path + live reconstruction]
 *
 * This section is ABOVE libmodem.  It is included because the fixed workload
 * depends on it and it is part of the frozen behavioral oracle.
 *
 * Exact command order before socket():
 *
 *   AT%XCOEX0=1,1,1565,1586
 *   AT%XSYSTEMMODE=0,1,0,0
 *   AT+CPSMS=1,,,"00100001","00000000"
 *   AT%FEACONF=0,0,0
 *   AT%FEACONF=0,3,1
 *   AT+CEDRXS=3
 *   AT%RAI=2
 *   AT+CEREG?
 *   AT+CFUN?
 *   AT+CEREG=5
 *   AT+CSCON=1
 *   AT+CFUN=1
 *
 * Registration criterion:
 *   CEREG registration state == 1 or 5
 *
 * After registration:
 *   AT%XMONITOR
 *
 * The XMONITOR response is RX data and therefore also requires the
 * HOST->MODEM RX-data-free control transaction.
 *
 * There is no required pre-setup AT+CFUN=4 in the current reference path.
 */


/* =========================================================================
 * 17. LOCAL SOCKET OBJECT MODEL
 * =========================================================================
 */

/*
 * The original socket structure is larger and serves generic stream/datagram,
 * poll, nonblocking, packet queues, flow control, TLS, etc.
 *
 * For the fixed UDP path, only these semantics matter.
 */
typedef struct {
    int modem_fd;         /* [P] returned by modem; first UDP socket is 0 */
    int family;
    int type;
    int proto;

    bool connecting;      /* [P] set before CONNECT request */
    bool connected;       /* [P] set on successful CONNECT response */
    bool closed;
    bool nonblock;

    uint32_t rai_value;   /* [P/H] local SO_RAI state used by send marshaling */

    int last_error;
} SocketModel;

static SocketModel socket0;


/*
 * [P] Zephyr ZVFS fd and modem/libmodem fd are NOT the same thing.
 *
 * In reference:
 *   Zephyr ZVFS fd = 2
 *   libmodem / modem fd = 0
 *
 * The fixed specialized host should simply use modem fd 0 and omit ZVFS.
 */


/* =========================================================================
 * 18. SOCKET OPEN / LOOKUP
 * =========================================================================
 */

/*
 * [P/H]
 * sock_init()      initializes generic socket table/state
 * sock_open()      reserves a host socket object
 * sock_find(fd)    local lookup only
 * _sock_close()    local cleanup
 *
 * None of these emits a modem-visible transaction by itself.
 */


/* =========================================================================
 * 19. WIRE ENUM TRANSLATIONS
 * =========================================================================
 */

/* [P] First IPv4 datagram/UDP request uses these wire values. */
#define RPC_AF_INET       1u
#define RPC_SOCK_DGRAM    2u
#define RPC_IPPROTO_UDP   2u

/*
 * [P] nrf_rai_to_rpc_rai() table in this build:
 *
 * public value -> RPC wire value
 *
 *   entry 0 -> 0x02000000
 *   entry 1 -> 0x01000000   <-- RAI_LAST in current workload
 *   entry 2 -> 0x04000000
 *   entry 3 -> 0x08000000
 *   entry 4 -> 0x10000000
 *
 * Public RAI_LAST is numeric value 2 in the NCS application API, but its
 * translated modem RPC field for this send is 0x01000000.
 */
#define RPC_RAI_LAST 0x01000000u


/* =========================================================================
 * 20. SOCKET() — COMPLETE FIXED-PATH MODEL
 * =========================================================================
 */

#define RPC_SOCKET_REQ 0x70010004u
#define RPC_SOCKET_RSP 0x80010004u

/*
 * [P] nrf_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)
 *
 * Generic checks:
 *   validate family
 *   validate protocol
 *   validate type
 *   validate type/protocol compatibility
 *   sock_open()
 *   rpc_client_msg_alloc(control_size=20, tx_payload=0)
 *
 * Request construction before _req_forward:
 *   four bytes at +16..+19 = 0xFF
 *   rpc AF
 *   rpc type
 *   rpc protocol
 *
 * _req_forward(op=0x7001)
 *
 * On success:
 *   save family/type/proto in local socket object
 *   return local modem fd
 *
 * Live reference: first modem fd == 0.
 */

/* [P] Exact modem-visible wire image immediately before SEND3. */
static const uint32_t SOCKET_REQUEST_WIRE[] = {
    0x70010004u, /* w0 */
    0x00000002u, /* w1 transport data kind */
    0x00000000u, /* w2 */
    0x00000000u, /* w3 */
    0x00000014u, /* w4 control size = 20 */
    0x00000000u, /* w5 cookie pointer at runtime */
    0xFFFFFFFFu, /* w6 */
    0x00000001u, /* w7 AF_INET wire */
    0x00000002u, /* w8 SOCK_DGRAM */
    0x00000002u  /* w9 UDP */
};

/* [P] Successful response shape. */
static const uint32_t SOCKET_RESPONSE_SHAPE[] = {
    0x80010004u, /* w0 */
    0x00000002u, /* w1 */
    0x00000000u, /* w2 */
    0x00000000u, /* w3 */
    0x00000010u, /* w4 */
    0x00000000u, /* w5 echoed cookie pointer at runtime */
    0xFFFFFFFFu, /* w6 */
    0x00000000u, /* w7 error */
    0x00000000u  /* w8 returned modem fd */
};


/* =========================================================================
 * 21. CONNECT() — COMPLETE FIXED-PATH MODEL
 * =========================================================================
 */

#define RPC_CONNECT_REQ 0x70020004u
#define RPC_CONNECT_RSP 0x80020004u

/*
 * [P] nrf_connect(fd, sockaddr, addrlen)
 *
 * Host-side sequence:
 *
 *   sock = sock_find(fd)
 *   validate sockaddr family against socket
 *   validate sockaddr length
 *   derive nonblocking behavior / timeout
 *   rpc_client_msg_alloc(control_size=28, tx_payload=0)
 *   msg fd field = fd
 *   encode sockaddr
 *   sock->CONNECTING = 1
 *   rpc_client_msg_send(op=0x7002)
 *
 * Blocking path:
 *   wait for response forwarded by rpc_ip_event_handler
 *
 * Response handler:
 *   clear CONNECTING
 *   if error == 0:
 *       set CONNECTED
 *   else:
 *       translate/set errno
 *
 * IMPORTANT:
 * No bind(), hidden socket-registration RPC, SO_RAI RPC, or other modem-
 * visible transaction occurs between successful socket() and CONNECT.
 */

/*
 * [P] Exact connected endpoint used by reference:
 *   IPv4 8.8.8.8
 *   port 2405
 *
 * Encoded sockaddr words:
 *   0x0004A509
 *   0x08080808
 */
static const uint32_t CONNECT_REQUEST_WIRE[] = {
    0x70020004u,
    0x00000002u,
    0x00000000u,
    0x00000000u,
    0x0000001Cu, /* control size 28 */
    0x00000000u,
    0x00000000u, /* fd=0 */
    0x0004A509u,
    0x08080808u
};


/* =========================================================================
 * 22. IP RESPONSE HANDLER
 * =========================================================================
 */

/*
 * [P/H] rpc_ip_event_handler() is the asynchronous modem->host IP dispatcher.
 *
 * It recognizes response/notification opcodes, finds local socket objects when
 * an fd is present, updates local state, and forwards generic request results.
 *
 * Fixed workload relevant responses:
 *
 *   0x8001 family -> socket result
 *       forwards returned modem fd + error
 *
 *   0x8002 family -> connect result
 *       find socket
 *       clear CONNECTING
 *       success -> set CONNECTED
 *       forward request result
 *
 *   0x8006 family -> connected-send result
 *       forward error / byte count
 *
 * Generic handler also contains branches for:
 *   receive packet delivery
 *   PDN status
 *   flow control
 *   TLS attach/notifications
 *   other socket service notifications
 *
 * Those branches are not required to send the fixed connected UDP report, but
 * the ordered transport must still retire their descriptors if such messages
 * appear.  A production specialized implementation should either implement
 * or deliberately reject every asynchronous event that its configured modem
 * can generate.
 */
static void handle_ip_event(RpcMsg *m)
{
    uint16_t family = (uint16_t)(m->w[0] >> 16);

    switch (family) {
    case 0x8001:
        /* socket() response/result forwarding */
        break;

    case 0x8002:
        /*
         * connect response:
         * request-specific layout in the working oracle:
         *   w6 = fd
         *   w7 = RPC error
         */
        if ((int)m->w[6] == socket0.modem_fd) {
            socket0.connecting = false;
            socket0.last_error = (int)m->w[7];
            if (m->w[7] == 0)
                socket0.connected = true;
        }
        break;

    case 0x8006:
        /* send result: w7 error, w8 bytes in observed response */
        break;

    default:
        break;
    }
}


/* =========================================================================
 * 23. SO_RAI
 * =========================================================================
 */

/*
 * [P] For the fixed workload:
 *
 *   setsockopt(fd, SOL_SOCKET, SO_RAI, &RAI_LAST, 4)
 *
 * is LOCAL libmodem socket state.
 *
 * There is no immediate modem RPC for SO_RAI.
 * The RAI choice is translated and inserted into the later SEND request.
 *
 * This is why CONNECT has no RAI field and why no hidden transaction exists
 * between socket() and connect().
 */
static int set_rai_last(SocketModel *s)
{
    s->rai_value = RPC_RAI_LAST;
    return 0;
}


/* =========================================================================
 * 24. CONNECTED UDP SEND
 * =========================================================================
 */

#define RPC_SEND_REQ 0x70060004u
#define RPC_SEND_RSP 0x80060004u

/*
 * [P] nrf_sendto(fd, buf, len, flags, addr=NULL, addrlen=0)
 * on a connected datagram socket:
 *
 *   sock_find(fd)
 *   validate flags/state
 *   because datagram is already connected and addr==NULL:
 *       choose opcode 0x7006
 *   allocate shared-TX payload
 *   copy application payload
 *   allocate RPC message
 *   marshal:
 *       payload pointer
 *       payload length
 *       control size = 14
 *       result cookie
 *       fd
 *       translated RAI local socket state
 *       flags/aux field
 *   DATA send via list_b / SEND3
 *   wait/forward response
 *
 * Explicit-address sendto uses opcode 0x7007 and a larger request.
 */

/*
 * [P] Exact 20-byte connected-send wire image, with runtime pointers marked.
 */
typedef struct {
    uint32_t w0;
    uint32_t w1;
    uint32_t payload_ptr;
    uint32_t payload_len;
    uint32_t ctrl_size;
    uint32_t cookie_ptr;
    uint32_t fd;
    uint32_t rai;
    uint32_t flags;
} ConnectedSendWire;

static ConnectedSendWire make_connected_send(
    uint32_t payload_ptr,
    uint32_t cookie_ptr)
{
    ConnectedSendWire q = {
        .w0 = 0x70060004u,
        .w1 = 0x00000002u,
        .payload_ptr = payload_ptr,
        .payload_len = 20u,
        .ctrl_size = 0x0Eu,
        .cookie_ptr = cookie_ptr,
        .fd = 0u,
        .rai = 0x01000000u,
        .flags = 0u
    };
    return q;
}

/*
 * [P] Successful observed send response:
 *
 *   w0 = 80060004
 *   w1 = 00000002
 *   w2 = 00000000
 *   w3 = 00000000
 *   w4 = 00000010
 *   w5 = cookie
 *   w6 = 00000000
 *   w7 = 00000000      RPC error
 *   w8 = 00000014      bytes sent
 */


/* =========================================================================
 * 25. CLOSE()
 * =========================================================================
 */

#define RPC_CLOSE_OPCODE 0x7009u

/*
 * [P] nrf_close(fd)
 *
 * Relevant disassembly:
 *
 *   sock_find(fd)
 *   if appropriate, rpc_client_msg_alloc(control_size=8, payload=0)
 *   request stores fd
 *   _req_forward(0x7009, ...)
 *   result 0 or one tolerated close-state result
 *   _sock_close(local object)
 *
 * The fixed telemetry experiment can keep one socket for the program lifetime;
 * nevertheless this is the modem-visible close operation if clean teardown is
 * required.
 */


/* =========================================================================
 * 26. ERROR TRANSLATION
 * =========================================================================
 */

/*
 * [P] rpc_error_to_nrf_errno() is a table/translation function.
 *
 * Important observed mapping:
 *
 *   RPC error 4 -> NRF EALREADY -> numeric 0x72 in this build
 *
 * The current EM reconstruction receives an ACTUAL CONNECT response carrying
 * RPC error 4; this is not a host-side timeout and not an unrelated packet.
 *
 * A minimal implementation may keep only mappings needed by its supported
 * operations, but must preserve the modem error values for diagnostics.
 */


/* =========================================================================
 * 27. COMPLETE MODEM STARTUP MODEL
 * =========================================================================
 */

static void construct_ctrl(void)
{
    memset((void *)CTRL, 0, SHM_CTRL_SIZE);

    CTRL->host.version   = CTRL_VERSION;
    CTRL->host.data_base = SHM_RX_ADDR;
    CTRL->host.data_size = SHM_RX_SIZE;
    CTRL->host.list_a    = SHM_CTRL_ADDR + CTRL_LIST_A_OFF;
    CTRL->host.list_b    = SHM_CTRL_ADDR + CTRL_LIST_B_OFF;
    CTRL->host.modem_hdr = SHM_CTRL_ADDR + CTRL_MODEM_OFF;

    CTRL->list_a.count = RPC_DESC_COUNT;
    CTRL->list_b.count = RPC_DESC_COUNT;

    for (unsigned i = 0; i < RPC_DESC_COUNT; ++i) {
        CTRL->list_a.desc[i].state_seq = DESC_FREE;
        CTRL->list_b.desc[i].state_seq = DESC_FREE;
        CTRL->list_a.desc[i].msg_ptr = 0;
        CTRL->list_b.desc[i].msg_ptr = 0;
    }

    expected_rx_sequence_num = 0;
    tx_sequence_num = 0;
}


/*
 * [P] nrf_modem_os_init():
 *
 *   initialize ordinary libmodem heap (0x400 bytes)
 *   initialize shared TX heap (0x2080 bytes: TX + pad in this image)
 *
 * These k_heap structures are host implementation machinery.
 * The modem startup handshake does not consume the heap.
 *
 * A specialized single-outstanding implementation can statically assign
 * payload storage instead of reproducing k_heap.
 */
static void host_os_init_model(void)
{
    /* host_heap_init(..., 0x400); */
    /* shm_tx_heap_init(SHM_TX_ADDR, 0x2080); */
}


/*
 * [P] Complete modem-visible initialization order.
 */
static bool modem_init_model(void)
{
    host_os_init_model();

    *(volatile uint32_t *)POWER_PREP_ADDR = 1u;
    /* busywait_us(200); */

    construct_ctrl();

    /*
     * IPC:
     *
     * SEND_CNF[1] = 0x02
     * SEND_CNF[3] = 0x08
     * SEND_CNF[5] = 0x20
     *
     * RECEIVE_CNF[0] = 0x01
     * RECEIVE_CNF[2] = 0x04
     * RECEIVE_CNF[4] = 0x10
     * RECEIVE_CNF[6] = 0x40
     * RECEIVE_CNF[7] = 0x80
     *
     * INTENSET = 0xD5
     * GPMEM0 = SHM_CTRL_ADDR
     * GPMEM1 = 0
     */

    /*
     * STARTN = 0
     * wait RECEIVE[2]
     *
     * Successful modem publication:
     *   GPMEM1 = 0x20008020
     *   CTRL->modem.state = 1
     *   CTRL->modem.ptr0  = 0x2000A568
     *   CTRL->modem.ptr1  = 0x2000A5EC
     */

    if (CTRL->modem.state != 1)
        return false;

    rpc_at_init_model();

    /*
     * rpc_ip_init()         host-only
     * rpc_gnss_init()       host-only for this startup claim
     * rpc_delta_dfu_init()  no-op
     * rpc_softsim_init()    no-op
     */

    *(volatile uint32_t *)POWER_POST_ADDR = 1u;

    return true;
}


/* =========================================================================
 * 28. TRUSTZONE / TF-M PRECONDITION
 * =========================================================================
 */

/*
 * [P] The working non-secure Zephyr environment includes TF-M.
 *
 * Bare EMS startup failed until the same prebuilt TF-M secure image was placed
 * at 0x00000000 and EMS ran non-secure from 0x00008000.
 *
 * TF-M establishes the required SPU/security attribution for the non-secure
 * application and modem-facing peripherals/RAM.
 *
 * This is a PLATFORM SECURITY PRECONDITION, not another hidden libmodem RPC.
 *
 * Once TF-M is present, the shared-memory + IPC + STARTN sequence above is
 * sufficient to reach the first modem startup response.
 */


/* =========================================================================
 * 29. IRQ / POLLING EQUIVALENCE FOR THE SPECIALIZED HOST
 * =========================================================================
 */

/*
 * [P] Zephyr/libmodem enables IPC IRQ42 and uses semaphores/events to wake
 * waiting threads.
 *
 * No extra modem-visible write was found in that scheduling plumbing.
 *
 * Therefore a specialized implementation may poll:
 *   - startup RECEIVE[2]
 *   - RPC RECEIVE event(s)
 *   - shared descriptor lists
 *
 * provided it preserves:
 *   - descriptor ownership
 *   - global TX sequence
 *   - global ordered RX sequence
 *   - message retirement
 *   - RX-data-free control messages
 *
 * IRQ/semaphore substitution does not change the modem protocol.
 */


/* =========================================================================
 * 30. COMPLETE FIXED-WORKLOAD EXECUTION SKELETON
 * =========================================================================
 */

static bool registration_ready_from_cereg(const char *s, size_t n)
{
    /*
     * Reference accepts registration state 1 (home) or 5 (roaming).
     * Parser here is schematic.
     */
    for (size_t i = 0; i + 1 < n; ++i) {
        if ((s[i] == ',' || s[i] == ':') &&
            (s[i + 1] == '1' || s[i + 1] == '5'))
            return true;
    }
    return false;
}

static int fixed_workload_reference(void)
{
    if (!modem_init_model())
        return -1;

    /*
     * AT setup — exact reference order:
     *
     * at("AT%XCOEX0=1,1,1565,1586");
     * at("AT%XSYSTEMMODE=0,1,0,0");
     * at("AT+CPSMS=1,,,\"00100001\",\"00000000\"");
     * at("AT%FEACONF=0,0,0");
     * at("AT%FEACONF=0,3,1");
     * at("AT+CEDRXS=3");
     * at("AT%RAI=2");
     * at("AT+CEREG?");
     * at("AT+CFUN?");
     * at("AT+CEREG=5");
     * at("AT+CSCON=1");
     * at("AT+CFUN=1");
     *
     * wait until CEREG is 1 or 5
     * at("AT%XMONITOR");
     */

    /*
     * socket(AF_INET, SOCK_DGRAM, UDP)
     *
     * modem request == SOCKET_REQUEST_WIRE
     * modem response yields fd=0
     */
    memset(&socket0, 0, sizeof(socket0));
    socket0.modem_fd = 0;
    socket0.family = RPC_AF_INET;
    socket0.type = RPC_SOCK_DGRAM;
    socket0.proto = RPC_IPPROTO_UDP;

    /*
     * connect(fd=0, 8.8.8.8:2405)
     *
     * Before send:
     *   socket0.connecting = true
     *
     * modem request == CONNECT_REQUEST_WIRE
     *
     * On successful 0x8002:
     *   connecting=false
     *   connected=true
     */
    socket0.connecting = true;

    /*
     * Once connected:
     *   set local SO_RAI = RAI_LAST
     *   no RPC is emitted here
     */
    set_rai_last(&socket0);

    /*
     * For each report:
     *
     *   payload[20]
     *   allocate/copy into shared TX region
     *   build 0x7006 request
     *   RAI field = 0x01000000
     *   SEND3
     *   ordered RX pump
     *   response 0x8006, error=0, bytes=20
     *
     *   wait 20 seconds
     *
     * PSM/RRC behavior after the send is primarily modem/network behavior [O].
     */

    return 0;
}


/* =========================================================================
 * 31. WHAT THE GENERIC LIBRARY DOES THAT THE FIXED HOST DOES NOT NEED
 * =========================================================================
 */

/*
 * [P/H] Linked generic machinery adjacent to the live path includes:
 *
 *   - multiple socket objects
 *   - socket reference counting
 *   - nonblocking operation
 *   - send/receive timeouts
 *   - packet queues
 *   - poll callbacks
 *   - flow control
 *   - stream state / EOF / stream errors
 *   - bind / listen / accept
 *   - explicit-address sendto (0x7007)
 *   - receive path
 *   - DNS / getaddrinfo
 *   - getsockopt / generic setsockopt
 *   - TLS attach/handshake
 *   - IPv6
 *   - generic error mapping
 *   - generic heap allocation
 *   - OS mutexes/semaphores/events
 *   - ZVFS/POSIX socket adaptation above libmodem
 *
 * None is evidence of a hidden requirement for:
 *   one IPv4 UDP socket,
 *   one connected endpoint,
 *   one outstanding request,
 *   one 20-byte payload,
 *   polling transport.
 */


/* =========================================================================
 * 32. MODEM-VISIBLE CONTRACT VS HOST-ONLY IMPLEMENTATION CONVENIENCE
 * =========================================================================
 */

/*
 * MODEM-VISIBLE / PROTOCOL-REQUIRED
 * ---------------------------------
 * [P]
 *   CTRL layout and initial host header
 *   list counts / initial FREE descriptors
 *   IPC routing / GPMEM publication
 *   STARTN
 *   POWER +0x68 / +0x6C sequence
 *   A7 AT init
 *   DATA vs CONTROL transport kind byte
 *   one shared outgoing TX sequence
 *   BUSY descriptor publication
 *   3-us pre-doorbell delay in current implementation
 *   SEND3 for data RPC
 *   SEND1 for control RPC
 *   one shared ordered incoming RX sequence across ptr1 + ptr0
 *   descriptor retirement preserving sequence
 *   RX-data-free control RPC
 *   exact socket/connect/send wire requests
 *
 * HOST-ONLY / SPECIALIZABLE
 * -------------------------
 * [P/H]
 *   Zephyr k_heap
 *   ordinary libmodem heap
 *   shared TX heap allocator policy
 *   semaphores
 *   mutexes
 *   IRQ wakeup vs polling
 *   result-object registry when only one request outstanding
 *   socket table when only one socket exists
 *   fd abstraction above modem fd
 *   ZVFS
 *   callback tables not used by the fixed application
 *   generic sockaddr allocation/copies when endpoint is compile-time fixed
 */


/* =========================================================================
 * 33. CURRENT CONNECT EALREADY — WHAT THIS MODEL ESTABLISHES
 * =========================================================================
 */

/*
 * The current EMS experiment has already matched:
 *
 *   - modem fd = 0
 *   - CONNECT wire request
 *   - list_b
 *   - message slot/pointer
 *   - descriptor BUSY state
 *   - outgoing CONNECT TX sequence = 0x001F
 *   - full pre-connect AT command count/order sufficient to reach that sequence
 *   - RX-data-free transactions
 *   - ordered modem->host RX sequence
 *   - modem->host TX-free control-message retirement
 *
 * Yet the modem returns an actual CONNECT response with error 4 (EALREADY).
 *
 * The comprehensive host reconstruction above does NOT reveal an additional
 * modem-visible call between socket success and CONNECT.
 *
 * Therefore, after implementing/verifying this reference model literally,
 * further assembly excavation is not the next discriminator.
 *
 * Remaining categories are:
 *
 *   A. a mismatch in the implementation versus this model;
 *   B. asynchronous modem/runtime state at the RPC boundary;
 *   C. timing/event handling differences in the surrounding NCS workload;
 *   D. closed modem behavior.
 *
 * Those can be investigated from the C-like model and boundary observations;
 * they do not require returning to raw assembly to discover another hidden
 * pre-CONNECT libmodem call.
 */


/* =========================================================================
 * 34. ADJACENT LIBMODEM FUNCTION INVENTORY
 * =========================================================================
 */

/*
 * The linked binary exposes the following relevant groups.  This inventory is
 * retained so future work can stay at the model/function level rather than
 * rediscovering names from assembly.
 *
 * MODEM / PLATFORM
 *   nrf_modem_init
 *   nrf_modem_shutdown
 *   nrf_modem_state_set
 *   nrf_modem_state_is_initialized
 *   nrf_modem_state_is_fault
 *   nrf_modem_platform_init
 *
 * RPC FRAMEWORK
 *   rpc_init
 *   rpc_shutdown
 *   rpc_handle_ctrl_message
 *   rpc_handle_data_message
 *
 * RPC TRANSPORT
 *   rpc_transport_init
 *   rpc_transport_msg_alloc
 *   rpc_transport_msg_data_tx_size
 *   rpc_transport_msg_data_rx_free
 *   rpc_transport_msg_send
 *   rpc_transport_request_shutdown
 *   rpc_transport_shutdown
 *   rpc_transport_data_rx_suspend
 *   rpc_transport_data_rx_resume
 *
 * IPC TRANSPORT
 *   rpc_transport_ipc_msg_alloc
 *   rpc_transport_ipc_ctrl_msg_alloc
 *   rpc_transport_ipc_data_msg_alloc
 *   rpc_transport_ipc_data_msg_send
 *   rpc_transport_ipc_ctrl_msg_send
 *   rpc_transport_ipc_msg_tx_free
 *   rpc_transport_ipc_msg_data_rx_free
 *   rpc_transport_ipc_request_shutdown
 *   rpc_transport_ipc_init
 *   ipc_irq_handler
 *   rpc_message_handler
 *   handle_modem_rpc_msg
 *
 * RPC CLIENT
 *   rpc_client_msg_alloc
 *   rpc_client_msg_send
 *   rpc_client_msg_data_rx_free
 *   rpc_client_msg_data_tx_size
 *   rpc_client_msg_data_tx_alloc
 *   rpc_client_msg_data_tx_free
 *
 * AT
 *   at_cmd_send
 *   at_response_match
 *   nrf_modem_at_cmd
 *   nrf_modem_at_printf
 *   nrf_modem_at_scanf
 *   rpc_at_event_handler
 *   rpc_at_init
 *
 * SOCKET LOCAL STATE
 *   sock_init
 *   sock_open
 *   sock_find
 *   _sock_close
 *   sock_shutdown
 *   sock_rpc_flow_control_set
 *   sock_is_connecting
 *   sock_is_connected
 *   sock_is_nonblock
 *   sock_has_rai_no_data
 *   sock_can_send
 *   sock_sndtimeo_ms_get
 *   sock_rcvtimeo_ms_get
 *   family/type/protocol validators
 *
 * IP API
 *   nrf_socket
 *   nrf_connect
 *   nrf_bind
 *   nrf_listen
 *   nrf_accept
 *   nrf_sendto
 *   nrf_recvfrom
 *   nrf_close
 *   nrf_setsockopt
 *   nrf_getsockopt
 *   nrf_getaddrinfo
 *   rpc_ip_event_handler
 *   rpc_ip_init
 *
 * TABLES / RESULT FORWARDING
 *   nrf_af_to_rpc_af
 *   nrf_so_to_rpc_so
 *   nrf_rai_to_rpc_rai
 *   nrf_type_to_rpc_type
 *   nrf_proto_to_rpc_proto
 *   nrf_sol_to_rpc_sol
 *   rpc_error_to_nrf_errno
 *   _req_forward
 *   res_cookie_get
 *   res_forward
 *
 * ADJACENT BUT NOT NEEDED FOR FIXED UDP SEND
 *   TLS attach/handshake
 *   DNS
 *   polling/fcntl
 *   GNSS RPC handler/init
 *   SoftSIM
 *   delta DFU
 */


/* =========================================================================
 * 35. RECONSTRUCTION LIMITS / FINAL BOUNDARY
 * =========================================================================
 */

/*
 * WHAT IS CLOSED
 * --------------
 * The host binary tells us exactly what is written into shared memory and
 * which IPC doorbell is rung.  It does NOT reveal the implementation behind:
 *
 *     RPC request -> modem firmware -> cellular stack/baseband/RF
 *
 * Specifically, host disassembly cannot reconstruct:
 *
 *   - why the modem internally decides CONNECT is EALREADY
 *   - modem socket object internals
 *   - cellular NAS/RRC implementation
 *   - carrier/network state machines
 *   - baseband/RF implementation
 *
 * That is the true closed-modem boundary.
 *
 * WHAT IS NOW REPRESENTED ABOVE
 * -----------------------------
 * For the fixed workload, every host-side mechanism presently known to affect
 * the modem contract is represented in this file:
 *
 *   startup
 *   security precondition
 *   shared memory
 *   IPC
 *   TX allocation/state
 *   outgoing sequence
 *   DATA/CONTROL framing
 *   ordered RX
 *   incoming sequence
 *   modem TX-free control notifications
 *   host RX-data-free control replies
 *   AT initialization
 *   AT data ownership
 *   NCS AT setup sequence
 *   socket
 *   connect
 *   SO_RAI
 *   connected send
 *   close
 *   response/error forwarding
 *
 * This is the intended change-control reference.
 */
