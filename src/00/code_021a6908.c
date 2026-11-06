#include "00/code_021a6908.h"
#include "ITCM/code_01ff8000.h"

u32 func_ov000_021a6908(OSMutex *a) {
    if (a->mHolder == NULL) {
        a->mHolder = (struct OSThread *) func_01ff8000;
        a->mLockCount = a->mLockCount + 1;
        return 1;
    }
    if (a->mHolder == (struct OSThread *) func_01ff8000) {
        a->mLockCount = a->mLockCount + 1;
        return 1;
    }
    return 0;
}
