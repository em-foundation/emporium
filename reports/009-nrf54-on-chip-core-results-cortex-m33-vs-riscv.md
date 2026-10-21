# EMR 9 — nRF54 On-Chip Core Results: Cortex-M33 vs RISC-V

**First recorded:** 2026-06-30  
**Status:** Legacy report — imported into the EM•Report series  
**Origin:** BlueJoule-GATT Dev — archived private development repository  
**Original milestone:** Results milestone

**Related FLPR strategy:** `L2 260619 nRF54 RISC-V EMS Strategy`  
**Tooling:** EM•Scope v25.6.x, Joulescope

> Imported into EM•porium with technical content preserved. Historical results have not been revalidated; exact firmware provenance is incomplete.

## TLDR

- BlueJoule-GATT now runs on both nRF54 EM•Script targets.
- The comparison is Cortex-M33 vs RISC-V FLPR.
- Both targets share the same BlueJoule-GATT logic, BLE controller, and most nRF54 low-level EM•Script drivers.
- Cortex-M33 EM•Script score: **60.82 EM•eralds**.
- RISC-V FLPR EM•Script score: **60.83 EM•eralds**.
- Both targets measured **152.2 µJ** per 10 s scoring period.
- Representative event energy is effectively identical: **129.6 µJ** M33 vs **129.7 µJ** FLPR.
- The FLPR image is about **31% larger** than M33, better than the rough **40%** overhead seen or expected in earlier FLPR work.
- The FLPR image fits comfortably inside one retained 16 KB SRAM block.
- Key result: same-class energy from Arm and RISC-V, with a tiny retained-SRAM FLPR image.

[← EM•Reports index](README.md)

## Related Reports

- [EMR 1 — BlueJoule-GATT v0 Definition](001-bluejoule-gatt-definition.md)
- [EMR 4 — EM•Scope Measurement Workflow](004-emscope-measurement-workflow.md)
- [EMR 5 — nRF52 Results and Cross-Generation Comparison](005-nrf52-results-and-cross-generation-comparison.md)

## 1. Purpose

This report compares two EM•Script BlueJoule-GATT targets inside the Nordic nRF54L15:

- the Cortex-M33 application core
- the RISC-V FLPR core

FLPR stands for **fast lightweight peripheral processor**. In the nRF54L15, it is an on-chip RISC-V coprocessor that can access much of the same peripheral set as the main application core.

The purpose is to show how the same BLE connection benchmark behaves when moved from the Arm application core to the RISC-V FLPR core.

This is also a portability test. The FLPR target is not a separate hand-written BLE implementation. It reuses the same BlueJoule-GATT logic, the same portable BLE controller path, and most of the same nRF54 low-level EM•Script driver code.

The narrow question is:

> Can the same tiny EM•Script BLE workload run on both nRF54 execution cores with comparable energy, timing, and size?

The measured answer is yes.

## 2. Why This Comparison Matters

The nRF54L15 contains more than one useful execution target.

The existing nRF54 EM•Script BlueJoule-GATT result runs on the Cortex-M33 application core. This report adds the RISC-V FLPR core as a second EM•Script target inside the same device family.

That makes the comparison unusually clean: same device family, same radio environment, same benchmark workload, different execution core.

The FLPR core is not normally positioned as an alternative BLE application processor. It is better understood as a lightweight on-chip processor for peripheral-side work, front-end processing, and virtual-peripheral style use cases.

Technically, FLPR can access the broader nRF54 memory address space, including the ability to execute from flash. But the natural and interesting FLPR operating point is small SRAM-resident code. In that model, one retained 16 KB SRAM block is a useful practical boundary.

BlueJoule-GATT is small enough to fit that model. It does not require a full general-purpose BLE stack. It requires a bounded BLE peripheral path: advertise, connect, complete targeted discovery, accept a `Command` write, serve a `Status` read, disconnect, and repeat.

A conventional BLE stack would be hard to imagine inside that small SRAM-resident envelope. The EM•Script result changes that assumption.

## 3. nRF54 Execution Targets

This report compares two EM•Script execution targets inside the nRF54L15.

The **Cortex-M33 application core** is the main application processor and the target used for the existing nRF54 EM•Script BlueJoule-GATT result.

The **RISC-V FLPR core** is the fast lightweight peripheral processor. Nordic / Zephyr target naming roughly corresponds to:

```text
cpuapp   Cortex-M33 application core
cpuflpr  RISC-V FLPR core
```

