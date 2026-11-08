#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct Kart Kart;

typedef struct Kart Kart;
typedef struct PointLink PointLink;

#include "Main/Unknown/code_0206bcb0.h"

// Declared here until the code that defines them is decompiled.
BOOL TryHoldKartStill(Kart *kart, u32 b, void *c);
void func_02070484(Kart *kart, Vec4 *quaternion);
void PlaceKartAtKeyedPlacement(Kart *kart, u32 key);
void AdvanceKartToKeyedPlacement(Kart *kart);
void func_02070f8c(Kart *kart);
void ResetKartMotionState(Kart *kart, s32 b);
void StartKartModelScaleAnimation(Kart *kart, s32 a);
void AdvanceKartHeadingSwing(Kart *kart);
void func_02071568(Kart *kart);
void AdvanceKartModelScaleAnimation(Kart *kart);
void func_02071894(Kart *kart);
void func_02071914(void *kart, int soundId);
void func_02071958(Kart *kart, s32 entryIndex);
void func_02071980(void *kart, int entryIndex);
void func_020719a8(u32 soundSource, u32 soundId);
PlayingSound *func_020719bc(SoundSource *soundSource, u32 soundId);
void func_020719d0(Kart *kart);
void InitKartSound(Kart *kart);
void func_02071ddc(KartItemEffectState *itemEffectState);
void func_02071e28(Kart *kart);
void func_02071f44(Kart *kart);
void func_02071fb8(Kart *kart, void *heap);
void ResetKart(Kart *kart);
void func_02072600(Kart *kart);
void InitKartPhysicalParams(Kart *kart);
// Slot 7 of Kart.mSlotFunctions, never called: when bit 0x20 of mUnk_7c is set, resets the Kart at its course start
// placement, creates its collision objects if it has none and sets bit 0x80 of mUnk_7c while clearing 0x60.
void ResetKartToStartPlacement(Kart *kart);
void func_02072930(Kart *kart);
void ResetKartAndSetPos(Kart *kart, const Vec3 *position, const Vec3 *forward, PointLink *link);
s32 AdvanceKartRespawnWait(Kart *kart, s32 *a);
// Slot 6 of Kart.mSlotFunctions: puts the Kart back on the course at the respawn place of Kart.mRespawnSlot (chosen
// first when -1; in battle the course hands out its next respawn slot), starts the respawn effect and counts the
// respawn of the selected entry's Kart.
void ResetKartToRespawnPoint(Kart *kart);
void AdvanceKartScaleFactor(Kart *kart);
// Declared here until the code that defines them is decompiled.
