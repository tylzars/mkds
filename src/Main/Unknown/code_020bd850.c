#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_020bd850.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b8000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020bcb74.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020bd7f8.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"

void func_020be3e4(void) {
    Unk0217b3d8_00 t[9] = {{0x1b, 0xf},  {0x1b, 0xf},  {0x1b, 0x26}, {0x1b, 0x3d}, {0x1b, 0x54},
                           {0x1b, 0x6b}, {0x1b, 0x82}, {0x1b, 0x99}, {0x1b, 0xb0}};
    Unk0217b3d8_00 v1;
    Unk0217b3d8_00 v2;
    Unk0217b3d8_00 v3;
    s32 b[8];
    s32 e;
    s32 k;
    u8 i;
    Unk020ee684 *o;

    e = data_0217b3d8->mUnk_0f8;
    if (func_020b33f4() <= 0x188) {
        data_0217b3d8->mUnk_0e0 = (0x20 - (func_020b33f4() - 0x168)) * 4;
    } else {
        data_0217b3d8->mUnk_0e0 = 0;
    }
    if (func_020b33f4() < 0x168) {
        return;
    }
    if (data_021759c0->mUnk_08 == 1) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        return;
    }
    if (data_021759c0->mUnk_08 == 2) {
        for (i = 0; i < (s32) data_021759c0->mUnk_3d0; i++) {
            data_0217b3d8->mUnk_0c0[i] = func_020a1154(i);
        }
    }
    for (i = 0; i < (s32) data_021759c0->mUnk_3d0; i++) {
        o = &data_027e00c8[i];
        data_0217b3d8->mUnk_040[i] = o->mUnk_030.mUnk_00 == 0x13 ? o->mUnk_014 : o->mUnk_030.mUnk_00;
        if (data_0217b3d8->mUnk_0f8 % 0x1c == 0) {
            data_0217b3d8->mUnk_060[i] = data_0217b3d8->mUnk_080[i];
            data_0217b3d8->mUnk_080[i] = func_0203c8dc(i);
        }
        v1 = t[data_0217b3d8->mUnk_060[i]];
        v2 = t[data_0217b3d8->mUnk_080[i]];
        if (data_0217b3d8->mUnk_060[i] > data_0217b3d8->mUnk_080[i]) {
            if (e < 10) {
                v3.mUnk_00 = v1.mUnk_00 + (e * 16) / 10;
                v3.mUnk_04 = v1.mUnk_04;
            } else if (e < 0x12) {
                k = e - 10;
                v3.mUnk_00 = v1.mUnk_00 + (v2.mUnk_00 - v1.mUnk_00) * k / 8 + 0x10;
                v3.mUnk_04 = v1.mUnk_04 + (v2.mUnk_04 - v1.mUnk_04) * k / 8;
            } else {
                v3.mUnk_00 = v1.mUnk_00 + 0x10 - ((e - 0x12) * 16) / 10;
                v3.mUnk_04 = v2.mUnk_04;
            }
        } else {
            v3.mUnk_00 = v1.mUnk_00 + e * (v2.mUnk_00 - v1.mUnk_00) / 0x1c;
            v3.mUnk_04 = v1.mUnk_04 + e * (v2.mUnk_04 - v1.mUnk_04) / 0x1c;
        }
        data_0217b3d8->mUnk_000[i] = v3;
    }
    for (i = 0; i < (s32) data_021759c0->mUnk_3d0; i++) {
        data_0217b3d8->mUnk_0a0[i] = i;
        b[i] = data_0217b3d8->mUnk_080[i];
    }
    func_020ae770(data_0217b3d8->mUnk_0a0, b, data_021759c0->mUnk_3d0);
    data_0217b3d8->mUnk_0f8++;
    if (data_0217b3d8->mUnk_0f8 >= 0x1c) {
        data_0217b3d8->mUnk_0f8 = 0;
    }
    for (i = 0; i < (s32) data_021759c0->mUnk_3d0; i++) {
        if (data_0217b3d8->mUnk_0fc[i].mUnk_00 != 0) {
            data_0217b3d8->mUnk_0fc[i].mUnk_00++;
            if (data_0217b3d8->mUnk_0fc[i].mUnk_00 > 0x24) {
                data_0217b3d8->mUnk_0fc[i].mUnk_00 = 0;
            }
        }
    }
}

