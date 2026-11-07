#include "Main/Unknown/code_02125ebc.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02124f4c.h"

#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212630c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_02126ea8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02126f78.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "code_02023374.h"
#include "code_0214a390.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214a054.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0214d018.h"

#pragma thumb on

void ClearTxtSystemCanvasInUse(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        gTxtSystem->mCanvasInUse[i] = 0;
    }
}

static inline void func_021274ec_inline(Unk0217d3f0_2178 *e, Unk0217d3f0_2098 *o, u32 v) {
    e->mUnk_00 = o;
    e->mUnk_04 = v;
    e->mUnk_08 = 1;
    e->mUnk_0c = 1;
}

s32 InitTxtSystem(void *b, Unk021274ec *c) {
    s32 a;
    s32 i;
    Unk0217d3f0_2098 *o;

    a = c->mUnk_10;
    gTxtSystem = HeapAlloc(b, 0x2278);
    if (c->mUnk_04 != 0) {
        gTxtSystem->mUnk_44 = 1;
    }
    if (c->mUnk_08 != 0) {
        gTxtSystem->mUnk_48 = 1;
    }
    if (c->mUnk_0c != 0) {
        gTxtSystem->mUnk_4c = 1;
    }
    gTxtSystem->mEnabled = 1;
    InitTxtSystemDisplay();
    a = LoadTxtSystem(a);
    for (i = 0; i < 7; i++) {
        if (!((i == 1 && gTxtSystem->mUnk_44 == 0) || (i == 2 && gTxtSystem->mUnk_48 == 0) ||
              (i == 3 && gTxtSystem->mUnk_4c == 0))) {
            gTxtSystem->mCharBuffers[i] =
                HeapAlloc(b, (gTxtSystemCanvasSizes[i][0] * gTxtSystemCanvasSizes[i][1]) << 5);
            NNS_G2dCharCanvasInitForBG(&gTxtSystem->mCharCanvases[i], gTxtSystem->mCharBuffers[i],
                                       gTxtSystemCanvasSizes[i][0], gTxtSystemCanvasSizes[i][1], 4);
            o = &gTxtSystem->mCharCanvases[i];
            o->mUnk_18(o, 0);
            func_021274ec_inline(&gTxtSystem->mUnk_2178[i], &gTxtSystem->mCharCanvases[i], c->mUnk_00);
        }
    }
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mState = 0;
    gTxtSystem->mNextState = 0;
    gTxtSystem->mPrevState = 0;
    gTxtSystem->mStateFrames = 0;
    gTxtSystem->mUnk_10 = 0;
    gTxtSystem->mAnimFrameIndex = 0;
    gTxtSystem->mAnimVisible[0] = 0;
    gTxtSystem->mAnimVisible[1] = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesEnabled[0] = 0;
    gTxtSystem->mBlendPlanesEnabled[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = 0;
    gTxtSystem->mBlendPlanesRequested[1] = 0;
    gTxtSystem->mOpenRequested = 0;
    gTxtSystem->mCloseRequested = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mInputAccepted = 0;
    gTxtSystem->mInputSoundId = 5;
    gTxtSystem->mSecondInputSoundId = 0x10;
    gTxtSystem->mOpenSoundId = 0x23;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBgOffset[i] = -192;
        gTxtSystem->mBgOffsetAtOpen[i] = 0;
        gTxtSystem->mBgOffsetRequested[i] = 0;
    }
    gTxtSystem->mBlendPlanes[0] = 0x19;
    gTxtSystem->mBlendPlanes[1] = 0x1a;
    gTxtSystem->mBrightness = 0;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBlendEv1[i] = 6;
        gTxtSystem->mBlendEv2[i] = 10;
    }
    gTxtSystem->mMode = 0;
    return a;
}
#pragma thumb off

