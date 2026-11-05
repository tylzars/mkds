#include "01/code_02198854.h"
#include "01/code_02199964.h"
#include "01/code_0219853c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/code_0219e824.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "01/code_02192e78.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_02148950.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"
#include "registers.h"

OptionSelectMenu *gOptionSelectMenu;

void func_ov001_021997dc(void) {
    s32 i;

    {
        s32 v0 = 0x8000;
        u8 a[2][2] = {{0xdc, 0x10}, {0xf0, 0x50}};
        s32 c[2] = {0xb, 0xc};

        for (i = 0; i < 2; i++) {
            v0 -= func_021243ac(gOptionSelectMenu->mHeap, data_ov001_021a6a24[i],
                                gOptionSelectMenu->mOptionSelectMenuMBnll, a[i][0], a[i][1], i,
                                gOptionSelectMenu->mOptionSelectMenuMNcer, gOptionSelectMenu->mOptionSelectMenuMBncl,
                                gOptionSelectMenu->mOptionSelectMenuMTable, v0);
            func_0212426c(0, data_ov001_021a6a24[i], gOptionSelectMenu->mOptionSelectMenuMBnll,
                          GetBmgEntry(gOptionSelectMenu->mOptionMessages, c[i]),
                          gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMTable);
        }
    }
    {
        s32 v2 = func_02148ca0();
        void *v1;
        u8 b[3][2] = {{0x9b, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
        s32 d[3] = {0, 2, 4};

        for (i = 0; i < 3; i++) {
            v1 = gOptionSelectMenu->mOptionMessages;
            if (i == 2) {
                v1 = gOptionSelectMenu->mCommonMessages;
            }
            v2 -= func_021243ac(gOptionSelectMenu->mHeap, data_ov001_021a6a34[i],
                                gOptionSelectMenu->mOptionSelectMenuSBnll, b[i][0], b[i][1], data_ov001_021a6a30[i],
                                gOptionSelectMenu->mOptionSelectMenuSNcer, gOptionSelectMenu->mOptionSelectMenuSBncl,
                                gOptionSelectMenu->mOptionSelectMenuSTable, v2);
            func_0212426c(1, data_ov001_021a6a34[i], gOptionSelectMenu->mOptionSelectMenuSBnll, GetBmgEntry(v1, d[i]),
                          gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSTable);
        }
    }
}

void InitOptionSelectMenu(void *a) {
    s32 i;

    gOptionSelectMenu = HeapAlloc(a, 0x90);
    gOptionSelectMenu->mHeap = a;
    gOptionSelectMenu->mState = 0;
    gOptionSelectMenu->mNextState = 0;
    gOptionSelectMenu->mIndex = 0;
    gOptionSelectMenu->mStateFrames = 0;
    gOptionSelectMenu->mUnk_38 = TRUE;
    LocateAndQueueOptionSelectMenu();
    func_0212b928(a, gOptionSelectMenu->mOptionSelectMenuSONclr, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6a28[i], 1, gOptionSelectMenu->mOptionSelectMenuSNcer,
                      gOptionSelectMenu->mOptionSelectMenuSBncl);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(a, gOptionSelectMenu->mOptionSelectMenuMBncl, gOptionSelectMenu->mOptionSelectMenuMBnll,
                  &gOptionSelectMenu->mOptionSelectMenuMTable);
    func_02124ed0(a, gOptionSelectMenu->mOptionSelectMenuSBncl, gOptionSelectMenu->mOptionSelectMenuSBnll,
                  &gOptionSelectMenu->mOptionSelectMenuSTable);
    gOptionSelectMenu->mOptionMessages = FindSceneFile(data_ov001_021a8644);
    gOptionSelectMenu->mCommonMessages = func_02047a28(data_ov001_021a8650);
    func_ov001_021997dc();
    gOptionSelectMenu->mUnk_24 = -140;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = 0;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0x28;
        } else if (i == 1) {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = 250;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0;
        } else {
            gOptionSelectMenu->mUnk_26[i].mUnk_00 = -250;
            gOptionSelectMenu->mUnk_26[i].mUnk_02 = 0;
        }
    }
    func_ov001_02199374();
    if (data_0217aa08->mUnk_00->mUnk_31_4 == 0) {
        gOptionSelectMenu->mUnk_0c[1] = 0;
    } else {
        gOptionSelectMenu->mUnk_0c[1] = 1;
    }
    for (i = 0; i < 2; i++) {
        gOptionSelectMenu->mUnk_14[i] = gOptionSelectMenu->mUnk_0c[i];
    }
    func_ov001_02198bbc();
    func_ov001_02198b58();
    for (i = 0; i < 2; i++) {
        gOptionSelectMenu->mUnk_40[i][0] = 0;
        gOptionSelectMenu->mUnk_40[i][1] = 0;
    }
    gOptionSelectMenu->mUnk_1c = FALSE;
    gOptionSelectMenu->mUnk_3c = TRUE;
    func_021281c8(0xe);
}

