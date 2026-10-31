#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df38.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_021189cc.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "registers.h"

#pragma thumb on

void func_02118038(void) {
    data_0217d360->mUnk_34 = 0xa;
    data_0217d360->mUnk_38 = 0;
    func_021277e4();
}

void func_02118024(void) {
    data_0217d360->mUnk_34 = 0xb;
    data_0217d360->mUnk_38 = 0;
}

void func_02117e24(void *param_1, void *param_2, void *param_3, s32 param_4) {
    s32 rem;
    int i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    param_1 = func_02036948(param_1);
    data_0217d360 = func_02036bec(param_1, 0x8c);
    data_0217d360->mUnk_2c = param_1;
    data_0217d360->mUnk_30 = 0;
    data_0217d360->mUnk_44 = data_0215c8fc[func_0202968c()];
    data_0217d360->mUnk_68 = 1;
    data_0217d360->mUnk_6c = 0;
    data_0217d360->mUnk_3c = param_4;
    data_0217d360->mUnk_70 = data_0217d360->mUnk_44;
    data_0217d360->mUnk_7c = 0;
    data_0217d360->mUnk_80 = param_2;
    data_0217d360->mUnk_84 = param_3;
    data_0217d360->mUnk_88 = 0;
    func_02118400();
    func_021189cc();
    func_02118b48();
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        func_020ae6d4(data_0217d360->mUnk_80, data_0217d360->mUnk_84);
    }
    data_0217d360->mUnk_24 = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        data_0217d360->mUnk_28 = func_0204799c("menu.bmg");
        func_02124ed0(data_0217d360->mUnk_2c, data_0217d360->mUnk_04, data_0217d360->mUnk_08, &data_0217d360->mUnk_18);
        func_02124ed0(data_0217d360->mUnk_2c, data_0217d360->mUnk_10, 0, &data_0217d360->mUnk_1c);
        rem = 0x8000;
        for (i = 0; i < 4; i++) {
            rem -= func_021243ac(data_0217d360->mUnk_2c, data_0215c7d8[i], data_0217d360->mUnk_08, data_0215c7e0[i], data_0215c7e8[i], data_0215c7d0[i], data_0217d360->mUnk_00, data_0217d360->mUnk_04, data_0217d360->mUnk_18, rem);
        }
        func_0211de40(data_0217d360->mUnk_2c);
        func_0211df44(data_0217d360->mUnk_2c);
        func_0211f2b8(data_0217d360->mUnk_2c);
    } else {
        func_0211f4b0(data_0217d360->mUnk_2c, data_0217d360->mUnk_84);
        if (func_020cccb4() != 0xc) {
            func_0211f394();
        } else {
            func_0211f380();
        }
    }
    func_021188dc();
    func_02118624();
    func_021181fc();
    func_02036820(data_0217d360->mUnk_2c);
    if (data_021759d0->mUnk_20 == 2) {
        func_021281fc();
    }
}

void func_02117db0(void) {
    if ((data_0217d360->mUnk_3c == 0 && data_0217d360->mUnk_88 == 1) || data_0217d360->mUnk_88 == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0211de34();
        func_0211df38();
        func_0211f2ac();
    } else {
        func_0211f498();
    }
    func_02036ab0(data_0217d360->mUnk_2c);
    data_0217d360 = 0;
}

#pragma thumb off
