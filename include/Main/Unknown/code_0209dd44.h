#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_0209d694.h" // SunFireball

typedef struct ItemObject ItemObject;

u8 CollideItemObjectWithSunFireball(SunFireball *sunFireball, ItemObject *itemObject, u8 *c, u8 *d);
u8 CollideKartWithSunFireball(SunFireball *sunFireball, Kart *kart, u8 *c, u8 *d);
