#include "00/code_0219d128.h"

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219cb00.h"
#include "00/code_0219d000.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c93c.h"
#include "00/code_0219cc00.h"
#include "00/code_0218f15c.h"
#include "code_02139f70.h"
#include "00/code_0219d934.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"
#include "code_0214d018.h"
#include "00/code_0219c954.h"
#include "00/code_0219cfc0.h"
#include "00/code_02197000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "code_021522a0.h"
#include "code_02152934.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_0219caac.h"
#include "00/code_0219742c.h"

void func_ov000_0219d934(void *first, void *second) {
    if (data_ov000_021b5664 != NULL) {
        data_ov000_021b5664->mUnk_44 = first;
        data_ov000_021b5664->mUnk_48 = second;
    }
}

void func_ov000_0219d8c8(Unk021b5664 *a, struct GpConnection *b, char *c, Unk02152490 *d, s32 e) {
    Unk021b5664 *q;
    data_ov000_021b5664 = a;
    a->mUnk_00 = 0;
    data_ov000_021b5664->mUnk_04 = b;
    data_ov000_021b5664->mUnk_08 = 0;
    q = data_ov000_021b5664;
    q->mUnk_0c = 0;
    q->mUnk_14 = e;
    data_ov000_021b5664->mUnk_18 = d;
    data_ov000_021b5664->mUnk_1c = 0;
    data_ov000_021b5664->mUnk_1d = 0;
    data_ov000_021b5664->mUnk_1e = 0;
    data_ov000_021b5664->mUnk_1f = 0;
    data_ov000_021b5664->mUnk_20 = 0;
    data_ov000_021b5664->mUnk_24 = 0;
    data_ov000_021b5664->mUnk_28 = c;
    data_ov000_021b5664->mUnk_2c = NULL;
    data_ov000_021b5664->mUnk_30 = NULL;
    data_ov000_021b5664->mUnk_34 = NULL;
    data_ov000_021b5664->mUnk_38 = NULL;
    data_ov000_021b5664->mUnk_3c = NULL;
    data_ov000_021b5664->mUnk_40 = NULL;
    data_ov000_021b5664->mUnk_44 = NULL;
    data_ov000_021b5664->mUnk_48 = NULL;
    data_ov000_021b5664->mUnk_4c = NULL;
    data_ov000_021b5664->mUnk_50 = 0;
}

void func_ov000_0219d81c(void) {
    if (data_ov000_021b5664 == NULL) {
        return;
    }
    if (data_ov000_021b5664->mUnk_18 == NULL) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (func_ov000_0219caf4() != 0 && func_ov000_0219746c() == FALSE) {
        func_ov000_0219d734(6, -0x1194a);
        return;
    }
    if (data_ov000_021b5664->mUnk_04 != NULL && data_ov000_021b5664->mUnk_04->mGpiConnection != NULL) {
        if (func_ov000_0219d034(func_ov000_0219d49c()) != 0) {
            return;
        }
        if (data_ov000_021b5664->mUnk_18 != NULL && data_ov000_021b5664->mUnk_1e != 3 &&
            data_ov000_021b5664->mUnk_08 > 7) {
            if (data_ov000_021b5664->mUnk_1e <= 1) {
                func_ov000_0219d2e8(data_ov000_021b5664->mUnk_18, data_ov000_021b5664->mUnk_14);
            }
            if (data_ov000_021b5664->mUnk_1c >= data_ov000_021b5664->mUnk_14) {
                data_ov000_021b5664->mUnk_1e = 3;
                data_ov000_021b5664->mUnk_1f++;
            }
        }
    }
    if (data_ov000_021b5664->mUnk_1f >= 2) {
        data_ov000_021b5664->mUnk_1f = 0;
        func_ov000_0219d2c4();
    }
}

void func_ov000_0219d770(s32 a, const char *b, void (*c)(s32, u8, void *), void *d, void (*e)(s32, u8, void *, void *),
                         void *f, void (*g)(s32, s32, void *), void *h) {
    s32 i;
    s32 j;
    s32 k;
    s8 l[0x28];
    data_ov000_021b5664->mUnk_2c = c;
    data_ov000_021b5664->mUnk_30 = d;
    data_ov000_021b5664->mUnk_34 = e;
    data_ov000_021b5664->mUnk_38 = f;
    data_ov000_021b5664->mUnk_3c = g;
    data_ov000_021b5664->mUnk_40 = h;
    i = 0;
    data_ov000_021b5664->mUnk_1d = 0;
    data_ov000_021b5664->mUnk_1e = 0;
    data_ov000_021b5664->mUnk_1f = 0;
    data_ov000_021b5664->mUnk_00 = 1;
    if (((s8 *) data_ov000_021b5664->mUnk_28)[i] != 0) {
        j = i;
        for (; i < 5; i++) {
            k = GstatsConnect(j);
            if (k == 0) {
                break;
            }
            if (k != 2 || i == 4) {
                func_ov000_0219cfc0(k);
                return;
            }
        }
        func_ov000_02197a9c((const char *) func_ov000_021975f4(NULL), b, l);
        func_ov000_02197594(0, a, (s32) l, func_ov000_0219cc30, 0);
        func_ov000_0219cb30();
    } else {
        data_ov000_021b5664->mUnk_1f++;
    }
}

