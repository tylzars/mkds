#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base at 0x00 (func_020a0318, func_020a066c, func_020a089c).
typedef struct Unk020a0318 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mDistanceVolumeFixed12;
    // Radius in whole units; the inner half-radius test uses w / 2 without the << 12.
    /* a8 */ s32 mRadius;
    /* ac */ s32 mCenterX;
    /* b0 */ s32 mCenterY;
    /* b4 */ s32 mCenterZ;
    /* b8 */ BOOL mDistanceLevelInverted;
    /* bc */ u16 mSoundId;
    /* be */ u16 mSecondSoundId;
    /* c0 */ s32 mDistanceLevelTimer;
    /* c4 */ s32 mDistanceLevel;
    /* c8 */ s32 mSoundTimer;
} Unk020a0318;

// Array of object pointers: pointer to the array and the number of entries (func_020a066c).
typedef struct Unk020a066c {
    /* 00 */ Unk020a0318 **mMapObjects;
    /* 04 */ u16 mMapObjectCount;
} Unk020a066c;

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
#include "Main/Unknown/code_020b502c.h" // CourseMapPoint

void *func_020a02f8(void);
void func_020a0318(void *mapObjectList, Unk020a0318 *mapObject);
void func_020a066c(MapObjectList *mapObjectList);
void func_020a089c(Unk020a0318 *mapObject);
// Steps Standings once per UpdateRace call in battle and mission run: the end timer and end callback, the hand- over of
// eliminated karts, the hit tracking, and the copy of each kart's position.
void UpdateStandings(void);
// Ends the Standings end timer (mEndTimer = -1) and runs mEndCallback when it is set; the mode 4 end step of the race
// progress calls it.
void FinishStandings(void);
void InitStandings(void);
CourseMapPoint *MoveToRandomForwardBattlePoint(void);
Vec3 *GetKartStandingPos(int kartIndex);
void CallKartHitCallbackForSelf(u16 kartIndex);
void SetWinnerIfOneTeamLeft(void);
void EliminateKart(u16 kartIndex);
void MoveKartTowardLastRank(u16 kartIndex);
void MoveKartTowardFirstRank(u16 kartIndex);
u16 GetBattleItemRank(s32 kartIndex);
void func_020a1ddc(s32 kartIndex);
unsigned int func_020a1e3c(unsigned int value);
