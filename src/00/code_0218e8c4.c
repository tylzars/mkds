#include "00/code_0218e8c4.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e368.h"
#include "00/code_021965a0.h"
#include "00/code_02190ba0.h"
#include "00/code_02196000.h"
#include "code_02135014.h"
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
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    r = func_ov000_0218f960(a, b);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218e974(GpConnection *a, s32 b, const u8 *c, const u8 *d) {
    GpiConnection *o;
    u8 e[0x100];
    u8 f[0x100];
    s8 *g;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mConnectState == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    if (c == NULL) {
        func_ov000_02196590(a, data_ov000_021b2450);
        return 2;
    }
    if (d == NULL) {
        func_ov000_02196590(a, data_ov000_021b2468);
        return 2;
    }
    func_ov000_02196914(e, c, 0x100);
    if (*(s8 *) e != 0) {
        g = (s8 *) e;
        do {
            if (*g == 0x5c) {
                *g = 0x2f;
            }
            g++;
        } while (*g != 0);
    }
    func_ov000_02196914(f, d, 0x100);
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
    func_ov000_02196914(o->mStatusString, e, 0x100);
    func_ov000_02196914(o->mLocationString, f, 0x100);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b2480);
    func_ov000_02190b58(a, &o->mOutputBuffer, b);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b2418);
    func_ov000_02190b58(a, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b248c);
    func_ov000_02190b80(a, &o->mOutputBuffer, e);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b249c);
    func_ov000_02190b80(a, &o->mOutputBuffer, f);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b2424);
    return 0;
}

u32 func_ov000_0218e908(GpConnection *a, s32 b, const u8 *c) {
    GpiConnection *o;
    if (a == NULL || (o = a->mGpiConnection) == NULL) {
        return 2;
    }
    if (o->mUnk_108 != 0) {
        return 0;
    }
    if (o->mConnectState == 4) {
        func_ov000_02196590(a, data_ov000_021b23e8);
        return 2;
    }
    if (c == NULL) {
        func_ov000_02196590(a, data_ov000_021b243c);
        return 2;
    }
    return func_ov000_0218fb3c(a, b, 1, c);
}

u32 func_ov000_0218e8c4(void) {
    u64 t;
    if (func_0200f6e4() != 1) {
        func_0213442c(data_ov000_021b23b0, data_ov000_021b23d0, NULL, 0x109);
    }
    t = func_0200f5ac();
    return (t << 6) / 0x82ea;
}
