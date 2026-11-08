#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct ItemBomb ItemBomb;

ItemBomb *func_020fd7a4(int index);
void func_020fd754(void *object);
void func_020fd684(void *object, Vec3 *d, Vec3 *f);
void func_020fd540(void **bombSlot, Vec3 *param_2, s32 param_3);
BOOL IsItemBombState2(ItemObject *object);
void ReleaseItemBomb(void **bombSlot);
void *StartItemBomb(void);
void *StartItemBombWithMapObject(void *mapObject, s32 param_2);
Vec3 *func_020fd308(ItemBomb *bomb, s32 *stateFrames, s32 *scaledScaleZ);
void func_020fd264(void);
