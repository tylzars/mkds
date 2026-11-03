#include "00/code_02190ba0.h"
#include "00/code_02193818.h"
#include "00/code_02194840.h"

u32 func_ov000_02191180(GpConnection *a, Unk02194934 *b) {
    GpiConnection *c;

    c = a->mGpiConnection;
    if (b->mUnk_08 != NULL && c->mUnk_104 == 0) {
        func_ov000_021a3668(b->mUnk_08->mUnk_08);
        b->mUnk_08->mUnk_08 = NULL;
        func_ov000_021a3668(b->mUnk_08->mUnk_0c);
        b->mUnk_08->mUnk_0c = NULL;
        func_ov000_021a3668(b->mUnk_08);
        b->mUnk_08 = NULL;
    }
    func_ov000_021a3668(b->mUnk_10);
    b->mUnk_10 = NULL;
    func_ov000_021a3668(b->mUnk_18);
    b->mUnk_18 = NULL;
    b->mUnk_14 = 0;
    if (b->mUnk_0c == 0 || (c->mUnk_104 == 1 && b->mUnk_08 == NULL)) {
        func_ov000_021948f8(a, b);
        return 0;
    }
    return 1;
}

void func_ov000_02190ff8(GpConnection *a, s32 b) {
    GpiConnection *c;
    Unk021937c0Node *d;
    Unk02193f2cNode *e;
    u32 f;

    c = a->mGpiConnection;
    if (c->mConnectState == 4) {
        return;
    }
    if (c->mConnectState != 0) {
        if (b != 0 && c->mConnectState == 3) {
            func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2b28);
            func_ov000_02190b58(a, &c->mOutputBuffer, c->mSesskey);
            func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2b3c);
        }
        func_ov000_021906e4(a, c->mConnectSocket, &c->mOutputBuffer, &f, 1, data_ov000_021b2b44);
        if (c->mConnectSocket != -1) {
            func_ov000_0218e524(c->mConnectSocket, 2);
            func_ov000_0218e53c(c->mConnectSocket);
            c->mConnectSocket = -1;
        }
        if (c->mListenSocket != -1) {
            func_ov000_0218e524(c->mListenSocket, 2);
            func_ov000_0218e53c(c->mListenSocket);
            c->mListenSocket = -1;
        }
        c->mConnectState = 4;
        c->mUserId = 0;
        c->mProfileId = 0;
    }
    func_ov000_021a3668(c->mInputBuffer);
    c->mInputBuffer = NULL;
    func_ov000_021a3668(c->mCommandBuffer);
    c->mCommandBuffer = NULL;
    func_ov000_021a3668(c->mOutputBuffer.mUnk_00);
    c->mOutputBuffer.mUnk_00 = NULL;
    func_ov000_021a3668(c->mUpdateproBuffer);
    c->mUpdateproBuffer = NULL;
    func_ov000_021a3668(c->mUpdateuiBuffer);
    c->mUpdateuiBuffer = NULL;
    while (c->mOperationList != NULL) {
        func_ov000_02193818(a, c->mOperationList);
    }
    c->mOperationList = NULL;
    e = c->mPeerList;
    while (e != NULL) {
        Unk02193f2cNode *g = e;
        e = e->mNext;
        func_ov000_02194120(a, g);
    }
    c->mPeerList = NULL;
    while (func_ov000_02194840(a, func_ov000_02191180, NULL) == 0) {
    }
}

void func_ov000_02190f4c(GpConnection *a, s32 b, s32 c) {
    GpiConnection *d;
    Unk02190ed4Cb e;
    Unk02190f4c *f;

    d = a->mGpiConnection;
    if (d == NULL) {
        func_0213442c(data_ov000_021b2a8c, data_ov000_021b2a58, NULL, 0x23);
    }
    if (b == 0) {
        func_0213442c(data_ov000_021b2aa0, data_ov000_021b2a58, NULL, 0x24);
    }
    if (c != 1 && c != 0) {
        func_0213442c(data_ov000_021b2ab8, data_ov000_021b2a58, NULL, 0x25);
    }
    if (c == 1) {
        d->mFatal = 1;
    }
    e = d->mCallbacks[0];
    if (e.mUnk_00 != NULL) {
        f = func_ov000_021a3690(0x10);
        if (f != NULL) {
            f->mUnk_00 = b;
            f->mUnk_0c = c;
            f->mUnk_04 = d->mErrorNumber;
            f->mUnk_08 = d;
        }
        func_ov000_02190ed4(a, e, f, NULL, 1);
    }
}

u32 func_ov000_02190ed4(GpConnection *a, Unk02190ed4Cb b, void *c, Unk021937c0Node *d, s32 e) {
    GpiConnection *f;
    Unk02190ed4Node *g;

    f = a->mGpiConnection;
    g = func_ov000_021a3690(0x18);
    if (g == NULL) {
        func_ov000_02196590(a, data_ov000_021b2a7c);
        return 1;
    }
    g->mUnk_00 = b;
    g->mUnk_08 = c;
    if (d != NULL) {
        g->mUnk_10 = d->mUnk_18;
    } else {
        g->mUnk_10 = 0;
    }
    g->mUnk_0c = e;
    g->mUnk_14 = NULL;
    if (f->mCallbackQueueHead == NULL) {
        f->mCallbackQueueHead = g;
    }
    if (f->mCallbackQueueTail != NULL) {
        f->mCallbackQueueTail->mUnk_14 = g;
    }
    f->mCallbackQueueTail = g;
    return 0;
}

