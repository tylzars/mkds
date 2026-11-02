#include "00/code_0218e2a4.h"

#include "00/code_0218e2dc.h"

s32 func_ov000_0218e2c0(void) {
    data_ov000_021b23ac = func_ov000_0218e2dc(data_ov000_021b23ac);
    return data_ov000_021b23ac;
}

void func_ov000_0218e2a4(u32 seed) {
    if (seed != 0) {
        seed &= 0x7fffffff;
    } else {
        seed = 1;
    }
    data_ov000_021b23ac = seed;
}
