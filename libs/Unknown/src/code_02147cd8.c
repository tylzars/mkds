#include "code_02147cd8.h"
#include "registers.h"

void func_02148504(const Vec3 *a, const Vec3 *b, Vec3 *c) {
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}

void func_021484d0(const Vec3 *a, const Vec3 *b, Vec3 *c) {
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
}

s32 func_0214848c(const Vec3 *a, const Vec3 *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + 0x800) >> 12);
}

s32 func_0214843c(const Unk02148038 *a, const Unk02148038 *b) {
    s32 p;
    s32 q;

    p = a->mUnk_00 * b->mUnk_00;
    p += a->mUnk_02 * b->mUnk_02;
    q = a->mUnk_04 * b->mUnk_04;
    return (s32) (((s64) p + (q + 0x800)) >> 12);
}

void func_021483a0(const Vec3 *a, const Vec3 *b, Vec3 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = ((s64) a->y * b->z - (s64) a->z * b->y + 0x800) >> 12;
    y = ((s64) a->z * b->x - (s64) a->x * b->z + 0x800) >> 12;
    z = ((s64) a->x * b->y - (s64) a->y * b->x + 0x800) >> 12;
    c->x = x;
    c->y = y;
    c->z = z;
}

void func_02148334(const Unk02148038 *a, const Unk02148038 *b, Unk02148038 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = (a->mUnk_02 * b->mUnk_04 - a->mUnk_04 * b->mUnk_02 + 0x800) >> 12;
    y = (a->mUnk_04 * b->mUnk_00 - a->mUnk_00 * b->mUnk_04 + 0x800) >> 12;
    z = (a->mUnk_00 * b->mUnk_02 - a->mUnk_02 * b->mUnk_00 + 0x800) >> 12;
    c->mUnk_00 = x;
    c->mUnk_02 = y;
    c->mUnk_04 = z;
}

s32 func_021482cc(const Vec3 *a) {
    s64 s;

    s = (s64) a->x * a->x;
    s += (s64) a->y * a->y;
    s += (s64) a->z * a->z;
    reg_CP_SQRTCNT = 1;
    *(vu64 *) 0x040002B8 = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) * (vu32 *) 0x040002B4 + 1) >> 1;
}

void func_0214818c(const Vec3 *a, Vec3 *b) {
    s64 s;
    s32 r;
    s64 t;

    s = (s64) a->x * a->x;
    s += (s64) a->y * a->y;
    s += (s64) a->z * a->z;
    reg_CP_DIVCNT = 2;
    *(vu64 *) 0x04000290 = 0x0100000000000000ULL;
    *(vu64 *) 0x04000298 = s;
    reg_CP_SQRTCNT = 1;
    *(vu64 *) 0x040002B8 = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = *(vu32 *) 0x040002B4;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    t = *(vs64 *) 0x040002A0 * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->y = (t * a->y + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
}

void func_02148038(const Unk02148038 *a, Unk02148038 *b) {
    s32 r;
    s64 t;
    s64 s;

    s = a->mUnk_00 * a->mUnk_00;
    s += a->mUnk_02 * a->mUnk_02;
    s += a->mUnk_04 * a->mUnk_04;
    reg_CP_DIVCNT = 2;
    *(vu64 *) 0x04000290 = 0x0100000000000000ULL;
    *(vu64 *) 0x04000298 = s;
    reg_CP_SQRTCNT = 1;
    *(vu64 *) 0x040002B8 = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = *(vu32 *) 0x040002B4;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    t = *(vs64 *) 0x040002A0 * r;
    b->mUnk_00 = (s16) ((t * a->mUnk_00 + 0x100000000000LL) >> 45);
    b->mUnk_02 = (s16) ((t * a->mUnk_02 + 0x100000000000LL) >> 45);
    b->mUnk_04 = (s16) ((t * a->mUnk_04 + 0x100000000000LL) >> 45);
}

void func_02147fd8(s32 a, const Vec3 *b, const Vec3 *c, Vec3 *d) {
    d->x = c->x + (s32) (((s64) a * b->x) >> 12);
    d->y = c->y + (s32) (((s64) a * b->y) >> 12);
    d->z = c->z + (s32) (((s64) a * b->z) >> 12);
}

s32 func_02147f50(const Vec3 *a, const Vec3 *b) {
    s32 x;
    s32 y;
    s32 z;
    s64 d;

    x = a->x - b->x;
    d = (s64) x * x;
    y = a->y - b->y;
    d += (s64) y * y;
    z = a->z - b->z;
    d += (s64) z * z;
    reg_CP_SQRTCNT = 1;
    *(vu64 *) 0x040002B8 = d << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) * (vu32 *) 0x040002B4 + 1) >> 1;
}

s32 func_02147f34(s32 a, s32 b) {
    func_02147d88(a, b);
    return func_02147e28();
}

s32 func_02147f18(s32 a) {
    func_02147dec(a);
    return func_02147e28();
}

s64 func_02147edc(s32 a) {
    func_02147dec(a);
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vs64 *) 0x040002A0;
}

u32 func_02147e8c(s32 a) {
    if (a > 0) {
        reg_CP_SQRTCNT = 1;
        *(vu64 *) 0x040002B8 = (u64) a << 32;
        return func_02147dc0();
    }
    return 0;
}

s64 func_02147e64(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vs64 *) 0x040002A0;
}

s32 func_02147e28(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s32) ((*(vs64 *) 0x040002A0 + 0x80000) >> 20);
}

void func_02147dec(s32 a) {
    reg_CP_DIVCNT = 1;
    *(vu64 *) 0x04000290 = 0x100000000000ULL;
    *(vu64 *) 0x04000298 = (u32) a;
}

u32 func_02147dc0(void) {
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return (*(vu32 *) 0x040002B4 + 0x200) >> 10;
}

void func_02147d88(s32 a, s32 b) {
    reg_CP_DIVCNT = 1;
    *(vu64 *) 0x04000290 = (u64) (u32) a << 32;
    *(vu64 *) 0x04000298 = (u32) b;
}

u32 func_02147d30(u32 a, u32 b) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = a;
    *(vu64 *) 0x04000298 = b;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vu32 *) 0x040002A0;
}

u32 func_02147cd8(u32 a, u32 b) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = a;
    *(vu64 *) 0x04000298 = b;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vu32 *) 0x040002A8;
}
