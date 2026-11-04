#include "01/code_ov001_02197b34.h"

#include "01/code_021956dc.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02116000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02047104.h"

TimeAttackTopMenu *gTimeAttackTopMenu;

void LoadTimeAttackTopMenuData(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Nclr *e = NULL;
    Nscr *f = NULL;

    LoadNcgrData(&d, FindSceneFile(data_ov001_021a835c));
    LoadNclrData(&e, FindSceneFile(data_ov001_021a8360));
    LoadNscrData(&f, FindSceneFile(data_ov001_021a8354));
    LoadNcgrData2(&a, FindSceneFile(data_ov001_021a8350));
    LoadNcerData(&b, FindSceneFile(data_ov001_021a834c));
    LoadNclrData(&c, FindSceneFile(data_ov001_021a8364));
}

void LocateAndQueueTimeAttackTopMenu(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Nscr *e = NULL;

    LocateNcgr(&c, FindSceneFile(data_ov001_021a835c));
    LocateNclr(&d, FindSceneFile(data_ov001_021a8360));
    LocateNscr(&e, FindSceneFile(data_ov001_021a8354));
    gTimeAttackTopMenu->mUnk_10 = HeapAlloc(gTimeAttackTopMenu->mHeap, 0x800);
    gTimeAttackTopMenu->mUnk_04 = FindSceneFile(data_ov001_021a8358);
    gTimeAttackTopMenu->mUnk_08 = FindSceneFile(data_ov001_021a8348);
    LocateNcgr2(&a, FindSceneFile(data_ov001_021a8350));
    LocateNcer(&gTimeAttackTopMenu->mUnk_00, FindSceneFile(data_ov001_021a834c));
    LocateNclr(&b, FindSceneFile(data_ov001_021a8364));
    CallQueueAppend(4, 0, c->mData, c->mDataSize);
    CallQueueAppend(0xf, 0, d->mData, 0x20);
    CallQueueAppend(8, 0, &e->mData, e->mDataSize);
    CallQueueAppend(8, 0x800, gTimeAttackTopMenu->mUnk_10, 0x800);
    CallQueueAppend(0x23, 0, a->mData, a->mDataSize);
    CallQueueAppend(0x1e, 0, b->mData, b->mDataSize);
}

void func_ov001_02198368(void) {
    gTimeAttackTopMenu->mNextState = 0;
    gTimeAttackTopMenu->mUnk_20 = 0;
    gTimeAttackTopMenu->mUnk_24 = -192;
}

void func_ov001_02198354(void) {
    gTimeAttackTopMenu->mNextState = 1;
    gTimeAttackTopMenu->mUnk_20 = 0;
}

void func_ov001_02198338(void) {
    gTimeAttackTopMenu->mNextState = 2;
    gTimeAttackTopMenu->mUnk_20 = 0;
    func_02128374();
}

void func_ov001_02198324(void) {
    gTimeAttackTopMenu->mNextState = 3;
    gTimeAttackTopMenu->mUnk_20 = 0;
}

void func_ov001_021982e8(void) {
    gTimeAttackTopMenu->mNextState = 4;
    gTimeAttackTopMenu->mUnk_20 = 0;
    switch (gTimeAttackTopMenu->mUnk_28) {
        case 1:
        case 2:
            func_021282c8();
            break;
    }
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021982d4(void) {
    gTimeAttackTopMenu->mNextState = 5;
    gTimeAttackTopMenu->mUnk_20 = 0;
}

void func_ov001_0219829c(s32 a) {
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6a18[a], 0xe, gTimeAttackTopMenu->mUnk_00, gTimeAttackTopMenu->mUnk_04);
}

void func_ov001_02198264(s32 a) {
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6a18[a], 0xf, gTimeAttackTopMenu->mUnk_00, gTimeAttackTopMenu->mUnk_04);
}

