#include "Main/Unknown/code_02008e10.h"
#include "code_0214cfe4.h"

#pragma thumb on

s32 FindOrAddEntry(const u8 *scanBlock, EntryCallbackFunc callback) {
    s32 i;
    EntryTable *entryTable;
    EntryRecord *entry;
    u16 usedMask;
    i = 0;
    entryTable = gEntryTable;
    entry = entryTable->mEntries;
    for (; i < 0x10; i++) {
        u32 entryBit = 1 << i;
        usedMask = entryTable->mUsedMask;
        if ((usedMask & entryBit) != 0 && entry->mUnk_4b8 == gReceivedGameInfo->mUnk_00 &&
            entry->mBssid[0] == scanBlock[4] && entry->mBssid[1] == scanBlock[5] && entry->mBssid[2] == scanBlock[6] &&
            entry->mBssid[3] == scanBlock[7] && entry->mBssid[4] == scanBlock[8] && entry->mBssid[5] == scanBlock[9] &&
            gReceivedGameInfo->mUnk_04_2 == entryTable->mEntries[i].mUnk_4b5) {
            if ((entryTable->mUnk_04 & entryBit) == 0) {
                SetScanBssidFromEntry(i);
            }
            return i;
        }
        entry++;
    }
    i = 0;
    usedMask = *(u16 *) entryTable;
    for (; i < 0x10; i++) {
        u32 entryBit = 1 << i;
        if ((usedMask & entryBit) == 0) {
            MIi_CpuCopy16(scanBlock, entryTable->mEntries[i].mScanBuffer, 0xc0);
            gEntryTable->mEntries[i].mUnk_4b3 = gReceivedGameInfo->mUnk_05;
            gEntryTable->mUsedMask |= (u16) entryBit;
            SetScanBssidFromEntry(i);
            return i;
        }
    }
    if (callback != NULL) {
        callback(4, NULL, 0);
    }
    return -1;
}

void func_02008ff0(u32 entryIndex, EntryCallbackFunc callback) {
    EntryRecord *entry;
    u32 entryBit;
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->mUnk_580 == entry->mUnk_584 && entry->mUnk_580 != 0 && entry->mUnk_35a != 0 &&
        entry->mUnk_588 == entry->mUnk_35a) {
        entryBit = 1 << entryIndex;
        if ((gEntryTable->mUnk_04 & entryBit) == 0) {
            gEntryTable->mUnk_04 |= entryBit;
            gEntryTable->mUnk_02 |= entryBit;
            ClearScanBssid();
            if (callback != NULL) {
                callback(1, entry, entryIndex);
            }
        }
    } else {
        entryBit = 1 << entryIndex;
        if ((gEntryTable->mUnk_04 & entryBit) != 0) {
            gEntryTable->mUnk_04 ^= entryBit;
            if (callback != NULL) {
                callback(2, entry, entryIndex);
            }
        }
    }
}

void UpdateEntryTimers(EntryCallbackFunc callback, u32 b) {
    u32 stopFollowing;
    s32 i;
    u32 entryOffset;
    stopFollowing = 0;
    i = 0;
    entryOffset = 0;
    for (; i < 0x10; i++) {
        EntryRecord *entry = OFFSET_PTR(EntryRecord, gEntryTable->mEntries, entryOffset);
        u16 entryBit = 1 << i;
        if (gEntryTable->mUsedMask & entryBit) {
            entry->mTimer -= gEntryTable->mUnk_0c;
            if (entry->mTimer < 0) {
                entry->mTimer = 0;
                if ((gEntryTable->mUnk_04 & entryBit) != 0 && callback != NULL) {
                    callback(3, NULL, i);
                }
                if ((gEntryTable->mUnk_06 & entryBit) != 0) {
                    stopFollowing = 1;
                }
                gEntryTable->mUsedMask &= ~entryBit;
                ClearEntry(i);
            }
        }
        entryOffset += sizeof(EntryRecord);
    }
    if (gEntryTable->mUnk_06 != 0 && gEntryTable->mUnk_08 > 0) {
        gEntryTable->mUnk_08 -= gEntryTable->mUnk_0c;
        if (gEntryTable->mUnk_08 < 0) {
            stopFollowing = 1;
        } else if (b == 0) {
            gEntryTable->mUnk_0a++;
            if (gEntryTable->mUnk_0a > 4) {
                stopFollowing = 1;
            }
        } else {
            gEntryTable->mUnk_0a = 0;
        }
    }
    if (stopFollowing != 0) {
        gEntryTable->mUnk_08 = 0;
        ClearScanBssid();
    }
}

void UpdateEntryFromScan(u8 *scanBlock, u32 entryIndex, u32 c) {
    EntryRecord *entry;
    ReplaceEntryIfChanged(scanBlock, entryIndex);
    func_02008d68(entryIndex);
    func_02008d30(entryIndex);
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->mLastSequence == gReceivedGameInfo->mSequence) {
        entry->mSequenceRepeats++;
        if (entry->mSequenceRepeats > 3) {
            entry->mTimer = 0;
            ExpireEntriesWithBssid(entry->mBssid);
            return;
        }
    } else {
        entry->mSequenceRepeats = 0;
    }
    entry->mLastSequence = gReceivedGameInfo->mSequence;
    entry->mTimer = 0x1771;
    entry->mUnk_4b8 = gReceivedGameInfo->mUnk_00;
    entry->mUnk_4b5 = gReceivedGameInfo->mUnk_04_2;
    entry->mUnk_58c = c;
    func_020091e0((u16 *) entry->mScanBuffer, entry->mUnk_4b8);
    if (gReceivedGameInfo->mUnk_04 == 2) {
        func_02008aa0(entryIndex);
    } else {
        func_02008c08(entryIndex);
    }
}

#pragma thumb off
