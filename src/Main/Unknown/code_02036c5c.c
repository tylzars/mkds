#include "Main/Unknown/code_02036c5c.h"

#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "os_irqHandler.h"
#include "gx.h"
#include "Main/Unknown/code_02039774.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02038000.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02148950.h"
#include "code_0214a5f0.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036820.h"

void UpdateBrightnessFade(BrightnessFade *fade) {
    switch (fade->mState) {
        case 0:
            break;
        case 1:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = 2;
                fade->mBrightness = 0;
            } else {
                fade->mBrightness = 0x10 - (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == 0) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
        case 2:
            fade->mBrightness = 0;
            break;
        case 3:
            fade->mFadeFrames++;
            if (fade->mFadeFrames >= fade->mFadeFrameCount) {
                fade->mState = 0;
                fade->mBrightness = 0x10;
            } else {
                fade->mBrightness = (fade->mFadeFrames << 4) / fade->mFadeFrameCount;
            }
            if (fade->mPositive == 0) {
                fade->mBrightness = -fade->mBrightness;
            }
            break;
    }
}

void InitBrightnessFades(void) {
    gMainBrightnessFade.mState = 0;
    gMainBrightnessFade.mPositive = 1;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = 0x10;
    gSubBrightnessFade.mState = 0;
    gSubBrightnessFade.mPositive = 1;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = 0x10;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
}

void WaitIrqAndTurnOnDisplays(void) {
    OS_WaitIrq(1, 1);
    GX_DispOn();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT | 0x10000;
}

void InitDisplayBgRecords(void *recordsBase, u32 bgMode) {
    DisplayBgRecords *records = recordsBase;
    u32 bgCntMode;
    records->mBg0CntLow2 = 0;
    records->mBg0CntBit6 = 0;
    records->mBg0CntVal14 = 0;
    records->mBg0CntVal7 = 0;
    records->mBg0CntVal8 = 0;
    records->mBg0CntVal2 = 0;
    records->mBg0CntVal13 = 0;
    records->mBg1CntLow2 = 1;
    records->mBg1CntVal14 = 0;
    records->mBg1CntVal7 = 0;
    records->mBg1CntBit6 = 0;
    records->mBg1CntVal8 = 0;
    records->mBg1CntVal2 = 0;
    records->mBg1CntVal13 = 0;
    bgCntMode = 6;
    switch (bgMode) {
        case 0:
        case 1:
        case 3:
            bgCntMode = 1;
            break;
        case 2:
        case 4:
            bgCntMode = 2;
            break;
        case 5:
            bgCntMode = 3;
            break;
        case 6:
            break;
    }
    records->mBg2Mode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg2CntLow2 = 2;
            records->mBg2CntVal14 = 0;
            records->mUnk_2a = 0;
            records->mBg2CntBit6 = 0;
            records->mBg2CntVal8 = 0;
            records->mBg2CntVal2 = 0;
            break;
        case 2:
            records->mBg2CntLow2 = 2;
            records->mBg2CntVal14 = 0;
            records->mBg2CntBit6 = 0;
            records->mUnk_2a = 0;
            records->mBg2CntVal8 = 0;
            records->mBg2CntVal2 = 0;
            break;
        case 3:
            records->mBg2CntLow2 = 2;
            records->mBg2CntBit6 = 0;
            records->mBg2CntVal14 = 0;
            records->mUnk_2a = 0;
            records->mBg2CntVal8 = 0;
            break;
    }
    bgCntMode = 6;
    switch (bgMode) {
        case 0:
            bgCntMode = 1;
            break;
        case 1:
        case 2:
            bgCntMode = 2;
            break;
        case 3:
        case 4:
        case 5:
            bgCntMode = 3;
            break;
        case 6:
            break;
    }
    records->mBg3Mode = bgCntMode;
    switch (bgCntMode) {
        case 1:
            records->mBg3CntLow2 = 2;
            records->mBg3CntVal14 = 0;
            records->mUnk_3a = 0;
            records->mBg3CntBit6 = 0;
            records->mBg3CntVal8 = 0;
            records->mBg3CntVal2 = 0;
            break;
        case 2:
            records->mBg3CntLow2 = 2;
            records->mBg3CntVal14 = 0;
            records->mBg3CntBit6 = 0;
            records->mUnk_3a = 0;
            records->mBg3CntVal8 = 0;
            records->mBg3CntVal2 = 0;
            break;
        case 3:
            records->mBg3CntLow2 = 2;
            records->mBg3CntBit6 = 0;
            records->mBg3CntVal14 = 0;
            records->mUnk_3a = 0;
            records->mBg3CntVal8 = 0;
            break;
    }
    records->mUnk_40 = 0;
    records->mUnk_42 = 0;
}

