#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_0214c778.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020ae6d4(void *c, void *d) {
    Unk020ae630 *a = c;
    Unk020ae630 *b = d;

    if (a != NULL) {
        a->mUnk_400 = 0;
        a->mUnk_402 = 0;
        func_0214cc04(3, a, 0xc0, 0x400);
    }
    if (b != NULL) {
        b->mUnk_400 = 0;
        b->mUnk_402 = 0;
        func_0214cc04(3, b, 0xc0, 0x400);
    }
}

void func_020ae6ac(void *c, void *d) {
    Unk020ae630 *a = c;
    Unk020ae630 *b = d;

    if (a != NULL) {
        a->mUnk_400 = 0;
        a->mUnk_402 = 0;
    }
    if (b != NULL) {
        b->mUnk_400 = 0;
        b->mUnk_402 = 0;
    }
}

void func_020ae630(void *c, void *d) {
    Unk020ae630 *a = c;
    Unk020ae630 *b = d;
    u16 n;
    s32 i;

    if (a != NULL) {
        n = a->mUnk_400;
        func_0200ee74(a, 0x400);
        for (i = 0; i < 0x80 - n; i++) {
            a->mUnk_00[n + i].mUnk_00 = (a->mUnk_00[n + i].mUnk_00 & 0xfe00ffff) | 0x1800000;
            a->mUnk_00[n + i].mUnk_00_0 = 0xe0;
        }
    }
    if (b != NULL) {
        n = b->mUnk_400;
        func_0200ee74(b, 0x400);
        for (i = 0; i < 0x80 - n; i++) {
            b->mUnk_00[n + i].mUnk_00 = (b->mUnk_00[n + i].mUnk_00 & 0xfe00ffff) | 0x1800000;
            b->mUnk_00[n + i].mUnk_00_0 = 0xe0;
        }
    }
}

#pragma thumb off
