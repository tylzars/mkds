#include "Main/Unknown/code_0212775c.h"
#include "registers.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_02127a38.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "g2d_CharCanvas.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021285b0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02128570.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"

#pragma thumb on
s32 InitSelectReturn(void *heap, s32 subCharOffset) {
    u32 subDisplayBits;
    gSelectReturn = HeapAlloc(heap, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectReturnDisplay();
        subCharOffset = LoadSelectReturn(subCharOffset);
        gSelectReturn->mDisplayBitOn = TRUE;
    } else {
        gSelectReturn->mDisplayBitOn = FALSE;
        subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        subDisplayBits &= ~4;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
    }
    gSelectReturn->mEnabled = TRUE;
    gSelectReturn->mState = 0;
    gSelectReturn->mNextState = 0;
    gSelectReturn->mStateFrames = 0;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState4Requested = FALSE;
    gSelectReturn->mBg2Offset = -0x28;
    gSelectReturn->mSoundId = 0xe;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnPointer(void) {
    u32 address;
    u32 zero;
    zero = 0u;
    address = (u32) &gSelectReturn;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void InitSelectReturnDisplay(void) {
    u32 subDisplayBits;
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 4) << 8);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe00;
}

s32 LoadSelectReturn(s32 subCharOffset) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;
    s32 i;
    s32 j;
    s32 k;
    LocateNcgr(&ncgr, FindFileInLoadedArchives("select_return_s_b_00.ncgr"));
    LocateNscr(&nscr, FindFileInLoadedArchives("select_return_s_bg_00.nscr"));
    LocateNclr(&nclr, FindFileInLoadedArchives("select_return_s_b_00.nclr"));
    subCharOffset -= ncgr->mDataSize;
    DC_FlushRange(ncgr->mData, ncgr->mDataSize);
    GXS_LoadBG2Char(ncgr->mData, subCharOffset, ncgr->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(gSelectReturn->mScreenMapCopy + i * 0x20 + j) =
                (subCharOffset >> 5) + *((u16 *) nscr->mData + i * 0x20 + j);
        }
    }
    DC_FlushRange(gSelectReturn->mScreenMapCopy, nscr->mDataSize);
    GXS_LoadBG2Scr(gSelectReturn->mScreenMapCopy, 0, nscr->mDataSize);
    DC_FlushRange(nclr->mData, 0x180);
    GXS_LoadBGPltt(nclr->mData + 0xc0, 0x180, 0x40);
    return subCharOffset;
}

void SetSelectReturnPaletteBits(s32 paletteKind) {
    s32 i;
    u16 paletteBits;
    paletteBits = 0xc000;
    if (paletteKind == 0) {
        paletteBits = 0xd000;
    }
    for (i = 0x260; i < 0x360; i++) {
        gSelectReturn->mScreenMapCopy[i] &= ~0xf000;
        gSelectReturn->mScreenMapCopy[i] |= paletteBits;
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x1a, 0x4c0, &gSelectReturn->mScreenMapCopy[0x260], 0x200);
    }
}

void AdvanceSelectReturnState0(void) {
    if (gSelectReturn->mState1Requested != FALSE) {
        gSelectReturn->mNextState = 1;
        gSelectReturn->mStateFrames = 0;
        SetSelectReturnPaletteBits(1);
    }
}

