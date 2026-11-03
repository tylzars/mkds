#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ba520.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b846c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020f830c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "code_020222ec.h"

static inline Unk020ee684 *func_020bab54_inline(u32 o) {
    return (Unk020ee684 *) ((u32) data_027e00c8 + o);
}

void func_020bab54(void) {
    s32 e;
    u32 i;
    s32 n;
    s32 v;
    s32 s;
    u32 k;
    Unk0212c400 **r;
    Unk0212c400 **r2;
    u32 k2;
    Unk0217b3cc_18 *w;
    Unk020ee684 *c;

    n = data_0217b3cc->mUnk_04;
    i = func_020b4d9c() * 0x210;
    e = func_020bab54_inline(i)->mUnk_028;
    data_0217b3cc->mUnk_14 = data_0217b3cc->mUnk_10;
    v = 0x13;
    c = func_020bab54_inline(i);
    if (c->mUnk_000 == 1) {
        data_0217b3cc->mUnk_04 = c->mUnk_004;
        n = data_0217b3cc->mUnk_04;
        data_0217b3cc->mUnk_10 = 1;
    } else if (n == 0) {
        data_0217b3cc->mUnk_10 = 0;
    } else if (n > 0 && n < 0xd6) {
        data_0217b3cc->mUnk_04 += 1;
        n = data_0217b3cc->mUnk_04;
        switch (n) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                data_0217b3cc->mUnk_04 = 0xd6;
                n = data_0217b3cc->mUnk_04;
                break;
        }
        data_0217b3cc->mUnk_10 = 1;
    } else if (n >= 0xd6 && n < e + 0xd5) {
        data_0217b3cc->mUnk_04 += 1;
        n = data_0217b3cc->mUnk_04;
        data_0217b3cc->mUnk_10 = 1;
    } else {
        func_0212c6f0((Unk0212c400 **) func_02108e88(), 0);
        data_0217b3cc->mUnk_04 = 0;
        n = data_0217b3cc->mUnk_04;
        if (func_020bab54_inline(i)->mUnk_00c >= 9) {
            if (data_021759c0->mUnk_00c != 2) {
                k = 0x40;
                if (data_021759c0->mCourseId == 0x21) {
                    k = 0x1c6;
                }
                if ((data_0217c780 & 1) != 0) {
                    r = func_0210e128(func_02108ea0(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*r != NULL) {
                            func_0212c6f0(r, 0);
                        }
                        if (*r != NULL) {
                            func_0212c6f0(r, 0);
                        }
                        func_0212ecc0(r, 0, k);
                    }
                }
            }
        } else {
            if (data_021759c0->mUnk_00c != 2) {
                k = 0x3f;
                if (data_021759c0->mCourseId == 0x21) {
                    k = 0x1c5;
                }
                if ((data_0217c780 & 1) != 0) {
                    r = func_0210e128(func_02108ea0(0));
                    if (data_0217d084.mUnk_0c != 0) {
                        if (*r != NULL) {
                            func_0212c6f0(r, 0);
                        }
                        if (*r != NULL) {
                            func_0212c6f0(r, 0);
                        }
                        func_0212ecc0(r, 0, k);
                    }
                }
            }
        }
        data_0217b3cc->mUnk_10 = 0;
    }
    if (data_0217b3cc->mUnk_14 == 0 && data_0217b3cc->mUnk_10 != 0 && data_021759c0->mUnk_00c != 2) {
        r2 = (Unk0212c400 **) func_02108e88();
        k2 = 0x3e;
        if (data_021759c0->mCourseId == 0x21) {
            k2 = 0x1c4;
        }
        if ((data_0217c780 & 1) != 0) {
            if (data_0217d084.mUnk_0c != 0) {
                if (*r2 != NULL) {
                    func_0212c6f0(r2, 0);
                }
                if (*r2 != NULL) {
                    func_0212c6f0(r2, 0);
                }
                func_0212ecc0(r2, 0, k2);
            }
        }
    }
    c = func_020bab54_inline(i);
    if (c->mUnk_000 == 0) {
        data_0217b3cc->mUnk_0c = c->mUnk_030.mUnk_00 == 0x13 ? c->mUnk_014 : c->mUnk_030.mUnk_00;
    } else {
        switch (n) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
            case 10:
            case 12:
            case 14:
            case 16:
            case 18:
            case 22:
            case 26:
            case 30:
            case 34:
            case 38:
            case 42:
            case 46:
            case 50:
            case 54:
            case 58:
            case 62:
            case 66:
            case 70:
            case 74:
            case 78:
            case 86:
            case 94:
            case 102:
            case 110:
            case 118:
            case 134:
            case 150:
            case 166:
            case 182:
            case 198:
            case 214:

                data_0217b3cc->mUnk_0c = c->mUnk_00c;
                func_020f830c(func_020bab54_inline(i));
                break;
        }
        v = func_020bab54_inline(i)->mUnk_00c;
        data_0217b3cc->mUnk_18.mUnk_00 = 0;
    }
    if (n < 6) {
        s = 0;
    } else if (n < 0x12) {
        s = ((n - 6) & 1) << 5 >> 1;
    } else if (n < 0x4e) {
        s = ((n - 0x12) & 3) << 5 >> 2;
    } else if (n < 0x76) {
        s = ((n - 0x4e) & 7) << 5 >> 3;
    } else if (n < 0xd6) {
        s = ((n - 0x76) & 0xf) << 5 >> 4;
    } else if (n >= e + 0xd6) {
        s = 0;
    } else {
        s = ((n - 0xd6) & ((s32) func_020bab54_inline(i)->mUnk_028 - 1)) << 5 >> func_020bab54_inline(i)->mUnk_02c;
    }
    if (data_0217b3cc->mUnk_18.mUnk_00 != 0) {
        w = &data_0217b3cc->mUnk_18;
        w->mUnk_08 += w->mUnk_0c;
        w->mUnk_0c += (s32) (((s64) (w->mUnk_10 - w->mUnk_08) * 0x333) >> 12);
        w->mUnk_0c = (s32) (((s64) w->mUnk_0c * 0xc00) >> 12);
        w->mUnk_04 = (s32) (((s64) w->mUnk_10 * 0x2000) >> 12) - w->mUnk_08;
        data_0217b3cc->mUnk_18.mUnk_00 += 1;
        if (data_0217b3cc->mUnk_18.mUnk_10 == 0xb33 && data_0217b3cc->mUnk_18.mUnk_00 > 7) {
            data_0217b3cc->mUnk_18.mUnk_10 = 0x1000;
        } else if (data_0217b3cc->mUnk_18.mUnk_10 == 0x1000 && data_0217b3cc->mUnk_18.mUnk_00 > 10) {
            data_0217b3cc->mUnk_18.mUnk_00 = 0;
        }
    }
    if (func_020bab54_inline(i)->mUnk_204 != 0) {
        s32 q;
        q = func_020bab54_inline(i)->mUnk_030.mUnk_00 == 0x13 ? func_020bab54_inline(i)->mUnk_014
                                                              : func_020bab54_inline(i)->mUnk_030.mUnk_00;
        if (q == 0xd) {
            data_0217b3cc->mUnk_18.mUnk_00 += 1;
            data_0217b3cc->mUnk_18.mUnk_04 = 0x1000;
            data_0217b3cc->mUnk_18.mUnk_08 = 0x1000;
            data_0217b3cc->mUnk_18.mUnk_0c = -0x19a;
            data_0217b3cc->mUnk_18.mUnk_10 = 0xb33;
        }
    }
    data_0217b3cc->mUnk_00 = s;
    data_0217b3cc->mUnk_08 = v;
}

