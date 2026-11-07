#pragma once

#include "types.h"

// Copies size bytes from src to the sub engine BG3 character data at offset.
void GXS_LoadBG3Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG3 character data at offset.
void GX_LoadBG3Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 character data at offset.
void GXS_LoadBG2Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG2 character data at offset.
void GX_LoadBG2Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 character data at offset.
void GXS_LoadBG1Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG1 character data at offset.
void GX_LoadBG1Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 character data at offset.
void GXS_LoadBG0Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG0 character data at offset.
void GX_LoadBG0Char(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG3 screen data at offset.
void GXS_LoadBG3Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG3 screen data at offset.
void GX_LoadBG3Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG2 screen data at offset.
void GXS_LoadBG2Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG2 screen data at offset.
void GX_LoadBG2Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG1 screen data at offset.
void GXS_LoadBG1Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG1 screen data at offset.
void GX_LoadBG1Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub engine BG0 screen data at offset.
void GXS_LoadBG0Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main engine BG0 screen data at offset.
void GX_LoadBG0Scr(const void *src, u32 offset, u32 size);
// Copies size bytes from src to sub OBJ character memory at 0x6600000 + offset; DMA for more than 0x30 bytes, else
// MIi_CpuCopy32.
void GXS_LoadOBJ(const void *src, u32 offset, u32 size);
// Copies size bytes from src to main OBJ character memory at 0x6400000 + offset; DMA for more than 0x30 bytes, else
// MIi_CpuCopy32.
void GX_LoadOBJ(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OAM at 0x7000400 + offset; same cut-over.
void GXS_LoadOAM(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main OAM at 0x7000000 + offset; DMA for more than 0x30 bytes, else MIi_CpuCopy32.
void GX_LoadOAM(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub OBJ palette at 0x5000600 + offset; same cut-over.
void GXS_LoadOBJPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main OBJ palette at 0x5000200 + offset; same cut-over.
void GX_LoadOBJPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the sub BG palette at 0x5000400 + offset; same cut-over.
void GXS_LoadBGPltt(const void *src, u32 offset, u32 size);
// Copies size bytes from src to the main BG palette at 0x5000000 + offset; DMA for more than 0x1c bytes, else
// MIi_CpuCopy16.
void GX_LoadBGPltt(const void *src, u32 offset, u32 size);
