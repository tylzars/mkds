#pragma once

#include "types.h"

// Blocks of words moved by MemCopy8Words, MemCopy9Words, MemCopy12Words and MemCopy16Words.
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

void MemFillWords(u32 a, void *b, u32 c);
void MemCopyWords(const void *a, void *b, u32 c);
void MemCopyWordsToOneAddress(const void *a, vu32 *b, u32 c);
void MemFillWordsByBlock(u32 a, void *b, u32 c);
void MemCopyWordsByBlock(const void *a, void *b, u32 c);
void MemCopy8Words(const void *a, void *b);
void MemCopy9Words(const void *a, void *b);
void MemCopy12Words(const void *a, void *b);
void MemCopy16Words(const void *a, void *b);
void MemFill(void *a, u8 b, u32 c);
void MemCopy(const void *a, void *b, u32 c);
void MemZero9Words(s32 *a);
s32 WordSwap(s32 a, s32 *b);
void ExpandCompressed(const void *a, void *b);

// Calls MemFillWordsByBlock with 0, passed through a stack offset of its own.
static inline void MemFillWordsByBlock_inline(void *p, u32 n) {
    volatile u32 v = 0;
    MemFillWordsByBlock(v, p, n);
}
