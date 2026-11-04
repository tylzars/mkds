#include "code_0200c914.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_00000000.h"
#include "registers.h"

u16 data_021617bc[8] = {8, 9, 10, 11, 3, 4, 5, 6};
Unk0216fee0 data_0216fee0[8];

void InterruptHandlerSet(u32 m, UnkFunc *f) {
    s32 i;
    Unk0216fee0 *t;

    for (i = 0; i < 22; i++) {
        if (m & 1) {
            t = 0;
            if (i >= 8 && i <= 11) {
                t = &data_0216fee0[i - 8];
            } else if (i >= 3 && i <= 6) {
                t = &data_0216fee0[i + 1];
            } else {
                data_027e0008[i] = f;
            }
            if (t != 0) {
                t->mUnk_00 = f;
                t->mUnk_08 = 0;
                t->mUnk_04 = 1;
            }
        }
        m >>= 1;
    }
}

UnkFunc *InterruptHandlerGet(u32 m) {
    s32 i;
    UnkFunc **p;

    p = data_027e0008;
    for (i = 0; i < 22; i++, p++) {
        if (m & 1) {
            if (i >= 8 && i <= 11) {
                return data_0216fee0[i - 8].mUnk_00;
            }
            if (i >= 3 && i <= 6) {
                return data_0216fee0[i + 1].mUnk_00;
            }
            return *p;
        }
        m >>= 1;
    }
    return 0;
}

void func_0200cb9c(u32 n, UnkFunc *f, u32 a) {
    data_0216fee0[n].mUnk_00 = f;
    data_0216fee0[n].mUnk_08 = a;
    data_0216fee0[n].mUnk_04 = InterruptEnableSetBits(1 << (n + 8)) & (1 << (n + 8));
}

void func_0200cb50(u32 n, UnkFunc *f, u32 a) {
    (data_0216fee0 + 4)[n].mUnk_00 = f;
    (data_0216fee0 + 4)[n].mUnk_08 = a;
    InterruptEnableSetBits(1 << (n + 3));
    (data_0216fee0 + 4)[n].mUnk_04 = 1;
}

u32 InterruptEnableWrite(u32 v) {
    u16 w;
    u32 o;

    w = reg_OS_IME;
    reg_OS_IME = 0;
    o = reg_OS_IE;
    reg_OS_IE = v;
    reg_OS_IME;
    reg_OS_IME = w;
    return o;
}

u32 InterruptEnableSetBits(u32 m) {
    u16 w;
    u32 o;

    w = reg_OS_IME;
    reg_OS_IME = 0;
    o = reg_OS_IE;
    reg_OS_IE = o | m;
    reg_OS_IME;
    reg_OS_IME = w;
    return o;
}

u32 InterruptEnableClearBits(u32 m) {
    u16 w;
    u32 o;

    w = reg_OS_IME;
    reg_OS_IME = 0;
    o = reg_OS_IE;
    reg_OS_IE = o & ~m;
    reg_OS_IME;
    reg_OS_IME = w;
    return o;
}

u32 InterruptFlagWrite(u32 v) {
    u16 w;
    u32 o;

    w = reg_OS_IME;
    reg_OS_IME = 0;
    o = reg_OS_IF;
    reg_OS_IF = v;
    reg_OS_IME;
    reg_OS_IME = w;
    return o;
}

void func_0200ca34(void) {
    u32 a;

    a = (u32) &data_027e0000;
    *(u32 *) (a + 0x3f7c) = 0xfddb597d;
    *(u32 *) (a + 0x3f80 - (u32) data_00000c00) = 0x7bf9dd5b;
}

void func_0200ca30(void) {}

void func_0200c994(u32 n) {
    UnkFunc *f;
    u32 m;

    m = 1 << data_021617bc[n];
    f = data_0216fee0[n].mUnk_00;
    data_0216fee0[n].mUnk_00 = 0;
    if (f != 0) {
        f(data_0216fee0[n].mUnk_08);
    }
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= m;
    if (data_0216fee0[n].mUnk_04 != 0) {
        return;
    }
    InterruptEnableClearBits(m);
}

void func_0200c984(void) {
    func_0200c994(0);
}

void func_0200c974(void) {
    func_0200c994(1);
}

void func_0200c964(void) {
    func_0200c994(2);
}

void func_0200c954(void) {
    func_0200c994(3);
}

void func_0200c944(void) {
    func_0200c994(4);
}

void func_0200c934(void) {
    func_0200c994(5);
}

void func_0200c924(void) {
    func_0200c994(6);
}

void func_0200c914(void) {
    func_0200c994(7);
}
