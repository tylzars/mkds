#pragma once

#include "types.h"

struct KartModelsEntry;

void SetKartModelsEntryCourseColors(struct KartModelsEntry *kartModelsEntry);
s32 AdvanceKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, s32 blendAmount);
void StartKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor);
