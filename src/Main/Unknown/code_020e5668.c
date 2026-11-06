#include "Main/Unknown/code_020e5668.h"

void func_020e5668(Unk020e516c *arg0, Vec3 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = arg1->x;
    value2 = ((s32) value2 >> 4);
    *(u32 *) ((value0) + (36)) = value2;
    value1 = arg1->z;
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((value0) + (44)) = value1;
}
