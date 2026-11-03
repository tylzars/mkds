#include "code_02022098.h"
#include "code_020220b0.h"

void func_020220b0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value4;
    value4 = value0;
    value0 = (value4) + (0x1cu);
    func_02022098(value0);
    value1 = 0u;
    *(u32 *) ((value4) + (0)) = value1;
    *(u32 *) ((value4) + (4)) = value1;
    value0 = 1u;
    *(u32 *) ((value4) + (8)) = value0;
    *(u32 *) ((value4) + (12)) = value1;
    value0 = 0x1000u;
    *(u32 *) ((value4) + (16)) = value0;
    *(u32 *) ((value4) + (20)) = value1;
    *(u32 *) ((value4) + (24)) = value1;
}
