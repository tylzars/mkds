#include "00/code_0219cc00.h"
#include "00/code_0219742c.h"
#include "00/code_02197000.h"
#include "00/code_0219c000.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d128.h"
#include "00/code_0219c93c.h"
#include "00/code_0219d934.h"

#include "00/code_0219c954.h"
#include "00/code_0219cb00.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/unk_021b4000.h"
#include "code_0200d118.h"
#include "code_02139f70.h"
#include "Main/Unknown/code_02152000.h"
#include "code_02152500.h"
#include "code_02152934.h"
#include "code_021522a0.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"

void func_ov000_0219ce48(GpConnection *a, Unk0219c400 *b, u32 c) {
    s32 i;
    s32 k;
    s32 n;
    if (b->mUnk_00 == 0 && b->mUnk_04 != 0 && func_02152a1c(&gWiFiBuddySync->mBuddies[c]) != 0) {
        if (gWiFiBuddySync->mState == 1) {
            gWiFiBuddySync->mBuddiesChanged = 1;
            for (i = 0; i < b->mUnk_04; i++) {
                if (func_ov000_0219d210(gWiFiBuddySync->mBuddies, c, b->mUnk_0c[i].mUnk_00) != FALSE) {
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->mUnk_1e = 1;
                    b->mUnk_08 = 0x601;
                    return;
                }
            }
            k = 0;
            for (i = 0; i < b->mUnk_04; i++) {
                ReportBuddySyncGpResult(GpGetBuddyIndex(a, b->mUnk_0c[i].mUnk_00, &n));
                if (n == ~k) {
                    AddBuddy(b->mUnk_0c[i].mUnk_00);
                } else {
                    func_02152468(&gWiFiBuddySync->mBuddies[c], b->mUnk_0c[0].mUnk_00);
                    DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[c]);
                    func_ov000_0219d504(c);
                    gWiFiBuddySync->mSyncIndex++;
                    gWiFiBuddySync->mUnk_1e = 1;
                    b->mUnk_08 = 0x601;
                    return;
                }
            }
            if (b->mUnk_08 != 0x600) {
                gWiFiBuddySync->mSyncIndex++;
                gWiFiBuddySync->mUnk_1e = 1;
            }
        }
    } else {
        if (b->mUnk_00 != 0) {
            if (ReportBuddySyncGpResult(b->mUnk_00) != 0) {
                return;
            }
        } else if (gWiFiBuddySync->mState == 1 || func_02152a1c(&gWiFiBuddySync->mBuddies[c]) == 0) {
            gWiFiBuddySync->mSyncIndex++;
            gWiFiBuddySync->mUnk_1e = 1;
        }
    }
}

void func_ov000_0219cd74(GpConnection *a, Unk0219c400 *b, u32 c) {
    GpConnection *h = a;
    s32 i;
    BOOL f;
    char s[0x18];
    u32 t;
    f = FALSE;
    i = 0;
    for (; i < gWiFiBuddySync->mBuddyEntryCount; i++) {
        if (func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 1) {
            DWC_LoginIdToUserName(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i], s);
            if (strcmp(s, (const char *) b->mUnk_8e) == 0) {
                func_ov000_0218ee1c(h, b->mUnk_04);
                func_02152468(&gWiFiBuddySync->mBuddies[i], b->mUnk_04);
                f = TRUE;
            }
        } else if (func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 3 ||
                   func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 2) {
            t = b->mUnk_04;
            if (t == DWC_GetGsProfileId(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i])) {
                func_ov000_0218ee1c(h, t);
                f = TRUE;
            }
        }
    }
    if (f != FALSE) {
        AddBuddy(b->mUnk_04);
    } else {
        func_ov000_0218ed74(h, b->mUnk_04);
    }
}

void func_ov000_0219cc94(GpConnection *a, Unk0219c400 *b, u32 c) {
    s32 i;
    BOOL f;
    char s[0x1c];
    u32 t;
    f = FALSE;
    i = 0;
    for (; i < gWiFiBuddySync->mBuddyEntryCount; i++) {
        if (func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 1) {
            DWC_LoginIdToUserName(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i], s);
            if (strcmp(s, (const char *) b->mUnk_8e) == 0) {
                func_02152468(&gWiFiBuddySync->mBuddies[i], b->mUnk_04);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[i]);
                f = TRUE;
            }
        } else if (func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 3 ||
                   func_02152a1c(&gWiFiBuddySync->mBuddies[i]) == 2) {
            t = b->mUnk_04;
            if (t == DWC_GetGsProfileId(func_ov000_0219c9c4(), &gWiFiBuddySync->mBuddies[i])) {
                func_02152468(&gWiFiBuddySync->mBuddies[i], t);
                DWCi_SetBuddyFriendData(&gWiFiBuddySync->mBuddies[i]);
                f = TRUE;
            }
        }
    }
    if (f != FALSE) {
        func_ov000_0219d504(
            func_ov000_0219d14c(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount, b->mUnk_04));
        gWiFiBuddySync->mBuddiesChanged = 1;
    }
}

void func_ov000_0219cc30(u32 a, u32 b, u32 c) {
    char s[0x40];
    RemovePendingStatsRequest();
    if (c == 0 || a != 0) {
        ReportBuddySyncError(6, -72200);
        return;
    }
    gWiFiBuddySync->mUnk_24 = b;
    OS_SNPrintf(s, 0x40, data_ov000_021b4068, gWiFiBuddySync->mUnk_28);
    func_ov000_0219cc00(gWiFiBuddySync->mUnk_24, 3, (u32) s, 0x80000001);
}

void func_ov000_0219cc00(u32 a, u32 b, u32 c, u32 d) {
    AddPendingStatsRequest();
    func_ov000_02197558(0, a, b, 0, c, (u32) &func_ov000_0219cb64, d);
}
