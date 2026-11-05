#pragma once

#include "types.h"

typedef struct Kart Kart;

typedef struct Kart Kart;

typedef struct Kart Kart;
typedef struct Unk02175620_bc Unk02175620_bc;

#include "Main/Unknown/code_0206bcb0.h"

// Declared here until the code that defines them is decompiled.
BOOL func_02070398(Kart *p, u32 b, void *c);
void func_02070484(Kart *p, Vec4 *q);
void func_020705fc(Kart *p, u32 b);
void func_020708a4(Kart *p);
void func_02070f8c(Kart *p);
void func_020710b0(Kart *p, s32 b);
void func_02071318(Kart *p, s32 a);
void func_020713a0(Kart *p);
void func_02071568(Kart *p);
void func_02071788(Kart *p);
void func_02071894(Kart *p);
void func_02071914(void *p, int a);
void func_02071958(Kart *p, s32 b);
void func_02071980(void *p, int b);
void func_020719a8(u32 arg0, u32 arg1);
PlayingSound *func_020719bc(SoundSource *p, u32 a);
void func_020719d0(Kart *p);
void func_02071c18(Kart *p);
void func_02071ddc(Unk0206ceb4 *p0);
void func_02071e28(Kart *p);
void func_02071f44(Kart *p);
void func_02071fb8(Kart *p, void *a);
void ResetKart(Kart *p);
void func_02072600(Kart *p);
void func_020726bc(Kart *p);
// Slot 7 of Kart.mSlotFunctions, never called: when bit 0x20 of mUnk_7c is set, resets the Kart at its course start
// placement, creates its collision objects if it has none and sets bit 0x80 of mUnk_7c while clearing 0x60.
void ResetKartToStartPlacement(Kart *p);
void func_02072930(Kart *p);
void ResetKartAndSetPos(Kart *p, const Vec3 *a, const Vec3 *b, Unk02175620_bc *c);
s32 func_02072d84(Kart *p, s32 *a);
// Slot 6 of Kart.mSlotFunctions: puts the Kart back on the course at the respawn place of Kart.mRespawnSlot (chosen
// first when -1; in battle the course hands out its next respawn slot), starts the respawn effect and counts the
// respawn of the selected entry's Kart.
void ResetKartToRespawnPoint(Kart *p);
void func_020732d8(Kart *p);
// Declared here until the code that defines them is decompiled.
