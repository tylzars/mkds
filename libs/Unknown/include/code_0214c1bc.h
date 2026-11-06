#pragma once

#include "types.h"

// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and address.
void GX_EndLoadClearImage(void);
// Copies size bytes from src to the colour image address + 0x20000 (the depth image).
void GX_LoadClearImageDepth(const void *src, u32 size);
// Copies size bytes from src to the colour image address.
void GX_LoadClearImageColor(const void *src, u32 size);
// Keeps the clear-image bank mask and sets the colour image address (0x6800000 for masks 2 and 3, 0x6840000 for 8 and
// 12, 0x67e0000 for 1, 0x6820000 for 4).
void GX_BeginLoadClearImage(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the mask and base.
void GX_EndLoadTexPltt(void);
// Copies size bytes from src to the texture palette base + offset; DMA channel when in use, else MIi_CpuCopy32.
void GX_LoadTexPltt(const void *src, u32 offset, u32 size);
// Keeps the texture-palette bank mask and sets the load base from the 8-entry table, indexed by mask >> 4.
void GX_BeginLoadTexPltt(void);
// Waits for the DMA channel, returns the kept mask to the bank group and clears the four state words.
void GX_EndLoadTex(void);
// Copies size bytes from src to the texture banks at offset; a copy that crosses the first run's size is split there,
// the rest goes to the second run base.
void GX_LoadTex(const void *src, u32 offset, u32 size);
// Keeps the texture bank mask and loads that mask's row of the block table: first run base, second run base, first run
// size.
void GX_BeginLoadTex(void);
