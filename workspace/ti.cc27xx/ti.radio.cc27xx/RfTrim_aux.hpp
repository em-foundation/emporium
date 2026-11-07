/*
 * Copyright (c) 2021-2026, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once
#include <stdint.h>

// CC2755x10 trim layout and algorithms from TI SDK LRFLPF3.
// The generic BLE 1 Mbps profile selects bandwidth 0 and dither bandwidth 1.
#define DeviceFamily_PARENT 1
#define DeviceFamily_PARENT_CC27XX 1
#define HWREG_READ_LRF(a) (*reinterpret_cast<volatile uint32_t *>(a))
#define HWREG_WRITE_LRF(a) HWREG_READ_LRF(a)
#define HWREGH_READ_LRF(a) (*reinterpret_cast<volatile uint16_t *>(a))
#define HWREGH_WRITE_LRF(a) HWREGH_READ_LRF(a)

namespace cc27_rf_trim {
#define LRF_TRIM_NUM_VARIANTS 2
typedef struct {
    uint32_t word[2];
} LRF_DoubleWord;

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
typedef struct {
    union {
        struct {
            uint16_t r0     : 4;
            uint16_t r1     : 4;
            uint16_t r2     : 4;
            uint16_t r3     : 4;
        } fields;
        uint16_t value;
    };
} LRF_Trim_vddsComp;
typedef struct {
    int8_t thr;
    union {
        struct {
            uint8_t val     : 4;
            uint8_t spare   : 4;
        } fields;
        uint8_t value;
    };
} LRF_Trim_rtrimTxComp;
typedef struct {
    union {
        struct {
            uint16_t lowCmp  : 4;
            uint16_t highCmp : 4;
            uint16_t nomTmp  : 4;
            uint16_t nomIdx  : 4;
        } fields;
        uint16_t value;
    };
} LRF_Trim_tempCoeffComp;
#endif //DeviceFamily_PARENT_CC27XX

typedef union {
    struct {
        // Trim value for LRFDRFE:PA0.TRIM
        union {
            struct {    // length: 2B
                uint16_t trim           : 5;
                uint16_t zero           : 11;
            } pa0;
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
            // Trim values for PA (mode0, mode1)
            struct {    // length: 2B
                uint16_t trim0           : 5;
                uint16_t zero0           : 3;
                uint16_t trim1           : 5;
                uint16_t zero1           : 3;
            } pa2trim01;
#endif
        };
        // Trim value for LRFDRFE:ATSTREFH.IREFTRIM
        struct {    // length: 2B
            uint16_t zero0          : 10;
            uint16_t irefTrim       : 5;
            uint16_t zero1          : 1;
        } atstRefH;
    } fields;
    struct {
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
        uint16_t pa2trim01;
#else
        uint16_t pa0;
#endif
        uint16_t atstRefH;
    };
    uint32_t data;
} LRF_Trim0;

typedef union {
    struct {
        // Trim value for LRFDRFE:LNA.TRIM
        struct {    // length: 2B
            uint16_t zero0          : 4;
            uint16_t trim           : 4;
            uint16_t zero1          : 8;
        } lna;
        // Trim value for LRFDRFE:IFAMPRFLDO.TRIM
        struct {    // length: 2B
            uint16_t zero           : 9;
            uint16_t trim           : 7;
        } ifampRfLdo;
        // Trim value for LRFDRFE:DIVLDO.VOUTTRIM
        struct {    // length: 2B
            uint16_t zero0          : 8;
            uint16_t voutTrim       : 7;
            uint16_t zero1          : 1;
        } divLdo;
        // Trim value for LRFDRFE:TDCLDO.VOUTTRIM
        struct {    // length: 2B
            uint16_t zero0          : 8;
            uint16_t voutTrim       : 7;
            uint16_t zero1          : 1;
        } tdcLdo;
    } fields;
    struct {
        uint16_t lna;
        uint16_t ifampRfLdo;
        uint16_t divLdo;
        uint16_t tdcLdo;
    };
    LRF_DoubleWord data;
} LRF_Trim1;

typedef union {
    struct {
        // Trim values for LRFDRFE:DCOLDO0
        struct {    // length: 2B
            uint16_t zero0          : 4;
            uint16_t firstTrim      : 4;
            uint16_t secondTrim     : 6;
            uint16_t zero1          : 2;
        } dcoLdo0;
        // Trim value for LRFDRFE:IFADCALDO.TRIMOUT
        struct {    // length: 2B
            uint16_t zero0          : 8;
            uint16_t trimout        : 6;
            uint16_t zero1          : 2;
        } ifadcAldo;
        // Trim value for LRFDRFE:IFADCDLDO.TRIMOUT
        struct {    // length: 2B
            uint16_t zero0          : 8;
            uint16_t trimout        : 6;
            uint16_t zero1          : 2;
        } ifadcDldo;
        // Trim value for LRFDRFE:DCO.TAILRESTRIM
        struct {    // length: 2B
            uint16_t zero0          : 3;
            uint16_t tailresTrim    : 4;
            uint16_t zero1          : 9;
        } dco;
    } fields;
    struct {
        uint16_t dcoLdo0;
        uint16_t ifadcAldo;
        uint16_t ifadcDldo;
        uint16_t dco;
    };
    LRF_DoubleWord data;
} LRF_Trim2;

typedef union {
    struct {
        // Trim value for LRFDRFE:IFADCQUANT.QUANTTHR
        struct {    // length: 2B
            uint16_t quantThr       : 3;
            uint16_t zero           : 13;
        } ifadcQuant;
        // Trim values for LRFDRFE:IFADC0
        struct {    // length: 2B
            uint16_t zero0          : 2;
            uint16_t aafcap         : 2;
            uint16_t int2Adj        : 4;
            uint16_t zero1          : 2;
            uint16_t ditheren       : 2;    /* Revision >= 4 only */
            uint16_t dithertrim     : 3;
            uint16_t zero2          : 1;
        } ifadc0;
        // Trim value for LRFDRFE:IFADC1.TRIM
        struct {    // length: 2B
            uint16_t zero0          : 9;
            uint16_t trim           : 6;
            uint16_t nrz            : 1;
        } ifadc1;
        // Trim values for LRFDRFE:IFADCLF
        struct {    // length: 2B
            uint16_t int3           : 4;
            uint16_t ff1            : 4;
            uint16_t ff2            : 4;
            uint16_t ff3            : 4;
        } ifadclf;
    } fields;
    struct {
        uint16_t ifadcQuant;
        uint16_t ifadc0;
        uint16_t ifadc1;
        uint16_t ifadclf;
    };
    LRF_DoubleWord data;
} LRF_Trim_Variant;

