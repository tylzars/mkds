#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020dd8b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"

#pragma thumb on

const Vec3 data_021583c8 = {0x100, 0x400, 0x100};

void func_020dd950(Unk020dd950 *d, Vec3 *a, Vec3 *b, s32 c, s32 n, s32 e, Vec3 *f) {
    s32 k;
    void *h;

    d->mUnk_00 = c;
    d->mUnk_20 = n;
    h = GetHeap(func_020364e8());
    d->mUnk_44 = HeapAlloc(h, n * 12);
    h = GetHeap(func_020364e8());
    d->mUnk_48 = HeapAlloc(h, n * 12);
    d->mUnk_34 = *f;
    d->mUnk_40 = (s32) (((s64) e * f->y) >> 12);
    k = n - 1;
    d->mUnk_24 = 0x1000 / k;
    d->mUnk_28 = (s32) (((s64) c * 0x119a) >> 12) / k;
    d->mUnk_2c = (s64) d->mUnk_28 * d->mUnk_28;
    func_020dd8b0(d, a, b);
    d->mUnk_0c = a->y + d->mUnk_40;
    d->mUnk_04 = 0x599;
    d->mUnk_10 = 0x51;
    d->mUnk_14 = data_021583c8;
    d->mUnk_08 = 1;
}

void func_020dd8b0(Unk020dd950 *d, Vec3 *a, Vec3 *b) {
    Vec3 v;
    Vec3 *q;
    s32 i;
    s32 k;

    Vec3Sub(b, a, &v);
    k = d->mUnk_24;
    v.x = (s32) (((s64) v.x * k) >> 12);
    v.y = (s32) (((s64) v.y * k) >> 12);
    v.z = (s32) (((s64) v.z * k) >> 12);
    *d->mUnk_44 = *a;
    q = d->mUnk_48;
    q->x = 0;
    q->y = 0;
    q->z = 0;
    for (i = 1; i < d->mUnk_20; i++) {
        Vec3Add(&d->mUnk_44[i - 1], &v, &d->mUnk_44[i]);
        q = d->mUnk_48;
        q[i].x = 0;
        q[i].y = 0;
        q[i].z = 0;
    }
}

#pragma thumb off
