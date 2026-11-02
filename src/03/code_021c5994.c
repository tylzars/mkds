#include "03/code_021c5994.h"
#include "03/code_021bf698.h"
#include "03/code_021c5724.h"
#include "03/code_021c5c68.h"
#include "03/unk_021da000.h"
#include "03/code_021ccd18.h"
#include "03/code_021d3254.h"
#include "03/code_021d3488.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"

void func_ov003_021c5994(u32 param_0) {
    int a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 + 4;
    a = func_02147cd8(*(u16 *) &data_ov003_021da1f0, 0x1c);
    if (a >= 4) {
        func_ov003_021c5aa4();
        return;
    }
    *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 - a;
    func_ov003_021c5c68();
    func_ov003_021cce58(
        func_02147d30(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40));
    func_ov003_021cce48();
    func_ov003_021c590c();
    data_ov003_021da1f4->mUnk_38 = 0;
    func_ov003_021d34c8(0, param_0);
}

void func_ov003_021c5a0c(u32 param_0) {
    int a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    if (*(u16 *) &data_ov003_021da1f0 > 4) {
        *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 - 4;
    } else {
        *(u16 *) &data_ov003_021da1f0 = 0;
    }
    a = func_02147cd8(*(u16 *) &data_ov003_021da1f0, 0x1c);
    if (a == 0x18) {
        func_ov003_021c5c68();
        return;
    }
    if (a > 0x18) {
        *(u16 *) &data_ov003_021da1f0 = *(u16 *) &data_ov003_021da1f0 + (0x1c - a);
        a = 0;
    }
    func_ov003_021c5aa4();
    if (a == 0) {
        func_ov003_021cce58(
            func_02147d30(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40));
        func_ov003_021cce48();
        func_ov003_021c590c();
        data_ov003_021da1f4->mUnk_38 = 0;
        func_ov003_021d34c8(0, param_0);
    }
}

void func_ov003_021c5aa4(void) {
    int a;
    int b;
    int i;
    a = 0x36 - func_02147cd8(*(u16 *) &data_ov003_021da1f0, 0x1c);
    b = data_ov003_021da1f4->mUnk_51;
    if (b > 5) {
        b = 5;
    }
    for (i = 0; i < b; i++, a += 0x1c) {
        Unk021da104_04 *p;
        p = data_ov003_021da1f4->mUnk_10[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a - 2) & 0xff) | 0xb30000;
        p = data_ov003_021da1f4->mUnk_24[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a + 1) & 0xff) | 0xd20000;
    }
    data_ov003_021da1f4->mUnk_56 = 1;
}

// non-matching: same instructions except register allocation and order; the original shifts the second parameter in
// place, keeps the 0xfffffc00 mask in r3 for both halfword updates and holds the address of data_ov003_021da1f4 in r4.
void func_ov003_021c5b34(int param_0, int param_1) {
    Unk021da104_04 *p;
    int m;
    if (param_0 < data_ov003_021da1f4->mUnk_51) {
        p = data_ov003_021da1f4->mUnk_10[param_1];
        m = param_0 * 0x2a;
        p->mUnk_04 = (p->mUnk_04 & 0xfc00) | data_ov003_021da1f4->mUnk_42[data_ov003_021da1f4->mUnk_00[m + 0x28]];
        p = data_ov003_021da1f4->mUnk_24[param_1];
        p->mUnk_04 =
            (p->mUnk_04 & 0xfc00) | data_ov003_021da1f4->mUnk_48[*(u16 *) (data_ov003_021da1f4->mUnk_00 + m + 0x26)];
    }
}

// non-matching: size 0xe8 against 0xd8; the original keeps the scaled second parameter in r7 and runs the copy loops in
// r2/r3, ours spills the scaled parameter to the stack and uses r5/r6/r7 for the loops.
void func_ov003_021c5b90(int param_0, int param_1) {
    u16 a[17];
    int b;
    int c;
    int d;
    int i;
    int j;
    int n;
    c = param_0 * 0x2a;
    b = func_ov003_021d3254(data_ov003_021da1f4->mUnk_00 + c, 0x20);
    d = param_1 * 0x1c;
    if (param_0 < data_ov003_021da1f4->mUnk_51) {
        if (b <= 0x10) {
            d += 6;
        }
        func_0214d168(a, 0, 0x22);
        if (b <= 0x10) {
            n = b;
        } else {
            n = 0x10;
        }
        {
            Unk021c5c68State *s = data_ov003_021da1f4;
            for (i = 0; i < n; i++) {
                a[i] = s->mUnk_00[c + i];
            }
        }
        func_ov003_021d2094(data_ov003_021da1f4->mUnk_0c, 0xa, d, 2, 0xa, a, 1);
        if (b > 0x10) {
            func_0214d168(a, 0, 0x22);
            b -= 0x10;
            {
                Unk021c5c68State *s = data_ov003_021da1f4;
                for (j = 0; j < b; j++) {
                    a[j] = s->mUnk_00[c + 0x10 + j];
                }
            }
            func_ov003_021d2094(data_ov003_021da1f4->mUnk_0c, 0xa, d + 0xc, 2, 0xa, a, 1);
        }
    }
}
