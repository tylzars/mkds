#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02180600.h"
#include "00/code_02180608.h"
#include "00/code_02182fdc.h"
#include "01/code_0219e0a8.h"
#include "01/code_021956dc.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "code_0214f4a4.h"
#include "code_021488e8.h"
#include "Main/Unknown/code_02039230.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0204984c_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0204984c_inline2(void) {
    s32 r = 0;
    if (func_0204984c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_0204984c_inline3(void) {
    s32 r = 0;
    if (func_0204984c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_0204984c_inline4(void) {
    s32 r = 0;
    if (func_0204984c_inline3() && (data_0217aa00->mUnk_0454 & 0x10)) {
        r = 1;
    }
    return r;
}

static inline s32 func_0204984c_inline5(void) {
    s32 r = 0;
    if (data_0217aa14 != 0 && (data_0217aa14->mUnk_75c & 0x10)) {
        r = 1;
    }
    return r;
}

static inline s32 func_0204984c_inline6(void) {
    s32 r = 0;
    if (data_0217d384 != 0 && data_0217d384->mUnk_1f30 != 0) {
        r = 1;
    }
    return r;
}

static inline s32 func_0204984c_inline7(void) {
    if (data_021759d4->mUnk_0c) {
        return data_021759d4->mUnk_10;
    }
    return 0;
}

static inline s32 func_0204984c_inline8(void) {
    if (!data_0217aa08->mUnk_28) {
        return func_0204984c_inline7();
    }
    return 1;
}

static inline s32 func_0204984c_inline9(void) {
    s32 r = 0;
    if (func_0204984c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

s32 func_0204984c(void *a, s32 b) {
    s32 r;
    s32 v;

    r = 0;
    if (func_0204984c_inline6()) {
        v = func_02120644();
        if (b != 0 && v != 0) {
            switch (v) {
                case 1:
                    v = 5;
                    break;
                case 2:
                    v = 6;
                    break;
                case 3:
                default:
                    v = 4;
                    break;
            }
            func_02049e38(v);
            r = 1;
        }
    } else if (b != 0 && func_0204984c_inline9()) {
        func_02049e38(0);
        r = 1;
        data_0217aa00->mUnk_0008 = 9;
    } else {
        func_02055340();
    }
    return r;
}

void func_02049980(s32 a) {
    func_02049e38(a);
}

u32 func_0204998c(void) {
    s32 v;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204984c_inline2() || func_0205e0a0() == 6 ||
        func_0205e0a0() == 13 || (func_0205e0a0() == 12 && func_ov000_02180608() == 0) ||
        (func_0205e0a0() != 12 && data_0217d384->mUnk_0008.mUnk_0e != 0)) {
        return 1;
    }
    switch (func_0205e0a0()) {
        case 9:
        case 15:
            return 1;
        case 2:
            if (data_021759c0->mUnk_00c == 6) {
                return 1;
            }
            break;
    }
    return 0;
}

s32 func_02049aa4(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204984c_inline2() ||
        (func_0205e0a0() == 12 && func_ov000_02180600() == 0) ||
        (func_0205e0a0() != 12 && data_0217d384->mUnk_0008.mUnk_0e != 0) || func_0205e0a0() == 13 ||
        func_0205e0a0() == 6) {
        return 0;
    }
    return 1;
}

u32 func_02049b6c(void) {
    u32 r = 0;

    if (data_021759c0->mUnk_08 == 5 && func_0204984c_inline5()) {
        r = 1;
    }
    if (func_0204984c_inline4()) {
        r = 1;
    }
    return r;
}

static inline void func_02049c3c_inline(Unk0200df9c *q) {
    q->mUnk_00 = q->mUnk_04 = 0;
}

static inline void func_02049c3c_inline2(Unk0214f4bc *p, void (*f)(void *)) {
    p->mUnk_00 = f;
    p->mUnk_04 = 0;
}

void func_02049c3c(void *a) {
    data_021759cc = func_02036bec(a, 0x124);
    data_021759cc->mUnk_000 = func_02036b74(a, 0x400, 0x20);
    data_021759cc->mUnk_10c = 6;
    data_021759cc->mUnk_110 = 0;
    data_021759cc->mUnk_118 = -1;
    data_021759cc->mUnk_11c = 0;
    func_02049c3c_inline(&data_021759cc->mUnk_0c4);
    func_0200e28c(&data_021759cc->mUnk_004, (void (*)(void *)) func_0204a1a8, 0, (u8 *) data_021759cc->mUnk_000 + 0x400,
                  0x400, 15);
    func_0200df68(&data_021759cc->mUnk_004);
    func_02049c3c_inline2(&data_021759cc->mUnk_0cc, func_02049d8c);
    func_02049c3c_inline2(&data_021759cc->mUnk_0d8, (void (*)(void *)) func_02049d54);
    func_0214f504(&data_021759cc->mUnk_0cc);
    func_0214f4d4(&data_021759cc->mUnk_0d8);
}

void func_02049d54(void) {
    if (data_021759cc->mUnk_0ec.mUnk_14 != 0) {
        data_021759cc->mUnk_0ec.mUnk_14();
    }
}

void func_02049d8c(void *a) {
    s32 b;
    s32 c;
    s32 d;

    do {
        func_02037a40();
        b = func_02054f58() != 1;
        c = func_0204984c_inline8();
        if (b == 0 && c == 0) {
            d = 1;
        } else {
            d = 0;
        }
        func_02037850();
        func_020373ec();
    } while (d == 0);
    if (data_021759cc->mUnk_0ec.mUnk_10 != 0) {
        data_021759cc->mUnk_0ec.mUnk_10();
    }
}

static inline void func_02049e38_inline(Unk020487fc *a) {
    if (a == 0 || func_0204a340(a->mUnk_02, a->mUnk_04)) {
        func_0204ac10();
    }
}

void func_02049e38(s32 a) {
    s32 b;
    s32 c;

    c = 0;
    b = data_021755a0 != 0;
    switch (a) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                c = 1;
            }
            break;
        case 1:
        case 2:
            c = 0;
            break;
        case 4:
        case 5:
        case 6:
            c = 1;
            break;
        case 3:
            c = 0;
            break;
    }
    data_021759cc->mUnk_118 = a;
    data_021759cc->mUnk_11c = c;
    func_02049f60();
    func_02105fcc();
    if (data_021759d0->mUnk_1c_0) {
        func_02049e38_inline(0);
    }
    if (b != 0) {
        func_02036c90();
        func_02036f10(10);
        do {
            func_02037a40();
            func_0210823c();
            func_02037850();
            func_020373ec();
        } while (func_02036d08() == 0);
    } else {
        func_02148908((u16 *) 0x400006c, 0x10);
    }
}

void func_02049f60(void) {
    s32 g;
    s32 a;
    s32 b;
    s32 d;
    s32 e;
    s32 f;

    a = 0;
    b = 0;
    data_021759cc->mUnk_120 = 0;
    func_0212b144();
    if (data_021755a0 != 0) {
        b = 1;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0212ad28(data_021759cc->mUnk_118, data_021759cc->mUnk_11c);
    }
    func_02039478();
    func_0203940c();
    VBlankIntrWait();
    if (func_0204984c_inline6()) {
        a = 1;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212ad28(data_021759cc->mUnk_118, data_021759cc->mUnk_11c);
    }
    func_02105b48();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02108d00();
    } else {
        func_02108c80();
    }
    func_0214f4bc(&data_021759cc->mUnk_0cc);
    func_0214f4a4(&data_021759cc->mUnk_0d8);
    func_0214f72c(1);
    if (a != 0) {
        switch (data_021759cc->mUnk_118) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                func_0211fd28();
                break;
        }
    }
    d = b == 0;
    do {
        func_0203940c();
        if (d == 0) {
            func_02037a40();
        }
        if (a == 0) {
            e = func_02054f58() == 1;
            f = e;
        } else {
            e = 1;
            f = data_0217d384->mUnk_0008.mUnk_0e == 0;
        }
        if (f != 0 && ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15)) {
            func_0214f83c(12, 0, 0);
        }
        g = func_0212b0b8();
        func_0210823c();
        VBlankIntrWait();
        if (b != 0) {
            func_020373ec();
        }
    } while (e == 0 || g == -1);
    switch (g) {
        case 1:
            data_021759cc->mUnk_120 = 12;
            break;
        default:
            data_021759cc->mUnk_120 = 0;
            break;
    }
}

