#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_0206bcb0.h"

typedef struct MapObject MapObject;

BOOL func_020f9c08(ItemObject *param_1);
void func_020f9ba8(ItemObject *param_1);
void func_020f9b0c(ItemObject *param_1);
void ResetItemObject(ItemObject *param_1, s32 param_2);
void ResetItemObjectAtPos(ItemObject *param_1, s32 param_2, u16 param_3, Vec3 *param_4);
// Releases what the object holds: the collision body, the model entry when flag 0x400000 is set, then calls the
// kind's release hook. Only ReleaseItemPoolObject calls it.
void ReleaseItemObject(ItemObject *param_1);
void func_020f98a0(ItemObject *param_1, Vec3 *param_2, Vec3 *param_3, u16 *param_4, s32 param_5);
s32 func_020f9880(ItemObject *param_1);
BOOL func_020f97e0(ItemObject *param_1, Kart *param_2);
BOOL IsItemObjectOverlappingSphere(ItemObject *param_1, Vec3 *param_2, s32 param_3);
void func_020f95d4(ItemObject *param_1, ItemObject *param_2);
void func_020f944c(ItemObject *param_1, MapObject *param_2);
void func_020f9334(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, Vec3 *param_5);
