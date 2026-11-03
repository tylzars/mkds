#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b458.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0204b430(u32 a, u32 b, u32 *c, u32 d, void (*e)(u32, u32), s32 f) {
    data_021759d4->mUnk_18 = b;
    func_0204b458(a, c, d, (void (*)(u32 *, u32)) e, 1, f);
}

void func_0204b418(u32 p0, void *p1, u32 p2, u32 p3) {
    u32 v5 = func_0204b458(p0, (u32 *) p1, p2, (void (*)(u32 *, u32))(p3), (s32) 0x0u, (s32) 0x0u);
}

#pragma thumb off
