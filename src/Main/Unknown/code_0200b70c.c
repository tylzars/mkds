#include "Main/Unknown/code_0200b70c.h"
#include "Main/Unknown/code_0200b7e0.h"

#pragma thumb on

void func_0200b794(u32 a, void *b, u32 c) {
    switch (a) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            func_0200b850(0, b, c);
            break;
        case 3:
            func_0200b850(1, b, c);
            break;
    }
}

u32 func_0200b72c(void) {
    u16 a;
    a = func_02143280();
    if (a == 0x8000 || a == 0) {
        return 0;
    }
    data_0216fde8->mUnk_0580.mUnk_04++;
    do {
        data_0216fde8->mUnk_0580.mUnk_04++;
        if (data_0216fde8->mUnk_0580.mUnk_04 > 0x10) {
            data_0216fde8->mUnk_0580.mUnk_04 = 1;
        }
    } while ((a & (1 << (data_0216fde8->mUnk_0580.mUnk_04 - 1))) == 0);
    return 1;
}

void func_0200b70c(void) {
    data_0216fde8->mUnk_5ef8 = 0;
    data_0216fde8->mUnk_5efc = 1;
}

#pragma thumb off
