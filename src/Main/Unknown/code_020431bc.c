#include "Main/Unknown/code_020431bc.h"
#include "Main/Unknown/code_02036820.h"

#pragma thumb on
CourseMap *AllocCourseMap(void *heap) {
    return HeapAlloc(heap, 0x110);
}
#pragma thumb off
