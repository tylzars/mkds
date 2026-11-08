#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

typedef struct Unk020d84e4 Unk020d84e4;
typedef struct SegmentProgress SegmentProgress;

struct CourseMapRow;

// Four words: QuaternionFromYAxisToVec3 writes them.
typedef struct Quaternion {
    /* 00 */ s32 mComponents[4];
} Quaternion;

void func_020d7d4c(Unk020d84e4 *m, struct CourseMapRow *courseRow, s32 speed, s32 d);
void func_020d7d18(SegmentProgress *segmentProgress, s32 a, Vec3 **points, s32 rate);
BOOL func_020d7c84(SegmentProgress *segmentProgress, s32 a, Vec3 **points);
// Stores in gViewYawQuaternion the rotation about Y by the angle of the matrix a.
void SetViewYawQuaternion(MtxFx43 *viewMatrix);
void QuaternionFromYAxisToVec3(Vec3 *p, void *output);
void QuaternionFromAngleAroundY(s32 angle, Quaternion *quaternion);
// Writes to q the quaternion QuaternionFromYAxisToVec3 gives for p combined with the Y rotation
// QuaternionFromAngleAroundY gives for b.
void QuaternionFromVec3AndAngleAroundY(void *directionPtr, s32 angle, void *outputPtr);
void func_020d79b0(void *quaternionPtr, u32 angle, void *outputPtr);
void func_020d7938(Quaternion *first, Quaternion *second, Quaternion *result);
void QuaternionMultiplyAngleAroundX(Quaternion *quaternion, s32 angle, Quaternion *result);
void QuaternionMultiplyAngleAroundY(void *quaternionPtr, s32 angle, void *resultPtr);
void QuaternionMultiplyAngleAroundZ(void *quaternionPtr, s32 angle, void *resultPtr);
void func_020d76a8(Quaternion *quaternion, s32 angle, Quaternion *result);
// Blends p toward q by d, toward the negated q when their dot product is negative.
void QuaternionBlendTowardNearerSign(void *fromPtr, void *toPtr, void *resultPtr, s32 amount);
void QuaternionNormalizeUnlessNearOne(Quaternion *input, Quaternion *output);
void QuaternionFromVec3Degrees(Vec3 *degrees, u32 *resultWords);
s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *vector, Vec3 *result);
s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *vector, Vec3 *result);
// Writes to c the vector a rotated about the Y axis by the angle b (0x10000 per turn).
void Vec3RotateAroundY(Vec3 *vector, s32 angle, Vec3 *result);
// Writes to b (a 3x3 matrix, nine words with 12 fractional bits) the rotation given by the three angles of a in degrees
// with 12 fractional bits: the X rotation, then the Y rotation, then the Z rotation multiplied on.
void Matrix3x3FromVec3Degrees(Vec3 *degrees, s32 *matrix);
u32 GetKartMapObjectResponseByKind(s32 flagBit, s32 itemEffect, s32 kindHundreds, s32 kindRemainder);
