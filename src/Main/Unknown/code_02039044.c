#include "Main/Unknown/code_02039044.h"
#include "code_0200c894.h"
#include "code_02148950.h"
#include "code_021488e8.h"

void func_02039044(void) {
    func_0200c894(1, 1);
    func_021489c4();
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 | 0x10000;
}

// non-matching: instructions identical; only the registers of the constants differ: the original keeps 0x10 in ip, 0 in
// r4 and 1 in lr, here they are in r4, lr and ip.
void func_0203907c(void) {
    Unk021755a8 *p = &data_021755b4;
    Unk021755a8 *q = &data_021755a8;
    s32 a;
    p->mUnk_08 = 0x10;
    a = p->mUnk_08;
    p->mUnk_00 = 0;
    p->mUnk_02 = 1;
    p->mUnk_04 = 0;
    p->mUnk_06 = 0;
    q->mUnk_00 = 0;
    q->mUnk_02 = 1;
    q->mUnk_04 = 0;
    q->mUnk_06 = 0;
    q->mUnk_08 = 0x10;
    func_02148908((u16 *) 0x400006c, a);
    func_02148908((u16 *) 0x400106c, q->mUnk_08);
}

void func_020390f0(Unk021755a8 *a) {
    switch (a->mUnk_00) {
        case 0:
            break;
        case 1:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 2;
                a->mUnk_08 = 0;
            } else {
                a->mUnk_08 = 0x10 - (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
        case 2:
            a->mUnk_08 = 0;
            break;
        case 3:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 0;
                a->mUnk_08 = 0x10;
            } else {
                a->mUnk_08 = (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
    }
}
