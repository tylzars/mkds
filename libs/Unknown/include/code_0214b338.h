#pragma once

#include "types.h"

// Waits for the DMA channel, returns the kept bank mask to the bank group and clears it.
void GXS_EndLoadOBJExtPltt(void);
// Copies c bytes from a to 0x68a0000 + b (sub OBJ extended palette, bank I); DMA channel when in use, else
// MemCopyWords.
void GXS_LoadOBJExtPltt(const void *a, u32 b, u32 c);
// Starts a load into the sub-screen OBJ extended palette (bank I): keeps the mask the bank group returns.
void GXS_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears it.
void GXS_EndLoadBGExtPltt(void);
// Copies c bytes from a to 0x6898000 + b (sub BG extended palette, bank H); DMA channel when in use, else MemCopyWords.
void GXS_LoadBGExtPltt(const void *a, u32 b, u32 c);
// Starts a load into the sub-screen BG extended palette (bank H): keeps the mask the bank group returns.
void GXS_BeginLoadBGExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the state.
void GX_EndLoadOBJExtPltt(void);
// Copies c bytes from a to the main OBJ extended palette at offset b from the base set by the begin call.
void GX_LoadOBJExtPltt(const void *a, u32 b, u32 c);
// Starts a load into the main-screen OBJ extended palette: keeps the bank mask and sets the base (0x6890000 for bank F,
// 0x6894000 for G).
void GX_BeginLoadOBJExtPltt(void);
// Waits for the DMA channel, returns the kept bank mask to the bank group and clears the load state.
void GX_EndLoadBGExtPltt(void);
// Copies c bytes from a to the main BG extended palette at offset b (relative to the base set by the begin call); uses
// the DMA channel when one is in use, else MemCopyWords.
void GX_LoadBGExtPltt(const void *a, u32 b, u32 c);
// Starts a load into the main-screen BG extended palette: asks the bank group for its mask, keeps it, and sets the load
// base (0x6880000 for bank E, 0x6894000 with a 0x4000 offset for G alone, 0x6890000 for F or F and G).
void GX_BeginLoadBGExtPltt(void);
