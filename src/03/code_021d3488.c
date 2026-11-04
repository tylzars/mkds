#include "03/code_021d1cd4.h"
#include "03/code_021d1d60.h"
#include "03/code_021d3488.h"
#include "03/code_021d3000.h"

#include "03/code_021d27d8.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "03/code_021d2e68.h"
#include "code_0200c914.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2ecc.h"
#include "03/unk_021d6000.h"

void func_ov003_021d35f4(void) {
    s32 i;
    u8 *b;

    data_ov003_021da32c = func_ov003_021d285c(0x78, 4);
    i = 0;
    b = data_ov003_021d67f0;
    do {
        data_ov003_021da32c[i].mUnk_34 = *b;
        data_ov003_021da32c[i].mUnk_38 = func_ov003_021d285c(*b * 0x14, 4);
        data_ov003_021da32c[i].mUnk_00 = func_ov003_021d1d60(*b, data_ov003_021da32c[i].mUnk_38, 0x14);
        data_ov003_021da32c[i].mResource = func_ov003_021d1d88(*b);
        data_ov003_021da32c[i].mUnk_08 = func_ov003_021d2ecc();
        data_ov003_021da32c[i].mUnk_0c.mUnk_10 = 0;
        data_ov003_021da32c[i].mUnk_20.mUnk_10 = 0xff;
        func_ov003_021d2e50(data_ov003_021da32c[i].mUnk_08, &data_ov003_021da32c[i].mUnk_0c);
        func_ov003_021d2e5c(data_ov003_021da32c[i].mUnk_08, &data_ov003_021da32c[i].mUnk_20);
        b++;
        i++;
    } while (i < 2);
}

void func_ov003_021d35c0(void) {
    int v1;
    int v2;
    v1 = 0;
    v2 = 0;
    do {
        func_ov003_021d2eb8(*(void **) ((u8 *) data_ov003_021da32c + v2 + 8));
        func_ov003_021d1d4c(*(void **) ((u8 *) data_ov003_021da32c + v2));
        v2 = v2 + 0x3c;
        v1 = v1 + 1;
    } while (2 > v1);
    func_ov003_021d2808(&data_ov003_021da32c);
    return;
}

void func_ov003_021d3558(int a) {
    Unk021d34e4 *b;
    s32 c;
    u32 d;

    b = data_ov003_021da32c[a].mUnk_0c.mUnk_04;
    if (b != &data_ov003_021da32c[a].mUnk_20) {
        do {
            b->mUnk_08(b, b->mUnk_0c);
            b = b->mUnk_04;
        } while (b != &data_ov003_021da32c[a].mUnk_20);
    }
    c = 0;
    if (data_ov003_021da32c[a].mUnk_34 > 0) {
        do {
            d = (u32) func_ov003_021d1cd4(data_ov003_021da32c[a].mResource);
            if (d == 0) {
                break;
            }
            func_ov003_021d3488(a, d);
            c++;
        } while (c < data_ov003_021da32c[a].mUnk_34);
    }
}

u32 func_ov003_021d3544(u32 p0, void *p1, void *p2, u32 p3) {
    return (u32) func_ov003_021d34e4(p0, (void (*)(Unk021d34e4 *, u32))(p1), (u32) p2, p3, (u32) 0x0u);
}

Unk021d34e4 *func_ov003_021d34e4(u32 a, void (*b)(Unk021d34e4 *a, u32 b), u32 c, u32 d, u8 e) {
    Unk021d34e4 *f;
    Unk021d34e4 *g;
    u32 h;

    f = func_ov003_021d1cd4((Unk021d1d88 *) data_ov003_021da32c[a].mUnk_00);
    f->mUnk_08 = b;
    f->mUnk_0c = c;
    f->mUnk_10 = d;
    f->mUnk_11 = e;
    h = InterruptEnableClearBits(1);
    g = data_ov003_021da32c[a].mUnk_0c.mUnk_04;
    while (1) {
        if (d < g->mUnk_10) {
            func_ov003_021d2e68((u32) g, (u32) f);
            break;
        }
        g = g->mUnk_04;
    }
    InterruptEnableSetBits(h);
    return f;
}

void func_ov003_021d34e0(Unk021d34e0 *a, UnkFunc *b) {
    a->mUnk_08 = b;
}

void func_ov003_021d34c8(u32 index, u32 value) {
    func_ov003_021d1d0c((Unk021d1d88 *) data_ov003_021da32c[index].mResource, (void *) value);
}

void func_ov003_021d34c0(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value3;
    value3 = (u32) &func_ov003_021d3488;
    func_ov003_021d3488(value0, value1);
    return;
}

void func_ov003_021d3488(int a, int b) {
    if (*(u8 *) (b + 0x11) != 0) {
        func_ov003_021d2808((s32 *) (b + 0xc));
    }
    func_ov003_021d2e90((u32) (b));
    func_ov003_021d1d0c((Unk021d1d88 *) (data_ov003_021da32c[a].mUnk_00), (void *) b);
}
