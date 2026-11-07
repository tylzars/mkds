#include "01/code_0219a050.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02114000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02124000.h"
#include "01/code_0219a000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "01/code_0219b540.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

RecordTopMenu *gRecordTopMenu;

void LocateAndQueueRecordTopMenu(void) {
    Ncgr *a;
    Nclr *b;
    Ncgr *c;
    Nclr *d;
    Ncgr *e;
    Nclr *f;
    Nscr *g;
    u16 *q;

    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    e = NULL;
    f = NULL;
    g = NULL;
    LocateNcgr(&e, FindSceneFile(gRecordTopMenuMBNcgrName));
    LocateNclr(&f, FindSceneFile(gRecordTopMenuMBNclrName));
    LocateNscr(&g, FindSceneFile(gRecordTopMenuMNscrName));
    gRecordTopMenu->mUnk_28 = HeapAlloc(gRecordTopMenu->mHeap, 0x800);
    gRecordTopMenu->mRecordTopMenuMBncl = FindSceneFile(gRecordTopMenuMBnclName);
    gRecordTopMenu->mRecordTopMenuMBnll = FindSceneFile(gRecordTopMenuMBnllName);
    LocateNcgr2(&a, FindSceneFile(gRecordTopMenuMNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuMNcer, FindSceneFile(gRecordTopMenuMNcerName));
    LocateNclr(&b, FindSceneFile(gRecordTopMenuMONclrName));
    gRecordTopMenu->mRecordTopMenuSBncl = FindSceneFile(gRecordTopMenuSBnclName);
    gRecordTopMenu->mRecordTopMenuSBnbl = FindSceneFile(gRecordTopMenuSBnblName);
    LocateNcgr2(&c, FindSceneFile(gRecordTopMenuSNcgrName));
    LocateNcer(&gRecordTopMenu->mRecordTopMenuSNcer, FindSceneFile(gRecordTopMenuSNcerName));
    LocateNclr(&d, FindSceneFile(gRecordTopMenuSONclrName));
    q = b->mData;
    CallQueueAppend(4, 0, e->mData, e->mDataSize);
    CallQueueAppend(15, 0, f->mData, 0x60);
    CallQueueAppend(8, 0, g->mData, g->mDataSize);
    CallQueueAppend(8, 0x800, gRecordTopMenu->mUnk_28, 0x800);
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(14, 0, b->mData, 0x1a0);
    CallQueueAppend(14, 0x1c0, q + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

void SetRecordTopMenuRowOn(s32 a) {
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6aa4[a], 14, gRecordTopMenu->mRecordTopMenuSNcer, gRecordTopMenu->mRecordTopMenuSBncl);
}

void SetRecordTopMenuRowOff(s32 a) {
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6aa4[a], 15, gRecordTopMenu->mRecordTopMenuSNcer, gRecordTopMenu->mRecordTopMenuSBncl);
}

void ResetRecordTopMenu(void) {
    s32 i;
    s32 j;
    u16 *p;
    s32 n;

    gRecordTopMenu->mNextState = 0;
    gRecordTopMenu->mStateFrames = 0;
    gRecordTopMenu->mBg0Offset = ~0xbf;
    n = gRecordTopMenu->mRecordTopMenuMBncl->mUnk_06;
    gRecordTopMenu->mRecordTopMenuMTable[0].mUnk_06 = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[1].mUnk_06 = ~0xbf;
    gRecordTopMenu->mRecordTopMenuMTable[n].mUnk_06 = ~0xbf;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[data_ov001_021a6aac[i]].mUnk_06 = ~0xbf;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[n + *p].mUnk_06 = ~0xbf;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = 0xe0;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = 0xe0;
        SetRecordTopMenuRowOff(i);
    }
}

