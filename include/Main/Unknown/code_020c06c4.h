#pragma once

#include "types.h"
#include "code_02022030.h"

typedef struct RaceHudSubScreenCells RaceHudSubScreenCells;

// Second view of an OAM entry: two words, each with a two-bit part at bit 10.
typedef struct RaceHudOamBits {
    /* 0 */ u32 mUnk_00 : 10;
    /* 0 */ u32 mUnk_0a : 2;
    /* 0 */ u32 mUnk_0c : 20;
    /* 4 */ u32 mUnk_04 : 10;
    /* 4 */ u32 mUnk_0e : 2;
    /* 4 */ u32 mUnk_10 : 20;
} RaceHudOamBits;

// Rotation matrix view of four OAM entries (0x20 bytes): a halfword at each of 0x06, 0x0e, 0x16 and 0x1e.
typedef struct RaceHudOamMatrix {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u8 mUnk_10[6];
    /* 16 */ s16 mUnk_16;
    /* 18 */ u8 mUnk_18[6];
    /* 1e */ s16 mUnk_1e;
} RaceHudOamMatrix;

// Argument of the race HUD draw functions: 0x80 elements of 8 bytes, then a halfword.
typedef struct RaceHudOamBuffer {
    union {
        /* 000 */ GXOamAttr mOams[0x80];
        /* 000 */ RaceHudOamBits mOamBits[0x80];
        /* 000 */ RaceHudOamMatrix mMatrices[0x20];
    };
    /* 400 */ u16 mOamCount;
} RaceHudOamBuffer;

void DrawRaceHudSubScreenCells(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);
void DrawRaceHudSubScreenCellsScaled(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation);
