#include "Main/Unknown/code_020a02f8.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02068000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02156000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020a1728.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a223c.h"
#include "Main/Unknown/code_020a228c.h"
#include "Main/Unknown/code_020a22ac.h"
#include "Main/Unknown/code_020a2300.h"

void func_020a238c(Unk020a3fa8_a4 *p0) {
    data_0217b1fc->mUnk_3bc = p0;
}

Unk020a3fa8_a4 *func_020a2378(void) {
    return data_0217b1fc->mUnk_3bc;
}

void func_020a2364(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 896) = p0;
}

void func_020a2350(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 900) = p0;
}

void func_020a233c(s32 (*p0)(u16 a, u16 b)) {
    data_0217b1fc->mUnk_388 = p0;
}

void func_020a2328(void (*p0)(u16 a)) {
    data_0217b1fc->mUnk_38c = p0;
}

void func_020a2314(void (*a)(void)) {
    data_0217b1fc->mUnk_390 = a;
}

void func_020a2300(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217b1fc)) + 924) = p0;
}

void func_020a22ac(u16 a) {
    if (func_02061fec() != 1) {
        return;
    }
    if (func_01ffc67c(GetKart(a)) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_64 = 10;
}

void func_020a228c(int a) {
    *(u32 *) (a * 0x70 + (u32) data_0217b1fc + 100) = 0xffffffff;
}

s32 func_020a2264(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_64;
}

s32 func_020a223c(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return -1;
    }
    return data_0217b1fc->mUnk_000[a].mUnk_68;
}

void func_020a2220(u16 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value3 = (u32) &data_0217b1fc;
    value2 = 0x70u;
    value3 = (u32) * (const u32 *) ((value3) + (0));
    value2 = (value0) * (value2) + (value3);
    *(u32 *) ((value2) + (108)) = value1;
}

u32 func_020a2204(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u32 *) ((value1) + (108));
    return value0;
}

void func_020a21bc(s32 a, s32 b) {
    if (b == 0) {
        return;
    }
    if (data_0217b1fc->mUnk_39c != NULL) {
        data_0217b1fc->mUnk_39c(a, b);
    }
}

s32 func_020a1ee4(s32 a, s32 b) {
    Kart *v1;
    Kart *v2;
    Unk0217b1fc_000 *v3;
    Unk0217b1fc_000 *v4;
    BOOL f5;
    s32 f4;
    BOOL f11;
    BOOL t;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v1 = GetKart(a);
    v2 = GetKart(b);
    v4 = &data_0217b1fc->mUnk_000[b];
    v3 = &data_0217b1fc->mUnk_000[a];
    f5 = FALSE;
    if (v4->mUnk_24[a] == 0) {
        if ((v1->mUnk_48 & 0x100000) != 0) {
            f5 = TRUE;
        }
    }
    f4 = 0;
    if (v3->mUnk_24[b] == 0) {
        if ((v2->mUnk_48 & 0x100000) != 0) {
            f4 = 1;
        }
    }
    f11 = TRUE;
    if ((v1->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(a) != 1) {
            f11 = FALSE;
        }
    }
    t = TRUE;
    if ((v2->mUnk_4c & 0x400000) == 0) {
        if (func_0207a8a4(b) != 1) {
            t = FALSE;
        }
    }
    if (f4 != 0) {
        v3->mUnk_24[b] = 1;
    }
    if (f5 != FALSE) {
        v4->mUnk_24[a] = 1;
    }
    if (f11 == FALSE && t == FALSE && f5 != FALSE && f4 != 0) {
        if (data_0217b1fc->mUnk_384 != NULL) {
            data_0217b1fc->mUnk_384(a, b);
            return 1;
        }
    } else if (f11 == FALSE && f4 != 0) {
        f4 = 0;
        if (func_0207a8a4(b) == 1) {
            v3->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != NULL) {
                f4 = data_0217b1fc->mUnk_380(a, b);
                if ((v1->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v1);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != NULL) {
            f4 = data_0217b1fc->mUnk_380(a, b);
            if ((v1->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v1);
            }
        }
        return f4;
    } else if (t == FALSE && f5 != FALSE) {
        f4 = 0;
        if (func_0207a8a4(a) == 1) {
            v4->mUnk_20 = 1;
            if (data_0217b1fc->mUnk_380 != NULL) {
                f4 = data_0217b1fc->mUnk_380(b, a);
                if ((v2->mUnk_4c & 0x400000) == 0) {
                    func_0206c17c(v2);
                }
            }
        } else if (data_0217b1fc->mUnk_380 != NULL) {
            f4 = data_0217b1fc->mUnk_380(b, a);
            if ((v2->mUnk_4c & 0x400000) == 0) {
                func_0206c17c(v2);
            }
        }
        return f4;
    }
    return 0;
}

void func_020a1e40(s32 a, Unk020f41c4_A *p) {
    u16 v;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (GetKart(a)->mState == 0) {
        return;
    }
    if (p->mUnk_44 != 0 && p->mUnk_44 != 1 && p->mUnk_44 != 9) {
        return;
    }
    v = p->mUnk_78;
    if ((v & 0x8000) != 0) {
        return;
    }
    data_0217b1fc->mUnk_000[a].mUnk_44 = v & ~0xff00;
}

u32 func_020a1e3c(u32 p0) {
    return p0;
}

void func_020a1ddc(s32 a) {
    s32 i;
    s32 n;

    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        data_0217b1fc->mUnk_000[i].mUnk_24[a] = 0;
    }
}

