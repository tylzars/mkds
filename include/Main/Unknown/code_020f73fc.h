#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020f9334.h"

void func_020f77f8(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity, MapObject *mapObject);
void func_020f7658(ItemObject *item, s32 c);
void StartItemObjectReleaseTimer(ItemObject *item);
void AdvanceItemObjectReleaseTimer(ItemObject *item);
void func_020f7430(ItemObject *item, s32 c);
void StartItemObjectRelease(ItemObject *item);
