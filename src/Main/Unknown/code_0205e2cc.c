#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020431cc.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_021458c4.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"

#pragma opt_rebuildconditionals off

EmblemBlock *CreateEmblemBlock(void *heap) {
    EmblemBlock *emblemBlock = HeapAlloc(heap, 0xb04);
    if (emblemBlock != NULL) {
        emblemBlock->mBlockIndex = -1;
    }
    return emblemBlock;
}

BOOL CopyEmblemFromBlock(EmblemBlock *emblemBlock, u8 buddyIndex, EmblemData *emblemData) {
    BuddyRecord buddyRecord;
    u8 blockIndex;
    u8 slotIndex;
    blockIndex = buddyIndex / 5;
    slotIndex = buddyIndex % 5;
    if (blockIndex != emblemBlock->mBlockIndex) {
        return FALSE;
    }
    MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[buddyIndex], &buddyRecord, 0x24);
    if (buddyRecord.mFilled == 0 || buddyRecord.mUnk_22_2 == 0) {
        return FALSE;
    }
    emblemData->mUnk_200 = (emblemBlock->mUnk_04.mFilledBits & (1 << slotIndex)) != 0;
    if (emblemData->mUnk_200 != 0) {
        MI_CpuCopy8(emblemBlock->mUnk_04.mEmblems[slotIndex], emblemData, 0x200);
    }
    return TRUE;
}

void SetupEmblemBlock(EmblemBlock *emblemBlock, u8 buddyIndex) {
    u8 blockIndex = buddyIndex / 5;
    if (IsBitArrayBitSet(blockIndex, &data_0217aa08->mFirstBlock->mUnk_2c[2], 2) == 0) {
        emblemBlock->mBlockIndex = -1;
        return;
    }
    if (blockIndex == emblemBlock->mBlockIndex) {
        return;
    }
    ReadBackupEmblemBlock(&emblemBlock->mUnk_04, blockIndex);
    emblemBlock->mBlockIndex = blockIndex;
}

void CopyOtherPlayerEmblemsToBlocks(void) {
    u8 blockIndex;
    u16 playerIndex;
    Unk0217aa00_45c *playerEntry;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[8];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u16 k;
    s32 ownIndex;
    BOOL blockCreated = FALSE;
    s32 buddyIndex;
    u8 slotIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 8; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (data_0217aa00->mUnk_0000 == 2) {
            ownIndex = data_0217aa00->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        if (playerIndex != (u16) ownIndex) {
            if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[playerIndex])) == 0) {
                if ((data_0217aa00->mParticipantMask & (1 << playerIndex)) != 0) {
                    playerEntry = &data_0217aa00->mUnk_045c[playerIndex];
                    buddyIndex = SetBuddyRecordFromPlayer(playerEntry, 1);
                    if (buddyIndex != -1) {
                        if (playerEntry->mUnk_214 != 0) {
                            buddyIndexOfPlayer[playerIndex] = buddyIndex;
                            blockHasEmblem[buddyIndex / 5] = 1;
                        }
                    }
                }
            }
        }
    }
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = data_0217aa08->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, &data_0217aa08->mFirstBlock->mUnk_2c[2], 2) != 0) {
                ReadBackupEmblemBlock(blockData, blockIndex);
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                SetBitArrayBit(blockIndex, &data_0217aa08->mFirstBlock->mUnk_2c[2], 2);
                blockCreated = TRUE;
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            for (k = 0; k < 8; k++) {
                buddyIndex = buddyIndexOfPlayer[k];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    blockData->mFilledBits |= 1 << slotIndex;
                    MI_CpuCopy8((u8 *) &data_0217aa00->mUnk_045c[k] + 0x14, blockData->mEmblems[slotIndex], 0x200);
                }
            }
            WriteBackupEmblemBlock(blockData, blockIndex);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    if (blockCreated != FALSE) {
        WriteBackupFirstBlock(data_0217aa08->mFirstBlock);
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    ClearBackupBusy();
}

