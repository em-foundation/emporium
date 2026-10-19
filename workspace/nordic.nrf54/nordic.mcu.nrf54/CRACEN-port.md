# CRACEN P-256 first checkpoint

Source-only bring-up candidate for nRF54L15 application Cortex-M33, secure
peripheral mapping. Not yet built or device-validated. Bob owns builds/loads/tests.

Run `nordic.mcu.nrf54/P256CracenTestP` with the nRF54 distro. It measures explicit
initialization (including microcode readback), runs the existing public-key/ECDH
vectors twice, then checks rejection of the all-zero public point. `TestVectors`
now calls `Crypto.P256`, selected by distro `CryptoC`; nRF52 retains its existing
assembly selection. The nRF54 CryptoC currently supplies P-256 only, not secure BLE.

## Mechanisms and provenance

Translated from installed NCS v3.0.2, under
`nrf/subsys/nrf_security/src/drivers/cracen/`:

- `cracenpsa/src/cracen.c`: PKE enable, microcode load and retained-image lifecycle.
- `cracenpsa/src/ecc.c`: public key = scalar times standard generator.
- `cracenpsa/src/key_derivation.c`, `common.c`: point validation then ECDH;
  shared secret is affine result X.
- `silexpk/target/hw/ba414/{pkhardware_ba414e.c,cmddefs_ecc.c,op_slots.h,
  regs_commands.h,ba414_status.c}`: command encoding, operand slots, status mask.
- `silexpk/target/baremetal_ba414e_with_ik/pk_baremetal.c`: slot size from
  capabilities, busy polling, command ownership.
- `silexpk/target/hw/ik/ikhardware.c`: pointer selection, memory barrier, START.
- `common/include/security/cracen.h`: operand RAM and microcode addresses.

These Nordic sources and the microcode carry `LicenseRef-Nordic-5-Clause`.
Preserve their notices and the SDK's Nordic license when distributing derivatives.
Microcode is copied without word changes into an EMS RO table: 1223 words,
4892 stored bytes. Host code, static RAM and runtime accelerator RAM are separate
costs. Nordic firmware is accelerator code, not a linked ARM C implementation.

## Deliberate first-checkpoint limits

Synchronous polling; exclusively owns CRACEN; no NVIC interrupt, Zephyr, PSA, KMU,
IKG, RNG, or software-P256 fallback. Scalar/projective randomization is disabled
for this arithmetic bring-up; no claim of production side-channel hardening.
Bring-up now enables all three submodules like Nordic's shared acquire path. Microcode retention is checked after each reacquisition; this diagnostic adds overhead to the current operation timings.
Bounded polling failure prints raw status and halts. Hardware faults are distinct
from invalid-point results. A passed vector run does not validate all error cases.

Uses Nordic's big-endian command mode with explicit conversion from EMS U256
limbs. Predefined P-256 supplies field/curve constants in hardware; only generator
coordinates are stored on the host. No software engine or math backend is imported.
ECDH includes point validation. Private scalar range is checked before submission.
Each operation releases module power and clears used operand/result slots.
Microcode is loaded once per application boot, matching Nordic's retention model;
reset/sleep depths beyond this standalone checkpoint remain unverified.

Software baselines reported by Bob on this target:

| Backend | Public key | ECDH |
| --- | ---: | ---: |
| Portable | 18928 us | 18902 us |
| M4 assembly | 7687 us | 7655 us |

Those software paths do not yet implement the same peer-validation behavior;
record that distinction when comparing provider timings.
## Bring-up correction: microcode is lost on disable

Bob's hardware run reports initialization 346 us, then a retention mismatch at word zero after disabling/re-enabling CRACEN (COMMAND reset to 0x0f). The initial retained-image assumption is disproved for this enable sequence. The provider now keeps CRACEN enabled until explicit shutdown; the test shuts it down after its final check. The next use reloads the image. Earlier per-operation power-release descriptions above are superseded. Retention-readback diagnostics remain inside acquisition and affect provisional timings. Power-release/reload policy is deferred until arithmetic passes.
