#include "Main/Unknown/code_0202cb2c.h"
#include "Main/Unknown/code_0202cbf4.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_0202cba4(void) {
    s32 i;
    Unk02174e3c_4c_04 *p;
    for (i = 0; i < 8; i++) {
        p = &data_02174e3c->mUnk_04c[i].mUnk_04;
        if (p->mUnk_00 < 10) {
            p->mUnk_00++;
        } else if (p->mUnk_04 != p->mUnk_0c) {
            p->mUnk_00 = 0;
            p->mUnk_08 = p->mUnk_0c;
            if (p->mUnk_04 > p->mUnk_0c) {
                p->mUnk_0c++;
            } else {
                p->mUnk_0c--;
            }
        }
    }
}

void func_0202cb68(s32 a) {
    switch (data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04) {
        case 0:
            func_0202cc18(a, 1);
            break;
        case 3:
            func_0202cc18(a, 2);
            break;
    }
}

void func_0202cb2c(s32 a) {
    switch (data_02174e3c->mUnk_04c[a].mUnk_04.mUnk_04) {
        case 1:
            func_0202cc18(a, 0);
            break;
        case 2:
            func_0202cc18(a, 3);
            break;
    }
}

#pragma thumb off
