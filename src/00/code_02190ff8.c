#include "00/code_02190ff8.h"

#include "00/code_02193634.h"
#include "00/code_02194840.h"
#include "00/code_0218e2a4.h"
#include "00/code_02191200.h"
#include "00/code_021965a0.h"
#include "00/code_0218eb9c.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "00/code_021965c8.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"
#include "code_021384cc.h"
#include "code_02133048.h"

void func_ov000_021920d8(s8 *p, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        p[i] = data_ov000_021b2f18[rand() % 0x3e];
    }
    p[i] = 0;
}

u32 func_ov000_02191e58(GpConnection *p, Unk021919ac_node *n) {
    GpiConnection *o;
    Unk021919ac_sa s;
    Unk021a8f84 *x;
    s32 z;
    s32 r;

    o = p->mGpiConnection;
    if (o->mFirewall == 0) {
        o->mListenSocket = func_ov000_0218e554(2, 1, 0);
        if (o->mListenSocket == -1) {
            func_ov000_021965a0(p, 5, data_ov000_021b2dbc);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
        if (func_ov000_0218e80c(o->mListenSocket, 0) == 0) {
            func_ov000_021965a0(p, 5, data_ov000_021b2de4);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
        __builtin__clear(&s, sizeof(s));
        s.f.mUnk_01 = 2;
        if (func_ov000_0218e4e4(o->mListenSocket, &s, 8) == -1) {
            func_ov000_021965a0(p, 5, data_ov000_021b2e18);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
        if (func_ov000_0218e49c(o->mListenSocket, 5) == -1) {
            func_ov000_021965a0(p, 5, data_ov000_021b2e40);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
        z = 8;
        if (func_ov000_0218e394(o->mListenSocket, &s, (u32 *) &z) == -1) {
            func_ov000_021965a0(p, 5, data_ov000_021b2e6c);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
        o->mPort = s.f.mUnk_02;
    } else {
        o->mListenSocket = -1;
        o->mPort = 0;
    }
    o->mConnectSocket = func_ov000_0218e554(2, 1, 0);
    if (o->mConnectSocket == -1) {
        func_ov000_021965a0(p, 5, data_ov000_021b2dbc);
        func_ov000_02190f4c(p, 3, 1);
        return 3;
    }
    if (func_ov000_0218e80c(o->mConnectSocket, 0) == 0) {
        func_ov000_021965a0(p, 5, data_ov000_021b2de4);
        func_ov000_02190f4c(p, 3, 1);
        return 3;
    }
    x = func_ov000_021a8f84(data_ov000_021b2ae8);
    if (x == NULL) {
        func_ov000_021965a0(p, 5, data_ov000_021b2e9c);
        func_ov000_02190f4c(p, 3, 1);
        return 3;
    }
    __builtin__clear(&s, sizeof(s));
    s.f.mUnk_01 = 2;
    s.f.mUnk_04 = **x->mUnk_0c;
    if (s.f.mUnk_04 == 0) {
        func_0213442c(data_ov000_021b2ed0, data_ov000_021b2b88, NULL, 0x90);
    }
    s.f.mUnk_02 = 0xcc74;
    if (func_ov000_0218e4b4(o->mConnectSocket, &s, 8) == -1) {
        r = func_ov000_0218e368(o->mConnectSocket);
        if (r != -6 && r != -26 && r != -76) {
            func_ov000_021965a0(p, 5, data_ov000_021b2ef0);
            func_ov000_02190f4c(p, 3, 1);
            return 3;
        }
    }
    n->mUnk_14 = 1;
    o->mConnectState = 1;
    return 0;
}

u32 func_ov000_02191cb0(GpConnection *p, const char *a, const char *b, const char *c, const char *d, const s8 *e,
                        const s8 *f, const char *g, s32 h, s32 i, s32 j, s32 k, s32 l) {
    GpiConnection *o;
    Unk021919ac_q *q;
    Unk021919ac_node *n;
    u32 r;

    o = p->mGpiConnection;
    if (o->mConnectState == 4) {
        r = func_ov000_0218f654(p);
        if (r != 0) {
            return r;
        }
    }
    if (o->mConnectState != 0) {
        func_ov000_02196590(p, data_ov000_021b2d94);
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
            func_ov000_02196590(p, data_ov000_021b2da8);
            return 2;
    }
    o->mFirewall = 1;
    func_ov000_02196914(o->mNick, a, 0x1f);
    func_ov000_02196914((char *) o->mUniquenick, b, 0x15);
    func_ov000_02196914(o->mEmail, c, 0x33);
    func_ov000_02196914((char *) o->mPassword, d, 0x1f);
    func_ov000_0218e850((s8 *) o->mEmail);
    q = func_ov000_021a3690(0x308);
    if (q == NULL) {
        func_ov000_02196590(p, data_ov000_021b2cdc);
        return 1;
    }
    memset(q, 0, 0x308);
    q->mUnk_304 = i;
    if (*e != 0 && *f != 0) {
        func_ov000_02196914((char *) q->mUnk_0c2, (const char *) e, 0x100);
        func_ov000_02196914((char *) q->mUnk_1c2, (const char *) f, 0x100);
    }
    if (g != NULL) {
        func_ov000_02196914(q->mUnk_2c2, g, 0x41);
    }
    r = func_ov000_021938cc(p, 0, (s32) q, (s32 *) &n, j, k, l);
    if (r != 0) {
        return r;
    }
    r = func_ov000_02191e58(p, n);
    if (r != 0) {
        n->mUnk_1c = r;
        func_ov000_02193954(p, (Unk021937c0Node *) n);
        func_ov000_02190ff8(p, 0);
        return r;
    }
    if (n->mUnk_08 != NULL) {
        r = func_ov000_0218f2e8(p, n->mUnk_18);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

u32 func_ov000_021919ac(GpConnection *p, Unk021919ac_q *q) {
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
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d54);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2be0);
    func_ov000_02190b80(p, &o->mOutputBuffer, q->mUnk_080);
    if (q->mUnk_0c2[0] != 0) {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d5c);
        func_ov000_02190b80(p, &o->mOutputBuffer, (u8 *) q->mUnk_0c2);
    } else if (o->mUniquenick[0] != 0) {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2c50);
        func_ov000_02190b80(p, &o->mOutputBuffer, (u8 *) o->mUniquenick);
    } else {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d68);
        func_ov000_02190b80(p, &o->mOutputBuffer, o->mNick);
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d70);
        func_ov000_02190b80(p, &o->mOutputBuffer, o->mEmail);
    }
    if (o->mUserId != 0) {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2bf4);
        func_ov000_02190b58(p, &o->mOutputBuffer, o->mUserId);
    }
    if (o->mProfileId != 0) {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2c30);
        func_ov000_02190b58(p, &o->mOutputBuffer, o->mProfileId);
    }
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d74);
    func_ov000_02190b80(p, &o->mOutputBuffer, a);
    if (o->mFirewall == 1) {
        func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d80);
    }
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d8c);
    v = o->mPort;
    func_ov000_02190b58(p, &o->mOutputBuffer, (s16) (u16) (((v >> 8) & 0xff) | ((v << 8) & 0xff00)));
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d18);
    func_ov000_02190b58(p, &o->mOutputBuffer, o->mProductId);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d24);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b4d6c);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d30);
    func_ov000_02190b58(p, &o->mOutputBuffer, o->mNamespaceId);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2d4c);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 func_ov000_021917b0(GpConnection *a, Unk02191284Data *b) {
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
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2cec);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2cf8);
    func_ov000_02190b80(a, &c->mOutputBuffer, c->mEmail);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d00);
    func_ov000_02190b80(a, &c->mOutputBuffer, c->mNick);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d08);
    func_ov000_02190b80(a, &c->mOutputBuffer, g);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d18);
    func_ov000_02190b58(a, &c->mOutputBuffer, c->mProductId);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d24);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b4d6c);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d30);
    func_ov000_02190b58(a, &c->mOutputBuffer, c->mNamespaceId);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2c50);
    func_ov000_02190b80(a, &c->mOutputBuffer, c->mUniquenick);
    if (b->mUnk_2c2[0] != 0) {
        d = strlen((const char *) b->mUnk_2c2);
        func_ov000_0218e2a4(0x79707367);
        for (e = 0; e < d; e++) {
            t = func_ov000_0218e284(0, 0xff);
            h[e] = t ^ b->mUnk_2c2[e];
        }
        h[e] = 0;
        func_ov000_0218e15c(h, i, d, 1);
        func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d40);
        func_ov000_02190b80(a, &c->mOutputBuffer, i);
    }
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2d4c);
    func_ov000_02190b80(a, &c->mOutputBuffer, data_ov000_021b2b3c);
    return 0;
}

