#include "03/code_021d2ecc.h"
#include "03/code_021d1cd4.h"
#include "Main/Unknown/code_0214d000.h"

#include "03/code_021d2fa0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"
#include "code_0214d018.h"

void ReleaseOamBuffers(void) {
    RemoveTaskEntryWrapper(1, gOamBuffers->mUploadTask);
    FreeExpHeapBlockAndClearPointer(&gOamBuffers);
}

OamEntry *CreateOamEntry(int screen, u8 *source) {
    OamEntry *entry;
    entry = PopPointerStack(gOamBuffers->mFreeEntries[screen]);
    MIi_CpuCopy32(source, entry, 8);
    return entry;
}

void DeleteOamEntry(u32 *entry) {
    OamBuffers *buffers;
    s32 screen = 0;

    *entry = (*entry & 0xc1fffcff) | 0x200;
    buffers = gOamBuffers;
    if ((u32) entry >= (u32) buffers + 0x400) {
        screen = 1;
    }
    PushPointerStack(buffers->mFreeEntries[screen], entry);
}

OamEntry *GetOamBufferEntry(int screen, int index) {
    return (OamEntry *) (&gOamBuffers->mBuffers[screen][index * 8]);
}

void *CreateNodeList(void) {
    u32 header = ((u32) AllocExpHeapBlock(0x10u, 0x4u));
    u32 firstEndNode;
    u32 lastEndNode;
    *(u32 *) ((header) + (0)) = 0x0u;
    firstEndNode = ((header) + (0x0u));
    lastEndNode = ((firstEndNode) + (0x8u));
    *(u32 *) ((header) + (4)) = lastEndNode;
    *(u32 *) ((header) + (8)) = header;
    *(u32 *) ((header) + (12)) = 0x0u;
    return (void *) header;
}
