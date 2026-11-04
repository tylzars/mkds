#pragma once

#include "types.h"
#include "code_02016638.h" // CallQueueEntry

typedef struct CallQueue CallQueue;

CallQueueEntry *CallQueueGetTailEntry(u32 arg0);
CallQueueEntry *CallQueueGetHeadEntry(CallQueue *p);