typedef struct
{
    uint16_t rtrimMinOffset : 2;
    uint16_t rtrimMaxOffset : 2;
    uint16_t divLdoMinOffset: 2;
    uint16_t divLdoMaxOffset: 2;
    uint16_t tdcLdoMinOffset: 2;
    uint16_t tdcLdoMaxOffset: 2;
    uint16_t tThrl          : 2;
    uint16_t tThrh          : 2;
} LRF_Trim_tempLdoRtrim;

typedef struct {
    int32_t rssiTcomp      : 4;
    int32_t magnTcomp      : 4;
    int32_t magnOffset     : 4;
    int32_t rfu            : 4;
    int32_t agcThrTcomp    : 4;
    int32_t agcThrOffset   : 4;
    int32_t lowGainOffset  : 4;
    int32_t highGainOffset : 4;
} LRF_Trim_tempRssiAgc;

typedef struct {
    uint8_t dcoldoFirstMinOffset       : 2;
    uint8_t dcoldoFirstMaxOffset       : 2;
    uint8_t dcoldoSecondMinOffset      : 2;
    uint8_t dcoldoSecondMaxOffset      : 2;
} LRF_Trim_dcoldoOffset;
typedef union {
    struct {
        struct {    // length: 4B
            LRF_Trim_tempLdoRtrim tempLdoRtrim;
            uint8_t hfxtPdError;
            LRF_Trim_dcoldoOffset dcoldoOffset; /* Revision >= 8 only */
         } lrfdrfeExtTrim1;                  /* Revision >= 4 only */
        // Trim values for synth divider 0
        LRF_Trim_tempRssiAgc lrfdrfeExtTrim0;
    } fields;
    struct {
        uint32_t lrfdrfeExtTrim1;
        uint32_t lrfdrfeExtTrim0;
    };
    uint32_t data;
} LRF_Trim3;

typedef union {
    struct {
        struct {    // length: 2B
                    // RSSI measured for front end 0 in production test.
                    // Value is read by RF Core FW during RF Core initialization
            uint16_t offset         : 8;
            uint16_t trimCompleteN  : 1;
            uint16_t zero           : 7;
        } fend0Rssi;
        // Trim values for synth divider 0
        struct {    // length: 2B
                    // Trim value for IQ mismatch compensation.
                    // Value is read by RF Core FW during RF Core initialization
            uint16_t iqmc           : 16;
        } syntDiv0;
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
        // Trim values for PA (mode2, mode3)
        struct {    // length: 2B
            uint16_t trim2           : 5;
            uint16_t zero0           : 3;
            uint16_t trim3           : 5;
            uint16_t zero1           : 3;
        } pa2trim23;
#else
        uint16_t res1;
#endif
        struct {
            uint8_t zero            : 4;
            uint8_t aafcap          : 4;
        } ifamprfldo[LRF_TRIM_NUM_VARIANTS];     /* Revision >= 4 only */
    } fields;
    struct {
        int8_t   rssiOffset;
        uint8_t  trimCompleteN;
        uint16_t demIQMC0;
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
        uint16_t pa2trim23;
#else
        uint16_t res1;
#endif
        uint8_t  ifamprfldo[LRF_TRIM_NUM_VARIANTS];
    };
    uint32_t data;
} LRF_Trim4;

#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
typedef union {
    struct {
        LRF_Trim_vddsComp vddsComp;
        uint16_t reserved;
        LRF_Trim_rtrimTxComp rtrimTxComp;
        LRF_Trim_tempCoeffComp tempCoeffComp;
    };
    uint32_t data;
} LRF_Trim11;
#endif //DeviceFamily_PARENT_CC27XX

/* This definition is used instead of the definition from hw_fcfg.h to accommodate implementation
   and cut parameters not relevant to LRF */
typedef struct {
    uint8_t             revision;           /* Revision of appTrims */
    uint8_t             nToolsClientOffset;
    uint8_t             reserved[2];
    LRF_Trim0           trim0;
    LRF_Trim1           trim1;
    LRF_Trim2           trim2;
    LRF_Trim_Variant    trimVariant[LRF_TRIM_NUM_VARIANTS];
    LRF_Trim3           trim3;
    LRF_Trim4           trim4;
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
    uint32_t            reserved1[15];
    LRF_Trim11          trim11;
#endif //DeviceFamily_PARENT_CC27XX
} LRF_TrimDef;