#pragma thumb on
void ClearTxtSystemPointer(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gTxtSystem;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void InitTxtSystemDisplay(void) {
    u32 a;
    u32 b;

    a = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((a | 4) << 8);
    reg_G2_BG2CNT &= ~3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    b = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((b | 1) << 8);
    reg_G2S_DB_BG0CNT &= ~3;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8b00;
}

static inline void func_0212717c_inline(void *dst, u16 value) {
    vu16 v = value;

    MIi_CpuClear16(v, dst, 0x1000);
}

s32 LoadTxtSystem(s32 d) {
    Ncgr *a;
    Ncgr *b;
    Nclr *c;

    if (*(vu16 *) 0x27ffc40 == 2) {
        LocateNcgr(&a, FindSceneFile(data_0216e708));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindSceneFile(data_0216e720));
        LocateNclr(&c, FindSceneFile(data_0216e738));
    } else {
        LocateNcgr(&a, FindFileInLoadedArchives(data_0216e750));
        LocateNcgr(&b, FindFileInLoadedArchives(data_0216e768));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindFileInLoadedArchives(data_0216e780));
        LocateNscr(&gTxtSystem->mBgNscrs[1], FindFileInLoadedArchives(data_0216e798));
        LocateNscr(&gTxtSystem->mBgNscrs[2], FindFileInLoadedArchives(data_0216e7b0));
        LocateNscr(&gTxtSystem->mBgNscrs[3], FindFileInLoadedArchives(data_0216e7c8));
        LocateNscr(&gTxtSystem->mBgNscrs[4], FindFileInLoadedArchives(data_0216e7e0));
        LocateNscr(&gTxtSystem->mBgNscrs[5], FindFileInLoadedArchives(data_0216e7f8));
        LocateNscr(&gTxtSystem->mBgNscrs[6], FindFileInLoadedArchives(data_0216e810));
        LocateNclr(&c, FindFileInLoadedArchives(data_0216e828));
    }
    gTxtSystem->mCanvasFileCharIndex[0] = 0;
    DC_FlushRange(a->mData, a->mDataSize);
    GX_LoadBG2Char(a->mData, 0, a->mDataSize);
    if (gTxtSystem->mUnk_48 != 0) {
        d = d - a->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[2] = d >> 5;
        DC_FlushRange(a->mData, a->mDataSize);
        GXS_LoadBG0Char(a->mData, d, a->mDataSize);
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        if (gTxtSystem->mUnk_44 != 0) {
            gTxtSystem->mCanvasFileCharIndex[1] = 0;
        }
        gTxtSystem->mB01CharIndex[0] = a->mDataSize >> 5;
        DC_FlushRange(b->mData, b->mDataSize);
        GX_LoadBG2Char(b->mData, gTxtSystem->mB01CharIndex[0] << 5, b->mDataSize);
        if (gTxtSystem->mUnk_4c != 0) {
            gTxtSystem->mCanvasFileCharIndex[3] = gTxtSystem->mCanvasFileCharIndex[2];
        }
        d = d - b->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[4] = d >> 5;
        gTxtSystem->mCanvasFileCharIndex[5] = d >> 5;
        gTxtSystem->mCanvasFileCharIndex[6] = d >> 5;
        gTxtSystem->mB01CharIndex[1] = d >> 5;
        DC_FlushRange(b->mData, b->mDataSize);
        GXS_LoadBG0Char(b->mData, d, b->mDataSize);
    }
    DC_FlushRange(c->mData, 0x1c0);
    GX_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    GXS_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    gTxtSystem->mUnk_2244 = c->mData[0xee];
    gTxtSystem->mUnk_2246 = c->mData[0xdf];
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    func_0212717c_inline((void *) G2S_GetBG0ScrPtr(), gTxtSystem->mCanvasFileCharIndex[4]);
    return d;
}

void RefreshTxtSystemAnim(void) {
    s32 r;
    s32 i;
    s32 c;
    s32 n;
    u16 *d;

    n = gTxtSystem->mAnimFrameIndex + 4;
    for (i = 0; i < 2; i++) {
        if (gTxtSystem->mAnimVisible[i] != 0) {
            d = gTxtSystem->mMainScreenBuffer;
            if (i == 1) {
                d = gTxtSystem->mSubScreenBuffer;
            }
            for (r = gTxtSystemNscrRects[n].mUnk_02; r <= gTxtSystemNscrRects[n].mUnk_03; r++) {
                for (c = gTxtSystemNscrRects[n].mUnk_00; c <= gTxtSystemNscrRects[n].mUnk_01; c++) {
                    *(d + r * 32 + c) =
                        gTxtSystem->mB01CharIndex[i] + *((u16 *) gTxtSystem->mBgNscrs[n]->mData + r * 32 + c);
                }
            }
        }
    }
}

