#include "03/code_021c83b0.h"
#include "code_02147cd8.h"

int func_ov003_021c83cc(int param_1) {
    int v1;
    int v2;
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    v2 = 0;
    do {
        if (v1 == param_1) {
            return v2;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    return -1;
}

int func_ov003_021c83b0(int param_1) {
    int v1;
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    return v1 + param_1;
}
