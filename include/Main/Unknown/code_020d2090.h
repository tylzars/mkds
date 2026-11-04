#pragma once

#include "types.h"

typedef struct Unk020f41c4_A Unk020f41c4_A;
typedef struct MapObject MapObject;

void *FindMainRaceOrMainEffectMapObjFile(const char *a);
void *FindCourseMapObjFile(const char *a);

void func_020d2090(void);
void func_020d20a8(void);
u32 DecimalNonZeroDigitsToBitMask(s32 c);
BOOL func_020d2234(MapObject *d, Unk020f41c4_A *e);
