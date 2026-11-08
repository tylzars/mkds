#pragma once

#include "types.h"

typedef struct KartAiItemUseEntry KartAiItemUseEntry;
typedef struct KartAiItemUse KartAiItemUse;

struct CourseMapCamera;
struct KartAiItemUse;
struct KartAi;
struct KartAiItemUseEntry;

// Four points, a parameter (0x1000 = one segment) and two words at 0x34 and 0x38. The camera position is blended from
// the four points.
typedef struct PosCurve {
    /* 00 */ Vec3 mPoints[4];
    /* 30 */ s32 mParam;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
} PosCurve;

struct KartAi;

extern void (*data_0217ae3c)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae40)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae44)(KartAiItemUse *a, struct KartAi *b);
extern void (*data_0217ae48)(KartAiItemUse *a, struct KartAi *b);

typedef struct KartAiItemUse KartAiItemUse;

struct KartAiRaceSpeedLimit;
struct KartAi;

extern KartAiItemUseEntry gRaceItemInUseEntries[];
extern KartAiItemUseEntry gRaceNormalHeldItemEntries[];
extern KartAiItemUseEntry gRaceHardHeldItemEntries[];
extern KartAiItemUseEntry gRaceEasyHeldItemEntries[];

// Writes to a the point of the curve b at parameter mParam (0 to 0x1000): the four control points of mPoints weighted
// by the uniform cubic B-spline basis.
void ComputePosCurvePoint(Vec3 *point, PosCurve *posCurve);
// Adds d to the curve parameter (0x1000 = one segment); past 0x1000 it shifts the four control points on to the next
// point of the entry's group (clamped after the last) and writes the point on the curve to a. UpdateCameraPosCurve
// calls it for groups of four or more points.
void UpdatePosCurve(Vec3 *point, PosCurve *posCurve, struct CourseMapCamera *mapCamera, s32 paramStep);
void func_0207bd6c(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
// Restarts the curve a on the entry b: clears its parameter and counters and, when the entry's group has four or more
// points, loads the first four as its control points (nothing is loaded for fewer).
void SetupPosCurve(PosCurve *posCurve, struct CourseMapCamera *mapCamera);
void SetupItemInUseEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
s32 DecrementItemInUseTimer(struct KartAiItemUse *itemUse);
void ResetItemInUseTimer(struct KartAiItemUse *itemUse, struct KartAiItemUseEntry *unusedEntry);
s32 DecrementHeldItemTimer(struct KartAiItemUse *itemUse);
void ResetHeldItemTimer(struct KartAiItemUse *itemUse);
void SetupHeldItemEntry(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void AdvanceRaceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void AdvanceItemBitRequests(struct KartAiItemUse *itemUse, struct KartAi *kartAi);
void ClearKartAiItemUse(KartAiItemUse *itemUse);
void UseItemBehindAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemForwardAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAndResetInUseTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAndResetHeldTimer(KartAiItemUse *itemUse, struct KartAi *kartAi);
void SetupRaceItemEntries(void);
void func_0207c8d8(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207c978(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterInUse(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseByTrailKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterInUseByCircleKind(KartAiItemUse *itemUse, struct KartAi *kartAi);
unsigned int func_0207cb70(unsigned int value);
void func_0207cb74(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *itemUse, struct KartAi *kartAi);
void RequestItemBitsByKartRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRank(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemByTargetOrRankAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207d3ec(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207d474(KartAiItemUse *itemUse, struct KartAi *kartAi);
void UseItemAfterHeld(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207d5b8(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0207d6a4(struct KartAiRaceSpeedLimit *raceSpeedLimit, struct KartAi *kartAi);
