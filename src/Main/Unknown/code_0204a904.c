#include "Main/Unknown/code_0204a904.h"

void StartReadingKeyRecording(KeyRecording *record) {
    record->mPairIndex = 0x0u;
    record->mRepeatCount = 0x0u;
    record->mStatus = 0x2u;
}

void FinishReadingKeyRecording(KeyRecording *record) {
    record->mStatus = 0x0u;
}