void ReleaseOptionSelectMenu(void) {
    u32 v;

    func_ov001_02199374();
    func_ov001_02199420();
    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~2) << 8);
    func_0212b91c();
    gOptionSelectMenu = NULL;
}

void LocateAndQueueOptionSelectMenu(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile(data_ov001_021a84ac));
    LocateNscr(&b, FindSceneFile(data_ov001_021a84c8));
    LocateNclr(&c, FindSceneFile(data_ov001_021a84e4));
    gOptionSelectMenu->mOptionSelectMenuMBncl = FindSceneFile(data_ov001_021a8500);
    gOptionSelectMenu->mOptionSelectMenuSBncl = FindSceneFile(data_ov001_021a851c);
    gOptionSelectMenu->mOptionSelectMenuSBnbl = FindSceneFile(data_ov001_021a8538);
    gOptionSelectMenu->mOptionSelectMenuMBnll = FindSceneFile(data_ov001_021a8554);
    gOptionSelectMenu->mOptionSelectMenuSBnll = FindSceneFile(data_ov001_021a8570);
    LocateNcgr2(&gOptionSelectMenu->mOptionSelectMenuMNcgr, FindSceneFile(data_ov001_021a858c));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuMNcer, FindSceneFile(data_ov001_021a85ac));
    LocateNclr(&gOptionSelectMenu->mOptionSelectMenuMONclr, FindSceneFile(data_ov001_021a85cc));
    LocateNcgr2(&gOptionSelectMenu->mOptionSelectMenuSNcgr, FindSceneFile(data_ov001_021a85e8));
    LocateNcer(&gOptionSelectMenu->mOptionSelectMenuSNcer, FindSceneFile(data_ov001_021a8608));
    LocateNclr(&gOptionSelectMenu->mOptionSelectMenuSONclr, FindSceneFile(data_ov001_021a8628));
    CallQueueAppend(5, 0, a->mData, a->mDataSize);
    CallQueueAppend(9, 0, b->mData, b->mDataSize);
    CallQueueAppend(0xf, 0x20, c->mData + 0x10, 0x20);
    CallQueueAppend(0x13, 0, gOptionSelectMenu->mOptionSelectMenuMNcgr->mData,
                    gOptionSelectMenu->mOptionSelectMenuMNcgr->mDataSize);
    CallQueueAppend(0x23, 0, gOptionSelectMenu->mOptionSelectMenuSNcgr->mData,
                    gOptionSelectMenu->mOptionSelectMenuSNcgr->mDataSize);
    CallQueueAppend(0xe, 0, gOptionSelectMenu->mOptionSelectMenuMONclr->mData,
                    gOptionSelectMenu->mOptionSelectMenuMONclr->mDataSize);
    CallQueueAppend(0x1e, 0, gOptionSelectMenu->mOptionSelectMenuSONclr->mData,
                    gOptionSelectMenu->mOptionSelectMenuSONclr->mDataSize);
}

void func_ov001_02199420(void) {
    switch (gOptionSelectMenu->mUnk_0c[0]) {
        case 1:
            func_02108e94(0);
            break;
        case 0:
            func_02108e94(1);
            break;
        case 2:
            func_02108e94(2);
            break;
    }
}

void func_ov001_021993b8(void) {
    switch (gOptionSelectMenu->mUnk_0c[0]) {
        case 1:
            data_0217aa08->mUnk_00->mUnk_31_1 = 1;
            break;
        case 0:
            data_0217aa08->mUnk_00->mUnk_31_1 = 0;
            break;
        case 2:
            data_0217aa08->mUnk_00->mUnk_31_1 = 2;
            break;
    }
}

void func_ov001_02199374(void) {
    switch (data_0217aa08->mUnk_00->mUnk_31_1) {
        case 1:
            gOptionSelectMenu->mUnk_0c[0] = 1;
            break;
        case 0:
            gOptionSelectMenu->mUnk_0c[0] = 0;
            break;
        case 2:
            gOptionSelectMenu->mUnk_0c[0] = 2;
            break;
    }
}

