#include "Main/Unknown/code_020364e0.h"

#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"

u32 RunHeapCall(HeapCall *call, u32 argument) {
    u32 result;
    void *outerHeap;
    call->mParent = gCurrentHeapCall;
    if (call->mParent != NULL) {
        outerHeap = call->mParent->mHeap;
    } else {
        outerHeap = GetArenaHeap();
    }
    call->mHeap = CreateExpHeapFromMaxFree(outerHeap);
    gCurrentHeapCall = call;
    result = ((u32(*)(u32)) call->mFunc)(argument);
    if (call->mAfterFunc != 0) {
        ((void (*)(void)) call->mAfterFunc)();
    }
    gCurrentHeapCall = call->mParent;
    HeapDestroy(call->mHeap);
    call->mHeap = NULL;
    return result;
}

void *GetCurrentHeapCall(void) {
    return gCurrentHeapCall;
}

void *GetHeap(HeapCall *call) {
    return call->mHeap;
}
