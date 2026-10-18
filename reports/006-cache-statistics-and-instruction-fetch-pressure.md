# EMR 6 — Cache Statistics and Instruction-Fetch Pressure

**First recorded:** 2026-06-02  
**Status:** Legacy report — imported into the EM•Report series  
**Origin:** BlueJoule-GATT Dev — archived private development repository  
**Original milestone:** Cache-statistics milestone

**Benchmark definition:** [`001-bluejoule-gatt-definition.md`](001-bluejoule-gatt-definition.md)  
**Cross-generation scores:** [`005-nrf52-results-and-cross-generation-comparison.md`](005-nrf52-results-and-cross-generation-comparison.md)  
**Tooling:** EM•Scope v25.6.x

> Imported into EM•porium with technical content preserved. Historical results have not been revalidated; exact firmware provenance is incomplete.

## TLDR

- BlueJoule-GATT now includes Nordic cache-statistics measurements.
- Measurements cover both nRF52 and nRF54.
- Each comparison is EM•Script versus Zephyr on the same board.
- The measured window is the same connection-only transaction.
- EM•Script shows less instruction-cache activity on both boards.
- EM•Script shows far fewer cache misses on both boards.
- On nRF54, Zephyr has 5.3× more cache reads.
- On nRF54, Zephyr has 27.9× more cache misses.
- On nRF52, Zephyr has 1.7× more cache reads.
- On nRF52, Zephyr has 14.7× more cache misses.
- Same-board comparisons are the meaningful comparisons.
- The data supports the tiny-code locality claim.

## 1. Purpose

This report examines instruction-cache behavior during the BlueJoule-GATT connection benchmark.

Earlier reports showed that the EM•Script implementation is smaller and scores higher than the Zephyr reference on both nRF52 and nRF54. This report looks at one possible reason: instruction-fetch pressure.

The goal is to compare EM•Script and Zephyr on the same Nordic hardware, using cache statistics collected during the same connection-only transaction window.

The focus is narrow: cache reads, cache hits, cache misses, and miss rate. Broader questions about instruction memory, SRAM execution, and future tiny-code processor design are left for later reports.

## 2. Measurement Window

Cache statistics were collected over the BlueJoule-GATT connection-only transaction window.

The measured window begins after the BLE connection is established and ends after the benchmark transaction completes:

    connection established
    start cache statistics
    GATT transaction
    disconnect
    stop cache statistics
    print statistics

Printing occurs outside the measured cache-statistics window.

This keeps the measurement focused on the BLE connection transaction rather than console output or reporting overhead.

## 3. Cache Counters

The cache-statistics instrumentation records a small set of counters over the measured transaction window:

    cache reads
    cache hits
    cache misses
    miss rate

The exact counter implementations differ between nRF52 and nRF54, so absolute counts should not be compared across hardware generations.

The meaningful comparisons are same-board:

    nRF54 Zephyr versus nRF54 EM•Script
    nRF52 Zephyr versus nRF52 EM•Script

This keeps the comparison focused on software behavior under the same cache architecture.

## 4. Cache Results

The cache counters should be compared only within the same hardware platform.

Same-board summary:

| Board | Cache reads | Miss rate | Cache misses |
|---|---:|---:|---:|
| nRF54 | Zephyr 5.3× higher | 26.6% vs 5.1% | Zephyr 27.9× higher |
| nRF52 | Zephyr 1.7× higher | 21.6% vs 2.5% | Zephyr 14.7× higher |

Raw counter data:

| Board | Stack | Cache reads | Cache hits | Cache misses | Miss rate |
|---|---|---:|---:|---:|---:|
| nRF54 | Zephyr | 10,756 | 7,887 | 2,869 | 26.6% |
| nRF54 | EM•Script | 2,014 | 1,910 | 103 | 5.1% |
| nRF52 | Zephyr | 207,126 | 162,314 | 44,812 | 21.6% |
| nRF52 | EM•Script | 122,252 | 119,194 | 3,058 | 2.5% |

On both boards, EM•Script produces less cache activity and far fewer cache misses during the same BlueJoule-GATT connection transaction.

