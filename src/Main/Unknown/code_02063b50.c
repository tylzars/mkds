#include "Main/Unknown/code_02063b50.h"
#include "Main/Unknown/code_0206bcb0.h"

// Copies row 0 of the kart's matrix at 0x120 to the given vector.
u32 GetKartMatrixRow0(Kart *kart, Vec3 *out) {
    Vec3 *row;
    s32 value0;
    s32 rowX = kart->mUnk_120.x;
    row = &kart->mUnk_120;
    out->x = rowX;
    value0 = row->y;
    out->y = value0;
    value0 = row->z;
    out->z = value0;
    return value0;
}
