#include "00/code_0218aea4.h"

#include "00/code_0218a9bc.h"
#include "00/types_0218b928.h"
#include "00/code_0218d000.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_0218dd8c.h"
#include "code_0214177c.h"
#include "00/unk_021b4000.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_021a3000.h"
#include "00/code_0218acf4.h"
#include "00/code_0218d818.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "00/code_0218a918.h"
#include "00/code_0218acb0.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218b000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a4b84.h"
#include "string.h"
#include "00/code_0218a67c.h"
#include "00/code_02196000.h"
#include "00/code_02196590.h"
#include "00/code_021965a0.h"
#include "00/code_02190ff8.h"
#include "00/code_02190000.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196594.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021a3a18.h"
#include "00/code_0218ab18.h"
#include "00/code_0218a71c.h"
#include "code_021384cc.h"
#include "00/code_021919ac.h"
#include "code_021382a8.h"
#include "00/code_0218d488.h"
#include "00/code_021a6d5c.h"

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
    DarraySort(p->mUnk_004, (u32) f);
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
            v3 = func_ov000_0218b27c(((u32 *) (u32) (v1)));
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
        AssertionFailed(data_ov000_021b22a4, data_ov000_021b2218, NULL, 0xf4);
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
        AssertionFailed(data_ov000_021b2280, data_ov000_021b2218, NULL, 0x11c);
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
            AssertionFailed(data_ov000_021b2290, data_ov000_021b2218, NULL, 0x132);
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

void func_ov000_0218ccbc(SbServerList *p) {
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    BOOL v5;
    s32 v6;
    s32 v7;
    s32 v8;
    s32 t;
    s32 s;
    s32 i;
    p->mUnk_074[0] = (s32) rand() % 0x5d + 0x21;
    s = 0;
    i = 1;
    v2 = 0;
    v1 = 1;
    v4 = 0;
    v3 = 1;
    v6 = 1;
    v5 = TRUE;
    v7 = 1;
    v8 = 1;
    for (; i < 8; i++) {
        s = ((p->mUnk_074[0] & v6) ^ (s ^ (t = i, t = (s32) (t ^ p->mUnk_074[i - 1]), t &= v5, t))) ^
            ((p->mUnk_074[0] < 0x4f) ? v3 : v4) ^ ((p->mUnk_074[i - 1] < p->mUnk_074[0]) ? v1 : v2);
        p->mUnk_074[i] = (s32) rand() % 0x5d + 0x21;
        if ((s != 0 && (p->mUnk_074[i] & v7) == 0) || (s == 0 && (p->mUnk_074[i] & v8) == 1)) {
            p->mUnk_074[i] += 1;
        }
    }
}

s32 func_ov000_0218cc48(SbServerList *p, void *a, s32 b) {
    s32 i = 1;
    s32 n;
    s32 r;
    do {
        i--;
        n = func_ov000_0218e420(p->mUnk_4b0, a, b, 0);
        if (n > 0) {
            break;
        }
        if (i < 0) {
            break;
        }
        func_ov000_0218c980(p);
        r = func_ov000_0218ca58(p, NULL, NULL, 2, 0);
        if (r != 0) {
            func_ov000_0218cf30(p);
            return r;
        }
    } while (i >= 0);
    if (n <= 0) {
        return 3;
    }
    return 0;
}

s32 func_ov000_0218ca58(SbServerList *p, const char *a, const char *b, u32 c, u32 d) {
    u8 v1[0x300];
    u16 t;
    s32 v2;
    u8 *v3;
    u8 *q;
    s32 r;
    if (p->mState != 1) {
        AssertionFailed(data_ov000_021b2240, data_ov000_021b2218, NULL, 0x20a);
    }
    if (a == NULL) {
        a = data_ov000_021b2260;
    }
    if (b == NULL) {
        b = data_ov000_021b2260;
    }
    if (strlen(a) > 0x100) {
        return 6;
    }
    if (strlen(b) > 0x100) {
        return 6;
    }
    r = func_ov000_0218ce14(p);
    if (r != 0) {
        return r;
    }
    p->mUnk_5c4 = c;
    func_ov000_0218ccbc(p);
    v2 = 2;
    q = v1;
    v3 = q + 2;
    func_ov000_0218cdc4(&v3, 0, &v2);
    func_ov000_0218cdc4(&v3, 1, &v2);
    func_ov000_0218cdc4(&v3, 3, &v2);
    func_ov000_0218cd94(&v3, p->mUnk_4b8, &v2);
    func_ov000_0218cdd8(&v3, p->mUnk_00c, &v2);
    func_ov000_0218cdd8(&v3, p->mUnk_030, &v2);
    func_ov000_0218cd74(&v3, p->mUnk_074, 8, &v2);
    func_ov000_0218cdd8(&v3, b, &v2);
    func_ov000_0218cdd8(&v3, a, &v2);
    func_ov000_0218cd94(
        &v3, ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00))), &v2);
    if ((p->mUnk_5c4 & 8) != 0) {
        func_ov000_0218cd94(&v3, p->mUnk_4a4, &v2);
    }
    if ((p->mUnk_5c4 & 0x80) != 0) {
        func_ov000_0218cd94(&v3, d, &v2);
    }
    t = (u16) ((((u16) v2 >> 8) & 0xff) | (((u16) v2 << 8) & 0xff00));
    __memcpy(v1, &t, 2);
    if (func_ov000_0218e420(p->mUnk_4b0, v1, v2, 0) <= 0) {
        func_ov000_0218c980(p);
        return 3;
    }
    p->mState = 3;
    p->mUnk_5c8 = 0;
    if (p->mInBuffer == NULL) {
        p->mInBuffer = func_ov000_021a3690(0x1000);
        if (p->mInBuffer == NULL) {
            return 5;
        }
        p->mInBufferLength = 0;
    }
    return 0;
}

void func_ov000_0218ca1c(SbServerList *p) {
    int i;
    for (i = 0; i < p->mUnk_480; i++) {
        func_ov000_0218d0e4(p, (u32) p->mUnk_084[i]);
    }
    p->mUnk_480 = 0;
}