static inline u16 func_020a1790_inline(Unk0217b1fc *d, s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == d->mUnk_000[j].mUnk_48) {
            return (u16) j;
        }
    }
    return 0;
}

u16 func_020a1cd8(s32 a) {
    s32 v;
    s32 i;
    s32 v1;

    if (data_021759c0->mMode == 2) {
        if (data_021759c0->mUnk_18 == 0) {
            v = 3 - data_0217b1fc->mUnk_000[a].mUnk_4c;
            v += 1;
        } else if (data_021759c0->mUnk_18 == 1) {
            v1 = 1;
            for (i = 0; i < data_021759c0->mKartCount; i++) {
                if (data_0217b1fc->mUnk_000[i].mUnk_4c > v1) {
                    v1 = data_0217b1fc->mUnk_000[i].mUnk_4c;
                }
            }
            v = (v1 + 1 - data_0217b1fc->mUnk_000[a].mUnk_4c) / 2 + 1;
        } else {
            v = a;
        }
    } else {
        v = 3 - data_0217b1fc->mUnk_000[a].mUnk_4c;
        v += 1;
    }
    if (v < 1) {
        v = 1;
    } else if (v > 3) {
        v = 3;
    }
    return v;
}

void func_020a1b6c(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    Unk0217b1fc_000 *e0;
    u16 r1;
    u16 r0;
    Unk0217b1fc_000 *e1;

    for (i = data_0217b1fc->mUnk_000[a].mUnk_48 - 1; i >= 0; i--) {
        e1 = &data_0217b1fc->mUnk_000[func_020a1790_inline(data_0217b1fc, i)];
        r1 = e1->mUnk_48;
        r0 = data_0217b1fc->mUnk_000[a].mUnk_48;
        e0 = &data_0217b1fc->mUnk_000[a];
        if (r0 > r1) {
            if (e0->mUnk_4c > e1->mUnk_4c || (e0->mUnk_08 == 0 && e1->mUnk_08 != 0)) {
                e1->mUnk_48 = r0;
                data_0217b1fc->mUnk_000[a].mUnk_48 = r1;
            }
        }
    }
    n = data_021759c0->mKartCount;
    data_0217b1fc->mUnk_3b0 = 0xffff;
    data_0217b1fc->mUnk_3ac = 0;
    for (j = 0; j < n; j++) {
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3b0 = (v < data_0217b1fc->mUnk_3b0 && v >= 0) ? v : data_0217b1fc->mUnk_3b0;
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3ac = (v > data_0217b1fc->mUnk_3ac) ? v : data_0217b1fc->mUnk_3ac;
    }
}