struct LRF_SwConfig { uint8_t bwIndex; uint8_t bwIndexDither; };
#define LRF_TRIM_NORMAL_BW    0
#define LRF_TRIM_HIGH_BW      1                 /* Revision >= 4 only */
#define LRF_TRIM_MIN_VERSION_FULL_FEATURES  4U    /* Only AppTrims revision 4 and above has all features */
#define LRF_TRIM_VERSION_DCOLDO_TEMPERATURE_COMPENSATION 8U /* Only AppTrims revision 8 and above have DCOLDO temperature compensation */
#define LRF_TRIM_VERSION_RSSIOFFSET_ISSUE_CC23X0R5 4U     /* AppTrims revision with issue in rssiOffset field */
#define LRF_TRIM_LIMIT_RSSIOFFSET_ISSUE_CC23X0R5  (-4)   /* If rssiOffset is less or equal to this, apply correction */
#define LRF_TRIM_CORRECTION_RSSIOFFSET_ISSUE_CC23X0R5 5  /* Correction to apply to devices with wrong RSSI offset */
#define LRF_TRIM_DCOLDO0_SECONDTRIM_INC_STATE_B_DCOLDO_WORKAROUND_CC27XX 10U    /* DCOLDO0:SECONDTRIM needs to be increased by 10 on CC27XX state B devices */
#define LRF_TRIM_DCOLDO0_SECONDTRIM_CODED_BITS_MASK ((1U << 3U) | (1U << 5U))    /* Bits mask for bit 3 and 5 of DCOLDO0:SECONDTRIM */
#define LRF_TRIM_DCOLDO0_SECONDTRIM_MAX_STATE 63U    /* DCOLDO0:SECONDTRIM maximum value allowed within the range of 6-bit representation */
#define LRF_TRIM_DCOLDO0_FIRSTTRIM_MIN_STATE -8    /* DCOLDO0:FIRSTTRIM minimum value allowed within the range of 4-bit two's complement representation */
#define LRF_DCOLDOSECOND_HIGH_TEMP_ADJ_FACTOR 5
#define LRF_DCOLDOSECOND_LOW_TEMP_ADJ_FACTOR  5
#define LRF_DCOLDO_DEADBAND 10
#define LRF_DCOLDO_OFFSET_LOWER_SATURATION 0
#define LRF_DCOLDOFIRST_HIGH_TEMP_ADJ_FACTOR_S  1
#define LRF_DCOLDOFIRST_HIGH_TEMP_ADJ_FACTOR_MUL 5
#define LRF_DCOLDOFIRST_LOW_TEMP_ADJ_FACTOR_S   1
#define LRF_DCOLDOFIRST_LOW_TEMP_ADJ_FACTOR_MUL 5
#define LRF_DCOLDOSECOND_FACTOR 2
#define DIV_BY_NINE_CONSTANT 1864135U
#define LRF_DCOLDO_OFFSET_HIGH_TEMP 16
#define LRF_DCOLDO_OFFSET_LOW_TEMP 9
#define LRF_DCOLDO_SHIFT_HIGH_TEMP 5
#define LRF_DCOLDO_SHIFT_LOW_TEMP 25
#define LRF_TEMPERATURE_NOM 25
#define LRF_CC27XX_RFE_SPARE5_PA_20DBM_ESD_CTRL_SET                      ((uint32_t)(0x1 << 14U))
#define LRF_CC27XX_RFE_SPARE5_RTRIM_TX_COMP_BITMASK                      ((uint32_t)(0x1 << 13U))
#define LRF_TRIM_SIGN_MAG_TO_SIGNED(x) (int8_t)(((x & 0x8) ? -(x & 0x7) : (x & 0x7)))
#define LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP 4U
#define LRF_DIVLDO_LOW_TEMP_ADJ_FACTOR 10U
#define LRF_DIVLDO_HIGH_TEMP_ADJ_FACTOR 10U
#define LRF_TDCLDO_LOW_TEMP_ADJ_FACTOR 10U
#define LRF_TDCLDO_HIGH_TEMP_ADJ_FACTOR 10U
#define LRF_RTRIM_LOW_TEMP_ADJ_FACTOR 1U
#define LRF_RTRIM_HIGH_TEMP_ADJ_FACTOR 1U
#define LRF_DEFAULT_RTRIM_MAX 15U
#define LRF_DEFAULT_RTRIM_MAX 12U
#define LRF_EXTTRIM0_TEMPERATURE_SCALE_EXP 7
#define LRF_TEMPERATURE_MIN (-40)
#define LRF_TEMPERATURE_MAX 125
#define RFE_SPARE0_LOW_GAIN_BM  0x000FU
#define RFE_SPARE0_LOW_GAIN     0U
#define RFE_SPARE0_HIGH_GAIN_BM 0x00F0U
#define RFE_SPARE0_HIGH_GAIN    4U
#define RFE_SPARE1_AGC_VALUE_BM 0x000FFU
#define RFE_SPARE1_AGC_VALUE    0U
#define LRF_ONE_THIRD_MANTISSA 21845U /* (round(1/3 * 2^16)) */
#define LRF_ONE_THIRD_NEG_EXP  16U
static uint32_t LRF_findExtTrim1TrimAdjustment(uint32_t temperatureDiff, uint32_t tempThreshFactor, uint32_t maxAdjustment);
static int32_t LRF_findExtTrim0TrimAdjustment(int32_t temperature, int32_t tempCompFactor, int32_t offset);
static void LRF_temperatureCompensateDcoldo(int32_t temperature, const LRF_TrimDef *trimDef);
static void LRF_temperatureCompensateTrim(const LRF_TrimDef *trimDef);
static void LRF_setTrimCommon(const LRF_TrimDef *trimDef, const LRF_SwConfig *swConfig);
static void LRF_applyTrim(const LRF_TrimDef *trimDef, const LRF_SwConfig *swConfig);

