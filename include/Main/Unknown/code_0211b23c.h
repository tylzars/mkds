#pragma once

#include "types.h"

void ReleaseSelectRaceRule(void);
void InitSelectRaceRule(void *a, s32 b, void *c, s32 d);
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
void func_0211c810(u16 a, u32 b);
void AdvanceSelectRaceRuleRowObjects(void);
void DecrementSelectRaceRuleCourseCount(void);
void IncrementSelectRaceRuleCourseCount(void);
void MoveSelectRaceRuleValuePrevious(s32 a);
void MoveSelectRaceRuleValueNext(s32 a);
s32 func_0211cdec(void);
BOOL func_0211ce24(void);
BOOL IsSelectRaceRuleValueAllowed(void);
void func_0211cfd0(void);
void func_0211d09c(void);
void ChangeSelectRaceRulePlayerTeam(u16 a, u32 b);
BOOL PickSelectRaceRuleCpuEntry(u16 *a);
