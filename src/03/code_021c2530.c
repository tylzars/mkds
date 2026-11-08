#include "03/code_021c2530.h"
#include "03/code_021c250c.h"
#include "03/code_021d1cd4.h"
#include "03/unk_021da000.h"

#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1d60.h"

void InitMessagesPool(void) {
    gMessagesPool = AllocExpHeapBlock(sizeof(MessagesPool), 4);
    gMessagesPool->mFreeList = CreateFilledPointerStack(8, gMessagesPool, 12);
}

void FreeMessagesPool(void) {
    FreeExpHeapBlockAndClearPointer(&gMessagesPool);
}

MessageFile *LoadMessages(void *path) {
    MessageFile *messages;
    u8 *section;
    u32 size;
    messages = PopPointerStack(gMessagesPool->mFreeList);
    messages->mFile = LoadFile(path, &size, 4);
    section = messages->mFile + 0x20;
    messages->mOffsets = OFFSET_PTR(u32, section, 0x10);
    messages->mData = section + *OFFSET_PTR(s32, section, 4) + 8;
    return messages;
}

void ReleaseMessages(MessageFile *messages) {
    DeleteLoadedFile(messages->mFile);
    PushPointerStack(gMessagesPool->mFreeList, messages);
}

void *GetMessageEntry(MessageFile *messages, u32 index) {
    return messages->mData + messages->mOffsets[index & 0x0000ffffu];
}
