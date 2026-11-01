#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d5000.h"

u16 func_020d3c44(void) {
    data_0217b4c4++;
    if (data_0217b4c4 > 0x3e) {
        data_0217b4c4 = data_0217b4c8;
    }
    return data_0217b4c4;
}

u16 func_020d3c2c(void) {
    return data_0217b4d0++;
}

#pragma thumb on

u16 func_020d3bf8(u32 param_1) {
    s32 i;
    u16 a;
    a = 0;
    i = 0;
    for (; i < data_0217b4f0->mUnk_004; i++) {
        if (param_1 == data_0217b4f0->mUnk_000[i]->mUnk_00) {
            a++;
        }
    }
    return a;
}

void func_020d3b74(void) {
    s32 i;
    s32 n;
    Unk020e71a0 **p;
    Unk020e71a0 *q;
    n = data_0217b4f0->mUnk_004;
    p = data_0217b4f0->mUnk_000;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mUnk_02 & 0x80) {
            if (q->mUnk_02 & 0x100) {
                q->mUnk_02 &= ~0x80;
            } else {
                q->mUnk_02 &= ~0xf000;
                q->mUnk_02 |= (q->mUnk_02 & 0xf) << 12;
                q->mUnk_02 |= data_021568dc;
                if (q->mUnk_64 != -1) {
                    func_020d5114(q->mUnk_64);
                }
            }
        }
        p++;
    }
}

void func_020d3b10(void) {
    s32 i;
    s32 n;
    Unk020e71a0 **p;
    Unk020e71a0 *q;
    n = data_0217b4f0->mUnk_004;
    p = data_0217b4f0->mUnk_000;
    for (i = 0; i < n; i++) {
        q = *p;
        if (q->mUnk_02 & 0x80) {
            q->mUnk_02 &= ~0x80;
            q->mUnk_02 &= ~0xf;
            q->mUnk_02 |= (q->mUnk_02 & 0xf000) >> 12;
            if (q->mUnk_64 != -1) {
                func_020d50ec(q->mUnk_64);
            }
        }
        p++;
    }
}

#pragma thumb off