void AdvanceSelectReturnState1(void) {
    SelectReturn *selectReturn;
    gSelectReturn->mBg2Offset = LookupSelectReturnState1Bg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 10) {
        selectReturn->mNextState = 2;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState1Requested = FALSE;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnState2(void) {
    SelectReturn *selectReturn;
    selectReturn = gSelectReturn;
    if (selectReturn->mState3Requested != FALSE) {
        selectReturn->mNextState = 3;
        SetSelectReturnPaletteBits(0);
        return;
    }
    if (selectReturn->mState4Requested != FALSE) {
        selectReturn->mNextState = 4;
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectReturnState3(void) {
    SelectReturn *selectReturn;
    selectReturn = gSelectReturn;
    selectReturn->mBg2Offset = data_0215d0b4[selectReturn->mStateFrames];
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 9) {
        if (selectReturn->mState4Requested != FALSE) {
            selectReturn->mNextState = 4;
            SetSelectReturnPaletteBits(0);
        } else {
            selectReturn->mNextState = 2;
            SetSelectReturnPaletteBits(1);
        }
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState3Requested = FALSE;
    }
}

void AdvanceSelectReturnState4(void) {
    SelectReturn *selectReturn;
    gSelectReturn->mBg2Offset = LookupSelectReturnState4Bg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    selectReturn = gSelectReturn;
    if (selectReturn->mStateFrames >= 10) {
        selectReturn->mNextState = 0;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState4Requested = FALSE;
    }
}

void AdvanceSelectReturn(void) {
    SelectReturn *selectReturn;
    selectReturn = gSelectReturn;
    if (selectReturn->mEnabled != FALSE) {
        selectReturn->mState = selectReturn->mNextState;
        switch (gSelectReturn->mState) {
            case 0:
                AdvanceSelectReturnState0();
                break;
            case 1:
                AdvanceSelectReturnState1();
                break;
            case 2:
                AdvanceSelectReturnState2();
                break;
            case 3:
                AdvanceSelectReturnState3();
                break;
            case 4:
                AdvanceSelectReturnState4();
                break;
        }
    }
}

void WriteSelectReturnRegisters(void) {
    SelectReturn *selectReturn;
    u32 subDisplayBits;
    selectReturn = gSelectReturn;
    if (selectReturn->mEnabled != FALSE) {
        if (selectReturn->mDisplayBitOn != FALSE) {
            if (((reg_GXS_DB_DISPCNT & 0x1f00) >> 8 & 4) == 0) {
                subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 4) << 8);
            }
        } else {
            if (((reg_GXS_DB_DISPCNT & 0x1f00) >> 8 & 4) != 0) {
                subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits & ~4) << 8);
            }
        }
        reg_G2S_DB_BG2OFS = (gSelectReturn->mBg2Offset << 16) & 0x1ff0000;
    }
}

void RequestSelectReturnState1(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        gSelectReturn->mState1Requested = FALSE;
    } else {
        gSelectReturn->mState1Requested = TRUE;
    }
    gSelectReturn->mState3Requested = FALSE;
    gSelectReturn->mState4Requested = FALSE;
}

// a != 0 also asks for state 4 once state 3 ends.
void RequestSelectReturnState3WithSound(s32 requestState4) {
    s32 soundId;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState3Requested = TRUE;
    if (requestState4 != 0) {
        gSelectReturn->mState4Requested = TRUE;
    } else {
        gSelectReturn->mState4Requested = FALSE;
    }
    soundId = gSelectReturn->mSoundId;
    if (soundId != -1) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) soundId);
    }
}

void RequestSelectReturnState4(void) {
    if (IsSelectReturnState0NoState1Request() != 0) {
        gSelectReturn->mState4Requested = FALSE;
    } else {
        gSelectReturn->mState4Requested = TRUE;
    }
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState3Requested = FALSE;
}

s32 IsSelectReturnState2NoState3Or4Request(void) {
    BOOL result;
    BOOL t;
    SelectReturn *selectReturn;
    result = FALSE;
    t = FALSE;
    selectReturn = gSelectReturn;
    if (selectReturn->mState == 2 && selectReturn->mState4Requested == FALSE) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (selectReturn->mState3Requested == FALSE) {
            result = TRUE;
        }
    }
    return result;
}

s32 IsSelectReturnState0NoState1Request(void) {
    BOOL result;
    SelectReturn *selectReturn;
    result = FALSE;
    selectReturn = gSelectReturn;
    if (selectReturn->mState == 0 && selectReturn->mState1Requested == FALSE) {
        result = TRUE;
    }
    return result;
}
#pragma thumb off