void AdvanceOptionSelectMenuState0(void) {
    s32 i;
    s32 j;
    s16 v;

    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mUnk_24 = func_020ae4c0(1, -140, 0, gOptionSelectMenu->mStateFrames, 10);
    v = func_020ae4c0(1, 250, 0, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = -v;
            } else {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = v;
            }
        }
    }
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 1;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState1(void) {
    gOptionSelectMenu->mStateFrames++;
    gOptionSelectMenu->mUnk_26[2].mUnk_02 = -func_0212825c(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 2;
        gOptionSelectMenu->mStateFrames = 0;
    }
}

void AdvanceOptionSelectMenuState2(void) {
    OptionSelectMenu *p;
    s32 sel;
    s32 r5;
    BOOL hasB;
    BOOL hasA;
    s32 i;
    Unk02175628Index idx;
    u16 v;

    p = gOptionSelectMenu;
    sel = p->mIndex;
    idx = UNK_02175628_INDEX_8;
    hasB = FALSE;
    r5 = -1;
    hasA = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        hasA = TRUE;
    }
    if (hasA == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
        hasB = TRUE;
    }
    if (hasB != FALSE) {
        r5 = RectTableFindContaining(p->mOptionSelectMenuSBnbl, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) != 0) {
        goto L1;
    } else {
        BOOL c = FALSE;
        BOOL d = FALSE;
        v = data_02175628[idx].mHasPair;
        if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
            d = TRUE;
        }
        if (d == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
            c = TRUE;
        }
        if (c != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                          data_02175628[idx].mUnk_4a) != FALSE) {
        L1:
            gOptionSelectMenu->mNextState = 4;
            gOptionSelectMenu->mNextOptionState = 0;
            for (i = 0; i < 2; i++) {
                gOptionSelectMenu->mUnk_0c[i] = gOptionSelectMenu->mUnk_14[i];
            }
            func_02128310(0);
            goto end;
        }
    }
    if (((u16) (data_02175628[idx].mUnk_00 & 1) != 0 && gOptionSelectMenu->mIndex == 2) || r5 == 2) {
        func_ov001_021993b8();
        if (gOptionSelectMenu->mUnk_0c[1] == 0) {
            data_0217aa08->mUnk_00->mUnk_31 &= ~0x10;
        } else {
            data_0217aa08->mUnk_00->mUnk_31 |= 0x10;
        }
        func_02056d40();
        if (gOptionSelectMenu->mIndex == 2) {
            gOptionSelectMenu->mUnk_38 = FALSE;
        }
        gOptionSelectMenu->mNextState = 3;
        gOptionSelectMenu->mNextOptionState = 0;
        gOptionSelectMenu->mIndex = 2;
        gOptionSelectMenu->mUnk_1c = TRUE;
        func_0212b7e8();
        func_02105ac0(5);
    } else if (r5 == 0) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]++;
        func_02105ac0(10);
    } else if (r5 == 1) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]++;
        func_02105ac0(1);
    } else if (func_020ae408(8, 0x40) != 0) {
        gOptionSelectMenu->mIndex--;
        if (gOptionSelectMenu->mIndex < 0) {
            gOptionSelectMenu->mIndex = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0 ||
               (gOptionSelectMenu->mIndex != 2 && (u16) (data_02175628[idx].mUnk_00 & 1) != 0)) {
        gOptionSelectMenu->mIndex++;
        if (gOptionSelectMenu->mIndex > 2) {
            gOptionSelectMenu->mIndex = 0;
        }
        func_02105ac0(0);
    } else if (gOptionSelectMenu->mIndex != 2 && func_020ae408(8, 0x20) != 0) {
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][0] = 6;
        if (gOptionSelectMenu->mIndex == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (gOptionSelectMenu->mIndex != 2 && func_020ae408(8, 0x10) != 0) {
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]++;
        if (func_020ae408(8, 0x10) != 0) {
            gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][1] = 6;
        }
        if (gOptionSelectMenu->mIndex == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (r5 == 3) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][0] = 6;
        func_02105ac0(10);
    } else if (r5 == 4) {
        gOptionSelectMenu->mIndex = 0;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][1] = 6;
        func_02105ac0(10);
    } else if (r5 == 5) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]--;
        gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][0] = 6;
        func_02105ac0(1);
    } else if (r5 == 6) {
        gOptionSelectMenu->mIndex = 1;
        gOptionSelectMenu->mUnk_0c[gOptionSelectMenu->mIndex]++;
        gOptionSelectMenu->mUnk_40[gOptionSelectMenu->mIndex][1] = 6;
        func_02105ac0(1);
    }