void InitTimeAttackTopMenu(void *a, void *b, s32 c) {
    void *heap;
    s32 i;

    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & 0x43) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(a);
    gTimeAttackTopMenu = HeapAlloc(heap, 0x38);
    gTimeAttackTopMenu->mHeap = heap;
    gTimeAttackTopMenu->mState = 0;
    gTimeAttackTopMenu->mUnk_2c = b;
    gTimeAttackTopMenu->mUnk_30 = c;
    gTimeAttackTopMenu->mUnk_34 = 0;
    func_ov001_02198368();
    if (func_020cccb4() == 0x1f) {
        if (data_0217b488->mUnk_0c == 0) {
            gTimeAttackTopMenu->mUnk_28 = 1;
        } else {
            gTimeAttackTopMenu->mUnk_28 = 2;
        }
    } else {
        gTimeAttackTopMenu->mUnk_28 = 0;
    }
    LocateAndQueueTimeAttackTopMenu();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6a10[i], 1, gTimeAttackTopMenu->mUnk_00, gTimeAttackTopMenu->mUnk_04);
    }
    func_020ae6d4(gTimeAttackTopMenu->mUnk_2c, (void *) gTimeAttackTopMenu->mUnk_30);
    func_02124ed0(gTimeAttackTopMenu->mHeap, gTimeAttackTopMenu->mUnk_04, NULL, &gTimeAttackTopMenu->mUnk_0c);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = 0xe0;
        func_ov001_02198264(i);
    }
    gTimeAttackTopMenu->mUnk_0c[12].mUnk_04 = 0xe0;
    gTimeAttackTopMenu->mUnk_0c[13].mUnk_04 = 0xe0;
    func_ov001_0219829c(gTimeAttackTopMenu->mUnk_28);
    FrmHeapShrinkInParent(gTimeAttackTopMenu->mHeap);
}

void ReleaseTimeAttackTopMenu(void) {
    HeapDestroy(gTimeAttackTopMenu->mHeap);
    gTimeAttackTopMenu = NULL;
}

void AdvanceTimeAttackTopMenuState0(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mUnk_20++;
    v = func_020ae4c0(1, 0xe0, 0, gTimeAttackTopMenu->mUnk_20, 10);
    gTimeAttackTopMenu->mUnk_24 = func_020ae4c0(1, -192, 0, gTimeAttackTopMenu->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mUnk_0c[12].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[13].mUnk_04 = v;
    if (gTimeAttackTopMenu->mUnk_20 >= 10) {
        func_ov001_02198354();
    }
}

void AdvanceTimeAttackTopMenuState1(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mUnk_20++;
    v = func_020ae488(gTimeAttackTopMenu->mUnk_20);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mUnk_0c[12].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[13].mUnk_04 = v;
    if (gTimeAttackTopMenu->mUnk_20 >= 10) {
        func_ov001_02198338();
    }
}

void AdvanceTimeAttackTopMenuState2(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        func_ov001_02198324();
    }
}

