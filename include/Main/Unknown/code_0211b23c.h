#pragma once

#include "types.h"

void ReleaseSelectRaceRule(void);
void InitSelectRaceRule(void *parentHeap, s32 b, void *oamList, s32 mode);
void RequestSelectRaceRuleState8(void);
void RequestSelectRaceRuleState7(void);
void RequestSelectRaceRuleState6(void);
void RequestSelectRaceRuleState5(void);
void RequestSelectRaceRuleState4(void);
void RequestSelectRaceRuleState3(void);
void RequestSelectRaceRuleState2(void);
void RequestSelectRaceRuleState1(void);
void ResetSelectRaceRulePositions(void);
void SetSelectRaceRuleHumanCount(void);
void ReadRaceSetupCopyIntoSelectRaceRule(void);
void AdvanceSelectRaceRuleTeamInput(void);
void func_0211c0cc(void);
void func_0211c14c(void);
void WriteSelectRaceRuleToRaceSetupCopy(void);
void func_0211c5ac(void);
void func_0211c810(u16 entryIndex, u32 value);
void AdvanceSelectRaceRuleRowObjects(void);
void DecrementSelectRaceRuleCourseCount(void);
void IncrementSelectRaceRuleCourseCount(void);
void MoveSelectRaceRuleValuePrevious(s32 playSound);
void MoveSelectRaceRuleValueNext(s32 playSound);
s32 IsSelectRaceRuleTeamsValid(void);
BOOL DoesSelectRaceRuleHumanCountMatch(void);
BOOL IsSelectRaceRuleValueAllowed(void);
void func_0211cfd0(void);
void func_0211d09c(void);
void ChangeSelectRaceRulePlayerTeam(u16 entryIndex, u32 teamIndex);
BOOL PickSelectRaceRuleCpuEntry(u16 *entryOut);
