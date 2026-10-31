#include "00/code_0218e644.h"
#include "00/code_0218e68c.h"

u32 func_ov000_0218e668(u32 param_1) {
    int v1;
    u32 v2[1];
    v2[0] = 0;
    v1 = func_ov000_0218e68c((u32) (param_1), (u32 *) (v2), (u32 *) (0), (u32 *) (0));
    if (v1 == 1) {
        return v2[0];
    }
    return 0;
}

u32 func_ov000_0218e644(u32 param_1) {
    int v1;
    u32 v2[1];
    v2[0] = 0;
    v1 = func_ov000_0218e68c((u32) (param_1), (u32 *) (0), (u32 *) (v2), (u32 *) (0));
    if (v1 == 1) {
        return v2[0];
    }
    return 0;
}
