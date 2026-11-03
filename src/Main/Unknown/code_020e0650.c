#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e0650.h"

void func_020e0650(u32 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = value0;
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = 0x1cu;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((value4) + (0)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (0));
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
}
