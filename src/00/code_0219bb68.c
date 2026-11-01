#include "00/code_0219bb68.h"
#include "00/code_0219b5a8.h"
#include "00/code_0219b000.h"
#include "00/code_0219c39c.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "00/code_0219d630.h"
#include "00/code_021a15f8.h"
#include "00/code_021a1ae0.h"
#include "00/code_021988e8.h"
#include "00/code_0219b694.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"
#include "code_02139f70.h"
#include "00/code_0219b964.h"

s32 func_ov000_0219bdec(const s8 *a, void (*b)(s32, s32), void *c, void (*d)(u32, u8), void *e, void (*f)(u32, u32),
                        void *g) {
    Unk021b54c8 *p;
    u32 n;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 || (p = data_ov000_021b54c8)->mUnk_24 < 3 ||
        p->mUnk_24 == 4) {
        return 0;
    }
    if (a == 0 || *a == 0) {
        n = 0;
    } else {
        if (func_0213a434((const u8 *) a) < 0x20) {
            n = func_0213a434((const u8 *) a);
        } else {
            n = 0x1f;
        }
        func_0214d1fc(a, p->mUnk_34, n);
    }
    data_ov000_021b54c8->mUnk_34[n] = 0;
    data_ov000_021b54c8->mUnk_64 = b;
    data_ov000_021b54c8->mUnk_68 = c;
    func_ov000_0219b8a8(4);
    func_ov000_0219d770((s32) data_ov000_021b54c8->mUnk_84.mUnk_4c, (const u8 *) data_ov000_021b54c8->mUnk_84.mUnk_14c,
                        (void (*)(s32, u8, void *)) func_ov000_0219b694, 0, (void (*)(s32, u8, void *, void *)) d, e,
                        (void (*)(s32, s32, void *)) f, g);
    return 1;
}

void func_ov000_0219bd90(u32 a, void *b, void *c, u32 d, void *e, u32 f) {
    if (func_ov000_0219c39c() == 0 && data_ov000_021b54c8->mUnk_24 == 3) {
        func_ov000_0219b964();
        data_ov000_021b54c8->mUnk_6c = (void (*)(u32, u32, void *)) c;
        data_ov000_021b54c8->mUnk_70 = (void *) d;
        func_ov000_0219b8a8(5);
        func_ov000_021a260c((u8) (a - 1), b, (u32) func_ov000_0219b5a8, 0, (u32) e, f);
    }
}

void func_ov000_0219bc78(void *a, u32 b, u32 c, u32 d, void *e, u32 f, u32 g, u32 h) {
    u8 s[0x40];
    u8 t[0x40];
    u8 i;
    u8 j;
    u8 n;
    if (func_ov000_0219c39c() == 0 && data_ov000_021b54c8->mUnk_24 == 3) {
        func_ov000_0219b964();
        data_ov000_021b54c8->mUnk_6c = (void (*)(u32, u32, void *)) e;
        data_ov000_021b54c8->mUnk_70 = (void *) f;
        func_ov000_0219b8a8(5);
        if (a != 0) {
            func_ov000_021a2468(a, b, (u8) (c - 1), d, func_ov000_0219b5a8, 0, g, h);
            return;
        }
        i = 0;
        b = 0;
        for (; i < func_ov000_0219d660(); i++) {
            t[i] = func_ov000_021a3448(0x80) + 1;
            b++;
        }
        i = 0;
        for (; i < func_ov000_0219d660(); i++) {
            if (t[i] != 0) {
                j = 0;
                n = 0;
                for (; j < func_ov000_0219d660(); j++) {
                    if (i != j && t[i] < t[j]) {
                        n++;
                    }
                }
                s[n] = i;
            }
        }
        func_ov000_021a2468(s, b, (u8) (c - 1), d, func_ov000_0219b5a8, 0, g, h);
    }
}

s32 func_ov000_0219bbfc(void) {
    Unk021b54c8 *p;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 ||
        ((p = data_ov000_021b54c8)->mUnk_24 != 5 && p->mUnk_24 != 6)) {
        return -1;
    }
    if (p->mUnk_33c.mUnk_0d == 0) {
        func_ov000_0219d558(1, data_ov000_021b4054, 0);
        func_ov000_0219b110();
        func_ov000_0219b8a8(3);
        return 1;
    }
    p->mUnk_2d = 1;
    func_ov000_021988e8(data_ov000_021b54c8->mUnk_00);
    data_ov000_021b54c8->mUnk_2d = 0;
    return 0;
}

s32 func_ov000_0219bbac(s32 a) {
    u32 p;
    if (data_ov000_021b54c8 == 0 || func_ov000_0219c39c() != 0 ||
        (data_ov000_021b54c8->mUnk_24 != 5 && data_ov000_021b54c8->mUnk_24 != 6)) {
        return -1;
    }
    p = func_ov000_0219b9d4(a);
    if (p == 0) {
        return -2;
    }
    func_ov000_02198908((void *) p);
    return 0;
}

s32 func_ov000_0219bb68(void) {
    if (data_ov000_021b54c8 == 0) {
        return 0;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
        return func_ov000_021a15f8() + 1;
    }
    return func_ov000_021a160c() + 1;
}
