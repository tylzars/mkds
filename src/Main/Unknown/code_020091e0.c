#include "Main/Unknown/code_020091e0.h"

#include "Main/Unknown/code_020091fc.h"
#include "code_02003024.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02008934.h"

#pragma thumb on

void SetEntryTable(void *entryTable) {
    gEntryTable = entryTable;
}

#pragma thumb off

#pragma thumb on
u32 SetScanBssidCallbacks(UnkFunc *setCallback, UnkFunc *clearCallback) {
    u32 value0 = (u32) setCallback;
    u32 clearCallbackCopy = (u32) clearCallback;
    u32 setCallbackSlot;
    setCallbackSlot = (u32) &gSetBssidCallback;
    *(u32 *) ((setCallbackSlot) + 0u) = value0;
    value0 = (u32) &gClearBssidCallback;
    *(u32 *) ((value0) + 0u) = clearCallbackCopy;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_02009828(GameInfoEntry *entry, Unk02009828 *params, const u8 *record) {
    u32 v1;
    u32 v2;
    volatile u16 clearValue;
    clearValue = 0;
    MIi_CpuClear16(clearValue, entry, 0x4c0);
    entry->mUnk_4b2 = 0;
    v1 = LoadFileIfSizeMatches(params->mUnk_0c, (u8 *) entry, 1) == 0;
    v2 = LoadFileIfSizeMatches(params->mUnk_10, (u8 *) entry, 0) == 0;
    if ((v1 | v2) != 0) {
        entry->mUnk_4b2 = 1;
        MemFillWordsByBlock_inline(entry, 0x220);
    }
    entry->mUnk_4b8 = params->mUnk_14;
    if (record != NULL) {
        MIi_CpuCopy16(record, entry->mUnk_220, 0x16);
    }
    entry->mUnk_236 = params->mUnk_18;
    v1 = GetU16StringLength(params->mUnk_04) * 2;
    MIi_CpuCopy16(params->mUnk_04, entry->mUnk_238, (u16) v1);
    MIi_CpuCopy16(params->mUnk_08, entry->mUnk_298, 0xc0);
    entry->mUnk_358 = 1;
    entry->mUnk_35a = 1;
    entry->mUnk_4b0 = 1;
}

// Reads file a into b (b + 0x20 when c is non-zero) only when its size is 0x20 (c == 0) or 0x200 (c != 0).
u32 LoadFileIfSizeMatches(const u8 *path, u8 *buffer, u32 isLarge) {
    FSFile file;
    u32 expectedSize;
    if (isLarge != 0) {
        expectedSize = 0x200;
    } else {
        expectedSize = 0x20;
    }
    if (isLarge != 0) {
        buffer += 0x20;
    }
    if (path == NULL) {
        return 0;
    }
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path) == 0) {
        return 0;
    }
    if (expectedSize != file.mProp.w.mUnk_08 - file.mProp.w.mUnk_04) {
        FS_CloseFile(&file);
        return 0;
    }
    FS_ReadFile(&file, buffer, expectedSize);
    FS_CloseFile(&file);
    return 1;
}

void func_0200973c(GameInfoEntry *entry, const void *records, u32 recordMask, u32 d) {
    u8 v1;
    s32 i;
    v1 = 1;
    MIi_CpuCopy16(records, entry->mUnk_35e, 0x14a);
    for (i = 0; i < 15; i++) {
        if ((recordMask & (2 << i)) != 0) {
            v1++;
        }
    }
    entry->mUnk_358 = v1;
    entry->mUnk_35a = recordMask | 1;
    entry->mUnk_35c = d;
    entry->mUnk_4b4++;
}

u32 GetU16StringLength(const u16 *string) {
    u32 length;
    for (length = 0; *string++ != 0; length++) {
    }
    return length;
}

void AppendGameInfoEntry(GameInfoEntry *newEntry) {
    GameInfoEntry *lastEntry;
    GameInfoEntry *nextEntry;
    if (gGameInfoList.mFirst == NULL) {
        gGameInfoList.mFirst = newEntry;
    } else {
        lastEntry = gGameInfoList.mFirst;
        nextEntry = lastEntry->mNext;
        if (nextEntry != NULL) {
            do {
                lastEntry = nextEntry;
                nextEntry = nextEntry->mNext;
            } while (nextEntry != NULL);
        }
        lastEntry->mNext = newEntry;
    }
    newEntry->mNext = NULL;
}

void InitGameInfoList(void) {
    gGameInfoList.mFirst = NULL;
    gGameInfoList.mCurrent = NULL;
    gGameInfoList.mState = 1;
    data_0216fc48 = NULL;
    ResetGameInfoWalk();
}

