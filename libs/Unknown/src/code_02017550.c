#include "code_02017550.h"
#include "code_020172d0.h"
#include "code_0201750c.h"

Unk02017584 *func_02017640(Unk02017328 *a, u32 b) {
    Unk02017584 *p;
    Unk02017584 *r;

    p = func_0201733c(a, 0);
    while (p != 0) {
        if (p->mUnk_18 <= b && b < p->mUnk_1c) {
            r = func_02017640(&p->mUnk_0c, b);
            if (r == 0) {
                r = p;
            }
            return r;
        }
        p = func_0201733c(a, p);
    }
    return 0;
}

Unk02017328 *func_02017614(u32 a) {
    Unk02017328 *l;
    Unk02017584 *p;

    l = &data_02173268;
    p = func_02017640(l, a);
    if (p != 0) {
        l = &p->mUnk_0c;
    }
    return l;
}

void func_02017584(Unk02017584 *a, u32 b, u32 c, u32 d, u16 e) {
    a->mUnk_00 = b;
    a->mUnk_18 = c;
    a->mUnk_1c = d;
    a->mUnk_20 = 0;
    a->mUnk_20 &= ~0xff;
    a->mUnk_20 |= e & 0xff;
    func_02017538(&a->mUnk_0c, 4);
    if (data_02173264 == 0) {
        func_02017538(&data_02173268, 4);
        data_02173264 = 1;
    }
    func_020174a4(func_02017614((u32) a), a);
}

void func_02017568(Unk02017584 *a) {
    func_02017354(func_02017614((u32) a), a);
}

void *func_02017550(void *a) {
    return func_02017640(&data_02173268, (u32) a);
}
