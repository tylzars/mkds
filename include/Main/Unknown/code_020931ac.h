#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // GroupFollower
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Object of kind 0x1a4 (MkdEfBurner); Unk02093708 is a view of the draw group record (word +0x1c), not of this
// object. After the shared part, a counter at 0xa0, a halfword at 0xa4, a value at 0xa8, a
// state at 0xac, a GroupFollower at 0xb0 and a table of countdowns at 0xd4.
typedef struct MkdEfBurner {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u16 mUnk_a4;
    /* a6 */ u8 mUnk_a6[2];
    /* a8 */ s32 mUnk_a8;
    /* State number of this kind's own per-frame switch in UpdateMkdEfBurner; this object does not use
       MapObject.mUnk_80's state machine; state 4 only from the group pre-step */
    /* ac */ u32 mState;
    /* b0 */ GroupFollower mUnk_b0;
    /* d4 */ s32 mUnk_d4[8];
} MkdEfBurner;

// Object of CreateMkdEfBurner: a word at 0x1c.
typedef struct Unk02093708 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk02093708;

#include "Main/Unknown/unk_0217b000.h" // Unk0217b498_00

u16 func_020931ac(Unk0217b498_00 *a);
void CreateMkdEfBurnerUpdateList(void);
void CreateMkdEfBurnerDrawList(void);
void CreateMkdEfBurnerKindData(void);
void UpdateMkdEfBurner(void *a, MkdEfBurner *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitMkdEfBurnerObjects(MapObjectList *p);
void DrawMkdEfBurner(void *a, MkdEfBurner *p);
void SetupDrawMkdEfBurner(void *a);
void CreateMkdEfBurner(Unk02093708 *p); /* also sets word +0x1c of the group record to 1 */
u8 CollideKartWithMkdEfBurner(MkdEfBurner *a, Kart *b, u8 *c, u8 *d);
void InitMkdEfBurner(MapObject *arg0); /* allocates the object's sound source (CreateMapObjectSoundSourceFalloff2) */
