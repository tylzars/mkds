#include "01/code_0219c784.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "01/unk_021a9000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "code_0201ea58.h"
#include "registers.h"

const u8 data_ov001_021a6bc4[] = {0};
const u8 data_ov001_021a6bc8[] = {0, 1};
const u8 data_ov001_021a6bcc[] = {9, 7};
const u8 data_ov001_021a6bd0[] = {1, 2, 3};
const u8 data_ov001_021a6bd4[] = {4, 5, 6};
const u8 data_ov001_021a6be8[6] = {0, 1, 2, 3, 4, 5};
const s8 data_ov001_021a6bd8[] = {0, -2, -3, -4, -3, -2};
const u8 data_ov001_021a6be0[] = {0, 0, 1, 1, 2, 2};
const u8 data_ov001_021a6bf0[6][3] = {{0, 12, 6}, {1, 13, 7}, {2, 14, 8}, {3, 15, 9}, {4, 16, 10}, {5, 17, 11}};
const Unk021a6c04 data_ov001_021a6c04[] = {
    {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16},
};
Unk021a9bf8 *data_ov001_021a9bf8;

void func_ov001_0219d2c0(void *c, s32 d, void *e, void *f) {
    s32 i, j;
    void *heap;
    void *p;

    heap = func_020369fc(c);
    data_ov001_021a9bf8 = func_02036bec(heap, 0x1088);
    data_ov001_021a9bf8->mUnk_1030 = heap;
    data_ov001_021a9bf8->mUnk_00 = 0;
    data_ov001_021a9bf8->mUnk_04 = 0;
    data_ov001_021a9bf8->mUnk_08 = 0;
    data_ov001_021a9bf8->mUnk_0c = 0;
    data_ov001_021a9bf8->mUnk_10 = 0;
    data_ov001_021a9bf8->mUnk_1c = 0;
    data_ov001_021a9bf8->mUnk_20 = 1;
    data_ov001_021a9bf8->mUnk_24 = -4;
    data_ov001_021a9bf8->mUnk_1080 = FindSceneFile("menu.bmg");
    data_ov001_021a9bf8->mUnk_1084 = func_02047a28("common.bmg");
    func_ov001_0219d03c();
    func_ov001_0219cf60();
    for (i = 0; i < 6; i++) {
        func_02124a98(data_ov001_021a6bf0[i][0], 1, data_ov001_021a9bf8->mUnk_1040, data_ov001_021a9bf8->mUnk_1054[1]);
    }
    data_ov001_021a9bf8->mUnk_1078 = e;
    data_ov001_021a9bf8->mUnk_107c = f;
    func_020ae6d4(e, f);
    for (i = 0; i < 2; i++) {
        func_02124ed0(data_ov001_021a9bf8->mUnk_1030, data_ov001_021a9bf8->mUnk_1054[i],
                      data_ov001_021a9bf8->mUnk_1064[i], &data_ov001_021a9bf8->mUnk_1034[i]);
    }
    data_ov001_021a9bf8->mUnk_1034[0][0].mUnk_06 = -0xa0;
    data_ov001_021a9bf8->mUnk_14 = 0xa0;
    func_ov001_0219cec4();
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 = 0xdc;
        }
    }
    {
        u8 a[2] = {0, 1};
        u8 b[2] = {5, 6};
        s32 rem = 0x8000;

        p = func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 6);
        if (d == 0) {
            p = func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 7);
        }
        for (i = 0; i < 2; i++) {
            rem -= func_021243ac(data_ov001_021a9bf8->mUnk_1030, a[i], data_ov001_021a9bf8->mUnk_1064[0], 0xa8, 13,
                                 b[i], data_ov001_021a9bf8->mUnk_103c, data_ov001_021a9bf8->mUnk_1054[0],
                                 data_ov001_021a9bf8->mUnk_1034[0], rem);
            func_0212426c(0, a[i], data_ov001_021a9bf8->mUnk_1064[0], p, data_ov001_021a9bf8->mUnk_1054[0],
                          data_ov001_021a9bf8->mUnk_1034[0]);
        }
        if (d == 1) {
            data_ov001_021a9bf8->mUnk_1034[0][5].mUnk_00 = 0;
        } else {
            data_ov001_021a9bf8->mUnk_1034[0][6].mUnk_00 = 0;
        }
    }
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    func_021281c8(14);
}

void func_ov001_0219d26c(void) {
    *(vu16 *) 0x400000c = (u16) ((*(vu16 *) 0x400000c & 0x43) | 0x1e10);
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x1f00) | 0x1800;
    func_02036ab0(data_ov001_021a9bf8->mUnk_1030);
    data_ov001_021a9bf8 = 0;
}

