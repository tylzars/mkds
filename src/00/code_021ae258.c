#include "00/code_021ae258.h"
#include "00/code_021a998c.h"

void func_ov000_021ae2d8(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != 0) {
        v1->mUnk_08 = 10;
        v1->mUnk_44 = 0;
    }
}

void func_ov000_021ae290(int param_1, u16 param_2, int param_3) {
    u16 v1;
    Unk021a998c *v2;
    v2 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v2 != 0) {
        if (param_3 == 0x7f000001) {
            param_3 = *(int *) &data_ov000_021b63b4;
        }
        v2->mUnk_1a = param_2;
        v2->mUnk_18 = v2->mUnk_1a;
        v2->mUnk_20 = param_3;
        v2->mUnk_1c = v2->mUnk_20;
        if (param_1 == 0) {
            v1 = func_ov000_021ae340();
            v2->mUnk_0a = v1;
            return;
        }
        v2->mUnk_0a = (short) param_1;
    }
}

void func_ov000_021ae270(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != (Unk021a998c *) 0x0) {
        v1->mUnk_00 = data_0216ff5c.mUnk_04;
        v1->mUnk_08 = 0;
        v1->mUnk_44 = 0;
        v1->mUnk_60 = 0;
        v1->mUnk_38 = 0;
    }
}

void func_ov000_021ae258(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != (Unk021a998c *) 0x0) {
        v1->mUnk_00 = 0;
    }
}