void ResetGameInfoWalk(void) {
    gGameInfoList.mUnk_0d = 0;
    gGameInfoList.mUnk_0e = 0;
    gGameInfoList.mUnk_0f = 0;
    gGameInfoList.mUnk_10 = 0;
    gGameInfoList.mNextSequence = 0;
}

void SetNextGameInfo(u32 ggid, u16 tgid, u32 attr) {
    while (1) {
        switch (gGameInfoList.mState) {
            case 0:
            case 1:
                if (AdvanceGameInfoEntry() == 0) {
                    return;
                }
                break;
            case 2:
                func_020095c4();
                break;
            case 3:
                func_020094b8(ggid, tgid, attr);
                return;
            case 4:
                func_02009494();
                break;
            case 5:
                func_020092d0(ggid, tgid, attr);
                return;
            case 6:
                break;
        }
    }
}

u32 AdvanceGameInfoEntry(void) {
    GameInfoEntry *entry;
    entry = gGameInfoList.mFirst;
    if (entry == NULL) {
        return 0;
    }
    if (gGameInfoList.mCurrent != NULL) {
        if (gGameInfoList.mCurrent->mNext != NULL) {
            entry = gGameInfoList.mCurrent->mNext;
        }
    }
    gGameInfoList.mCurrent = entry;
    ResetGameInfoWalk();
    gGameInfoList.mUnk_0e = gGameInfoList.mCurrent->mUnk_4b4;
    gGameInfoList.mState = 2;
    return 1;
}

void func_020095c4(void) {
    GameInfoEntry *entry;
    if (gGameInfoList.mState == 2) {
        entry = gGameInfoList.mCurrent;
        if (entry->mUnk_4b2 == 0) {
            gGameInfoList.mUnk_10 = 9;
            gGameInfoList.mUnk_08 = (u8 *) entry;
        } else {
            gGameInfoList.mUnk_10 = 4;
            gGameInfoList.mUnk_08 = (u8 *) entry + 0x220;
        }
        gGameInfoList.mState = 3;
    }
}

