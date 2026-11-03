#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_0211952c.h"

#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_021277ac.h"
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
    if (gSelectCup->mUnk_58 != 0) {
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
        if (gSelectCup->mUnk_58 == 7) {
            gSelectCup->mUnk_5c = gSelectCup->mUnk_50;
            func_02119e88();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            w = gSelectCup->mUnk_04->mUnk_06;
            r = func_02116d10(7 - gSelectCup->mUnk_58, 1);
            gSelectCup->mUnk_1c[w].mUnk_06 = r;
            gSelectCup->mUnk_1c[w + 1].mUnk_06 = r;
        }
        gSelectCup->mUnk_58--;
    } else if (gSelectCup->mUnk_50 != gSelectCup->mUnk_5c) {
        gSelectCup->mUnk_58 = 7;
    }
}

void func_02119c20(void) {
    s16 v;
    s32 w;
    s32 i;
    s32 u;

    gSelectCup->mUnk_38 = 0;
    gSelectCup->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (func_020cccb4() != 0x1a) {
            w = gSelectCup->mUnk_04->mUnk_06;
            gSelectCup->mUnk_44 = -0xc0;
            gSelectCup->mUnk_1c[0].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[2].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[1].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[4].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[3].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[5].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w + 1].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w + 2].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w + 3].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w + 4].mUnk_06 = -0xc0;
            gSelectCup->mUnk_1c[w + 5].mUnk_06 = -0xc0;
        }
        if (func_020cccb4() != 0x1a) {
            v = -0x20;
        } else {
            v = -0xe0;
        }
        u = gSelectCup->mUnk_10->mUnk_06;
        gSelectCup->mUnk_48 = v;
        gSelectCup->mUnk_20[0x14].mUnk_06 = v;
        gSelectCup->mUnk_20[0x13].mUnk_06 = v;
        gSelectCup->mUnk_20[2].mUnk_06 = v;
        gSelectCup->mUnk_20[1].mUnk_06 = v;
        gSelectCup->mUnk_20[0].mUnk_06 = v;
        for (i = 0; i < 8; i++) {
            gSelectCup->mUnk_20[data_0215cacc[i]].mUnk_06 = v;
        }
        for (i = 0; i < 4; i++) {
            gSelectCup->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
            gSelectCup->mUnk_20[u + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

void func_02119c0c(void) {
    gSelectCup->mUnk_38 = 1;
    gSelectCup->mUnk_3c = 0;
}

void func_02119bf0(void) {
    gSelectCup->mUnk_38 = 2;
    gSelectCup->mUnk_3c = 0;
    func_02128374();
}

void func_02119bdc(void) {
    gSelectCup->mUnk_38 = 3;
    gSelectCup->mUnk_3c = 0;
}

void func_02119ba8(void) {
    gSelectCup->mUnk_38 = 4;
    gSelectCup->mUnk_3c = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02119ac4(void) {
    u16 buf[0x100];
    Unk0217d364 *d;

    gSelectCup->mUnk_38 = 5;
    gSelectCup->mUnk_3c = 0;
    d = gSelectCup;
    switch (d->mUnk_40) {
        case 0:
        case 1:
        case 3:
            func_021277f8(GetBmgEntry(d->mUnk_28, 4), GetBmgEntry(d->mUnk_28, 2), 0);
            break;
        case 2:
            func_021277f8(GetBmgEntry(d->mUnk_28, 4), GetBmgEntry(d->mUnk_28, 2), 0);
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_0212513c(GetBmgEntry(gSelectCup->mUnk_2c,
                                          data_0215cb3c[data_0215cadc[func_0202968c()]][gSelectCup->mUnk_50]),
                              GetBmgEntry(gSelectCup->mUnk_28, 0x8b), buf, 0x200);
                func_02125ebc(0x23);
                func_021266e4(buf);
            }
            break;
    }
}
#pragma thumb off

#pragma thumb on

void func_02119a90(void) {
    gSelectCup->mUnk_38 = 6;
    gSelectCup->mUnk_3c = 0;
    func_0212775c(0, (u32) 7);
    func_0212775c(1, (u32) 0x10);
    func_0212775c(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on
void func_02119a38(void) {
    gSelectCup->mUnk_38 = 7;
    gSelectCup->mUnk_3c = 0;
    switch (gSelectCup->mUnk_40) {
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
    gSelectCup->mUnk_38 = 8;
    gSelectCup->mUnk_3c = 0;
    if (gSelectCup->mUnk_40 == 0) {
        if (gSelectCup->mUnk_6c == 1) {
            if (func_0211e130() != 0) {
                func_021282c8();
            }
        }
    } else {
        func_021282c8();
    }
}

void InitSelectCup(void *b, void *c, void *d, s32 e) {
    void *a;
    s32 x;
    s32 i;
    u32 v;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    a = func_02036948(b);
    gSelectCup = func_02036bec(a, 0x70);
    gSelectCup->mUnk_30 = a;
    gSelectCup->mUnk_34 = 0;
    gSelectCup->mUnk_50 = data_0215cb7c[func_020296e4()];
    gSelectCup->mUnk_54 = 1;
    gSelectCup->mUnk_58 = 0;
    gSelectCup->mUnk_40 = e;
    gSelectCup->mUnk_5c = gSelectCup->mUnk_50;
    gSelectCup->mUnk_60 = 0;
    gSelectCup->mUnk_64 = c;
    gSelectCup->mUnk_68 = d;
    gSelectCup->mUnk_6c = 0;
    func_0211a3bc();
    gSelectCup->mUnk_28 = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_02124ed0(gSelectCup->mUnk_30, gSelectCup->mUnk_04, gSelectCup->mUnk_08, &gSelectCup->mUnk_1c);
        func_02124ed0(gSelectCup->mUnk_30, gSelectCup->mUnk_10, gSelectCup->mUnk_18, &gSelectCup->mUnk_20);
        x = 0x8000;
        x -= func_021243ac(gSelectCup->mUnk_30, 0, gSelectCup->mUnk_08, 0xb4, 0xd, 0, gSelectCup->mUnk_00,
                           gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        x -= func_021243ac(gSelectCup->mUnk_30, 1, gSelectCup->mUnk_08, 0xb4, 0xd, 1, gSelectCup->mUnk_00,
                           gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        x -= func_021243ac(gSelectCup->mUnk_30, 2, gSelectCup->mUnk_08, 0x96, 0xd, 2, gSelectCup->mUnk_00,
                           gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        x -= func_021243ac(gSelectCup->mUnk_30, 3, gSelectCup->mUnk_08, 0x50, 0xd, 3, gSelectCup->mUnk_00,
                           gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        x -= func_021243ac(gSelectCup->mUnk_30, 4, gSelectCup->mUnk_08, 0x96, 0xd, 4, gSelectCup->mUnk_00,
                           gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        func_021243ac(gSelectCup->mUnk_30, 5, gSelectCup->mUnk_08, 0x50, 0xd, 5, gSelectCup->mUnk_00,
                      gSelectCup->mUnk_04, gSelectCup->mUnk_1c, x);
        v = func_02148ca0();
        for (i = 0; i < 4; i++) {
            v -= func_021243ac(gSelectCup->mUnk_30, data_0215cab4[i], gSelectCup->mUnk_18, data_0215cabc[i],
                               data_0215cac4[i], data_0215caa4[i], gSelectCup->mUnk_0c, gSelectCup->mUnk_10,
                               gSelectCup->mUnk_20, v);
        }
        func_0211de40(gSelectCup->mUnk_30);
        func_0211df44(gSelectCup->mUnk_30);
    } else {
        gSelectCup->mUnk_2c = FindSceneFile("ghost.bmg");
        func_0211f4b0(gSelectCup->mUnk_30, gSelectCup->mUnk_68);
        func_0211f380();
    }
    func_0211a100();
    func_02119e88();
    func_02119c20();
    func_02036820(gSelectCup->mUnk_30);
}

void func_021196f4(void) {
    if (gSelectCup->mUnk_6c == 1) {
        if (gSelectCup->mUnk_40 == 0) {
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
    func_02036ab0(gSelectCup->mUnk_30);
    gSelectCup = NULL;
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

    gSelectCup->mUnk_3c++;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_020ae4c0(1, 0x100, 0, gSelectCup->mUnk_3c, 10);
        v = func_020ae4c0(1, -0xc0, 0, gSelectCup->mUnk_3c, 10);
        if (func_020cccb4() != 0x1a) {
            w = gSelectCup->mUnk_04->mUnk_06;
            gSelectCup->mUnk_44 = v;
            gSelectCup->mUnk_1c[0].mUnk_06 = v;
            gSelectCup->mUnk_1c[2].mUnk_06 = v;
            gSelectCup->mUnk_1c[1].mUnk_06 = v;
            gSelectCup->mUnk_1c[4].mUnk_06 = v;
            gSelectCup->mUnk_1c[3].mUnk_06 = v;
            gSelectCup->mUnk_1c[5].mUnk_06 = v;
            gSelectCup->mUnk_1c[w].mUnk_06 = v;
            gSelectCup->mUnk_1c[w + 1].mUnk_06 = v;
            gSelectCup->mUnk_1c[w + 2].mUnk_06 = v;
            gSelectCup->mUnk_1c[w + 3].mUnk_06 = v;
            gSelectCup->mUnk_1c[w + 4].mUnk_06 = v;
            gSelectCup->mUnk_1c[w + 5].mUnk_06 = v;
        }
        if (func_020cccb4() == 0x1a) {
            w = gSelectCup->mUnk_10->mUnk_06;
            gSelectCup->mUnk_48 = v - 0x20;
            gSelectCup->mUnk_20[0x14].mUnk_06 = v - 0x20;
            gSelectCup->mUnk_20[0x13].mUnk_06 = v - 0x20;
            gSelectCup->mUnk_20[2].mUnk_06 = v - 0x20;
            gSelectCup->mUnk_20[1].mUnk_06 = v - 0x20;
            gSelectCup->mUnk_20[0].mUnk_06 = v - 0x20;
            for (i = 0; i < 8; i++) {
                gSelectCup->mUnk_20[data_0215cacc[i]].mUnk_06 = v - 0x20;
            }
            v -= 0x20;
            for (i = 0; i < 4; i++) {
                gSelectCup->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
                gSelectCup->mUnk_20[w + data_0215cab4[i]].mUnk_06 = v;
            }
        }
    }
    if (gSelectCup->mUnk_3c >= 10) {
        func_02119bf0();
    }
}
#pragma thumb off

#pragma thumb on

void func_0211952c(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        func_02119bdc();
    }
}

#pragma thumb off
