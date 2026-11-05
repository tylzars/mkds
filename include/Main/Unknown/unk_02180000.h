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
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gSubBgExtPaletteLoadBankMask;
// Address the OBJ extended palette load starts from; 0 when idle.
extern u32 gObjExtPaletteLoadBase;
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gObjExtPaletteLoadBankMask;
// Subtracted from the load offset: 0x4000 when only bank G is mapped, else 0.
extern u32 gBgExtPaletteLoadBaseOffset;
// Address the BG extended palette load starts from; set by the begin call, 0 when idle.
extern u32 gBgExtPaletteLoadBase;
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gBgExtPaletteLoadBankMask;
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gSubObjExtPaletteLoadBankMask;

// Display mode value (the bits at 16 and up of the main display word) kept while the display is off and by
// GX_SetGraphicsMode; GX_DispOn writes it back.
extern u8 gSavedDispMode[];

// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gClearImageLoadBankMask;
// Start of the first run of texture banks.
extern u32 gTextureLoadFirstBase;
// Address the texture palette load starts from, from gTexturePaletteBaseTable.
extern u8 *gTexturePaletteLoadBase;
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern s32 gTexturePaletteLoadBankMask;
// Address of the colour slot; the depth slot is 0x20000 above it. For a single bank it lies below that bank.
extern u8 *gClearImageLoadBase;
// The bank mask kept between the begin and end call of that load group; 0 when no load is open.
extern u32 gTextureLoadBankMask;
// Start of the second run (0 when the mask is one run).
extern u32 gTextureLoadSecondBase;
// Byte size of the first run.
extern u32 gTextureLoadFirstSize;
