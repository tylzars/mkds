#include "Main/Unknown/code_0204a9e4.h"

void func_0204a9f8(KeyRecording *record) {
    record->mBuffer = NULL;
}

void ResetKeyRecording(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = 0x0u;
}
