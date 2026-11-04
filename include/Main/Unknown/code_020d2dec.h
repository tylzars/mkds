#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct Unk020fa294 Unk020fa294;

MapObject *CreateMapObject(u32 kind, Unk020fa294 *courseRow, MapObject *source);
MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind);
MapObject *CreateMapObjectFromCourseMapRow(Unk020fa294 *courseRow, s32 kind);
void InitMapObjects(void);
void func_020d2e24(void);
void func_020d2dec(void);
