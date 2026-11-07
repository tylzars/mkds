#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02036820.h"

u32 CreateCourseGhostRecords(u32 heap) {
    u32 value0 = heap;
    u32 size;
    u32 value12;
    value12 = (u32) &HeapAlloc;
    size = 0x600u;
    value0 = (u32) HeapAlloc((void *) value0, size);
    return value0;
}
