#include "00/code_0219218c.h"

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0219210c.h"
#include "00/code_02193000.h"
#include "00/code_02196590.h"
#include "00/code_02196594.h"
#include "00/code_021a3690.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_02133048.h"
#include "00/code_0218e2dc.h"
#include "00/code_02192d64.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/code_021947e4.h"
#include "00/code_021965a0.h"
#include "00/code_021919ac.h"
#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02190cd4.h"
#include "00/code_02196000.h"
#include "00/code_021a3668.h"
#include "00/code_02193b88.h"

u32 GpiUnpackDate(u32 a, s32 b, u32 *c, u32 *d, u32 *e) {
    int v1;
    u32 v2;
    u32 v3;
    v2 = b >> 0x18 & 0xff;
    v3 = b >> 0x10 & 0xff;
    b = b & ((u32) 0x0000ffffu);
    v1 = GpiIsValidDate(v2, v3, b);
    if (v1 == 0) {
        AssertionFailed(data_ov000_021b323c, data_ov000_021b31f8, NULL, 0xb7);
    }
    v1 = GpiIsValidDate(v2, v3, b);
    if (v1 == 0) {
        GpiSetErrorMessage((u32 *) (u32) (a), data_ov000_021b3254);
        return 2;
    }
    *c = v2;
    *d = v3;
    *e = b;
    return 0;
}

void func_ov000_0219338c(Unk02192e04 *a, Unk0219338c *b) {
    if (a->mUnk_00[0] != NULL) {
        GpiCopyString(b->mUnk_008, a->mUnk_00[0], 0x1f);
    } else {
        b->mUnk_008[0] = 0;
    }
    if (a->mUnk_00[1] != NULL) {
        GpiCopyString(b->mUnk_027, a->mUnk_00[1], 0x15);
    } else {
        b->mUnk_027[0] = 0;
    }
    if (a->mUnk_00[2] != NULL) {
        GpiCopyString(b->mUnk_03c, a->mUnk_00[2], 0x33);
    } else {
        b->mUnk_03c[0] = 0;
    }
    if (a->mUnk_00[3] != NULL) {
        GpiCopyString(b->mUnk_06f, a->mUnk_00[3], 0x1f);
    } else {
        b->mUnk_06f[0] = 0;
    }
    if (a->mUnk_00[4] != NULL) {
        GpiCopyString(b->mUnk_08e, a->mUnk_00[4], 0x1f);
    } else {
        b->mUnk_08e[0] = 0;
    }
    if (a->mUnk_00[5] != NULL) {
        GpiCopyString(b->mUnk_0ad, a->mUnk_00[5], 0x4c);
    } else {
        b->mUnk_0ad[0] = 0;
    }
    b->mUnk_0fc = a->mUnk_18;
    GpiCopyString(b->mUnk_100, a->mUnk_1c, 0xb);
    GpiCopyString(b->mUnk_10b, a->mUnk_27, 3);
    b->mUnk_110 = a->mUnk_2c;
    b->mUnk_114 = a->mUnk_30;
    if (a->mUnk_34 != NULL) {
        GpiCopyString(b->mUnk_118, a->mUnk_34, 0x80);
    } else {
        b->mUnk_118[0] = 0;
    }
    b->mUnk_198 = a->mUnk_b4;
    b->mUnk_19c = a->mUnk_b8;
    b->mUnk_1a0 = a->mUnk_bc;
    b->mUnk_1a4 = a->mUnk_c0;
    b->mUnk_1a8 = a->mUnk_c4;
    if (a->mUnk_c8 != NULL) {
        GpiCopyString(b->mUnk_1ac, a->mUnk_c8, 0x33);
    } else {
        b->mUnk_1ac[0] = 0;
    }
    b->mUnk_0fc = a->mUnk_18;
    b->mUnk_110 = a->mUnk_2c;
    b->mUnk_114 = a->mUnk_30;
    b->mUnk_198 = a->mUnk_b4;
    b->mUnk_19c = a->mUnk_b8;
    b->mUnk_1a0 = a->mUnk_bc;
    b->mUnk_1a4 = a->mUnk_c0;
    b->mUnk_1a8 = a->mUnk_c4;
    b->mUnk_1e0 = a->mUnk_cc[0];
    b->mUnk_1e4 = a->mUnk_cc[1];
    b->mUnk_1e8 = a->mUnk_cc[2];
    b->mUnk_1ec = a->mUnk_cc[3];
    b->mUnk_1f0 = a->mUnk_cc[4];
    b->mUnk_1f4 = a->mUnk_cc[5];
    b->mUnk_1f8 = a->mUnk_cc[6];
    b->mUnk_1fc = a->mUnk_cc[7];
    b->mUnk_200 = a->mUnk_cc[8];
}

