#pragma once

#include "types.h"

typedef struct SoundRow SoundRow;

u32 GetSceneSoundRowIndex(s32 sceneNumber, void *output);
u32 GetCourseSoundRowIndex(u32 courseId, void *output);
SoundRow GetSoundRow(u32 rowIndex);
