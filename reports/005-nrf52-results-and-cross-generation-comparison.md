# EMR 5 — nRF52 Results and Cross-Generation Comparison

**First recorded:** 2026-05-30  
**Status:** Legacy report — imported into the EM•Report series  
**Origin:** BlueJoule-GATT Dev — archived private development repository  
**Original milestone:** Cross-generation results milestone

**Tooling:** EM•Scope v25.6.x

> Imported into EM•porium with technical content preserved. Historical results have not been revalidated; exact firmware provenance is incomplete.

## TLDR

- BlueJoule-GATT now has results across two Nordic hardware generations.
- The EM•Script peripheral has been ported from nRF54 to nRF52.
- The port was primarily in the nRF52 radio, timer, RTC, and platform layer.
- The portable controller/profile code remained largely unchanged.
- The Zephyr reference application is essentially unchanged across platforms.
- The same benchmark transaction was used on both nRF52 and nRF54.
- The same EM•Scope scoring method was used for all four measurements.
- EM•Script outperforms the Nordic/Zephyr reference on both platforms.
- nRF54 is substantially more efficient than nRF52 for both stacks.
- EM•Script shows a larger gain on nRF54 than on nRF52.
- The result strengthens BlueJoule-GATT as a cross-generation benchmark.
- The result strengthens the tiny-code claim beyond a single chip result.

At 3.0 V:

    Platform        Nordic/Zephyr    EM•Script    EM•Script gain
    nRF52 @ 3.0 V      28.16          30.44          +8.1%
    nRF54 @ 3.0 V      46.00          58.28         +26.7%

[← EM•Reports index](README.md)

## Related Reports

- [EMR 1 — BlueJoule-GATT v0 Definition](001-bluejoule-gatt-definition.md)
- [EMR 4 — EM•Scope Measurement Workflow](004-emscope-measurement-workflow.md)

## 1. Purpose

This report extends the earlier BlueJoule-GATT nRF54 results to nRF52, an earlier Nordic hardware generation.

The goal is to document the nRF52 EM•Script port, compare nRF52 and nRF54 measurements, and summarize the resulting four-way score matrix across two platforms and two software stacks.

The main question is whether the EM•Script advantage observed on Nordic’s current nRF54 flagship generation also appears on the earlier nRF52 generation using the same benchmark transaction and EM•Scope scoring method.

## 2. Measurement Set

This report compares four BlueJoule-GATT measurements:

    Platform        Stack
    nRF52 @ 3.0 V   Nordic/Zephyr reference
    nRF52 @ 3.0 V   EM•Script candidate
    nRF54 @ 3.0 V   Nordic/Zephyr reference
    nRF54 @ 3.0 V   EM•Script candidate

All four measurements use the same benchmark transaction:

    advertise
    connect
    targeted service discovery
    targeted characteristic discovery
    write Command
    read Status
    disconnect
    return to sleep
    repeat

All four measurements use EM•Scope scoring with the same connection-only benchmark model.

The scored event excludes the preceding advertising period and focuses on the BLE connection transaction itself.

## 3. nRF52 EM•Script Port Summary

The EM•Script BlueJoule-GATT peripheral was ported from nRF54 to nRF52.

The portable BLE controller, benchmark profile, and top-level BlueJoule-GATT behavior remained largely unchanged. The port was concentrated in the nRF52-specific radio, timer, RTC, and platform layer.

The nRF52 implementation now supports the full benchmark transaction:

    connectable advertising
    scan request / scan response
    CONNECT_IND reception
    BLE data-channel operation
    LL feature exchange
    targeted service and characteristic discovery
    Command write
    Status read
    LL terminate
    repeated EM•Scope capture/scoring

The nRF52 RTC path now provides the timing interface needed by the radio driver while internally using the 32.768 kHz RTC domain. Fine active timing, including scan-response turnaround, remains handled by the active timing path.

The resulting nRF52 EM•Script image remains in the same size class as the nRF54 implementation, with the current build at `text(4944), const(292), data(68), bss(204)`.

The completed port shows that the EM•Script BlueJoule-GATT implementation is not tied to the nRF54 radio driver.

## 4. Measurement Artifacts and Summary

Each measurement is represented by an EM•Scope-generated `ABOUT.md` report and representative event image.

Primary measurement artifacts:

- [nRF52 EM•Script candidate](assets/captures/nrf-52-dk/emscript-3V0-P/ABOUT.md)
- [nRF52 Nordic/Zephyr reference](assets/captures/nrf-52-dk/zephyr-3V0-P/ABOUT.md)
- [nRF54 EM•Script candidate](assets/captures/nrf-54-dk/emscript-3V0-P/ABOUT.md)
- [nRF54 Nordic/Zephyr reference](assets/captures/nrf-54-dk/zephyr-3V0-P/ABOUT.md)

The table below summarizes the 10-second BlueJoule-GATT score data extracted from those reports.

