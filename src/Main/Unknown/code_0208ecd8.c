#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_0208ecd8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"

void func_0208ecd8(Unk0208ec64_08 *a, Unk0208ec64 *b) {
    Unk0206bcb0 *o;
    Vec3 v;
    Vec3 x;
    Vec3 y;
    Vec3 z;
    Vec3 *p;
    s32 k;

    o = func_0207a974(b->mUnk_20);
    v = o->mUnk_80;
    p = &o->mUnk_120;
    k = b->mUnk_24;
    x.x = (s32) (((s64) p->x * k) >> 12);
    x.y = (s32) (((s64) p->y * k) >> 12);
    x.z = (s32) (((s64) p->z * k) >> 12);
    p = &o->mUnk_12c;
    k = b->mUnk_28;
    y.x = (s32) (((s64) p->x * k) >> 12);
    y.y = (s32) (((s64) p->y * k) >> 12);
    y.z = (s32) (((s64) p->z * k) >> 12);
    p = &o->mUnk_138;
    k = b->mUnk_2c;
    z.x = (s32) (((s64) p->x * k) >> 12);
    z.y = (s32) (((s64) p->y * k) >> 12);
    z.z = (s32) (((s64) p->z * k) >> 12);
    Vec3Add(&v, &x, &v);
    Vec3Add(&v, &y, &v);
    Vec3Add(&v, &z, &v);
    a->mUnk_08 = b->mUnk_1c;
    a->mUnk_0c = 0;
    a->mUnk_10.x = v.x >> 4;
    a->mUnk_10.y = v.y >> 4;
    a->mUnk_10.z = v.z >> 4;
}
