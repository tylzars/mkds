#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/code_021a64a0.h"
#include "01/code_021a0e7c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02105550.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "01/code_0219ffb4.h"
#include "01/code_021a0000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_0203b680.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02148ca0.h"
#include "registers.h"

void func_ov001_021a0734(void) {
    u32 v0;
    u32 v1;

    func_0202947c((s8) (data_ov001_021ca414->mUnk_9e + 1));
    v0 = func_02029608();
    v1 = func_020295f8();
    func_02029468((u32) ((u16) (func_0203b680((u32) (data_ov001_021ca414->mUnk_4c), v0, v1) - 1)));
}

s32 func_ov001_021a071c(void) {
    if (data_ov001_021ca414->mUnk_ac != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021a0620(void) {
    u16 b;
    s16 v;
    s32 i;

    if (func_ov001_021a071c() != 0) {
        if (data_ov001_021ca414->mUnk_ac == 7) {
            data_ov001_021ca414->mUnk_b0 = data_ov001_021ca414->mUnk_9e;
            func_ov001_021a0774();
        } else {
            b = data_ov001_021ca414->mUnk_04->mUnk_06;
            v = func_02116d10(7 - data_ov001_021ca414->mUnk_ac, 1);
            data_ov001_021ca414->mUnk_94 = v;
            data_ov001_021ca414->mUnk_40[0].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[1].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[9].mUnk_06 = v;
            data_ov001_021ca414->mUnk_40[18].mUnk_06 = v;
            for (i = 0; i < 7; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_06 = v;
            }
            for (i = 0; i < 6; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_06 = v;
            }
            data_ov001_021ca414->mUnk_40[b].mUnk_06 = v;
            for (i = 0; i < 9; i++) {
                data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_06 = v;
            }
        }
        data_ov001_021ca414->mUnk_ac = data_ov001_021ca414->mUnk_ac - 1;
    } else if (data_ov001_021ca414->mUnk_9e != data_ov001_021ca414->mUnk_b0) {
        data_ov001_021ca414->mUnk_ac = 7;
    }
}

void func_ov001_021a04f0(void) {
    s32 i;
    s32 j;
    u16 a;
    u16 b;

    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_64 = 0;
    data_ov001_021ca414->mUnk_68 = 0;
    data_ov001_021ca414->mUnk_90 = 0x100;
    data_ov001_021ca414->mUnk_94 = 0;
    data_ov001_021ca414->mUnk_98 = -192;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = 0x100;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = 0x100;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = 0x100;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = 0x100;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = 0x100;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = 0x100;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = 0x100;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = 0x100;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = 0x100;
        }
    }
}

void func_ov001_021a04dc(void) {
    data_ov001_021ca414->mUnk_64 = 1;
    data_ov001_021ca414->mUnk_68 = 0;
}

void func_ov001_021a04c0(void) {
    data_ov001_021ca414->mUnk_64 = 2;
    data_ov001_021ca414->mUnk_68 = 0;
    func_02128374();
}

void func_ov001_021a04ac(void) {
    data_ov001_021ca414->mUnk_64 = 3;
    data_ov001_021ca414->mUnk_68 = 0;
}

s32 func_ov001_021a0488(void) {
    data_ov001_021ca414->mUnk_64 = 4;
    data_ov001_021ca414->mUnk_68 = 0;
    return func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a0428(void) {
    s32 i;
    void *v0;

    data_ov001_021ca414->mUnk_64 = 5;
    data_ov001_021ca414->mUnk_68 = 0;
    v0 = func_020b3f7c(data_ov001_021ca414->mUnk_54, 4);
    func_021277f8((void *) ((u32) v0), (void *) ((u32) func_020b3f7c(data_ov001_021ca414->mUnk_54, 2)), 0);
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 0;
    }
}

void func_ov001_021a0414(void) {
    data_ov001_021ca414->mUnk_64 = 6;
    data_ov001_021ca414->mUnk_68 = 0;
}

void func_ov001_021a03f8(void) {
    data_ov001_021ca414->mUnk_64 = 7;
    data_ov001_021ca414->mUnk_68 = 0;
    func_021277e4();
}

void func_ov001_021a03a0(void) {
    data_ov001_021ca414->mUnk_64 = 8;
    data_ov001_021ca414->mUnk_68 = 0;
    func_021282c8();
    switch (data_ov001_021ca414->mUnk_bc) {
        case 1:
            func_02105584(4, 10, func_02029608());
            break;
        case 2:
            func_02105584(0, 10, func_02029608());
            break;
    }
}