void func_020094b8(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u8 *source;
    u8 *dataEnd;
    volatile u16 clearValue;
    dataEnd = (u8 *) gGameInfoList.mCurrent + 0x358;
    source = gGameInfoList.mUnk_08;
    if (source + 0x62 <= dataEnd) {
        gGameInfoBlock.mUnk_0c_b = 0x62;
    } else {
        gGameInfoBlock.mUnk_0c_b = dataEnd - source;
        clearValue = 0;
        MIi_CpuClear16(clearValue, (u8 *) &gGameInfoBlock.mUnk_0e + gGameInfoBlock.mUnk_0c_b,
                       0x62 - gGameInfoBlock.mUnk_0c_b);
    }
    MIi_CpuCopy16(gGameInfoList.mUnk_08, &gGameInfoBlock.mUnk_0e, gGameInfoBlock.mUnk_0c_b);
    gGameInfoBlock.mUnk_0a = gGameInfoList.mUnk_0f;
    gGameInfoBlock.mUnk_0b = gGameInfoList.mUnk_10;
    entry = gGameInfoList.mCurrent;
    gGameInfoBlock.mUnk_04_0 = entry->mUnk_4b2;
    gGameInfoBlock.mUnk_05 = entry->mUnk_4b3;
    gGameInfoBlock.mUnk_06 = gGameInfoList.mUnk_0e;
    gGameInfoBlock.mUnk_00 = entry->mUnk_4b8;
    gGameInfoBlock.mUnk_04_2 = entry->mUnk_4b5;
    gGameInfoBlock.mSequence = gGameInfoList.mNextSequence++;
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = ComputeU16Checksum(&gGameInfoBlock.mChecksum, 0x68);
    gGameInfoList.mUnk_0f++;
    if (gGameInfoList.mUnk_0f < gGameInfoList.mUnk_10) {
        gGameInfoList.mUnk_08 += 0x62;
    } else {
        gGameInfoList.mState = 4;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
}

void func_02009494(void) {
    gGameInfoList.mCurrent->mUnk_4b0 = 1;
    gGameInfoList.mUnk_0e = gGameInfoList.mCurrent->mUnk_4b4;
    gGameInfoList.mState = 5;
}

void func_020092d0(u32 ggid, u16 tgid, u32 attr) {
    GameInfoEntry *entry;
    u32 pendingMask;
    u32 recordBit;
    u8 *destination;
    s32 i;
    s32 sourceOffset;
    u32 recordCount;
    volatile u16 clearValue;
    if (gGameInfoList.mUnk_0e != gGameInfoList.mCurrent->mUnk_4b4) {
        func_02009494();
    }
    gGameInfoBlock.mUnk_04_0 = 2;
    entry = gGameInfoList.mCurrent;
    gGameInfoBlock.mUnk_05 = entry->mUnk_4b3;
    gGameInfoBlock.mUnk_06 = gGameInfoList.mUnk_0e;
    gGameInfoBlock.mUnk_00 = entry->mUnk_4b8;
    gGameInfoBlock.mUnk_04_2 = entry->mUnk_4b5;
    gGameInfoBlock.mSequence = gGameInfoList.mNextSequence++;
    gGameInfoBlock.mUnk_0a = entry->mUnk_358;
    gGameInfoBlock.mUnk_0c = entry->mUnk_35a;
    gGameInfoBlock.mUnk_0e = entry->mUnk_35c;
    if (data_0216fc44 == 0 && data_0216fc48 != NULL) {
        data_0216fc48(entry->mUnk_4b8);
    }
    for (i = 0; i < 8; i++) {
        gGameInfoBlock.mUnk_68[i] = gGameInfoList.mCurrent->mUnk_4a8[i];
    }
    clearValue = 0;
    MIi_CpuClear16(clearValue, gGameInfoBlock.mUnk_10, 0x58);
    recordCount = 0;
    pendingMask = (u16) (gGameInfoList.mCurrent->mUnk_4b0 ^ gGameInfoList.mCurrent->mUnk_35a);
    i = 0;
    destination = gGameInfoBlock.mUnk_10;
    sourceOffset = 0;
    for (; i < 15; i++) {
        recordBit = 2 << i;
        if ((pendingMask & recordBit) != 0) {
            MIi_CpuCopy16(gGameInfoList.mCurrent->mUnk_35e + sourceOffset, destination, 0x16);
            gGameInfoList.mCurrent->mUnk_4b0 |= recordBit;
            destination += 0x16;
            recordCount++;
            if (recordCount == 4) {
                break;
            }
        }
        sourceOffset += 0x16;
    }
    if (recordCount < 4) {
        gGameInfoBlock.mUnk_10[recordCount * 0x16] &= ~0xf0;
    }
    gGameInfoBlock.mChecksum = 0;
    gGameInfoBlock.mChecksum = ComputeU16Checksum(&gGameInfoBlock.mChecksum, 0x68);
    if (gGameInfoList.mCurrent->mUnk_4b0 == gGameInfoList.mCurrent->mUnk_35a) {
        gGameInfoList.mState = 1;
    }
    attr |= 2;
    WM_SetGameInfo(NULL, &gGameInfoBlock, 0x70, ggid, tgid, attr);
    if (data_0216fc44 == 1 && data_0216fc48 != NULL) {
        data_0216fc48(gGameInfoList.mCurrent->mUnk_4b8);
    }
}

void ClearEntryTable(void) {
    MemFillWordsByBlock_inline(gEntryTable, 0x5910);
    gEntryTable->mUnk_0c = 1;
}

u32 AddScanResult(Unk02008f00Func callback, u32 b, ScanBlock *scanBlock) {
    s32 entryIndex;
    if (func_020091fc(scanBlock) == 0) {
        return 0;
    }
    MIi_CpuCopy16(scanBlock, data_0216fce0, 0xc0);
    scanBlock = (ScanBlock *) data_0216fce0;
    gReceivedGameInfo = data_0216fd30;
    if (ComputeU16Checksum(OFFSET_PTR(u16, gReceivedGameInfo, 8), 0x68) != 0) {
        return 0;
    }
    entryIndex = FindOrAddEntry((u8 *) scanBlock, callback);
    if (entryIndex < 0) {
        return 0;
    }
    UpdateEntryFromScan((u8 *) scanBlock, entryIndex, b);
    func_02008ff0(entryIndex, callback);
    return 1;
}

u32 func_020091fc(ScanBlock *scanBlock) {
    if ((scanBlock->mUnk_4b & 2) == 0 || scanBlock->mUnk_40 != 1) {
        return 0;
    }
    return 1;
}

#pragma thumb off

#pragma thumb on

void func_020091e0(u16 *scanBlock, u32 p1) {
    scanBlock[5] = 0x20u;
    scanBlock[6] = p1;
    scanBlock[7] = ((((p1) & (0xffff0000u))) >> 16);
    scanBlock[8] = (scanBlock[0x24]);
}

#pragma thumb off
