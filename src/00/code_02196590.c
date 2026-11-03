#include "00/code_02196590.h"
#include "00/code_02196914.h"

void func_ov000_02196590(void *arg0, void *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value2 = 0x100u;
    value3 = (u32) &func_ov000_02196914;
    func_ov000_02196914((u8 *) value0, (void *) value1, (s32) value2);
    return;
}
