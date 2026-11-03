#pragma avoid_byte all

#include "code_02134008.h"
#include "code_02139e20.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_02142000.h"

Unk02134008 func_0213428c(Unk02134008 a, Unk02134008 b, u32 c) {
    Unk0217ee98 *t;
    Unk02134008Func fn;

    t = func_02142584();
    if ((c & 0xc00000) == 0) {
        c |= func_02133ddc(0, 0) & 0xc00000;
    }
    switch (c & 0x7c000000) {
        case 0x40000000:
            fn = t->mUnk_04[4];
            break;
        case 0x04000000:
            fn = t->mUnk_04[0];
            break;
        case 0x10000000:
            fn = t->mUnk_04[2];
            break;
        case 0x20000000:
            fn = t->mUnk_04[3];
            break;
        case 0x08000000:
            fn = t->mUnk_04[1];
            break;
        default:
            fn = 0;
            break;
    }
    if (fn == 0) {
        raise(2);
    }
    return fn(a, b, c);
}

u32 func_02134238(u32 a, u32 b) {
    Unk02134008 s;
    Unk02134008 r;

    s.mUnk_00 = a;
    r = func_0213428c(s, s, b);
    return r.mUnk_00;
}

u32 func_021341e0(u32 a, u32 b, u32 c) {
    Unk02134008 s;
    Unk02134008 r;

    s.mUnk_00 = a;
    s.mUnk_04 = b;
    r = func_0213428c(s, s, c);
    return r.mUnk_00;
}

u64 func_02134188(u32 a, u32 b) {
    Unk02134008 s;
    Unk02134008 r;

    s.mUnk_00 = a;
    r = func_0213428c(s, s, b);
    return *(u64 *) &r;
}

u64 func_0213412c(u32 a, u32 b, u32 c) {
    Unk02134008 s;
    Unk02134008 r;

    s.mUnk_00 = a;
    s.mUnk_04 = b;
    r = func_0213428c(s, s, c);
    return *(u64 *) &r;
}

u32 func_021340d4(u32 a, u32 b, u32 c) {
    Unk02134008 s;
    Unk02134008 t;
    Unk02134008 r;

    s.mUnk_00 = a;
    t.mUnk_00 = b;
    r = func_0213428c(s, t, c);
    return r.mUnk_00;
}

u64 func_0213406c(u32 a, u32 b, u32 c, u32 d, u32 e) {
    Unk02134008 s;
    Unk02134008 t;
    Unk02134008 r;

    s.mUnk_00 = a;
    s.mUnk_04 = b;
    t.mUnk_00 = c;
    t.mUnk_04 = d;
    r = func_0213428c(s, t, e);
    return *(u64 *) &r;
}

u32 func_02134008(u32 a, u32 b, u32 c, u32 d, u32 e) {
    Unk02134008 s;
    Unk02134008 t;
    Unk02134008 r;

    s.mUnk_00 = a;
    s.mUnk_04 = b;
    t.mUnk_00 = c;
    t.mUnk_04 = d;
    r = func_0213428c(s, t, e);
    return r.mUnk_00;
}