void RefreshTxtSystemScreenBuffers(u32 *b) {
    u8 a[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 i;
    s32 r;
    s32 c;
    s32 k;
    u16 *d;

    MemFillWordsByBlock_inline(gTxtSystem->mMainScreenBuffer, 0x1000);
    func_0212717c_inline(&gTxtSystem->mSubScreenBuffer, gTxtSystem->mCanvasFileCharIndex[4]);
    for (i = 0; i < 9; i++) {
        if (*b != 0) {
            if ((u32) (i - 7) <= 1) {
                RefreshTxtSystemAnim();
            } else if (i != 6) {
                k = a[i];
                d = gTxtSystem->mSubScreenBuffer;
                if ((u32) i <= 1) {
                    d = gTxtSystem->mMainScreenBuffer;
                }
                for (r = gTxtSystemNscrRects[k].mUnk_02; r <= gTxtSystemNscrRects[k].mUnk_03; r++) {
                    for (c = gTxtSystemNscrRects[k].mUnk_00; c <= gTxtSystemNscrRects[k].mUnk_01; c++) {
                        *(d + r * 32 + c) = gTxtSystem->mCanvasFileCharIndex[i] +
                                            *((u16 *) gTxtSystem->mBgNscrs[k]->mData + r * 32 + c);
                    }
                }
            }
        }
        b++;
    }
}
#pragma thumb off

#pragma thumb on

void func_02126ef8(void) {
    TxtSystem *v1;
    v1 = gTxtSystem;
    if (0 < v1->mExtraCanvasCount) {
        CallQueueAppend(0x1f, ((0xee - v1->mSelectedIndex) * 2), &v1->mUnk_2246, 2);
        CallQueueAppend(0x1f, (0xfe - gTxtSystem->mSelectedIndex) * 2, &gTxtSystem->mUnk_2246, 2);
        v1 = gTxtSystem;
        if (v1->mExtraCanvasCount == 2) {
            CallQueueAppend(0x1f, ((v1->mSelectedIndex + 0xed) * 2), &v1->mUnk_2244, 2);
            CallQueueAppend(0x1f, (gTxtSystem->mSelectedIndex + 0xfd) * 2, &gTxtSystem->mUnk_2244, 2);
        }
    }
}

void func_02126ea8(void) {
    int v2;
    if (0 < gTxtSystem->mExtraCanvasCount) {
        v2 = 0;
        do {
            CallQueueAppend(0x1f, ((v2 + 0xed) * 2), &gTxtSystem->mUnk_2244, 2);
            CallQueueAppend(0x1f, ((v2 + 0xfd) * 2), &gTxtSystem->mUnk_2244, 2);
            v2 = v2 + 1;
        } while (v2 < 2);
    }
}

#pragma thumb off

#pragma thumb on

// State 0: serves an open request by building the screens and queueing them.
void AdvanceTxtSystemState0(void) {
    u32 a[9];
    s32 i;
    s32 n;
    s32 m;

    if (gTxtSystem->mOpenRequested != 0) {
        for (i = 0; i < 9; i++) {
            if (i <= 6) {
                if (gTxtSystem->mCanvasInUse[i] != 0) {
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            } else {
                if ((&gTxtSystem->mNextState)[i] != 0) {
                    (&gTxtSystem->mNextState)[i] = 0;
                    *(&gTxtSystem->mState + i - 1) = 1;
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            }
        }
        RefreshTxtSystemScreenBuffers(a);
        CallQueueAppend(10, 0, gTxtSystem->mMainScreenBuffer, 0x1000);
        CallQueueAppend(0x18, 0, &gTxtSystem->mSubScreenBuffer, 0x1000);
        gTxtSystem->mNextState = 1;
        gTxtSystem->mStateFrames = 0;
        for (i = 0; i < 2; i++) {
            gTxtSystem->mBgOffsetAtOpen[i] = gTxtSystem->mBgOffsetRequested[i];
        }
        for (i = 0; i < 2; i++) {
            gTxtSystem->mBlendPlanesEnabled[i] = gTxtSystem->mBlendPlanesRequested[i];
        }
        for (i = 0; i < 7; i++) {
            if (gTxtSystem->mCanvasInUse[i] != 0) {
                n = (gTxtSystemCanvasSizes[i][0] * gTxtSystemCanvasSizes[i][1]) << 5;
                m = 0x14;
                if ((u32) i <= 1) {
                    m = 6;
                }
                CallQueueAppend(m, (gTxtSystem->mCanvasFileCharIndex[i] + gTxtSystemCanvasCharOffsets[i]) << 5,
                                gTxtSystem->mCharBuffers[i], n);
            }
        }
        if (gTxtSystem->mExtraCanvasCount > 0) {
            func_02126ef8();
        }
        if (gTxtSystem->mAnimVisible[0] == 0 && gTxtSystem->mAnimVisible[1] == 0) {
            if (gTxtSystem->mOpenSoundId != -1) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) gTxtSystem->mOpenSoundId);
            }
        }
    }
}