void InitDisplaySettings(DisplaySettings *settings, void *descriptorBase) {
    DisplaySettingsDesc *descriptor = descriptorBase;
    *(DisplaySettingsDesc *) settings = *descriptor;
    InitDisplayBgRecords(&settings->mMainBg0, descriptor->mMainBgMode);
    InitDisplayBgRecords(&settings->mSubBg0, descriptor->mSubBgMode);
    settings->mG3xParams = NULL;
    settings->mFrameStartTick = 0;
    settings->mWaitEndTick = 0;
    settings->mTimeBeforeWait = 0;
    settings->mTimeSinceWaitEnd = 0;
    settings->mTimeSinceFrameStart = 0;
    settings->mUnk_b4 = 0;
    settings->mIrqCallback = NULL;
    settings->mFrameFlags = 0;
}

void *CreateDisplaySettings(void *heap, void *descriptor) {
    DisplaySettings *settings = HeapAlloc(heap, 0xdc);
    G3xParams *g3xParams;
    InitDisplaySettings(settings, descriptor);
    if (settings->mBg0As == 1) {
        g3xParams = HeapAlloc(heap, 8);
        g3xParams->mClearColor = 0x5000;
        g3xParams->mSwapBit0 = 1;
        g3xParams->mSwapBit1 = 1;
        settings->mG3xParams = g3xParams;
    }
    return settings;
}

void SetBg0Record(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13) {
    DisplayBgRecords *records = recordsBase;
    records->mBg0CntLow2 = cntLow2;
    records->mBg0CntVal14 = cntVal14;
    records->mBg0CntVal7 = cntVal7;
    records->mBg0CntBit6 = cntBit6;
    records->mBg0CntVal8 = cntVal8;
    records->mBg0CntVal2 = cntVal2;
    records->mBg0CntVal13 = cntVal13;
}

void SetBg1Record(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8, u32 cntVal2,
                  u32 cntVal13) {
    DisplayBgRecords *records = recordsBase;
    records->mBg1CntLow2 = cntLow2;
    records->mBg1CntVal14 = cntVal14;
    records->mBg1CntVal7 = cntVal7;
    records->mBg1CntBit6 = cntBit6;
    records->mBg1CntVal8 = cntVal8;
    records->mBg1CntVal2 = cntVal2;
    records->mBg1CntVal13 = cntVal13;
}

void SetBg2RecordParams(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2) {
    DisplayBgRecords *records = recordsBase;
    records->mBg2CntLow2 = cntLow2;
    records->mBg2CntBit6 = cntBit6;
    records->mBg2CntVal14 = cntVal14;
    records->mUnk_2a = e;
    records->mBg2CntVal8 = cntVal8;
    records->mBg2CntVal2 = cntVal2;
}

void SetBg3RecordParams(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8, u32 cntVal2) {
    DisplayBgRecords *records = recordsBase;
    records->mBg3CntLow2 = cntLow2;
    records->mBg3CntBit6 = cntBit6;
    records->mBg3CntVal14 = cntVal14;
    records->mUnk_3a = e;
    records->mBg3CntVal8 = cntVal8;
    records->mBg3CntVal2 = cntVal2;
}

void SetBg2RecordMode5(void *recordsBase, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8) {
    DisplayBgRecords *records = recordsBase;
    records->mBg2Mode = 5;
    records->mBg2CntLow2 = cntLow2;
    records->mBg2CntBit6 = cntBit6;
    records->mBg2CntVal14 = cntVal14;
    records->mUnk_2a = e;
    records->mBg2CntVal8 = cntVal8;
}

