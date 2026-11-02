#include "00/code_0218e368.h"
#include "00/unk_021b4000.h"

#include "00/code_021a88a8.h"
#include "00/code_021a4654.h"
#include "00/code_021a8aa8.h"
#include "00/code_0218e49c.h"

u32 func_ov000_0218e3b8(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 param_5) {
    u32 value0;
    u32 value1;
    u32 value3;
    value0 = 0u;
    value1 = ~(value0);
    value3 = (u32) &func_ov000_0218e56c;
    value0 = (u32) func_ov000_0218e56c(value0, value1);
    return value0;
}

s32 func_ov000_0218e394(u32 p0, void *p1, u32 *p2) {
    u32 v2 = (((u32) p1) + (0x0u));
    u32 v3 = (((u32) p2) + (0x0u));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v6;
    u32 v7;
    u32 v10;
    u32 v11;
    *(u8 *) ((v2) + (0)) = (u8) v4;
    v6 = func_ov000_021a8f0c(p0, (u32) p1);
    v7 = ((u32) * (u8 *) ((v2) + (0)));
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
