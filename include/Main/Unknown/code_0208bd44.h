#pragma once

#include "types.h"
#include "Main/Unknown/code_020888b4.h"

void SetupKartAiForStaffRoll(KartAi *kartAi, s32 kartIndex);
void func_0208bdc0(KartAi *kartAi);
void func_0208bde0(KartAi *kartAi, PointLink *pointLink);
void SetupKartAiForAwardMissionRun(KartAi *kartAi, s32 kartIndex);
void SetupBattleKartAiItemInUseEntry(KartAi *kartAi);
void SetupBattleKartAiHeldItemEntry(KartAi *kartAi);
void CopyBattleKartAiLinkPosAndDirection(Vec3 *position, Vec3 *direction, KartAi *kartAi);
BOOL IsBattleKartAiLinkRequested(KartAi *kartAi);
void RequestBattleKartAiPointLink(KartAi *kartAi);
void AdvanceKartAiForBattle(KartAi *kartAi);