u32 SetG3xSwapBits(DisplaySettings *settings, u32 swapBit0, u32 swapBit1) {
    u32 value0 = (u32) settings;
    u32 swapBit0Copy = swapBit0;
    u32 swapBit1Copy = swapBit1;
    u32 g3xParams;
    g3xParams = *(const u32 *) ((value0) + (108));
    settings->mG3xParams->mSwapBit0 = swapBit0Copy;
    value0 = *(const u32 *) ((value0) + (108));
    *(u8 *) ((value0) + (3)) = swapBit1Copy;
    return value0;
}

void func_02038c94(DisplaySettings *settings, u32 value) {
    settings->mUnk_b2 = value;
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_0203810C_ARG_0 } Unk0203810c_Arg;

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_0203810c_inline(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline2(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7,
                                         Unk0203810c_Arg val8, Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline3(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8,
                                         Unk0203810c_Arg val2, Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_0203810c_inline4(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_0203810c_inline5(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_0203810c_inline6(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_020386d0_inline(vu16 *cntReg, Bg23CntFields *fields) {
    *cntReg = (*cntReg & ~3) | fields->mBgCntLow2;
    if (fields->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline2(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val7,
                                         Unk0203810c_Arg val8, Unk0203810c_Arg val2) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline3(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val8,
                                         Unk0203810c_Arg val2, Unk0203810c_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_020386d0_inline4(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_020386d0_inline5(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x80 | (val8 << 8) | (val13 << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_020386d0_inline6(vu16 *cntReg, Unk0203810c_Arg val14, Unk0203810c_Arg val13,
                                         Unk0203810c_Arg val8) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | 0x84 | (val8 << 8) | (val13 << 13);
}

void ApplyBg2Cnt(Bg23Cnt *cnt, s32 isMainScreen) {
    s32 matrix[4];
    Bg23CntFields *fields;

    matrix[1] = 0;
    matrix[2] = 0;
    matrix[0] = 0x1000;
    matrix[3] = 0x1000;
    fields = &cnt->mFields;
    switch (cnt->mMode) {
        case 1:
            if (isMainScreen != 0) {
                reg_G2_BG2OFS = 0;
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline2(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline2(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline3(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->mUnk_06);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline3(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->mUnk_06);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline4(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline4(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline5(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline5(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, fields);
                func_020386d0_inline6(&reg_G2_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, matrix, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, fields);
                func_020386d0_inline6(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

void ApplyBg3Cnt(Bg23Cnt *cnt, s32 isMainScreen) {
    s32 matrix[4];
    Bg23CntFields *fields;

    matrix[1] = 0;
    matrix[2] = 0;
    matrix[0] = 0x1000;
    matrix[3] = 0x1000;
    fields = &cnt->mFields;
    switch (cnt->mMode) {
        case 1:
            if (isMainScreen != 0) {
                reg_G2_BG3OFS = 0;
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline2(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline2(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8,
                                      (Unk0203810c_Arg) fields->mBgCntVal2);
            }
            break;
        case 2:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline3(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->mUnk_06);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline3(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mBgCntVal8, (Unk0203810c_Arg) fields->mBgCntVal2,
                                      (Unk0203810c_Arg) fields->mUnk_06);
            }
            break;
        case 3:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline4(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline4(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 4:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline5(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline5(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        case 5:
            if (isMainScreen != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, fields);
                func_0203810c_inline6(&reg_G2_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, matrix, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, fields);
                func_0203810c_inline6(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) fields->mBgCntVal14,
                                      (Unk0203810c_Arg) fields->mUnk_06, (Unk0203810c_Arg) fields->mBgCntVal8);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls MIi_CpuClearFast with v, passed through a stack offset of its own.
static inline void func_02037abc_inline(u32 fillValue, void *destination, u32 size) {
    volatile u32 fillValueCopy = fillValue;
    MIi_CpuClearFast(fillValueCopy, destination, size);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_02037abc_inline2(vu16 *cntReg, Bg01Cnt *cnt) {
    *cntReg = (*cntReg & ~3) | cnt->mBgCntLow2;
    if (cnt->mBgCntBit6 != 0) {
        *cntReg |= 0x40;
    } else {
        *cntReg &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void func_02037abc_inline3(vu32 *reg, Unk02037abc_Arg bits) {
    *reg = (*reg & 0xffcfffef) | bits;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void func_02037abc_inline4(Unk02037abc_Arg bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | bits;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void func_02037abc_inline5(Unk02037abc_Arg bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | bits;
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from five values.
static inline void func_02037abc_inline6(vu16 *cntReg, Unk02037abc_Arg val14, Unk02037abc_Arg val7,
                                         Unk02037abc_Arg val8, Unk02037abc_Arg val2, Unk02037abc_Arg val13) {
    *cntReg = (*cntReg & 0x43) | (val14 << 14) | (val7 << 7) | (val8 << 8) | (val2 << 2) | (val13 << 13);
}

void InitDisplayFromSettings(void *settingsPtr) {
    DisplaySettings *settings;
    Bg01Cnt *cnt;
    u16 clearColor;

    settings = settingsPtr;
    gDisplaySettings = settings;
    ClearLcdcBanksByState();
    func_02037abc_inline(0xc0, (void *) 0x07000000, 0x400);
    func_02037abc_inline(0xc0, (void *) 0x07000400, 0x400);
    func_02037abc_inline(0, (void *) 0x05000000, 0x400);
    func_02037abc_inline(0, (void *) 0x05000400, 0x400);
    if (gDisplaySettings->mBankForBG != 0) {
        GX_SetBankForBG(gDisplaySettings->mBankForBG);
    }
    if (gDisplaySettings->mBankForOBJ != 0) {
        GX_SetBankForOBJ(gDisplaySettings->mBankForOBJ);
    }
    if (gDisplaySettings->mBankForBGExtPltt != 0) {
        GX_SetBankForBGExtPltt(gDisplaySettings->mBankForBGExtPltt);
    }
    if (gDisplaySettings->mBankForOBJExtPltt != 0) {
        GX_SetBankForOBJExtPltt(gDisplaySettings->mBankForOBJExtPltt);
    }
    if (gDisplaySettings->mBankForTex != 0) {
        GX_SetBankForTex(gDisplaySettings->mBankForTex);
    }
    if (gDisplaySettings->mBankForTexPltt != 0) {
        GX_SetBankForTexPltt(gDisplaySettings->mBankForTexPltt);
    }
    if (gDisplaySettings->mBankForClearImage != 0) {
        GX_SetBankForClearImage(gDisplaySettings->mBankForClearImage);
    }
    if (gDisplaySettings->mBankForSubBG != 0) {
        GX_SetBankForSubBG(gDisplaySettings->mBankForSubBG);
    }
    if (gDisplaySettings->mBankForSubOBJ != 0) {
        GX_SetBankForSubOBJ(gDisplaySettings->mBankForSubOBJ);
    }
    if (gDisplaySettings->mBankForSubBGExtPltt != 0) {
        GX_SetBankForSubBGExtPltt(gDisplaySettings->mBankForSubBGExtPltt);
    }
    if (gDisplaySettings->mBankForSubOBJExtPltt != 0) {
        GX_SetBankForSubOBJExtPltt(gDisplaySettings->mBankForSubOBJExtPltt);
    }
    if (gDisplaySettings->mBankForARM7 != 0) {
        SetBankForARM7ByState(gDisplaySettings->mBankForARM7);
    }
    if (gDisplaySettings->mBankForLCDC != 0) {
        GX_SetBankForLCDC(gDisplaySettings->mBankForLCDC);
    }
    data_02175614.mUnk_00;
    GX_SetGraphicsMode(settings->mDispMode, settings->mMainBgMode, settings->mBg0As);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (settings->mMainDisplayMask << 8);
    GXS_SetGraphicsMode(settings->mSubBgMode);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (settings->mSubDisplayMask << 8);
    if (settings->mBg0As == 1) {
        G3X_Init();
        G3X_InitTable();
        G3X_InitMtxStack();
        reg_G3X_DISP3DCNT &= 0xffffcffd;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
        clearColor = settings->mG3xParams->mClearColor;
        G3X_SetClearColor((u16) (clearColor & 0x7fff), (u8) ((clearColor & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (settings->mMainDisplayMask & 1) {
        cnt = &settings->mMainBg0;
        func_02037abc_inline2(&reg_G2_BG0CNT, cnt);
        if (settings->mBg0As == 1) {
            G2Bg0OfsWrite(0);
        } else {
            reg_G2_BG0OFS = 0;
            func_02037abc_inline6(&reg_G2_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                                  (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                                  (Unk02037abc_Arg) cnt->mBgCntVal13);
        }
    }
    if (settings->mSubDisplayMask & 1) {
        reg_G2S_DB_BG0OFS = 0;
        cnt = &settings->mSubBg0;
        func_02037abc_inline2(&reg_G2S_DB_BG0CNT, cnt);
        func_02037abc_inline6(&reg_G2S_DB_BG0CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 2) {
        reg_G2_BG1OFS = 0;
        cnt = &settings->mMainBg1;
        func_02037abc_inline2(&reg_G2_BG1CNT, cnt);
        func_02037abc_inline6(&reg_G2_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mSubDisplayMask & 2) {
        reg_G2S_DB_BG1OFS = 0;
        cnt = &settings->mSubBg1;
        func_02037abc_inline2(&reg_G2S_DB_BG1CNT, cnt);
        func_02037abc_inline6(&reg_G2S_DB_BG1CNT, (Unk02037abc_Arg) cnt->mBgCntVal14, (Unk02037abc_Arg) cnt->mBgCntVal7,
                              (Unk02037abc_Arg) cnt->mBgCntVal8, (Unk02037abc_Arg) cnt->mBgCntVal2,
                              (Unk02037abc_Arg) cnt->mBgCntVal13);
    }
    if (settings->mMainDisplayMask & 4) {
        ApplyBg2Cnt(&settings->mMainBg2, 1);
    }
    if (settings->mSubDisplayMask & 4) {
        ApplyBg2Cnt(&settings->mSubBg2, 0);
    }
    if (settings->mMainDisplayMask & 8) {
        ApplyBg3Cnt(&settings->mMainBg3, 1);
    }
    if (settings->mSubDisplayMask & 8) {
        ApplyBg3Cnt(&settings->mSubBg3, 0);
    }
    if (settings->mMainDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GX_DISPCNT, (Unk02037abc_Arg) settings->mUnk_68);
        func_02037abc_inline4((Unk02037abc_Arg) settings->mUnk_6a);
    }
    if (settings->mSubDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GXS_DB_DISPCNT, (Unk02037abc_Arg) settings->mUnk_b0);
        func_02037abc_inline5((Unk02037abc_Arg) settings->mUnk_b2);
    }
    reg_GX_POWCNT |= 0x8000;
}

void DisableAllBanksAndNullDisplaySettings(void) {
    DisableAllBanks();
    gDisplaySettings = NULL;
}

void PrepareDisplayFrame(void) {
    DisplaySettings *settings;
    u64 tick;
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mFrameStartTick = tick;
    if (settings->mBg0As == 1) {
        G3X_Reset();
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(0);
    }
}

u32 func_02037a20(void) {
    return (gDisplaySettings->mFrameFlags & 2) ? 1 : 0;
}

u32 ClearFrameFinishedFlag(void) {
    u32 value0;
    u32 settings;
    value0 = (u32) &gDisplaySettings;
    settings = *(const u32 *) ((value0) + (0));
    value0 = gDisplaySettings->mFrameFlags;
    value0 = (value0) & ~(1u);
    gDisplaySettings->mFrameFlags = value0;
    return value0;
}

static inline void func_02036d3c_inline(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 0 || (fade->mState == 3 && fade->mPositive == 1)) {
        return;
    }
    fade->mPositive = 1;
    if (fade->mState != 1) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 3;
    fade->mFadeFrameCount = frameCount;
}

static inline void func_02036f10_inline(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 0 || (fade->mState == 3 && fade->mPositive == 0)) {
        return;
    }
    fade->mPositive = 0;
    if (fade->mState != 1) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 3;
    fade->mFadeFrameCount = frameCount;
}

static inline void func_020370d4_inline(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    fade->mPositive = 0;
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    if (fade->mState != 3) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 1;
    fade->mFadeFrameCount = frameCount;
}

static inline void func_02037288_inline(BrightnessFade *fade, s16 frameCount) {
    if (fade->mState == 2 || fade->mState == 1) {
        return;
    }
    if (fade->mState != 3) {
        fade->mFadeFrames = 0;
    } else {
        fade->mFadeFrames = (frameCount * fade->mBrightness) / 16;
    }
    fade->mState = 1;
    fade->mFadeFrameCount = frameCount;
}

void FinishDisplayFrame(void) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    settings = gDisplaySettings;
    if (settings->mBg0As == 1) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void func_02037658(s32 a) {
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    BOOL swapAndWait;
    DisplaySettings *settings;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    if (a == 0 || (gDisplaySettings->mFrameFlags & 2) == 0) {
        swapAndWait = TRUE;
    } else {
        swapAndWait = FALSE;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == 1 && swapAndWait != FALSE) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    if (swapAndWait != FALSE) {
        for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
            OS_WaitIrq(1, 1);
        }
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void FinishDisplayFrameSwapIf(s32 doSwap) {
    DisplaySettings *settings;
    u64 tick;
    s16 prevMainBrightness;
    s16 prevSubBrightness;
    u16 i;
    prevMainBrightness = gMainBrightnessFade.mBrightness;
    prevSubBrightness = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    settings = gDisplaySettings;
    if (settings->mBg0As == 1 && doSwap != 0) {
        reg_G3_SWAP_BUFFERS = (settings->mG3xParams->mSwapBit1 << 1) | settings->mG3xParams->mSwapBit0;
    }
    settings = gDisplaySettings;
    tick = OS_GetTick();
    settings->mTimeBeforeWait = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (prevMainBrightness != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    }
    if (prevSubBrightness != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void RecordFrameTimes(void) {
    u64 tick;
    DisplaySettings *settings;
    tick = OS_GetTick();
    if (gFrameCallback != NULL) {
        gFrameCallback(3);
    }
    settings = gDisplaySettings;
    settings->mTimeSinceWaitEnd = (tick - settings->mWaitEndTick) * 0xfa00 / 0x82ea;
    settings = gDisplaySettings;
    settings->mTimeSinceFrameStart = (tick - settings->mFrameStartTick) * 0xfa00 / 0x82ea;
}

void StartFadeToClearOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02037288_inline(&gMainBrightnessFade, frameCount);
    } else {
        func_02037288_inline(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToClear(s16 frameCount) {
    func_02037288_inline(&gMainBrightnessFade, frameCount);
    func_02037288_inline(&gSubBrightnessFade, frameCount);
}

void StartFadeToClearNegativeOneScreen(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_020370d4_inline(&gMainBrightnessFade, frameCount);
    } else {
        func_020370d4_inline(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToClearNegative(s16 frameCount) {
    func_020370d4_inline(&gMainBrightnessFade, frameCount);
    func_020370d4_inline(&gSubBrightnessFade, frameCount);
}

void StartFadeToFadedNegativeOneScreen(s32 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02036f10_inline(&gMainBrightnessFade, frameCount);
    } else {
        func_02036f10_inline(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToFadedNegative(s16 frameCount) {
    func_02036f10_inline(&gMainBrightnessFade, frameCount);
    func_02036f10_inline(&gSubBrightnessFade, frameCount);
}

void StartFadeToFadedPositiveOneScreen(s16 frameCount, s32 isMainScreen) {
    if (isMainScreen != 0) {
        func_02036d3c_inline(&gMainBrightnessFade, frameCount);
    } else {
        func_02036d3c_inline(&gSubBrightnessFade, frameCount);
    }
}

void StartFadeToFadedPositive(s16 frameCount) {
    func_02036d3c_inline(&gMainBrightnessFade, frameCount);
    func_02036d3c_inline(&gSubBrightnessFade, frameCount);
}

u32 AreBrightnessFadesFaded(void) {
    if (gMainBrightnessFade.mState == 0 && gSubBrightnessFade.mState == 0) {
        return 1;
    }
    return 0;
}

void SetBrightnessFadesClear(void) {
    gMainBrightnessFade.mState = 2;
    gMainBrightnessFade.mPositive = 0;
    gMainBrightnessFade.mFadeFrames = 0;
    gMainBrightnessFade.mFadeFrameCount = 0;
    gMainBrightnessFade.mBrightness = 0;
    gSubBrightnessFade.mState = 2;
    gSubBrightnessFade.mPositive = 0;
    gSubBrightnessFade.mFadeFrames = 0;
    gSubBrightnessFade.mFadeFrameCount = 0;
    gSubBrightnessFade.mBrightness = 0;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, gSubBrightnessFade.mBrightness);
}

u32 AreBrightnessFadesClear(void) {
    if ((gMainBrightnessFade.mState == 2) && (gSubBrightnessFade.mState == 2)) {
        return 1;
    }
    return 0;
}
