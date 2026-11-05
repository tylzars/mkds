#include "code_020165b8.h"
#include "code_02016638.h"

CallQueueEntry *CallQueueGetHeadEntry(CallQueue *p) {
    return p->mEntries + p->mHeadIndex;
}

CallQueueEntry *CallQueueGetTailEntry(CallQueue *arg0) {
    return arg0->mEntries + arg0->mTailIndex;
}