This report uses **Cortex-M33 application core** and **RISC-V FLPR core** for readability outside Nordic-specific tooling.

The two targets are different processor architectures, but both can access much of the same nRF54 peripheral set. That matters because the FLPR result does not require a separate radio stack or a separate device-driver universe.

The FLPR execution model uses a small Cortex-M33 launcher. The launcher performs the required setup, prepares the FLPR image, starts the FLPR core, and then enters a low-power idle state. During the benchmark, the BlueJoule-GATT workload runs on FLPR; the M33 is not part of the active benchmark path.

For this experiment, the FLPR image runs from SRAM and is packed into one retained 16 KB SRAM block.

## 4. Shared Implementation

All EM•Script BlueJoule-GATT builds share substantial portable code: application logic, GATT profile, portable BLE controller, connection-management logic, and benchmark transaction.

Normally, the largest target-specific differences appear lower in the stack: radio driver code, device-driver code, interrupts, clocks, timers, and startup.

The nRF54 Cortex-M33 / FLPR comparison is unusual because the sharing extends much farther down into the device layer.

Both builds reuse the same nRF54 EM•Script peripheral-facing modules wherever practical, including:

- nRF54 RADIO driver
- nRF54 GPIO driver
- real-time clock and timing support
- crystal and clock-control support
- common interrupt abstractions
- most low-level nRF54 device support used by the benchmark

The FLPR-specific code is concentrated where the execution environment is genuinely different:

- FLPR startup
- M33 launcher and handoff
- linker layout and retained-SRAM placement
- FLPR interrupt entry details
- FLPR-specific sleep management

This makes the comparison stronger. The Cortex-M33 and FLPR builds are mostly the same EM•Script BLE workload and the same nRF54 EM•Script device code compiled for two different execution cores.

## 5. Measurement Setup

The Cortex-M33 and FLPR measurements use the standard BlueJoule-GATT workflow.

The benchmark transaction is the same one used throughout the report series:

```text
connect
discover service
discover characteristics
write Command
read Status
disconnect
```

Advertising is required to establish the connection, but the scored BlueJoule-GATT window excludes the preceding advertising period.

The peripheral runs on the nRF54L15 DK. The central is the same deterministic BlueJoule-GATT central used for the existing benchmark runs. It scans for the BlueJoule-GATT service UUID, connects, performs targeted discovery, writes `Command`, reads `Status`, and disconnects.

Both nRF54 EM•Script targets use the same 10 s event-period EM•Scope score used for the other BlueJoule-GATT targets.

The Cortex-M33 and FLPR results were taken back-to-back using the current EM•Script nRF54 codebase. That matters because the nRF54 EM•Script implementation evolved during FLPR bring-up, and most of that code is shared between the two targets.


## 6. Score and Energy Results

The headline result is that the current Cortex-M33 and FLPR EM•Script builds are effectively identical within measurement resolution.

| Platform | Implementation | 10 s Score | EM•Scope | Notes |
|---|---|---:|---|---|
| nRF54 | EM•Script / Cortex-M33 | 60.82 EM•eralds | [report](assets/captures/nrf-54-dk/emscript-m33-3V0-p/ABOUT.md) | Current codebase; back-to-back with FLPR |
| nRF54 | EM•Script / RISC-V FLPR | 60.83 EM•eralds | [report](assets/captures/nrf-54-dk/emscript-flpr-3V0-P/ABOUT.md) | Current codebase; back-to-back with Cortex-M33 |
| nRF54 | EM•Script / Cortex-M33 | 58.28 EM•eralds | [report](assets/captures/nrf-54-dk/emscript-3V0-P/ABOUT.md) | Prior published run on earlier codebase |
| nRF54 | Zephyr / Cortex-M33 | 46.00 EM•eralds | [report](assets/captures/nrf-54-dk/zephyr-3V0-P/ABOUT.md) | Existing nRF54 Zephyr reference |


The most important comparison is the current-codebase EM•Script pair:

```text
Cortex-M33 application core:  60.82 EM•eralds
RISC-V FLPR core:             60.83 EM•eralds
```

For practical purposes, those results are the same.

The underlying EM•Scope energy numbers show the same result:

```text
Target                  Sleep Power   Event Energy   Energy / 10 s Period   10 s Score
---------------------   -----------   ------------   --------------------   ----------
Cortex-M33 EM•Script       2.3 µW       129.6 µJ          152.2 µJ           60.82 EM•eralds
RISC-V FLPR EM•Script      2.3 µW       129.7 µJ          152.2 µJ           60.83 EM•eralds
```

