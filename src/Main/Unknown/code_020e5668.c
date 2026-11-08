#include "Main/Unknown/code_020e5668.h"

void SetShadowPositionXZ(Unk020e516c *shadow, Vec3 *position) {
    u32 shadowAddress = (u32) shadow;
    u32 value1 = (u32) position;
    u32 shadowX;
    shadowX = position->x;
    shadowX = ((s32) shadowX >> 4);
    *(u32 *) ((shadowAddress) + (36)) = shadowX;
    value1 = position->z;
    value1 = ((s32) value1 >> 4);
    *(u32 *) ((shadowAddress) + (44)) = value1;
}
