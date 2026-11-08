#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_0206bcb0.h"

typedef struct MapObject MapObject;

BOOL func_020f9c08(ItemObject *item);
void func_020f9ba8(ItemObject *item);
void func_020f9b0c(ItemObject *item);
void ResetItemObject(ItemObject *item, s32 kind);
void ResetItemObjectAtPos(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos);
// Releases what the object holds: the collision body, the model entry when flag 0x400000 is set, then calls the
// kind's release hook. Only ReleaseItemPoolObject calls it.
void ReleaseItemObject(ItemObject *item);
void func_020f98a0(ItemObject *itemParam, Vec3 *prevPos, Vec3 *normal, u16 *colorBlend, s32 param_5);
s32 func_020f9880(ItemObject *item);
BOOL func_020f97e0(ItemObject *item, Kart *kart);
BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius);
void func_020f95d4(ItemObject *item, ItemObject *other);
void func_020f944c(ItemObject *itemParam, MapObject *mapObjectParam);
void func_020f9334(void *itemParam, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal);
