#include "00/code_0219cb00.h"
#include "00/code_0219d934.h"
#include "00/code_0219d128.h"

#pragma opt_propagation off

void func_ov000_0219cb64(u32 a, u32 b, s32 c, u32 d, s32 e, u32 f, u32 g) {
    u32 t;
    t = g;
    func_ov000_0219cb00();
    if (t == 0x80000001) {
        if (e != 0) {
            if (gWiFiBuddySync->mState == 1) {
                gWiFiBuddySync->mCompletedParts++;
            } else {
                t = 0;
            }
        } else {
            ReportBuddySyncError(6, -72220);
        }
    }
    if ((t & 0x80000000) == 0) {
        if (e != 0) {
            if (gWiFiBuddySync->mUnk_4c != NULL) {
                gWiFiBuddySync->mUnk_4c(1, (u32) (c - 2) <= 1 ? 1 : 0, g);
            }
        } else {
            ReportBuddySyncError(6, -72220);
            if (gWiFiBuddySync->mUnk_4c != NULL) {
                gWiFiBuddySync->mUnk_4c(0, 0, g);
            }
        }
    }
}

void func_ov000_0219cb30(void) {
    WiFiBuddySync *p = gWiFiBuddySync;
    if (p->mPendingStatsRequestCount == -1) {
        ReportBuddySyncError(0xb, -70009);
        return;
    }
    p->mPendingStatsRequestCount++;
}

void func_ov000_0219cb00(void) {
    WiFiBuddySync *p = gWiFiBuddySync;
    if (p->mPendingStatsRequestCount == 0) {
        ReportBuddySyncError(0xb, -70009);
        return;
    }
    p->mPendingStatsRequestCount--;
}
