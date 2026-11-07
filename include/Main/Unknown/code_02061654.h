#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

extern u16 data_021653e8;
extern s16 data_021653ec;
extern Vec3 data_021653f0;

u32 func_02061654(void *a);
s32 func_02061678(void *a);
s32 func_0206169c(void *a);
BOOL func_020616c0(void *a, void *b);
BOOL func_02061704(void *a, TimeRecord *b);
BOOL func_0206174c(void *a);
u16 func_02061768(void);
s32 func_02061788(void);
// Returns TRUE and writes the number of update frames since SetRaceUpdateFramesAtEntryEnd to a, or returns FALSE when
// that has not run yet.
s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *a);
// Stores the current mUpdateFrames in Race.mUpdateFramesAtEntryEnd; called when the end handler of the kart of the
// selected entry first runs.
u32 SetRaceUpdateFramesAtEntryEnd(void);
u32 func_020617f0(void);
void *GetCurrentCamera(void);
unsigned int func_02061818(void);
MtxFx43 *func_0206182c(void);
unsigned int func_0206183c(void);
void func_0206184c(void);
void func_02061860(void);
void func_02061874(void);
void func_02061944(s32 a, s32 b);
void InitRaceFog(void);
// Returns Race.mUpdateFramesMod2; changes nothing.
unsigned int GetRaceUpdateFramesMod2(void);
// Returns Race.mUpdateFramesMod8; changes nothing.
unsigned int GetRaceUpdateFramesMod8(void);
// Returns Race.mUpdateFramesModKartCount; changes nothing.
unsigned int GetRaceUpdateFramesModKartCount(void);
unsigned int GetRaceUpdateFrames(void);
// Sets Race.mStarted to 1 and starts the race clock (StartRaceClock); called once per race by UpdateRaceStartSequence
// when its mSequenceFrames is 180.
void StartRace(void);
// Returns Race.mStarted (1 once the race has started); changes nothing.
unsigned int IsRaceStarted(void);
void func_02062000(void);
void func_02062004(void);
void func_02062078(void);
// Sets the direction of light 0 that func_02062078 gives to the 3D engine (Race.mLightVectorX, Y and Z) from a.
void SetRaceLightVector(const Vec3 *a);
void DrawRace(void);
void UpdateRace(void);
void func_02062860(void);
void func_020629a4(void);
void func_02062a0c(void);
void InitRace(void);
unsigned int func_02062eb0(void);
// Returns Race.mUseChainCameras: 1 for the kinds 3 to 5 of RaceSetup.mUnk_00c, which other code also uses to tell
// those kinds apart; changes nothing.
unsigned int GetRaceUseChainCameras(void);
