#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_0204a978(KeyRecording *a) {
    if (a->mBuffer == NULL) {
        return;
    }
    if (a->mUnk_0c == FALSE) {
        if (a->mBuffer != NULL) {
            MI_CpuFill8(a->mBuffer, 0, 0xdcc);
        }
        a->mUnk_0c = TRUE;
    }
    a->mBuffer->mUnk_00 = 0;
    a->mUnk_0c = FALSE;
    a->mPairIndex = 0;
    a->mRepeatCount = 0;
    a->mStatus = 1;
}
