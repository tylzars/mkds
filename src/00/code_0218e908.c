#include "00/code_0218e908.h"

#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_0218e2dc.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "00/code_02196000.h"
#include "00/code_021906e4.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/unk_021b23b0.h"
#include "code_0200f5ac.h"

u32 func_ov000_0218eb44(GpConnection *a, u32 b) {
    GpiConnection *o;
    u32 r;
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
    r = GpiWriteDelbuddyAndRemoveBuddy(a, b);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 GpSetStatus(GpConnection *a, s32 b, const char *c, const char *d) {
    GpiConnection *o;
    char e[0x100];
    char f[0x100];
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
        GpiSetErrorMessage(a, data_ov000_021b2450);
        return 2;
    }
    if (d == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b2468);
        return 2;
    }
    GpiCopyString(e, c, 0x100);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    GpiCopyString(f, d, 0x100);
    if (*(s8 *) f != 0) {
        g = (s8 *) f;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    if (b == o->mStatus && strcmp(e, o->mStatusString) == 0 && strcmp(f, o->mLocationString) == 0) {
        return 0;
    }
    o->mStatus = b;
    GpiCopyString(o->mStatusString, e, 0x100);
    GpiCopyString(o->mLocationString, f, 0x100);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2480);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, b);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2418);
    GpiAppendBufferNumber(a, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b248c);
    GpiAppendBufferString(a, &o->mOutputBuffer, e);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b249c);
    GpiAppendBufferString(a, &o->mOutputBuffer, f);
    GpiAppendBufferString(a, &o->mOutputBuffer, data_ov000_021b2424);
    return 0;
}

u32 GpSendMessage(GpConnection *a, s32 b, const char *c) {
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
    if (c == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b243c);
        return 2;
    }
    return func_ov000_0218fb3c(a, b, 1, c);
}
