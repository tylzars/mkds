#include "00/code_0219d128.h"

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219cb00.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "00/code_0219cc00.h"
#include "00/code_0218f15c.h"
#include "code_02139f70.h"
#include "00/code_0219d934.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"
#include "code_0214d018.h"
#include "00/code_0219c954.h"
#include "00/code_0219cfc0.h"
#include "00/code_02197000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "code_021522a0.h"
#include "code_02152934.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_0219caac.h"
#include "00/code_0219742c.h"
#include "code_02152a24.h"

// Stores the callback and its argument in mBuddyChangedCallback / mBuddyChangedCallbackArg of gWiFiBuddySync when the
// object exists.
void SetBuddyChangedCallback(void *first, void *second) {
    if (gWiFiBuddySync != NULL) {
        gWiFiBuddySync->mBuddyChangedCallback = first;
        gWiFiBuddySync->mBuddyChangedCallbackArg = second;
    }
}

// Runs from InitWiFiConnection, per login.
void InitBuddySync(WiFiBuddySync *a, struct GpConnection *b, char *c, Unk02152490 *d, s32 e) {
    WiFiBuddySync *q;
    gWiFiBuddySync = a;
    a->mState = 0;
    gWiFiBuddySync->mGpConnection = b;
    gWiFiBuddySync->mPollCount = 0;
    q = gWiFiBuddySync;
    q->mLastPollTime = 0;
    q->mBuddyEntryCount = e;
    gWiFiBuddySync->mBuddies = d;
    gWiFiBuddySync->mSyncIndex = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mUnk_1e = 0;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mPendingStatsRequestCount = 0;
    gWiFiBuddySync->mUnk_24 = 0;
    gWiFiBuddySync->mUnk_28 = c;
    gWiFiBuddySync->mResultCallback = NULL;
    gWiFiBuddySync->mResultCallbackArg = NULL;
    gWiFiBuddySync->mBuddyStatusCallback = NULL;
    gWiFiBuddySync->mBuddyStatusCallbackArg = NULL;
    gWiFiBuddySync->mEntryMergedCallback = NULL;
    gWiFiBuddySync->mEntryMergedCallbackArg = NULL;
    gWiFiBuddySync->mBuddyChangedCallback = NULL;
    gWiFiBuddySync->mBuddyChangedCallbackArg = NULL;
    gWiFiBuddySync->mUnk_4c = NULL;
    gWiFiBuddySync->mUnk_50 = 0;
}

// Also the only pump of the GP connection: every call in states 3 to 6 reaches func_ov000_0219d49c, which calls
// GpUpdate every 300 ms, whether or not a sync was started; the list part runs after more than 7 polls.
void UpdateBuddySync(void) {
    if (gWiFiBuddySync == NULL) {
        return;
    }
    if (gWiFiBuddySync->mBuddies == NULL) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (GetPendingStatsRequestCount() != 0 && func_ov000_0219746c() == FALSE) {
        ReportBuddySyncError(6, -0x1194a);
        return;
    }
    if (gWiFiBuddySync->mGpConnection != NULL && gWiFiBuddySync->mGpConnection->mGpiConnection != NULL) {
        if (ReportBuddySyncGpResult(func_ov000_0219d49c()) != 0) {
            return;
        }
        if (gWiFiBuddySync->mBuddies != NULL && gWiFiBuddySync->mUnk_1e != 3 && gWiFiBuddySync->mPollCount > 7) {
            if (gWiFiBuddySync->mUnk_1e <= 1) {
                func_ov000_0219d2e8(gWiFiBuddySync->mBuddies, gWiFiBuddySync->mBuddyEntryCount);
            }
            if (gWiFiBuddySync->mSyncIndex >= gWiFiBuddySync->mBuddyEntryCount) {
                gWiFiBuddySync->mUnk_1e = 3;
                gWiFiBuddySync->mCompletedParts++;
            }
        }
    }
    if (gWiFiBuddySync->mCompletedParts >= 2) {
        gWiFiBuddySync->mCompletedParts = 0;
        FinishBuddySync();
    }
}

