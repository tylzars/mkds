#include "00/code_02193818.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_0218e49c.h"
#include "00/code_02193e70.h"
#include "00/code_02194000.h"
#include "00/code_021965a0.h"
#include "00/code_02196590.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_02134d30.h"
#include "code_02135014.h"

void func_ov000_02193818(GpConnection *param_1, Unk021937c0Node *param_2) {
    GpiConnection *a = param_1->mGpiConnection;
    Unk021937c0Node *b = a->mOperationList;
    Unk021937c0Node *c = NULL;

    while (b != NULL) {
        if (b == param_2) {
            if (c == NULL) {
                a->mOperationList = b->mNext;
            } else {
                c->mNext = param_2->mNext;
            }
            func_ov000_02193858(param_1, param_2);
            return;
        }
        c = b;
        b = b->mNext;
    }
}

void func_ov000_02193858(GpConnection *param_1, Unk021937c0Node *param_2) {
    GpiConnection *a = param_1->mGpiConnection;
    Unk02193858 *b;

    if (param_2->mUnk_00 == 3) {
        b = (Unk02193858 *) param_2->mUnk_04;
        a->mSearchCount--;
        if (a->mSearchCount < 0) {
            func_0213442c(data_ov000_021b32c0, data_ov000_021b32b0, NULL, 0xb6);
        }
        func_ov000_0218e524(b->mUnk_04, 2);
        func_ov000_0218e53c(b->mUnk_04);
        func_ov000_021a3668(b->mUnk_18);
        b->mUnk_18 = NULL;
        func_ov000_021a3668(b->mUnk_08);
        b->mUnk_08 = NULL;
    }
    func_ov000_021a3668(param_2->mUnk_04);
    param_2->mUnk_04 = NULL;
    func_ov000_021a3668(param_2);
}

u32 func_ov000_021938cc(GpConnection *param_1, int param_2, int param_3, int *param_4, int param_5, int param_6,
                        int param_7) {
    GpiConnection *a = param_1->mGpiConnection;
    Unk021937c0Node *b = func_ov000_021a3690(0x24);

    if (b == NULL) {
        func_ov000_02196590(param_1, data_ov000_021b32e0);
        return 1;
    }
    b->mUnk_00 = param_2;
    b->mUnk_04 = (void *) param_3;
    b->mUnk_08 = param_5;
    b->mUnk_14 = 0;
    if (param_2 == 0) {
        b->mUnk_18 = 1;
    } else {
        b->mUnk_18 = a->mNextOperationId++;
        if (a->mNextOperationId < 2) {
            a->mNextOperationId = 2;
        }
    }
    b->mUnk_1c = 0;
    b->mUnk_0c.mUnk_00 = (void (*)(void *, void *, u32)) param_6;
    b->mUnk_0c.mUnk_04 = param_7;
    b->mNext = a->mOperationList;
    a->mOperationList = b;
    *param_4 = (s32) b;
    return 0;
}

s32 func_ov000_02193954(GpConnection *param_1, Unk021937c0Node *param_2) {
    GpiConnection *a = param_1->mGpiConnection;
    Unk02190ed4Cb b;
    Unk02193954_0 *c;
    Unk02193954_1 *d;
    Unk02193954_3 *e;
    Unk02193954_4 *f;
    s32 g;

    if (param_1 == NULL) {
        func_0213442c(data_ov000_021b32f0, data_ov000_021b32b0, NULL, 0x22);
    }
    if (param_1->mGpiConnection == NULL) {
        func_0213442c(data_ov000_021b3304, data_ov000_021b32b0, NULL, 0x23);
    }
    if (param_2 == NULL) {
        func_0213442c(data_ov000_021b3318, data_ov000_021b32b0, NULL, 0x24);
    }
    b = param_2->mUnk_0c;
    if (b.mUnk_00 != NULL) {
        switch (param_2->mUnk_00) {
            case 0:
                c = func_ov000_021a3690(0x20);
                if (c == NULL) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                memset(c, 0, 0x20);
                c->mUnk_00 = param_2->mUnk_1c;
                if (a->mErrorNumber == 0x201) {
                    c->mUnk_04 = a->mProfileId;
                    a->mProfileId = 0;
                }
                g = func_ov000_02190ed4(param_1, b, c, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 1:
                d = func_ov000_021a3690(8);
                if (d == NULL) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                memset(d, 0, 8);
                d->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, d, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 2:
                c = func_ov000_021a3690(0x204);
                if (c == NULL) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                memset(c, 0, 0x204);
                c->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, c, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 3:
                e = func_ov000_021a3690(0x10);
                if (e == NULL) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                memset(e, 0, 0x10);
                e->mUnk_00 = param_2->mUnk_1c;
                e->mUnk_0c = 0;
                g = func_ov000_02190ed4(param_1, b, e, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            case 4:
                f = func_ov000_021a3690(4);
                if (f == NULL) {
                    func_ov000_02196590(param_1, data_ov000_021b32e0);
                    return 1;
                }
                memset(f, 0, 4);
                f->mUnk_00 = param_2->mUnk_1c;
                g = func_ov000_02190ed4(param_1, b, f, param_2, 0);
                if (g != 0) {
                    return g;
                }
                break;
            default:
                func_0213442c(data_ov000_021b32ac, data_ov000_021b32b0, NULL, 0x6b);
                break;
        }
    }
    return 0;
}

s32 func_ov000_02193b88(GpConnection *param_1, Unk02193f2cNode *param_2, const char *param_3, s32 param_4) {
    char a[0x24];
    s32 b;

    if (param_2 == NULL) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x389);
    }
    if (param_3 == NULL) {
        param_3 = data_ov000_021b3348;
    }
    if (param_4 == -1) {
        param_4 = strlen(param_3);
    }
    sprintf(a, data_ov000_021b334c, param_4);
    b = func_ov000_02190968(param_1, (Unk02190988 *) param_2, a);
    if (b != 0) {
        return b;
    }
    b = func_ov000_02190988(param_1, (Unk02190988 *) param_2, param_3, param_4);
    if (b != 0) {
        return b;
    }
    b = func_ov000_02190a24(param_1, (Unk02190988 *) param_2, 0);
    if (b != 0) {
        return b;
    }
    param_2->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
    return 0;
}

