#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e516c.h"

void SetShadowPositionRaised(ShadowMatrix *shadow, Vec3 *position) {
    shadow->mUnk_000[9] = position->x >> 4;
    shadow->mUnk_000[10] = (position->y + 0x1999) >> 4;
    shadow->mUnk_000[11] = position->z >> 4;
}
