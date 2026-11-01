#include "Main/Unknown/code_02100704.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02100b78.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020ee684.h"

void func_02100b54(Unk02101c84 *p) {
    if (p->mUnk_000.mUnk_d0 == &p->mUnk_000.mUnk_0c4) {
        p->mUnk_000.mUnk_50 = p->mUnk_000.mUnk_0c4;
        p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_50;
    }
}

void func_021009fc(Unk02101c84 *p) {
    int i;
    Unk020ee684 *e;
    void (*f)(Unk02101c84 *);

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &(data_027e00c8)[(u16) i];
    p->mUnk_168 = e->mUnk_1fc;
    p->mUnk_144 = 0;
    if (p->mUnk_24c != 0) {
        if (e->mUnk_014 == 0x10) {
            p->mUnk_184 = p->mUnk_168->mUnk_98;
            p->mUnk_190 = p->mUnk_168->mUnk_a4;
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        } else {
            p->mUnk_144 = 1;
            if (p->mUnk_000.mUnk_74 & 0x8000000) {
                func_020fe694(0xb, p->mUnk_000.mUnk_4e, 1, 5);
            }
            p->mUnk_16c = 0;
            p->mUnk_174 = 0;
        }
    }
    if (p->mUnk_160 == 0xf) {
        func_020f4020(&p->mUnk_1a4, data_0215a1c0, data_0215a1c0[0].y);
        p->mUnk_248 = 3;
        p->mUnk_15c = 1;
    } else {
        p->mUnk_17c = -p->mUnk_150;
        p->mUnk_170 = p->mUnk_14c;
    }
    if (p->mUnk_144 == 0) {
        func_020f8e3c((u32) p->mUnk_168, 0xf7);
    }
    p->mUnk_270 = 0;
    f = (p->mUnk_168->mUnk_48 & 1) ? func_02100b78 : func_02100b54;
    f(p);
}

void func_02100704(Unk02101c84 *p) {
    s32 i;
    Unk020ee684 *e;
    u32 n;
    s32 k;
    s32 a0;
    s32 a1;

    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &(data_027e00c8)[(u16) i];
    if (p->mUnk_24c != 0 && e->mUnk_014 != 0x10 && p->mUnk_158 != -0x40) {
        p->mUnk_144 = 1;
        if (p->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe694(0xb, p->mUnk_000.mUnk_4e, 1, 5);
        }
    } else {
        n = 0x28 - func_021014a0(p, p->mUnk_15c == 0 ? 1 : 0, 6);
        if (n < 7) {
            if (p->mUnk_164 > 0) {
                p->mUnk_164 -= 5;
            }
            if (n == 1) {
                if (p->mUnk_24c == 0) {
                    if (p->mUnk_260 == -1) {
                        k = 0;
                    } else {
                        p->mUnk_154 = p->mUnk_25c;
                        p->mUnk_158 = p->mUnk_260;
                        p->mUnk_25c = 0x12;
                        p->mUnk_260 = -1;
                        k = 1;
                    }
                    if (k == 0) {
                        p->mUnk_130--;
                        p->mUnk_26c = 1;
                        p->mUnk_270++;
                        if (p->mUnk_270 > 0x3c) {
                            p->mUnk_25c = 0x13;
                            p->mUnk_260 = -0x40;
                            p->mUnk_160 = 0xe;
                        }
                        goto skip;
                    }
                }
                e->mUnk_014 = 0x13;
                if (p->mUnk_154 != 0x13) {
                    if (p->mUnk_24c == 0) {
                        func_0205a548(((u8 *) data_0217aa18)[e->mUnk_1f8 & 0xff], p->mUnk_154, p->mUnk_158);
                    } else {
                        func_020f40dc(&e->mUnk_030, p->mUnk_154, p->mUnk_158);
                    }
                    p->mUnk_154 = 0x13;
                    p->mUnk_158 = -0x40;
                    p->mUnk_160 = 0xe;
                    func_020f8e3c((u32) e->mUnk_1fc, 0xf8);
                } else {
                    p->mUnk_158 = -0x40;
                    p->mUnk_160 = 0xe;
                }
                if ((p->mUnk_000.mUnk_74 & 0x8000000) && p->mUnk_24c != 0) {
                    func_020fe694(0xb, p->mUnk_000.mUnk_4e, 3,
                                  ((e->mUnk_030.mUnk_00 << 2) | e->mUnk_030.mUnk_08) & 0xff);
                }
            }
        }
    }
skip:
    if (p->mUnk_15c == 0 && p->mUnk_144 != 0) {
        a0 = p->mUnk_16c;
        a1 = p->mUnk_174;
        func_021014a0(p, 1, 6);
        p->mUnk_178 = p->mUnk_16c - a0;
        p->mUnk_180 = p->mUnk_174 - a1;
        p->mUnk_13c = 6;
        p->mUnk_13e = 1;
        p->mUnk_26c = 0;
    }
    if (!(p->mUnk_000.mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 == 5 || p->mUnk_264 == 7) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}
