#include "00/code_02192d64.h"

u32 func_ov000_02192d64(Unk0218f960 *param_1, Unk021906e4 *param_2) {
    Unk0218f960_00 *v1;
    v1 = param_1->mUnk_00;
    if (0 < v1->mUnk_448) {
        func_ov000_02190b80(param_1, param_2, data_ov000_021b3184);
        func_ov000_02190b58(param_1, param_2, v1->mUnk_198);
        func_ov000_02190b80(param_1, param_2, v1->mUnk_440);
        func_ov000_02190b80(param_1, param_2, data_ov000_021b2f94);
        v1->mUnk_448 = 0;
    }
    if (0 < v1->mUnk_458) {
        func_ov000_02190b80(param_1, param_2, data_ov000_021b319c);
        func_ov000_02190b58(param_1, param_2, v1->mUnk_198);
        func_ov000_02190b80(param_1, param_2, v1->mUnk_450);
        func_ov000_02190b80(param_1, param_2, data_ov000_021b2f94);
        v1->mUnk_458 = 0;
    }
    return 0;
}
