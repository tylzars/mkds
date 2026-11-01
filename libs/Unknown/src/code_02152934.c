#include "code_02152934.h"
#include "code_02152a24.h"
#include "code_020205b0.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on

u32 func_02152934(u64 a, u32 b) {
    u32 r;

    if (func_02152950(a, b) != 0) {
        r = a & ~0xffffffff00000000ull;
    } else {
        r = 0;
    }
    return r;
}

s32 func_02152950(u64 a, u32 b) {
    u32 s[2];
    u8 t[0x100];
    s32 c;

    s[0] = a;
    s[1] = b;
    func_020207a8(t, 7);
    c = func_0202061c(t, s, 8) & 0x7f;
    return c == (a >> 32);
}

u64 func_02152988(u32 a, u32 b) {
    u32 s[2];
    u8 t[0x100];
    u64 v;

    s[0] = a;
    s[1] = b;
    func_020207a8(t, 7);
    v = func_0202061c(t, s, 8) & 0x7f;
    v <<= 32;
    v |= a;
    return v;
}

void func_021529bc(Unk02152490 *a) {
    u32 b;
    if (func_02152a58(a) == 3) {
        b = func_02152a6c(a) | 4;
        func_02152a04(a, b);
    }
}

#pragma thumb off
