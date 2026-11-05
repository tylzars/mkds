#include "Main/Unknown/code_020c5dd8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020c06c4.h"

#include "Main/Unknown/code_020c5df0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020ba000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214cfe4.h"
#include "code_020222ec.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020c70d8.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0203c5f8.h"

u32 func_020c70d8(void) {
    return ((u32) gRaceNewRecordTa->mUnk_14);
}

s32 func_020c70bc(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_18 : 0;
}

s32 func_020c70a0(void) {
    return gRaceNewRecordTa != NULL ? gRaceNewRecordTa->mUnk_dc : 0;
}

void InitRaceNewRecordTa(void) {
    s32 i;

    if (data_021759c0->mMode != 1) {
        return;
    }
    gRaceNewRecordTa = HeapAlloc(GetHeap(func_020364e8()), 0xe8);
    gRaceNewRecordTa->mUnk_00 = func_020c610c;
    gRaceNewRecordTa->mUnk_04 = 0;
    gRaceNewRecordTa->mUnk_08 = 0;
    gRaceNewRecordTa->mUnk_0c = -1;
    gRaceNewRecordTa->mUnk_10 = 0;
    gRaceNewRecordTa->mUnk_14 = 0;
    gRaceNewRecordTa->mUnk_18 = 0;
    for (i = 0; i < 6; i++) {
        func_02056bc0(data_021759c0->mCourseId, i, &gRaceNewRecordTa->mRecords[i]);
    }
    gRaceNewRecordTa->mUnk_18 = 0;
    gRaceNewRecordTa->mUnk_dc = 0;
    gRaceNewRecordTa->mOffsetX = -0x100;
    gRaceNewRecordTa->mUnk_e4 = 0;
}

void func_020c6f84(void) {
    if (data_021759c0->mMode == 1) {
        gRaceNewRecordTa = NULL;
    }
}

void func_020c6f14(void) {
    if (data_021759c0->mMode != 1) {
        return;
    }
    gRaceNewRecordTa->mUnk_00();
    gRaceNewRecordTa->mUnk_e4 = gRaceNewRecordTa->mUnk_e4 + 1;
    if (gRaceNewRecordTa->mUnk_e4 >= 0x18) {
        gRaceNewRecordTa->mUnk_e4 = 0;
    }
}

void func_020c6adc(Unk020c06c4 *a, s32 b, s32 c, Unk02056bc0 *d) {
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 e5[2];
    s32 e6[2];
    s32 e7[2];
    s32 e8[2];
    s32 v[9] = {0, 9, 18, 28, 37, 46, 56, 65, 74};
    TimeDigits w;
    s32 k;
    void *p;

    SplitTimeDigits(d->mUnk_02, d->mUnk_03, d->mUnk_00, &w);
    if (d->mUnk_18 == 0) {
        w.mUnk_00[0] = w.mUnk_00[1] = w.mUnk_00[2] = w.mUnk_00[3] = w.mUnk_00[4] = w.mUnk_00[5] = w.mUnk_00[6] = 0xb;
    }
    if (w.mUnk_00[0] != 0) {
        p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[0] + 0xe);
        e0[0] = (b + v[0]) << 12;
        e0[1] = c << 12;
        k = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e0, 0, 1);
    }
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[1] + 0xe);
    e1[0] = (b + v[1]) << 12;
    e1[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e1, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(0x18);
    e2[0] = (b + v[2]) << 12;
    e2[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e2, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[2] + 0xe);
    e3[0] = (b + v[3]) << 12;
    e3[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e3, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[3] + 0xe);
    e4[0] = (b + v[4]) << 12;
    e4[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e4, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(0x18);
    e5[0] = (b + v[5]) << 12;
    e5[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e5, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[4] + 0xe);
    e6[0] = (b + v[6]) << 12;
    e6[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e6, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[5] + 0xe);
    e7[0] = (b + v[7]) << 12;
    e7[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e7, 0, 1);
    p = GetRaceNewRecordTaSNcerEntry(w.mUnk_00[6] + 0xe);
    e8[0] = (b + v[8]) << 12;
    e8[1] = c << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e8, 0, 1);
}