The nRF54 result is especially strong: Zephyr produces more than five times as many cache reads and nearly twenty-eight times as many cache misses as EM•Script.

The nRF52 result shows the same direction: Zephyr produces more cache reads and nearly fifteen times as many cache misses as EM•Script.

## 5. Interpretation

The cache statistics suggest two related effects.

First, EM•Script produces less cache-read activity during the measured transaction window. This suggests less instruction-fetch work for the same BlueJoule-GATT connection transaction.

Second, EM•Script produces a much lower miss rate. This suggests better locality from a smaller, more specialized working set.

Together, these results support the tiny-code locality claim: a profile-specialized implementation can reduce both the amount of code fetched and the cost of fetching it.

This does not prove that cache behavior explains all of the EM•Script energy advantage. It does show that instruction-fetch pressure is meaningfully lower for EM•Script on both Nordic platforms tested.

## 6. Measurement Caveats

These measurements come from instrumented builds, not the final low-power scoring builds.

The instrumentation is kept outside the measured cache window where possible:

    start cache statistics
    run connection transaction
    stop cache statistics
    print statistics

Printing occurs after the counters have been stopped.

Even so, enabling cache-statistics and console support can change code layout and build behavior. The results should therefore be treated as comparative evidence, not as a replacement for the power-scoring measurements in earlier reports.

The strongest conclusions are same-board comparisons:

    nRF54 Zephyr versus nRF54 EM•Script
    nRF52 Zephyr versus nRF52 EM•Script

The data should not be read as an absolute architectural comparison between nRF52 and nRF54.

## 7. Build Configurations

Cache statistics are collected using separate instrumented builds.

The Zephyr/NCS peripheral now has four working build configurations:

| Build | Purpose |
|---|---|
| `build_power_52` | nRF52 low-power scoring build |
| `build_stats_52` | nRF52 cache-stat / logging build |
| `build_power_54` | nRF54 low-power scoring build |
| `build_stats_54` | nRF54 cache-stat / logging build |

Power builds disable UART, console, printk, and cache reporting.

Stats builds enable UART, console, printk, and `CONFIG_BLUEJOULE_CACHE_STATS`.

The purpose is to keep power scoring and cache-stat collection separate, so the reporting build does not become the benchmark scoring build.

Build commands:

    # nRF52 power
    west build --build-dir build_power_52 . --pristine --board nrf52dk/nrf52832 -- -DCONF_FILE='prj.conf;prj_nrf52.conf' -DDTC_OVERLAY_FILE=boards/nrf52dk_nrf52832_power.overlay

    # nRF54 power
    west build --build-dir build_power_54 . --pristine --board nrf54l15dk/nrf54l15/cpuapp -- -DCONF_FILE='prj.conf' -DEXTRA_DTC_OVERLAY_FILE=boards/nrf54l15dk_nrf54l15_cpuapp_power.overlay

    # nRF52 stats
    west build --build-dir build_stats_52 . --pristine --board nrf52dk/nrf52832 -- -DCONF_FILE='prj.conf;prj_nrf52.conf;prj_cache.conf'

    # nRF54 stats
    west build --build-dir build_stats_54 . --pristine --board nrf54l15dk/nrf54l15/cpuapp -- -DCONF_FILE='prj.conf;prj_cache.conf'

The Nordic VS Code extension may generate longer commands with debug-thread options. Those options are not part of the benchmark definition and are omitted here.

## 8. Closing Note

The cache-statistics results add a new dimension to the BlueJoule-GATT comparison.

Earlier reports showed that EM•Script is smaller and scores higher than Zephyr on both nRF52 and nRF54. This report shows that EM•Script also creates less instruction-cache activity and far fewer cache misses during the same connection transaction.

That does not replace the power measurements, but it helps explain them.

The result strengthens the tiny-code argument: small, profile-specialized software can reduce memory footprint, reduce instruction-fetch pressure, and contribute to lower active energy.

<p align="right">
  <sub>
    drafted with ChatGPT &ndash; reviewed/approved by
    <a href="https://github.com/biosbob">@biosbob</a>
  </sub>
</p>