void func_020be2f4(Unk020d029c *a) {
    s32 *e;
    Unk020224e0_o *p;

    if (func_020b33f4() < 0x168) {
        return;
    }
    data_0217b3d8->mUnk_0e4 = func_020ae5c4(a);
    switch (data_021759c0->mUnk_08) {
        case 0:
        case 3:
        case 5:
            func_020bd7f8(a);
            break;
        case 2:
            switch (func_020b1dbc()) {
                case 0:
                    func_020bd178(a);
                    break;
                case 1:
                case 2:
                case 3:
                    func_020bcbe8(a);
                    break;
            }
            break;
    }
    e = data_0217b3d8->mUnk_0e8;
    p = &a->mUnk_000[data_0217b3d8->mUnk_0e4 * 4];
    p[0].mUnk_00[3] = e[0] >> 4;
    p[1].mUnk_00[3] = e[1] >> 4;
    p[2].mUnk_00[3] = e[2] >> 4;
    p[3].mUnk_00[3] = e[3] >> 4;
}

u32 func_020be15c(u16 a) {
    u32 r;
    Unk0217b3d8 *d;
    Unk0217b3d8_fc *e;
    s32 v;

    if (func_020b1cf4(a) != 0) {
        r = 0x25;
    } else if (data_021759c0->mUnk_08 == 2 && func_020a100c(a) != 0) {
        r = 0x24;
    } else if (data_021759c0->mUnk_08 == 2 && func_020a1084(a) != 0) {
        r = 0xc9;
    } else if (data_021759c0->mUnk_08 != 2 && func_0203c880(a) != 0) {
        r = 0x24;
    } else if ((d = data_0217b3d8)->mUnk_0fc[a].mUnk_00 != 0) {
        v = d->mUnk_0fc[a].mUnk_00 - 1;
        if (v % 12 < 6) {
            r = 0xc9;
        } else if ((e = (Unk0217b3d8_fc *) &d->mUnk_0fc[0].mUnk_04)[a].mUnk_00 == 5) {
            switch (d->mUnk_0fc[a].mUnk_08) {
                case 1:
                    r = 0x11;
                    break;
                case 2:
                    r = 0x12;
                    break;
                case 3:
                    r = 0x13;
                    break;
            }
        } else {
            r = LookupRaceSNcerIndex(a, e[a].mUnk_00);
        }
    } else if (d->mUnk_040[a] != 0x13) {
        r = LookupRaceSNcerIndex(a, d->mUnk_040[a]);
    } else if (data_027e00c8[a].mUnk_000 == 1) {
        r = 0x16;
    } else {
        r = 0xc9;
    }
    return r;
}

void func_020bdf08(Unk020d029c *a) {
    s32 t[8][2] = {{8, 0xf}, {8, 0x26}, {8, 0x3d}, {8, 0x54}, {8, 0x6b}, {8, 0x82}, {8, 0x99}, {8, 0xb0}};
    u16 i;
    s32 e;
    s32 j;
    s32 v;
    s32 y;
    s32 q1[2];
    s32 q2[2];
    Unk020224e0_c *c;

    e = data_0217b3d8->mUnk_0e0;
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        j = data_0217b3d8->mUnk_060[i] - 1;
        c = GetRaceSNcerEntry(j + 0x35);
        q1[0] = (t[j][0] - e - 1) << 12;
        y = t[j][1];
        q1[1] = (y - 4) << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        v = 0;
        if (data_021759c0->mUnk_08 == 2 && func_020a1084(i) != 0) {
            v = 1;
        } else if (data_021759c0->mUnk_08 != 2 && (func_020b1cf4(i) != 0 || func_0207a84c(i) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if (i == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUnk_58 != 0 && data_021759c0->mUnk_68[i].mUnk_08.mUnk_04 == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x75);
        q2[0] = -e << 12;
        q2[1] = y << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q2, 0, 1);
    }
}

void func_020bdb34(Unk020d029c *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    u16 f;
    s32 *d;
    s32 s;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
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
        q3[0] = (p.mUnk_00 + 0xa) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
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
        c = GetRaceSNcerEntry(v + 0x79);
        q4[0] = (p.mUnk_00 - 0xb) << 12;
        q4[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
    }
}

void func_020bd850(Unk020d029c *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    s32 *d;
    u16 f;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
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
        c = GetRaceSNcerEntry(v + 0x7d);
        q3[0] = (p.mUnk_00 - 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += func_020224e0(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
    }
}
