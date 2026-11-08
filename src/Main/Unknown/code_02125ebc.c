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
#include "g2d_CharCanvas.h"
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

static inline void func_021274ec_inline(Unk0217d3f0_2178 *textCanvas, CharCanvas *charCanvas, u32 font) {
    textCanvas->mUnk_00 = charCanvas;
    textCanvas->mUnk_04 = font;
    textCanvas->mUnk_08 = 1;
    textCanvas->mUnk_0c = 1;
}

s32 InitTxtSystem(void *heap, TxtSystemArgs *args) {
    s32 subCharOffset;
    s32 i;
    CharCanvas *charCanvas;

    subCharOffset = args->mSubCharOffset;
    gTxtSystem = HeapAlloc(heap, 0x2278);
    if (args->mUseCanvas1 != 0) {
        gTxtSystem->mUseCanvas1 = 1;
    }
    if (args->mUseCanvas2 != 0) {
        gTxtSystem->mUseCanvas2 = 1;
    }
    if (args->mUseCanvas3 != 0) {
        gTxtSystem->mUseCanvas3 = 1;
    }
    gTxtSystem->mEnabled = 1;
    InitTxtSystemDisplay();
    subCharOffset = LoadTxtSystem(subCharOffset);
    for (i = 0; i < 7; i++) {
        if (!((i == 1 && gTxtSystem->mUseCanvas1 == 0) || (i == 2 && gTxtSystem->mUseCanvas2 == 0) ||
              (i == 3 && gTxtSystem->mUseCanvas3 == 0))) {
            gTxtSystem->mCharBuffers[i] =
                HeapAlloc(heap, (gTxtSystemCanvasSizes[i][0] * gTxtSystemCanvasSizes[i][1]) << 5);
            NNS_G2dCharCanvasInitForBG(&gTxtSystem->mCharCanvases[i], gTxtSystem->mCharBuffers[i],
                                       gTxtSystemCanvasSizes[i][0], gTxtSystemCanvasSizes[i][1], 4);
            charCanvas = &gTxtSystem->mCharCanvases[i];
            charCanvas->mUnk_18(charCanvas, 0);
            func_021274ec_inline(&gTxtSystem->mUnk_2178[i], &gTxtSystem->mCharCanvases[i], args->mFont);
        }
    }
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mState = 0;
    gTxtSystem->mNextState = 0;
    gTxtSystem->mPrevState = 0;
    gTxtSystem->mStateFrames = 0;
    gTxtSystem->mAnimFrameIndexFrames = 0;
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
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearTxtSystemPointer(void) {
    u32 address;
    u32 zero;
    zero = 0u;
    address = (u32) &gTxtSystem;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void InitTxtSystemDisplay(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((mainDisplayBits | 4) << 8);
    reg_G2_BG2CNT &= ~3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 1) << 8);
    reg_G2S_DB_BG0CNT &= ~3;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8b00;
}

static inline void func_0212717c_inline(void *dst, u16 value) {
    vu16 fillValue = value;

    MIi_CpuClear16(fillValue, dst, 0x1000);
}

