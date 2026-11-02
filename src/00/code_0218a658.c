#include "00/code_0218a658.h"

u32 func_ov000_0218a658(u32 param_1) {
    int v1;
    v1 = memcmp((const u8 *) (param_1), (const u8 *) &data_ov000_021b2168, 8);
    if (v1 == 0) {
        return 1;
    }
    return 0;
}