u32 func_ov000_02191284(GpConnection *a, Unk021937c0Node *b, const char *c) {
    GpiConnection *d;
    Unk02191284Data *e;
    char f[0x21];
    char g[0x15];
    char h[0x200];
    char i[0x52];
    Unk02190ed4Cb j;
    Unk02191284Node *k;
    void *l;
    u32 m;

    d = a->mGpiConnection;
    if (func_ov000_02196870(a, c, 0) != 0) {
        if (d->mErrorNumber == 0x106 && d->mProfileId != 0) {
            func_ov000_0219490c(a, d->mProfileId);
            d->mUserId = 0;
            d->mProfileId = 0;
        } else if (d->mErrorNumber == 0x201) {
            if (func_ov000_021967b4(c, data_ov000_021b2b98, h, 0x200) != 0) {
                d->mProfileId = func_0213bf90(h);
            }
        }
        if (strstr(c, data_ov000_021b2ba0) != NULL) {
            func_ov000_021965a0(a, d->mErrorNumber, d->mErrorMessage);
            func_ov000_02190f4c(a, 4, 1);
            return 4;
        }
        func_ov000_021965a0(a, d->mErrorNumber, d->mErrorMessage);
        func_ov000_02190f4c(a, 4, 0);
        return 4;
    }
    e = (Unk02191284Data *) b->mUnk_04;
    switch (b->mUnk_14) {
        case 1:
            if (strncmp(c, data_ov000_021b2ba8, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2be0, e->mUnk_000, 0x80) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (e->mUnk_304 != 0) {
                m = func_ov000_021917b0(a, e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 3;
            } else {
                m = func_ov000_021919ac(a, (Unk021919ac_q *) e);
                if (m != 0) {
                    return m;
                }
                b->mUnk_14 = 2;
            }
            break;
        case 3:
            if (strncmp(c, data_ov000_021b2bec, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUserId = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c30, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mProfileId = func_0213bf90(h);
            m = func_ov000_021919ac(a, (Unk021919ac_q *) e);
            if (m != 0) {
                return m;
            }
            b->mUnk_14 = 2;
            break;
        case 2:
            if (strncmp(c, data_ov000_021b2c3c, 5) != 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2bb0);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2c44, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mSesskey = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2bf4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mUserId = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c30, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            d->mProfileId = func_0213bf90(h);
            if (func_ov000_021967b4(c, data_ov000_021b2c50, g, 0x15) == 0) {
                g[0] = 0;
            }
            if (func_ov000_021967b4(c, data_ov000_021b2c60, (char *) d->mUnk_474, 0x19) == 0) {
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
            if (func_ov000_021967b4(c, data_ov000_021b2cb4, h, 0x200) == 0) {
                func_ov000_021965a0(a, 1, data_ov000_021b2c00);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (memcmp(f, h, 0x20) != 0) {
                func_ov000_021965a0(a, 0x108, data_ov000_021b2cbc);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
            if (d->mUnk_100 != 0) {
                Unk02194934 *n = func_ov000_0219496c(a, d->mProfileId);
                n->mUnk_00 = d->mProfileId;
                n->mUnk_04 = d->mUserId;
            }
            d->mConnectState = 3;
            j = b->mUnk_0c;
            if (j.mUnk_00 != NULL) {
                k = func_ov000_021a3690(0x20);
                if (k == NULL) {
                    func_ov000_02196590(a, data_ov000_021b2cdc);
                    return 1;
                }
                memset(k, 0, 0x20);
                k->mUnk_04 = d->mProfileId;
                k->mUnk_00 = 0;
                func_ov000_02196914(k->mUnk_08, g, 0x15);
                m = func_ov000_02190ed4(a, j, k, b, 0);
                if (m != 0) {
                    return m;
                }
            }
            func_ov000_02193818(a, b);
            break;
    }
    return 0;
}

int func_ov000_02191200(GpConnection *a) {
    int v1;
    GpiConnection *v2;
    int v3;
    v2 = a->mGpiConnection;
    v1 = func_ov000_02196714(a, v2->mConnectSocket, (u32 *) (&v3));
    if (v1 == 0) {
        if (v3 == 4) {
            func_ov000_021965a0(a, 0x107u, data_ov000_021b2b48);
            func_ov000_02190f4c(a, 4, 1);
            return 4;
        }
        if (v3 == 0) {
            return 0;
        }
        if (v3 != 3) {
            func_0213442c(data_ov000_021b2b70, data_ov000_021b2b88, NULL, 0x2ef);
        }
        v2->mConnectState = 2;
        v1 = 0;
    }
    return v1;
}

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
