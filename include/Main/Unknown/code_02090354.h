#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime
#include "Main/Unknown/code_02080b1c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Sman: a map object of kind 0x19d in two parts (top and bottom models); state 1 sends the top up and down while the
// bottom part's scale drops to 0, and later both parts come back.
typedef struct Sman {
    /* 00 */ MapObject mUnk_00;
    // The angle changes only while this is non-zero (states 0 and 3).
    /* a0 */ s32 mAngleZEnabled;
    /* a4 */ s32 mAngleZ;
    /* a8 */ s32 mAngleZPerFrame;
    // Counted in states 2 and 3 only.
    /* ac */ s32 mStateFrames;
    /* b0 */ s32 mTopRiseProgress;
    /* b4 */ s32 mBottomScale;
    /* b8 */ s32 mTopHeight;
    /* bc */ s32 mTopHeightPerFrame;
    /* c0 */ s32 mTopStartHeight;
    /* c4 */ s32 mTopLowHeight;
    // State of UpdateSman: 0 at rest, 1 top goes up and down, 2 waits, 3 both parts come back;
    // func_02091828 and func_020917d0 set 1.
    /* c8 */ s32 mState;
} Sman;

// Array of Sman pointers at 0x00, its count at 0x04.
typedef struct SmanList {
    /* 00 */ Sman **mSmans;
    /* 04 */ u16 mSmanCount;
} SmanList;

void SetupBattleItemEntries(void);
s32 func_020905a8(KartKillerCursor *a);
void TurnKartKillerTowardPointLink(KartKillerCursor *a);
void AdvanceKartKillerAlongPointLinks(KartKillerCursor *a);
s32 func_0209081c(KartKillerCursor *a);
void ResetKartKillerCursorTo(KartKillerCursor *a, Unk02080b1c_00 *b);
void SetupKartKillerCursor(KartKillerCursor *a, u32 b);
BOOL IsTimeLessThanStaffGhostTime(u32 a, void *b);
void LoadStaffGhostTime(void *a);
BOOL IsAllGrandPrixRecordsTopRank(void);
s32 func_020909cc(void);
u32 func_02090b24(void);
u32 func_02090cf8(void);
u32 func_02090ff4(void);
u32 func_0209119c(void);
u32 func_020911a8(void);
void *CreateSmanUpdateList(void);
void *CreateSmanBottomDrawList(void);
void *CreateSmanTopDrawList(void);
void CreateSmanKindData(void);
void UpdateSman(void *a, Sman *sman); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSmanObjects(SmanList *a);
void DrawSmanBottom(void *a, Sman *sman);
void SetupDrawSmanBottom(void *a);
void CreateSmanBottom(void *a);
void DrawSmanTop(void *a, Sman *sman);
void SetupDrawSmanTop(void *a);
void CreateSmanTop(void *a);
