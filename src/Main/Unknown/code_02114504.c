#include "Main/Unknown/code_02114504.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

u16 func_02114584(u16 a) {
    Unk02116a4c w;

    func_021142d4((u8) a, &w);
    return w.mUnk_00 * 0x1a0 + w.mUnk_01 * 32 + w.mUnk_02;
}

void func_02114504(s32 a, u16 b) {
    s32 i;
    s32 j;
    s32 n;
    u16 p;
    s32 e;
    Unk0217d34c_04 t;
    u32 m;
    u16 v;
    Unk0217d34c_04 *q;

    p = 0;
    n = a + b;
    e = n - 1;
    for (i = a; i < e; i++) {
        m = 0;
        for (j = i; j < n; j++) {
            v = func_02114584(j);
            if (m < v) {
                m = v;
                p = j;
            }
        }
        for (j = p; j > i; j--) {
            q = data_0217d34c->mUnk_04 + j - 1;
            t = *q;
            *q = data_0217d34c->mUnk_04[j];
            data_0217d34c->mUnk_04[j] = t;
        }
    }
}

#pragma thumb off