// non-matching: registers and the two stores of 12 or 0 to mUnk_120 at the end of the loop: the original keeps the
// data_021755a0 test in r8 and the loop result in r9 (this source gives r9 and r8) and branches (bne) over a plain
// store of 12 and a plain store of 0, this source predicates them (ldreq/ldrne, strbeq/strbne): 8 bytes shorter.
void func_0204a1a8(void *a) {
    s32 d;
    s32 b;
    s32 c;

    while (1) {
        b = 0;
        c = 0;
        func_0200e01c(&data_021759cc->mUnk_0c4);
        data_021759cc->mUnk_120 = 0;
        func_0212b144();
        if (data_021755a0 != 0) {
            c = 1;
        }
        func_02039478();
        func_0203940c();
        VBlankIntrWait();
        if (func_0204984c_inline6()) {
            b = 1;
        }
        func_0212ad28(data_021759cc->mUnk_118, data_021759cc->mUnk_11c);
        func_02105b48();
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_02108d00();
        } else {
            func_02108c80();
        }
        if (b != 0) {
            switch (data_021759cc->mUnk_118) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    func_0211fd28();
                    break;
            }
        }
        do {
            if (c != 0) {
                func_02037a40();
            }
            if (b == 0) {
                d = func_02054f58() == 1;
            } else {
                d = 1;
            }
            func_0210823c();
            VBlankIntrWait();
            if (c != 0) {
                func_020373ec();
            }
        } while (d == 0);
        do {
            if (c != 0) {
                func_02037a40();
            }
            func_0203940c();
            d = func_0212b0b8();
            func_0210823c();
            VBlankIntrWait();
            if (c != 0) {
                func_020373ec();
            }
        } while (d == -1);
        if (d == 1) {
            data_021759cc->mUnk_120 = 12;
        } else {
            data_021759cc->mUnk_120 = 0;
        }
    }
}

