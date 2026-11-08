#include "Main/Unknown/code_02025bb4.h"
#include "code_0201ea30.h"
#include "code_0201ea58.h"

#pragma thumb on

void func_02025c94(int id, int x, int y, Unk0201ea30 *graphics) {
    short *entry = (func_0201ea30(graphics, id));
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

void func_02025c6c(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout) {
    u16 *destinationEntry;
    u16 *sourceEntry;
    destinationEntry = func_0201ea30(cellLayout, destinationId);
    sourceEntry = func_0201ea30(cellLayout, sourceId);
    *destinationEntry = *sourceEntry;
    destinationEntry[1] = sourceEntry[1];
}

void func_02025c48(u32 destinationId, u32 sourceId, Unk0201ea30 *cellLayout) {
    int destinationEntry;
    int sourceEntry;
    destinationEntry = (s32) func_0201ea30(cellLayout, destinationId);
    sourceEntry = (s32) func_0201ea30(cellLayout, sourceId);
    *(u32 *) (destinationEntry + 4) = *(u32 *) (sourceEntry + 4);
}

void func_02025c1c(u32 entryId, void *outputPointer, Unk0201ea30 *cellLayout) {
    Unk02025bb4Entry *output = outputPointer;
    short *layoutEntry;
    layoutEntry = func_0201ea30(cellLayout, entryId);
    output->mUnk_08 = 1;
    output->mUnk_0c = ((*layoutEntry << 0x14) >> 0x14);
    output->mUnk_0e = ((layoutEntry[1] << 0x14) >> 0x14);
}

void func_02025bf0(u32 entryId, void *outputPointer, Unk0201ea30 *labelLayout) {
    Unk02025bb4Entry *output = outputPointer;
    short *layoutEntry;
    layoutEntry = func_0201ea58(labelLayout, entryId);
    output->mUnk_08 = 1;
    output->mUnk_0c = ((*layoutEntry << 0x14) >> 0x14);
    output->mUnk_0e = ((layoutEntry[1] << 0x14) >> 0x14);
}

void RectTableSetEntryXY(int id, int x, int y, Unk0201ea30 *graphics) {
    short *entry = (s16 *) RectTableGetEntry(graphics, id);
    entry[0] = (entry[0] & 0xfffff000U) | (x & 0xfff);
    entry[1] = (entry[1] & 0xfffff000U) | (y & 0xfff);
}

#pragma thumb off
