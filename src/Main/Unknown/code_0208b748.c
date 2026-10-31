#include "Main/Unknown/code_0208b748.h"

void *func_0208b7bc(u32 a, const Vec3 *b) {
    s32 e;
    Vec3 v;
    Unk0201ca6c *q;
    Unk020184e4 *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = func_02018600(p, e, &v);
    if (q != 0) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    return q;
}

void func_0208b748(u32 a, const Vec3 *b, void *c, void (*d)()) {
    s32 e;
    Vec3 v;
    Unk020184e4 *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    func_02018578(p, e, &v, (s32) c, (void (*)(Unk0201ca6c *, s32)) d);
}
