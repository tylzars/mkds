#include "00/code_0219a430.h"
#include "code_02134d30.h"
#include "00/code_0218d000.h"
#include "00/code_0218dc44.h"
#include "00/code_0218dddc.h"
#include "00/code_0218e368.h"
#include "00/code_0218e554.h"
#include "00/code_0218e53c.h"
#include "00/code_02197e8c.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_021919ac.h"
#include "00/code_0219a000.h"
#include "00/code_0219a5e8.h"
#include "00/code_0219a604.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"

typedef struct Unk0219a430Addr {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219a430Addr;

// non-matching: registers only; the original reuses the zero from the -1 compare for the two zero stores into the
// struct, keeps the byte-swapped halfword in r5 and reads the compared field into r1 (ours r2)
u32 func_ov000_0219a430(Unk02197e8c **a, const u8 *b, u32 c, u32 d, u32 e) {
    Unk02197e8c *f;
    u16 i;
    Unk0219a430Addr g;
    u32 h;
    s32 j;
    func_ov000_0218e8b8();
    if (d == 0) {
        d = 0x10000;
    }
    if (c == 0) {
        c = 0x10000;
    }
    if (func_ov000_0219a654(b, &h, &i) == 0) {
        return 4;
    }
    f = func_ov000_021a3690(0x44);
    if (f == 0) {
        return 1;
    }
    func_02134de0(f, 0, 0x44);
    f->mUnk_00 = -1;
    f->mUnk_3c = d;
    f->mUnk_38 = c;
    f->mUnk_24 = (void (*)(Unk02197e8c *)) e;
    f->mUnk_0c = func_ov000_0218e004(4, 0x20, 2, (s32(*)(void *, s32)) & func_ov000_0219a604,
                                     (s32(*)(void *, void *)) & func_ov000_0219a5e8, 0);
    if (f->mUnk_0c == 0) {
        func_ov000_021a3668(f);
        return 1;
    }
    f->mUnk_10 = (void *) func_ov000_0218dc94(4, 4, (void (*)(void *)) & func_ov000_0219a5dc);
    if (f->mUnk_10 == 0) {
        func_ov000_0218dfb4(f->mUnk_0c);
        func_ov000_021a3668(f);
        return 1;
    }
    f->mUnk_00 = func_ov000_0218e554(2, 2, 0);
    if (f->mUnk_00 == -1) {
        func_ov000_0218dfb4(f->mUnk_0c);
        func_ov000_0218dc48(f->mUnk_10);
        func_ov000_021a3668(f);
        return 3;
    }
    ((u32 *) &g)[0] = 0;
    ((u32 *) &g)[1] = 0;
    g.mUnk_01 = 2;
    g.mUnk_04 = h;
    g.mUnk_02 = ((i >> 8) & 0xff) | ((i << 8) & 0xff00);
    if (func_ov000_0218e4e4(f->mUnk_00, &g, 8) == -1) {
        func_ov000_0218e53c(f->mUnk_00);
        func_ov000_0218dfb4(f->mUnk_0c);
        func_ov000_0218dc48(f->mUnk_10);
        func_ov000_021a3668(f);
        return 3;
    }
    j = 8;
    func_ov000_0218e394(f->mUnk_00, &g, (u32 *) &j);
    f->mUnk_04 = g.mUnk_04;
    f->mUnk_08 = ((g.mUnk_02 >> 8) & 0xff) | ((g.mUnk_02 << 8) & 0xff00);
    *a = f;
    return 0;
}

Unk02197fe8 *func_ov000_0219a5b0(Unk02197e8c *a, u32 b, u32 c) {
    Unk02197fe8 d;
    Unk02197fe8 *e;
    void *f;
    d.mUnk_00 = b;
    d.mUnk_04 = c;
    e = &d;
    f = func_ov000_0218de28(a->mUnk_0c, &e);
    if (f != 0) {
        return *(Unk02197fe8 **) f;
    }
    return 0;
}

void func_ov000_0219a5dc(Unk02197fe8 **a) {
    func_ov000_021984b4(*a);
}
