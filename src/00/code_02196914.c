#include "00/code_02196914.h"

void func_ov000_02196914(u8 *param_1, const void *param_2, s32 param_3) {
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b3b10, data_ov000_021b3a1c, 0, 0x2f);
    }
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b3b20, data_ov000_021b3a1c, 0, 0x30);
    }
    strncpy(param_1, param_2, param_3);
    *(param_1 + param_3 + -1) = 0;
    return;
}
