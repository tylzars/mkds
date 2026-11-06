#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on
u32 InitMapObjectUpdateList(MapObjectList *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = *(const u16 *) ((value4) + 4u);
    value1 = (value1 << 2);
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((value4) + 0u) = value0;
    value1 = 0u;
    *(u16 *) ((value4) + 4u) = value1;
    value0 = 3u;
    *(u32 *) ((value4) + 24u) = value0;
    *(u32 *) ((value4) + 28u) = value1;
    *(u32 *) ((value4) + 32u) = value0;
    return value0;
}
#pragma thumb off
