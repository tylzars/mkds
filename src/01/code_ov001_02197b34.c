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
#include "registers.h"

TimeAttackTopMenu *gTimeAttackTopMenu;

void LoadTimeAttackTopMenuData(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Nclr *e = NULL;
    Nscr *f = NULL;

    LoadNcgrData(&d, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LoadNclrData(&e, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LoadNscrData(&f, FindSceneFile(gTimeAttackTopMenuMNscrName));
    LoadNcgrData2(&a, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LoadNcerData(&b, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LoadNclrData(&c, FindSceneFile(gTimeAttackTopMenuSONclrName));
}

void LocateAndQueueTimeAttackTopMenu(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Nscr *e = NULL;

    LocateNcgr(&c, FindSceneFile(gTimeAttackTopMenuMBNcgrName));
    LocateNclr(&d, FindSceneFile(gTimeAttackTopMenuMBNclrName));
    LocateNscr(&e, FindSceneFile(gTimeAttackTopMenuMNscrName));
    gTimeAttackTopMenu->mUnk_10 = HeapAlloc(gTimeAttackTopMenu->mHeap, 0x800);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBncl = FindSceneFile(gTimeAttackTopMenuSBnclName);
    gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl = FindSceneFile(gTimeAttackTopMenuSBnblName);
    LocateNcgr2(&a, FindSceneFile(gTimeAttackTopMenuSNcgrName));
    LocateNcer(&gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, FindSceneFile(gTimeAttackTopMenuSNcerName));
    LocateNclr(&b, FindSceneFile(gTimeAttackTopMenuSONclrName));
    CallQueueAppend(4, 0, c->mData, c->mDataSize);
    CallQueueAppend(0xf, 0, d->mData, 0x20);
    CallQueueAppend(8, 0, &e->mData, e->mDataSize);
    CallQueueAppend(8, 0x800, gTimeAttackTopMenu->mUnk_10, 0x800);
    CallQueueAppend(0x23, 0, a->mData, a->mDataSize);
    CallQueueAppend(0x1e, 0, b->mData, b->mDataSize);
}

void func_ov001_02198368(void) {
    gTimeAttackTopMenu->mNextState = 0;
    gTimeAttackTopMenu->mStateFrames = 0;
    gTimeAttackTopMenu->mBg0Offset = -192;
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState1.
void RequestTimeAttackTopMenuState1(void) {
    gTimeAttackTopMenu->mNextState = 1;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void func_ov001_02198338(void) {
    gTimeAttackTopMenu->mNextState = 2;
    gTimeAttackTopMenu->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState3.
void RequestTimeAttackTopMenuState3(void) {
    gTimeAttackTopMenu->mNextState = 3;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void func_ov001_021982e8(void) {
    gTimeAttackTopMenu->mNextState = 4;
    gTimeAttackTopMenu->mStateFrames = 0;
    switch (gTimeAttackTopMenu->mIndex) {
        case 1:
        case 2:
            RequestSelectReturnState4();
            break;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

// Requests state 5: stores mNextState = 5 and zeroes mStateFrames; the next AdvanceTimeAttackTopMenu call copies it to
// mState and runs AdvanceTimeAttackTopMenuState5.
void RequestTimeAttackTopMenuState5(void) {
    gTimeAttackTopMenu->mNextState = 5;
    gTimeAttackTopMenu->mStateFrames = 0;
}

void func_ov001_0219829c(s32 a) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6a18[a], 0xe, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                  gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void func_ov001_02198264(s32 a) {
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6a18[a], 0xf, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                  gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
}

void InitTimeAttackTopMenu(void *a, void *b, s32 c) {
    void *heap;
    s32 i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    heap = CreateFrmHeapFromMaxFree(a);
    gTimeAttackTopMenu = HeapAlloc(heap, 0x38);
    gTimeAttackTopMenu->mHeap = heap;
    gTimeAttackTopMenu->mState = 0;
    gTimeAttackTopMenu->mUnk_2c = b;
    gTimeAttackTopMenu->mUnk_30 = c;
    gTimeAttackTopMenu->mResult = 0;
    func_ov001_02198368();
    if (GetPreviousMenuScreenNumber() == 0x1f) {
        if (data_0217b488->mUnk_0c == 0) {
            gTimeAttackTopMenu->mIndex = 1;
        } else {
            gTimeAttackTopMenu->mIndex = 2;
        }
    } else {
        gTimeAttackTopMenu->mIndex = 0;
    }
    LocateAndQueueTimeAttackTopMenu();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6a10[i], 1, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer,
                      gTimeAttackTopMenu->mTimeAttackTopMenuSBncl);
    }
    func_020ae6d4(gTimeAttackTopMenu->mUnk_2c, (void *) gTimeAttackTopMenu->mUnk_30);
    func_02124ed0(gTimeAttackTopMenu->mHeap, gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, NULL,
                  &gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a08[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a10[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[i]].mUnk_04 = 0xe0;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a18[i]].mUnk_04 = 0xe0;
        func_ov001_02198264(i);
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mUnk_04 = 0xe0;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mUnk_04 = 0xe0;
    func_ov001_0219829c(gTimeAttackTopMenu->mIndex);
    FrmHeapShrinkInParent(gTimeAttackTopMenu->mHeap);
}

void ReleaseTimeAttackTopMenu(void) {
    HeapDestroy(gTimeAttackTopMenu->mHeap);
    gTimeAttackTopMenu = NULL;
}

void AdvanceTimeAttackTopMenuState0(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    v = InterpolateS16(1, 0xe0, 0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, -192, 0, gTimeAttackTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mUnk_04 = v;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuState1();
    }
}

void AdvanceTimeAttackTopMenuState1(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    v = func_020ae488(gTimeAttackTopMenu->mStateFrames);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mUnk_04 = v;
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        func_ov001_02198338();
    }
}

void AdvanceTimeAttackTopMenuState2(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestTimeAttackTopMenuState3();
    }
}

void AdvanceTimeAttackTopMenuState3(void) {
    BOOL flag2 = FALSE;
    u32 sel = -1;
    s32 dir = 3;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL flag1 = FALSE;
    InputSlot *e;
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
        sel = RectTableFindContaining(gTimeAttackTopMenu->mTimeAttackTopMenuSBnbl, data_02175628[i].mPairX,
                                      data_02175628[i].mPairY);
    }
    e = &data_02175628[i];
    bits = e->mUnk_00 & PAD_KEY_B;
    if ((u16) bits == 0) {
        flag3 = flag4 = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                              data_02175628[i].mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    RequestTimeAttackTopMenuState5();
    gTimeAttackTopMenu->mResult = 4;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    bits = e->mUnk_00 & PAD_KEY_A;
    if ((u16) bits != 0 || sel <= 2) {
        if ((u16) bits == 0) {
            func_ov001_02198264(gTimeAttackTopMenu->mIndex);
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
            if (gTimeAttackTopMenu->mIndex != dir) {
                gTimeAttackTopMenu->mIndex = dir;
                func_ov001_0219829c(gTimeAttackTopMenu->mIndex);
            }
        } else {
            func_ov001_02198264(gTimeAttackTopMenu->mIndex);
        }
        switch (gTimeAttackTopMenu->mIndex) {
            case 0:
                gTimeAttackTopMenu->mResult = 1;
                break;
            case 1:
                gTimeAttackTopMenu->mResult = 2;
                break;
            case 2:
                gTimeAttackTopMenu->mResult = 3;
                break;
        }
        func_ov001_021982e8();
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            func_ov001_02198264(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex--;
            if (gTimeAttackTopMenu->mIndex < 0) {
                gTimeAttackTopMenu->mIndex = 2;
            }
            func_ov001_0219829c(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            func_ov001_02198264(gTimeAttackTopMenu->mIndex);
            gTimeAttackTopMenu->mIndex++;
            if (gTimeAttackTopMenu->mIndex >= 3) {
                gTimeAttackTopMenu->mIndex = 0;
            }
            func_ov001_0219829c(gTimeAttackTopMenu->mIndex);
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceTimeAttackTopMenuState4(void) {
    s16 v;

    gTimeAttackTopMenu->mStateFrames++;
    v = func_020ae488(gTimeAttackTopMenu->mStateFrames);
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a08[gTimeAttackTopMenu->mIndex]].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a10[gTimeAttackTopMenu->mIndex]].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[gTimeAttackTopMenu->mIndex]].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a18[gTimeAttackTopMenu->mIndex]].mUnk_04 = v;
    switch (gTimeAttackTopMenu->mIndex) {
        case 1:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mUnk_04 = v;
            break;
        case 2:
            gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mUnk_04 = v;
            break;
    }
    if (gTimeAttackTopMenu->mStateFrames == 5) {
        func_ov001_0219829c(gTimeAttackTopMenu->mIndex);
    }
    if (gTimeAttackTopMenu->mStateFrames >= 10) {
        RequestTimeAttackTopMenuState5();
    }
}

void AdvanceTimeAttackTopMenuState5(void) {
    s16 v;
    s32 i;

    gTimeAttackTopMenu->mStateFrames++;
    v = InterpolateS16(1, 0, 0xe0, gTimeAttackTopMenu->mStateFrames, 10);
    gTimeAttackTopMenu->mBg0Offset = InterpolateS16(1, 0, -192, gTimeAttackTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a08[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a10[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a00[i]].mUnk_04 = v;
        gTimeAttackTopMenu->mTimeAttackTopMenuSTable[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[12].mUnk_04 = v;
    gTimeAttackTopMenu->mTimeAttackTopMenuSTable[13].mUnk_04 = v;
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
    func_02124c30(gTimeAttackTopMenu->mTimeAttackTopMenuSBncl, gTimeAttackTopMenu->mTimeAttackTopMenuSNcer, NULL,
                  (void *) gTimeAttackTopMenu->mUnk_30, gTimeAttackTopMenu->mTimeAttackTopMenuSTable);
    if (gTimeAttackTopMenu->mState == 5 && gTimeAttackTopMenu->mStateFrames >= 10) {
        return gTimeAttackTopMenu->mResult;
    }
    return 0;
}

void WriteTimeAttackTopMenuBg0Offset(void) {
    reg_G2_BG0OFS = (-gTimeAttackTopMenu->mBg0Offset << 16) & 0x1ff0000;
}