s32 GpiProcessInfoOperation(GpConnection *r, GpiOperation *s, const char *t) {
    GpiConnection *a;
    GpiProfile *b;
    GpiCallback c;
    char d[0x40];
    char e[0x1f];
    char f[0x15];
    char g[0x33];
    char h[0x1f];
    char i[0x1f];
    char j[0x33];
    Unk0219338c *l;
    GpiPeer *q;
    s32 profileid;
    s32 o;
    s32 p;

    a = r->mGpiConnection;
    if (GpiReadError(r, t, 1) != FALSE) {
        return 4;
    }
    if (strncmp(t, data_ov000_021b31b0, 4) != 0) {
        GpiSetError(r, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(r, 3, 1);
        return 3;
    }
    if (GpiGetValue(t, data_ov000_021b2f80, d, 0x40) == FALSE) {
        GpiSetError(r, 1, data_ov000_021b31b8);
        GpiQueueErrorCallback(r, 3, 1);
        return 3;
    }
    profileid = StrtolBase10(d);
    if (profileid <= 0) {
        AssertionFailed(data_ov000_021b31e8, data_ov000_021b31f8, NULL, 0x15a);
    }
    GpiFindProfile(r, profileid, &b);
    {
        Unk02192e04 k = {0};
        char m[0x4c];
        k.mUnk_00[0] = e;
        k.mUnk_00[1] = f;
        k.mUnk_00[2] = g;
        k.mUnk_00[3] = h;
        k.mUnk_00[4] = i;
        k.mUnk_00[5] = m;
        k.mUnk_c8 = j;
        if (GpiGetValue(t, data_ov000_021b2fcc, k.mUnk_00[0], 0x1f) == FALSE) {
            k.mUnk_00[0][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fd4, k.mUnk_00[1], 0x15) == FALSE) {
            k.mUnk_00[1][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fe4, k.mUnk_00[2], 0x33) == FALSE) {
            k.mUnk_00[2][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2ff8, k.mUnk_00[3], 0x1f) == FALSE) {
            k.mUnk_00[3][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3004, k.mUnk_00[4], 0x1f) == FALSE) {
            k.mUnk_00[4][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3064, d, 0x40) == FALSE) {
            k.mUnk_18 = -1;
        } else {
            k.mUnk_18 = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3010, k.mUnk_00[5], 0x4c) == FALSE) {
            k.mUnk_00[5][0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b301c, k.mUnk_1c, 0xb) == FALSE) {
            k.mUnk_1c[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3040, k.mUnk_27, 3) == FALSE) {
            k.mUnk_27[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b3204, d, 0x40) == FALSE) {
            k.mUnk_2c = 0;
        } else {
            k.mUnk_2c = atof(d);
        }
        if (GpiGetValue(t, data_ov000_021b320c, d, 0x40) == FALSE) {
            k.mUnk_30 = 0;
        } else {
            k.mUnk_30 = atof(d);
        }
        if (GpiGetValue(t, data_ov000_021b3214, k.mUnk_34, 0x80) == FALSE) {
            k.mUnk_34[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b2fb0, d, 0x40) == FALSE) {
            k.mUnk_b4 = 0;
            k.mUnk_b8 = 0;
            k.mUnk_bc = 0;
        } else {
            o = GpiUnpackDate((u32) r, StrtolBase10(d), &k.mUnk_b4, &k.mUnk_b8, &k.mUnk_bc);
            if (o != 0) {
                return o;
            }
        }
        if (GpiGetValue(t, data_ov000_021b305c, d, 0x40) == FALSE) {
            k.mUnk_c0 = 0x502;
        } else if ((s8) d[0] == 0x30) {
            k.mUnk_c0 = 0x500;
        } else if ((s8) d[0] == 0x31) {
            k.mUnk_c0 = 0x501;
        } else {
            k.mUnk_c0 = 0x502;
        }
        if (GpiGetValue(t, data_ov000_021b321c, d, 0x40) == FALSE) {
            k.mUnk_c4 = -1;
        } else {
            k.mUnk_c4 = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30a4, k.mUnk_c8, 0x33) == FALSE) {
            k.mUnk_c8[0] = 0;
        }
        if (GpiGetValue(t, data_ov000_021b30ac, d, 0x40) == FALSE) {
            k.mUnk_cc[0] = 0;
        } else {
            k.mUnk_cc[0] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30b4, d, 0x40) == FALSE) {
            k.mUnk_cc[1] = 0;
        } else {
            k.mUnk_cc[1] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30bc, d, 0x40) == FALSE) {
            k.mUnk_cc[2] = 0;
        } else {
            k.mUnk_cc[2] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30c4, d, 0x40) == FALSE) {
            k.mUnk_cc[3] = 0;
        } else {
            k.mUnk_cc[3] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30cc, d, 0x40) == FALSE) {
            k.mUnk_cc[4] = 0;
        } else {
            k.mUnk_cc[4] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30d4, d, 0x40) == FALSE) {
            k.mUnk_cc[5] = 0;
        } else {
            k.mUnk_cc[5] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b30dc, d, 0x40) == FALSE) {
            k.mUnk_cc[6] = 0;
        } else {
            k.mUnk_cc[6] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3224, d, 0x40) == FALSE) {
            k.mUnk_cc[7] = 0;
        } else {
            k.mUnk_cc[7] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b322c, d, 0x40) == FALSE) {
            k.mUnk_cc[8] = 0;
        } else {
            k.mUnk_cc[8] = StrtolBase10(d);
        }
        if (GpiGetValue(t, data_ov000_021b3234, d, 0x40) == FALSE) {
            GpiSetError(r, 1, data_ov000_021b31b8);
            GpiQueueErrorCallback(r, 3, 1);
            return 3;
        }
        p = a->mUnk_100;
        q = a->mPeerList;
        while (q != NULL) {
            if (q->mProfileId == profileid && q->mState == 0x65) {
                if (b == NULL) {
                    b = GpiFindOrAddProfile(r, profileid);
                }
                q->mState = 0x66;
                p = 1;
            }
            q = q->mNext;
        }
        if (b == NULL && a->mUnk_100 != 0) {
            b = GpiFindOrAddProfile(r, profileid);
        }
        if (p != 0) {
            func_ov000_021a3668(b->mUnk_18);
            b->mUnk_18 = NULL;
            b->mUnk_18 = func_ov000_0218e880(d);
        }
        if (a->mUnk_100 != 0) {
            func_ov000_0219218c(r, (Unk021919ac_node *) b, (Unk021919ac_f0 *) &k);
        }
        c = s->mUnk_0c;
        if (c.mCallback != NULL) {
            l = func_ov000_021a3690(0x204);
            if (l == NULL) {
                GpiSetErrorMessage(r, data_ov000_021b2f58);
                return 1;
            }
            func_ov000_0219338c(&k, l);
            l->mUnk_000 = 0;
            l->mUnk_004 = profileid;
            o = GpiQueueCallback(r, c, l, s, 0);
            if (o != 0) {
                return o;
            }
        }
        GpiRemoveOperation(r, s);
        return 0;
    }
}

