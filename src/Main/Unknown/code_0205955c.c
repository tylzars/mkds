#include "Main/Unknown/code_0205955c.h"
#include "Main/Unknown/code_02004d80.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020473a8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_0205955c_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0205955c_inline2(void) {
    s32 r = 0;
    if (func_0205955c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_0205955c_inline3(void) {
    s32 r = 0;
    if (func_0205955c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_0205955c_inline4(void) {
    s32 r = 0;
    if (func_0205955c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

void func_020597d0(const void *a, s32 b, s32 c, s32 d) {
    s32 v;
    s32 m;

    v = data_0217aa00->mUnk_0004;
    if (v != 11) {
        func_020559ec(a, c, d);
        return;
    }
    m = 1 << c;
    if (!(data_0217aa00->mUnk_164c & m)) {
        func_0214d1fc(a, &data_0217aa00->mUnk_045c[c], 0x14);
        data_0217aa00->mUnk_164c |= m;
    }
}

s32 func_02059784(void) {
    s32 r;
    u16 i;
    u8 m;

    r = 1;
    i = r;
    m = data_0217aa00->mUnk_0044.mUnk_43;
    for (; i < 8; i++) {
        if ((m & (r << i)) && data_0217aa00->mUnk_15bc_view.mUnk_10[i] == 0) {
            r = 0;
            break;
        }
    }
    return r;
}

s32 func_02059700(void) {
    s32 r;

    r = 0;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            data_0217aa00->mUnk_1e34 = 6;
            break;
        case 6:
            if (data_0217aa00->mUnk_0044.mUnk_43 == (data_0217aa00->mUnk_0044.mUnk_43 & data_0217aa00->mUnk_1d54)) {
                data_0217aa00->mUnk_1e34 = 7;
            }
            break;
        case 7:
            if (func_020505a8(5, 0xff) != 0) {
                data_0217aa00->mUnk_1d54 = r;
                data_0217aa00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            r = 1;
            break;
    }
    return r;
}

s32 func_020595e8(s32 a, void *b, void *c) {
    s32 r;

    r = 0;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            if (data_0217aa00->mUnk_0454 & 1) {
                data_0217aa00->mUnk_1e34 = 2;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                switch (a) {
                    case 0:
                        func_020473e4();
                        break;
                    case 1:
                        func_020472e4(b, c);
                        break;
                    case 2:
                        func_020472a8();
                        break;
                    case 3:
                        func_020473a8();
                        break;
                }
                data_0217aa00->mUnk_000c = 0x27;
                data_0217aa00->mUnk_0010 = 1;
                data_0217aa00->mUnk_1d08 = 0;
                func_02004d80(&data_0217aa00->mUnk_1d0c);
                data_0217aa00->mUnk_1e34 = 3;
            } else {
                data_0217aa00->mUnk_1e34 = 5;
            }
            func_020505a8(3, 1);
            break;
        case 3:
            if (func_0204f644() != 0) {
                data_0217aa00->mUnk_1e34 = 5;
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

u32 func_0205955c(void) {
    if (func_0205955c_inline4()) {
        return 3;
    }
    switch (func_0205955c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(0, 0, 0);
        default:
            return 3;
    }
}

#pragma thumb off
