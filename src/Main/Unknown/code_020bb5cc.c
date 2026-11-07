#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_02108e6c.h"
#include "code_0212bcac.h"

void func_020bb5cc(void) {
    NNSSndSeqPlayer **seqPlayer;
    seqPlayer = GetSndHandles();
    NNS_SndPlayerStopSeq(seqPlayer, 0);
}