void func_ov000_0219d734(s32 a, s32 b) {
    if (data_ov000_021b5664 != NULL && a != 0) {
        func_ov000_0219c384(a, b);
        if (data_ov000_021b5664->mUnk_00 != 0 && data_ov000_021b5664->mUnk_00 != 2) {
            data_ov000_021b5664->mUnk_2c(a, data_ov000_021b5664->mUnk_1d, data_ov000_021b5664->mUnk_30);
        }
        func_ov000_0219d478();
    }
}

void func_ov000_0219d708(u32 a, u32 *b) {
    if (data_ov000_021b5664->mUnk_18 != NULL) {
        func_ov000_0218eff8((GpConnection *) (a), *b, 0, 0, (Unk0218eff8Cb) func_ov000_0219cd74, 0);
    }
    return;
}

u32 func_ov000_0219d6c4(u32 a, u32 *b, u32 c) {
    int v1;
    v1 = strcmp((const char *) (b[2]), data_ov000_021b4078);
    if (v1 == 0) {
        func_ov000_0218eff8((GpConnection *) (a), *b, 0, 0, (Unk0218eff8Cb) func_ov000_0219cc94, 0);
        return 1;
    }
    return 0;
}

void func_ov000_0219d674(struct GpConnection *a, s32 *b) {
    Unk0218ec44 c;
    u32 d;
    Unk021b5664 *e;
    if (data_ov000_021b5664->mUnk_34 != NULL) {
        d = func_ov000_0219d5e4(b[0]);
        if (d != -1) {
            GpGetBuddyStatus(a, b[2], &c);
            e = data_ov000_021b5664;
            e->mUnk_34(d, c.mUnk_004, c.mUnk_108, e->mUnk_38);
        }
    }
}

s32 func_ov000_0219d660(void) {
    if (data_ov000_021b5664 != NULL) {
        return data_ov000_021b5664->mUnk_14;
    }
    return 0;
}

int func_ov000_0219d630(int a) {
    Unk02152500 *v1;
    u32 v2;
    v1 = func_ov000_0219c9c4();
    v2 = func_02152520((void *) (v1), &data_ov000_021b5664->mUnk_18[a]);
    if ((v2 == 0) || (v2 == -1)) {
        v2 = 0;
    }
    return v2;
}

u32 func_ov000_0219d5e4(u32 a) {
    s32 i;
    if (data_ov000_021b5664 == NULL || a == 0) {
        return -1;
    }
    for (i = 0; i < data_ov000_021b5664->mUnk_14; i++) {
        if (a == func_ov000_0219d630(i)) {
            return i;
        }
    }
    return -1;
}

void func_ov000_0219d5bc(void) {
    if (data_ov000_021b5664 != NULL) {
        data_ov000_021b5664->mUnk_08 = 0;
        data_ov000_021b5664->mUnk_0c = func_0200f5ac();
    }
}

u32 func_ov000_0219d558(s32 a, void *b, void *c) {
    if (data_ov000_021b5664 == NULL || data_ov000_021b5664->mUnk_04 == NULL) {
        return 0;
    }
    if (a == -1) {
        a = data_ov000_021b5664->mUnk_04->mGpiConnection->mStatus;
    }
    if (b == NULL) {
        b = data_ov000_021b5664->mUnk_04->mGpiConnection->mStatusString;
    }
    if (c == NULL) {
        c = data_ov000_021b5664->mUnk_04->mGpiConnection->mLocationString;
    }
    return GpSetStatus(data_ov000_021b5664->mUnk_04, a, b, c);
}

void func_ov000_0219d504(s32 a) {
    Unk0218ec44 b;
    if (data_ov000_021b5664->mUnk_44 != NULL && data_ov000_021b5664->mUnk_00 != 1) {
        ((void (*)(s32, void *)) data_ov000_021b5664->mUnk_44)(a, data_ov000_021b5664->mUnk_48);
    }
    if (data_ov000_021b5664->mUnk_34 != NULL) {
        Unk021b5664 *c;
        u8 d = func_ov000_0219daa8(&data_ov000_021b5664->mUnk_18[a], (char *) b.mUnk_108);
        c = data_ov000_021b5664;
        c->mUnk_34(a, d, b.mUnk_108, c->mUnk_38);
    }
}

void func_ov000_0219d4f8(void) {
    *(u32 *) &data_ov000_021b5664 = 0;
    return;
}

int func_ov000_0219d49c(void) {
    Unk021b5664 *a = data_ov000_021b5664;
    if ((func_0200f5ac() - a->mUnk_0c) * 64 / 0x82ea >= 300) {
        a->mUnk_08 = a->mUnk_08 + 1;
        GpUpdate(data_ov000_021b5664->mUnk_04);
        data_ov000_021b5664->mUnk_0c = func_0200f5ac();
    }
    return 0;
}

void func_ov000_0219d478(void) {
    if (data_ov000_021b5664 != NULL) {
        GstatsClose();
        data_ov000_021b5664->mUnk_00 = 0;
    }
}

