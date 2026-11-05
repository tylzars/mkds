#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern u8 data_027e0000[];
struct KartItems;
// Element 8 is used by code_021001ac.c for an owner flagged 0x8000
extern struct KartItems *gKartItems;
extern s32 data_027e0060;
extern u16 data_027e0064[16];
extern u32 data_027e0084[16];
extern u16 gKartItemsCount;
