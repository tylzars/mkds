#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

BOOL func_020f9290(void *itemParam, Vec3 *normal);
void func_020f91fc(void *itemParam, s32 soundId);
BOOL func_020f91e0(ItemObject *itemParam);
BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance);
BOOL func_020f9160(ItemObject *c);
void func_020f9114(void *itemParam);
void func_020f90dc(ItemObject *itemParam);
void func_020f90bc(ItemObject *itemParam);
void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 d);
void func_020f8e78(void *itemParam);