static uint32_t LRF_findExtTrim1TrimAdjustment(uint32_t temperatureDiff, uint32_t tempThreshFactor, uint32_t maxAdjustment)
{
    uint32_t adjustment;
    /* Calculate adjustment = round((temperatureDiff * maxAdjustment) / (tempThreshFactor * 2^LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP)) */
    switch (tempThreshFactor)
    {
        case 0:
        default:
            /* tempThreshFactor = 0:
               No temperatures will be in the range for adjustment */
            adjustment = 0;
            break;
        case 1:
            /* tempThreshFactor = 1:
               adjustment = round((temperatureDiff * maxAdjustment) / (1 * 2^LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP)) */
            adjustment = ((temperatureDiff * maxAdjustment) + (1U << (LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP - 1U))) >> LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP;
            break;
        case 2:
            /* tempThreshFactor = 2:
               adjustment = round((temperatureDiff * maxAdjustment) / (2 * 2^LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP)) */
            adjustment = ((temperatureDiff * maxAdjustment) + (1U << LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP)) >> (LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP + 1U);
            break;
        case 3:
            /* tempThreshFactor = 3:
               adjustment = round((temperatureDiff * maxAdjustment) / (3 * 2^LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP))
               Use approximation with multiplication to avoid performing division */
            adjustment = ((temperatureDiff * maxAdjustment * LRF_ONE_THIRD_MANTISSA) + (1U << (LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP + LRF_ONE_THIRD_NEG_EXP - 1U)))
                >> (LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP + LRF_ONE_THIRD_NEG_EXP);
            break;
    }
    return adjustment;
}

static int32_t LRF_findExtTrim0TrimAdjustment(int32_t temperature, int32_t tempCompFactor, int32_t offset)
{
    return (((temperature - LRF_TEMPERATURE_NOM) * tempCompFactor) >> LRF_EXTTRIM0_TEMPERATURE_SCALE_EXP) + offset;
}

