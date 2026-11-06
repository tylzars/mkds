#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f38.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02053e74_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_02053e74_inline2(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline3(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline4(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02054754_inline(Unk0217aa00_15c8 *e) {
    BOOL r = FALSE;
    u8 f = e->mUnk_06_0;
    if (data_0217aa00->mUnk_15ec == 0) {
        if (f & 1) {
            r = TRUE;
        }
    } else {
        if (f & 2) {
            r = TRUE;
        }
    }
    return r;
}

static inline s32 func_02054754_inline2(Unk0217aa00_15bc *q, Unk0217aa00_15c8 *e) {
    u8 mask = data_0217aa00->mUnk_0044.mUnk_43;
    u8 i;
    BOOL ok = FALSE;
    u16 m;

    for (i = 1; i < 8; i++) {
        if (mask & (1 << i)) {
            if (q->mUnk_10[i] == 0) {
                ok = FALSE;
                i = 8;
            } else {
                m = data_0217aa00->mUnk_15ec == 0 ? 1 : 2;
                if ((m & e[i].mUnk_06_0) == 0) {
                    ok = FALSE;
                    i = 8;
                } else {
                    ok = TRUE;
                }
            }
        }
    }
    return ok;
}

static inline u32 func_0205465c_inline(Unk0217aa00 *p) {
    if (p == NULL) {
        return 0;
    }
    return p->mUnk_0000;
}

s32 func_02054c98(s32 a, void *b) {
    BOOL r;

    r = FALSE;
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 v;

        v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
        if (v == 0xffff) {
            return 2;
        }
    }
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0:
        case 21:
            data_0217aa00->mUnk_0454 &= ~0x40;
            data_0217aa00->mUnk_0004 = 1;
            func_020536e0();
            break;
        case 1:
            data_0217aa00->mUnk_0004 = 11;
            if (a != 0) {
                func_020532dc(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 2:
            if (a != 0) {
                func_020532dc(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 3:
            func_02053094(0);
            break;
        case 4:
            func_0204f814();
            func_0204f938(b);
            func_02052bf8();
            break;
        case 5:
            func_02052b60(NULL);
            break;
        case 6:
            func_0204ef1c();
            break;
        case 7:
            if (data_0217aa00->mUnk_1e45 == -1) {
                StartScan(0, NULL, NULL);
            } else {
                EndScan();
            }
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, NULL, func_02054f38);
            break;
        case 10:
            data_0217aa00->mUnk_1e3c = 1;
            func_0204ef1c();
            break;
        case 11:
            if (a != 0) {
                func_0204f468();
            } else {
                func_0204f408();
                func_0204ef88();
            }
            r = TRUE;
            break;
        default:
            func_020533a0();
            break;
    }
    return r;
}

s32 func_02054b44(void) {
    BOOL r;

    r = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 v;

        v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
        if (v == 0xffff) {
            return 2;
        }
    }
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0x28:
        case 0x29:
            func_0204f148();
            break;
        case 0x2a:
            switch (func_02053e74_inline()) {
                case 1:
                    data_0217aa00->mUnk_000c = 0x28;
                    break;
                case 2:
                    data_0217aa00->mUnk_000c = 0x29;
                    break;
            }
            r = TRUE;
            break;
    }
    return r;
}

void func_02054aa0(void) {
    s32 c0;
    s32 c1;

    if (data_0217aa00->mUnk_0004 != 11) {
        return;
    }
    if (data_0217aa00->mUnk_000c == 0x2c) {
        func_02006f50(data_0217aa00->mUnk_1da0[0]->mUnk_00, 0, &c0, &c1);
    }
    if (data_0217aa00->mUnk_1e42 != 0) {
        data_0217aa00->mUnk_1e42 = data_0217aa00->mUnk_1e42 - 1;
        return;
    }
    if (func_02053e74_inline() == 0) {
        return;
    }
    func_0204ed84();
}

s32 func_02054938(void) {
    BOOL r;

    r = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 v;

        v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
        if (v == 0xffff) {
            return 2;
        }
    }
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0x28:
        case 0x29:
        case 0x2a:
            data_0217aa00->mUnk_1d5c = 0;
            func_0204f0b8();
            break;
        case 0x2b:
            func_0204f008();
            break;
        case 0x2c:
            func_0204ead0(1, 0);
            break;
        case 0x2e:
            data_0217aa00->mUnk_1e3c = 0;
            r = TRUE;
            break;
    }
    return r;
}