#pragma thumb on

int LookupSelectReturnState1Bg2Offset(int frame) {
    if (frame < 0) {
        frame = 0;
    }
    if (10 <= frame) {
        frame = 9;
    }
    return data_0215d0c0[frame];
}

int LookupSelectReturnState4Bg2Offset(int frame) {
    if (frame < 0) {
        frame = 0;
    }
    if (10 <= frame) {
        frame = 9;
    }
    return data_0215d0cc[frame];
}

#pragma thumb off

#pragma thumb on
BOOL IsSelectReturnState2NoState3Or4RequestAndInRect(s32 pointX, s32 pointY) {
    if (IsSelectReturnState2NoState3Or4Request() != 0 && pointX >= 0 && pointX <= 0x28 && pointY >= 0x98 &&
        pointY <= 0xc0) {
        return TRUE;
    }
    return FALSE;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnDisplayBitOn(void) {
    u32 value0;
    u32 object;
    u32 zero;
    zero = 0u;
    value0 = (u32) &gSelectReturn;
    object = *(const u32 *) ((value0) + 0u);
    value0 = 0x820u;
    *(u32 *) ((object) + (value0)) = zero;
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnDisplayBitOn(void) {
    if (*(vu16 *) 0x27ffc40 != 2) {
        gSelectReturn->mDisplayBitOn = TRUE;
    }
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnSoundId(u32 soundId) {
    u32 value0 = soundId;
    u32 value1;
    u32 object;
    value1 = (u32) &gSelectReturn;
    object = *(const u32 *) ((value1) + 0u);
    value1 = 0x824u;
    *(u32 *) ((object) + (value1)) = value0;
}
#pragma thumb off

#pragma thumb on
// Zeroes the char buffer gate; StartSelectChoises sets it after taking the strings.
u32 ClearSelectChoisesUseCharBuffers(void) {
    u32 value0;
    u32 object;
    u32 zero;
    zero = 0u;
    value0 = (u32) &gSelectChoises;
    object = *(const u32 *) ((value0) + 0u);
    value0 = 0x8a0u;
    *(u32 *) ((object) + (value0)) = zero;
    return value0;
}
#pragma thumb off

#pragma thumb on
s32 InitSelectChoises(void *heap, void *font, s32 subCharOffset) {
    s32 i;
    s32 charSpacing;
    CharCanvas *charCanvas;
    Unk0217d3f0_2178 *textCanvas;
    u32 subDisplayBits;
    gSelectChoises = HeapAlloc(heap, 0x8b4);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectChoisesDisplay();
        subCharOffset = LoadSelectChoises(subCharOffset);
        gSelectChoises->mDisplayBitOn = 1;
    } else {
        gSelectChoises->mDisplayBitOn = 0;
        subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        subDisplayBits &= ~1;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (subDisplayBits << 8);
    }
    for (i = 0; i < 2; i++) {
        gSelectChoises->mCharBuffers[i] = HeapAlloc(heap, 0x800);
        NNS_G2dCharCanvasInitForBG(&gSelectChoises->mCharCanvases[i], gSelectChoises->mCharBuffers[i], 0x20, 2, 4);
        charCanvas = &gSelectChoises->mCharCanvases[i];
        charCanvas->mUnk_18(charCanvas, 0);
        charSpacing = func_020b4acc();
        textCanvas = &gSelectChoises->mUnk_874[i];
        textCanvas->mUnk_00 = &gSelectChoises->mCharCanvases[i];
        textCanvas->mUnk_04 = (u32) font;
        textCanvas->mUnk_08 = charSpacing;
        textCanvas->mUnk_0c = 0;
    }
    ClearSelectChoisesUseCharBuffers();
    gSelectChoises->mEnabled = 1;
    gSelectChoises->mState = 0;
    gSelectChoises->mNextState = 0;
    gSelectChoises->mState2Frames = 0;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    gSelectChoises->mState1Requested = 0;
    gSelectChoises->mState0Requested = 0;
    gSelectChoises->mDone = 0;
    gSelectChoises->mIndexNone = 0;
    gSelectChoises->mSoundIds[0] = 7;
    gSelectChoises->mSoundIds[1] = 0x10;
    gSelectChoises->mIndexNoneSoundId = 0x10;
    return subCharOffset;
}
#pragma thumb off

#pragma thumb on
void ClearSelectChoisesPointer(void) {
    u32 address;
    u32 zero;
    zero = 0u;
    address = (u32) &gSelectChoises;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
u32 InitSelectChoisesDisplay(void) {
    u32 value0;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001008u;
    registerValue = *(const u16 *) ((registerAddress) + 0u);
    value0 = 3u;
    registerValue = (registerValue) & ~(value0);
    *(u16 *) ((registerAddress) + 0u) = registerValue;
    registerValue = *(const u16 *) ((registerAddress) + 0u);
    value0 = 67u;
    registerValue = (registerValue) & (value0);
    value0 = 0xb00u;
    registerValue = (registerValue) | (value0);
    *(u16 *) ((registerAddress) + 0u) = registerValue;
    return value0;
}
#pragma thumb off

#pragma thumb on

s32 LoadSelectChoises(s32 subCharOffset) {
    Ncgr *chars;
    Nscr *screenMap;
    Nclr *palette;
    s32 s;
    s32 i;
    s32 j;
    s32 tileColumn;
    s32 tileRowOffset;
    ByteRect *tileRect;

    LocateNcgr(&chars, FindFileInLoadedArchives(gSelectChoisesSBNcgrName));
    LocateNscr(&screenMap, FindFileInLoadedArchives(gSelectChoisesSBgNscrName));
    LocateNclr(&palette, FindFileInLoadedArchives(gSelectChoisesSBNclrName));
    subCharOffset = subCharOffset - chars->mDataSize;
    s = subCharOffset >> 5;
    gSelectChoises->mFirstTileIndex = s;
    DC_FlushRange(chars->mData, chars->mDataSize);
    GXS_LoadBG0Char(chars->mData, subCharOffset, chars->mDataSize);
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            *(gSelectChoises->mNscrCopy + i * 32 + j) = s + *((u16 *) screenMap->mData + i * 32 + j);
        }
    }
    DC_FlushRange(gSelectChoises->mNscrCopy, screenMap->mDataSize);
    GXS_LoadBG0Scr(gSelectChoises->mNscrCopy, 0, screenMap->mDataSize);
    tileRect = &gSelectChoisesTileRect;
    tileRowOffset = tileRect->mUnk_02 * 32;
    tileColumn = tileRect->mUnk_00;
    gSelectChoises->mToggleOnFirstTile = gSelectChoises->mFirstTileIndex + (tileColumn + tileRowOffset);
    gSelectChoises->mToggleOffFirstTile = gSelectChoises->mFirstTileIndex + (tileRowOffset + (tileColumn + 3));
    DC_FlushRange(palette->mData, 0x1c0);
    GXS_LoadBGPltt(palette->mData + 0xe0, 0x1c0, 0x40);
    return subCharOffset;
}

void RefreshSelectChoisesNscrCopy(void) {
    s32 column;
    s32 i;
    s32 row;
    BOOL useToggleOnTiles;
    ByteRect *tileRect;
    s32 lastColumn;
    s32 tileIndex;
    u8(*origin)[2];
    s32 lastRow;
    s32 screenMapIndex;

    i = 0;
    origin = gSelectChoisesNscrOrigins;
    tileRect = &gSelectChoisesTileRect;
    lastColumn = tileRect->mUnk_01 - tileRect->mUnk_00;
    lastRow = tileRect->mUnk_03 - tileRect->mUnk_02;
    for (; i < 2; i++) {
        useToggleOnTiles = FALSE;
        if (i == gSelectChoises->mIndex && gSelectChoises->mToggleOn != 0) {
            useToggleOnTiles = TRUE;
        }
        for (row = 0; row <= lastRow; row++) {
            for (column = 0; column <= lastColumn; column++) {
                screenMapIndex = column + (*origin)[0] + ((row + (*origin)[1]) << 5);
                tileIndex = row * 32 + (gSelectChoises->mToggleOffFirstTile + column);
                if (useToggleOnTiles != FALSE) {
                    tileIndex = row * 32 + (gSelectChoises->mToggleOnFirstTile + column);
                }
                if (useToggleOnTiles != FALSE) {
                    gSelectChoises->mNscrCopy[screenMapIndex] =
                        tileIndex + ((gSelectChoises->mNscrCopy[screenMapIndex] & 0xffff0c00) + 0xe000);
                } else {
                    gSelectChoises->mNscrCopy[screenMapIndex] =
                        tileIndex + (gSelectChoises->mNscrCopy[screenMapIndex] & 0xfffffc00);
                }
            }
        }
        origin++;
    }
}

void RefreshSelectChoisesPaletteBits(void) {
    s32 i;
    s32 row;
    s32 column;
    s32 topNibble;
    s32 entry;

    for (i = 0; i < 2; i++) {
        topNibble = 0xe;
        if (gSelectChoises->mIndex != i) {
            topNibble = 0xf;
        }
        for (row = gSelectChoisesPaletteRects[i].mUnk_02; row <= gSelectChoisesPaletteRects[i].mUnk_03; row++) {
            for (column = gSelectChoisesPaletteRects[i].mUnk_00; column <= gSelectChoisesPaletteRects[i].mUnk_01;
                 column++) {
                entry = gSelectChoises->mNscrCopy[row * 32 + column];
                entry &= 0xffff0fff;
                entry += topNibble << 12;
                gSelectChoises->mNscrCopy[row * 32 + column] = entry;
            }
        }
    }
}

void RefreshAndQueueSelectChoises(void) {
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    RefreshSelectChoisesPaletteBits();
    RefreshSelectChoisesNscrCopy();
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x18, 0, gSelectChoises->mNscrCopy, 0x800);
    }
}

