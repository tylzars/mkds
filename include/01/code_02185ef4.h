#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object passed to the per-frame functions UpdateMissionGate and DrawMissionGate.
typedef struct MissionGateObject {
    /* 000 */ MapObject mMapObject;
    /* 0a0 */ MapObject *mNegativeSideObject;
    /* 0a4 */ MapObject *mPositiveSideObject;
    /* 0a8 */ u16 mNsbmaFrameIndex;
    /* 0aa */ u8 mUnk_0aa[0x2];
    /* 0ac */ s32 mState;
} MissionGateObject;

// Object whose flags and index CollideKartWithMissionGate reads.
typedef struct Unk02185d74 {
    /* 00 */ u8 mUnk_00[0x48];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x28];
    /* 74 */ u16 mUnk_74;
} Unk02185d74;

// Table of objects walked by InitMissionGateObjects.
typedef struct MissionGateList {
    /* 00 */ MissionGateObject **mObjects;
    /* 04 */ u16 mObjectCount;
} MissionGateList;

#include "01/code_0219b250.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ff9000.h"
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
#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_0209b000.h"

typedef struct Unk02185f04_1 {
    /* 00 */ u8 mUnk_00[0x50];
    /* 50 */ s32 mUnk_50;
    /* 54 */ u8 mUnk_54[0x4];
    /* 58 */ s32 mUnk_58;
} Unk02185f04_1;

typedef struct Unk02185fb0_1 {
    /* 00 */ u8 mUnk_00[0x80];
    /* 80 */ s32 mUnk_80;
    /* 84 */ u8 mUnk_84[0x4];
    /* 88 */ s32 mUnk_88;
} Unk02185fb0_1;

void InitMissionRunMapObject(void *mapObjectList, Unk02188950 *mapObject, const char *nsbmdName, const char *nsbcaName,
                             const char *prmName);
void func_ov001_021872e0(Unk02188950 *mapObject, int offsetX, int offsetY, int offsetZ, int emitterParamX,
                         int emitterParamY, int emitterParamZ, int effectId, u32 timer);

void StartEffectInSlot(Unk02188950 *mapObject, s32 effectIndex, s32 offsetX, s32 offsetY, s32 offsetZ, u32 effectId,
                       s32 timer);

#include "01/code_02188950.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_02187000.h"

void *CreateEmptyMapObjectUpdateList(void);
s32 CollideItemWithMissionRunMapObject(Unk02188950 *mapObject, Unk02185f04_1 *itemObject, u8 *c, u8 *d);
s32 CollideKartWithMissionRunMapObject(Unk02188950 *mapObject, Unk02185fb0_1 *kart, u8 *c, u8 *d);
s32 ComputeSphereHitOnMissionRunMapObject(Unk02188950 *mapObject, Vec3 *sphereCenter, s32 sphereRadius,
                                          Vec3 *overlapOffset);
void DrawMissionRunMapObjectShadow(void *mapObjectList, Unk02188950 *mapObject, s32 invertDepth);
void DrawMissionRunMapObject(void *mapObjectList, Unk02188950 *mapObject);
void AdvanceMissionRunMapObject(u32 a, Unk02188950 *mapObject);
u16 StepAngleSidewaysToPoint(Vec3 *targetPoint, Vec3 *origin, s32 signedMaxStep, s32 angleOffset, s32 angle);
u16 StepAngleTowardDirection(Vec3 *target, Vec3 *origin, s32 maxStep, s32 angle);
int StepIntTowardTarget(int target, int step, int current);
void ToggleShadowScale(void);
void LoadMissionRunMapObjectShadow(void *mapObjectList, Unk02188950 *mapObject, const char *shadowNsbmdName);
BOOL func_ov001_021871d0(Unk02188950 *mapObject);
u32 func_ov001_021871f8(Unk02188950 *mapObject, int b);
void DisableMissionRunMapObjectGravity(Unk02188950 *mapObject);
void func_ov001_02187218(Unk02188950 *mapObject, int b, s32 (*nextFunc)(Unk02188950 *));
void func_ov001_0218742c(Unk0206c1ac *a, const UnkVec16 *b);
void StartModelEffectAtWaterHeight(Unk02188950 *mapObject, u32 modelEffectKind, int timer);
void StartEffectAtWaterHeight(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer);
void StartEffectAtRowHeight(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer);
void StartEffectAtScaledOffset(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer);
void StartEffectAtOffset(Unk02188950 *mapObject, u32 offsetX, u32 offsetY, u32 offsetZ, u32 effectId, u32 timer);
void ComputeEffectPosition(Unk02188950 *mapObject, int effectIndex, Vec3 *position);
void ReleaseEffects(Unk02188950 *mapObject);
void ThrowItemKinokoFromPosition(void *kinoko, Vec3 *position, Vec3 *velocity, s32 timer);
void ThrowItemBombFromPosition(void *bomb, Vec3 *position, Vec3 *velocity, s32 timer);

#include "01/code_0219b540.h"