BOOL func_02054754(void) {
    BOOL r;
    Unk0217aa00_15bc *q;

    r = FALSE;
    q = &data_0217aa00->mUnk_15bc_view;
    if (!func_02053e74_inline2()) {
        return TRUE;
    }
    if (!(data_0217aa00->mUnk_0454 & 4)) {
        return TRUE;
    }
    if (func_0204ffbc() != 0) {
        return TRUE;
    }
    if (q->mUnk_10[0] != 0) {
        Unk0217aa00 *p;

        p = data_0217aa00;
        if (func_02054754_inline(q->mUnk_0c) != 0) {
            if ((p->mUnk_0454 & 8) != 0) {
                p->mUnk_0004 = 9;
            } else {
                p->mUnk_0004 = 8;
            }
            r = TRUE;
            data_0217aa00->mUnk_15f4 = 0;
        } else if (func_02053e74_inline() == 1) {
            if (func_02054754_inline2(q, q->mUnk_0c) != 0) {
                p->mUnk_008b |= 1;
            }
        }
    }
    return r;
}

s32 func_020546d8(void) {
    if (func_02053e74_inline2()) {
        data_0217aa00->mUnk_0004 = 7;
        data_0217aa00->mUnk_008b &= ~1;
        if (data_0217aa00->mUnk_15ec == 0) {
            data_0217aa00->mUnk_15ec = 1;
        } else {
            data_0217aa00->mUnk_15ec = 0;
        }
    }
    return 1;
}

s32 func_0205465c(void) {
    Unk0217aa00 *p;
    s32 r;
    s32 x;

    r = 0;
    p = data_0217aa00;
    if (func_0205465c_inline(p) != 1) {
        r = 2;
    } else {
        if (func_0205465c_inline(p) == 1) {
            if ((p->mUnk_0454 & 0x40) != 0) {
                x = p->mUnk_1699;
            } else {
                x = p->mUnk_0044.mUnk_40;
            }
        } else {
            x = 0;
        }
        if (x == 0) {
            if (p->mUnk_1e38 != 0) {
                r = 1;
            } else {
                r = 2;
            }
        }
    }
    return r;
}

void func_020545e8(void *a) {
    data_0217aa00 = HeapAllocAligned(a, 0x1f00, 0x20);
    data_0217aa00->mUnk_0000 = 0;
    data_0217aa00->mUnk_0004 = 0;
    data_0217aa00->mUnk_0008 = 9;
    data_0217aa00->mUnk_000c = 0;
    data_0217aa00->mUnk_0010 = 0;
    data_0217aa00->mUnk_0454 = 0;
    data_0217aa00->mUnk_0456_0 = 0;
}

void func_02054368(void *a) {
    data_0217aa00->mUnk_0014 = HeapAllocAligned(a, 0xf00, 0x20);
    data_0217aa00->mUnk_0018 = HeapAllocAligned(a, 0x40, 0x20);
    data_0217aa00->mUnk_001c = HeapAllocAligned(a, 0x20, 0x20);
    data_0217aa00->mUnk_0024 = HeapAllocAligned(a, 0xc0, 0x20);
    data_0217aa00->mUnk_0028 = HeapAllocAligned(a, 0xc0, 0x20);
    data_0217aa00->mUnk_0020 = HeapAllocAligned(a, 0x44, 0x20);
    data_0217aa00->mUnk_002c = HeapAllocAligned(a, 0x400, 0x20);
    data_0217aa00->mUnk_0030 = 0x1c0;
    data_0217aa00->mUnk_0034 = (u32) HeapAllocAligned(a, data_0217aa00->mUnk_0030, 0x20);
    data_0217aa00->mUnk_0038 = 0x400;
    data_0217aa00->mUnk_003c = (u32) HeapAllocAligned(a, data_0217aa00->mUnk_0038, 0x20);
    data_0217aa00->mUnk_15bc = HeapAllocAligned(a, 0x820, 0x20);
    data_0217aa00->mUnk_15c0 = HeapAllocAligned(a, 0x200, 0x20);
    data_0217aa00->mUnk_15c4 = HeapAllocAligned(a, 8, 0x20);
    data_0217aa00->mUnk_15c8 = HeapAllocAligned(a, 0x40, 0x20);
    data_0217aa00->mUnk_0040 = HeapAllocAligned(a, 0x18, 0x20);
    data_0217aa00->mUnk_1664 = 0;
    data_0217aa00->mUnk_165c = 0;
    data_0217aa00->mUnk_1658 = 0;
    data_0217aa00->mUnk_0044.mUnk_38 = HeapAllocAligned(a, 0x1c, 0x20);
    data_0217aa00->mHeap = NNS_FndCreateExpHeapEx(HeapAlloc(a, 0x7800), 0x7800, 1);
    data_0217aa00->mUnk_1e24 = 0;
    data_0217aa00->mUnk_1e2c = 0;
    data_0217aa00->mUnk_1e20 = 0;
    data_0217aa00->mUnk_1e28 = 0;
    data_0217aa00->mUnk_0456_0 = 1;
    func_02053d00();
}

void func_02054330(void) {
    while (func_02054f58() != 1) {
    }
    data_0217aa00->mUnk_0456_0 = 0;
}

