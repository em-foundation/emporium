# EM•Reports

Reports 1–9 originated in BlueJoule-GATT Dev, an archived private development repository, before the EM•Report convention was established. They are preserved here as legacy technical snapshots. Import changes are limited to identity, provenance, presentation, and links; historical technical content is preserved and results have not been revalidated. Exact firmware revisions for the reported measurements were not consistently recorded.

For reports 1–9, dates below are the first recorded commits in the original development history, rather than measurement dates or dates of import. Reports 001 and 003 originally carried 2026-05-25 in their filenames; their first recorded commits are dated 2026-05-26. Newly authored reports use their report date; each report states its own provenance and draft status where applicable.

## Table of Contents

| Report | Date | Title | Description |
| --- | --- | --- | --- |
| EMR&#160;001 | 2026&#8209;05&#8209;26 | [BlueJoule-GATT v0 Definition](001-bluejoule-gatt-definition.md) | Defines the benchmark profile, central/peripheral requirements, discovery model, measurement window, and scoring intent. |
| EMR&#160;002 | 2026&#8209;05&#8209;26 | [Zephyr Reference Implementation](002-zephyr-reference-implementation.md) | Documents the Zephyr central/peripheral reference implementation, tested hardware, build flow, packet trace, and baseline measurement. |
| EMR&#160;003 | 2026&#8209;05&#8209;26 | [EM•Script Candidate Implementation](003-emscript-candidate-implementation.md) | Documents the EM•Script candidate implementation and same-hardware comparison against the Zephyr reference. |
| EMR&#160;004 | 2026&#8209;05&#8209;27 | [EM•Scope Measurement Workflow](004-emscope-measurement-workflow.md) | Documents the automated repeated-measurement workflow and first EM•Scope scores. |
| EMR&#160;005 | 2026&#8209;05&#8209;30 | [nRF52 Results and Cross-Generation Comparison](005-nrf52-results-and-cross-generation-comparison.md) | Documents the nRF52 EM•Script port and the nRF52/nRF54 comparison. |
| EMR&#160;006 | 2026&#8209;06&#8209;02 | [Cache Statistics and Instruction-Fetch Pressure](006-cache-statistics-and-instruction-fetch-pressure.md) | Documents cache-statistics measurements comparing EM•Script and Zephyr. |
| EMR&#160;007 | 2026&#8209;06&#8209;11 | [TI CC2340R5 SimpleLink, Zephyr, and EM•Script Results](007-ti-cc2340r5-results.md) | Documents the TI CC2340R5 same-device comparison across SimpleLink, Zephyr, and EM•Script. |
| EMR&#160;008 | 2026&#8209;06&#8209;12 | [TI CC2340R5 Connection-Event Drilldown](008-ti-cc2340r5-connection-event-drilldown.md) | Examines a matched ATT Read Request event to show software-controlled active time. |
| EMR&#160;009 | 2026&#8209;06&#8209;30 | [nRF54 On-Chip Core Results: Cortex-M33 vs RISC-V](009-nrf54-on-chip-core-results-cortex-m33-vs-riscv.md) | Compares EM•Script BlueJoule-GATT on the nRF54 Cortex-M33 and FLPR RISC-V cores. |
| EMR&#160;010 | 2026&#8209;10&#8209;18 | [BlueJoule-GATT-Secure Definition](010-bluejoule-gatt-secure-definition.md) | Defines the secure benchmark extension, reference Central, pairing workload, and connection-energy measurement boundary. |
| EMR&#160;011 | 2026&#8209;10&#8209;18 | [nRF52 Secure GATT: Zephyr versus EM•Script](011-nrf52-secure-gatt-zephyr-vs-emscript.md) | Compares secure-GATT energy, timing, and memory footprints on nRF52. |
| EMR&#160;012 | 2026&#8209;10&#8209;21 | [nRF54 Secure GATT: Zephyr versus EM•Script](012-nrf54-secure-gatt-zephyr-vs-emscript.md) | Compares secure-GATT energy, timing, and memory footprints on the nRF54L15 Cortex-M33. |
| EMR&#160;013 | 2026&#8209;10&#8209;24 | [TI23 Secure GATT: Zephyr versus EM•Script](013-ti23-secure-gatt-zephyr-vs-emscript.md) | Preliminary comparison of secure-GATT energy, computation, and memory footprints on the TI CC2340R5. |
