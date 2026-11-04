#include "00/code_0218cd74.h"

#include "code_02134d30.h"
#include "00/code_0218b280.h"
#include "00/code_0218b3ac.h"
#include "00/code_0218d000.h"
#include "00/code_0218dd8c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218d818.h"
#include "00/code_0218b708.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "code_02135014.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021919ac.h"
#include "00/code_021a3a18.h"
#include "code_021384cc.h"
#include "code_0214177c.h"
#include "00/code_0218c958.h"
#include "00/code_0218b220.h"
#include "code_021382a8.h"
#include "00/code_0218b000.h"
#include "00/code_0218d488.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"

s32 func_ov000_0218d430(u32 *c, u32 *d) {
    char *a;
    char *b;
    s32 result;
    a = SbServerGetValue((SbServer *) *c, (const char *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    b = SbServerGetValue((SbServer *) *d, (const char *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    result = strcmp(a, b);
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        result = -result;
    }
    return result;
}

s32 func_ov000_0218d3d8(u32 *a, u32 *b) {
    char *x;
    char *y;
    s32 r;
    x = SbServerGetValue((SbServer *) *a, (const char *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    y = SbServerGetValue((SbServer *) *b, (const char *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    r = func_02142368(x, y);
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        r = -r;
    }
    return r;
}

void func_ov000_0218d374(SbServerList *p, s32 a, u32 b, u32 c) {
    s32 (*f)(u32 *, u32 *);
    switch (c) {
        case 0:
            f = func_ov000_0218d528;
            break;
        case 1:
            f = func_ov000_0218d488;
            break;
        case 2:
            f = func_ov000_0218d430;
            break;
        case 3:
            f = func_ov000_0218d3d8;
            break;
        default:
            f = func_ov000_0218d3d8;
            break;
    }
    p->mUnk_498 = b;
    p->mUnk_49c = a;
    data_ov000_021b4d24 = p;
    DarraySort((u32) p->mUnk_004, (u32) f);
}

void func_ov000_0218d340(SbServerList *p, u32 a) {
    DarrayAppend(p->mUnk_004, &a);
    p->mCallback(p, 0, a, p->mUnk_494);
}

int func_ov000_0218d300(SbServerList *a, int b) {
    int v1;
    int *v2;
    int v3;
    v1 = DarrayGetCount(a->mUnk_004);
    v3 = 0;
    if (0 < v1) {
        do {
            v2 = DarrayGetElement(a->mUnk_004, v3);
            if (b == *v2) {
                return v3;
            }
            v3 = v3 + 1;
        } while (v3 < v1);
    }
    return -1;
}

int func_ov000_0218d2a8(SbServerList *a, int b, int c) {
    u32 v1;
    int v2;
    int v3;
    u32 *v4;
    int v5;
    v5 = DarrayGetCount(a->mUnk_004);
    v2 = 0;
    if (0 < v5) {
        do {
            v4 = DarrayGetElement(a->mUnk_004, v2);
            v1 = *v4;
            v3 = func_ov000_0218b27c((u32 *) ((u32 *) (u32) (v1)));
            if ((b == v3) && (v3 = func_ov000_0218b25c(v1), c == v3)) {
                return v2;
            }
            v2 = v2 + 1;
        } while (v2 < v5);
    }
    return -1;
}

void func_ov000_0218d278(SbServerList *p, u32 v1) {
    if (p->mUnk_5d0 == 0) {
        func_ov000_0218b224(v1, 0);
    } else {
        func_ov000_0218b224(v1, p->mUnk_5d0);
    }
    p->mUnk_5d0 = v1;
}

void func_ov000_0218d238(SbServerList *p, s32 a) {
    u32 v = *(u32 *) DarrayGetElement(p->mUnk_004, a);
    p->mCallback(p, 2, v, p->mUnk_494);
    DarrayRemove(p->mUnk_004, a);
    func_ov000_0218d278(p, v);
}

u32 func_ov000_0218d22c(SbServerList *a) {
    u32 value0;
    u32 value3;
    value3 = (u32) &DarrayGetCount;
    value0 = DarrayGetCount(a->mUnk_004);
    return value0;
}

u32 func_ov000_0218d218(SbServerList *a, u32 b) {
    u32 *v;
    v = DarrayGetElement(a->mUnk_004, b);
    return *v;
}

void func_ov000_0218d1dc(SbServerList *p) {
    int v1;
    int v2;
    if (p->mUnk_5d0 != 0) {
        v1 = p->mUnk_5d0;
        while (v1 != 0) {
            v2 = func_ov000_0218b220(v1);
            func_ov000_0218b3ac(&v1);
            v1 = v2;
        }
        p->mUnk_5d0 = 0;
    }
}

void func_ov000_0218d1a0(SbServerList *a) {
    int v1;
    u32 *v2;
    int v3;
    v1 = DarrayGetCount(a->mUnk_004);
    v3 = 0;
    if (0 < v1) {
        do {
            v2 = DarrayGetElement(a->mUnk_004, v3);
            func_ov000_0218d278(a, *v2);
            v3 = v3 + 1;
        } while (v3 < v1);
    }
    DarrayRemoveAll(a->mUnk_004);
    func_ov000_0218d1dc(a);
}

void func_ov000_0218d180(u32 p0) {
    u32 v1 = ((p0) + (0x0u));
    u32 v5 = (u32) DarrayCreate((u32) 0x4u, (u32) 0x64u, (u32) 0x0u);
    u32 v8;
    *(u32 *) ((v1) + (4)) = v5;
    v8 = 0x5d0u;
    *(u32 *) ((v1) + (0 + (v8))) = (u32) 0x0u;
}

void *func_ov000_0218d134(SbServerList *p, const char *v1) {
    s32 k[2];
    s32 *e;
    k[0] = (s32) v1;
    e = HashtableFind(func_ov000_0218b3f4(p), k);
    if (e != NULL) {
        e[1] = e[1] + 1;
        return (void *) e[0];
    }
    k[0] = (s32) func_ov000_0218e880(v1);
    k[1] = 1;
    HashtableSet(func_ov000_0218b3f4(p), k);
    return (void *) k[0];
}

void func_ov000_0218d0e4(SbServerList *p, u32 v1) {
    s32 k[2];
    s32 *e;
    k[0] = v1;
    e = HashtableFind(func_ov000_0218b3f4(p), k);
    if (e == NULL) {
        func_0213442c(data_ov000_021b22a4, data_ov000_021b2218, NULL, 0xf4);
    }
    if (e != NULL) {
        e[1] = e[1] - 1;
        if (e[1] == 0) {
            HashtableRemove(func_ov000_0218b3f4(p), k);
        }
    }
}

int func_ov000_0218d0c8(const void *a, int b) {
    int v1;
    const s8 *p = a;
    v1 = 0;
    if (0 < b) {
        do {
            if (p[v1] == 0) {
                return v1 + 1;
            }
            v1 = v1 + 1;
        } while (v1 < b);
    }
    return -1;
}

static inline void func_ov000_0218ce14_inline(Unk0218cd94 *d, Unk0218cd94 *s) {
    u8 *p = (u8 *) d;
    u8 *q = (u8 *) s;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
}

void SbServerListInit(SbServerList *slist, const char *a, const char *b, const char *c, u32 d, s32 e, UnkFunc *callback,
                      void *g) {
    if (slist == NULL) {
        func_0213442c(data_ov000_021b2280, data_ov000_021b2218, NULL, 0x11c);
    }
    if (e != 0 || data_ov000_021b4d28 == 1) {
        slist->mState = 1;
        func_ov000_0218d180((u32) slist);
        func_ov000_0218b3f4(slist);
        strcpy(slist->mUnk_00c, a);
        strcpy(slist->mUnk_030, b);
        strcpy(slist->mUnk_054, c);
        slist->mCallback = callback;
        slist->mUnk_48c = NULL;
        if (callback == NULL) {
            func_0213442c(data_ov000_021b2290, data_ov000_021b2218, NULL, 0x132);
        }
        slist->mUnk_494 = g;
        slist->mUnk_498 = (u32) data_ov000_021b2260;
        slist->mUnk_4a0 = 0;
        slist->mUnk_4b0 = -1;
        slist->mInBuffer = NULL;
        slist->mInBufferLength = 0;
        slist->mUnk_008 = NULL;
        slist->mUnk_484 = -1;
        slist->mUnk_480 = 0;
        slist->mUnk_4a4 = 0;
        slist->mUnk_4b8 = d;
        func_ov000_0218c45c(slist, data_ov000_021b2260);
        slist->mUnk_5cc = 0;
        srand(func_ov000_0218e8c4());
        func_ov000_0218e8b8();
    }
}

void func_ov000_0218cf30(SbServerList *p) {
    s32 n = p->mInBufferLength;
    const char *s;
    const char *t;
    char *q;
    if (n > 0) {
        s = data_ov000_021b21ec;
        if ((u32) n > strlen(s)) {
            q = (char *) p->mInBuffer;
            t = data_ov000_021b21ec;
            if (strncmp(q, t, strlen(t)) == 0) {
                func_ov000_0218c45c(p, q + strlen(s));
                p->mCallback(p, 5, *(u32 *) data_ov000_021b4d1c, p->mUnk_494);
            }
        }
    }
    p->mCallback(p, 4, *(u32 *) data_ov000_021b4d1c, p->mUnk_494);
    func_ov000_0218c980(p);
}

u32 func_ov000_0218cef4(const s8 *a, u32 b) {
    s32 c;
    u32 h = 0;
    while ((c = *a) != 0) {
        if (c >= 0 && c < 0x80) {
            c = data_0215d184[c];
        }
        h *= 0x9ccf9319;
        h += c;
        a++;
    }
    return h % b;
}

s32 func_ov000_0218ce14(SbServerList *p) {
    Unk0218ce14 v1;
    char v2[0x80];
    u32 h;
    Unk021a8f84 *e;
    h = func_ov000_0218cef4((s8 *) p->mUnk_00c, 0x14);
    if (data_ov000_021b4d20 != NULL) {
        strcpy(v2, data_ov000_021b4d20);
    } else {
        sprintf(v2, data_ov000_021b2264, p->mUnk_00c, h);
    }
    v1.mUnk_01 = 2;
    v1.mUnk_02 = 0xee70;
    v1.mUnk_04 = func_ov000_0218e374((u32) v2);
    if (v1.mUnk_04 == -1) {
        e = func_ov000_021a8f84(v2);
        if (e == NULL) {
            return 2;
        }
        func_ov000_0218ce14_inline((Unk0218cd94 *) &v1.mUnk_04, (Unk0218cd94 *) e->mUnk_0c[0]);
    }
    if (p->mUnk_4b0 == -1) {
        p->mUnk_4b0 = func_ov000_0218e554(2, 1, 0);
        if (p->mUnk_4b0 == -1) {
            return 1;
        }
    }
    if (func_ov000_0218e4b4(p->mUnk_4b0, &v1, 8) != 0) {
        func_ov000_0218e53c(p->mUnk_4b0);
        p->mUnk_4b0 = -1;
        return 3;
    }
    return 0;
}

void func_ov000_0218cdd8(u8 **a, const char *b, s32 *c) {
    u32 n;
    if (b == NULL) {
        b = data_ov000_021b2260;
    }
    n = strlen(b) + 1;
    memcpy(*a, b, n);
    *c = *c + n;
    *a = *a + n;
}

void func_ov000_0218cdc4(u8 **a, u8 b, s32 *c) {
    **a = b;
    *c = *c + 1;
    *a = *a + 1;
    return;
}

void func_ov000_0218cd94(u8 **a, u32 b, s32 *c) {
    u8 *p = *a;
    u8 *q = (u8 *) &b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    *c = *c + 4;
    *a = *a + 4;
}

void func_ov000_0218cd74(u8 **arg0, const void *arg1, s32 arg2, s32 *arg3) {
    memcpy(*arg0, arg1, arg2);
    *arg3 = *arg3 + arg2;
    *arg0 = *arg0 + arg2;
    return;
}
