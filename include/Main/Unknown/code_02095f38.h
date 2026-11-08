#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

typedef struct ItemObject ItemObject;

// Object up to 0x109 bytes.
typedef struct CoverPooHole {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mTimer;
    /* b0 */ s32 mState;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ u16 mUnk_c4;
    /* c6 */ u8 mUnk_c6[2];
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ u16 mUnk_e4;
    /* e6 */ u8 mUnk_e6[2];
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u8 mUnk_108;
} CoverPooHole;

#include "Main/Unknown/unk_0217b000.h" // Unk0217b498_00
#include "Main/Unknown/code_0206bcb0.h" // Kart

BOOL func_02095f38(Unk0217b498_00 *a);
void *CreateCoverPooHoleUpdateList(void);
void *CreateCoverPooHoleDrawList(void);
void CreateCoverPooHoleKindData(void);
void UpdateCoverPooHole(void *a,
                        CoverPooHole *coverPooHole); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 func_020968c0(s32 a, s32 b);
s32 func_020968dc(s32 a);
void InitCoverPooHoleObjects(MapObjectList *mapObjectList);
void DrawCoverPooHole(void *a, CoverPooHole *coverPooHole);
void CreateCoverPooHole(void *a);
BOOL TryGetCoverPooHolePushOut(CoverPooHole *coverPooHole, const Vec3 *position, s32 radius, Vec3 *pushOut);
u32 CollideItemObjectWithCoverPooHole(CoverPooHole *coverPooHole, ItemObject *a, u8 *b, u8 *c);
u32 CollideKartWithCoverPooHole(CoverPooHole *coverPooHole, Kart *kart, u8 *b, u8 *c);
void InitCoverPooHole(MapObject *mapObject);
u32 func_0209753c(u32 a);
