#include "03/code_021d2ecc.h"
#include "03/code_021d2fa0.h"
#include "03/code_021d27d8.h"

Unk021d1770_08 *func_ov003_021d2eec(int param_1, int param_2) {
    return (Unk021d1770_08 *) (&data_ov003_021da2f0->mUnk_000[param_1][param_2 * 8]);
}

void *func_ov003_021d2ecc(void) {
    u32 v4 = ((u32) func_ov003_021d285c((u32) 0x10u, (u32) 0x4u));
    u32 v7;
    u32 v8;
    *(u32 *) ((v4) + (0)) = (u32) 0x0u;
    v7 = ((v4) + (0x0u));
    v8 = ((v7) + (0x8u));
    *(u32 *) ((v4) + (4)) = v8;
    *(u32 *) ((v4) + (8)) = v4;
    *(u32 *) ((v4) + (12)) = (u32) 0x0u;
    return (void *) v4;
}