s32 func_0204a340(s32 a, s32 b) {
    s32 r = 1;

    switch (a) {
        case 0:
            if (b == 2) {
                r = 0;
            }
            break;
        case 11:
            if (b == 14) {
                r = 0;
            }
            break;
        case 14:
            if (b == 3 || b == 7) {
                r = 0;
            }
            break;
        case 7:
            if (b == 3 || b == 14) {
                r = 0;
            }
            break;
        case 3:
            if (b == 7) {
                r = 0;
            }
            break;
        case 2:
            if (b != 0) {
                if (b == 15) {
                    if (func_ov001_0219e0b8()) {
                        func_0204ab64(0x78);
                    }
                    r = 0;
                }
            } else {
                r = 0;
            }
            break;
    }
    return r;
}

s32 func_0204a428(s32 a, s32 *b) {
    s32 r = 0;

    switch (a) {
        case 11:
            *b = 4;
            r = 1;
            break;
        case 0:
            *b = 0;
            r = 1;
            break;
        case 7:
            *b = 4;
            r = 1;
            break;
        case 2:
            if (data_021759c0->mUnk_00c == 6) {
                if (data_021759c0->mUnk_00 != 0x35) {
                    if (data_021759c0->mUnk_00 == 0x36) {
                        *b = 0x46;
                    }
                } else {
                    *b = 0x45;
                }
                r = 1;
            }
            break;
    }
    return r;
}

void func_0204a4d8(void) {
    func_02120150();
}

u32 func_0204a4e4(void) {
    if (data_021759cc->mUnk_10c == 6) {
        return -1;
    }
    return data_021759cc->mUnk_0ec.mUnk_1a;
}

s16 func_0204a508(void) {
    if (data_021759cc->mUnk_10c == 6) {
        return -1;
    }
    return data_021759cc->mUnk_0ec.mUnk_18;
}
