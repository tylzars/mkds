#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020e005c.h"

void func_020d8bf8(Unk020e0144 *follower, Vec3 *position, Vec3 *step) {
    func_020d939c(&follower->mUnk_00->mUnk_00[follower->mUnk_0c], follower->mUnk_14, follower->mUnk_10, position, step);
    if (follower->mUnk_18 == 0) {
        step->x = -step->x;
        step->y = -step->y;
        step->z = -step->z;
    }
}

void func_020d8bc0(Unk020e0144 *follower, Vec3 *position) {
    func_020d91dc(&follower->mUnk_00->mUnk_00[follower->mUnk_0c], follower->mUnk_14, position);
}
