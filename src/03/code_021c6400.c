#include "03/code_021c6400.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf620.h"
#include "03/code_021bf83c.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021c5724.h"
#include "03/code_021c5944.h"
#include "03/code_021c5c68.h"
#include "03/code_021c6394.h"
#include "03/code_021c2120.h"
#include "03/code_021cc97c.h"
#include "03/code_021cd0d0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1c18.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3544.h"
#include "03/unk_021da000.h"
#include "code_02147cd8.h"
#include "code_0214b824.h"

static inline Unk021da104_04 *func_ov003_021c6400_inline(u32 a, u32 b) {
    return func_ov003_021d1c18(a, b);
}

// non-matching: same size; the original sets the byte offset register (adds r4, r5, #0) before loading the two table
// bytes in the first loop, ours after them (3 instructions in a different order).
void func_ov003_021c6400(void) {
    int n;
    int i;
    u32 j;
    u8 c;
    u8 d;
    n = data_ov003_021da1f4->mUnk_51;
    if (n > 5) {
        n = 5;
    }
    i = 0;
    if (n > 0) {
        c = data_ov003_021d6388[0];
        d = data_ov003_021d638c[0];
        do {
            data_ov003_021da1f4->mUnk_10[i] = func_ov003_021c6400_inline(0, c);
            data_ov003_021da1f4->mUnk_24[i] = func_ov003_021c6400_inline(0, d);
            i++;
        } while (i < n);
    }
    for (j = 0; j < 3; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d6388[j], (u8 *) data_ov003_021da1f4->mUnk_10[0]);
        data_ov003_021da1f4->mUnk_42[j] = data_ov003_021da1f4->mUnk_10[0]->mUnk_04 & 0x3ff;
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d638c[j], (u8 *) data_ov003_021da1f4->mUnk_24[0]);
        data_ov003_021da1f4->mUnk_48[j] = data_ov003_021da1f4->mUnk_24[0]->mUnk_04 & 0x3ff;
    }
    for (i = 0; i < n; i++) {
        Unk021da104_04 *q;
        q = data_ov003_021da1f4->mUnk_10[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
        q = data_ov003_021da1f4->mUnk_24[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
}

void func_ov003_021c6508(void) {
    int a;
    u32 b;
    b = 0;
    data_ov003_021da1f4->mUnk_40 = (data_ov003_021da1f4->mUnk_51 - 4) * 0x1c;
    if (data_ov003_021da1f4->mUnk_51 <= 4) {
        a = 0;
        data_ov003_021da1f4->mUnk_53 = 0;
    } else if (data_ov003_021da1f4->mUnk_51 <= 8) {
        a = 1;
        data_ov003_021da1f4->mUnk_53 = 0x1f;
    } else {
        a = 2;
        data_ov003_021da1f4->mUnk_53 = 0x37;
    }
    if (a != 0) {
        b = func_02147d30(*(u16 *) &data_ov003_021da1f0 * data_ov003_021da1f4->mUnk_53, data_ov003_021da1f4->mUnk_40);
    }
    func_ov003_021ccea4(a, 0x55, 0xec, 0x3f, b);
}

void func_ov003_021c6588(void) {
    u8 a[0x19] = "char/xb4ApListBack.nsc.l";
    u8 b[0x16] = "char/ybBgStep31.ncl.l";
    func_ov003_021bf620(data_ov003_021d7260, func_0214bbcc);
    data_ov003_021da1f4->mUnk_04 = func_ov003_021d14b8(func_ov003_021bf650(a), 0, 4);
    func_ov003_021cca30(data_ov003_021da1f4->mUnk_04);
    func_ov003_021cc9fc();
    data_ov003_021da1f4->mUnk_08 = func_ov003_021d14b8(func_ov003_021bf650(b), 0, 4);
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 3;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 2;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & ~3) | 3;
    *(vu16 *) 0x400000e = (*(vu16 *) 0x400000e & ~3) | 2;
}

void func_ov003_021c6668(void) {
    s32 a;
    data_ov003_021da1f4 = func_ov003_021d283c(0x5c, 4);
    func_ov003_021c20dc(&a, 0);
    if (a == 0) {
        data_ov003_021da1ec = 0;
        *(u16 *) &data_ov003_021da1f0 = 0;
    }
    data_ov003_021da1f4->mUnk_51 = func_ov003_021cd0d0((int *) data_ov003_021da1f4);
    func_ov003_021c6588();
    func_ov003_021bf854();
    func_ov003_021bf43c(0x80, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021c6508();
    func_ov003_021c6400();
    data_ov003_021da1f4->mUnk_0c = func_ov003_021d2288(0, 0);
    data_ov003_021da1f4->mUnk_3c = func_ov003_021d3544(1, func_ov003_021c5944, 0, 0x6e);
    func_ov003_021c5c68();
    func_ov003_021c590c();
    func_ov003_021c212c(func_ov003_021c63c4);
}
