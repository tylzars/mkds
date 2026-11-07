#include "code_02146cb0.h"

#pragma thumb on
// Sets the four words at dst to the 2x2 rotation matrix (cosVal, sinVal, -sinVal, cosVal).
void MTX_Rot22_(s32 *dst, s32 sinVal, s32 cosVal) {
    dst[0] = cosVal;
    dst[1] = sinVal;
    dst[2] = -sinVal;
    dst[3] = cosVal;
}
#pragma thumb off
