# CC27xx advertising bring-up

BlueJouleAdvP is the first bench target. The driver supports unencrypted BLE 1M advertising at 0 dBm on channels 37–39. RX, controller scheduling, and packet crypto remain future milestones.

Radio headers, generic BLE profile, firmware, and trim algorithms originate from TI SimpleLink Low Power F3 SDK commit 4aa2c92162fe6c62103bc7b60018ca47a44a3585.
The profile is source/ti/devices/radioconfig/.meta/config/rcl/ble_bt5_1m_2m_coded_generic_cc27xx.json.
P10 overrides select LRFDMDM.SPARE0 = 0x2318 and LRFDRFE.PA0.RC = 3.
The LP_EM_CC2755P10 power table supplies the 0 dBm entry 0x1E0C94.

RfTrim_aux.hpp preserves TI's trim types and temperature compensation. The appTrims offset 0x2f0 was independently checked by compiling offsetof(fcfg_t, appTrims) against the working Zephyr HAL C header.
The additional PMUD, SYSTIM, and SYS0 headers come from T:/ti/zephyr-ti/modules/hal/ti/simplelink_lpf3/source/ti/devices/cc27xx/inc.

RfCtrl, RfFifo, RfFreq, and RfTemp start from the CC23xx EM implementation.
Build with ti.cc27xx://flash. Hardware transmission and packet decoding still require bench validation.
