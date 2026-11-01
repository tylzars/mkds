#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_02111000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02114c98.h"
#include "Main/Unknown/code_02114cb0.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_0211568c.h"
#include "Main/Unknown/code_021156d4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02182fdc.h"
#include "01/code_02195a6c.h"

#pragma thumb on

void func_02114c48(void) {
    u16 a;

    a = func_02116870();
    if (func_02125f54()) {
        if (func_02125f60() == 0) {
            func_02114174(a + data_0217d350->mUnk_74);
            data_0217d350->mUnk_84 = 1;
        } else {
            data_0217d350->mUnk_84 = 0;
        }
        func_02115cc4();
    }
}

void func_02114ad8(void) {
    s32 i;
    s32 j;
    s16 a;
    u16 x;
    u16 y;
    u16 v;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0, -0x100, data_0217d350->mUnk_5c, 10);
    x = data_0217d350->mUnk_08->mUnk_06;
    y = data_0217d350->mUnk_18->mUnk_06;
    if (func_021143b4() != 0 && data_0217d350->mUnk_84 != 0) {
        data_0217d350->mUnk_68 = a;
        data_0217d350->mUnk_14[1].mUnk_04 = a;
        data_0217d350->mUnk_14[2].mUnk_04 = a;
        data_0217d350->mUnk_14[3].mUnk_04 = a;
        data_0217d350->mUnk_14[x].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 1].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xb].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                data_0217d350->mUnk_14[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        data_0217d350->mUnk_24[1].mUnk_04 = a;
        data_0217d350->mUnk_24[y].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 1].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            data_0217d350->mUnk_24[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    if (func_02125f88()) {
        v = func_02116870();
        if (func_021143b4() <= v) {
            data_0217d350->mUnk_76--;
        }
        if (data_0217d350->mUnk_76 < 0) {
            data_0217d350->mUnk_a0 = 3;
            func_02111488(data_0217d350->mUnk_a0);
        } else {
            func_02115ca0();
        }
    }
}

void func_0211489c(void) {
    s32 i;
    s32 j;
    s16 a;
    s16 b;
    u16 x;
    u16 y;
    u16 z;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0x100, 0, data_0217d350->mUnk_5c, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_0217d350->mUnk_5c, 10);
    x = data_0217d350->mUnk_08->mUnk_06;
    y = data_0217d350->mUnk_18->mUnk_06;
    z = data_0217d350->mUnk_30->mUnk_06;
    if (data_0217d350->mUnk_84 != 0) {
        data_0217d350->mUnk_68 = a;
        data_0217d350->mUnk_14[1].mUnk_04 = a;
        data_0217d350->mUnk_14[2].mUnk_04 = a;
        data_0217d350->mUnk_14[3].mUnk_04 = a;
        data_0217d350->mUnk_14[x].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 1].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xb].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                data_0217d350->mUnk_14[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        data_0217d350->mUnk_24[1].mUnk_04 = a;
        data_0217d350->mUnk_24[y].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 1].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            data_0217d350->mUnk_24[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    data_0217d350->mUnk_70 = b;
    data_0217d350->mUnk_3c[30].mUnk_04 = a;
    data_0217d350->mUnk_3c[31].mUnk_04 = a;
    data_0217d350->mUnk_3c[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (data_0217d350->mUnk_5c > 10) {
        if (func_02128294()) {
            func_02115e0c();
        }
    }
}

void func_02114754(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 z;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0, 0x100, data_0217d350->mUnk_5c, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_0217d350->mUnk_5c, 10);
    z = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = b;
    data_0217d350->mUnk_3c[30].mUnk_04 = a;
    data_0217d350->mUnk_3c[31].mUnk_04 = a;
    data_0217d350->mUnk_3c[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (data_0217d350->mUnk_5c >= 10) {
        func_02111488(data_0217d350->mUnk_a0);
    }
}

void func_02114668(void) {
    data_0217d350->mUnk_54 = data_0217d350->mUnk_58;
    switch (data_0217d350->mUnk_54) {
        case 0:
            func_021156bc();
            break;
        case 1:
            func_021156a4();
            break;
        case 2:
            func_0211568c();
            break;
        case 3:
            func_0211553c();
            break;
        case 4:
            func_02115204();
            break;
        case 5:
            func_02115000();
            break;
        case 6:
            func_02114dfc();
            break;
        case 7:
            func_02114cb0();
            break;
        case 8:
            func_02114c98();
            break;
        case 9:
            func_02114c48();
            break;
        case 10:
            func_02114ad8();
            break;
        case 11:
            func_0211489c();
            break;
        case 12:
            func_02114754();
            break;
    }
    func_02116624();
    switch (data_0217d350->mUnk_40) {
        case 0:
            func_02124c30(data_0217d350->mUnk_08, data_0217d350->mUnk_04, data_0217d350->mUnk_0c, func_02111318(),
                          data_0217d350->mUnk_14);
            break;
        case 1:
            func_02124c30(data_0217d350->mUnk_18, data_0217d350->mUnk_04, data_0217d350->mUnk_1c, func_02111318(),
                          data_0217d350->mUnk_24);
            break;
    }
    func_02124c30(data_0217d350->mUnk_30, data_0217d350->mUnk_2c, data_0217d350->mUnk_38, func_0211130c(),
                  data_0217d350->mUnk_3c);
}

void func_02114604(void) {
    *(vu32 *) 0x4000010 = (-data_0217d350->mUnk_60 & 0x1ff) | ((-data_0217d350->mUnk_64 << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-data_0217d350->mUnk_68 & 0x1ff) | ((-data_0217d350->mUnk_6c << 16) & 0x1ff0000);
    *(vu32 *) 0x400101c = (-data_0217d350->mUnk_70 << 16) & 0x1ff0000;
    func_02111428();
}

void func_021145dc(void) {
    u32 a;

    a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | ((a | 9) << 8);
}

void func_021145b4(void) {
    void (*a[5])() = {func_02115728, func_021156d4, func_02114668, func_02114604, func_021145dc};

    func_02111494(a);
}

#pragma thumb off
