#pragma once

#include "types.h"

typedef struct ItemKouraW ItemKouraW;

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift);