void func_020ba63c(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 w[4];
    s32 x;
    s32 y;
    Unk020224e0_c *t;
    Unk020224e0_c *r;
    s32 l;
    Unk020224e0_o *q;
    Unk020224e0_o *o;
    u16 k;

    x = data_0217b3cc->mUnk_00;
    y = data_0217b3cc->mUnk_08;
    r = GetRaceMNcerEntry(data_021759c0->mUseTeams == 0                                     ? 8
                          : data_021759c0->mUnk_68[func_020b4d9c()].mUnk_08.mTeamIndex == 0 ? 9
                                                                                            : 10);
    if (data_021759c0->mUnk_00c == 4) {
        return;
    }
    if (data_021759c0->mUnk_00c == 1) {
        return;
    }
    t = GetRaceMNcerEntry(0xc);
    a[0] = 0x18000;
    a[1] = 0x18000;
    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
    l = p->mUnk_400;
    b[0] = 0x18000;
    b[1] = 0x18000;
    q = &p->mUnk_000[l];
    p->mUnk_400 += func_020224e0(q, 0x80 - l, r, NULL, b, 0, 1);
    for (; l < p->mUnk_400; l++, q++) {
        ((u32 *) q)[0] = (((u32 *) q)[0] & ~0xc00) | 0x800;
        ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
    }
    l = p->mUnk_400;
    c[0] = 0x18000;
    c[1] = 0x18000;
    q = &p->mUnk_000[l];
    p->mUnk_400 += func_020224e0(q, 0x80 - l, r, NULL, c, 0, 1);
    for (; l < p->mUnk_400; l++, q++) {
        ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
    }
    if (data_0217b3cc->mUnk_18.mUnk_00 == 0) {
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(y));
        d[0] = 0x18000;
        d[1] = (x - 8) << 12;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(data_0217b3cc->mUnk_0c));
        e[0] = 0x18000;
        e[1] = (x + 0x18) << 12;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
    } else {
        k = func_020ae5c4(p);
        w[0] = func_02147f34(0x1000, data_0217b3cc->mUnk_18.mUnk_04);
        w[1] = 0;
        w[2] = 0;
        w[3] = func_02147f34(0x1000, data_0217b3cc->mUnk_18.mUnk_08);
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(y));
        l = p->mUnk_400;
        f[0] = 0x18000;
        f[1] = (x - 8) << 12;
        q = &p->mUnk_000[l];
        p->mUnk_400 += func_020224e0(q, 0x80 - l, t, w, f, k, 1);
        for (; l < p->mUnk_400; l++, q++) {
            ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
        }
        t = GetRaceMNcerEntry(LookupRaceMNcerIndex(data_0217b3cc->mUnk_0c));
        l = p->mUnk_400;
        g[0] = 0x18000;
        g[1] = (x + 0x18) << 12;
        q = &p->mUnk_000[l];
        p->mUnk_400 += func_020224e0(q, 0x80 - l, t, w, g, k, 1);
        for (; l < p->mUnk_400; l++, q++) {
            ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
        }
        o = &p->mUnk_000[k * 4];
        o[0].mUnk_00[3] = w[0] >> 4;
        o[1].mUnk_00[3] = w[1] >> 4;
        o[2].mUnk_00[3] = w[2] >> 4;
        o[3].mUnk_00[3] = w[3] >> 4;
    }
    t = GetRaceMNcerEntry(0xb);
    h[0] = 0x18000;
    h[1] = 0x18000;
    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
}

s32 func_020ba620(void) {
    if (data_0217b3c8 != NULL) {
        return data_0217b3c8->mUnk_08;
    }
    return 0;
}

void func_020ba520(void) {
    Unk0217b3c8 *q;
    s32 v;

    q = HeapAlloc(GetHeap(func_020364e8()), 0xc);
    data_0217b3c8 = q;
    v = data_021759c0->mUnk_08;
    switch (v) {
        case 4:
            data_0217b3c8->mUnk_00 = v == 4 ? func_ov001_02181820() : 0;
            data_0217b3c8->mUnk_04 = data_021759c0->mUnk_37;
            break;
        case 2:
            switch (data_021759c0->mUnk_18) {
                case 0:
                    q->mUnk_00_h[0] = 0;
                    data_0217b3c8->mUnk_00_h[1] = func_020a10d4(func_020b4d9c());
                    break;
                case 1:
                default:
                    data_0217b3c8->mUnk_00_h[0] = func_020a1154(func_020b4d9c());
                    break;
            }
            break;
        case 1:
            break;
        default:
            data_0217b3c8->mUnk_00 = func_0203c8dc(func_020b4d9c()) - 1;
            break;
    }
    data_0217b3c8->mUnk_08 = 1;
}
