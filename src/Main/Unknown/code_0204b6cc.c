#include "Main/Unknown/code_0204b6cc.h"

#pragma thumb on

void func_0204b6f8(u32 p0, void *p1, u32 p2, void (*p3)(u32, u32), u32 p4) {
    u32 v4 = p4;
    u32 v7 =
        ((u32) func_0204b714((u32) p0, (u32 *) p1, (u32) p2, (void (*)(u32 *, u32))(p3), (s32) 0x0u, v4, (s32) 0x0u));
}

void func_0204b6cc(u32 param_1, u32 param_2, u32 *param_3, u32 param_4, void (*param_5)(u32, u32), u32 param_6,
                   s32 param_7) {
    data_021759d4->mUnk_18 = param_2;
    func_0204b714(param_1, param_3, param_4, (void (*)(u32 *, u32)) param_5, 1, param_6, param_7);
}

#pragma thumb off
