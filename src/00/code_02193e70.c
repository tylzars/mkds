#include "00/code_02190548.h"
#include "00/code_0219218c.h"
#include "00/code_02193e70.h"
#include "00/code_02192000.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021947e4.h"

#include "00/code_02193818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/code_0218e49c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_0218dc44.h"
#include "00/code_021a3668.h"
#include "00/unk_021b3000.h"
#include "code_021382a8.h"
#include "00/code_0218d818.h"
#include "00/code_02196590.h"
#include "code_02135014.h"
#include "code_0213a460.h"
#include "00/code_0218fca8.h"
#include "00/code_021965a0.h"
#include "00/code_021965c8.h"

s32 func_ov000_02194590(GpConnection *a, Unk02193f2cNode *b) {
    GpiConnection *r;
    Unk02193f2cNode *p;
    BOOL f;
    s32 t;
    s32 x;
    s32 y;
    s32 z;
    Unk02194934 *e;
    u8 *q;
    u8 *w;

    r = a->mGpiConnection;
    switch (b->mUnk_00) {
        case 0x65:
            break;
        case 0x66:
            t = func_ov000_02193d64(a, b);
            if (t != 0) {
                return t;
            }
            break;
        case 0x67:
            t = func_ov000_02196714(a, b->mUnk_08, (u32 *) &x);
            if (t != 0) {
                return t;
            }
            if (x == 4) {
                func_ov000_02196590(a, data_ov000_021b33a0);
                return 3;
            } else if (x == 3) {
                f = TRUE;
                if (func_ov000_02194934(a, b->mUnk_0c, &e) == 0) {
                    func_ov000_02196590(a, data_ov000_021b33a0);
                    return 3;
                }
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34d0);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34d8);
                func_ov000_02190b58(a, b->mUnk_28, r->mProfileId);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34e0);
                func_ov000_02190b80(a, b->mUnk_28, r->mNick);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34e8);
                func_ov000_02190b80(a, b->mUnk_28, e->mUnk_18);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
                for (p = r->mPeerList; p != NULL; p = p->mNext) {
                    if (p->mUnk_0c == b->mUnk_0c && p != b && p->mUnk_00 <= 0x67) {
                        f = FALSE;
                    }
                }
                if (f != FALSE) {
                    func_ov000_021a3668(e->mUnk_18);
                    e->mUnk_18 = NULL;
                    if (func_ov000_021947e4(e) != 0) {
                        func_ov000_021948f8(a, e);
                    }
                }
                b->mUnk_00 = 0x68;
            }
            break;
        case 0x68:
            t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &y, (u32 *) &z,
                                    data_ov000_021b3490);
            if (t != 0) {
                return t;
            }
            w = strstr(b->mUnk_18, data_ov000_021b34c8);
            if (w == NULL) {
                break;
            }
            *w = 0;
            q = b->mUnk_18;
            if (strncmp(q, data_ov000_021b34f8, 7) == 0) {
                b->mUnk_14 = b->mUnk_14 + 1;
                if (b->mUnk_14 > 1) {
                    func_ov000_02196590(a, data_ov000_021b3508);
                    return 3;
                }
                t = func_ov000_02193e70(a, b);
                if (t != 0) {
                    return t;
                }
            } else if (strncmp(q, data_ov000_021b3500, 6) != 0) {
                func_ov000_02196590(a, data_ov000_021b352c);
                return 3;
            }
            b->mUnk_00 = 0x69;
            b->mUnk_20 = 0;
            break;
        default:
            func_0213442c(data_ov000_021b3440, data_ov000_021b333c, NULL, 0x9f);
            break;
    }
    if (b->mUnk_30 > 0) {
        t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) b->mUnk_28, (u32 *) &z, 1, data_ov000_021b3490);
        if (z != 0 || t != 0) {
            b->mUnk_00 = 0x6a;
        }
    }
    return 0;
}

s32 func_ov000_021943f0(GpConnection *a, Unk02193f2cNode *b) {
    GpiConnection *r;
    s32 x;
    s32 y;
    s32 t;
    s32 v;
    u8 *p;
    u8 *q;
    u8 c0[0x10];
    u8 c1[0x1f];
    u8 c2[0x21];
    u8 c3[0x21];
    u8 c4[0x103];

    r = a->mGpiConnection;
    if (b->mUnk_00 != 0x68) {
        func_0213442c(data_ov000_021b34a8, data_ov000_021b333c, NULL, 0xc1);
    }
    t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &x, (u32 *) &y, data_ov000_021b3490);
    if (t != 0) {
        return t;
    }
    if (y != 0) {
        b->mUnk_00 = 0x6a;
        return 0;
    }
    p = strstr(b->mUnk_18, data_ov000_021b34c8);
    if (p != NULL) {
        *p = 0;
        q = b->mUnk_18;
        if (strncmp(q, data_ov000_021b34d0, 6) == 0) {
            if (func_ov000_021967b4(q, data_ov000_021b34d8, c0, 0x10) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            v = func_0213bf90(c0);
            if (func_ov000_021967b4(b->mUnk_18, data_ov000_021b34e0, c1, 0x1f) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            if (func_ov000_021967b4(b->mUnk_18, data_ov000_021b34e8, c2, 0x21) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            sprintf(c4, data_ov000_021b34f0, r->mPassword, r->mProfileId, v);
            func_ov000_0218e0fc(c4, strlen(c4), c3);
            if (strcmp(c2, c3) != 0) {
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34f8);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
                b->mUnk_00 = 0x6a;
                return 0;
            }
            func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b3500);
            func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
            b->mUnk_00 = 0x69;
            b->mUnk_0c = v;
        } else {
            b->mUnk_00 = 0x6a;
            return 0;
        }
        b->mUnk_20 = 0;
    }
    return 0;
}

