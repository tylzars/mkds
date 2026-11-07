#pragma once

#include "types.h"

// Blocks of words moved by MI_Copy32B, MI_Copy36B, MI_Copy48B and MI_Copy64B.
typedef struct Unk0214d0e0 {
    /* 00 */ u32 mUnk_00[8];
} Unk0214d0e0;

typedef struct Unk0214d0fc {
    /* 00 */ u32 mUnk_00[9];
} Unk0214d0fc;

typedef struct Unk0214d118 {
    /* 00 */ u32 mUnk_00[12];
} Unk0214d118;

typedef struct Unk0214d13c {
    /* 00 */ u32 mUnk_00[16];
} Unk0214d13c;

void MIi_CpuClear32(u32 data, void *destp, u32 size);
void MIi_CpuCopy32(const void *srcp, void *destp, u32 size);
void MIi_CpuSend32(const void *srcp, vu32 *destp, u32 size);
void MIi_CpuClearFast(u32 data, void *destp, u32 size);
void MIi_CpuCopyFast(const void *srcp, void *destp, u32 size);
void MI_Copy32B(const void *pSrc, void *pDest);
void MI_Copy36B(const void *pSrc, void *pDest);
void MI_Copy48B(const void *pSrc, void *pDest);
void MI_Copy64B(const void *pSrc, void *pDest);
void MI_CpuFill8(void *dstp, u8 data, u32 size);
void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
void MI_Zero36B(void *pDest);
u32 MI_SwapWord(u32 setData, volatile u32 *destp);
void MI_UncompressLZ8(const void *srcp, void *destp);

// Calls MIi_CpuClearFast with 0, passed through a stack offset of its own.
static inline void MemFillWordsByBlock_inline(void *p, u32 n) {
    volatile u32 v = 0;
    MIi_CpuClearFast(v, p, n);
}
