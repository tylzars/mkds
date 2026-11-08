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
    s32 color;
    gPaletteBlend = HeapAlloc(heap, 0x90);
    gPaletteBlend->mCycleFrames = 0;
    gPaletteBlend->mStopped = FALSE;
    gPaletteBlend->mPaletteIndex = paletteIndex;
    gPaletteBlend->mFirstBlend = TRUE;
    MI_CpuCopy8(nclr->mData + paletteIndex * 0x10, gPaletteBlend->mPalette, 0x20);
    for (i = 0; i < 4; i++) {
        color = gPaletteBlend->mFromColors[i];
        gPaletteBlend->mBlendFrom[i].mBits0To4 = color & 0x1f;
        gPaletteBlend->mBlendFrom[i].mBits5To9 = (color & 0x3e0) >> 5;
        gPaletteBlend->mBlendFrom[i].mBits10To14 = (color & 0x7c00) >> 10;
    }
    for (i = 0; i < 4; i++) {
        color = gPaletteBlend->mToColors[i];
        gPaletteBlend->mBlendTo[i].mBits0To4 = color & 0x1f;
        gPaletteBlend->mBlendTo[i].mBits5To9 = (color & 0x3e0) >> 5;
        gPaletteBlend->mBlendTo[i].mBits10To14 = (color & 0x7c00) >> 10;
    }
}
#pragma thumb off

