#include "Main/Unknown/code_020aa81c.h"

#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020ab660.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02167000.h"
#include "g2d_CharCanvas.h"
#include "code_0214d018.h"
#include "tp.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ab72c.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9ed8.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_020aba9c.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020aa810.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "registers.h"

#pragma thumb on

void SplitBytesIntoNibbles(u8 *v1, u8 *v2, s32 n) {
    s32 i;
    s32 v3;

    v3 = n * n / 2;
    for (i = 0; i < v3; i++) {
        v2[i * 2] = v1[i] & 0xf;
        v2[i * 2 + 1] = (v1[i] >> 4) & 0xf;
    }
}

s32 GetKeyboardLastCharIndex(void) {
    s32 r;
    KeyboardTextEntry *d;
    s32 i;
    s32 j;

    r = 0;
    d = gKeyboardTextEntry;
    i = d->mTextIndex;
    j = d->mTextLimit - 1;
    if (i == j && d->mText[i] >= 0x20) {
        r = i;
    } else {
        j = i - 1;
        if (j >= 0 && d->mText[j] >= 0x20) {
            r = j;
        }
    }
    return r;
}

s32 KeyboardKeyCallback(u32 a, s32 b) {
    s32 r;
    s32 i;
    u16 v;
    u16 w;

    r = 0;
    i = GetKeyboardLastCharIndex();
    switch ((s32) a) {
        case 6:
            if (GetKeyboardChosenKeyValue() != 6) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e7);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 7:
            if (GetKeyboardChosenKeyValue() != 7) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e8);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x10:
            v = ConvertCharPair1(gKeyboardTextEntry->mText[i]);
            w = gKeyboardTextEntry->mText[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x11:
            v = ConvertCharPair2(gKeyboardTextEntry->mText[i]);
            w = gKeyboardTextEntry->mText[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 0x12:
            v = ConvertCharPair3(gKeyboardTextEntry->mText[i]);
            w = gKeyboardTextEntry->mText[i];
            if (w == v) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1ed);
                r = 3;
            }
            break;
        case 4:
        case 5:
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1eb);
            break;
        case 0x20:
        case 0x3000:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ea);
            }
            break;
        case 8:
            if (b != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, r, 0x1e9);
            }
            break;
        default:
            if (b != 0 && a >= 0x20) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e6);
            }
            break;
    }
    return r;
}

u16 KeyboardCursorCallback(s32 a, u16 b) {
    u16 r;

    r = 0;
    switch (a) {
        case 1:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 2;
            } else if ((b & 0x40) != 0) {
                r = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUnk_00;
            } else if ((b & 0x80) != 0) {
                r = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUnk_02;
            }
            break;
        case 2:
            if ((b & 0x20) != 0 || (b & 0x10) != 0) {
                r = 1;
            } else if ((b & 0x40) != 0) {
                r = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUnk_04;
            } else if ((b & 0x80) != 0) {
                r = data_02156808[gKeyboardTextEntry->mLayoutIndex].mUnk_06;
            }
            break;
    }
    StartSoundOncePerFrame(0x1e4);
    return r;
}

void InitKeyboardTextEntry(s32 a, s32 b, s32 c) {
    KeyboardTextEntry *p;

    gKeyboardTextEntry = HeapAlloc(GetHeap(func_020364e8()), 0x78);
    gKeyboardTextEntry->mTextCapacity = c;
    gKeyboardTextEntry->mTextLimit = c;
    gKeyboardTextEntry->mTextIndex = 0;
    gKeyboardTextEntry->mUnk_48 = 0;
    gKeyboardTextEntry->mText = HeapAlloc(GetHeap(func_020364e8()), (c + 1) * 2);
    gKeyboardTextEntry->mBg2ScrSize = b * (a * 2);
    gKeyboardTextEntry->mBg2Scr = HeapAlloc(GetHeap(func_020364e8()), gKeyboardTextEntry->mBg2ScrSize);
    gKeyboardTextEntry->mBg2CharSize = 0x4020;
    gKeyboardTextEntry->mBg2Char = HeapAllocAligned(GetHeap(func_020364e8()), gKeyboardTextEntry->mBg2CharSize, 0x20);
    p = gKeyboardTextEntry;
    InitKeyboardKeysAndCanvas(func_020b403c(0), p->mBg2Char, p->mBg2Scr, a, b, 0);
    SetKeyboardCursorCallback(KeyboardCursorCallback);
    SetKeyboardKeyCallback(KeyboardKeyCallback);
    func_020ab07c(0);
    func_020ab070(1);
    gKeyboardTextEntry->mOffsetX = 0;
    gKeyboardTextEntry->mOffsetY = 0;
    gKeyboardTextEntry->mButton0X0 = 0x23;
    gKeyboardTextEntry->mButton0Y0 = 0x7a;
    gKeyboardTextEntry->mButton0X1 = 0x7d;
    gKeyboardTextEntry->mButton0Y1 = 0x8e;
    gKeyboardTextEntry->mButton1X0 = 0x83;
    gKeyboardTextEntry->mButton1Y0 = 0x7a;
    gKeyboardTextEntry->mButton1X1 = 0xdd;
    gKeyboardTextEntry->mButton1Y1 = 0x8e;
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[0], FindSceneFile(data_02167bf4));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[2], FindSceneFile(data_02167c0c));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[1], FindSceneFile(data_02167c24));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[3], FindSceneFile(data_02167c3c));
    LoadNcgrData2(&gKeyboardTextEntry->mNcgrs[4], FindSceneFile(data_02167c54));
    LocateNcgr2(&gKeyboardTextEntry->mUnk_24, FindSceneFile(data_02167c6c));
    gKeyboardTextEntry->mKbds[0] = FindSceneFile(data_02167c84);
    gKeyboardTextEntry->mKbds[2] = FindSceneFile(data_02167c90);
    gKeyboardTextEntry->mKbds[1] = FindSceneFile(data_02167c9c);
    gKeyboardTextEntry->mKbds[3] = FindSceneFile(data_02167ca4);
    gKeyboardTextEntry->mKbds[4] = FindSceneFile(data_02167cb0);
    gKeyboardTextEntry->mKbds[5] = FindSceneFile(data_02167cbc);
    gKbdmapAscii = FindSceneFile(data_02167cc8);
    gKbdmapAsciiCaps = FindSceneFile(data_02167cd8);
    gKbdmapAsciiShift = FindSceneFile(data_02167cec);
    gKbdmapHiragana = FindSceneFile(data_02167d00);
    gKbdmapHiraganaDakuten = FindSceneFile(data_02167d10);
    gKbdmapHiraganaHandaku = FindSceneFile(data_02167d28);
    gKbdmapHiraganaSmall = FindSceneFile(data_02167d40);
    gKbdmapKatakana = FindSceneFile(data_02167d58);
    gKbdmapKatakanaDakuten = FindSceneFile(data_02167d68);
    gKbdmapKatakanaHandaku = FindSceneFile(data_02167d80);
    gKbdmapKatakanaSmall = FindSceneFile(data_02167d98);
    gKbdmapOther1 = FindSceneFile(data_02167db0);
    gKbdmapOther2 = FindSceneFile(data_02167dc0);
    gKbdmapOther3 = FindSceneFile(data_02167dd0);
    SetupKeyboardInputMasks(1, 2, 0x400);
}

