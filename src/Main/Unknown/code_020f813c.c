#include "Main/Unknown/code_020f813c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020be930.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"

static inline u32 func_020f8a04_inline(Unk020f41c4_B *random, u32 limit) {
    random->mUnk_00 = random->mUnk_08 * random->mUnk_00 + random->mUnk_10;
    if (limit == 0) {
        return random->mUnk_00 >> 32;
    } else {
        return ((random->mUnk_00 >> 32) * limit) >> 32;
    }
}

s32 PickItem(s32 kartVariant, s32 forcedRowHandle, s32 param_3, s32 param_4, s32 isEntryKart, s32 itemCount) {
    ItemSlotTable *table;
    Unk020f41c4_B *random;
    u16 *row;
    s32 variant;
    s32 i;
    u16 acc;
    s32 j;
    s32 x;
    s32 sel;
    s32 t;
    u16 roll;
    s32 objectKind;
    enum { K0 } u;

    sel = 0x13;
    if (forcedRowHandle != 0) {
        param_3 = (u16) (forcedRowHandle - 1);
        variant = 0;
        table = &data_0217bc74;
    } else {
        table = param_4 != 0 ? &data_0217bc6c : &data_0217bc64;
        param_3 = (u16) (param_3 - 1);
        variant = kartVariant;
    }
    row = table->mRows[param_3];
    acc = 0;
    t = 0;
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        for (i = 0; i < 0xe; i++) {
            t += (u16) (gItemKinds[(s32) i].mUnk_90 *
                        (gItemPools[(s32) i].mReservedCount - gItemPools[(s32) i].mUnk_18));
        }
    }
    for (j = 0; j < itemCount; j++) {
        objectKind = gItemInfos[(s32) j].mObjectKind;
        if (!((j == 8 && data_0217bc60 > 0) || (j == 7 && data_0217bc5c > 0) || (j == 0xf && data_0217bc58 > 0))) {
            if (gItemPools[objectKind].mLimit - gItemPools[objectKind].mReservedCount > 0 &&
                gItemInfos[(s32) j].mEnabled != FALSE) {
                x = gItemKinds[objectKind].mUnk_90 * gItemInfos[(s32) j].mObjectCount;
                if (x == 0 || x + t <= 0x28) {
                    if (j >= 9 && variant != 0) {
                        if (variant == 1) {
                            acc = acc + (row[j] >> 2);
                        } else {
                            acc = 3 * row[j] + acc;
                        }
                    } else {
                        acc = acc + row[j];
                    }
                }
            }
        }
        gItemWeightSums[j] = acc;
    }
    random = &gRaceProgress->mRandom;
    if (acc == 0) {
        x = 0;
    } else {
        x = func_020f8a04_inline(random, acc);
    }
    roll = x;
    for (j = 0; j < itemCount; j++) {
        if (roll < gItemWeightSums[j]) {
            sel = j;
            break;
        }
    }
    if (ReplaceUnavailableItem(&sel) != FALSE) {
        TryReleaseItemObjectsForItemInfo(sel);
    }
    if (isEntryKart != 0) {
        if (forcedRowHandle != 0) {
            gItemSlotSpinItemCount = 0;
            for (u = 0; u < itemCount; u++) {
                if (u == sel || row[u] != 0) {
                    gItemSlotSpinItems[gItemSlotSpinItemCount++] = u;
                }
            }
        } else {
            gItemSlotSpinItemCount = 0;
        }
    }
    return sel;
}

