#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_02124bf0.h"

#pragma thumb on
u32 IncrementOamMatrixCount(OamList *oamList) {
    u16 *counterPointer = &oamList->mMatrixCount;
    *counterPointer = *counterPointer + 1;
    return (u32) counterPointer;
}
#pragma thumb off
