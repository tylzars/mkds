#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020ae730.h"
#include "Main/Unknown/code_020be950.h"

#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c7464.h"
#include "Main/Unknown/code_020c7690.h"
#include "Main/Unknown/code_020c77a0.h"
#include "Main/Unknown/code_020c79d4.h"
#include "Main/Unknown/code_020c7b0c.h"
#include "Main/Unknown/code_020c7c1c.h"
#include "Main/Unknown/code_020c7d54.h"
#include "Main/Unknown/code_020c7f84.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c8d30.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ca3e4.h"
#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020cce24.h"
#include "Main/Unknown/code_020ccf6c.h"
#include "Main/Unknown/code_020cd2f0.h"
#include "Main/Unknown/code_020cd44c.h"
#include "Main/Unknown/code_020cd598.h"
#include "Main/Unknown/code_020cd6f4.h"
#include "Main/Unknown/code_020cd844.h"
#include "Main/Unknown/code_020cd9dc.h"
#include "Main/Unknown/code_020cdb54.h"
#include "Main/Unknown/code_020cdc90.h"
#include "Main/Unknown/code_020cdde4.h"
#include "Main/Unknown/code_020cdf18.h"
#include "Main/Unknown/code_020ce100.h"
#include "Main/Unknown/code_020ce264.h"
#include "Main/Unknown/code_020ce3e0.h"
#include "Main/Unknown/code_020ce548.h"
#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020beb9c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cd000.h"
#include "Main/Unknown/code_020ce000.h"
#include "Main/Unknown/code_020cf000.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02169000.h"
#include "01/code_021892ac.h"
#include "01/code_02188e88.h"
#include "01/code_021899e4.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020ae000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_021813f4.h"

u32 func_020c0dc4(void) {
    return ((u32) data_0217b3dc->mUnk_000);
}

u32 func_020c0db0(void) {
    return ((u32) data_0217b3dc->mUnk_004);
}

u32 func_020c0d9c(void) {
    return ((u32) data_0217b3dc->mUnk_008);
}

BOOL func_020c0c2c(Unk0217b498 **a, s32 b) {
    BOOL t;
    void *q;
    void *p;
    s32 i;
    s32 n;

    t = FALSE;
    q = func_021000d0(b);
    p = func_02100138(b);
    if (b == 0x1ae || b == 0x1ab) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (p == NULL) {
            return FALSE;
        }
        n = func_021000c8(p);
        if (n == 0) {
            return FALSE;
        }
    } else {
        if (q == NULL) {
            return FALSE;
        }
        n = func_02100094(q);
        if (n == 0) {
            return FALSE;
        }
    }
    *a = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    if (t != FALSE) {
        (*a)->mUnk_00 = (Unk0217b498_00 **) func_0210008c(p);
    } else {
        (*a)->mUnk_00 = (Unk0217b498_00 **) func_02100084(q);
    }
    (*a)->mUnk_04 = 0;
    (*a)->mUnk_08 = n;
    (*a)->mUnk_0c = HeapAlloc(GetHeap(func_020364e8()), n * 8);
    for (i = 0; i < n; i++) {
        func_020b5fe4(&(*a)->mUnk_00[i]->mUnk_04, &(*a)->mUnk_0c[i]);
    }
    (*a)->mUnk_10 = func_020ae730(n * 2, 0x14);
    return TRUE;
}

BOOL func_020c0ba8(Unk0217b498 **a, s32 b) {
    if (b == 0) {
        return FALSE;
    }
    *a = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    (*a)->mUnk_04 = 0;
    (*a)->mUnk_08 = b;
    (*a)->mUnk_0c = HeapAlloc(GetHeap(func_020364e8()), b * 8);
    (*a)->mUnk_10 = func_020ae730(b, 0x14);
    return TRUE;
}

void func_020c0b84(Unk0217b498 **a) {
    (*a)->mUnk_00 = NULL;
    (*a)->mUnk_0c = NULL;
    (*a)->mUnk_10 = NULL;
    *a = NULL;
}

void func_020c092c(Unk020c06c4 *a, Unk0217b498 *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    u16 n;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    Unk020c06c4_08 *t;
    Unk0217b498_10 *r;
    s32 x;
    s32 y;
    void *z;

    l = data_0217b3dc->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mUnk_04; i++) {
        p = b->mUnk_10[i].mUnk_0c;
        if (l <= p) {
            q = b->mUnk_10[i].mUnk_0e;
            n = 0;
            if (c != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4cb0(d, (u16) (b->mUnk_10[i].mUnk_10 + 0x8000 - v));
                } else {
                    func_020b4cb0(d, (u16) (v + (0x8000 - b->mUnk_10[i].mUnk_10)));
                }
                n = func_020ae5c4(a);
                a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            }
            r = &b->mUnk_10[i];
            x = r->mUnk_00.mUnk_00;
            z = r->mUnk_08;
            y = r->mUnk_00.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 +=
                func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, c != 0 ? d : 0, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}

