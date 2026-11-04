#include "00/code_02190ff8.h"

#include "00/code_02193634.h"
#include "00/code_02194840.h"
#include "00/code_0218e2a4.h"
#include "00/code_02191200.h"
#include "00/code_021965a0.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/code_02196594.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_021947e4.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"
#include "code_021384cc.h"
#include "code_02133048.h"
#include "00/code_02193b88.h"
#include "00/code_02190cd4.h"

void func_ov000_021920d8(s8 *p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p[i] = data_ov000_021b2f18[rand() % 0x3e];
    }
    p[i] = 0;
}

u32 GpiOpenSockets(GpConnection *p, Unk021919ac_node *n) {
    GpiConnection *o;
    Unk021919ac_sa s;
    Unk021a8f84 *x;
    s32 z;
    s32 r;

    o = p->mGpiConnection;
    if (o->mFirewall == 0) {
        o->mListenSocket = func_ov000_0218e554(2, 1, 0);
        if (o->mListenSocket == -1) {
            GpiSetError(p, 5, data_ov000_021b2dbc);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
        if (func_ov000_0218e80c(o->mListenSocket, 0) == 0) {
            GpiSetError(p, 5, data_ov000_021b2de4);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
        __builtin__clear(&s, sizeof(s));
        s.f.mUnk_01 = 2;
        if (func_ov000_0218e4e4(o->mListenSocket, &s, 8) == -1) {
            GpiSetError(p, 5, data_ov000_021b2e18);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
        if (func_ov000_0218e49c(o->mListenSocket, 5) == -1) {
            GpiSetError(p, 5, data_ov000_021b2e40);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
        z = 8;
        if (func_ov000_0218e394(o->mListenSocket, &s, (u32 *) &z) == -1) {
            GpiSetError(p, 5, data_ov000_021b2e6c);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
        o->mPort = s.f.mUnk_02;
    } else {
        o->mListenSocket = -1;
        o->mPort = 0;
    }
    o->mConnectSocket = func_ov000_0218e554(2, 1, 0);
    if (o->mConnectSocket == -1) {
        GpiSetError(p, 5, data_ov000_021b2dbc);
        GpiQueueErrorCallback(p, 3, 1);
        return 3;
    }
    if (func_ov000_0218e80c(o->mConnectSocket, 0) == 0) {
        GpiSetError(p, 5, data_ov000_021b2de4);
        GpiQueueErrorCallback(p, 3, 1);
        return 3;
    }
    x = func_ov000_021a8f84(data_ov000_021b2ae8);
    if (x == NULL) {
        GpiSetError(p, 5, data_ov000_021b2e9c);
        GpiQueueErrorCallback(p, 3, 1);
        return 3;
    }
    __builtin__clear(&s, sizeof(s));
    s.f.mUnk_01 = 2;
    s.f.mUnk_04 = **x->mUnk_0c;
    if (s.f.mUnk_04 == 0) {
        AssertionFailed(data_ov000_021b2ed0, data_ov000_021b2b88, NULL, 0x90);
    }
    s.f.mUnk_02 = 0xcc74;
    if (func_ov000_0218e4b4(o->mConnectSocket, &s, 8) == -1) {
        r = func_ov000_0218e368(o->mConnectSocket);
        if (r != -6 && r != -26 && r != -76) {
            GpiSetError(p, 5, data_ov000_021b2ef0);
            GpiQueueErrorCallback(p, 3, 1);
            return 3;
        }
    }
    n->mUnk_14 = 1;
    o->mConnectState = 1;
    return 0;
}

u32 GpiStartConnect(GpConnection *p, const char *a, const char *b, const char *c, const char *d, const s8 *e,
                    const s8 *f, const char *g, s32 h, s32 i, s32 j, s32 k, s32 l) {
    GpiConnection *o;
    Unk021919ac_q *q;
    Unk021919ac_node *n;
    u32 r;

    o = p->mGpiConnection;
    if (o->mConnectState == 4) {
        r = GpiResetConnection(p);
        if (r != 0) {
            return r;
        }
    }
    if (o->mConnectState != 0) {
        GpiSetErrorMessage(p, data_ov000_021b2d94);
        return 2;
    }
    switch (h) {
        case 1:
            o->mFirewall = 1;
            break;
        case 0:
            o->mFirewall = 0;
            break;
        default:
            GpiSetErrorMessage(p, data_ov000_021b2da8);
            return 2;
    }
    o->mFirewall = 1;
    GpiCopyString(o->mNick, a, 0x1f);
    GpiCopyString((char *) o->mUniquenick, b, 0x15);
    GpiCopyString(o->mEmail, c, 0x33);
    GpiCopyString((char *) o->mPassword, d, 0x1f);
    func_ov000_0218e850((s8 *) o->mEmail);
    q = func_ov000_021a3690(0x308);
    if (q == NULL) {
        GpiSetErrorMessage(p, data_ov000_021b2cdc);
        return 1;
    }
    memset(q, 0, 0x308);
    q->mUnk_304 = i;
    if (*e != 0 && *f != 0) {
        GpiCopyString((char *) q->mUnk_0c2, (const char *) e, 0x100);
        GpiCopyString((char *) q->mUnk_1c2, (const char *) f, 0x100);
    }
    if (g != NULL) {
        GpiCopyString(q->mUnk_2c2, g, 0x41);
    }
    r = GpiCreateOperation(p, 0, (s32) q, (s32 *) &n, j, k, l);
    if (r != 0) {
        return r;
    }
    r = GpiOpenSockets(p, n);
    if (r != 0) {
        n->mUnk_1c = r;
        GpiQueueOperationCallback(p, (GpiOperation *) n);
        GpiCloseConnection(p, 0);
        return r;
    }
    if (n->mUnk_08 != NULL) {
        r = GpiUpdateConnection(p, n->mId);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

u32 GpiWriteLogin(GpConnection *p, Unk021919ac_q *q) {
    GpiConnection *o;
    s8 *s;
    s8 *t;
    Unk021919ac_h *h;
    char a[0x21];
    char b[0x200];
    char c[0x57];
    u16 v;

    o = p->mGpiConnection;
    func_ov000_021920d8((s8 *) q->mUnk_080, 0x20);
    if (q->mUnk_1c2[0] != 0) {
        s = q->mUnk_1c2;
    } else {
        s = o->mPassword;
    }
    func_ov000_0218e0fc((const char *) s, strlen((const char *) s), q->mUnk_0a1);
    if (q->mUnk_0c2[0] != 0) {
        t = q->mUnk_0c2;
    } else if (o->mUniquenick[0] != 0) {
        t = o->mUniquenick;
    } else {
        sprintf(c, data_ov000_021b2c68, o->mNick, o->mEmail);
        t = (s8 *) c;
    }
    sprintf(b, data_ov000_021b2c70, q->mUnk_0a1, data_ov000_021b2c80, t, q->mUnk_080, q, q->mUnk_0a1);
    func_ov000_0218e0fc(b, strlen(b), a);
    if (o->mUnk_100 != 0) {
        func_ov000_0219488c(p, o->mNick, o->mEmail, (void **) &h);
        if (h != NULL) {
            o->mUserId = h->mUnk_04;
            o->mProfileId = h->mUnk_00;
        }
    }
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d54);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2be0);
    GpiAppendBufferString(p, &o->mOutputBuffer, q->mUnk_080);
    if (q->mUnk_0c2[0] != 0) {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d5c);
        GpiAppendBufferString(p, &o->mOutputBuffer, (u8 *) q->mUnk_0c2);
    } else if (o->mUniquenick[0] != 0) {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2c50);
        GpiAppendBufferString(p, &o->mOutputBuffer, (u8 *) o->mUniquenick);
    } else {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d68);
        GpiAppendBufferString(p, &o->mOutputBuffer, o->mNick);
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d70);
        GpiAppendBufferString(p, &o->mOutputBuffer, o->mEmail);
    }
    if (o->mUserId != 0) {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2bf4);
        GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mUserId);
    }
    if (o->mProfileId != 0) {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2c30);
        GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mProfileId);
    }
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d74);
    GpiAppendBufferString(p, &o->mOutputBuffer, a);
    if (o->mFirewall == 1) {
        GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d80);
    }
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d8c);
    v = o->mPort;
    GpiAppendBufferNumber(p, &o->mOutputBuffer, (s16) (u16) (((v >> 8) & 0xff) | ((v << 8) & 0xff00)));
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d18);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mProductId);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d24);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b4d6c);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d30);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mNamespaceId);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2d4c);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 GpiWriteNewuser(GpConnection *a, Unk02191284Data *b) {
    GpiConnection *c;
    u32 d;
    u32 e;
    s8 t;
    s8 f[0x1f];
    s8 g[0x2d];
    s8 h[0x41];
    s8 i[0x59];

    c = a->mGpiConnection;
    d = strlen((const char *) c->mPassword);
    func_ov000_0218e2a4(0x79707367);
    for (e = 0; e < d; e++) {
        t = func_ov000_0218e284(0, 0xff);
        f[e] = t ^ c->mPassword[e];
    }
    f[e] = 0;
    func_ov000_0218e15c(f, g, d, 1);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2cec);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2cf8);
    GpiAppendBufferString(a, &c->mOutputBuffer, c->mEmail);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d00);
    GpiAppendBufferString(a, &c->mOutputBuffer, c->mNick);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d08);
    GpiAppendBufferString(a, &c->mOutputBuffer, g);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d18);
    GpiAppendBufferNumber(a, &c->mOutputBuffer, c->mProductId);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d24);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b4d6c);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d30);
    GpiAppendBufferNumber(a, &c->mOutputBuffer, c->mNamespaceId);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2c50);
    GpiAppendBufferString(a, &c->mOutputBuffer, c->mUniquenick);
    if (b->mUnk_2c2[0] != 0) {
        d = strlen((const char *) b->mUnk_2c2);
        func_ov000_0218e2a4(0x79707367);
        for (e = 0; e < d; e++) {
            t = func_ov000_0218e284(0, 0xff);
            h[e] = t ^ b->mUnk_2c2[e];
        }
        h[e] = 0;
        func_ov000_0218e15c(h, i, d, 1);
        GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d40);
        GpiAppendBufferString(a, &c->mOutputBuffer, i);
    }
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2d4c);
    GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 GpiProcessConnectOperation(GpConnection *a, GpiOperation *b, const char *c) {
    GpiConnection *d;
    Unk02191284Data *e;
    char f[0x21];
    char g[0x15];
    char h[0x200];
    char i[0x52];
    GpiCallback j;
    Unk02191284Node *k;
    void *l;
    u32 m;

    d = a->mGpiConnection;
    if (GpiReadError(a, c, 0) != 0) {
        if (d->mErrorNumber == 0x106 && d->mProfileId != 0) {
            GpiRemoveProfileById(a, d->mProfileId);
            d->mUserId = 0;
            d->mProfileId = 0;
        } else if (d->mErrorNumber == 0x201) {
            if (GpiGetValue(c, data_ov000_021b2b98, h, 0x200) != 0) {
                d->mProfileId = StrtolBase10(h);
            }
        }
        if (strstr(c, data_ov000_021b2ba0) != NULL) {
            GpiSetError(a, d->mErrorNumber, d->mErrorMessage);
            GpiQueueErrorCallback(a, 4, 1);
            return 4;
        }
        GpiSetError(a, d->mErrorNumber, d->mErrorMessage);
        GpiQueueErrorCallback(a, 4, 0);
        return 4;
    }
    e = (Unk02191284Data *) b->mUnk_04;
    switch (b->mUnk_14) {
        case 1:
            if (strncmp(c, data_ov000_021b2ba8, 5) != 0) {
                GpiSetError(a, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (GpiGetValue(c, data_ov000_021b2be0, e->mUnk_000, 0x80) == 0) {
                GpiSetError(a, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (e->mUnk_304 != 0) {
                m = GpiWriteNewuser(a, e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 3;
            } else {
                m = GpiWriteLogin(a, (Unk021919ac_q *) e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 2;
            }
            break;
        case 3:
            if (strncmp(c, data_ov000_021b2bec, 5) != 0) {
                GpiSetError(a, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (GpiGetValue(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            d->mUserId = StrtolBase10(h);
            if (GpiGetValue(c, data_ov000_021b2c30, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            d->mProfileId = StrtolBase10(h);
            m = GpiWriteLogin(a, (Unk021919ac_q *) e);
            if (m != 0) {
                return m;
            }
            b->mUnk_14 = 2;
            break;
        case 2:
            if (strncmp(c, data_ov000_021b2c3c, 5) != 0) {
                GpiSetError(a, 1, data_ov000_021b2bb0);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (GpiGetValue(c, data_ov000_021b2c44, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            d->mSesskey = StrtolBase10(h);
            if (GpiGetValue(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            d->mUserId = StrtolBase10(h);
            if (GpiGetValue(c, data_ov000_021b2c30, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            d->mProfileId = StrtolBase10(h);
            if (GpiGetValue(c, data_ov000_021b2c50, g, 0x15) == 0) {
                g[0] = 0;
            }
            if (GpiGetValue(c, data_ov000_021b2c60, (char *) d->mUnk_474, 0x19) == 0) {
                d->mUnk_474[0] = 0;
            }
            if (e->mUnk_c2[0] != 0) {
                l = e->mUnk_c2;
            } else if (d->mUniquenick[0] != 0) {
                l = d->mUniquenick;
            } else {
                sprintf(i, data_ov000_021b2c68, d->mNick, d->mEmail);
                l = i;
            }
            sprintf(h, data_ov000_021b2c70, e->mUnk_a1, data_ov000_021b2c80, l, e, e->mUnk_80, e->mUnk_a1);
            func_ov000_0218e0fc(h, strlen(h), f);
            if (GpiGetValue(c, data_ov000_021b2cb4, h, 0x200) == 0) {
                GpiSetError(a, 1, data_ov000_021b2c00);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (memcmp(f, h, 0x20) != 0) {
                GpiSetError(a, 0x108, data_ov000_021b2cbc);
                GpiQueueErrorCallback(a, 3, 1);
                return 3;
            }
            if (d->mUnk_100 != 0) {
                GpiProfile *n = GpiFindOrAddProfile(a, d->mProfileId);
                n->mProfileId = d->mProfileId;
                n->mUserId = d->mUserId;
            }
            d->mConnectState = 3;
            j = b->mUnk_0c;
            if (j.mCallback != NULL) {
                k = func_ov000_021a3690(0x20);
                if (k == NULL) {
                    GpiSetErrorMessage(a, data_ov000_021b2cdc);
                    return 1;
                }
                memset(k, 0, 0x20);
                k->mUnk_04 = d->mProfileId;
                k->mUnk_00 = 0;
                GpiCopyString(k->mUnk_08, g, 0x15);
                m = GpiQueueCallback(a, j, k, b, 0);
                if (m != 0) {
                    return m;
                }
            }
            GpiRemoveOperation(a, b);
            break;
    }
    return 0;
}

int func_ov000_02191200(GpConnection *a) {
    int v1;
    GpiConnection *v2;
    int v3;
    v2 = a->mGpiConnection;
    v1 = GpiCheckConnectComplete(a, v2->mConnectSocket, (u32 *) (&v3));
    if (v1 == 0) {
        if (v3 == 4) {
            GpiSetError(a, 0x107u, data_ov000_021b2b48);
            GpiQueueErrorCallback(a, 4, 1);
            return 4;
        }
        if (v3 == 0) {
            return 0;
        }
        if (v3 != 3) {
            AssertionFailed(data_ov000_021b2b70, data_ov000_021b2b88, NULL, 0x2ef);
        }
        v2->mConnectState = 2;
        v1 = 0;
    }
    return v1;
}

u32 func_ov000_02191180(GpConnection *a, GpiProfile *b) {
    GpiConnection *c;

    c = a->mGpiConnection;
    if (b->mBuddyStatus != NULL && c->mUnk_104 == 0) {
        func_ov000_021a3668(b->mBuddyStatus->mUnk_08);
        b->mBuddyStatus->mUnk_08 = NULL;
        func_ov000_021a3668(b->mBuddyStatus->mUnk_0c);
        b->mBuddyStatus->mUnk_0c = NULL;
        func_ov000_021a3668(b->mBuddyStatus);
        b->mBuddyStatus = NULL;
    }
    func_ov000_021a3668(b->mUnk_10);
    b->mUnk_10 = NULL;
    func_ov000_021a3668(b->mUnk_18);
    b->mUnk_18 = NULL;
    b->mUnk_14 = 0;
    if (b->mUnk_0c == 0 || (c->mUnk_104 == 1 && b->mBuddyStatus == NULL)) {
        GpiRemoveProfile(a, b);
        return 0;
    }
    return 1;
}

void GpiCloseConnection(GpConnection *a, s32 b) {
    GpiConnection *c;
    GpiOperation *d;
    GpiPeer *e;
    u32 f;

    c = a->mGpiConnection;
    if (c->mConnectState == 4) {
        return;
    }
    if (c->mConnectState != 0) {
        if (b != 0 && c->mConnectState == 3) {
            GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2b28);
            GpiAppendBufferNumber(a, &c->mOutputBuffer, c->mSesskey);
            GpiAppendBufferString(a, &c->mOutputBuffer, data_ov000_021b2b3c);
        }
        GpiSendBuffer(a, c->mConnectSocket, &c->mOutputBuffer, &f, 1, data_ov000_021b2b44);
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
    func_ov000_021a3668(c->mOutputBuffer.mBuffer);
    c->mOutputBuffer.mBuffer = NULL;
    func_ov000_021a3668(c->mUpdateproBuffer);
    c->mUpdateproBuffer = NULL;
    func_ov000_021a3668(c->mUpdateuiBuffer);
    c->mUpdateuiBuffer = NULL;
    while (c->mOperationList != NULL) {
        GpiRemoveOperation(a, c->mOperationList);
    }
    c->mOperationList = NULL;
    e = c->mPeerList;
    while (e != NULL) {
        GpiPeer *g = e;
        e = e->mNext;
        GpiPeerDelete(a, g);
    }
    c->mPeerList = NULL;
    while (GpiForEachProfileWhileNonZero(a, func_ov000_02191180, NULL) == 0) {
    }
}
