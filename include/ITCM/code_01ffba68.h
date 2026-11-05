#pragma once

#include "types.h"

typedef struct Kart Kart;

void func_01ffba68(Kart *p);
void func_01ffbd9c(Kart *p);
void UpdateKartSpeedLimit(Kart *p);
void UpdateKartSpeedLimitGoal(Kart *p);
// Stores the previous collision center: the point mRadius plus 0x400 along the up vector from mUnk_98. Slot 5 of
// Kart.mSlotFunctions for every Kart except the remote Karts of mode 5; also called once from func_020653d0.
void SetKartPrevCollisionCenter(Kart *p);
void func_01ffc008(Vec3 *a, const Vec3 *b, s32 c, Kart *p);
void ComputeKartPointAlongUp(Vec3 *a, const Vec3 *b, s32 c, Kart *p);
void func_01ffc090(Kart *p, s32 a);
s32 func_01ffc158(Kart *p, s16 a, s16 b, s32 c, s32 d, u32 e);
s32 func_01ffc27c(Kart *p, s32 a);
void func_01ffc500(s32 *a);
void func_01ffc558(Kart *p);
void func_01ffc5a0(Kart *p);
BOOL func_01ffc67c(Kart *p);
void func_01ffc6c0(Kart *p);
void func_01ffc8cc(Kart *p);
void func_01ffc920(Kart *p);
s32 func_01ffc92c(Kart *p);
void func_01ffc9e8(Kart *p, s32 a);
void func_01ffca50(Kart *p);
// First step of UpdateKarts for one Kart: copies the near-Kart mask, the position, mUnk_1d8, mUnk_2e4 and mUnk_2d8 into
// their previous values, clears mTestedKartMask, mNearKartMask and some bits of mUnk_44 and mUnk_4c, then runs slot 5
// of Kart.mSlotFunctions.
void UpdateKartPrevValuesAndClearFlags(Kart *p);
// Slot 4 step of one Kart: moves Kart.mCollisionCenter, sweeps it against the course from Kart.mPrevCollisionCenter,
// counts the step and calls the function in mUnk_230.
void AdvanceKartCollision(Kart *p);
// Slot 3 step of one Kart: speed limits from the physical parameters, the Kart state function, gravity and the velocity
// added to mPos. Does not test collisions.
void AdvanceKartMotion(Kart *p);
// Writes nine words (a 3x3 rotation matrix with 12 fractional bits) to its first argument from the quaternion at its
// second argument (w in the fourth component); which of the nine words is a row or a column is not claimed.
void Matrix3x3FromQuaternion(void *param_1, void *param_2);
void func_01ffcd84(void *a, const Vec4 *b);
// Writes to c the linear blend of the quaternions a and b with weight d out of 0x1000 (0x1000 gives b); the result is
// not normalized.
void QuaternionBlend(Vec4 *a, const Vec4 *b, Vec4 *c, s32 d);
// Writes to c the Hamilton product of the quaternions a and b (x, y, z, w with 12 fractional bits, w the scalar part);
// c may be a or b.
void QuaternionMultiply(const Vec4 *a, const Vec4 *b, Vec4 *c);
