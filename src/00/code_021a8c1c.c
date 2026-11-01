#include "00/code_021a8c1c.h"

u8 *func_ov000_021a8c6c(Unk021b5dfc a) {
    func_ov000_021a8bc0(2, &a, (char *) data_ov000_021b6030, 0x10);
    return data_ov000_021b6030;
}

u32 func_ov000_021a8c1c(u32 param_1, u32 *param_2) {
    u32 a = func_ov000_021a88a8(param_1);
    if (a == 0) {
        return 0;
    }
    *param_2 = ((a << 24) & 0xff000000) | (((a << 8) & 0xff0000) | (((a >> 24) & 0xff) | ((a >> 8) & 0xff00)));
    return 1;
}
