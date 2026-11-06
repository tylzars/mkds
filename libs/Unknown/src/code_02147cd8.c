#include "code_02147cd8.h"
#include "registers.h"

// Adds two vectors component by component: sum = a + b.
void VEC_Add(const Vec3 *a, const Vec3 *b, Vec3 *sum) {
    sum->x = a->x + b->x;
    sum->y = a->y + b->y;
    sum->z = a->z + b->z;
}

// Subtracts two vectors component by component: difference = a - b.
void VEC_Subtract(const Vec3 *a, const Vec3 *b, Vec3 *difference) {
    difference->x = a->x - b->x;
    difference->y = a->y - b->y;
    difference->z = a->z - b->z;
}

// Dot product of two 20.12 vectors, rounded to 20.12.
s32 VEC_DotProduct(const Vec3 *a, const Vec3 *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + 0x800) >> 12);
}

// Dot product of two 4.12 halfword vectors, rounded to 20.12.
s32 VEC_Fx16DotProduct(const Vec3s16 *a, const Vec3s16 *b) {
    s32 sum;
    s32 last;

    sum = a->x * b->x;
    sum += a->y * b->y;
    last = a->z * b->z;
    return (s32) (((s64) sum + (last + 0x800)) >> 12);
}

// Cross product of two 20.12 vectors, rounded to 20.12.
void VEC_CrossProduct(const Vec3 *a, const Vec3 *b, Vec3 *result) {
    s32 x;
    s32 y;
    s32 z;

    x = ((s64) a->y * b->z - (s64) a->z * b->y + 0x800) >> 12;
    y = ((s64) a->z * b->x - (s64) a->x * b->z + 0x800) >> 12;
    z = ((s64) a->x * b->y - (s64) a->y * b->x + 0x800) >> 12;
    result->x = x;
    result->y = y;
    result->z = z;
}

// Cross product of two 4.12 halfword vectors.
void VEC_Fx16CrossProduct(const Vec3s16 *a, const Vec3s16 *b, Vec3s16 *result) {
    s32 x;
    s32 y;
    s32 z;

    x = (a->y * b->z - a->z * b->y + 0x800) >> 12;
    y = (a->z * b->x - a->x * b->z + 0x800) >> 12;
    z = (a->x * b->y - a->y * b->x + 0x800) >> 12;
    result->x = x;
    result->y = y;
    result->z = z;
}

// Length of a vector, from the square root coprocessor.
s32 VEC_Mag(const Vec3 *v) {
    s64 squared;

    squared = (s64) v->x * v->x;
    squared += (s64) v->y * v->y;
    squared += (s64) v->z * v->z;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = squared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) reg_CP_SQRT_RESULT + 1) >> 1;
}

// Scales a vector to length 1.0 using the divider and square root coprocessors.
void VEC_Normalize(const Vec3 *src, Vec3 *dst) {
    s64 squared;
    s32 root;
    s64 scale;

    squared = (s64) src->x * src->x;
    squared += (s64) src->y * src->y;
    squared += (s64) src->z * src->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x0100000000000000ULL;
    reg_CP_DIV_DENOM = squared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = squared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    scale = (s64) reg_CP_DIV_RESULT * root;
    dst->x = (scale * src->x + 0x100000000000LL) >> 45;
    dst->y = (scale * src->y + 0x100000000000LL) >> 45;
    dst->z = (scale * src->z + 0x100000000000LL) >> 45;
}

// Scales a halfword vector to length 1.0 using the divider and square root coprocessors.
void VEC_Fx16Normalize(const Vec3s16 *src, Vec3s16 *dst) {
    s32 root;
    s64 scale;
    s64 squared;

    squared = src->x * src->x;
    squared += src->y * src->y;
    squared += src->z * src->z;
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x0100000000000000ULL;
    reg_CP_DIV_DENOM = squared;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = squared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    root = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    scale = (s64) reg_CP_DIV_RESULT * root;
    dst->x = (s16) ((scale * src->x + 0x100000000000LL) >> 45);
    dst->y = (s16) ((scale * src->y + 0x100000000000LL) >> 45);
    dst->z = (s16) ((scale * src->z + 0x100000000000LL) >> 45);
}

// result = base + vector * scale, with scale in 20.12.
void VEC_MultAdd(s32 scale, const Vec3 *vector, const Vec3 *base, Vec3 *result) {
    result->x = base->x + (s32) (((s64) scale * vector->x) >> 12);
    result->y = base->y + (s32) (((s64) scale * vector->y) >> 12);
    result->z = base->z + (s32) (((s64) scale * vector->z) >> 12);
}

// Distance between two points, from the square root coprocessor.
s32 VEC_Distance(const Vec3 *a, const Vec3 *b) {
    s32 x;
    s32 y;
    s32 z;
    s64 squared;

    x = a->x - b->x;
    squared = (s64) x * x;
    y = a->y - b->y;
    squared += (s64) y * y;
    z = a->z - b->z;
    squared += (s64) z * z;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = squared << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return ((s32) reg_CP_SQRT_RESULT + 1) >> 1;
}

// Divides numer by denom and returns the 20.12 quotient.
s32 FX_Div(s32 numer, s32 denom) {
    FX_DivAsync(numer, denom);
    return FX_GetDivResult();
}

// Returns 1.0 / denom in 20.12.
s32 FX_Inv(s32 denom) {
    FX_InvAsync(denom);
    return FX_GetDivResult();
}

// Returns the raw 64-bit result of 1.0 / denom.
s64 FX_InvFx64c(s32 denom) {
    FX_InvAsync(denom);
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s64) reg_CP_DIV_RESULT;
}

// Square root of a 20.12 value, 0 for values that are not positive.
s32 FX_Sqrt(s32 x) {
    if (x > 0) {
        reg_CP_SQRTCNT = 1;
        reg_CP_SQRT_PARAM = (u64) x << 32;
        return FX_GetSqrtResult();
    }
    return 0;
}

// Waits for the divider and returns the raw 64-bit quotient.
s64 FX_GetDivResultFx64c(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s64) reg_CP_DIV_RESULT;
}

// Waits for the divider and returns the quotient rounded to 20.12.
s32 FX_GetDivResult(void) {
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s32) (((s64) reg_CP_DIV_RESULT + 0x80000) >> 20);
}

// Starts 1.0 / denom on the divider without waiting.
void FX_InvAsync(s32 denom) {
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) denom;
}

// Waits for the square root unit and returns the result rounded to 20.12.
s32 FX_GetSqrtResult(void) {
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return (reg_CP_SQRT_RESULT + 0x200) >> 10;
}

// Starts numer / denom on the divider without waiting.
void FX_DivAsync(s32 numer, s32 denom) {
    reg_CP_DIVCNT = 1;
    reg_CP_DIV_NUMER = (u64) (u32) numer << 32;
    reg_CP_DIV_DENOM = (u32) denom;
}

// Integer division on the divider.
s32 FX_DivS32(s32 numer, s32 denom) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = numer;
    reg_CP_DIV_DENOM = (u32) denom;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return (s32) * (vu32 *) 0x040002A0;
}

// Integer remainder on the divider.
s32 FX_ModS32(s32 numer, s32 denom) {
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = numer;
    reg_CP_DIV_DENOM = (u32) denom;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    return *(vu32 *) 0x040002A8;
}