void func_02127d28(void) {
    s32 savedIndex;

    savedIndex = gSelectChoises->mIndex;
    gSelectChoises->mIndex = -1;
    RefreshSelectChoisesPaletteBits();
    gSelectChoises->mIndex = savedIndex;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x18, 0, gSelectChoises->mNscrCopy, 0x800);
    }
}

void AdvanceSelectChoisesState0(void) {
    s32 i;
    s32 j;
    s32 tileOffset;

    if (gSelectChoises->mState1Requested != 0) {
        RefreshAndQueueSelectChoises();
        gSelectChoises->mNextState = 1;
        i = 0;
        gSelectChoises->mState1Requested = i;
        gSelectChoises->mState2Frames = i;
        gSelectChoises->mIndexNone = i;
        if (gSelectChoises->mUseCharBuffers != 0) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
                    tileOffset = (j + i * 2) * 32 + 5;
                    if (*(vu16 *) 0x27ffc40 != 2) {
                        CallQueueAppend(0x14, (gSelectChoises->mFirstTileIndex + tileOffset) << 5,
                                        gSelectChoises->mCharBuffers[i] + ((j * 32 + 5) << 5), 0x360);
                    }
                }
            }
        }
    }
}

static inline BOOL func_02127a84_inline(u16 pointX, u16 pointY, u8 minX, u8 maxX, u8 minY, u8 maxY) {
    if (pointX >= minX && pointX <= maxX && pointY >= minY && pointY <= maxY) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02127a84_inline2(u32 inputSlotIndex) {
    BOOL r = FALSE;
    BOOL s = FALSE;
    u16 c = data_02175674[inputSlotIndex].mPressedBits;

    if (c == 0 && data_02175680[inputSlotIndex].mPressedBits < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[inputSlotIndex].mPressedBits == 0 && c != 0) {
        r = TRUE;
    }
    return r;
}

void AdvanceSelectChoisesState1(void) {
    s32 hit;
    u16 touchX;
    u16 touchY;
    InputSlotIndex inputSlotIndex;
    u16 keys;

    inputSlotIndex = UNK_02175628_INDEX_8;
    touchX = data_02175670[inputSlotIndex].mPressedBits;
    touchY = data_02175672[inputSlotIndex].mPressedBits;
    if (gSelectChoises->mState0Requested != 0) {
        gSelectChoises->mNextState = 0;
        gSelectChoises->mState0Requested = 0;
        return;
    }
    hit = -1;
    if (func_02127a84_inline2(inputSlotIndex) != 0) {
        if (func_02127a84_inline(touchX, touchY, gSelectChoisesHitRects[0].mUnk_00, gSelectChoisesHitRects[0].mUnk_01,
                                 gSelectChoisesHitRects[0].mUnk_02, gSelectChoisesHitRects[0].mUnk_03) != FALSE) {
            hit = 0;
        }
        if (func_02127a84_inline(touchX, touchY, gSelectChoisesHitRects[1].mUnk_00, gSelectChoisesHitRects[1].mUnk_01,
                                 gSelectChoisesHitRects[1].mUnk_02, gSelectChoisesHitRects[1].mUnk_03) != FALSE) {
            hit = 1;
        }
    }
    keys = data_02175628[inputSlotIndex].mPressedBits;
    if ((u16) (keys & PAD_KEY_A) != 0 || hit != -1) {
        if (hit == -1 || gSelectChoises->mIndex == hit) {
            func_02127d28();
        } else {
            gSelectChoises->mIndex = hit;
            RefreshAndQueueSelectChoises();
        }
        gSelectChoises->mNextState = 2;
        if (gSelectChoises->mDisplayBitOn != 0) {
            if (gSelectChoises->mSoundIds[gSelectChoises->mIndex] != -1) {
                StartSoundOncePerFrame((u16) gSelectChoises->mSoundIds[gSelectChoises->mIndex]);
            }
        }
    } else {
        if ((u16) (keys & PAD_KEY_B) != 0) {
            gSelectChoises->mIndexNone = 1;
            gSelectChoises->mState2Frames = 0xb;
            gSelectChoises->mNextState = 2;
            if (gSelectChoises->mDisplayBitOn != 0) {
                if (gSelectChoises->mIndexNoneSoundId != -1) {
                    StartSoundOncePerFrame((u16) gSelectChoises->mIndexNoneSoundId);
                }
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_UP) != 0 && gSelectChoises->mIndex == 1) {
            gSelectChoises->mIndex = 0;
            RefreshAndQueueSelectChoises();
            if (gSelectChoises->mDisplayBitOn != 0) {
                StartSoundOncePerFrame(0);
            }
            return;
        }
        if ((u16) (keys & PAD_KEY_DOWN) != 0 && gSelectChoises->mIndex == 0) {
            gSelectChoises->mIndex = 1;
            RefreshAndQueueSelectChoises();
            if (gSelectChoises->mDisplayBitOn != 0) {
                StartSoundOncePerFrame(0);
            }
        }
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectChoisesState2(void) {
    SelectChoises *selectChoises;
    int stateFrames;
    selectChoises = gSelectChoises;
    if (selectChoises->mState0Requested != 0) {
        selectChoises->mNextState = 0;
        gSelectChoises->mState0Requested = 0;
        return;
    }
    selectChoises->mState2Frames = selectChoises->mState2Frames + 1;
    stateFrames = gSelectChoises->mState2Frames;
    if (15 <= stateFrames) {
        gSelectChoises->mDone = 1;
        gSelectChoises->mState2Frames = 0xf;
        return;
    }
    if (5 <= stateFrames) {
        RefreshAndQueueSelectChoises();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectChoises(void) {
    if (gSelectChoises->mEnabled != 0) {
        gSelectChoises->mState = gSelectChoises->mNextState;
        switch (gSelectChoises->mState) {
            case 0:
                AdvanceSelectChoisesState0();
                break;
            case 1:
                AdvanceSelectChoisesState1();
                break;
            case 2:
                AdvanceSelectChoisesState2();
                break;
        }
        gSelectChoises->mToggleFrames++;
        if ((gSelectChoises->mToggleOn != 0 && gSelectChoises->mToggleFrames > 0x1e) ||
            (gSelectChoises->mToggleOn == 0 && gSelectChoises->mToggleFrames > 0x14)) {
            gSelectChoises->mToggleOn = gSelectChoises->mToggleOn == 0;
            gSelectChoises->mToggleFrames = 0;
            RefreshSelectChoisesNscrCopy();
            if (*(vu16 *) 0x27ffc40 != 2) {
                CallQueueAppend(0x18, 0, gSelectChoises->mNscrCopy, 0x800);
            }
        }
    }
}

void WriteSelectChoisesRegisters(void) {
    u32 subDisplayBits;

    if (gSelectChoises->mEnabled != 0) {
        reg_G2S_DB_BG0OFS = 0;
        if (gSelectChoises->mState == 0 || gSelectChoises->mDisplayBitOn == 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, 0);
            subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits & ~1) << 8);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, -10);
            subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 1) << 8);
        }
    }
}

