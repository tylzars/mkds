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

struct Unk02089a24;
struct KartAi;

extern KartAiItemUseEntry data_usa_0215524c[];
extern KartAiItemUseEntry data_usa_021552f4[];
extern KartAiItemUseEntry data_usa_021553cc[];
extern KartAiItemUseEntry data_usa_021554a4[];

// Writes to a the point of the curve b at parameter mParam (0 to 0x1000): the four control points of mPoints weighted
// by the uniform cubic B-spline basis.
void ComputePosCurvePoint(Vec3 *a, PosCurve *b);
// Adds d to the curve parameter (0x1000 = one segment); past 0x1000 it shifts the four control points on to the next
// point of the entry's group (clamped after the last) and writes the point on the curve to a. UpdateCameraPosCurve
// calls it for groups of four or more points.
void UpdatePosCurve(Vec3 *a, PosCurve *b, struct CourseMapCamera *c, s32 d);
void func_0207bd6c(PosCurve *a, struct CourseMapCamera *b);
// Restarts the curve a on the entry b: clears its parameter and counters and, when the entry's group has four or more
// points, loads the first four as its control points (nothing is loaded for fewer).
void SetupPosCurve(PosCurve *a, struct CourseMapCamera *b);
void SetupItemInUseEntry(struct KartAiItemUse *a, struct KartAi *b);
s32 DecrementItemInUseTimer(struct KartAiItemUse *a);
void ResetItemInUseTimer(struct KartAiItemUse *a, struct KartAiItemUseEntry *b);
s32 DecrementHeldItemTimer(struct KartAiItemUse *a);
void ResetHeldItemTimer(struct KartAiItemUse *a);
void SetupHeldItemEntry(struct KartAiItemUse *a, struct KartAi *b);
void func_0207c270(struct KartAiItemUse *a, struct KartAi *b);
void AdvanceItemBitRequests(struct KartAiItemUse *a, struct KartAi *b);
void func_0207c448(KartAiItemUse *p0);
void UseItemBehindAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b);
void UseItemForwardAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b);
void UseItemAndResetInUseTimer(KartAiItemUse *a, struct KartAi *b);
void UseItemAndResetHeldTimer(KartAiItemUse *a, struct KartAi *b);
void func_0207c78c(void);
void func_0207c8d8(KartAiItemUse *a, struct KartAi *b);
void func_0207c978(KartAiItemUse *a, struct KartAi *b);
void UseItemByRankAfterInUse(KartAiItemUse *a, struct KartAi *b);
void UseItemByTargetOrRankAfterInUse(KartAiItemUse *a, struct KartAi *b);
void func_0207caa8(KartAiItemUse *a, struct KartAi *b);
void func_0207cb0c(KartAiItemUse *a, struct KartAi *b);
unsigned int func_0207cb70(unsigned int p0);
void func_0207cb74(KartAiItemUse *a, struct KartAi *b);
void UseItemAfterHeldIfTurnUnder20(KartAiItemUse *a, struct KartAi *b);
void RequestItemBitsByKartRank(KartAiItemUse *a, struct KartAi *b);
void UseItemByTargetOrRank(KartAiItemUse *a, struct KartAi *b);
void UseItemByRankAfterHeld(KartAiItemUse *a, struct KartAi *b);
void UseItemByTargetOrRankAfterHeld(KartAiItemUse *a, struct KartAi *b);
void func_0207d3ec(KartAiItemUse *a, struct KartAi *b);
void func_0207d474(KartAiItemUse *a, struct KartAi *b);
void UseItemAfterHeld(KartAiItemUse *a, struct KartAi *b);
void func_0207d5b8(KartAiItemUse *a, struct KartAi *b);
void func_0207d6a4(struct Unk02089a24 *a, struct KartAi *b);
