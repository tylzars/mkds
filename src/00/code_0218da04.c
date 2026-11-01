#include "00/code_0218da04.h"

void func_ov000_0218da5c(Unk0218dc94 *param_1, s32 param_2) {
    if ((param_2 < 0) || (param_2 >= param_1->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, 0, 0xca);
    }
    func_ov000_0218dd74(param_1, param_2);
    func_ov000_0218da9c((int *) param_1, param_2);
}

void func_ov000_0218da1c(Unk0218dc94 *param_1, const void *param_2, s32 param_3) {
    if ((param_3 < 0) || (param_3 >= param_1->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, 0, 0xd3);
    }
    func_ov000_0218dd74(param_1, param_3);
    func_ov000_0218dd18(param_1, param_2, param_3);
}

void func_ov000_0218da04(u32 p0, u32 p1) {
    u32 v2 = ((p0) + (0x0u));
    u32 v3 = ((p1) + (0x0u));
    u32 v4 = ((u32) * (u32 *) ((v2) + (20)));
    u32 v5 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v6 = ((u32) * (u32 *) ((v2) + (8)));
    func_021382a8((u8 *) v4, v5, v6, (int (*)(void *, void *))(v3));
}
