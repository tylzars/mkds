#pragma once

#include "types.h"

struct Unk02089a24;
struct KartAi;

struct Unk02089a24;
struct KartAi;

struct Unk02089a24;
struct KartAi;

struct KartAi;
struct Kart;
struct Unk02175620_bc;

void func_0207d814(struct Unk02089a24 *a, struct KartAi *b);
u16 PickKartAiRaceStartBoost(s32 a);
void func_0207d9f0(struct Unk02089a24 *a, struct KartAi *b, s32 c);
void AdvanceRaceKartAiSpeedLimit(struct Unk02089a24 *a, struct KartAi *b);
void PickKartAiRaceStart(struct Unk02089a24 *a, struct KartAi *b);
void ResetRaceKartAiSpeedLimit(struct Unk02089a24 *p0, struct KartAi *p1);
u32 SetupRaceKartAiSpeedLimit(struct Unk02089a24 *arg0, struct KartAi *arg1);
void InitKartAiTables(void);
void AdvanceStaffRollKartAi(struct KartAi *p);
void SetupStaffRollKartAi(struct KartAi *p, struct Kart *q, s32 a);
void AdvanceAwardMissionRunKartAi(struct KartAi *p);
void ResetAwardMissionRunKartAi(struct KartAi *p, struct Unk02175620_bc *a);
void SetupAwardMissionRunKartAi(struct KartAi *p, struct Kart *q, s32 a);
