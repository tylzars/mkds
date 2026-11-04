#include "code_020165b8.h"
#include "code_02016638.h"

CallQueueEntry *CallQueueGetHeadEntry(CallQueue *p) {
    return p->mEntries + p->mHeadIndex;
}

CallQueueEntry *CallQueueGetTailEntry(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) * (const u16 *) ((value0) + (10));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + ((value1 << 4));
    return (CallQueueEntry *) value0;
}
