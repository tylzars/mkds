#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_0204b714.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0204b6f8(u32 p0, void *p1, u32 p2, void (*p3)(u32, u32), u32 p4) {
    u32 v4 = p4;
    u32 v7 = func_0204b714(p0, p1, p2, (void (*)(u32 *, u32))(p3), 0x0u, v4, 0x0u);
}

void func_0204b6cc(u32 a, u32 b, u32 *c, u32 d, void (*e)(u32, u32), u32 f, s32 g) {
    data_021759d4->mUnk_18 = b;
    func_0204b714(a, c, d, (void (*)(u32 *, u32)) e, 1, f, g);
}

#pragma thumb off
