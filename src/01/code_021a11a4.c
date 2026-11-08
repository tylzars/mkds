#include "01/code_021a11a4.h"

#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "01/code_021a6430.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_021a1000.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "registers.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116000.h"
#include "00/code_02181f98.h"
#include "01/code_02185000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02029440.h"

SelectEngine *gSelectEngine;

void LoadSelectEngineData(void) {
    Ncgr *l0 = NULL;
    Unk02021dc8 *l1 = NULL;
    Nclr *l2 = NULL;
    Ncgr *l3 = NULL;
    Unk02021dc8 *l4 = NULL;
    Nclr *l5 = NULL;
    Ncgr *l6 = NULL;
    Nscr *l7 = NULL;
    Nclr *l8 = NULL;

    LoadNcgrData(&l6, FindSceneFile(gSelectEngineMBNcgrName));
    LoadNclrData(&l8, FindSceneFile(gSelectEngineMBNclrName));
    LoadNscrData(&l7, FindSceneFile(gSelectEngineMNscrName));
    LoadNcgrData2(&l0, FindSceneFile(gSelectEngineMNcgrName));
    LoadNcerData(&l1, FindSceneFile(gSelectEngineMNcerName));
    LoadNclrData(&l2, FindSceneFile(gSelectEngineMONclrName));
    LoadNcgrData2(&l3, FindSceneFile(gSelectEngineSNcgrName));
    LoadNcerData(&l4, FindSceneFile(gSelectEngineSNcerName));
    LoadNclrData(&l5, FindSceneFile(gSelectEngineSONclrName));
}

void LocateAndQueueSelectEngine(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Ncgr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    u16 *h;

    LocateNcgr(&e, FindSceneFile(gSelectEngineMBNcgrName));
    LocateNclr(&g, FindSceneFile(gSelectEngineMBNclrName));
    LocateNscr(&f, FindSceneFile(gSelectEngineMNscrName));
    gSelectEngine->mUnk_1c = HeapAlloc(gSelectEngine->mHeap, 0x800);
    gSelectEngine->mSelectEngineMBncl = FindSceneFile(gSelectEngineMBnclName);
    LocateNcgr2(&a, FindSceneFile(gSelectEngineMNcgrName));
    LocateNcer(&gSelectEngine->mSelectEngineMNcer, FindSceneFile(gSelectEngineMNcerName));
    LocateNclr(&b, FindSceneFile(gSelectEngineMONclrName));
    LocateNcgr2(&c, FindSceneFile(gSelectEngineSNcgrName));
    LocateNcer(&gSelectEngine->mSelectEngineSNcer, FindSceneFile(gSelectEngineSNcerName));
    LocateNclr(&d, FindSceneFile(gSelectEngineSONclrName));
    if (IsBackupFlagSet(0x10) != 0) {
        gSelectEngine->mSelectEngineAOrBSBncl = FindSceneFile(gSelectEngineBSBnclName);
        gSelectEngine->mSelectEngineAOrBSBnbl = FindSceneFile(gSelectEngineBSBnblName);
    } else {
        gSelectEngine->mSelectEngineAOrBSBncl = FindSceneFile(gSelectEngineASBnclName);
        gSelectEngine->mSelectEngineAOrBSBnbl = FindSceneFile(gSelectEngineASBnblName);
    }
    h = b->mData;
    CallQueueAppend(4, 0, e->mData, e->mDataSize);
    CallQueueAppend(0xf, 0, g->mData, 0x100);
    CallQueueAppend(8, 0, f->mData, f->mDataSize);
    CallQueueAppend(8, 0x800, gSelectEngine->mUnk_1c, 0x800);
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, (u8 *) h + 0x1c0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

void func_ov001_021a1cb0(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mVisible = 0;
        for (j = 0; j < 3; j++) {
            gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mVisible = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[i]].mVisible = 1;
    }
    gSelectEngine->mSelectEngineMTable[6].mVisible = 1;
    gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[gSelectEngine->mIndex]].mVisible = 1;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][0]].mVisible = 1;
        func_02124a98(data_ov001_021a6fa0[i][0], 1, gSelectEngine->mSelectEngineSNcer,
                      gSelectEngine->mSelectEngineAOrBSBncl);
    }
    func_02124a98(2, 1, gSelectEngine->mSelectEngineMNcer, gSelectEngine->mSelectEngineMBncl);
}