void func_02054208(Unk0217aa00_15bc *a) {
    Unk0217aa00_1e4c *q;
    s32 i;
    s32 j;

    a->mUnk_3a = 0;
    MI_CpuFill8(data_0217aa00->mUnk_15c4, 0, 8);
    for (i = 0; i < 8; i++) {
        a->mUnk_10[i] = 0;
        MI_CpuFill8(&a->mUnk_0c[i], 0, 8);
    }
    a->mUnk_3c[0] = 0;
    for (i = 0; i < 7; i++) {
        a->mUnk_3c[i] = 0;
    }
    a->mUnk_4a = 0;
    a->mUnk_34 = 5;
    a->mUnk_38 = 0;
    a->mUnk_30 = 0;
    data_0217aa00->mUnk_0454 &= ~0x10;
    data_0217aa00->mUnk_008b &= ~1;
    q = &data_0217aa00->mUnk_1e4c_view;
    q->mUnk_60 = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    data_0217aa00->mUnk_0454 &= ~0x10;
}

void func_02053fa8(void) {
    u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < 7; i++) {
        data_0217aa00->mUnk_0044.mUnk_00[i].mUnk_06 = 0xffff;
        q = data_0217aa00->mUnk_0044.mUnk_00[i].mUnk_00;
        for (j = 0; j < 6; j++) {
            q[j] = 0;
        }
    }
    data_0217aa00->mUnk_0044.mUnk_42 = 0;
    data_0217aa00->mUnk_0044.mUnk_43 = 0;
    data_0217aa00->mUnk_0044.mUnk_40 = 0;
    data_0217aa00->mUnk_0044.mUnk_3c = 0;
    data_0217aa00->mUnk_0044.mUnk_41 = -1;
    data_0217aa00->mUnk_0088 = -1;
    data_0217aa00->mUnk_008a = 0;
    data_0217aa00->mUnk_008b = 0;
    data_0217aa00->mUnk_0044.mUnk_3e = 0;
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, data_0217aa00->mUnk_0044.mUnk_38, 0x14);
    data_0217aa00->mUnk_0044.mUnk_38->mUnk_0e.mUnk_06_4 = data_021759d0->mUnk_04;
    data_0217aa00->mUnk_0044.mUnk_38->mUnk_0e.mUnk_06_0 = 0;
    for (j = 0; j < 4; j++) {
        data_0217aa00->mUnk_00ac[j].mUnk_dc_0 = 0;
        data_0217aa00->mUnk_00ac[j].mUnk_db = 0;
        q = data_0217aa00->mUnk_00ac[j].mUnk_c0;
        for (k = 0; k < 6; k++) {
            q[k] = 0;
        }
    }
    data_0217aa00->mUnk_0432 = 0xffff;
    data_0217aa00->mUnk_0438 = 0;
    data_0217aa00->mUnk_0434 = 0;
    data_0217aa00->mUnk_0439 = 1;
    data_0217aa00->mUnk_043a = 0;
    data_0217aa00->mUnk_0436 = 0;
    data_0217aa00->mUnk_043c = 0;
    data_0217aa00->mUnk_043d = 0;
    data_0217aa00->mUnk_043b = 0;
    q = data_0217aa00->mUnk_00ac_view.mUnk_380;
    for (l = 0; l < 6; l++) {
        q[l] = 0;
    }
    data_0217aa00->mUnk_0457 = 0;
    data_0217aa00->mUnk_0458 = 0;
    data_0217aa00->mUnk_1699 = 0;
    data_0217aa00->mUnk_0454 &= ~1;
    func_020562b4();
    func_02054208(&data_0217aa00->mUnk_15bc_view);
}

void func_02053e74(void) {
    Unk0217aa00_1e4c *q;
    Unk0217aa00 *p;
    Unk0217aa00_1eb8 *t;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    q = &data_0217aa00->mUnk_1e4c_view;
    q->mUnk_60 = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    data_0217aa00->mUnk_0454 &= ~0x10;
    data_0217aa00->mUnk_0454 |= 8;
    p = data_0217aa00;
    a = 0;
    switch (func_02053e74_inline()) {
        case 1:
            a = p->mUnk_0018->mUnk_0c;
            break;
        case 2:
            a = p->mUnk_0024->mUnk_48;
            break;
    }
    b = 0;
    switch (func_02053e74_inline()) {
        case 1:
            b = p->mUnk_0018->mUnk_0c;
            break;
        case 2:
            b = p->mUnk_0024->mUnk_48;
            break;
    }
    p->mUnk_1eb8.mUnk_00 = b + (a << 10);
    t = &p->mUnk_1eb8;
    t->mUnk_04 = 0;
    t->mUnk_08 = 0x6c078965;
    t->mUnk_0c = 0x5d588b65;
    t->mUnk_10 = 0x269ec3;
    t->mUnk_14 = 0;
}
