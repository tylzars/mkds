#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0204f198.h"
#include "Main/Unknown/code_0204f19c.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0204f4d0(const void *a, void *b, void **c, u32 d, s32 e) {
    u16 i;
    for (i = 0; i < 12; i++) {
        if (data_0217aa00->mUnk_16a0[i].mUnk_34 == 0) {
            func_0214d1fc(a, &data_0217aa00->mUnk_16a0[i].mUnk_34, 0x40);
            if (e != 0) {
                data_0217aa00->mUnk_16a0[i].mUnk_74 = data_0217aa00->mUnk_1d58;
                data_0217aa00->mUnk_16a0[i].mUnk_78 = 0;
                data_0217aa00->mUnk_16a0[i].mUnk_84_29 = 1;
                data_0217aa00->mUnk_16a0[i].mUnk_84_0 = d;
            } else {
                data_0217aa00->mUnk_16a0[i].mUnk_74 = 0;
                data_0217aa00->mUnk_16a0[i].mUnk_78 = 0;
                data_0217aa00->mUnk_16a0[i].mUnk_84_29 = 0;
                data_0217aa00->mUnk_16a0[i].mUnk_84_0 = d;
            }
            data_0217aa00->mUnk_16a0[i].mUnk_80 = b;
            data_0217aa00->mUnk_16a0[i].mUnk_84_30 = 1;
            data_0217aa00->mUnk_16a0[i].mUnk_7c = c;
            return;
        }
    }
}

void func_0204f468(void) {
    data_0217aa00->mUnk_000c = 0x28;
    data_0217aa00->mUnk_0010 = 1;
    func_02006aac(0x192, 0xe, func_0204f19c);
    data_0217aa00->mUnk_1e42 = 0;
    data_0217aa00->mUnk_1e44 &= ~1;
    data_0217aa00->mUnk_0454 |= 0x200;
    data_0217aa00->mUnk_0010 = 0;
}

void func_0204f408(void) {
    data_0217aa00->mUnk_000c = 0x29;
    data_0217aa00->mUnk_0010 = 1;
    func_02006a10(func_0204f198);
    data_0217aa00->mUnk_1e42 = 0;
    data_0217aa00->mUnk_1e44 &= ~1;
    data_0217aa00->mUnk_0454 |= 0x200;
    data_0217aa00->mUnk_0010 = 0;
}

void func_0204f33c(void *a) {
    s32 i;
    data_0217aa00->mUnk_1e28 = 0x1c0;
    data_0217aa00->mUnk_1e20 = func_02036b74(a, data_0217aa00->mUnk_1e28, 0x20);
    data_0217aa00->mUnk_1e2c = 0x400;
    data_0217aa00->mUnk_1e24 = func_02036b74(a, data_0217aa00->mUnk_1e2c, 0x20);
    for (i = 0; i < 8; i++) {
        data_0217aa00->mUnk_1da0[i] = func_02036b74(a, 0x28, 0x20);
        data_0217aa00->mUnk_1de0[i] = func_02036b74(a, 4, 0x20);
    }
    data_0217aa00->mUnk_1e30 = (s32) func_02036b74(a, 0x192, 0x20);
    data_0217aa00->mUnk_1e48 = func_02036b74(a, 0x20, 0x20);
}

void func_0204f240(void *a, s32 b) {
    Unk0217aa00_16a0_view *v = &data_0217aa00->mUnk_16a0_view;
    s32 i;
    for (i = 0; i < 12; i++) {
        v->mUnk_000[i].mUnk_34 = 0;
        v->mUnk_000[i].mUnk_74 = NULL;
        v->mUnk_000[i].mUnk_78 = NULL;
        v->mUnk_000[i].mUnk_84_29 = 0;
        v->mUnk_000[i].mUnk_84_0 = 0;
    }
    v->mUnk_660 = b;
    v->mUnk_798 = 0;
    v->mUnk_79c = 0;
    v->mUnk_7a0 = 0;
    v->mUnk_7a2 = 0;
    v->mUnk_7a4 = 0;
    v->mUnk_7a5 = -1;
    v->mUnk_7a6 = 0;
    v->mUnk_6b4 = 0;
    v->mUnk_668 = 0;
    v->mUnk_66a = -1;
    v->mUnk_6b8 = NULL;
    if (b == 2) {
        func_0204f33c(a);
        func_0204ee64();
    } else if (b == 1) {
        data_0217aa00->mUnk_1d58 = func_02036b74(a, 0x4b000, 0x20);
    }
}

#pragma thumb off
