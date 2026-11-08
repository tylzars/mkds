#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

void InitKart(Kart *kart, void (**slotFunctions)(Kart *));
// Stores the previous collision center from mPrevPos. Slot 5 of Kart.mSlotFunctions for a Kart of player kind 3 in mode
// 5.
void SetKartPrevCollisionCenterFromPrevPos(Kart *kart);
void func_02064d60(Kart *kart, Vec3 *groundNormal);
void func_02064f50(Kart *kart);
void func_020651fc(Kart *kart);
