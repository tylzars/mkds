#include "Main/Unknown/code_0212b1a8.h"

#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02024000.h"
#include "g2d_CharCanvas.h"
#include "code_0214a034.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02016468.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0212b5d8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_0214a2f4.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_0212b928.h"
#include "registers.h"

#pragma thumb on
void InitPaletteBlend(void *heap, Nclr *nclr, u32 paletteIndex) {
    s32 i;
    s32 v;
    gPaletteBlend = HeapAlloc(heap, 0x90);
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = FALSE;
    gPaletteBlend->mPaletteIndex = paletteIndex;
    gPaletteBlend->mFirstBlend = TRUE;
    MI_CpuCopy8(nclr->mData + paletteIndex * 0x10, gPaletteBlend->mUnk_0a, 0x20);
    for (i = 0; i < 4; i++) {
        v = gPaletteBlend->mUnk_14[i];
        gPaletteBlend->mBlendFrom[i].mUnk_00 = v & 0x1f;
        gPaletteBlend->mBlendFrom[i].mUnk_04 = (v & 0x3e0) >> 5;
        gPaletteBlend->mBlendFrom[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
    for (i = 0; i < 4; i++) {
        v = gPaletteBlend->mUnk_1c[i];
        gPaletteBlend->mBlendTo[i].mUnk_00 = v & 0x1f;
        gPaletteBlend->mBlendTo[i].mUnk_04 = (v & 0x3e0) >> 5;
        gPaletteBlend->mBlendTo[i].mUnk_08 = (v & 0x7c00) >> 10;
    }
}
#pragma thumb off

#pragma thumb on
void func_0212b91c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gPaletteBlend;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void BlendPaletteColors(s32 weight) {
    s32 i;
    PaletteBlend *p;
    for (i = 0; i < 4; i++) {
        p = gPaletteBlend;
        (&p->mUnk_0a[1])[i] =
            ((((0x1000 - weight) * p->mBlendFrom[i].mUnk_08 + weight * p->mBlendTo[i].mUnk_08) >> 12) << 10) |
            ((((0x1000 - weight) * p->mBlendFrom[i].mUnk_00 + weight * p->mBlendTo[i].mUnk_00) >> 12) |
             ((((0x1000 - weight) * p->mBlendFrom[i].mUnk_04 + weight * p->mBlendTo[i].mUnk_04) >> 12) << 5));
    }
    if (gPaletteBlend->mFirstBlend == FALSE) {
        CallQueueAppend(0x1e, gPaletteBlend->mPaletteIndex << 5, gPaletteBlend->mUnk_0a, 0x20);
    } else {
        gPaletteBlend->mFirstBlend = FALSE;
    }
}

void AdvancePaletteBlend(void) {
    s32 a;
    if (gPaletteBlend->mStopped == FALSE) {
        gPaletteBlend->mCycleFrames++;
        if (gPaletteBlend->mCycleFrames >= 0x5a) {
            gPaletteBlend->mCycleFrames = 0;
        }
    }
    a = gPaletteBlend->mCycleFrames;
    if (a < 0x1e) {
        BlendPaletteColors(((0x1e - a) << 12) / 0x1e);
    } else if (a < 0x3c) {
        BlendPaletteColors(0);
    } else {
        BlendPaletteColors(((a - 0x3c) << 12) / 0x1e);
    }
}

void ResetPaletteBlendCycle(void) {
    gPaletteBlend->mCycleFrames = 0;
}

void StopPaletteBlend(void) {
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = TRUE;
}

void StartPaletteBlend(void) {
    gPaletteBlend->mStopped = FALSE;
}
#pragma thumb off

void InitStaffRollText(void *heap) {
    s32 i;
    s32 v;
    Nclr *p;
    StaffRollText *d;
    TextCanvas *q;
    void *t;
    gStaffRollText = HeapAlloc(heap, 0x85c);
    gStaffRollText->mHeap = heap;
    gStaffRollText->mState = 0;
    gStaffRollText->mNextState = 0;
    CallQueueInit(HeapAlloc(heap, 0xa0), 0xa);
    gStaffRollText->mScrollYFixed = 0;
    gStaffRollText->mNextReadScrollY = 0;
    gStaffRollText->mScrollYRemaining = -1;
    gStaffRollText->mScrollYPerFrame = 0x70a;
    gStaffRollText->mUnk_01c = 1;
    gStaffRollText->mUnk_850 = 1;
    gStaffRollText->mUnk_854 = 0x240;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x100;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x1000;
    MemFillWordsByBlock_inline((void *) G2S_GetBG0CharPtr(), 0x8000);
    for (i = 0; i < 0x400; i++) {
        ((u16 *) G2S_GetBG0ScrPtr())[i] = i | 0xf000;
    }
    LoadNclrData(&p, FindSceneFile(gEndingStaffRollB00NclrName));
    CallQueueAppend(0x1f, 0x1e0, p->mData + 0xf0, 0x20);
    NNS_G2dCharCanvasInitForBG(gStaffRollText->mUnk_020, gStaffRollText->mUnk_050, 0x20, 2, 4);
    v = gStaffRollText->mUnk_01c;
    t = func_020b403c(2);
    d = gStaffRollText;
    q = &d->mUnk_040;
    d->mUnk_040.mCharCanvas = d->mUnk_020;
    q->mFont = t;
    q->mCharSpacing = v;
    q->mLineSpacing = 0;
    MI_CpuFill8(gStaffRollText->mUnk_050, 0, 0x800);
    gStaffRollText->mTextPosition = GetBmgEntry(FindSceneFile(gStaffRollBmgName), 0);
}

u32 func_0212b5d8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gStaffRollText;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void AdvanceStaffRollTextState1(void) {
    s32 e;
    s32 c;
    s32 i;
    u8 *r;
    StaffRollText *p;
    u16 buf[100];
    s32 v;
    BOOL n;
    s32 f;
    s32 x;
    u32 w;
    s32 a;
    Unk0217d40c_18 *q;
    gStaffRollText->mScrollYFixed += gStaffRollText->mScrollYPerFrame;
    a = (gStaffRollText->mScrollYFixed >> 12) - 8;
    if (a < 0) {
        a += 0x100;
    }
    a = a % 256;
    MemFillWordsByBlock_inline((void *) (G2S_GetBG0CharPtr() + ((a >> 3) << 10)), 0x400);
    p = gStaffRollText;
    if (p->mScrollYRemaining > 0) {
        p->mScrollYRemaining -= p->mScrollYPerFrame;
        if (gStaffRollText->mScrollYRemaining <= 0) {
            gStaffRollText->mNextState = 2;
        }
        return;
    }
    if (p->mScrollYFixed <= p->mNextReadScrollY) {
        return;
    }
    i = 0;
    n = FALSE;
    MI_CpuFill8(buf, 0, 0xc8);
    do {
        p = gStaffRollText;
        r = p->mTextPosition;
        q = (Unk0217d40c_18 *) r;
        w = q->mUnk_00;
        if (w == 0x1a) {
            c = q->mUnk_03;
            e = q->mUnk_02;
            f = q->mUnk_04;
            if (c == 1) {
                x = 0;
                if (f != 0x63) {
                    x = q->mUnk_06;
                }
                switch (f) {
                    case 0:
                        p->mUnk_854 = 0x40;
                        switch (x) {
                            case 0:
                                gStaffRollText->mUnk_854 |= 0x200;
                                break;
                            case 1:
                                gStaffRollText->mUnk_854 |= 0x400;
                                break;
                            case 2:
                                gStaffRollText->mUnk_854 |= 0x800;
                                break;
                        }
                        break;
                    case 1:
                        n = TRUE;
                        p->mNextReadScrollY += x << 16;
                        break;
                    case 2:
                        p->mUnk_850 = x * 2 + 1;
                        break;
                    case 3:
                        p->mUnk_01c = x;
                        break;
                    case 4:
                        p->mScrollYPerFrame = (x << 12) / 100;
                        break;
                    case 5:
                        break;
                    case 0x63:
                        n = TRUE;
                        p->mScrollYRemaining = 0xd0000;
                        break;
                }
            }
            gStaffRollText->mTextPosition += e;
        } else if (w == 0xa) {
            n = TRUE;
            p->mNextReadScrollY += 0x10000;
            gStaffRollText->mTextPosition += 2;
        } else if (w == 0) {
            p->mTextPosition = r + 2;
        } else {
            buf[i] = w;
            i++;
            p->mTextPosition += 2;
        }
    } while (n == FALSE);
    MI_CpuFill8(gStaffRollText->mUnk_050, 0, 0x800);
    v = gStaffRollText->mUnk_850;
    c = 0;
    if (v == 3) {
        c = 2;
    }
    NNSi_G2dTextCanvasDrawTextRect(&gStaffRollText->mUnk_040, 8, c, 0xf0, 0x10, v, gStaffRollText->mUnk_854, buf);
    p = gStaffRollText;
    a = (((p->mScrollYFixed >> 12) % 256) + 0xc0) >> 3;
    a = a << 3;
    if (a >= 0x100) {
        a -= 0x100;
    }
    if (a + 0x10 > 0x100) {
        CallQueueAppend(0x14, a << 7, p->mUnk_050, (0x100 - a) << 7);
        CallQueueAppend(0x14, 0, &gStaffRollText->mUnk_050[a << 7], (a - 0xf0) << 7);
    } else {
        CallQueueAppend(0x14, a << 7, p->mUnk_050, 0x800);
    }
}

void AdvanceStaffRollText(void) {
    gStaffRollText->mState = gStaffRollText->mNextState;
    switch (gStaffRollText->mState) {
        case 0:
            break;
        case 1:
            AdvanceStaffRollTextState1();
            break;
        case 2:
            break;
    }
}

void func_0212b1c0(void) {
    reg_G2S_DB_BG0OFS = (((gStaffRollText->mScrollYFixed >> 12) % 256) << 16) & 0x1ff0000;
    CallQueueDrain();
}

u32 StartStaffRollText(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gStaffRollText;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}
