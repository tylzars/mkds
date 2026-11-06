#pragma once

#include "types.h"

void MemCopyWordsToG2sBg3CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2Bg3CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2sBg2CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2Bg2CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2sBg1CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2Bg1CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2sBg0CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyWordsToG2Bg0CntBits2To5Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2sBg3CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2Bg3CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2sBg2CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2Bg2CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2sBg1CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2Bg1CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2sBg0CntBits8To12Address(const void *a, u32 b, u32 c);
void MemCopyHalfwordsToG2Bg0CntBits8To12Address(const void *a, u32 b, u32 c);
// Copies c bytes from a to sub OBJ character memory at 0x6600000 + b (a fixed address); same cut-over.
void GXS_LoadOBJ(const void *a, u32 b, u32 c);
// Copies c bytes from a to main OBJ character memory at 0x6400000 + b (a fixed address; no bank lookup); DMA for more
// than 0x30 bytes, else MIi_CpuCopy32.
void GX_LoadOBJ(const void *a, u32 b, u32 c);
// Copies c bytes from a to the sub OAM at 0x7000400 + b; same cut-over.
void GXS_LoadOAM(const void *a, u32 b, u32 c);
// Copies c bytes from a to the main OAM at 0x7000000 + b; DMA for more than 0x30 bytes, else MIi_CpuCopy32.
void GX_LoadOAM(const void *a, u32 b, u32 c);
// Copies c bytes from a to the sub OBJ palette at 0x5000600 + b; same cut-over.
void GXS_LoadOBJPltt(const void *a, u32 b, u32 c);
// Copies c bytes from a to the main OBJ palette at 0x5000200 + b; same cut-over.
void GX_LoadOBJPltt(const void *a, u32 b, u32 c);
// Copies c bytes from a to the sub BG palette at 0x5000400 + b; same cut-over.
void GXS_LoadBGPltt(const void *a, u32 b, u32 c);
// Copies c bytes from a to the main BG palette at 0x5000000 + b; DMA for more than 0x1c bytes, else MIi_CpuCopy16.
void GX_LoadBGPltt(const void *a, u32 b, u32 c);
