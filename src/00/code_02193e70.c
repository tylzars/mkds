#include "00/code_02193e70.h"

int func_ov000_02193e70(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    int v1;
    int v2[2];
    v1 = func_ov000_021938cc((int *) ((int *) (u32) (param_1)), 2, 0, (int *) (v2), 0, 0, 0);
    if ((v1 == 0) && (v1 = func_ov000_02192330((Unk021919ac *) (u32) (param_1), (u32) (param_2->mUnk_0c),
                                               (u32) (*(u32 *) (v2[0] + 0x18))),
                      v1 == 0)) {
        param_2->mUnk_00 = 0x65;
        v1 = 0;
    }
    return v1;
}
