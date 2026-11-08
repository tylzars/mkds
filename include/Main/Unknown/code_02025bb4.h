#pragma once

#include "types.h"

typedef struct Unk0201ea30 Unk0201ea30;

// 0x40-byte entry that func_02025bf0 and func_02025c1c fill.
typedef struct Unk02025bb4Entry {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ s16 mUnk_0c;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ u8 mUnk_10[0x30];
} Unk02025bb4Entry;

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics);
void func_02025bf0(u32 entryId, void *outputPointer, Unk0201ea30 *labelLayout);
void func_02025c1c(u32 entryId, void *outputPointer, Unk0201ea30 *cellLayout);
void func_02025c48(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c6c(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout);
void func_02025c94(int id, int x, int y, Unk0201ea30 *graphics);
