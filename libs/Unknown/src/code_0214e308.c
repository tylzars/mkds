#include "code_0214e308.h"
#include "code_0214e6e4.h"
#include "Main/Unknown/code_0200f000.h"
#include "registers.h"

// non-matching: 79.5: size 0x260 against 0x270; the original keeps out in r7, a in r6, b in r5, c in r4, loads e and
// f before the range tests into caller-saved registers and reloads the stack arguments after func_0200fca0 (e into a
// stack slot, d, f, h into r9, r8, r10), and starts the second division before the first result is checked;
// here e and f stay in callee-saved registers across the call.
// Returns 1 when an argument is out of range or two paired values are equal; otherwise writes to the registers at
// 0x04000280-0x0400029c twice and fills out from the words read back at 0x040002a0.
u32 func_0214e464(Unk0214e334 *out, u32 a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g, u16 h) {
    u32 s;
    s32 q;
    s32 v;

    if (a >= 0x1000 || b >= 0x1000 || e >= 0x1000 || f >= 0x1000) {
        return 1;
    }
    if (c >= 0x100 || g >= 0x100 || d >= 0xc0 || h >= 0xc0) {
        return 1;
    }
    if (c == g || d == h || a == e || b == f) {
        return 1;
    }
    s = func_0200fca0();
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = (a - e) << 8;
    *(vu64 *) 0x04000298 = (u32) (c - g);
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = *(vs32 *) 0x040002a0;
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = (b - f) << 8;
    *(vu64 *) 0x04000298 = (u32) (d - h);
    if (q >= 0x8000 || q < -0x8000) {
        func_0200fcb4(s);
        return 1;
    }
    out->mUnk_04 = q;
    v = (s32) ((((a + e) << 8) - out->mUnk_04 * (c + g)) << 9) >> 16;
    if (v >= 0x8000 || v < -0x8000) {
        func_0200fcb4(s);
        return 1;
    }
    out->mUnk_00 = v;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = *(vs32 *) 0x040002a0;
    func_0200fcb4(s);
    if (q >= 0x8000 || q < -0x8000) {
        return 1;
    }
    out->mUnk_06 = q;
    v = (s32) ((((b + f) << 8) - out->mUnk_06 * (d + h)) << 9) >> 16;
    if (v >= 0x8000 || v < -0x8000) {
        return 1;
    }
    out->mUnk_02 = v;
    return 0;
}

// Copies in to out when mUnk_30 is 0; otherwise scales in->mUnk_00 and in->mUnk_02 with the words at mUnk_18 (by
// 22 bits) and clamps them to 0xff and 0xbf; out is zeroed when in->mUnk_04 is 0.
void func_0214e334(Unk0214e334 *out, const Unk0214e334_b *in) {
    Unk0214e334_c *c;
    s64 t;

    if (data_021803d8.mUnk_30 == 0) {
        *(Unk0214e334_b *) out = *in;
        return;
    }
    c = &data_021803d8.mUnk_18;
    out->mUnk_04 = in->mUnk_04;
    out->mUnk_06 = in->mUnk_06;
    if (in->mUnk_04 == 0) {
        out->mUnk_00 = 0;
        out->mUnk_02 = 0;
        return;
    }
    t = ((s64) (in->mUnk_00 * 4) - c->mUnk_00) * c->mUnk_08;
    out->mUnk_00 = t >> 22;
    if (out->mUnk_00 < 0) {
        out->mUnk_00 = 0;
    } else if (out->mUnk_00 > 0xff) {
        out->mUnk_00 = 0xff;
    }
    t = ((s64) (in->mUnk_02 * 4) - c->mUnk_0c) * c->mUnk_14;
    out->mUnk_02 = t >> 22;
    if (out->mUnk_02 < 0) {
        out->mUnk_02 = 0;
        return;
    }
    if (out->mUnk_02 > 0xbf) {
        out->mUnk_02 = 0xbf;
    }
}

// Waits until none of the bits a is set in mUnk_36.
void func_0214e31c(u32 a) {
    while (data_021803d8.mUnk_36 & a) {
    }
}

// Returns the bits a of mUnk_34.
u32 func_0214e308(u32 a) {
    return data_021803d8.mUnk_34 & a;
}
