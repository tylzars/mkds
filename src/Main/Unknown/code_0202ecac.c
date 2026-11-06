#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_0202ecbc(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &NNS_SndArcPlayerStartSeqArc;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value0 = (u32) NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, value2);
    return value0;
}

u32 func_0202ecac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &func_0202ecbc;
    value1 = 0u;
    value0 = (u32) func_0202ecbc(value0, value1);
    return value0;
}