void func_020c06c4(Unk020c06c4 *a, Unk0217b498 *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    u16 n;
    Unk020c06c4_08 *t;
    Unk0217b498_10 *r;
    s32 x;
    s32 y;
    void *z;

    l = data_0217b3dc->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mUnk_04; i++) {
        p = b->mUnk_10[i].mUnk_0c;
        if (l <= p) {
            q = b->mUnk_10[i].mUnk_0e;
            if (c != 0) {
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b4bf8(d, b->mUnk_0c[i].mUnk_00, (u16) (b->mUnk_10[i].mUnk_10 - v));
                } else {
                    func_020b4bf8(d, b->mUnk_0c[i].mUnk_00, (u16) (v - b->mUnk_10[i].mUnk_10));
                }
            } else {
                func_020b4cec(d, b->mUnk_0c[i].mUnk_00);
            }
            n = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            r = &b->mUnk_10[i];
            x = r->mUnk_00.mUnk_00;
            z = r->mUnk_08;
            y = r->mUnk_00.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, d, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}

void func_020beb9c(void) {
    data_0217b3dc = HeapAlloc(GetHeap(func_020364e8()), 0x25c);
    data_0217b3dc->mUnk_000 = 0;
    data_0217b3dc->mUnk_004 = 0;
    data_0217b3dc->mUnk_008 = 0;
    data_0217b3dc->mUnk_00c = 0;
    if (func_020c9fb8()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c9fb8 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ca3e4()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ca3e4 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cf310()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cf310 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7464()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7464 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7690()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7690 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c77a0()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c77a0 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c79d4()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c79d4 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ca534()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ca534 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7b0c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7b0c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7c1c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7c1c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7d54()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7d54 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c7f84()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c7f84 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c8254()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c8254 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020c8d30()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020c8d30 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ca670()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ca670 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cce24()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cce24 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ccf6c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ccf6c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd2f0()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd2f0 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ce3e0()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ce3e0 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cdc90()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cdc90 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cdb54()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cdb54 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd844()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd844 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd598()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd598 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd44c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd44c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ce6a8()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ce6a8 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ce100()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ce100 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd9dc()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd9dc && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ce264()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ce264 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cdf18()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cdf18 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020d0e3c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020d0e3c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cdde4()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cdde4 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cd6f4()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cd6f4 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020ce548()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020ce548 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020cee0c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020cee0c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020d0280()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020d0280 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_020d011c()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_020d011c && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (data_021759c0->mUnk_08 != 4) {
        return;
    }
    if (func_ov001_02181510()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02181510 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189584()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189584 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_021896e0()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_021896e0 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189848()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189848 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189290()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189290 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189bd8()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189bd8 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_021899b0()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_021899b0 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189d88()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189d88 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189410()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189410 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
    if (func_ov001_02189128()) {
        s32 n;
        s32 i;

        n = data_0217b3dc->mUnk_00c++;
        for (i = 0; data_021691ec[i].mUnk_00 != func_ov001_02189128 && i < 49; i++) {
        }
        if (i < 49) {
            data_0217b3dc->mUnk_010[n] = data_021691ec[i].mUnk_04;
            data_0217b3dc->mUnk_0d4[n] = data_021691ec[i].mUnk_08;
            data_0217b3dc->mUnk_198[n] = data_021691ec[i].mUnk_0c;
        }
    }
}

void func_020beb40(void) {
    s32 i;

    for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
        data_0217b3dc->mUnk_010[i]();
    }
    data_0217b3dc = NULL;
}

void func_020be9d4(void) {
    Vec3 v;
    s32 i;
    s32 n;
    float f;

    switch (func_020b1dbc()) {
        case 0:
            func_020c97c0();
            break;
        case 1:
        case 2:
        case 3:
            if (func_020b1d50() * 3 > 0) {
                f = 0.5f + (float) (func_020b1d50() * 0x3000);
            } else {
                f = (float) (func_020b1d50() * 0x3000) - 0.5f;
            }
            n = (s32) f;
            data_0217b3dc->mUnk_004 = (s32) (((s64) n * 20) >> 12);
            data_0217b3dc->mUnk_008 = func_02147f34(0x2400, data_0217b3dc->mUnk_004);
            func_020b503c(func_020b1d34(), data_0217b3dc->mUnk_004);
            func_0207a91c(&v, func_020b4d9c());
            data_0217b3dc->mUnk_000 = func_020b4e70(&v) != 0 ? 0 : 3;
            for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
                data_0217b3dc->mUnk_0d4[i]();
            }
            break;
    }
}

void func_020be950(void *a) {
    s32 i;

    switch (func_020b1dbc()) {
        case 0:
            func_020c8dbc(a);
            break;
        case 1:
        case 2:
        case 3:
            for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
                data_0217b3dc->mUnk_198[i](a);
            }
            break;
    }
}
