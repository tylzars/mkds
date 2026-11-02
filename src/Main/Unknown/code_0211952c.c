#include "Main/Unknown/code_0211952c.h"

#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_021196f4.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df38.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148ca0.h"
#include "registers.h"
#include "Main/Unknown/code_02119a90.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

u32 func_02119dfc(void) {
    if (data_0217d364->mUnk_58 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_02119d78(void) {
    s32 w;
    s16 r;

    if (func_02119dfc() != 0) {
        if (data_0217d364->mUnk_58 == 7) {
            data_0217d364->mUnk_5c = data_0217d364->mUnk_50;
            func_02119e88();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            w = data_0217d364->mUnk_04->mUnk_06;
            r = func_02116d10(7 - data_0217d364->mUnk_58, 1);
            data_0217d364->mUnk_1c[w].mUnk_06 = r;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = r;
        }
        data_0217d364->mUnk_58--;
    } else if (data_0217d364->mUnk_50 != data_0217d364->mUnk_5c) {
        data_0217d364->mUnk_58 = 7;
    }
}

void func_02119c20(void) {
    s16 v;
    s32 w;
    s32 i;
    s32 u;

    data_0217d364->mUnk_38 = 0;
    data_0217d364->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (func_020cccb4() != 0x1a) {
            w = data_0217d364->mUnk_04->mUnk_06;
            data_0217d364->mUnk_44 = -0xc0;
            data_0217d364->mUnk_1c[0].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[2].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[1].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[4].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[3].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[5].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 2].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 3].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 4].mUnk_06 = -0xc0;
            data_0217d364->mUnk_1c[w + 5].mUnk_06 = -0xc0;
        }
        if (func_020cccb4() != 0x1a) {
            v = -0x20;
        } else {
            v = -0xe0;
        }
        u = data_0217d364->mUnk_10->mUnk_06;
        data_0217d364->mUnk_48 = v;
        data_0217d364->mUnk_20[0x14].mUnk_06 = v;
        data_0217d364->mUnk_20[0x13].mUnk_06 = v;
        data_0217d364->mUnk_20[2].mUnk_06 = v;
        data_0217d364->mUnk_20[1].mUnk_06 = v;
        data_0217d364->mUnk_20[0].mUnk_06 = v;
        for (i = 0; i < 8; i++) {
            data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_06 = v;
        }
        for (i = 0; i < 4; i++) {
            data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
            data_0217d364->mUnk_20[u + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

void func_02119c0c(void) {
    data_0217d364->mUnk_38 = 1;
    data_0217d364->mUnk_3c = 0;
}

void func_02119bf0(void) {
    data_0217d364->mUnk_38 = 2;
    data_0217d364->mUnk_3c = 0;
    func_02128374();
}

void func_02119bdc(void) {
    data_0217d364->mUnk_38 = 3;
    data_0217d364->mUnk_3c = 0;
}

void func_02119ba8(void) {
    data_0217d364->mUnk_38 = 4;
    data_0217d364->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02119ac4(void) {
    u16 buf[0x100];
    Unk0217d364 *d;

    data_0217d364->mUnk_38 = 5;
    data_0217d364->mUnk_3c = 0;
    d = data_0217d364;
    switch (d->mUnk_40) {
        case 0:
        case 1:
        case 3:
            func_021277f8(func_020b3f7c(d->mUnk_28, 4), func_020b3f7c(d->mUnk_28, 2), 0);
            break;
        case 2:
            func_021277f8(func_020b3f7c(d->mUnk_28, 4), func_020b3f7c(d->mUnk_28, 2), 0);
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_0212513c(func_020b3f7c(data_0217d364->mUnk_2c,
                                            data_0215cb3c[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50]),
                              func_020b3f7c(data_0217d364->mUnk_28, 0x8b), buf, 0x200);
                func_02125ebc(0x23);
                func_021266e4(buf);
            }
            break;
    }
}
#pragma thumb off

#pragma thumb on

void func_02119a90(void) {
    data_0217d364->mUnk_38 = 6;
    data_0217d364->mUnk_3c = 0;
    func_0212775c(0, (u32) 7);
    func_0212775c(1, (u32) 0x10);
    func_0212775c((int) 0xffffffff, (u32) 0x10);
}

#pragma thumb off

#pragma thumb on
void func_02119a38(void) {
    data_0217d364->mUnk_38 = 7;
    data_0217d364->mUnk_3c = 0;
    switch (data_0217d364->mUnk_40) {
        case 0:
        case 1:
        case 3:
            func_021277e4();
            break;
        case 2:
            func_021277e4();
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_02125fc0();
            }
            break;
    }
}

void func_021199f8(void) {
    data_0217d364->mUnk_38 = 8;
    data_0217d364->mUnk_3c = 0;
    if (data_0217d364->mUnk_40 == 0) {
        if (data_0217d364->mUnk_6c == 1) {
            if (func_0211e130() != 0) {
                func_021282c8();
            }
        }
    } else {
        func_021282c8();
    }
}

void func_02119770(void *b, void *c, void *d, s32 e) {
    void *a;
    s32 x;
    s32 i;
    u32 v;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    a = func_02036948(b);
    data_0217d364 = func_02036bec(a, 0x70);
    data_0217d364->mUnk_30 = a;
    data_0217d364->mUnk_34 = 0;
    data_0217d364->mUnk_50 = data_0215cb7c[func_020296e4()];
    data_0217d364->mUnk_54 = 1;
    data_0217d364->mUnk_58 = 0;
    data_0217d364->mUnk_40 = e;
    data_0217d364->mUnk_5c = data_0217d364->mUnk_50;
    data_0217d364->mUnk_60 = 0;
    data_0217d364->mUnk_64 = c;
    data_0217d364->mUnk_68 = d;
    data_0217d364->mUnk_6c = 0;
    func_0211a3bc();
    data_0217d364->mUnk_28 = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_02124ed0(data_0217d364->mUnk_30, data_0217d364->mUnk_04, data_0217d364->mUnk_08, &data_0217d364->mUnk_1c);
        func_02124ed0(data_0217d364->mUnk_30, data_0217d364->mUnk_10, data_0217d364->mUnk_18, &data_0217d364->mUnk_20);
        x = 0x8000;
        x -= func_021243ac(data_0217d364->mUnk_30, 0, data_0217d364->mUnk_08, 0xb4, 0xd, 0, data_0217d364->mUnk_00,
                           data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        x -= func_021243ac(data_0217d364->mUnk_30, 1, data_0217d364->mUnk_08, 0xb4, 0xd, 1, data_0217d364->mUnk_00,
                           data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        x -= func_021243ac(data_0217d364->mUnk_30, 2, data_0217d364->mUnk_08, 0x96, 0xd, 2, data_0217d364->mUnk_00,
                           data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        x -= func_021243ac(data_0217d364->mUnk_30, 3, data_0217d364->mUnk_08, 0x50, 0xd, 3, data_0217d364->mUnk_00,
                           data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        x -= func_021243ac(data_0217d364->mUnk_30, 4, data_0217d364->mUnk_08, 0x96, 0xd, 4, data_0217d364->mUnk_00,
                           data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        func_021243ac(data_0217d364->mUnk_30, 5, data_0217d364->mUnk_08, 0x50, 0xd, 5, data_0217d364->mUnk_00,
                      data_0217d364->mUnk_04, data_0217d364->mUnk_1c, x);
        v = func_02148ca0();
        for (i = 0; i < 4; i++) {
            v -= func_021243ac(data_0217d364->mUnk_30, data_0215cab4[i], data_0217d364->mUnk_18, data_0215cabc[i],
                               data_0215cac4[i], data_0215caa4[i], data_0217d364->mUnk_0c, data_0217d364->mUnk_10,
                               data_0217d364->mUnk_20, v);
        }
        func_0211de40(data_0217d364->mUnk_30);
        func_0211df44(data_0217d364->mUnk_30);
    } else {
        data_0217d364->mUnk_2c = FindSceneFile("ghost.bmg");
        func_0211f4b0(data_0217d364->mUnk_30, data_0217d364->mUnk_68);
        func_0211f380();
    }
    func_0211a100();
    func_02119e88();
    func_02119c20();
    func_02036820(data_0217d364->mUnk_30);
}

void func_021196f4(void) {
    if (data_0217d364->mUnk_6c == 1) {
        if (data_0217d364->mUnk_40 == 0) {
            if (func_0211e130() != 0) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
            }
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
        }
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0211de34();
        func_0211df38();
    } else {
        func_0211f498();
    }
    func_02036ab0(data_0217d364->mUnk_30);
    data_0217d364 = 0;
}
#pragma thumb off

#pragma thumb on

void func_021196dc(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_02119c0c();
    }
}

#pragma thumb off

#pragma thumb on
void func_02119544(void) {
    s16 v;
    s32 w;
    s32 i;

    data_0217d364->mUnk_3c++;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_020ae4c0(1, 0x100, 0, data_0217d364->mUnk_3c, 10);
        v = func_020ae4c0(1, -0xc0, 0, data_0217d364->mUnk_3c, 10);
        if (func_020cccb4() != 0x1a) {
            w = data_0217d364->mUnk_04->mUnk_06;
            data_0217d364->mUnk_44 = v;
            data_0217d364->mUnk_1c[0].mUnk_06 = v;
            data_0217d364->mUnk_1c[2].mUnk_06 = v;
            data_0217d364->mUnk_1c[1].mUnk_06 = v;
            data_0217d364->mUnk_1c[4].mUnk_06 = v;
            data_0217d364->mUnk_1c[3].mUnk_06 = v;
            data_0217d364->mUnk_1c[5].mUnk_06 = v;
            data_0217d364->mUnk_1c[w].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 1].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 2].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 3].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 4].mUnk_06 = v;
            data_0217d364->mUnk_1c[w + 5].mUnk_06 = v;
        }
        if (func_020cccb4() == 0x1a) {
            w = data_0217d364->mUnk_10->mUnk_06;
            data_0217d364->mUnk_48 = v - 0x20;
            data_0217d364->mUnk_20[0x14].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[0x13].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[2].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[1].mUnk_06 = v - 0x20;
            data_0217d364->mUnk_20[0].mUnk_06 = v - 0x20;
            for (i = 0; i < 8; i++) {
                data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_06 = v - 0x20;
            }
            v -= 0x20;
            for (i = 0; i < 4; i++) {
                data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
                data_0217d364->mUnk_20[w + data_0215cab4[i]].mUnk_06 = v;
            }
        }
    }
    if (data_0217d364->mUnk_3c >= 10) {
        func_02119bf0();
    }
}
#pragma thumb off

#pragma thumb on

void func_0211952c(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        func_02119bdc();
    }
}

#pragma thumb off
