#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, MapObjectKindData
#include "Main/Unknown/code_0209bc74.h"
#include "Main/Unknown/code_020a0028.h" // Airship

// Object of kind 0x157 (TownMonte) with the MapObject base: two halfwords at 0xa0 and 0xa2, then three words
// (UpdateTownMonte, func_0209f800, DrawTownMonte).
typedef struct TownMonte {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} TownMonte;

// Array of object pointers: pointer to the array and the number of entries (func_0209f800).
typedef struct Unk0209f800 {
    /* 00 */ TownMonte **mUnk_00;
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
void UpdateTownMonte(void *a, TownMonte *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_0209f800(Unk0209f800 *a);
void DrawTownMonte(void *a, TownMonte *p);
void CreateTownMonte(Unk0209bc74 *a); /* also stores the hook func_0209fc2c in the record's +0x14 */
void func_0209fc2c(void);
void func_0209fc38(void);
void func_0209fc78(MapObject *p);
void *func_0209fd74(void);
void *func_0209fd94(void);
void UpdateAirship(void *a, Airship *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
