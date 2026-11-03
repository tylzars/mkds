#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0207e1d4.h"
#include "Main/Unknown/code_0207f05c.h"
#include "Main/Unknown/code_02085984.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_020172d0.h"
#include "code_0201750c.h"

#pragma thumb on

void func_02085fd8(void) {
    Unk021759c0 *p;
    Unk0217aec0 *r;
    data_0217aec0 = NULL;
    p = data_021759c0;
    if (p->mUnk_00c != 5 && p->mUnk_08 != 2 && p->mUnk_00c != 6) {
        r = func_02047950(data_usa_02165990);
        p = data_021759c0;
        if (p->mUnk_08 == 0) {
            r = &r[(p->mCourseId - 1) * 12 + p->mUnk_010];
        } else {
            r = &r[(p->mCourseId - 1) * 12 + (p->mUnk_010 + 1) * 3];
            switch (p->mUnk_014) {
                case 2:
                    r++;
                    break;
                case 3:
                    r += 2;
                    break;
            }
        }
        data_0217aec0 = r;
    }
}

void func_02085e04(void) {
    u16 i;
    BOOL z;
    s32 m;
    data_0217aebc = HeapAlloc(GetHeap(func_020364e8()), 0x144);
    z = FALSE;
    m = -1;
    for (i = 0; (u32) i < 8; i++) {
        data_0217aebc->mUnk_000[i] = z;
        data_0217aebc->mUnk_020[i] = m;
        data_0217aebc->mUnk_040[i] = m;
        data_0217aebc->mUnk_060[i] = m;
        data_0217aebc->mUnk_090[i] = z;
    }
    data_0217aebc->mUnk_080 = m;
    data_0217aebc->mUnk_084 = m;
    data_0217aebc->mUnk_088 = m;
    data_0217aebc->mUnk_08c = z;
    if (data_021759c0->mUnk_08 == 1) {
        data_0217aebc->mUnk_128 = &data_0217561c->mUnk_498;
    } else {
        data_0217aebc->mUnk_128 = &data_0217561c->mUnk_47c;
    }
    if (data_021759c0->mKartCount > 1 && data_021759c0->mKartCount - data_021759c0->mUnk_3d1 == 1) {
        data_0217aebc->mUnk_120 = 1;
        data_0217aebc->mUnk_124 = ((u32) data_021759c0->mUnk_3d1 >> 1) + 1;
    } else {
        data_0217aebc->mUnk_120 = 0;
        data_0217aebc->mUnk_124 = -1;
    }
    if (data_0217aec0 != NULL) {
        func_02085bec();
        func_02085ad8();
        if (data_021759c0->mUnk_08 == 0) {
            switch (data_021759c0->mUnk_010) {
                case 0:
                    data_0217aebc->mUnk_138 = 0;
                    break;
                case 1:
                    data_0217aebc->mUnk_138 = 1;
                    break;
                case 2:
                    data_0217aebc->mUnk_138 = 2;
                    break;
                default:
                    data_0217aebc->mUnk_138 = 1;
                    break;
            }
        } else {
            switch (data_021759c0->mUnk_014) {
                case 1:
                    data_0217aebc->mUnk_138 = 0;
                    break;
                case 2:
                    data_0217aebc->mUnk_138 = 1;
                    break;
                case 3:
                    data_0217aebc->mUnk_138 = 2;
                    break;
                default:
                    data_0217aebc->mUnk_138 = 1;
                    break;
            }
        }
        data_0217aec0->mUnk_04 = func_02147f34(data_0217aec0->mUnk_04, 0x3000);
    }
    func_02085d1c();
    func_0207fba0();
    func_0207e268();
    func_0207c78c();
    if (data_021759c0->mUnk_08 == 2) {
        func_02089974();
        func_02090354();
    }
}

void func_02085d1c(void) {
    u16 j;
    u16 k;
    BOOL f;
    BOOL g;
    Unk021759c0_70 *e;
    j = 0;
    data_0217aebc->mUnk_13c = j;
    for (k = 0; (u32) k < 2; k++) {
        data_0217aebc->mUnk_13e[k] = j;
    }
    for (j = 0; (u32) j < data_021759c0->mKartCount; j++) {
        if (data_021759c0->mUseTeams != 0) {
            for (k = 0; (u32) k < 2; k++) {
                f = FALSE;
                if ((u32) data_021759c0->mUnk_68[j].mUnk_08.mUnk_00 > 3) {
                } else if ((1 << data_021759c0->mUnk_68[j].mUnk_08.mUnk_00) & 0xd) {
                    f = TRUE;
                }
                if (f != FALSE && k == data_021759c0->mUnk_68[j].mUnk_08.mTeamIndex) {
                    data_0217aebc->mUnk_13e[k]++;
                    break;
                }
            }
        } else {
            g = FALSE;
            e = &data_021759c0->mUnk_68[j].mUnk_08;
            if ((u32) e->mUnk_00 <= 3 && ((1 << e->mUnk_00) & 0xd)) {
                g = TRUE;
            }
            if (g != FALSE) {
                data_0217aebc->mUnk_13c++;
            }
        }
    }
}

