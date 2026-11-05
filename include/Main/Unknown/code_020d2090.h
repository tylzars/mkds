#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct MapObject MapObject;

void *FindMainRaceOrMainEffectMapObjFile(const char *a);
void *FindCourseMapObjFile(const char *a);

void func_020d2090(void);
void InitRaceMNumberPair(void);
u32 DecimalNonZeroDigitsToBitMask(s32 c);
BOOL func_020d2234(MapObject *d, ItemObject *e);
