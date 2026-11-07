#include "Main/Unknown/code_020cb1c4.h"

#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1dc.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_020cb1dc(u32 seqIndex, u32 seqArcNo) {
    u32 value0 = seqIndex;
    u32 value1 = seqArcNo;
    u32 value2;
    u32 value12;
    value12 = (u32) &NNS_SndArcPlayerStartSeqArc;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, value2);
    return value0;
}

u32 func_020cb1cc(u32 seqIndex) {
    u32 value0 = seqIndex;
    u32 value1;
    u32 value12;
    value12 = (u32) &func_020cb1dc;
    value1 = 0u;
    value0 = func_020cb1dc(value0, value1);
    return value0;
}

u32 func_020cb1c4(u16 *pair) {
    return pair[2];
}