void func_020a19f8(u16 a) {
    s32 i;
    s32 j;
    s32 n;
    s32 v;
    Unk0217b1fc_000 *e0;
    u16 r1;
    u16 r0;
    Unk0217b1fc_000 *e1;

    for (i = data_0217b1fc->mUnk_000[a].mUnk_48 + 1; i < 8; i++) {
        e1 = &data_0217b1fc->mUnk_000[func_020a1790_inline(data_0217b1fc, i)];
        r1 = e1->mUnk_48;
        r0 = data_0217b1fc->mUnk_000[a].mUnk_48;
        e0 = &data_0217b1fc->mUnk_000[a];
        if (r0 < r1) {
            if (e0->mUnk_4c < e1->mUnk_4c || (e0->mUnk_08 != 0 && e1->mUnk_08 == 0)) {
                e1->mUnk_48 = r0;
                data_0217b1fc->mUnk_000[a].mUnk_48 = r1;
            }
        }
    }
    n = data_021759c0->mKartCount;
    data_0217b1fc->mUnk_3b0 = 0xffff;
    data_0217b1fc->mUnk_3ac = 0;
    for (j = 0; j < n; j++) {
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3b0 = (v < data_0217b1fc->mUnk_3b0 && v >= 0) ? v : data_0217b1fc->mUnk_3b0;
        v = data_0217b1fc->mUnk_000[j].mUnk_4c;
        data_0217b1fc->mUnk_3ac = (v > data_0217b1fc->mUnk_3ac) ? v : data_0217b1fc->mUnk_3ac;
    }
}

void func_020a1904(u16 a) {
    Kart *c;

    if (data_0217b1fc->mUnk_38c != NULL) {
        data_0217b1fc->mUnk_38c(a);
    }
    data_0217b1fc->mUnk_000[a].mUnk_08 = 1;
    if (data_021759c0->mMode == 2) {
        data_0217b1fc->mUnk_000[a].mUnk_4c = -1;
        data_0217b1fc->mUnk_000[a].mUnk_50 = 0;
    }
    if ((u32) a >= data_021759c0->mKartCount) {
        return;
    }
    func_020a19f8(a);
    if (data_021759c0->mMode == 2) {
        func_02068b5c(GetKart(a));
    } else if (data_021759c0->mMode == 4) {
        c = GetKart(a);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
}

void func_020a1790(void) {
    s32 n;
    s32 v;
    s32 i;
    s32 j;
    s32 v1;
    s32 k;
    u16 x;
    Unk0217b1fc *d;
    Unk0217b1fc_000 *e;
    Kart *c;

    n = data_021759c0->mKartCount;
    d = data_0217b1fc;
    for (k = 0; k < 8; k++) {
        if (d->mUnk_000[k].mUnk_48 == 0) {
            x = k;
            goto found;
        }
    }
    x = 0;
found:
    v = d->mUnk_000[x].mUnk_46;
    e = d->mUnk_000;
    for (j = 0; j < 8; j++, e++) {
        if (e->mUnk_08 == 0) {
            if (v != e->mUnk_46) {
                return;
            }
        }
    }
    for (i = 0; i < n; i++) {
        c = GetKart((u16) i);
        c->mUnk_48 |= 0x2000;
        c->mUnk_7c |= 8;
    }
    data_0217b1fc->mUnk_3b4 = v;
    if (data_021759c0->mMode == 2) {
        if (data_021759c0->mUnk_18 == 1) {
            func_0212ecc0(&data_0217d068, 0, 0x4a);
        }
        data_0217b1fc->mUnk_3a8 = 0x5a;
    } else if (data_021759c0->mMode == 4) {
        v1 = data_021759c0->mEntryIndex;
        if (data_0217b1fc->mUnk_3b4 == v1) {
            func_0203e74c((u16) v1);
        } else {
            func_0203cd04((u16) v1);
        }
        data_0217b1fc->mUnk_3a8 = 0;
    }
}

void func_020a1748(u16 a) {
    Unk0217b1fc_000 *e;

    e = &data_0217b1fc->mUnk_000[a];
    e->mUnk_1c = -2;
    e->mUnk_18 = -2;
    e->mUnk_44 = a;
    data_0217b1fc->mUnk_388(a, a);
}

void func_020a1728(int a) {
    *(u32 *) (a * 0x70 + (u32) data_0217b1fc + 8) = 0;
}

static inline u16 func_020a12b8_inline(s32 i) {
    s32 j;

    for (j = 0; j < 8; j++) {
        if ((u16) i == data_0217b1fc->mUnk_000[j].mUnk_48) {
            return (u16) j;
        }
    }
    return 0;
}

void func_020a16d0(u16 a) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return;
    }
    func_020a1904(a);
    func_020a1790();
}

