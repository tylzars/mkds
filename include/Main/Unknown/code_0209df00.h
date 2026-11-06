#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectList

// Element of 0x10 bytes: a position, then two halfwords.
typedef struct Unk0209df84_c4 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0209df84_c4;

// Object of kind 0x1af (Fireball2); Unk0209e950 is a view of the draw group record (word +0x1c), not of this
// object. After the shared part, the counts at 0xa0 and 0xa2, a grid of elements from 0xc4 (rows of
// 0x140 bytes, 0xa0 rows of 0xa2 elements) and the words from 0x19c4.
typedef struct Fireball2 {
    /* 0000 */ MapObject mUnk_00;
    /* 00a0 */ u16 mUnk_a0;
    /* 00a2 */ u16 mUnk_a2;
    /* 00a4 */ u16 mUnk_a4;
    /* 00a6 */ u8 mUnk_a6[2];
    /* 00a8 */ s32 mUnk_a8;
    /* 00ac */ s32 mUnk_ac;
    /* 00b0 */ u16 mUnk_b0;
    /* 00b2 */ u16 mUnk_b2;
    /* 00b4 */ Vec3 mUnk_b4;
    /* 00c0 */ u8 mUnk_c0[2];
    /* 00c2 */ u16 mUnk_c2;
    /* 00c4 */ Unk0209df84_c4 mUnk_c4[20][20];
    /* 19c4 */ s32 mUnk_19c4[8];
    /* 19e4 */ s32 mUnk_19e4;
} Fireball2;

// Object given to CreateFireball2, which sets the word at 0x1c.
typedef struct Unk0209e950 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk0209e950;

void *func_0209df00(void);
void *func_0209df20(void);
void func_0209df44(void);
void UpdateFireball2(void *a, Fireball2 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_0209e310(MapObjectList *p);
void DrawFireball2(void *a, Fireball2 *b);
void func_0209e938(void *a);
void CreateFireball2(Unk0209e950 *a); /* also sets word +0x1c of the group record to 1 */
BOOL func_0209e988(Fireball2 *a, Vec3 *b, s32 c);
u8 func_0209ea10(Fireball2 *a, Kart *b, u8 *c, u8 *d);
void InitFireball2(Fireball2 *a);
void *func_0209eb04(void);