static void LRF_temperatureCompensateDcoldo(int32_t temperature, const LRF_TrimDef *trimDef)
{
    uint32_t trimDcoldo0Val;
    if (trimDef->revision >= LRF_TRIM_VERSION_DCOLDO_TEMPERATURE_COMPENSATION) {
        /* Only compensate if temperature is outside deadband limits */
        int32_t offsetDcoLdoFirst = 0;
        int32_t offsetDcoLdoSecond = 0;
        if ((temperature >= LRF_TEMPERATURE_NOM + LRF_DCOLDO_DEADBAND) || (temperature <=  LRF_TEMPERATURE_NOM - LRF_DCOLDO_DEADBAND))
        {
            int32_t dcoldoSecondMaxOffset = (int32_t) trimDef->trim3.fields.lrfdrfeExtTrim1.dcoldoOffset.dcoldoSecondMaxOffset;
            int32_t dcoldoSecondMinOffset = (int32_t) trimDef->trim3.fields.lrfdrfeExtTrim1.dcoldoOffset.dcoldoSecondMinOffset;
            int32_t dcoldoFirstMaxOffset  = (int32_t) trimDef->trim3.fields.lrfdrfeExtTrim1.dcoldoOffset.dcoldoFirstMaxOffset;
            int32_t dcoldoFirstMinOffset  = (int32_t) trimDef->trim3.fields.lrfdrfeExtTrim1.dcoldoOffset.dcoldoFirstMinOffset;

            int32_t tempDiff = LRF_TEMPERATURE_NOM - temperature;
            int32_t upperSaturationFirst;
            int32_t upperSaturationSecond;
            /* Calculate offset values for the trims, also set upper saturation */
            if (temperature > LRF_TEMPERATURE_NOM)
            {
                offsetDcoLdoSecond = (int32_t) (((-tempDiff-LRF_DCOLDO_DEADBAND) * LRF_DCOLDOSECOND_FACTOR * dcoldoSecondMaxOffset) + LRF_DCOLDO_OFFSET_HIGH_TEMP) >> LRF_DCOLDO_SHIFT_HIGH_TEMP;
                offsetDcoLdoFirst  = (int32_t) (((-tempDiff-LRF_DCOLDO_DEADBAND) * dcoldoFirstMaxOffset) + LRF_DCOLDO_OFFSET_HIGH_TEMP) >> LRF_DCOLDO_SHIFT_HIGH_TEMP;
                upperSaturationSecond = dcoldoSecondMaxOffset * LRF_DCOLDOSECOND_HIGH_TEMP_ADJ_FACTOR;
                upperSaturationFirst  = (dcoldoFirstMaxOffset * LRF_DCOLDOFIRST_HIGH_TEMP_ADJ_FACTOR_MUL) >> LRF_DCOLDOFIRST_HIGH_TEMP_ADJ_FACTOR_S;
            }
            else
            {
                offsetDcoLdoSecond = (int32_t) ((((tempDiff-LRF_DCOLDO_DEADBAND) * LRF_DCOLDOSECOND_FACTOR * dcoldoSecondMinOffset) + LRF_DCOLDO_OFFSET_LOW_TEMP) * DIV_BY_NINE_CONSTANT) >> LRF_DCOLDO_SHIFT_LOW_TEMP;
                offsetDcoLdoFirst  = (int32_t) ((((tempDiff-LRF_DCOLDO_DEADBAND) * dcoldoFirstMinOffset) + LRF_DCOLDO_OFFSET_LOW_TEMP)  * DIV_BY_NINE_CONSTANT) >> LRF_DCOLDO_SHIFT_LOW_TEMP;
                upperSaturationSecond = dcoldoSecondMinOffset * LRF_DCOLDOSECOND_LOW_TEMP_ADJ_FACTOR;
                upperSaturationFirst  = (dcoldoFirstMinOffset * LRF_DCOLDOFIRST_LOW_TEMP_ADJ_FACTOR_MUL) >> LRF_DCOLDOFIRST_LOW_TEMP_ADJ_FACTOR_S;
            }

            /* Saturate values if out of bounds */
            if (offsetDcoLdoSecond > upperSaturationSecond)
            {
                offsetDcoLdoSecond = upperSaturationSecond;
            }
            if (offsetDcoLdoSecond < LRF_DCOLDO_OFFSET_LOWER_SATURATION)
            {
                offsetDcoLdoSecond = LRF_DCOLDO_OFFSET_LOWER_SATURATION;
            }

            if (offsetDcoLdoFirst > upperSaturationFirst)
            {
                offsetDcoLdoFirst = upperSaturationFirst;
            }
            if (offsetDcoLdoFirst < LRF_DCOLDO_OFFSET_LOWER_SATURATION)
            {
                offsetDcoLdoFirst = LRF_DCOLDO_OFFSET_LOWER_SATURATION;
            }
        }

        /* Get trim values to add offset */
        trimDcoldo0Val = trimDef->trim2.dcoLdo0;
        uint32_t secondTrimVal = (trimDcoldo0Val & LRFDRFE_DCOLDO0_SECONDTRIM_M) >> LRFDRFE_DCOLDO0_SECONDTRIM_S;
        int32_t firstTrimVal = (int32_t) ((trimDcoldo0Val & LRFDRFE_DCOLDO0_FIRSTTRIM_M) >> LRFDRFE_DCOLDO0_FIRSTTRIM_S);

        /* Sign extend DCOLDO0:FIRSTTRIM since it is a negative value */
        firstTrimVal = ((firstTrimVal << (int32_t) (32U - LRFDRFE_DCOLDO0_FIRSTTRIM_W )) >> (int32_t) (32U - LRFDRFE_DCOLDO0_FIRSTTRIM_W));

        /* Invert bit 3 and 5 to decode the SECONDTRIM value */
        uint32_t secondTrimValDecoded = secondTrimVal ^ LRF_TRIM_DCOLDO0_SECONDTRIM_CODED_BITS_MASK;

        /* Add offset to trim values */
        uint32_t newSecondTrimVal = secondTrimValDecoded + (uint32_t) offsetDcoLdoSecond;

        /* The voltage output of DCOLDO0:FIRSTTRIM has a negative slope where the minimum trim value gives the maximum output voltage.
        For this reason we need to subtract the temperature offset instead of adding it. */
        int32_t newFirstTrimVal =  firstTrimVal - offsetDcoLdoFirst;

        /* DCOLDO0.SECONDTRIM is saturated at LRF_TRIM_DCOLDO0_SECONDTRIM_MAX_STATE */
        if (newSecondTrimVal > LRF_TRIM_DCOLDO0_SECONDTRIM_MAX_STATE)
        {
            newSecondTrimVal = LRF_TRIM_DCOLDO0_SECONDTRIM_MAX_STATE;
        }
        /* DCOLDO0.FIRSTTRIM is saturated at LRF_TRIM_DCOLDO0_FIRSTTRIM_MIN_STATE since it is a negative value */
        if (newFirstTrimVal < LRF_TRIM_DCOLDO0_FIRSTTRIM_MIN_STATE)
        {
            newFirstTrimVal = LRF_TRIM_DCOLDO0_FIRSTTRIM_MIN_STATE;
        }

        /* Invert bit 3 and 5 to encode the SECONDTRIM value */
        uint32_t newSecondTrimValCoded = newSecondTrimVal ^ LRF_TRIM_DCOLDO0_SECONDTRIM_CODED_BITS_MASK;

        /* Write offseted trim values to their register */
        trimDcoldo0Val = (trimDcoldo0Val & ~LRFDRFE_DCOLDO0_FIRSTTRIM_M) | (((uint32_t) (newFirstTrimVal) << LRFDRFE_DCOLDO0_FIRSTTRIM_S) &  LRFDRFE_DCOLDO0_FIRSTTRIM_M );
        trimDcoldo0Val = (trimDcoldo0Val & ~LRFDRFE_DCOLDO0_SECONDTRIM_M) | (newSecondTrimValCoded << LRFDRFE_DCOLDO0_SECONDTRIM_S);
    }
    else
    {
        trimDcoldo0Val = trimDef->trim2.dcoLdo0;
    }
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_DCOLDO0) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_DCOLDO0) | trimDcoldo0Val;
}

