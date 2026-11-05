#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // Unk020e0144

// 0x48-byte entries from 0xb0 of Sanbo; func_020a8098 writes the first mUnk_1d0 of them.
typedef struct Unk020a7f18_0b0 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u8 mUnk_1e[2];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
} Unk020a7f18_0b0;

// Object of kind 0x1b2 (Sanbo: sanbo_h and sanbo_b models in one object). Object passed to func_020a7f18 and
// func_020a7fc4 as their first argument and on to func_020a8098: the shared MapObject part, words at 0xa0 to 0xac, four
// 0x48-byte entries with their count at 0x1d0, a word at 0x1d4, an Unk020e0144 at 0x1d8 and a word at 0x1fc.
typedef struct Sanbo {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ Unk020a7f18_0b0 mUnk_0b0[4];
    /* 1d0 */ u16 mUnk_1d0;
    /* 1d2 */ u8 mUnk_1d2[2];
    /* 1d4 */ s32 mUnk_1d4;
    /* 1d8 */ Unk020e0144 mUnk_1d8;
    /* State number of this kind's own per-frame switch in UpdateSanbo; this object does not use
       MapObject.mUnk_80's state machine; also read in its draw, state 1 is never written */
    /* 1fc */ s32 mState;
} Sanbo;

#include "Main/Unknown/code_020a71c8.h"
#include "Main/Unknown/code_020a7eb4.h"
