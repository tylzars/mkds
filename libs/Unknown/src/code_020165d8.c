#include "code_020165d8.h"
#include "code_02016638.h"

s32 CallQueueAddTail(CallQueue *p) {
    if (CallQueueIsFull(p) != 0) {
        return 0;
    }
    p->mTailIndex = CallQueueNextIndex(p, p->mTailIndex);
    p->mCount += 1;
    return 1;
}
