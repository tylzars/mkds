#include "00/code_0218b434.h"
#include "00/code_021a3000.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218b220.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218c958.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"

#include "code_0214177c.h"
#include "00/code_0218afd4.h"
#include "00/code_0218b708.h"
#include "00/code_0218a918.h"
#include "00/code_0218acb0.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218b000.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e49c.h"
#include "00/code_021a4b84.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "00/code_021a3690.h"

Unk0218b668 *func_ov000_0218b668(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, s32 g, UnkFunc *h, u32 l) {
    Unk0218b668 *p;
    if (g == 0 && data_ov000_021b4d28 != 1) {
        return 0;
    }
    p = func_ov000_021a3690(0x638);
    if (p == 0) {
        return 0;
    }
    p->mUnk_630 = h;
    p->mUnk_634 = l;
    p->mUnk_624 = 0;
    func_ov000_0218cfb8(&p->mUnk_04c, (const u8 *) a, (const u8 *) b, (const u8 *) c, d, g, func_ov000_0218b780, p);
    func_ov000_0218acf4((Unk0218a9bc *) p, e, f, g, func_ov000_0218b708, p);
    return p;
}

void func_ov000_0218b64c(Unk0218b668 *p) {
    func_ov000_0218c958(&p->mUnk_04c);
    func_ov000_0218acb0(p);
    func_ov000_021a3668(p);
}

s32 func_ov000_0218b590(Unk0218b668 *a, s32 b, u32 c, u8 *d, s32 e, const u8 *f, u32 g, u32 h) {
    u8 v1[256] = {0};
    s32 n;
    s32 i;
    s32 r;
    const u8 *s;
    n = 0;
    a->mUnk_620 = c;
    a->mUnk_040 = 0;
    for (i = 0; i < e; i++) {
        s = data_ov000_021b45bc[d[i]];
        if (n + (s32) strlen(s) + 1 >= 256) {
            break;
        }
        n += sprintf(v1 + n, data_ov000_021b21e8, s);
        func_ov000_0218a93c((u32) a, d[i]);
    }
    r = func_ov000_0218ca58(&a->mUnk_04c, v1, f, g, h);
    if (r == 0 && b == 0) {
        n = 10;
        while (a->mUnk_04c.mUnk_000 == 3 || (a->mUnk_010 > 0 && r == 0)) {
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
        func_ov000_0218b590((Unk0218b668 *) p0, (s32) p1, p2, (u8 *) p3, (s32) v2, (const u8 *) v4, (u32) 0x80u, v8);
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
    b = func_ov000_0218d300((u32) &p->mUnk_04c, a);
    if (b != -1) {
        func_ov000_0218d238(&p->mUnk_04c, b);
    }
}

s32 func_ov000_0218b4bc(struct Unk0218b668 *p) {
    func_ov000_0218a950((s32) p);
    return func_ov000_0218b8e4(&p->mUnk_04c);
}

void func_ov000_0218b4a4(struct Unk0218b668 *p) {
    func_ov000_0218c980(&p->mUnk_04c);
    func_ov000_0218acd8((s32) p);
}

void func_ov000_0218b48c(struct Unk0218b668 *p) {
    func_ov000_0218b4a4(p);
    func_ov000_0218d1a0((u32) &p->mUnk_04c);
}

u32 func_ov000_0218b480(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value3;
    value0 = (value0) + 76u;
    value3 = (u32) &func_ov000_0218d218;
    value0 = (u32) func_ov000_0218d218(value0, value1);
    return value0;
}

u32 func_ov000_0218b474(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value0 = (value0) + 76u;
    value3 = (u32) &func_ov000_0218d22c;
    value0 = (u32) func_ov000_0218d22c(value0);
    return value0;
}

void func_ov000_0218b464(Unk0218b668 *p0, u32 p1, void *p2, u32 p3) {
    func_ov000_0218d374(&p0->mUnk_04c, (s32) p1, (u32) p2, p3);
}

u32 func_ov000_0218b458(int a) {
    return *(u32 *) (a + 0x4ec);
}

u32 func_ov000_0218b44c(Unk0218afac *entry, u32 modulus) {
    return func_ov000_0218afd4(entry->mName, modulus);
}

s32 func_ov000_0218b440(const u8 *const *first, const u8 *const *second) {
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