void AdvanceTimeAttackTopMenuState3(void) {
    BOOL flag2 = FALSE;
    u32 sel = -1;
    s32 dir = 3;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL flag1 = FALSE;
    Unk02175628 *e;
    s32 bits;
    BOOL flag4;
    s32 flag3;

    if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
        flag1 = TRUE;
    }
    if (flag1 == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
        flag2 = TRUE;
    }
    if (flag2 != FALSE) {
        sel = RectTableFindContaining(gTimeAttackTopMenu->mUnk_08, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    e = &data_02175628[i];
    bits = e->mUnk_00 & 2;
    if ((u16) bits == 0) {
        flag3 = flag4 = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(0xe);
    func_ov001_021982d4();
    gTimeAttackTopMenu->mUnk_34 = 4;
    func_02128310(0);
    return;
next:
    bits = e->mUnk_00 & 1;
    if ((u16) bits != 0 || sel <= 2) {
        if ((u16) bits == 0) {
            func_ov001_02198264((s32) (gTimeAttackTopMenu->mUnk_28));
            switch (sel) {
                case 0:
                    dir = 0;
                    break;
                case 1:
                    dir = 1;
                    break;
                case 2:
                    dir = 2;
                    break;
            }
            if (gTimeAttackTopMenu->mUnk_28 != dir) {
                gTimeAttackTopMenu->mUnk_28 = dir;
                func_ov001_0219829c((s32) (gTimeAttackTopMenu->mUnk_28));
            }
        } else {
            func_ov001_02198264((s32) (gTimeAttackTopMenu->mUnk_28));
        }
        switch (gTimeAttackTopMenu->mUnk_28) {
            case 0:
                gTimeAttackTopMenu->mUnk_34 = 1;
                break;
            case 1:
                gTimeAttackTopMenu->mUnk_34 = 2;
                break;
            case 2:
                gTimeAttackTopMenu->mUnk_34 = 3;
                break;
        }
        func_ov001_021982e8();
    } else {
        if (func_020ae408(8, 0x40) != 0) {
            func_ov001_02198264((s32) (gTimeAttackTopMenu->mUnk_28));
            gTimeAttackTopMenu->mUnk_28--;
            if (gTimeAttackTopMenu->mUnk_28 < 0) {
                gTimeAttackTopMenu->mUnk_28 = 2;
            }
            func_ov001_0219829c((s32) (gTimeAttackTopMenu->mUnk_28));
            func_0212ecc0(&data_0217d068, 0, 0);
        } else if (func_020ae408(8, 0x80) != 0) {
            func_ov001_02198264((s32) (gTimeAttackTopMenu->mUnk_28));
            gTimeAttackTopMenu->mUnk_28++;
            if (gTimeAttackTopMenu->mUnk_28 >= 3) {
                gTimeAttackTopMenu->mUnk_28 = 0;
            }
            func_ov001_0219829c((s32) (gTimeAttackTopMenu->mUnk_28));
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceTimeAttackTopMenuState4(void) {
    s16 v;

    gTimeAttackTopMenu->mUnk_20++;
    v = func_020ae488(gTimeAttackTopMenu->mUnk_20);
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a08[gTimeAttackTopMenu->mUnk_28]].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a10[gTimeAttackTopMenu->mUnk_28]].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[gTimeAttackTopMenu->mUnk_28]].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a18[gTimeAttackTopMenu->mUnk_28]].mUnk_04 = v;
    switch (gTimeAttackTopMenu->mUnk_28) {
        case 1:
            gTimeAttackTopMenu->mUnk_0c[12].mUnk_04 = v;
            break;
        case 2:
            gTimeAttackTopMenu->mUnk_0c[13].mUnk_04 = v;
            break;
    }
    if (gTimeAttackTopMenu->mUnk_20 == 5) {
        func_ov001_0219829c((s32) (gTimeAttackTopMenu->mUnk_28));
    }
    if (gTimeAttackTopMenu->mUnk_20 >= 10) {
        func_ov001_021982d4();
    }
}

void AdvanceTimeAttackTopMenuState5(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mUnk_20++;
    v = func_020ae4c0(1, 0, 0xe0, gTimeAttackTopMenu->mUnk_20, 10);
    gTimeAttackTopMenu->mUnk_24 = func_020ae4c0(1, 0, -192, gTimeAttackTopMenu->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mUnk_0c[12].mUnk_04 = v;
    gTimeAttackTopMenu->mUnk_0c[13].mUnk_04 = v;
}

s32 AdvanceTimeAttackTopMenu(void) {
    gTimeAttackTopMenu->mState = gTimeAttackTopMenu->mNextState;
    switch (gTimeAttackTopMenu->mState) {
        case 0:
            AdvanceTimeAttackTopMenuState0();
            break;
        case 1:
            AdvanceTimeAttackTopMenuState1();
            break;
        case 2:
            AdvanceTimeAttackTopMenuState2();
            break;
        case 3:
            AdvanceTimeAttackTopMenuState3();
            break;
        case 4:
            AdvanceTimeAttackTopMenuState4();
            break;
        case 5:
            AdvanceTimeAttackTopMenuState5();
            break;
    }
    func_02124c30(gTimeAttackTopMenu->mUnk_04, gTimeAttackTopMenu->mUnk_00, NULL, (void *) gTimeAttackTopMenu->mUnk_30,
                  gTimeAttackTopMenu->mUnk_0c);
    if (gTimeAttackTopMenu->mState == 5 && gTimeAttackTopMenu->mUnk_20 >= 10) {
        return gTimeAttackTopMenu->mUnk_34;
    }
    return 0;
}

void func_ov001_02197b34(void) {
    *(vu32 *) 0x4000010 = (-gTimeAttackTopMenu->mUnk_24 << 16) & 0x1ff0000;
}