void func_ov001_021a0190(s32 param_1, s32 param_2, s32 param_3) {
    s32 i;
    void *heap;
    s32 rem;
    u16 base;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xd204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9004;
    heap = func_02036948((void *) param_1);
    data_ov001_021ca414 = func_02036bec(heap, 0xc0);
    data_ov001_021ca414->mUnk_5c = heap;
    data_ov001_021ca414->mUnk_60 = 0;
    data_ov001_021ca414->mUnk_9e = func_020295f8() - 1;
    data_ov001_021ca414->mUnk_9c = 0;
    data_ov001_021ca414->mUnk_ac = 0;
    data_ov001_021ca414->mUnk_a4 = 0;
    data_ov001_021ca414->mUnk_b4 = (void *) param_2;
    data_ov001_021ca414->mUnk_b8 = (void *) param_3;
    data_ov001_021ca414->mUnk_bc = 0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_6c[i] = 0;
    }
    func_ov001_021a0e34();
    func_ov001_021a0e7c();
    func_020ae6d4(data_ov001_021ca414->mUnk_b4, data_ov001_021ca414->mUnk_b8);
    func_02124ed0(data_ov001_021ca414->mUnk_5c, data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_08,
                  &data_ov001_021ca414->mUnk_40);
    func_02124ed0(data_ov001_021ca414->mUnk_5c, data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_18,
                  &data_ov001_021ca414->mUnk_44);
    data_ov001_021ca414->mUnk_54 = func_02047a28(data_ov001_021a94a4);
    data_ov001_021ca414->mUnk_58 = func_0204799c(data_ov001_021a94b0);
    data_ov001_021ca414->mUnk_4c = func_02047a28(data_ov001_021a94bc);
    data_ov001_021ca414->mUnk_50 = (Unk021ca414_50 *) ((u8 *) func_0204799c(data_ov001_021a94d0) + 8);
    func_021243ac(data_ov001_021ca414->mUnk_5c, 0, data_ov001_021ca414->mUnk_08, 0xd2, 0x46, 0,
                  data_ov001_021ca414->mUnk_00, data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_40, 0x8000);
    rem = func_02148ca0();
    for (i = 0; i < 9; i++) {
        rem -= func_021243ac(data_ov001_021ca414->mUnk_5c, data_ov001_021a6e10[i][0], data_ov001_021ca414->mUnk_18,
                             data_ov001_021a6e34[i][0], data_ov001_021a6e58[i][0], data_ov001_021a6e7c[i][5],
                             data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44,
                             rem);
        base = data_ov001_021a6e10[i][0];
        rem -= func_021243ac(data_ov001_021ca414->mUnk_5c, data_ov001_021a6e10[i][1], data_ov001_021ca414->mUnk_18,
                             data_ov001_021a6e34[i][1], data_ov001_021a6e58[i][1],
                             base + data_ov001_021ca414->mUnk_10->mUnk_06, data_ov001_021ca414->mUnk_0c,
                             data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44, rem);
    }
    func_ov001_021a64ac(data_ov001_021ca414->mUnk_5c);
    func_ov001_021a0b3c();
    data_ov001_021ca414->mUnk_b0 = data_ov001_021ca414->mUnk_9e;
    func_ov001_021a0774();
    func_ov001_021a04f0();
    func_02036820(data_ov001_021ca414->mUnk_5c);
}

void func_ov001_021a0140(void) {
    switch (data_ov001_021ca414->mUnk_bc) {
        case 1:
            func_02105550(4, func_02029608());
            break;
        case 2:
            func_02105550(0, func_02029608());
            break;
    }
    func_ov001_021a64a0();
    func_02036ab0(data_ov001_021ca414->mUnk_5c);
    data_ov001_021ca414 = 0;
}

void func_ov001_021a0118(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    if (func_02036c5c() != 0) {
        func_ov001_021a04dc();
    }
}

void func_ov001_0219ffb4(void) {
    s32 i;
    s32 j;
    u16 a;
    s16 v0;
    u16 b;
    s16 v1;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    v0 = func_020ae4c0(1, 0x100, 0, data_ov001_021ca414->mUnk_68, 10);
    v1 = func_020ae4c0(1, -192, 0, data_ov001_021ca414->mUnk_68, 10);
    data_ov001_021ca414->mUnk_90 = v0;
    data_ov001_021ca414->mUnk_98 = v1;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = v0;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = v0;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = v0;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = v0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = v0;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = v0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = v0;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = v0;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = v0;
        }
    }
    if (data_ov001_021ca414->mUnk_68 >= 10) {
        func_ov001_021a04c0();
    }
}
