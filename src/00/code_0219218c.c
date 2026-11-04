#include "00/code_0219218c.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f960.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0219210c.h"
#include "00/code_02193000.h"
#include "00/code_02194000.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "code_02135014.h"
#include "code_0213a460.h"
#include "code_02133048.h"
#include "00/code_0218e49c.h"

u32 func_ov000_02192d30(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = func_ov000_02190b80(p, &o->mUpdateproBuffer, a);
    if (r != 0) {
        return r;
    }
    r = func_ov000_02190b80(p, &o->mUpdateproBuffer, b);
    if (r != 0) {
        return r;
    }
    return 0;
}

u32 func_ov000_02192cfc(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = func_ov000_02190b80(p, &o->mUpdateuiBuffer, a);
    if (r != 0) {
        return r;
    }
    r = func_ov000_02190b80(p, &o->mUpdateuiBuffer, b);
    if (r != 0) {
        return r;
    }
    return 0;
}

u32 func_ov000_0219296c(GpConnection *p, s32 a, s32 b) {
    char c[0x10];
    u32 r;

    switch (a) {
        case 0x708:
            if (b < 0) {
                func_ov000_02196590(p, data_ov000_021b30e4);
                return 2;
            }
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b301c, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70b:
            switch (b) {
                case 0x500:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3050);
                    if (r != 0) {
                        return r;
                    }
                    break;
                case 0x501:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3054);
                    if (r != 0) {
                        return r;
                    }
                    break;
                case 0x502:
                    r = func_ov000_02192d30(p, data_ov000_021b305c, data_ov000_021b3058);
                    if (r != 0) {
                        return r;
                    }
                    break;
                default:
                    func_ov000_02196590(p, data_ov000_021b30f8);
                    return 2;
            }
            break;
        case 0x706:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b3064, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70c:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3108, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70d:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3118, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70e:
            sprintf(c, data_ov000_021b2f9c, b / 16);
            r = func_ov000_02192cfc(p, data_ov000_021b3124, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x710:
            sprintf(c, data_ov000_021b2f9c, b / 4);
            r = func_ov000_02192cfc(p, data_ov000_021b3130, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x712:
            sprintf(c, data_ov000_021b2f9c, b / 4);
            r = func_ov000_02192cfc(p, data_ov000_021b3140, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x713:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3150, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x714:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3160, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x715:
            if (b != 0) {
                b = 1;
            }
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192cfc(p, data_ov000_021b3174, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x718:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30ac, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x719:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30b4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71a:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30bc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71b:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30c4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71c:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30cc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71d:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30d4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71e:
            sprintf(c, data_ov000_021b2f9c, b);
            r = func_ov000_02192d30(p, data_ov000_021b30dc, c);
            if (r != 0) {
                return r;
            }
            break;
        default:
            func_ov000_02196590(p, data_ov000_021b2fa0);
            return 2;
    }
    return 0;
}

u32 func_ov000_021923b4(GpConnection *p, s32 a, const s8 *b) {
    GpiConnection *o;
    char c[0x100];
    u32 r;

    o = p->mGpiConnection;
    if (b == NULL) {
        func_ov000_02196590(p, data_ov000_021b2fbc);
        return 2;
    }
    switch (a) {
        case 0x700:
            if (*b == 0) {
                func_ov000_02196590(p, data_ov000_021b2fbc);
                return 2;
            }
            func_ov000_02196914(c, (const char *) b, 0x1f);
            func_ov000_02196914(o->mNick, c, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2fcc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x701:
            if (*b == 0) {
                func_ov000_02196590(p, data_ov000_021b2fbc);
                return 2;
            }
            func_ov000_02196914(c, (const char *) b, 0x15);
            func_ov000_02196914((char *) o->mUniquenick, c, 0x15);
            r = func_ov000_02192d30(p, data_ov000_021b2fd4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x702:
            if (*b == 0) {
                func_ov000_02196590(p, data_ov000_021b2fbc);
                return 2;
            }
            func_ov000_02196914(c, (const char *) b, 0x33);
            func_ov000_0218e850((s8 *) c);
            func_ov000_02196914(o->mEmail, c, 0x33);
            r = func_ov000_02192cfc(p, data_ov000_021b2fe4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x703:
            if (*b == 0) {
                func_ov000_02196590(p, data_ov000_021b2fbc);
                return 2;
            }
            func_ov000_02196914(c, (const char *) b, 0x1f);
            func_ov000_02196914((char *) o->mPassword, c, 0x1f);
            r = func_ov000_02192cfc(p, data_ov000_021b2fec, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x704:
            func_ov000_02196914(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2ff8, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x705:
            func_ov000_02196914(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b3004, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x707:
            func_ov000_02196914(c, (const char *) b, 0x4c);
            r = func_ov000_02192d30(p, data_ov000_021b3010, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x708:
            func_ov000_02196914(c, (const char *) b, 0xb);
            r = func_ov000_02192d30(p, data_ov000_021b301c, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x709:
            if (strlen((const char *) b) != 2) {
                func_ov000_02196590(p, data_ov000_021b3028);
                return 2;
            }
            func_ov000_02196914(c, (const char *) b, 3);
            r = func_ov000_02192d30(p, data_ov000_021b3040, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70b: {
            s32 d;

            d = *b;
            if (d >= 0 && d < 0x80) {
                d = data_0215d204[d];
            }
            if ((s8) d == 0x4d) {
                __memcpy(c, data_ov000_021b3050, 2);
            } else if ((s8) d == 0x46) {
                __memcpy(c, data_ov000_021b3054, 2);
            } else {
                __memcpy(c, data_ov000_021b3058, 2);
            }
            r = func_ov000_02192d30(p, data_ov000_021b305c, c);
            if (r != 0) {
                return r;
            }
            break;
        }
        case 0x706:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3064, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70d:
            r = func_ov000_0219296c(p, 0x70d, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70e:
            r = func_ov000_0219296c(p, 0x70e, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70f:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3070, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x710:
            r = func_ov000_0219296c(p, 0x710, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x711:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3084, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x712:
            r = func_ov000_0219296c(p, 0x712, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x714:
            r = func_ov000_0219296c(p, 0x714, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x715:
            r = func_ov000_0219296c(p, 0x715, func_0213bf90((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x716:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3098, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x717:
            func_ov000_02196914(c, (const char *) b, 0x33);
            r = func_ov000_02192d30(p, data_ov000_021b30a4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x718:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30ac, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x719:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30b4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71a:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30bc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71b:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30c4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71c:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30cc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71d:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30d4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71e:
            func_ov000_02196914(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30dc, c);
            if (r != 0) {
                return r;
            }
            break;
        default:
            func_ov000_02196590(p, data_ov000_021b2fa0);
            return 2;
    }
    return 0;
}

u32 func_ov000_02192330(GpConnection *p, u32 a, u32 b) {
    GpiConnection *o;

    o = p->mGpiConnection;
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2f68);
    func_ov000_02190b58(p, &o->mOutputBuffer, o->mSesskey);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2f80);
    func_ov000_02190b58(p, &o->mOutputBuffer, a);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2f8c);
    func_ov000_02190b58(p, &o->mOutputBuffer, b);
    func_ov000_02190b80(p, &o->mOutputBuffer, data_ov000_021b2f94);
    return 0;
}

u32 func_ov000_0219222c(GpConnection *p, u32 a, s32 b, u32 c, u32 d, u32 e) {
    Unk02194934 *x;
    Unk021919ac_node *n;
    Unk021919ac_m *m;
    Unk02190ed4Cb w;
    u32 r;
    BOOL f;
    u32 t;
    GpiConnection *o;

    o = p->mGpiConnection;
    n = NULL;
    f = FALSE;
    if (b == 1) {
        f = TRUE;
    }
    if (o->mUnk_100 == 0) {
        f = FALSE;
    }
    if (d != 0 && f != FALSE && func_ov000_02194934(p, a, &x) != 0 && x->mUnk_0c != 0) {
        m = func_ov000_021a3690(0x204);
        if (m == NULL) {
            func_ov000_02196590(p, data_ov000_021b2f58);
            return 1;
        }
        func_ov000_0219338c((Unk02192e04 *) x->mUnk_0c, (Unk0219338c *) m);
        m->mUnk_000 = 0;
        m->mUnk_004 = a;
        w.mUnk_00 = (void (*)(void *, void *, u32)) d;
        w.mUnk_04 = e;
        r = func_ov000_021938cc(p, 2, 0, (s32 *) &n, 1, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mUnk_18;
        r = func_ov000_02190ed4(p, w, m, (Unk021937c0Node *) n, 0);
        if (r != 0) {
            return r;
        }
        func_ov000_02193818(p, (Unk021937c0Node *) n);
    } else {
        r = func_ov000_021938cc(p, 2, 0, (s32 *) &n, c, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mUnk_18;
        r = func_ov000_02192330(p, a, t);
        if (r != 0) {
            return r;
        }
    }
    if (c != 0) {
        r = func_ov000_0218f2e8(p, t);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

u32 func_ov000_0219218c(GpConnection *p, Unk021919ac_node *n, Unk021919ac_f0 *a) {
    if (p->mGpiConnection->mUnk_100 == 0) {
        return 1;
    }
    func_ov000_0219210c(n);
    n->mUnk_0c = func_ov000_021a3690(0xf0);
    if (n->mUnk_0c != NULL) {
        *n->mUnk_0c = *a;
        n->mUnk_0c->mUnk_00[0] = func_ov000_0218e880(a->mUnk_00[0]);
        n->mUnk_0c->mUnk_00[1] = func_ov000_0218e880(a->mUnk_00[1]);
        n->mUnk_0c->mUnk_00[2] = func_ov000_0218e880(a->mUnk_00[2]);
        n->mUnk_0c->mUnk_00[3] = func_ov000_0218e880(a->mUnk_00[3]);
        n->mUnk_0c->mUnk_00[4] = func_ov000_0218e880(a->mUnk_00[4]);
        n->mUnk_0c->mUnk_00[5] = func_ov000_0218e880(a->mUnk_00[5]);
        n->mUnk_0c->mUnk_c8 = func_ov000_0218e880(a->mUnk_c8);
    }
    if (n->mUnk_0c != NULL) {
        return 1;
    }
    return 0;
}