void StartBuddySync(s32 a, const char *b, void (*c)(s32, u8, void *), void *d, void (*e)(s32, u8, void *, void *),
                    void *f, void (*g)(s32, s32, void *), void *h) {
    s32 i;
    s32 j;
    s32 k;
    s8 l[0x28];
    gWiFiBuddySync->mResultCallback = c;
    gWiFiBuddySync->mResultCallbackArg = d;
    gWiFiBuddySync->mBuddyStatusCallback = e;
    gWiFiBuddySync->mBuddyStatusCallbackArg = f;
    gWiFiBuddySync->mEntryMergedCallback = g;
    gWiFiBuddySync->mEntryMergedCallbackArg = h;
    i = 0;
    gWiFiBuddySync->mBuddiesChanged = 0;
    gWiFiBuddySync->mUnk_1e = 0;
    gWiFiBuddySync->mCompletedParts = 0;
    gWiFiBuddySync->mState = 1;
    if (((s8 *) gWiFiBuddySync->mUnk_28)[i] != 0) {
        j = i;
        for (; i < 5; i++) {
            k = GstatsConnect(j);
            if (k == 0) {
                break;
            }
            if (k != 2 || i == 4) {
                ReportBuddySyncStatsResult(k);
                return;
            }
        }
        func_ov000_02197a9c((const char *) func_ov000_021975f4(NULL), b, l);
        func_ov000_02197594(0, a, (s32) l, func_ov000_0219cc30, 0);
        AddPendingStatsRequest();
    } else {
        gWiFiBuddySync->mCompletedParts++;
    }
}

// Records the (error kind, code) pair in the error store of the layer (func_ov000_0219c384), calls the result callback
// with the code only while the sync runs (mState is 1) and closes the stats link. Not only the sync calls it: also the
// connection's GP error mapper, the stats code and the matching code.
void ReportBuddySyncError(s32 a, s32 b) {
    if (gWiFiBuddySync != NULL && a != 0) {
        func_ov000_0219c384(a, b);
        if (gWiFiBuddySync->mState != 0 && gWiFiBuddySync->mState != 2) {
            gWiFiBuddySync->mResultCallback(a, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
        }
        func_ov000_0219d478();
    }
}

// GP callback slot 1 (request): an incoming add-buddy request. The reply handler func_ov000_0219cd74 authorizes it
// and adds the sender back (AddBuddy) when the list holds an entry with that name or id; otherwise the request is
// dropped locally (no message is sent).
void WiFiGpBuddyRequestCallback(GpConnection *a, u32 *b) {
    if (gWiFiBuddySync->mBuddies != NULL) {
        func_ov000_0218eff8(a, *b, 0, 0, (Unk0218eff8Cb) func_ov000_0219cd74, 0);
    }
    return;
}

u32 func_ov000_0219d6c4(u32 a, u32 *b, u32 c) {
    int v1;
    v1 = strcmp((const char *) (b[2]), data_ov000_021b4078);
    if (v1 == 0) {
        func_ov000_0218eff8((GpConnection *) (a), *b, 0, 0, (Unk0218eff8Cb) func_ov000_0219cc94, 0);
        return 1;
    }
    return 0;
}

// GP callback slot 2 (status): looks up the list entry and calls mBuddyStatusCallback.
void WiFiGpBuddyStatusCallback(struct GpConnection *a, s32 *b) {
    Unk0218ec44 c;
    u32 d;
    WiFiBuddySync *e;
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        d = FindBuddyEntryIndex(b[0]);
        if (d != -1) {
            GpGetBuddyStatus(a, b[2], &c);
            e = gWiFiBuddySync;
            e->mBuddyStatusCallback(d, c.mUnk_004, c.mUnk_108, e->mBuddyStatusCallbackArg);
        }
    }
}

s32 func_ov000_0219d660(void) {
    if (gWiFiBuddySync != NULL) {
        return gWiFiBuddySync->mBuddyEntryCount;
    }
    return 0;
}

// 0 when the entry holds no id.
int GetBuddyEntryProfileId(int a) {
    Unk02152500 *v1;
    u32 v2;
    v1 = func_ov000_0219c9c4();
    v2 = func_02152520(v1, &gWiFiBuddySync->mBuddies[a]);
    if ((v2 == 0) || (v2 == -1)) {
        v2 = 0;
    }
    return v2;
}