void func_ov001_021a1c34(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][1]].mVisible = 0;
        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][2]].mVisible = 0;
        if (gSelectEngine->mIndex == i && gSelectEngine->mUnk_38 != FALSE) {
            gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][2]].mVisible = 1;
        } else {
            gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][1]].mVisible = 1;
        }
    }
    if (IsBackupFlagSet(0x10) == 0) {
        for (i = 0; i < 3; i++) {
            gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[3][i]].mVisible = 0;
        }
    }
}

void func_ov001_021a1bf8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mVisible = 0;
    }
    gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[gSelectEngine->mIndex]].mVisible = 1;
}

void func_ov001_021a1bb8(void) {
    if (gSelectEngine->mIndex == 3) {
        SetEngineIndex(data_ov001_021a6f90[2]);
        SetMirrorMode();
    } else {
        SetEngineIndex(data_ov001_021a6f90[gSelectEngine->mIndex]);
        ClearMirrorMode();
    }
    SetCupIndex(0);
}

u32 func_ov001_021a1ba0(void) {
    if (gSelectEngine->mUnk_3c != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021a1b08(void) {
    s32 i;
    s16 v;

    if (func_ov001_021a1ba0() != 0) {
        if (gSelectEngine->mUnk_3c == 7) {
            gSelectEngine->mUnk_40 = gSelectEngine->mIndex;
            func_ov001_021a1bf8();
        } else {
            v = LookupIndexChangeOffset(7 - gSelectEngine->mUnk_3c, 0);
            for (i = 0; i < 6; i++) {
                gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[i]].mOffsetY = v;
            }
            for (i = 0; i < 4; i++) {
                gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mOffsetY = v;
            }
        }
        gSelectEngine->mUnk_3c -= 1;
    } else if (gSelectEngine->mIndex != gSelectEngine->mUnk_40) {
        gSelectEngine->mUnk_3c = 7;
    }
}

void func_ov001_021a1a04(void) {
    s32 i;
    s32 j;

    gSelectEngine->mNextState = 0;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mBg0Offset = 0xc0;
    for (i = 0; i < 6; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[i]].mOffsetY = 0xc0;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = -0xc0;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mOffsetY = 0xc0;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = -0xe0;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = 0xe0;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = 0xe0;
            }
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState1.
void RequestSelectEngineState1(void) {
    gSelectEngine->mNextState = 1;
    gSelectEngine->mStateFrames = 0;
}

// Requests state 2: stores mNextState = 2 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState2.
void RequestSelectEngineState2(void) {
    gSelectEngine->mNextState = 2;
    gSelectEngine->mStateFrames = 0;
}

void func_ov001_021a19c0(void) {
    gSelectEngine->mNextState = 3;
    gSelectEngine->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 4: stores mNextState = 4 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState4.
void RequestSelectEngineState4(void) {
    gSelectEngine->mNextState = 4;
    gSelectEngine->mStateFrames = 0;
}

void func_ov001_021a1978(void) {
    gSelectEngine->mNextState = 5;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mResult = 1;
    func_ov001_021a1bb8();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceSelectEngine call copies it to
// mState and runs AdvanceSelectEngineState6.
void RequestSelectEngineState6(void) {
    gSelectEngine->mNextState = 6;
    gSelectEngine->mStateFrames = 0;
}

void InitSelectEngine(void *a, void *b, void *c) {
    void *heap;
    SelectEngine *p;
    vu16 *bg0 = &reg_G2_BG0CNT;
    vu16 *bg1 = &reg_G2_BG1CNT;

    *bg0 = (*bg0 & ~3) | 1;
    *bg1 = (*bg1 & ~3) | 1;
    *bg0 = (*bg0 & 0x43) | 0x9004;
    *bg1 = (*bg1 & 0x43) | 0x9204;
    reg_G2_BG0OFS = 0xc00000;
    reg_G2_BG1OFS = 0xc00000;
    heap = CreateFrmHeapFromMaxFree(a);
    p = HeapAlloc(heap, 0x50);
    gSelectEngine = p;
    p->mHeap = heap;
    gSelectEngine->mState = 0;
    gSelectEngine->mUnk_3c = 0;
    gSelectEngine->mUnk_38 = TRUE;
    gSelectEngine->mUnk_44 = b;
    gSelectEngine->mUnk_48 = c;
    gSelectEngine->mResult = 0;
    if (GetMirrorMode() != 0) {
        gSelectEngine->mIndex = 3;
    } else {
        gSelectEngine->mIndex = data_ov001_021a6f74[GetEngineIndex()];
    }
    gSelectEngine->mUnk_40 = gSelectEngine->mIndex;
    LocateAndQueueSelectEngine();
    func_020ae6d4(gSelectEngine->mUnk_44, gSelectEngine->mUnk_48);
    InitLayoutTable(gSelectEngine->mHeap, gSelectEngine->mSelectEngineMBncl, NULL, &gSelectEngine->mSelectEngineMTable);
    InitLayoutTable(gSelectEngine->mHeap, gSelectEngine->mSelectEngineAOrBSBncl, NULL,
                    &gSelectEngine->mSelectEngineAOrBSTable);
    func_ov001_021a1cb0();
    func_ov001_021a1bf8();
    func_ov001_021a1a04();
    FrmHeapShrinkInParent(gSelectEngine->mHeap);
}

void ReleaseSelectEngine(void) {
    HeapDestroy(gSelectEngine->mHeap);
    gSelectEngine = NULL;
}

void AdvanceSelectEngineState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestSelectEngineState1();
    }
}

void AdvanceSelectEngineState1(void) {
    s16 a;
    s16 b;
    s32 j;
    s32 i;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    a = InterpolateS16(1, 0xe0, 0, gSelectEngine->mStateFrames, 10);
    b = InterpolateS16(1, -0xc0, 0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -b;
    for (i = 0; i < 6; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[i]].mOffsetY = -b;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = b;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mOffsetY = -b;
        if (IsBackupFlagSet(0x10)) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = a;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][j]].mOffsetX = a;
            }
        }
    }
    if (gSelectEngine->mStateFrames >= 10) {
        RequestSelectEngineState2();
    }
}