void func_ov000_02190da0(GpConnection *a, Unk02190ed4Node *b) {
    Unk02190da0Data *c;
    Unk02190da0Data *e;
    s32 d;

    if (b->mUnk_00.mUnk_00 == NULL) {
        func_0213442c(data_ov000_021b2a38, data_ov000_021b2a58, NULL, 0x6e);
    }
    if (b->mUnk_08 == NULL) {
        func_0213442c(data_ov000_021b2a68, data_ov000_021b2a58, NULL, 0x6f);
    }
    b->mUnk_00.mUnk_00(a, b->mUnk_08, b->mUnk_00.mUnk_04);
    if (b->mUnk_0c == 2) {
        c = b->mUnk_08;
        func_ov000_021a3668(c->mUnk_08);
        c = b->mUnk_08;
        c->mUnk_08 = NULL;
    } else if (b->mUnk_0c == 3) {
        e = b->mUnk_08;
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
    } else if (b->mUnk_0c == 4) {
        c = b->mUnk_08;
        func_ov000_021a3668(c->mUnk_0c);
        c->mUnk_0c = NULL;
    } else if (b->mUnk_0c == 7) {
        c = b->mUnk_08;
        if (c->mUnk_10 != NULL) {
            func_ov000_021a3668(c->mUnk_10);
            c->mUnk_10 = NULL;
        }
    } else if (b->mUnk_0c == 8) {
        c = b->mUnk_08;
        if (c->mUnk_08 != NULL) {
            func_ov000_021a3668(c->mUnk_08);
            c->mUnk_08 = NULL;
        }
    } else if (b->mUnk_0c == 9) {
        Unk02190da0Data *f = b->mUnk_08;
        for (d = 0; d < f->mUnk_04; d++) {
            func_ov000_021a3668(f->mUnk_08[d]);
            f->mUnk_08[d] = NULL;
        }
        func_ov000_021a3668(f->mUnk_08);
        f->mUnk_08 = NULL;
    }
    func_ov000_021a3668(b->mUnk_08);
    b->mUnk_08 = NULL;
    func_ov000_021a3668(b);
}

u32 func_ov000_02190cd4(GpConnection *a, s32 b) {
    GpiConnection *c;
    Unk02190ed4Node *d;
    Unk02190ed4Node *e;
    Unk02190ed4Node *f;
    Unk02190ed4Node *g;

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
                Unk02190ed4Node *h = g->mUnk_14;
                if (g->mUnk_10 == b || g->mUnk_0c == 1) {
                    if (f != NULL) {
                        f->mUnk_14 = h;
                    } else {
                        d = h;
                    }
                    if (e == g) {
                        e = f;
                    }
                    func_ov000_02190da0(a, g);
                } else {
                    f = g;
                }
                g = h;
            } while (g != NULL);
        }
        if (c->mCallbackQueueHead != NULL) {
            c->mCallbackQueueTail->mUnk_14 = d;
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
            d = g->mUnk_14;
            func_ov000_02190da0(a, g);
            g = d;
        }
        g = c->mCallbackQueueHead;
    }
    return 0;
}

u32 func_ov000_02190c64(void *a, Unk021906e4 *b, s32 c) {
    u8 *d;
    s32 e;
    s32 f;

    if (b == NULL) {
        func_0213442c(data_ov000_021b2890, data_ov000_021b28a8, NULL, 0x25);
    }
    e = b->mUnk_08;
    f = b->mUnk_04;
    d = b->mUnk_00;
    if (f == e) {
        f += 0x800;
        d = func_ov000_021a3678(d, f + 1);
        if (d == NULL) {
            func_ov000_02196590(a, data_ov000_021b292c);
            return 1;
        }
    }
    d[e] = c;
    d[e + 1] = 0;
    b->mUnk_08 += 1;
    b->mUnk_04 = f;
    b->mUnk_00 = d;
    return 0;
}

u32 func_ov000_02190ba0(void *a, Unk021906e4 *b, const void *c, s32 d) {
    s32 f;
    u8 *e;
    s32 g;

    if (c == NULL) {
        func_0213442c(data_ov000_021b2a18, data_ov000_021b28a8, NULL, 0x51);
    }
    if (d < 0) {
        func_0213442c(data_ov000_021b2a28, data_ov000_021b28a8, NULL, 0x52);
    }
    if (b == NULL) {
        func_0213442c(data_ov000_021b2890, data_ov000_021b28a8, NULL, 0x53);
    }
    if (c == NULL) {
        return 0;
    }
    g = b->mUnk_08;
    f = b->mUnk_04;
    e = b->mUnk_00;
    if (f - g < d) {
        f += d < 0x800 ? 0x800 : d;
        e = func_ov000_021a3678(e, f + 1);
        if (e == NULL) {
            func_ov000_02196590(a, data_ov000_021b292c);
            return 1;
        }
    }
    memcpy(e + g, c, d);
    e[g + d] = 0;
    b->mUnk_08 += d;
    b->mUnk_04 = f;
    b->mUnk_00 = e;
    return 0;
}
