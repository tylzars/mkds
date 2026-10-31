#include "00/code_021a4610.h"

void func_ov000_021a4648(u8 *param_1, u8 *param_2) {
    u8 v1;
    v1 = *param_1;
    *param_1 = *param_2;
    *param_2 = v1;
}

u8 func_ov000_021a4610(u32 param_1) {
    if (param_1 < 0x1a) {
        return param_1 + 0x41 & 0xff;
    }
    if (param_1 < 0x34) {
        return param_1 + 0x47 & 0xff;
    }
    if (param_1 < 0x3e) {
        return param_1 - 4 & 0xff;
    }
    if (param_1 == 0x3e) {
        return 0x2b;
    }
    if (param_1 == 0x3f) {
        return 0x2f;
    }
    return 0;
}