// Requests state 1 for the next update.
void RequestRecordTopMenuState1(void) {
    gRecordTopMenu->mNextState = 1;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 2 for the next update.
void RequestRecordTopMenuState2(void) {
    gRecordTopMenu->mNextState = 2;
    gRecordTopMenu->mStateFrames = 0;
}

void func_ov001_0219ae44(void) {
    gRecordTopMenu->mNextState = 3;
    gRecordTopMenu->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4 for the next update.
void RequestRecordTopMenuState4(void) {
    gRecordTopMenu->mNextState = 4;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuState5(void) {
    gRecordTopMenu->mNextState = 5;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

// Requests state 6 for the next update.
void RequestRecordTopMenuState6(void) {
    gRecordTopMenu->mNextState = 6;
    gRecordTopMenu->mStateFrames = 0;
}

// Requests state 7 for the next update.
void RequestRecordTopMenuState7(void) {
    gRecordTopMenu->mNextState = 7;
    gRecordTopMenu->mStateFrames = 0;
}

void RequestRecordTopMenuState8(void) {
    gRecordTopMenu->mNextState = 8;
    gRecordTopMenu->mStateFrames = 0;
    SetupTxtSystemSubText(GetBmgEntry(gRecordTopMenu->mUnk_20, 0x76));
}

void RequestRecordTopMenuState9(void) {
    gRecordTopMenu->mNextState = 9;
    gRecordTopMenu->mStateFrames = 0;
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
}

void RequestRecordTopMenuState10(void) {
    gRecordTopMenu->mNextState = 10;
    gRecordTopMenu->mStateFrames = 0;
    RequestTxtSystemClose();
}

// Requests state 11 for the next update.
void RequestRecordTopMenuState11(void) {
    gRecordTopMenu->mNextState = 11;
    gRecordTopMenu->mStateFrames = 0;
}

void IncrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex++;
    if (gRecordTopMenu->mIndex >= 3) {
        gRecordTopMenu->mIndex = 0;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
}

void DecrementRecordTopMenuIndex(void) {
    gRecordTopMenu->mIndex--;
    if (gRecordTopMenu->mIndex < 0) {
        gRecordTopMenu->mIndex = 2;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
}

void func_ov001_0219ac98(void) {
    s32 best = 7;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (IsGrandPrixRecordFilled(i, j)) {
                s32 v = func_02060364(i, j);
                if (best > v) {
                    best = v;
                }
            } else {
                best = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[data_ov001_021a6aac[i]].mUnk_00 = 0;
    }
    if (best > 4) {
        gRecordTopMenu->mRecordTopMenuMTable[data_ov001_021a6aac[best - 5]].mUnk_00 = 1;
    }
}

void InitRecordTopMenu(void *heap) {
    u32 scores[3][3] = {0};
    u16 buf[16];
    s32 rem;
    u16 x;
    u16 base;
    s32 i;
    s32 j;
    Unk0217aa08_00 **pp;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x8800;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    gRecordTopMenu = HeapAlloc(heap, 0x48);
    gRecordTopMenu->mHeap = heap;
    gRecordTopMenu->mState = 0;
    switch (GetRecordPrevScreen()) {
        case 1:
        case 5:
            gRecordTopMenu->mIndex = 0;
            break;
        case 2:
            gRecordTopMenu->mIndex = 1;
            break;
        case 3:
            if (GetRecordCount()) {
                gRecordTopMenu->mIndex = 2;
            } else {
                gRecordTopMenu->mIndex = 0;
            }
            break;
    }
    LocateAndQueueRecordTopMenu();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6ac4[i], 1, gRecordTopMenu->mRecordTopMenuSNcer,
                      gRecordTopMenu->mRecordTopMenuSBncl);
    }
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMBnll,
                  &gRecordTopMenu->mRecordTopMenuMTable);
    func_02124ed0(heap, gRecordTopMenu->mRecordTopMenuSBncl, NULL, &gRecordTopMenu->mRecordTopMenuSTable);
    gRecordTopMenu->mUnk_20 = FindFileInLoadedArchives("common.bmg");
    gRecordTopMenu->mRecordMessages = FindSceneFile("record.bmg");
    rem = 0x8000;
    rem -=
        func_021243ac(heap, 0, gRecordTopMenu->mRecordTopMenuMBnll, 0xaa, 0xe, 0, gRecordTopMenu->mRecordTopMenuMNcer,
                      gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable, rem);
    func_0212426c(0, 0, gRecordTopMenu->mRecordTopMenuMBnll, GetBmgEntry(gRecordTopMenu->mRecordMessages, 9),
                  gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    x = 1;
    base = gRecordTopMenu->mRecordTopMenuMBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            rem -= func_021243ac(heap, data_ov001_021a6ae4[i][j], gRecordTopMenu->mRecordTopMenuMBnll,
                                 data_ov001_021a6af8[i][j], data_ov001_021a6b0c[i][j], x,
                                 gRecordTopMenu->mRecordTopMenuMNcer, gRecordTopMenu->mRecordTopMenuMBncl,
                                 gRecordTopMenu->mRecordTopMenuMTable, rem);
            x = base + data_ov001_021a6ae4[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_ov001_021a6ae4[0][i], gRecordTopMenu->mRecordTopMenuMBnll,
                      GetBmgEntry(gRecordTopMenu->mRecordMessages, gRecordTopMenuRecordMessageIndices[i]),
                      gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable);
    }
    pp = &data_0217aa08->mUnk_00;
    scores[1][0] = (*pp)->mUnk_34[0];
    scores[2][0] = (*pp)->mUnk_34[1];
    scores[1][1] = (*pp)->mUnk_34[2];
    scores[2][1] = (*pp)->mUnk_34[3];
    scores[1][2] = (*pp)->mUnk_34[4];
    scores[2][2] = (*pp)->mUnk_34[5];
    for (i = 1; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (scores[i][j] > 9999) {
                scores[i][j] = 9999;
            }
            func_02124fac(scores[i][j], buf);
            func_02124248(0, data_ov001_021a6ae4[i][j], gRecordTopMenu->mRecordTopMenuMBnll, buf,
                          gRecordTopMenu->mRecordTopMenuMBncl, gRecordTopMenu->mRecordTopMenuMTable, 6);
        }
    }
    func_ov001_0219ac98();
    ResetRecordTopMenu();
    SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
}

void ReleaseRecordTopMenu(void) {
    u32 a;
    u32 b;

    gRecordTopMenu = NULL;
    a = (reg_GX_DISPCNT & 0x1f00) >> 8;
    a &= ~0x11;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (a << 8);
    b = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    b &= ~0x1;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (b << 8);
}

void AdvanceRecordTopMenuState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestRecordTopMenuState1();
    }
}

