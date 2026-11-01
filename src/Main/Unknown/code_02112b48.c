#include "Main/Unknown/code_02112b48.h"

#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_0211398c.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113f34.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0212df7c.h"
#include "registers.h"

#pragma thumb on

void func_021136f8(void) {
    u16 a;
    u16 b;
    s16 v;
    if (func_02113790() != 0) {
        if (data_0217d348->mUnk_70 == 7) {
            data_0217d348->mUnk_74 = data_0217d348->mUnk_68;
            func_02113a3c();
        } else {
            a = data_0217d348->mUnk_08->mUnk_06;
            b = data_0217d348->mUnk_18->mUnk_06;
            v = func_02116d10(7 - data_0217d348->mUnk_70, 0);
            data_0217d348->mUnk_5c = v;
            data_0217d348->mUnk_14[3].mUnk_06 = v;
            data_0217d348->mUnk_14[a].mUnk_06 = v;
            data_0217d348->mUnk_24[1].mUnk_06 = v;
            data_0217d348->mUnk_24[b].mUnk_06 = v;
        }
        data_0217d348->mUnk_70 = data_0217d348->mUnk_70 - 1;
    } else {
        if (data_0217d348->mUnk_68 != 5 && data_0217d348->mUnk_68 != data_0217d348->mUnk_74) {
            data_0217d348->mUnk_70 = 7;
        }
    }
}

void func_021134d4(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    i = 0;
    data_0217d348->mUnk_50 = 0;
    data_0217d348->mUnk_54 = 0;
    data_0217d348->mUnk_58 = 0;
    data_0217d348->mUnk_5c = -192;
    data_0217d348->mUnk_60 = 0;
    data_0217d348->mUnk_64 = -192;
    a = data_0217d348->mUnk_08->mUnk_06;
    b = data_0217d348->mUnk_18->mUnk_06;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_14[0].mUnk_06 = -192;
    data_0217d348->mUnk_14[1].mUnk_06 = -192;
    data_0217d348->mUnk_14[2].mUnk_06 = -192;
    data_0217d348->mUnk_14[3].mUnk_06 = -192;
    data_0217d348->mUnk_14[a].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 1].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 11].mUnk_06 = -192;
    data_0217d348->mUnk_14[a + 12].mUnk_06 = -192;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = -192;
        }
    }
    data_0217d348->mUnk_24[1].mUnk_06 = -192;
    data_0217d348->mUnk_24[0].mUnk_06 = -192;
    data_0217d348->mUnk_24[b].mUnk_06 = -192;
    data_0217d348->mUnk_24[b + 1].mUnk_06 = -192;
    data_0217d348->mUnk_24[b + 14].mUnk_06 = -192;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_06 = -192;
    }
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    data_0217d348->mUnk_3c[26].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = 0x100;
    for (l = 0; l < 5; l++) {
        data_0217d348->mUnk_3c[data_0215c3e0[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[l]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = 0x100;
    }
    for (j = 0; j < 2; j++) {
        data_0217d348->mUnk_3c[data_0215c3ac[j]].mUnk_00 = 0;
    }
}

void func_021134b8(void) {
    data_0217d348->mUnk_50 = 1;
    data_0217d348->mUnk_54 = 0;
    func_02113a3c();
}

void func_0211349c(void) {
    data_0217d348->mUnk_50 = 2;
    data_0217d348->mUnk_54 = 0;
    func_021139b4();
}

void func_02113480(void) {
    data_0217d348->mUnk_50 = 3;
    data_0217d348->mUnk_54 = 0;
    func_02128374();
}

void func_0211346c(void) {
    data_0217d348->mUnk_50 = 4;
    data_0217d348->mUnk_54 = 0;
}

void func_02113458(void) {
    data_0217d348->mUnk_50 = 5;
    data_0217d348->mUnk_54 = 0;
}

void func_02113420(void) {
    data_0217d348->mUnk_50 = 6;
    data_0217d348->mUnk_54 = 0;
    switch (data_0217d348->mUnk_6c) {
        case 0:
            func_021139a0();
            break;
        case 1:
            func_0211398c();
            break;
    }
    func_021139b4();
}

void func_0211340c(void) {
    data_0217d348->mUnk_50 = 7;
    data_0217d348->mUnk_54 = 0;
}

void func_021132e4(void) {
    s32 i;
    u16 x;
    data_0217d348->mUnk_50 = 8;
    i = 0;
    data_0217d348->mUnk_54 = 0;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    data_0217d348->mUnk_3c[26].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = 0x100;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
    }
    func_0205edf8();
}

