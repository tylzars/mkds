#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "code_02147cd8.h"

void func_020d8b18(Unk020e0144 *a, Vec3 *b, Vec3 *c) {
    func_020d9270(&a->mUnk_00->mUnk_00[a->mUnk_0c], a->mUnk_14, a->mUnk_10, b, c);
    if (a->mUnk_18 == 0) {
        c->x = -c->x;
        c->z = -c->z;
    }
}

void func_020d8a5c(Unk020e0144 *a, Vec3 *b) {
    Unk020e0144_00_0 *p;
    s32 t;
    s32 u;
    p = &a->mUnk_00->mUnk_00[a->mUnk_0c];
    t = a->mUnk_14;
    u = 0x1000000 - t;
    b->x = (s32) (((s64) p->mUnk_00[0].x * u) >> 24);
    b->y = (s32) (((s64) p->mUnk_00[0].y * u) >> 24);
    b->z = (s32) (((s64) p->mUnk_00[0].z * u) >> 24);
    b->x = b->x + (s32) (((s64) p->mUnk_00[3].x * t) >> 24);
    b->y = b->y + (s32) (((s64) p->mUnk_00[3].y * t) >> 24);
    b->z = b->z + (s32) (((s64) p->mUnk_00[3].z * t) >> 24);
}

void func_020d8918(Unk020e0144 *a, Vec3 *b, Vec3 *c) {
    Unk020e0144_00_0 *p;
    s32 t;
    s32 u;
    s32 k;
    p = &a->mUnk_00->mUnk_00[a->mUnk_0c];
    t = a->mUnk_14;
    u = 0x1000000 - t;
    b->x = (s32) (((s64) p->mUnk_00[0].x * u) >> 24);
    b->y = (s32) (((s64) p->mUnk_00[0].y * u) >> 24);
    b->z = (s32) (((s64) p->mUnk_00[0].z * u) >> 24);
    b->x = b->x + (s32) (((s64) p->mUnk_00[3].x * t) >> 24);
    b->y = b->y + (s32) (((s64) p->mUnk_00[3].y * t) >> 24);
    b->z = b->z + (s32) (((s64) p->mUnk_00[3].z * t) >> 24);
    func_021484d0(&p->mUnk_00[3], &p->mUnk_00[0], c);
    k = a->mUnk_10;
    c->x = (s32) (((s64) c->x * k) >> 24);
    c->y = (s32) (((s64) c->y * k) >> 24);
    c->z = (s32) (((s64) c->z * k) >> 24);
    if (a->mUnk_18 == 0) {
        c->x = -c->x;
        c->y = -c->y;
        c->z = -c->z;
    }
}
