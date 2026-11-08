#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 func_0206f04c(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 d, s32 e, s32 f);
void func_0206f574(Kart *kart, u32 collisionFlags, Vec3 *contactNormal);
void func_0206f694(Kart *kart, u32 collisionFlags, Vec3 *b, s32 headingDelta);
void func_0206f824(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet);
void AdvanceKartRaceStartBoost(Kart *kart);
void ApplyKartWaterDepth(Kart *kart);
void func_0206ff50(Kart *kart, u32 collisionFlags);
