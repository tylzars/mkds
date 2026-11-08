#pragma once

#include "types.h"

typedef struct Unk021d1d88 Unk021d1d88;
typedef struct MessageFile MessageFile;

typedef struct MessagesPool {
    /* 00 */ u8 pad_00[0x60];
    /* 60 */ Unk021d1d88 *mFreeList;
} MessagesPool;

extern MessagesPool *gMessagesPool;

void *GetMessageEntry(MessageFile *messages, u32 index);
void ReleaseMessages(MessageFile *messages);
MessageFile *LoadMessages(void *path);
void FreeMessagesPool(void);
void InitMessagesPool(void);
