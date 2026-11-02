#include "Main/Unknown/code_020a2e88.h"

void func_020a2ebc(Unk020a2fe4 *a, Vec3 *b) {
    a->mUnk_a0 = 0x1e;
    a->mUnk_a4 = -1;
    a->mUnk_f4 = 1;
    a->mUnk_f8 = NULL;
    if (b == NULL) {
        return;
    }
    a->mUnk_00.mUnk_04.x = b->x;
    a->mUnk_00.mUnk_04.y = b->y + 0xf666;
    a->mUnk_00.mUnk_04.z = b->z;
}

void func_020a2e88(Unk020a2fe4 *a, Vec3 *b, Vec3 *c) {
    a->mUnk_b0 = *b;
    a->mUnk_bc = *c;
}
