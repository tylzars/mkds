#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02056464(Unk0217aa00_45c *a) {
    func_0214d1fc(data_0217aa08->mUnk_00->mUnk_0c, a->mUnk_000, 0x14);
    if (data_0217aa08->mUnk_04->mUnk_004 != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        a->mUnk_214 = 1;
        func_0214d1fc(data_0217aa08->mUnk_04->mUnk_008, &a->mUnk_014, 0x200);
    } else {
        a->mUnk_214 = 0;
        func_0214d168(&a->mUnk_014, 0, 0x200);
    }
    func_0214d1fc(data_0217aa08->mUnk_00->mUnk_20, a->mUnk_224, 4);
    a->mUnk_228_0 = data_021759d0->mUnk_00;
    a->mUnk_228_4 = data_021759d0->mUnk_04;
    a->mUnk_216 = data_0217aa08->mUnk_00->mUnk_24;
    a->mUnk_229 = func_02056208();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0214d168(&a->mUnk_218, 0, 0xc);
    } else {
        func_02152490(data_0217aa08->mUnk_00->mUnk_4c, &a->mUnk_218);
    }
}

s32 func_02056574(s32 a, Unk020565e4 *b) {
    s32 r;

    r = 0;
    switch (a) {
        case 0:
            r = func_020565e4(data_0217aa08->mUnk_14, b);
            break;
        case 1:
            r = func_020565e4(data_0217aa08->mUnk_18, b);
            break;
        case 2:
            break;
    }
    return r;
}

s32 func_020565ac(s32 a, s32 b, Unk020565e4 *c) {
    s32 r;

    r = 0;
    switch (a) {
        case 0:
            r = func_0205660c(data_0217aa08->mUnk_14, b, c);
            break;
        case 1:
            r = func_0205660c(data_0217aa08->mUnk_18, b, c);
            break;
        case 2:
            break;
    }
    return r;
}

s32 func_020565e4(Unk0217aa08_14 *a, Unk020565e4 *b) {
    if (a->mUnk_08_0 == 0) {
        return 0;
    }
    b->mUnk_02 = a->mUnk_08_8;
    b->mUnk_03 = a->mUnk_08_15;
    b->mUnk_00 = a->mUnk_08_22;
    return 1;
}

s32 func_0205660c(Unk0217aa08_14 *a, s32 b, Unk020565e4 *c) {
    u8 i;
    u32 v;

    i = (b - 1) * 3;
    v = 0;
    if (a->mUnk_08_0 == 0) {
        return v;
    }
    v |= a->mUnk_20[i] << 16;
    v |= a->mUnk_20[i + 1] << 8;
    v |= a->mUnk_20[i + 2];
    c->mUnk_02 = (v >> 17) & 0x7f;
    c->mUnk_03 = (v >> 10) & 0x7f;
    c->mUnk_00 = v & 0x3ff;
    return 1;
}

void func_02056670(u32 a) {
    Unk0217aa08_14 *p;

    p = data_0217aa08->mUnk_18;
    if (func_020573c8(a) == 0) {
        p->mUnk_08_0 = 0;
    } else {
        func_020578fc(a, p);
    }
}

#pragma thumb off
