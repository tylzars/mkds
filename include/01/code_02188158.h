#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;
typedef struct ItemBomb ItemBomb;

ItemBomb *FindItemBombInRange(Unk02188950 *mapObject, u32 radius, u32 halfAngle);
BOOL IsPointInRange(Unk02188950 *mapObject, Vec3 *point, s32 radius, s32 halfAngle);
void SetItemCollisionCallback(Unk02188950 *mapObject, UnkFunc *itemCollisionCallback);
void SetKartCollisionCallback(Unk02188950 *mapObject, UnkFunc *kartCollisionCallback);
