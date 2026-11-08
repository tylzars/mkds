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

void func_0207d814(struct KartAiRaceSpeedLimit *a, struct KartAi *b);
u16 PickKartAiRaceStartBoost(s32 a);
void func_0207d9f0(struct KartAiRaceSpeedLimit *a, struct KartAi *b, s32 c);
void AdvanceRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *a, struct KartAi *b);
void PickKartAiRaceStart(struct KartAiRaceSpeedLimit *a, struct KartAi *b);
void ResetRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *p0, struct KartAi *p1);
u32 SetupRaceKartAiSpeedLimit(struct KartAiRaceSpeedLimit *arg0, struct KartAi *arg1);
void InitKartAiTables(void);
void AdvanceStaffRollKartAi(struct KartAi *p);
void SetupStaffRollKartAi(struct KartAi *p, struct Kart *q, s32 a);
void AdvanceAwardMissionRunKartAi(struct KartAi *p);
void ResetAwardMissionRunKartAi(struct KartAi *p, struct PointLink *a);
void SetupAwardMissionRunKartAi(struct KartAi *p, struct Kart *q, s32 a);
