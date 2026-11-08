#include "Main/Unknown/code_02007ec4.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/code_020091fc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_02008310(void *rangeTable, Unk02008188 *source) {
    u32 entryIndex;
    u32 savedInterrupts;
    u32 entryOffset;
    Unk0216fdac *work;
    Unk020082b4 *record;
    u8 i;
    entryIndex = 0xff;
    savedInterrupts = OS_DisableInterrupts();
    if (func_02009958() == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    work = data_0216fdac;
    if (work->mEntryCount + 1 > 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    for (i = 0; i < 0x10; i++) {
        if ((OFFSET_PTR(Unk0216fdac, work, i * 0x5d4))->mUnk_1d40 == rangeTable) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        if ((OFFSET_PTR(Unk0216fdac, work, i * 0x5d4))->mEntryUsed == 0) {
            entryIndex = i;
            break;
        }
    }
    if (i == 0x10) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    entryOffset = entryIndex * 0x5d4;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d40 = rangeTable;
    record = (Unk020082b4 *) (data_0216fdac->mUnk_1788 + entryOffset);
    func_020082b4(record, source);
    MI_CpuCopy8((u8 *) rangeTable + 0x1c, record->mUnk_c4, 0x20);
    if (func_020080e8((Unk0200806c_b *) (data_0216fdac->mUnk_1d2c + entryOffset), record) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    func_02009828((GameInfoEntry *) (data_0216fdac->mUnk_1788 + 0xe4 + entryOffset), rangeTable,
                  (const u8 *) &data_0216fdac->mUnk_1300);
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d21 = entryIndex;
    AppendGameInfoEntry((GameInfoEntry *) (data_0216fdac->mUnk_1788 + 0xe4 + entryOffset));
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d1f = data_0216fc30++;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d4e = 1;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d44 = source;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d54 = &source->mUnk_1e8;
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d58 = source->mUnk_258;
    if ((OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mUnk_1d54->mUnk_30[3].mUnk_0c != 0) {
        if (IsWorkerActive() == 0) {
            func_0200b00c(data_0216fdac->mUnk_7ce0);
            StartWorkerThread(&data_0216fdac->mUnk_74e0, 0x800);
        }
    }
    (OFFSET_PTR(Unk0216fdac, data_0216fdac, entryOffset))->mEntryUsed = 1;
    data_0216fdac->mEntryCount++;
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

void func_020082b4(Unk020082b4 *record, Unk02008188 *source) {
    u32 nextAddress;
    u8 *headerTail;
    u32 *kinds;
    Unk020082b4_0c *range;
    s32 i;
    nextAddress = 0x022c0000;
    headerTail = source->mUnk_160;
    record->mUnk_00 = source->mUnk_024;
    record->mUnk_04 = source->mUnk_034;
    range = record->mUnk_0c;
    kinds = data_02152bc0;
    for (i = 0; i < 3; i++) {
        func_02008188(source, kinds, range, &nextAddress);
        range++;
        kinds++;
    }
    MI_CpuCopy8(headerTail, record->mUnk_3c, 0x88);
}

void func_02008188(Unk02008188 *source, u32 *kindWord, Unk020082b4_0c *range, u32 *nextAddress) {
    u32 outOfBounds;
    u32 useNextAddress;
    u32 *pair;
    u32 end;
    switch (*kindWord) {
        case 0:
            pair = source->mUnk_028;
            if (source->mUnk_028[0] >= 0x02000000 && source->mUnk_028[0] < 0x022c0000 &&
                source->mUnk_028[0] + pair[1] <= 0x022c0000) {
                range->mUnk_08 = pair[1];
                range->mUnk_04 = pair[0];
                range->mUnk_00 = range->mUnk_04;
                range->mUnk_0c &= ~1;
                return;
            }
            OS_Terminate();
            return;
        case 1:
            outOfBounds = 0;
            useNextAddress = 0;
            pair = source->mUnk_038;
            end = source->mUnk_038[0] + pair[1];
            if (source->mUnk_038[0] >= 0x02000000 && source->mUnk_038[0] < 0x023fe800) {
                if (end > 0x02300000) {
                    if (end < 0x023fe800 && pair[1] <= 0x40000) {
                        useNextAddress = 1;
                    } else {
                        outOfBounds = 1;
                    }
                }
            } else if (source->mUnk_038[0] >= 0x037f8000 && source->mUnk_038[0] < 0x0380f000) {
                if (end <= 0x0380f000) {
                    useNextAddress = 1;
                } else {
                    outOfBounds = 1;
                }
            } else {
                outOfBounds = 1;
            }
            if (outOfBounds == 1) {
                OS_Terminate();
            }
            range->mUnk_08 = pair[1];
            range->mUnk_04 = pair[0];
            if (useNextAddress == 0) {
                range->mUnk_00 = range->mUnk_04;
            } else {
                range->mUnk_00 = *nextAddress;
                *nextAddress = *nextAddress + range->mUnk_08;
            }
            range->mUnk_0c = (range->mUnk_0c & ~1) | 1;
            return;
        case 2:
            range->mUnk_08 = 0x160;
            range->mUnk_04 = 0x027ffe00;
            range->mUnk_00 = range->mUnk_04;
            range->mUnk_0c &= ~1;
            return;
    }
}

static inline struct Unk0216fdac *func_0200806c_inline(void) {
    return data_0216fdac;
}

u32 func_020080e8(Unk0200806c_b *chunkTable, Unk020082b4 *record) {
    u32 offset;
    u16 nextChunk;
    u8 i;
    Unk020082b4_0c *range;
    u16 *chunkStarts;
    chunkStarts = chunkTable->mUnk_0c;
    offset = 0;
    if (record == NULL) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        chunkTable->mUnk_00[i] = offset;
        offset += record->mUnk_0c[i].mUnk_08;
    }
    chunkStarts[0] = 0;
    for (i = 0; i < 3; i++) {
        range = &record->mUnk_0c[i];
        nextChunk = chunkStarts[i] + (u16) ((range->mUnk_08 + data_0216fdac->mUnk_1318 - 1) / data_0216fdac->mUnk_1318);
        if (func_02007f38(i, range->mUnk_04, range->mUnk_08) == 0) {
            return 0;
        }
        if (i < 2) {
            chunkStarts[i + 1] = nextChunk;
        } else {
            chunkTable->mUnk_0c[3] = nextChunk;
        }
    }
    return 1;
}

BOOL func_0200806c(Unk020072c0_buf *result, void *b, u16 chunk, void *d) {
    u32 offset;
    Unk020082b4 *record;
    Unk020082b4_0c *range;
    Unk0200806c_b *chunkTable;
    s8 i;
    chunkTable = b;
    record = d;
    if (chunk >= chunkTable->mUnk_0c[3]) {
        return FALSE;
    }
    for (i = 2; i >= 0; i--) {
        if (chunk >= chunkTable->mUnk_0c[i]) {
            break;
        }
    }
    if (i < 0) {
        return FALSE;
    }
    offset = (chunk - chunkTable->mUnk_0c[i]) * func_0200806c_inline()->mUnk_1318;
    range = &record->mUnk_0c[i];
    result->mUnk_04 = range->mUnk_08 - offset;
    if (result->mUnk_04 > data_0216fdac->mUnk_1318) {
        result->mUnk_04 = data_0216fdac->mUnk_1318;
    }
    result->mUnk_08 = offset + chunkTable->mUnk_00[i];
    result->mUnk_00 = offset + range->mUnk_00;
    result->mUnk_0c = i;
    return TRUE;
}

u32 func_02007ff0(u32 rangeIndex, u32 address, u32 size) {
    switch (data_02152bc0[rangeIndex]) {
        case 2:
            if (address >= 0x027ffe00 && address + size <= 0x027fff60) {
                return 1;
            }
            break;
        case 0:
            if (address >= 0x02000000 && address + size <= 0x022c0000) {
                return 1;
            }
            break;
        case 1:
            if (address >= 0x022c0000 && address + size <= 0x02300000) {
                return 1;
            }
            if (address >= 0x02000000 && address + size <= 0x02300000) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

u32 func_02007f38(u32 rangeIndex, u32 address, u32 size) {
    u32 end;
    switch (data_02152bc0[rangeIndex]) {
        case 0:
        case 2:
            return func_02007ff0(rangeIndex, address, size);
        case 1:
            if (address >= 0x02000000 && address < 0x023fe800) {
                end = address + size;
                if (address < 0x02300000 && end > 0x02300000) {
                    return 0;
                }
                if (end <= 0x02300000) {
                    return 1;
                }
                if (end < 0x023fe800 && size <= 0x40000) {
                    return 1;
                }
                return 0;
            }
            if (address >= 0x037f8000 && address < 0x0380f000) {
                if (address + size <= 0x0380f000) {
                    return 1;
                }
                return 0;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

void func_02007ec4(ScanBlock *record, u16 b, u16 c, u32 d, u32 e) {
    u32 v1;
    u32 v2;
    u16 *p = (u16 *) 0x027ffc40;
    MI_CpuCopy8(*p == 2 ? (void *) (p + 1) : (void *) 0, record, 0x3c);
    record->mUnk_3c = 0x10;
    record->mUnk_44 = record->mUnk_0c | (record->mUnk_0e << 16);
    record->mUnk_48 = record->mUnk_10;
    record->mUnk_4a = 0;
    record->mUnk_4c = b;
    record->mUnk_4e = c;
    v1 = 0;
    if (e != 0) {
        v1 = 8;
    }
    if (d != 0) {
        v2 = 4;
    } else {
        v2 = 0;
    }
    record->mUnk_4b = v2 | v1 | 1;
}

#pragma thumb off
