#include "Main/Unknown/code_020ca984.h"

#include "Main/Unknown/code_020ca994.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

u32 GetEmblemChoisesInputSlot(void) {
    return 0x8u;
}

u16 func_020ca9c8(InputSlot *slot, u32 mask) {
    return slot->mUnk_00 & mask;
}

u16 func_020ca9ac(u32 slotIndex, u32 mask) {
    return func_020ca9c8(&data_02175628[slotIndex], mask);
}

u32 func_020ca994(u32 seqIndex, u32 seqArcNo) {
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

u32 StartEmblemChoisesSound(u32 seqIndex) {
    u32 value0 = seqIndex;
    u32 seqArcNo;
    u32 calleeAddress;
    calleeAddress = (u32) &func_020ca994;
    seqArcNo = 0u;
    value0 = func_020ca994(value0, seqArcNo);
    return value0;
}
