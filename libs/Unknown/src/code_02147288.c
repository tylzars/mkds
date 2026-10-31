#include "code_02147288.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0214d000.h"

void func_02147914(const Unk02012f58 *a, Unk02012f58 *b, s32 c, s32 d, s32 e) {
    func_021470f8(a, b, c, d, e);
    b->mUnk_24.x = a->mUnk_24.x;
    b->mUnk_24.y = a->mUnk_24.y;
    b->mUnk_24.z = a->mUnk_24.z;
}

void func_021478f0(Unk02012f58 *a, const Vec3 *b, s32 c, s32 d) {
    func_02146f98(a, b, c, d);
    a->mUnk_24.x = 0;
    a->mUnk_24.y = 0;
    a->mUnk_24.z = 0;
}

// non-matching: 6 words differ, all between +0x18 and +0x50 (the words at 0x18 and 0x10 of the first argument are
// loaded into r0 and r3 instead of r3 and r0, and two smull and a mov are one slot apart); the rest matches.
// No change from: other operand orders, cast placements or statement orders of the c products, declaration
// order, the p select as init + if, ?: or switch, s64 rounding constants. The original's second c1 product has the
// 0x18 word as the second smull operand while the 0x14 word is still loaded first.
s32 func_0214755c(const Unk02012f58 *a, Unk02012f58 *b) {
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

    if (a == b) {
        p = &buf;
    } else {
        p = b;
    }
    c1 = (s32) (((s64) a->mUnk_0c.x * a->mUnk_18.z - (s64) a->mUnk_18.x * a->mUnk_0c.z + 0x800) >> 12);
    c0 = (s32) (((s64) a->mUnk_0c.y * a->mUnk_18.z - (s64) a->mUnk_0c.z * a->mUnk_18.y + 0x800) >> 12);
    c2 = (s32) (((s64) a->mUnk_0c.x * a->mUnk_18.y - (s64) a->mUnk_18.x * a->mUnk_0c.y + 0x800) >> 12);
    n = ((s64) a->mUnk_00.x * c0 - (s64) a->mUnk_00.y * c1 + (s64) a->mUnk_00.z * c2 + 0x800) >> 12;
    if (n == 0) {
        return -1;
    }
    func_02147dec(n);
    d0 = ((s64) a->mUnk_00.y * a->mUnk_18.z - (s64) a->mUnk_18.y * a->mUnk_00.z) >> 12;
    d1 = ((s64) a->mUnk_00.y * a->mUnk_0c.z - (s64) a->mUnk_0c.y * a->mUnk_00.z) >> 12;
    d2 = ((s64) a->mUnk_00.x * a->mUnk_18.z - (s64) a->mUnk_18.x * a->mUnk_00.z) >> 12;
    d3 = ((s64) a->mUnk_00.x * a->mUnk_0c.z - (s64) a->mUnk_0c.x * a->mUnk_00.z) >> 12;
    k = func_02147e28();
    p->mUnk_00.x = ((s64) k * c0) >> 12;
    p->mUnk_00.y = -(s32) (((s64) k * d0) >> 12);
    p->mUnk_00.z = ((s64) k * d1) >> 12;
    p->mUnk_0c.x = -(s32) (((s64) k * c1) >> 12);
    p->mUnk_0c.y = ((s64) k * d2) >> 12;
    p->mUnk_0c.z = -(s32) (((s64) k * d3) >> 12);
    p->mUnk_18.x = ((s64) k * c2) >> 12;
    e0 = ((s64) a->mUnk_00.x * a->mUnk_18.y - (s64) a->mUnk_18.x * a->mUnk_00.y) >> 12;
    p->mUnk_18.y = -(s32) (((s64) k * e0) >> 12);
    e1 = ((s64) a->mUnk_00.x * a->mUnk_0c.y - (s64) a->mUnk_0c.x * a->mUnk_00.y) >> 12;
    p->mUnk_18.z = ((s64) k * e1) >> 12;
    p->mUnk_24.x = -(s32) (((s64) p->mUnk_00.x * a->mUnk_24.x + (s64) p->mUnk_0c.x * a->mUnk_24.y +
                            (s64) p->mUnk_18.x * a->mUnk_24.z) >>
                           12);
    p->mUnk_24.y = -(s32) (((s64) p->mUnk_00.y * a->mUnk_24.x + (s64) p->mUnk_0c.y * a->mUnk_24.y +
                            (s64) p->mUnk_18.y * a->mUnk_24.z) >>
                           12);
    p->mUnk_24.z = -(s32) (((s64) p->mUnk_00.z * a->mUnk_24.x + (s64) p->mUnk_0c.z * a->mUnk_24.y +
                            (s64) p->mUnk_18.z * a->mUnk_24.z) >>
                           12);
    if (p == &buf) {
        func_0214d118(&buf, b);
    }
    return 0;
}

