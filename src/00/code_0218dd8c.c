#include "00/code_0218dd8c.h"

int func_ov000_0218dd8c(int *param_1, int param_2, u32 param_3) {
    int v1;
    int v2;
    int v3;
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xd3);
    }
    v3 = 0;
    if (0 < param_1[1]) {
        v2 = 0;
        do {
            v1 = (int) func_ov000_0218d8dc((int *) (u32) (*(u32 *) (*param_1 + v2)), (UnkCompare *) param_2,
                                           (void *) param_3);
            if (v1 != 0) {
                return v1;
            }
            v2 = v2 + 4;
            v3 = v3 + 1;
        } while (v3 < param_1[1]);
    }
    return 0;
}
