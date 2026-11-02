#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma thumb on

static inline u32 func_02058b38_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02058b74_inline(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

static inline s32 func_02058cac_inline2(void) {
    s32 r = 0;
    if (func_02058b38_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_02058cac_inline3(void) {
    s32 r = 0;
    if (func_02058cac_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_02058cac_inline4(void) {
    s32 r = 0;
    if (func_02058cac_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

void func_02058b38(void) {
    if (func_02058b38_inline() == 1) {
        data_0217aa00->mUnk_15f6 = data_0217aa00->mUnk_0044.mUnk_43 | 1;
    }
    data_0217aa00->mUnk_1608.mUnk_14 = 0;
}

void func_02058b74(void) {
    data_0217aa00->mUnk_1608.mUnk_18 = data_0217aa00->mUnk_1608.mUnk_18 - 1;
    if (data_0217aa00->mUnk_1608.mUnk_18 < 0) {
        func_02058b74_inline(7);
    }
}

void func_02058ba4(void) {
    u64 v;

    v = (u32) func_0200f5ac() << 8;
    v = (u32) v & ~(u32) (v >> 32);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        v = v * 0x5d588b656c078965ull + 0x269ec3;
        data_0217aa00->mUnk_1608.mUnk_18 = (u16) (((v >> 32) * 0xb4) >> 32) + 0x78;
    } else {
        data_0217aa00->mUnk_1608.mUnk_18 = 0xb4;
    }
}

void func_02058c10(void) {
    if (data_0217aa00->mUnk_0010 != 0) {
        return;
    }
    if (func_02058b38_inline() != 1) {
        func_02058b74_inline(0x16);
        return;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 11:
        case 15:
            func_02051814(0);
            return;
        case 13:
            func_02058b74_inline(7);
            break;
    }
}

void func_02058c74(void) {
    u16 v;

    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
    func_02056464(&data_0217aa00->mUnk_045c[v]);
}

// non-matching: 12 words in the inline chain after func_02046b40: the zero and the three flags of
// func_02058cac_inline4/3/2 sit in r2, r1, r5 (original r3, r2, r1) and the loaded word in r3 (original r5).
s32 func_02058cac(void) {
    s32 r;
    u16 v;

    r = 0;
    if (!func_02058cac_inline2()) {
        return 1;
    }
    v = ((const Unk0217aa00 *) data_0217aa00)->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
    if (v == 0xffff && func_02058b38_inline() == 2) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_02050e60(0);
            return 3;
        }
        return 2;
    }
    func_02046b40(&data_0217aa00->mUnk_1608);
    if (!func_02058cac_inline4()) {
        if (func_02058b38_inline() == 1 && data_0217aa00->mUnk_0044.mUnk_40 == 0) {
            func_02050e60(7);
        }
    }
    if (data_0217aa00->mUnk_1608.mUnk_0e == 0xf) {
        r = 1;
    }
    return r;
}

s32 func_02058dc0(void (*a)(void)) {
    s32 r;

    r = 0;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            if (data_0217aa00->mUnk_0454 & 1) {
                switch (func_02058b38_inline()) {
                    case 1:
                        data_0217aa00->mUnk_1e34 = 6;
                        break;
                    case 2:
                        data_0217aa00->mUnk_1e34 = 2;
                        break;
                }
            }
            break;
        case 7:
            func_020505a8(5, 0xff);
            data_0217aa00->mUnk_1e44 |= 2;
            data_0217aa00->mUnk_1d54 = r;
            data_0217aa00->mUnk_1e34 = 1;
            break;
        case 6:
            if (data_0217aa00->mUnk_0044.mUnk_43 == (data_0217aa00->mUnk_0044.mUnk_43 & data_0217aa00->mUnk_1d54)) {
                data_0217aa00->mUnk_1e34 = 7;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                func_02057df0(a);
                data_0217aa0c->mUnk_f8 = 1;
            }
            data_0217aa00->mUnk_1e34 = 3;
            func_020505a8(3, 1);
            break;
        case 3:
            if (data_0217aa0c->mUnk_f8 == 0) {
                if (data_0217aa00->mUnk_164f != 0) {
                    func_02050e60(7);
                } else {
                    data_0217aa00->mUnk_1e34 = 5;
                }
            }
            break;
        case 5:
            if (func_020505a8(4, 1) != 0) {
                data_0217aa00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            if (data_0217aa00->mUnk_1e44 & 2) {
                r = 1;
            }
            break;
    }
    return r;
}

#pragma thumb off