end:
    if (gOptionSelectMenu->mUnk_0c[0] < 0) {
        gOptionSelectMenu->mUnk_0c[0] = 2;
    }
    if (gOptionSelectMenu->mUnk_0c[0] > 2) {
        gOptionSelectMenu->mUnk_0c[0] = 0;
    }
    if (gOptionSelectMenu->mUnk_0c[1] < 0) {
        gOptionSelectMenu->mUnk_0c[1] = 1;
    }
    if (gOptionSelectMenu->mUnk_0c[1] > 1) {
        gOptionSelectMenu->mUnk_0c[1] = 0;
    }
    if (gOptionSelectMenu->mIndex == 2 && sel != 2) {
        func_0212b7fc();
    }
    func_ov001_02199420();
}

void AdvanceOptionSelectMenuState3(void) {
    gOptionSelectMenu->mStateFrames++;
    if (gOptionSelectMenu->mStateFrames >= 10) {
        gOptionSelectMenu->mNextState = 4;
        gOptionSelectMenu->mStateFrames = 0;
    } else if (gOptionSelectMenu->mStateFrames >= 5) {
        gOptionSelectMenu->mUnk_38 = TRUE;
    }
}

void AdvanceOptionSelectMenuState4(void) {
    s32 i;
    s32 j;
    s16 t;
    void *a;
    void *b;

    gOptionSelectMenu->mUnk_24 = func_020ae4c0(1, 0, -0x8c, gOptionSelectMenu->mStateFrames, 10);
    gOptionSelectMenu->mStateFrames++;
    t = func_020ae4c0(1, 0, 250, gOptionSelectMenu->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = -t;
            } else {
                gOptionSelectMenu->mUnk_26[i].mUnk_00 = t;
            }
        }
    }
    gOptionSelectMenu->mUnk_26[2].mUnk_02 = -func_02128244(gOptionSelectMenu->mStateFrames);
    if (gOptionSelectMenu->mStateFrames >= 10) {
        if (gOptionSelectMenu->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
            gOptionSelectMenu->mUnk_3c = FALSE;
            if (gOptionSelectMenu->mUnk_1c != FALSE) {
                func_02125ebc(0x21);
                a = GetBmgEntry(gOptionSelectMenu->mOptionMessages, 0x10);
                b = GetBmgEntry(gOptionSelectMenu->mCommonMessages, 4);
                func_02126230(a, b);
                gOptionSelectMenu->mNextState = 5;
                gOptionSelectMenu->mStateFrames = 0;
                func_021282c8();
            } else {
                RequestOptionState(gOptionSelectMenu->mNextOptionState);
            }
        }
    }
}

void AdvanceOptionSelectMenuState5(void) {
    s32 r;

    if (func_02125f54() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                r = data_021759d4->mUnk_10;
            } else {
                r = 0;
            }
        } else {
            r = 1;
        }
        if (r == 0) {
            func_02125ebc(0x23);
            func_02125fc0();
            func_02128374();
        }
    }
    if (func_02125f88() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        RequestOptionState(gOptionSelectMenu->mNextOptionState);
    }
}

void func_ov001_02198bbc(void) {
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = gOptionSelectMenu->mOptionSelectMenuMBncl->mUnk_06;
    b = gOptionSelectMenu->mOptionSelectMenuSBncl->mUnk_06;
    for (i = 0; i < 1; i++) {
        gOptionSelectMenu->mOptionSelectMenuMTable[data_ov001_021a6a20[i]].mUnk_06 = gOptionSelectMenu->mUnk_24;
    }
    for (i = 0; i < 2; i++) {
        (gOptionSelectMenu->mOptionSelectMenuMTable + a)[data_ov001_021a6a24[i]].mUnk_06 = gOptionSelectMenu->mUnk_24;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a5c[i][j]].mUnk_04 =
                gOptionSelectMenu->mUnk_26[i].mUnk_00;
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a5c[i][j]].mUnk_06 =
                gOptionSelectMenu->mUnk_26[i].mUnk_02;
        }
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[data_ov001_021a6a34[i]].mUnk_04 =
            gOptionSelectMenu->mUnk_26[i].mUnk_00;
        (gOptionSelectMenu->mOptionSelectMenuSTable + b)[data_ov001_021a6a34[i]].mUnk_06 =
            gOptionSelectMenu->mUnk_26[i].mUnk_02;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][j][0]].mUnk_04 -=
                func_020adc64(6 - gOptionSelectMenu->mUnk_40[i][0]);
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][j][1]].mUnk_04 +=
                func_020adc64(6 - gOptionSelectMenu->mUnk_40[i][1]);
        }
    }
}

