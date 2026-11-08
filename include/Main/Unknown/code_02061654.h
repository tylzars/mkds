#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

extern u16 data_021653e8;
extern s16 data_021653ec;
extern Vec3 data_021653f0;

u32 GetGhostRecordCourseId(void *ghostRecord);
s32 GetGhostRecordKartIndex(void *ghostRecord);
s32 GetGhostRecordCharacterIndex(void *ghostRecord);
BOOL GetGhostRecordName(void *ghostRecord, void *name);
BOOL GetGhostRecordTime(void *ghostRecord, TimeRecord *timeRecord);
BOOL IsGhostRecordFilled(void *ghostRecord);
u16 GetSplMaxPolyId(void);
s32 GetMapObjectFirstPolygonId(void);
// Returns TRUE and writes the number of update frames since SetRaceUpdateFramesAtEntryEnd to a, or returns FALSE when
// that has not run yet.
s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *framesOut);
// Stores the current mUpdateFrames in Race.mUpdateFramesAtEntryEnd; called when the end handler of the kart of the
// selected entry first runs.
u32 SetRaceUpdateFramesAtEntryEnd(void);
u32 SetRaceUpdateFramesUnlimited(void);
void *GetCurrentCamera(void);
unsigned int GetCurrentCameraKind(void);
MtxFx43 *GetCurrentViewMatrix(void);
unsigned int IsFadeFogActive(void);
void SetFadeFogHoldFramesToLimit(void);
void ClearFadeFogHoldFrames(void);
void StartFadeFog(void);
void BuildFadeFog(s32 fadeLevel, s32 b);
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
void DrawRaceWorld(void);
// Sets the direction of light 0 that DrawRaceWorld gives to the 3D engine (Race.mLightVectorX, Y and Z) from a.
void SetRaceLightVector(const Vec3 *lightVector);
void DrawRace(void);
void UpdateRace(void);
void Init3dEngine(void);
void func_020629a4(void);
void InitRaceFields(void);
void InitRace(void);
unsigned int IsRaceAwardOrStaffRoll(void);
// Returns Race.mUseChainCameras: 1 for the kinds 3 to 5 of RaceSetup.mUnk_00c, which other code also uses to tell
// those kinds apart; changes nothing.
unsigned int GetRaceUseChainCameras(void);