#pragma thumb on
void ClearPaletteBlendPointer(void) {
    u32 address;
    u32 zero;
    zero = 0u;
    address = (u32) &gPaletteBlend;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void BlendPaletteColors(s32 weight) {
    s32 i;
    PaletteBlend *paletteBlend;
    for (i = 0; i < 4; i++) {
        paletteBlend = gPaletteBlend;
        (&paletteBlend->mPalette[1])[i] = ((((0x1000 - weight) * paletteBlend->mBlendFrom[i].mBits10To14 +
                                             weight * paletteBlend->mBlendTo[i].mBits10To14) >>
                                            12)
                                           << 10) |
                                          ((((0x1000 - weight) * paletteBlend->mBlendFrom[i].mBits0To4 +
                                             weight * paletteBlend->mBlendTo[i].mBits0To4) >>
                                            12) |
                                           ((((0x1000 - weight) * paletteBlend->mBlendFrom[i].mBits5To9 +
                                              weight * paletteBlend->mBlendTo[i].mBits5To9) >>
                                             12)
                                            << 5));
    }
    if (gPaletteBlend->mFirstBlend == FALSE) {
        CallQueueAppend(0x1e, gPaletteBlend->mPaletteIndex << 5, gPaletteBlend->mPalette, 0x20);
    } else {
        gPaletteBlend->mFirstBlend = FALSE;
    }
}

void AdvancePaletteBlend(void) {
    s32 cycleFrames;
    if (gPaletteBlend->mStopped == FALSE) {
        gPaletteBlend->mCycleFrames++;
        if (gPaletteBlend->mCycleFrames >= 0x5a) {
            gPaletteBlend->mCycleFrames = 0;
        }
    }
    cycleFrames = gPaletteBlend->mCycleFrames;
    if (cycleFrames < 0x1e) {
        BlendPaletteColors(((0x1e - cycleFrames) << 12) / 0x1e);
    } else if (cycleFrames < 0x3c) {
        BlendPaletteColors(0);
    } else {
        BlendPaletteColors(((cycleFrames - 0x3c) << 12) / 0x1e);
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
    s32 charSpacing;
    Nclr *nclr;
    StaffRollText *staffRollText;
    TextCanvas *textCanvas;
    void *font;
    gStaffRollText = HeapAlloc(heap, 0x85c);
    gStaffRollText->mHeap = heap;
    gStaffRollText->mState = 0;
    gStaffRollText->mNextState = 0;
    CallQueueInit(HeapAlloc(heap, 0xa0), 0xa);
    gStaffRollText->mScrollYFixed = 0;
    gStaffRollText->mNextReadScrollY = 0;
    gStaffRollText->mScrollYRemaining = -1;
    gStaffRollText->mScrollYPerFrame = 0x70a;
    gStaffRollText->mCharSpacing = 1;
    gStaffRollText->mUnk_850 = 1;
    gStaffRollText->mUnk_854 = 0x240;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x100;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x1000;
    MemFillWordsByBlock_inline((void *) G2S_GetBG0CharPtr(), 0x8000);
    for (i = 0; i < 0x400; i++) {
        ((u16 *) G2S_GetBG0ScrPtr())[i] = i | 0xf000;
    }
    LoadNclrData(&nclr, FindSceneFile(gEndingStaffRollB00NclrName));
    CallQueueAppend(0x1f, 0x1e0, nclr->mData + 0xf0, 0x20);
    NNS_G2dCharCanvasInitForBG(gStaffRollText->mCharCanvas, gStaffRollText->mCharBuffer, 0x20, 2, 4);
    charSpacing = gStaffRollText->mCharSpacing;
    font = func_020b403c(2);
    staffRollText = gStaffRollText;
    textCanvas = &staffRollText->mTextCanvas;
    staffRollText->mTextCanvas.mCharCanvas = staffRollText->mCharCanvas;
    textCanvas->mFont = font;
    textCanvas->mCharSpacing = charSpacing;
    textCanvas->mLineSpacing = 0;
    MI_CpuFill8(gStaffRollText->mCharBuffer, 0, 0x800);
    gStaffRollText->mTextPosition = GetBmgEntry(FindSceneFile(gStaffRollBmgName), 0);
}

u32 ClearStaffRollTextPointer(void) {
    u32 address;
    u32 zero;
    address = (u32) &gStaffRollText;
    zero = 0u;
    *(u32 *) ((address) + (0)) = zero;
    return address;
}

void AdvanceStaffRollTextState1(void) {
    s32 tagSize;
    s32 c;
    s32 charCount;
    u8 *textPosition;
    StaffRollText *staffRollText;
    u16 lineText[100];
    s32 v;
    BOOL lineDone;
    s32 variant;
    s32 argument;
    u32 character;
    s32 a;
    StaffRollTag *tag;
    gStaffRollText->mScrollYFixed += gStaffRollText->mScrollYPerFrame;
    a = (gStaffRollText->mScrollYFixed >> 12) - 8;
    if (a < 0) {
        a += 0x100;
    }
    a = a % 256;
    MemFillWordsByBlock_inline((void *) (G2S_GetBG0CharPtr() + ((a >> 3) << 10)), 0x400);
    staffRollText = gStaffRollText;
    if (staffRollText->mScrollYRemaining > 0) {
        staffRollText->mScrollYRemaining -= staffRollText->mScrollYPerFrame;
        if (gStaffRollText->mScrollYRemaining <= 0) {
            gStaffRollText->mNextState = 2;
        }
        return;
    }
    if (staffRollText->mScrollYFixed <= staffRollText->mNextReadScrollY) {
        return;
    }
    charCount = 0;
    lineDone = FALSE;
    MI_CpuFill8(lineText, 0, 0xc8);
    do {
        staffRollText = gStaffRollText;
        textPosition = staffRollText->mTextPosition;
        tag = (StaffRollTag *) textPosition;
        character = tag->mCharacter;
        if (character == 0x1a) {
            c = tag->mKind;
            tagSize = tag->mSize;
            variant = tag->mVariant;
            if (c == 1) {
                argument = 0;
                if (variant != 0x63) {
                    argument = tag->mArgument;
                }
                switch (variant) {
                    case 0:
                        staffRollText->mUnk_854 = 0x40;
                        switch (argument) {
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
                        lineDone = TRUE;
                        staffRollText->mNextReadScrollY += argument << 16;
                        break;
                    case 2:
                        staffRollText->mUnk_850 = argument * 2 + 1;
                        break;
                    case 3:
                        staffRollText->mCharSpacing = argument;
                        break;
                    case 4:
                        staffRollText->mScrollYPerFrame = (argument << 12) / 100;
                        break;
                    case 5:
                        break;
                    case 0x63:
                        lineDone = TRUE;
                        staffRollText->mScrollYRemaining = 0xd0000;
                        break;
                }
            }
            gStaffRollText->mTextPosition += tagSize;
        } else if (character == 0xa) {
            lineDone = TRUE;
            staffRollText->mNextReadScrollY += 0x10000;
            gStaffRollText->mTextPosition += 2;
        } else if (character == 0) {
            staffRollText->mTextPosition = textPosition + 2;
        } else {
            lineText[charCount] = character;
            charCount++;
            staffRollText->mTextPosition += 2;
        }
    } while (lineDone == FALSE);
    MI_CpuFill8(gStaffRollText->mCharBuffer, 0, 0x800);
    v = gStaffRollText->mUnk_850;
    c = 0;
    if (v == 3) {
        c = 2;
    }
    NNSi_G2dTextCanvasDrawTextRect(&gStaffRollText->mTextCanvas, 8, c, 0xf0, 0x10, v, gStaffRollText->mUnk_854,
                                   lineText);
    staffRollText = gStaffRollText;
    a = (((staffRollText->mScrollYFixed >> 12) % 256) + 0xc0) >> 3;
    a = a << 3;
    if (a >= 0x100) {
        a -= 0x100;
    }
    if (a + 0x10 > 0x100) {
        CallQueueAppend(0x14, a << 7, staffRollText->mCharBuffer, (0x100 - a) << 7);
        CallQueueAppend(0x14, 0, &gStaffRollText->mCharBuffer[a << 7], (a - 0xf0) << 7);
    } else {
        CallQueueAppend(0x14, a << 7, staffRollText->mCharBuffer, 0x800);
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

void SetStaffRollScrollAndDrainQueue(void) {
    reg_G2S_DB_BG0OFS = (((gStaffRollText->mScrollYFixed >> 12) % 256) << 16) & 0x1ff0000;
    CallQueueDrain();
}

u32 StartStaffRollText(void) {
    u32 address;
    u32 one;
    address = (u32) &gStaffRollText;
    one = 1u;
    address = *(const u32 *) ((address) + (0));
    *(u32 *) ((address) + (4)) = one;
    return address;
}
