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

    LoadNcgrData(&l6, FindSceneFile(data_ov001_021a94ec));
    LoadNclrData(&l8, FindSceneFile(data_ov001_021a9508));
    LoadNscrData(&l7, FindSceneFile(data_ov001_021a94f0));
    LoadNcgrData2(&l0, FindSceneFile(data_ov001_021a94dc));
    LoadNcerData(&l1, FindSceneFile(data_ov001_021a94e4));
    LoadNclrData(&l2, FindSceneFile(data_ov001_021a950c));
    LoadNcgrData2(&l3, FindSceneFile(data_ov001_021a94f4));
    LoadNcerData(&l4, FindSceneFile(data_ov001_021a94f8));
    LoadNclrData(&l5, FindSceneFile(data_ov001_021a94fc));
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

    LocateNcgr(&e, FindSceneFile(data_ov001_021a94ec));
    LocateNclr(&g, FindSceneFile(data_ov001_021a9508));
    LocateNscr(&f, FindSceneFile(data_ov001_021a94f0));
    gSelectEngine->mUnk_1c = HeapAlloc(gSelectEngine->mHeap, 0x800);
    gSelectEngine->mUnk_04 = FindSceneFile(data_ov001_021a9504);
    LocateNcgr2(&a, FindSceneFile(data_ov001_021a94dc));
    LocateNcer(&gSelectEngine->mUnk_00, FindSceneFile(data_ov001_021a94e4));
    LocateNclr(&b, FindSceneFile(data_ov001_021a950c));
    LocateNcgr2(&c, FindSceneFile(data_ov001_021a94f4));
    LocateNcer(&gSelectEngine->mUnk_08, FindSceneFile(data_ov001_021a94f8));
    LocateNclr(&d, FindSceneFile(data_ov001_021a94fc));
    if (func_02056dec(0x10) != 0) {
        gSelectEngine->mUnk_0c = FindSceneFile(data_ov001_021a94e8);
        gSelectEngine->mUnk_10 = FindSceneFile(data_ov001_021a9510);
    } else {
        gSelectEngine->mUnk_0c = FindSceneFile(data_ov001_021a9500);
        gSelectEngine->mUnk_10 = FindSceneFile(data_ov001_021a94e0);
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
        gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
        for (j = 0; j < 3; j++) {
            gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f68[i]].mUnk_00 = 1;
    }
    gSelectEngine->mUnk_14[6].mUnk_00 = 1;
    gSelectEngine->mUnk_14[data_ov001_021a6f28[gSelectEngine->mIndex]].mUnk_00 = 1;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][0]].mUnk_00 = 1;
        func_02124a98(data_ov001_021a6fa0[i][0], 1, gSelectEngine->mUnk_08, gSelectEngine->mUnk_0c);
    }
    func_02124a98(2, 1, gSelectEngine->mUnk_00, gSelectEngine->mUnk_04);
}

void func_ov001_021a1c34(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 0;
        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 0;
        if (gSelectEngine->mIndex == i && gSelectEngine->mUnk_38 != FALSE) {
            gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 1;
        } else {
            gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 1;
        }
    }
    if (func_02056dec(0x10) == 0) {
        for (i = 0; i < 3; i++) {
            gSelectEngine->mUnk_18[data_ov001_021a6fa0[3][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_021a1bf8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
    }
    gSelectEngine->mUnk_14[data_ov001_021a6f28[gSelectEngine->mIndex]].mUnk_00 = 1;
}

void func_ov001_021a1bb8(void) {
    if (gSelectEngine->mIndex == 3) {
        func_020295c0(data_ov001_021a6f90[2]);
        func_020295b0();
    } else {
        func_020295c0(data_ov001_021a6f90[gSelectEngine->mIndex]);
        func_020295a0();
    }
    func_02029590(0);
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
            v = func_02116d10(7 - gSelectEngine->mUnk_3c, 0);
            for (i = 0; i < 6; i++) {
                gSelectEngine->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = v;
            }
            for (i = 0; i < 4; i++) {
                gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = v;
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
        gSelectEngine->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = 0xc0;
    }
    gSelectEngine->mUnk_14[6].mUnk_06 = -0xc0;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = 0xc0;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = -0xe0;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void func_ov001_021a19f0(void) {
    gSelectEngine->mNextState = 1;
    gSelectEngine->mStateFrames = 0;
}

void func_ov001_021a19dc(void) {
    gSelectEngine->mNextState = 2;
    gSelectEngine->mStateFrames = 0;
}

void func_ov001_021a19c0(void) {
    gSelectEngine->mNextState = 3;
    gSelectEngine->mStateFrames = 0;
    func_02128374();
}

void func_ov001_021a19ac(void) {
    gSelectEngine->mNextState = 4;
    gSelectEngine->mStateFrames = 0;
}

void func_ov001_021a1978(void) {
    gSelectEngine->mNextState = 5;
    gSelectEngine->mStateFrames = 0;
    gSelectEngine->mResult = 1;
    func_ov001_021a1bb8();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a1964(void) {
    gSelectEngine->mNextState = 6;
    gSelectEngine->mStateFrames = 0;
}

void InitSelectEngine(s32 a, void *b, void *c) {
    void *heap;
    SelectEngine *p;
    vu16 *bg0 = (vu16 *) 0x4000008;
    vu16 *bg1 = (vu16 *) 0x400000a;

    *bg0 = (*bg0 & ~3) | 1;
    *bg1 = (*bg1 & ~3) | 1;
    *bg0 = (*bg0 & 0x43) | 0x9004;
    *bg1 = (*bg1 & 0x43) | 0x9204;
    *(vu32 *) 0x4000010 = 0xc00000;
    *(vu32 *) 0x4000014 = 0xc00000;
    heap = CreateFrmHeapFromMaxFree((void *) a);
    p = HeapAlloc(heap, 0x50);
    gSelectEngine = p;
    p->mHeap = heap;
    gSelectEngine->mState = 0;
    gSelectEngine->mUnk_3c = 0;
    gSelectEngine->mUnk_38 = TRUE;
    gSelectEngine->mUnk_44 = b;
    gSelectEngine->mUnk_48 = c;
    gSelectEngine->mResult = 0;
    if (func_0202967c() != 0) {
        gSelectEngine->mIndex = 3;
    } else {
        gSelectEngine->mIndex = data_ov001_021a6f74[func_0202969c()];
    }
    gSelectEngine->mUnk_40 = gSelectEngine->mIndex;
    LocateAndQueueSelectEngine();
    func_020ae6d4(gSelectEngine->mUnk_44, gSelectEngine->mUnk_48);
    func_02124ed0(gSelectEngine->mHeap, gSelectEngine->mUnk_04, NULL, &gSelectEngine->mUnk_14);
    func_02124ed0(gSelectEngine->mHeap, gSelectEngine->mUnk_0c, NULL, &gSelectEngine->mUnk_18);
    func_ov001_021a1cb0();
    func_ov001_021a1bf8();
    func_ov001_021a1a04();
    FrmHeapShrinkInParent((void *) gSelectEngine->mHeap);
}

void ReleaseSelectEngine(void) {
    HeapDestroy((void *) gSelectEngine->mHeap);
    gSelectEngine = NULL;
}

void AdvanceSelectEngineState0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_ov001_021a19f0();
    }
    return;
}

void AdvanceSelectEngineState1(void) {
    s16 a;
    s16 b;
    s32 j;
    s32 i;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    a = func_020ae4c0(1, 0xe0, 0, gSelectEngine->mStateFrames, 10);
    b = func_020ae4c0(1, -0xc0, 0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -b;
    for (i = 0; i < 6; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = -b;
    }
    gSelectEngine->mUnk_14[6].mUnk_06 = b;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = -b;
        if (func_02056dec(0x10)) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = a;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = a;
            }
        }
    }
    if (gSelectEngine->mStateFrames >= 10) {
        func_ov001_021a19dc();
    }
}

