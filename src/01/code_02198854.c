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
#include "Main/Unknown/code_0212b5ec.h"
#include "Main/Unknown/code_0212b91c.h"
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

void func_ov001_021997dc(void) {
    s32 i;

    {
        s32 v0 = 0x8000;
        u8 a[2][2] = {{0xdc, 0x10}, {0xf0, 0x50}};
        s32 c[2] = {0xb, 0xc};

        for (i = 0; i < 2; i++) {
            v0 -= func_021243ac(data_ov001_021a9be8->mUnk_50, data_ov001_021a6a24[i], data_ov001_021a9be8->mUnk_80,
                                a[i][0], a[i][1], i, data_ov001_021a9be8->mUnk_5c, data_ov001_021a9be8->mUnk_74,
                                data_ov001_021a9be8->mUnk_54, v0);
            func_0212426c(0, data_ov001_021a6a24[i], data_ov001_021a9be8->mUnk_80,
                          GetBmgEntry(data_ov001_021a9be8->mUnk_88, c[i]), data_ov001_021a9be8->mUnk_74,
                          data_ov001_021a9be8->mUnk_54);
        }
    }
    {
        s32 v2 = func_02148ca0();
        void *v1;
        u8 b[3][2] = {{0x9b, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
        s32 d[3] = {0, 2, 4};

        for (i = 0; i < 3; i++) {
            v1 = data_ov001_021a9be8->mUnk_88;
            if (i == 2) {
                v1 = data_ov001_021a9be8->mUnk_8c;
            }
            v2 -= func_021243ac(data_ov001_021a9be8->mUnk_50, data_ov001_021a6a34[i], data_ov001_021a9be8->mUnk_84,
                                b[i][0], b[i][1], data_ov001_021a6a30[i], data_ov001_021a9be8->mUnk_60,
                                data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_58, v2);
            func_0212426c(1, data_ov001_021a6a34[i], data_ov001_021a9be8->mUnk_84, GetBmgEntry(v1, d[i]),
                          data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_58);
        }
    }
}

void func_ov001_02199640(void *a) {
    s32 i;

    data_ov001_021a9be8 = HeapAlloc(a, 0x90);
    data_ov001_021a9be8->mUnk_50 = a;
    data_ov001_021a9be8->mUnk_00 = 0;
    data_ov001_021a9be8->mUnk_04 = 0;
    data_ov001_021a9be8->mUnk_08 = 0;
    data_ov001_021a9be8->mUnk_20 = 0;
    data_ov001_021a9be8->mUnk_38 = 1;
    func_ov001_02199464();
    func_0212b928(a, data_ov001_021a9be8->mUnk_70, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6a28[i], 1, data_ov001_021a9be8->mUnk_60, data_ov001_021a9be8->mUnk_78);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(a, data_ov001_021a9be8->mUnk_74, data_ov001_021a9be8->mUnk_80, &data_ov001_021a9be8->mUnk_54);
    func_02124ed0(a, data_ov001_021a9be8->mUnk_78, data_ov001_021a9be8->mUnk_84, &data_ov001_021a9be8->mUnk_58);
    data_ov001_021a9be8->mUnk_88 = FindSceneFile(data_ov001_021a8644);
    data_ov001_021a9be8->mUnk_8c = func_02047a28(data_ov001_021a8650);
    func_ov001_021997dc();
    data_ov001_021a9be8->mUnk_24 = -140;
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = 0;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0x28;
        } else if (i == 1) {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = 250;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0;
        } else {
            data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -250;
            data_ov001_021a9be8->mUnk_26[i].mUnk_02 = 0;
        }
    }
    func_ov001_02199374();
    if (data_0217aa08->mUnk_00->mUnk_31_4 == 0) {
        data_ov001_021a9be8->mUnk_0c[1] = 0;
    } else {
        data_ov001_021a9be8->mUnk_0c[1] = 1;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9be8->mUnk_14[i] = data_ov001_021a9be8->mUnk_0c[i];
    }
    func_ov001_02198bbc();
    func_ov001_02198b58();
    for (i = 0; i < 2; i++) {
        data_ov001_021a9be8->mUnk_40[i][0] = 0;
        data_ov001_021a9be8->mUnk_40[i][1] = 0;
    }
    data_ov001_021a9be8->mUnk_1c = 0;
    data_ov001_021a9be8->mUnk_3c = 1;
    func_021281c8(0xe);
}

