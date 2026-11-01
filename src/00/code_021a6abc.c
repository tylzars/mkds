#include "00/code_021a6abc.h"
#include "00/code_021a6908.h"
#include "00/code_021a68dc.h"
#include "00/code_021a6934.h"
#include "00/unk_021b5000.h"
#include "Main/Unknown/code_0200edc0.h"
#include "code_02133048.h"
#include "code_02142eac.h"
#include "code_0200fc8c.h"

void func_ov000_021a6c08(u8 param_1) {
    u8 a;
    u8 b;

    if (param_1 & 2) {
        a = (param_1 >> 2) & 0xff;
    } else {
        a = (param_1 >> 2) + 25;
    }
    b = data_ov000_021b5f80;
    data_ov000_021b5f84[b % 16] = a;
    if (b >= 16) {
        data_ov000_021b5f80 = (b + 1) % 16 + 16;
    } else {
        data_ov000_021b5f80++;
    }
}

void func_ov000_021a6bdc(void) {
    if (data_ov000_021b5f54.mUnk_00 == 0) {
        data_ov000_021b5f54.mUnk_00 = 1;
        data_ov000_021b5f54.mUnk_24 = 0;
        data_ov000_021b5f54.mUnk_04.mUnk_04 = 0;
        data_ov000_021b5f54.mUnk_04.mUnk_00 = 0;
        func_0200edc0(&data_ov000_021b5f54.mUnk_0c);
    }
}

void func_ov000_021a6bb4(Unk021a6bb4 *param_1) {
    Unk021b5f54Func a = data_ov000_021b5f54.mUnk_28;

    if (a != 0) {
        a(param_1->mUnk_1e, param_1->mUnk_18, param_1->mUnk_2c, param_1->mUnk_06);
    }
}

void func_ov000_021a6b54(void) {
    Unk021b5f50 *a;

    a = func_ov000_021a5b30();
    if (a != 0 && a->mUnk_2260 == 9 && a->mUnk_226b != 1) {
        if (func_ov000_021a6908((u8 *) &data_ov000_021b5f54.mUnk_0c) != 0) {
            if (func_02144438((Unk021425e8Func) func_ov000_021a6934, a->mUnk_2144, a->mUnk_0f00, 0) != 2) {
                func_ov000_021a68dc(&data_ov000_021b5f54.mUnk_0c);
            }
        }
    }
}

u8 *func_ov000_021a6b10(void) {
    u8 *a = 0;
    Unk021b5f50 *b;
    u32 c;

    b = func_ov000_021a5b30();
    c = func_0200fca0();
    if (b != 0 && b->mUnk_2260 == 9 && b->mUnk_226b == 0) {
        a = b->mUnk_2144;
    }
    func_0200fcb4(c);
    return a;
}

u8 *func_ov000_021a6abc(u16 *param_1) {
    u8 *a = 0;
    u16 b = 0;
    Unk021b5f50 *c;
    u32 d;

    c = func_ov000_021a5b30();
    d = func_0200fca0();
    if (c != 0 && c->mUnk_2260 == 9 && c->mUnk_226b == 0) {
        a = c->mUnk_214c;
        b = c->mUnk_214a;
    }
    func_0200fcb4(d);
    if (param_1 != 0) {
        *param_1 = b;
    }
    return a;
}
