#include "00/code_0218ed74.h"

u32 func_ov000_0218ed74(int *param_1, int param_2) {
    int v1;
    int v2;
    int v3;
    if ((param_1 == (int *) 0x0) || (v2 = *param_1, v2 == 0)) {
        return 2;
    }
    if (*(int *) (v2 + 0x108) != 0) {
        return 0;
    }
    if (*(int *) (v2 + 0x1d8) == 4) {
        func_ov000_02196590(param_1, data_ov000_021b23e8);
        return 2;
    }
    v1 = func_ov000_02194934((Unk0218f960 *) param_1, param_2, (Unk02194934 **) &v3);
    if (v1 == 0) {
        return 0;
    }
    *(int *) (v3 + 0x14) = *(int *) (v3 + 0x14) + -1;
    if ((*(int *) (v2 + 0x100) == 0) && (*(int *) (v3 + 0x14) <= 0)) {
        func_ov000_021a3668((void *) (*(u32 *) (v3 + 0x10)));
        *(u32 *) (v3 + 0x10) = 0;
        v2 = func_ov000_021947e4((Unk02194934 *) v3);
        if (v2 != 0) {
            func_ov000_021948f8((Unk0218f960 *) param_1, (Unk02194934 *) v3);
        }
    }
    return 0;
}
