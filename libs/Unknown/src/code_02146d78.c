#include "code_02146d78.h"

void func_021470f8(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e) {
    b->mUnk_00.x = (s32) (((s64) c * a->mUnk_00.x) >> 12);
    b->mUnk_00.y = (s32) (((s64) c * a->mUnk_00.y) >> 12);
    b->mUnk_00.z = (s32) (((s64) c * a->mUnk_00.z) >> 12);
    b->mUnk_0c.x = (s32) (((s64) d * a->mUnk_0c.x) >> 12);
    b->mUnk_0c.y = (s32) (((s64) d * a->mUnk_0c.y) >> 12);
    b->mUnk_0c.z = (s32) (((s64) d * a->mUnk_0c.z) >> 12);
    b->mUnk_18.x = (s32) (((s64) e * a->mUnk_18.x) >> 12);
    b->mUnk_18.y = (s32) (((s64) e * a->mUnk_18.y) >> 12);
    b->mUnk_18.z = (s32) (((s64) e * a->mUnk_18.z) >> 12);
}

// non-matching: 0x15c against 0x160; the original stores the x * x low word to the stack, computes t into its
// register r1 and reloads it twice; ours keeps t in r8 and reloads once; otherwise the same instructions in other
// registers and order
void func_02146f98(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;
    s64 xx;
    s64 yy;
    s64 zz;
    s32 xy;
    s32 xz;
    s32 yz;
    s32 sx;
    s32 sy;
    s32 sz;

    x = b->x;
    y = b->y;
    z = b->z;
    t = 0x1000 - d;
    xx = (s64) t * ((s64) x * x);
    xy = (s32) (((s64) t * x * y) >> 24);
    sx = (s32) (((s64) c * x) >> 12);
    a->mUnk_00.x = (s32) (xx >> 24) + d;
    yy = (s64) t * ((s64) y * y);
    a->mUnk_0c.y = (s32) (yy >> 24) + d;
    zz = (s64) t * ((s64) z * z);
    a->mUnk_18.z = (s32) (zz >> 24) + d;
    sy = (s32) (((s64) c * y) >> 12);
    sz = (s32) (((s64) c * z) >> 12);
    a->mUnk_00.y = xy + sz;
    a->mUnk_0c.x = xy - sz;
    xz = (s32) (((s64) t * x * z) >> 24);
    a->mUnk_00.z = xz - sy;
    a->mUnk_18.x = xz + sy;
    yz = (s32) (((s64) t * y * z) >> 24);
    a->mUnk_0c.z = yz + sx;
    a->mUnk_18.y = yz - sx;
}

void func_02146dfc(const s32 *a, const s32 *b, s32 *c) {
    Unk02146dfc buf;
    s32 *p;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 y0;
    s32 y1;
    s32 y2;

    p = c;
    if (p == b) {
        p = buf.mUnk_00;
    }
    x0 = a[0];
    x1 = a[1];
    x2 = a[2];
    p[0] = (s32) (((s64) x0 * b[0] + (s64) x1 * b[3] + (s64) x2 * b[6]) >> 12);
    p[1] = (s32) (((s64) x0 * b[1] + (s64) x1 * b[4] + (s64) x2 * b[7]) >> 12);
    y0 = b[2];
    y1 = b[5];
    y2 = b[8];
    p[2] = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a[3];
    x1 = a[4];
    x2 = a[5];
    p[5] = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p[4] = (s32) (((s64) x0 * b[1] + (s64) x1 * b[4] + (s64) x2 * b[7]) >> 12);
    y0 = b[0];
    y1 = b[3];
    y2 = b[6];
    p[3] = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a[6];
    x1 = a[7];
    x2 = a[8];
    p[6] = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p[7] = (s32) (((s64) x0 * b[1] + (s64) x1 * b[4] + (s64) x2 * b[7]) >> 12);
    p[8] = (s32) (((s64) x0 * b[2] + (s64) x1 * b[5] + (s64) x2 * b[8]) >> 12);
    if (p == buf.mUnk_00) {
        *(Unk02146dfc *) c = buf;
    }
}

void func_02146d78(const Vec3 *a, const s32 *b, Vec3 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = a->x;
    y = a->y;
    z = a->z;
    c->x = (s32) (((s64) x * b[0] + (s64) y * b[3] + (s64) z * b[6]) >> 12);
    c->y = (s32) (((s64) x * b[1] + (s64) y * b[4] + (s64) z * b[7]) >> 12);
    c->z = (s32) (((s64) x * b[2] + (s64) y * b[5] + (s64) z * b[8]) >> 12);
}
