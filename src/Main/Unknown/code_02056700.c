#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02056a4c(Unk0217aa08_10_04 *a, Unk02056a2c *b) {
    if (b->mUnk_00 != 0) {
        a->mUnk_00_0 = 1;
        a->mUnk_00_1 = b->mUnk_01;
    } else {
        a->mUnk_00_0 = 0;
    }
}

void func_02056a2c(Unk0217aa08_10_04 *a, Unk02056a2c *b) {
    if (a->mUnk_00_0 != 0) {
        b->mUnk_00 = 1;
        b->mUnk_01 = a->mUnk_00_1;
    } else {
        b->mUnk_00 = 0;
    }
}

void func_02056a04(s32 a, s32 b, Unk02056a2c *c) {
    func_02056a4c(&data_0217aa08->mUnk_10->mUnk_04[(a - 1) * 9 + b - 1], c);
}

s32 func_020569dc(s32 a, s32 b, Unk02056a2c *c) {
    func_02056a2c(&data_0217aa08->mUnk_10->mUnk_04[(a - 1) * 9 + b - 1], c);
    return 1;
}

void func_020569a8(void *a) {
    func_0214d1fc(a, data_0217aa08->mUnk_04->mUnk_008, 0x200);
    data_0217aa08->mUnk_04->mUnk_004 = 1;
    func_02056430();
}

void func_02056750(s32 a, u16 b) {
    Unk0217aa08_14 *p;
    s32 k;
    s32 n;
    u8 m;
    u8 i;
    u8 j;
    s32 t[4];
    Unk02056750_c v;
    u8 v1[0xf];
    u32 w;

    n = func_0204684c();
    k = data_021759c0->mUnk_68[b].mUnk_08.mUnk_0c;
    p = data_0217aa08->mUnk_14;
    if (n == -1) {
        return;
    }
    func_0214d168(p, 0, 0xe00);
    func_0203bfec(t);
    p->mUnk_04_16 = t[0];
    p->mUnk_04_23 = t[1];
    p->mUnk_04_27 = t[2];
    w = data_021759c0->mUnk_68[b].mUnk_00;
    p->mUnk_04_0 = (u8) w;
    w = data_021759c0->mUnk_68[b].mUnk_04;
    p->mUnk_04_4 = (u8) w;
    w = data_021759c0->mUnk_00;
    p->mUnk_04_10 = (u8) w;
    p->mUnk_08_0 = 1;
    p->mUnk_08_1 = 0;
    p->mUnk_08_2 = data_021759d0->mUnk_00;
    p->mUnk_08_4 = 0;
    p->mUnk_2f_0 = func_02056208();
    func_0203c7cc(b, &v.mUnk_00, &v.mUnk_01, &v.mUnk_02);
    p->mUnk_08_8 = v.mUnk_00;
    p->mUnk_08_15 = v.mUnk_01;
    p->mUnk_08_22 = v.mUnk_02;
    func_0214d1fc(data_0217aa08->mUnk_00->mUnk_0c, p->mUnk_0c, 0x14);
    func_0214d1fc(data_02175628[k].mUnk_28, p->mUnk_30, 0xdcc);
    func_0214d168(v1, 0, 0xf);
    for (i = 1; i <= (s32) func_02044618(); i++) {
        j = (i - 1) * 3;
        func_0203c778(b, i, &v.mUnk_00, &v.mUnk_01, &v.mUnk_02);
        w = 0;
        w |= (v.mUnk_00 & 0x7f) << 17;
        w |= (v.mUnk_01 & 0x7f) << 10;
        w |= v.mUnk_02 & 0x3ff;
        v1[j] = w >> 16;
        v1[j + 1] = w >> 8;
        v1[j + 2] = w;
    }
    func_0214d1fc(v1, p->mUnk_20, 0xf);
    m = n;
    func_020579d0(m, p);
    if (func_020573f8(m) == 0) {
        func_0205746c(m, data_0217aa08->mUnk_00->mUnk_26, 4);
        func_020574a0();
    }
}

void func_02056700(void) {
    s32 n;
    s32 f;
    Unk0217aa08_14 *p;

    f = 0;
    n = func_0204684c();
    p = data_0217aa08->mUnk_14;
    if (n == -1) {
        f = 1;
    } else if (func_020573f8(n) == 0) {
        f = 1;
    }
    if (f != 0) {
        p->mUnk_08_0 = 0;
    } else {
        func_0205798c(n, p);
    }
}

#pragma thumb off