u32 GpiWriteUpdateBuffers(GpConnection *a, GpiBuffer *b) {
    GpiConnection *v1;
    v1 = a->mGpiConnection;
    if (0 < v1->mUpdateproBufferLength) {
        GpiAppendBufferString(a, b, data_ov000_021b3184);
        GpiAppendBufferNumber(a, b, v1->mSesskey);
        GpiAppendBufferString(a, b, v1->mUpdateproBuffer);
        GpiAppendBufferString(a, b, data_ov000_021b2f94);
        v1->mUpdateproBufferLength = 0;
    }
    if (0 < v1->mUpdateuiBufferLength) {
        GpiAppendBufferString(a, b, data_ov000_021b319c);
        GpiAppendBufferNumber(a, b, v1->mSesskey);
        GpiAppendBufferString(a, b, v1->mUpdateuiBuffer);
        GpiAppendBufferString(a, b, data_ov000_021b2f94);
        v1->mUpdateuiBufferLength = 0;
    }
    return 0;
}

u32 func_ov000_02192d30(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = GpiAppendBufferString(p, &o->mUpdateproBuffer, a);
    if (r != 0) {
        return r;
    }
    r = GpiAppendBufferString(p, &o->mUpdateproBuffer, b);
    if (r != 0) {
        return r;
    }
    return 0;
}