The prior 58.28 EM•erald Cortex-M33 result remains useful historical context, but it should not be mixed with the current FLPR result to infer a core-to-core difference. During FLPR bring-up, the shared nRF54 EM•Script codebase continued to evolve, and the current Cortex-M33 build was rerun back-to-back with the FLPR build.

The Zephyr row is included as the existing nRF54 general-purpose stack reference. There is no Zephyr FLPR BlueJoule-GATT result in this report.

Because the score, event energy, period energy, and sleep power are all essentially identical, this report does not include a separate matched-event drilldown. Previous BlueJoule-GATT reports used event drilldowns when the traces exposed a clear software-path difference. Here, nothing material separates the two nRF54 EM•Script targets at the event-energy level.

## 7. Program Size and Retained SRAM

The energy result is effectively tied. The main architectural difference is program size.

```text
Target                  Text     Const    Data    BSS     Total
---------------------   ------   ------   -----   -----   ------
Cortex-M33 EM•Script     6212 B    284 B    68 B   216 B   6780 B
RISC-V FLPR EM•Script    8204 B    384 B    68 B   216 B   8872 B
```

The FLPR image is larger, as expected for this RISC-V target.

```text
FLPR text overhead:        about 32%
FLPR total-size overhead:  about 31%
```

That result is better than the rough 40% overhead seen or expected in some earlier FLPR sizing work. Some of the improvement reflects prior FLPR distro-shaping work: common-code reuse, reduced target-specific overhead, and keeping FLPR-specific support concentrated in startup, launch, retained-memory layout, interrupt entry, and sleep management.

The FLPR build also fits comfortably inside the practical retained-SRAM target used for this experiment.

```text
practical retained-SRAM target:  about 15 KB
observed FLPR image footprint:   about 8.9 KB
```

That means the full EM•Script BlueJoule-GATT peripheral path fits in one retained 16 KB SRAM block with meaningful headroom.

The FLPR execution model includes a small Cortex-M33 launcher written in EM•Script. The launcher is less than 400 bytes of generated code. It packages with the FLPR payload as a single loadable image, prepares the FLPR memory image, starts the FLPR core, and then leaves the benchmark workload running on FLPR.

This contrasts with the Zephyr FLPR launcher model, where the launcher image is on the order of 30 KB. The EM•Script launcher is not a second application framework; it is a tiny handoff mechanism.

The EM•Scope result is a whole-chip measurement. It is not measuring a FLPR rail or subtracting the rest of the SoC. After the EM•Script launcher starts FLPR, the Cortex-M33 enters a low-power idle state and is not part of the active benchmark path. The reported FLPR energy is therefore the energy of the nRF54 device as deployed: launcher idle, FLPR running the benchmark, and the shared radio/peripheral hardware active as needed.

The one-block SRAM result is not because FLPR is architecturally limited to 16 KB. The FLPR core can access the broader nRF54 memory address space, including the ability to execute from flash. The point is that a small SRAM-resident execution model is the natural and interesting operating point for this processor.

The result is a useful tiny-code demonstration: a real BLE connection benchmark, including the benchmark profile, controller path, radio-facing support, runtime state, and low-power execution path, fits inside the kind of small retained-memory envelope normally associated with peripheral-side firmware rather than BLE stack execution.

## 8. Interpretation

The main result is straightforward: for BlueJoule-GATT, the current EM•Script Cortex-M33 and FLPR builds are in the same measured energy class.

That was not the obvious outcome.

The Cortex-M33 application core is the normal place to run this kind of workload. The FLPR core is a secondary RISC-V processor intended for lighter-weight peripheral-side work. Yet the same EM•Script BLE benchmark runs on both targets and produces effectively identical energy results.

The result is meaningful because the implementation is shared. This is not a custom FLPR-only BLE stack and not a separate FLPR-only radio path. It is mostly the same EM•Script application, BLE controller, connection logic, and nRF54 device support compiled for two different instruction-set architectures.

The size result is the main visible architectural difference. The FLPR build is about 31% larger than the Cortex-M33 build, but still only about 8.9 KB. That is small enough to keep the complete benchmark workload inside the retained-SRAM operating point used for this experiment.

The combination is the real finding:

```text
same benchmark workload
same-class measured energy
different execution core
modest code-size penalty
tiny retained-SRAM footprint
```

This does not imply that FLPR should replace the Cortex-M33 as the general BLE host. It does show that a bounded, profile-specialized BLE workload can run on a secondary RISC-V core when the software is small enough.

For BlueJoule-GATT, the nRF54 result now has two meanings. It remains a benchmark result showing strong EM•Script energy performance on Nordic hardware. It is also a portability result showing that the same tiny BLE path can move from the Arm application core to the RISC-V FLPR core without a meaningful energy penalty.

## 9. RISC-V and Tiny-Code Architecture

The FLPR result also points toward a broader architecture discussion.

The point is not that the nRF54 FLPR core is the ideal processor for a BLE stack. It was designed as a lightweight on-chip processor for peripheral-side work, and this report should not be read as a claim that it should replace the Cortex-M33 application core.

The more interesting point is that FLPR is a RISC-V core inside a modern BLE SoC. RISC-V makes this kind of specialization easier to imagine. A processor can be shaped around a particular memory model, power model, peripheral role, or retained-state assumption more naturally than with a fixed commercial microcontroller core.

Tiny code changes the architecture question. If the hot software path is small enough, future MCUs may not need to assume that all meaningful protocol work requires a large general-purpose core, a large cache, or a large retained memory image.

Instead, some workloads may fit a different model:

```text
small staged runtime
small retained SRAM image
explicitly managed hot code
direct peripheral access
fast wake / short active window
return to low-power state
```

The nRF54 FLPR BlueJoule-GATT result is not proof of that future architecture. It is one data point.

But it is a useful one: a real BLE connection benchmark can run from a secondary on-chip RISC-V processor when the software is small enough.

## 10. Caveats

This report compares EM•Script on the nRF54 Cortex-M33 application core against EM•Script on the nRF54 RISC-V FLPR core. It does not include a Zephyr-on-FLPR result.

The Zephyr score included earlier is the existing nRF54 Cortex-M33 Zephyr reference. It provides useful context, but it is not a same-core comparison against FLPR.

The FLPR result should also not be interpreted as a general-purpose BLE stack claim. BlueJoule-GATT is a bounded benchmark transaction with a small custom profile. It exercises a real BLE connection path, but it is not a full general-purpose BLE host stack.

The result also does not address Bluetooth qualification or certification. The point of this report is measured benchmark behavior and EM•Script portability, not product qualification.

The retained-SRAM result should be interpreted carefully. FLPR is not architecturally limited to one 16 KB SRAM block, and it can access more of the nRF54 memory system. The important point is that this benchmark did not need more.

The score comparison should also be read within measurement resolution. The Cortex-M33 and FLPR scores are effectively identical. The result should not be reported as FLPR being meaningfully better than the Cortex-M33.

The earlier 58.28 EM•erald Cortex-M33 result remains historical context. This report uses the current back-to-back Cortex-M33 and FLPR measurements because they were taken from the same current EM•Script codebase.

Finally, the FLPR path is still new. Future work may improve RISC-V-specific code generation, startup, sleep, interrupt handling, or timing, in addition to common EM•Script improvements that benefit both nRF54 targets.

## 11. Closing Note

BlueJoule-GATT now has a same-chip Arm versus RISC-V result inside the Nordic nRF54 family.

The Cortex-M33 application core remains the normal execution target for this class of workload. The FLPR core is a secondary on-chip processor aimed at smaller peripheral-side tasks. Even so, the same EM•Script BlueJoule-GATT workload runs on both targets and produces effectively identical measured energy.

That is the important result.

The FLPR build is larger, but still small enough to fit comfortably inside the one-block retained-SRAM operating point used for this experiment. The launcher is tiny, the benchmark path is shared, and most of the nRF54 low-level EM•Script device code is reused.

This adds a new row to the BlueJoule-GATT matrix, but it also adds a stronger portability statement: EM•Script can carry a real BLE connection benchmark from the nRF54 Arm application core to the nRF54 RISC-V FLPR core without changing the basic benchmark workload or giving up energy performance.

For this report, the conclusion is simple:

```text
same nRF54 device family
same EM•Script BLE workload
same measured energy class
different processor architecture
tiny retained-SRAM footprint
```

<p align="right">
  <sub>
    drafted with ChatGPT &ndash; reviewed/approved by
    <a href="https://github.com/biosbob">@biosbob</a>
  </sub>
</p>