void func_ov001_021995f8(void) {
    u32 v;

    func_ov001_02199374();
    func_ov001_02199420();
    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~2) << 8);
    func_0212b91c();
    data_ov001_021a9be8 = NULL;
}

void func_ov001_02199464(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile(data_ov001_021a84ac));
    LocateNscr(&b, FindSceneFile(data_ov001_021a84c8));
    LocateNclr(&c, FindSceneFile(data_ov001_021a84e4));
    data_ov001_021a9be8->mUnk_74 = FindSceneFile(data_ov001_021a8500);
    data_ov001_021a9be8->mUnk_78 = FindSceneFile(data_ov001_021a851c);
    data_ov001_021a9be8->mUnk_7c = FindSceneFile(data_ov001_021a8538);
    data_ov001_021a9be8->mUnk_80 = FindSceneFile(data_ov001_021a8554);
    data_ov001_021a9be8->mUnk_84 = FindSceneFile(data_ov001_021a8570);
    LocateNcgr2(&data_ov001_021a9be8->mUnk_64, FindSceneFile(data_ov001_021a858c));
    LocateNcer(&data_ov001_021a9be8->mUnk_5c, FindSceneFile(data_ov001_021a85ac));
    LocateNclr(&data_ov001_021a9be8->mUnk_6c, FindSceneFile(data_ov001_021a85cc));
    LocateNcgr2(&data_ov001_021a9be8->mUnk_68, FindSceneFile(data_ov001_021a85e8));
    LocateNcer(&data_ov001_021a9be8->mUnk_60, FindSceneFile(data_ov001_021a8608));
    LocateNclr(&data_ov001_021a9be8->mUnk_70, FindSceneFile(data_ov001_021a8628));
    CallQueueAppend(5, 0, a->mData, a->mDataSize);
    CallQueueAppend(9, 0, b->mData, b->mDataSize);
    CallQueueAppend(0xf, 0x20, c->mData + 0x10, 0x20);
    CallQueueAppend(0x13, 0, data_ov001_021a9be8->mUnk_64->mData, data_ov001_021a9be8->mUnk_64->mDataSize);
    CallQueueAppend(0x23, 0, data_ov001_021a9be8->mUnk_68->mData, data_ov001_021a9be8->mUnk_68->mDataSize);
    CallQueueAppend(0xe, 0, data_ov001_021a9be8->mUnk_6c->mData, data_ov001_021a9be8->mUnk_6c->mDataSize);
    CallQueueAppend(0x1e, 0, data_ov001_021a9be8->mUnk_70->mData, data_ov001_021a9be8->mUnk_70->mDataSize);
}

void func_ov001_02199420(void) {
    switch (data_ov001_021a9be8->mUnk_0c[0]) {
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
    switch (data_ov001_021a9be8->mUnk_0c[0]) {
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
            data_ov001_021a9be8->mUnk_0c[0] = 1;
            break;
        case 0:
            data_ov001_021a9be8->mUnk_0c[0] = 0;
            break;
        case 2:
            data_ov001_021a9be8->mUnk_0c[0] = 2;
            break;
    }
}

void func_ov001_021992dc(void) {
    s32 i;
    s32 j;
    s16 v;

    data_ov001_021a9be8->mUnk_20++;
    data_ov001_021a9be8->mUnk_24 = func_020ae4c0(1, -140, 0, data_ov001_021a9be8->mUnk_20, 10);
    v = func_020ae4c0(1, 250, 0, data_ov001_021a9be8->mUnk_20, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -v;
            } else {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = v;
            }
        }
    }
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 1;
        data_ov001_021a9be8->mUnk_20 = 0;
    }
}

