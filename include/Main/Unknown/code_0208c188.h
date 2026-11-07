#pragma once

#include "types.h"
#include "Main/Unknown/code_020888b4.h"

void CallKartAiSetupItemInUseEntry(KartAi *kartAi);
void CallKartAiSetupHeldItemEntry(KartAi *kartAi);
void CallKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
void CallKartAiRequestLink(KartAi *kartAi);
void CallKartAiAdvance(KartAi *kartAi);
void CallKartAiReset(KartAi *kartAi, Unk02175620_bc *link);
void CallKartAiSetup(KartAi *kartAi, s32 kartIndex);
void RegisterKartAiCallbacks(void);
