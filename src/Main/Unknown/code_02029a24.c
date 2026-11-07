#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"

#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on

void CreateRaceSetupCopy(void *a) {
    u32 v1;
    v1 = ((u32) HeapAlloc(a, (0x00000110u)));
    *(u32 *) &gRaceSetupCopy = v1;
    ResetRaceSetupCopy();
}

#pragma thumb off

void func_02029a4c(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    MIi_CpuClearFast(v, a, c);
}

void func_02029a38(void *a, u32 b) {
    func_02029a4c(a, 0, b);
}

u32 func_02029a24(void) {
    return (data_021759d0->mUnk_20);
}