// State 1: slides the box in over 15 steps.
void AdvanceTxtSystemState1(void) {
    TxtSystem *p;
    s32 i;

    gTxtSystem->mStateFrames++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBgOffset[i] = InterpolateS16(1, gTxtSystemBgOffsets[gTxtSystem->mOpenFromIndex],
                                                  -gTxtSystem->mBgOffsetAtOpen[i], gTxtSystem->mStateFrames, 0xf);
    }
    p = gTxtSystem;
    p->mBrightness = (p->mStateFrames * -10) / 15;
    if (gTxtSystem->mStateFrames >= 15) {
        if (gTxtSystem->mCloseRequested == 0) {
            gTxtSystem->mOpenRequested = 0;
        }
        gTxtSystem->mNextState = 2;
        gTxtSystem->mStateFrames = 0;
    }
}

static inline BOOL func_02126a00_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02126a00_inline2(u32 v) {
    BOOL r = FALSE;
    BOOL s = FALSE;

    if (data_02175674[v].mUnk_00 == 0 && data_02175680[v].mUnk_00 < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[v].mUnk_00 == 0 && data_02175674[v].mUnk_00 != 0) {
        r = TRUE;
    }
    return r;
}

// State 2: open; answers a close request, or a touch or key press when the box has buttons.
void AdvanceTxtSystemState2(void) {
    s32 m;
    s32 t;
    u16 y;
    s32 hit;
    u16 x;
    TxtSystem *p;
    u32 v;
    u16 w;

    switch (gTxtSystem->mMode) {
        case 0:
            v = 8;
            break;
        case 1:
            v = func_020435bc();
            break;
    }
    x = data_02175670[v].mUnk_00;
    p = gTxtSystem;
    t = p->mBgOffset[1] + data_02175672[v].mUnk_00;
    if (t < 0) {
        t = 0xff;
    }
    if (t > 0xff) {
        t = 0xff;
    }
    y = t;
    if (p->mCloseRequested != 0) {
        p->mNextState = 4;
        return;
    }
    m = p->mExtraCanvasCount;
    if (m <= 0) {
        return;
    }
    hit = -1;
    if (m == 2) {
        if (func_02126a00_inline2(v) != 0) {
            if (func_02126a00_inline(x, y, gTxtSystemHitRects[5].mUnk_00, gTxtSystemHitRects[5].mUnk_01,
                                     gTxtSystemHitRects[5].mUnk_02, gTxtSystemHitRects[5].mUnk_03) != FALSE) {
                hit = 0;
            }
            if (func_02126a00_inline(x, y, gTxtSystemHitRects[6].mUnk_00, gTxtSystemHitRects[6].mUnk_01,
                                     gTxtSystemHitRects[6].mUnk_02, gTxtSystemHitRects[6].mUnk_03) != FALSE) {
                hit = 1;
            }
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & PAD_KEY_A) == 0) {
        if (func_02126a00_inline2(v) == 0 || m != 1 ||
            func_02126a00_inline(x, y, gTxtSystemHitRects[4].mUnk_00, gTxtSystemHitRects[4].mUnk_01,
                                 gTxtSystemHitRects[4].mUnk_02, gTxtSystemHitRects[4].mUnk_03) == FALSE) {
            if (hit == -1) {
                goto L;
            }
        }
    }
    if (m == 1) {
        func_02126ea8();
    } else {
        if (hit == -1 || p->mSelectedIndex == hit) {
            func_02126ea8();
        } else {
            p->mSelectedIndex = hit;
            func_02126ef8();
        }
    }
    gTxtSystem->mNextState = 3;
    if (gTxtSystem->mExtraCanvasCount == 2 && gTxtSystem->mSelectedIndex == 1) {
        if (gTxtSystem->mSecondInputSoundId != -1) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) gTxtSystem->mSecondInputSoundId);
        }
    } else {
        if (gTxtSystem->mInputSoundId != -1) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) gTxtSystem->mInputSoundId);
        }
    }
    gTxtSystem->mInputAccepted = 1;
    return;
