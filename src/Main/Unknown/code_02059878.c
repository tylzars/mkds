#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

s32 RunResultScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks resultSceneCallbacks = gResultSceneCallbacks;

    RunScene(sceneNumbers, &resultSceneCallbacks);
    return 0;
}

#pragma thumb on

static inline u32 func_02059878_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02059878_inline2(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

u32 IsAllMPChunksReceived(u32 slot) {
    u32 chunkCount;
    u8 *receivedFlags;
    u32 allReceived;
    u32 chunkIndex;

    receivedFlags = data_0217aa00->mChunkReceivedFlags[slot];
    allReceived = 1;
    if (func_02059878_inline() == 1) {
        chunkCount = 0x12;
    } else {
        chunkCount = 2;
    }
    for (chunkIndex = 0; chunkIndex < chunkCount; chunkIndex++) {
        if (receivedFlags[chunkIndex] == 0) {
            allReceived = 0;
            break;
        }
    }
    return allReceived;
}

void ProcessMPChunk(u8 *chunk) {
    u32 playerIndex;
    Unk0217aa00_45c *entry;
    u32 finished;
    u32 byteOffset;
    u16 ownIndex;
    u8 playerBit;

    playerIndex = chunk[0];
    entry = &data_0217aa00->mUnk_045c[playerIndex];
    finished = 0;
    if (func_02059878_inline() == 1) {
        byteOffset = chunk[1] << 5;
    } else {
        byteOffset = chunk[1] * 0x168;
    }
    switch (chunk[1]) {
        case 0xff:
            if (func_02059878_inline() == 2) {
                func_02059878_inline2(9);
            }
            break;
        case 0xfe:
            if (func_02059878_inline() == 2) {
                data_0217aa00->mUnk_043a = *(u16 *) (chunk + 2);
            }
            break;
        case 0xfd:
            if (func_02059878_inline() == 1) {
                data_0217aa00->mUnk_162a |= 1 << playerIndex;
                if (data_0217aa00->mUnk_0044.mChildMask ==
                    (data_0217aa00->mUnk_0044.mChildMask & data_0217aa00->mUnk_162a)) {
                    func_02059878_inline2(10);
                }
            }
            break;
        case 0xfc:
            data_0217aa00->mUnk_045c[playerIndex].mUnk_214 = 0;
            finished = 1;
            break;
        default:
            MI_CpuCopy8(chunk + 4, entry->mUnk_000 + byteOffset, *(u16 *) (chunk + 2));
            data_0217aa00->mChunkReceivedFlags[chunk[0]][chunk[1]] = 1;
            if (IsAllMPChunksReceived(chunk[0]) != 0) {
                finished = 1;
            }
            break;
    }
    if (finished != 0) {
        playerBit = 1U << chunk[0];
        if (func_02059878_inline() == 1) {
            if (QueueMPChunk(0xff, NULL, 0, 0, playerBit) != FALSE) {
                data_0217aa00->mUnk_162a |= 1 << chunk[0];
                return;
            }
        } else {
            data_0217aa00->mUnk_162a |= 1 << chunk[0];
            if (data_0217aa00->mUnk_043a == (data_0217aa00->mUnk_043a & data_0217aa00->mUnk_162a)) {
                ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                if (QueueMPChunk(0xfd, NULL, 0, ownIndex, 1) != FALSE) {
                    func_02059878_inline2(10);
                }
            }
        }
    }
}

void func_02059920(Unk02059920 *a) {
    if (a->mUnk_02 == 0 && a->mUnk_0c != NULL && a->mUnk_10 >= 4) {
        DC_StoreRange(a->mUnk_0c, a->mUnk_10);
        switch (a->mUnk_04) {
            case 7:
            case 9:
                break;
            case 0x15:
                ProcessMPChunk(a->mUnk_0c);
                break;
        }
    }
}

void func_02059878(void) {
    ConnectionWork *p;
    u32 v;

    InitStateMachine(&data_0217aa00->mUnk_1608, gMPStateTable, 0x17, NULL);
    data_0217aa00->mUnk_164e = 0;
    data_0217aa00->mUnk_1608.mUnk_14 = 0;
    data_0217aa00->mUnk_1608.mUnk_1a = 0;
    data_0217aa00->mEntryChunkIndex = 0;
    data_0217aa00->mUnk_162a = 0;
    data_0217aa00->mUnk_164c = 0;
    p = data_0217aa00;
    v = 0;
    if (p != NULL) {
        v = p->mUnk_0000;
    }
    if (v == 1) {
        p->mUnk_0044.mUnk_42 = (p->mUnk_0454 & 0x40) != 0 ? p->mUnk_1695 : p->mUnk_0044.mChildMask;
    }
    data_0217aa00->mUnk_1eb0 = 0;
}

#pragma thumb off
