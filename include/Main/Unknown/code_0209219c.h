#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of kind 0x19f (Basabasa), 0xd8 bytes: the MapObject it starts with, a vector at 0xa0 and words and halfwords
// up to 0xd4.
typedef struct Basabasa {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ Vec3 mUnk_a0;
    /* ac */ u16 mUnk_ac;
    /* ae */ u8 mUnk_ae[2];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ u16 mUnk_c0;
    /* c2 */ u8 mUnk_c2[2];
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ u8 mUnk_d0;
    /* d1 */ u8 mUnk_d1[3];
    /* State number of this kind's own per-frame switch in UpdateBasabasa; this object does not use
       MapObject.mUnk_80's state machine */
    /* d4 */ s32 mState;
} Basabasa;

typedef struct Basabasa Basabasa;

// Object func_0209297c reads: a halfword at 0x74 and a vector at 0x80.
typedef struct Unk0209297c {
    /* 00 */ u8 mUnk_00[0x74];
    /* 74 */ u16 mUnk_74;
    /* 76 */ u8 mUnk_76[10];
    /* 80 */ Vec3 mUnk_80;
} Unk0209297c;

void CreateBasabasa(void *a);

void StartBasabasa(u32 a, const Vec3 *b, const Vec3 *c, u32 d, s32 e, u16 f);
void CreateBasabasaUpdateList(void);
void CreateBasabasaDrawList(void);
void CreateBasabasaKindData(void);
void UpdateBasabasa(void *a, Basabasa *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBasabasa(void *a, Basabasa *b);
void SetupDrawBasabasa(void *a);
u8 func_0209297c(Basabasa *a, Unk0209297c *b, void *c, u8 *d);
/* creates the pooled object hidden (parks it with ParkMapObject); the spawner later takes it with
 * UnparkFirstParkedMapObject */
void InitBasabasa(MapObject *arg0);
