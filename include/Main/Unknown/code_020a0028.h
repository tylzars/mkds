#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // Unk020e0144
#include "Main/Unknown/code_020f9c6c.h" // CourseMapRow

// Object of kind 0x158 (Airship) with the Unk020e0144 base at 0xc8 (DrawAirship, InitAirshipObjects).
typedef struct Airship {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s16 mUnk_a8;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ u32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ Unk020e0144 mUnk_c8;
    /* State number of this kind's own per-frame switch in UpdateAirship; this object does not use
       MapObject.mUnk_80's state machine; also written by the group pre-step */
    /* ec */ s32 mState;
} Airship;

// Array of object pointers: pointer to the array and the number of entries (InitAirshipObjects).
typedef struct Unk020a0064 {
    /* 00 */ Airship **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020a0064;

void CreateAirship(void *a);
void DrawAirship(void *a, Airship *p);
void InitAirshipObjects(Unk020a0064 *p);
s32 func_020a0044(s32 a);
s32 func_020a0028(s32 a, s32 b);
