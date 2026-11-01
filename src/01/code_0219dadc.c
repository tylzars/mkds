#include "01/code_0219dadc.h"
#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02056d40.h"
#include "code_0201ea58.h"

void func_ov001_0219dadc(void) {
    Unk02175628Index index = UNK_02175628_INDEX_8;
    s32 result = -1;
    s32 cond2 = 0;
    s32 cond1 = 0;
    u16 value;
    u16 flags;

    value = data_02175628[index].mUnk_4c;
    if (value == 0 && data_02175628[index].mUnk_58 < 5) {
        cond1 = 1;
    }
    if (cond1 == 0 && data_02175628[index].mUnk_54 == 0 && value != 0) {
        cond2 = 1;
    }
    if (cond2 != 0) {
        result =
            func_0201ea84(data_ov001_021a9bfc->mUnk_48, data_02175628[index].mUnk_48, data_02175628[index].mUnk_4a);
    }
    flags = data_02175628[index].mUnk_00 & 2;
    if (flags != 0) {
        goto next;
    }
    cond2 = 0;
    cond1 = 0;
    value = data_02175628[index].mUnk_4c;
    if (value == 0 && data_02175628[index].mUnk_58 < 5) {
        cond1 = 1;
    }
    if (cond1 == 0 && data_02175628[index].mUnk_54 == 0 && value != 0) {
        cond2 = 1;
    }
    if (cond2 != 0 && func_02128210(data_02175628[index].mUnk_48, data_02175628[index].mUnk_4a) != 0) {
    next:
        data_ov001_021a9bfc->mUnk_04 = 5;
        data_ov001_021a9bfc->mUnk_20 = 2;
        if (data_ov001_021a9bfc->mUnk_0c != data_ov001_021a9bfc->mUnk_10) {
            func_02128310(1);
        } else {
            func_02128310(0);
        }
        if (data_ov001_021a9bfc->mUnk_0c == 0) {
            data_0217aa08->mUnk_00->mUnk_31_3 = 0;
        } else {
            data_0217aa08->mUnk_00->mUnk_31_3 = 1;
        }
        func_02056d40();
    } else {
        flags = data_02175628[index].mUnk_00 & 1;
        if ((flags != 0 && data_ov001_021a9bfc->mUnk_08 == 0) || result == 0) {
            if (data_ov001_021a9bfc->mUnk_08 == 0) {
                data_ov001_021a9bfc->mUnk_24 = 0;
            }
            data_ov001_021a9bfc->mUnk_04 = 4;
            data_ov001_021a9bfc->mUnk_20 = 6;
            data_ov001_021a9bfc->mUnk_08 = 0;
            data_0217b488->mUnk_18 = 1;
            func_02105ac0(5);
        } else if (result == 1) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c++;
            func_02105ac0(1);
        } else if (func_020ae408(8, 0x40) != 0 && data_ov001_021a9bfc->mUnk_08 > 0) {
            data_ov001_021a9bfc->mUnk_08--;
            func_02105ac0(0);
        } else if (func_020ae408(8, 0x80) != 0 && data_ov001_021a9bfc->mUnk_08 < 1) {
            data_ov001_021a9bfc->mUnk_08++;
            func_02105ac0(0);
        } else if (data_ov001_021a9bfc->mUnk_08 == 1 && func_020ae408(8, 0x20) != 0) {
            data_ov001_021a9bfc->mUnk_0c--;
            data_ov001_021a9bfc->mUnk_28[0] = 6;
            func_02105ac0(1);
        } else if (data_ov001_021a9bfc->mUnk_08 == 1 && func_020ae408(8, 0x10) != 0) {
            data_ov001_021a9bfc->mUnk_0c++;
            if (func_020ae408(8, 0x10) != 0) {
                data_ov001_021a9bfc->mUnk_28[1] = 6;
            }
            func_02105ac0(1);
        } else if (result == 2) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c--;
            data_ov001_021a9bfc->mUnk_28[0] = 6;
            func_02105ac0(1);
        } else if (result == 3) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c++;
            data_ov001_021a9bfc->mUnk_28[1] = 6;
            func_02105ac0(1);
        }
    }
    if (data_ov001_021a9bfc->mUnk_0c < 0) {
        data_ov001_021a9bfc->mUnk_0c = 1;
    }
    if (data_ov001_021a9bfc->mUnk_0c > 1) {
        data_ov001_021a9bfc->mUnk_0c = 0;
    }
}
