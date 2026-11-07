#pragma once

#include "types.h"

typedef struct Unk0208fd8c_08 Unk0208fd8c_08;
typedef struct Unk0208fd8c Unk0208fd8c;

struct CourseMapCamera;
struct Unk0208fd8c;
struct Unk020888b4;
struct Unk0208fd8c_08;

// Four points, a parameter (0x1000 = one segment) and two words at 0x34 and 0x38. The camera position is blended from
// the four points.
typedef struct PosCurve {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mParam;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
} PosCurve;

struct Unk020888b4;

extern void (*data_0217ae3c)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae40)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae44)(Unk0208fd8c *a, struct Unk020888b4 *b);
extern void (*data_0217ae48)(Unk0208fd8c *a, struct Unk020888b4 *b);

typedef struct Unk0208fd8c Unk0208fd8c;

struct Unk02089a24;
struct Unk020888b4;

extern Unk0208fd8c_08 data_usa_0215524c[];
extern Unk0208fd8c_08 data_usa_021552f4[];
extern Unk0208fd8c_08 data_usa_021553cc[];
extern Unk0208fd8c_08 data_usa_021554a4[];

// Writes to a the point of the curve b at parameter mParam (0 to 0x1000): the four control points of mPoints weighted
// by the uniform cubic B-spline basis.
void ComputePosCurvePoint(Vec3 *a, PosCurve *b);
// Adds d to the curve parameter (0x1000 = one segment); past 0x1000 it shifts the four control points on to the next
// point of the entry's group (clamped after the last) and writes the point on the curve to a. UpdateCameraPosCurve
// calls it for groups of four or more points.
void UpdatePosCurve(Vec3 *a, PosCurve *b, struct CourseMapCamera *c, s32 d);
void func_0207bd6c(PosCurve *a, struct CourseMapCamera *b);
// Restarts the curve a on the entry b: clears its parameter and counters and, when the entry's group has four or more
// points, loads the first four as its control points (nothing is loaded for fewer).
void SetupPosCurve(PosCurve *a, struct CourseMapCamera *b);
void SetupItemInUseEntry(struct Unk0208fd8c *a, struct Unk020888b4 *b);
s32 DecrementItemInUseTimer(struct Unk0208fd8c *a);
void ResetItemInUseTimer(struct Unk0208fd8c *a, struct Unk0208fd8c_08 *b);
s32 DecrementHeldItemTimer(struct Unk0208fd8c *a);
void ResetHeldItemTimer(struct Unk0208fd8c *a);
void SetupHeldItemEntry(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c270(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c2ec(struct Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c448(Unk0208fd8c *p0);
void func_0207c47c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c548(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c614(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c6d0(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c78c(void);
void func_0207c8d8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207c978(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207ca18(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207ca60(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207caa8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cb0c(Unk0208fd8c *a, struct Unk020888b4 *b);
unsigned int func_0207cb70(unsigned int p0);
void func_0207cb74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cc74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207cd74(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d194(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d35c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d3a4(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d3ec(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d474(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d4cc(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d5b8(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0207d6a4(struct Unk02089a24 *a, struct Unk020888b4 *b);