static void LRF_temperatureCompensateTrim(const LRF_TrimDef *trimDef)
{
    uint32_t divLdoTempOffset = 0;
    uint32_t tdcLdoTempOffset = 0;
    uint32_t rtrimTempOffset = 0;
    int32_t rssiTempOffset = 0;
    int32_t agcValOffset = 0;
    int32_t agcHighGainOffset = 0;
    int32_t agcLowGainOffset = 0;
    int16_t temperature = ti_radio_cc27xx_RfTemp::getTemperature();



    if (trimDef->revision >= LRF_TRIM_MIN_VERSION_FULL_FEATURES)
    {
        LRF_Trim_tempLdoRtrim tempLdoRtrim = trimDef->trim3.fields.lrfdrfeExtTrim1.tempLdoRtrim;

        int16_t tempThreshLow = LRF_TEMPERATURE_MIN + (int16_t) (tempLdoRtrim.tThrl * (1U << LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP));
        int16_t tempThreshHigh = LRF_TEMPERATURE_MAX - (int16_t) (tempLdoRtrim.tThrh * (1U << LRF_EXTTRIM1_TEMPERATURE_SCALE_EXP));

        /* Adjust values for extreme temperatures */
        if (temperature < tempThreshLow)
        {
            uint32_t temperatureDiff = (uint32_t) (tempThreshLow - temperature);
            divLdoTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrl,
                LRF_DIVLDO_LOW_TEMP_ADJ_FACTOR * tempLdoRtrim.divLdoMinOffset);
            tdcLdoTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrl,
                LRF_TDCLDO_LOW_TEMP_ADJ_FACTOR * tempLdoRtrim.tdcLdoMinOffset);
            rtrimTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrl,
                LRF_RTRIM_LOW_TEMP_ADJ_FACTOR * tempLdoRtrim.rtrimMinOffset);
        }
        else if (temperature > tempThreshHigh)
        {
            uint32_t temperatureDiff = (uint32_t) (temperature - tempThreshHigh);
            divLdoTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrh,
                LRF_DIVLDO_HIGH_TEMP_ADJ_FACTOR * tempLdoRtrim.divLdoMaxOffset);
            tdcLdoTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrh,
                LRF_TDCLDO_HIGH_TEMP_ADJ_FACTOR * tempLdoRtrim.tdcLdoMaxOffset);
            rtrimTempOffset = LRF_findExtTrim1TrimAdjustment(temperatureDiff, tempLdoRtrim.tThrh,
                LRF_RTRIM_HIGH_TEMP_ADJ_FACTOR * tempLdoRtrim.rtrimMaxOffset);
        }
        else
        {
            /* Do nothing */
        }

        rssiTempOffset = LRF_findExtTrim0TrimAdjustment(temperature, trimDef->trim3.fields.lrfdrfeExtTrim0.rssiTcomp, 0);

        if (((HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_AGCINFO) & RFE_COMMON_RAM_AGCINFO_MODE_M) >> RFE_COMMON_RAM_AGCINFO_MODE_S) == (RFE_COMMON_RAM_AGCINFO_MODE_FAST >> RFE_COMMON_RAM_AGCINFO_MODE_S))
        {
            /* Fast AGC */
            agcValOffset =LRF_findExtTrim0TrimAdjustment(temperature, trimDef->trim3.fields.lrfdrfeExtTrim0.agcThrTcomp,
                                                         trimDef->trim3.fields.lrfdrfeExtTrim0.agcThrOffset);
            agcHighGainOffset = trimDef->trim3.fields.lrfdrfeExtTrim0.highGainOffset;
            agcLowGainOffset = trimDef->trim3.fields.lrfdrfeExtTrim0.lowGainOffset;
        }
        else
        {
            /* Standard AGC */
            agcValOffset = LRF_findExtTrim0TrimAdjustment(temperature, trimDef->trim3.fields.lrfdrfeExtTrim0.magnTcomp,
                                                          trimDef->trim3.fields.lrfdrfeExtTrim0.magnOffset);
        }
    }

    LRF_temperatureCompensateDcoldo(temperature, trimDef);

    uint32_t divLdoVoutTrim = trimDef->trim1.fields.divLdo.voutTrim;

    /* Most significant bit is inverted */
    divLdoVoutTrim ^= 0x40U;

    divLdoVoutTrim += divLdoTempOffset;

    /* Saturate at maximum value */
    if (divLdoVoutTrim > (LRFDRFE_DIVLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S))
    {
        divLdoVoutTrim = (LRFDRFE_DIVLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S);
    }
    /* Write back with most signigicant bit inverted back */
    HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_DIVLDOF) = HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_DIVLDOF) | (((uint16_t) divLdoVoutTrim ^ 0x40U) << RFE_COMMON_RAM_DIVLDOF_VOUTTRIM_S);

    /* Add offset to initial value */
    divLdoVoutTrim += HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_DIVLDOIOFF);

    /* Saturate at maximum value */
    if (divLdoVoutTrim > (LRFDRFE_DIVLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S))
    {
        divLdoVoutTrim = (LRFDRFE_DIVLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S);
    }
    /* Write back with most signigicant bit inverted back */
    HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_DIVLDOI) = HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_DIVLDOI) | (((uint16_t) divLdoVoutTrim ^ 0x40U) << RFE_COMMON_RAM_DIVLDOI_VOUTTRIM_S);

    uint32_t tdcLdoVoutTrim = trimDef->trim1.fields.tdcLdo.voutTrim;

    if (tdcLdoTempOffset > 0U)
    {
        /* Most significant bit is inverted */
        tdcLdoVoutTrim ^= 0x40U;

        tdcLdoVoutTrim += tdcLdoTempOffset;

        /* Saturate at maximum value */
        if (tdcLdoVoutTrim > (LRFDRFE_TDCLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S))
        {
            tdcLdoVoutTrim = (LRFDRFE_TDCLDO_VOUTTRIM_ONES >> LRFDRFE_DIVLDO_VOUTTRIM_S);
        }

        /* Invert back */
        tdcLdoVoutTrim ^= 0x40U;
    }
    /* Write back */
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_TDCLDO) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_TDCLDO) | (tdcLdoVoutTrim << LRFDRFE_TDCLDO_VOUTTRIM_S);

    uint32_t rtrim = trimDef->trim2.fields.dco.tailresTrim;

    /* Temperature compensation and PHY offset can only be applied if the value is not above the saturation level */
    /* If RTRIM from FCFG is above this, always use that level */
    if (rtrim < LRF_DEFAULT_RTRIM_MAX)
    {
        /* Add offset from temperature compensation */
        rtrim += rtrimTempOffset;

        /* Add offset from PHY */
        rtrim += HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_RTRIMOFF);

        /* Saturate */
        if (rtrim > LRF_DEFAULT_RTRIM_MAX)
        {
            rtrim = LRF_DEFAULT_RTRIM_MAX;
        }
    }

    /* Ensure it is not smaller than minimum from PHY */
    uint32_t minRtrim = HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_RTRIMMIN);
    if (rtrim < minRtrim)
    {
        rtrim = minRtrim;
    }
