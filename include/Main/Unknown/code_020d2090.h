#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct MapObject MapObject;

void *FindMainRaceOrMainEffectMapObjFile(const char *name);
void *FindCourseMapObjFile(const char *name);

void func_020d2090(void);
void InitRaceMNumberPair(void);
u32 DecimalNonZeroDigitsToBitMask(s32 number);
BOOL func_020d2234(MapObject *mapObject, ItemObject *itemObject);
