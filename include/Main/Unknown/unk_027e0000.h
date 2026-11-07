#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
typedef struct Unk027e0000 Unk027e0000;
extern Unk027e0000 data_027e0000;
struct KartItems;
// Element 8 is used by code_021001ac.c for an owner flagged 0x8000
extern struct KartItems *gKartItems;
extern s32 gCollisionHitCount;
extern u16 gCollisionHitValues[16];
extern u32 gCollisionHitBits[16];
extern u16 gKartItemsCount;