void AdvanceKeyboardTextEntry(void) {
    s32 i;
    Unk02175628Index v1;
    KeyboardTextEntry *q;
    u16 v;

    i = GetKeyboardLastCharIndex();
    PollKeyboard();
    GetKeyboardKeyValue();
    v1 = UNK_02175628_INDEX_8;
    if ((u16) (data_02175628[v1].mUnk_00 & 8) != 0) {
        if (GetKeyboardCursorValueWrapper() != 1) {
            MoveKeyboardCursorToValueWrapper(1);
        }
    } else if (GetKeyboardKeyValue() == 8) {
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        q = gKeyboardTextEntry;
        if (q->mTextIndex != 0) {
            if (q->mText[q->mTextIndex] == 0) {
                q->mTextIndex--;
            }
            gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex] = 0;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e3);
        }
    } else if (GetKeyboardKeyValue() >= 0x20) {
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        q = gKeyboardTextEntry;
        if (q->mTextIndex < q->mTextLimit) {
            if (q->mText[q->mTextIndex] != GetKeyboardKeyValue()) {
                q = gKeyboardTextEntry;
                q->mText[q->mTextIndex] = GetKeyboardKeyValue();
                gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextIndex + 1] = 0;
                if (gKeyboardTextEntry->mTextIndex < gKeyboardTextEntry->mTextLimit - 1) {
                    gKeyboardTextEntry->mTextIndex++;
                }
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e2);
            }
        }
    } else if (GetKeyboardKeyValue() == 0x10) {
        v = ConvertCharPair1(gKeyboardTextEntry->mText[i]);
        if (v != gKeyboardTextEntry->mText[i]) {
            gKeyboardTextEntry->mText[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x11) {
        v = ConvertCharPair2(gKeyboardTextEntry->mText[i]);
        if (v != gKeyboardTextEntry->mText[i]) {
            gKeyboardTextEntry->mText[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x12) {
        v = ConvertCharPair3(gKeyboardTextEntry->mText[i]);
        if (v != gKeyboardTextEntry->mText[i]) {
            gKeyboardTextEntry->mText[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        }
    } else if (GetKeyboardKeyValue() == 0x13) {
        v = CycleCharTables(gKeyboardTextEntry->mText[i]);
        if (v != gKeyboardTextEntry->mText[i]) {
            gKeyboardTextEntry->mText[i] = v;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ec);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ed);
        }
    }
    GetKeyboardKeyValue();
}

#pragma thumb off

#pragma thumb on

void UploadKeyboardBg2Data(void) {
    DC_FlushRange(gKeyboardTextEntry->mBg2Scr, gKeyboardTextEntry->mBg2ScrSize);
    GXS_LoadBG2Scr(gKeyboardTextEntry->mBg2Scr, 0, gKeyboardTextEntry->mBg2ScrSize);
    DC_FlushRange(gKeyboardTextEntry->mBg2Char, gKeyboardTextEntry->mBg2CharSize);
    GXS_LoadBG2Char(gKeyboardTextEntry->mBg2Char, 0, gKeyboardTextEntry->mBg2CharSize);
}

#pragma thumb off

#pragma thumb on
void func_020aba94(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    func_020ab07c(value0);
}
#pragma thumb off

#pragma thumb on

void SelectKeyboardLayout(u32 a) {
    switch (a) {
        case 0:
            SetupKeyboardLayoutOther3(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                      gKeyboardLayoutRectCounts[a]);
            break;
        case 1:
            SetupKeyboardLayoutHiragana(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                        gKeyboardLayoutRectCounts[a]);
            break;
        case 2:
            SetupKeyboardLayoutAscii(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                     gKeyboardLayoutRectCounts[a]);
            break;
        case 3:
            SetupKeyboardLayoutOther1(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                      gKeyboardLayoutRectCounts[a]);
            break;
        case 4:
            SetupKeyboardLayoutOther2(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                      gKeyboardLayoutRectCounts[a]);
            break;
        case 5:
            SetupKeyboardLayoutOther3(gKeyboardTextEntry->mKbds[a], gKeyboardTextEntry->mNcgrs[a],
                                      gKeyboardLayoutRectCounts[a]);
            break;
    }
    gKeyboardTextEntry->mLayoutIndex = a;
}

void SetKeyboardOffset(s32 a, s32 b) {
    gKeyboardTextEntry->mOffsetX = a;
    gKeyboardTextEntry->mOffsetY = b;
    StoreKeyboardOffset(gKeyboardTextEntry->mOffsetX, gKeyboardTextEntry->mOffsetY);
    reg_G2S_DB_BG2OFS = (-gKeyboardTextEntry->mOffsetX & 0x1ff) | ((-gKeyboardTextEntry->mOffsetY << 16) & 0x1ff0000);
    SetKeyboardButton0Rect(gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton0X0,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton0Y0,
                           gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton0X1,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton0Y1);
    SetKeyboardButton1Rect(gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton1X0,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton1Y0,
                           gKeyboardTextEntry->mOffsetX + gKeyboardTextEntry->mButton1X1,
                           gKeyboardTextEntry->mOffsetY + gKeyboardTextEntry->mButton1Y1);
}

#pragma thumb off

#pragma thumb on

void SetKeyboardButton0Corners(u32 a, u32 b, u32 c, u32 d) {
    KeyboardTextEntry **v1;
    KeyboardTextEntry *v2;
    v1 = &gKeyboardTextEntry;
    gKeyboardTextEntry->mButton0X0 = a;
    (*v1)->mButton0Y0 = b;
    (*v1)->mButton0X1 = c;
    (*v1)->mButton0Y1 = d;
    v2 = *v1;
    SetKeyboardButton0Rect(v2->mOffsetX + v2->mButton0X0, v2->mOffsetY + v2->mButton0Y0, v2->mOffsetX + v2->mButton0X1,
                           v2->mOffsetY + v2->mButton0Y1);
}

void SetKeyboardButton1Corners(u32 a, u32 b, u32 c, u32 d) {
    KeyboardTextEntry **v1;
    KeyboardTextEntry *v2;
    v1 = &gKeyboardTextEntry;
    gKeyboardTextEntry->mButton1X0 = a;
    (*v1)->mButton1Y0 = b;
    (*v1)->mButton1X1 = c;
    (*v1)->mButton1Y1 = d;
    v2 = *v1;
    SetKeyboardButton1Rect(v2->mOffsetX + v2->mButton1X0, v2->mOffsetY + v2->mButton1Y0, v2->mOffsetX + v2->mButton1X1,
                           v2->mOffsetY + v2->mButton1Y1);
}

#pragma thumb off

#pragma thumb on

void MoveKeyboardCursorToValueWrapper(u16 a) {
    MoveKeyboardCursorToValue(a);
}

u32 GetKeyboardCursorValueWrapper(void) {
    return GetKeyboardCursorValue();
}

#pragma thumb off

#pragma thumb on

void GetKeyboardCursorBoundsRelative(s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 value;
    GetKeyboardCursorRectBounds(a, b, c, d);
    *a = *a - gKeyboardTextEntry->mOffsetX;
    *b = *b - gKeyboardTextEntry->mOffsetY;
    *c = *c - gKeyboardTextEntry->mOffsetX;
    *d = *d - gKeyboardTextEntry->mOffsetY;
    value = *a;
    if (value < 0) {
        value += 0x100;
    }
    *a = value;
    value = *b;
    if (value < 0) {
        value += 0x100;
    }
    *b = value;
    value = *c;
    if (value < 0) {
        value += 0x100;
    }
    *c = value;
    value = *d;
    if (value < 0) {
        value += 0x100;
    }
    *d = value;
}

#pragma thumb off

#pragma thumb on

void SetKeyboardText(const u16 *a) {
    s32 i;

    for (i = 0; i < gKeyboardTextEntry->mTextCapacity; i++) {
        gKeyboardTextEntry->mText[i] = 0;
    }
    for (i = 0; i < gKeyboardTextEntry->mTextLimit; i++) {
        gKeyboardTextEntry->mText[i] = *a;
        if (*a == 0) {
            gKeyboardTextEntry->mTextIndex = i;
            gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
            return;
        }
        a++;
    }
    gKeyboardTextEntry->mTextIndex = gKeyboardTextEntry->mTextLimit - 1;
    gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
    gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextLimit] = 0;
}

#pragma thumb off

#pragma thumb on

u16 *GetKeyboardText(void) {
    return gKeyboardTextEntry->mText;
}

#pragma thumb off

#pragma thumb on

void SetKeyboardTextLimit(u16 a) {
    gKeyboardTextEntry->mTextLimit = a;
    if (gKeyboardTextEntry->mTextIndex >= gKeyboardTextEntry->mTextLimit - 1) {
        gKeyboardTextEntry->mTextIndex = gKeyboardTextEntry->mTextLimit - 1;
        gKeyboardTextEntry->mUnk_48 = gKeyboardTextEntry->mTextIndex;
        gKeyboardTextEntry->mText[gKeyboardTextEntry->mTextLimit] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u16 GetKeyboardTextIndex(void) {
    return gKeyboardTextEntry->mTextIndex;
}

#pragma thumb off

#pragma thumb on

void ClearKeyboardInput(void) {
    MemFillWordsByBlock_inline(&gKeyboardInput, 0x28);
}

#pragma thumb off

#pragma thumb on

void InitKeyboardInput(void) {
    ClearKeyboardInput();
    gKeyboardInput.mTouchEnabled = TRUE;
}

#pragma thumb off

#pragma thumb on

void AdvanceKeyboardInput(u16 a, volatile TPData b) {
    u32 t;
    u16 v;

    t = a ^ gKeyboardInput.mKeysDown;
    gKeyboardInput.mKeysPressed = a & t;
    gKeyboardInput.mKeysReleased = ~a & t;
    gKeyboardInput.mKeysDown = a;
    if ((gKeyboardInput.mKeysDown & gKeyboardInput.mUnk_0a) != 0) {
        gKeyboardInput.mUnk_00++;
    } else {
        gKeyboardInput.mUnk_00 = 0;
    }
    if (gKeyboardInput.mTouchEnabled != FALSE) {
        if (b.mValidity != 0) {
            b.mX = gKeyboardInput.mPrevSample[0];
            b.mY = gKeyboardInput.mPrevSample[1];
            b.mTouch = gKeyboardInput.mPrevSample[2];
            b.mValidity = gKeyboardInput.mPrevSample[3];
            b.mTouch = 0;
        }
        v = b.mTouch;
        if (v != gKeyboardInput.mPrevSample[2]) {
            gKeyboardInput.mTouchStatus = v != 0 ? 1 : 3;
            gKeyboardInput.mUnk_18 = 0;
        } else if (v != 0) {
            gKeyboardInput.mTouchStatus = 2;
            gKeyboardInput.mUnk_18++;
        } else {
            gKeyboardInput.mTouchStatus = 0;
        }
        if (v != 0) {
            gKeyboardInput.mLastTouchX = b.mX;
            gKeyboardInput.mLastTouchY = b.mY;
        }
        gKeyboardInput.mTouchDown = v;
        gKeyboardInput.mPrevSample[0] = b.mX;
        gKeyboardInput.mPrevSample[1] = b.mY;
        gKeyboardInput.mPrevSample[2] = b.mTouch;
        gKeyboardInput.mPrevSample[3] = b.mValidity;
    }
}

#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeysPressed(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = gKeyboardInput.mKeysPressed;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardKeysDown(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = gKeyboardInput.mKeysDown;
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardTouchDown(void) {
    u32 value0;
    value0 = gKeyboardInput.mTouchDown;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardTouchStatus(void) {
    u32 value0;
    value0 = gKeyboardInput.mTouchStatus;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardLastTouchX(void) {
    u32 value0;
    value0 = gKeyboardInput.mLastTouchX;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardLastTouchY(void) {
    u32 value0;
    value0 = gKeyboardInput.mLastTouchY;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 IsKeyboardTouchEnabled(void) {
    u32 value0;
    value0 = gKeyboardInput.mTouchEnabled;
    return value0;
}
#pragma thumb off

#pragma thumb on

void SetupRepeatCounterDefault(RepeatCounter *p0) {
    p0->mRepeatFrames = 0x0u;
    p0->mUnk_06 = 0x0u;
    p0->mFirstFireFrame = 0x28u;
    p0->mRepeatFireFrame = 0x2du;
}

void SetupRepeatCounter(RepeatCounter *p0, u32 p1, u32 p2) {
    p0->mRepeatFrames = 0x0u;
    p0->mUnk_06 = 0x0u;
    p0->mFirstFireFrame = p1;
    p0->mRepeatFireFrame = ((p1) + (p2));
}

#pragma thumb off

#pragma thumb on

void AdvanceRepeatCounter(RepeatCounter *p) {
    p->mRepeatFrames = p->mRepeatFrames + 1;
    if (p->mRepeatFrames == p->mFirstFireFrame || p->mRepeatFrames == p->mRepeatFireFrame) {
        p->mUnk_06 = 1;
    }
    if (p->mRepeatFrames > p->mRepeatFireFrame) {
        p->mRepeatFrames = p->mFirstFireFrame + 1;
    }
}

#pragma thumb off

#pragma thumb on

void ResetRepeatCounter(RepeatCounter *p0) {
    p0->mRepeatFrames = 0x0u;
    p0->mUnk_06 = 0x0u;
}

#pragma thumb off

#pragma thumb on

BOOL IsRepeatCounterFiring(RepeatCounter *p) {
    if (p->mRepeatFrames == p->mFirstFireFrame || p->mRepeatFrames == p->mRepeatFireFrame) {
        return TRUE;
    }
    return FALSE;
}

void SetupKeyboardKeyRepeat(u16 a) {
    SetupRepeatCounterDefault(&gKeyboardKeyRepeat.mCounter);
    gKeyboardKeyRepeat.mKeyMask = a;
    gKeyboardKeyRepeat.mRepeatKeys = 0;
}

void AdvanceKeyboardKeyRepeat(void) {
    if (gKeyboardKeyRepeat.mRepeatKeys == 0 && GetKeyboardKeysPressed(gKeyboardKeyRepeat.mKeyMask) != 0) {
        gKeyboardKeyRepeat.mRepeatKeys = GetKeyboardKeysPressed(gKeyboardKeyRepeat.mKeyMask);
        return;
    }
    if (GetKeyboardKeysDown(gKeyboardKeyRepeat.mRepeatKeys) != 0) {
        AdvanceRepeatCounter(&gKeyboardKeyRepeat.mCounter);
    } else {
        ResetRepeatCounter(&gKeyboardKeyRepeat.mCounter);
        gKeyboardKeyRepeat.mRepeatKeys = 0;
    }
}

u16 GetKeyboardRepeatedKeys(void) {
    u32 v;

    if (IsRepeatCounterFiring(&gKeyboardKeyRepeat.mCounter) != FALSE) {
        v = GetKeyboardKeysDown(gKeyboardKeyRepeat.mRepeatKeys);
    } else {
        v = 0;
    }
    return v;
}

u16 GetKeyboardKeysPressedOrRepeated(void) {
    if (GetKeyboardKeysPressed(0x2fff) != 0) {
        return GetKeyboardKeysPressed(0x2fff);
    }
    return GetKeyboardRepeatedKeys();
}

void AsciiLayoutCallback(KeyboardKeys *p) {
    switch (p->mKeyId) {
        case 4:
            p->mToggledKeyId = p->mToggledKeyId != 4 ? 4 : 0;
            break;
        case 5:
            p->mToggledKeyId = p->mToggledKeyId != 5 ? 5 : 0;
            break;
    }
    switch (p->mToggledKeyId) {
        case 0:
            p->mCharMap = gKbdmapAscii + 1;
            break;
        case 4:
            p->mCharMap = gKbdmapAsciiShift + 1;
            break;
        case 5:
            p->mCharMap = gKbdmapAsciiCaps + 1;
            break;
    }
}

void HiraganaKatakanaLayoutCallback(KeyboardKeys *p) {
    switch (p->mKeyId) {
        case 4:
            p->mChosenKeyId = 4;
            p->mToggledKeyId = 0;
            break;
        case 5:
            p->mChosenKeyId = 5;
            p->mToggledKeyId = 0;
            break;
    }
    switch (p->mChosenKeyId) {
        case 4:
            if (p->mToggledKeyId == 0) {
                p->mCharMap = gKbdmapHiragana + 1;
            }
            break;
        case 5:
            if (p->mToggledKeyId == 0) {
                p->mCharMap = gKbdmapKatakana + 1;
            }
            break;
    }
}

KeyboardRect *FindKeyboardRectByValue(u16 a) {
    KeyboardRect *e;
    s32 i;
    u16 n;
    u16 c;
    u16 *w;

    if (gKeyboardKeys.mCurrentLayout != NULL) {
        e = gKeyboardKeys.mCurrentLayout->mRects;
        n = gKeyboardKeys.mCurrentLayout->mRectCount;
        c = gKeyboardKeys.mCurrentLayout->mFixedKeyCount;
        w = gKeyboardKeys.mCharMap;
        switch (a) {
            case 0:
                return NULL;
            case 1:
                return &gKeyboardKeys.mButton0Rect;
            case 2:
                return &gKeyboardKeys.mButton1Rect;
            case 8:
                return e;
            case 10:
                return e + 1;
            case 0x20:
            case 0x3000:
                return e + 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mWidth > 1 && e[i].mHeight > 1 && a == w[e[i].mKeyId - c - 1]) {
                return &e[i];
            }
        }
    }
    return NULL;
}

s32 GetKeyboardRectValue(KeyboardRect *p) {
    KeyboardRect *e;
    s32 i;
    s32 n;
    u16 c;
    u16 *w;

    if (gKeyboardKeys.mCurrentLayout != NULL) {
        e = gKeyboardKeys.mCurrentLayout->mRects;
        n = gKeyboardKeys.mCurrentLayout->mRectCount;
        c = gKeyboardKeys.mCurrentLayout->mFixedKeyCount;
        w = gKeyboardKeys.mCharMap;
        if (p == NULL) {
            return 0;
        }
        if (p == &gKeyboardKeys.mButton0Rect) {
            return 1;
        }
        if (p == &gKeyboardKeys.mButton1Rect) {
            return 2;
        }
        for (i = 0; i < n; i++) {
            if (e[i].mWidth > 1 && e[i].mHeight > 1 && p == &e[i]) {
                switch (i) {
                    case 0:
                        return 8;
                    case 1:
                        return 0xa;
                    case 2:
                        return 0x20;
                }
                return w[e[i].mKeyId - c - 1];
            }
        }
    }
    return 0;
}

s32 GetKeyboardValueForKeyId(u32 a) {
    KeyboardLayout *t;
    u16 c;

    t = gKeyboardKeys.mCurrentLayout;
    if (t != NULL) {
        if (a == 0) {
            return 0;
        }
        c = t->mFixedKeyCount;
        if (a <= c || a == 0xffff) {
            if (t->mCallback == HiraganaKatakanaLayoutCallback) {
                switch ((s32) a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x3000;
                    case 4:
                        return 6;
                    case 5:
                        return 7;
                    case 6:
                        return 0x10;
                    case 7:
                        return 0x11;
                    case 8:
                        return 0x12;
                    case 0xffff:
                        return 0x13;
                }
            } else {
                switch (a) {
                    case 1:
                        return 8;
                    case 2:
                        return 0xa;
                    case 3:
                        return 0x20;
                    case 4:
                        return 4;
                    case 5:
                        return 5;
                }
            }
        }
        if (a <= 0xff && gKeyboardKeys.mCharMap[a - c - 1] > 0x20) {
            return gKeyboardKeys.mCharMap[a - c - 1];
        }
    }
    return 0;
}

void SetupKeyboardInputMasks(u16 a, u16 b, u16 c) {
    gKeyboardInputMasks[0] = a;
    gKeyboardInputMasks[1] = b;
    gKeyboardInputMasks[2] = c;
    SetupKeyboardKeyRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
}

#pragma thumb off

#pragma thumb on
u32 StoreKeyboardOffset(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &gKeyboardOffsetX;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &gKeyboardOffsetY;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void GetKeyboardCursorRectBounds(s32 *a, s32 *b, s32 *c, s32 *d) {
    if (gKeyboardKeys.mCursorRect != NULL && a != NULL && b != NULL && c != NULL && d != NULL) {
        *a = gKeyboardKeys.mCursorRect->mX;
        *b = gKeyboardKeys.mCursorRect->mY;
        *c = gKeyboardKeys.mCursorRect->mX + gKeyboardKeys.mCursorRect->mWidth;
        *d = gKeyboardKeys.mCursorRect->mY + gKeyboardKeys.mCursorRect->mHeight;
        if (gKeyboardKeys.mCursorRect->mKeyId <= 0xff) {
            *a = *a + gKeyboardOffsetX;
            *b = *b + gKeyboardOffsetY;
            *c = *c + gKeyboardOffsetX;
            *d = *d + gKeyboardOffsetY;
        }
    }
}

void InitKeyboardKeysAndCanvas(struct Unk02022aa8 *a, void *b, u16 *c, s32 d, s32 e, s32 f) {
    MI_CpuFill8(&gKeyboardKeys, 0, 0x54);
    gKeyboardCanvas.mFont = a;
    gKeyboardCanvas.mBg2Char = b;
    gKeyboardCanvas.mUnk_08 = b;
    gKeyboardCanvas.mBg2Scr = c;
    gKeyboardCanvas.mUnk_10 = d;
    gKeyboardCanvas.mUnk_14 = e;
    gKeyboardCanvas.mUnk_1c = f;
    InitKeyboardInput();
    SetupRepeatCounter(&data_0217b2ac, 0x28, 5);
    SetupKeyboardKeyRepeat(gKeyboardInputMasks[2] | (gKeyboardInputMasks[0] | 0xf0 | gKeyboardInputMasks[1]));
    gCharTablePair1[0] = gCharTablePair2[0] = gCharTablePair3[0] = gCharTables[0];
    gCharTablePair1[1] = gCharTables[1];
    gCharTablePair2[1] = gCharTables[2];
    gCharTablePair3[1] = gCharTables[3];
}

#pragma thumb off

#pragma thumb on
void func_020ab07c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gKeyboardCanvas.mUnk_18 = value0;
}
#pragma thumb off

#pragma thumb on
void func_020ab070(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gKeyboardCanvas.mUnk_20 = value0;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gKeyboardKeys;
    *(u32 *) ((value1) + 76u) = value0;
}
#pragma thumb off

#pragma thumb on
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gKeyboardKeys;
    *(u32 *) ((value1) + 80u) = value0;
}
#pragma thumb off

#pragma thumb on

void CallKeyboardKeyCallback(s32 a) {
    if (gKeyboardKeys.mKeyCallback != NULL) {
        if (gKeyboardKeys.mKeyCallback(GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId), a) != 0) {
            gKeyboardKeys.mKeyId = 0;
        }
    }
}

void FillKeyboardBg2Scr(KeyboardKeys *a) {
    s32 w;
    s32 h;
    s32 i;
    s32 v1;
    BOOL j0;
    s32 j;
    volatile u16 n;

    h = a->mCurrentLayout->mNcgr->mUnk_02;
    w = a->mCurrentLayout->mNcgr->mUnk_00;
    n = h * w;
    MIi_CpuClear16(n, gKeyboardCanvas.mBg2Scr, gKeyboardCanvas.mUnk_14 * (gKeyboardCanvas.mUnk_10 * 2));
    i = 0;
    v1 = 0;
    v1 = (u32) v1;
    j0 = FALSE;
    if (i < w) {
        v1 = 0;
        v1 = (u32) v1;
        do {
            for (j = j0; j < h; j++) {
                gKeyboardCanvas.mBg2Scr[j + i * gKeyboardCanvas.mUnk_14 / 2] =
                    (gKeyboardCanvas.mUnk_18 << 12) | (j + (gKeyboardCanvas.mUnk_1c + v1));
            }
            v1 += h;
            i++;
        } while (i < w);
    }
}

u16 FindFirstCharRectIndex(KeyboardLayout *a) {
    u16 i;
    const KeyboardLayout *p = a;

    for (i = 0; i < p->mRectCount; i++) {
        if (a->mFixedKeyCount + 1 == a->mRects[i].mKeyId) {
            return i;
        }
    }
    return 0;
}

KeyboardRect *FindKeyboardRectAt(KeyboardKeys *a, s32 b, s32 c) {
    KeyboardRect *e;
    KeyboardLayout *q;
    s32 n;
    KeyboardRect *t;
    s32 i;

    e = &a->mButton0Rect;
    if (e->mWidth > 1 && e->mHeight > 1 && e->mY <= c && c < e->mY + e->mHeight && e->mX <= b &&
        b < e->mX + e->mWidth) {
        return e;
    }
    e = &a->mButton1Rect;
    if (e->mWidth > 1 && e->mHeight > 1 && e->mY <= c && c < e->mY + e->mHeight && e->mX <= b &&
        b < e->mX + e->mWidth) {
        return e;
    }
    q = a->mCurrentLayout;
    t = q->mRects;
    n = q->mRectCount;
    for (i = 0; i < n; i++) {
        if (t[i].mWidth > 1 && t[i].mHeight > 1 && gKeyboardOffsetY + t[i].mY <= c &&
            c < gKeyboardOffsetY + (t[i].mY + t[i].mHeight) && gKeyboardOffsetX + t[i].mX <= b &&
            b < gKeyboardOffsetX + (t[i].mX + t[i].mWidth)) {
            return &t[i];
        }
    }
    return NULL;
}

void DrawKeyboardGlyphs(KeyboardKeys *a) {
    Unk02022aa8 *f;
    KeyboardRect *e;
    Unk02022ce4_08 *u;
    NNSG2dCharWidths *t;
    NNSG2dGlyph v1;
    Unk02023374 v2;
    s32 c;
    KeyboardLayout *q;
    u32 g;
    s32 v;
    s32 n;
    s32 j;
    s32 h;
    s32 i;
    s32 k;

    f = gKeyboardCanvas.mFont;
    c = f->mUnk_00->mUnk_08->mUnk_01;
    q = a->mCurrentLayout;
    MIi_CpuCopyFast(q->mNcgr->mData, gKeyboardCanvas.mBg2Char, q->mNcgr->mDataSize);
    NNS_G2dCharCanvasInitForBG(&v2, gKeyboardCanvas.mBg2Char, q->mNcgr->mUnk_02, q->mNcgr->mUnk_00, 4);
    n = FindFirstCharRectIndex(q);
    i = 0;
    if (q->mRectCount - n > 0) {
        j = 0;
        k = n;
        do {
            e = &q->mRects[(u32) n];
            g = *OFFSET_PTR(u16, a->mCharMap, j);
            if (e->mWidth > 1 && e->mHeight > 1) {
                v = NNS_G2dFontFindGlyphIndex(f, g);
                if (v == 0xffff) {
                    v = f->mUnk_00->mUnk_02;
                }
                t = NNS_G2dFontGetCharWidthsFromIndex(f, v);
                v1.mPWidths = t;
                u = f->mUnk_00->mUnk_08;
                v1.mImage = u->mUnk_08 + v * u->mUnk_02;
                h = (e->mWidth - t->mGlyphWidth) / 2;
                v2.mUnk_14(&v2, f, e->mX + h, e->mY + (e->mHeight - c) / 2, gKeyboardCanvas.mUnk_20, &v1);
            }
            n++;
            j += 2;
            i++;
        } while (i < q->mRectCount - k);
    }
}

void MarkKeyboardRects(KeyboardKeys *a) {
    KeyboardLayout *q;
    KeyboardRect *e;
    KeyboardRect *r;

    q = a->mCurrentLayout;
    MIi_CpuCopyFast(gKeyboardCanvas.mBg2Char, gKeyboardCanvas.mUnk_08, q->mNcgr->mDataSize);
    MemFillWordsByBlock_inline((u8 *) gKeyboardCanvas.mUnk_08 + (q->mNcgr->mDataSize << 5), 0x20);
    if (a->mChosenKeyId != 0) {
        e = q->mRects + (a->mChosenKeyId - 1);
        r = e;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    if (a->mToggledKeyId != 0) {
        e = q->mRects + (a->mToggledKeyId - 1);
        r = e;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = a->mCursorRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0] && e != a->mTouchStartRect && e != a->mKeyDownRect) {
        r = e;
        do {
            AddToNonzeroNibblesOnRectEdge(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = a->mKeyDownRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0]) {
        r = e;
        do {
            AddToNonzeroNibblesInRect(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                      r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
    e = a->mTouchStartRect;
    if (e != NULL && e->mKeyId != 0 && e->mKeyId <= 0xff && e->mKeyId != data_0217b2b8[1] &&
        e->mKeyId != data_0217b2b8[0] && e != a->mKeyDownRect) {
        if (a->mTouchRect != NULL && e->mKeyId == a->mTouchRect->mKeyId) {
            r = e;
            do {
                AddToNonzeroNibblesInRect(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
                r += r->mNextRectOffset;
            } while (r != e);
            return;
        }
        r = e;
        do {
            AddToNonzeroNibblesOnRectEdge(gKeyboardCanvas.mUnk_08, gKeyboardKeys.mCurrentLayout->mNcgr->mUnk_02 << 3, 8,
                                          r->mX, r->mY, r->mX + r->mWidth, r->mY + r->mHeight);
            r += r->mNextRectOffset;
        } while (r != e);
    }
}

u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *a) {
    u32 r;
    u32 b;
    KeyboardRect *p;

    r = 0;
    b = 0;
    p = a->mTouchStartRect;
    if (p != NULL && a->mTouchRect != NULL) {
        b = 1;
    }
    if (b != 0) {
        if (a->mTouchRect->mKeyId == p->mKeyId) {
            r = 1;
        }
    }
    return r;
}

void AdvanceKeyboardKeys(u16 a, TPData b) {
    u16 h;
    u16 k;
    void (*fn)(KeyboardKeys *);

    AdvanceKeyboardInput(a, b);
    AdvanceKeyboardKeyRepeat();
    gKeyboardKeys.mKeyId = 0;
    gKeyboardKeys.mKeyValue = 0;
    if (gKeyboardKeys.mCurrentLayout != NULL && gKeyboardKeys.mCharMap != NULL) {
        if (GetKeyboardKeysDown(gKeyboardInputMasks[0]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCursorRect;
        } else if (GetKeyboardKeysDown(gKeyboardInputMasks[1]) != 0) {
            gKeyboardKeys.mKeyDownRect = gKeyboardKeys.mCurrentLayout->mRects;
        } else {
            gKeyboardKeys.mKeyDownRect = NULL;
        }
        k = gKeyboardInputMasks[0];
        if ((GetKeyboardKeysPressedOrRepeated() & k) != 0) {
            gKeyboardKeys.mKeyId = gKeyboardKeys.mCursorRect->mKeyId;
            CallKeyboardKeyCallback(GetKeyboardKeysPressed(k));
        } else {
            k = gKeyboardInputMasks[1];
            if ((GetKeyboardKeysPressedOrRepeated() & k) != 0) {
                gKeyboardKeys.mKeyId = 1;
                CallKeyboardKeyCallback(GetKeyboardKeysPressed(k));
            } else {
                k = gKeyboardInputMasks[2];
                if ((GetKeyboardKeysPressedOrRepeated() & k) != 0) {
                    fn = gKeyboardKeys.mCurrentLayout->mCallback;
                    if (fn == AsciiLayoutCallback) {
                        h = data_0217b2b8[1];
                        if (h == 0) {
                            gKeyboardKeys.mKeyId = 4;
                        } else if (h == 4) {
                            gKeyboardKeys.mKeyId = 5;
                        } else if (h == 5) {
                            gKeyboardKeys.mKeyId = 5;
                        }
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(k));
                    } else if (fn == HiraganaKatakanaLayoutCallback) {
                        gKeyboardKeys.mKeyId = 0xffff;
                        CallKeyboardKeyCallback(GetKeyboardKeysPressed(k));
                    }
                }
            }
        }
        if ((GetKeyboardKeysPressedOrRepeated() & 0x40) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x40, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x80) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x80, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x20) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x20, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        } else if ((GetKeyboardKeysPressedOrRepeated() & 0x10) != 0) {
            gKeyboardKeys.mCursorRect =
                FindKeyboardRectInDirection(0x10, gKeyboardKeys.mCursorRect, gKeyboardKeys.mCurrentLayout->mRects);
        }
        if (GetKeyboardTouchDown() != 0) {
            gKeyboardKeys.mTouchRect =
                FindKeyboardRectAt(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
        }
        if (GetKeyboardTouchStatus() == 1) {
            gKeyboardKeys.mTouchStartRect =
                FindKeyboardRectAt(&gKeyboardKeys, GetKeyboardLastTouchX(), GetKeyboardLastTouchY());
            if (gKeyboardKeys.mTouchStartRect != NULL) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(1);
            }
        } else if (GetKeyboardTouchStatus() == 3) {
            gKeyboardKeys.mTouchStartRect = NULL;
        }
        if (IsKeyboardTouchOnStartKeyId(&gKeyboardKeys) != 0) {
            AdvanceRepeatCounter(&data_0217b2ac);
            if (IsRepeatCounterFiring(&data_0217b2ac) != FALSE) {
                gKeyboardKeys.mKeyId = gKeyboardKeys.mTouchStartRect->mKeyId;
                CallKeyboardKeyCallback(0);
            }
        } else {
            ResetRepeatCounter(&data_0217b2ac);
        }
        gKeyboardKeys.mKeyValue = GetKeyboardValueForKeyId(gKeyboardKeys.mKeyId);
        if (gKeyboardKeys.mKeyValue >= 0x20) {
            fn = gKeyboardKeys.mCurrentLayout->mCallback;
            if (fn == AsciiLayoutCallback) {
                if (data_0217b2b8[1] == 4) {
                    data_0217b2b8[1] = 0;
                }
            } else if (fn == HiraganaKatakanaLayoutCallback) {
                data_0217b2b8[1] = 0;
            }
        }
        if (gKeyboardKeys.mKeyId != 0 && gKeyboardKeys.mCurrentLayout->mCallback != NULL) {
            gKeyboardKeys.mCurrentLayout->mCallback(&gKeyboardKeys);
        }
        DrawKeyboardGlyphs(&gKeyboardKeys);
        MarkKeyboardRects(&gKeyboardKeys);
    }
}

void PollKeyboard(void) {
    TPData a;
    TPData b;

    if (IsKeyboardTouchEnabled() != 0) {
        do {
            TP_RequestSamplingAsync();
        } while (TP_WaitRawResult(&a) != 0);
        TP_GetCalibratedPoint(&b, &a);
    } else {
        b.mTouch = 0;
        b.mValidity = 3;
    }
    AdvanceKeyboardKeys(((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff, b);
}

#pragma thumb off
