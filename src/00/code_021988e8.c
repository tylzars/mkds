#include "00/code_021988e8.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e49c.h"
#include "00/code_02198748.h"
#include "00/code_02198a8c.h"

void func_ov000_021988e8(Unk02197e8c *a) {
    func_ov000_0218dddc(a->mUnk_0c, (void (*)(void *, void *)) func_ov000_021988fc, 0);
}

void func_ov000_021988fc(Unk02197fe8 **a) {
    func_ov000_02198908(*a);
}

void func_ov000_02198908(Unk02197fe8 *a) {
    func_ov000_02198548(a, 1);
}

void func_ov000_02198914(Unk02197fe8 *a, u8 *b, int c, int d) {
    if (a->mUnk_0c == 5) {
        func_ov000_0219a61c((const u8 **) &b, &c);
        if (func_ov000_0218dc44((u32 *) a->mUnk_98) != 0) {
            func_ov000_02198098(a, 0, (s32) b, (void *) c, d);
            return;
        }
        func_ov000_02198ad8(a, b, c, d);
    }
}

int func_ov000_02198968(void *a, Unk02197fe8 **b, u32 c, void *d, int e, u32 f, int g, int h) {
    Unk02197fe8 *m;
    u32 i;
    u16 j;
    u32 k;
    int l;
    int n;
    if (func_ov000_0219a654((const u8 *) c, &i, &j) == 0 || i == 0 || (k = j) == 0) {
        return 4;
    }
    if (((((i << 24) & 0xff000000) | (((i << 8) & 0xff0000) | (((i >> 24) & 0xff) | ((i >> 8) & 0xff00)))) &
         0xe0000000) == 0xe0000000) {
        return 4;
    }
    l = func_ov000_0219885c(a, &m, i, k);
    if (l != 0) {
        return l;
    }
    m->mUnk_20 = f;
    n = func_ov000_021987c8(m, d, e, (Unk02198778 *) g);
    if (n != 0) {
        func_ov000_0219a220(m);
        return n;
    }
    if (h == 0) {
        if (b != 0) {
            *b = m;
        }
        return 0;
    }
    m->mUnk_24++;
    do {
        func_ov000_02198a8c(a);
        l = m->mUnk_0c >= 5 ? 1 : 0;
        if (l == 0) {
            func_ov000_0218e8bc(1);
        }
    } while (l == 0);
    m->mUnk_24--;
    if (m->mUnk_0c == 5) {
        *b = m;
    }
    return m->mUnk_18;
}

void func_ov000_02198a74(Unk02197fe8 *a, void *b, u32 c) {
    func_ov000_02198748(a, b, c);
}

int func_ov000_02198a7c(Unk02197fe8 *a, Unk02198778 *b) {
    return func_ov000_02198778(a, b);
}