void func_020c692c(Unk020c06c4 *a, s32 b, s32 c, s32 d) {
    s32 e0[2];
    s32 e1[2];
    Unk02056bc0 l;
    s32 n;
    BOOL f;
    s32 k;
    void *p;
    RaceNewRecordTa *m;

    m = gRaceNewRecordTa;
    n = m->mUnk_e4;
    f = FALSE;
    l = m->mRecords[b];
    if (b == 5) {
        if ((m != NULL ? m->mUnk_10 : 0) != 0) {
            b = 0;
            f = TRUE;
        } else {
            b = 6;
        }
    } else if (m->mUnk_08 == 0 || b < m->mUnk_0c) {
        b++;
    } else if (b == m->mUnk_0c) {
        b = 0;
        f = TRUE;
    }
    if (l.mUnk_18 != 0) {
        p = GetRaceNewRecordTaSNcerEntry(b + 7);
        e0[0] = (c + 0x32) << 12;
        e0[1] = d << 12;
        k = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e0, 0, 1);
        p = GetRaceNewRecordTaSNcerEntry(b + 0x1a);
        e1[0] = (c + 0x3d) << 12;
        e1[1] = d << 12;
        k = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e1, 0, 1);
    }
    if (f != FALSE && n >= 0x10) {
        return;
    }
    func_020c6adc(a, c + 0xab, d, &l);
}

void DrawRaceNewRecordTa(Unk020c06c4 *a) {
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    u16 i;
    s32 k;
    s32 x;
    void *p;

    p = GetRaceNewRecordTaSNcerEntry(0);
    e0[0] = (gRaceNewRecordTa->mOffsetX + 0x80) << 12;
    e0[1] = 0xc000;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e0, 0, 1);
    for (i = 0; i < 5; i++) {
        p = GetRaceNewRecordTaSNcerEntry(i + 1);
        x = i * 0x18 + 0x28;
        e1[0] = gRaceNewRecordTa->mOffsetX << 12;
        e1[1] = (i * 0x18 + 0x28) << 12;
        k = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e1, 0, 1);
        func_020c692c(a, i, gRaceNewRecordTa->mOffsetX, x);
    }
    p = GetRaceNewRecordTaSNcerEntry(6);
    e2[0] = gRaceNewRecordTa->mOffsetX << 12;
    e2[1] = 0x9f000;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, p, NULL, e2, 0, 1);
    func_020c692c(a, i, gRaceNewRecordTa->mOffsetX + 1, 0xb4);
}

BOOL func_020c657c(s32 a) {
    u8 x;
    u8 y;
    u16 z;
    s32 k;
    s32 j;
    Unk02056bc0 *q;
    s32 t;
    Unk02056bc0 *e;
    Unk02056bc0 *g;
    u8 n0;
    u8 n1;
    u16 n2;

    GetKartFinishTime(func_020b4d9c(), &x, &y, &z);
    q = gRaceNewRecordTa->mRecords;
    t = y * 1000 + x * 60000 + z;
    k = 0;
    do {
        if (q->mUnk_18 == 0 || t < q->mUnk_00 + (q->mUnk_03 * 1000 + q->mUnk_02 * 60000)) {
            goto found;
        }
        k++;
        q++;
    } while (k < 5);
    return FALSE;
found:
    if (a != 0) {
        for (j = 4; j > k; j--) {
            gRaceNewRecordTa->mRecords[j] = gRaceNewRecordTa->mRecords[j - 1];
            func_02056c6c(data_021759c0->mCourseId, j, &gRaceNewRecordTa->mRecords[j]);
        }
        n2 = z;
        n1 = y;
        n0 = x;
        g = gRaceNewRecordTa->mRecords;
        e = g + k;
        e->mUnk_02 = n0;
        e->mUnk_03 = n1;
        g[k].mUnk_00 = n2;
        MemCopyHalfwords(data_021759c0->mCurrentEntries[func_020b4d9c()].mPlayer.mName, e->mUnk_04, 0x14);
        e->mUnk_18 = 1;
        e->mUnk_19 = data_021759c0->mCurrentEntries[func_020b4d9c()].mCharacterIndex;
        e->mUnk_1a = data_021759c0->mCurrentEntries[func_020b4d9c()].mKartIndex;
        func_02056c6c(data_021759c0->mCourseId, k, e);
        if (k != 5) {
            gRaceNewRecordTa->mUnk_0c = k;
        }
    } else {
        gRaceNewRecordTa->mUnk_0c = k;
    }
    return TRUE;
}

