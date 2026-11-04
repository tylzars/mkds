#pragma once

#include "types.h"

// Three halfword components.
typedef struct Unk02148038 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
} Unk02148038;

u32 func_02147cd8(u32 a, u32 b);
u32 Div32(u32 a, u32 b);
void func_02147d88(s32 a, s32 b);
u32 func_02147dc0(void);
void func_02147dec(s32 a);
s32 func_02147e28(void);
s64 func_02147e64(void);
u32 func_02147e8c(s32 a);
s64 func_02147edc(s32 a);
s32 func_02147f18(s32 a);
s32 DivFixed12(s32 a, s32 b);
s32 func_02147f50(const Vec3 *a, const Vec3 *b);
// Argument order: scalar, vector, base, result: result = base + vector * scalar (scalar with 12 fractional bits).
void Vec3AddScaled(s32 a, const Vec3 *b, const Vec3 *c, Vec3 *d);
void func_02148038(const Unk02148038 *a, Unk02148038 *b);
void Vec3Normalize(const Vec3 *a, Vec3 *b);
s32 Vec3Length(const Vec3 *a);
void func_02148334(const Unk02148038 *a, const Unk02148038 *b, Unk02148038 *c);
void Vec3Cross(const Vec3 *a, const Vec3 *b, Vec3 *c);
s32 func_0214843c(const Unk02148038 *a, const Unk02148038 *b);
s32 Vec3Dot(const Vec3 *a, const Vec3 *b);
void Vec3Sub(const Vec3 *a, const Vec3 *b, Vec3 *c);
void Vec3Add(const Vec3 *a, const Vec3 *b, Vec3 *c);
