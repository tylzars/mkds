#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/unk_02154000.h"

#pragma thumb on

u32 func_0202e43c(s32 a) {
    return gCupCourseIdTable[a / 4][a % 4];
}

#pragma thumb off