BOOL func_020c6428(s32 a) {
    u8 x;
    u8 y;
    u16 z;
    Unk02056bc0 *e;
    Unk02056bc0 *g;
    u8 n0;
    u8 n1;
    u16 n2;

    e = &gRaceNewRecordTa->mRecords[5];
    gRaceNewRecordTa->mUnk_14 = GetKartBestLapTime(func_020b4d9c(), &x, &y, &z);
    if (e->mUnk_18 != 0) {
        if (z + (y * 1000 + x * 60000) >= e->mUnk_00 + (e->mUnk_03 * 1000 + e->mUnk_02 * 60000)) {
            return FALSE;
        }
    }
    if (a != 0) {
        n2 = z;
        n1 = y;
        n0 = x;
        g = gRaceNewRecordTa->mRecords;
        e = g + 5;
        e->mUnk_02 = n0;
        e->mUnk_03 = n1;
        g[5].mUnk_00 = n2;
        MemCopyHalfwords(data_021759c0->mCurrentEntries[func_020b4d9c()].mPlayer.mName, e->mUnk_04, 0x14);
        e->mUnk_18 = 1;
        e->mUnk_19 = data_021759c0->mCurrentEntries[func_020b4d9c()].mCharacterIndex;
        e->mUnk_1a = data_021759c0->mCurrentEntries[func_020b4d9c()].mKartIndex;
        func_02056c6c(data_021759c0->mCourseId, 5, e);
    }
    return TRUE;
}

void func_020c610c(void) {
    Unk020adc24 x;
    Unk020adc24 y;
    u8 a;
    u8 b;
    u16 c;
    u8 d;
    u8 e;
    u16 f;
    BOOL r;
    BOOL v1;
    s32 t;
    s32 j;
    s32 n;
    s32 g;
    Unk02056bc0 *q;
    Unk02056bc0 *w;

    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (func_020b1a20() != 0) {
        return;
    }
    if (data_021759c0->mUnk_00c == 0) {
        gRaceNewRecordTa->mUnk_08 = func_020c657c(1);
        gRaceNewRecordTa->mUnk_10 = func_020c6428(1);
        if (gRaceNewRecordTa->mUnk_08 != 0 || gRaceNewRecordTa->mUnk_10 != 0) {
            gRaceNewRecordTa->mUnk_18 = 1;
            func_02056408();
            gRaceNewRecordTa->mUnk_00 = func_020c5f7c;
            gRaceNewRecordTa->mUnk_04 = 0;
        } else {
            r = FALSE;
            if (func_020ba620() != 0) {
                if (data_021759c0->mMode == 1 && data_021759c0->mUnk_3e6 == 1) {
                    MemCopy(&data_021759c0->mUnk_3e2, &x, 4);
                    v1 = TRUE;
                } else {
                    v1 = FALSE;
                }
                if (v1 != FALSE) {
                    GetKartFinishTime((u16) data_021759c0->mEntryIndex, &y.mUnk_02, &y.mUnk_03, &y.mUnk_00);
                    if (func_020adc24(&y, &x) != FALSE) {
                        r = TRUE;
                    }
                } else {
                    r = TRUE;
                }
            }
            if (r != FALSE) {
                gRaceNewRecordTa->mUnk_18 = 1;
                func_02056750(data_021759c0->mCourseId, (u16) data_021759c0->mEntryIndex);
                gRaceNewRecordTa->mUnk_00 = func_020c5f08;
                gRaceNewRecordTa->mUnk_04 = 0;
            } else {
                gRaceNewRecordTa->mUnk_00 = func_020c5e30;
                gRaceNewRecordTa->mUnk_04 = 0;
            }
        }
    } else {
        GetKartFinishTime(func_020b4d9c(), &a, &b, &c);
        w = gRaceNewRecordTa->mRecords;
        t = b * 1000 + a * 60000 + c;
        for (j = 4; j >= 0; j--) {
            q = &w[j];
            if (q->mUnk_18 != 0 && t == q->mUnk_00 + (q->mUnk_03 * 1000 + q->mUnk_02 * 60000)) {
                j = 1;
                goto found;
            }
        }
        j = 0;
    found:
        gRaceNewRecordTa->mUnk_08 = j;
        q = &gRaceNewRecordTa->mRecords[5];
        gRaceNewRecordTa->mUnk_14 = GetKartBestLapTime(func_020b4d9c(), &d, &e, &f);
        if (d == q->mUnk_02 && e == q->mUnk_03 && f == q->mUnk_00) {
            r = TRUE;
        } else {
            r = FALSE;
        }
        gRaceNewRecordTa->mUnk_10 = r;
        gRaceNewRecordTa->mUnk_00 = func_020c5e30;
        gRaceNewRecordTa->mUnk_04 = 0;
    }
    gRaceNewRecordTa->mUnk_dc = 1;
}

