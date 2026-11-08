#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

#include "code_020184e4.h"

extern Vec3 data_usa_021660fc;
extern char gRaceEffectSpaName[];
extern char gRaceEffectFogOffSpaName[];
extern char gMissionEffectSpaName[];

u32 func_0208b484(u32 outIndex, u32 effectId);
void *StartEffectWithKartVelocity(u32 effectId, Vec3 *position, u32 kartIndex, s32 velocityScale);
void PlaceEffect(void *emitter, const Vec3 *position);
Unk0201ca6c *func_0208b60c(s32 resourceId, Vec3 *position);
void func_0208b6b0(void **emitterSlot);
void DeleteEffectAndClearPointer(Unk0201ca6c **emitterSlot);
void DeleteEffect(Unk0201ca6c *emitter);
// Starts effect a at the position b and returns the effect object (NULL when none is made).
void *StartEffect(u32 effectId, const Vec3 *position);
void DrawEffects(MtxFx43 *viewMatrix);
void UpdateEffects(void);
void InitEffects(void *defaultHeap);
u32 HeapAllocForSPLManager(u32 size);
