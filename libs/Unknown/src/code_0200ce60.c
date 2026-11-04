#include "code_0200ce60.h"
#include "code_0200cdb0.h"
#include "code_0200ce30.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0200fc8c.h"
#include "registers.h"
#include "00/code_02188720.h"

s32 data_0216ff40;

void func_0200d028(void) {
    Unk0200ce60 *p;
    volatile u32 v;

    if (data_0216ff40 != 0) {
        return;
    }
    data_0216ff40 = 1;
    ((Unk0200ce60 *) 0x027ffff0)->mUnk_00 = 0;
    func_0200cfc0(0x7e, (Unk0200ce60 *) 0x027ffff0, 0);
    p = (Unk0200ce60 *) 0x027ffff0;
    if (p->mUnk_06 != 0) {
        do {
            func_0200cdb0();
        } while (p->mUnk_06 != 0);
    }
    *(u32 *) 0x027fffb0 = 0xffffffff;
    *(u32 *) 0x027fffb4 = 0xffff0000;
    v = 0;
    MemFillWords(v, (void *) 0x027fffc0, 0x28);
    reg_MI_EXMEMCNT |= 0x800;
    reg_MI_EXMEMCNT |= 0x80;
    func_0200cf20(0x7e, (Unk0200ce60 *) 0x027ffff0, 0);
    func_0200cfc0(0x7f, (Unk0200ce60 *) 0x027ffff0, 0);
}

s32 func_0200cfd0(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k) {
    s32 r;

    r = func_0200cea0(a, p, f, k);
    while (r > 0) {
        func_0200cdb0();
        r = func_0200cea0(a, p, f, k);
    }
    return r;
}

s32 func_0200cfc0(u32 a, Unk0200ce60 *p, u32 (*f)(void)) {
    return func_0200cfd0(a, p, f, 0);
}

s32 func_0200cf30(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k) {
    u32 s;

    if (a != p->mUnk_04) {
        return -2;
    }
    if (k != 0) {
        s = func_0200fccc();
    } else {
        s = IrqDisable();
    }
    p->mUnk_04 = 0;
    if (f != 0) {
        f();
    }
    p->mUnk_00 = 0;
    if (k != 0) {
        func_0200fce0(s);
    } else {
        IrqRestore(s);
    }
    return 0;
}

s32 func_0200cf20(u32 a, Unk0200ce60 *p, u32 (*f)(void)) {
    return func_0200cf30(a, p, f, 0);
}

s32 func_0200cea0(u32 a, Unk0200ce60 *p, u32 (*f)(void), s32 k) {
    u32 s;
    s32 r;

    if (k != 0) {
        s = func_0200fccc();
    } else {
        s = IrqDisable();
    }
    r = func_0214d33c(a, &p->mUnk_00);
    if (r == 0) {
        if (f != 0) {
            f();
        }
        p->mUnk_04 = a;
    }
    if (k != 0) {
        func_0200fce0(s);
    } else {
        IrqRestore(s);
    }
    return r;
}

s32 func_0200ce80(u32 a) {
    return func_0200cf30(a, (Unk0200ce60 *) 0x027fffe8, func_0200ce30, 1);
}

s32 func_0200ce60(u32 a) {
    return func_0200cea0(a, (Unk0200ce60 *) 0x027fffe8, func_0200ce48, 1);
}
