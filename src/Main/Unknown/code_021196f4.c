#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_021196f4.h"

#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df38.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "registers.h"

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

void func_02119770(void *param_1, void *param_2, void *param_3, s32 param_4) {
    void *a;
    s32 x;
    s32 i;
    u32 v;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    a = func_02036948(param_1);
    data_0217d364 = func_02036bec(a, 0x70);
    data_0217d364->mUnk_30 = a;
    data_0217d364->mUnk_34 = 0;
    data_0217d364->mUnk_50 = data_0215cb7c[func_020296e4()];
    data_0217d364->mUnk_54 = 1;
    data_0217d364->mUnk_58 = 0;
    data_0217d364->mUnk_40 = param_4;
    data_0217d364->mUnk_5c = data_0217d364->mUnk_50;
    data_0217d364->mUnk_60 = 0;
    data_0217d364->mUnk_64 = param_2;
    data_0217d364->mUnk_68 = param_3;
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
        data_0217d364->mUnk_2c = func_0204799c("ghost.bmg");
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
