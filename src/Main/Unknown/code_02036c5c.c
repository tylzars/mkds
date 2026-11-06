#include "Main/Unknown/code_02036c5c.h"

#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200c894.h"
#include "code_021488e8.h"
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

void UpdateBrightnessFade(BrightnessFade *a) {
    switch (a->mState) {
        case 0:
            break;
        case 1:
            a->mFadeFrames++;
            if (a->mFadeFrames >= a->mFadeFrameCount) {
                a->mState = 2;
                a->mBrightness = 0;
            } else {
                a->mBrightness = 0x10 - (a->mFadeFrames << 4) / a->mFadeFrameCount;
            }
            if (a->mPositive == 0) {
                a->mBrightness = -a->mBrightness;
            }
            break;
        case 2:
            a->mBrightness = 0;
            break;
        case 3:
            a->mFadeFrames++;
            if (a->mFadeFrames >= a->mFadeFrameCount) {
                a->mState = 0;
                a->mBrightness = 0x10;
            } else {
                a->mBrightness = (a->mFadeFrames << 4) / a->mFadeFrameCount;
            }
            if (a->mPositive == 0) {
                a->mBrightness = -a->mBrightness;
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
    GXx_SetMasterBrightness_((u16 *) 0x400006c, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_((u16 *) 0x400106c, gSubBrightnessFade.mBrightness);
}

void WaitIrqAndTurnOnDisplays(void) {
    OS_WaitIrq(1, 1);
    GX_DispOn();
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 | 0x10000;
}

void InitDisplayBgRecords(void *a, u32 b) {
    DisplayBgRecords *p = a;
    u32 c;
    p->mUnk_00 = 0;
    p->mUnk_02 = 0;
    p->mUnk_04 = 0;
    p->mUnk_06 = 0;
    p->mUnk_08 = 0;
    p->mUnk_0a = 0;
    p->mUnk_0c = 0;
    p->mUnk_10 = 1;
    p->mUnk_14 = 0;
    p->mUnk_16 = 0;
    p->mUnk_12 = 0;
    p->mUnk_18 = 0;
    p->mUnk_1a = 0;
    p->mUnk_1c = 0;
    c = 6;
    switch (b) {
        case 0:
        case 1:
        case 3:
            c = 1;
            break;
        case 2:
        case 4:
            c = 2;
            break;
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_20 = c;
    switch (c) {
        case 1:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_26 = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 2:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_26 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 3:
            p->mUnk_24 = 2;
            p->mUnk_26 = 0;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            break;
    }
    c = 6;
    switch (b) {
        case 0:
            c = 1;
            break;
        case 1:
        case 2:
            c = 2;
            break;
        case 3:
        case 4:
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_30 = c;
    switch (c) {
        case 1:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_36 = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 2:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_36 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 3:
            p->mUnk_34 = 2;
            p->mUnk_36 = 0;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            break;
    }
    p->mUnk_40 = 0;
    p->mUnk_42 = 0;
}

void InitDisplaySettings(DisplaySettings *a, void *b) {
    DisplaySettingsDesc *c = b;
    *(DisplaySettingsDesc *) a = *c;
    InitDisplayBgRecords(&a->mMainBg0, c->mMainBgMode);
    InitDisplayBgRecords(&a->mSubBg0, c->mSubBgMode);
    a->mG3xParams = NULL;
    a->mFrameStartTick = 0;
    a->mWaitEndTick = 0;
    a->mTimeBeforeWait = 0;
    a->mTimeSinceWaitEnd = 0;
    a->mTimeSinceFrameStart = 0;
    a->mUnk_b4 = 0;
    a->mIrqCallback = NULL;
    a->mFrameFlags = 0;
}

void *CreateDisplaySettings(void *a, void *b) {
    DisplaySettings *p = HeapAlloc(a, 0xdc);
    G3xParams *q;
    InitDisplaySettings(p, b);
    if (p->mBg0As == 1) {
        q = HeapAlloc(a, 8);
        q->mClearColor = 0x5000;
        q->mSwapBit0 = 1;
        q->mSwapBit1 = 1;
        p->mG3xParams = q;
    }
    return p;
}

void SetBg0Record(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    DisplayBgRecords *p = a;
    p->mUnk_00 = b;
    p->mUnk_04 = d;
    p->mUnk_06 = e;
    p->mUnk_02 = c;
    p->mUnk_08 = f;
    p->mUnk_0a = g;
    p->mUnk_0c = h;
}

void SetBg1Record(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    DisplayBgRecords *p = a;
    p->mUnk_10 = b;
    p->mUnk_14 = d;
    p->mUnk_16 = e;
    p->mUnk_12 = c;
    p->mUnk_18 = f;
    p->mUnk_1a = g;
    p->mUnk_1c = h;
}

void SetBg2RecordParams(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    DisplayBgRecords *p = a;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
    p->mUnk_2e = g;
}

void SetBg3RecordParams(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    DisplayBgRecords *p = a;
    p->mUnk_34 = b;
    p->mUnk_36 = c;
    p->mUnk_38 = d;
    p->mUnk_3a = e;
    p->mUnk_3c = f;
    p->mUnk_3e = g;
}

void SetBg2RecordMode5(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    DisplayBgRecords *p = a;
    p->mUnk_20 = 5;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
}

u32 SetG3xSwapBits(DisplaySettings *arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    value3 = *(const u32 *) ((value0) + (108));
    arg0->mG3xParams->mSwapBit0 = value1;
    value0 = *(const u32 *) ((value0) + (108));
    *(u8 *) ((value0) + (3)) = value2;
    return value0;
}

void func_02038c94(DisplaySettings *p0, u32 p1) {
    p0->mUnk_b2 = p1;
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_0203810C_ARG_0 } Unk0203810c_Arg;

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_0203810c_inline(vu16 *r, Bg23CntFields *q) {
    *r = (*r & ~3) | q->mUnk_00;
    if (q->mUnk_02 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline2(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_0203810c_inline3(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d << 2) | (e << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_0203810c_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_0203810c_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_0203810c_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (d << 8) | (c << 13);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_020386d0_inline(vu16 *r, Bg23CntFields *q) {
    *r = (*r & ~3) | q->mUnk_00;
    if (q->mUnk_02 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline2(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from four values.
static inline void func_020386d0_inline3(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d,
                                         Unk0203810c_Arg e) {
    *r = (*r & 0x43) | (b << 14) | (c << 8) | (d << 2) | (e << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from three values.
static inline void func_020386d0_inline4(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bit 7 and the rest from three values.
static inline void func_020386d0_inline5(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x80 | (d << 8) | (c << 13);
}

// Keeps bits 0, 1 and 6 of the halfword register r, sets bits 2 and 7 and the rest from three values.
static inline void func_020386d0_inline6(vu16 *r, Unk0203810c_Arg b, Unk0203810c_Arg c, Unk0203810c_Arg d) {
    *r = (*r & 0x43) | (b << 14) | 0x84 | (d << 8) | (c << 13);
}

void ApplyBg2Cnt(Bg23Cnt *a, s32 b) {
    s32 m[4];
    Bg23CntFields *q;

    m[1] = 0;
    m[2] = 0;
    m[0] = 0x1000;
    m[3] = 0x1000;
    q = &a->mFields;
    switch (a->mMode) {
        case 1:
            if (b != 0) {
                reg_G2_BG2OFS = 0;
                func_020386d0_inline(&reg_G2_BG2CNT, q);
                func_020386d0_inline2(&reg_G2_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            } else {
                reg_G2S_DB_BG2OFS = 0;
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, q);
                func_020386d0_inline2(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            }
            break;
        case 2:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, q);
                func_020386d0_inline3(&reg_G2_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, q);
                func_020386d0_inline3(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            }
            break;
        case 3:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, q);
                func_020386d0_inline4(&reg_G2_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, q);
                func_020386d0_inline4(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 4:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, q);
                func_020386d0_inline5(&reg_G2_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, q);
                func_020386d0_inline5(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 5:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2_BG2CNT, q);
                func_020386d0_inline6(&reg_G2_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, m, 0, 0, 0, 0);
                func_020386d0_inline(&reg_G2S_DB_BG2CNT, q);
                func_020386d0_inline6(&reg_G2S_DB_BG2CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        default:
            break;
    }
}

void ApplyBg3Cnt(Bg23Cnt *a, s32 b) {
    s32 m[4];
    Bg23CntFields *q;

    m[1] = 0;
    m[2] = 0;
    m[0] = 0x1000;
    m[3] = 0x1000;
    q = &a->mFields;
    switch (a->mMode) {
        case 1:
            if (b != 0) {
                reg_G2_BG3OFS = 0;
                func_0203810c_inline(&reg_G2_BG3CNT, q);
                func_0203810c_inline2(&reg_G2_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            } else {
                reg_G2S_DB_BG3OFS = 0;
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, q);
                func_0203810c_inline2(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08, (Unk0203810c_Arg) q->mUnk_0a);
            }
            break;
        case 2:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, q);
                func_0203810c_inline3(&reg_G2_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, q);
                func_0203810c_inline3(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_08,
                                      (Unk0203810c_Arg) q->mUnk_0a, (Unk0203810c_Arg) q->mUnk_06);
            }
            break;
        case 3:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, q);
                func_0203810c_inline4(&reg_G2_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, q);
                func_0203810c_inline4(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 4:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, q);
                func_0203810c_inline5(&reg_G2_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, q);
                func_0203810c_inline5(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        case 5:
            if (b != 0) {
                G2x_SetBGyAffine_(&reg_G2_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2_BG3CNT, q);
                func_0203810c_inline6(&reg_G2_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            } else {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, m, 0, 0, 0, 0);
                func_0203810c_inline(&reg_G2S_DB_BG3CNT, q);
                func_0203810c_inline6(&reg_G2S_DB_BG3CNT, (Unk0203810c_Arg) q->mUnk_04, (Unk0203810c_Arg) q->mUnk_06,
                                      (Unk0203810c_Arg) q->mUnk_08);
            }
            break;
        default:
            break;
    }
}

// Enum-typed parameters of the inlines below: the original reads their values before the register.
typedef enum { UNK_02037ABC_ARG_0 } Unk02037abc_Arg;

// Calls MIi_CpuClearFast with v, passed through a stack offset of its own.
static inline void func_02037abc_inline(u32 v, void *p, u32 n) {
    volatile u32 w = v;
    MIi_CpuClearFast(w, p, n);
}

// Sets the low two bits of the halfword register r and its bit 6 from the first two halfwords of q.
static inline void func_02037abc_inline2(vu16 *r, Bg01Cnt *q) {
    *r = (*r & ~3) | q->mBgCntLow2;
    if (q->mBgCntBit6 != 0) {
        *r |= 0x40;
    } else {
        *r &= ~0x40;
    }
}

// Sets bits 4, 20 and 21 of the word register r.
static inline void func_02037abc_inline3(vu32 *r, Unk02037abc_Arg v) {
    *r = (*r & 0xffcfffef) | v;
}

// Sets bits 5, 6 and 22 of the word at 0x04000000.
static inline void func_02037abc_inline4(Unk02037abc_Arg v) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffbfff9f) | v;
}

// Sets bits 5 and 6 of the word at 0x04001000.
static inline void func_02037abc_inline5(Unk02037abc_Arg v) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x60) | v;
}

// Keeps bits 0, 1 and 6 of the halfword register r and sets the rest from five values.
static inline void func_02037abc_inline6(vu16 *r, Unk02037abc_Arg b, Unk02037abc_Arg c, Unk02037abc_Arg d,
                                         Unk02037abc_Arg e, Unk02037abc_Arg f) {
    *r = (*r & 0x43) | (b << 14) | (c << 7) | (d << 8) | (e << 2) | (f << 13);
}

void InitDisplayFromSettings(void *a) {
    DisplaySettings *p;
    Bg01Cnt *q;
    u16 v;

    p = a;
    gDisplaySettings = p;
    func_02039bd4();
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
        func_02039b94(gDisplaySettings->mBankForARM7);
    }
    if (gDisplaySettings->mBankForLCDC != 0) {
        GX_SetBankForLCDC(gDisplaySettings->mBankForLCDC);
    }
    data_02175614.mUnk_00;
    GX_SetGraphicsMode(p->mDispMode, p->mMainBgMode, p->mBg0As);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (p->mMainDisplayMask << 8);
    GXS_SetGraphicsMode(p->mSubBgMode);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (p->mSubDisplayMask << 8);
    if (p->mBg0As == 1) {
        G3X_Init();
        G3X_InitTable();
        G3X_InitMtxStack();
        reg_G3X_DISP3DCNT &= 0xffffcffd;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 4;
        reg_G3X_ALPHA_TEST_REF = 0;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G2_BLDCNT = 0;
        reg_G3_SWAP_BUFFERS = (p->mG3xParams->mSwapBit1 << 1) | p->mG3xParams->mSwapBit0;
        v = p->mG3xParams->mClearColor;
        G3X_SetClearColor((u16) (v & 0x7fff), (u8) ((v & 0x8000) >> 15), 0x7fff, 0x3f, 0);
    }
    if (p->mMainDisplayMask & 1) {
        q = &p->mMainBg0;
        func_02037abc_inline2(&reg_G2_BG0CNT, q);
        if (p->mBg0As == 1) {
            G2Bg0OfsWrite(0);
        } else {
            reg_G2_BG0OFS = 0;
            func_02037abc_inline6(&reg_G2_BG0CNT, (Unk02037abc_Arg) q->mBgCntVal14, (Unk02037abc_Arg) q->mBgCntVal7,
                                  (Unk02037abc_Arg) q->mBgCntVal8, (Unk02037abc_Arg) q->mBgCntVal2,
                                  (Unk02037abc_Arg) q->mBgCntVal13);
        }
    }
    if (p->mSubDisplayMask & 1) {
        reg_G2S_DB_BG0OFS = 0;
        q = &p->mSubBg0;
        func_02037abc_inline2(&reg_G2S_DB_BG0CNT, q);
        func_02037abc_inline6(&reg_G2S_DB_BG0CNT, (Unk02037abc_Arg) q->mBgCntVal14, (Unk02037abc_Arg) q->mBgCntVal7,
                              (Unk02037abc_Arg) q->mBgCntVal8, (Unk02037abc_Arg) q->mBgCntVal2,
                              (Unk02037abc_Arg) q->mBgCntVal13);
    }
    if (p->mMainDisplayMask & 2) {
        reg_G2_BG1OFS = 0;
        q = &p->mMainBg1;
        func_02037abc_inline2(&reg_G2_BG1CNT, q);
        func_02037abc_inline6(&reg_G2_BG1CNT, (Unk02037abc_Arg) q->mBgCntVal14, (Unk02037abc_Arg) q->mBgCntVal7,
                              (Unk02037abc_Arg) q->mBgCntVal8, (Unk02037abc_Arg) q->mBgCntVal2,
                              (Unk02037abc_Arg) q->mBgCntVal13);
    }
    if (p->mSubDisplayMask & 2) {
        reg_G2S_DB_BG1OFS = 0;
        q = &p->mSubBg1;
        func_02037abc_inline2(&reg_G2S_DB_BG1CNT, q);
        func_02037abc_inline6(&reg_G2S_DB_BG1CNT, (Unk02037abc_Arg) q->mBgCntVal14, (Unk02037abc_Arg) q->mBgCntVal7,
                              (Unk02037abc_Arg) q->mBgCntVal8, (Unk02037abc_Arg) q->mBgCntVal2,
                              (Unk02037abc_Arg) q->mBgCntVal13);
    }
    if (p->mMainDisplayMask & 4) {
        ApplyBg2Cnt(&p->mMainBg2, 1);
    }
    if (p->mSubDisplayMask & 4) {
        ApplyBg2Cnt(&p->mSubBg2, 0);
    }
    if (p->mMainDisplayMask & 8) {
        ApplyBg3Cnt(&p->mMainBg3, 1);
    }
    if (p->mSubDisplayMask & 8) {
        ApplyBg3Cnt(&p->mSubBg3, 0);
    }
    if (p->mMainDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GX_DISPCNT, (Unk02037abc_Arg) p->mUnk_68);
        func_02037abc_inline4((Unk02037abc_Arg) p->mUnk_6a);
    }
    if (p->mSubDisplayMask & 0x10) {
        func_02037abc_inline3(&reg_GXS_DB_DISPCNT, (Unk02037abc_Arg) p->mUnk_b0);
        func_02037abc_inline5((Unk02037abc_Arg) p->mUnk_b2);
    }
    reg_GX_POWCNT |= 0x8000;
}

void DisableAllBanksAndNullDisplaySettings(void) {
    DisableAllBanks();
    gDisplaySettings = NULL;
}

void PrepareDisplayFrame(void) {
    DisplaySettings *p;
    u64 t;
    p = gDisplaySettings;
    t = OS_GetTick();
    p->mFrameStartTick = t;
    if (p->mBg0As == 1) {
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
    u32 value1;
    value0 = (u32) &gDisplaySettings;
    value1 = *(const u32 *) ((value0) + (0));
    value0 = gDisplaySettings->mFrameFlags;
    value0 = (value0) & ~(1u);
    gDisplaySettings->mFrameFlags = value0;
    return value0;
}

static inline void func_02036d3c_inline(BrightnessFade *p, s16 a) {
    if (p->mState == 0 || (p->mState == 3 && p->mPositive == 1)) {
        return;
    }
    p->mPositive = 1;
    if (p->mState != 1) {
        p->mFadeFrames = 0;
    } else {
        p->mFadeFrames = (a * p->mBrightness) / 16;
    }
    p->mState = 3;
    p->mFadeFrameCount = a;
}

static inline void func_02036f10_inline(BrightnessFade *p, s16 a) {
    if (p->mState == 0 || (p->mState == 3 && p->mPositive == 0)) {
        return;
    }
    p->mPositive = 0;
    if (p->mState != 1) {
        p->mFadeFrames = 0;
    } else {
        p->mFadeFrames = (a * p->mBrightness) / 16;
    }
    p->mState = 3;
    p->mFadeFrameCount = a;
}

static inline void func_020370d4_inline(BrightnessFade *p, s16 a) {
    if (p->mState == 2 || p->mState == 1) {
        return;
    }
    p->mPositive = 0;
    if (p->mState == 2 || p->mState == 1) {
        return;
    }
    if (p->mState != 3) {
        p->mFadeFrames = 0;
    } else {
        p->mFadeFrames = (a * p->mBrightness) / 16;
    }
    p->mState = 1;
    p->mFadeFrameCount = a;
}

static inline void func_02037288_inline(BrightnessFade *p, s16 a) {
    if (p->mState == 2 || p->mState == 1) {
        return;
    }
    if (p->mState != 3) {
        p->mFadeFrames = 0;
    } else {
        p->mFadeFrames = (a * p->mBrightness) / 16;
    }
    p->mState = 1;
    p->mFadeFrameCount = a;
}

void FinishDisplayFrame(void) {
    DisplaySettings *p;
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    c = gMainBrightnessFade.mBrightness;
    d = gSubBrightnessFade.mBrightness;
    if (gFrameCallback != NULL) {
        gFrameCallback(1);
    }
    UpdateBrightnessFade(&gMainBrightnessFade);
    UpdateBrightnessFade(&gSubBrightnessFade);
    DC_StoreAll();
    p = gDisplaySettings;
    if (p->mBg0As == 1) {
        *(vu32 *) 0x4000540 = (p->mG3xParams->mSwapBit1 << 1) | p->mG3xParams->mSwapBit0;
    }
    if ((gDisplaySettings->mFrameFlags & 1) == 0) {
        gDisplaySettings->mFrameFlags |= 2;
    } else {
        gDisplaySettings->mFrameFlags &= ~2;
        gDisplaySettings->mFrameFlags &= ~1;
    }
    p = gDisplaySettings;
    t = OS_GetTick();
    p->mTimeBeforeWait = (t - p->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (c != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, gMainBrightnessFade.mBrightness);
    }
    if (d != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void func_02037658(s32 a) {
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    BOOL e;
    DisplaySettings *p;
    c = gMainBrightnessFade.mBrightness;
    d = gSubBrightnessFade.mBrightness;
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
        e = TRUE;
    } else {
        e = FALSE;
    }
    p = gDisplaySettings;
    if (p->mBg0As == 1 && e != FALSE) {
        *(vu32 *) 0x4000540 = (p->mG3xParams->mSwapBit1 << 1) | p->mG3xParams->mSwapBit0;
    }
    p = gDisplaySettings;
    t = OS_GetTick();
    p->mTimeBeforeWait = (t - p->mFrameStartTick) * 0xfa00 / 0x82ea;
    if (e != FALSE) {
        for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
            OS_WaitIrq(1, 1);
        }
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (c != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, gMainBrightnessFade.mBrightness);
    }
    if (d != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void FinishDisplayFrameSwapIf(s32 a) {
    DisplaySettings *p;
    u64 t;
    s16 c;
    s16 d;
    u16 i;
    c = gMainBrightnessFade.mBrightness;
    d = gSubBrightnessFade.mBrightness;
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
    p = gDisplaySettings;
    if (p->mBg0As == 1 && a != 0) {
        *(vu32 *) 0x4000540 = (p->mG3xParams->mSwapBit1 << 1) | p->mG3xParams->mSwapBit0;
    }
    p = gDisplaySettings;
    t = OS_GetTick();
    p->mTimeBeforeWait = (t - p->mFrameStartTick) * 0xfa00 / 0x82ea;
    for (i = 0; i < gDisplaySettings->mWaitIrqCount; i++) {
        OS_WaitIrq(1, 1);
    }
    gDisplaySettings->mFrameFlags |= 1;
    gDisplaySettings->mWaitEndTick = OS_GetTick();
    if (c != gMainBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400006c, gMainBrightnessFade.mBrightness);
    }
    if (d != gSubBrightnessFade.mBrightness) {
        GXx_SetMasterBrightness_((u16 *) 0x400106c, gSubBrightnessFade.mBrightness);
    }
    if (gFrameCallback != NULL) {
        gFrameCallback(2);
    }
}

void RecordFrameTimes(void) {
    u64 t;
    DisplaySettings *p;
    t = OS_GetTick();
    if (gFrameCallback != NULL) {
        gFrameCallback(3);
    }
    p = gDisplaySettings;
    p->mTimeSinceWaitEnd = (t - p->mWaitEndTick) * 0xfa00 / 0x82ea;
    p = gDisplaySettings;
    p->mTimeSinceFrameStart = (t - p->mFrameStartTick) * 0xfa00 / 0x82ea;
}

void StartFadeToClearOneScreen(s16 a, s32 b) {
    if (b != 0) {
        func_02037288_inline(&gMainBrightnessFade, a);
    } else {
        func_02037288_inline(&gSubBrightnessFade, a);
    }
}

void StartFadeToClear(s16 a) {
    func_02037288_inline(&gMainBrightnessFade, a);
    func_02037288_inline(&gSubBrightnessFade, a);
}

void StartFadeToClearNegativeOneScreen(s32 a, s32 b) {
    if (b != 0) {
        func_020370d4_inline(&gMainBrightnessFade, a);
    } else {
        func_020370d4_inline(&gSubBrightnessFade, a);
    }
}

void StartFadeToClearNegative(s16 a) {
    func_020370d4_inline(&gMainBrightnessFade, a);
    func_020370d4_inline(&gSubBrightnessFade, a);
}

void StartFadeToFadedNegativeOneScreen(s32 a, s32 b) {
    if (b != 0) {
        func_02036f10_inline(&gMainBrightnessFade, a);
    } else {
        func_02036f10_inline(&gSubBrightnessFade, a);
    }
}

void StartFadeToFadedNegative(s16 a) {
    func_02036f10_inline(&gMainBrightnessFade, a);
    func_02036f10_inline(&gSubBrightnessFade, a);
}

void StartFadeToFadedPositiveOneScreen(s16 a, s32 b) {
    if (b != 0) {
        func_02036d3c_inline(&gMainBrightnessFade, a);
    } else {
        func_02036d3c_inline(&gSubBrightnessFade, a);
    }
}

void StartFadeToFadedPositive(s16 a) {
    func_02036d3c_inline(&gMainBrightnessFade, a);
    func_02036d3c_inline(&gSubBrightnessFade, a);
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
    GXx_SetMasterBrightness_((u16 *) 0x400006c, gMainBrightnessFade.mBrightness);
    GXx_SetMasterBrightness_((u16 *) 0x400106c, gSubBrightnessFade.mBrightness);
}

u32 AreBrightnessFadesClear(void) {
    if (((*(u16 *) &gMainBrightnessFade) == 2) && ((*(u16 *) &gSubBrightnessFade) == 2)) {
        return 1;
    }
    return 0;
}
