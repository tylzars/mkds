#include "Main/Unknown/code_0202a360.h"

#pragma thumb on

// non-matching: 90.7%; same control flow, register and stack-offset differences in the array loops
u32 func_0202a360(void) {
    Unk021759c0 *d;
    u32 n;
    s32 v;
    s32 a[8];
    s32 b;
    s32 i;
    s32 m;
    s32 e;
    s32 x;
    s32 y;
    s32 r4;
    s32 r5;
    s32 r6;
    s32 w;

    d = data_021759c0;
    n = d->mUnk_3d0;
    if (d->mUnk_08 == 0) {
        if (data_0217b488->mUnk_7c < 3) {
            return 0;
        }
        return 1;
    }
    switch (data_021759d0->mUnk_20) {
        case 0:
            v = 0;
            break;
        case 1:
        case 2:
            if (data_0217aa00->mUnk_0000 == 2) {
                w = data_0217aa00->mUnk_0432;
            } else {
                w = 0;
            }
            v = data_0217aa00->mUnk_1e52[(u16) w].mUnk_00;
            break;
        case 3:
            v = (u16) func_02122778(func_ov000_0219bb50());
            break;
    }
    if (data_021759c0->mUnk_58 != 0) {
        v = v * 0x30;
        r6 = *(s32 *) ((u8 *) data_021759c0 + v + 0x74);
        switch (data_021759c0->mUnk_1c) {
            case 1:
                r4 = data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[0].mUnk_02;
                r5 = data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[1].mUnk_02;
                break;
            case 2:
                r4 = data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[0].mUnk_00;
                r5 = data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[1].mUnk_00;
                break;
        }
        if (r4 == r5) {
            return 7;
        }
        if (r4 > r5) {
            if (r6 == 0) {
                return 5;
            }
            return 6;
        }
        if (r6 == 1) {
            return 5;
        }
        return 6;
    }
    i = 0;
    m = -1;
    e = 1;
    for (; i < n; i++) {
        if (data_021759d0->mUnk_20 == 3 || data_021759c0->mUnk_1c == 2) {
            x = func_0205dc7c((u16) i);
            y = func_0205db28();
            a[i] = data_0217aa1c->mUnk_000[y][func_0205dc7c(x)].mUnk_00;
        } else {
            x = func_0205dc7c((u16) i);
            y = func_0205db28();
            a[i] = data_0217aa1c->mUnk_000[y][func_0205dc7c(x)].mUnk_05;
        }
        if (m < a[i]) {
            m = a[i];
        }
    }
    for (i = 1; i < n; i++) {
        e = e & (a[0] == a[i]);
    }
    if (e != 0) {
        return 4;
    }
    if (m == a[v]) {
        return 2;
    }
    return 3;
}

#pragma thumb off
