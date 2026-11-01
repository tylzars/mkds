#include "01/code_0219a304.h"
#include "01/code_0219a950.h"
#include "01/code_0219ae30.h"
#include "01/unk_021a6000.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02114000.h"
#include "00/code_02182fdc.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_02111488.h"
#include "code_0201ea58.h"

void func_ov001_0219a5bc(void) {
    Unk02175628Index i;
    u16 flags;
    s32 b;
    s32 sel;
    s32 a;
    s32 b2;
    s32 a2;
    s32 t;

    b = 0;
    sel = -1;
    i = UNK_02175628_INDEX_8;
    a = 0;
    if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
        b = 1;
    }
    if (b != 0) {
        sel = func_0201ea84(data_ov001_021a9bf0->mUnk_14, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b2 = 0;
        a2 = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            b2 = 1;
        }
        if (b2 == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto skip;
        }
    }
    func_021281c8(15);
    func_ov001_0219adfc();
    data_ov001_021a9bf0->mUnk_44 = 5;
    func_02128310(1);
    return;
skip:
    if ((u32) sel <= 2) {
        t = data_ov001_021a6acc[sel];
        if (data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[t]].mUnk_00 != 0) {
            if (data_ov001_021a9bf0->mUnk_40 == t) {
                func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
                data_ov001_021a9bf0->mUnk_40 = t;
            } else {
                func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
                data_ov001_021a9bf0->mUnk_40 = t;
                func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
            }
            func_ov001_0219ae10();
        }
    } else {
        flags = data_02175628[i].mUnk_00 & 1;
        if (flags != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ae10();
        } else if (func_020ae408(8, 0x40) != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ad10();
            func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
        } else if (func_020ae408(8, 0x80) != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ad3c();
            func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
        }
    }
}

void func_ov001_0219a4fc(void) {
    s16 v;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae488(data_ov001_021a9bf0->mUnk_38);
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    if (data_ov001_021a9bf0->mUnk_38 == 5) {
        func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        if (data_ov001_021a9bf0->mUnk_40 == 2 && func_021143b4() == 0) {
            func_ov001_0219ade8();
            return;
        }
        data_ov001_021a9bf0->mUnk_44 = data_ov001_021a6ad8[data_ov001_021a9bf0->mUnk_40];
        func_ov001_0219adfc();
    }
}

void func_ov001_0219a3a0(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    if (func_0211145c() == -1 && data_ov001_021a9bf0->mUnk_44 == 5) {
        func_02111450(0);
    }
    data_ov001_021a9bf0->mUnk_38++;
    a = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9bf0->mUnk_38, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_ov001_021a9bf0->mUnk_38, 10);
    data_ov001_021a9bf0->mUnk_3c = b;
    idx = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10 && func_0211145c() == -1) {
        func_02111488(data_ov001_021a9bf0->mUnk_44);
    }
}

void func_ov001_0219a304(void) {
    s16 v;
    s32 i;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9bf0->mUnk_38, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219adbc();
    }
}