u16 func_020a1520(void) {
    Unk0212c400 **h;
    s32 v;
    u16 k;
    s32 i;
    s32 m;
    s32 n;
    s32 a;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return 0;
    }
    v = data_0217b1fc->mUnk_3a4 + 1;
    if (v >= 3) {
        v = 3;
    }
    data_0217b1fc->mUnk_3a4 = v;
    data_0217b1fc->mUnk_3a2 = data_021565f0[data_0217b1fc->mUnk_3a4];
    a = data_0217b1fc->mUnk_3b0;
    if (a != data_0217b1fc->mUnk_3ac) {
        n = data_021759c0->mKartCount;
        for (m = 0; m <= a; m++) {
            for (i = n - 1; i >= 0; i--) {
                k = func_020a12b8_inline(i);
                if (m == data_0217b1fc->mUnk_000[k].mUnk_4c) {
                    func_020a1904(k);
                }
            }
            func_020a1790();
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return 0;
            }
        }
    }
    if (data_0217c780 & 1) {
        h = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            if (h[0] != NULL) {
                func_0212c6f0(h, 0);
            }
            func_0212ecc0(h, 0, 0x4b);
        }
    }
    return data_0217b1fc->mUnk_3a2;
}

void func_020a12b8(void) {
    s32 n;
    s32 i;
    u16 k;
    s32 m;
    u16 s;
    Unk020f41c4_B *r;

    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return;
    }
    if (data_021759c0->mMode == 2) {
        n = data_021759c0->mKartCount;
        if (data_021759c0->mUnk_18 == 0) {
            if (data_0217b1fc->mUnk_3b4 >= 0) {
                return;
            }
            s = (u16) n;
            do {
                r = &data_0217561c->mUnk_47c;
                if ((u16) n == 0) {
                    m = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    if (s == 0) {
                        m = (u32) (r->mUnk_00 >> 32);
                    } else {
                        m = (u32) (((u64) (u32) (r->mUnk_00 >> 32) * (u64) s) >> 32);
                    }
                }
                k = (u16) m;
                if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                    func_020a16d0(k);
                    data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                }
            } while (data_0217b1fc->mUnk_3b4 < 0);
        } else if (data_021759c0->mUnk_18 == 1) {
            for (i = n - 1; i >= 0; i--) {
                if (data_0217b1fc->mUnk_3b4 < 0) {
                    k = func_020a12b8_inline(i);
                    if (data_0217b1fc->mUnk_000[k].mUnk_08 == 0) {
                        func_020a16d0(k);
                        data_0217b1fc->mUnk_000[k].mUnk_08 = 2;
                    }
                }
            }
        }
    } else if (data_021759c0->mMode == 4) {
        for (i = 7; i >= 0; i--) {
            k = func_020a12b8_inline(i);
            if (k != data_021759c0->mEntryIndex && data_0217b1fc->mUnk_3b4 < 0) {
                func_020a16d0(k);
            }
        }
    }
}