void InitItemSlot(KartItems *slot, KartItems *kartItems) {
    slot->mSelf = kartItems;
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
    slot->mIsPeer = gRaceSetup->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

void StartItemSlot(KartItems *slot, s32 forcedRowHandle, s32 rank, s32 isHumanGhostOrPeer, s32 shortSpin) {
    KartItems *kartItems;
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;
    BOOL isMode5;
    BOOL isEntryKart;

    kartItems = slot->mSelf;
    isMode5 = gRaceSetup->mMode == 5;
    if (slot->mSlotState != 0) {
        return;
    }
    if (slot->mActiveItem != 0x13) {
        return;
    }
    slot->mSlotState = 1;
    slot->mSlotShownItem = 0x13;
    if (!isMode5) {
        StopRaceRankListItemInUse(slot->mSelf->mKartIndex);
    }
    if (isMode5) {
        slot->mUnk_01c = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = 0x85;
        slot->mUnk_028 = 0x10;
        slot->mUnk_02c = 4;
    } else if (shortSpin != 0) {
        slot->mUnk_01c = TRUE;
        slot->mSlotFrames = 0x4d;
        slot->mSlotFrameCount = 0x65;
        slot->mUnk_028 = 8;
        slot->mUnk_02c = 3;
    } else {
        slot->mUnk_01c = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = 0xd5;
        slot->mUnk_028 = 0x10;
        slot->mUnk_02c = 4;
    }
    isEntryKart = kartItems->mKartIndex == gRaceSetup->mEntryIndex;
    if (kartItems->mItemInUse.mObjectKind != 0xf && kartItems->mItemInUse.mItemInfoIndex >= 9) {
        slot->mSlotResult = PickItem(0, forcedRowHandle, rank, isHumanGhostOrPeer, isEntryKart, 9);
    } else {
        slot->mSlotResult = PickItem(GetKartVariant(kartItems->mKartIndex), forcedRowHandle, rank, isHumanGhostOrPeer,
                                     isEntryKart, 0x12);
    }
    if (isMode5) {
        func_0205a750(slot->mSlotResult);
        slot->mResultPending = TRUE;
        return;
    }
    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount += itemInfo->mObjectCount;
}

void func_020f86c4(KartItems *slot) {
    KartItems *kartItems;
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;

    kartItems = slot->mSelf;
    if (kartItems->mActiveItem != 0x13) {
        kartItems->mActiveItem = 0x13;
    }
    if (slot->mSlotState != 0) {
        if (kartItems->mResultPending == FALSE) {
            itemIndex = kartItems->mSlotResult;
            itemInfo = &gItemInfos[itemIndex];
            objectKind = itemInfo->mObjectKind;
            pool = &gItemPools[objectKind];
            pool->mReservedCount -= itemInfo->mObjectCount;
        }
        kartItems->mSlotState = 0;
        kartItems->mSlotFrames = 0;
        kartItems->mSlotShownItem = 0x13;
        kartItems->mSlotResult = 0x13;
        kartItems->mActiveItem = 0x13;
        kartItems->mResultPending = FALSE;
    } else {
        if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
            ReleaseHeldItem(&kartItems->mHeldItem, 1);
        }
    }
    slot->mSlotState = 1;
    slot->mSlotFrames = 0;
    slot->mSlotFrameCount = 0x85;
    slot->mSlotShownItem = 0x13;
    slot->mActiveItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mResultPending = TRUE;
}

