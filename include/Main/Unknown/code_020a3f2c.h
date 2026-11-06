#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

// Object returned by func_0209bfa8: the words at 0x38 and 0x3c are set by func_020a5918.
typedef struct Unk0209bfa8 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0209bfa8;

#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of kind 0x6a (Shine16), also typed Unk020888b4_d0 (code_020888b4.c) and MapObject (code_020a3f2c.c) where the
// pool list is walked. Object reached through func_02100138(0x6a), set up by func_020a5744 and updated by
// UpdateShine16: the shared MapObject part, then words up to 0xe8. UpdateShine16 switches on the word at 0xe0 (0 to 6).
typedef struct Shine16 {
    /* 00 */ MapObject mUnk_00;
    // Height of the shine above the followed kart's position: 0 at spawn and pickup, then grows by the shine's vertical
    // speed each frame.
    /* a0 */ s32 mHeightAboveKart;
    // y at which a falling shine bounces (the spawn point's y + 0x14000); 0 for a shine that starts resting. Only the
    // fall state reads it.
    /* a4 */ s32 mFloorY;
    /* a8 */ s32 mUnk_a8;
    /* ac */ u8 mUnk_ac[4];
    // Frame index of the shine's .nsbtp animation, stepped every few frames and wrapped at the animation's frame count;
    // the draw passes it to the frame setter.
    /* b0 */ s32 mNsbtpFrameIndex;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    // Set to 0x19 when a kart takes the shine (a second pickup is refused while it is above 0), counted down while the
    // shine follows the kart; at 0 the shine shrinks away. 0 at spawn.
    /* c0 */ s32 mPickupTimer;
    /* c4 */ s32 mUnk_c4;
    // Index of the kart the shine follows in states 2 and 3: the kart that took it, or the kart it was released from.
    /* c8 */ u16 mKartIndex;
    /* ca */ u16 mUnk_ca;
    /* cc */ Vec3 mUnk_cc;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* State number of this kind's own per-frame switch in UpdateShine16; this object does not use
       MapObject.mUnk_80's state machine; also read in the second draw callback func_020a683c */
    /* e0 */ s32 mState;
    /* e4 */ void *mUnk_e4;
    /* e8 */ s32 mUnk_e8;
} Shine16;

#include "Main/Unknown/code_020a3fa8.h" // Unk020a3fa8

void *func_020a3f2c(void);
u32 func_020a3f48(void);
void InitKartBalloons(Unk020a3fa8 *a);
void func_020a4b70(u16 a, Vec3 *b);
void func_020a4c20(void);
void func_020a4c58(u16 a);
BOOL func_020a4d94(u16 a, u16 b);
s32 func_020a4f54(u16 a, u16 b);
BOOL func_020a5268(u16 a, u16 b);
void func_020a5608(Kart *a, Kart *b);
void func_020a5744(Vec3 *a, s32 b, s32 c);
void ParkShine16Objects(void);
void *func_020a58b4(void);
void *func_020a58d0(void);
void *func_020a58f4(void);
void func_020a5918(void);
void UpdateShine16(void *a, Shine16 *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
