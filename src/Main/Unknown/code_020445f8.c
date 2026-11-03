#include "Main/Unknown/code_020445f8.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020445f8(void) {
    u32 value0;
    u32 value1;
    u32 value12;
    value0 = (u32) &data_021759c0;
    value12 = (u32) &func_0205950c;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (488));
    value1 = (u32) * (const u32 *) ((value1) + (496));
    func_0205950c((void *) value0, (void *) value1);
}