void func_02085bec(void) {
    u16 i0;
    s32 m0;
    s32 m1;
    s16 i;
    u16 k;
    s32 v;
    BOOL f;
    s32 v1;

    i0 = 0;
    m0 = 0;
    m1 = 0;
    for (; (u32) i0 < 2; i0++) {
        data_0217aebc->mUnk_114[i0] = 0;
    }
    data_0217aebc->mUnk_110 = 1;
    data_0217aebc->mUnk_11c = 0;
    if (data_021759c0->mUnk_08 == 0) {
        for (i = 0; i < data_021759c0->mKartCount; i++) {
            k = i;
            v = func_0205d3f0(k);
            f = FALSE;
            if ((u32) data_021759c0->mUnk_68[k].mUnk_08.mUnk_00 <= 3 &&
                ((1 << data_021759c0->mUnk_68[k].mUnk_08.mUnk_00) & 0xd)) {
                f = TRUE;
            }
            if (f != FALSE) {
                if (v > m0) {
                    m0 = v;
                }
            } else {
                if (v > m1) {
                    m1 = v;
                }
                if (i == data_021759c0->mUnk_3d5[0]) {
                    data_0217aebc->mUnk_114[0] = v;
                } else if (i == data_021759c0->mUnk_3d5[1]) {
                    data_0217aebc->mUnk_114[1] = v;
                }
            }
        }
        v1 = m0 - m1;
        if (v1 <= -5) {
            if (data_021759c0->mUnk_3d4 > 1) {
                data_0217aebc->mUnk_110 = 0;
                if (data_0217aebc->mUnk_114[0] > data_0217aebc->mUnk_114[1]) {
                    data_0217aebc->mUnk_11c = 1;
                }
            }
        } else if (data_021759c0->mUnk_014 != 1 && v1 >= 4) {
            data_0217aebc->mUnk_110 = 2;
        }
    }
}

void func_02085ad8(void) {
    u16 a;
    u16 b;
    u16 i;
    u16 k;
    u16 n;
    u16 q;
    u16 j;
    Unk021759c0 *p;
    s32 v;
    BOOL f;
    u32 g;
    a = 0;
    b = 0;
    g = data_021759c0->mKartCount;
    func_02017538(&data_0217aebc->mUnk_12c, 4);
    for (i = 0; (u32) i < 2; i++) {
        if (data_021759c0->mUnk_3d5[i] >= 0) {
            a++;
        }
    }
    n = data_021759c0->mKartCount;
    for (k = 0; (u32) k < n; k++) {
        f = FALSE;
        if ((u32) data_021759c0->mUnk_68[k].mUnk_08.mUnk_00 <= 3 &&
            ((1 << data_021759c0->mUnk_68[k].mUnk_08.mUnk_00) & 0xd)) {
            f = TRUE;
        }
        if (f != FALSE) {
            b++;
        }
    }
    q = n - b - a;
    j = 0;
    for (; j < q; j++) {
        data_0217aebc->mUnk_0b0[j].mUnk_00 = (u16) (j + a + 1);
        func_020174a4(&data_0217aebc->mUnk_12c, &data_0217aebc->mUnk_0b0[j]);
    }
    a = 0;
    p = data_021759c0;
    for (; (u32) a < p->mKartCount; a++) {
        if (p->mUnk_08 == 1) {
            v = a;
        } else {
            v = func_02085984(a, &g);
        }
        data_0217aebc->mUnk_090[a] = v;
        p = data_021759c0;
    }
}

s32 func_02085984(u16 a, u32 *b) {
    s32 r;
    BOOL v1;
    BOOL g;
    BOOL f;
    s32 s;
    s32 m;
    s32 v;
    u16 k;
    Unk02017328 *l;
    u16 n;
    u32 h;
    u16 x;
    u16 y;
    Unk0217aebc *d;
    Unk021759c0 *p;
    Unk0217aebc_128 *c;
    Unk0217aebc_0b0 *e;
    v1 = FALSE;
    r = -1;
    d = data_0217aebc;
    m = d->mUnk_110;
    if (m == 2) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    f = FALSE;
    p = data_021759c0;
    s = p->mUnk_68[a].mUnk_08.mUnk_00;
    if ((u32) s <= 3 && ((1 << s) & 0xd)) {
        f = TRUE;
    }
    if (f != FALSE) {
        r = *b;
        *b = r - 1;
    } else {
        if (m == 0) {
            s = d->mUnk_11c;
            if (s != 0) {
                s = 1;
            } else {
                s = 0;
            }
            if (s == 0) {
                v = 1;
            } else {
                v = 0;
            }
            if (a == p->mUnk_3d5[s]) {
                r = 1;
                v1 = TRUE;
            } else if (a == (u16) p->mUnk_3d5[v]) {
                r = 2;
                v1 = TRUE;
            }
        } else {
            for (k = 0; (u32) k < 2; k++) {
                s = p->mUnk_3d5[k];
                if (s == a) {
                    if (k == 0) {
                        r = 1;
                    } else {
                        r = 2;
                        if (g != FALSE) {
                            r = 1;
                        }
                    }
                    v1 = TRUE;
                    break;
                }
            }
        }
        if (v1 == FALSE) {
            l = &data_0217aebc->mUnk_12c;
            n = l->mUnk_08;
            c = data_0217aebc->mUnk_128;
            x = n - 1;
            if (x == 0) {
                h = 0;
            } else {
                c->mUnk_00 = (s64) c->mUnk_08 * (s64) c->mUnk_00 + c->mUnk_10;
                y = (u16) n - 1;
                if (y == 0) {
                    h = c->mUnk_00 >> 32;
                } else {
                    h = (s64) (u32) (c->mUnk_00 >> 32) * (s64) (u32) y >> 32;
                }
            }
            e = func_020172d8(l, (u16) h);
            r = e->mUnk_00;
            func_02017354(l, e);
        }
    }
    return r;
}

#pragma thumb off
