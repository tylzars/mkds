#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020d94dc.h"

void func_020d939c(Unk020e0144_00_0 *a, s32 b, s32 c, Vec3 *d, Vec3 *e) {
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;
    func_020d970c(b, &f, &g, &h, &i, &j, &k, &l, &m);
    func_020d95c0(a->mUnk_00, d, f, g, h, i);
    func_020d95c0(a->mUnk_00, e, j, k, l, m);
    e->x = ((s64) e->x * c) >> 24;
    e->y = ((s64) e->y * c) >> 24;
    e->z = ((s64) e->z * c) >> 24;
}
