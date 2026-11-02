#include "Main/Unknown/code_0202cb2c.h"

#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_0202cc44(s32 param_1, s32 param_2) {
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_00 = 10;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_0c = param_2;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_04 = data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_0c;
    data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_08 = data_02174e3c->mUnk_04c[param_1].mUnk_04.mUnk_04;
}

void func_0202cc18(s32 param_1, s32 param_2) {
    Unk02174e3c_4c_04 *entry;
    entry = &data_02174e3c->mUnk_04c[param_1].mUnk_04;
    entry->mUnk_04 = param_2;
    if (entry->mUnk_04 == entry->mUnk_08) {
        entry->mUnk_08 = entry->mUnk_0c;
        entry->mUnk_0c = entry->mUnk_04;
        entry->mUnk_00 = 10 - entry->mUnk_00;
    }
}

void func_0202cbf4(void) {
    s32 i;
    i = 0;
    do {
        func_0202cc44(i, 0);
        func_0202cc18(i, 1);
        i++;
    } while (i < 8);
}

#pragma thumb off

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