void func_ov001_0219d03c(void) {
    volatile u16 z;
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk020b4a44 *c;
    Unk020b4a44 *d;

    LocateNcgr(&a, FindSceneFile("mg/select_battle_stage_m_b.ncgr"));
    LocateNscr(&data_ov001_021a9bf8->mUnk_106c[0], FindSceneFile("mg/select_battle_stage_m_00.nscr"));
    LocateNscr(&data_ov001_021a9bf8->mUnk_106c[1], FindSceneFile("mg/select_battle_stage_m_01.nscr"));
    LocateNscr(&data_ov001_021a9bf8->mUnk_106c[2], FindSceneFile("mg/select_battle_stage_m_02.nscr"));
    LocateNclr(&b, FindSceneFile("mg/select_battle_stage_m_b.nclr"));
    data_ov001_021a9bf8->mUnk_1054[0] = FindSceneFile("mg/select_battle_stage_m.bncl");
    data_ov001_021a9bf8->mUnk_105c[0] = 0;
    data_ov001_021a9bf8->mUnk_1064[0] = FindSceneFile("mg/select_battle_stage_m.bnll");
    data_ov001_021a9bf8->mUnk_1054[1] = FindSceneFile("mg/select_battle_stage_s.bncl");
    data_ov001_021a9bf8->mUnk_105c[1] = FindSceneFile("mg/select_battle_stage_s.bnbl");
    data_ov001_021a9bf8->mUnk_1064[1] = 0;
    LocateNcgr2(&data_ov001_021a9bf8->mUnk_1044, FindSceneFile("mg/select_battle_stage_m.nce.ncgr"));
    LocateNcer(&data_ov001_021a9bf8->mUnk_103c, FindSceneFile("mg/select_battle_stage_m.nce.ncer"));
    LocateNclr(&c, FindSceneFile("mg/select_battle_stage_m_o.nclr"));
    LocateNcgr2(&data_ov001_021a9bf8->mUnk_1048, FindSceneFile("mg/select_battle_stage_s.nce.ncgr"));
    LocateNcer(&data_ov001_021a9bf8->mUnk_1040, FindSceneFile("mg/select_battle_stage_s.nce.ncer"));
    LocateNclr(&d, FindSceneFile("mg/select_battle_stage_s_o.nclr"));
    z = 0;
    func_0214cfe4(z, data_ov001_021a9bf8->mUnk_30, 0x1000);
    func_02016468(6, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(10, 0, data_ov001_021a9bf8->mUnk_30, 0x1000);
    func_02016468(15, 0, b->mUnk_0c, 0x180);
    func_02016468(19, 0, data_ov001_021a9bf8->mUnk_1044->mUnk_14, data_ov001_021a9bf8->mUnk_1044->mUnk_10);
    func_02016468(14, 0, c->mUnk_0c, 0x1a0);
    func_02016468(14, 0x1c0, c->mUnk_0c + 0xe0, 0x40);
    func_02016468(35, 0, data_ov001_021a9bf8->mUnk_1048->mUnk_14, data_ov001_021a9bf8->mUnk_1048->mUnk_10);
    func_02016468(30, 0, d->mUnk_0c, d->mUnk_08);
}

void func_ov001_0219cf60(void) {
    s32 x, y;
    s32 idx = data_ov001_021a9bf8->mUnk_08;
    u8 src = data_ov001_021a6be0[idx];

    for (y = 0; y <= data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_03 -
                         data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_02;
         y++) {
        for (x = 0; x <= data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_01 -
                             data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_00;
             x++) {
            (data_ov001_021a9bf8->mUnk_30[data_ov001_021a6bcc[1] + y] + data_ov001_021a6bcc[0])[x] =
                *((u16 *) data_ov001_021a9bf8->mUnk_106c[src]->mUnk_0c + x +
                  data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_00 +
                  (data_ov001_021a6c04[data_ov001_021a9bf8->mUnk_08].mUnk_02 + y) * 32);
        }
    }
    func_02016468(10, 0, data_ov001_021a9bf8->mUnk_30, 0x600);
}

void func_ov001_0219cec4(void) {
    s32 i;
    u16 x = data_ov001_021a9bf8->mUnk_1054[0]->mUnk_06;

    for (i = 0; i < 1; i++) {
        data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bc4[i]].mUnk_06 = -data_ov001_021a9bf8->mUnk_14;
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bd0[i]].mUnk_06 =
            data_ov001_021a9bf8->mUnk_1c - data_ov001_021a9bf8->mUnk_14;
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[0][data_ov001_021a6bd4[i]].mUnk_04 = data_ov001_021a9bf8->mUnk_18;
    }
    for (i = 0; i < 2; i++) {
        (data_ov001_021a9bf8->mUnk_1034[0] + x)[data_ov001_021a6bc8[i]].mUnk_04 = data_ov001_021a9bf8->mUnk_18;
    }
}

