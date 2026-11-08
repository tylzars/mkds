#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartAi KartAi;

#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02080b1c.h"

BOOL IsTargetKartSet(KartAi *p);
void func_0207e668(KartAi *p);
void SetKartAiSideOffsetFromKart(KartAi *p);
void AdvanceKartAiSideOffset(KartAi *p);
s32 ComputeAngleToPositionDegrees(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *d);
void func_0207ebfc(KartAi *p);
void func_0207f05c(KartAi *p);
void PickKartAiTargetKart(KartAi *p);
s32 ShouldKartAiTargetKart(u32 a, u32 b);
BOOL func_0207f600(s32 a);
void func_0207f630(KartAi *p, LinkCursor *q, Kart *r);
void func_0207f668(KartAi *p, LinkCursor *q, Kart *r);
void func_0207f6f0(KartAi *p, LinkCursor *q, Kart *r, PointLink *s, Vec3 *a, Vec3 *b);
void AdvanceRaceKartAi(KartAi *p);
void ResetRaceKartAiAtPointLink(KartAi *p);
void ResetKartAi(KartAi *p, s32 a);
void SetupRaceKartAi(KartAi *p, Kart *q, s32 a);
void func_0207fba0(void);
void AdvanceStaffRollPointLinkCursor(Unk02080b1c *p);
s32 func_0207fe70(Unk02080b1c *p);
void AdvanceAwardPointLinkCursor(Unk02080b1c *p);
