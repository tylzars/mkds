#include "00/code_02191200.h"

int func_ov000_02191200(Unk0218f960 *param_1) {
    int v1;
    Unk0218f960_00 *v2;
    int v3;
    v2 = param_1->mUnk_00;
    v1 = func_ov000_02196714(param_1, v2->mUnk_1d4, (u32 *) (&v3));
    if (v1 == 0) {
        if (v3 == 4) {
            func_ov000_021965a0(param_1, 0x107u, data_ov000_021b2b48);
            func_ov000_02190f4c(param_1, 4, 1);
            return 4;
        }
        if (v3 == 0) {
            return 0;
        }
        if (v3 != 3) {
            func_0213442c(data_ov000_021b2b70, data_ov000_021b2b88, 0, 0x2ef);
        }
        v2->mUnk_1d8 = 2;
        v1 = 0;
    }
    return v1;
}
