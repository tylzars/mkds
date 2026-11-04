#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_0214d954.h"

#pragma thumb on

void func_0203be88(u8 *a, u32 b, u32 c) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    p->mUnk_00 |= 1 << b;
    p->mUnk_24[b] = c;
}

void func_0203bea4(u8 *a, u32 b, u32 c) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    p->mUnk_01 |= 1 << b;
    p->mUnk_04[b] = c;
}

void func_0203bec0(u8 *a) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    u8 i;
    p->mUnk_00 = 0;
    p->mUnk_01 = 0;
    for (i = 0; i < 8; i++) {
        p->mUnk_04[i] = -1;
        p->mUnk_24[i] = -1;
    }
}

u8 *func_0203bedc(void *a) {
    Unk0203ba84 *p;
    void *t;
    p = HeapAlloc(a, 0x48);
    t = func_02056444(a);
    p->mUnk_44 = t;
    func_0203bec0((u8 *) p);
    return (u8 *) p;
}

#pragma thumb off

void func_0203bf04(Unk0203bf04_a *a, Unk0203bf04_b *b) {
    MemCopy(a, b, 0x30);
    MemCopy(a->mUnk_030, b->mUnk_230, 0xdcc);
    if (data_0217aa08->mUnk_04->mUnk_004 != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        MemCopy(data_0217aa08->mUnk_04->mUnk_008, b->mUnk_030, 0x200);
        b->mUnk_008 |= 2;
    } else {
        MemFill(b->mUnk_030, 0, 0x200);
        b->mUnk_008 &= ~2;
    }
    b->mUnk_02f_0 = func_02056208();
}

void func_0203bfc4(Unk0203bfc4 *a) {
    if (func_0214df78((u32 *) a) != 0) {
        a->mUnk_00 = 0;
        a->mUnk_04 = 0;
        a->mUnk_08 = 0;
    }
}

void func_0203bfec(s32 *a) {
    if (func_0214e038((u32 *) a) != 0) {
        a[0] = 5;
        a[1] = 1;
        a[2] = 1;
    }
}

u32 func_0203c018(Unk020487fc *a) {
    Unk021a9034 b = data_usa_02164798;
    func_020487fc(a, &b);
    return 0;
}

void func_0203c060(s32 a) {
    func_02037a40();
    func_020ada2c(a);
}