| Platform | Stack | Sleep Current | Event Energy | Energy / 10 s Period | Energy / Day | 10 s Score |
|---|---:|---:|---:|---:|---:|---:|
| nRF52 @ 3.0 V | Nordic/Zephyr | 1.2 µA | 293.0 µJ | 328.8 µJ | 2.8 J | 28.16 |
| nRF52 @ 3.0 V | EM•Script | 1.1 µA | 270.6 µJ | 304.2 µJ | 2.6 J | 30.44 |
| nRF54 @ 3.0 V | Nordic/Zephyr | 1.1 µA | 168.8 µJ | 201.3 µJ | 1.7 J | 46.00 |
| nRF54 @ 3.0 V | EM•Script | 0.9 µA | 131.4 µJ | 158.9 µJ | 1.4 J | 58.28 |

The 10-second score is used here because it represents a more realistic repeated-connection interval than a one-second connection cycle.

The nRF54 results were introduced in earlier reports. This report adds the corresponding nRF52 results and rolls all four measurements into one comparison.

## 5. Program Size

The score matrix captures energy behavior. Program size is a separate but important differentiator.

Current build sizes:

| Platform | Stack | Read-only memory | Read-write memory |
|---|---|---:|---:|
| nRF52 | Nordic/Zephyr | 108,840 B | 21,116 B |
| nRF52 | EM•Script | 5,236 B | 272 B |
| nRF54 | Nordic/Zephyr | 130,012 B | 25,644 B |
| nRF54 | EM•Script | 5,628 B | 284 B |

For Nordic/Zephyr, read-only memory is the reported flash size and read-write memory is the reported RAM size.

For EM•Script, read-only memory is `text + const`; read-write memory is `data + bss`.

The EM•Script implementations remain in the same roughly 5 KB read-only size class on both platforms.

This is a major part of the result: EM•Script scores higher while using dramatically less memory than the Nordic/Zephyr reference implementation.

## 6. Cross-Generation Comparison

The four measurements show two clear trends.

First, EM•Script scores higher than the Nordic/Zephyr reference on both platforms:

    nRF52 gain:  8%
    nRF54 gain: 27%

Second, nRF54 is substantially more efficient than nRF52 for both stacks:

    Nordic/Zephyr improvement: 63%
    EM•Script improvement:     91%

The EM•Script gain is larger on nRF54 than on nRF52. This may reflect more than radio efficiency alone. Smaller, more specialized code may benefit disproportionately on newer hardware with faster execution paths and better instruction-cache behavior.

That cache effect is not analyzed in this report, but it is an important follow-up topic. On nRF54, hardware cache statistics may make it possible to quantify whether the roughly 5 KB EM•Script image is materially more cache-friendly than the much larger Nordic/Zephyr image.

The comparison should also be read carefully. The Nordic/Zephyr implementation is a general-purpose BLE stack running in a full RTOS environment. The EM•Script implementation is profile-specialized and intentionally narrow.

That specialization is part of the point: BlueJoule-GATT measures what can be achieved when the software is built directly for the benchmark profile rather than routed through a general-purpose stack.

## 7. Interpretation

The nRF52 result shows that the EM•Script advantage is not unique to nRF54.

The same benchmark transaction now runs across two Nordic generations, using the same EM•Scope scoring method, and EM•Script scores higher on both platforms.

The result should be interpreted as a profile-specialized comparison. The Nordic/Zephyr reference uses a general-purpose BLE stack and RTOS environment. The EM•Script implementation is intentionally narrow, with the benchmark profile, packet paths, and retained state known at build time.

That specialization is the point of the comparison. BlueJoule-GATT is intended to show what becomes possible when the software is built directly around a small, fixed BLE transaction instead of routed through a general-purpose stack.

The nRF54 result remains the stronger energy result, but the nRF52 result is strategically important because it shows the same direction on an earlier Nordic platform.

## 8. Current Caveats

These are engineering results, not final BlueJoule-GATT 1.0 certification results.

The Nordic/Zephyr reference is a general-purpose BLE stack running in a full RTOS environment. It is not specialized only for this benchmark transaction.

The EM•Script implementation is intentionally profile-specific. It implements the narrow BlueJoule-GATT peripheral behavior needed for this benchmark.

That makes the comparison asymmetric, but not unfair. The asymmetry is part of what BlueJoule-GATT is intended to explore: how much energy and memory can be saved when the software is specialized for a small, fixed BLE transaction.

Current caveats:

- exact firmware commits should be recorded for published measurements
- Nordic/Zephyr build sizes may be reducible with further configuration work
- repeated Joulescope captures remain useful for sharper reference data
- nRF54 cache behavior is not analyzed in this report
- the benchmark definition may still evolve before BlueJoule-GATT 1.0

## 9. Closing Note

The nRF52 result turns BlueJoule-GATT from a single-platform comparison into a cross-generation Nordic comparison.

The same benchmark transaction now runs on both nRF52 and nRF54, with both the Nordic/Zephyr reference and EM•Script candidate measured using the same EM•Scope scoring method.

The result is consistent across both platforms: EM•Script is much smaller and scores higher.

This strengthens the BlueJoule-GATT proof of concept and provides a stronger basis for continued benchmark refinement and future public reporting.
