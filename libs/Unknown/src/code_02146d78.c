#include "code_02146d78.h"

void Matrix4x3ScaleFirstThreeRows(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e) {
    b->mUnk_00[0].x = (s32) (((s64) c * a->mUnk_00[0].x) >> 12);
    b->mUnk_00[0].y = (s32) (((s64) c * a->mUnk_00[0].y) >> 12);
    b->mUnk_00[0].z = (s32) (((s64) c * a->mUnk_00[0].z) >> 12);
    b->mUnk_00[1].x = (s32) (((s64) d * a->mUnk_00[1].x) >> 12);
    b->mUnk_00[1].y = (s32) (((s64) d * a->mUnk_00[1].y) >> 12);
    b->mUnk_00[1].z = (s32) (((s64) d * a->mUnk_00[1].z) >> 12);
    b->mUnk_00[2].x = (s32) (((s64) e * a->mUnk_00[2].x) >> 12);
    b->mUnk_00[2].y = (s32) (((s64) e * a->mUnk_00[2].y) >> 12);
    b->mUnk_00[2].z = (s32) (((s64) e * a->mUnk_00[2].z) >> 12);
}

void Matrix4x3FirstThreeRowsFromVec3AndPair(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;
    s64 xx;
    s64 yy;
    s64 zz;
    s32 xy;
    u32 xz;
    s32 yz;
    s32 sx;
    s32 sy;
    s32 sz;
    u32 e;
    s32 f;
    s32 g;

    e = b->x;
    t = (s64) (0x1000 - d);
    x = e;
    g = b->y;
    f = (s64) b->z;
    y = g;
    z = f;
    xx = (s64) t * ((s64) x * x);
    a->mUnk_00[0].x = (s32) (xx >> 24) + d;
    xy = (s32) (((s64) t * x * y) >> 24);
    sx = (s32) (((s64) c * x) >> 12);
    yy = t * ((s64) y * y);
    a->mUnk_00[1].y = (s32) (yy >> 24) + d;
    zz = (s64) t * ((s64) z * z);
    a->mUnk_00[2].z = (s32) (zz >> 24) + d;
    sy = (s32) (((s64) c * y) >> 12);
    sz = (s32) (((s64) c * z) >> 12);
    a->mUnk_00[0].y = xy + sz;
    a->mUnk_00[1].x = xy - sz;
    xz = (s32) (((s64) t * x * z) >> 24);
    a->mUnk_00[0].z = xz - sy;
    a->mUnk_00[2].x = xz + sy;
    yz = (s32) (((s64) t * y * z) >> 24);
    a->mUnk_00[1].z = yz + sx;
    a->mUnk_00[2].y = yz - sx;
}

void Matrix3x3Multiply(const s32 *a, const s32 *b, s32 *c) {
    Matrix3x3 buf;
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
        *(Matrix3x3 *) c = buf;
    }
}

void Vec3MultiplyMatrix3x3(const Vec3 *a, const s32 *b, Vec3 *c) {
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
