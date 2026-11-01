#include "Main/Unknown/code_0204a5f8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/code_021a2398.h"

void func_0204a5f8(void) {
    func_020364e0(func_020364e8());
    func_020399a8();
    func_02043c14();
    func_ov001_021a23f4();
}

s32 func_0204a620(Unk02175650 *a) {
    if (a->mUnk_08 != 2) {
        return 0;
    }
    return ((u32) a->mUnk_04 << 1) > 0xd1b;
}

s32 func_0204a650(Unk02175650 *a) {
    return a->mUnk_08 == 3;
}

u16 func_0204a664(Unk02175650 *a) {
    Unk02175650_buf *b;
    u8 *e;
    u16 i;
    u16 r;
    u8 v;

    if (a->mUnk_08 != 2) {
        return 0;
    }
    b = a->mUnk_00;
    i = a->mUnk_04;
    if (i >= b->mUnk_00) {
        a->mUnk_08 = 0;
        return 0;
    }
    e = &b->mUnk_04[i * 2];
    v = e[0];
    r = 0;
    r |= (v & 1) ? 1 : 0;
    r |= (v & 2) ? 2 : 0;
    r |= (v & 4) ? 0x100 : 0;
    r |= (v & 8) ? 0x600 : 0;
    r |= (v & 0x10) ? 0x10 : 0;
    r |= (v & 0x20) ? 0x20 : 0;
    r |= (v & 0x80) ? 0x40 : 0;
    r |= (v & 0x40) ? 0x80 : 0;
    a->mUnk_06++;
    if (a->mUnk_06 >= e[1]) {
        a->mUnk_04++;
        a->mUnk_06 = 0;
    }
    return r;
}

// non-matching: the original needs only r4 to r6 (the entry byte count shares a register with the bit temporaries),
// here a fourth saved register is used and the function is 0x14 bytes larger.
void func_0204a798(Unk02175650 *a, u16 b) {
    s32 f;
    u8 n;
    u8 *e;
    u8 v;
    u16 i;
    Unk02175650_buf *c;
    s32 s;

    s = a->mUnk_08;
    if (s != 1) {
        return;
    }
    c = a->mUnk_00;
    i = a->mUnk_04;
    e = &c->mUnk_04[i * 2];
    v = 0;
    v |= (b & 1) ? 1 : 0;
    v |= (b & 2) ? 2 : 0;
    v |= (b & 0x100) ? 4 : 0;
    v |= (b & 0x600) ? 8 : 0;
    v |= (b & 0x10) ? 0x10 : 0;
    v |= (b & 0x20) ? 0x20 : 0;
    v |= (b & 0x80) ? 0x40 : 0;
    v |= (b & 0x40) ? 0x80 : 0;
    n = e[1];
    f = 0;
    if (n != 0 && e[0] != v) {
        f = 1;
    } else if (n >= 0xff) {
        f = 1;
    }
    if (f != 0) {
        if (i >= 0x6e4) {
            if (s != 1) {
                return;
            }
            c->mUnk_00 = i << 1;
            a->mUnk_08 = 3;
            func_0200ee58(a->mUnk_00, 0xdcc);
            return;
        }
        a->mUnk_04++;
        e += 2;
        e[1] = 0;
    }
    e[0] = v;
    e[1]++;
}
