#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
extern u8 data_0218049c[];
extern u8 data_021804a0[];

// Defined by the linker script.
extern u8 OV000_TEXT_START[];
extern u8 OV001_TEXT_START[];
extern u8 OV002_CTOR_START[];
extern u8 OV000_BSS_END[];
extern u8 OV001_BSS_END[];
extern u8 OV002_BSS_END[];

extern u32 data_021802a0;
extern UnkWordFunc *data_021802a4;
// Id from IdAlloc, taken in GX_Init; ReleaseVramBankGroup hands it to the lock-table release.
extern u16 gVramLockId;
// 13 bank-mask halfwords: [0] banks that are directly accessible, then the banks given to the background, sprites,
// second processor, texture, texture palette, clear image, background and sprite extended palettes, sub background, sub
// sprites, sub background and sub sprite extended palettes. data_021802b2-data_021802c8 are elements 1 to 12.
extern u8 gVramBankGroups[];
extern u16 data_021802b2;
extern u16 data_021802b4;
extern u16 data_021802b6;
extern u16 data_021802b8;
extern u16 data_021802ba;
extern u16 data_021802bc;
extern u16 data_021802be;
extern u16 data_021802c0;
extern u16 data_021802c2;
extern u16 data_021802c4;
extern u16 data_021802c6;
extern u16 data_021802c8;
extern u32 data_021802cc;
extern u32 data_021802d0;
extern u32 data_021802d4;
extern u32 data_021802d8;
extern u32 data_021802dc;
extern u32 data_021802e0;
extern u32 data_021802e4;

// Display mode value (the bits at 16 and up of the main display word) kept while the display is off and by
// GX_SetGraphicsMode; GX_DispOn writes it back.
extern u8 gSavedDispMode[];

extern u32 data_021802e8;
extern u32 data_021802ec;
extern u8 *data_021802f0;
extern s32 data_021802f4;
extern u8 *data_021802f8;
extern u32 data_021802fc;
extern u32 data_02180300;
extern u32 data_02180304;
