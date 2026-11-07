# CC27xx advertising bring-up

BlueJouleAdvP is the first bench target. The driver supports unencrypted BLE 1M advertising at 0 dBm on channels 37�39. BlueJouleAdvP is hardware-verified. BlueJouleGattP adds the controller, bounded RX windows, and scan-response chaining; scan responses have been verified by phone discovery of BlueJouleGattP. Connections and packet crypto are not yet supported.

Radio headers, generic BLE profile, firmware, and trim algorithms originate from TI SimpleLink Low Power F3 SDK commit 4aa2c92162fe6c62103bc7b60018ca47a44a3585.
The profile is source/ti/devices/radioconfig/.meta/config/rcl/ble_bt5_1m_2m_coded_generic_cc27xx.json.
P10 overrides select LRFDMDM.SPARE0 = 0x2318 and LRFDRFE.PA0.RC = 3.
The LP_EM_CC2755P10 power table supplies the 0 dBm entry 0x1E0C94.

RfTrim_aux.hpp preserves TI's trim types and temperature compensation. The appTrims offset 0x2f0 was independently checked by compiling offsetof(fcfg_t, appTrims) against the working Zephyr HAL C header.
The additional PMUD, SYSTIM, and SYS0 headers come from T:/ti/zephyr-ti/modules/hal/ti/simplelink_lpf3/source/ti/devices/cc27xx/inc.

RfCtrl, RfFifo, RfFreq, and RfTemp start from the CC23xx EM implementation.
Build with ti.cc27xx://flash. The scan-response turnaround starts from the CC23xx 47 us command-lead model and has passed the phone scan-response test. The first BlueJouleGattP test is scanning only: do not connect. Shared software P256 supports SMP startup; CMAC and packet protection use explicit unsupported providers. RTC radio pauses and AlarmMgr share the CH0 compare, preserving the earlier deadline; CH1 is capture-only.


RX target difference: TI LRFLPF3.c LRF_programCMixN applies the CC27XX RCL-489 I/Q-swap workaround by reversing the CC23 mixer sign. RfFreq now follows that target conditional. Bob verified phone discovery after this correction. Temporary UART dumps, DBG-C/D instrumentation, and isolation probes were then removed; the cleaned image awaits re-verification.

