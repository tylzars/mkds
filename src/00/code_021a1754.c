#include "00/code_021a1754.h"

u32 func_ov000_021a1754(int param_1, int param_2) {
    int v1;
    int v2;
    v2 = *(int *) &data_ov000_021b566c;
    if (0 == v2) {
        return 0;
    }
    v1 = 0;
    if (0 < param_2) {
        do {
            if (param_1 == *(int *) (v2 + 0xf4)) {
                func_ov000_021a1620(v1, param_2);
                return 1;
            }
            v2 = v2 + 4;
            v1 = v1 + 1;
        } while (v1 < param_2);
    }
    return 0;
}
