#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020e005c.h"

void func_020d8bf8(Unk020e0144 *a, Vec3 *b, Vec3 *c) {
    func_020d939c(&a->mUnk_00->mUnk_00[a->mUnk_0c], a->mUnk_14, a->mUnk_10, b, c);
    if (a->mUnk_18 == 0) {
        c->x = -c->x;
        c->y = -c->y;
        c->z = -c->z;
    }
}

void func_020d8bc0(Unk020e0144 *a, Vec3 *b) {
    func_020d91dc(&a->mUnk_00->mUnk_00[a->mUnk_0c], a->mUnk_14, b);
}
