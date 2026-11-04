#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020431bc.h"

#pragma thumb on
CourseMap *func_020431bc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value3;
    value1 = 0x110u;
    value3 = (u32) &HeapAlloc;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    return (CourseMap *) value0;
}
#pragma thumb off