s32 func_ov000_02194370(GpConnection *a, Unk02193f2cNode *b) {
    Unk02194370Entry *c;
    s32 y;
    s32 t;

    if (b->mUnk_30 != 0) {
        return 0;
    }
    if (func_ov000_0218dc44(b->mUnk_38) != 0) {
        do {
            c = func_ov000_0218dbf8(b->mUnk_38, 0);
            t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) c, (u32 *) &y, 0, data_ov000_021b3490);
            if (y != 0 || t != 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            if (c->mUnk_0c != c->mUnk_08) {
                break;
            }
            func_ov000_0218da5c(b->mUnk_38, 0);
        } while (func_ov000_0218dc44(b->mUnk_38) != 0);
    }
    return 0;
}

s32 func_ov000_021941c4(GpConnection *a, Unk02193f2cNode *b) {
    GpiConnection *r;
    Unk021941c4Msg *s;
    s32 x;
    s32 y;
    Unk02190ed4Cb p;
    s32 m;
    s32 n;
    s32 o;
    s32 t;

    r = a->mGpiConnection;
    if (b->mUnk_30 != 0) {
        t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) b->mUnk_28, (u32 *) &y, 1, data_ov000_021b3490);
        if (y != 0 || t != 0) {
            b->mUnk_00 = 0x6a;
            return 0;
        }
    }
    if (b->mUnk_30 == 0) {
        t = func_ov000_02194370(a, b);
        if (t != 0) {
            return t;
        }
        if (b->mUnk_00 == 0x6a) {
            return 0;
        }
    }
    t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &x, (u32 *) &y, data_ov000_021b3490);
    if (t != 0) {
        b->mUnk_00 = 0x6a;
        return 0;
    }
    if (x > 0) {
        b->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    }
    do {
        t = func_ov000_02190618(a, (Unk021906e4 *) &b->mUnk_18, &m, &n, &o);
        if (t != 0) {
            return t;
        }
        if (m != 0) {
            switch (n) {
                case 1:
                    p = r->mCallbacks[3];
                    if (p.mUnk_00 != NULL) {
                        s = func_ov000_021a3690(0xc);
                        if (s == NULL) {
                            func_ov000_02196590(a, data_ov000_021b3494);
                            return 1;
                        }
                        s->mUnk_00 = b->mUnk_0c;
                        s->mUnk_08 = (u32) func_ov000_0218e880((u8 *) m);
                        s->mUnk_04 = func_ov000_0218e320(NULL);
                        t = func_ov000_02190ed4(a, p, s, NULL, 2);
                        if (t != 0) {
                            return t;
                        }
                    }
                    break;
                case 0x66:
                    func_ov000_0218fb3c(a, b->mUnk_0c, 0x67, data_ov000_021b34a4);
                    break;
                case 200:
                case 201:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                    func_ov000_02196434(a, b, n, b->mUnk_18, m, o);
                    break;
            }
            func_ov000_021905d4(a, (Unk021906e4 *) &b->mUnk_18);
        }
    } while (m != 0);
    if (y != 0) {
        b->mUnk_00 = 0x6a;
    }
    return 0;
}

s32 func_ov000_02194160(GpConnection *b, Unk02193f2cNode *c) {
    s32 a = 0;

    if (c->mUnk_00 == 0x64) {
        func_0213442c(data_ov000_021b3468, data_ov000_021b333c, NULL, 0x1d9);
    }
    if (c->mUnk_00 != 0x69) {
        if (c->mUnk_04 != 0) {
            a = func_ov000_02194590(b, c);
        } else {
            a = func_ov000_021943f0(b, c);
        }
    }
    if (a == 0 && c->mUnk_00 == 0x69) {
        a = func_ov000_021941c4(b, c);
    }
    return a;
}

