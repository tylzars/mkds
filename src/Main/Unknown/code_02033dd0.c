#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

// Reads the table of data_0217aa1c, a row chosen by one call and a column by another.
static inline Unk0217aa1c_00 *func_02033e6c_inline(u32 a) {
    return &data_0217aa1c->mUnk_000[func_0205db28()][func_0205dc7c(a)];
}

#pragma thumb on

s32 func_02033dd0(void) {
    BOOL r;

    r = FALSE;
    if (data_02174e60->mUnk_148 != 0 && data_02174e60->mUnk_14c < 0x12c) {
        r = TRUE;
    }
    return r;
}

s32 func_02033dfc(void) {
    BOOL r;

    r = FALSE;
    if (data_02174e60->mUnk_148 != 0 && data_02174e60->mUnk_14c == 0) {
        r = TRUE;
    }
    return r;
}

s32 func_02033e24(void) {
    s32 r;
    s32 i;

    r = 1;
    i = 0;
    for (; i < data_02174e60->mUnk_0d8; i++) {
        r &= data_02174e60->mUnk_0e4[i].mUnk_00 == 0 ? 1 : 0;
    }
    return r;
}

// non-matching: same instructions and size (0x1b8); registers differ: the original keeps the object pointer of the
// sorting loops in r3, the rank in r4 and the inner counter in r1, ours r2, r3 and r4
void func_02033e6c(void) {
    u16 i;
    u16 j;
    u16 k;
    s32 n;

    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_02174e60->mUnk_0e0 == 3 || data_021759c0->mUnk_1c == 2) {
            data_02174e60->mUnk_0e4[i].mUnk_04 = func_02033e6c_inline(func_0205dc7c(i))->mUnk_00;
        } else {
            data_02174e60->mUnk_0e4[i].mUnk_04 = func_02033e6c_inline(func_0205dc7c(i))->mUnk_05;
        }
    }
    for (j = 0; j < data_02174e60->mUnk_0d8; j++) {
        n = 0;
        for (k = 0; k < data_02174e60->mUnk_0d8; k++) {
            if (j != k && data_02174e60->mUnk_0e4[j].mUnk_04 < data_02174e60->mUnk_0e4[k].mUnk_04) {
                n++;
            }
        }
        data_02174e60->mUnk_0e4[j].mUnk_00 = n;
    }
    if (data_021759c0->mUnk_58 != 0) {
        if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_1c == 1) {
            func_02034188();
        } else {
            func_02034024();
        }
    } else if (data_021759c0->mUnk_08 == 2) {
        for (k = 0; k < data_02174e60->mUnk_0d8; k++) {
            data_02174e60->mUnk_0e4[k].mUnk_08 = data_0217b488->mUnk_ec[k];
        }
    } else {
        for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
            data_02174e60->mUnk_0e4[i].mUnk_08 = func_0205d4e8(i) - 1;
        }
    }
}

// non-matching: 0x168 bytes, original 0x164; same loops, but the original keeps the rank on the stack (offset 0x24) and
// fills the two index lists through post-incremented pointers, ours through indexes
void func_02034024(void) {
    Unk02174e60 *o;
    s32 a[8];
    s32 b[8];
    s32 c[8];
    s32 r;
    s32 v1;
    s32 v2;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 v;

    r = 0;
    v1 = 0;
    v2 = 0;
    o = data_02174e60;
    for (i = 0; i < o->mUnk_0d8; i++) {
        a[i] = o->mUnk_0e4[i].mUnk_04;
    }
    o = data_02174e60;
    for (i = 0; i < o->mUnk_0d8; i++) {
        if (data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_04 == 0) {
            b[v1++] = i;
        } else {
            c[v2++] = i;
        }
    }
    for (j = 0; j < v1; j++) {
        v = -1;
        m = -1;
        for (k = 0; k < v1; k++) {
            if (v < a[b[k]]) {
                v = a[b[k]];
                m = k;
            }
        }
        data_02174e60->mUnk_0e4[b[m]].mUnk_08 = r++;
        a[b[m]] = -2;
    }
    if (r < 4 && v2 <= 4) {
        r = 4;
    }
    for (j = 0; j < v2; j++) {
        v = -1;
        m = -1;
        for (k = 0; k < v2; k++) {
            if (v < a[c[k]]) {
                v = a[c[k]];
                m = k;
            }
        }
        data_02174e60->mUnk_0e4[c[m]].mUnk_08 = r++;
        a[c[m]] = -2;
    }
}

void func_02034188(void) {
    Unk02174e60 *o;
    s32 r;
    s32 n;
    s32 i;

    r = 0;
    n = 0;
    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_04 == 0) {
            data_02174e60->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_04 == 1) {
            n++;
        }
    }
    if (r < 4 && n <= 4) {
        r = 4;
    }
    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_04 == 1) {
            data_02174e60->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
}

// non-matching: 0xf8 bytes, original 0x108; the original keeps each OR constant of the halfword updates in its own
// register (0x1f or 0xe or 7, then 0x20) where ours folds them into one constant
void func_02034244(void) {
    s16 a;

    a = func_02025ebc(&data_02174e64->mUnk_194);
    *(vu32 *) 0x4000010 = (a << 16) & 0x1ff0000;
    *(vu32 *) 0x400101c = (-a << 16) & 0x1ff0000;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4000048 = (*(vu16 *) 0x4000048 & ~0x3f) | 0x1f | 0x20;
        *(vu16 *) 0x400004a = (*(vu16 *) 0x400004a & ~0x3f) | 0xe | 0x20;
        *(vu16 *) 0x4000040 = 0xff;
        *(vu16 *) 0x4000044 = ((-a << 8) & 0xff00) | 0xc0;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(vu16 *) 0x4001048 = (*(vu16 *) 0x4001048 & ~0x3f) | 0x1f | 0x20;
        *(vu16 *) 0x400104a = (*(vu16 *) 0x400104a & ~0x3f) | 7 | 0x20;
        *(vu16 *) 0x4001040 = 0xff;
        *(vu16 *) 0x4001044 = (a + 0xc0) & 0xff;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
        *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
