#pragma once

#include "types.h"

typedef struct KartAi KartAi;

void func_0208bfd8(KartAi *kartAi);
void func_0208bfec(KartAi *kartAi);
void CopyKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL IsKartAiLinkRequested(KartAi *kartAi);
void RequestKartAiPointLink(KartAi *kartAi);
void AdvanceKartAiForRace(KartAi *kartAi);
void ResetKartAiForRace(KartAi *kartAi);
void SetupKartAiForRace(KartAi *kartAi, s32 kartIndex);
