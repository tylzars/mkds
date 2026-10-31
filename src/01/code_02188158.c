#include "01/code_02188158.h"

void func_ov001_02188200(Unk02188950 *param_1, UnkFunc *param_2) {
    param_1->mUnk_2d4 = param_2;
    return;
}

void func_ov001_021881f4(Unk02188950 *param_1, UnkFunc *param_2) {
    param_1->mUnk_2dc = param_2;
}

s32 func_ov001_021881a8(Unk02188950 *param_1, Vec3 *param_2, s32 param_3, s32 param_4) {
    if ((param_3 != 0 || param_4 != 0) &&
        (param_3 == 0 || func_ov001_02188f04(param_1, param_2, param_3) != 0) &&
        (param_4 == 0 || func_ov001_02188eac(param_1, param_1->mUnk_1a8, param_2, param_4) != 0)) {
        return 1;
    }
    return 0;
}

int func_ov001_02188158(u32 param_1, u32 param_2, u32 param_3) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = func_020fd7f0();
    v4 = 0;
    if (0 < v1) {
        do {
            v2 = func_020fd7a4((int) (v4));
            if ((v2 != 0) &&
                (v3 = func_ov001_021881a8((Unk02188950 *) (param_1), (Vec3 *) (v2 + 0x50), (s32) (param_2), (s32) (param_3)),
                 v3 != 0)) {
                return v2;
            }
            v4 = v4 + 1;
        } while (v4 < v1);
    }
    return 0;
}