u32 func_ov000_02192cfc(GpConnection *p, const char *a, const char *b) {
    GpiConnection *o;
    u32 r;

    o = p->mGpiConnection;
    r = GpiAppendBufferString(p, &o->mUpdateuiBuffer, a);
    if (r != 0) {
        return r;
    }
    r = GpiAppendBufferString(p, &o->mUpdateuiBuffer, b);
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
                GpiSetErrorMessage(p, data_ov000_021b30e4);
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
                    GpiSetErrorMessage(p, data_ov000_021b30f8);
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
            GpiSetErrorMessage(p, data_ov000_021b2fa0);
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
        GpiSetErrorMessage(p, data_ov000_021b2fbc);
        return 2;
    }
    switch (a) {
        case 0x700:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x1f);
            GpiCopyString(o->mNick, c, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2fcc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x701:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x15);
            GpiCopyString((char *) o->mUniquenick, c, 0x15);
            r = func_ov000_02192d30(p, data_ov000_021b2fd4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x702:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x33);
            func_ov000_0218e850((s8 *) c);
            GpiCopyString(o->mEmail, c, 0x33);
            r = func_ov000_02192cfc(p, data_ov000_021b2fe4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x703:
            if (*b == 0) {
                GpiSetErrorMessage(p, data_ov000_021b2fbc);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 0x1f);
            GpiCopyString((char *) o->mPassword, c, 0x1f);
            r = func_ov000_02192cfc(p, data_ov000_021b2fec, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x704:
            GpiCopyString(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b2ff8, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x705:
            GpiCopyString(c, (const char *) b, 0x1f);
            r = func_ov000_02192d30(p, data_ov000_021b3004, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x707:
            GpiCopyString(c, (const char *) b, 0x4c);
            r = func_ov000_02192d30(p, data_ov000_021b3010, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x708:
            GpiCopyString(c, (const char *) b, 0xb);
            r = func_ov000_02192d30(p, data_ov000_021b301c, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x709:
            if (strlen((const char *) b) != 2) {
                GpiSetErrorMessage(p, data_ov000_021b3028);
                return 2;
            }
            GpiCopyString(c, (const char *) b, 3);
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
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3064, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x70d:
            r = func_ov000_0219296c(p, 0x70d, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70e:
            r = func_ov000_0219296c(p, 0x70e, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x70f:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3070, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x710:
            r = func_ov000_0219296c(p, 0x710, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x711:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3084, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x712:
            r = func_ov000_0219296c(p, 0x712, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x714:
            r = func_ov000_0219296c(p, 0x714, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x715:
            r = func_ov000_0219296c(p, 0x715, StrtolBase10((const char *) b));
            if (r != 0) {
                return r;
            }
            break;
        case 0x716:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b3098, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x717:
            GpiCopyString(c, (const char *) b, 0x33);
            r = func_ov000_02192d30(p, data_ov000_021b30a4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x718:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30ac, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x719:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30b4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71a:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30bc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71b:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30c4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71c:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30cc, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71d:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30d4, c);
            if (r != 0) {
                return r;
            }
            break;
        case 0x71e:
            GpiCopyString(c, (const char *) b, 0x100);
            r = func_ov000_02192d30(p, data_ov000_021b30dc, c);
            if (r != 0) {
                return r;
            }
            break;
        default:
            GpiSetErrorMessage(p, data_ov000_021b2fa0);
            return 2;
    }
    return 0;
}

u32 func_ov000_02192330(GpConnection *p, u32 a, u32 b) {
    GpiConnection *o;

    o = p->mGpiConnection;
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f68);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, o->mSesskey);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f80);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, a);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f8c);
    GpiAppendBufferNumber(p, &o->mOutputBuffer, b);
    GpiAppendBufferString(p, &o->mOutputBuffer, data_ov000_021b2f94);
    return 0;
}

u32 func_ov000_0219222c(GpConnection *p, u32 a, s32 b, u32 c, u32 d, u32 e) {
    GpiProfile *x;
    Unk021919ac_node *n;
    Unk021919ac_m *m;
    GpiCallback w;
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
    if (d != 0 && f != FALSE && GpiFindProfile(p, a, &x) != 0 && x->mUnk_0c != 0) {
        m = func_ov000_021a3690(0x204);
        if (m == NULL) {
            GpiSetErrorMessage(p, data_ov000_021b2f58);
            return 1;
        }
        func_ov000_0219338c((Unk02192e04 *) x->mUnk_0c, (Unk0219338c *) m);
        m->mUnk_000 = 0;
        m->mUnk_004 = a;
        w.mCallback = (void (*)(void *, void *, u32)) d;
        w.mUnk_04 = e;
        r = GpiCreateOperation(p, 2, 0, (s32 *) &n, 1, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mId;
        r = GpiQueueCallback(p, w, m, (GpiOperation *) n, 0);
        if (r != 0) {
            return r;
        }
        GpiRemoveOperation(p, (GpiOperation *) n);
    } else {
        r = GpiCreateOperation(p, 2, 0, (s32 *) &n, c, d, e);
        if (r != 0) {
            return r;
        }
        t = n->mId;
        r = func_ov000_02192330(p, a, t);
        if (r != 0) {
            return r;
        }
    }
    if (c != 0) {
        r = GpiUpdateConnection(p, t);
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