void func_ov000_02194120(GpConnection *a, Unk02193f2cNode *b) {
    func_ov000_0218e524(b->mUnk_08, 2);
    func_ov000_0218e53c(b->mUnk_08);
    func_ov000_021a3668(b->mUnk_18);
    b->mUnk_18 = NULL;
    func_ov000_021a3668(*(void **) b->mUnk_28);
    *(void **) b->mUnk_28 = NULL;
    if (b->mUnk_38 != NULL) {
        func_ov000_0218dc48(b->mUnk_38);
        b->mUnk_38 = NULL;
    }
    func_ov000_021a3668(b);
}

void func_ov000_0219405c(GpConnection *f, Unk02193f2cNode *g) {
    GpiConnection *a = f->mGpiConnection;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    Unk0219405c *d;
    s32 e;

    if (g == NULL) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x213);
    }
    b = a->mPeerList;
    if (b == g) {
        a->mPeerList = g->mNext;
    } else {
        c = b->mNext;
        while (c != g) {
            if (c == NULL) {
                func_0213442c(data_ov000_021b3440, data_ov000_021b333c, NULL, 0x225);
                func_ov000_0219690c(f, data_ov000_021b3444);
                return;
            }
            b = c;
            c = c->mNext;
        }
        b->mNext = g->mNext;
    }
    if (func_ov000_0218dc44(g->mUnk_38) != 0) {
        do {
            d = func_ov000_0218dbf8(g->mUnk_38, 0);
            if (d->mUnk_10 < 0x64) {
                func_ov000_0218fbe0(f, g->mUnk_0c, d->mUnk_10, (const u8 *) (d->mUnk_00 + d->mUnk_14));
            }
            func_ov000_0218da5c(g->mUnk_38, 0);
        } while (func_ov000_0218dc44(g->mUnk_38) != 0);
    }
    func_ov000_02194120(f, g);
}

void func_ov000_02193ff4(s32 a) {
    func_ov000_0218e7dc(a, 0x4000);
    func_ov000_0218e7dc(a, 0x8000);
    func_ov000_0218e7dc(a, 0x10000);
    func_ov000_0218e7dc(a, 0x20000);
    func_ov000_0218e7dc(a, 0x40000);
    func_ov000_0218e7ac(a, 0x4000);
    func_ov000_0218e7ac(a, 0x8000);
    func_ov000_0218e7ac(a, 0x10000);
    func_ov000_0218e77c(a);
    func_ov000_0218e74c(a);
}

s32 func_ov000_02193f50(GpConnection *e) {
    GpiConnection *a = e->mGpiConnection;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    s32 d;

    if (a->mListenSocket != -1 && func_ov000_0218e668(a->mListenSocket) != 0) {
        d = func_ov000_0218e478(a->mListenSocket, NULL, NULL);
        if (d != -1) {
            b = func_ov000_02193eac(e, -1, 0);
            if (b != NULL) {
                b->mUnk_00 = 0x68;
                b->mUnk_08 = d;
                func_ov000_0218e80c(d, 0);
                func_ov000_02193ff4(b->mUnk_08);
            } else {
                func_ov000_0218e53c(d);
            }
        }
    }
    b = a->mPeerList;
    while (b != NULL) {
        c = b->mNext;
        d = func_ov000_02194160(e, b);
        if (b->mUnk_00 == 0x6a || d != 0 || (s32) func_ov000_0218e320(NULL) > b->mUnk_10) {
            func_ov000_0219405c(e, b);
        }
        b = c;
    }
    return 0;
}

Unk02193f2cNode *func_ov000_02193f2c(GpConnection *object, u32 key) {
    Unk02193f2cNode *node = object->mGpiConnection->mPeerList;
    while (node != NULL) {
        if (node->mUnk_0c == key && node->mUnk_00 == 0x69) {
            return node;
        }
        node = node->mNext;
    }
    return NULL;
}

void func_ov000_02193f18(u32 *a) {
    func_ov000_021a3668((void *) (*a));
    *a = 0;
    return;
}

Unk02193f2cNode *func_ov000_02193eac(GpConnection *c, u32 d, u32 e) {
    GpiConnection *a = c->mGpiConnection;
    Unk02193f2cNode *b = func_ov000_021a3690(0x40);

    if (b == NULL) {
        return NULL;
    }
    memset(b, 0, 0x40);
    b->mUnk_00 = 0x64;
    b->mUnk_04 = e;
    b->mUnk_08 = -1;
    b->mUnk_0c = d;
    b->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    b->mNext = a->mPeerList;
    b->mUnk_38 = (void *) func_ov000_0218dc94(0x18, 0, (void (*)(void *)) func_ov000_02193f18);
    a->mPeerList = b;
    return b;
}

int func_ov000_02193e70(GpConnection *a, Unk02193f2cNode *b) {
    int v1;
    int v2[2];
    v1 = func_ov000_021938cc(a, 2, 0, v2, 0, 0, 0);
    if ((v1 == 0) && (v1 = func_ov000_02192330(a, (u32) (b->mUnk_0c), (u32) (*(u32 *) (v2[0] + 0x18))), v1 == 0)) {
        b->mUnk_00 = 0x65;
        v1 = 0;
    }
    return v1;
}
