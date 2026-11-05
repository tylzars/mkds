#include "00/code_0219cfc0.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c3e4.h"
#include "00/code_0219c954.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/code_0219cc00.h"
#include "00/code_0219d128.h"
#include "Main/Unknown/code_02152000.h"

#pragma opt_rebuildconditionals off

u32 func_ov000_0219d094(void *a, Unk0218ec44 *b) {
    s32 c;
    s32 d = 0;
    if (gWiFiBuddySync == NULL || func_ov000_0219c3e4() == 0) {
        return 0;
    }
    c = func_02152520((void *) func_ov000_0219c9c4(), a);
    if (c > 0 && GpGetBuddyIndex(gWiFiBuddySync->mGpConnection, c, &d) != 0) {
        return 0;
    }
    if (c <= 0 || d == -1) {
        return 0;
    }
    if (GpGetBuddyStatus(gWiFiBuddySync->mGpConnection, d, b) != 0) {
        return 0;
    }
    return 1;
}

// Maps a GP result 1 to 4 to (kind, code - 0x11558) and calls ReportBuddySyncError; returns the result, 0 passes
// through.
int ReportBuddySyncGpResult(int a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 11;
            c = -2;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -20;
            break;
    }
    ReportBuddySyncError(b, c - 0x11558);
    return a;
}

// Maps a GstatsConnect result (1, 2, 3, 5, 7, else 11 / -9) to (kind, code - 0x11940) and calls ReportBuddySyncError;
// returns the result.
int ReportBuddySyncStatsResult(int a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -30;
            break;
        case 3:
            b = 6;
            c = -20;
            break;
        case 5:
            b = 6;
            c = -40;
            break;
        case 7:
            b = 6;
            c = -70;
            break;
        default:
            b = 11;
            c = -9;
            break;
    }
    ReportBuddySyncError(b, c - 0x11940);
    return a;
}
