#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // RandomState64

RandomState64 *GetRandomState(void);
BOOL TrySetBackLights(s32 firstRequest, s32 secondRequest);
void StopSceneSoundSetSeqWithSteps(u32 fadeSteps);
void ReleaseSceneSoundSetPlayer(void);
void StopSceneSoundSetSeq(void);
void StartSceneSoundSetSeq(void);
void InitSceneSoundSetPlayer(s32 seqId);