void AdvanceRecordTopMenuState1(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    gRecordTopMenu->mStateFrames++;
    a = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    b = InterpolateS16(1, -0xc0, 0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = b;
    idx = gRecordTopMenu->mRecordTopMenuMBncl->mUnk_06;
    gRecordTopMenu->mRecordTopMenuMTable[0].mUnk_06 = b;
    gRecordTopMenu->mRecordTopMenuMTable[1].mUnk_06 = b;
    gRecordTopMenu->mRecordTopMenuMTable[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState2();
    }
}

void AdvanceRecordTopMenuState2(void) {
    s16 v;
    s32 i;

    gRecordTopMenu->mStateFrames++;
    v = func_020ae488(gRecordTopMenu->mStateFrames);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        func_ov001_0219ae44();
    }
}

void AdvanceRecordTopMenuState3(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestRecordTopMenuState4();
    }
}

void AdvanceRecordTopMenuState4(void) {
    Unk02175628Index i;
    u16 flags;
    BOOL b;
    s32 sel;
    BOOL a;
    BOOL b2;
    BOOL a2;
    s32 t;

    b = FALSE;
    sel = -1;
    i = UNK_02175628_INDEX_8;
    a = FALSE;
    if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        sel = RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, data_02175628[i].mPairX,
                                      data_02175628[i].mPairY);
    }
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b2 = FALSE;
        a2 = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            a2 = TRUE;
        }
        if (a2 == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            b2 = TRUE;
        }
        if (b2 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                           data_02175628[i].mPairY) == FALSE) {
            goto skip;
        }
    }
    SetSelectReturnSoundId(15);
    RequestRecordTopMenuState6();
    gRecordTopMenu->mUnk_44 = 5;
    RequestSelectReturnState3WithSound(1);
    return;
skip:
    if ((u32) sel <= 2) {
        t = data_ov001_021a6acc[sel];
        if (gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[t]].mUnk_00 != 0) {
            if (gRecordTopMenu->mIndex == t) {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = t;
            } else {
                SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
                gRecordTopMenu->mIndex = t;
                SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
            }
            RequestRecordTopMenuState5();
        }
    } else {
        flags = data_02175628[i].mUnk_00 & 1;
        if (flags != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            RequestRecordTopMenuState5();
        } else if (GetNewOrRepeatBits(8, 0x40) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            DecrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        } else if (GetNewOrRepeatBits(8, 0x80) != 0) {
            SetRecordTopMenuRowOff(gRecordTopMenu->mIndex);
            IncrementRecordTopMenuIndex();
            SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
        }
    }
}

void AdvanceRecordTopMenuState5(void) {
    s16 v;

    gRecordTopMenu->mStateFrames++;
    v = func_020ae488(gRecordTopMenu->mStateFrames);
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[gRecordTopMenu->mIndex]].mUnk_04 = v;
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[gRecordTopMenu->mIndex]].mUnk_04 = v;
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[gRecordTopMenu->mIndex]].mUnk_04 = v;
    gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[gRecordTopMenu->mIndex]].mUnk_04 = v;
    if (gRecordTopMenu->mStateFrames == 5) {
        SetRecordTopMenuRowOn(gRecordTopMenu->mIndex);
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        if (gRecordTopMenu->mIndex == 2 && GetRecordCount() == 0) {
            RequestRecordTopMenuState7();
            return;
        }
        gRecordTopMenu->mUnk_44 = data_ov001_021a6ad8[gRecordTopMenu->mIndex];
        RequestRecordTopMenuState6();
    }
}