u32 func_ov000_02193c20(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, Unk02193c20 *param_4) {
    char a[0x44];
    u32 b = param_4->mUnk_04;
    u32 c = param_4->mUnk_00;
    u32 d = param_4->mUnk_08;

    if (param_4 == NULL) {
        func_0213442c(data_ov000_021b335c, data_ov000_021b333c, NULL, 0x376);
    }
    sprintf(a, data_ov000_021b3368, param_3, c, b, d);
    return func_ov000_02190968(param_1, (Unk02190988 *) param_2, a);
}

s32 func_ov000_02193c74(GpConnection *param_1, Unk02193f2cNode *param_2, u32 param_3, const char *param_4) {
    u32 b;
    s32 c;

    if (param_2 == NULL) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, NULL, 0x340);
    }
    if (param_4 == NULL) {
        func_0213442c(data_ov000_021b337c, data_ov000_021b333c, NULL, 0x341);
    }
    b = strlen(param_4);
    {
        Unk02193c74 a = {0};
        a.mUnk_10 = param_3;
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b338c);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b58(param_1, &a, param_3);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b3390);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b58(param_1, &a, b);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190b80(param_1, &a, data_ov000_021b3398);
        if (c != 0) {
            return c;
        }
        a.mUnk_14 = a.mUnk_08;
        c = func_ov000_02190ba0(param_1, (Unk021906e4 *) &a, param_4, b);
        if (c != 0) {
            return c;
        }
        c = func_ov000_02190c64(param_1, (Unk021906e4 *) &a, 0);
        if (c != 0) {
            return c;
        }
        func_ov000_0218dbc0(param_2->mUnk_38, &a);
        param_2->mUnk_10 = func_ov000_0218e320(NULL) + 0x12c;
        return 0;
    }
}

s32 func_ov000_02193d64(GpConnection *param_1, Unk02193f2cNode *param_2) {
    Unk02193d64 b;
    Unk02194934 *a;
    s32 c;
    u32 *p;

    if (func_ov000_02194934(param_1, param_2->mUnk_0c, &a) == 0) {
        func_ov000_02196590(param_1, data_ov000_021b33a0);
        return 3;
    }
    param_2->mUnk_08 = func_ov000_0218e554(2, 1, 0);
    if (param_2->mUnk_08 == -1) {
        func_ov000_021965a0(param_1, 5, data_ov000_021b33bc);
        func_ov000_02190f4c(param_1, 3, 0);
        return 3;
    }
    if (func_ov000_0218e80c(param_2->mUnk_08, 0) == 0) {
        func_ov000_021965a0(param_1, 5, data_ov000_021b33e4);
        func_ov000_02190f4c(param_1, 3, 0);
        return 3;
    }
    func_ov000_02193ff4(param_2->mUnk_08);
    p = (u32 *) &b;
    p[0] = 0;
    p[1] = 0;
    b.mUnk_01 = 2;
    b.mUnk_04 = a->mUnk_08->mUnk_10;
    b.mUnk_02 = a->mUnk_08->mUnk_14;
    c = func_ov000_0218e4b4(param_2->mUnk_08, &b, 8);
    if (c == -1) {
        c = func_ov000_0218e368(param_2->mUnk_08);
        if (c != -6 && c != -0x1a && c != -0x4c) {
            func_ov000_021965a0(param_1, 5, data_ov000_021b3418);
            func_ov000_02190f4c(param_1, 3, 1);
            return 3;
        }
    }
    param_2->mUnk_00 = 0x67;
    return 0;
}
