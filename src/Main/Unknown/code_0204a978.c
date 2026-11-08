#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void StartKeyRecording(KeyRecording *record) {
    if (record->mBuffer == NULL) {
        return;
    }
    if (record->mUnk_0c == FALSE) {
        if (record->mBuffer != NULL) {
            MI_CpuFill8(record->mBuffer, 0, 0xdcc);
        }
        record->mUnk_0c = TRUE;
    }
    record->mBuffer->mUnk_00 = 0;
    record->mUnk_0c = FALSE;
    record->mPairIndex = 0;
    record->mRepeatCount = 0;
    record->mStatus = 1;
}
