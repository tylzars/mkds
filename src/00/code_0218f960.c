#include "00/code_0218f960.h"

#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_0218d000.h"
#include "00/code_02194840.h"
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
#include "00/code_02194000.h"
#include "00/code_021947e4.h"
#include "00/code_02190548.h"
#include "00/code_021948f8.h"
#include "00/code_02193818.h"
#include "00/code_02192000.h"
#include "00/code_02193e70.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/unk_021b23b0.h"

u32 func_ov000_0218fbe0(GpConnection *a, s32 b, s32 c, const char *d) {
    GpiConnection *o;
    char e[0xdad];
    o = a->mGpiConnection;
    func_ov000_02196914(e, d, 0xdad);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27c4);
    func_ov000_02190b58(a, &o->mOutputBuffer, c);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b275c);
    func_ov000_02190b58(a, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27cc);
    func_ov000_02190b58(a, &o->mOutputBuffer, b);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b27d0);
    func_ov000_02190b80(a, &o->mOutputBuffer, e);
    func_ov000_02190b80(a, &o->mOutputBuffer, data_ov000_021b2778);
    return 0;
}

u32 func_ov000_0218fb3c(GpConnection *a, s32 b, s32 c, const char *d) {
    Unk02194934 *e;
    Unk02193f2cNode *n;
    u32 r;
    n = func_ov000_02193f2c(a, b);
    if (n == NULL) {
        if (func_ov000_02194934(a, b, &e) == 0 || e->mUnk_08 == NULL || e->mUnk_08->mUnk_14 == 0) {
            return func_ov000_0218fbe0(a, b, c, d);
        }
        n = func_ov000_02193eac(a, b, 1);
        if (n == NULL) {
            return 1;
        }
        if (e->mUnk_18 == NULL) {
            r = func_ov000_02193e70(a, n);
            if (r != 0) {
                return r;
            }
        } else {
            r = func_ov000_02193d64(a, n);
            if (r != 0) {
                return r;
            }
        }
    }
    r = func_ov000_02193c74(a, n, c, d);
    if (r == 0) {
        return 0;
    }
    return r;
}

u32 func_ov000_0218faac(GpConnection *a, u32 b) {
    GpiConnection *o;
    Unk02194934 *e;
    u32 r;
    o = a->mGpiConnection;
    if (func_ov000_02194934(a, b, &e) == 0) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    if (e->mUnk_10 == NULL) {
        func_ov000_02196590(a, data_ov000_021b273c);
        return 2;
    }
    r = func_ov000_02190548(a, e);
    if (r == 0) {
        e->mUnk_14--;
        if (o->mUnk_100 == 0 && e->mUnk_14 <= 0) {
            func_ov000_021a3668(e->mUnk_10);
            e->mUnk_10 = NULL;
            if (func_ov000_021947e4(e) != 0) {
                func_ov000_021948f8(a, e);
            }
        }
        return 0;
    }
    return r;
}

s32 func_ov000_0218fa98(void *unused, Unk0218fa98 *object, s32 minimum) {
    if (object->mUnk_08 != NULL && *object->mUnk_08 > minimum) {
        --*object->mUnk_08;
    }
    return 1;
}

u32 func_ov000_0218f960(GpConnection *p, u32 b) {
    GpiConnection *o;
    Unk02194934 *e;
    s32 n;

    o = p->mGpiConnection;
    if (func_ov000_02194934(p, b, &e) == 0) {
        func_ov000_02196590(p, data_ov000_021b273c);
        return 2;
    }
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2750);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b275c);
    func_ov000_02190b58(p, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2768);
    func_ov000_02190b58(p, &o->mOutputBuffer, e->mUnk_00);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2778);
    if (e->mUnk_08 != NULL) {
        n = e->mUnk_08->mUnk_00;
        if (n < 0) {
            func_0213442c(data_ov000_021b2780, data_ov000_021b278c, NULL, 0x1fd);
        }
        func_ov000_021a3668(e->mUnk_08->mUnk_08);
        e->mUnk_08->mUnk_08 = NULL;
        func_ov000_021a3668(e->mUnk_08->mUnk_0c);
        e->mUnk_08->mUnk_0c = NULL;
        func_ov000_021a3668(e->mUnk_08);
        e->mUnk_08 = NULL;
        if (func_ov000_021947e4(e) != 0) {
            func_ov000_021948f8(p, e);
        }
        o->mBuddyCount--;
        if (o->mBuddyCount < 0) {
            func_0213442c(data_ov000_021b2798, data_ov000_021b278c, NULL, 0x204);
        }
        func_ov000_02194840(p, func_ov000_0218fa98, (void *) n);
    }
    return 0;
}
