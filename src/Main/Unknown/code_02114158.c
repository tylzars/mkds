#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02114504.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02182fdc.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_021143f4(void) {
    s32 i;
    u16 a;
    s32 b;
    s32 c;

    a = 0;
    data_0217d34c->mUnk_00 = 0;
    for (i = 0; i < 0x3c; i++) {
        if (func_02060b34(i)) {
            data_0217d34c->mUnk_00++;
            if (func_02060afc(i)) {
                a++;
            }
        }
    }
    if (data_0217d34c->mUnk_00 != 0) {
        b = 0;
        c = a;
        for (i = 0; i < 0x3c; i++) {
            if (func_02060b34(i)) {
                if (func_02060afc(i)) {
                    data_0217d34c->mUnk_04[b].mUnk_00 = (u8) i;
                    b++;
                } else {
                    data_0217d34c->mUnk_04[c].mUnk_00 = (u8) i;
                    c++;
                }
            }
        }
        func_02114504(0, a);
        func_02114504(a, data_0217d34c->mUnk_00 - a);
    }
}

u16 func_021143b4(void) {
    s32 i;
    u16 n;

    n = 0;
    if (data_0217d34c == 0) {
        for (i = 0; i < 0x3c; i++) {
            if (func_02060b34(i)) {
                n++;
            }
        }
        return n;
    }
    return data_0217d34c->mUnk_00;
}

s32 func_02114398(u16 a) {
    return func_02060afc(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_0211437c(u16 a) {
    return func_02060ac8(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114360(u16 a) {
    return func_02060a60(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114344(u16 a) {
    return func_020609f8(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_02114328(u16 a) {
    return func_02060a94(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_0211430c(u16 a) {
    return func_02060a2c(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_021142f0(u16 a) {
    return func_020609c4(data_0217d34c->mUnk_04[a].mUnk_00);
}

s32 func_021142d4(u16 a, void *b) {
    return func_02060950(data_0217d34c->mUnk_04[a].mUnk_00, b);
}

void func_02114298(u16 a, void *b, u32 c) {
    u8 t[0x14];

    func_020608fc(data_0217d34c->mUnk_04[a].mUnk_00, t);
    func_0214d168(b, 0, c);
    func_0214cffc(t, b, 0x14);
}

s32 func_0211427c(u16 a) {
    return func_02060880(data_0217d34c->mUnk_04[a].mUnk_00, 1);
}

s32 func_02114260(u16 a) {
    return func_02060880(data_0217d34c->mUnk_04[a].mUnk_00, 0);
}

void func_021141c8(u16 a, Unk021141c8 *b, void *c) {
    u8 d;

    func_0205ec14(data_0217d34c->mUnk_08, data_0217d34c->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    if (!func_0205eca4(data_0217d34c->mUnk_08, data_0217d34c->mUnk_04[a].mUnk_00, b) || b->mUnk_200 == 0) {
        b->mUnk_200 = 1;
        func_0214d0a8(data_0217d34c->mUnk_0c, b, 0x200);
    }
    func_020ac2fc(b, c, 0x20);
}

void func_02114174(u16 a) {
    u8 d;

    func_020607b0(data_0217d34c->mUnk_04[a].mUnk_00);
    d = data_0217aa08->mUnk_28;
    do {
    } while (d == 0 ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1);
    func_021143f4();
}

s32 func_02114158(u16 a, void *b) {
    return func_02060468(data_0217d34c->mUnk_04[a].mUnk_00, b);
}

#pragma thumb off
