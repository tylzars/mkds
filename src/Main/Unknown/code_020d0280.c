#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c70d8.h"
#include "Main/Unknown/code_02044000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020c7000.h"

void func_020d0a18(void) {
    u8 a;
    u8 b;
    u16 c;
    u16 i;
    s32 v;

    if (data_021759c0->mUnk_08 != 0 && data_021759c0->mUnk_08 != 1) {
        return;
    }
    func_0203c7cc(func_020b4d9c(), &a, &b, &c);
    func_020ae7c4(a, b, c, &data_0217b49c->mUnk_00);
    for (i = 0; i < func_02044618(); i++) {
        func_0203c778(func_020b4d9c(), i + 1, &a, &b, &c);
        func_020ae7c4(a, b, c, &data_0217b49c->mUnk_1c[i]);
    }
    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    if (func_020c7148() == 0 && func_020c70ec() == 0) {
        return;
    }
    data_0217b49c->mUnk_a8++;
    if (data_0217b49c->mUnk_a8 >= 0x10) {
        data_0217b49c->mUnk_a8 = 0;
    }
    v = data_0217b49c->mUnk_a8 % 16;
    if (v < 4) {
        data_0217b49c->mUnk_ac = 0;
        return;
    }
    if (v < 8) {
        data_0217b49c->mUnk_ac = 0xd;
        return;
    }
    if (v < 12) {
        data_0217b49c->mUnk_ac = 0x1a;
    } else {
        data_0217b49c->mUnk_ac = 0xd;
    }
}

void func_020d06b8(Unk020d029c *a) {
    Unk020224e0_c *c;
    s32 q[4][2];
    s32 t[6];
    u16 i;
    s32 n;
    s32 j;
    s32 k;

    n = func_020c5db0();
    if (data_021759c0->mUnk_08 != 0 && data_021759c0->mUnk_08 != 1) {
        return;
    }
    if (data_021759c0->mUnk_00c == 4 || data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (func_020c70bc() != 0) {
        c = GetRaceGoalMNcerEntry(0x43);
        q[0][0] = 0x80000;
        q[0][1] = 0x60000;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[0], 0, 1);
    }
    if (n <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        t[i] = func_020ae4c0(1, 0x80, 0, n - i * 4, 0x14);
    }
    c = GetRaceGoalMNcerEntry((func_020c7148() != 0 ? data_0217b49c->mUnk_ac : 0) + 0x15);
    q[1][0] = (t[0] + 0xa2) << 12;
    q[1][1] = 0x10000;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[1], 0, 1);
    func_020d029c(a, t[0], 0x10, &data_0217b49c->mUnk_00, func_020c7148() != 0 ? data_0217b49c->mUnk_ac : 0);
    c = GetRaceGoalMNcerEntry((func_020c70ec() != 0 ? data_0217b49c->mUnk_ac : 0) + 0x16);
    q[2][0] = (t[1] + 0x99) << 12;
    q[2][1] = 0x28000;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[2], 0, 1);
    for (i = 0; i < func_02044618(); i++) {
        j = 0;
        if (func_020c70ec() != 0 && i + 1 == func_020c70d8()) {
            j = data_0217b49c->mUnk_ac;
        }
        c = GetRaceGoalMNcerEntry(i + 0x18 + j);
        k = i * 16 + 0x28;
        q[3][0] = (t[i + 1] + 0x9e) << 12;
        q[3][1] = k << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[3], 0, 1);
        func_020d029c(a, t[i + 1], k, &data_0217b49c->mUnk_1c[i], j);
    }
}

void func_020d029c(Unk020d029c *a, s32 b, s32 d, Unk020ae7c4 *e, s32 f) {
    Unk020224e0_c *c;
    s32 p0[2];
    s32 p1[2];
    s32 p2[2];
    s32 p3[2];
    s32 p4[2];
    s32 p5[2];
    s32 p6[2];
    s32 p7[2];
    s32 p8[2];
    s32 t[9] = {170, 179, 188, 198, 207, 216, 226, 235, 244};

    if (e->mUnk_00[0] != 0) {
        c = GetRaceGoalMNcerEntry(e->mUnk_00[0] + 0x17 + f);
        p0[0] = (b + t[0]) << 12;
        p0[1] = d << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p0, 0, 1);
    }
    c = GetRaceGoalMNcerEntry(e->mUnk_00[1] + 0x17 + f);
    p1[0] = (b + t[1]) << 12;
    p1[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p1, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p2[0] = (b + t[2]) << 12;
    p2[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p2, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[2] + 0x17 + f);
    p3[0] = (b + t[3]) << 12;
    p3[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p3, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[3] + 0x17 + f);
    p4[0] = (b + t[4]) << 12;
    p4[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p4, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p5[0] = (b + t[5]) << 12;
    p5[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p5, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[4] + 0x17 + f);
    p6[0] = (b + t[6]) << 12;
    p6[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p6, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[5] + 0x17 + f);
    p7[0] = (b + t[7]) << 12;
    p7[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p7, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[6] + 0x17 + f);
    p8[0] = (b + t[8]) << 12;
    p8[1] = d << 12;
    a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p8, 0, 1);
}

s32 func_020d0280(void) {
    return func_020c0c2c(&data_0217b498, 0x1b5);
}
