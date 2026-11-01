#include "00/code_0218cdd8.h"
#include "00/code_0218c45c.h"
#include "00/code_0218cd94.h"
#include "00/code_0218d000.h"
#include "00/code_0218d180.h"
#include "00/code_0218e368.h"
#include "00/code_0218e53c.h"
#include "00/code_0218e554.h"
#include "00/code_0218e8b4.h"
#include "00/code_021906e4.h"
#include "00/code_021919ac.h"
#include "00/code_021a4654.h"
#include "00/unk_021b2000.h"
#include "Main/Unknown/code_021384cc.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_0214177c.h"
#include "00/code_0218c958.h"
#include "00/code_0218e8c4.h"

static inline void func_ov000_0218ce14_inline(Unk0218cd94 *d, Unk0218cd94 *s) {
    u8 *p = (u8 *) d;
    u8 *q = (u8 *) s;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
}

void func_ov000_0218cfb8(Unk021b4d24 *p, const u8 *a, const u8 *b, const u8 *c, u32 d, s32 e, UnkFunc *f, void *g) {
    if (p == 0) {
        func_0213442c(data_ov000_021b2280, data_ov000_021b2218, 0, 0x11c);
    }
    if (e != 0 || data_ov000_021b4d28 == 1) {
        p->mUnk_000 = 1;
        func_ov000_0218d180((u32) p);
        func_ov000_0218b3f4(p);
        func_0213a2d0((char *) p->mUnk_00c, a);
        func_0213a2d0((char *) p->mUnk_030, b);
        func_0213a2d0((char *) p->mUnk_054, c);
        p->mUnk_488 = f;
        p->mUnk_48c = 0;
        if (f == 0) {
            func_0213442c(data_ov000_021b2290, data_ov000_021b2218, 0, 0x132);
        }
        p->mUnk_494 = g;
        p->mUnk_498 = (u32) data_ov000_021b2260;
        p->mUnk_4a0 = 0;
        p->mUnk_4b0 = -1;
        p->mUnk_07c = 0;
        p->mUnk_080 = 0;
        p->mUnk_008 = 0;
        p->mUnk_484 = -1;
        p->mUnk_480 = 0;
        p->mUnk_4a4 = 0;
        p->mUnk_4b8 = d;
        func_ov000_0218c45c(p, data_ov000_021b2260);
        p->mUnk_5cc = 0;
        func_021384cc(func_ov000_0218e8c4());
        func_ov000_0218e8b8();
    }
}

void func_ov000_0218cf30(Unk021b4d24 *p) {
    s32 n = p->mUnk_080;
    const u8 *s;
    const u8 *t;
    u8 *q;
    if (n > 0) {
        s = data_ov000_021b21ec;
        if ((u32) n > func_0213a434(s)) {
            q = p->mUnk_07c;
            t = data_ov000_021b21ec;
            if (func_0213a038(q, t, func_0213a434(t)) == 0) {
                func_ov000_0218c45c(p, q + func_0213a434(s));
                p->mUnk_488(p, 5, *(u32 *) data_ov000_021b4d1c, p->mUnk_494);
            }
        }
    }
    p->mUnk_488(p, 4, *(u32 *) data_ov000_021b4d1c, p->mUnk_494);
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

s32 func_ov000_0218ce14(Unk021b4d24 *p) {
    Unk0218ce14 v1;
    u8 v2[0x80];
    u32 h;
    Unk021a8f84 *e;
    h = func_ov000_0218cef4((s8 *) p->mUnk_00c, 0x14);
    if (data_ov000_021b4d20 != 0) {
        func_0213a2d0((char *) v2, data_ov000_021b4d20);
    } else {
        func_02135014(v2, data_ov000_021b2264, p->mUnk_00c, h);
    }
    v1.mUnk_01 = 2;
    v1.mUnk_02 = 0xee70;
    v1.mUnk_04 = func_ov000_0218e374((u32) v2);
    if (v1.mUnk_04 == -1) {
        e = func_ov000_021a8f84(v2);
        if (e == 0) {
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

void func_ov000_0218cdd8(u8 **a, const u8 *b, s32 *c) {
    u32 n;
    if (b == 0) {
        b = data_ov000_021b2260;
    }
    n = func_0213a434(b) + 1;
    func_02134eb8(*a, b, n);
    *c = *c + n;
    *a = *a + n;
}
