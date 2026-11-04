#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

// Reads the table of data_0217aa1c, a row chosen by one call and a column by another.
static inline Unk0217aa1c_00 *func_02033e6c_inline(u32 a) {
    return &data_0217aa1c->mUnk_000[func_0205db28()][func_0205dc7c(a)];
}

#pragma thumb on

void func_02034244(void) {
    s16 a;
    u32 b;
    u32 c;
    s32 d;
    s32 e;

    a = func_02025ebc(&data_02174e64->mUnk_194);
    *(vu32 *) 0x4000010 = (a << 16) & 0x1ff0000;
    d = -a;
    *(vu32 *) 0x400101c = (d << 16) & 0x1ff0000;
    switch (a) {
        default:
            *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x2000;
            e = (*(vu16 *) 0x4000048 & ~0x3f) | 0x1f;
            *(vu16 *) 0x4000048 = e | 0x20;
            *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0xe) | 0x20;
            *(vu16 *) 0x4000040 = 0xff;
            *(vu16 *) 0x4000044 = ((d << 8) & 0xff00) | 0xc0;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffff1fff) | 0x2000;
            c = (*(vu16 *) 0x4001048 & ~0x3f) | 0x1f;
            *(vu16 *) 0x4001048 = c | 0x20;
            b = (*(vu16 *) 0x400104a & ~0x3f) | (u32) 7;
            *(vu16 *) 0x400104a = b | 0x20;
            *(vu16 *) 0x4001040 = 0xff;
            *(vu16 *) 0x4001044 = (a + 0xc0) & 0xff;
            break;
        case 0:
            *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
            *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
            break;
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
        if (data_021759c0->mCurrentEntries[(u16) i].mUnk_08.mTeamIndex == 0) {
            data_02174e60->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_021759c0->mCurrentEntries[(u16) i].mUnk_08.mTeamIndex == 1) {
            n++;
        }
    }
    if (r < 4 && n <= 4) {
        r = 4;
    }
    for (i = 0; i < data_02174e60->mUnk_0d8; i++) {
        if (data_021759c0->mCurrentEntries[(u16) i].mUnk_08.mTeamIndex == 1) {
            data_02174e60->mUnk_0e4[i].mUnk_08 = r;
            r++;
        }
    }
}

void func_02034024(void) {
    Unk02174e60 *o;
    s32 a[8];
    s32 b[8];
    s32 c[8];
    s32 m;
    s32 r;
    s32 k;
    s32 v1;
    s32 i;
    s32 v2;
    s32 j;
    s32 v;
    s32 d;
    s32 e;
    s32 f;

    r = 0;
    v1 = 0;
    v2 = 0;
    for (i = 0; i < (o = data_02174e60)->mUnk_0d8; i++) {
        a[i] = o->mUnk_0e4[i].mUnk_04;
    }
    for (i = 0; i < (o = *(Unk02174e60 **) &data_02174e60)->mUnk_0d8; i++) {
        if (data_021759c0->mCurrentEntries[(u16) i].mUnk_08.mTeamIndex == 0) {
            b[v1] = i;
            v1 = v1 + 1;
        } else {
            c[v2] = i;
            v2 = v2 + 1;
        }
    }
    for (d = 0; d < v1; d++) {
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
        e = -1;
        f = -1;
        for (k = 0; k < v2; k++) {
            if (e < a[c[k]]) {
                e = a[c[k]];
                f = k;
            }
        }
        data_02174e60->mUnk_0e4[c[f]].mUnk_08 = r++;
        a[c[f]] = -2;
    }
}

void func_02033e6c(void) {
    u16 j;
    u16 k;
    s32 n;

    for (k = 0; k < data_02174e60->mUnk_0d8; k++) {
        if (data_02174e60->mUnk_0e0 == 3 || data_021759c0->mUnk_1c == 2) {
            data_02174e60->mUnk_0e4[k].mUnk_04 = func_02033e6c_inline(func_0205dc7c(k))->mUnk_00;
        } else {
            data_02174e60->mUnk_0e4[k].mUnk_04 = func_02033e6c_inline(func_0205dc7c(k))->mUnk_05;
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
    if (data_021759c0->mUseTeams != 0) {
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
        for (k = 0; k < data_02174e60->mUnk_0d8; k++) {
            data_02174e60->mUnk_0e4[k].mUnk_08 = func_0205d4e8(k) - 1;
        }
    }
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

s32 func_02033dfc(void) {
    BOOL r;

    r = FALSE;
    if (data_02174e60->mUnk_148 != 0 && data_02174e60->mUnk_14c == 0) {
        r = TRUE;
    }
    return r;
}

s32 func_02033dd0(void) {
    BOOL r;

    r = FALSE;
    if (data_02174e60->mUnk_148 != 0 && data_02174e60->mUnk_14c < 0x12c) {
        r = TRUE;
    }
    return r;
}

#pragma thumb off