BOOL UpdateItemSlot(KartItems *slot, KartItems *kartItems) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } objectKind;
    s32 mode;
    u32 b;

    switch (slot->mSlotState) {
        case 1:
            slot->mSlotFrames++;
            mode = gRaceSetup->mMode;
            if (mode == 5 && slot->mResultPending != FALSE) {
                b = kartItems->mKartIndex & 0xff;
                if (func_0205a310(((u8 *) data_0217aa18)[b]) == 0) {
                    b = func_0205a2ac(((u8 *) data_0217aa18)[b]);
                    if (IsItemInfoObjectCountFree(b) != FALSE) {
                        TryReleaseItemObjectsForItemInfo(b);
                    }
                    itemInfo = &gItemInfos[b];
                    objectKind = itemInfo->mObjectKind;
                    pool = &gItemPools[objectKind];
                    pool->mReservedCount += itemInfo->mObjectCount;
                    slot->mSlotResult = b;
                    slot->mResultPending = FALSE;
                    slot->mSlotFrameCount += slot->mSlotFrames - 0x6f;
                } else if (slot->mSlotFrames > 0x6e) {
                    slot->mSlotFrames = 0x67;
                }
                return FALSE;
            }
            if (slot->mSlotFrames > 0x3c &&
                (((kartItems->mFlags & 0x241) == 0x241 && mode != 5 && slot->mUnk_01c == FALSE) ||
                 slot->mSlotFrames > slot->mSlotFrameCount)) {
                slot->mSlotFrames = 0;
                slot->mSlotState = 2;
            }
            break;
        case 2:
            slot->mSlotFrames++;
            if (slot->mSlotFrames > slot->mUnk_028 * 2) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void FinishItemSlot(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;

    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
}

void StopItemSlot(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;

    if (slot->mResultPending == FALSE) {
        itemIndex = slot->mSlotResult;
        itemInfo = &gItemInfos[itemIndex];
        objectKind = itemInfo->mObjectKind;
        pool = &gItemPools[objectKind];
        pool->mReservedCount -= itemInfo->mObjectCount;
    }
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
}

static inline u16 func_020f830c_inline(Unk020f41c4_B *random, u32 limit) {
    u32 value;
    if (limit == 0) {
        value = 0;
    } else {
        random->mUnk_00 = random->mUnk_08 * random->mUnk_00 + random->mUnk_10;
        if (limit == 0) {
            value = random->mUnk_00 >> 32;
        } else {
            value = ((random->mUnk_00 >> 32) * limit) >> 32;
        }
    }
    return value;
}

void PickItemSlotShownItem(KartItems *slot) {
    Unk020f41c4_B *random;
    s32 *items;
    u16 itemCount;
    u32 index;

    switch (slot->mSlotState) {
        case 0:
            return;
        case 1:
            if (gItemSlotSpinItemCount != 0) {
                itemCount = gItemSlotSpinItemCount;
                items = gItemSlotSpinItems;
            } else {
                itemCount = gItemSlotPossibleItemCount;
                items = gItemSlotPossibleItems;
            }
            random = &gRaceProgress->mLocalRandom;
            index = func_020f830c_inline(random, itemCount);
            if (slot->mSlotShownItem == items[index]) {
                index = (u16) (index + 1);
                if (index >= itemCount) {
                    index = 0;
                }
            }
            slot->mSlotShownItem = items[index];
            break;
        case 2:
            slot->mSlotShownItem = slot->mSlotResult;
            break;
    }
}

void func_020f82e8(s32 a) {
    data_0217bc60 = 1800;
    if (a != 0) {
        data_0217bc60 += 300;
    }
}

void func_020f82c4(s32 a) {
    data_0217bc5c = 1800;
    if (a != 0) {
        data_0217bc5c += 300;
    }
}

void func_020f82a4(s32 a) {
    data_0217bc58 = 0x384;
    if (a != 0) {
        data_0217bc58 += 0x12c;
    }
}

void func_020f8258(void) {
    if (data_0217bc60 > 0) {
        data_0217bc60 = data_0217bc60 - 1;
    }
    if (data_0217bc5c > 0) {
        data_0217bc5c = data_0217bc5c - 1;
    }
    if (data_0217bc58 > 0) {
        data_0217bc58 = data_0217bc58 - 1;
    }
}

void func_020f81c0(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;

    if (slot->mSelf->mKartIndex == gRaceSetup->mEntryIndex) {
        func_020bb5cc();
    }
    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
}

void SetActiveItem(KartItems *kartItems, u32 itemIndex) {
    kartItems->mActiveItem = itemIndex;
}

#pragma thumb on

u8 *LoadItemSlotTableData(ItemSlotTable *table, u8 *data) {
    s32 rowCount;
    s32 columnCount;
    s32 i;
    s32 j;
    u16(*tab)[0x12];

    rowCount = *data++;
    columnCount = *data++;
    table->mRowCount = rowCount;
    table->mRows = HeapAlloc(GetHeap(GetCurrentHeapCall()), (rowCount + 1) * 0x24);
    tab = table->mRows;
    for (i = 0; i < columnCount; i++) {
        for (j = 0; j < rowCount; j++) {
            tab[j][i] = *data++;
        }
        tab[j][i] = 0xffff;
    }
    return data;
}

#pragma thumb off

#pragma thumb on
u8 *ComputeItemSlotTableDataEnd(u8 *data) {
    return data + 2 + data[1] * data[0];
}
#pragma thumb off
