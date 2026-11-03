#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_021031f4.h"

#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02103890.h"
#include "code_0212c6ac.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02103840.h"

u32 func_02103840(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    value1 = (u32) &data_021759c0;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const s8 *) ((value1) + (98));
    compareLeft0 = value0;
    compareRight0 = value1;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value0 = (u32) &data_0217c658;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft1 = value0;
    compareRight1 = 0u;
    if (compareLeft1 == compareRight1) {
        return value0;
    }
    value1 = (u32) &data_0217c644;
    value0 = (u32) &data_0217c650;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft2 = value1;
    compareRight2 = value2;
    if ((s32) compareLeft2 < (s32) compareRight2) {
        *(u32 *) ((value0) + (0)) = value2;
    }
    return value0;
}

void func_0210366c(Unk021035ac *p) {
    s32 i;
    s32 a;
    s32 b;
    s32 vb;
    s32 va;
    s32 j;
    s16(*q)[2] = p->mUnk_10;

    for (i = 0; i < 4; i++) {
        q[i][0] = 0;
        q[i][1] = 0;
    }
    for (i = 0; i < 4; i++) {
        a = p->mUnk_00[i][0];
        b = p->mUnk_00[i][1];
        if (a > 0) {
            if (a > 0x4cd) {
                va = (s32) (((s64) a * a) >> 12);
            } else {
                va = 0x171;
            }
        } else {
            if (a < 0x4cd) {
                va = -(s32) (((s64) a * a) >> 12);
            } else {
                va = -0x171;
            }
        }
        if (b > 0) {
            if (b > 0x4cd) {
                vb = (s32) (((s64) b * b) >> 12);
            } else {
                vb = 0x171;
            }
        } else {
            if (b < 0x4cd) {
                vb = -(s32) (((s64) b * b) >> 12);
            } else {
                vb = -0x171;
            }
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                q[j][0] += (s32) (((s64) va * 12) >> 12);
                q[j][1] += (s32) (((s64) vb * 12) >> 12);
            } else {
                q[j][0] += (s32) (((s64) va * 8) >> 12);
                q[j][1] += (s32) (((s64) vb * 8) >> 12);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (q[i][1] < 0) {
            q[i][1] = 0;
        }
    }
    p->mUnk_28 = 1;
}

void func_021035ac(int b2) {
    Unk021035ac *e;
    s32 i;
    s32 n;
    s32 a;
    s32 b;

    if (b2 != data_021759c0->mUnk_62) {
        return;
    }
    n = *(s32 *) data_0217c658;
    if (n == 0) {
        return;
    }
    a = *(s32 *) data_0217c644;
    b = *(s32 *) data_0217c650;
    if (b < a) {
        *(s32 *) data_0217c650 = a;
    }
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        e = &((Unk021035ac *) data_0217c654)[i];
        if (e->mUnk_28 == 0 && e->mUnk_24 == (void *) func_0210465c) {
            func_0210366c(e);
        }
        i++;
    } while (i < *(s32 *) data_0217c658);
}

u32 func_02103598(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217c664;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_02103554(const char *a) {
    u32 v;

    func_020e6488((Unk020e6488 **) &v, FindCourseMapObjFile(a), 0, 0);
    func_020e6ab8((Unk020e6488 *) v);
    func_0210340c((Unk0210340c *) data_0217c664, (Unk020e6488 *) v);
}

void func_02103544(u32 a, u32 b) {
    func_02103900(a, b, 1);
}

#pragma thumb on
void func_02103468(void) {
    Unk020e6488 *q;
    s32 i;

    data_0217c654 = func_02036bec(func_020364e0(func_020364e8()), 0xd0);
    data_0217c638 = 0xffff;
    *(u32 *) data_0217c658 = 0;
    data_0217c64c = 0;
    func_0212c6f0((Unk0212c400 **) func_02108e6c(6), 1);
    q = func_020ed4d0(data_0216c7b4, NULL, data_0216c7c4);
    func_0210340c((Unk0210340c *) data_0217c684, q);
    data_0217c63c = func_020d3c2c();
    for (i = 0; i < 3; i++) {
        func_020d3c2c();
    }
    *(u32 *) 0x4000440 = 0;
    *(u32 *) 0x4000444 = 0;
    func_0214ad4c(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x1fb, 1, (Unk0214ad4c *) data_0217c6a4);
    *(u32 *) 0x4000448 = 1;
}

void func_0210340c(Unk0210340c *p, Unk020e6488 *q) {
    u32 t;

    p->mUnk_00 = q;
    p->mUnk_04 = 0x51f80c0;
    p->mUnk_04 = p->mUnk_04 & 0xc0ffffff;
    p->mUnk_08 = *q->mUnk_1c;
    p->mUnk_0c = *q->mUnk_20;
    p->mUnk_10 = q->mUnk_0c;
    p->mUnk_14 = q->mUnk_10;
    t = p->mUnk_08;
    p->mUnk_18 = 1 << (((t & 0x3800000) >> 0x17) + 0xf);
    p->mUnk_1c = 1 << (((t & 0x700000) >> 0x14) + 0xf);
}
#pragma thumb off

void func_021031f4(Unk02102674 *p) {
    s32 b3;
    s32 a;
    s32 b2;
    s32 i;
    Unk0217561c *q;
    Unk020f41c4_B *b;
    Unk0206bcb0 *r;
    u16 j;
    u32 n;
    u16 v;

    b2 = (u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8);
    a = data_021759c0->mUnk_62;
    if (data_021759c0->mUnk_08 == 2) {
        b3 = data_021759c0->mKartCount;
        for (i = 0; i < b3; i++) {
            if (i == b2) {
                continue;
            }
            r = func_0207a974(i);
            if (r->mUnk_7c & 0x402020) {
                continue;
            }
            if (r->mUnk_4c & 0x10000840) {
                continue;
            }
            if (r->mUnk_48 & 0x10000) {
                continue;
            }
            q = data_0217561c;
            b = &q->mUnk_498;
            b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
            p->mUnk_130[i] = (u16) (((b->mUnk_00 >> 32) * 4) >> 32) + 1;
        }
    } else {
        j = 1;
        n = func_0203c8dc(b2);
        do {
            v = (u16) data_0217561c->mUnk_474[(u8) j - 1];
            r = func_0207a974(v);
            if ((r->mUnk_7c & 0x402020) == 0 && (r->mUnk_4c & 0x10000840) == 0 && (r->mUnk_48 & 0x10000) == 0) {
                p->mUnk_130[v] = 4 - ((j - 1) >> 1);
            }
            j++;
        } while (j < n);
    }
    if (a < 0 || p->mUnk_130[a] == 0) {
        p->mUnk_198 = 0;
        return;
    }
    p->mUnk_198 = 1;
    p->mUnk_12c = func_0207a974(a);
    func_020f8e3c((u32) p->mUnk_12c, 0xf3);
}
