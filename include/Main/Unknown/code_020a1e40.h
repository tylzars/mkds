#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h" // ItemObject

void CallStandingsKartOffsetCallback(s32 a, s32 b);
s32 CallKartCollisionCallbacks(s32 a, s32 b);
void SetKartHitByKartIndexFromItem(s32 a, ItemObject *p);