void func_ov001_0219cdd4(void) {
    s32 i, j;

    data_ov001_021a9bf8->mUnk_0c++;
    if (data_ov001_021a9bf8->mUnk_0c > 20) {
        data_ov001_021a9bf8->mUnk_04 = 1;
        data_ov001_021a9bf8->mUnk_0c = 0;
        data_ov001_021a9bf8->mUnk_04 = 1;
        func_02128374();
    } else if (data_ov001_021a9bf8->mUnk_0c > 10) {
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 =
                    func_020ae488(data_ov001_021a9bf8->mUnk_0c - 10);
            }
        }
    } else {
        data_ov001_021a9bf8->mUnk_14 = func_020ae4c0(1, 0xa0, 0, data_ov001_021a9bf8->mUnk_0c, 10);
        data_ov001_021a9bf8->mUnk_18 = func_020ae4c0(1, -0x100, 0, data_ov001_021a9bf8->mUnk_0c, 10);
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 =
                    func_020ae4c0(1, 0xdc, 0, data_ov001_021a9bf8->mUnk_0c, 10);
            }
        }
    }
}

void func_ov001_0219cdb4(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        data_ov001_021a9bf8->mUnk_04 = 2;
    }
    return;
}

void func_ov001_0219cba0(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 res = -1;
    s32 sel = -4;
    s32 b = 0;
    s32 a;
    s32 i;
    s32 prev;
    u16 x;

    a = 0;
    x = data_02175628[idx].mUnk_4c;
    if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        res = func_0201ea84(data_ov001_021a9bf8->mUnk_105c[1], data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    for (i = 0; i < 6; i++) {
        if (res == data_ov001_021a6be8[i]) {
            sel = i;
        }
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        b = 0;
        a = 0;
        x = data_02175628[idx].mUnk_4c;
        if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
            a = 1;
        }
        if (a == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
            b = 1;
        }
        if (b == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    if (data_0217b488->mUnk_08 == 2) {
        data_ov001_021a9bf8->mUnk_04 = 4;
        func_02128310(0);
        data_ov001_021a9bf8->mUnk_2c = 0;
        return;
    }
    data_ov001_021a9bf8->mUnk_04 = 6;
    data_ov001_021a9bf8->mUnk_28 = -3;
    if (data_021759d0->mUnk_20 == 0) {
        func_02128310(0);
        data_ov001_021a9bf8->mUnk_2c = 0;
        return;
    }
    func_02128310(1);
    data_ov001_021a9bf8->mUnk_2c = 1;
    return;
next:
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0 || sel != -4) {
        prev = data_ov001_021a9bf8->mUnk_08;
        if ((u16) (data_02175628[idx].mUnk_00 & 1) == 0) {
            data_ov001_021a9bf8->mUnk_08 = sel;
        }
        if (data_ov001_021a9bf8->mUnk_08 == prev) {
            data_ov001_021a9bf8->mUnk_20 = 0;
        }
        data_ov001_021a9bf8->mUnk_28 = data_ov001_021a9bf8->mUnk_08;
        data_ov001_021a9bf8->mUnk_04 = 3;
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        data_ov001_021a9bf8->mUnk_08--;
        if (data_ov001_021a9bf8->mUnk_08 < 0) {
            data_ov001_021a9bf8->mUnk_08 = 5;
        }
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(0);
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        data_ov001_021a9bf8->mUnk_08++;
        if (data_ov001_021a9bf8->mUnk_08 >= 6) {
            data_ov001_021a9bf8->mUnk_08 = 0;
        }
        data_ov001_021a9bf8->mUnk_10 = 6;
        func_02105ac0(0);
    }
}

void func_ov001_0219caf4(void) {
    s32 i;
    s16 v;

    data_ov001_021a9bf8->mUnk_0c++;
    v = func_020ae488(data_ov001_021a9bf8->mUnk_0c);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[data_ov001_021a9bf8->mUnk_08][i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf8->mUnk_0c >= 10) {
        data_ov001_021a9bf8->mUnk_04 = 5;
        data_ov001_021a9bf8->mUnk_0c = 0;
        func_021277f8(func_020b3f7c(data_ov001_021a9bf8->mUnk_1084, 4),
                      func_020b3f7c(data_ov001_021a9bf8->mUnk_1084, 2), 0);
        func_0212775c(0, 7);
        func_0212775c(1, 0x10);
    } else if (data_ov001_021a9bf8->mUnk_0c >= 5) {
        data_ov001_021a9bf8->mUnk_20 = 1;
    }
}

void func_ov001_0219ca94(void) {
    if (func_02128294() != 0) {
        data_ov001_021a9bf8->mUnk_28 = -2;
        func_021277f8(func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 0x14),
                      func_020b3f7c(data_ov001_021a9bf8->mUnk_1080, 0x15), 0);
        func_0212775c(0, 5);
        func_0212775c(1, 0xc);
        data_ov001_021a9bf8->mUnk_04 = 5;
    }
}