L:
    if (m == 2) {
        if ((u16) (w & PAD_KEY_LEFT) != 0 && p->mSelectedIndex == 1) {
            p->mSelectedIndex = 0;
            func_02126ef8();
            StartSoundOncePerFrame(0);
            return;
        }
        if ((u16) (w & 0x10) != 0 && p->mSelectedIndex == 0) {
            p->mSelectedIndex = 1;
            func_02126ef8();
            StartSoundOncePerFrame(0);
        }
    }
}

// State 3: ten steps after an accepted input, then sets mDone.
void AdvanceTxtSystemState3(void) {
    gTxtSystem->mStateFrames++;
    gTxtSystem->mInputAccepted = 0;
    if (gTxtSystem->mStateFrames >= 10) {
        gTxtSystem->mDone = 1;
        gTxtSystem->mNextState = 2;
        gTxtSystem->mStateFrames = 0;
    } else if (gTxtSystem->mStateFrames >= 5) {
        func_02126ef8();
    }
}

// State 4: slides the box out over 15 steps.
void AdvanceTxtSystemState4(void) {
    TxtSystem *p;
    s32 i;

    gTxtSystem->mStateFrames++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBgOffset[i] =
            InterpolateS16(1, -gTxtSystem->mBgOffsetAtOpen[i], gTxtSystemBgOffsets[gTxtSystem->mCloseToIndex],
                           gTxtSystem->mStateFrames, 0xf);
    }
    p = gTxtSystem;
    p->mBrightness = -10 - (p->mStateFrames * -10) / 15;
    if (gTxtSystem->mStateFrames >= 15) {
        for (i = 0; i < 2; i++) {
            gTxtSystem->mBgOffset[i] = -192;
        }
        gTxtSystem->mNextState = 0;
        func_02126ea8();
        gTxtSystem->mStateFrames = 0;
        gTxtSystem->mCloseRequested = 0;
        gTxtSystem->mDone = 0;
        gTxtSystem->mAnimVisible[0] = 0;
        gTxtSystem->mAnimVisible[1] = 0;
    }
}

void AdvanceTxtSystem(void) {
    if (gTxtSystem->mEnabled != 0) {
        gTxtSystem->mPrevState = gTxtSystem->mState;
        gTxtSystem->mState = gTxtSystem->mNextState;
        switch (gTxtSystem->mState) {
            case 0:
                AdvanceTxtSystemState0();
                break;
            case 1:
                AdvanceTxtSystemState1();
                break;
            case 2:
                AdvanceTxtSystemState2();
                break;
            case 3:
                AdvanceTxtSystemState3();
                break;
            case 4:
                AdvanceTxtSystemState4();
                break;
        }
        if (gTxtSystem->mAnimVisible[0] != 0 || gTxtSystem->mAnimVisible[1] != 0) {
            gTxtSystem->mUnk_10++;
            if (gTxtSystem->mUnk_10 >= 4) {
                gTxtSystem->mUnk_10 = 0;
                gTxtSystem->mAnimFrameIndex++;
                if (gTxtSystem->mAnimFrameIndex >= 3) {
                    gTxtSystem->mAnimFrameIndex = 0;
                }
                RefreshTxtSystemAnim();
                CallQueueAppend(10, 0, gTxtSystem->mMainScreenBuffer, 0x1000);
                CallQueueAppend(0x18, 0, &gTxtSystem->mSubScreenBuffer, 0x1000);
            }
        }
    }
}

