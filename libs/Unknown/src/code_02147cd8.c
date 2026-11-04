#include "code_02147cd8.h"
#include "registers.h"

void Vec3Add(const Vec3 *a, const Vec3 *b, Vec3 *c) {
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    c->z = a->z + b->z;
}

void Vec3Sub(const Vec3 *a, const Vec3 *b, Vec3 *c) {
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    c->z = a->z - b->z;
}

s32 Vec3Dot(const Vec3 *a, const Vec3 *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + 0x800) >> 12);
}

s32 Vec3s16Dot(const Vec3s16 *a, const Vec3s16 *b) {
    s32 p;
    s32 q;

    p = a->x * b->x;
    p += a->y * b->y;
    q = a->z * b->z;
    return (s32) (((s64) p + (q + 0x800)) >> 12);
}

void Vec3Cross(const Vec3 *a, const Vec3 *b, Vec3 *c) {
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

void Vec3s16Cross(const Vec3s16 *a, const Vec3s16 *b, Vec3s16 *c) {
    s32 x;
    s32 y;
    s32 z;

    x = (a->y * b->z - a->z * b->y + 0x800) >> 12;
    y = (a->z * b->x - a->x * b->z + 0x800) >> 12;
    z = (a->x * b->y - a->y * b->x + 0x800) >> 12;
    c->x = x;
    c->y = y;
    c->z = z;
}

s32 Vec3Length(const Vec3 *a) {
    s64 s;

    s = (s64) a->x * a->x;
    s += (s64) a->y * a->y;
    s += (s64) a->z * a->z;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) * (vu32 *) 0x040002B4 + 1) >> 1;
}

void Vec3Normalize(const Vec3 *a, Vec3 *b) {
    s64 s;
    s32 r;
    s64 t;

    s = (s64) a->x * a->x;
    s += (s64) a->y * a->y;
    s += (s64) a->z * a->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x0100000000000000ULL;
    reg_CP_DIV_DENOM = s;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    t = *(vs64 *) 0x040002A0 * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->y = (t * a->y + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
}

void Vec3s16Normalize(const Vec3s16 *a, Vec3s16 *b) {
    s32 r;
    s64 t;
    s64 s;

    s = a->x * a->x;
    s += a->y * a->y;
    s += a->z * a->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x0100000000000000ULL;
    reg_CP_DIV_DENOM = s;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = s << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    t = *(vs64 *) 0x040002A0 * r;
    b->x = (s16) ((t * a->x + 0x100000000000LL) >> 45);
    b->y = (s16) ((t * a->y + 0x100000000000LL) >> 45);
    b->z = (s16) ((t * a->z + 0x100000000000LL) >> 45);
}

void Vec3AddScaled(s32 a, const Vec3 *b, const Vec3 *c, Vec3 *d) {
    d->x = c->x + (s32) (((s64) a * b->x) >> 12);
    d->y = c->y + (s32) (((s64) a * b->y) >> 12);
    d->z = c->z + (s32) (((s64) a * b->z) >> 12);
}

s32 Vec3Distance(const Vec3 *a, const Vec3 *b) {
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
    reg_CP_SQRT_PARAM = d << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) * (vu32 *) 0x040002B4 + 1) >> 1;
}

s32 DivFixed12(s32 a, s32 b) {
    DivFixed12Start(a, b);
    return DivFixed12Result();
}

s32 ReciprocalFixed12(s32 a) {
    ReciprocalFixed12Start(a);
    return DivFixed12Result();
}

s64 ReciprocalFixed12Raw(s32 a) {
    ReciprocalFixed12Start(a);
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vs64 *) 0x040002A0;
}

u32 SqrtFixed12(s32 a) {
    if (a > 0) {
        reg_CP_SQRTCNT = 1;
        reg_CP_SQRT_PARAM = (u64) a << 32;
        return SqrtFixed12Result();
    }
    return 0;
}

s64 DivResult64(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vs64 *) 0x040002A0;
}

s32 DivFixed12Result(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s32) ((*(vs64 *) 0x040002A0 + 0x80000) >> 20);
}

void ReciprocalFixed12Start(s32 a) {
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) a;
}

u32 SqrtFixed12Result(void) {
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return (reg_CP_SQRT_RESULT + 0x200) >> 10;
}

void DivFixed12Start(s32 a, s32 b) {
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = (u64) (u32) a << 32;
    reg_CP_DIV_DENOM = (u32) b;
}

u32 Div32(u32 a, u32 b) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = a;
    reg_CP_DIV_DENOM = b;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vu32 *) 0x040002A0;
}

u32 Div32Remainder(u32 a, u32 b) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = a;
    reg_CP_DIV_DENOM = b;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vu32 *) 0x040002A8;
}
