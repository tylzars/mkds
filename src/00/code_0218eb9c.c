#include "00/code_0218eb9c.h"
#include "00/code_021947e4.h"
#include "00/code_02196000.h"
#include "00/code_021a3000.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"

#include "00/code_02194808.h"
#include "00/code_021948f8.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b23b0.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "00/code_0218f960.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "code_02135014.h"
#include "00/code_021906e4.h"
#include "00/code_0219218c.h"
#include "00/code_02193000.h"
#include "00/unk_021b3000.h"
#include "00/code_02194bb8.h"

void GpDisconnect(GpConnection *a) {
    if (a != NULL && a->mGpiConnection != NULL && a->mGpiConnection->mUnk_108 == 0) {
        GpiCloseConnection(a, 1);
        GpiResetConnection(a);
    }
    return;
}

u32 func_ov000_0218f0a8(GpConnection *a, s8 *b, s8 *c, s8 *d, s8 *e, s8 *f, s32 g, u32 h, Unk0218f0a8Cb i, u32 j) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (i == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218f0a8Arg k = {0};
        k.mUnk_08 = 0x601;
        i(a, &k, j);
        return 0;
    }
    return func_ov000_021960a4(a, b, c, d, e, f, g, 0, h, (u32) i, j);
}

u32 func_ov000_0218eff8(GpConnection *a, u32 b, s32 c, u32 d, Unk0218eff8Cb e, u32 f) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL || b == 0) {
        return 2;
    }
    if (e == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b242c);
        return 2;
    }
    if (o->mUnk_108 != 0) {
        Unk0218eff8Arg g = {0};
        e(a, &g, f);
        return 0;
    }
    if (o->mConnectState == 4) {
        GpiSetErrorMessage(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0219222c(a, b, c, d, (u32) e, f);
}

u32 func_ov000_0218efa8(GpConnection *a, s32 b, const s8 *c) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mConnectState == 4) {
        GpiSetErrorMessage(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_021923b4(a, b, c);
}

u32 GpWriteAddbuddy(GpConnection *a, u32 b, const char *c) {
    GpiConnection *o;
    char e[0x401];
    s8 *g;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mConnectState == 4) {
        GpiSetErrorMessage(a, data_ov000_021b23e8);
        return 2;
    }
    if (c == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b24dc);
        return 2;
    }
    GpiCopyString(e, c, 0x401);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b24ec);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2418);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b24f8);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, b);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2508);
    GpiAppendBufferString(a, &o->mOutputBuffer, e);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2424);
    return 0;
}

u32 func_ov000_0218ee1c(GpConnection *a, u32 b) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mConnectState == 4) {
        GpiSetErrorMessage(a, data_ov000_021b23e8);
        return 2;
    }
    return func_ov000_0218faac(a, b);
}

u32 func_ov000_0218ed74(GpConnection *b, int c) {
    int v1;
    int v2;
    GpiConnection *a;
    int v3;
    if ((b == NULL) || (a = b->mGpiConnection, a == NULL)) {
        return 2;
    }
    if (a->mUnk_108 != 0) {
        return 0;
    }
    if (a->mConnectState == 4) {
        GpiSetErrorMessage(b, data_ov000_021b23e8);
        return 2;
    }
    v1 = GpiFindProfile(b, c, (GpiProfile **) &v3);
    if (v1 == 0) {
        return 0;
    }
    *(s32 *) (v3 + 0x14) = *(s32 *) (v3 + 0x14) + -1;
    if ((a->mUnk_100 == 0) && (*(s32 *) (v3 + 0x14) <= 0)) {
        func_ov000_021a3668((void *) (*(u32 *) (v3 + 0x10)));
        *(u32 *) (v3 + 0x10) = 0;
        v2 = GpiIsProfileEmpty((GpiProfile *) v3);
        if (v2 != 0) {
            GpiRemoveProfile(b, (GpiProfile *) v3);
        }
    }
    return 0;
}

s32 GpGetBuddyCount(GpConnection *object, s32 *output) {
    GpiConnection *state;
    if (object == NULL || object->mGpiConnection == NULL) {
        return 2;
    }
    state = object->mGpiConnection;
    if (state->mUnk_108 != 0) {
        *output = 0;
        return 0;
    }
    *output = state->mBuddyCount;
    return 0;
}

u32 GpGetBuddyStatus(GpConnection *a, s32 b, Unk0218ec44 *c) {
    GpiConnection *o;
    GpiProfile *e;
    GpiBuddyStatus *n;
    void *v;
    s32 m;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        memset(c, 0, 0x210);
        return 0;
    }
    if (c == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b24a8);
        return 2;
    }
    m = o->mBuddyCount;
    if (b < 0 || b >= m) {
        GpiSetErrorMessage(a, data_ov000_021b24b8);
        return 2;
    }
    e = (GpiProfile *) GpiFindProfileByBuddyIndex(a, b);
    if (e == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b24b8);
        return 2;
    }
    n = e->mBuddyStatus;
    if (n == NULL) {
        AssertionFailed(data_ov000_021b24c8, data_ov000_021b24d4, NULL, 0x5cf);
    }
    c->mUnk_000 = e->mProfileId;
    c->mUnk_004 = n->mUnk_04;
    v = n->mUnk_08;
    if (v != NULL) {
        GpiCopyString(c->mUnk_008, v, 0x100);
    } else {
        *(u8 *) v = 0;
    }
    v = n->mUnk_0c;
    if (v != NULL) {
        GpiCopyString(c->mUnk_108, v, 0x100);
    } else {
        *(u8 *) v = 0;
    }
    c->mUnk_208 = n->mUnk_10;
    c->mUnk_20c = n->mUnk_14;
    return 0;
}

u32 GpGetBuddyIndex(GpConnection *a, u32 b, s32 *c) {
    GpiConnection *o;
    GpiProfile *e;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        *c = 0;
        return 0;
    }
    if (GpiFindProfile(a, b, &e) != 0 && e->mBuddyStatus != NULL) {
        *c = e->mBuddyStatus->mIndex;
    } else {
        *c = -1;
    }
    return 0;
}

u32 GpIsBuddy(GpConnection *a, u32 b) {
    int v1;
    int v2[1];
    if ((a == NULL) || (a->mGpiConnection == NULL)) {
        return 0;
    }
    if (a->mGpiConnection->mUnk_108 != 0) {
        return 0;
    }
    v1 = GpiFindProfile(a, b, (GpiProfile **) v2);
    if ((v1 != 0) && (*(s32 *) (v2[0] + 8) != 0)) {
        return 1;
    }
    return 0;
}