void func_020c5f7c(void) {
    Unk020adc24 x;
    Unk020adc24 y;
    BOOL r;
    BOOL v1;
    s32 t;

    if (data_0217aa08->mUnk_28 == 0) {
        t = data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0;
    } else {
        t = 1;
    }
    if (t != 0) {
        return;
    }
    r = FALSE;
    if (func_020ba620() != 0) {
        if (data_021759c0->mMode == 1 && data_021759c0->mUnk_3e6 == 1) {
            MemCopy(&data_021759c0->mUnk_3e2, &x, 4);
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
        if (v1 != FALSE) {
            GetKartFinishTime((u16) data_021759c0->mEntryIndex, &y.mUnk_02, &y.mUnk_03, &y.mUnk_00);
            if (func_020adc24(&y, &x) != FALSE) {
                r = TRUE;
            }
        } else {
            r = TRUE;
        }
    }
    if (r != FALSE) {
        gRaceNewRecordTa->mUnk_18 = 1;
        func_02056750(data_021759c0->mCourseId, (u16) data_021759c0->mEntryIndex);
        gRaceNewRecordTa->mUnk_00 = func_020c5f08;
        gRaceNewRecordTa->mUnk_04 = 0;
    } else {
        gRaceNewRecordTa->mUnk_18 = 0;
        gRaceNewRecordTa->mUnk_00 = func_020c5eb8;
        gRaceNewRecordTa->mUnk_04 = 0;
    }
}

void func_020c5f08(void) {
    s32 t;

    if (data_0217aa08->mUnk_28 == 0) {
        t = data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0;
    } else {
        t = 1;
    }
    if (t != 0) {
        return;
    }
    gRaceNewRecordTa->mUnk_18 = 0;
    gRaceNewRecordTa->mUnk_00 = func_020c5eb8;
    gRaceNewRecordTa->mUnk_04 = 0;
}

void func_020c5eb8(void) {
    if (func_020b1a20() != 0) {
        return;
    }
    func_020b1d64();
    gRaceNewRecordTa->mUnk_00 = func_020c5e30;
    gRaceNewRecordTa->mUnk_04 = 0;
}

void func_020c5e30(void) {
    s32 n;

    n = gRaceNewRecordTa->mUnk_04;
    gRaceNewRecordTa->mUnk_04 = n + 1;
    if (n < 0x14) {
        gRaceNewRecordTa->mOffsetX = func_020ae4c0(1, -0x100, 0, n, 0x14);
    } else {
        gRaceNewRecordTa->mOffsetX = 0;
        gRaceNewRecordTa->mUnk_00 = (void (*)(void)) func_020c5df0;
        gRaceNewRecordTa->mUnk_04 = 0;
    }
}

u32 func_020c5df0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) &gRaceNewRecordTa;
    value3 = (u32) * (const u32 *) ((value0) + (0));
    value2 = (u32) gRaceNewRecordTa->mUnk_04;
    value1 = (value2) + (1u);
    gRaceNewRecordTa->mUnk_04 = value1;
    compareLeft0 = value2;
    compareRight0 = 0x3cu;
    if ((s32) compareLeft0 < (s32) compareRight0) {
        return value0;
    }
    value2 = (u32) * (const u32 *) ((value0) + (0));
    value3 = (u32) &func_020c5dd8;
    value1 = 0u;
    *(u32 *) ((value2) + (0)) = value3;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}

u32 func_020c5dd8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceNewRecordTa;
    value1 = 0u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (220)) = value1;
    return value0;
}
