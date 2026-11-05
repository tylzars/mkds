#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct Camera Camera;

#include "Main/Unknown/unk_0217a000.h"

typedef struct Camera Camera;

// The 0x4c-byte entries of the table at CourseMap::mUnk_7c: a position at 0x00, two vectors at 0x18 and 0x24 (look-at
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
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mShakeKind;
} CourseMapCamera;

#include "code_02012b30.h" // Unk02012f58

extern s32 data_usa_021656c0;
extern s32 data_usa_021656c4;
extern Unk0214ad4c data_usa_02170284;
extern Unk02012f58 data_usa_021702c8;
extern s32 data_usa_0217ac80;
extern s32 data_usa_0217ac90;

void UpdateCameraWobble(Camera *p);
void func_02073f90(void);
void func_02073fb0(u32 a, s32 b);
void StartCameraWobble(s32 a, u32 b, s32 c);
void ResetCameraBehind(const Vec3 *a, void *b);
void func_020741a0(Vec3 *a, Vec3 *b, Camera *c, Kart *d, Vec3 *e, const Vec3 *f, s32 g);
void func_020745d4(Vec3 *a, Vec3 *b, s32 *c, Kart *d, s32 e, s32 f);
void SetCameraHeightHold(s32 a);
void ResetCameraHalfFovAngle(void);
void ResetCameraHalfFovAngleGoal(void);
void SetCameraHalfFovAngleGoal(unsigned int p0);
Camera *func_02074888(void);
Camera *func_02074898(void);
void *func_020748a8(void);
void func_020748b8(Camera *p);
void func_02074978(Camera *p);
void func_020749a4(Camera *p, s32 a);
void func_02074b00(Camera *p);
void func_02074e6c(Camera *p);
void func_02075390(Camera *p);
void func_02075424(Camera *p);
Unk02012f58 *func_0207564c(void);
Unk02012f58 *func_02075694(void);
void func_020757d8(void);
void func_02075900(Camera *p);
BOOL func_02075a94(Camera *p);
u32 func_02075cf0(void);
void func_02075d08(s32 a);
void func_02075eb8(void);
void func_02075fe0(Camera *a, Kart *b, Vec3 *c);
void func_020760ec(Camera *a, Kart *b, Vec3 *c);
void func_02076528(Camera *a, Kart *b);
void SetupCameraBehindKart(void);
void func_02076bcc(Camera *a);
void func_02076c50(Camera *a, s32 b);
Unk02012f58 *func_02076cc4(void);
void SetupCamera(Camera *p);