void func_ov001_021992a0(void) {
    data_ov001_021a9be8->mUnk_20++;
    data_ov001_021a9be8->mUnk_26[2].mUnk_02 = -func_0212825c(data_ov001_021a9be8->mUnk_20);
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 2;
        data_ov001_021a9be8->mUnk_20 = 0;
    }
}

void func_ov001_02198ec0(void) {
    Unk021a9be8 *p;
    s32 sel;
    s32 r5;
    BOOL hasB;
    BOOL hasA;
    s32 i;
    Unk02175628Index idx;
    u16 v;

    p = data_ov001_021a9be8;
    sel = p->mUnk_08;
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
        r5 = func_0201ea84(p->mUnk_7c, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
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
                                                                          data_02175628[idx].mUnk_4a) != 0) {
        L1:
            data_ov001_021a9be8->mUnk_04 = 4;
            data_ov001_021a9be8->mUnk_34 = 0;
            for (i = 0; i < 2; i++) {
                data_ov001_021a9be8->mUnk_0c[i] = data_ov001_021a9be8->mUnk_14[i];
            }
            func_02128310(0);
            goto end;
        }
    }
    if (((u16) (data_02175628[idx].mUnk_00 & 1) != 0 && data_ov001_021a9be8->mUnk_08 == 2) || r5 == 2) {
        func_ov001_021993b8();
        if (data_ov001_021a9be8->mUnk_0c[1] == 0) {
            data_0217aa08->mUnk_00->mUnk_31 &= ~0x10;
        } else {
            data_0217aa08->mUnk_00->mUnk_31 |= 0x10;
        }
        func_02056d40();
        if (data_ov001_021a9be8->mUnk_08 == 2) {
            data_ov001_021a9be8->mUnk_38 = 0;
        }
        data_ov001_021a9be8->mUnk_04 = 3;
        data_ov001_021a9be8->mUnk_34 = 0;
        data_ov001_021a9be8->mUnk_08 = 2;
        data_ov001_021a9be8->mUnk_1c = 1;
        func_0212b7e8();
        func_02105ac0(5);
    } else if (r5 == 0) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        func_02105ac0(10);
    } else if (r5 == 1) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        func_02105ac0(1);
    } else if (func_020ae408(8, 0x40) != 0) {
        data_ov001_021a9be8->mUnk_08--;
        if (data_ov001_021a9be8->mUnk_08 < 0) {
            data_ov001_021a9be8->mUnk_08 = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0 ||
               (data_ov001_021a9be8->mUnk_08 != 2 && (u16) (data_02175628[idx].mUnk_00 & 1) != 0)) {
        data_ov001_021a9be8->mUnk_08++;
        if (data_ov001_021a9be8->mUnk_08 > 2) {
            data_ov001_021a9be8->mUnk_08 = 0;
        }
        func_02105ac0(0);
    } else if (data_ov001_021a9be8->mUnk_08 != 2 && func_020ae408(8, 0x20) != 0) {
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        if (data_ov001_021a9be8->mUnk_08 == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (data_ov001_021a9be8->mUnk_08 != 2 && func_020ae408(8, 0x10) != 0) {
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        if (func_020ae408(8, 0x10) != 0) {
            data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        }
        if (data_ov001_021a9be8->mUnk_08 == 0) {
            func_02105ac0(10);
        } else {
            func_02105ac0(1);
        }
    } else if (r5 == 3) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        func_02105ac0(10);
    } else if (r5 == 4) {
        data_ov001_021a9be8->mUnk_08 = 0;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        func_02105ac0(10);
    } else if (r5 == 5) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]--;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][0] = 6;
        func_02105ac0(1);
    } else if (r5 == 6) {
        data_ov001_021a9be8->mUnk_08 = 1;
        data_ov001_021a9be8->mUnk_0c[data_ov001_021a9be8->mUnk_08]++;
        data_ov001_021a9be8->mUnk_40[data_ov001_021a9be8->mUnk_08][1] = 6;
        func_02105ac0(1);
    }