#if defined(DeviceFamily_PARENT) && (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
    /* RTRIM Tx Compensation might be required depending on the selected Tx output power. For now, initialize RAM registers to default values. */
    HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_RTRIMTXCMP) = 0;
    /* Write rtrim into RAM register instead of the usual register (LRFDRFE:DCO.TAILRESTRIM) */
    HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_RTRIM) = (rtrim << RFE_COMMON_RAM_RTRIM_VAL_S);
    /* Signal the LRF to use the default RTRIM value. This might change based on the programmed Tx output power */
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_SPARE5) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_SPARE5) & ~(LRF_CC27XX_RFE_SPARE5_RTRIM_TX_COMP_BITMASK);
#else
    /* Write into register */
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_DCO) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_DCO) | (rtrim << LRFDRFE_DCO_TAILRESTRIM_S);
#endif

    /* Get RSSI offset from FCFG */
    int32_t rssiOffset = trimDef->trim4.rssiOffset;

#if defined(DeviceFamily_CC23X0R5) || defined(DeviceFamily_CC23X0R22) || defined(DeviceFamily_CC2340R53)
    /* RCL-335: Some devices (State D) have an error in the programmed RSSI offset */
    if (trimDef->revision == LRF_TRIM_VERSION_RSSIOFFSET_ISSUE_CC23X0R5)
    {
        if (rssiOffset <= LRF_TRIM_LIMIT_RSSIOFFSET_ISSUE_CC23X0R5)
        {
            rssiOffset += LRF_TRIM_CORRECTION_RSSIOFFSET_ISSUE_CC23X0R5;
        }
    }
#endif

    /* Apply temperature compensation */
    rssiOffset += rssiTempOffset;

    /* Apply PHY specific offset */
    rssiOffset += (int32_t) HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_PHYRSSIOFFSET);

    /* Store in HW register */
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_RSSIOFFSET) = (uint32_t) rssiOffset;

    if (((HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_AGCINFO) & RFE_COMMON_RAM_AGCINFO_MODE_M) >> RFE_COMMON_RAM_AGCINFO_MODE_S) == (RFE_COMMON_RAM_AGCINFO_MODE_FAST >> RFE_COMMON_RAM_AGCINFO_MODE_S))
    {
        uint32_t spare0Val = HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_SPARE0SHADOW);
        if (agcHighGainOffset != 0 || agcLowGainOffset != 0)
        {
            int32_t lowGain = (int32_t) ((spare0Val & RFE_SPARE0_LOW_GAIN_BM) >> RFE_SPARE0_LOW_GAIN);
            int32_t highGain = (int32_t) ((spare0Val & RFE_SPARE0_HIGH_GAIN_BM) >> RFE_SPARE0_HIGH_GAIN);
            if (agcLowGainOffset != 0)
            {
                lowGain += agcLowGainOffset;
                if (lowGain < 0)
                {
                    lowGain = 0;
                }
                if (lowGain > (int32_t) (RFE_SPARE0_LOW_GAIN_BM >> RFE_SPARE0_LOW_GAIN))
                {
                    lowGain = (RFE_SPARE0_LOW_GAIN_BM >> RFE_SPARE0_LOW_GAIN);
                }
            }
            if (agcHighGainOffset != 0)
            {
                highGain += agcHighGainOffset;
                if (highGain < 0)
                {
                    highGain = 0;
                }
                if (highGain > (int32_t) (RFE_SPARE0_HIGH_GAIN_BM >> RFE_SPARE0_HIGH_GAIN))
                {
                    highGain = (RFE_SPARE0_HIGH_GAIN_BM >> RFE_SPARE0_HIGH_GAIN);
                }
            }
            spare0Val = (spare0Val & ~(RFE_SPARE0_LOW_GAIN_BM | RFE_SPARE0_HIGH_GAIN_BM)) |
                (uint32_t) (lowGain << RFE_SPARE0_LOW_GAIN) | (uint32_t) (highGain << RFE_SPARE0_HIGH_GAIN);
        }
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_SPARE0) = spare0Val;
    }

    uint32_t spare1Val = HWREGH_READ_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_SPARE1SHADOW);
    if (agcValOffset != 0)
    {
        int32_t agcVal = (int32_t) ((spare1Val & RFE_SPARE1_AGC_VALUE_BM) >> RFE_SPARE1_AGC_VALUE);
        agcVal += agcValOffset;
        if (agcVal < 0)
        {
            agcVal = 0;
        }
        if (agcVal > (int32_t) (RFE_SPARE1_AGC_VALUE_BM >> RFE_SPARE1_AGC_VALUE))
        {
            agcVal = (RFE_SPARE1_AGC_VALUE_BM >> RFE_SPARE1_AGC_VALUE);
        }
        spare1Val = (uint32_t) ((spare1Val & ~RFE_SPARE1_AGC_VALUE_BM) | ((uint32_t) agcVal << RFE_SPARE1_AGC_VALUE));
    }
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_SPARE1) = spare1Val;
}

