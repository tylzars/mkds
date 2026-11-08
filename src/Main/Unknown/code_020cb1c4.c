#include "Main/Unknown/code_020cb1c4.h"

#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1dc.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_020cb1dc(u32 seqIndex, u32 seqArcNo) {
    u32 value0 = seqIndex;
    u32 seqArcNoCopy = seqArcNo;
    u32 seqIndexCopy;
    u32 calleeAddress;
    calleeAddress = (u32) &NNS_SndArcPlayerStartSeqArc;
    seqIndexCopy = value0;
    value0 = (u32) &data_0217d068;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, seqArcNoCopy, seqIndexCopy);
    return value0;
}

u32 func_020cb1cc(u32 seqIndex) {
    u32 value0 = seqIndex;
    u32 seqArcNo;
    u32 calleeAddress;
    calleeAddress = (u32) &func_020cb1dc;
    seqArcNo = 0u;
    value0 = func_020cb1dc(value0, seqArcNo);
    return value0;
}

u32 func_020cb1c4(u16 *pair) {
    return pair[2];
}
