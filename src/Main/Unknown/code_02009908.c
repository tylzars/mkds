#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/unk_0216f000.h"

#include "Main/Unknown/code_02008934.h"

#pragma thumb on

void func_0200991c(void *p0) {
    *(u32 *) ((u8 *) (u32) (((u32) (&data_0216fc40))) + 0) = (u32) p0;
}

#pragma thumb off

#pragma thumb on
u32 func_02009908(UnkFunc *arg0, UnkFunc *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_0216fc38;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &data_0216fc34;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off
