#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

s32 func_02059b78(Unk020487fc *a) {
    Unk021a9034 b = data_02165368;

    func_020487fc(a, &b);
    return 0;
}

#pragma thumb on

static inline u32 func_02059878_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02059878_inline2(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

u32 func_02059b28(u32 a) {
    u32 n;
    u8 *p;
    u32 r;
    u32 i;

    p = data_0217aa00->mUnk_162c[a];
    r = 1;
    if (func_02059878_inline() == 1) {
        n = 0x12;
    } else {
        n = 2;
    }
    for (i = 0; i < n; i++) {
        if (p[i] == 0) {
            r = 0;
            break;
        }
    }
    return r;
}

void func_02059954(u8 *a) {
    u32 i;
    Unk0217aa00_45c *e;
    u32 f;
    u32 v1;
    u16 v;
    u8 m;

    i = a[0];
    e = &data_0217aa00->mUnk_045c[i];
    f = 0;
    if (func_02059878_inline() == 1) {
        v1 = a[1] << 5;
    } else {
        v1 = a[1] * 0x168;
    }
    switch (a[1]) {
        case 0xff:
            if (func_02059878_inline() == 2) {
                func_02059878_inline2(9);
            }
            break;
        case 0xfe:
            if (func_02059878_inline() == 2) {
                data_0217aa00->mUnk_043a = *(u16 *) (a + 2);
            }
            break;
        case 0xfd:
            if (func_02059878_inline() == 1) {
                data_0217aa00->mUnk_162a |= 1 << i;
                if (data_0217aa00->mUnk_0044.mUnk_43 == (data_0217aa00->mUnk_0044.mUnk_43 & data_0217aa00->mUnk_162a)) {
                    func_02059878_inline2(10);
                }
            }
            break;
        case 0xfc:
            data_0217aa00->mUnk_045c[i].mUnk_214 = 0;
            f = 1;
            break;
        default:
            func_0214d1fc(a + 4, e->mUnk_000 + v1, *(u16 *) (a + 2));
            data_0217aa00->mUnk_162c[a[0]][a[1]] = 1;
            if (func_02059b28(a[0]) != 0) {
                f = 1;
            }
            break;
    }
    if (f != 0) {
        m = (u8) (1U << a[0]);
        if (func_02059878_inline() == 1) {
            if (func_020586ac(0xff, NULL, 0, 0, m) != 0) {
                data_0217aa00->mUnk_162a |= 1 << a[0];
                return;
            }
        } else {
            data_0217aa00->mUnk_162a |= 1 << a[0];
            if (data_0217aa00->mUnk_043a == (data_0217aa00->mUnk_043a & data_0217aa00->mUnk_162a)) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                if (func_020586ac(0xfd, NULL, 0, v, 1) != 0) {
                    func_02059878_inline2(10);
                }
            }
        }
    }
}

void func_02059920(Unk02059920 *a) {
    if (a->mUnk_02 == 0 && a->mUnk_0c != NULL && a->mUnk_10 >= 4) {
        func_0200ee58(a->mUnk_0c, a->mUnk_10);
        switch (a->mUnk_04) {
            case 7:
            case 9:
                break;
            case 0x15:
                func_02059954(a->mUnk_0c);
                break;
        }
    }
}

void func_02059878(void) {
    Unk0217aa00 *p;
    u32 v;

    func_02046be8(&data_0217aa00->mUnk_1608, data_021652b0, 0x17, NULL);
    data_0217aa00->mUnk_164e = 0;
    data_0217aa00->mUnk_1608.mUnk_14 = 0;
    data_0217aa00->mUnk_1608.mUnk_1a = 0;
    data_0217aa00->mUnk_1628 = 0;
    data_0217aa00->mUnk_162a = 0;
    data_0217aa00->mUnk_164c = 0;
    p = data_0217aa00;
    v = 0;
    if (p != NULL) {
        v = p->mUnk_0000;
    }
    if (v == 1) {
        p->mUnk_0044.mUnk_42 = (p->mUnk_0454 & 0x40) != 0 ? p->mUnk_1695 : p->mUnk_0044.mUnk_43;
    }
    data_0217aa00->mUnk_1eb0 = 0;
}

#pragma thumb off
