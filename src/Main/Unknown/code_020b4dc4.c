#include "Main/Unknown/code_020b4dc4.h"

u32 func_020b4df8(void) {
    return ((u32) *(
        const u32 *) ((u8 *) (u32) (((u32) *(
                                   const u32 *) ((u8 *) (u32) (((u32) (&data_021759c0))) +
                                                          0))) +
                               8));
}

u32 func_020b4dc4(int param_1) {
    int v1;
    u32 v2;
    v1 = func_020b4df8();
    if ((v1 == 1) && (param_1 != 0)) {
        return 1;
    }
    v2 = func_0207a68c(param_1);
    return v2;
}