void CopyWiFiOtherEmblemsToBlocks(void) {
    u8 blockIndex;
    u16 playerIndex;
    Unk0217aa00_45c *playerRecordData;
    u8 blockHasEmblem[12];
    s8 buddyIndexOfPlayer[4];
    EmblemBlockData *blockData;
    s32 firstBuddyIndex;
    s32 endBuddyIndex;
    u8 slotIndex;
    u16 k;
    u8 *filledBits;
    s32 buddyIndex;
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        blockHasEmblem[blockIndex] = 0;
    }
    for (playerIndex = 0; playerIndex < 4; playerIndex++) {
        buddyIndexOfPlayer[playerIndex] = -1;
        if (playerIndex != func_ov000_0219bb50()) {
            playerRecordData = GetWiFiSessionPlayerRecordData(playerIndex & 0xff);
            if (playerRecordData != NULL) {
                buddyIndex = SetBuddyRecordFromPlayer(playerRecordData, 0);
                if (buddyIndex != -1) {
                    if (playerRecordData->mUnk_214 != 0) {
                        buddyIndexOfPlayer[playerIndex] = buddyIndex;
                        blockHasEmblem[buddyIndex / 5] = 1;
                    }
                }
            }
        }
    }
    WriteBackupBuddyRecordBlock(data_0217aa08->mBuddyRecordBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    for (blockIndex = 0; blockIndex < 12; blockIndex++) {
        if (blockHasEmblem[blockIndex] != 0) {
            blockData = data_0217aa08->mEmblemBlockData;
            if (IsBitArrayBitSet(blockIndex, &data_0217aa08->mFirstBlock->mUnk_2c[2], 2) != 0) {
                ReadBackupEmblemBlock(blockData, blockIndex);
                if (gBackupAccess->mBackupEnabled != 0) {
                    CARD_WaitBackupAsync();
                }
            } else {
                MI_CpuFill8(blockData, 0, 0xb00);
                SetBitArrayBit(blockIndex, &data_0217aa08->mFirstBlock->mUnk_2c[2], 2);
            }
            firstBuddyIndex = blockIndex * 5;
            endBuddyIndex = (blockIndex + 1) * 5;
            filledBits = (u8 *) blockData + 4;
            for (k = 0; k < 4; k++) {
                buddyIndex = buddyIndexOfPlayer[k];
                if (buddyIndex >= firstBuddyIndex && buddyIndex < endBuddyIndex) {
                    slotIndex = buddyIndex % 5;
                    *filledBits = *filledBits | (1 << slotIndex);
                    MI_CpuCopy8((u8 *) GetWiFiSessionPlayerRecordData(k & 0xff) + 0x14, blockData->mEmblems[slotIndex],
                                0x200);
                }
            }
            WriteBackupEmblemBlock(blockData, blockIndex);
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    ClearBackupBusy();
}

static inline s32 func_0205e5c4_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void StartCopyOtherEmblems(s32 useConnection) {
    void (*copyFunction)(void);
    BOOL connectionReady;
    s32 d;
    if (useConnection != 0) {
        connectionReady = FALSE;
        d = func_0205e5c4_inline();
        if (d != 0) {
            if (data_0217aa00->mUnk_0004 != 13) {
                connectionReady = TRUE;
            }
        }
        if (connectionReady == FALSE) {
            return;
        }
        copyFunction = CopyOtherPlayerEmblemsToBlocks;
    } else {
        d = 0;
        if (gWiFiSession != NULL) {
            if (gWiFiSession->mHeapCreated != FALSE) {
                d = 1;
            }
        }
        if (d == 0) {
            return;
        }
        copyFunction = CopyWiFiOtherEmblemsToBlocks;
    }
    SetBackupBusy();
    QueueThreadFunction(copyFunction);
    gThreadFunctionQueue->mRunRequested = 1;
}

static inline u8 func_0205e548_inline(void *recordOut) {
    u8 filledCount = 0;
    u8 recordIndex = 0;
    do {
        if (recordOut != 0) {
            MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[recordIndex], recordOut, 0x24);
        }
        if (data_0217aa08->mBuddyRecordBlock->mRecords[recordIndex].mFilled != 0) {
            filledCount = filledCount + 1;
        }
        recordIndex = recordIndex + 1;
    } while (recordIndex < 60);
    return filledCount;
}

u8 CountEmblemEntries(void) {
    return func_0205e548_inline(0);
}

#pragma thumb on

void func_0205e530(void) {
    InitGhostScene(GetHeap(GetCurrentHeapCall()));
}

void func_0205e528(void) {
    ReleaseGhostScene();
}

void func_0205e520(void) {
    func_0202dec8();
}

void func_0205e518(u32 sceneNumbers) {
    AdvanceGhostScene(sceneNumbers);
}

s32 RunGhostScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = data_021653c0;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}

#pragma thumb off

static inline s32 func_0205e2cc_inline(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void CreateShapeMapObjectCountList(void *heap) {
    u16 shapeCount;
    u16 i;
    u16 entryIndex;
    u16 shapeIndex;
    u16 entryCount;
    CourseMapShape *courseMapShape;
    ShapeMapObjectCount *entry;
    s32 u;
    s32 v;
    s32 w;
    s32 y;
    shapeCount = gCourseMap->mShapeCount;
    entryCount = 0;
    data_0217aa24 = HeapAlloc(heap, 8);
    for (i = 0; i < shapeCount; i++) {
        if (GetCourseMapShape(i)->mKind == 5) {
            entryCount = entryCount + 1;
        }
    }
    if (entryCount != 0) {
        data_0217aa24->mEntries = HeapAlloc(heap, entryCount * 0xc);
    }
    entryIndex = 0;
    data_0217aa24->mEntryCount = entryCount;
    for (shapeIndex = 0; shapeIndex < shapeCount; shapeIndex++) {
        courseMapShape = GetCourseMapShape(shapeIndex);
        if (courseMapShape->mKind == 5) {
            entry = &data_0217aa24->mEntries[entryIndex];
            entry->mShapeIndex = shapeIndex;
            u = 0;
            switch (courseMapShape->mShapeKind) {
                case 0:
                    u = func_0205e2cc_inline(func_020431cc(), courseMapShape->mScale.x);
                    v = func_0205e2cc_inline(func_020431d4(), courseMapShape->mScale.y) >> 1;
                    y = func_0205e2cc_inline(func_020431cc(), courseMapShape->mScale.z);
                    w = func_0205e2cc_inline(u, u) + func_0205e2cc_inline(v, v);
                    y = func_0205e2cc_inline(y, y);
                    u = FX_Sqrt(y + w);
                    break;
                case 1:
                    u = func_0205e2cc_inline(func_020431dc(), courseMapShape->mScale.x);
                    break;
            }
            entry->mRadius = u;
            entry->mMapObjectCount = 0;
            entry->mIncreaseCount = 0;
            entryIndex = entryIndex + 1;
        }
    }
}