s32 LoadTxtSystem(s32 subCharOffset) {
    Ncgr *firstChars;
    Ncgr *secondChars;
    Nclr *palette;

    if (*(vu16 *) 0x27ffc40 == 2) {
        LocateNcgr(&firstChars, FindSceneFile(data_0216e708));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindSceneFile(data_0216e720));
        LocateNclr(&palette, FindSceneFile(data_0216e738));
    } else {
        LocateNcgr(&firstChars, FindFileInLoadedArchives(data_0216e750));
        LocateNcgr(&secondChars, FindFileInLoadedArchives(data_0216e768));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindFileInLoadedArchives(data_0216e780));
        LocateNscr(&gTxtSystem->mBgNscrs[1], FindFileInLoadedArchives(data_0216e798));
        LocateNscr(&gTxtSystem->mBgNscrs[2], FindFileInLoadedArchives(data_0216e7b0));
        LocateNscr(&gTxtSystem->mBgNscrs[3], FindFileInLoadedArchives(data_0216e7c8));
        LocateNscr(&gTxtSystem->mBgNscrs[4], FindFileInLoadedArchives(data_0216e7e0));
        LocateNscr(&gTxtSystem->mBgNscrs[5], FindFileInLoadedArchives(data_0216e7f8));
        LocateNscr(&gTxtSystem->mBgNscrs[6], FindFileInLoadedArchives(data_0216e810));
        LocateNclr(&palette, FindFileInLoadedArchives(data_0216e828));
    }
    gTxtSystem->mCanvasFileCharIndex[0] = 0;
    DC_FlushRange(firstChars->mData, firstChars->mDataSize);
    GX_LoadBG2Char(firstChars->mData, 0, firstChars->mDataSize);
    if (gTxtSystem->mUseCanvas2 != 0) {
        subCharOffset = subCharOffset - firstChars->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[2] = subCharOffset >> 5;
        DC_FlushRange(firstChars->mData, firstChars->mDataSize);
        GXS_LoadBG0Char(firstChars->mData, subCharOffset, firstChars->mDataSize);
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        if (gTxtSystem->mUseCanvas1 != 0) {
            gTxtSystem->mCanvasFileCharIndex[1] = 0;
        }
        gTxtSystem->mB01CharIndex[0] = firstChars->mDataSize >> 5;
        DC_FlushRange(secondChars->mData, secondChars->mDataSize);
        GX_LoadBG2Char(secondChars->mData, gTxtSystem->mB01CharIndex[0] << 5, secondChars->mDataSize);
        if (gTxtSystem->mUseCanvas3 != 0) {
            gTxtSystem->mCanvasFileCharIndex[3] = gTxtSystem->mCanvasFileCharIndex[2];
        }
        subCharOffset = subCharOffset - secondChars->mDataSize;
        gTxtSystem->mCanvasFileCharIndex[4] = subCharOffset >> 5;
        gTxtSystem->mCanvasFileCharIndex[5] = subCharOffset >> 5;
        gTxtSystem->mCanvasFileCharIndex[6] = subCharOffset >> 5;
        gTxtSystem->mB01CharIndex[1] = subCharOffset >> 5;
        DC_FlushRange(secondChars->mData, secondChars->mDataSize);
        GXS_LoadBG0Char(secondChars->mData, subCharOffset, secondChars->mDataSize);
    }
    DC_FlushRange(palette->mData, 0x1c0);
    GX_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
    GXS_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
    gTxtSystem->mUnk_2244 = palette->mData[0xee];
    gTxtSystem->mUnk_2246 = palette->mData[0xdf];
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    func_0212717c_inline((void *) G2S_GetBG0ScrPtr(), gTxtSystem->mCanvasFileCharIndex[4]);
    return subCharOffset;
}

void RefreshTxtSystemAnim(void) {
    s32 row;
    s32 i;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    rectIndex = gTxtSystem->mAnimFrameIndex + 4;
    for (i = 0; i < 2; i++) {
        if (gTxtSystem->mAnimVisible[i] != 0) {
            screenBuffer = gTxtSystem->mMainScreenBuffer;
            if (i == 1) {
                screenBuffer = gTxtSystem->mSubScreenBuffer;
            }
            for (row = gTxtSystemNscrRects[rectIndex].mUnk_02; row <= gTxtSystemNscrRects[rectIndex].mUnk_03; row++) {
                for (column = gTxtSystemNscrRects[rectIndex].mUnk_00; column <= gTxtSystemNscrRects[rectIndex].mUnk_01;
                     column++) {
                    *(screenBuffer + row * 32 + column) =
                        gTxtSystem->mB01CharIndex[i] +
                        *((u16 *) gTxtSystem->mBgNscrs[rectIndex]->mData + row * 32 + column);
                }
            }
        }
    }
}

