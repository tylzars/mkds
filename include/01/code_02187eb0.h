#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;
typedef struct Kart Kart;
typedef struct CourseMapGroupEntry CourseMapGroupEntry;

void func_ov001_02187eb0(Unk02188950 *mapObject);
CourseMapGroupEntry *GetNextGroupEntry(Unk02188950 *mapObject);
s32 func_ov001_02187f38(Unk02188950 *mapObject);
s32 func_ov001_02187f7c(Unk02188950 *mapObject);
CourseMapGroupEntry *GetCurrentGroupEntry(Unk02188950 *mapObject);
Kart *GetEntryKartFacingObject(Unk02188950 *mapObject, s32 radius, s32 halfAngle);
Kart *GetEntryKartInAngleRange(Unk02188950 *mapObject, s32 angleOffset, s32 radius, s32 halfAngle);
Kart *GetEntryKartInRange(Unk02188950 *mapObject, s32 radius, s32 halfAngle);
