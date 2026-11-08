#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"

#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on

void CreateRaceSetupCopy(void *heap) {
    u32 setupCopyAddress;
    setupCopyAddress = ((u32) HeapAlloc(heap, (0x00000110u)));
    *(u32 *) &gRaceSetupCopy = setupCopyAddress;
    ResetRaceSetupCopy();
}

#pragma thumb off

void func_02029a4c(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void func_02029a38(void *destination, u32 size) {
    func_02029a4c(destination, 0, size);
}

u32 func_02029a24(void) {
    return (data_021759d0->mUnk_20);
}
