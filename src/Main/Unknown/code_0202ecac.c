#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 func_0202ecbc(u32 index, u32 archiveNo) {
    u32 value0 = index;
    u32 archiveNoCopy = archiveNo;
    u32 indexCopy;
    u32 calleeAddress;
    calleeAddress = (u32) &NNS_SndArcPlayerStartSeqArc;
    indexCopy = value0;
    value0 = (u32) &data_0217d068;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, archiveNoCopy, indexCopy);
    return value0;
}

u32 func_0202ecac(u32 index) {
    u32 value0 = index;
    u32 archiveNo;
    u32 calleeAddress;
    calleeAddress = (u32) &func_0202ecbc;
    archiveNo = 0u;
    value0 = func_0202ecbc(value0, archiveNo);
    return value0;
}
