#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020d12b0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = 4u;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    value1 = (u32) &data_0217b4a8;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}

u32 func_020d129c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b4a8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
