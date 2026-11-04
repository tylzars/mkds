#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202de00.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_020354fc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02125000.h"

#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021281b4.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0212d254.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02035c50(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *s;
    s32 i;
    s32 v;
    s32 e;
    u8 x[4];
    s16 w[12];

    s = &data_02174e68->mUnk_2c[1];
    if (a == 1) {
        c += func_0202ddb0();
        func_0212426c(1, b, s->mUnk_14, GetBmgEntry(data_02174e68->mUnk_88, func_02025d74(func_0202db04(c))),
                      s->mUnk_0c, s->mUnk_18);
        func_0202dcf4(c, x);
        func_02025cd0(w, x[2], x[3], *(u16 *) x);
        func_02124224(1, b + 7, s->mUnk_14, w, s->mUnk_0c, s->mUnk_18, 7);
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            e = i + 7;
            if (i == d) {
                v = 14;
            } else {
                v = 15;
            }
            func_02124100(i, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
            func_02124100(e, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_02035c14(void) {
    void *v1;
    v1 = GetBmgEntry((void *) data_02174e68->mUnk_88, 3);
    func_02125ee8((int) 0xfffffff4, 0);
    func_02126638(v1, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_0203551c_inline(void) {
    Unk021759d4 *p = data_021759d4;
    if (p->mUnk_0c != 0) {
        return p->mUnk_10;
    }
    return 0;
}

static inline s32 func_0203551c_inline_2(void) {
    if (data_0217aa08->mUnk_28 == 0) {
        return func_0203551c_inline();
    }
    return 1;
}

void func_02035b78(void) {
    void *e;
    void *f;
    void *g;
    u8 y[0x14];
    u16 w[11];
    u16 h[0x100];

    e = GetBmgEntry(data_02174e68->mUnk_88, 0x12);
    f = GetBmgEntry(data_02174e68->mUnk_84, 0);
    g = GetBmgEntry(data_02174e68->mUnk_84, 1);
    func_0202dc68(data_02174e68->mUnk_80 + func_0202ddb0(), y);
    MemCopyHalfwords(y, w, 0x14);
    w[10] = 0;
    func_0212513c(w, e, h, 0x100);
    func_02125ed0(0, -1);
    func_02125fd4((u32) h, (u32) f, (u32) g, 1, 0, 1, 1, 0);
}

void func_02035b0c(void) {
    Unk02174e14_00 *s;
    Unk02174e14_00 *t;
    s32 n;
    s32 m;
    s32 i;
    s16 c;

    s = &data_02174e68->mUnk_2c[0];
    t = &data_02174e68->mUnk_2c[1];
    n = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    m = t->mUnk_0c->mUnk_06 + t->mUnk_14->mUnk_06;
    c = func_02025ebc(&data_02174e68->mUnk_90);
    for (i = 0; i < n; i++) {
        s->mUnk_18[i].mUnk_06 = -c;
    }
    for (i = 0; i < m; i++) {
        t->mUnk_18[i].mUnk_06 = c;
    }
}

void func_02035a9c(void) {
    s32 n;
    u32 d;
    u32 e;
    u32 f;
    u32 x;
    u8 y[0x14];
    u16 w[11];

    n = func_0202ddb0() + data_02174e68->mUnk_80;
    func_0202dcf4(n, &x);
    func_0202dc68(n, y);
    MemCopyHalfwords(y, w, 0x14);
    w[10] = 0;
    d = func_0202dbe8(n);
    e = func_0202db68(n);
    f = func_0202db04(n);
    func_0202de00((Unk02174e14 *) &data_02174e68->mUnk_2c[0], data_0215404c, w, d, e, f, (Unk0202de00_g *) &x);
}

void func_020357dc(void *a, void *b, void *c) {
    void *h;
    Unk02174e14_00 *s;
    s32 i;
    u32 n;
    s32 j;
    s32 k;
    s32 m;
    s32 x;
    s32 y;
    s32 z;
    s16 *t;
    void *g;
    u16 w[3];

    h = CreateFrmHeapFromMaxFree(a);
    data_02174e68 = HeapAlloc(h, 0xa8);
    MemFillWordsByBlock_inline(data_02174e68, 0xa8);
    data_02174e68->mHeap = h;
    data_02174e68->mUnk_24[0] = b;
    data_02174e68->mUnk_24[1] = c;
    data_02174e68->mUnk_84 = func_02047a28(data_021644e0);
    data_02174e68->mUnk_88 = FindSceneFile(data_021644ec);
    s = &data_02174e68->mUnk_2c[0];
    n = func_02148cb8();
    func_02025b20(s, data_021644f8, data_02164518, data_02164538, data_02164558, data_02164574, NULL, FindSceneFile);
    func_02025a50(0, data_02174e68->mHeap, s);
    for (i = 0; i < s->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(0, data_02174e68->mHeap, s, data_0215404c[i], n);
    }
    func_020258d4(1, data_02174e68, data_02164590, data_021645b0, data_021645d0, 3, FindSceneFile);
    s = &data_02174e68->mUnk_2c[1];
    n = func_02148ca0();
    k = 0;
    func_02025b20(s, data_021645ec, data_0216460c, data_0216462c, data_0216464c, data_02164668, data_02164684,
                  FindSceneFile);
    func_02025a50(1, data_02174e68->mHeap, s);
    m = s->mUnk_0c->mUnk_06;
    j = 0;
    if (j < s->mUnk_14->mUnk_06) {
        t = data_02164470[0];
        do {
            if (t[3] < 0) {
                t[3] = m + k++;
            }
            n -= func_02025a00(1, data_02174e68->mHeap, s, data_02164470[j], n);
            t += 4;
            j++;
        } while (j < s->mUnk_14->mUnk_06);
    }
    for (i = 0; i < 8; i++) {
        func_021249a8(i, 3, s->mUnk_08, s->mUnk_0c);
    }
    for (j = 0, t = data_02164470[0]; j < 7; j++) {
        x = t[3];
        y = t[0];
        z = data_02164470[j + 7][0];
        g = s->mUnk_18;
        func_02025c1c(x, (u8 *) g + (x << 6), s->mUnk_0c);
        func_02025bf0(y, (u8 *) g + (y << 6) + (m << 6), s->mUnk_14);
        func_02025bf0(z, (u8 *) g + (z << 6) + (m << 6), s->mUnk_14);
        t += 4;
    }
    func_02025c1c(7, (u8 *) s->mUnk_18 + 0x1c0, s->mUnk_0c);
    w[0] = 0;
    w[1] = m;
    w[2] = m + 7;
    func_0202e530(data_02174e68->mHeap, 3, w, 7, 8, 0x7c, s->mUnk_18, s->mUnk_10, data_02174e68->mUnk_20 + 0xc, 0, 1, 2,
                  10, func_02035c50);
    func_02025b84(0, &data_02174e68->mUnk_64);
    func_02035a9c();
    func_02025f80(&data_02174e68->mUnk_90, 0, 10, -0xc0, 0);
    func_02128374();
    func_021281c8(0xf);
    func_02035c14();
    FrmHeapShrinkInParent(data_02174e68->mHeap);
}

s32 func_0203551c(u16 *a) {
    Unk02174e68 *p;
    enum { K0 = -1 } r;
    s32 z;
    BOOL f;
    BOOL g;
    s32 i;
    u16 k;
    u16 w;
    void *e;
    Unk02174e14_00 *t;
    void *h;

    r = K0;
    k = func_020435bc();
    z = 0;
    func_02025edc(&data_02174e68->mUnk_90);
    f = FALSE;
    g = FALSE;
    w = data_02175674[k].mUnk_00;
    if (w == 0 && data_02175680[k].mUnk_00 < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[k].mUnk_00 == 0 && w != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        z = IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[k].mUnk_00, data_02175672[k].mUnk_00);
    }
    p = data_02174e68;
    switch (p->mUnk_8c) {
        case 0:
            if (p->mUnk_90.mUnk_00 == 1) {
                p->mUnk_8c = 1;
            } else {
                func_02035b0c();
            }
            break;
        case 1:
            if (func_02125f88() != 0) {
                func_02035c14();
            }
            func_0202e4b0();
            i = func_0202e4a4();
            if (data_02174e68->mUnk_80 != i) {
                data_02174e68->mUnk_80 = i;
                func_02035a9c();
            }
            if (func_0202e468() != 0) {
                func_0212ecc0(&data_0217d068, 0, 5);
            }
            if (func_0202e47c() != 0) {
                func_02035b78();
                func_021282c8();
                data_02174e68->mUnk_8c = 2;
            } else if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || z != 0) {
                e = GetBmgEntry(data_02174e68->mUnk_88, 0x54);
                h = GetBmgEntry(data_02174e68->mUnk_84, 4);
                func_02125ed0(0, 5);
                func_02126230(e, h);
                func_02128310(1);
                data_02174e68->mUnk_a0 = 0;
                data_02174e68->mUnk_8c = 4;
            }
            break;
        case 2:
            if (func_02125f40() != 0 && func_02125f60() == 0) {
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 10);
                func_0212d5e0(&data_0217d0a0);
            }
            if (func_02125f54() != 0) {
                if (func_02125f60() == 0) {
                    ((Unk0202ddd8 *) func_0202ddd8())->mUnk_08_0 = 1;
                    func_020566a8((u8) data_02174e68->mUnk_80, func_0202ddd8());
                    data_02174e68->mUnk_8c = 3;
                } else {
                    func_02128374();
                    data_02174e68->mUnk_8c = 1;
                }
                func_02125fc0();
            }
            break;
        case 3:
            if (func_0203551c_inline_2() != 0) {
                e = GetBmgEntry(p->mUnk_88, 0x10);
                h = GetBmgEntry(data_02174e68->mUnk_84, 4);
                func_02125ed0(0, 5);
                func_02126230(e, h);
                data_02174e68->mUnk_a0 = 0;
                data_02174e68->mUnk_8c = 4;
            }
            break;
        case 4:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (a != NULL) {
                    a[2] = 1;
                }
                data_02174e68->mUnk_8c = 5;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        t = data_02174e68->mUnk_2c;
        func_02124c30(t[i].mUnk_0c, t[i].mUnk_08, t[i].mUnk_14, data_02174e68->mUnk_24[i], t[i].mUnk_18);
    }
    return r;
}

#pragma thumb off

#pragma thumb on

void func_020354fc(void) {
    HeapDestroy((void *) data_02174e68->mHeap);
    *(int *) &data_02174e68 = 0;
}

#pragma thumb off
