#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base: two halfwords at 0xa0 and 0xa2, then two words (UpdateRainStar, DrawRainStar,
// UpdateChandelier, InitChandelierObjects).
typedef struct Unk0209f1c8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
} Unk0209f1c8;

// Array of object pointers: pointer to the array and the number of entries (InitChandelierObjects).
typedef struct Unk0209f514 {
    /* 00 */ Unk0209f1c8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209f514;

extern char gRainStarNsbmdName[];
extern char gRainStarNsbtaName[];

void *CreateRainStarUpdateList(void);
void *CreateRainStarDrawList(void);
void UpdateRainStar(void *a, Unk0209f1c8 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawRainStar(void *a, Unk0209f1c8 *b);
void CreateRainStar(void *a);
void *CreateChandelierUpdateList(void);
void *CreateChandelierDrawList(void);
void UpdateChandelier(void *a, Unk0209f1c8 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitChandelierObjects(Unk0209f514 *a);
