#include "00/code_02190cd4.h"
#include "00/code_021947e4.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/code_0218e2dc.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

#include "00/code_021906e4.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_02194840.h"

void GpiQueueErrorCallback(GpConnection *a, s32 result, s32 fatal) {
    GpiConnection *iconnection;
    GpiCallback e;
    Unk02190f4c *f;

    iconnection = a->mGpiConnection;
    if (iconnection == NULL) {
        AssertionFailed(data_ov000_021b2a8c, data_ov000_021b2a58, NULL, 0x23);
    }
    if (result == 0) {
        AssertionFailed(data_ov000_021b2aa0, data_ov000_021b2a58, NULL, 0x24);
    }
    if (fatal != 1 && fatal != 0) {
        AssertionFailed(data_ov000_021b2ab8, data_ov000_021b2a58, NULL, 0x25);
    }
    if (fatal == 1) {
        iconnection->mFatal = 1;
    }
    e = iconnection->mCallbacks[0];
    if (e.mCallback != NULL) {
        f = func_ov000_021a3690(0x10);
        if (f != NULL) {
            f->mUnk_00 = result;
            f->mUnk_0c = fatal;
            f->mUnk_04 = iconnection->mErrorNumber;
            f->mUnk_08 = iconnection;
        }
        GpiQueueCallback(a, e, f, NULL, 1);
    }
}

u32 GpiQueueCallback(GpConnection *a, GpiCallback b, void *c, GpiOperation *d, s32 e) {
    GpiConnection *f;
    GpiQueuedCallback *g;

    f = a->mGpiConnection;
    g = func_ov000_021a3690(0x18);
    if (g == NULL) {
        GpiSetErrorMessage(a, data_ov000_021b2a7c);
        return 1;
    }
    g->mCallback = b;
    g->mArg = c;
    if (d != NULL) {
        g->mUnk_10 = d->mId;
    } else {
        g->mUnk_10 = 0;
    }
    g->mUnk_0c = e;
    g->mNext = NULL;
    if (f->mCallbackQueueHead == NULL) {
        f->mCallbackQueueHead = g;
    }
    if (f->mCallbackQueueTail != NULL) {
        f->mCallbackQueueTail->mNext = g;
    }
    f->mCallbackQueueTail = g;
    return 0;
}

void GpiCallAndFreeCallback(GpConnection *a, GpiQueuedCallback *data) {
    Unk02190da0Data *c;
    Unk02190da0Data *e;
    s32 d;

    if (data->mCallback.mCallback == NULL) {
        AssertionFailed(data_ov000_021b2a38, data_ov000_021b2a58, NULL, 0x6e);
    }
    if (data->mArg == NULL) {
        AssertionFailed(data_ov000_021b2a68, data_ov000_021b2a58, NULL, 0x6f);
    }
    data->mCallback.mCallback(a, data->mArg, data->mCallback.mUnk_04);
    if (data->mUnk_0c == 2) {
        c = data->mArg;
        func_ov000_021a3668(c->mUnk_08);
        c = data->mArg;
        c->mUnk_08 = NULL;
    } else if (data->mUnk_0c == 3) {
        e = data->mArg;
        for (d = 0; d < e->mUnk_38; d++) {
            func_ov000_021a3668(e->mUnk_3c[d]);
            e->mUnk_3c[d] = NULL;
            func_ov000_021a3668(e->mUnk_40[d]);
            e->mUnk_40[d] = NULL;
        }
        func_ov000_021a3668(e->mUnk_3c);
        e->mUnk_3c = NULL;
        func_ov000_021a3668(e->mUnk_40);
        e->mUnk_40 = NULL;
    } else if (data->mUnk_0c == 4) {
        c = data->mArg;
        func_ov000_021a3668(c->mUnk_0c);
        c->mUnk_0c = NULL;
    } else if (data->mUnk_0c == 7) {
        c = data->mArg;
        if (c->mUnk_10 != NULL) {
            func_ov000_021a3668(c->mUnk_10);
            c->mUnk_10 = NULL;
        }
    } else if (data->mUnk_0c == 8) {
        c = data->mArg;
        if (c->mUnk_08 != NULL) {
            func_ov000_021a3668(c->mUnk_08);
            c->mUnk_08 = NULL;
        }
    } else if (data->mUnk_0c == 9) {
        Unk02190da0Data *f = data->mArg;
        for (d = 0; d < f->mUnk_04; d++) {
            func_ov000_021a3668(f->mUnk_08[d]);
            f->mUnk_08[d] = NULL;
        }
        func_ov000_021a3668(f->mUnk_08);
        f->mUnk_08 = NULL;
    }
    func_ov000_021a3668(data->mArg);
    data->mArg = NULL;
    func_ov000_021a3668(data);
}

u32 GpiCallQueuedCallbacks(GpConnection *a, s32 b) {
    GpiConnection *c;
    GpiQueuedCallback *d;
    GpiQueuedCallback *e;
    GpiQueuedCallback *f;
    GpiQueuedCallback *g;

    c = a->mGpiConnection;
    if (b != 0) {
        d = c->mCallbackQueueHead;
        e = c->mCallbackQueueTail;
        f = NULL;
        c->mCallbackQueueHead = NULL;
        c->mCallbackQueueTail = NULL;
        g = d;
        if (g != NULL) {
            do {
                GpiQueuedCallback *h = g->mNext;
                if (g->mUnk_10 == b || g->mUnk_0c == 1) {
                    if (f != NULL) {
                        f->mNext = h;
                    } else {
                        d = h;
                    }
                    if (e == g) {
                        e = f;
                    }
                    GpiCallAndFreeCallback(a, g);
                } else {
                    f = g;
                }
                g = h;
            } while (g != NULL);
        }
        if (c->mCallbackQueueHead != NULL) {
            c->mCallbackQueueTail->mNext = d;
            c->mCallbackQueueTail = e;
        } else {
            c->mCallbackQueueHead = d;
            c->mCallbackQueueTail = e;
        }
        return 0;
    }
    g = c->mCallbackQueueHead;
    while (g != NULL) {
        c->mCallbackQueueHead = NULL;
        c->mCallbackQueueTail = NULL;
        while (g != NULL) {
            d = g->mNext;
            GpiCallAndFreeCallback(a, g);
            g = d;
        }
        g = c->mCallbackQueueHead;
    }
    return 0;
}
