#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"

void StoreRaceProgressKartLapTime(RaceProgressKart *a, s32 b);
void AddLapTimes(const Unk0217aa1c_144_00 *a, const Unk0217aa1c_144_00 *b, Unk0217aa1c_144_00 *c);
// d is a sub-frame correction.
void ComputeRaceTime(u8 *a, u8 *b, u16 *c, s32 d, u32 e);
s16 FindKartCheckpointBackward(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f);
s16 FindKartCheckpointForward(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e, s32 f);
BOOL TryGetKartCheckpointProgress(RaceProgressKart *a, s32 *b, Vec3 *c, u16 d, u16 e);
s32 ComputeProgressBetweenCheckpoints(const Vec3 *a, u16 b, u16 c);
BOOL IsPointBetweenCheckpointLines(const Vec3 *a, const CourseMapCheckpoint *b, const CourseMapCheckpoint *c);
void UpdateRaceClock(void);
