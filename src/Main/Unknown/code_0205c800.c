#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205bc08.h"
#include "Main/Unknown/code_0205c800.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219bb50.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

void func_0205c800(u16 a, void (*b)(u32)) {
    u16 i;
    s32 r;
    u16 n;

    r = -1;
    for (i = 1; i <= 4; i++) {
        n = a + i;
        if (n >= 4) {
            n = n - 4;
        }
        if (n != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << (u8) n)) != 0) {
            r = n;
            break;
        }
    }
    if (r == -1) {
        return;
    }
    b(r);
}

void func_0205c898(void) {
    s32 i;
    Unk0217aa14 *p;
    u8 n;
    u64 x;

    data_0217aa14->mUnk_0fa = 1 << func_ov000_0219bb50();
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_0f8 = 0;
    for (i = 0; i < 4; i++) {
        p = data_0217aa14;
        n = p->mUnk_014[i].mUnk_34;
        x = *(u64 *) &p->mUnk_014[i].mUnk_28;
        if (n == 0) {
            p->mUnk_104[i].mUnk_84 = 0;
        } else {
            p->mUnk_104[i].mUnk_84 = (x / n * 64 / 0x82ea + 32) / 33;
        }
    }
}

static inline BOOL func_0205c98c_inline(void) {
    u8 i;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_014[i].mUnk_30 != 0) {
            func_0214d1fc(&p->mUnk_014[i], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = func_0200f5ac();
            if (func_0205c340(i, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[i].mUnk_30 = 0;
            } else {
                func_0214d168(q, 0, 0x28);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void func_0205c98c(void) {
    u16 i;
    u8 m;
    u16 k;
    u8 b;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;
    Unk0217aa14_754 *r;

    m = 0;
    for (i = 0; i < 4; i++) {
        if (i == func_ov000_0219bb50() || data_0217aa14->mUnk_014[i].mUnk_34 >= 12) {
            m = m | (1 << i);
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & m)) {
        p->mUnk_0fb = m;
        p = data_0217aa14;
        p->mUnk_010 = 2;
        p->mUnk_012 = 1;
    }
    if (func_0205c98c_inline() != FALSE) {
        return;
    }
    p = data_0217aa14;
    k = p->mUnk_0f8;
    if (k < 4) {
        b = k;
        if ((p->mUnk_749 & (1 << b)) != 0 && b != func_ov000_0219bb50()) {
            p = data_0217aa14;
            if (p->mUnk_014[b].mUnk_34 < 12) {
                r = p->mUnk_754;
                q = &r->mUnk_04;
                r->mUnk_04.mUnk_00_h = func_ov000_0219bb50();
                *(u64 *) &q->mUnk_04 = func_0200f5ac();
                q->mUnk_0c[0] = 0;
                q->mUnk_0c[1] = 0;
                q->mUnk_0c[2] = 0;
                q->mUnk_0c[3] = 0;
                q->mUnk_0c[4] = 0;
                *(u32 *) &q->mUnk_20[0] = 0;
                func_0205c340(b, 0, 0x28);
            } else {
                if (p->mUnk_014[b].mUnk_36 == 0) {
                    func_0205c340(b, 5, 0);
                }
                data_0217aa14->mUnk_014[b].mUnk_36++;
                if (data_0217aa14->mUnk_014[b].mUnk_36 > 4) {
                    data_0217aa14->mUnk_014[b].mUnk_36 = 0;
                }
            }
        }
        data_0217aa14->mUnk_0f8++;
    } else {
        p->mUnk_0f8 = 0;
    }
}

void func_0205cbe4(void) {
    u8 i;
    s32 *e;
    Unk0217aa14 *b;

    for (i = 0; i < 4; i++) {
        e = &data_0217aa14->mUnk_014[i].mUnk_04;
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
        e[4] = 0;
        e[5] = 0;
        e[6] = 0;
        e[7] = 0;
        e[8] = 0;
        b = data_0217aa14;
        b->mUnk_014[i].mUnk_28 = 0;
        b->mUnk_014[i].mUnk_2c = 0;
        b->mUnk_014[i].mUnk_34 = 0;
        data_0217aa14->mUnk_014[i].mUnk_35 = 0;
        data_0217aa14->mUnk_014[i].mUnk_36 = 0;
    }
    data_0217aa14->mUnk_0f8 = 0;
    data_0217aa14->mUnk_0fb = 0;
    data_0217aa14->mUnk_0fd = 0;
    data_0217aa14->mUnk_0f4 = 0;
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_758 = 1;
    data_0217aa14->mUnk_75c &= ~2;
    data_0217aa14->mUnk_75c |= 0x80;
    data_0217aa14->mUnk_75c &= ~0x10;
}

void func_0205ccec(void) {
    Unk0217aa14 *p;

    p = data_0217aa14;
    if (p == NULL) {
        return;
    }
    switch (p->mUnk_00e) {
        case 4:
        case 5:
            p->mUnk_728++;
            break;
    }
}

void func_0205cd24(void *a) {
    s32 i;
    s32 j;
    u8 k;
    s32 n;
    u8 m;
    Unk0217aa14 *p;

    if (data_021759c0->mUnk_08 != 5) {
        return;
    }
    data_0217aa14 = HeapAlloc(a, 0x760);
    data_0217aa14->mUnk_754 = HeapAllocAligned(a, 0x6c, 0x20);
    for (i = 0; i < 16; i++) {
        data_0217aa14->mUnk_324[i].mUnk_04 = HeapAllocAligned(a, 20, 32);
        for (j = 0; j < 4; j++) {
            data_0217aa14->mUnk_3e4[i][j].mUnk_04 = HeapAllocAligned(a, 20, 32);
        }
    }
    data_0217aa14->mUnk_0fc = data_0217aa18->mUnk_04;
    func_0214d168(data_0217aa14->mUnk_754, 0, 0x6c);
    for (n = 0; n < 4; n++) {
        func_0214d168(&data_0217aa14->mUnk_104[n], 0, 0x68);
        data_0217aa14->mUnk_104[n].mUnk_86_0 = 0;
    }
    k = data_0217aa14->mUnk_0fc;
    data_0217aa14->mUnk_748 = 0;
    data_0217aa14->mUnk_749 = k;
    for (k = 0; k < 4; k++) {
        data_0217aa14->mUnk_74a[k] = 0;
        data_0217aa14->mUnk_740[k] = 0;
    }
    func_0205ad88();
    func_0205a6b4();
    data_0217aa14->mUnk_75c |= 1;
    data_0217aa14->mUnk_75c |= 0x40;
    p = data_0217aa14;
    p->mUnk_010 = 0;
    p->mUnk_012 = 1;
    data_0217aa14->mUnk_758 = 0;
    for (m = 0; m < 4; m++) {
        j = data_0217aa18->mUnk_06[m];
        data_0217aa14->mUnk_104[m].mUnk_80 = 0;
        if (j >= 0) {
            data_0217aa14->mUnk_104[m].mUnk_86_1 = func_0205d27c((u8) j);
        } else {
            data_0217aa14->mUnk_104[m].mUnk_86_1 = 0;
        }
    }
    func_02046be8(data_0217aa14, data_02165388, 6, NULL);
}

void func_0205cfd4(u32 a) {
    u8 i;
    u8 n;

    for (i = 0, n = 0; i < 4; i++) {
        data_0217aa18->mUnk_06[i] = -1;
        if ((a & (1 << i)) != 0) {
            data_0217aa18->mUnk_00[n] = i;
            data_0217aa18->mUnk_06[i] = n;
            n++;
        }
    }
    data_0217aa18->mUnk_04 = a;
    while (n < 4) {
        data_0217aa18->mUnk_00[n] = -1;
        n++;
    }
}

void func_0205d07c(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_0217aa18->mUnk_00[i] = -1;
        data_0217aa18->mUnk_06[i] = -1;
    }
    data_0217aa18->mUnk_05 = 0;
}
