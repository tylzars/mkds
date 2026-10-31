#include "00/code_021935bc.h"

u32 func_ov000_021935bc(u32 param_1, u32 param_2, u32 *param_3, u32 *param_4, u32 *param_5) {
    int v1;
    u32 v2;
    u32 v3;
    v2 = (int) param_2 >> 0x18 & 0xff;
    v3 = (int) param_2 >> 0x10 & 0xff;
    param_2 = param_2 & ((u32) 0x0000ffffu);
    v1 = func_ov000_02193634((int) (v2), (int) (v3), (int) (param_2));
    if (v1 == 0) {
        func_0213442c(data_ov000_021b323c, data_ov000_021b31f8, 0, 0xb7);
    }
    v1 = func_ov000_02193634((int) (v2), (int) (v3), (int) (param_2));
    if (v1 == 0) {
        func_ov000_02196590((u32 *) (u32) (param_1), data_ov000_021b3254);
        return 2;
    }
    *param_3 = v2;
    *param_4 = v3;
    *param_5 = param_2;
    return 0;
}