void AdvanceSelectEngineState2(void) {
    s16 x;
    s32 j;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    x = func_020ae488(gSelectEngine->mStateFrames);
    gSelectEngine->mBg0Offset = x;
    for (j = 0; j < 6; j++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[j]].mOffsetY = x;
    }
    for (j = 0; j < 4; j++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[j]].mOffsetY = x;
    }
    if (gSelectEngine->mStateFrames >= 10) {
        func_ov001_021a19c0();
    }
}

void AdvanceSelectEngineState3(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestSelectEngineState4();
    }
}

void AdvanceSelectEngineState4(void) {
    u32 r5 = -1;
    InputSlotIndex idx = UNK_02175628_INDEX_8;
    BOOL b1;
    s32 a1;
    BOOL b2;
    s32 a2;
    u32 v;
    u32 w;
    s32 t;
    s32 s;
    SelectEngine *o;

    func_ov001_021a1b08();
    a1 = b1 = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        a1 = 1;
    }
    if (a1 == 0 && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
        b1 = TRUE;
    }
    if (b1 != FALSE) {
        r5 = RectTableFindContaining(gSelectEngine->mSelectEngineAOrBSBnbl, data_02175628[idx].mPairX,
                                     data_02175628[idx].mPairY);
    }
    if ((u16) (data_02175628[idx].mPressedBits & PAD_KEY_B) == 0) {
        a2 = b2 = FALSE;
        w = data_02175628[idx].mHasPair;
        if (w == 0 && data_02175628[idx].mNoPairCount < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[idx].mPrevHasPair == 0 && w != 0) {
            b2 = TRUE;
        }
        if (b2 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mPairX,
                                                                           data_02175628[idx].mPairY) == FALSE) {
            goto next;
        }
    }
    if (func_ov001_021a1ba0() != 0) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    RequestSelectEngineState6();
    gSelectEngine->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (r5 <= 3) {
        s = data_ov001_021a6f80[r5];
        if (gSelectEngine->mIndex == s) {
            gSelectEngine->mUnk_38 = FALSE;
        }
        gSelectEngine->mIndex = s;
        func_ov001_021a1978();
        return;
    }
    if ((u16) (data_02175628[idx].mPressedBits & PAD_KEY_A) != 0) {
        gSelectEngine->mUnk_38 = FALSE;
        func_ov001_021a1978();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f20[t];
        } else {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f40[t];
        }
        if (s != 0) {
            o->mIndex = t + s;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f30[t];
        } else {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f48[t];
        }
        if (s != 0) {
            o->mIndex = t + s;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f38[t];
        } else {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f50[t];
        }
        if (s != 0) {
            o->mIndex = t + s;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (IsBackupFlagSet(0x10) != 0) {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f60[t];
        } else {
            t = gSelectEngine->mIndex;
            o = gSelectEngine;
            s = data_ov001_021a6f58[t];
        }
        if (s != 0) {
            o->mIndex = t + s;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceSelectEngineState5(void) {
    func_ov001_021a1b08();
    if (gSelectEngine->mStateFrames == 5) {
        gSelectEngine->mUnk_38 = TRUE;
    }
    gSelectEngine->mStateFrames++;
    if (gSelectEngine->mStateFrames >= 10) {
        if (func_ov001_021a1ba0() == 0) {
            RequestSelectEngineState6();
        }
    }
}

void AdvanceSelectEngineState6(void) {
    s16 a;
    s16 b;
    s32 i;
    s32 k;

    gSelectEngine->mStateFrames++;
    a = InterpolateS16(1, 0, 0xc0, gSelectEngine->mStateFrames, 10);
    b = InterpolateS16(1, 0, -0xc0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -b;
    for (i = 0; i < 6; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f68[i]].mOffsetY = -b;
    }
    gSelectEngine->mSelectEngineMTable[6].mOffsetY = b;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mSelectEngineMTable[data_ov001_021a6f28[i]].mOffsetY = -b;
        if (IsBackupFlagSet(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (k = 0; k < 3; k++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][k]].mOffsetX = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (k = 0; k < 3; k++) {
                        gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][k]].mOffsetX = a;
                    }
                    break;
            }
        } else {
            for (k = 0; k < 3; k++) {
                gSelectEngine->mSelectEngineAOrBSTable[data_ov001_021a6fa0[i][k]].mOffsetX = a;
            }
        }
    }
}