void func_021132b4(void) {
    data_0217d348->mUnk_50 = 9;
    data_0217d348->mUnk_54 = 0;
    data_0217d348->mUnk_3c[25].mUnk_00 = 1;
    func_0212ecc0(&data_0217d068, 0, 4);
}

void func_02113298(void) {
    data_0217d348->mUnk_50 = 10;
    data_0217d348->mUnk_54 = 0;
    func_021282c8();
}

void func_02113174(void) {
    s32 i;
    u16 x;
    data_0217d348->mUnk_50 = 11;
    i = 0;
    data_0217d348->mUnk_54 = 0;
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[21].mUnk_04 = 0x100;
    data_0217d348->mUnk_3c[24].mUnk_04 = -256;
    data_0217d348->mUnk_3c[25].mUnk_04 = -256;
    data_0217d348->mUnk_3c[26].mUnk_04 = -256;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = -256;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = 0x100;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = 0x100;
    }
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_3c[data_0215c3ac[i]].mUnk_00 = 0;
    }
    func_021139b4();
}

void func_02112bb4(void *a) {
    s32 r;
    s32 i;
    s32 j;
    u16 e;
    u16 x;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc800;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xcc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    data_0217d348 = func_02036bec(a, 0x94);
    data_0217d348->mUnk_48 = a;
    data_0217d348->mUnk_6a = func_02111418();
    data_0217d348->mUnk_68 = func_02111408();
    data_0217d348->mUnk_6c = 0;
    data_0217d348->mUnk_70 = 0;
    data_0217d348->mUnk_74 = data_0217d348->mUnk_68;
    data_0217d348->mUnk_40 = 0;
    data_0217d348->mUnk_88 = 0;
    data_0217d348->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        data_0217d348->mUnk_80[i] = 0;
    }
    func_02077a28(a);
    func_02113f34();
    func_02124ed0(a, data_0217d348->mUnk_08, data_0217d348->mUnk_0c, &data_0217d348->mUnk_14);
    func_02124ed0(a, data_0217d348->mUnk_18, data_0217d348->mUnk_1c, &data_0217d348->mUnk_24);
    func_02124ed0(a, data_0217d348->mUnk_30, data_0217d348->mUnk_38, &data_0217d348->mUnk_3c);
    data_0217d348->mUnk_44 = func_0204799c("record.bmg");
    r = 0x8000;
    r -= func_021243ac(a, 0, data_0217d348->mUnk_0c, 0x8c, 0x10, 0, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    r -= func_021243ac(a, 1, data_0217d348->mUnk_0c, 0xaa, 0xe, 1, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    func_0212426c(0, 1, data_0217d348->mUnk_0c, func_020b3f7c(data_0217d348->mUnk_44, 0), data_0217d348->mUnk_08,
                  data_0217d348->mUnk_14);
    r -= func_021243ac(a, 0xb, data_0217d348->mUnk_0c, 0x96, 0xe, 2, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    func_0212426c(0, 0xb, data_0217d348->mUnk_0c, func_020b3f7c(data_0217d348->mUnk_44, 1), data_0217d348->mUnk_08,
                  data_0217d348->mUnk_14);
    r -= func_021243ac(a, 0xc, data_0217d348->mUnk_0c, 0x46, 0x10, 3, data_0217d348->mUnk_04, data_0217d348->mUnk_08,
                       data_0217d348->mUnk_14, r);
    e = 4;
    x = data_0217d348->mUnk_08->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            r -= func_021243ac(a, data_0215c410[i][j], data_0217d348->mUnk_0c, data_0215c424[i][j], data_0215c438[i][j],
                               e, data_0217d348->mUnk_04, data_0217d348->mUnk_08, data_0217d348->mUnk_14, r);
            e = x + data_0215c410[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c410[0][i], data_0217d348->mUnk_0c,
                      func_020b3f7c(data_0217d348->mUnk_44, data_0215c3b4[i]), data_0217d348->mUnk_08,
                      data_0217d348->mUnk_14);
    }
    r -= func_021243ac(a, 0, data_0217d348->mUnk_1c, 0x8c, 0x10, 0, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    r -= func_021243ac(a, 1, data_0217d348->mUnk_1c, 0x70, 0x10, 1, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    func_0212426c(0, 1, data_0217d348->mUnk_1c, func_020b3f7c(data_0217d348->mUnk_44, 0xb), data_0217d348->mUnk_18,
                  data_0217d348->mUnk_24);
    r -= func_021243ac(a, 0xe, data_0217d348->mUnk_1c, 0xe0, 0x38, 2, data_0217d348->mUnk_04, data_0217d348->mUnk_18,
                       data_0217d348->mUnk_24, r);
    func_0212426c(0, 0xe, data_0217d348->mUnk_1c, func_020b3f7c(data_0217d348->mUnk_44, 0xc), data_0217d348->mUnk_18,
                  data_0217d348->mUnk_24);
    for (i = 0; i < 12; i++) {
        r -= func_021243ac(a, data_0215c478[i], data_0217d348->mUnk_1c, data_0215c490[i], data_0215c460[i], i + 3,
                           data_0217d348->mUnk_04, data_0217d348->mUnk_18, data_0217d348->mUnk_24, r);
    }
    r = func_02148ca0();
    for (i = 0; i < 5; i++) {
        r -= func_021243ac(a, data_0215c3bc[i], data_0217d348->mUnk_38, data_0215c3c8[i], data_0215c3d4[i],
                           data_0215c3ec[i], data_0217d348->mUnk_2c, data_0217d348->mUnk_30, data_0217d348->mUnk_3c, r);
    }
    func_021243ac(a, 5, data_0217d348->mUnk_38, 0x98, 0x10, 0x19, data_0217d348->mUnk_2c, data_0217d348->mUnk_30,
                  data_0217d348->mUnk_3c, r);
    func_0212426c(1, 5, data_0217d348->mUnk_38, func_020b3f7c(data_0217d348->mUnk_44, 3), data_0217d348->mUnk_30,
                  data_0217d348->mUnk_3c);
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c3e0[i], 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
        func_02124a98(data_0215c3ec[i], 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
        func_02124140(data_0215c3bc[i], 0, data_0217d348->mUnk_38, data_0217d348->mUnk_3c, data_0217d348->mUnk_30);
    }
    func_02124a98(0x18, 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
    func_02124a98(0x19, 0, data_0217d348->mUnk_2c, data_0217d348->mUnk_30);
    func_02124140(5, 0, data_0217d348->mUnk_38, data_0217d348->mUnk_3c, data_0217d348->mUnk_30);
    data_0217d348->mUnk_78 = func_02036bec(a, 0x201);
    data_0217d348->mUnk_7c = func_02036bec(a, 0x200);
    if (func_0211147c() == 4) {
        if (func_021143b4() != 0) {
            data_0217d348->mUnk_4c = 11;
            func_02113174();
        } else {
            data_0217d348->mUnk_4c = 8;
            func_021132e4();
            if (func_0211146c() == 12) {
                data_0217d348->mUnk_90 = 6;
            } else {
                data_0217d348->mUnk_90 = 0;
            }
        }
    } else {
        data_0217d348->mUnk_4c = 0;
        func_021134d4();
        func_020ae6d4(func_02111318(), func_0211130c());
    }
    data_0217d348->mUnk_3c[24].mUnk_00 = 0;
    data_0217d348->mUnk_3c[25].mUnk_00 = 0;
}

void func_02112b48(void) {
    u32 v;
    if (data_0217d348->mUnk_90 == 4) {
        func_021113fc(data_0217d348->mUnk_6a);
        func_021113f0(data_0217d348->mUnk_68);
    } else {
        func_021113fc(0);
        func_021113f0(0);
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v & ~0x13) << 8);
    }
    data_0217d348 = 0;
}

#pragma thumb off
