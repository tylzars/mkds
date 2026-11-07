#pragma once

#include "types.h"

typedef struct Kart Kart;

// Sets mUnk_100_q to the quaternion from the up vector to a (y = 0, w keeps its sign) and normalizes it; when there is
// none, multiplies it by the quaternion from mUnk_244 to a first.
void AdvanceKartQuaternionFromVector(Kart *p, Vec3 *a);
void ScaleKartVelocityAndSetCappedLengthAndDirection(Kart *p, s32 a);
s32 LimitKartForwardSpeedAndGetScaled(Kart *p);
void func_01ffb0cc(Kart *p);