end:
    if (data_ov001_021a9be8->mUnk_0c[0] < 0) {
        data_ov001_021a9be8->mUnk_0c[0] = 2;
    }
    if (data_ov001_021a9be8->mUnk_0c[0] > 2) {
        data_ov001_021a9be8->mUnk_0c[0] = 0;
    }
    if (data_ov001_021a9be8->mUnk_0c[1] < 0) {
        data_ov001_021a9be8->mUnk_0c[1] = 1;
    }
    if (data_ov001_021a9be8->mUnk_0c[1] > 1) {
        data_ov001_021a9be8->mUnk_0c[1] = 0;
    }
    if (data_ov001_021a9be8->mUnk_08 == 2 && sel != 2) {
        func_0212b7fc();
    }
    func_ov001_02199420();
}

void func_ov001_02198e94(void) {
    data_ov001_021a9be8->mUnk_20++;
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        data_ov001_021a9be8->mUnk_04 = 4;
        data_ov001_021a9be8->mUnk_20 = 0;
    } else if (data_ov001_021a9be8->mUnk_20 >= 5) {
        data_ov001_021a9be8->mUnk_38 = 1;
    }
}

void func_ov001_02198d8c(void) {
    s32 i;
    s32 j;
    s16 t;
    void *a;
    void *b;

    data_ov001_021a9be8->mUnk_24 = func_020ae4c0(1, 0, -0x8c, data_ov001_021a9be8->mUnk_20, 10);
    data_ov001_021a9be8->mUnk_20++;
    t = func_020ae4c0(1, 0, 250, data_ov001_021a9be8->mUnk_20, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            if (i == 1) {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = -t;
            } else {
                data_ov001_021a9be8->mUnk_26[i].mUnk_00 = t;
            }
        }
    }
    data_ov001_021a9be8->mUnk_26[2].mUnk_02 = -func_02128244(data_ov001_021a9be8->mUnk_20);
    if (data_ov001_021a9be8->mUnk_20 >= 10) {
        if (data_ov001_021a9be8->mUnk_20 >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
            data_ov001_021a9be8->mUnk_3c = 0;
            if (data_ov001_021a9be8->mUnk_1c != 0) {
                func_02125ebc(0x21);
                a = GetBmgEntry(data_ov001_021a9be8->mUnk_88, 0x10);
                b = GetBmgEntry(data_ov001_021a9be8->mUnk_8c, 4);
                func_02126230(a, b);
                data_ov001_021a9be8->mUnk_04 = 5;
                data_ov001_021a9be8->mUnk_20 = 0;
                func_021282c8();
            } else {
                RequestOptionState(data_ov001_021a9be8->mUnk_34);
            }
        }
    }
}

void func_ov001_02198d20(void) {
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
        RequestOptionState(data_ov001_021a9be8->mUnk_34);
    }
}

void func_ov001_02198bbc(void) {
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = data_ov001_021a9be8->mUnk_74->mUnk_06;
    b = data_ov001_021a9be8->mUnk_78->mUnk_06;
    for (i = 0; i < 1; i++) {
        data_ov001_021a9be8->mUnk_54[data_ov001_021a6a20[i]].mUnk_06 = data_ov001_021a9be8->mUnk_24;
    }
    for (i = 0; i < 2; i++) {
        (data_ov001_021a9be8->mUnk_54 + a)[data_ov001_021a6a24[i]].mUnk_06 = data_ov001_021a9be8->mUnk_24;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a6a44[i]; j++) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a5c[i][j]].mUnk_04 = data_ov001_021a9be8->mUnk_26[i].mUnk_00;
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a5c[i][j]].mUnk_06 = data_ov001_021a9be8->mUnk_26[i].mUnk_02;
        }
        (data_ov001_021a9be8->mUnk_58 + b)[data_ov001_021a6a34[i]].mUnk_04 = data_ov001_021a9be8->mUnk_26[i].mUnk_00;
        (data_ov001_021a9be8->mUnk_58 + b)[data_ov001_021a6a34[i]].mUnk_06 = data_ov001_021a9be8->mUnk_26[i].mUnk_02;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][j][0]].mUnk_04 -=
                func_020adc64(6 - data_ov001_021a9be8->mUnk_40[i][0]);
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][j][1]].mUnk_04 +=
                func_020adc64(6 - data_ov001_021a9be8->mUnk_40[i][1]);
        }
    }
}

