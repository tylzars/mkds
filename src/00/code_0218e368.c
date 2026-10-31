#include "00/code_0218e368.h"
#include "00/code_021a8c1c.h"
#include "00/code_021a8f0c.h"

s32 func_ov000_0218e394(u32 p0, void *p1, u32 *p2) {
    u32 v2 = (((u32) p1) + (0x0u));
    u32 v3 = (((u32) p2) + (0x0u));
    u32 v4 = ((u32) *(u32 *) ((v3) + (0)));
    u32 v6;
    u32 v7;
    u32 v10;
    u32 v11;
    *(u8 *) ((v2) + (0)) = (u8) v4;
    v6 = func_ov000_021a8f0c(p0, (u32) p1);
    v7 = ((u32) *(u8 *) ((v2) + (0)));
    *(u32 *) ((v3) + (0)) = v7;
    v10 = ~(0x0u);
    v11 = func_ov000_0218e56c(v6, v10);
    return v11;
}

u32 func_ov000_0218e374(u32 param_1) {
    int v1;
    u32 v2[1];
    v1 = func_ov000_021a8c1c(param_1, (u32 *) v2);
    if (v1 == 0) {
        return 0xffffffff;
    }
    return v2[0];
}

u32 func_ov000_0218e368(s32 param_1) {
    return *(u32 *) &data_ov000_021b4e08;
}
