#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_02008d68(u32 entryIndex) {
    if (gReceivedGameInfo->mUnk_05 != gEntryTable->mEntries[entryIndex].mUnk_4b3) {
        func_0200895c(entryIndex);
        SetScanBssidFromEntry(entryIndex);
        gEntryTable->mEntries[entryIndex].mUnk_4b3 = gReceivedGameInfo->mUnk_05;
    }
}

void func_02008d30(u32 entryIndex) {
    if (gReceivedGameInfo->mUnk_06 != gEntryTable->mEntries[entryIndex].mUnk_4b4) {
        SetScanBssidFromEntry(entryIndex);
    }
}

void ExpireEntriesWithBssid(const u8 *bssid) {
    s32 i;
    u32 entryOffset;
    u32 zero;
    i = 0;
    entryOffset = 0;
    zero = 0;
    for (; i < 0x10; i++) {
        if (gEntryTable->mUsedMask & (1 << i)) {
            u8 *firstBssid = gEntryTable->mEntries[0].mBssid;
            u8 *entryBssid = firstBssid + entryOffset;
            if (bssid[0] == firstBssid[entryOffset] && bssid[1] == entryBssid[1] && bssid[2] == entryBssid[2] &&
                bssid[3] == entryBssid[3] && bssid[4] == entryBssid[4] && bssid[5] == entryBssid[5]) {
                *(s16 *) ((u8 *) gEntryTable + entryOffset + 0x59a) = zero;
            }
        }
        entryOffset += sizeof(EntryRecord);
    }
}

void func_02008c08(u32 entryIndex) {
    EntryRecord *entry;
    u8 *dataEnd;
    u8 *destination;
    Unk0216fc1c *gameInfo;
    u32 byteCount;
    entry = &gEntryTable->mEntries[entryIndex];
    dataEnd = &entry->mUnk_358;
    if (entry->mUnk_4b3 == gReceivedGameInfo->mUnk_05 && (entry->mUnk_580 & (1 << gReceivedGameInfo->mUnk_0a)) != 0) {
        return;
    }
    if (gReceivedGameInfo->mUnk_04 == 0) {
        destination = (u8 *) entry;
    } else {
        destination = entry->mUnk_220;
    }
    gameInfo = gReceivedGameInfo;
    destination += gameInfo->mUnk_0a * 0x62;
    byteCount = *(u8 *) &gameInfo->mUnk_0c;
    if (destination + byteCount > dataEnd) {
        return;
    }
    MIi_CpuCopy16(&gReceivedGameInfo->mUnk_0e, destination, byteCount);
    entry->mUnk_4b2 = gReceivedGameInfo->mUnk_04;
    entry->mUnk_580 |= 1 << gReceivedGameInfo->mUnk_0a;
    entry->mUnk_584 = (1 << gReceivedGameInfo->mUnk_0b) - 1;
}

void func_02008aa0(u32 entryIndex) {
    EntryRecord *entry;
    s32 i;
    u32 j;
    u8 *record;
    vu16 clearValue;
    u16 zero;
    entry = &gEntryTable->mEntries[entryIndex];
    if (entry->mUnk_4b4 != gReceivedGameInfo->mUnk_06) {
        if ((u8) (entry->mUnk_4b4 + 1) == gReceivedGameInfo->mUnk_06) {
            i = 0;
            record = entry->mUnk_35e;
            zero = 0;
            for (; i < 0xf; i++) {
                if (gReceivedGameInfo->mUnk_0e & (2 << i)) {
                    clearValue = zero;
                    MIi_CpuClear16(clearValue, record, 0x16);
                }
                record += 0x16;
            }
            *(u16 *) &entry->mUnk_588 &= ~gReceivedGameInfo->mUnk_0e;
            gEntryTable->mUnk_04 &= ~(1 << entryIndex);
        } else {
            vu16 v2 = 0;
            MIi_CpuClear16(v2, entry->mUnk_35e, 0x14a);
            entry->mUnk_588 = 0;
            gEntryTable->mUnk_04 &= ~(1 << entryIndex);
        }
        entry->mUnk_4b4 = gReceivedGameInfo->mUnk_06;
    } else if (entry->mUnk_588 == gReceivedGameInfo->mUnk_0c) {
        return;
    }
    entry->mUnk_358 = gReceivedGameInfo->mUnk_0a;
    entry->mUnk_35a = gReceivedGameInfo->mUnk_0c;
    entry->mUnk_35c = gReceivedGameInfo->mUnk_0e;
    entry->mUnk_588 |= 1;
    for (i = 0; i < 8; i++) {
        entry->mUnk_4a8[i] = gReceivedGameInfo->mUnk_68[i];
    }
    for (j = 0; j < 4; j++) {
        u32 recordNumber = gReceivedGameInfo->mUnk_10[j].mUnk_00_4;
        if (recordNumber != 0) {
            MIi_CpuCopy16(&gReceivedGameInfo->mUnk_10[j], &entry->mUnk_35e[(recordNumber - 1) * 0x16], 0x16);
            entry->mUnk_588 |= 1 << recordNumber;
        }
    }
}

void SetScanBssidFromEntry(u32 entryIndex) {
    if (gEntryTable->mUnk_06 == 0) {
        if (gSetBssidCallback != NULL) {
            gSetBssidCallback(gEntryTable->mEntries[entryIndex].mBssid);
        }
        gEntryTable->mUnk_0c = 0x16;
        gEntryTable->mUnk_06 = 1 << entryIndex;
        gEntryTable->mUnk_08 = 0x321;
    }
}

void ClearScanBssid(void) {
    if (gEntryTable->mUnk_06 != 0) {
        if (*gClearBssidCallback != 0) {
            (*gClearBssidCallback)();
        }
        gEntryTable->mUnk_0c = 1;
        gEntryTable->mUnk_06 = 0;
        gEntryTable->mUnk_0a = 0;
    }
}

void ClearEntry(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    gEntryTable->mUnk_02 &= ~entryBit;
    gEntryTable->mUnk_04 &= ~entryBit;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &gEntryTable->mEntries[entryIndex], sizeof(EntryRecord));
}

void func_0200895c(u32 entryIndex) {
    u32 entryBit = 1 << entryIndex;
    vu16 clearValue;
    gEntryTable->mUnk_02 &= ~entryBit;
    gEntryTable->mUnk_04 &= ~entryBit;
    gEntryTable->mEntries[entryIndex].mUnk_580 = 0;
    gEntryTable->mEntries[entryIndex].mUnk_584 = 0;
    gEntryTable->mEntries[entryIndex].mUnk_588 = 0;
    gEntryTable->mEntries[entryIndex].mUnk_58c = 0;
    clearValue = 0;
    MIi_CpuClear16(clearValue, &gEntryTable->mEntries[entryIndex], 0x4c0);
}

EntryRecord *GetEntryOrNull(u32 entryIndex) {
    if ((gEntryTable->mUnk_02 & (1 << entryIndex)) == 0) {
        return NULL;
    }
    return &gEntryTable->mEntries[entryIndex];
}

#pragma thumb off