void func_0214733c(const Unk02012f58 *a, const Unk02012f58 *b, Unk02012f58 *c) {
    Unk02012f58 buf;
    Unk02012f58 *p;
    s32 x0, x1, x2;
    s32 y0, y1, y2;

    p = c;
    if (p == b) {
        p = &buf;
    }
    x0 = a->mUnk_00.x;
    x1 = a->mUnk_00.y;
    x2 = a->mUnk_00.z;
    p->mUnk_00.x = (s32) (((s64) x0 * b->mUnk_00.x + (s64) x1 * b->mUnk_0c.x + (s64) x2 * b->mUnk_18.x) >> 12);
    p->mUnk_00.y = (s32) (((s64) x0 * b->mUnk_00.y + (s64) x1 * b->mUnk_0c.y + (s64) x2 * b->mUnk_18.y) >> 12);
    y0 = b->mUnk_00.z;
    y1 = b->mUnk_0c.z;
    y2 = b->mUnk_18.z;
    p->mUnk_00.z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_0c.x;
    x1 = a->mUnk_0c.y;
    x2 = a->mUnk_0c.z;
    p->mUnk_0c.z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_0c.y = (s32) (((s64) x0 * b->mUnk_00.y + (s64) x1 * b->mUnk_0c.y + (s64) x2 * b->mUnk_18.y) >> 12);
    y0 = b->mUnk_00.x;
    y1 = b->mUnk_0c.x;
    y2 = b->mUnk_18.x;
    p->mUnk_0c.x = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_18.x;
    x1 = a->mUnk_18.y;
    x2 = a->mUnk_18.z;
    p->mUnk_18.x = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_18.y = (s32) (((s64) x0 * b->mUnk_00.y + (s64) x1 * b->mUnk_0c.y + (s64) x2 * b->mUnk_18.y) >> 12);
    y0 = b->mUnk_00.z;
    y1 = b->mUnk_0c.z;
    y2 = b->mUnk_18.z;
    p->mUnk_18.z = (s32) (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    x0 = a->mUnk_24.x;
    x1 = a->mUnk_24.y;
    x2 = a->mUnk_24.z;
    p->mUnk_24.z = b->mUnk_24.z + (((s64) x0 * y0 + (s64) x1 * y1 + (s64) x2 * y2) >> 12);
    p->mUnk_24.y = b->mUnk_24.y + (((s64) x0 * b->mUnk_00.y + (s64) x1 * b->mUnk_0c.y + (s64) x2 * b->mUnk_18.y) >> 12);
    p->mUnk_24.x = b->mUnk_24.x + (((s64) x0 * b->mUnk_00.x + (s64) x1 * b->mUnk_0c.x + (s64) x2 * b->mUnk_18.x) >> 12);
    if (p == &buf) {
        *c = buf;
    }
}

void func_02147288(const Vec3 *a, const Unk02012f58 *b, Vec3 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = a->x;
    y = a->y;
    z = a->z;
    c->x = (s32) (((s64) x * b->mUnk_00.x + (s64) y * b->mUnk_0c.x + (s64) z * b->mUnk_18.x) >> 12);
    c->x += b->mUnk_24.x;
    c->y = (s32) (((s64) x * b->mUnk_00.y + (s64) y * b->mUnk_0c.y + (s64) z * b->mUnk_18.y) >> 12);
    c->y += b->mUnk_24.y;
    c->z = (s32) (((s64) x * b->mUnk_00.z + (s64) y * b->mUnk_0c.z + (s64) z * b->mUnk_18.z) >> 12);
    c->z += b->mUnk_24.z;
}