void AdvanceSelectEngineState2(void) {
    s16 x;
    s32 j;
    gSelectEngine->mStateFrames = gSelectEngine->mStateFrames + 1;
    x = func_020ae488(gSelectEngine->mStateFrames);
    gSelectEngine->mBg0Offset = x;
    for (j = 0; j < 6; j++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f68[j]].mUnk_06 = x;
    }
    for (j = 0; j < 4; j++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f28[j]].mUnk_06 = x;
    }
    if (gSelectEngine->mStateFrames >= 10) {
        func_ov001_021a19c0();
    }
}

void AdvanceSelectEngineState3(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        func_ov001_021a19ac();
    }
    return;
}

void AdvanceSelectEngineState4(void) {
    u32 r5 = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
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
        r5 = RectTableFindContaining(gSelectEngine->mUnk_10, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        a2 = b2 = FALSE;
        w = data_02175628[idx].mHasPair;
        if (w == 0 && data_02175628[idx].mNoPairCount < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[idx].mPrevHasPair == 0 && w != 0) {
            b2 = TRUE;
        }
        if (b2 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                           data_02175628[idx].mUnk_4a) == FALSE) {
            goto next;
        }
    }
    if (func_ov001_021a1ba0() != 0) {
        return;
    }
    func_021281c8(0xe);
    func_ov001_021a1964();
    gSelectEngine->mResult = 2;
    func_02128310(0);
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
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0) {
        gSelectEngine->mUnk_38 = FALSE;
        func_ov001_021a1978();
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (func_02056dec(0x10) != 0) {
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
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        if (func_02056dec(0x10) != 0) {
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
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        if (func_02056dec(0x10) != 0) {
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
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (func_02056dec(0x10) != 0) {
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
            func_0212ecc0(&data_0217d068, 0, 0);
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
            func_ov001_021a1964();
        }
    }
}

void AdvanceSelectEngineState6(void) {
    s16 a;
    s16 b;
    s32 i;
    s32 k;

    gSelectEngine->mStateFrames++;
    a = func_020ae4c0(1, 0, 0xc0, gSelectEngine->mStateFrames, 10);
    b = func_020ae4c0(1, 0, -0xc0, gSelectEngine->mStateFrames, 10);
    gSelectEngine->mBg0Offset = -b;
    for (i = 0; i < 6; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = -b;
    }
    gSelectEngine->mUnk_14[6].mUnk_06 = b;
    for (i = 0; i < 4; i++) {
        gSelectEngine->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = -b;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (k = 0; k < 3; k++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (k = 0; k < 3; k++) {
                        gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
                    }
                    break;
            }
        } else {
            for (k = 0; k < 3; k++) {
                gSelectEngine->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
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
    func_02124c30(gSelectEngine->mUnk_04, gSelectEngine->mUnk_00, NULL, gSelectEngine->mUnk_44, gSelectEngine->mUnk_14);
    func_02124c30(gSelectEngine->mUnk_0c, gSelectEngine->mUnk_08, NULL, gSelectEngine->mUnk_48, gSelectEngine->mUnk_18);
    if (gSelectEngine->mState == 6 && gSelectEngine->mStateFrames >= 10) {
        return gSelectEngine->mResult;
    }
    return 0;
}

void WriteSelectEngineBg0Offset(void) {
    reg_G2_BG0OFS = (-gSelectEngine->mBg0Offset << 16) & 0x01ff0000;
}
