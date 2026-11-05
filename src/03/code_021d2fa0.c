#include "03/code_021d2fa0.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d1d60.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214b824.h"
#include "code_0214d018.h"

void func_ov003_021d31b0(void) {
    s32 i;

    data_ov003_021da2f4 = func_ov003_021d283c(0x340, 4);
    for (i = 0; i < 2; i++) {
        data_ov003_021da2f4[i].mUnk_19c = func_ov003_021d1d60(0x20, &data_ov003_021da2f4[i], 0xc);
        data_ov003_021da2f4[i].mUnk_198 = func_ov003_021d2ecc();
        data_ov003_021da2f4[i].mUnk_180.mUnk_08 = 0x300;
        data_ov003_021da2f4[i].mUnk_18c.mUnk_08 = 0x400;
        func_ov003_021d2e50(data_ov003_021da2f4[i].mUnk_198, &data_ov003_021da2f4[i].mUnk_180);
        func_ov003_021d2e5c(data_ov003_021da2f4[i].mUnk_198, &data_ov003_021da2f4[i].mUnk_18c);
    }
}

Unk021d309c *func_ov003_021d309c(u32 a, s32 b, s32 c, u32 *d) {
    Unk021d309c *e;
    Unk021d309c *f;
    Unk021d309c *g;
    Unk021d31b0 *k;
    s32 h;
    s32 l;
    u32 i;

    e = func_ov003_021d1cd4(data_ov003_021da2f4[a].mUnk_19c);
    l = (b + 3 & ~3) >> 2;
    e->mUnk_0a = l;
    i = InterruptEnableClearBits(1);
    if (c != 0) {
        k = data_ov003_021da2f4;
        f = &k[a].mUnk_180;
        if (f != &k[a].mUnk_18c) {
            do {
                g = f->mUnk_04;
                h = f->mUnk_08 + f->mUnk_0a;
                if (h + l <= g->mUnk_08) {
                    e->mUnk_08 = h;
                    func_ov003_021d2e68((u32) g, (u32) e);
                    break;
                }
                f = g;
            } while (f != &k[a].mUnk_18c);
        }
        if (f == &data_ov003_021da2f4[a].mUnk_18c) {
            IrqDisableLoopForever();
        }
    } else {
        k = data_ov003_021da2f4;
        f = &k[a].mUnk_18c;
        if (f != &k[a].mUnk_180) {
            do {
                g = f->mUnk_00;
                h = f->mUnk_08 - l;
                if (h >= g->mUnk_08 + g->mUnk_0a) {
                    e->mUnk_08 = h;
                    func_ov003_021d2e68((u32) f, (u32) e);
                    break;
                }
                f = g;
            } while (f != &k[a].mUnk_180);
        }
        if (f == &data_ov003_021da2f4[a].mUnk_180) {
            IrqDisableLoopForever();
        }
    }
    *d = e->mUnk_08;
    InterruptEnableSetBits(i);
    return e;
}

void func_ov003_021d305c(u32 c) {
    Unk021d31b0 *a;
    s32 b = 0;

    func_ov003_021d2e90(c);
    a = data_ov003_021da2f4;
    if (c >= (u32) a + 0x1a0) {
        b = 1;
    }
    func_ov003_021d1d0c(a[b].mUnk_19c, (void *) c);
}

void func_ov003_021d2fdc(void) {
    Unk021d2fa0 *a = func_ov003_021d285c(0x80c, 4);
    vu32 b;
    s32 i;

    data_ov003_021da2f0 = a;
    b = 0x200;
    MemFillWordsByBlock(b, a, 0x800);
    for (i = 0; i < 2; i++) {
        data_ov003_021da2f0->mUnk_800[i] = func_ov003_021d1d60(0x40, data_ov003_021da2f0->mUnk_000[i], 8);
    }
    data_ov003_021da2f0->mUnk_808 = func_ov003_021d3544(1, func_ov003_021d2fa0, NULL, 200);
}

void func_ov003_021d2fa0(void) {
    func_0200ee74((u8 *) data_ov003_021da2f0, 0x800);
    func_0214bfcc(data_ov003_021da2f0->mUnk_000[0], 0, 0x400);
    func_0214bf64(data_ov003_021da2f0->mUnk_000[1], 0, 0x400);
}
