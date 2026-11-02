#include "Main/Unknown/code_020bcb74.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020bd850.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"

void func_020bd178(Unk020d029c *a) {
    s32 s;
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 q9[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = 0;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        s = 0;
        if (data_021759c0->mUnk_08 == 2 && func_020a1084((u16) k) != 0) {
            s = 1;
        } else if (data_021759c0->mUnk_08 != 2 && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            s = 1;
        }
        s = s != 0 ? 0x6d : 0x65;
        c = GetRaceSNcerEntry(s + k);
        q3[0] = (p.mUnk_00 + 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q3, 0, 1);
        if (data_021759c0->mUnk_18 == 0) {
            s32 t = data_0217b3d8->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q4[0] = (p.mUnk_00 + 0x57) << 12;
            q4[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q4, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q5[0] = (p.mUnk_00 + 0x5c) << 12;
            q5[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q5, 0, 1);
        } else {
            s32 t = data_0217b3d8->mUnk_0c0[k] / 10;
            s32 u = data_0217b3d8->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q6[0] = (p.mUnk_00 + 0x57) << 12;
            q6[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q6, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q7[0] = (p.mUnk_00 + 0x54) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q7, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q8[0] = (p.mUnk_00 + 0x5c) << 12;
            q8[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q8, 0, 1);
        }
        v = 0;
        if (data_021759c0->mUnk_08 == 2 && func_020a1084((u16) k) != 0) {
            v = 1;
        } else if (data_021759c0->mUnk_08 != 2 && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUnk_58 != 0 && data_021759c0->mUnk_68[(u16) k].mUnk_08.mUnk_04 == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x81);
        q9[0] = (p.mUnk_00 - 0xb) << 12;
        q9[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q9, 0, 1);
    }
}

void func_020bcbe8(Unk020d029c *a) {
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = 0;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        if (data_021759c0->mUnk_18 == 0) {
            s32 t = data_0217b3d8->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q3[0] = (p.mUnk_00 + 0x25) << 12;
            q3[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q3, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q4[0] = (p.mUnk_00 + 0x2a) << 12;
            q4[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q4, 0, 1);
        } else {
            s32 t = data_0217b3d8->mUnk_0c0[k] / 10;
            s32 u = data_0217b3d8->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q5[0] = (p.mUnk_00 + 0x25) << 12;
            q5[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q5, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q6[0] = (p.mUnk_00 + 0x22) << 12;
            q6[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q6, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q7[0] = (p.mUnk_00 + 0x2a) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q7, 0, 1);
        }
        v = 0;
        if (data_021759c0->mUnk_08 == 2 && func_020a1084((u16) k) != 0) {
            v = 1;
        } else if (data_021759c0->mUnk_08 != 2 && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUnk_58 != 0 && data_021759c0->mUnk_68[(u16) k].mUnk_08.mUnk_04 == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x85);
        q8[0] = (p.mUnk_00 - 0xb) << 12;
        q8[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, 0, q8, 0, 1);
    }
}

void func_020bcb74(void) {
    data_0217b3d4 = func_02036bec(func_020364e0(func_020364e8()), 0x14);
    data_0217b3d4->mUnk_00 = 0;
    data_0217b3d4->mUnk_04 = 0;
    data_0217b3d4->mUnk_08 = (u16) (func_02044618() - 1);
    data_0217b3d4->mUnk_0c = 0;
    data_0217b3d4->mUnk_10 = 1;
}
