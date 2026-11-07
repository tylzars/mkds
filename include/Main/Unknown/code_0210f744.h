#pragma once

#include "types.h"
#include "code_0212bcac.h"

// Object gSeqVariableReadings: a signed halfword at 0x00, a signed halfword at 0x02, a signed word at 0x04 and four
// bytes at 0x08; GetSeqVariableSinceChangeFrames and IsSeqVariableChanged read the word at 0x04,
// UpdateSeqVariableReadings reads and writes all of them, and ResetSeqVariableReadings writes all of them.
typedef struct SeqVariableReading {
    /* 00 */ s16 mValue;
    /* 02 */ s16 mPrevValue;
    /* 04 */ s32 mSinceChangeFrames;
    /* 08 */ u8 mVariableNo[4];
} SeqVariableReading;

extern SeqVariableReading gSeqVariableReadings[];

void ResetSeqVariableReadings(void);
void UpdateSeqVariableReadings(NNSSndSeqPlayer **a);
u32 IsSeqVariableChanged(u32 a);
u32 GetSeqVariableSinceChangeFrames(u32 a);
