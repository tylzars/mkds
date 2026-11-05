#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Camera Camera;

#include "Main/Unknown/unk_0217a000.h"

typedef struct Camera Camera;

// The 0x4c-byte entries of the table at CourseMap.mCameras: a position at 0x00, two vectors at 0x18 and 0x24 (look-at
// ends in some kinds, angles or a kart index in others), blend steps, a kind (mKind), a duration (mFrameCount), the
// next entry (mNextIndex).
typedef struct CourseMapCamera {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ u8 mUnk_30[0x2];
    /* 32 */ s16 mHalfFovPairFirst;
    /* 34 */ s16 mHalfFovPairSecond;
    /* 36 */ u8 mUnk_36[0x2];
    /* 38 */ s16 mHalfFovPairFirstEnd;
    /* 3a */ s16 mHalfFovPairSecondEnd;
    /* 3c */ s16 mFovBlendPerFrame;
    // Entry type: tested 0 .. 8 (4 = two-screen pair, 5 and 6 angle entries, 6 / 7 / 8 also picked by the loader for
    // CourseMap slots cc / d0 / d4).
    /* 3e */ u16 mKind;
    /* 40 */ u16 mEntryGroupIndex;
    // Added to the position curve's parameter each call (0x1000 = one segment); also copied into Unk02077750.mUnk_7c,
    // which nothing reads.
    /* 42 */ s16 mPosCurvePerFrame;
    /* 44 */ u16 mLookAtBlendPerFrame;
    // Frames the entry lasts (compared with mCourseMapCameraFrames); the battle step compares it with the race clock
    // instead.
    /* 46 */ u16 mFrameCount;
    /* 48 */ s16 mNextIndex;
    // 0 on most entries; 1 marks the entry where the first chain camera starts, 2 the entry where the second starts.
    // The loader keeps the first entry with each value (CourseMap.mFirstChainStartEntry, mSecondChainStartEntry).
    /* 4a */ u8 mChainStart;
    /* 4b */ u8 mShakeKind;
} CourseMapCamera;

#include "code_02012b30.h" // Unk02012f58

extern s32 data_usa_021656c4;
extern Unk0214ad4c data_usa_02170284;
extern Unk02012f58 data_usa_021702c8;
extern s32 data_usa_0217ac80;

