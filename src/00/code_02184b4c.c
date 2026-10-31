#include "00/code_02184b4c.h"

void func_ov000_02184b68(u32 param_1) {
    int v1;
    u32 v2;
    u32 v3;
    v1 = ((u32) func_02036bec((void *) (param_1), 8));
    *(int *) &data_ov000_021b4c80 = v1;
    *(u32 *) (v1 + 4) = param_1;
    func_ov000_02184b4c();
    v2 = ((u32) func_ov000_021804f4());
    v3 = ((int) func_ov000_021804e0());
    func_0202ab2c((u32) (param_1), (u32) (v2), (u32) (v3));
    func_0212a910(1, 1);
    return;
}

void func_ov000_02184b50(void) {
    func_0202a90c();
    *(u32 *) &data_ov000_021b4c80 = 0;
    return;
}

void func_ov000_02184b4c(void) {
    return;
}
