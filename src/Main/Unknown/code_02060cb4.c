#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0203b070.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_021524d8.h"
#include "Main/Unknown/code_02152698.h"
#include "Main/Unknown/code_02152918.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "code_021522a0.h"
#include "code_02152500.h"
#include "code_021526e4.h"
#include "code_02152934.h"

#pragma opt_loop_invariants off

void func_020613a0(void) {
    u8 i;
    u8 *a;
    char b[0x80];

    i = 0;
    a = data_0217aa08->mUnk_40;
    for (; i < 0x20; i++) {
        func_0203b070(i, b, 0x80);
        func_0204863c(b, a + i * 0x230, 0x230);
    }
    func_02057504();
    data_0217aa08->mUnk_40 = NULL;
}

void func_02061358(void *a) {
    data_0217aa08->mUnk_40 = a;
    func_02057514();
    func_02057df0((void (*)(void)) func_020613a0);
    data_0217aa0c->mUnk_f8 = 1;
}

void func_020612b0(void) {
    Unk0217aa08_00 *a;
    u32 b;
    u32 c;

    gWiFiSession->mKartCountCopy = gWiFiSession->mKartCount;
    a = data_0217aa08->mUnk_00;
    b = a->mUnk_34[5] + (u8) (gWiFiSession->mKartCountCopy - 1);
    c = data_021653e4 + 3;
    if (b > c) {
        b = c;
    }
    data_0217aa08->mUnk_00->mUnk_34[5] = b;
    func_02057ca4(data_0217aa08->mUnk_00);
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
}

s32 func_02061290(void) {
    return func_02152638(data_0217aa08->mUnk_00->mUnk_4c);
}

s32 func_02061250(void) {
    u64 a;
    s32 b;

    a = func_02152500(data_0217aa08->mUnk_00->mUnk_4c);
    b = 0;
    if (a != b) {
        b = 1;
    }
    return b;
}

void func_02061220(u32 a) {
    u64 b;

    b = func_02152500(data_0217aa08->mUnk_00->mUnk_4c);
    func_02152918((u32) b, (u32) (b >> 32), a);
}

s32 func_02061104(const void *a) {
    u8 b[12];
    Unk0217aa08_20_04 c;
    u64 d;
    s32 e;
    u8 i;
    u8 *f;

    d = Decimal12CharsToValue(a);
    if (func_02152950(d, 0x414d434a) == 0) {
        return 1;
    }
    if (d == func_02152500(data_0217aa08->mUnk_00->mUnk_4c)) {
        return 1;
    }
    func_021524d8(b, (u32) d, (u32) (d >> 32));
    f = (u8 *) data_0217aa08->mUnk_20 + 0x874;
    e = -1;
    for (i = 0; i < 60; i++) {
        u8 *g;

        func_0205ee14(i, &c);
        if (c.mUnk_22_0 == 1) {
            g = f + i * 12;
            if (func_02152698(g) != 0 && func_02152390(g, b) != 0) {
                e = (s8) i;
                break;
            }
        }
    }
    if (e != -1) {
        return 2;
    }
    return 0;
}

s32 func_0206105c(const void *a) {
    Unk0217aa08_20_04 b;
    s32 c;
    u8 i;
    u8 *d;

    d = (u8 *) data_0217aa08->mUnk_20 + 0x874;
    c = -1;
    for (i = 0; i < 60; i++) {
        u8 *e;

        func_0205ee14(i, &b);
        if (b.mUnk_22_0 == 1) {
            e = d + i * 12;
            if (func_02152698(e) != 0 && func_02152390(e, a) != 0) {
                c = (s8) i;
                break;
            }
        }
    }
    return c;
}

s32 func_02060d1c(u8 *a, void *b, u8 *c, s32 d, s32 e, s32 f) {
    Unk0203b0a0 h;
    Unk0203b0a0 j;
    Unk0217aa08_20_04 k;
    s32 g[3];
    s32 m;
    BOOL n;
    s32 q;
    s32 i;
    u8 *p;
    u8 r;
    u8 s;
    u8 t;
    u8 v;

    m = -1;
    n = FALSE;
    func_0203bfec(g);
    r = g[0];
    s = g[1];
    t = g[2];
    p = a;
    for (i = 0; i < 60; i = (s8) (i + 1), p += 12) {
        func_0205ee14((u8) i, &k);
        if (k.mUnk_22_0 == 1 && func_02152698(c) != 0 && func_02152698(p) != 0 && func_02152390(p, c) != 0) {
            m = i;
            n = TRUE;
            break;
        }
    }
    if (d != 0 && n != FALSE) {
        return -1;
    }
    if (f == 0 && m == -1) {
        return -1;
    }
    if (m == -1) {
        for (i = 0; i < 60; i = (s8) (i + 1)) {
            func_0205ee14((u8) i, &k);
            if (k.mUnk_22_0 == 0) {
                m = i;
                break;
            }
        }
    }
    q = -1;
    if (m == -1) {
        h.mUnk_00 = 100;
        h.mUnk_01 = 12;
        h.mUnk_02 = 31;
        for (i = 0; i < 60; i = (s8) (i + 1)) {
            func_0205ee14((u8) i, &k);
            j.mUnk_00 = k.mUnk_0c_0;
            j.mUnk_01 = k.mUnk_0c_7;
            j.mUnk_02 = k.mUnk_0c_11;
            if (k.mUnk_22_0 == 1 && k.mUnk_22_3 == 0 && func_0203b0a0(&j, &h) != FALSE) {
                h = j;
                q = i;
            }
        }
        if (q != -1) {
            m = q;
        }
    }
    if (m == -1) {
        return -1;
    }
    MI_CpuCopy8(c, a + m * 12, 12);
    v = m;
    func_0205ee14(v, &k);
    if (n == FALSE) {
        func_02057624((u32) &k);
    }
    k.mUnk_0c_0 = r;
    k.mUnk_0c_7 = s;
    k.mUnk_0c_11 = t;
    if (d != 0) {
        k.mUnk_22_1 = 1;
    } else {
        k.mUnk_22_1 = 0;
    }
    MI_CpuCopy8(b, k.mUnk_0e, 0x14);
    k.mUnk_22_2 = e != 0;
    k.mUnk_22_0 = 1;
    func_0205ee74(v, &k);
    return m;
}

s32 func_02060cb4(const void *a, void *b) {
    u8 c[12];
    u64 d;

    d = Decimal12CharsToValue(a);
    func_021524d8(c, (u32) d, (u32) (d >> 32));
    return func_02060d1c((u8 *) data_0217aa08->mUnk_20 + 0x874, b, c, 1, 0, 1);
}
