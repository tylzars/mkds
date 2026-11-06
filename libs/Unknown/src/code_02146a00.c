#include "code_02146a00.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_021458c4.h"

// Tag 11 callback: when a reply arrives, clears the request bit of CARDiCommon.mFlag and wakes CARDiCommon.mCurTh.
void CARDi_OnFifoRecv(u32 tag, u32 data, u32 err) {
    CARDiCommon *p;
    u32 value;

    if (tag != 0xb) {
        return;
    }
    if (err == 0) {
        return;
    }
    p = (CARDiCommon *) &gAccessState;
    value = p->mFlag;
    value = value & ~0x20;
    p->mFlag = value;
    OS_WakeupThreadDirect(p->mCurTh);
}
