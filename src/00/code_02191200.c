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
#include "00/code_02193818.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"

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