void func_ov001_02198b58(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a2c[i]; j++) {
            if (j == data_ov001_021a9be8->mUnk_0c[i]) {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a38[i][j]].mUnk_00 = 1;
            } else {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a38[i][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_ov001_02198a6c(void) {
    s32 i;
    s32 k;

    for (i = 0; i < 3; i++) {
        if (i == data_ov001_021a9be8->mUnk_08 && data_ov001_021a9be8->mUnk_38 != 0) {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a30[i]].mUnk_00 = 1;
            func_02124100(data_ov001_021a6a34[i], 14, data_ov001_021a9be8->mUnk_84, data_ov001_021a9be8->mUnk_58,
                          data_ov001_021a9be8->mUnk_78);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 14, data_ov001_021a9be8->mUnk_60,
                              data_ov001_021a9be8->mUnk_78);
            }
        } else {
            data_ov001_021a9be8->mUnk_58[data_ov001_021a6a30[i]].mUnk_00 = 0;
            func_02124100(data_ov001_021a6a34[i], 15, data_ov001_021a9be8->mUnk_84, data_ov001_021a9be8->mUnk_58,
                          data_ov001_021a9be8->mUnk_78);
            for (k = 0; k < data_ov001_021a6a2c[i]; k++) {
                func_02124a20(data_ov001_021a6a38[i][k], 15, data_ov001_021a9be8->mUnk_60,
                              data_ov001_021a9be8->mUnk_78);
            }
        }
    }
}

void func_ov001_021989bc(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (i == data_ov001_021a9be8->mUnk_08) {
                if (data_ov001_021a9be8->mUnk_40[i][j] > 0) {
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 1;
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                    data_ov001_021a9be8->mUnk_40[i][j]--;
                } else {
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                    data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 1;
                }
            } else {
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][0][j]].mUnk_00 = 0;
                data_ov001_021a9be8->mUnk_58[data_ov001_021a6a50[i][1][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_ov001_02198918(void) {
    Unk021a9be8 *p;

    data_ov001_021a9be8->mUnk_00 = data_ov001_021a9be8->mUnk_04;
    switch (data_ov001_021a9be8->mUnk_00) {
        case 0:
            func_ov001_021992dc();
            break;
        case 1:
            func_ov001_021992a0();
            break;
        case 2:
            func_ov001_02198ec0();
            break;
        case 3:
            func_ov001_02198e94();
            break;
        case 4:
            func_ov001_02198d8c();
            break;
        case 5:
            func_ov001_02198d20();
            break;
    }
    func_0212b80c();
    func_ov001_02198bbc();
    func_ov001_02198b58();
    func_ov001_02198a6c();
    func_ov001_021989bc();
    p = data_ov001_021a9be8;
    func_02124c30(p->mUnk_74, p->mUnk_5c, p->mUnk_80, func_ov001_0219e920(), p->mUnk_54);
    p = data_ov001_021a9be8;
    func_02124c30(p->mUnk_78, p->mUnk_60, p->mUnk_84, func_ov001_0219e90c(), p->mUnk_58);
}

void func_ov001_02198878(void) {
    u32 plane;

    if (data_ov001_021a9be8->mUnk_3c != 0) {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane |= 2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    } else {
        plane = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        plane &= ~2;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (plane << 8);
    }
    func_0214a40c((u32 *) 0x4001050, 0, 2, 6, 10);
    *(vu32 *) 0x4000010 = (-data_ov001_021a9be8->mUnk_24 << 16) & 0x1ff0000;
    *(vu32 *) 0x4000014 = (-data_ov001_021a9be8->mUnk_24 << 16) & 0x1ff0000;
}

void func_ov001_02198854(void) {
    UnkFunc *table[4] = {func_ov001_02199640, func_ov001_021995f8, func_ov001_02198918, func_ov001_02198878};

    SetOptionStateCallbacks((UnkFunc **) (table));
}
