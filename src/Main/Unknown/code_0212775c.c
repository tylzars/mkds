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
s32 InitSelectReturn(void *heap, s32 b) {
    u32 t;
    gSelectReturn = HeapAlloc(heap, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectReturnDisplay();
        b = LoadSelectReturn(b);
        gSelectReturn->mDisplayBitOn = TRUE;
    } else {
        gSelectReturn->mDisplayBitOn = FALSE;
        t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        t &= ~4;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (t << 8);
    }
    gSelectReturn->mEnabled = TRUE;
    gSelectReturn->mState = 0;
    gSelectReturn->mNextState = 0;
    gSelectReturn->mStateFrames = 0;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState4Requested = FALSE;
    gSelectReturn->mBg2Offset = -0x28;
    gSelectReturn->mSoundId = 0xe;
    return b;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnPointer(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gSelectReturn;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void InitSelectReturnDisplay(void) {
    u32 t;
    t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((t | 4) << 8);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe00;
}

s32 LoadSelectReturn(s32 a) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;
    s32 i;
    s32 j;
    s32 k;
    LocateNcgr(&ncgr, FindFileInLoadedArchives("select_return_s_b_00.ncgr"));
    LocateNscr(&nscr, FindFileInLoadedArchives("select_return_s_bg_00.nscr"));
    LocateNclr(&nclr, FindFileInLoadedArchives("select_return_s_b_00.nclr"));
    a -= ncgr->mDataSize;
    DC_FlushRange(ncgr->mData, ncgr->mDataSize);
    GXS_LoadBG2Char(ncgr->mData, a, ncgr->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(gSelectReturn->mScreenMapCopy + i * 0x20 + j) = (a >> 5) + *((u16 *) nscr->mData + i * 0x20 + j);
        }
    }
    DC_FlushRange(gSelectReturn->mScreenMapCopy, nscr->mDataSize);
    GXS_LoadBG2Scr(gSelectReturn->mScreenMapCopy, 0, nscr->mDataSize);
    DC_FlushRange(nclr->mData, 0x180);
    GXS_LoadBGPltt(nclr->mData + 0xc0, 0x180, 0x40);
    return a;
}

