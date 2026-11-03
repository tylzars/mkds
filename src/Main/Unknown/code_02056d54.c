#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057174.h"
#include "Main/Unknown/code_02057244.h"
#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_02057130(void) {
    func_0205721c(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02057514();
        func_02057df0(func_02057174);
        data_0217aa0c->mUnk_f8 = 1;
    }
}

void func_02056fdc(void) {
    u16 a;

    a = 0;
    data_0217aa08->mUnk_2c = 0;
    func_02057c60(data_0217aa08->mUnk_00);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        if ((s32) data_021759d4->mUnk_04 == 4) {
            data_0217aa08->mUnk_2a = 0xffff;
            data_0217aa08->mUnk_2c = 4;
            func_02057504();
            return;
        }
        a |= 1;
    }
    func_02057bcc(data_0217aa08->mUnk_04);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        a |= 2;
    }
    func_02057b40(data_0217aa08->mUnk_08);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        a |= 4;
    }
    func_02057aac(data_0217aa08->mUnk_0c);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        a |= 8;
    }
    func_02057a18(data_0217aa08->mUnk_10);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        a |= 0x10;
    }
    func_02057764(data_0217aa08->mUnk_20);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        a |= 0x20;
    }
    if (data_0217aa08->mUnk_2c == 0) {
        if (a != 0) {
            data_0217aa08->mUnk_2c = 3;
        } else {
            data_0217aa08->mUnk_2c = 0;
        }
    }
    data_0217aa08->mUnk_2a = a;
    func_02057504();
}

void func_02056f98(void) {
    data_0217aa08->mUnk_44_0 = 1;
    data_0217aa08->mUnk_3c = 0;
    data_0217aa08->mUnk_2a = 0;
    func_02057514();
    func_02057df0(func_02056fdc);
    data_0217aa0c->mUnk_f8 = 1;
}

void func_02056e70(void) {
    if (data_0217aa08->mUnk_2a & 2) {
        func_020572e8();
        func_02057c14(data_0217aa08->mUnk_04);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    if (data_0217aa08->mUnk_2a & 4) {
        func_020572cc();
        func_02057b84(data_0217aa08->mUnk_08);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    if (data_0217aa08->mUnk_2a & 8) {
        func_020572b0();
        func_02057af4(data_0217aa08->mUnk_0c);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    if (data_0217aa08->mUnk_2a & 0x10) {
        func_02057294();
        func_02057a60(data_0217aa08->mUnk_10);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    if (data_0217aa08->mUnk_2a & 0x20) {
        func_02057244();
        func_020577b4(data_0217aa08->mUnk_20);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    if (data_0217aa08->mUnk_2a & 1) {
        func_02057304(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2);
        func_02057ca4(data_0217aa08->mUnk_00);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    data_0217aa08->mUnk_2a = 0;
    func_02057504();
}

void func_02056e48(void) {
    func_02057514();
    func_02057df0(func_02056e70);
    data_0217aa0c->mUnk_f8 = 1;
}

void func_02056e24(s32 a) {
    u8 *b;

    b = data_0217aa08->mUnk_00->mUnk_20;
    b[a >> 3] |= 1 << (a & 7);
}

u32 func_02056e00(s32 a, u8 *b) {
    u32 r;

    r = 1;
    if (((1 << (a & 7)) & b[a >> 3]) == 0) {
        r = 0;
    }
    return r;
}

u32 func_02056dec(u32 a) {
    return func_02056e00(a, data_0217aa08->mUnk_00->mUnk_20);
}

u8 func_02056dac(u8 *a) {
    u8 r;

    r = 1;
    if (func_02056e00(0x13, a)) {
        r = 4;
    } else if (func_02056e00(0x12, a)) {
        r = 3;
    } else if (func_02056e00(0x11, a)) {
        r = 2;
    }
    return r;
}

u8 func_02056d98(void) {
    return func_02056dac(data_0217aa08->mUnk_00->mUnk_20);
}

void func_02056d54(u32 a) {
    u8 *b;

    if (a > 3) {
        b = data_0217aa08->mUnk_00->mUnk_20;
        b[2] |= 8;
    }
    if (a > 2) {
        b = data_0217aa08->mUnk_00->mUnk_20;
        b[2] |= 4;
    }
    if (a > 1) {
        b = data_0217aa08->mUnk_00->mUnk_20;
        b[2] |= 2;
    }
}

#pragma thumb off