int AdvanceSelectEngine(void) {
    gSelectEngine->mState = gSelectEngine->mNextState;
    switch (gSelectEngine->mState) {
        case 0:
            AdvanceSelectEngineState0();
            break;
        case 1:
            AdvanceSelectEngineState1();
            break;
        case 2:
            AdvanceSelectEngineState2();
            break;
        case 3:
            AdvanceSelectEngineState3();
            break;
        case 4:
            AdvanceSelectEngineState4();
            break;
        case 5:
            AdvanceSelectEngineState5();
            break;
        case 6:
            AdvanceSelectEngineState6();
            break;
    }
    func_ov001_021a1c34();
    DrawLayoutTable(gSelectEngine->mSelectEngineMBncl, gSelectEngine->mSelectEngineMNcer, NULL, gSelectEngine->mUnk_44,
                    gSelectEngine->mSelectEngineMTable);
    DrawLayoutTable(gSelectEngine->mSelectEngineAOrBSBncl, gSelectEngine->mSelectEngineSNcer, NULL,
                    gSelectEngine->mUnk_48, gSelectEngine->mSelectEngineAOrBSTable);
    if (gSelectEngine->mState == 6 && gSelectEngine->mStateFrames >= 10) {
        return gSelectEngine->mResult;
    }
    return 0;
}

void WriteSelectEngineBg0Offset(void) {
    reg_G2_BG0OFS = (-gSelectEngine->mBg0Offset << 16) & 0x01ff0000;
}
