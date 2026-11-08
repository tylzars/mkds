#include "Main/Unknown/code_020e6f9c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on
u32 InitMapObjectUpdateList(MapObjectList *list) {
    u32 value0 = (u32) list;
    u32 value1;
    u32 listPointer;
    listPointer = (value0) + (0u);
    value0 = (u32) GetCurrentHeapCall();
    value0 = (u32) GetHeap((void *) value0);
    value1 = *(const u16 *) ((listPointer) + 4u);
    value1 = (value1 << 2);
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((listPointer) + 0u) = value0;
    value1 = 0u;
    *(u16 *) ((listPointer) + 4u) = value1;
    value0 = 3u;
    *(u32 *) ((listPointer) + 24u) = value0;
    *(u32 *) ((listPointer) + 28u) = value1;
    *(u32 *) ((listPointer) + 32u) = value0;
    return value0;
}
#pragma thumb off
