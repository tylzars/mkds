#include "code_02147288.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

void Matrix4x3ScaleRowsCopyRow3(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e) {
    Matrix4x3ScaleFirstThreeRows(a, b, c, d, e);
    b->mUnk_00[3].x = a->mUnk_00[3].x;
    b->mUnk_00[3].y = a->mUnk_00[3].y;
    b->mUnk_00[3].z = a->mUnk_00[3].z;
}

void Matrix4x3FromVec3AndPair(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d) {
    Matrix4x3FirstThreeRowsFromVec3AndPair(a, b, c, d);
    a->mUnk_00[3].x = 0;
    a->mUnk_00[3].y = 0;
    a->mUnk_00[3].z = 0;
}

s32 Matrix4x3Invert(const Unk02012f58 *a, Unk02012f58 *b) {
    Unk02012f58 buf;
    Unk02012f58 *p;
    s64 c0;
    s64 c1;
    s64 c2;
    s32 n;
    s32 k;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    s32 e0;
    s32 e1;
    s32 u;
    s32 t;
    s32 w;

    u = a->mUnk_00[1].z;
    t = a->mUnk_00[2].y;
    if (a == b) {
        p = &buf;
    } else {
        p = b;
    }
    w = a->mUnk_00[1].y;
    c1 = (s32) (((s64) a->mUnk_00[1].x * a->mUnk_00[2].z - (s64) u * a->mUnk_00[2].x + 0x800) >> 12);
    c0 = (s32) (((s64) w * a->mUnk_00[2].z - (s64) u * t + 0x800) >> 12);
    c2 = (s32) (((s64) a->mUnk_00[1].x * a->mUnk_00[2].y - w * (s64) a->mUnk_00[2].x + 0x800) >> 12);
    n = ((s64) a->mUnk_00[0].x * c0 - (s64) a->mUnk_00[0].y * c1 + (s64) a->mUnk_00[0].z * c2 + 0x800) >> 12;
    if (n == 0) {
        return -1;
    }
    ReciprocalFixed12Start(n);
    d0 = ((s64) a->mUnk_00[0].y * a->mUnk_00[2].z - (s64) a->mUnk_00[2].y * a->mUnk_00[0].z) >> 12;
    d1 = ((s64) a->mUnk_00[0].y * a->mUnk_00[1].z - (s64) a->mUnk_00[1].y * a->mUnk_00[0].z) >> 12;
    d2 = ((s64) a->mUnk_00[0].x * a->mUnk_00[2].z - (s64) a->mUnk_00[2].x * a->mUnk_00[0].z) >> 12;
    d3 = ((s64) a->mUnk_00[0].x * a->mUnk_00[1].z - (s64) a->mUnk_00[1].x * a->mUnk_00[0].z) >> 12;
    k = DivFixed12Result();
    p->mUnk_00[0].x = ((s64) k * c0) >> 12;
    p->mUnk_00[0].y = -(s32) (((s64) k * d0) >> 12);
    p->mUnk_00[0].z = ((s64) k * d1) >> 12;
    p->mUnk_00[1].x = -(s32) (((s64) k * c1) >> 12);
    p->mUnk_00[1].y = ((s64) k * d2) >> 12;
    p->mUnk_00[1].z = -(s32) (((s64) k * d3) >> 12);
    p->mUnk_00[2].x = ((s64) k * c2) >> 12;
    e0 = ((s64) a->mUnk_00[0].x * a->mUnk_00[2].y - (s64) a->mUnk_00[2].x * a->mUnk_00[0].y) >> 12;
    p->mUnk_00[2].y = -(s32) (((s64) k * e0) >> 12);
    e1 = ((s64) a->mUnk_00[0].x * a->mUnk_00[1].y - (s64) a->mUnk_00[1].x * a->mUnk_00[0].y) >> 12;
    p->mUnk_00[2].z = ((s64) k * e1) >> 12;
    p->mUnk_00[3].x = -(s32) (((s64) p->mUnk_00[0].x * a->mUnk_00[3].x + (s64) p->mUnk_00[1].x * a->mUnk_00[3].y +
                               (s64) p->mUnk_00[2].x * a->mUnk_00[3].z) >>
                              12);
    p->mUnk_00[3].y = -(s32) (((s64) p->mUnk_00[0].y * a->mUnk_00[3].x + (s64) p->mUnk_00[1].y * a->mUnk_00[3].y +
                               (s64) p->mUnk_00[2].y * a->mUnk_00[3].z) >>
                              12);
    p->mUnk_00[3].z = -(s32) (((s64) p->mUnk_00[0].z * a->mUnk_00[3].x + (s64) p->mUnk_00[1].z * a->mUnk_00[3].y +
                               (s64) p->mUnk_00[2].z * a->mUnk_00[3].z) >>
                              12);
    if (p == &buf) {
        MI_Copy48B(&buf, b);
    }
    return 0;
}

