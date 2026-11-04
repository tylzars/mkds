#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021965a0.h"
#include "00/code_021967b4.h"
#include "00/code_02194b9c.h"
#include "00/code_02194ba4.h"
#include "code_0213a460.h"
#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "code_0213442c.h"
#include "00/code_02196000.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218dd8c.h"
#include "00/code_021a3668.h"
#include "00/code_02190cd4.h"

void GpiReleaseProfile(GpiProfile *a) {
    if (a->mBuddyStatus != NULL) {
        func_ov000_021a3668(a->mBuddyStatus->mUnk_08);
        a->mBuddyStatus->mUnk_08 = NULL;
        func_ov000_021a3668(a->mBuddyStatus->mUnk_0c);
        a->mBuddyStatus->mUnk_0c = NULL;
        func_ov000_021a3668(a->mBuddyStatus);
        a->mBuddyStatus = NULL;
    }
    func_ov000_0219210c((Unk021919ac_node *) a);
    func_ov000_021a3668(a->mUnk_10);
    a->mUnk_10 = NULL;
    func_ov000_021a3668(a->mUnk_18);
    a->mUnk_18 = NULL;
}

BOOL GpiInitProfileList(GpConnection *a) {
    GpiConnection *r;

    r = a->mGpiConnection;
    r->mBuddyCount = 0;
    r->mProfileList.mUnk_04 = 0;
    r->mProfileList.mTable = func_ov000_0218e0e0(0x1c, 4, GpiHashProfile, GpiCompareProfiles, GpiReleaseProfile);
    if (r->mProfileList.mTable != NULL) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov000_02194a0c(GpConnection *a, GpiOperation *b, const char *c) {
    GpiCallback p;
    u32 *m;
    s32 v;
    s32 t;
    char d[0x10];

    if (GpiReadError(a, c, 1) != 0) {
        return 4;
    }
    if (strncmp(c, data_ov000_021b3564, 5) != 0) {
        GpiSetError(a, 1, data_ov000_021b356c);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    if (GpiGetValue(c, data_ov000_021b359c, d, 0x10) == 0) {
        GpiSetError(a, 1, data_ov000_021b356c);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    v = func_0213bf90(d);
    p = b->mUnk_0c;
    if (p.mCallback != NULL) {
        m = func_ov000_021a3690(8);
        if (m == NULL) {
            GpiSetErrorMessage(a, data_ov000_021b35a8);
            return 1;
        }
        m[1] = v;
        m[0] = 0;
        t = GpiQueueCallback(a, p, m, b, 0);
        if (t != 0) {
            return t;
        }
    }
    GpiRemoveOperation(a, b);
    return 0;
}

GpiProfile *GpiFindOrAddProfile(GpConnection *a, s32 id) {
    Unk0218f960_428 *c;
    GpiProfile *e;

    c = &a->mGpiConnection->mProfileList;
    if (id <= 0) {
        func_0213442c(data_ov000_021b354c, data_ov000_021b3554, NULL, 0x2b5);
    }
    if (id <= 0) {
        return NULL;
    }
    if (GpiFindProfile(a, id, &e) != 0) {
        return e;
    }
    {
        GpiProfile s = {0};

        s.mProfileId = id;
        s.mUserId = 0;
        s.mUnk_0c = 0;
        s.mUnk_10 = NULL;
        s.mUnk_18 = NULL;
        s.mUnk_14 = 0;
        HashtableSet(c->mTable, &s);
    }
    c->mUnk_04 = c->mUnk_04 + 1;
    if (GpiFindProfile(a, id, &e) != 0) {
        return e;
    }
    return NULL;
}

u32 GpiFindProfile(GpConnection *a, u32 b, GpiProfile **c) {
    GpiConnection *r;
    GpiProfile d;
    GpiProfile *e;

    r = a->mGpiConnection;
    d.mProfileId = b;
    e = HashtableFind(r->mProfileList.mTable, &d);
    if (c != NULL) {
        *c = e;
    }
    if (e != NULL) {
        return 1;
    }
    return 0;
}

void GpiRemoveProfileById(GpConnection *a, u32 b) {
    GpiConnection *r;
    GpiProfile *e;

    r = a->mGpiConnection;
    if (GpiFindProfile(a, b, &e) != 0) {
        HashtableRemove(r->mProfileList.mTable, e);
    }
}

void GpiRemoveProfile(GpConnection *a, GpiProfile *b) {
    HashtableRemove(a->mGpiConnection->mProfileList.mTable, b);
}
