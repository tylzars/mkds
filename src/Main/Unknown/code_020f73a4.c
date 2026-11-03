#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020ee684.h"

void func_020f73d4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value2 = ((u32) &data_027e00cc);
    value1 = value0;
    value3 = (u32) * (const u32 *) ((value2) + (0));
    value2 = (u32) * (const u32 *) ((value1) + (68));
    value0 = 0x44u;
    value0 = (value2) * (value0) + (value3);
    value12 = (u32) &func_020f0f70;
    func_020f0f70((Unk027e00cc *) value0, (Unk020f41c4_A *) value1);
}

u32 func_020f73a4(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = 0xcu;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    value1 = (u32) &data_0217bc4c;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
