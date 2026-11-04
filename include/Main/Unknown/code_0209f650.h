#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectKindData
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_020a0028.h" // Unk020a018c

// Object with the MapObject base: two halfwords at 0xa0 and 0xa2, then three words (func_0209f6d8, func_0209f800,
// func_0209fb0c).
typedef struct Unk0209f6d8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk0209f6d8;

// Array of object pointers: pointer to the array and the number of entries (func_0209f800).
typedef struct Unk0209f800 {
    /* 00 */ Unk0209f6d8 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209f800;

extern char gChandelierNsbmdName[];
extern char gChandelierNsbcaName[];
extern char gTownMonteNsbmdName[];
extern char gTownMonteNsbtpName[];
extern void *gTownMonte;
extern MapObjectKindData *data_usa_0217b18c[19];

void CreateChandelier(void *a);
void *func_0209f698(void);
void *func_0209f6b8(void);
void func_0209f6d8(void *a, Unk0209f6d8 *p);
void func_0209f800(Unk0209f800 *a);
void func_0209fb0c(void *a, Unk0209f6d8 *p);
void func_0209fbe4(Unk0209bc74 *a);
void func_0209fc2c(void);
void func_0209fc38(void);
void func_0209fc78(MapObject *p);
void *func_0209fd74(void);
void *func_0209fd94(void);
void func_0209fdb4(void *a, Unk020a018c *p);
