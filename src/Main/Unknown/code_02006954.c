#include "Main/Unknown/code_02006954.h"

#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_020070e4(void) {
    return ((u32) data_0216f3d0);
}

u32 func_020070d8(void) {
    return ((u32) data_0216f3d4);
}

void func_020070cc(u32 p0) {
    data_0216f3d0 = (u16) p0;
}

void func_020070c0(u32 p0) {
    data_0216f3d4 = (u16) p0;
}

Unk0216f3dc *func_020070b8(void) {
    return (Unk0216f3dc *) data_0216f3dc;
}

u32 func_020070b0(void) {
    return ((u32) (&data_0216f478));
}

#pragma thumb off

#pragma thumb on

u32 func_0200704c(const Unk0216f3dc_9c *a) {
    u32 v1;
    s32 *v2;
    v1 = IrqDisable();
    if (data_0216f3c8 != 1) {
        IrqRestore(v1);
        return 0;
    }
    v2 = (s32 *) func_020070b0();
    if (v2 == NULL || *v2 != 0) {
        IrqRestore(v1);
        return 0;
    }
    MemCopyWords(a, data_0216f478, 0x9c);
    IrqRestore(v1);
    return 1;
}

#pragma thumb off

#pragma thumb on

Unk02007014 *func_02007040(void) {
    return data_0216f3d8;
}

void func_02007034(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) (&data_0216f3d8))) + 0) = p0;
}

#pragma thumb off

#pragma thumb on

Unk02007014 *func_02007014(u32 a) {
    Unk02007014 *v1;
    for (v1 = func_02007040(); v1 != NULL; v1 = v1->mUnk_28) {
        if (v1->mUnk_00 == a) {
            return v1;
        }
    }
    return NULL;
}

#pragma thumb off

#pragma thumb on

void func_02007008(u32 p0) {
    data_02161780 = p0;
}

u32 func_02006ffc(void) {
    return data_02161780;
}

#pragma thumb off

#pragma thumb on

s32 func_02006fdc(s32 a) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((a >> i) & 1) != 0) {
            return i;
        }
    }
    return -1;
}

u32 func_02006f98(s32 a) {
    s32 v1;
    s32 v2;
    v1 = func_020070e4();
    v2 = a / v1 + ((a % v1) != 0 ? 1 : 0);
    return ((v2 >> 5) + ((v2 & 0x1f) != 0 ? 1 : 0)) << 2;
}

BOOL func_02006f50(u32 a, s32 b, s32 *c, s32 *d) {
    Unk0216f3dc *v1;
    Unk0200628c *v2;
    v1 = func_020070b8();
    v2 = &v1->mUnk_1d4[b].mUnk_24;
    if (v1->mUnk_000.mUnk_00 == 4 && v1->mUnk_000.mUnk_14 == a) {
        *d = v2->mUnk_04;
        *c = v2->mUnk_10;
        return TRUE;
    }
    return FALSE;
}

u32 func_02006f14(s32 a, s32 b) {
    switch (func_020070b8()->mUnk_000.mUnk_00) {
        case 4:
        case 6:
            return 0;
    }
    func_020070c0(a - 0xe);
    func_020070cc(b - 0xe);
    return 1;
}

#pragma thumb off

#pragma thumb on

int func_02006ef8(void) {
    int v1;
    Unk02007014 *v2;
    v1 = 0;
    for (v2 = func_02007040(); v2 != NULL; v2 = v2->mUnk_28) {
        v1 = v1 + 1;
    }
    return v1;
}

#pragma thumb off

#pragma thumb on

s32 func_02006e74(Unk02007014 *a, u32 b, const void *c, u8 *d, u32 e, u16 f) {
    Unk02007014 *v1;
    u32 v2;
    v2 = IrqDisable();
    if (func_02007040() == NULL) {
        func_02007034((u32) a);
    } else {
        for (v1 = func_02007040(); v1->mUnk_28 != NULL; v1 = v1->mUnk_28) {
        }
        v1->mUnk_28 = a;
    }
    if (d == NULL) {
        a->mUnk_32 = 1;
    } else {
        a->mUnk_2c = d;
        a->mUnk_32 = 0;
    }
    a->mUnk_28 = NULL;
    a->mUnk_00 = b;
    a->mUnk_04 = e;
    a->mUnk_30 = f;
    if (c != NULL) {
        MemCopy(c, a->mUnk_08, 0x20);
    } else {
        MemFill(a->mUnk_08, 0, 0x20);
    }
    IrqRestore(v2);
    return 1;
}

Unk02007014 *func_02006df8(u32 a) {
    Unk02007014 *v1;
    Unk02007014 *v2;
    u32 v3;
    v3 = IrqDisable();
    v1 = func_02007040();
    if (v1 == NULL) {
        IrqRestore(v3);
        return NULL;
    }
    if (v1->mUnk_00 == a) {
        func_02007034((u32) v1->mUnk_28);
        IrqRestore(v3);
        return v1;
    }
    for (v2 = v1->mUnk_28; v2 != NULL; v1 = v2, v2 = v2->mUnk_28) {
        if (v2->mUnk_00 == a) {
            v1->mUnk_28 = v2->mUnk_28;
            IrqRestore(v3);
            return v2;
        }
    }
    IrqRestore(v3);
    return NULL;
}

