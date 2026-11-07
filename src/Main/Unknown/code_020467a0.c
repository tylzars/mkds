#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020467a0(void) {
    u32 value0;
    u32 value1;
    ResetCupRecords();
    value0 = (u32) &gRaceSetup;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x200u);
    *(u16 *) ((value0) + (72)) = value1;
}