u32 func_020a128c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value1 = (u32) &data_0217b1fc;
    value0 = 0u;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const u32 *) ((value2) + (948));
    compareLeft0 = value1;
    compareRight0 = 0u;
    if ((s32) compareLeft0 < (s32) compareRight0) {
        return value0;
    }
    value1 = (u32) * (const u32 *) ((value2) + (936));
    compareLeft1 = value1;
    compareRight1 = 0u;
    if ((s32) compareLeft1 < (s32) compareRight1) {
        value0 = 1u;
    }
    return value0;
}

BOOL func_020a126c(void) {
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        return TRUE;
    }
    return FALSE;
}

u16 func_020a1250(int arg0) {
    return data_0217b1fc->mUnk_000[arg0].mUnk_48;
}

u32 func_020a1238(void) {
    return ((u32) data_0217b1fc->mUnk_3a0);
}

void func_020a1218(short a) {
    Unk0217b1fc *v1;
    v1 = data_0217b1fc;
    v1->mUnk_3a0 = v1->mUnk_3a0 + a;
}

u16 func_020a119c(void) {
    s32 i;
    s32 v1;
    s32 n;
    s32 v;

    v1 = 0;
    n = data_021759c0->mKartCount;
    for (i = 0; i < n; i++) {
        v = data_0217b1fc->mUnk_000[(u16) i].mUnk_4c;
        if (v <= 0) {
            v = 0;
        }
        v1 += (u16) v;
    }
    return v1;
}

u16 func_020a1180(void) {
    return data_0217b1fc->mUnk_3ac;
}

u16 func_020a1154(u16 a) {
    s32 v;

    v = data_0217b1fc->mUnk_000[a].mUnk_4c;
    if (v <= 0) {
        v = 0;
    }
    return v;
}

void func_020a10f0(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_4c += b;
    if (b > 0) {
        func_020a1b6c(a);
    } else if (b < 0) {
        func_020a19f8(a);
    }
}

u16 func_020a10d4(u16 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (u32) * (const u16 *) ((value1) + (80));
    return (u16) value0;
}

void func_020a10ac(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_50 += b;
}

BOOL func_020a1084(int a) {
    if (data_0217b1fc->mUnk_000[a].mUnk_08 != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_020a1048(u16 a) {
    Unk0217b1fc *d;
    BOOL r;
    s32 v;

    d = data_0217b1fc;
    r = FALSE;
    v = d->mUnk_000[a].mUnk_4c;
    if (d->mUnk_3b0 == v) {
        if (d->mUnk_3ac != v) {
            r = TRUE;
        }
    }
    return r;
}

s32 func_020a100c(s32 a) {
    Unk0217b1fc_000 *e;
    BOOL r;

    e = &data_0217b1fc->mUnk_000[a];
    r = FALSE;
    if (data_0217b1fc->mUnk_3b4 == e->mUnk_46) {
        if (data_0217b1fc->mUnk_3a8 < 0) {
            r = TRUE;
        }
    }
    return r;
}

Vec3 *func_020a0ff0(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0217b1fc;
    value1 = 0x70u;
    value2 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value0) * (value1) + (value2);
    value0 = (value1) + (0xcu);
    return (Vec3 *) value0;
}

Unk02175620_84 *func_020a0f0c(void) {
    Unk020f41c4_B *a;
    u16 v;
    s32 w;

    a = &data_0217561c->mUnk_47c;
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    v = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 5) >> 32) + 1;
    w = data_0217b1fc->mUnk_3b8 + v;
    if (w >= gCourseMap->mUnk_88) {
        w = 0;
    }
    data_0217b1fc->mUnk_3b8 = w;
    return &gCourseMap->mUnk_84[data_0217b1fc->mUnk_3b8];
}

