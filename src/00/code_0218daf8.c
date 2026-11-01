#include "00/code_0218daf8.h"

void func_ov000_0218daf8(u32 *param_1, u32 param_2, int param_3) {
    int v1;
    u32 v2;
    u8 v3[8];
    if (param_3 == 0) {
        func_0213442c(data_ov000_021b2308, data_ov000_021b22dc, 0, 0xb7);
    }
    v1 = (int) func_ov000_0218d818((void *) param_2, (u8 *) param_1[5], *param_1, param_1[2], (UnkCompare *) param_3,
                                   (s32 *) (void *) (v3));
    v2 = _s32_div_f(v1 - param_1[5], param_1[2]);
    func_ov000_0218db48(param_1, (void *) (param_2), v2);
    return;
}
