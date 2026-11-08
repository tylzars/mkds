#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // GroupFollower

// The 0x40-byte record CreateMapObjectKindData builds; its first five arguments go to 0x00, 0x04, 0x18, 0x20, 0x1c.
typedef struct Unk0209bf70 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08[0x10];
    /* 18 */ void *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c[0xc];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bf70;

// Object of kinds 0x1a8, 0x1b4 and 0x1b5 (Bound, Cream, Berry); mWobbling is set while its scale wobbles.
typedef struct Bound {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mNsbtpFrameIndex;
    /* 0a2 */ u8 mUnk_0a2[2];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[0xc];
    /* 0b4 */ s32 mInitialScaleX;
    /* 0b8 */ u16 mWobbleXAngle;
    /* 0ba */ u8 mUnk_0ba[2];
    // Scale factor of x and z (1.12 fixed): mWobbleXMid plus mWobbleXAmplitude times the angle pair of mWobbleXAngle.
    /* 0bc */ s32 mWobbleScaleX;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ s32 mWobbleXMid;
    /* 0c8 */ s32 mWobbleXAmplitude;
    /* 0cc */ s32 mWobbleXAmplitudePerFrame;
    /* 0d0 */ s32 mWobbleXAnglePerFrame;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ u16 mWobbleYAngle;
    /* 0da */ u8 mUnk_0da[2];
    /* 0dc */ s32 mWobbleScaleY;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mWobbleYMid;
    /* 0e8 */ s32 mWobbleYAmplitude;
    /* 0ec */ s32 mWobbleYAmplitudePerFrame;
    /* 0f0 */ s32 mWobbleYAnglePerFrame;
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ GroupFollower mUnk_0f8;
    // TRUE while the scale wobbles; cleared when both amplitudes have reached 0.
    /* 11c */ BOOL mWobbling;
    // Per kart index: set to 0x1f after a push and counted down every frame; a push is only computed at 0.
    /* 120 */ s32 mKartTimers[8];
} Bound;

// Sun, kind 0x1ad: UpdateSun steps mState 0 to 4 and back; state 3 unparks a MAP_OBJECT_KIND_SUN_FIREBALL object twice per cycle.
typedef struct Sun {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u32 mUnk_0a0;
    /* 0a4 */ u16 mUnk_0a4;
    /* 0a6 */ u8 mUnk_0a6[2];
    /* 0a8 */ s32 mTimer;
    /* 0ac */ u32 mUnk_0ac;
    /* 0b0 */ u16 mUnk_0b0;
    /* 0b2 */ u16 mNsbcaFrameIndex;
    // 1.12 fixed: mNsbcaFrameIndex grows by this >> 12; rises to 0x8000 in state 3, falls to 0x1000 in the others.
    /* 0b4 */ s32 mNsbcaFrameIndexPerFrame;
    /* 0b8 */ GroupFollower mUnk_0b8;
    /* 0dc */ s32 mState;
} Sun;

extern const char gBerryNsbmdName[];
extern const char gCreamEffectNsbmdName[];
extern const char gCreamNsbmdName[];
extern const char gBoundNsbmdName[];
extern const char gBoundNsbtpName[];
extern const char gSunNsbmdName[];
extern const char gSunNsbcaName[];
extern const char gSunLODNsbmdName[];

void CreateBound(void *a);

// Declared here until the code that defines it is decompiled.

// The Sun object as DrawSun takes it: mState at 0xdc and mNsbcaFrameIndex at 0xb2.
typedef struct Unk0209d3fc {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u8 mUnk_a0[0xc];
    /* ac */ u32 mUnk_ac;
    /* b0 */ u16 mUnk_b0;
    /* b2 */ u16 mNsbcaFrameIndex;
    /* b4 */ u8 mUnk_b4[0x28];
    /* dc */ u32 mState;
} Unk0209d3fc;

extern u32 data_usa_021565d0;
extern u16 data_usa_021565d4;
extern const char data_usa_02167328[];

Unk0209bf70 *func_0209bf70(void *a, void *b, void *c, u32 d, u16 e, u16 f);
u32 CreateEmptyMapObjectKindData(void);
void *CreateMapObjectKindData(void *param_1, void *param_2, void *param_3, u32 param_4, u16 param_5);
BOOL StartBoundWobble(s32 a);
void CreateBoundUpdateList(void);
void CreateBerryDrawList(void);
void CreateCreamDrawList(void);
void CreateBoundDrawList(void);
void CreateBerryKindData(void);
void CreateCreamKindData(void);
void CreateBoundKindData(void);
void UpdateBoundAndCreamAndBerry(MapObjectList *a, Bound *p);
s32 func_0209c4bc(s32 a, s32 b);
s16 func_0209c4d8(s32 a);
void InitBoundAndCreamAndBerryObjects(MapObjectList *a);
void DrawBerry(MapObjectList *a, Bound *p);
void DrawCream(MapObjectList *a, Bound *p);
void CreateBerry(void *a); /* also loads cream_effect.nsbmd */
void CreateCream(void *a); /* also loads cream_effect.nsbmd */
void DrawBound(MapObjectList *a, Bound *p);
BOOL func_0209c8b0(Bound *p, Vec3 *a, s32 b, Vec3 *c);
u8 CollideItemObjectWithBound(Bound *p, void *a, u8 *b, u8 *c);
s32 CollideKartWithBound(Bound *p, Kart *k, u8 *b, u8 *c);
void InitBound(Bound *p);
void CreateSunUpdateList(void);
void CreateSunDrawList(void);
void UpdateSun(MapObjectList *a, Sun *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitSunObjects(MapObjectList *a);
void DrawSun(void *a, Unk0209d3fc *b);
