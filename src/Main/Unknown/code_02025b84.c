#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
u32 func_02025b84(u32 arg0, void *arg1) {
    u32 value0 = arg0;
    u32 value1 = (u32) arg1;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value4 = (value1) + (0u);
    value0 = (u32) func_020b4018(value0);
    *(u32 *) ((value4) + 0u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) func_020b400c(value0);
    *(u32 *) ((value4) + 8u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) func_020b4030(value0);
    *(u32 *) ((value4) + 4u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) func_020b4000(value0);
    *(u32 *) ((value4) + 12u) = value0;
    return value0;
}
#pragma thumb off
