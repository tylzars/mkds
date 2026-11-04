#pragma once

#include "types.h"

typedef struct Kart Kart;

void func_01ffad14(Kart *p, Vec3 *a);
void ScaleKartVelocityAndSetCappedLengthAndDirection(Kart *p, s32 a);
s32 LimitKartForwardSpeedAndGetScaled(Kart *p);
void func_01ffb0cc(Kart *p);
