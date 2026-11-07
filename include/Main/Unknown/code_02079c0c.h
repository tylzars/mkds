#pragma once

#include "types.h"

struct KartModelsEntry;

void SetKartModelsEntryCourseColors(struct KartModelsEntry *a);
s32 AdvanceKartModelColorBlend(struct KartModelsEntry *a, s32 b);
void StartKartModelColorBlend(struct KartModelsEntry *a, u16 b, u16 c, u16 d);