void RequestSelectChoisesState1(void) {
    if ((gSelectChoises->mState == 0 && gSelectChoises->mState1Requested != 0) || gSelectChoises->mState == 1) {
        gSelectChoises->mState0Requested = 1;
    } else {
        gSelectChoises->mState0Requested = 0;
    }
    gSelectChoises->mState1Requested = 1;
}

void StartSelectChoises(void *firstText, void *secondText, s32 startOnSecond) {
    CharCanvas *charCanvas;

    charCanvas = &gSelectChoises->mCharCanvases[0];
    charCanvas->mUnk_18(charCanvas, 5);
    charCanvas = &gSelectChoises->mCharCanvases[1];
    charCanvas->mUnk_18(charCanvas, 5);
    func_0212583c(&gSelectChoises->mUnk_874[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, firstText);
    func_0212583c(&gSelectChoises->mUnk_874[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, secondText);
    ClearSelectChoisesUseCharBuffers();
    gSelectChoises->mUseCharBuffers = 1;
    RequestSelectChoisesState1();
    if (startOnSecond == 0) {
        gSelectChoises->mIndex = 0;
    } else {
        gSelectChoises->mIndex = 1;
    }
    RefreshAndQueueSelectChoises();
    gSelectChoises->mDone = 0;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
}

void RequestSelectChoisesState0(void) {
    gSelectChoises->mState1Requested = 0;
    gSelectChoises->mState0Requested = 1;
}

u32 IsSelectChoisesState1NoState0Request(void) {
    u32 result;

    result = 0;
    if (gSelectChoises->mState == 1 && gSelectChoises->mState0Requested == 0) {
        result = 1;
    }
    return result;
}

s32 IsSelectChoisesState0NoState1Request(void) {
    BOOL result;

    result = FALSE;
    if (gSelectChoises->mState == 0 && gSelectChoises->mState1Requested == 0) {
        result = TRUE;
    }
    return result;
}
#pragma thumb off

#pragma thumb on

s32 GetSelectChoisesIndex(void) {
    if (gSelectChoises->mIndexNone != 0) {
        return 0xffffffff;
    }
    return gSelectChoises->mIndex;
}

u32 GetSelectChoisesDone(void) {
    return gSelectChoises->mDone;
}

void SetSelectChoisesSoundId(int choiceIndex, u32 soundId) {
    if (choiceIndex == -1) {
        gSelectChoises->mIndexNoneSoundId = soundId;
        return;
    }
    gSelectChoises->mSoundIds[choiceIndex] = soundId;
}

#pragma thumb off
