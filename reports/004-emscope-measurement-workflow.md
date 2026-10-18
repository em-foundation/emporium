# EMR 4 — EM•Scope Measurement Workflow

**First recorded:** 2026-05-27  
**Status:** Legacy report — imported into the EM•Report series  
**Origin:** BlueJoule-GATT Dev — archived private development repository  
**Original milestone:** Automated measurement milestone

**Benchmark definition:** [`001-bluejoule-gatt-definition.md`](001-bluejoule-gatt-definition.md)  
**Reference baseline:** [`002-zephyr-reference-implementation.md`](002-zephyr-reference-implementation.md)  
**Candidate baseline:** [`003-emscript-candidate-implementation.md`](003-emscript-candidate-implementation.md)  
**Tooling:** EM•Scope v25.6.x

> Imported into EM•porium with technical content preserved. Historical results have not been revalidated; exact firmware provenance is incomplete.

## TLDR

- BlueJoule-GATT now supports automated repeated measurement.
- The Zephyr central runs continuously as a benchmark driver.
- The Zephyr and EM•Script peripherals now support repeated benchmark cycles.
- Each cycle includes advertising, connection, targeted GATT transaction, disconnect, and return to sleep.
- EM•Scope v25.6.x adds the analysis support needed for BlueJoule-GATT captures.
- EM•Scope can extract connection-only events from repeated captures, even when advertising activity is also present.
- Current engineering scores show the EM•Script candidate using about **22–23% less event energy** than the Zephyr reference.
- The EM•Script candidate scores about **29% higher** in EM•eralds.
- This turns BlueJoule-GATT from a manually inspected waveform into a reproducible benchmark workflow.

## 1. Purpose

This report documents the transition from manual BlueJoule-GATT waveform inspection to automated repeated measurement and scoring.

Earlier reports defined the benchmark, documented the Zephyr reference implementation, and documented the EM•Script candidate implementation. Those reports were based on carefully selected single-transaction captures.

This report describes the next milestone: the benchmark can now run repeatedly, EM•Scope can extract connection-only events from the capture, and the resulting events can be scored reproducibly.

## 2. Automated Benchmark Flow

The current benchmark flow repeats automatically.

The Zephyr central runs continuously as a benchmark driver:

    scan
    connect
    discover BlueJoule-GATT service
    discover Status and Command characteristics
    write Command
    read Status
    disconnect
    restart scan
    repeat

The central intentionally repeats targeted GATT discovery on every connection. It does not cache handles between benchmark cycles.

The central also toggles an LED during each connection. This provides a simple visual indication that benchmark connections are occurring, roughly once per second.

The peripheral side runs as a repeated benchmark target:

    wake / enter active benchmark window
    advertise quickly
    accept connection
    complete BlueJoule-GATT transaction
    disconnect
    return to sleep
    repeat

The goal is a waveform containing repeated benchmark impulses separated by idle or sleep time.

## 3. EM•Scope v25.6.x Support

EM•Scope v25.6.x adds the analysis support needed for BlueJoule-GATT repeated captures.

Project background: [EM•Scope](https://github.com/em-foundation/emscope/blob/docs-stable/docs/ReadMore.md)

A BlueJoule-GATT capture contains more than one kind of activity:

    sparse pre-connection advertising pulses
    dense 7.5 ms connection-event train
    return to idle/sleep
    repeated cycles

For connection-only scoring, EM•Scope must identify the dense connection-event activity and exclude sparse advertising that occurred before the connection.

The event-based analysis path makes this possible. The final analyzed event markers define the scored connection activity.

## 4. Capture and Scan Workflow

The current working scan recipe is:

    emscope scan --sleep-window 100 --gap 15 --min-duration 75

Useful review and scoring commands are:

    emscope view -s        # review detected sleep behavior
    emscope view -e        # review detected events
    emscope view -j        # review generated analysis data
    emscope view -w -e     # generate what-if score using event-based scoring

The key option for this benchmark is:

    --sleep-window 100

A shorter sleep-estimation window helps avoid inflated sleep estimates in busy BlueJoule-GATT captures.

The primary scoring path is:

    emscope view -w -e

Here, `-w` is shorthand for what-if scoring. The what-if view generates the EM•erald score, normally using the default one-second event period unless another period is specified.

The `-e` option tells EM•Scope to score the analyzed events rather than the gross capture span.

The older gross/span what-if path remains available as:

    emscope view -w

For BlueJoule-GATT connection-only scoring, the event-based what-if path is the preferred scoring path.

## 5. Event Scoring Model

BlueJoule-GATT currently reports a connection-only score.

In a repeated capture, each benchmark cycle may include:

    advertising activity
    connection transaction
    disconnect
    sleep / idle interval

EM•Scope extracts the connection activity as the scored event. Sparse pre-connection advertising is discarded for the connection-only score.

This matches the benchmark definition in report 01: BlueJoule-GATT measures the connection transaction, not advertising.

## 6. Results and Capture Artifacts

The current engineering scores were produced from 12-second Nordic PPK captures.

Each capture was processed with the same EM•Scope scan/scoring flow. The raw capture was reduced through scan transformations, trimmed to a representative set of detected connection events, and scored using event-based analysis.

The generated `ABOUT.md` files are the primary human-readable score reports for this milestone:

- [Zephyr EM•Scope report](assets/captures/nrf-54-dk/zephyr-3V0-P/ABOUT.md)
- [EM•Script EM•Scope report](assets/captures/nrf-54-dk/emscript-3V0-P/ABOUT.md)

Each generated report includes the hardware/software configuration, sleep estimate, event energy, EM•erald score, and a representative event image.

Current score summary:

    Zephyr reference peripheral:
        representative event: 168.8 µJ
        score: 5.38 EM•eralds

    EM•Script candidate peripheral:
        representative event: 131.4 µJ
        score: 6.90 EM•eralds

Comparison:

    EM•Script uses 22% less event energy.
    EM•Script scores 28% higher in EM•eralds.

These automated repeated-capture scores are consistent with the earlier manually inspected captures in reports 02 and 03.

Full raw capture publishing may evolve separately, using the same general conventions as the original BlueJoule repository.

## 7. Measurement Notes

The current captures used a Nordic PPK in current measurement mode.

EM•Scope was given a fixed 3.0 V supply value for energy calculation.

A Joulescope JS220 may still be useful for sharper reference captures and detailed inspection.

## 8. Current Limitations

These are engineering scores, not final BlueJoule-GATT 1.0 certification results.

Current caveats:

- exact firmware commits should be recorded for published measurements
- repeated Joulescope captures remain useful for sharper reference data
- connection-only scoring is now working, but full-cycle scoring may also be useful later
- capture artifact publication may evolve before BlueJoule-GATT 1.0
- the benchmark definition may still evolve before BlueJoule-GATT 1.0

## 9. Closing Note

BlueJoule-GATT is now reproducibly scoreable with EM•Scope.

The benchmark has moved from manual waveform inspection to automated repeated measurement with stable first engineering scores.

<p align="right">
  <sub>
    drafted with ChatGPT &ndash; reviewed/approved by
    <a href="https://github.com/biosbob">@biosbob</a>
  </sub>
</p>