void Matrix4x3Multiply(const Unk02012f58 *a, const Unk02012f58 *b, Unk02012f58 *c) {
    Unk02012f58 buf;
    Unk02012f58 *p;
    s32 x0, x1, x2;
    s32 y0, y1, y2;

    p = c;
    if (p == b) {
        p = &buf;
    }
    x0 = a->mUnk_00[0].x;
    x1 = a->mUnk_00[0].y;
    x2 = a->mUnk_00[0].z;
    p->mUnk_00[0].x =
        (s32) (((s64) x0 * b->mUnk_00[0].x + (s64) x1 * b->mUnk_00[1].x + (s64) x2 * b->mUnk_00[2].x) >> 12);
    p->mUnk_00[0].y =
        (s32) (((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12);
    y0 = b->mUnk_00[0].z;
    y1 = b->mUnk_00[1].z;
    y2 = b->mUnk_00[2].z;
    p->mUnk_00[0].z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_00[1].x;
    x1 = a->mUnk_00[1].y;
    x2 = a->mUnk_00[1].z;
    p->mUnk_00[1].z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_00[1].y =
        (s32) (((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12);
    y0 = b->mUnk_00[0].x;
    y1 = b->mUnk_00[1].x;
    y2 = b->mUnk_00[2].x;
    p->mUnk_00[1].x = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_00[2].x;
    x1 = a->mUnk_00[2].y;
    x2 = a->mUnk_00[2].z;
    p->mUnk_00[2].x = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_00[2].y =
        (s32) (((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12);
    y0 = b->mUnk_00[0].z;
    y1 = b->mUnk_00[1].z;
    y2 = b->mUnk_00[2].z;
    p->mUnk_00[2].z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_00[3].x;
    x1 = a->mUnk_00[3].y;
    x2 = a->mUnk_00[3].z;
    p->mUnk_00[3].z = b->mUnk_00[3].z + (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_00[3].y = b->mUnk_00[3].y +
                      (((s64) x0 * b->mUnk_00[0].y + (s64) x1 * b->mUnk_00[1].y + (s64) x2 * b->mUnk_00[2].y) >> 12);
    p->mUnk_00[3].x = b->mUnk_00[3].x +
                      (((s64) x0 * b->mUnk_00[0].x + (s64) x1 * b->mUnk_00[1].x + (s64) x2 * b->mUnk_00[2].x) >> 12);
    if (p == &buf) {
        *c = buf;
    }
}

void Vec3MultiplyMatrix4x3(const Vec3 *a, const Unk02012f58 *b, Vec3 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = a->x;
    y = a->y;
    z = a->z;
    c->x = (s32) (((s64) x * b->mUnk_00[0].x + (s64) y * b->mUnk_00[1].x + (s64) z * b->mUnk_00[2].x) >> 12);
    c->x += b->mUnk_00[3].x;
    c->y = (s32) (((s64) x * b->mUnk_00[0].y + (s64) y * b->mUnk_00[1].y + (s64) z * b->mUnk_00[2].y) >> 12);
    c->y += b->mUnk_00[3].y;
    c->z = (s32) (((s64) x * b->mUnk_00[0].z + (s64) y * b->mUnk_00[1].z + (s64) z * b->mUnk_00[2].z) >> 12);
    c->z += b->mUnk_00[3].z;
}
