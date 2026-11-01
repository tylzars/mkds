#include "00/code_02181ab8.h"

void func_ov000_02181b4c(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 v1 = 0;
    u32 v2 = -1;
    s32 v3 = 0;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        v3 = 1;
    }
    if (v3 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        v1 = 1;
    }
    if (v1 != 0) {
        v2 = func_0201ea84(data_ov000_021b4c6c->mUnk_30, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    v5 = data_02175628[i].mUnk_00 & 2;
    if ((u16) v5 == 0) {
        v7 = v6 = 0;
        if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
            v7 = 1;
        }
        if (v7 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
            v6 = 1;
        }
        if (v6 == 0 || func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto next;
        }
    }
    data_ov000_021b4c6c->mUnk_04 = 5;
    data_ov000_021b4c6c->mUnk_10 = 10;
    if (data_ov000_021b4c6c->mUnk_10 == 10) {
        func_02128310(1);
    }
    return;
next:
    v5 = data_02175628[i].mUnk_00 & 1;
    if ((u16) v5 == 0 && v2 > 2) {
        goto skip;
    }
    v4 = data_ov000_021b4c6c->mUnk_08;
    if ((u16) v5 == 0) {
        switch (v2) {
            case 0:
                data_ov000_021b4c6c->mUnk_08 = 0;
                break;
            case 1:
                data_ov000_021b4c6c->mUnk_08 = 1;
                break;
            case 2:
                data_ov000_021b4c6c->mUnk_08 = 2;
                break;
        }
    }
    if (data_ov000_021b4c6c->mUnk_08 == v4) {
        data_ov000_021b4c6c->mUnk_18 = 0;
    }
    data_ov000_021b4c6c->mUnk_04 = 4;
    switch (data_ov000_021b4c6c->mUnk_08) {
        case 0:
            if (func_0211fd68() == 1) {
                data_ov000_021b4c6c->mUnk_10 = 2;
            } else {
                data_ov000_021b4c6c->mUnk_10 = 0;
            }
            break;
        case 1:
            data_ov000_021b4c6c->mUnk_10 = 8;
            break;
        case 2:
            data_ov000_021b4c6c->mUnk_10 = 13;
            break;
    }
    func_02105ac0(5);
    return;
skip:
    if (func_020ae408(8, 0x40) != 0) {
        data_ov000_021b4c6c->mUnk_08--;
        if (data_ov000_021b4c6c->mUnk_08 < 0) {
            data_ov000_021b4c6c->mUnk_08 = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0) {
        data_ov000_021b4c6c->mUnk_08++;
        if (data_ov000_021b4c6c->mUnk_08 > 2) {
            data_ov000_021b4c6c->mUnk_08 = 0;
        }
        func_02105ac0(0);
    }
}

void func_ov000_02181ab8(void) {
    s32 i;
    s32 v;

    data_ov000_021b4c6c->mUnk_0c = data_ov000_021b4c6c->mUnk_0c + 1;
    v = func_020ae488(data_ov000_021b4c6c->mUnk_0c);
    for (i = 0; i < data_ov000_021b05cc[data_ov000_021b4c6c->mUnk_08]; i++) {
        data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[data_ov000_021b4c6c->mUnk_08][i]].mUnk_04 = v;
    }
    if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        data_ov000_021b4c6c->mUnk_04 = 5;
        if (data_ov000_021b4c6c->mUnk_08 == 0 || data_ov000_021b4c6c->mUnk_08 == 2) {
            func_021282c8();
        }
        data_ov000_021b4c6c->mUnk_0c = 0;
    } else if (data_ov000_021b4c6c->mUnk_0c >= 5) {
        data_ov000_021b4c6c->mUnk_18 = 1;
    }
}