void SetSelectReturnPaletteBits(s32 a) {
    s32 i;
    u16 v;
    v = 0xc000;
    if (a == 0) {
        v = 0xd000;
    }
    for (i = 0x260; i < 0x360; i++) {
        gSelectReturn->mScreenMapCopy[i] &= ~0xf000;
        gSelectReturn->mScreenMapCopy[i] |= v;
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
    SelectReturn *p;
    gSelectReturn->mBg2Offset = LookupSelectReturnState1Bg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 10) {
        p->mNextState = 2;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState1Requested = FALSE;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnState2(void) {
    SelectReturn *v1;
    v1 = gSelectReturn;
    if (v1->mState3Requested != FALSE) {
        v1->mNextState = 3;
        SetSelectReturnPaletteBits(0);
        return;
    }
    if (v1->mState4Requested != FALSE) {
        v1->mNextState = 4;
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectReturnState3(void) {
    SelectReturn *p;
    p = gSelectReturn;
    p->mBg2Offset = data_0215d0b4[p->mStateFrames];
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 9) {
        if (p->mState4Requested != FALSE) {
            p->mNextState = 4;
            SetSelectReturnPaletteBits(0);
        } else {
            p->mNextState = 2;
            SetSelectReturnPaletteBits(1);
        }
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState3Requested = FALSE;
    }
}

void AdvanceSelectReturnState4(void) {
    SelectReturn *p;
    gSelectReturn->mBg2Offset = LookupSelectReturnState4Bg2Offset(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 10) {
        p->mNextState = 0;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState4Requested = FALSE;
    }
}

void AdvanceSelectReturn(void) {
    SelectReturn *p;
    p = gSelectReturn;
    if (p->mEnabled != FALSE) {
        p->mState = p->mNextState;
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
    SelectReturn *p;
    u32 t;
    p = gSelectReturn;
    if (p->mEnabled != FALSE) {
        if (p->mDisplayBitOn != FALSE) {
            if (((reg_GXS_DB_DISPCNT & 0x1f00) >> 8 & 4) == 0) {
                t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((t | 4) << 8);
            }
        } else {
            if (((reg_GXS_DB_DISPCNT & 0x1f00) >> 8 & 4) != 0) {
                t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((t & ~4) << 8);
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
void RequestSelectReturnState3WithSound(s32 a) {
    s32 v;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState3Requested = TRUE;
    if (a != 0) {
        gSelectReturn->mState4Requested = TRUE;
    } else {
        gSelectReturn->mState4Requested = FALSE;
    }
    v = gSelectReturn->mSoundId;
    if (v != -1) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) v);
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
    BOOL r;
    BOOL t;
    SelectReturn *p;
    r = FALSE;
    t = FALSE;
    p = gSelectReturn;
    if (p->mState == 2 && p->mState4Requested == FALSE) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (p->mState3Requested == FALSE) {
            r = TRUE;
        }
    }
    return r;
}

s32 IsSelectReturnState0NoState1Request(void) {
    BOOL r;
    SelectReturn *p;
    r = FALSE;
    p = gSelectReturn;
    if (p->mState == 0 && p->mState1Requested == FALSE) {
        r = TRUE;
    }
    return r;
}
#pragma thumb off

#pragma thumb on

int LookupSelectReturnState1Bg2Offset(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return data_0215d0c0[a];
}

int LookupSelectReturnState4Bg2Offset(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return data_0215d0cc[a];
}

#pragma thumb off

#pragma thumb on
BOOL IsSelectReturnState2NoState3Or4RequestAndInRect(s32 a, s32 b) {
    if (IsSelectReturnState2NoState3Or4Request() != 0 && a >= 0 && a <= 0x28 && b >= 0x98 && b <= 0xc0) {
        return TRUE;
    }
    return FALSE;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnDisplayBitOn(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &gSelectReturn;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x820u;
    *(u32 *) ((value1) + (value0)) = value2;
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
void SetSelectReturnSoundId(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gSelectReturn;
    value2 = *(const u32 *) ((value1) + 0u);
    value1 = 0x824u;
    *(u32 *) ((value2) + (value1)) = value0;
}
#pragma thumb off

#pragma thumb on
// Zeroes the char buffer gate; StartSelectChoises sets it after taking the strings.
u32 ClearSelectChoisesUseCharBuffers(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &gSelectChoises;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x8a0u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on
s32 InitSelectChoises(void *a, void *b, s32 c) {
    s32 i;
    s32 r;
    Unk0217d3f0_2098 *q;
    Unk0217d3f0_2178 *e;
    u32 t;
    gSelectChoises = HeapAlloc(a, 0x8b4);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectChoisesDisplay();
        c = LoadSelectChoises(c);
        gSelectChoises->mDisplayBitOn = 1;
    } else {
        gSelectChoises->mDisplayBitOn = 0;
        t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        t &= ~1;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (t << 8);
    }
    for (i = 0; i < 2; i++) {
        gSelectChoises->mCharBuffers[i] = HeapAlloc(a, 0x800);
        NNS_G2dCharCanvasInitForBG(&gSelectChoises->mCharCanvases[i], gSelectChoises->mCharBuffers[i], 0x20, 2, 4);
        q = &gSelectChoises->mCharCanvases[i];
        q->mUnk_18(q, 0);
        r = func_020b4acc();
        e = &gSelectChoises->mUnk_874[i];
        e->mUnk_00 = &gSelectChoises->mCharCanvases[i];
        e->mUnk_04 = (u32) b;
        e->mUnk_08 = r;
        e->mUnk_0c = 0;
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
    return c;
}
#pragma thumb off

#pragma thumb on
void ClearSelectChoisesPointer(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gSelectChoises;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
u32 InitSelectChoisesDisplay(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0x4001008u;
    value1 = *(const u16 *) ((value2) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    *(u16 *) ((value2) + 0u) = value1;
    value1 = *(const u16 *) ((value2) + 0u);
    value0 = 67u;
    value1 = (value1) & (value0);
    value0 = 0xb00u;
    value1 = (value1) | (value0);
    *(u16 *) ((value2) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

s32 LoadSelectChoises(s32 d) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;
    s32 s;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    ByteRect *e;

    LocateNcgr(&a, FindFileInLoadedArchives(gSelectChoisesSBNcgrName));
    LocateNscr(&b, FindFileInLoadedArchives(gSelectChoisesSBgNscrName));
    LocateNclr(&c, FindFileInLoadedArchives(gSelectChoisesSBNclrName));
    d = d - a->mDataSize;
    s = d >> 5;
    gSelectChoises->mFirstTileIndex = s;
    DC_FlushRange(a->mData, a->mDataSize);
    GXS_LoadBG0Char(a->mData, d, a->mDataSize);
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            *(gSelectChoises->mNscrCopy + i * 32 + j) = s + *((u16 *) b->mData + i * 32 + j);
        }
    }
    DC_FlushRange(gSelectChoises->mNscrCopy, b->mDataSize);
    GXS_LoadBG0Scr(gSelectChoises->mNscrCopy, 0, b->mDataSize);
    e = &gSelectChoisesTileRect;
    y = e->mUnk_02 * 32;
    x = e->mUnk_00;
    gSelectChoises->mToggleOnFirstTile = gSelectChoises->mFirstTileIndex + (x + y);
    gSelectChoises->mToggleOffFirstTile = gSelectChoises->mFirstTileIndex + (y + (x + 3));
    DC_FlushRange(c->mData, 0x1c0);
    GXS_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    return d;
}

void RefreshSelectChoisesNscrCopy(void) {
    s32 c;
    s32 i;
    s32 r;
    BOOL f;
    ByteRect *e;
    s32 w;
    s32 v;
    u8(*p)[2];
    s32 h;
    s32 q;

    i = 0;
    p = gSelectChoisesNscrOrigins;
    e = &gSelectChoisesTileRect;
    w = e->mUnk_01 - e->mUnk_00;
    h = e->mUnk_03 - e->mUnk_02;
    for (; i < 2; i++) {
        f = FALSE;
        if (i == gSelectChoises->mIndex && gSelectChoises->mToggleOn != 0) {
            f = TRUE;
        }
        for (r = 0; r <= h; r++) {
            for (c = 0; c <= w; c++) {
                q = c + (*p)[0] + ((r + (*p)[1]) << 5);
                v = r * 32 + (gSelectChoises->mToggleOffFirstTile + c);
                if (f != FALSE) {
                    v = r * 32 + (gSelectChoises->mToggleOnFirstTile + c);
                }
                if (f != FALSE) {
                    gSelectChoises->mNscrCopy[q] = v + ((gSelectChoises->mNscrCopy[q] & 0xffff0c00) + 0xe000);
                } else {
                    gSelectChoises->mNscrCopy[q] = v + (gSelectChoises->mNscrCopy[q] & 0xfffffc00);
                }
            }
        }
        p++;
    }
}

void RefreshSelectChoisesPaletteBits(void) {
    s32 i;
    s32 r;
    s32 c;
    s32 v;
    s32 t;

    for (i = 0; i < 2; i++) {
        v = 0xe;
        if (gSelectChoises->mIndex != i) {
            v = 0xf;
        }
        for (r = gSelectChoisesPaletteRects[i].mUnk_02; r <= gSelectChoisesPaletteRects[i].mUnk_03; r++) {
            for (c = gSelectChoisesPaletteRects[i].mUnk_00; c <= gSelectChoisesPaletteRects[i].mUnk_01; c++) {
                t = gSelectChoises->mNscrCopy[r * 32 + c];
                t &= 0xffff0fff;
                t += v << 12;
                gSelectChoises->mNscrCopy[r * 32 + c] = t;
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
    s32 a;

    a = gSelectChoises->mIndex;
    gSelectChoises->mIndex = -1;
    RefreshSelectChoisesPaletteBits();
    gSelectChoises->mIndex = a;
    gSelectChoises->mToggleFrames = 0;
    gSelectChoises->mToggleOn = 1;
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x18, 0, gSelectChoises->mNscrCopy, 0x800);
    }
}

void AdvanceSelectChoisesState0(void) {
    s32 i;
    s32 j;
    s32 t;

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
                    t = (j + i * 2) * 32 + 5;
                    if (*(vu16 *) 0x27ffc40 != 2) {
                        CallQueueAppend(0x14, (gSelectChoises->mFirstTileIndex + t) << 5,
                                        gSelectChoises->mCharBuffers[i] + ((j * 32 + 5) << 5), 0x360);
                    }
                }
            }
        }
    }
}

static inline BOOL func_02127a84_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02127a84_inline2(u32 v) {
    BOOL r = FALSE;
    BOOL s = FALSE;
    u16 c = data_02175674[v].mUnk_00;

    if (c == 0 && data_02175680[v].mUnk_00 < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[v].mUnk_00 == 0 && c != 0) {
        r = TRUE;
    }
    return r;
}

void AdvanceSelectChoisesState1(void) {
    s32 hit;
    u16 x;
    u16 y;
    Unk02175628Index v;
    u16 w;

    v = UNK_02175628_INDEX_8;
    x = data_02175670[v].mUnk_00;
    y = data_02175672[v].mUnk_00;
    if (gSelectChoises->mState0Requested != 0) {
        gSelectChoises->mNextState = 0;
        gSelectChoises->mState0Requested = 0;
        return;
    }
    hit = -1;
    if (func_02127a84_inline2(v) != 0) {
        if (func_02127a84_inline(x, y, gSelectChoisesHitRects[0].mUnk_00, gSelectChoisesHitRects[0].mUnk_01,
                                 gSelectChoisesHitRects[0].mUnk_02, gSelectChoisesHitRects[0].mUnk_03) != FALSE) {
            hit = 0;
        }
        if (func_02127a84_inline(x, y, gSelectChoisesHitRects[1].mUnk_00, gSelectChoisesHitRects[1].mUnk_01,
                                 gSelectChoisesHitRects[1].mUnk_02, gSelectChoisesHitRects[1].mUnk_03) != FALSE) {
            hit = 1;
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & PAD_KEY_A) != 0 || hit != -1) {
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
        if ((u16) (w & PAD_KEY_B) != 0) {
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
        if ((u16) (w & PAD_KEY_UP) != 0 && gSelectChoises->mIndex == 1) {
            gSelectChoises->mIndex = 0;
            RefreshAndQueueSelectChoises();
            if (gSelectChoises->mDisplayBitOn != 0) {
                StartSoundOncePerFrame(0);
            }
            return;
        }
        if ((u16) (w & PAD_KEY_DOWN) != 0 && gSelectChoises->mIndex == 0) {
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
    SelectChoises *v1;
    int v2;
    v1 = gSelectChoises;
    if (v1->mState0Requested != 0) {
        v1->mNextState = 0;
        gSelectChoises->mState0Requested = 0;
        return;
    }
    v1->mState2Frames = v1->mState2Frames + 1;
    v2 = gSelectChoises->mState2Frames;
    if (15 <= v2) {
        gSelectChoises->mDone = 1;
        gSelectChoises->mState2Frames = 0xf;
        return;
    }
    if (5 <= v2) {
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
    u32 a;

    if (gSelectChoises->mEnabled != 0) {
        reg_G2S_DB_BG0OFS = 0;
        if (gSelectChoises->mState == 0 || gSelectChoises->mDisplayBitOn == 0) {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, 0);
            a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((a & ~1) << 8);
        } else {
            G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x1e, 0x1f, 6, 10, -10);
            a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((a | 1) << 8);
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

void StartSelectChoises(void *a, void *b, s32 c) {
    Unk0217d3f0_2098 *p;

    p = &gSelectChoises->mCharCanvases[0];
    p->mUnk_18(p, 5);
    p = &gSelectChoises->mCharCanvases[1];
    p->mUnk_18(p, 5);
    func_0212583c(&gSelectChoises->mUnk_874[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, a);
    func_0212583c(&gSelectChoises->mUnk_874[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, b);
    ClearSelectChoisesUseCharBuffers();
    gSelectChoises->mUseCharBuffers = 1;
    RequestSelectChoisesState1();
    if (c == 0) {
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
    u32 r;

    r = 0;
    if (gSelectChoises->mState == 1 && gSelectChoises->mState0Requested == 0) {
        r = 1;
    }
    return r;
}

s32 IsSelectChoisesState0NoState1Request(void) {
    BOOL r;

    r = FALSE;
    if (gSelectChoises->mState == 0 && gSelectChoises->mState1Requested == 0) {
        r = TRUE;
    }
    return r;
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

void SetSelectChoisesSoundId(int a, u32 b) {
    if (a == -1) {
        gSelectChoises->mIndexNoneSoundId = b;
        return;
    }
    gSelectChoises->mSoundIds[a] = b;
}

#pragma thumb off