void AdvanceRecordTopMenuState6(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    if (GetRecordNextScene() == -1 && gRecordTopMenu->mUnk_44 == 5) {
        SetRecordNextScene(0);
    }
    gRecordTopMenu->mStateFrames++;
    a = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    b = InterpolateS16(1, 0, -0xc0, gRecordTopMenu->mStateFrames, 10);
    gRecordTopMenu->mBg0Offset = b;
    idx = gRecordTopMenu->mRecordTopMenuMBncl->mUnk_06;
    gRecordTopMenu->mRecordTopMenuMTable[0].mUnk_06 = b;
    gRecordTopMenu->mRecordTopMenuMTable[1].mUnk_06 = b;
    gRecordTopMenu->mRecordTopMenuMTable[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuMTable[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            gRecordTopMenu->mRecordTopMenuMTable[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = a;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (gRecordTopMenu->mStateFrames >= 10 && GetRecordNextScene() == -1) {
        RequestRecordScreen(gRecordTopMenu->mUnk_44);
    }
}

void AdvanceRecordTopMenuState7(void) {
    s16 v;
    s32 i;

    gRecordTopMenu->mStateFrames++;
    v = InterpolateS16(1, 0, 0xe0, gRecordTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        RequestRecordTopMenuState8();
    }
}

void AdvanceRecordTopMenuState8(void) {
    int v1;
    v1 = IsTxtSystemState2NoCloseRequest();
    if (v1 != 0) {
        RequestRecordTopMenuState9();
    }
}

void AdvanceRecordTopMenuState9(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u16 flags;
    BOOL b;
    BOOL a;
    u16 v;

    RectTableFindContaining(gRecordTopMenu->mRecordTopMenuSBnbl, data_02175628[i].mPairX, data_02175628[i].mPairY);
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b = FALSE;
        a = FALSE;
        v = data_02175628[i].mHasPair;
        if (v == 0 && data_02175628[i].mNoPairCount < 5) {
            a = TRUE;
        }
        if (a == FALSE && data_02175628[i].mPrevHasPair == 0 && v != 0) {
            b = TRUE;
        }
        if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                          data_02175628[i].mPairY) == FALSE) {
            return;
        }
    }
    RequestRecordTopMenuState10();
    RequestSelectReturnState3WithSound(0);
}

void AdvanceRecordTopMenuState10(void) {
    int v1;
    v1 = IsTxtSystemState0NoOpenRequest();
    if (v1 != 0) {
        RequestRecordTopMenuState11();
    }
}

void AdvanceRecordTopMenuState11(void) {
    s32 i;
    s16 v;
    gRecordTopMenu->mStateFrames++;
    v = InterpolateS16(1, 0xe0, 0, gRecordTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ab4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6ac4[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6a9c[i]].mUnk_04 = v;
        gRecordTopMenu->mRecordTopMenuSTable[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (gRecordTopMenu->mStateFrames >= 10) {
        func_ov001_0219ae44();
    }
}

void AdvanceRecordTopMenu(void) {
    RecordTopMenu *p;
    gRecordTopMenu->mState = gRecordTopMenu->mNextState;
    switch (gRecordTopMenu->mState) {
        case 0:
            AdvanceRecordTopMenuState0();
            break;
        case 1:
            AdvanceRecordTopMenuState1();
            break;
        case 2:
            AdvanceRecordTopMenuState2();
            break;
        case 3:
            AdvanceRecordTopMenuState3();
            break;
        case 4:
            AdvanceRecordTopMenuState4();
            break;
        case 5:
            AdvanceRecordTopMenuState5();
            break;
        case 6:
            AdvanceRecordTopMenuState6();
            break;
        case 7:
            AdvanceRecordTopMenuState7();
            break;
        case 8:
            AdvanceRecordTopMenuState8();
            break;
        case 9:
            AdvanceRecordTopMenuState9();
            break;
        case 10:
            AdvanceRecordTopMenuState10();
            break;
        case 11:
            AdvanceRecordTopMenuState11();
            break;
    }
    p = gRecordTopMenu;
    func_02124c30(p->mRecordTopMenuMBncl, p->mRecordTopMenuMNcer, p->mRecordTopMenuMBnll, func_02111318(),
                  p->mRecordTopMenuMTable);
    p = gRecordTopMenu;
    func_02124c30(p->mRecordTopMenuSBncl, p->mRecordTopMenuSNcer, NULL, func_0211130c(), p->mRecordTopMenuSTable);
}

void func_ov001_0219a0c0(void) {
    reg_G2_BG0OFS = (-gRecordTopMenu->mBg0Offset << 16) & 0x1ff0000;
    AdvanceRecordSceneRegistersTimer();
}

void WriteRecordTopMenuRegisters(void) {
    u32 a;
    u32 b;
    a = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((a | 0x11) << 8);
    b = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((b | 0x1) << 8);
}

void RegisterRecordTopMenuCallbacks(void) {
    UnkFunc *tbl[5] = {InitRecordTopMenu, ReleaseRecordTopMenu, AdvanceRecordTopMenu, func_ov001_0219a0c0,
                       WriteRecordTopMenuRegisters};
    SetRecordScreenCallbacks(tbl);
}
