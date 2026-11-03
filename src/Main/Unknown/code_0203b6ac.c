#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203ba70.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467a0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200f5ac.h"
#include "code_02133048.h"
#include "code_0214d964.h"

#pragma thumb on

BOOL func_0203b96c(s32 a) {
    if (a == 9) {
        return FALSE;
    }
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (func_02056dec(0) != 0 || func_02056dec(1) != 0 || func_02056dec(2) != 0 || func_02056dec(3) != 0) {
                return TRUE;
            }
            break;
        case 3:
            if (func_02056dec(4) != 0 || func_02056dec(5) != 0 || func_02056dec(6) != 0 || func_02056dec(7) != 0) {
                return TRUE;
            }
            break;
        case 6:
            if (func_02056dec(8) != 0 || func_02056dec(9) != 0 || func_02056dec(10) != 0 || func_02056dec(11) != 0) {
                return TRUE;
            }
            break;
        case 7:
            if (func_02056dec(12) != 0 || func_02056dec(13) != 0 || func_02056dec(14) != 0 || func_02056dec(15) != 0) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

u32 func_0203b8e4(Unk020f41c4_B *a) {
    u8 n;
    u8 i;
    u16 k;
    u16 m;
    u32 v;

    n = 0;
    k = 0;
    for (i = 0; i < 8; i++) {
        if (func_0203b96c(i) != FALSE) {
            n++;
        }
    }
    if (n == 0) {
        v = 0;
    } else {
        a->mUnk_00 = _ll_mul(a->mUnk_08, a->mUnk_00) + a->mUnk_10;
        if (n == 0) {
            v = a->mUnk_00 >> 32;
        } else {
            v = (u64) (u32) (a->mUnk_00 >> 32) * (u32) n >> 32;
        }
    }
    m = v;
    for (i = 0; i < 8; i++) {
        if (func_0203b96c(i) != FALSE) {
            k++;
            if (k > m) {
                break;
            }
        }
    }
    return i;
}

void func_0203b6ac(u8 *a) {
    Unk020f41c4_B r;
    u32 t[3];
    u16 v1[2];
    u32 x;
    u32 y;
    u16 v2[8];
    u16 c;
    u16 d;
    u16 f;
    u16 g;
    u16 i;
    u16 j;
    u16 k;
    u16 e;
    u32 h;
    u32 l;

    if (func_0214df78(t) != 0) {
        t[0] = 0;
        t[1] = 0;
        t[2] = 0;
    }
    r.mUnk_00 = (u32) ((t[0] * 60 + t[1]) * 60 + t[2] + func_0200f5ac());
    r.mUnk_08 = 0x5d588b656c078965ULL;
    r.mUnk_10 = 0x269ec3;
    data_021759c0->mUnk_1e8.mUnk_08 = 0;
    data_021759c0->mUnk_1e8.mUnk_0c = 1;
    data_021759c0->mUnk_1e8.mUnk_10 = 2;
    data_021759c0->mUnk_1e8.mUnk_58 = 0;
    data_021759c0->mUnk_1e8.mUnk_1c = 0;
    data_021759c0->mUnk_1e8.mUnk_20 = 0;
    data_021759c0->mUnk_1e8.mUnk_57 = 0;
    data_021759c0->mUnk_1e8.mUnk_64 = -1;
    data_021759c0->mUnk_1e8.mUnk_14 = 2;
    r.mUnk_00 = _ll_mul(r.mUnk_08, r.mUnk_00) + r.mUnk_10;
    d = (u64) (u32) (r.mUnk_00 >> 32) * 4 >> 32;
    c = func_0203b8e4(&r);
    data_021759c0->mUnk_1e8.mUnk_00 = data_02154128[c][d];
    r.mUnk_00 = _ll_mul(r.mUnk_08, r.mUnk_00) + r.mUnk_10;
    e = (u64) (u32) (r.mUnk_00 >> 32) * 8 >> 32;
    data_021759c0->mUnk_1e8.mUnk_63 = e;
    for (k = 0; k < 2; k++) {
        for (j = 0; j < 8; j++) {
            if (j != e) {
                v1[k] = j;
                break;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        v2[i] = i;
    }
    for (g = 0; g < 1000; g++) {
        r.mUnk_00 = _ll_mul(r.mUnk_08, r.mUnk_00) + r.mUnk_10;
        f = (u64) (u32) (r.mUnk_00 >> 32) * 7 >> 32;
        r.mUnk_00 = _ll_mul(r.mUnk_08, r.mUnk_00) + r.mUnk_10;
        h = v2[f];
        v2[f] = v2[(u16) ((u64) (u32) (r.mUnk_00 >> 32) * 7 >> 32)];
        v2[(u16) ((u64) (u32) (r.mUnk_00 >> 32) * 7 >> 32)] = h;
    }
    func_0203be6c(a, 0, 0, 0);
    func_0203ba70(a);
    for (i = 0; i < 8; i++) {
        l = 3;
        if (v1[0] == i) {
            l = 0;
        }
        if (v1[1] == i) {
            l = 1;
        }
        func_0203be48(a, i, &x, &y);
        func_020468b0(i, x, y, 1, -1, l);
    }
    func_020467a0();
}

#pragma thumb off
