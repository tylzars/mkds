#pragma once

#include "types.h"

void SetSelectReturnDisplayBitOn(void);

void SetSelectChoisesSoundId(int choiceIndex, u32 soundId);
unsigned int GetSelectChoisesDone(void);
s32 GetSelectChoisesIndex(void);
u32 ClearSelectChoisesUseCharBuffers(void);
void SetSelectReturnSoundId(u32 soundId);
