#include "00/code_021919ac.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218e49c.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"
#include "code_021384dc.h"
#include "code_0213442c.h"
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

u32 func_ov000_02191cb0(GpConnection *p, const u8 *a, const u8 *b, const u8 *c, const u8 *d, const s8 *e, const s8 *f,
                        const u8 *g, s32 h, s32 i, s32 j, s32 k, s32 l) {
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
    func_ov000_02196914((u8 *) o->mUniquenick, b, 0x15);
    func_ov000_02196914(o->mEmail, c, 0x33);
    func_ov000_02196914((u8 *) o->mPassword, d, 0x1f);
    func_ov000_0218e850((s8 *) o->mEmail);
    q = func_ov000_021a3690(0x308);
    if (q == NULL) {
        func_ov000_02196590(p, data_ov000_021b2cdc);
        return 1;
    }
    memset(q, 0, 0x308);
    q->mUnk_304 = i;
    if (*e != 0 && *f != 0) {
        func_ov000_02196914((u8 *) q->mUnk_0c2, e, 0x100);
        func_ov000_02196914((u8 *) q->mUnk_1c2, f, 0x100);
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
    u8 a[0x21];
    u8 b[0x200];
    u8 c[0x57];
    u16 v;

    o = p->mGpiConnection;
    func_ov000_021920d8((s8 *) q->mUnk_080, 0x20);
    if (q->mUnk_1c2[0] != 0) {
        s = q->mUnk_1c2;
    } else {
        s = o->mPassword;
    }
    func_ov000_0218e0fc((const u8 *) s, strlen((const u8 *) s), q->mUnk_0a1);
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
