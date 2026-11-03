#include "Main/Unknown/code_0202a360.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02122734.h"
#include "00/code_02182fdc.h"

#pragma opt_rebuildconditionals off

#pragma thumb on

static inline Unk0217aa1c_144_00 *func_0202a360_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

u32 func_0202a360(void) {
    Unk021759c0 *d;
    s32 n;
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
    Unk0217aa1c_00 *p;

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
                r4 = func_0202a360_inline(0)->mUnk_02;
                r5 = func_0202a360_inline(1)->mUnk_02;
                break;
            case 2:
                r4 = func_0202a360_inline(0)->mUnk_00;
                r5 = func_0202a360_inline(1)->mUnk_00;
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
            p = &data_0217aa1c->mUnk_000[y][func_0205dc7c(x)];
            a[i] = p->mUnk_00;
        } else {
            x = func_0205dc7c((u16) i);
            y = func_0205db28();
            p = &data_0217aa1c->mUnk_000[y][func_0205dc7c(x)];
            a[i] = p->mUnk_05;
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
