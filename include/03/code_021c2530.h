#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;
typedef struct MessageFile MessageFile;

typedef struct MessagesPool {
    /* 00 */ u8 pad_00[0x60];
    /* 60 */ PointerStack *mFreeList;
} MessagesPool;

extern MessagesPool *gMessagesPool;

void *GetMessageEntry(MessageFile *messages, u32 index);
void ReleaseMessages(MessageFile *messages);
MessageFile *LoadMessages(void *path);
void FreeMessagesPool(void);
void InitMessagesPool(void);