void func_ov001_02198b58(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a2c[i]; j++) {
            if (j == gOptionSelectMenu->mUnk_0c[i]) {
                gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a38[i][j]].mUnk_00 = 1;
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a38[i][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_ov001_02198a6c(void) {
    s32 i;
    s32 k;

    for (i = 0; i < 3; i++) {
        if (i == gOptionSelectMenu->mIndex && gOptionSelectMenu->mUnk_38 != FALSE) {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a30[i]].mUnk_00 = 1;
            func_02124100(data_ov001_021a6a34[i], 14, gOptionSelectMenu->mOptionSelectMenuSBnll,
                          gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 14, gOptionSelectMenu->mOptionSelectMenuSNcer,
                              gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        } else {
            gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a30[i]].mUnk_00 = 0;
            func_02124100(data_ov001_021a6a34[i], 15, gOptionSelectMenu->mOptionSelectMenuSBnll,
                          gOptionSelectMenu->mOptionSelectMenuSTable, gOptionSelectMenu->mOptionSelectMenuSBncl);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 15, gOptionSelectMenu->mOptionSelectMenuSNcer,
                              gOptionSelectMenu->mOptionSelectMenuSBncl);
            }
        }
    }
}

void func_ov001_021989bc(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (i == gOptionSelectMenu->mIndex) {
                if (gOptionSelectMenu->mUnk_40[i][j] > 0) {
                    gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][0][j]].mUnk_00 = 1;
                    gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                    gOptionSelectMenu->mUnk_40[i][j]--;
                } else {
                    gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                    gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                }
            } else {
                gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                gOptionSelectMenu->mOptionSelectMenuSTable[data_ov001_021a6a50[i][1][j]].mUnk_00 = 0;
            }
        }
    }
}

void AdvanceOptionSelectMenu(void) {
    OptionSelectMenu *p;

    gOptionSelectMenu->mState = gOptionSelectMenu->mNextState;
    switch (gOptionSelectMenu->mState) {
        case 0:
            AdvanceOptionSelectMenuState0();
            break;
        case 1:
            AdvanceOptionSelectMenuState1();
            break;
        case 2:
            AdvanceOptionSelectMenuState2();
            break;
        case 3:
            AdvanceOptionSelectMenuState3();
            break;
        case 4:
            AdvanceOptionSelectMenuState4();
            break;
        case 5:
            AdvanceOptionSelectMenuState5();
            break;
    }
    func_0212b80c();
    func_ov001_02198bbc();
    func_ov001_02198b58();
    func_ov001_02198a6c();
    func_ov001_021989bc();
    p = gOptionSelectMenu;
    func_02124c30(p->mOptionSelectMenuMBncl, p->mOptionSelectMenuMNcer, p->mOptionSelectMenuMBnll,
                  func_ov001_0219e920(), p->mOptionSelectMenuMTable);
    p = gOptionSelectMenu;
    func_02124c30(p->mOptionSelectMenuSBncl, p->mOptionSelectMenuSNcer, p->mOptionSelectMenuSBnll,
                  func_ov001_0219e90c(), p->mOptionSelectMenuSTable);
}

void func_ov001_02198878(void) {
    u32 plane;

    if (gOptionSelectMenu->mUnk_3c != FALSE) {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane |= 2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    } else {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane &= ~2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    }
    func_0214a40c((u32 *) 0x4001050, 0, 2, 6, 10);
    *(vu32 *) 0x4000010 = (-gOptionSelectMenu->mUnk_24 << 16) & 0x1ff0000;
    *(vu32 *) 0x4000014 = (-gOptionSelectMenu->mUnk_24 << 16) & 0x1ff0000;
}

void RegisterOptionSelectMenuCallbacks(void) {
    UnkFunc *table[4] = {InitOptionSelectMenu, ReleaseOptionSelectMenu, AdvanceOptionSelectMenu, func_ov001_02198878};

    SetOptionStateCallbacks((table));
}
