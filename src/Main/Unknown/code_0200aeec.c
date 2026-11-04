#include "Main/Unknown/code_0200aeec.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

#pragma thumb on

u32 func_0200aff8(Unk0200aeec *a) {
    if (a->mUnk_04_0 != 0) {
        return 1;
    }
    return 0;
}

void func_0200aeec(Unk0200aeec *a, void *b, void *c, u32 d) {
    Unk0200aeec_head *v1;
    u32 v2;
    u32 v3;
    Unk0200aeec *v4;
    Unk0200aeec *v5;
    v1 = data_0216fde0;
    if (func_0200b018() == 0) {
        IrqDisableLoopForever();
    }
    if (a->mUnk_04_0 != 0) {
        IrqDisableLoopForever();
    }
    if (d > 31) {
        v2 = ThreadGetSortKey(&v1->mUnk_00);
        if (d == 32) {
            if (v2 != 0) {
                d = v2 - 1;
            } else {
                d = 0;
            }
        } else if (d == 33) {
            if (v2 < 31) {
                d = v2 + 1;
            } else {
                d = 31;
            }
        } else if (d == 34) {
            d = v2;
        } else {
            d = 31;
        }
    }
    v3 = IrqDisable();
    a->mUnk_04_0 = 1;
    a->mUnk_04_1 = d;
    a->mUnk_08 = b;
    a->mUnk_0c = c;
    if (v1->mUnk_c0 == NULL) {
        if (a == &v1->mUnk_c4) {
            data_0216fde0 = NULL;
        }
        v1->mUnk_c0 = a;
        ThreadSetRunnable(&v1->mUnk_00);
    } else {
        v4 = v1->mUnk_c0;
        if (a == &v1->mUnk_c4) {
            if (v4->mUnk_00 != NULL) {
                do {
                    v4 = v4->mUnk_00;
                } while (v4->mUnk_00 != NULL);
            }
            v4->mUnk_00 = a;
            data_0216fde0 = NULL;
        } else if (v4->mUnk_04_1 > d) {
            v1->mUnk_c0 = a;
            a->mUnk_00 = v4;
        } else {
            while ((v5 = v4->mUnk_00) != NULL && v5->mUnk_04_1 <= d) {
                v4 = v5;
            }
            a->mUnk_00 = v5;
            v4->mUnk_00 = a;
        }
    }
    IrqRestore(v3);
}

#pragma thumb off
