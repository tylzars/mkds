#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

// Object of StartNsKiller2: after the shared part, a counter at 0xa0 and a word at 0xa4. A prefix view of the
// kind 0x1a2 (NsKiller2) pool objects.
typedef struct Unk020937c4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
} Unk020937c4;

// Object of kind 0x1a2 (NsKiller2), pool objects: after the shared part, a counter at 0xa0, a state at 0xa4 and an
// object at 0xa8.
typedef struct NsKiller2 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ SoundDistanceSquaredChange *mUnk_a8;
} NsKiller2;

// Object of kind 0x1a1 (NsKiller1), creates 20 NsKiller2 in its Init: after the shared part, a counter at 0xa0, a state
// at 0xa8 and an Unk020e0144 at 0xac.
typedef struct NsKiller1 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ u8 mUnk_a4[4];
    /* State number of this kind's own per-frame switch in UpdateNsKiller1; this object does not use
       MapObject.mUnk_80's state machine */
    /* a8 */ s32 mState;
    /* ac */ Unk020e0144 mUnk_ac;
} NsKiller1;

void StartNsKiller2(Vec3 *a, Vec3 *b, u16 c);
void func_02093884(void);
void func_020938a0(void);
void func_020938c0(void);
void UpdateNsKiller2(void *a, NsKiller2 *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawNsKiller2(void *a, NsKiller2 *p);
void CreateNsKiller2AndNsKiller2S(void *a);
u8 func_02093b7c(NsKiller2 *a, Kart *b, u8 *c, u8 *d);
/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitNsKiller2(NsKiller2 *p);
void func_02093cb4(void);
void func_02093cd4(void);
void UpdateNsKiller1(void *a, NsKiller1 *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitNsKiller1Objects(MapObjectList *p);
void DrawNsKiller1(void *a, NsKiller1 *p);
void CreateNsKiller1(void *a);