void func_020a0e00(void) {
    s32 i;
    Unk0217b1fc_000 *e;

    data_0217b1fc = HeapAlloc(GetHeap(func_020364e8()), 0x3c0);
    for (i = 0; i < 8; i++) {
        e = &data_0217b1fc->mUnk_000[i];
        e->mUnk_1c = -2;
        e->mUnk_18 = -2;
        e->mUnk_44 = (u16) i;
        e->mUnk_48 = (u16) i;
        if (i < data_021759c0->mKartCount) {
            switch (data_021759c0->mCurrentEntries[(u16) i].mUnk_08.mTeamIndex) {
                case 0:
                    e->mUnk_46 = 1;
                    break;
                case 1:
                    e->mUnk_46 = 3;
                    break;
                default:
                    e->mUnk_46 = (u16) i;
                    break;
            }
            e->mUnk_08 = 0;
            e->mUnk_4c = 0;
            e->mUnk_50 = 0;
        } else {
            e->mUnk_08 = 2;
            e->mUnk_4c = -1;
            e->mUnk_50 = 0;
            e->mUnk_46 = data_021759c0->mKartCount;
        }
    }
    data_0217b1fc->mUnk_3b4 = -1;
}

void func_020a0dbc(void) {
    data_0217b1fc->mUnk_3a8 = -1;
    if (data_0217b1fc->mUnk_390 != NULL) {
        data_0217b1fc->mUnk_390();
    }
}

