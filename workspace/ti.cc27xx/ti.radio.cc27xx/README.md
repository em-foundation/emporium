# CC27xx advertising bring-up

BlueJouleAdvP is the first bench target. The driver supports unencrypted BLE 1M advertising at 0 dBm on channels 37�39. BlueJouleAdvP is hardware-verified. BlueJouleGattP adds the controller, bounded RX windows, and scan-response chaining; scan responses have been verified by phone discovery of BlueJouleGattP. Unencrypted connections, service discovery, and characteristic write/read have also passed a manual nRF Connect phone test. Packet crypto remains unsupported.

Radio headers, generic BLE profile, firmware, and trim algorithms originate from TI SimpleLink Low Power F3 SDK commit 4aa2c92162fe6c62103bc7b60018ca47a44a3585.
The profile is source/ti/devices/radioconfig/.meta/config/rcl/ble_bt5_1m_2m_coded_generic_cc27xx.json.
P10 overrides select LRFDMDM.SPARE0 = 0x2318 and LRFDRFE.PA0.RC = 3.
The LP_EM_CC2755P10 power table supplies the 0 dBm entry 0x1E0C94.

RfTrim_aux.hpp preserves TI's trim types and temperature compensation. The appTrims offset 0x2f0 was independently checked by compiling offsetof(fcfg_t, appTrims) against the working Zephyr HAL C header.
The additional PMUD, SYSTIM, and SYS0 headers come from T:/ti/zephyr-ti/modules/hal/ti/simplelink_lpf3/source/ti/devices/cc27xx/inc.

RfCtrl, RfFifo, RfFreq, and RfTemp start from the CC23xx EM implementation.
Build with ti.cc27xx://flash. The scan-response turnaround starts from the CC23xx 47 us command-lead model and has passed the phone scan-response test. BlueJouleGattP supports the unencrypted manual connection test described below. Shared software P256 supports SMP startup; CMAC and packet protection use explicit unsupported providers. RTC radio pauses and AlarmMgr share the CH0 compare, preserving the earlier deadline; CH1 is capture-only.


RX target difference: TI LRFLPF3.c LRF_programCMixN applies the CC27XX RCL-489 I/Q-swap workaround by reversing the CC23 mixer sign. RfFreq now follows that target conditional. Bob verified phone discovery after this correction. Temporary UART dumps, DBG-C/D instrumentation, and isolation probes were then removed; the cleaned scan-response image was reverified on the phone.


## Unencrypted connection bench test

The driver now accepts data channels 0-36 and applies the connection access address and CRC initialization, following the CC23xx controller model. RX/TX use the connected FIFO layout, including the RAM-only S1 byte. Profile setup precomputes the PA setting so RX-to-TX turnaround does not perform temperature arithmetic. Bob verified connection, service discovery, and characteristic write/read using nRF Connect. A quick connect/disconnect capture showed 79 RX and 79 completed TX operations with zero RX timeouts. Controlled-central benchmark scoring remains unverified on CC27xx. CMAC and packet encryption remain unsupported.

Temporary DBG-C/D connection markers and the RAM control-packet trace were removed after bench investigation. Routine UART output remains disabled; error messages remain enabled.

Use nRF Connect to connect to BlueJoule-GATT at C0:AA:AA:AA:AA:AA, discover service 0000b100-0000-1000-8000-00805f9b34fb, write hex 04 to Command (b102), and read Status (b101), expecting hex 84. This is an unencrypted manual GATT test, not the secure benchmark. Capture AppOut and DBG-A/B/C/D around Connect if it fails.

### Characterization status

Manual phone tests are bring-up evidence, not official BlueJoule benchmark captures. One 3 V PPK selection, believed to be an empty connection exchange, measured 1.380 ms and 7.71 uC (23.13 uJ). The archived CC23xx 1.29 ms / 13.0 uJ example contains an ATT Read Request and is not an exactly matched empty event. Do not treat their ratio as a controlled benchmark result.

The shared controller does not implement channel-map updates. A successful phone trace contained an LL_CHANNEL_MAP_IND followed by LL_UNKNOWN_RSP; longer-session stability requires follow-up. One earlier attempt ended with repeated RX timeouts. A subsequent traced attempt completed manual GATT operations; the previous drop was not conclusively explained. Phone interval updates and dense hotel RF traffic complicate these informal comparisons.
