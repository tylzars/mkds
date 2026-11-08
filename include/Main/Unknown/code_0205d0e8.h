#pragma once

#include "types.h"

typedef struct Unk0217aa1c_144_00 Unk0217aa1c_144_00;

void CopyKartCupRecords(u8 from, u8 to);
s32 func_0205d140(void);
s32 func_0205d190(void);
u8 GetKartStartRank(u32 kart);
u8 GetKartPreviousWinCount(u32 kart);
u16 GetKartPreviousTotalPoints(u32 kart);
s32 GetCupWinningTeam(void);
s32 GetKartCupRank(u32 kart);
void SetTeamWinCountsAndPoints(s32 winningTeam);
void SetCupWinningTeam(s32 team);
void SetKartCupRank(s32 kart, u8 rank);
void GetKartCourseFinishTime(Unk0217aa1c_144_00 *finishTime, u32 kart, u32 course);
void SetKartCourseFinishTime(u32 kart, Unk0217aa1c_144_00 *finishTime);
void func_0205d88c(u32 kart, s32 b);
void ClearKartCourseTotalPoints(u32 kart);
void SetKartCourseResult(u32 kart, s32 rank, u32 points);
u8 GetCourseIndexInCup(void);
void ResetCupRecords(void);