void func_ov001_0219ca2c(void) {
    if (func_02127788() != 0) {
        if (data_ov001_021a9bf8->mUnk_28 == -2 || data_ov001_021a9bf8->mUnk_28 == -1) {
            if (func_02127794() == 1) {
                data_ov001_021a9bf8->mUnk_04 = 6;
            } else {
                data_ov001_021a9bf8->mUnk_04 = 2;
            }
        } else {
            if (func_02127794() == 0) {
                data_ov001_021a9bf8->mUnk_04 = 6;
                func_021282c8();
                data_ov001_021a9bf8->mUnk_2c = 1;
            } else {
                data_ov001_021a9bf8->mUnk_04 = 2;
            }
        }
        func_021277e4();
    }
}

void func_ov001_0219c950(void) {
    s32 i;
    s32 j;

    data_ov001_021a9bf8->mUnk_0c++;
    if (data_ov001_021a9bf8->mUnk_0c > 10) {
        if ((data_ov001_021a9bf8->mUnk_2c != 0 && func_02128274() != 0) ||
            (data_ov001_021a9bf8->mUnk_2c == 0 && func_02128294() != 0)) {
            data_ov001_021a9bf8->mUnk_24 = data_ov001_021a9bf8->mUnk_28;
            return;
        }
    }
    if (data_ov001_021a9bf8->mUnk_0c > 10) {
        data_ov001_021a9bf8->mUnk_0c = 10;
    }
    data_ov001_021a9bf8->mUnk_14 = func_020ae4c0(1, 0, 0xa0, data_ov001_021a9bf8->mUnk_0c, 10);
    data_ov001_021a9bf8->mUnk_18 = func_020ae4c0(1, 0, -0x100, data_ov001_021a9bf8->mUnk_0c, 10);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][j]].mUnk_04 =
                func_020ae4c0(1, 0, 0xdc, data_ov001_021a9bf8->mUnk_0c, 10);
        }
    }
}

void func_ov001_0219c8ec(void) {
    s32 i;
    s32 zero = 0;

    for (i = 0; i < 6; i++) {
        if (i == data_ov001_021a9bf8->mUnk_08 && data_ov001_021a9bf8->mUnk_20 != 0) {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][1]].mUnk_00 = 1;
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][2]].mUnk_00 = 0;
        } else {
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][1]].mUnk_00 = zero;
            data_ov001_021a9bf8->mUnk_1034[1][data_ov001_021a6bf0[i][2]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219c8c8(void) {
    if (data_ov001_021a9bf8->mUnk_10 > 0) {
        data_ov001_021a9bf8->mUnk_10--;
    }
    data_ov001_021a9bf8->mUnk_1c = data_ov001_021a6bd8[data_ov001_021a9bf8->mUnk_10];
}

s32 func_ov001_0219c80c(void) {
    s32 i;

    data_ov001_021a9bf8->mUnk_00 = data_ov001_021a9bf8->mUnk_04;
    switch (data_ov001_021a9bf8->mUnk_00) {
        case 0:
            func_ov001_0219cdd4();
            break;
        case 1:
            func_ov001_0219cdb4();
            break;
        case 2:
            func_ov001_0219cba0();
            break;
        case 3:
            func_ov001_0219caf4();
            break;
        case 4:
            func_ov001_0219ca94();
            break;
        case 5:
            func_ov001_0219ca2c();
            break;
        case 6:
            func_ov001_0219c950();
            break;
    }
    func_ov001_0219c8c8();
    func_ov001_0219c8ec();
    func_ov001_0219cec4();
    func_ov001_0219cf60();
    for (i = 0; i < 2; i++) {
        func_02124c30(data_ov001_021a9bf8->mUnk_1054[i], (&data_ov001_021a9bf8->mUnk_103c)[i],
                      data_ov001_021a9bf8->mUnk_1064[i], (&data_ov001_021a9bf8->mUnk_1078)[i],
                      data_ov001_021a9bf8->mUnk_1034[i]);
    }
    return data_ov001_021a9bf8->mUnk_24;
}

void func_ov001_0219c784(void) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x1c00;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | 0x1600;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & ~3) | 1;
    *(vu16 *) 0x4000050 = 0;
    func_0214a40c((u32 *) 0x4001050, 0, 2, 6, 10);
    *(vu32 *) 0x4000018 = ((data_ov001_021a9bf8->mUnk_14 - data_ov001_021a9bf8->mUnk_1c) << 16) & 0x1ff0000;
}