void RefreshTxtSystemScreenBuffers(u32 *b) {
    u8 rectIndices[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 i;
    s32 row;
    s32 column;
    s32 rectIndex;
    u16 *screenBuffer;

    MemFillWordsByBlock_inline(gTxtSystem->mMainScreenBuffer, 0x1000);
    func_0212717c_inline(&gTxtSystem->mSubScreenBuffer, gTxtSystem->mCanvasFileCharIndex[4]);
    for (i = 0; i < 9; i++) {
        if (*b != 0) {
            if ((u32) (i - 7) <= 1) {
                RefreshTxtSystemAnim();
            } else if (i != 6) {
                rectIndex = rectIndices[i];
                screenBuffer = gTxtSystem->mSubScreenBuffer;
                if ((u32) i <= 1) {
                    screenBuffer = gTxtSystem->mMainScreenBuffer;
                }
                for (row = gTxtSystemNscrRects[rectIndex].mUnk_02; row <= gTxtSystemNscrRects[rectIndex].mUnk_03;
                     row++) {
                    for (column = gTxtSystemNscrRects[rectIndex].mUnk_00;
                         column <= gTxtSystemNscrRects[rectIndex].mUnk_01; column++) {
                        *(screenBuffer + row * 32 + column) =
                            gTxtSystem->mCanvasFileCharIndex[i] +
                            *((u16 *) gTxtSystem->mBgNscrs[rectIndex]->mData + row * 32 + column);
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
    TxtSystem *txtSystem;
    txtSystem = gTxtSystem;
    if (0 < txtSystem->mExtraCanvasCount) {
        CallQueueAppend(0x1f, ((0xee - txtSystem->mSelectedIndex) * 2), &txtSystem->mUnk_2246, 2);
        CallQueueAppend(0x1f, (0xfe - gTxtSystem->mSelectedIndex) * 2, &gTxtSystem->mUnk_2246, 2);
        txtSystem = gTxtSystem;
        if (txtSystem->mExtraCanvasCount == 2) {
            CallQueueAppend(0x1f, ((txtSystem->mSelectedIndex + 0xed) * 2), &txtSystem->mUnk_2244, 2);
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
    s32 bufferSize;
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
                bufferSize = (gTxtSystemCanvasSizes[i][0] * gTxtSystemCanvasSizes[i][1]) << 5;
                m = 0x14;
                if ((u32) i <= 1) {
                    m = 6;
                }
                CallQueueAppend(m, (gTxtSystem->mCanvasFileCharIndex[i] + gTxtSystemCanvasCharOffsets[i]) << 5,
                                gTxtSystem->mCharBuffers[i], bufferSize);
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
    TxtSystem *txtSystem;
    s32 i;

    gTxtSystem->mStateFrames++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBgOffset[i] = InterpolateS16(1, gTxtSystemBgOffsets[gTxtSystem->mOpenFromIndex],
                                                  -gTxtSystem->mBgOffsetAtOpen[i], gTxtSystem->mStateFrames, 0xf);
    }
    txtSystem = gTxtSystem;
    txtSystem->mBrightness = (txtSystem->mStateFrames * -10) / 15;
    if (gTxtSystem->mStateFrames >= 15) {
        if (gTxtSystem->mCloseRequested == 0) {
            gTxtSystem->mOpenRequested = 0;
        }
        gTxtSystem->mNextState = 2;
        gTxtSystem->mStateFrames = 0;
    }
}

static inline BOOL func_02126a00_inline(u16 pointX, u16 pointY, u8 minX, u8 maxX, u8 minY, u8 maxY) {
    if (pointX >= minX && pointX <= maxX && pointY >= minY && pointY <= maxY) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02126a00_inline2(u32 inputSlotIndex) {
    BOOL r = FALSE;
    BOOL s = FALSE;

    if (data_02175674[inputSlotIndex].mUnk_00 == 0 && data_02175680[inputSlotIndex].mUnk_00 < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[inputSlotIndex].mUnk_00 == 0 && data_02175674[inputSlotIndex].mUnk_00 != 0) {
        r = TRUE;
    }
    return r;
}

// State 2: open; answers a close request, or a touch or key press when the box has buttons.
void AdvanceTxtSystemState2(void) {
    s32 buttonCount;
    s32 offsetTouchY;
    u16 clampedTouchY;
    s32 hit;
    u16 touchX;
    TxtSystem *txtSystem;
    u32 inputSlotIndex;
    u16 keys;

    switch (gTxtSystem->mMode) {
        case 0:
            inputSlotIndex = 8;
            break;
        case 1:
            inputSlotIndex = func_020435bc();
            break;
    }
    touchX = data_02175670[inputSlotIndex].mUnk_00;
    txtSystem = gTxtSystem;
    offsetTouchY = txtSystem->mBgOffset[1] + data_02175672[inputSlotIndex].mUnk_00;
    if (offsetTouchY < 0) {
        offsetTouchY = 0xff;
    }
    if (offsetTouchY > 0xff) {
        offsetTouchY = 0xff;
    }
    clampedTouchY = offsetTouchY;
    if (txtSystem->mCloseRequested != 0) {
        txtSystem->mNextState = 4;
        return;
    }
    buttonCount = txtSystem->mExtraCanvasCount;
    if (buttonCount <= 0) {
        return;
    }
    hit = -1;
    if (buttonCount == 2) {
        if (func_02126a00_inline2(inputSlotIndex) != 0) {
            if (func_02126a00_inline(touchX, clampedTouchY, gTxtSystemHitRects[5].mUnk_00,
                                     gTxtSystemHitRects[5].mUnk_01, gTxtSystemHitRects[5].mUnk_02,
                                     gTxtSystemHitRects[5].mUnk_03) != FALSE) {
                hit = 0;
            }
            if (func_02126a00_inline(touchX, clampedTouchY, gTxtSystemHitRects[6].mUnk_00,
                                     gTxtSystemHitRects[6].mUnk_01, gTxtSystemHitRects[6].mUnk_02,
                                     gTxtSystemHitRects[6].mUnk_03) != FALSE) {
                hit = 1;
            }
        }
    }
    keys = data_02175628[inputSlotIndex].mUnk_00;
    if ((u16) (keys & PAD_KEY_A) == 0) {
        if (func_02126a00_inline2(inputSlotIndex) == 0 || buttonCount != 1 ||
            func_02126a00_inline(touchX, clampedTouchY, gTxtSystemHitRects[4].mUnk_00, gTxtSystemHitRects[4].mUnk_01,
                                 gTxtSystemHitRects[4].mUnk_02, gTxtSystemHitRects[4].mUnk_03) == FALSE) {
            if (hit == -1) {
                goto L;
            }
        }
    }
    if (buttonCount == 1) {
        func_02126ea8();
    } else {
        if (hit == -1 || txtSystem->mSelectedIndex == hit) {
            func_02126ea8();
        } else {
            txtSystem->mSelectedIndex = hit;
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
    if (buttonCount == 2) {
        if ((u16) (keys & PAD_KEY_LEFT) != 0 && txtSystem->mSelectedIndex == 1) {
            txtSystem->mSelectedIndex = 0;
            func_02126ef8();
            StartSoundOncePerFrame(0);
            return;
        }
        if ((u16) (keys & 0x10) != 0 && txtSystem->mSelectedIndex == 0) {
            txtSystem->mSelectedIndex = 1;
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
    TxtSystem *txtSystem;
    s32 i;

    gTxtSystem->mStateFrames++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mBgOffset[i] =
            InterpolateS16(1, -gTxtSystem->mBgOffsetAtOpen[i], gTxtSystemBgOffsets[gTxtSystem->mCloseToIndex],
                           gTxtSystem->mStateFrames, 0xf);
    }
    txtSystem = gTxtSystem;
    txtSystem->mBrightness = -10 - (txtSystem->mStateFrames * -10) / 15;
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
            gTxtSystem->mAnimFrameIndexFrames++;
            if (gTxtSystem->mAnimFrameIndexFrames >= 4) {
                gTxtSystem->mAnimFrameIndexFrames = 0;
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

void func_021266e4(void *text) {
    func_02126638(text, 1, 1, 1, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void func_02126638(void *text, s32 mainBlendPlanes, s32 subBlendPlanes, s32 openFromIndex, s32 closeToIndex,
                   s32 mainAnim, s32 subAnim) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mUnk_18(charCanvas, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void func_0212658c(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                   u32 mainAnim, u32 subAnim) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[1];
    charCanvas->mUnk_18(charCanvas, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[1], 0, 0, gTxtSystemCanvasSizes[1][0] << 3, gTxtSystemCanvasSizes[1][1] << 3,
                  1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[1] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}
#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButton(void *text, void *buttonText) {
    u32 subBlendPlanes = ((0x1u) + (0x0u));
    SetupTxtSystemMainTextButtonEx(text, buttonText, 0x1u, subBlendPlanes, 0x1u, 0x0u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemMainTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                    u32 openFromIndex, u32 closeToIndex, u32 mainAnim) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mUnk_18(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[4];
    charCanvas->mUnk_18(charCanvas, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, text);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3, gTxtSystemCanvasSizes[4][1] << 3,
                  2, 0x480, 1, buttonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemMainTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    SetupTxtSystemMainTextTwoButtonsEx(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0, 0);
}

void SetupTxtSystemMainTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                        u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                                        u32 mainAnim) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[0];
    charCanvas->mUnk_18(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[5];
    charCanvas->mUnk_18(charCanvas, 0xe);
    charCanvas = &gTxtSystem->mCharCanvases[6];
    charCanvas->mUnk_18(charCanvas, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, gTxtSystemCanvasSizes[0][0] << 3, gTxtSystemCanvasSizes[0][1] << 3,
                  1, 0x480, 1, text);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3, gTxtSystemCanvasSizes[5][1] << 3,
                  2, 0x480, 1, buttonText);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3, gTxtSystemCanvasSizes[6][1] << 3,
                  2, 0x480, 1, secondButtonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[0] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = selectedIndex;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = mainAnim;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubText(void *text) {
    SetupTxtSystemSubTextEx(text, 1, 1, 1, 0, 0);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextEx(void *text, u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex,
                             u32 subAnim) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mUnk_18(charCanvas, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, text);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = subAnim;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButton(void *text, void *buttonText) {
    u32 subBlendPlanes = ((0x1u) + (0x0u));
    SetupTxtSystemSubTextButtonEx(text, buttonText, 0x1u, subBlendPlanes, 0x1u, 0x0u);
}

#pragma thumb off

#pragma thumb on

void SetupTxtSystemSubTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mUnk_18(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[4];
    charCanvas->mUnk_18(charCanvas, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, text);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, gTxtSystemCanvasSizes[4][0] << 3, gTxtSystemCanvasSizes[4][1] << 3,
                  2, 0x480, 1, buttonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[4] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 1;
    gTxtSystem->mSelectedIndex = 0;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void SetupTxtSystemSubTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex) {
    SetupTxtSystemSubTextTwoButtonsEx(text, buttonText, secondButtonText, selectedIndex, 1, 1, 1, 0);
}

void SetupTxtSystemSubTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex) {
    CharCanvas *charCanvas;

    charCanvas = &gTxtSystem->mCharCanvases[2];
    charCanvas->mUnk_18(charCanvas, 0xf);
    charCanvas = &gTxtSystem->mCharCanvases[5];
    charCanvas->mUnk_18(charCanvas, 0xe);
    charCanvas = &gTxtSystem->mCharCanvases[6];
    charCanvas->mUnk_18(charCanvas, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, gTxtSystemCanvasSizes[2][0] << 3, gTxtSystemCanvasSizes[2][1] << 3,
                  1, 0x480, 1, text);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, gTxtSystemCanvasSizes[5][0] << 3, gTxtSystemCanvasSizes[5][1] << 3,
                  2, 0x480, 1, buttonText);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, gTxtSystemCanvasSizes[6][0] << 3, gTxtSystemCanvasSizes[6][1] << 3,
                  2, 0x480, 1, secondButtonText);
    ClearTxtSystemCanvasInUse();
    gTxtSystem->mCanvasInUse[2] = 1;
    gTxtSystem->mCanvasInUse[5] = 1;
    gTxtSystem->mCanvasInUse[6] = 1;
    RequestTxtSystemOpen();
    gTxtSystem->mExtraCanvasCount = 2;
    gTxtSystem->mSelectedIndex = selectedIndex;
    gTxtSystem->mDone = 0;
    gTxtSystem->mAnimRequested[0] = 0;
    gTxtSystem->mAnimRequested[1] = 0;
    gTxtSystem->mBlendPlanesRequested[0] = mainBlendPlanes;
    gTxtSystem->mBlendPlanesRequested[1] = subBlendPlanes;
    gTxtSystem->mOpenFromIndex = openFromIndex;
    gTxtSystem->mCloseToIndex = closeToIndex;
}

void RequestTxtSystemClose(void) {
    gTxtSystem->mOpenRequested = 0;
    gTxtSystem->mCloseRequested = 1;
}

s32 IsTxtSystemState2NoCloseRequest(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mState == 2 && gTxtSystem->mCloseRequested == 0) {
        result = TRUE;
    }
    return result;
}

s32 IsTxtSystemState0NoOpenRequest(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mState == 0 && gTxtSystem->mOpenRequested == 0) {
        result = TRUE;
    }
    return result;
}

s32 IsTxtSystemState2AfterState1(void) {
    BOOL result;

    result = FALSE;
    if (gTxtSystem->mPrevState == 1 && gTxtSystem->mState == 2) {
        result = TRUE;
    }
    return result;
}

#pragma thumb off

#pragma thumb on
s32 GetTxtSystemSelectedIndex(void) {
    u32 selectedIndex;
    selectedIndex = gTxtSystem->mSelectedIndex;
    return selectedIndex;
}
#pragma thumb off

#pragma thumb on
s32 GetTxtSystemDone(void) {
    u32 done;
    done = gTxtSystem->mDone;
    return done;
}
#pragma thumb off

#pragma thumb on

u32 GetTxtSystemInputAccepted(void) {
    return gTxtSystem->mInputAccepted;
}

void SetTxtSystemMode(u32 mode) {
    gTxtSystem->mMode = mode;
}

#pragma thumb off

#pragma thumb on

void SetTxtSystemBgOffsetRequested(int mainOffset, int subOffset) {
    if (mainOffset < -0x96) {
        mainOffset = -0x96;
    }
    if (mainOffset > 0x96) {
        mainOffset = 0x96;
    }
    if (subOffset < -0x96) {
        subOffset = -0x96;
    }
    if (subOffset > 0x96) {
        subOffset = 0x96;
    }
    gTxtSystem->mBgOffsetRequested[0] = mainOffset;
    gTxtSystem->mBgOffsetRequested[1] = subOffset;
}

#pragma thumb off

#pragma thumb on
void SetTxtSystemSoundId(int soundIndex, u32 soundId) {
    u32 value0 = soundIndex;
    u32 value1 = soundId;
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

void SetTxtSystemOpenSoundId(u32 soundId) {
    gTxtSystem->mOpenSoundId = soundId;
}

#pragma thumb off