static void LRF_setTrimCommon(const LRF_TrimDef *trimDef, const LRF_SwConfig *swConfig)
{
    uint8_t bwIndex = 0;
    uint8_t bwIndexDither = 0;
    uint8_t revision = trimDef->revision;
    if (revision >= LRF_TRIM_MIN_VERSION_FULL_FEATURES)
    {
        bwIndex = swConfig->bwIndex;
        bwIndexDither = swConfig->bwIndexDither;
    }
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCQUANT) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCQUANT) | trimDef->trimVariant[bwIndex].ifadcQuant;
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC0)     = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC0) | trimDef->trimVariant[bwIndex].ifadc0;
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC1)     = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC1) | trimDef->trimVariant[bwIndex].ifadc1;
    HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCLF)    = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCLF) | trimDef->trimVariant[bwIndex].ifadclf;

    if (revision >= LRF_TRIM_MIN_VERSION_FULL_FEATURES)
    {
        /* Set AAFCAP according to BW */
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFAMPRFLDO) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFAMPRFLDO) | trimDef->trim4.ifamprfldo[bwIndex];

        if (bwIndexDither != bwIndex)
        {
            /* Use different setting of dither settings compared to the rest of the IFADC0 register. */
            HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC0) = (HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADC0) & ~(LRFDRFE_IFADC0_DITHEREN_M | LRFDRFE_IFADC0_DITHERTRIM_M)) |
                ((uint32_t) trimDef->trimVariant[bwIndexDither].ifadc0 & (LRFDRFE_IFADC0_DITHEREN_M | LRFDRFE_IFADC0_DITHERTRIM_M));
        }
    }
}

static void LRF_applyTrim(const LRF_TrimDef *trimDef, const LRF_SwConfig *swConfig)
{

    if (trimDef != NULL)
    {
#if (DeviceFamily_PARENT == DeviceFamily_PARENT_CC27XX)
        HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_PATRIM01) = trimDef->trim0.pa2trim01;
        HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_PATRIM23) = trimDef->trim4.pa2trim23;
#else
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_PA0)        = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_PA0) | trimDef->trim0.pa0;
#endif
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_ATSTREFH)   = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_ATSTREFH) | trimDef->trim0.atstRefH;

        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_LNA)        = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_LNA) | trimDef->trim1.lna;
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFAMPRFLDO) = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFAMPRFLDO) | trimDef->trim1.ifampRfLdo;

        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCALDO)  = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCALDO) | trimDef->trim2.ifadcAldo;
        HWREG_WRITE_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCDLDO)  = HWREG_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFADCDLDO) | trimDef->trim2.ifadcDldo;

        /* DEMIQMC0 has no fields not to be trimmed */
        HWREG_WRITE_LRF(LRFDMDM_BASE + LRFDMDM_O_DEMIQMC0)   =  trimDef->trim4.demIQMC0;

        /* Write trim to shadow registers */
        HWREGH_WRITE_LRF(LRFD_RFERAM_BASE + RFE_COMMON_RAM_O_IFAMPRFLDODEFAULT) = HWREGH_READ_LRF(LRFDRFE_BASE + LRFDRFE_O_IFAMPRFLDO) & LRFDRFE_IFAMPRFLDO_TRIM_M;

        LRF_setTrimCommon(trimDef, swConfig);
        LRF_temperatureCompensateTrim(trimDef);
    }
}

static inline void apply() {
    const LRF_SwConfig config = { 0, 1 };
    // offsetof(fcfg_t, appTrims) = 0x2f0, verified with the working Zephyr TI C header.
    const auto trims = reinterpret_cast<const LRF_TrimDef *>(FCFG_BASE + 0x2f0);
    LRF_applyTrim(trims, &config);
}
}
#undef HWREG_READ_LRF
#undef HWREG_WRITE_LRF
#undef HWREGH_READ_LRF
#undef HWREGH_WRITE_LRF
#undef DeviceFamily_PARENT
#undef DeviceFamily_PARENT_CC27XX