void func_ov000_0218c9d4(SbServerList *p) {
    int i;
    if (p->mUnk_008 != NULL) {
        for (i = 0; i < DarrayGetCount(p->mUnk_008); i++) {
            func_ov000_0218d0e4(p, *(u32 *) DarrayGetElement(p->mUnk_008, i));
        }
        DarrayDelete(p->mUnk_008);
        p->mUnk_008 = NULL;
    }
}

void func_ov000_0218c980(SbServerList *p) {
    if (p->mInBuffer != NULL) {
        func_ov000_021a3668(p->mInBuffer);
    }
    p->mInBuffer = NULL;
    p->mInBufferLength = 0;
    if (p->mUnk_4b0 != -1) {
        func_ov000_0218e53c(p->mUnk_4b0);
    }
    p->mUnk_4b0 = -1;
    p->mState = 1;
    func_ov000_0218c9d4(p);
    p->mUnk_484 = -1;
    func_ov000_0218ca1c(p);
}

void func_ov000_0218c958(SbServerList *p) {
    func_ov000_0218c980(p);
    func_ov000_0218d1a0(p);
    func_ov000_0218b3c8(p);
    if (p->mUnk_004 != NULL) {
        DarrayDelete(p->mUnk_004);
    }
    p->mUnk_004 = NULL;
}

void func_ov000_0218c8e0(SbServerList *a, s8 *b, s32 c) {
    s32 d;
    s8 *p;
    s32 i;
    s8 *q;
    d = strlen(a->mUnk_054);
    p = (s8 *) a->mUnk_054;
    for (i = 0; i < c; i++) {
        s32 x = p[i % d];
        s32 y = i * x % 8;
        s32 z = i % 8;
        a->mUnk_074[y] = a->mUnk_074[y] ^ (s8) (a->mUnk_074[z] ^ b[i]);
    }
    func_ov000_0218a7bc((Unk0218a71c *) a->mUnk_4bc, (const u8 *) a->mUnk_074, 8);
}

s32 func_ov000_0218c8ac(u32 a) {
    s32 b;
    b = 5;
    if ((a & 2) != 0) {
        b += 4;
    }
    if ((a & 8) != 0) {
        b += 4;
    }
    if ((a & 0x10) != 0) {
        b += 2;
    }
    if ((a & 0x20) != 0) {
        b += 2;
    }
    return b;
}

BOOL func_ov000_0218c84c(u8 *a, s32 b) {
    s32 k;
    while (b > 0 && *(s8 *) a != 0) {
        k = func_ov000_0218d0c8(a, b);
        if (k < 0) {
            return FALSE;
        }
        a += k;
        b -= k;
        k = func_ov000_0218d0c8(a, b);
        if (k < 0) {
            return FALSE;
        }
        a += k;
        b -= k;
    }
    if (b == 0) {
        return FALSE;
    }
    return *(s8 *) a == 0;
}

BOOL func_ov000_0218c794(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    s32 t;
    d = DarrayGetCount(a->mUnk_008);
    i = 0;
    if (d > 0) {
        do {
            switch (((Unk0218c0bc *) DarrayGetElement(a->mUnk_008, i))->mUnk_04) {
                case 1:
                    b += 1;
                    c -= 1;
                    break;
                case 2:
                    b += 2;
                    c -= 2;
                    break;
                case 0:
                    if (c < 1) {
                        return FALSE;
                    }
                    t = b[0];
                    b += 1;
                    c -= 1;
                    if (t == 0xff) {
                        k = func_ov000_0218d0c8(b, c);
                        if (k == -1) {
                            return FALSE;
                        }
                        b += k;
                        c -= k;
                    }
                    break;
                default:
                    AssertionFailed(data_ov000_021b223c, data_ov000_021b2218, NULL, 0x317);
                    return FALSE;
            }
            if (c < 0) {
                return FALSE;
            }
            i++;
        } while (i < d);
    }
    return TRUE;
}

void func_ov000_0218c744(SbServerList *a, u8 *b, s32 c, u8 *d, u16 *e) {
    u8 f;
    u8 *p;
    u8 *q;
    if (c >= 5) {
        f = b[0];
        p = b + 1;
        d[0] = p[0];
        d[1] = p[1];
        d[2] = p[2];
        d[3] = p[3];
        if ((f & 0x10) != 0) {
            if (c - 5 < 2) {
                return;
            }
            q = (u8 *) e;
            p = b + 5;
            q[0] = p[0];
            q[1] = p[1];
        } else {
            *e = a->mUnk_4a8;
        }
    }
}

s32 func_ov000_0218c550(SbServerList *a, void *b, u8 *c, s32 d, s32 e) {
    s32 h;
    s32 f;
    s32 g;
    s32 i;
    u16 k;
    u16 l;
    u32 j;
    s32 n;
    u8 *o;
    u8 *p;
    u8 *q;
    Unk0218c0bc *r;
    f = d;
    g = c[0];
    func_ov000_0218af24(b, g);
    c += 5;
    d -= 5;
    if ((g & 0x10) != 0) {
        c += 2;
        d -= 2;
    }
    if ((g & 2) != 0) {
        q = (u8 *) &j;
        q[0] = c[0];
        q[1] = c[1];
        q[2] = c[2];
        q[3] = c[3];
        c += 4;
        d -= 4;
    } else {
        j = 0;
    }
    if ((g & 0x20) != 0) {
        q = (u8 *) &l;
        q[0] = c[0];
        q[1] = c[1];
        c += 2;
        d -= 2;
    } else {
        l = a->mUnk_4a8;
    }
    func_ov000_0218af1c(b, j, l);
    if ((g & 8) != 0) {
        q = (u8 *) &j;
        q[0] = c[0];
        q[1] = c[1];
        q[2] = c[2];
        q[3] = c[3];
        c += 4;
        d -= 4;
        func_ov000_0218af18(b, j);
    }
    if ((g & 0x40) != 0) {
        h = DarrayGetCount(a->mUnk_008);
        i = 0;
        if (h > 0) {
            do {
                r = DarrayGetElement(a->mUnk_008, i);
                switch (r->mUnk_04) {
                    case 1:
                        SbServerSetInt(b, r->mUnk_00, c[0]);
                        c += 1;
                        d -= 1;
                        break;
                    case 2:
                        q = (u8 *) &k;
                        q[0] = c[0];
                        q[1] = c[1];
                        SbServerSetInt(b, r->mUnk_00, (u16) ((k >> 8 & 0xff) | (k << 8 & 0xff00)));
                        c += 2;
                        d -= 2;
                        break;
                    case 0:
                        if (e != 0) {
                            n = c[0];
                            c += 1;
                            d -= 1;
                        } else {
                            n = 0xff;
                        }
                        if (n == 0xff) {
                            SbServerSetValue(b, r->mUnk_00, (const char *) c);
                            n = strlen((const char *) c) + 1;
                            c += n;
                            d -= n;
                        } else {
                            SbServerSetValue(b, r->mUnk_00, a->mUnk_084[n]);
                        }
                        break;
                }
                i++;
            } while (i < h);
        }
        func_ov000_0218af14(b, func_ov000_0218af10(b) | 1);
    }
    g = g & 0x80;
    if (g != 0) {
        while ((s8) c[0] != 0 && d > 0) {
            o = c;
            n = strlen((const char *) c) + 1;
            c += n;
            d -= n;
            SbServerSetValue(b, (const char *) o, (const char *) c);
            n = strlen((const char *) c) + 1;
            c += n;
            d -= n;
        }
        d -= 1;
        func_ov000_0218af14(b, func_ov000_0218af10(b) | 2);
    }
    return f - d;
}

