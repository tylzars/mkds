#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "registers.h"

void func_0210a53c(Unk0206bcb0 *a) {
    if (a->mUnk_488 == 0xffff) {
        return;
    }
    func_0210c558(&a->mUnk_00, 0, a->mUnk_488, 0);
    a->mUnk_488 = 0xffff;
}

void func_02109468(void) {
    BOOL f;
    Unk02109468 t0;
    Unk02109468 t1;
    Unk02109468 t2;
    Unk02109468 t3;
    Unk02109468 t4;
    Unk02109468 b0;
    Unk02109468 c0;
    Unk02109468 b1;
    Unk02109468 c1;
    Unk02109468 b2;
    Unk02109468 c2;
    Unk02109468 b3;
    Unk02109468 c3;
    Unk02109468 b4;
    Unk02109468 c4;
    Unk02109468 w5;
    Unk02109468 w6;
    Unk02109468 w7;
    Unk02109468 w8;
    Unk02109468 w9;
    Unk02109468 w10;
    Unk02109468 w11;
    Unk02109468 w12;
    Unk02109468 w13;
    Unk02109468 w14;
    Unk02109468 w15;
    Unk02109468 w16;
    static Unk02109468 s14 = {1400, 750, 55, 100, 110};
    static Unk02109468 s3 = {380, 304, 66, 150, 95};
    static Unk02109468 s4 = {800, 500, 57, 150, 95};
    static Unk02109468 s6 = {3000, 1500, 52, 150, 95};
    static Unk02109468 s5 = {1100, 550, 47, 150, 95};
    static Unk02109468 s7 = {600, 400, 47, 150, 95};
    static Unk02109468 s8 = {1500, 900, 69, 150, 115};
    static Unk02109468 s9 = {1200, 600, 47, 150, 95};
    static Unk02109468 s10 = {5000, 4000, 88, 150, 127};
    static Unk02109468 s11 = {1100, 550, 62, 150, 95};
    static Unk02109468 s2 = {1100, 500, 71, 150, 95};
    static Unk02109468 s13 = {1000, 650, 55, 300, 110};
    static Unk02109468 s12 = {800, 400, 47, 54, 95};
    static Unk02109468 s15 = {1100, 600, 55, 100, 110};
    static Unk02109468 s16 = {950, 525, 55, 100, 110};
    static Unk02109468 s0 = {800, 500, 47, 150, 127};
    static Unk02109468 s1 = {800, 500, 47, 150, 95};

    if (func_0205e0a0() == 2 && data_021759c0->mUnk_00c == 2) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    t0 = s0;
    if (f != FALSE) {
        b0 = t0;
        b0.mUnk_00 = 0x44c;
        b0.mUnk_04 = 0x226;
        b0.mUnk_08 = 0x2f;
        b0.mUnk_10 = 0x5f;
        t0 = b0;
    }
    c0 = t0;
    data_0217ca6c[0].mUnk_10 = c0.mUnk_10;
    data_0217ca6c[0].mUnk_00 = c0.mUnk_00;
    data_0217ca6c[0].mUnk_04 = c0.mUnk_04;
    data_0217ca6c[0].mUnk_08 = c0.mUnk_08;
    data_0217ca6c[0].mUnk_0c = c0.mUnk_0c;
    data_0217ca6c[0].mUnk_14 = DivFixed12((c0.mUnk_08 - c0.mUnk_10) << 12, (c0.mUnk_04 - c0.mUnk_0c) << 12);
    data_0217ca6c[0].mUnk_18 = DivFixed12(c0.mUnk_08 << 12, (c0.mUnk_04 - c0.mUnk_00) << 12);
    data_0217ca6c[0].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[0].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[0].mUnk_20 = (((s32) ((((s64) (c0.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (c0.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t1 = s1;
    if (f != FALSE) {
        b1 = t1;
        b1.mUnk_00 = 0x44c;
        b1.mUnk_04 = 0x226;
        b1.mUnk_08 = 0x2f;
        b1.mUnk_10 = 0x5f;
        t1 = b1;
    }
    c1 = t1;
    data_0217c8f8.mUnk_10 = c1.mUnk_10;
    data_0217c8f8.mUnk_00 = c1.mUnk_00;
    data_0217c8f8.mUnk_04 = c1.mUnk_04;
    data_0217c8f8.mUnk_08 = c1.mUnk_08;
    data_0217c8f8.mUnk_0c = c1.mUnk_0c;
    data_0217c8f8.mUnk_14 = DivFixed12((c1.mUnk_08 - c1.mUnk_10) << 12, (c1.mUnk_04 - c1.mUnk_0c) << 12);
    data_0217c8f8.mUnk_18 = DivFixed12(c1.mUnk_08 << 12, (c1.mUnk_04 - c1.mUnk_00) << 12);
    data_0217c8f8.mUnk_1c = DivFixed12(0x666, (data_0217c8f8.mUnk_0c << 12) + 0x36000);
    data_0217c8f8.mUnk_20 = (((s32) ((((s64) (c1.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                            (((s32) ((((s64) (c1.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t2 = s2;
    if (f != FALSE) {
        b2 = t2;
        b2.mUnk_00 = 0x514;
        b2.mUnk_04 = 0x28a;
        b2.mUnk_08 = 0x2f;
        b2.mUnk_10 = 0x5f;
        t2 = b2;
    }
    c2 = t2;
    data_0217ca6c[1].mUnk_10 = c2.mUnk_10;
    data_0217ca6c[1].mUnk_00 = c2.mUnk_00;
    data_0217ca6c[1].mUnk_04 = c2.mUnk_04;
    data_0217ca6c[1].mUnk_08 = c2.mUnk_08;
    data_0217ca6c[1].mUnk_0c = c2.mUnk_0c;
    data_0217ca6c[1].mUnk_14 = DivFixed12((c2.mUnk_08 - c2.mUnk_10) << 12, (c2.mUnk_04 - c2.mUnk_0c) << 12);
    data_0217ca6c[1].mUnk_18 = DivFixed12(c2.mUnk_08 << 12, (c2.mUnk_04 - c2.mUnk_00) << 12);
    data_0217ca6c[1].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[1].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[1].mUnk_20 = (((s32) ((((s64) (c2.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (c2.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t3 = s3;
    if (f != FALSE) {
        b3 = t3;
        b3.mUnk_00 = 0x44c;
        b3.mUnk_04 = 0x226;
        b3.mUnk_08 = 0x2f;
        b3.mUnk_10 = 0x5f;
        t3 = b3;
    }
    c3 = t3;
    data_0217ca6c[2].mUnk_10 = c3.mUnk_10;
    data_0217ca6c[2].mUnk_00 = c3.mUnk_00;
    data_0217ca6c[2].mUnk_04 = c3.mUnk_04;
    data_0217ca6c[2].mUnk_08 = c3.mUnk_08;
    data_0217ca6c[2].mUnk_0c = c3.mUnk_0c;
    data_0217ca6c[2].mUnk_14 = DivFixed12((c3.mUnk_08 - c3.mUnk_10) << 12, (c3.mUnk_04 - c3.mUnk_0c) << 12);
    data_0217ca6c[2].mUnk_18 = DivFixed12(c3.mUnk_08 << 12, (c3.mUnk_04 - c3.mUnk_00) << 12);
    data_0217ca6c[2].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[2].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[2].mUnk_20 = (((s32) ((((s64) (c3.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (c3.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t4 = s4;
    if (f != FALSE) {
        b4 = t4;
        b4.mUnk_00 = 0x44c;
        b4.mUnk_04 = 0x226;
        b4.mUnk_08 = 0x2f;
        b4.mUnk_10 = 0x5f;
        t4 = b4;
    }
    c4 = t4;
    data_0217ca6c[3].mUnk_10 = c4.mUnk_10;
    data_0217ca6c[3].mUnk_00 = c4.mUnk_00;
    data_0217ca6c[3].mUnk_04 = c4.mUnk_04;
    data_0217ca6c[3].mUnk_08 = c4.mUnk_08;
    data_0217ca6c[3].mUnk_0c = c4.mUnk_0c;
    data_0217ca6c[3].mUnk_14 = DivFixed12((c4.mUnk_08 - c4.mUnk_10) << 12, (c4.mUnk_04 - c4.mUnk_0c) << 12);
    data_0217ca6c[3].mUnk_18 = DivFixed12(c4.mUnk_08 << 12, (c4.mUnk_04 - c4.mUnk_00) << 12);
    data_0217ca6c[3].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[3].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[3].mUnk_20 = (((s32) ((((s64) (c4.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (c4.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w5 = s5;
    data_0217ca6c[4].mUnk_10 = w5.mUnk_10;
    data_0217ca6c[4].mUnk_00 = w5.mUnk_00;
    data_0217ca6c[4].mUnk_04 = w5.mUnk_04;
    data_0217ca6c[4].mUnk_08 = w5.mUnk_08;
    data_0217ca6c[4].mUnk_0c = w5.mUnk_0c;
    data_0217ca6c[4].mUnk_14 = DivFixed12((w5.mUnk_08 - w5.mUnk_10) << 12, (w5.mUnk_04 - w5.mUnk_0c) << 12);
    data_0217ca6c[4].mUnk_18 = DivFixed12(w5.mUnk_08 << 12, (w5.mUnk_04 - w5.mUnk_00) << 12);
    data_0217ca6c[4].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[4].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[4].mUnk_20 = (((s32) ((((s64) (w5.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w5.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w6 = s6;
    data_0217ca6c[5].mUnk_10 = w6.mUnk_10;
    data_0217ca6c[5].mUnk_00 = w6.mUnk_00;
    data_0217ca6c[5].mUnk_04 = w6.mUnk_04;
    data_0217ca6c[5].mUnk_08 = w6.mUnk_08;
    data_0217ca6c[5].mUnk_0c = w6.mUnk_0c;
    data_0217ca6c[5].mUnk_14 = DivFixed12((w6.mUnk_08 - w6.mUnk_10) << 12, (w6.mUnk_04 - w6.mUnk_0c) << 12);
    data_0217ca6c[5].mUnk_18 = DivFixed12(w6.mUnk_08 << 12, (w6.mUnk_04 - w6.mUnk_00) << 12);
    data_0217ca6c[5].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[5].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[5].mUnk_20 = (((s32) ((((s64) (w6.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w6.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w7 = s7;
    data_0217ca6c[6].mUnk_10 = w7.mUnk_10;
    data_0217ca6c[6].mUnk_00 = w7.mUnk_00;
    data_0217ca6c[6].mUnk_04 = w7.mUnk_04;
    data_0217ca6c[6].mUnk_08 = w7.mUnk_08;
    data_0217ca6c[6].mUnk_0c = w7.mUnk_0c;
    data_0217ca6c[6].mUnk_14 = DivFixed12((w7.mUnk_08 - w7.mUnk_10) << 12, (w7.mUnk_04 - w7.mUnk_0c) << 12);
    data_0217ca6c[6].mUnk_18 = DivFixed12(w7.mUnk_08 << 12, (w7.mUnk_04 - w7.mUnk_00) << 12);
    data_0217ca6c[6].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[6].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[6].mUnk_20 = (((s32) ((((s64) (w7.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w7.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w8 = s8;
    data_0217ca6c[7].mUnk_10 = w8.mUnk_10;
    data_0217ca6c[7].mUnk_00 = w8.mUnk_00;
    data_0217ca6c[7].mUnk_04 = w8.mUnk_04;
    data_0217ca6c[7].mUnk_08 = w8.mUnk_08;
    data_0217ca6c[7].mUnk_0c = w8.mUnk_0c;
    data_0217ca6c[7].mUnk_14 = DivFixed12((w8.mUnk_08 - w8.mUnk_10) << 12, (w8.mUnk_04 - w8.mUnk_0c) << 12);
    data_0217ca6c[7].mUnk_18 = DivFixed12(w8.mUnk_08 << 12, (w8.mUnk_04 - w8.mUnk_00) << 12);
    data_0217ca6c[7].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[7].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[7].mUnk_20 = (((s32) ((((s64) (w8.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w8.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w9 = s9;
    data_0217ca6c[8].mUnk_10 = w9.mUnk_10;
    data_0217ca6c[8].mUnk_00 = w9.mUnk_00;
    data_0217ca6c[8].mUnk_04 = w9.mUnk_04;
    data_0217ca6c[8].mUnk_08 = w9.mUnk_08;
    data_0217ca6c[8].mUnk_0c = w9.mUnk_0c;
    data_0217ca6c[8].mUnk_14 = DivFixed12((w9.mUnk_08 - w9.mUnk_10) << 12, (w9.mUnk_04 - w9.mUnk_0c) << 12);
    data_0217ca6c[8].mUnk_18 = DivFixed12(w9.mUnk_08 << 12, (w9.mUnk_04 - w9.mUnk_00) << 12);
    data_0217ca6c[8].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[8].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[8].mUnk_20 = (((s32) ((((s64) (w9.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w9.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w10 = s10;
    data_0217ca6c[9].mUnk_10 = w10.mUnk_10;
    data_0217ca6c[9].mUnk_00 = w10.mUnk_00;
    data_0217ca6c[9].mUnk_04 = w10.mUnk_04;
    data_0217ca6c[9].mUnk_08 = w10.mUnk_08;
    data_0217ca6c[9].mUnk_0c = w10.mUnk_0c;
    data_0217ca6c[9].mUnk_14 = DivFixed12((w10.mUnk_08 - w10.mUnk_10) << 12, (w10.mUnk_04 - w10.mUnk_0c) << 12);
    data_0217ca6c[9].mUnk_18 = DivFixed12(w10.mUnk_08 << 12, (w10.mUnk_04 - w10.mUnk_00) << 12);
    data_0217ca6c[9].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[9].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[9].mUnk_20 = (((s32) ((((s64) (w10.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                               (((s32) ((((s64) (w10.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w11 = s11;
    data_0217ca6c[10].mUnk_10 = w11.mUnk_10;
    data_0217ca6c[10].mUnk_00 = w11.mUnk_00;
    data_0217ca6c[10].mUnk_04 = w11.mUnk_04;
    data_0217ca6c[10].mUnk_08 = w11.mUnk_08;
    data_0217ca6c[10].mUnk_0c = w11.mUnk_0c;
    data_0217ca6c[10].mUnk_14 = DivFixed12((w11.mUnk_08 - w11.mUnk_10) << 12, (w11.mUnk_04 - w11.mUnk_0c) << 12);
    data_0217ca6c[10].mUnk_18 = DivFixed12(w11.mUnk_08 << 12, (w11.mUnk_04 - w11.mUnk_00) << 12);
    data_0217ca6c[10].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[10].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[10].mUnk_20 = (((s32) ((((s64) (w11.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w11.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w12 = s12;
    data_0217ca6c[11].mUnk_10 = w12.mUnk_10;
    data_0217ca6c[11].mUnk_00 = w12.mUnk_00;
    data_0217ca6c[11].mUnk_04 = w12.mUnk_04;
    data_0217ca6c[11].mUnk_08 = w12.mUnk_08;
    data_0217ca6c[11].mUnk_0c = w12.mUnk_0c;
    data_0217ca6c[11].mUnk_14 = DivFixed12((w12.mUnk_08 - w12.mUnk_10) << 12, (w12.mUnk_04 - w12.mUnk_0c) << 12);
    data_0217ca6c[11].mUnk_18 = DivFixed12(w12.mUnk_08 << 12, (w12.mUnk_04 - w12.mUnk_00) << 12);
    data_0217ca6c[11].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[11].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[11].mUnk_20 = (((s32) ((((s64) (w12.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w12.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w13 = s13;
    data_0217ca6c[12].mUnk_10 = w13.mUnk_10;
    data_0217ca6c[12].mUnk_00 = w13.mUnk_00;
    data_0217ca6c[12].mUnk_04 = w13.mUnk_04;
    data_0217ca6c[12].mUnk_08 = w13.mUnk_08;
    data_0217ca6c[12].mUnk_0c = w13.mUnk_0c;
    data_0217ca6c[12].mUnk_14 = DivFixed12((w13.mUnk_08 - w13.mUnk_10) << 12, (w13.mUnk_04 - w13.mUnk_0c) << 12);
    data_0217ca6c[12].mUnk_18 = DivFixed12(w13.mUnk_08 << 12, (w13.mUnk_04 - w13.mUnk_00) << 12);
    data_0217ca6c[12].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[12].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[12].mUnk_20 = (((s32) ((((s64) (w13.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w13.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w14 = s14;
    data_0217ca6c[13].mUnk_10 = w14.mUnk_10;
    data_0217ca6c[13].mUnk_00 = w14.mUnk_00;
    data_0217ca6c[13].mUnk_04 = w14.mUnk_04;
    data_0217ca6c[13].mUnk_08 = w14.mUnk_08;
    data_0217ca6c[13].mUnk_0c = w14.mUnk_0c;
    data_0217ca6c[13].mUnk_14 = DivFixed12((w14.mUnk_08 - w14.mUnk_10) << 12, (w14.mUnk_04 - w14.mUnk_0c) << 12);
    data_0217ca6c[13].mUnk_18 = DivFixed12(w14.mUnk_08 << 12, (w14.mUnk_04 - w14.mUnk_00) << 12);
    data_0217ca6c[13].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[13].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[13].mUnk_20 = (((s32) ((((s64) (w14.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w14.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w15 = s15;
    data_0217ca6c[14].mUnk_10 = w15.mUnk_10;
    data_0217ca6c[14].mUnk_00 = w15.mUnk_00;
    data_0217ca6c[14].mUnk_04 = w15.mUnk_04;
    data_0217ca6c[14].mUnk_08 = w15.mUnk_08;
    data_0217ca6c[14].mUnk_0c = w15.mUnk_0c;
    data_0217ca6c[14].mUnk_14 = DivFixed12((w15.mUnk_08 - w15.mUnk_10) << 12, (w15.mUnk_04 - w15.mUnk_0c) << 12);
    data_0217ca6c[14].mUnk_18 = DivFixed12(w15.mUnk_08 << 12, (w15.mUnk_04 - w15.mUnk_00) << 12);
    data_0217ca6c[14].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[14].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[14].mUnk_20 = (((s32) ((((s64) (w15.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w15.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w16 = s16;
    data_0217ca6c[15].mUnk_10 = w16.mUnk_10;
    data_0217ca6c[15].mUnk_00 = w16.mUnk_00;
    data_0217ca6c[15].mUnk_04 = w16.mUnk_04;
    data_0217ca6c[15].mUnk_08 = w16.mUnk_08;
    data_0217ca6c[15].mUnk_0c = w16.mUnk_0c;
    data_0217ca6c[15].mUnk_14 = DivFixed12((w16.mUnk_08 - w16.mUnk_10) << 12, (w16.mUnk_04 - w16.mUnk_0c) << 12);
    data_0217ca6c[15].mUnk_18 = DivFixed12(w16.mUnk_08 << 12, (w16.mUnk_04 - w16.mUnk_00) << 12);
    data_0217ca6c[15].mUnk_1c = DivFixed12(0x666, (data_0217ca6c[15].mUnk_0c << 12) + 0x36000);
    data_0217ca6c[15].mUnk_20 = (((s32) ((((s64) (w16.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w16.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
}

s32 func_021092b0(Unk0210bcf4 *p) {
    Unk0206bcb0 *k;
    Unk0217ca6c *e;
    s32 v;
    s32 a;

    k = (Unk0206bcb0 *) p->mUnk_00;
    v = 0;
    if (k != NULL) {
        if (k != NULL && k->mUnk_00.mUnk_3c == 0 && k->mIndex != data_021759c0->mEntryIndex) {
            e = &data_0217c8f8;
        } else {
            e = &data_0217ca6c[k->mUnk_00.mUnk_3c];
        }
    } else {
        e = &data_0217ca6c[p->mUnk_20->mUnk_08];
    }
    a = p->mUnk_10;
    if (a <= e->mUnk_0c) {
        v = e->mUnk_10;
    } else if (a <= e->mUnk_04) {
        v = e->mUnk_10 + (((s32) ((((s64) e->mUnk_14 * ((a - e->mUnk_0c) << 12)) + 0x800) >> 12)) >> 12);
    } else if (a < e->mUnk_00) {
        v = ((s32) ((((s64) e->mUnk_18 * ((a - e->mUnk_00) << 12)) + 0x800) >> 12)) >> 12;
    }
    a = p->mUnk_08;
    if (a < 0x36) {
        if (a > -e->mUnk_0c) {
            a = ((s32) ((((s64) e->mUnk_1c * ((a - 0x36) << 12)) + 0x800) >> 12)) + 0x1000;
            v = ((s32) ((((s64) a * (v << 12)) + 0x800) >> 12)) >> 12;
        } else {
            v = ((s32) ((((s64) (v << 12) * 0x99a) + 0x800) >> 12)) >> 12;
        }
    }
    if (v < 0) {
        return 0;
    }
    if (v > e->mUnk_10) {
        return e->mUnk_10;
    }
    return v;
}

s32 func_0210920c(Unk0210bcf4 *p) {
    u32 a;
    s32 v;

    a = AngleFromPair(p->mUnk_08 << 12, -p->mUnk_0c << 12);
    if (a > 0x7fff) {
        a = (u16) (0xffff - a);
    }
    v = ((s32) ((((s64) (s32) (a << 12) * -32) + 0x800) >> 12)) >> 12;
    v += 0x7f;
    if (v < -0x80) {
        v = -0x80;
    } else if (v > 0x7f) {
        v = 0x7f;
    }
    return v;
}

u32 func_02109184(Unk0210bcf4 *p) {
    u32 a;
    u32 b;

    if (p->mUnk_00 != NULL) {
        a = ((Unk0206bcb0 *) p->mUnk_00)->mUnk_00.mUnk_40;
    } else {
        a = p->mUnk_20->mUnk_0c;
    }
    reg_CP_SQRTCNT = 0;
    *(vu32 *) 0x040002b8 = a;
    b = p->mUnk_04;
    p->mUnk_08 = func_02073e4c(b) >> 12;
    p->mUnk_0c = func_02073e04(b) >> 12;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return reg_CP_SQRT_RESULT;
}
