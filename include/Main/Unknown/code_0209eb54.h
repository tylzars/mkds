#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of UpdatePicture: after the shared part, a halfword at 0xa0, the phase at 0xa4, a counter at 0xa8 and the
// state at 0xac.
typedef struct Unk0209ec80 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk0209ec80;

/* kind 0xd objects are MapObject-sized (0xa0); the Unk0209ec80 parameter is the Picture type, only the MapObject
   part is read */
void DrawPuddle(void *a, Unk0209ec80 *b);
void func_0209ec00(void *a);
void CreatePuddle(void *a);
void *func_0209ec44(void);
void *func_0209ec60(void);
void UpdatePicture(void *a, Unk0209ec80 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawPicture(void *a, Unk0209ec80 *b);
void CreatePicture1AndPicture2(void *a);
