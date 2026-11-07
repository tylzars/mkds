#pragma once

#include "types.h"

typedef struct ItemKouraW ItemKouraW;

BOOL TrySetItemKouraWKartItems(ItemKouraW *item, s32 kartIndex);
void SteerItemKouraWToKartForward(ItemKouraW *item, s32 gain, s32 lift);
void SteerItemKouraWToNextAnglePoint(ItemKouraW *item, s32 gain, s32 maxStep, s32 radius, u16 angleStep);
