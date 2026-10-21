# EMR 10 — BlueJoule-GATT-Secure Definition

**Report date:** 2026-10-18  
**Status:** Benchmark overview — point-in-time snapshot  
**Repository snapshot:** EM•porium `dev` at [`5f8e2ab`](https://github.com/em-foundation/emporium/tree/5f8e2ab3acbf63d0b2c45f683243bbc37ff6997e)

## TLDR

- Extends BlueJoule-GATT with pairing and link encryption. [[EMR 1](001-bluejoule-gatt-definition.md)]
- Uses LE Secure Connections / Just Works.
- Pairs on every connection; no bonding.
- Encrypts before GATT discovery.
- Retains the original `Command` write and `Status` read.
- Prepares local P-256 key pairs before connection.
- Includes ECDH and pairing calculations in the measured transaction.
- Uses a Zephyr Central on the nRF52 DK.
- Uses BLE 1M PHY and a 7.5 ms connection interval.
- Repeats at nominal one-second cadence.
- Measures peripheral connection energy, excluding advertising.
- Describes the workload; publishes no official score.
- Does not establish production security or Bluetooth qualification.

[← EM•Reports index](README.md)

## Related Reports

- [EMR 1 — BlueJoule-GATT v0 Definition](001-bluejoule-gatt-definition.md)
- [EMR 2 — Zephyr Reference Implementation](002-zephyr-reference-implementation.md)
- [EMR 4 — EM•Scope Measurement Workflow](004-emscope-measurement-workflow.md)

## 1. What Changes from BlueJoule-GATT?

The original benchmark measures a short BLE peripheral connection transaction: targeted discovery, one write, one read, and clean disconnect. BlueJoule-GATT-Secure preserves that application work and adds the cost of establishing an encrypted link on each connection.

| Aspect | BlueJoule-GATT | BlueJoule-GATT-Secure |
| --- | --- | --- |
| Service and characteristics | Known UUIDs, discovered handles | Unchanged |
| Application work | Write `Command`, read `Status` | Unchanged |
| Pairing | Not part of the workload | LE Secure Connections on every connection |
| Link encryption | Not part of the workload | Established before discovery and application traffic |
| Bonding / stored LTK reconnection | Not applicable | Disabled |
| Measured quantity | Peripheral connection energy | Peripheral connection energy, including pairing and encryption setup |

The name identifies the added security procedure, not an authenticated-peer security level. **Just Works provides an encrypted link without man-in-the-middle-authenticated peer identity.** Passkey Entry, Numeric Comparison and Out-of-Band association are outside this workload.

## 2. The Transaction

```text
Outside the measured connection
    initialize the implementation and prepare its local P-256 key pair
    advertise the BlueJoule-GATT service; Central scans and connects

Measured connection transaction
    connection establishment and required Link Layer exchanges
    SMP Pairing Request / Response
    exchange P-256 public keys and compute the ECDH shared secret
    Pairing Confirm / Random exchange
    derive MacKey / LTK and exchange DHKey Checks
    establish Link Layer encryption
    discover the BlueJoule-GATT service and its characteristics
    write Command, receive the write response
    read Status, check the returned value
    disconnect and return toward idle / sleep

Outside the measured connection
    wait for the next benchmark cycle
```

This is a logical overview, not a requirement to serialize computation and every packet exactly as drawn. An implementation may overlap ECDH with public-key transmission, use multiple packet exchanges in a connection event, or organize the work differently while preserving protocol dependencies and the application result.

The measured computation includes the pairing functions f4, f5 and f6, session-key derivation, and packet encryption/authentication needed to complete the transaction. This is not an isolated elliptic-curve benchmark.

## 3. Application Profile Remains Unchanged

The peripheral advertises connectably, includes the benchmark service UUID in its primary advertising packet, and transmits at 0 dBm. The initial reference uses advertising channel 37 only to simplify sniffer acquisition; advertising energy is not scored.

| Attribute | UUID | Application operation |
| --- | --- | --- |
| Primary service | `0000b100-0000-1000-8000-00805f9b34fb` | Targeted service discovery |
| Status characteristic | `0000b101-0000-1000-8000-00805f9b34fb` | Read |
| Command characteristic | `0000b102-0000-1000-8000-00805f9b34fb` | Write with response |

The reference transaction writes the single byte `0x04` and expects the single-byte Status value `0x84`. The peripheral updates Status from the command with its high bit set.

The Central discovers handles on each connection; it does not use hard-coded handles or a persistent GATT cache. It locates the service by UUID and discovers characteristics within that service, rather than browsing unrelated services.

The secure Zephyr peripheral requires an encrypted link for the application read and write. Service and characteristic declarations remain discoverable without those application-value permissions, but the reference Central deliberately waits for successful encryption before starting discovery. This fixes the transaction order rather than relying on an access-denied response to initiate pairing.

## 4. Reference Central and Secure Configuration

The reference Central is the existing Zephyr BlueJoule-GATT application with a bounded secure variant:

1. On connection, request encryption with `bt_conn_set_security(conn, BT_SECURITY_L2)`.
2. Wait for the security callback to report success at level 2 or higher; disconnect on failure.
3. Run the original discover / write / read / disconnect transaction.

The reference connection parameters are BLE 1M PHY, a 7.5 ms connection interval, zero peripheral latency and a 4 s supervision timeout. Automatic PHY and data-length updates are disabled in the reference Central configuration. These conditions do not prescribe an identical number of events or packets for every candidate implementation.

Both secure Zephyr variants add the following configuration fragment after their ordinary platform configuration:

```ini
CONFIG_BT_SMP=y
CONFIG_BT_SMP_SC_PAIR_ONLY=y
CONFIG_BT_SMP_SC_ONLY=n
CONFIG_BT_BONDABLE=n
CONFIG_BT_SETTINGS=n
```

These are the actual reference settings, not a portable configuration recipe for every stack or Zephyr release. `BT_SMP_SC_PAIR_ONLY` selects Secure Connections pairing; the separate `BT_SMP_SC_ONLY` option is not enabled in these builds. No user-interaction authentication callbacks are registered for this Just Works workload. Ordinary console/logging output is disabled for power measurements. The resolved build configuration, not the fragment alone, is the authority when reproducing an implementation.

The reference firmware may run continuously; measurement does not require it to halt after a fixed number of connections. The initial reference builds use nRF Connect SDK 3.0.2 / Zephyr `v4.0.99-ncs1-2`.

## 5. Key Preparation and Per-Pairing Work

**Public-key exchange is not public-key generation.** The former happens on each benchmark pairing; the latter is deliberately outside the measured connection.

The reference Zephyr lifecycle prepares a P-256 key pair during Bluetooth initialization and retains it across ordinary pairings. The EM•Script candidate likewise prepares its public key at runtime startup. This makes the steady-state comparison consistent: neither side is charged for local public-key generation inside each transaction.

Each pairing still computes ECDH using the peer's public key and performs the confirm, key-derivation and DHKey-check procedures. No bonding means the result is not replaced on the next connection by a stored-LTK reconnection.

Key preparation and eventual rotation consume time and energy. Excluding them defines the **connection benchmark**, not a claim about total lifetime energy. A product-level measurement must account for those costs separately and state its key-refresh policy.

Reused key pairs and fresh pairing nonces are distinct choices. The Zephyr reference generates a fresh nonce per pairing. The current EM•Script bring-up implementation still uses disclosed deterministic key/nonce and encryption-setup fixtures. They support repeatable interoperability and packet decoding, but are not production security policy. Such fixtures must be disclosed with candidate results; this report does not establish security equivalence between those implementations.

## 6. Measurement and Reporting Boundary

Repeat transactions at nominal one-second cadence, allowing the peripheral to return to idle between them. Exact connection-start spacing may vary with advertising and scanning. An advertising-attempt counter is not a count of verified completed secure transactions.

Engineering captures support energy statistics, waveform comparisons and protocol analysis. They are not automatically official BlueJoule scoring runs. The ten-transaction scoring procedure is a separate use of this workload; no official BlueJoule / EM•erald score is published here.

Measure peripheral energy from connection establishment through completion, termination and return toward idle. Exclude startup/key-pair preparation, preceding advertising, the Central's own consumption, and the inter-connection wait. Record the actual waveform or packet-aligned trimming convention: a power-defined boundary is not automatically identical to the timestamp of CONNECT_IND or LL_TERMINATE_IND.

Report energy per completed transaction, preferably in µJ, with the averaging method, spread and sample count. Retain unusually expensive completed transactions; do not silently select only the lowest-energy passes. Identify failed, incomplete or capture-truncated attempts separately. Duration and connection-event count are useful explanatory measurements, not fixed success criteria.

At minimum, record:

- Peripheral and Central hardware.
- Firmware revisions and software versions.
- Actual DUT voltage, wiring and TX power.
- PHY, interval and peripheral latency.
- Pairing and bonding settings.
- Key-preparation boundary and test fixtures.
- Logging and instrumentation state.
- Integration boundaries and completed-transaction count.
- Energy statistics, failures and retries.
- Evidence of encryption and the expected application result.

The initial engineering comparisons use 3.0 V and a Joulescope JS220. USB-powered captures at a different DUT voltage are not interchangeable controls, even when the firmware is identical. The measurement approach builds on [EMR 4](004-emscope-measurement-workflow.md).

## 7. Packet Evidence and Scope

A useful verification trace covers connection establishment, Secure Connections public-key exchange and DHKey checks, Link Layer encryption start, the encrypted application transaction, and normal termination. The decrypted application read should agree with the Central's expected Status value.

Nordic Sniffer and Wireshark were used during development. Decoding encrypted traffic requires appropriate test key material and enough of the pairing exchange. A sniffer's BAD MIC indication alone does not prove that either peer rejected a packet: missing key material, capture loss and decoder state must first be distinguished from an actual authentication failure.

This overview uses the transaction diagram rather than a single implementation-specific packet screenshot. Detailed trace interpretation, timing, code footprint and power comparisons belong in implementation/result reports. Benchmark completion does not establish general encrypted throughput, robustness under every loss pattern, Bluetooth qualification, or production resistance to attacks.

## 8. Snapshot and Reference-Artifact Status

As of this report date, **a dedicated BlueJoule-GATT-Secure repository does not exist**. The working reference applications and captures are retained locally; decisions about their durable publication location and access remain open. This report therefore provides no speculative repository link and does not imply that the reference code is presently available to readers.

BlueJoule-GATT-Secure is the name used here for the benchmark extension. This report is a dated overview of its current workload and assumptions, not a maintained formal specification or a commitment to a future repository layout.

