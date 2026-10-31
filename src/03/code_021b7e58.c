#include "03/code_021b7e58.h"

void func_ov003_021b7e94(u8 *param_1, u32 param_2, u8 *param_3) {
    int v1;
    v1 = _s32_div_f(param_2, 2);
    func_ov003_021b7d90((void *) param_3, (const void *) (param_1 + v1), v1);
    func_ov003_021b7d90((void *) (param_3 + v1), (const void *) param_1, v1);
    func_ov003_021b7d90((void *) param_1, (const void *) param_3, param_2);
    return;
}

u32 func_ov003_021b7e70(u32 param_1, int param_2) {
    u32 v1;
    if (0 < param_2) {
        v1 = (*(UnkWordFunc *) (*(u32 *) &data_ov003_021d8a0c))(param_2);
        return v1;
    }
    return 0;
}

void func_ov003_021b7e58(u32 param_1, u32 param_2) {
    (*(UnkFunc *) (*(u32 *) &data_ov003_021d8a18))(param_2);
    return;
}