s32 func_ov000_0218c468(SbServerList *a, u8 *b, s32 c) {
    s32 e;
    s32 d;
    void *h;
    u16 f;
    u32 g;
    s32 r;
    if (c < 1) {
        return 0;
    }
    d = b[0];
    e = func_ov000_0218c8ac(d);
    if (c < e) {
        return 0;
    }
    if ((d & 0x40) != 0) {
        if (func_ov000_0218c794(a, b + e, c - e) == FALSE) {
            return 0;
        }
    }
    d = d & 0x80;
    if (d != 0) {
        if (func_ov000_0218c84c(b + e, c - e) == FALSE) {
            return 0;
        }
    }
    if (memcmp(b + 1, data_ov000_021b2234, 4) == 0) {
        return -1;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    h = func_ov000_0218af28(a, g, f);
    if (func_ov000_0218aefc(h) != 0) {
        return -2;
    }
    r = func_ov000_0218c550(a, h, b, c, 1);
    func_ov000_0218d340(a, (u32) h);
    return r;
}

void func_ov000_0218c45c(SbServerList *a, char *b) {
    a->mUnk_4ac = b;
    return;
}

s32 func_ov000_0218c15c(SbServerList *a) {
    u8 *p;
    s32 n;
    s32 u;
    s32 v;
    s32 w;
    s32 k;
    Unk0218c0bc e;
    u8 *q;
    u8 *r;
    p = a->mInBuffer;
    n = a->mInBufferLength;
    switch (a->mUnk_5c8) {
        case 0:
            if (n < 1) {
                break;
            }
            u = (p[0] ^ 0xec) + 2;
            if (n < u) {
                break;
            }
            v = p[u - 1] ^ 0xea;
            w = u + v;
            if (n < w) {
                break;
            }
            func_ov000_0218c8e0(a, (s8 *) (p + u), v);
            a->mUnk_5c8 = 1;
            p += w;
            n -= w;
            func_ov000_0218a6f4(a->mUnk_4bc, p, n);
        case 1:
            if (n < 6) {
                break;
            }
            q = (u8 *) &a->mUnk_4a0;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            a->mCallback(a, 6, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
            q = (u8 *) &a->mUnk_4a8;
            r = p + 4;
            q[0] = r[0];
            q[1] = r[1];
            if (a->mUnk_4a8 == 0xffff) {
                if (func_ov000_0218d0c8(p + 6, n - 6) == -1) {
                    break;
                }
                func_ov000_0218c45c(a, (char *) (p + 6));
                a->mCallback(a, 5, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                if (a->mInBuffer == NULL) {
                    break;
                }
            }
            p += 6;
            n -= 6;
            if ((a->mUnk_5c4 & 2) != 0 || a->mUnk_4a8 == 0xffff) {
                a->mUnk_5c8 = 5;
                a->mState = 2;
                break;
            }
            a->mUnk_5c8 = 2;
            a->mUnk_484 = -1;
        case 2:
            if (a->mUnk_484 == -1) {
                if (n < 1) {
                    break;
                }
                a->mUnk_484 = p[0];
                a->mUnk_008 = DarrayCreate(8, a->mUnk_484, NULL);
                if (a->mUnk_008 == NULL) {
                    return 5;
                }
                p += 1;
                n -= 1;
            }
            while (a->mUnk_484 > DarrayGetCount(a->mUnk_008)) {
                if (n < 2) {
                    break;
                }
                k = func_ov000_0218d0c8(p + 1, n - 1);
                if (k == -1) {
                    break;
                }
                e.mUnk_04 = p[0];
                e.mUnk_00 = func_ov000_0218d134(a, (const char *) (p + 1));
                DarrayAppend(a->mUnk_008, &e);
                k += 1;
                p += k;
                n -= k;
            }
            if (a->mUnk_484 > DarrayGetCount(a->mUnk_008)) {
                break;
            }
            a->mUnk_5c8 = 3;
            a->mUnk_484 = -1;
        case 3:
            if (a->mUnk_484 == -1) {
                if (n < 1) {
                    break;
                }
                a->mUnk_484 = p[0];
                a->mUnk_480 = 0;
                p += 1;
                n -= 1;
            }
            while (a->mUnk_484 > a->mUnk_480) {
                k = func_ov000_0218d0c8(p, n);
                if (k == -1) {
                    break;
                }
                a->mUnk_084[a->mUnk_480++] = func_ov000_0218d134(a, (const char *) p);
                p += k;
                n -= k;
            }
            if (a->mUnk_484 > a->mUnk_480) {
                break;
            }
            a->mUnk_5c8 = 4;
        case 4:
            if (n < 5) {
                break;
            }
            do {
                k = func_ov000_0218c468(a, p, n);
                if (k == -2) {
                    return 5;
                }
                if (k == -1) {
                    n -= 5;
                    p += 5;
                    a->mUnk_5c8 = 5;
                    a->mState = 2;
                    a->mCallback(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
                    break;
                }
                p += k;
                n -= k;
                if (a->mInBuffer == NULL) {
                    k = 0;
                }
            } while (k != 0);
            break;
    }
    if (n < 0) {
        AssertionFailed(data_ov000_021b2228, data_ov000_021b2218, NULL, 0x4af);
    }
    if (a->mInBuffer == NULL) {
        return 0;
    }
    if (n != 0) {
        memmove(a->mInBuffer, p, n);
    }
    a->mInBufferLength = n;
    return 0;
}

s32 func_ov000_0218c0bc(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 k;
    Unk0218c0bc e;
    d = b[0];
    b += 1;
    c -= 1;
    if (a->mUnk_008 != NULL) {
        func_ov000_0218c9d4(a);
    }
    a->mUnk_008 = DarrayCreate(8, d, NULL);
    if (a->mUnk_008 == NULL) {
        return 5;
    }
    i = 0;
    if (d > 0) {
        do {
            if (c < 2) {
                return 4;
            }
            k = func_ov000_0218d0c8(b + 1, c - 1);
            if (k == -1) {
                return 4;
            }
            e.mUnk_04 = b[0];
            e.mUnk_00 = func_ov000_0218d134(a, (const char *) (b + 1));
            DarrayAppend(a->mUnk_008, &e);
            k += 1;
            b += k;
            c -= k;
            i++;
        } while (i < d);
    }
    return 0;
}

s32 func_ov000_0218bf78(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    s32 i;
    s32 e;
    s32 k;
    s32 m;
    u8 *l;
    u32 f;
    u16 g;
    u32 h;
    u8 *p;
    u8 *q;
    if (c < 2) {
        return 4;
    }
    d = b[0];
    e = b[1];
    b += 2;
    c -= 2;
    i = 0;
    if (e > 0) {
        do {
            l = b;
            k = func_ov000_0218d0c8(b, c);
            if (k == -1) {
                return 4;
            }
            b += k;
            c -= k;
            if (c < 11) {
                return 4;
            }
            p = b;
            q = (u8 *) &f;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            p = b + 4;
            q = (u8 *) &g;
            q[0] = p[0];
            q[1] = p[1];
            p = b + 6;
            q = (u8 *) &h;
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            h = (h << 24 & 0xff000000) | ((h << 8 & 0xff0000) | ((h >> 24 & 0xff) | (h >> 8 & 0xff00)));
            b += 10;
            c -= 10;
            m = func_ov000_0218d0c8(b, c);
            if (m == -1) {
                return 4;
            }
            a->mUnk_490(a, l, f, g, h, b, a->mUnk_494);
            b += m;
            c -= m;
            i++;
        } while (i < e);
    }
    if (d != 0) {
        a->mUnk_490(a, 0, 0, 0, 0, 0, a->mUnk_494);
    }
    return 0;
}

s32 func_ov000_0218be68(SbServerList *a, u8 *b, s32 c) {
    u32 g;
    u32 d;
    u16 e;
    u32 f;
    s32 h;
    s32 i;
    s32 j;
    u8 *k[16];
    u8 *p;
    u8 *q;
    u8 *l;
    if (c < 11) {
        return 4;
    }
    p = b;
    q = (u8 *) &d;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    q = (u8 *) &e;
    p = b + 4;
    q[0] = p[0];
    q[1] = p[1];
    i = func_ov000_0218d2a8(a, d, e);
    if (i == -1) {
        return 0;
    }
    f = func_ov000_0218d218(a, i);
    q = (u8 *) &g;
    p = b + 6;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    g = (g << 24 & 0xff000000) | ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00)));
    h = b[10];
    b += 11;
    c -= 11;
    for (j = 0; j < h && j < 16;) {
        if (c < 1) {
            break;
        }
        i = func_ov000_0218d0c8(b, c);
        if (i == -1) {
            return 4;
        }
        k[j] = b;
        b += i;
        c -= i;
        j++;
    }
    if (a->mUnk_48c == NULL) {
        return 0;
    }
    a->mUnk_48c(a, f, g, j, k, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218be10(SbServerList *a, u8 *b, s32 c) {
    u32 d;
    u16 e;
    s32 f;
    u8 *p;
    u8 *q;
    if (c < 6) {
        return 4;
    }
    p = b;
    q = (u8 *) &d;
    q[0] = p[0];
    q[1] = p[1];
    q[2] = p[2];
    q[3] = p[3];
    q = (u8 *) &e;
    p = b + 4;
    q[0] = p[0];
    q[1] = p[1];
    f = func_ov000_0218d2a8(a, d, e);
    if (f != -1) {
        func_ov000_0218d238(a, f);
        return 0;
    }
    return 0;
}

s32 func_ov000_0218bd5c(SbServerList *a, u8 *b, s32 c) {
    s32 d;
    void *e;
    u16 f;
    u32 g;
    if (c < 5) {
        return 4;
    }
    func_ov000_0218c744(a, b, c, (u8 *) &g, &f);
    d = func_ov000_0218d2a8(a, g, f);
    if (d == -1) {
        e = func_ov000_0218af28(a, g, f);
        if (func_ov000_0218aefc(e) != 0) {
            return 5;
        }
    } else {
        e = (void *) func_ov000_0218d218(a, d);
    }
    if (func_ov000_0218c550(a, e, b, c, 0) < 0) {
        return 4;
    }
    if (d == -1) {
        func_ov000_0218d340(a, (u32) e);
    }
    a->mCallback(a, 1, e, a->mUnk_494);
    return 0;
}

s32 func_ov000_0218bc08(SbServerList *slist) {
    s32 b;
    u16 c;
    u8 *q;
    u8 *p;
    b = 0;
    while (slist->mInBufferLength >= 3) {
        q = (u8 *) &c;
        p = slist->mInBuffer;
        q[0] = p[0];
        q[1] = p[1];
        c = (c >> 8 & 0xff) | (c << 8 & 0xff00);
        if (c > 0x1000) {
            b = 4;
            break;
        }
        if (slist->mInBufferLength < c) {
            return 0;
        }
        switch ((s8) slist->mInBuffer[2]) {
            case 1:
                b = func_ov000_0218c0bc(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 2:
                b = func_ov000_0218bd5c(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 3:
                if (func_ov000_0218e420(slist->mUnk_4b0, slist->mInBuffer, c, 0) <= 0) {
                    return 3;
                }
                break;
            case 4:
                b = func_ov000_0218be10(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 5:
                b = func_ov000_0218be68(slist, slist->mInBuffer + 3, c - 3);
                break;
            case 6:
                b = func_ov000_0218bf78(slist, slist->mInBuffer + 3, c - 3);
                break;
        }
        slist->mInBufferLength -= c;
        if (slist->mInBufferLength < 0) {
            AssertionFailed(data_ov000_021b2200, data_ov000_021b2218, NULL, 0x5b4);
        }
        if (slist->mInBufferLength != 0 && slist->mInBuffer != NULL) {
            memmove(slist->mInBuffer, slist->mInBuffer + c, slist->mInBufferLength);
        }
        if (b != 0) {
            break;
        }
    }
    if (b != 0) {
        func_ov000_0218cf30(slist);
    }
    return b;
}

s32 func_ov000_0218bb44(SbServerList *a) {
    s32 b;
    s32 c;
    s32 d;
    if (func_ov000_0218e668(a->mUnk_4b0) == 0) {
        return 0;
    }
    b = a->mInBufferLength;
    c = func_ov000_0218e460(a->mUnk_4b0, a->mInBuffer + b, 0x1000 - b, 0);
    if ((u32) (c + 1) <= 1) {
        func_ov000_0218cf30(a);
        return 3;
    }
    a->mInBufferLength += c;
    d = 0;
    if (a->mState == 2 || a->mUnk_5c8 > 0) {
        func_ov000_0218a6f4(a->mUnk_4bc, a->mInBuffer + b, a->mInBufferLength - b);
    }
    if (a->mState == 3) {
        d = func_ov000_0218c15c(a);
    }
    if (d != 0) {
        return d;
    }
    if (a->mState == 2 && a->mInBufferLength > 0) {
        return func_ov000_0218bc08(a);
    }
    return 0;
}

s32 func_ov000_0218ba88(SbServerList *a, u32 b, u16 c, u8 *d, s32 e) {
    Unk0218ba88 g;
    u16 h;
    u8 *p;
    u8 *q;
    s32 r;
    if (a->mState == 1) {
        func_ov000_0218ca58(a, NULL, NULL, 2, 0);
    }
    if (a->mState == 1) {
        return 3;
    }
    h = e + 9;
    g.mUnk_00 = (h >> 8 & 0xff) | (h << 8 & 0xff00);
    p = g.mUnk_02;
    q = (u8 *) &g.mUnk_00;
    p[0] = q[0];
    p[1] = q[1];
    g.mUnk_04 = 2;
    p = g.mUnk_05;
    q = (u8 *) &b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    p = g.mUnk_09;
    q = (u8 *) &c;
    p[0] = q[0];
    p[1] = q[1];
    r = func_ov000_0218cc48(a, g.mUnk_02, 9);
    if (r != 0) {
        return r;
    }
    if (func_ov000_0218e420(a->mUnk_4b0, d, e, 0) < 0) {
        return 3;
    }
    return 0;
}

s32 func_ov000_0218ba10(SbServerList *a, u32 b, u16 c, u32 d) {
    u8 v[10];
    u8 *p;
    u8 *q;
    v[0] = 0xfd;
    v[1] = 0xfc;
    v[2] = 0x1e;
    v[3] = 0x66;
    v[4] = 0x6a;
    v[5] = 0xb2;
    d = (d << 24 & 0xff000000) | ((d << 8 & 0xff0000) | ((d >> 24 & 0xff) | (d >> 8 & 0xff00)));
    p = v + 6;
    q = (u8 *) &d;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    return func_ov000_0218ba88(a, b, c, v, 10);
}

s32 func_ov000_0218b928(SbServerList *a) {
    Unk0218b8f4 v1;
    s32 v2;
    u8 v3[0x5e0];
    void *p;
    v2 = 8;
    while (func_ov000_0218e668(a->mUnk_4b0) != 0) {
        if (func_ov000_0218e438(a->mUnk_4b0, v3, 0x5db, 0, (u8 *) &v1, &v2) != -1) {
            if (func_ov000_0218d2a8(a, v1.mUnk_04, v1.mUnk_02) == -1) {
                p = func_ov000_0218af28(a, v1.mUnk_04, v1.mUnk_02);
                if (func_ov000_0218aefc(p) != 0) {
                    return 5;
                }
                func_ov000_0218af24(p, 0x11);
                func_ov000_0218d340(a, (u32) p);
            }
        }
    }
    if (func_ov000_0218e8c4() - a->mUnk_4b4 > 0x7d0) {
        func_ov000_0218e53c(a->mUnk_4b0);
        a->mUnk_4b0 = -1;
        a->mState = 1;
        a->mCallback(a, 3, *(u32 *) data_ov000_021b4d1c, a->mUnk_494);
    }
    return 0;
}

s32 func_ov000_0218b8e4(SbServerList *a) {
    func_ov000_0218d1dc(a);
    switch (a->mState) {
        case 2:
        case 3:
            return func_ov000_0218bb44(a);
        case 0:
            return func_ov000_0218b928(a);
        case 1:
        default:
            return 0;
    }
}

void func_ov000_0218b780(SbServerList *a, s32 b, SbServer *c, Unk0218b668 *d) {
    switch (b) {
        case 0:
            d->mUnk_630(d, 0, c, d->mUnk_634);
            if (((c->mUnk_14 & 3) == 0 || (c->mUnk_14 & 0x40) == 0) && (c->mUnk_14 & 0x2c) == 0 && d->mUnk_624 == 0) {
                s32 t;
                if (c->mUnk_15 & 1) {
                    if (d->mUnk_04c.mState == 0 || d->mUnk_000.mUnk_40 == 0) {
                        t = 1;
                    } else {
                        t = 0;
                    }
                } else {
                    t = 2;
                }
                func_ov000_0218ac54(&d->mUnk_000, c, 0, t);
            }
            break;
        case 1:
            if ((c->mUnk_14 & 0x43) == 0) {
                d->mUnk_630(d, 2, c, d->mUnk_634);
            } else {
                d->mUnk_630(d, 1, c, d->mUnk_634);
            }
            break;
        case 2:
            if ((c->mUnk_14 & 0x2c) != 0) {
                func_ov000_0218a918(d, c);
            }
            d->mUnk_630(d, 3, c, d->mUnk_634);
            break;
        case 3:
            if (d->mUnk_620 != 0) {
                func_ov000_0218c980(a);
            }
            if (DarrayGetCount(a->mUnk_004) == 0 || d->mUnk_000.mUnk_08.mUnk_08 == 0) {
                d->mUnk_630(d, 4, 0, d->mUnk_634);
            }
            break;
        case 5:
            d->mUnk_630(d, 5, 0, d->mUnk_634);
            break;
        case 6:
            func_ov000_0218acf0(d, d->mUnk_04c.mUnk_4a0);
            break;
    }
    if (c != NULL && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}

void func_ov000_0218b708(void *a, s32 b, SbServer *c, Unk0218b668 *d) {
    switch (b) {
        case 1:
            d->mUnk_630(d, 2, c, d->mUnk_634);
            break;
        case 0:
            d->mUnk_630(d, 1, c, d->mUnk_634);
            break;
        case 2:
            d->mUnk_630(d, 4, c, d->mUnk_634);
            break;
    }
    if (c != NULL && c->mUnk_00 == d->mUnk_628 && c->mUnk_04 == d->mUnk_62c) {
        d->mUnk_628 = 0;
    }
}

Unk0218b668 *func_ov000_0218b668(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, s32 g, UnkFunc *h, u32 l) {
    Unk0218b668 *p;
    if (g == 0 && data_ov000_021b4d28 != 1) {
        return NULL;
    }
    p = func_ov000_021a3690(0x638);
    if (p == NULL) {
        return NULL;
    }
    p->mUnk_630 = h;
    p->mUnk_634 = l;
    p->mUnk_624 = 0;
    SbServerListInit(&p->mUnk_04c, (const char *) a, (const char *) b, (const char *) c, d, g, func_ov000_0218b780, p);
    func_ov000_0218acf4(&p->mUnk_000, e, f, g, func_ov000_0218b708, p);
    return p;
}

void func_ov000_0218b64c(Unk0218b668 *p) {
    func_ov000_0218c958(&p->mUnk_04c);
    func_ov000_0218acb0(p);
    func_ov000_021a3668(p);
}

s32 func_ov000_0218b590(Unk0218b668 *a, s32 b, u32 c, u8 *d, s32 e, const char *f, u32 g, u32 h) {
    char v1[256] = {0};
    s32 n;
    s32 i;
    s32 r;
    const char *s;
    n = 0;
    a->mUnk_620 = c;
    a->mUnk_000.mUnk_40 = 0;
    for (i = 0; i < e; i++) {
        s = data_ov000_021b45bc[d[i]];
        if (n + (s32) strlen(s) + 1 >= 256) {
            break;
        }
        n += sprintf(v1 + n, data_ov000_021b21e8, s);
        func_ov000_0218a93c(&a->mUnk_000, d[i]);
    }
    r = func_ov000_0218ca58(&a->mUnk_04c, v1, f, g, h);
    if (r == 0 && b == 0) {
        n = 10;
        while (a->mUnk_04c.mState == 3 || (a->mUnk_000.mUnk_08.mUnk_08 > 0 && r == 0)) {
            func_ov000_0218e8bc(n);
            r = func_ov000_0218b4bc(a);
        }
    }
    return r;
}

u32 func_ov000_0218b570(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    u32 v2 = p4;
    u32 v4 = p5;
    u32 v8 = p6;
    u32 v10 =
        func_ov000_0218b590((Unk0218b668 *) p0, (s32) p1, p2, (u8 *) p3, (s32) v2, (const char *) v4, (u32) 0x80u, v8);
    return v10;
}

s32 func_ov000_0218b530(Unk0218b668 *a, u32 b, s32 c, u8 *d, s32 e) {
    u32 f = func_ov000_0218e374(b);
    return func_ov000_0218ba88(&a->mUnk_04c, f, (u16) (((c >> 8) & 0xff) | ((c << 8) & 0xff00)), d, e);
}

s32 func_ov000_0218b4f8(Unk0218b668 *a, u32 b, s32 c, u32 d) {
    u32 e = func_ov000_0218e374(b);
    return func_ov000_0218ba10(&a->mUnk_04c, e, (u16) (((c >> 8) & 0xff) | ((c << 8) & 0xff00)), d);
}

void func_ov000_0218b4d4(struct Unk0218b668 *p, s32 a) {
    s32 b;
    b = func_ov000_0218d300(&p->mUnk_04c, a);
    if (b != -1) {
        func_ov000_0218d238(&p->mUnk_04c, b);
    }
}

s32 func_ov000_0218b4bc(struct Unk0218b668 *p) {
    func_ov000_0218a950(p);
    return func_ov000_0218b8e4(&p->mUnk_04c);
}

void func_ov000_0218b4a4(struct Unk0218b668 *p) {
    func_ov000_0218c980(&p->mUnk_04c);
    func_ov000_0218acd8(p);
}

void func_ov000_0218b48c(struct Unk0218b668 *p) {
    func_ov000_0218b4a4(p);
    func_ov000_0218d1a0(&p->mUnk_04c);
}

u32 func_ov000_0218b480(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value3;
    value0 = (value0) + 76u;
    value3 = (u32) &func_ov000_0218d218;
    value0 = (u32) func_ov000_0218d218((SbServerList *) value0, value1);
    return value0;
}

u32 func_ov000_0218b474(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value0 = (value0) + 76u;
    value3 = (u32) &func_ov000_0218d22c;
    value0 = (u32) func_ov000_0218d22c((SbServerList *) value0);
    return value0;
}

void func_ov000_0218b464(Unk0218b668 *p0, u32 p1, void *p2, u32 p3) {
    func_ov000_0218d374(&p0->mUnk_04c, (s32) p1, (u32) p2, p3);
}

u32 func_ov000_0218b458(Unk0218b668 *a) {
    return a->mUnk_04c.mUnk_4a0;
}

u32 func_ov000_0218b44c(Unk0218afac *entry, u32 modulus) {
    return func_ov000_0218afd4(entry->mName, modulus);
}

s32 func_ov000_0218b440(const char *const *first, const char *const *second) {
    return func_02142368(*first, *second);
}

void func_ov000_0218b434(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value3 = (u32) &func_ov000_021a3668;
    func_ov000_021a3668((void *) value0);
    return;
}

struct Hashtable *func_ov000_0218b3f4(struct SbServerList *p) {
    if (data_ov000_021b4d18 == NULL) {
        data_ov000_021b4d18 =
            HashtableCreate(8, 100, 2, (s32(*)(void *, s32)) func_ov000_0218b44c,
                            (s32(*)(void *, void *)) func_ov000_0218b440, (void (*)(void *)) func_ov000_0218b434);
    }
    return data_ov000_021b4d18;
}

void func_ov000_0218b3c8(void *a) {
    int v1;
    if ((data_ov000_021b4d18 != NULL) && (v1 = HashtableGetCount(data_ov000_021b4d18), v1 == 0)) {
        HashtableDelete(data_ov000_021b4d18);
        *(s32 *) &data_ov000_021b4d18 = 0;
    }
    return;
}

void func_ov000_0218b3ac(int *a) {
    int v1;
    v1 = *a;
    HashtableDelete((s32 *) (*(u32 *) (v1 + 0x18)));
    *(u32 *) (v1 + 0x18) = 0;
    func_ov000_021a3668((void *) (v1));
    return;
}

void SbServerSetValue(SbServer *e, const char *v1, const char *v2) {
    char *a[2];
    a[0] = func_ov000_0218d134(NULL, v1);
    a[1] = func_ov000_0218d134(NULL, v2);
    HashtableSet(e->mKeyValues, a);
}

void SbServerSetInt(SbServer *e, const char *v1, u32 c) {
    char a[20];
    sprintf(a, data_ov000_021b21e4, c);
    SbServerSetValue(e, v1, a);
}

char *SbServerGetValue(SbServer *server, const char *v1, char *d) {
    Unk0218b30c a;
    u32 *b;
    if (server == NULL) {
        AssertionFailed(data_ov000_021b21d0, data_ov000_021b21d8, NULL, 0x97);
    }
    if (server == NULL) {
        return NULL;
    }
    a.mUnk_00 = v1;
    b = HashtableFind(server->mKeyValues, &a);
    if (b != NULL) {
        d = (char *) b[1];
    }
    return d;
}

s32 SbServerGetInt(SbServer *e, const char *v1, s32 d) {
    char *a;
    s32 c;
    if (strcmp(v1, data_ov000_021b21c8) == 0) {
        return func_ov000_0218af9c(e);
    }
    a = SbServerGetValue(e, v1, NULL);
    if (a == NULL || (c = *a, !((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)))) {
        return d;
    }
    return StrtolBase10(a);
}

double SbServerGetDouble(SbServer *e, const char *v1, double d) {
    char *a;
    a = SbServerGetValue(e, v1, NULL);
    if (a != NULL) {
        d = atof(a);
    }
    return d;
}

u32 func_ov000_0218b27c(u32 *a) {
    return *a;
}

u32 func_ov000_0218b260(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u16 *) ((value0) + 4u);
    value2 = ((u32) ((s32) value1 >> 8));
    value0 = 255u;
    value2 = (value2) & (value0);
    value1 = (value1 << 8);
    value0 = 0xff00u;
    value1 = (value1) & (value0);
    value2 = (value2) | (value1);
    value0 = (value2 << 16);
    value0 = (value0 >> 16);
    return value0;
}

u16 func_ov000_0218b25c(int a) {
    return *(u16 *) (a + 4);
}

u32 func_ov000_0218b248(int a) {
    if ((*(u8 *) (a + 0x15) & 2) == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov000_0218b244(int a) {
    return *(u32 *) (a + 8);
}

u32 func_ov000_0218b228(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) * (const u16 *) ((value0) + 12u);
    value2 = ((u32) ((s32) value1 >> 8));
    value0 = 255u;
    value2 = (value2) & (value0);
    value1 = (value1 << 8);
    value0 = 0xff00u;
    value1 = (value1) & (value0);
    value2 = (value2) | (value1);
    value0 = (value2 << 16);
    value0 = (value0 >> 16);
    return value0;
}

void func_ov000_0218b224(int a, u32 b) {
    *(u32 *) (a + 0x20) = b;
    return;
}

u32 func_ov000_0218b220(int a) {
    return *(u32 *) (a + 0x20);
}

u32 func_ov000_0218b1e0(const char *s) {
    Unk021b21ac t;
    u32 i;
    const char **p;
    t = data_ov000_021b21ac;
    p = t.mUnk_00;
    for (i = 0; i < 2; i++) {
        if (strcmp(s, *p) == 0) {
            return 0;
        }
        p++;
    }
    return 1;
}

s8 *func_ov000_0218b19c(s8 *s, s32 c) {
    s8 *a;
    s8 *b;
    s32 d;
    if (s != NULL) {
        data_ov000_021b4d14 = s;
    }
    a = data_ov000_021b4d14;
    while ((d = *(b = data_ov000_021b4d14)) != 0 && d != c) {
        data_ov000_021b4d14++;
    }
    if (b == a) {
        a = NULL;
    }
    if (d != 0) {
        data_ov000_021b4d14++;
        *b = 0;
    }
    return a;
}

void func_ov000_0218b148(SbServer *e, s8 *v1) {
    s8 *a;
    s8 *b;
    a = func_ov000_0218b19c(v1 + 1, 0x5c);
    while (a != NULL) {
        b = func_ov000_0218b19c(NULL, 0x5c);
        if (b == NULL) {
            b = data_ov000_021b21c4;
        }
        if (func_ov000_0218b1e0((const char *) a) != 0) {
            SbServerSetValue(e, (const char *) a, (const char *) b);
        }
        a = func_ov000_0218b19c(NULL, 0x5c);
    }
}

void func_ov000_0218b010(SbServer *e, s8 *v1, s32 n) {
    Unk0218b010 t;
    s8 *s;
    s8 *p;
    s8 *v;
    s32 a;
    s32 i;
    s32 b;
    s32 c;
    s32 d;
    s32 f;
    u16 w;
    while (*v1 != 0) {
        f = func_ov000_0218d0c8(v1, n);
        if (f < 0) {
            return;
        }
        p = v1;
        v1 += f;
        n -= f;
        f = func_ov000_0218d0c8(v1, n);
        if (f < 0) {
            return;
        }
        v = v1;
        v1 += f;
        n -= f;
        SbServerSetValue(e, (const char *) p, (const char *) v);
    }
    v1++;
    n--;
    for (i = 0; i < 2; i++) {
        if (n < 2) {
            return;
        }
        __memcpy(t.mUnk_00, v1, 2);
        w = *(u16 *) t.mUnk_00;
        *(u16 *) t.mUnk_00 = ((w >> 8) & 0xff) | ((w << 8) & 0xff00);
        v1 += 2;
        n -= 2;
        s = v1;
        a = 0;
        while (*v1 != 0) {
            f = func_ov000_0218d0c8(v1, n);
            if (f < 0 || f > 100) {
                return;
            }
            a++;
            v1 += f;
            n -= f;
        }
        v1++;
        n--;
        b = 0;
        while (b < *(u16 *) t.mUnk_00) {
            p = s;
            c = 0;
            while (c < a) {
                d = func_ov000_0218d0c8(v1, n);
                if (d < 0) {
                    return;
                }
                sprintf(t.mUnk_02, data_ov000_021b21bc, p, b);
                SbServerSetValue(e, t.mUnk_02, (const char *) v1);
                v1 += d;
                n -= d;
                p += strlen((const char *) p) + 1;
                c++;
            }
            b++;
        }
    }
}

u32 func_ov000_0218afd4(const s8 *v1, u32 v2) {
    s32 c;
    u32 a;
    a = 0;
    c = *v1;
    while (c != 0) {
        if (c >= 0 && c < 0x80) {
            c = data_0215d184[c];
        }
        a *= 0x9ccf9319;
        a += c;
        v1++;
        c = *v1;
    }
    return a % v2;
}

void func_ov000_0218afb8(u32 *a) {
    func_ov000_0218d0e4((u32) (0), (u32) (*a));
    func_ov000_0218d0e4((u32) (0), (u32) (a[1]));
    return;
}

u32 func_ov000_0218afac(Unk0218afac *entry, u32 modulus) {
    return func_ov000_0218afd4(entry->mName, modulus);
}

s32 func_ov000_0218afa0(const char *const *first, const char *const *second) {
    return func_02142368(*first, *second);
}

u32 func_ov000_0218af9c(SbServer *a) {
    return a->mPing;
}

SbServer *func_ov000_0218af28(SbServerList *a, u32 b, u16 c) {
    SbServer *p;
    p = func_ov000_021a3690(0x24);
    if (p == NULL) {
        return NULL;
    }
    p->mKeyValues =
        HashtableCreate(8, 8, 4, (s32(*)(void *, s32)) func_ov000_0218afac,
                        (s32(*)(void *, void *)) func_ov000_0218afa0, (void (*)(void *)) func_ov000_0218afb8);
    if (p->mKeyValues == NULL) {
        func_ov000_021a3668(p);
        return NULL;
    }
    p->mUnk_14 = 0;
    p->mUnk_15 = 0;
    p->mUnk_20 = NULL;
    p->mPing = 0;
    p->mUnk_10 = 0;
    p->mUnk_00 = b;
    p->mUnk_04 = c;
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    return p;
}

void func_ov000_0218af24(SbServer *a, s32 b) {
    a->mUnk_15 = b;
    return;
}

void func_ov000_0218af1c(SbServer *a, u32 b, u16 c) {
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    return;
}

void func_ov000_0218af18(SbServer *a, u32 b) {
    a->mUnk_10 = b;
    return;
}

void func_ov000_0218af14(SbServer *a, u8 b) {
    a->mUnk_14 = b;
    return;
}

u8 func_ov000_0218af10(SbServer *a) {
    return a->mUnk_14;
}

u32 func_ov000_0218aefc(SbServer *a) {
    if (a == *(SbServer **) &data_ov000_021b4d1c) {
        return 1;
    }
    return 0;
}

void func_ov000_0218aedc(Unk0218ae68 *a, SbServer *b) {
    if (a->mUnk_04 != NULL) {
        a->mUnk_04->mUnk_20 = b;
    }
    a->mUnk_04 = b;
    b->mUnk_20 = NULL;
    if (a->mUnk_00 == NULL) {
        a->mUnk_00 = b;
    }
    a->mUnk_08 = a->mUnk_08 + 1;
    return;
}

void func_ov000_0218aec4(Unk0218ae68 *a, SbServer *b) {
    b->mUnk_20 = a->mUnk_00;
    a->mUnk_00 = b;
    if (a->mUnk_04 == NULL) {
        a->mUnk_04 = b;
    }
    a->mUnk_08 = a->mUnk_08 + 1;
    return;
}

SbServer *func_ov000_0218aea4(Unk0218ae68 *a) {
    SbServer *v1;
    v1 = a->mUnk_00;
    if (v1 != NULL) {
        a->mUnk_00 = v1->mUnk_20;
        if (a->mUnk_00 == NULL) {
            a->mUnk_04 = NULL;
        }
        a->mUnk_08 = a->mUnk_08 + -1;
    }
    return v1;
}
