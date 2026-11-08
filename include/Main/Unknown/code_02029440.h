#pragma once

#include "types.h"

void SetSessionKartCount(unsigned int sessionKartCount);
void SetRaceSetupCopyEntryIndex(unsigned int entryIndex);
void SetMissionFileRowIndex(unsigned int missionFileRowIndex);
void SetMissionTableColumn(unsigned int missionTableColumn);
void SetMissionTableRow(unsigned int missionTableRow);
void func_0202949c(unsigned int p0);
void func_020294ac(u16 entryIndex, u32 b);
void func_020294c0(u16 entryIndex, u32 b);
void SetPlayerKind(u16 entryIndex, u32 playerKind);
void SetKartIndex(u16 entryIndex, u32 kartIndex);
void SetCharacterIndex(u16 entryIndex, u32 characterIndex);
void SetTeamIndex(u16 entryIndex, u32 teamIndex);
void ClearUseTeams(void);
void SetUseTeams(void);
void SetRuleKind(unsigned int ruleKind);
void SetRaceSetupCopyCourseCount(u16 courseCount);
void SetCourseListMode(unsigned int courseListMode);
void SetCpuDifficulty(unsigned int cpuDifficulty);
void SetCourseId(unsigned int courseId);
void SetCupIndex(unsigned int cupIndex);
void ClearMirrorMode(void);
void SetMirrorMode(void);
void SetEngineIndex(unsigned int engineIndex);
unsigned int GetSessionKartCount(void);
unsigned int GetRaceSetupCopyEntryIndex(void);
unsigned int GetMissionTableColumn(void);
unsigned int GetMissionTableRow(void);
unsigned int GetTeamIndex(u16 entryIndex);
unsigned int GetUseTeams(void);
unsigned int GetRuleKind(void);
unsigned int GetRaceSetupCopyCourseCount(void);
unsigned int GetCourseListMode(void);
unsigned int GetCpuDifficulty(void);
unsigned int GetMirrorMode(void);
unsigned int GetCupIndex(void);
unsigned int GetEngineIndex(void);
unsigned int GetPlayerKind(u16 entryIndex);
unsigned int GetKartIndex(u16 entryIndex);
unsigned int GetCharacterIndex(u16 entryIndex);
unsigned int GetCourseId(void);
