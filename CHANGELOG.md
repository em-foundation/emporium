# Changelog

## release-26.10

* Added Distro Packages tours (103)
* Added distro build and register-access workflows
* Added timers, interrupts, sleep, and GPIO examples
* Added distro gallery spanning Raspberry Pi, nRF52, and CC23xx
* Improved Tour Guide source folding and Content-view reveal
* Improved board/setup behavior for distro development workflows
* Added GNU linker-script and map-file VS Code support
* Added Raspberry Pi `load.sh` support for simulator workflows
* EM•Script pinned to 26.3.4
* EM•Builder pinned to 26.3.0
* Validated released tour metadata

## release-26.09

* Added CoreMark tours (102)
* Added portable CoreMark implementation in EM•Script
* Added ActiveRunner and SleepyRunner benchmark modes
* Added real-hardware support for nRF52, nRF54, and CC23xx
* Added real-hardware build, load, and serial workflows
* Added PulseView capture with low-cost logic analyzers
* Added current-board highlighting in EM•Builder
* EM•Script pinned to 26.3.4
* EM•Builder pinned to 26.2.2
* Improved Linux J-Link packaging
* Added Linux XDS110 setup for TI UniFlash
* Validated Windows, macOS, and Linux host workflows
* Validated released tour metadata

### Note

* Linux TI UniFlash users must run `tools/ti-uniflash/udev_rules.sh` once before loading TI hardware.

## release-26.08

* First public EM•porium release
* Added Welcome Aboard tours (100)
* Added Basic Examples tours (101)
* Added source-control workflow guidance
* Added clone-local VS Code environment
* Added `npm start` launch/provision workflow
* Added reset/refresh launch support
* Updated EM•Builder and EMS toolchain pins
* Fixed `$table` `for...of` iteration translation
* Validated Basic and Combo examples
