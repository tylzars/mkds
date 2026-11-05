#pragma once

#include "types.h"

typedef struct Kart Kart;

void func_01ffba68(Kart *p);
void func_01ffbd9c(Kart *p);
void UpdateKartSpeedLimit(Kart *p);
void UpdateKartSpeedLimitGoal(Kart *p);
void func_01ffbfe4(Kart *p);
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
void func_01ffcac0(Kart *p);
void func_01ffcb58(Kart *p);
void func_01ffcc50(Kart *p);
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
