#include "03/code_021d2fa0.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d1d60.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214b824.h"
#include "code_0214d018.h"

void InitObjCharRanges(void) {
    s32 i;

    gObjCharRanges = AllocZeroedExpHeapBlock(0x340, 4);
    for (i = 0; i < 2; i++) {
        gObjCharRanges[i].mFreeRanges = CreateFilledPointerStack(0x20, &gObjCharRanges[i], 0xc);
        gObjCharRanges[i].mList = CreateNodeList();
        gObjCharRanges[i].mListStart.mStart = 0x300;
        gObjCharRanges[i].mListEnd.mStart = 0x400;
        func_ov003_021d2e50(gObjCharRanges[i].mList, &gObjCharRanges[i].mListStart);
        func_ov003_021d2e5c(gObjCharRanges[i].mList, &gObjCharRanges[i].mListEnd);
    }
}

ObjCharRange *CreateObjCharRange(u32 screen, s32 charCount, s32 fromFront, u32 *outStart) {
    ObjCharRange *range;
    ObjCharRange *node;
    ObjCharRange *neighbor;
    ObjCharRanges *ranges;
    s32 start;
    s32 unitCount;
    u32 savedIrqMask;

    range = PopPointerStack(gObjCharRanges[screen].mFreeRanges);
    unitCount = (charCount + 3 & ~3) >> 2;
    range->mLength = unitCount;
    savedIrqMask = OS_DisableIrqMask(1);
    if (fromFront != 0) {
        ranges = gObjCharRanges;
        node = &ranges[screen].mListStart;
        if (node != &ranges[screen].mListEnd) {
            do {
                neighbor = node->mNext;
                start = node->mStart + node->mLength;
                if (start + unitCount <= neighbor->mStart) {
                    range->mStart = start;
                    AddNodeBefore((u32) neighbor, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListEnd);
        }
        if (node == &gObjCharRanges[screen].mListEnd) {
            OS_Terminate();
        }
    } else {
        ranges = gObjCharRanges;
        node = &ranges[screen].mListEnd;
        if (node != &ranges[screen].mListStart) {
            do {
                neighbor = node->mPrev;
                start = node->mStart - unitCount;
                if (start >= neighbor->mStart + neighbor->mLength) {
                    range->mStart = start;
                    AddNodeBefore((u32) node, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListStart);
        }
        if (node == &gObjCharRanges[screen].mListStart) {
            OS_Terminate();
        }
    }
    *outStart = range->mStart;
    OS_EnableIrqMask(savedIrqMask);
    return range;
}

void DeleteObjCharRange(u32 range) {
    ObjCharRanges *ranges;
    s32 screen = 0;

    RemoveNodeFromList(range);
    ranges = gObjCharRanges;
    if (range >= (u32) ranges + 0x1a0) {
        screen = 1;
    }
    PushPointerStack(ranges[screen].mFreeRanges, (void *) range);
}

void InitOamBuffers(void) {
    OamBuffers *buffers = AllocExpHeapBlock(0x80c, 4);
    vu32 fillValue;
    s32 i;

    gOamBuffers = buffers;
    fillValue = 0x200;
    MIi_CpuClearFast(fillValue, buffers, 0x800);
    for (i = 0; i < 2; i++) {
        gOamBuffers->mFreeEntries[i] = CreateFilledPointerStack(0x40, gOamBuffers->mBuffers[i], 8);
    }
    gOamBuffers->mUploadTask = AddTask(1, UploadOamBuffers, NULL, 200);
}

void UploadOamBuffers(void) {
    DC_FlushRange((u8 *) gOamBuffers, 0x800);
    GX_LoadOAM(gOamBuffers->mBuffers[0], 0, 0x400);
    GXS_LoadOAM(gOamBuffers->mBuffers[1], 0, 0x400);
}
