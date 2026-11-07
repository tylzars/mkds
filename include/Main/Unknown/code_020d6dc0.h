#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

typedef struct Unk020d84e4 Unk020d84e4;
typedef struct Unk020d849c Unk020d849c;

struct CourseMapRow;

// Four words: QuaternionFromYAxisToVec3 writes them.
typedef struct Quaternion {
    /* 00 */ s32 mComponents[4];
} Quaternion;

void func_020d7d4c(Unk020d84e4 *m, struct CourseMapRow *b, s32 c, s32 d);
void func_020d7d18(Unk020d849c *p, s32 a, Vec3 **b, s32 c);
BOOL func_020d7c84(Unk020d849c *p, s32 a, Vec3 **b);
// Stores in gViewYawQuaternion the rotation about Y by the angle of the matrix a.
void SetViewYawQuaternion(MtxFx43 *a);
void QuaternionFromYAxisToVec3(Vec3 *p, void *q);
void QuaternionFromAngleAroundY(s32 a, Quaternion *b);
// Writes to q the quaternion QuaternionFromYAxisToVec3 gives for p combined with the Y rotation
// QuaternionFromAngleAroundY gives for b.
void QuaternionFromVec3AndAngleAroundY(void *p, s32 b, void *q);
void func_020d79b0(void *p, u32 b, void *q);
void func_020d7938(Quaternion *a, Quaternion *b, Quaternion *c);
void QuaternionMultiplyAngleAroundX(Quaternion *a, s32 b, Quaternion *c);
void QuaternionMultiplyAngleAroundY(void *m, s32 b, void *o);
void QuaternionMultiplyAngleAroundZ(void *m, s32 b, void *o);
void func_020d76a8(Quaternion *a, s32 b, Quaternion *c);
// Blends p toward q by d, toward the negated q when their dot product is negative.
void QuaternionBlendTowardNearerSign(void *p, void *q, void *r, s32 d);
void QuaternionNormalizeUnlessNearOne(Quaternion *a, Quaternion *b);
void QuaternionFromVec3Degrees(Vec3 *a, u32 *m);
s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *a, Vec3 *b);
s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *a, Vec3 *b);
// Writes to c the vector a rotated about the Y axis by the angle b (0x10000 per turn).
void Vec3RotateAroundY(Vec3 *a, s32 b, Vec3 *c);
// Writes to b (a 3x3 matrix, nine words with 12 fractional bits) the rotation given by the three angles of a in degrees
// with 12 fractional bits: the X rotation, then the Y rotation, then the Z rotation multiplied on.
void Matrix3x3FromVec3Degrees(Vec3 *a, s32 *b);
u32 GetKartMapObjectResponseByKind(s32 a, s32 b, s32 c, s32 d);