void WriteTxtSystemRegisters(void) {
    if (gTxtSystem->mEnabled != 0) {
        reg_G2_BG2OFS = (gTxtSystem->mBgOffset[0] << 16) & 0x1ff0000;
        reg_G2S_DB_BG0OFS = (gTxtSystem->mBgOffset[1] << 16) & 0x1ff0000;
        if (gTxtSystem->mBlendPlanesEnabled[0] != 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, gTxtSystem->mBlendPlanes[0], 0x1f, gTxtSystem->mBlendEv1[0],
                                       gTxtSystem->mBlendEv2[0], gTxtSystem->mBrightness);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, 0, 0x1f, gTxtSystem->mBlendEv1[0], gTxtSystem->mBlendEv2[0],
                                       gTxtSystem->mBrightness);
        }
        if (gTxtSystem->mBlendPlanesEnabled[1] != 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, gTxtSystem->mBlendPlanes[1], 0x1f, gTxtSystem->mBlendEv1[1],
                                       gTxtSystem->mBlendEv2[1], gTxtSystem->mBrightness);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0, 0x1f, gTxtSystem->mBlendEv1[1], gTxtSystem->mBlendEv2[1],
                                       gTxtSystem->mBrightness);
        }
    }
}

void RequestTxtSystemOpen(void) {
    if ((gTxtSystem->mState == 0 && gTxtSystem->mOpenRequested != 0) || gTxtSystem->mState == 1 ||
        gTxtSystem->mState == 2) {
        gTxtSystem->mCloseRequested = 1;
    } else {
        gTxtSystem->mCloseRequested = 0;
    }
    gTxtSystem->mOpenRequested = 1;
}
#pragma thumb off

#pragma thumb on

