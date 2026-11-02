#include "Main/Unknown/code_020ca69c.h"

#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020ca6b8.h"

#pragma thumb on
void func_020ca6b8(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gEmblemChoises;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_020ca6a8(void) {
    gEmblemChoises->mUnk_08 = 1;
}
#pragma thumb off

#pragma thumb on

u32 func_020ca69c(void) {
    return ((u32) gEmblemChoises->mUnk_1c);
}

#pragma thumb off