void func_ov000_0219d2e8(Unk02152490 *a, s32 b) {
    s32 c;
    s32 d;
    s32 i;
    char e[0x18];
    Unk0218ec44 f;
    s32 g;
    if (data_ov000_021b5664->mUnk_1e == 0) {
        func_ov000_0219d034(GpGetBuddyCount(data_ov000_021b5664->mUnk_04, &c));
        for (d = 0; d < c; d++) {
            func_ov000_0219d034(GpGetBuddyStatus(data_ov000_021b5664->mUnk_04, d, &f));
            for (i = 0; i < b; i++) {
                if (f.mUnk_000 == func_ov000_0219d630(i)) {
                    if (func_02152a24((Unk02152490 *) a + i) == 0) {
                        func_02152468(&a[i], f.mUnk_000);
                        func_021529bc(&a[i]);
                        data_ov000_021b5664->mUnk_1d = 1;
                    }
                    break;
                }
            }
            if (i == b) {
                func_ov000_0219d034(func_ov000_0218eb44(data_ov000_021b5664->mUnk_04, f.mUnk_000));
                c--;
                d--;
            }
        }
        data_ov000_021b5664->mUnk_1e = 1;
    }
    for (; data_ov000_021b5664->mUnk_1c < b; data_ov000_021b5664->mUnk_1c++) {
        g = func_ov000_0219d630(data_ov000_021b5664->mUnk_1c);
        if (g != 0) {
            if (func_ov000_0219d210(a, data_ov000_021b5664->mUnk_1c, g) == FALSE &&
                func_02152a24(&a[data_ov000_021b5664->mUnk_1c]) == 0) {
                func_ov000_0219d034(GpGetBuddyIndex(data_ov000_021b5664->mUnk_04, g, &d));
                if (d == -1) {
                    func_ov000_0219d128(g);
                }
            }
        } else if (func_02152520((void *) func_ov000_0219c9c4(), &a[data_ov000_021b5664->mUnk_1c]) == -1) {
            func_02152458(func_ov000_0219c9c4(), &a[data_ov000_021b5664->mUnk_1c], e);
            func_ov000_0218f0a8(data_ov000_021b5664->mUnk_04, NULL, NULL, NULL, NULL, (s8 *) e, 0, 0,
                                (Unk0218f0a8Cb) func_ov000_0219ce48, data_ov000_021b5664->mUnk_1c);
            data_ov000_021b5664->mUnk_1e = 2;
            return;
        }
    }
}

void func_ov000_0219d2c4(void) {
    data_ov000_021b5664->mUnk_2c(0, data_ov000_021b5664->mUnk_1d, data_ov000_021b5664->mUnk_30);
    data_ov000_021b5664->mUnk_00 = 2;
}

void func_ov000_0219d288(Unk02152490 *a, s32 b, s32 c) {
    if (data_ov000_021b5664 != NULL) {
        MemFill(&a[b], 0, 12);
        if (data_ov000_021b5664->mUnk_3c != NULL) {
            data_ov000_021b5664->mUnk_3c(b, c, data_ov000_021b5664->mUnk_40);
        }
    }
}

BOOL func_ov000_0219d210(Unk02152490 *a, s32 b, s32 c) {
    s32 i;
    s32 j;
    for (i = 0; i < b; i++) {
        j = func_ov000_0219d630(i);
        if (j != 0 && j == c) {
            if (func_02152a24(&a[b]) != 0 && func_02152a24(&a[i]) == 0) {
                func_ov000_0219d288(a, i, b);
            } else {
                func_ov000_0219d288(a, b, i);
            }
            data_ov000_021b5664->mUnk_1d = 1;
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_ov000_0219d14c(Unk02152490 *a, s32 b, s32 c) {
    s32 l;
    s32 i;
    s32 j;
    s32 k;
    Unk02152490 *p;
    Unk02152490 *q;
    Unk02152490 *r;
    i = 0;
    l = -1;
    if (b - 1 > 0) {
        p = a;
        q = a;
        do {
            k = func_ov000_0219d630(i);
            if (k != 0) {
                if (k == c) {
                    l = i;
                }
                j = i + 1;
                if (j < b) {
                    r = &a[j];
                    do {
                        if (k == func_ov000_0219d630(j)) {
                            if (func_02152a1c(p) == 2 && func_02152a1c(r) == 3) {
                                func_02152468(q, k);
                            }
                            if (func_02152a24(r) != 0) {
                                func_021529bc(q);
                            }
                            func_ov000_0219d288(a, j, i);
                            data_ov000_021b5664->mUnk_1d = 1;
                        }
                        r++;
                        j++;
                    } while (j < b);
                }
            }
            p++;
            q++;
            i++;
        } while (i < b - 1);
    }
    return l;
}

u32 func_ov000_0219d128(u32 a) {
    u32 v1;
    v1 = GpWriteAddbuddy(data_ov000_021b5664->mUnk_04, (u32) (a), data_ov000_021b5664->mUnk_28);
    func_ov000_0219d034(v1);
    return v1;
}
