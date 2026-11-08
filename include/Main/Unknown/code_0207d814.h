#pragma once

#include "types.h"

struct KartAiRaceSpeedLimit;
struct KartAi;

struct KartAiRaceSpeedLimit;
struct KartAi;

struct KartAiRaceSpeedLimit;
struct KartAi;

struct KartAi;
struct Kart;
struct PointLink;

void func_0207d814(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
u16 PickKartAiRaceStartBoost(s32 pickLast);
void func_0207d9f0(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi, s32 speedLimitCap);
void AdvanceRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
u32 SetupRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
void InitKartAiTables(void);
void AdvanceStaffRollKartAi(struct KartAi *kartAi);
void SetupStaffRollKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a);
void AdvanceAwardMissionRunKartAi(struct KartAi *kartAi);
void ResetAwardMissionRunKartAi(struct KartAi *kartAi, struct PointLink *pointLink);
void SetupAwardMissionRunKartAi(struct KartAi *kartAi, struct Kart *kart, s32 a);