void func_021266e4(void *a) {
    func_02126638(a, 1, 1, 1, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void func_02126638(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[0];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, a);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = f;
    gTxtSystem->mAnimRequested[1] = g;
    gTxtSystem->mBlendPlanesRequested[0] = b;
    gTxtSystem->mBlendPlanesRequested[1] = c;
    gTxtSystem->mOpenFromIndex = d;
    gTxtSystem->mCloseToIndex = e;
}

void func_0212658c(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[1];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[1], 0, 0, gTxtSystemCanvasSizes[1][0] << 3, gTxtSystemCanvasSizes[1][1] << 3,
                  1, 0x480, 1, a);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[1] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = f;
    gTxtSystem->mAnimRequested[1] = g;
    gTxtSystem->mBlendPlanesRequested[0] = b;
    gTxtSystem->mBlendPlanesRequested[1] = c;
    gTxtSystem->mOpenFromIndex = d;
    gTxtSystem->mCloseToIndex = e;
}
#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButton(void *p0, void *p1) {
    u32 v7 = ((0x1u) + (0x0u));
    SetupTxtSystemMainTextButtonEx(p0, p1, 0x1u, v7, 0x1u, 0x0u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButtonEx(void *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[0];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mCharCanvases[4];
    p->mUnk_18(p, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3, gTxtSystemCanvasSizes[4][1] << 3,
                  2, 0x480, 1, b);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = g;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = c;
    gTxtSystem->mBlendPlanesRequested[1] = d;
    gTxtSystem->mOpenFromIndex = e;
    gTxtSystem->mCloseToIndex = f;
}

void SetupTxtSystemMainTextTwoButtons(void *a, void *b, void *c, s32 d) {
    SetupTxtSystemMainTextTwoButtonsEx(a, b, c, d, 1, 1, 1, 0, 0);
}

void SetupTxtSystemMainTextTwoButtonsEx(void *a, void *b, void *c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[0];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mCharCanvases[5];
    p->mUnk_18(p, 0xe);
    p = &gTxtSystem->mCharCanvases[6];
    p->mUnk_18(p, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3, gTxtSystemCanvasSizes[5][1] << 3,
                  2, 0x480, 1, b);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3, gTxtSystemCanvasSizes[6][1] << 3,
                  2, 0x480, 1, c);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = d;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = i;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = e;
    gTxtSystem->mBlendPlanesRequested[1] = f;
    gTxtSystem->mOpenFromIndex = g;
    gTxtSystem->mCloseToIndex = h;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubText(void *a) {
    SetupTxtSystemSubTextEx(a, 1, 1, 1, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextEx(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[2];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, a);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = f;
    gTxtSystem->mBlendPlanesRequested[0] = b;
    gTxtSystem->mBlendPlanesRequested[1] = c;
    gTxtSystem->mOpenFromIndex = d;
    gTxtSystem->mCloseToIndex = e;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButton(void *p0, void *p1) {
    u32 v6 = ((0x1u) + (0x0u));
    SetupTxtSystemSubTextButtonEx(p0, p1, 0x1u, v6, 0x1u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButtonEx(void *a, void *b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[2];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mCharCanvases[4];
    p->mUnk_18(p, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3, gTxtSystemCanvasSizes[4][1] << 3,
                  2, 0x480, 1, b);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = c;
    gTxtSystem->mBlendPlanesRequested[1] = d;
    gTxtSystem->mOpenFromIndex = e;
    gTxtSystem->mCloseToIndex = f;
}

void SetupTxtSystemSubTextTwoButtons(void *a, void *b, void *c, s32 d) {
    SetupTxtSystemSubTextTwoButtonsEx(a, b, c, d, 1, 1, 1, 0);
}

void SetupTxtSystemSubTextTwoButtonsEx(void *a, void *b, void *c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mCharCanvases[2];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mCharCanvases[5];
    p->mUnk_18(p, 0xe);
    p = &gTxtSystem->mCharCanvases[6];
    p->mUnk_18(p, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3, gTxtSystemCanvasSizes[5][1] << 3,
                  2, 0x480, 1, b);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3, gTxtSystemCanvasSizes[6][1] << 3,
                  2, 0x480, 1, c);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = d;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = e;
    gTxtSystem->mBlendPlanesRequested[1] = f;
    gTxtSystem->mOpenFromIndex = g;
    gTxtSystem->mCloseToIndex = h;
}

void RequestTxtSystemClose(void) {
    gTxtSystem->mOpenRequested = 0;
    gTxtSystem->mCloseRequested = 1;
}

s32 IsTxtSystemState2NoCloseRequest(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mState == 2 && gTxtSystem->mCloseRequested == 0) {
        r = TRUE;
    }
    return r;
}

s32 IsTxtSystemState0NoOpenRequest(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mState == 0 && gTxtSystem->mOpenRequested == 0) {
        r = TRUE;
    }
    return r;
}

s32 IsTxtSystemState2AfterState1(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mPrevState == 1 && gTxtSystem->mState == 2) {
        r = TRUE;
    }
    return r;
}

#pragma thumb off

#pragma thumb on
s32 GetTxtSystemSelectedIndex(void) {
    u32 value0;
    value0 = gTxtSystem->mSelectedIndex;
    return value0;
}
#pragma thumb off

#pragma thumb on
s32 GetTxtSystemDone(void) {
    u32 value0;
    value0 = gTxtSystem->mDone;
    return value0;
}
#pragma thumb off

#pragma thumb on

u32 GetTxtSystemInputAccepted(void) {
    return gTxtSystem->mInputAccepted;
}

void SetTxtSystemMode(u32 p0) {
    gTxtSystem->mMode = p0;
}

#pragma thumb off

#pragma thumb on

void SetTxtSystemBgOffsetRequested(int a, int b) {
    if (a < -0x96) {
        a = -0x96;
    }
    if (a > 0x96) {
        a = 0x96;
    }
    if (b < -0x96) {
        b = -0x96;
    }
    if (b > 0x96) {
        b = 0x96;
    }
    gTxtSystem->mBgOffsetRequested[0] = a;
    gTxtSystem->mBgOffsetRequested[1] = b;
}

#pragma thumb off

#pragma thumb on
void SetTxtSystemSoundId(int arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &gTxtSystem;
    value2 = *(const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    value2 = (value2) + (value0);
    value0 = 0x2250u;
    *(u32 *) ((value2) + (value0)) = value1;
}
#pragma thumb off

#pragma thumb on

void SetTxtSystemOpenSoundId(u32 p0) {
    gTxtSystem->mOpenSoundId = p0;
}

#pragma thumb off
