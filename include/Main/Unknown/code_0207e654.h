#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct KartAi KartAi;

#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02080b1c.h"

BOOL IsTargetKartSet(KartAi *kartAi);
void func_0207e668(KartAi *kartAi);
void SetKartAiSideOffsetFromKart(KartAi *kartAi);
void AdvanceKartAiSideOffset(KartAi *kartAi);
s32 ComputeAngleToPositionDegrees(Vec3 *targetPos, Vec3 *originPos, Vec3 *planeNormal, Vec3 *forward);
void func_0207ebfc(KartAi *kartAi);
void func_0207f05c(KartAi *kartAi);
void PickKartAiTargetKart(KartAi *kartAi);
s32 ShouldKartAiTargetKart(u32 kartIndex, u32 targetIndex);
BOOL func_0207f600(s32 kartIndex);
void SetKartAiLinkPosAndClearSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart);
void SetKartAiLinkPosAndAddSideOffset(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart);
void func_0207f6f0(KartAi *kartAi, LinkCursor *linkCursor, Kart *kart, PointLink *requestedLink, Vec3 *kartPos,
                   Vec3 *kartForward);
void AdvanceRaceKartAi(KartAi *kartAi);
void ResetRaceKartAiAtPointLink(KartAi *kartAi);
void ResetKartAi(KartAi *kartAi, s32 a);
void SetupRaceKartAi(KartAi *kartAi, Kart *kart, s32 a);
void func_0207fba0(void);
void AdvanceStaffRollPointLinkCursor(PointLinkCursor *pointLinkCursor);
s32 GetPointLinkSpeedRatio(PointLinkCursor *pointLinkCursor);
void AdvanceAwardPointLinkCursor(PointLinkCursor *pointLinkCursor);
