#include "Main/Unknown/code_02036588.h"

void InitHeapCall(HeapCall *call, u32 func) {
    call->mUnk_00 = 0;
    call->mFunc = func;
    call->mAfterFunc = 0;
    call->mParent = NULL;
    call->mHeap = NULL;
}

void SetHeapCallFunc(HeapCall *call, u32 func) {
    call->mFunc = func;
}
