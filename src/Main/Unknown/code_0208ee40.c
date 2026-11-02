#include "Main/Unknown/code_0208ee40.h"
#include "Main/Unknown/code_02017000.h"

#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020172d0.h"

void func_0208f0a0(void) {
    void *p;
    p = func_0201733c(&data_0217b08c->mUnk_00, 0);
    while (p != 0) {
        func_0208e99c(p);
        p = func_0201733c(&data_0217b08c->mUnk_00, p);
    }
}

void func_0208ee7c(const Unk02012f58 *a) {
    Unk0208ec64 *p;
    Unk0208ec64_08 *r;
    Unk0208ec64_08 *q;
    s32 v;
    u8 f;
    s32 g;

    f = data_021663d8;
    g = 0;
    p = func_0201733c(&data_0217b08c->mUnk_00, 0);
    if (p == 0) {
        return;
    }
    do {
        if (g == 0) {
            *(u16 *) 0x4000060 = (*(u16 *) 0x4000060 & ~0x3000) | 8;
            *(u32 *) 0x40004c4 = 0x7c004210;
            *(u32 *) 0x40004c0 = 0x42100000;
            *(u32 *) 0x4000440 = 3;
            *(u32 *) 0x4000454 = 0;
            *(u32 *) 0x4000440 = 2;
            *(u32 *) 0x40004a8 = data_021663f4.mUnk_00;
            *(u32 *) 0x40004ac = data_021663f4.mUnk_18 >> (4 - ((data_021663f4.mUnk_00 >> 26 & 7) == 2));
            g = 1;
        }
        *(u32 *) 0x4000480 = 0x7fff;
        q = func_0201733c(&p->mUnk_08, 0);
        if (q != 0 && data_021663e8 != 0) {
            r = func_0201733c(&p->mUnk_08, 0);
            if (r != 0) {
                do {
                    v = 0x1f - q->mUnk_0c * data_021663dc;
                    *(u32 *) 0x40004a4 = (u32) f << 24 | (data_0217b08c->mUnk_34 | 0xc0) | v << 16;
                    func_0208e82c(a, q, r, &data_021663f4);
                    q = r;
                    r = func_0201733c(&p->mUnk_08, r);
                } while (r != 0);
            }
        }
        f = f + 1;
        p = func_0201733c(&data_0217b08c->mUnk_00, p);
    } while (p != 0);
}

void func_0208ee40(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) * (const u32 *) ((value1) + (20));
    value2 = (u32) * (const u32 *) ((value1) + (28));
    value1 = 0u;
    *(u32 *) ((value0) + (8)) = value2;
    *(u16 *) ((value0) + (12)) = (u16) value1;
    value1 = (u32) * (const u32 *) ((value3) + (0));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (16)) = value1;
    value1 = (u32) * (const u32 *) ((value3) + (4));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (20)) = value1;
    value1 = (u32) * (const u32 *) ((value3) + (8));
    value1 = ((u32) ((s32) value1 >> 4));
    *(u32 *) ((value0) + (24)) = value1;
}