u32 func_02006ddc(u16 a, void (*b)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 2;
    v1.mUnk_08 = a;
    v1.mUnk_10 = b;
    return func_0200704c(&v1);
}

u32 func_02006db0(u16 a, u32 b, const void *c, void (*d)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 6;
    v1.mUnk_08 = a;
    v1.mUnk_10 = d;
    v1.mUnk_14 = b;
    v1.mUnk_18 = 0x28;
    MemCopyWords(c, &v1.mUnk_1c, 0x40);
    return func_0200704c(&v1);
}

u32 func_02006d78(u16 a, u32 b, const void *c, u32 d, const void *e, void (*f)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    v1.mUnk_00 = 4;
    v1.mUnk_08 = a;
    v1.mUnk_10 = f;
    v1.mUnk_14 = b;
    v1.mUnk_18 = d;
    MemCopyWords(c, &v1.mUnk_1c, 0x40);
    MemCopyWords(e, &v1.mUnk_5c, 0x40);
    return func_0200704c(&v1);
}

u32 func_02006d3c(u16 a, const void *b, s32 c, void (*d)(void)) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc_9c *v2;
    if (c < 0 || c > 9) {
        return 0;
    }
    v1.mUnk_00 = 10;
    v2 = &v1;
    v2->mUnk_08 = a;
    v2->mUnk_10 = (void (*)(Unk0216f3dc_9c *)) d;
    MemCopy(b, &v2->mUnk_14, c);
    *((u8 *) v2 + 0x1d) = c;
    return func_0200704c(&v1);
}

s32 func_02006c2c(s32 a, s32 b) {
    Unk0216f3dc *v1;
    s32 i;
    s32 v2;
    v1 = func_020070b8();
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = func_02005cc8(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005d4c(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005b80(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
        v2 = func_02005d08(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    v2 = func_02005a30(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    v2 = func_0200589c(v1, a, b);
    if (v2 != 0) {
        return v2;
    }
    i = data_0216177c;
    do {
        i++;
        if (i > 15) {
            i = 1;
        }
        v2 = func_02005bec(v1, i, a, b);
        if (v2 != 0) {
            data_0216177c = i;
            return v2;
        }
    } while (i != data_0216177c);
    for (i = 1; i < 16; i++) {
        v2 = func_02005b18(v1, i, a, b);
        if (v2 != 0) {
            return v2;
        }
    }
    return func_020068b4(a, 0xfffe, 0);
}

#pragma thumb off

#pragma thumb on

void func_02006c0c(u32 a, const u8 *b, int c) {
    if (0 < c) {
        func_02005dac(func_020070b8(), a, b, c);
    }
}

void func_02006bec(const u8 *a, u32 b) {
    func_02005dac(func_020070b8(), 0, a, b);
}

#pragma thumb off

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
    v3 = IrqDisable();
    if (data_0216f3c8 == 1) {
        IrqRestore(v3);
        return;
    }
    data_0216f3c8 = 1;
    func_02007008(0);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = NULL;
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
    IrqRestore(v3);
}

void func_02006a10(void (*a)(Unk0216f3dc_9c *)) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc *v2;
    s32 i;
    u32 v3;
    v3 = IrqDisable();
    if (data_0216f3c8 == 1) {
        IrqRestore(v3);
        return;
    }
    data_0216f3c8 = 1;
    func_02007008(-1);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = NULL;
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
    IrqRestore(v3);
}

void func_02006974(void) {
    Unk0216f3dc_9c v1;
    Unk0216f3dc *v2;
    s32 i;
    u32 v3;
    v3 = IrqDisable();
    if (data_0216f3c8 == 0) {
        IrqRestore(v3);
        return;
    }
    data_0216f3c8 = 0;
    func_02007008(-1);
    func_02007034(0);
    v2 = func_020070b8();
    v2->mUnk_000.mUnk_00 = 0;
    v2->mUnk_000.mUnk_08 = 0;
    v2->mUnk_000.mUnk_0a = 0;
    v2->mUnk_000.mUnk_10 = NULL;
    v2->mUnk_138.mUnk_00 = 0;
    v2->mUnk_138.mUnk_08 = 0;
    v2->mUnk_138.mUnk_0a = 0;
    v2->mUnk_138.mUnk_10 = NULL;
    for (i = 0; i < 16; i++) {
        v2->mUnk_1d4[i].mUnk_03 = 0;
    }
    v1.mUnk_00 = 0;
    func_0200704c(&v1);
    func_020070f0();
    func_020070c0(-1);
    func_020070cc(-1);
    IrqRestore(v3);
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