void func_020a08ec(void) {
    Kart *o;
    BOOL a;
    BOOL b;
    s32 v;
    u32 f;
    s32 i;
    s32 n;
    Unk0217b1fc_000 *e = data_0217b1fc->mUnk_000;

    n = data_021759c0->mKartCount;
    if (data_0217b1fc->mUnk_3b4 >= 0) {
        if (data_0217b1fc->mUnk_3a8 > 0) {
            data_0217b1fc->mUnk_3a8 = data_0217b1fc->mUnk_3a8 - 1;
            if (data_0217b1fc->mUnk_3a8 <= 0) {
                data_0217b1fc->mUnk_3a8 = -1;
                if (data_0217b1fc->mUnk_390 != NULL) {
                    data_0217b1fc->mUnk_390();
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (data_0217b1fc->mUnk_000[i].mUnk_08 == 1) {
                if (i != data_021759c0->mEntryIndex) {
                    func_02068a00(GetKart((u16) i));
                }
                data_0217b1fc->mUnk_000[i].mUnk_08 = 2;
            }
        }
        return;
    }
    for (i = n - 1; i >= 0; i--) {
        e = &data_0217b1fc->mUnk_000[i];
        if (e->mUnk_08 == 1) {
            func_02068a00(GetKart((u16) i));
            data_0217b1fc->mUnk_000[i].mUnk_08 = 2;
        } else if (data_0217b1fc->mUnk_3b4 < 0 && e->mUnk_4c > 0) {
            o = GetKart((u16) i);
            e = &data_0217b1fc->mUnk_000[i];
            v = e->mUnk_64 - 1;
            if (v <= 0) {
                v = 0;
            }
            e->mUnk_64 = v;
            data_0217b1fc->mUnk_000[i].mUnk_68 = -(data_0217b1fc->mUnk_000[i].mUnk_68 <= 0);
            if (func_01ffc67c(o) != 0 || (u16) (data_02175628[o->mEntryIndex].mBits & 3) != 0) {
                data_0217b1fc->mUnk_000[i].mUnk_68 = -1;
                data_0217b1fc->mUnk_000[i].mUnk_64 = -1;
            } else if (func_02061fec() == 1) {
                if ((u16) (data_02175628[(u32) o->mEntryIndex].mBits & 4) != 0) {
                    data_0217b1fc->mUnk_000[i].mUnk_68 = 1;
                } else if (data_02175628[o->mEntryIndex].mUnk_5a != 0) {
                    data_0217b1fc->mUnk_000[i].mUnk_64 = 10;
                }
            }
            if (data_0217b1fc->mUnk_388 != NULL) {
                b = TRUE;
                f = o->mUnk_48;
                a = (f & 0x200) != 0;
                if (o->mState == 0 && (f & 0x4000000) == 0) {
                    b = FALSE;
                }
                if (e->mUnk_04 == 0 && a != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_04 = 1;
                    e->mUnk_00 = 0;
                    e->mUnk_18 = -2;
                    e->mUnk_44 = (u16) i;
                    e->mUnk_20 = 0;
                    if (e->mUnk_4c <= 1) {
                        if ((data_021759c0->mMode == 2 && data_021759c0->mUnk_18 == 0) || data_021759c0->mMode == 4) {
                            o->mUnk_7c |= 0x20000000;
                            o->mUnk_48 &= ~0x2000000;
                        }
                    }
                } else if (e->mUnk_04 == 1 && (o->mUnk_44 & 0x10000) != 0) {
                    e->mUnk_04 = 0;
                    e->mUnk_1c = 0;
                    if ((o->mUnk_4c & 0x400000) == 0) {
                        func_0206c17c(o);
                    }
                }
                if (e->mUnk_1c == 0) {
                    e->mUnk_1c = -2;
                    data_0217b1fc->mUnk_388((u16) i, 8);
                    e->mUnk_44 = i;
                } else if (e->mUnk_1c >= 0) {
                    e->mUnk_1c = e->mUnk_1c + 1;
                }
                if (e->mUnk_00 == 0 && b != FALSE && (o->mUnk_4c & 0x400000) == 0) {
                    e->mUnk_00 = 1;
                    if (e->mUnk_4c <= 1) {
                        if ((data_021759c0->mMode == 2 && data_021759c0->mUnk_18 == 0) || data_021759c0->mMode == 4) {
                            o->mUnk_7c |= 0x20000000;
                        }
                    }
                } else if (e->mUnk_00 == 1 && b == FALSE && (o->mUnk_48 & 0x6052840) == 0) {
                    e->mUnk_00 = 0;
                    if (e->mUnk_20 == 0) {
                        e->mUnk_18 = 0;
                        if ((o->mUnk_4c & 0x400000) == 0) {
                            func_0206c17c(o);
                        }
                    } else {
                        e->mUnk_20 = 0;
                    }
                }
                if (e->mUnk_18 == 0) {
                    e->mUnk_18 = -2;
                    data_0217b1fc->mUnk_388((u16) i, e->mUnk_44);
                    e->mUnk_44 = i;
                } else if (e->mUnk_18 >= 0) {
                    e->mUnk_18 = e->mUnk_18 + 1;
                }
            }
            e->mUnk_0c = o->mPos;
        }
    }
}

void func_020a089c(Unk020a0318 *p) {
    s32 v;

    v = data_021759c0->mCourseId;
    if (v == 0x12) {
        p->mUnk_bc = 0x121;
    } else if (v == 0x1f) {
        p->mUnk_bc = 0x111;
        p->mUnk_be = 0x10a;
    } else {
        p->mUnk_bc = 0x20d;
    }
}

void func_020a066c(Unk020a066c *p) {
    s32 i;
    Unk020a0318 *o;
    Unk020f41c4_B *a;

    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        if (data_021759c0->mCourseId == 0x12) {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mPos.x + 0x73a000;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z - 0x1400000;
            o->mUnk_b8 = 1;
        } else if (data_021759c0->mCourseId == 0x1f) {
            o->mUnk_a8 = 0x546;
            o->mUnk_ac = o->mUnk_00.mPos.x + 0x28a000;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z - 0x32000;
            o->mUnk_b8 = 0;
        } else {
            o->mUnk_a8 = 0xa28;
            o->mUnk_ac = o->mUnk_00.mPos.x;
            o->mUnk_b0 = o->mUnk_00.mPos.y;
            o->mUnk_b4 = o->mUnk_00.mPos.z;
            o->mUnk_b8 = 0;
        }
        a = &data_0217561c->mUnk_498;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c8 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x3c) >> 32) + 0x258;
        o->mUnk_a4 = 0x7f000;
        a = &data_0217561c->mUnk_498;
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        o->mUnk_c0 = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xf) >> 32);
    }
}

