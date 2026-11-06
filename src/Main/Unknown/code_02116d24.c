#include "Main/Unknown/code_02116d24.h"

#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

const u16 gWaitBnclIndices[4] = {0, 1, 2, 0};

void AdvanceWait(void) {
    u8 *q;
    Wait *p;

    gWait->mFrameIndexFrames++;
    if (gWait->mFrameIndexFrames >= 4) {
        gWait->mFrameIndex++;
        if (gWait->mFrameIndex >= 3) {
            gWait->mFrameIndex = 0;
        }
        gWait->mFrameIndexFrames = 0;
        func_02124748(gWaitBnclIndices[gWait->mFrameIndex], gWait->mNcer, gWait->mNcgr, gWait->mBncl, gWait->mUnk_20,
                      gWait->mDestinationBnclIndex, gWait->mDestinationNcer, gWait->mDestinationBncl);
        p = gWait;
        q = p->mNclr->mUnk_0c;
        switch (p->mUnk_20) {
            case 0:
                CallQueueAppend(0xe, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
            case 1:
                CallQueueAppend(0x1e, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
        }
    }
}

#pragma thumb off
