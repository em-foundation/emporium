# nRF91 EMS Conformance Audit

**Date:** 2026-08-29  
**Oracle:** `nrf91-libmodem-host-reference-model-20260829.c`  
**Implementation:** `Modem.em(20260829-151829).ts`  
**Type definitions:** `Types.em(9).ts`

## Summary

The current EMS implementation already matches most of the modem-visible contract in the frozen C reference model. The audit found **two concrete transport differences that should be corrected before the next modem run**, plus one stale type constant and one teardown difference that does not affect the current CONNECT failure.

| Area | Status | Finding |
|---|---|---|
| TF-M / non-secure precondition | MATCH | External platform precondition already established. |
| Shared-memory layout | MATCH | CTRL/TX/PAD/RX layout and host header construction agree. |
| IPC routing | MATCH | SEND/RECEIVE routing, INTENSET, GPMEM0/1 agree. |
| POWER startup | MATCH | +0x68, 200 us delay, +0x6C, STARTN behavior represented. |
| AT init | MATCH | A7 initialization request is represented. |
| TX descriptor allocator | MATCH for fixed workload | FREE→ALLOC, message pointer assignment, caller-side zeroing. |
| TX sequence | MATCH | One global sequence shared by DATA and CONTROL sends. |
| DATA framing | MATCH | `w1` low byte 2, BUSY publication, 3 us delay, SEND3. |
| CONTROL framing | MATCH | RX-data-free uses same TX sequence, kind 1, 3 us, SEND1. |
| Ordered RX sequence | MATCH | One shared `rpc_rx_seq`, ptr1 searched before ptr0. |
| RX retirement | MATCH | Upper sequence preserved; low state becomes FREE. |
| Modem→host control dispatch | **DIFFERENCE** | EMS explicitly recognizes only control type 2. Reference consumes ptr0 control types 1, 2, and 4 (and retires them in sequence). |
| Generic incoming data dispatch | **DIFFERENCE** | `rpcDrainAt()` stops on a non-AT data message instead of dispatching/retiring it. Reference always consumes the next in-sequence data message through the subsystem dispatcher. |
| AT shared-TX ownership | **DIFFERENCE / specialization hazard** | EMS reuses one fixed AT TX buffer. The reference heap permits a new allocation before the prior pointer is returned by modem control type 2. A one-buffer specialization must therefore not reuse that buffer until the matching TX-free notification has been consumed. |
| AT setup command order/content | MATCH | XCOEX0 → SYSTEMMODE → CPSMS → FEACONF×2 → CEDRXS=3 → RAI=2 → CEREG? → CFUN? → CEREG=5 → CSCON=1 → CFUN=1 → registration → XMONITOR. |
| Registration criterion | MATCH | 1 or 5. |
| Socket wire request | MATCH | Exact 0x7001 request, modem fd 0 result path. |
| AF_INET wire value | MATCH in Modem, **stale in Types** | Modem correctly writes wire value 1; `Types.em.ts` still declares `RPC_AF_INET = 2`. |
| CONNECT wire request | MATCH | fd 0, control size 0x1C, `0x0004A509`, `0x08080808`. |
| Hidden pre-CONNECT RPC | NOT PRESENT | Frozen model confirms none. |
| SO_RAI | MATCH by specialization | EMS hardcodes translated `RAI_LAST = 0x01000000` into SEND rather than storing generic socket state. |
| Connected SEND wire request | MATCH | 0x7006, 20 bytes, control size 0x0E, fd 0, RAI_LAST. |
| Socket local state machine | NOT NEEDED | Host-only generic bookkeeping can be omitted for one fixed socket. |
| ZVFS / POSIX fd layer | NOT NEEDED | Modem fd is used directly. |
| Heap/mutex/semaphore infrastructure | NOT NEEDED | May be replaced by static one-outstanding storage if ownership rules are preserved. |
| Close | NOT IMPLEMENTED | Frozen model identifies modem close opcode 0x7009. Current EMS instead eventually sends `AT+CFUN=0`; this does not explain CONNECT `EALREADY`. |

## Concrete corrections before the next run

### 1. Treat ptr0 as a control channel, not merely a “TX-free” detector

Current EMS helper `rpcRxIsTxFree()` recognizes only:

```text
type == 2
```

The reference transport consumes every expected ptr0 control descriptor in sequence. For this workload:

- type 1: consume, no action
- type 2: consume; host shared-TX free bookkeeping
- type 4: consume, no action

For the static EMS allocator, type 2 must additionally mark the corresponding fixed host TX buffer reusable.

### 2. Never stop the ordered RX sequence on an unrelated data event

Current `rpcDrainAt()` does:

```text
if opcode != AT:
    break
```

That leaves the expected descriptor BUSY and prevents all later sequence numbers from being consumed. The reference dispatcher instead routes every in-sequence ptr1 message to its subsystem handler and retires it.

For the fixed EMS workload, it is sufficient to:

- process AT events that matter,
- process socket/connect/send responses that matter,
- safely ignore other known IP/asynchronous events,
- **always retire the in-sequence descriptor**.

### 3. Enforce ownership of the one static AT TX buffer

The current AT implementation always writes the next command at `SHM_TX_ADDR`.

That is valid only after the modem has emitted its type-2 control notification returning that same pointer. The generic reference can allocate another heap block if the previous one has not yet returned; the static EMS implementation cannot.

Required specialization rule:

```text
before writing the next AT command:
    previous AT TX buffer must be free

when ptr0 type-2 control arrives for SHM_TX_ADDR:
    mark AT TX buffer free
```

This is the most important semantic difference not represented by the current one-buffer implementation.

## Items that should not be changed

The audit finds no reason to alter:

- shared-memory addresses/layout,
- CONNECT packet fields,
- socket fd (`0`),
- CONNECT TX sequence machinery,
- ptr1-before-ptr0 ordering,
- preserved RX descriptor sequence bits,
- RAI translated value `0x01000000`,
- AT command list/order,
- TF-M setup,
- polling in place of Zephyr IRQ/semaphore scheduling.

## Recommended next implementation

Make one Modem revision containing all three transport corrections above:

1. generic ptr0 control consumption,
2. generic in-sequence ptr1 retirement/dispatch,
3. explicit static AT TX-buffer ownership.

Also correct `Types.em.ts`:

```text
RPC_AF_INET = 1
```

Then run once.

If CONNECT still returns modem error 4 after those corrections, the frozen reference model and EMS modem-visible path will be substantially conformant. The next step would then be a runtime boundary comparison, not further ELF excavation.