void UpdateCameraWobble(Camera *p);
void func_02073f90(void);
void func_02073fb0(u32 a, s32 b);
void StartCameraWobble(s32 a, u32 b, s32 c);
void ResetCameraBehind(const Vec3 *a, void *b);
// Moves the chase camera position a toward the position goal behind the Kart: adds the Kart's movement of the last
// frame, eases to the goal (follow distance behind the direction f, plus the Kart and collision offsets and
// mPosGoalYOffset), keeps mHeldHeight while mHeightHold is set, then puts a at mFollowDistance times
// mFollowDistanceScale from e (the Kart position). With bit 0x1000 of the Kart's mUnk_48 set it only adds the Kart's
// movement times mKartMoveScale, and nothing at all while bit 0x4000000 of its mUnk_4c is also set.
void UpdateChaseCameraPos(Vec3 *a, Vec3 *b, Camera *c, Kart *d, Vec3 *e, const Vec3 *f, s32 g);
// Moves the chase camera look-at a toward the Kart position: x and z at once, y eased. b is the eased offset (mUnk_0b4
// of the Camera) and *c the lowering (mLookAtLowering): raised by 0x1000 per call up to 0xa000 while bit 0x10000 of the
// Kart's mUnk_48 is set, else decayed. Takes the three Camera members by pointer, not the Camera.
void UpdateChaseCameraLookAt(Vec3 *a, Vec3 *b, s32 *c, Kart *d, s32 e, s32 f);
void SetCameraHeightHold(s32 a);
void ResetCameraHalfFovAngle(void);
void ResetCameraHalfFovAngleGoal(void);
void SetCameraHalfFovAngleGoal(unsigned int p0);
Camera *func_02074888(void);
Camera *func_02074898(void);
// Returns the chase camera (gChaseCamera).
void *GetChaseCamera(void);
// Sets mLookAt between the entry's first point (mUnk_18) and second point (mUnk_24) by mLookAtBlend, which grows by the
// entry's mLookAtBlendPerFrame up to 0x1000; without a step it copies the first point.
void UpdateCameraLookAtBlend(Camera *p);
// Entry kind 3: moves mPos along the entry's curve (UpdateCameraPosCurve), blends mLookAt (UpdateCameraLookAtBlend),
// then updates the view with world up (UpdateCameraViewWithWorldUp).
void UpdateCameraPosCurveLookAtBlend(Camera *p);
// Moves mPos along the points of the entry's group by a (0x1000 = one segment): four or more points run the curve
// mPosCurve, two or three a straight line from the first to the second point, fewer than two do nothing.
void UpdateCameraPosCurve(Camera *p, s32 a);
void func_02074b00(Camera *p);
// Entry kinds 5 and 6 (the angle entries of CourseMapCamera.mKind): puts the Camera around the followed Kart from the
// entry's angles (mUnk_18.x, mUnk_18.y, mUnk_24.x, mUnk_24.y: degrees converted to 0x10000 per turn) and distance
// (mUnk_18.z), lowers the position and look-at by the Kart's mUnk_2bc, pushes mPos out of walls except in modes 2 and 4
// of data_021759c0->mMode, then updates the view.
void UpdateCameraAngleEntry(Camera *p);
// Entry kind 1: moves mPos along the entry's curve (UpdateCameraPosCurve), points mLookAt at the followed Kart (raised
// by 0x6000; when data_021759c0->mUnk_00c is 5 the Kart comes from the entry's mUnk_24.z and the raise from its
// mUnk_18.y) and updates the view.
void UpdateCameraPosCurveLookAtKart(Camera *p);
// Does nothing while mCourseMapCamera is NULL. Otherwise runs the entry (UpdateCameraByEntryKind), counts
// mCourseMapCameraFrames and, when it reaches the entry's mFrameCount, starts the entry at mNextIndex (sets
// gRaceProgress->mUnk_4d0 when there is none). For gFirstChainCamera with mFrustumShift 1 it also starts the next entry
// of gSecondChainCamera. UpdateRace reaches it once a frame, only while gRace->mUnk_28 is non-zero.
void UpdateCameraEntry(Camera *p);
// Steps gFirstChainCamera (UpdateCameraEntry), updates its view, stores it in gCurrentChainCamera and returns its view
// matrix. UpdateRace calls it when data_021759c0->mUnk_00c is 4.
Unk02012f58 *UpdateFirstChainCamera(void);
// Sets mFrustumShift of the two chain cameras (1 and 2 while the second's entry is of kind 4, else 0) and steps the
// first. Then it copies the first's field of view pair, mPos and mLookAt into the second (shift 2) or steps the second.
// It updates the view of the first on even frames and of the second on odd frames, stores that camera in
// gCurrentChainCamera and returns its view matrix. UpdateRace calls it when data_021759c0->mUnk_00c is 3 or 5.
Unk02012f58 *UpdateChainCameraPair(void);
// As StartEntryCameraKind6Entry for CourseMap.mFirstKind8EntryInMode4, setting mKind8EntryRunning.
void StartEntryCameraKind8Entry(void);
// Runs the Camera's current entry by its mKind: 0 puts the camera at the entry position and looks at the followed Kart,
// 1 UpdateCameraPosCurveLookAtKart, 2 puts the camera at the entry position with a blended look-at
// (UpdateCameraLookAtBlend), 3 UpdateCameraPosCurveLookAtBlend, 5 and 6 UpdateCameraAngleEntry; kinds 4, 7 and 8 have
// no case. Then sets the field of view pair: blended toward the entry's end pair by mFovBlend when the entry has an
// mFovBlendPerFrame, else copied from the entry.
void UpdateCameraByEntryKind(Camera *p);
// Steps the Camera through CourseMapCamera entries and returns whether it is the camera in use this frame (UpdateRace
// then shows it, else the chase camera). With data_021759c0->mUnk_00c equal to 6 it runs func_02074b00 and returns
// TRUE. Returns FALSE while mEntryUpdateHold or mEntryUpdateDisabled is set, and when no CourseMapShape of mKind 1
// contains the followed Kart's position (func_020411e4 finds none); mPrevPos and gEntryCameraUpdateRan are written
// before either. Otherwise it starts the entry that shape names when it differs from the last one, runs it and returns
// TRUE. UpdateRace calls it only while gRace->mUnk_28 is 0 and func_0203c5e4() is non-zero.
BOOL TryUpdateEntryCamera(Camera *p);
u32 func_02075cf0(void);
void func_02075d08(s32 a);
// Does nothing when CourseMap.mFirstKind6Entry is NULL. Otherwise sets mKind6EntryRunning and makes that entry the
// current entry of gEntryCamera (fresh mFovBlend, field of view pair and mShakeKind), sets up its mPosCurve (and
// mUnk_1d0 in mode 2), advances the local random once when the entry Kart has ended and sets gCameraEntryChanged.
void StartEntryCameraKind6Entry(void);
// Eases mPosGoalYOffset toward 0 or, while bit 0x10 of the Kart's mUnk_44 or bit 0x10000 of its mUnk_48 is set, toward
// a multiple of the y of c (the Kart's forward vector times mFollowDirectionSign); while bit 0x40000000 of mUnk_48 is
// set it eases toward 0 at once.
void UpdateChaseCameraPosGoalYOffset(Camera *a, Kart *b, Vec3 *c);
// Tests the camera's path from mPrevPos to mPos against the course collision. On a hit it sets mPosGoalCollisionOffset
// and mCollisionOffsetLengthGoal or moves mPos out directly; it always eases mCollisionOffsetLength toward its goal.
// Also sets mUnk_254, mUnk_258 and mUnk_25c and clears data_usa_0217ac80.
void UpdateChaseCameraCollision(Camera *a, Kart *b, Vec3 *c);
// One frame of the chase camera (gChaseCamera) following Kart b: eases the field of view, the look-at, the position
// goal and the position toward the Kart, then runs the collision test and the wobble. With bit 0x20 of the Kart's
// mUnk_7c set it only updates mViewPosYOffset, and only while water is present. UpdateRace does not call it while
// gRace->mUnk_28 is non-zero.
void UpdateChaseCamera(Camera *a, Kart *b);
void SetupCameraBehindKart(void);
void func_02076bcc(Camera *a);
void func_02076c50(Camera *a, s32 b);
Unk02012f58 *func_02076cc4(void);
