#include "00/code_02181e98.h"

void func_ov000_02181e98(void *a) {
    s32 i;
    s32 j;
    s32 k;

    data_ov000_021b4c6c = func_02036bec(a, 0x40);
    data_ov000_021b4c6c->mUnk_14 = (s32) a;
    data_ov000_021b4c6c->mUnk_00 = 0;
    data_ov000_021b4c6c->mUnk_04 = 0;
    data_ov000_021b4c6c->mUnk_10 = -1;
    switch (func_ov000_021806d4()) {
        case 0:
        case 2:
            data_ov000_021b4c6c->mUnk_08 = 0;
            break;
        case 8:
            data_ov000_021b4c6c->mUnk_08 = 1;
            break;
        case 13:
            data_ov000_021b4c6c->mUnk_08 = 2;
            break;
    }
    data_ov000_021b4c6c->mUnk_0c = 0;
    data_ov000_021b4c6c->mUnk_18 = 1;
    data_ov000_021b4c6c->mUnk_38 = func_0204799c("wifi.bmg");
    data_ov000_021b4c6c->mUnk_3c = func_02047a28("common.bmg");
    func_ov000_02181df8();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov000_021b05c0[i], 1, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c6c->mUnk_2c, 0, &data_ov000_021b4c6c->mUnk_1c);
    for (j = 0; j < 3; j++) {
        for (k = 0; k < data_ov000_021b05cc[j]; k++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[j][k]].mUnk_04 = 0xdc;
        }
    }
    func_0212a910(1, 0);
    func_021281c8(0xf);
    func_0204f7f4();
}