void func_020a0318(void *a, Unk020a0318 *p) {
    Kart *o;
    Unk0212c400 **h;
    Unk020f41c4_B *r;
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    s32 v;
    s32 x;
    s32 w;
    s32 z;
    s32 y;
    s64 d;

    if (p->mUnk_c0-- <= 0) {
        p->mUnk_c0 = 0xf;
        w = p->mUnk_a8;
        x = w / 2;
        o = GetKart((u16) data_021759c0->mEntryIndex);
        y = o->mPos.x - p->mUnk_ac;
        z = o->mPos.z - p->mUnk_b4;
        d = (s64) y * y + (s64) z * z;
        if (d < (s64) x * x) {
            v = 2;
        } else if (d < (s64) (w << 12) * (w << 12)) {
            v = 1;
        } else {
            v = 0;
        }
        p->mUnk_c4 = v;
        if (p->mUnk_b8 != 0) {
            p->mUnk_c4 = p->mUnk_c4 == 0;
        }
    }
    if (p->mUnk_c4 > 1) {
        p->mUnk_a4 = 0x7f001;
    } else if (p->mUnk_c4 > 0) {
        p->mUnk_a4 = p->mUnk_a4 + 0x4000;
        if (p->mUnk_a4 > 0x7f000) {
            p->mUnk_a4 = 0x7f000;
        }
    } else {
        p->mUnk_a4 = p->mUnk_a4 - 0x4000;
        if (p->mUnk_a4 < 0) {
            p->mUnk_a4 = 0;
        }
    }
    if (p->mUnk_bc != 0) {
        if (p->mUnk_c4 != 0) {
            if (*func_02108e6c(8) != NULL) {
                o = GetKart((u16) data_021759c0->mEntryIndex);
                p->mUnk_a0 = p->mUnk_a0 - (s32) (((s64) o->mVelocityLengthRatio * 0x1000) >> 12);
                if (p->mUnk_a0 < 0xc000) {
                    p->mUnk_a0 = 0xc000;
                }
            } else if (p->mUnk_c8-- <= 0) {
                h = func_02108e6c(8);
                s1.mUnk_00 = p->mUnk_bc;
                s1.mUnk_04 = NULL;
                s1.mUnk_08 = 4;
                s1.mUnk_0c = func_020d4ef4(NULL);
                func_0210b760(&s1, h);
                r = &data_0217561c->mUnk_498;
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                p->mUnk_c8 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 0x3c) >> 32) + 0x78;
                p->mUnk_a0 = 0x7f000;
            }
        } else if (p->mUnk_c8 > 0) {
            p->mUnk_c8 = p->mUnk_c8 - 1;
        }
        if (*func_02108e6c(8) != NULL) {
            v = p->mUnk_a4 < p->mUnk_a0 ? p->mUnk_a4 : p->mUnk_a0;
            func_02105b28(func_02108e6c(8), v >> 12);
        }
    }
    if (p->mUnk_be == 0) {
        return;
    }
    if (p->mUnk_c4 != 0) {
        if (*func_02108e6c(9) == NULL) {
            h = func_02108e6c(9);
            s2.mUnk_00 = p->mUnk_be;
            s2.mUnk_04 = NULL;
            s2.mUnk_08 = 4;
            s2.mUnk_0c = func_020d4ef4(NULL);
            func_0210b760(&s2, h);
        }
    }
    if (*func_02108e6c(9) == NULL) {
        return;
    }
    func_02105b28(func_02108e6c(9), p->mUnk_a4 >> 12);
}

u32 func_020a02f8(void) {
    return func_0209bf48(func_020a066c, func_020a0318, NULL);
}
