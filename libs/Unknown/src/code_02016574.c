#include "code_02016574.h"
#include "code_02016638.h"

s32 CallQueueRemoveHead(CallQueue *p) {
    if (CallQueueIsEmpty(p) != 0) {
        return 0;
    }
    p->mHeadIndex = CallQueueNextIndex(p, p->mHeadIndex);
    p->mCount -= 1;
    return 1;
}
