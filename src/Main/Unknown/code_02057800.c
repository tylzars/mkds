#include "Main/Unknown/code_02057800.h"
#include "Main/Unknown/code_020578d0.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_0205786c(u32 a, u32 b, GhostRecord *c) {
    Unk021759d4 *d;
    u32 t;
    u32 n;
    u32 v1;
    u32 v2;
    void *v3;

    d = data_021759d4;
    if (d->mUnk_0c != 0) {
        if (a != 0) {
            t = 0;
            v1 = 0xe00;
            n = b * v1;
            v3 = d->mUnk_60;
            v2 = 0x47504b4e;
        } else {
            t = 0x1c000;
            v1 = 0x1000;
            n = b * v1;
            v3 = d->mUnk_60;
            v2 = 0x47444b4e;
        }
        d->mUnk_68 = c;
        func_0204b6f8(n + (t + 0xaf00), v3, v1, func_020578e8, v2);
    }
}

void func_02057800(u32 a, u32 b, GhostRecord *c) {
    void (*f)(u32, u32);
    Unk021759d4 *d;
    u32 t;
    u32 n;
    u32 v1;
    u32 v2;
    void *v3;

    d = data_021759d4;
    if (d->mUnk_0c != 0) {
        if (a != 0) {
            t = 0;
            v1 = 0xe00;
            n = b * v1;
            v3 = d->mUnk_60;
            v2 = 0x47504b4e;
            f = func_020578e8;
        } else {
            t = 0x1c000;
            v1 = 0x1000;
            n = b * v1;
            v3 = d->mUnk_60;
            v2 = 0x47444b4e;
            f = func_020578d0;
        }
        d->mUnk_68 = c;
        func_0204b6f8(n + (t + 0xaf00), v3, v1, f, v2);
    }
}

#pragma thumb off
