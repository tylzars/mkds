#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_020f2dac.h"

void StartItemObjectBouncing(BouncingItemObject *object, u32 bouncesRemaining) {
    object->mBouncesRemaining = bouncesRemaining;
    object->mItemObject.mUnk_124 = BounceItemObject;
}
