# EMR 1 — BlueJoule-GATT v0 Definition

**First recorded:** 2026-05-26  
**Status:** Legacy report — imported into the EM•Report series  
**Origin:** BlueJoule-GATT Dev — archived private development repository  
**Original milestone:** Candidate benchmark definition



> Imported into EM•porium with technical content preserved. Historical results have not been revalidated; exact firmware provenance is incomplete.

## TLDR

- BlueJoule-GATT is a BLE connection benchmark.
- It complements the original BlueJoule advertising benchmark.
- The benchmark measures a short GATT transaction, not advertising.
- The peripheral advertises a custom BlueJoule-GATT service.
- The peripheral advertises connectably.
- The service UUID appears in the primary advertising packet.
- The peripheral transmits at 0 dBm.
- The central connects, discovers handles, writes `Command`, reads `Status`, and disconnects.
- UUIDs use the Bluetooth base-UUID form: service `0xB100`, status `0xB101`, command `0xB102`.
- The central uses targeted discovery, not full generic GATT browsing.
- UUIDs are known by the central; handles are discovered at runtime.
- The scored window excludes the advertising period before connection.
- The goal is a repeatable connection-energy impulse suitable for EM•Scope / BlueJoule scoring.

## 1. Benchmark Purpose

BlueJoule-GATT measures the energy required for a BLE peripheral to complete a short, repeatable, application-level GATT transaction.

The benchmark is intended to capture the cost of:

- connection establishment
- minimal link-layer control traffic
- targeted GATT discovery
- one application write
- one application read
- clean disconnect
- return toward idle/sleep

This differs from the original BlueJoule advertising benchmark, which primarily measures a fixed advertising event. BlueJoule-GATT measures bounded protocol work during an actual BLE connection.

## 2. Benchmark Profile

The peripheral exposes one custom primary service:

```text
BlueJoule-GATT Service
    UUID: 0000b100-0000-1000-8000-00805f9b34fb
```

The service contains two characteristics:

```text
Status Characteristic
    UUID: 0000b101-0000-1000-8000-00805f9b34fb
    Properties: read

Command Characteristic
    UUID: 0000b102-0000-1000-8000-00805f9b34fb
    Properties: write
```

The `Command` characteristic is written by the benchmark central.

The `Status` characteristic is read by the benchmark central after the command write.

## 3. Peripheral Advertising

The peripheral shall advertise connectably.

The peripheral shall include the BlueJoule-GATT Service UUID in the primary advertising packet.

This lets the benchmark central discover candidate peripherals without hard-coded device addresses.

The peripheral may provide a scan response.

The scan response may include a local name, such as:

```text
BlueJoule-GATT
```

The peripheral shall transmit at 0 dBm.

This applies to peripheral transmissions during both advertising and the connection transaction.

Advertising energy is not included in the scored BlueJoule-GATT connection window.

## 4. Central Transaction

The benchmark central performs this fixed transaction:

```text
scan for advertised BlueJoule-GATT service UUID
connect
perform required minimal BLE link-layer exchanges
discover BlueJoule-GATT service by UUID
discover Command and Status characteristics within that service
write Command
read Status
disconnect cleanly
```

The central knows the service and characteristic UUIDs.

The central does not know handles in advance. It discovers handles during the transaction.

## 5. Discovery Model

BlueJoule-GATT uses targeted discovery.

The central discovers only the benchmark service and the characteristics inside that service.

The central does not perform full generic GATT enumeration over `0x0001..0xffff`.

The central does not enumerate unrelated GAP, GATT, Device Information, vendor, or stack-default services.

Those services may exist on the peripheral, but they are not part of the benchmark transaction.

## 6. Handle Model

The central must not use hard-coded handles.

The benchmark uses:

```text
known UUIDs
discovered handles
```

A peripheral implementation may use fixed/static handles internally.

That internal choice is not visible to the benchmark central and is not constrained by this definition.

## 7. Measurement Window

The scored measurement window covers the connection transaction only.

It starts when the peripheral accepts the connection / enters the benchmark connection window.

It ends after the benchmark transaction completes, the connection is terminated, and the peripheral returns toward its idle or sleep state.

The advertising period before connection is excluded.

Expected current-class transaction duration is roughly:

```text
115–125 ms
15–17 connection events
```

These values are descriptive, not normative.

## 8. Scored Metric

The primary score should be energy per completed transaction.

Preferred reporting unit:

```text
joules per completed BlueJoule-GATT transaction
```

For engineering notes, smaller units such as µJ may be used for readability.

Charge may also be reported when useful, but final BlueJoule-style scoring should be based on energy.

At fixed voltage, energy can be estimated as:

```text
energy = charge × voltage
```

The scored energy covers only the connection transaction. Advertising energy before the connection is excluded.

## 9. Required Reported Conditions

A benchmark result should report:

- peripheral hardware
- central hardware
- central firmware/software version
- peripheral software/stack
- supply voltage
- TX power setting
- connection interval
- measured transaction duration
- number of connection events, if available
- packet trace or packet-count summary, if available
- whether advertising was excluded from the score

## 10. Fairness Model

The benchmark fixes the central transaction.

It does not require all peripherals to use the same internal implementation strategy.

A conventional stack may implement the benchmark profile using generic GATT tables, callbacks, framework services, and scheduler paths.

A specialized implementation may compile the benchmark profile into fixed handles, compact constants, direct dispatch paths, and statically sized buffers.

Both are valid if the peripheral exposes the required profile and completes the benchmark transaction correctly.

Differences in response latency, connection-event count, empty packets, scheduler overhead, and cleanup time are measured outcomes.

## 11. Current v0 Scope

This v0 definition covers:

- BLE peripheral role
- BLE 1M PHY
- BLE 4.2-style connection behavior
- custom BlueJoule-GATT service
- connectable advertising with the BlueJoule-GATT Service UUID
- peripheral transmissions at 0 dBm
- targeted service discovery
- targeted characteristic discovery
- write `Command`
- read `Status`
- clean disconnect
- energy measurement of the connection transaction only

This v0 definition does not cover:

- full generic GATT browsing
- pairing or encryption
- notifications
- sustained connected idle
- mobile-app-driven timing
- known-handle proprietary profiles
- advertising-energy scoring

## 12. Path to 1.0

Remaining work toward a stable BlueJoule-GATT 1.0 definition:

- finalize automated EM•Scope measurement flow
- automate repeated one-second-style benchmark cycles
- trim captured current data to isolate connection transactions
- standardize result reporting
- document reference packet traces
- document reference implementations and candidate results

<p align="right">
  <sub>
    drafted with ChatGPT &ndash; reviewed/approved by
    <a href="https://github.com/biosbob">@biosbob</a>
  </sub>
</p>
