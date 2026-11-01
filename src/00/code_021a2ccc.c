#include "00/code_021a2ccc.h"
#include "00/code_0219b9c4.h"
#include "00/code_0219c39c.h"
#include "00/code_021a1000.h"
#include "00/code_021a2000.h"
#include "00/code_021a2f98.h"
#include "00/code_021a31e8.h"
#include "00/unk_021b5000.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"

void func_ov000_021a2dfc(int a, void *b, s32 c) {
    Unk021a2d68 *e = &data_ov000_021b5dd0->mUnk_000[a];
    u32 t[2];
    u16 n;
    e->mUnk_1e = func_ov000_021a2fb4(a);
    n = func_ov000_021a31e8(b);
    switch (n) {
        case 1:
            if (c != 8) {
                return;
            }
            func_0214d1fc(b, t, 8);
            e->mUnk_18 = t[0];
            e->mUnk_10 = 0;
            if (e->mUnk_04 != 0 && e->mUnk_08 >= e->mUnk_18) {
                e->mUnk_1d = 2;
            } else {
                e->mUnk_1d = 4;
            }
            break;
        case 2:
        case 3:
        case 4:
            e->mUnk_1d = 3;
            break;
    }
    e->mUnk_22 = n;
}

void func_ov000_021a2d68(int a, void *b, s32 c) {
    Unk021a2d68 *e = &data_ov000_021b5dd0->mUnk_000[a];
    s32 n;
    if (func_ov000_021a2fb4(a) == 2) {
        if (e->mUnk_10 + c > e->mUnk_08) {
            func_0200fd1c();
        }
        func_0214d1fc(b, e->mUnk_04 + e->mUnk_10, c);
    }
    e->mUnk_10 += c;
    n = e->mUnk_18;
    if (e->mUnk_10 == n) {
        e->mUnk_1d = 1;
        e->mUnk_10 = 0;
        e->mUnk_18 = 0;
        if (data_ov000_021b5dd0->mUnk_604 != 0) {
            data_ov000_021b5dd0->mUnk_604(a, e->mUnk_04, n);
        }
    }
    if (data_ov000_021b5dd0->mUnk_608 != 0 && e->mUnk_2c != 0) {
        e->mUnk_24 = func_0200f5ac();
    }
}

void func_ov000_021a2d38(u32 a, void *b, s32 c) {
    Unk021a2d68 *e = func_ov000_021a2fdc(a);
    e->mUnk_1d = e->mUnk_1e;
    switch (e->mUnk_22) {
        case 2:
        case 3:
        case 4:
            func_ov000_021a18e0(a, e->mUnk_22, b);
            break;
    }
}

s32 func_ov000_021a2d18(u32 a) {
    s32 n = func_ov000_021988dc(func_ov000_0219b9d4(a)) - 0x207;
    if (n <= 0) {
        n = 0;
    }
    return n;
}

s32 func_ov000_021a2ccc(void) {
    if (data_ov000_021b566c == 0 || data_ov000_021b566c->mUnk_1e8 == 0 || func_ov000_0219c39c() != 0) {
        return 0;
    }
    if (func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8) == 0) {
        return 1;
    }
    return 0;
}
