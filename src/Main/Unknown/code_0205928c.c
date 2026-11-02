#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"

#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"

#pragma thumb on

void func_0205982c(void *a) {
    int v1;
    int v2;
    u32 v3;
    int *v4;
    v3 = (u32) func_02036b74(a, ((u32) 0x0000016cu), 0x20);
    v4 = (int *) &data_0217aa00;
    data_0217aa00->mUnk_1624 = (void *) v3;
    v1 = 0;
    v2 = 0;
    do {
        v3 = ((u32) func_02036bec(a, (u32) 0x12));
        *(u32 *) (*v4 + v2 + 0x162c) = v3;
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off

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
                FS_InitFile(&data_0217aa00->mUnk_1d0c);
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

#pragma thumb on

void func_0205950c(void *a, void *b) {
    Unk0217aa00_1608 *part;
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    part = &data_0217aa00->mUnk_1608;
    part->mUnk_10 = 0x10;
    part->mUnk_12 = 1;
    data_0217aa00->mUnk_1650 = a;
    data_0217aa00->mUnk_1654 = b;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_020593dc_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_020593dc_inline2(void) {
    s32 r = 0;
    if (func_020593dc_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_020593dc_inline3(void) {
    s32 r = 0;
    if (func_020593dc_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_020593dc_inline4(void) {
    s32 r = 0;
    if (func_020593dc_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

void func_020594d4(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = 0x12;
    p->mUnk_12 = 1;
}

void func_0205949c(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = 0x15;
    p->mUnk_12 = 1;
}

u32 func_020593dc(void) {
    if (func_020593dc_inline4()) {
        return 3;
    }
    if (!func_020593dc_inline2()) {
        return 1;
    }
    switch (func_020593dc_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(1, data_0217aa00->mUnk_1650, data_0217aa00->mUnk_1654);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void func_020593b4(void) {
    int v1;
    if (data_0217aa00 == 0) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        func_020518c8((u32) 0);
    }
}

void func_02059388(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_020593dc();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x11;
        v2->mUnk_12 = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_0205933c(void) {
    u32 a;

    a = func_0210e5e4((u32) data_0217aa00->mUnk_1654, (u32) data_0217aa00->mUnk_1650);
    if (*(u16 *) 0x027ffc40 == 2) {
        func_02043f28(0);
    }
    if (a == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

void func_02059304(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

#pragma thumb off

#pragma thumb on

void func_020592d4(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_02058dc0(func_0205933c);
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mUnk_10 = 0x14;
        v2->mUnk_12 = 1;
    }
}

void func_020592ac(void) {
    int v1;
    if (data_0217aa00 == 0) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        func_020518c8((u32) 1);
    }
}

void func_0205928c(void) {
    Unk0217aa00_1608 *v1;
    if (data_0217aa00->mUnk_0010 == 0) {
        v1 = &data_0217aa00->mUnk_1608;
        v1->mUnk_10 = 0xf;
        v1->mUnk_12 = 1;
    }
}

#pragma thumb off
