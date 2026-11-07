#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020f36d8.h"

void func_020f9320(ItemObject *item, u32 clearBits) {
    item->mUnk_fc = (((item->mUnk_fc)) & ((~(clearBits))));
}

void BounceItemVelocityOffSurface(Vec3 *velocity, Vec3 *normal) {
    BounceVelocityOffSurface(velocity, normal, 0xb33, 0x733, 0xacd, velocity);
}
