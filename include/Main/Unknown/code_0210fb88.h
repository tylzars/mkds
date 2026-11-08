#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217d000.h" // SeqPlayerControl
#include "code_0212bcac.h"

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps);
void func_0211003c(u32 soundId, NNSSndSeqPlayer **handle);
void func_0210fb88(SeqPlayerControl *control, NNSSndSeqPlayer **handle);
