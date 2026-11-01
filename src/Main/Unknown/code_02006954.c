#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006c2c.h"
#include "Main/Unknown/code_02006ffc.h"
#include "Main/Unknown/code_02007034.h"
#include "Main/Unknown/code_020070b0.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0200704c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

void func_02006b50(s32 a, s32 b) {
    Unk0216f3dc *v1;
    v1 = func_020070b8();
    if (func_02005cc8(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005d4c(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005b80(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005d08(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005bec(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005b18(v1, 0, a, b) != 0) {
        return;
    }
    if (func_02005a30(v1, a, b) != 0) {
        return;
    }
    if (func_0200589c(v1, a, b) != 0) {
        return;
    }
    func_020068b4(a, 0xffff, 0);
}

void func_02006aac(s32 a, s32 b, void (*c)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc *v2;
    s32 i;
    u32 v3;
    v3 = func_0200fca0();
    if (data_0216f3c8 == 1) {
        func_0200fcb4(v3);
        return;
    }
    data_0216f3c8 = 1;
    func_02007008(0);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = 0;
    v2->mUnk_138.mUnk_00 = 0;
    v2->mUnk_138.mUnk_08 = 0;
    v2->mUnk_138.mUnk_0a = 0;
    v2->mUnk_138.mUnk_10 = c;
    for (i = 0; i < 16; i++) {
        v2->mUnk_1d4[i].mUnk_03 = 0;
    }
    v1.mUnk_00 = 0;
    func_0200704c(&v1);
    func_020070f0();
    func_020070c0(a - 0xe);
    func_020070cc(b - 0xe);
    func_0200fcb4(v3);
}

void func_02006a10(void (*a)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc *v2;
    s32 i;
    u32 v3;
    v3 = func_0200fca0();
    if (data_0216f3c8 == 1) {
        func_0200fcb4(v3);
        return;
    }
    data_0216f3c8 = 1;
    func_02007008(-1);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = 0;
    v2->mUnk_138.mUnk_00 = 0;
    v2->mUnk_138.mUnk_08 = 0;
    v2->mUnk_138.mUnk_0a = 0;
    v2->mUnk_138.mUnk_10 = a;
    for (i = 0; i < 16; i++) {
        v2->mUnk_1d4[i].mUnk_03 = 0;
    }
    v1.mUnk_00 = 0;
    func_0200704c(&v1);
    func_020070f0();
    func_020070c0(0);
    func_020070cc(0);
    func_0200fcb4(v3);
}

void func_02006974(void) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc *v2;
    s32 i;
    u32 v3;
    v3 = func_0200fca0();
    if (data_0216f3c8 == 0) {
        func_0200fcb4(v3);
        return;
    }
    data_0216f3c8 = 0;
    func_02007008(-1);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = 0;
    v2->mUnk_138.mUnk_00 = 0;
    v2->mUnk_138.mUnk_08 = 0;
    v2->mUnk_138.mUnk_0a = 0;
    v2->mUnk_138.mUnk_10 = 0;
    for (i = 0; i < 16; i++) {
        v2->mUnk_1d4[i].mUnk_03 = 0;
    }
    v1.mUnk_00 = 0;
    func_0200704c(&v1);
    func_020070f0();
    func_020070c0(-1);
    func_020070cc(-1);
    func_0200fcb4(v3);
}

u32 func_02006954(s32 a, s32 b) {
    u16 v1;
    v1 = 0;
    if (b > 0 && a != 0) {
        v1 = func_02006c2c(a, b);
    }
    return v1;
}

#pragma thumb off
