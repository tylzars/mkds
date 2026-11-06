#pragma once

#include "types.h"

// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and address.
void GX_EndLoadClearImage(void);
// Copies b bytes from a to the colour-slot address + 0x20000 (the depth slot).
void GX_LoadClearImageDepth(const void *a, u32 b);
// Copies b bytes from a to the colour-slot address.
void GX_LoadClearImageColor(const void *a, u32 b);
// Keeps the clear-image bank mask and sets the colour-slot address (0x6800000 for masks 2 and 3, 0x6840000 for 8 and
// 12, 0x67e0000 for 1, 0x6820000 for 4).
void GX_BeginLoadClearImage(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and base.
void GX_EndLoadTexPltt(void);
// Copies c bytes from a to the texture palette base + b; DMA channel when in use, else MIi_CpuCopy32.
void GX_LoadTexPltt(const void *a, u32 b, u32 c);
// Keeps the texture-palette bank mask and sets the load base from the 8-entry table, indexed by mask >> 4.
void GX_BeginLoadTexPltt(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the four state words.
void GX_EndLoadTex(void);
// Copies c bytes from a to the texture banks at offset b; a copy that crosses the first run's size is split there, the
// rest goes to the second run base.
void GX_LoadTex(const void *a, u32 b, u32 c);
// Keeps the texture bank mask and loads that mask's row of the block table: first run base, second run base, first run
// size.
void GX_BeginLoadTex(void);