// Index of the entry with this GP profile id, or -1.
u32 FindBuddyEntryIndex(u32 a) {
    s32 i;
    if (gWiFiBuddySync == NULL || a == 0) {
        return -1;
    }
    for (i = 0; i < gWiFiBuddySync->mBuddyEntryCount; i++) {
        if (a == GetBuddyEntryProfileId(i)) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219d5bc(void) {
    if (gWiFiBuddySync != NULL) {
        gWiFiBuddySync->mPollCount = 0;
        gWiFiBuddySync->mLastPollTime = func_0200f5ac();
    }
}

u32 func_ov000_0219d558(s32 a, void *b, void *c) {
    if (gWiFiBuddySync == NULL || gWiFiBuddySync->mGpConnection == NULL) {
        return 0;
    }
    if (a == -1) {
        a = gWiFiBuddySync->mGpConnection->mGpiConnection->mStatus;
    }
    if (b == NULL) {
        b = gWiFiBuddySync->mGpConnection->mGpiConnection->mStatusString;
    }
    if (c == NULL) {
        c = gWiFiBuddySync->mGpConnection->mGpiConnection->mLocationString;
    }
    return GpSetStatus(gWiFiBuddySync->mGpConnection, a, b, c);
}

void func_ov000_0219d504(s32 a) {
    Unk0218ec44 b;
    if (gWiFiBuddySync->mBuddyChangedCallback != NULL && gWiFiBuddySync->mState != 1) {
        ((void (*)(s32, void *)) gWiFiBuddySync->mBuddyChangedCallback)(a, gWiFiBuddySync->mBuddyChangedCallbackArg);
    }
    if (gWiFiBuddySync->mBuddyStatusCallback != NULL) {
        WiFiBuddySync *c;
        u8 d = func_ov000_0219daa8(&gWiFiBuddySync->mBuddies[a], b.mUnk_108);
        c = gWiFiBuddySync;
        c->mBuddyStatusCallback(a, d, b.mUnk_108, c->mBuddyStatusCallbackArg);
    }
}

void func_ov000_0219d4f8(void) {
    *(u32 *) &gWiFiBuddySync = 0;
    return;
}

int func_ov000_0219d49c(void) {
    WiFiBuddySync *a = gWiFiBuddySync;
    if ((func_0200f5ac() - a->mLastPollTime) * 64 / 0x82ea >= 300) {
        a->mPollCount = a->mPollCount + 1;
        GpUpdate(gWiFiBuddySync->mGpConnection);
        gWiFiBuddySync->mLastPollTime = func_0200f5ac();
    }
    return 0;
}

void func_ov000_0219d478(void) {
    if (gWiFiBuddySync != NULL) {
        GstatsClose();
        gWiFiBuddySync->mState = 0;
    }
}

void func_ov000_0219d2e8(Unk02152490 *a, s32 b) {
    s32 c;
    s32 d;
    s32 i;
    char e[0x18];
    Unk0218ec44 f;
    s32 g;
    if (gWiFiBuddySync->mUnk_1e == 0) {
        ReportBuddySyncGpResult(GpGetBuddyCount(gWiFiBuddySync->mGpConnection, &c));
        for (d = 0; d < c; d++) {
            ReportBuddySyncGpResult(GpGetBuddyStatus(gWiFiBuddySync->mGpConnection, d, &f));
            for (i = 0; i < b; i++) {
                if (f.mUnk_000 == GetBuddyEntryProfileId(i)) {
                    if (func_02152a24((Unk02152490 *) a + i) == 0) {
                        func_02152468(&a[i], f.mUnk_000);
                        func_021529bc(&a[i]);
                        gWiFiBuddySync->mBuddiesChanged = 1;
                    }
                    break;
                }
            }
            if (i == b) {
                ReportBuddySyncGpResult(func_ov000_0218eb44(gWiFiBuddySync->mGpConnection, f.mUnk_000));
                c--;
                d--;
            }
        }
        gWiFiBuddySync->mUnk_1e = 1;
    }
    for (; gWiFiBuddySync->mSyncIndex < b; gWiFiBuddySync->mSyncIndex++) {
        g = GetBuddyEntryProfileId(gWiFiBuddySync->mSyncIndex);
        if (g != 0) {
            if (func_ov000_0219d210(a, gWiFiBuddySync->mSyncIndex, g) == FALSE &&
                func_02152a24(&a[gWiFiBuddySync->mSyncIndex]) == 0) {
                ReportBuddySyncGpResult(GpGetBuddyIndex(gWiFiBuddySync->mGpConnection, g, &d));
                if (d == -1) {
                    AddBuddy(g);
                }
            }
        } else if (func_02152520(func_ov000_0219c9c4(), &a[gWiFiBuddySync->mSyncIndex]) == -1) {
            func_02152458(func_ov000_0219c9c4(), &a[gWiFiBuddySync->mSyncIndex], e);
            func_ov000_0218f0a8(gWiFiBuddySync->mGpConnection, NULL, NULL, NULL, NULL, (s8 *) e, 0, 0,
                                (Unk0218f0a8Cb) func_ov000_0219ce48, gWiFiBuddySync->mSyncIndex);
            gWiFiBuddySync->mUnk_1e = 2;
            return;
        }
    }
}

// The step UpdateBuddySync runs when both parts have ended: reports success (code 0) to the result callback and sets
// the finished state (mState 2).
void FinishBuddySync(void) {
    gWiFiBuddySync->mResultCallback(0, gWiFiBuddySync->mBuddiesChanged, gWiFiBuddySync->mResultCallbackArg);
    gWiFiBuddySync->mState = 2;
}

void func_ov000_0219d288(Unk02152490 *a, s32 b, s32 c) {
    if (gWiFiBuddySync != NULL) {
        MemFill(&a[b], 0, 12);
        if (gWiFiBuddySync->mEntryMergedCallback != NULL) {
            gWiFiBuddySync->mEntryMergedCallback(b, c, gWiFiBuddySync->mEntryMergedCallbackArg);
        }
    }
}

BOOL func_ov000_0219d210(Unk02152490 *a, s32 b, s32 c) {
    s32 i;
    s32 j;
    for (i = 0; i < b; i++) {
        j = GetBuddyEntryProfileId(i);
        if (j != 0 && j == c) {
            if (func_02152a24(&a[b]) != 0 && func_02152a24(&a[i]) == 0) {
                func_ov000_0219d288(a, i, b);
            } else {
                func_ov000_0219d288(a, b, i);
            }
            gWiFiBuddySync->mBuddiesChanged = 1;
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_ov000_0219d14c(Unk02152490 *a, s32 b, s32 c) {
    s32 l;
    s32 i;
    s32 j;
    s32 k;
    Unk02152490 *p;
    Unk02152490 *q;
    Unk02152490 *r;
    i = 0;
    l = -1;
    if (b - 1 > 0) {
        p = a;
        q = a;
        do {
            k = GetBuddyEntryProfileId(i);
            if (k != 0) {
                if (k == c) {
                    l = i;
                }
                j = i + 1;
                if (j < b) {
                    r = &a[j];
                    do {
                        if (k == GetBuddyEntryProfileId(j)) {
                            if (func_02152a1c(p) == 2 && func_02152a1c(r) == 3) {
                                func_02152468(q, k);
                            }
                            if (func_02152a24(r) != 0) {
                                func_021529bc(q);
                            }
                            func_ov000_0219d288(a, j, i);
                            gWiFiBuddySync->mBuddiesChanged = 1;
                        }
                        r++;
                        j++;
                    } while (j < b);
                }
            }
            p++;
            q++;
            i++;
        } while (i < b - 1);
    }
    return l;
}

// Sends the GP add-buddy request for a profile id (GpWriteAddbuddy with mUnk_28 as the reason text) and runs the
// error check; the buddy exists only once the other side authorizes.
u32 AddBuddy(u32 a) {
    u32 v1;
    v1 = GpWriteAddbuddy(gWiFiBuddySync->mGpConnection, (u32) (a), gWiFiBuddySync->mUnk_28);
    ReportBuddySyncGpResult(v1);
    return v1;
}
