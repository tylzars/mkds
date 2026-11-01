#include "01/code_0219d620.h"
#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02125f54.h"

void func_ov001_0219d998(void) {
    s32 i;
    s32 j;
    s32 value;

    if (func_ov001_02192e84() == -1 && data_ov001_021a9bfc->mUnk_20 == 6) {
        func_ov001_02192e78(3);
    }
    data_ov001_021a9bfc->mUnk_14++;
    value = func_020ae4c0(1, 0, 250, data_ov001_021a9bfc->mUnk_14, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 0) {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = -value;
            } else {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = value;
            }
        }
    }
    if (data_ov001_021a9bfc->mUnk_14 >= 10) {
        if (data_ov001_021a9bfc->mUnk_14 >= 10 && (func_02128294() != 0 || func_02128274() != 0)) {
            if (func_ov001_02192e84() == -1) {
                Unk021a9bfc *obj = data_ov001_021a9bfc;
                s32 arg;
                void *first;

                if (obj->mUnk_0c == obj->mUnk_10) {
                    func_ov001_02192ea0(obj->mUnk_20);
                    return;
                }
                arg = 9;
                if (obj->mUnk_0c == 1) {
                    arg = 10;
                }
                obj->mUnk_04 = 6;
                func_02125ebc(0x21);
                first = func_020b3f7c(data_ov001_021a9bfc->mUnk_50, arg);
                func_02126230((u32) first, (u32) func_020b3f7c(data_ov001_021a9bfc->mUnk_54, 4));
                data_ov001_021a9bfc->mUnk_14 = 0;
            }
        }
    }
}

void func_ov001_0219d934(void) {
    s32 value;

    if (func_02125f54() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                value = data_021759d4->mUnk_10;
            } else {
                value = 0;
            }
        } else {
            value = 1;
        }
        if (value == 0) {
            func_02125ebc(0x23);
            func_02125fc0();
            return;
        }
    }
    if (func_02125f88() != 0) {
        func_ov001_02192ea0(data_ov001_021a9bfc->mUnk_20);
    }
}

void func_ov001_0219d858(void) {
    s32 i;
    s32 j;
    s32 index;
    s32 k;

    index = data_ov001_021a9bfc->mUnk_44->mUnk_06;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][j]].mUnk_04 = data_ov001_021a9bfc->mUnk_18[i].mUnk_00;
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][j]].mUnk_06 = data_ov001_021a9bfc->mUnk_18[i].mUnk_02;
        }
    }
    data_ov001_021a9bfc->mUnk_34[index].mUnk_04 = data_ov001_021a9bfc->mUnk_18[1].mUnk_00;
    data_ov001_021a9bfc->mUnk_34[index].mUnk_06 = data_ov001_021a9bfc->mUnk_18[1].mUnk_02;
    for (k = 0; k < 3; k++) {
        data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[k][0]].mUnk_04 -=
            func_020adc64(6 - data_ov001_021a9bfc->mUnk_28[0]);
        data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[k][1]].mUnk_04 +=
            func_020adc64(6 - data_ov001_021a9bfc->mUnk_28[1]);
    }
}

void func_ov001_0219d810(void) {
    s32 i;

    for (i = 0; i < data_ov001_021a6c30[1]; i++) {
        if (i == data_ov001_021a9bfc->mUnk_0c) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c1c[1][i]].mUnk_00 = 1;
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c1c[1][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219d730(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        if (i == data_ov001_021a9bfc->mUnk_08 && data_ov001_021a9bfc->mUnk_24 != 0) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][1]].mUnk_00 = 1;
            if (i == 1) {
                func_02124100(0, 14, data_ov001_021a9bfc->mUnk_4c, data_ov001_021a9bfc->mUnk_34,
                              data_ov001_021a9bfc->mUnk_44);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 14, data_ov001_021a9bfc->mUnk_38,
                              data_ov001_021a9bfc->mUnk_44);
            }
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][1]].mUnk_00 = 0;
            if (i == 1) {
                func_02124100(0, 15, data_ov001_021a9bfc->mUnk_4c, data_ov001_021a9bfc->mUnk_34,
                              data_ov001_021a9bfc->mUnk_44);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 15, data_ov001_021a9bfc->mUnk_38,
                              data_ov001_021a9bfc->mUnk_44);
            }
        }
    }
}

void func_ov001_0219d6ac(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (data_ov001_021a9bfc->mUnk_08 == 1) {
            if (data_ov001_021a9bfc->mUnk_28[i] > 0) {
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 1;
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
                data_ov001_021a9bfc->mUnk_28[i]--;
            } else {
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
            }
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219d620(void) {
    data_ov001_021a9bfc->mUnk_00 = data_ov001_021a9bfc->mUnk_04;
    switch (data_ov001_021a9bfc->mUnk_00) {
        case 0:
            func_ov001_0219de18();
            break;
        case 1:
            func_ov001_0219dd94();
            break;
        case 2:
            func_ov001_0219dd74();
            break;
        case 3:
            func_ov001_0219dadc();
            break;
        case 4:
            func_ov001_0219daa0();
            break;
        case 5:
            func_ov001_0219d998();
            break;
        case 6:
            func_ov001_0219d934();
            break;
    }
    func_ov001_0219d858();
    func_ov001_0219d810();
    func_ov001_0219d730();
    func_ov001_0219d6ac();
    func_02124c30(data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_38, data_ov001_021a9bfc->mUnk_4c,
                  func_ov001_0219e90c(), data_ov001_021a9bfc->mUnk_34);
}
