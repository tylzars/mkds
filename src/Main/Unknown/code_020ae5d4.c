#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_02124bf0.h"

#pragma thumb on
u32 func_020ae5d4(OamList *oamList) {
    u16 *counterPointer = &oamList->mUnk_402;
    *counterPointer = *counterPointer + 1;
    return (u32) counterPointer;
}
#pragma thumb off
