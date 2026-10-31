#include "03/code_021d1f70.h"

u8 func_ov003_021d1f70(int param_1) {
    int v1;
    if (param_1 == 1) {
        v1 = *(int *) &data_ov003_021da2c0;
    } else {
        v1 = (int) data_ov003_021da2c0 + 0xc;
    }
    return *(u8 *) (v1 + 9);
}
