#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "registers.h"

void func_0210a53c(Kart *a) {
    if (a->mUnk_488 == 0xffff) {
        return;
    }
    StopSoundEx(&a->mSoundSource, 0, a->mUnk_488, 0);
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

    if (GetCurrentSceneNumber() == 2 && data_021759c0->mUnk_00c == 2) {
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
    gSoundFalloffs[0].mMaxVolume = c0.mUnk_10;
    gSoundFalloffs[0].mOuterDistance = c0.mUnk_00;
    gSoundFalloffs[0].mUnk_04 = c0.mUnk_04;
    gSoundFalloffs[0].mUnk_08 = c0.mUnk_08;
    gSoundFalloffs[0].mInnerDistance = c0.mUnk_0c;
    gSoundFalloffs[0].mUnk_14 = DivFixed12((c0.mUnk_08 - c0.mUnk_10) << 12, (c0.mUnk_04 - c0.mUnk_0c) << 12);
    gSoundFalloffs[0].mUnk_18 = DivFixed12(c0.mUnk_08 << 12, (c0.mUnk_04 - c0.mUnk_00) << 12);
    gSoundFalloffs[0].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[0].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[0].mUnk_20 = (((s32) ((((s64) (c0.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
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
    gOtherKartSoundFalloff.mMaxVolume = c1.mUnk_10;
    gOtherKartSoundFalloff.mOuterDistance = c1.mUnk_00;
    gOtherKartSoundFalloff.mUnk_04 = c1.mUnk_04;
    gOtherKartSoundFalloff.mUnk_08 = c1.mUnk_08;
    gOtherKartSoundFalloff.mInnerDistance = c1.mUnk_0c;
    gOtherKartSoundFalloff.mUnk_14 = DivFixed12((c1.mUnk_08 - c1.mUnk_10) << 12, (c1.mUnk_04 - c1.mUnk_0c) << 12);
    gOtherKartSoundFalloff.mUnk_18 = DivFixed12(c1.mUnk_08 << 12, (c1.mUnk_04 - c1.mUnk_00) << 12);
    gOtherKartSoundFalloff.mUnk_1c = DivFixed12(0x666, (gOtherKartSoundFalloff.mInnerDistance << 12) + 0x36000);
    gOtherKartSoundFalloff.mUnk_20 = (((s32) ((((s64) (c1.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
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
    gSoundFalloffs[1].mMaxVolume = c2.mUnk_10;
    gSoundFalloffs[1].mOuterDistance = c2.mUnk_00;
    gSoundFalloffs[1].mUnk_04 = c2.mUnk_04;
    gSoundFalloffs[1].mUnk_08 = c2.mUnk_08;
    gSoundFalloffs[1].mInnerDistance = c2.mUnk_0c;
    gSoundFalloffs[1].mUnk_14 = DivFixed12((c2.mUnk_08 - c2.mUnk_10) << 12, (c2.mUnk_04 - c2.mUnk_0c) << 12);
    gSoundFalloffs[1].mUnk_18 = DivFixed12(c2.mUnk_08 << 12, (c2.mUnk_04 - c2.mUnk_00) << 12);
    gSoundFalloffs[1].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[1].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[1].mUnk_20 = (((s32) ((((s64) (c2.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
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
    gSoundFalloffs[2].mMaxVolume = c3.mUnk_10;
    gSoundFalloffs[2].mOuterDistance = c3.mUnk_00;
    gSoundFalloffs[2].mUnk_04 = c3.mUnk_04;
    gSoundFalloffs[2].mUnk_08 = c3.mUnk_08;
    gSoundFalloffs[2].mInnerDistance = c3.mUnk_0c;
    gSoundFalloffs[2].mUnk_14 = DivFixed12((c3.mUnk_08 - c3.mUnk_10) << 12, (c3.mUnk_04 - c3.mUnk_0c) << 12);
    gSoundFalloffs[2].mUnk_18 = DivFixed12(c3.mUnk_08 << 12, (c3.mUnk_04 - c3.mUnk_00) << 12);
    gSoundFalloffs[2].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[2].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[2].mUnk_20 = (((s32) ((((s64) (c3.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
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
    gSoundFalloffs[3].mMaxVolume = c4.mUnk_10;
    gSoundFalloffs[3].mOuterDistance = c4.mUnk_00;
    gSoundFalloffs[3].mUnk_04 = c4.mUnk_04;
    gSoundFalloffs[3].mUnk_08 = c4.mUnk_08;
    gSoundFalloffs[3].mInnerDistance = c4.mUnk_0c;
    gSoundFalloffs[3].mUnk_14 = DivFixed12((c4.mUnk_08 - c4.mUnk_10) << 12, (c4.mUnk_04 - c4.mUnk_0c) << 12);
    gSoundFalloffs[3].mUnk_18 = DivFixed12(c4.mUnk_08 << 12, (c4.mUnk_04 - c4.mUnk_00) << 12);
    gSoundFalloffs[3].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[3].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[3].mUnk_20 = (((s32) ((((s64) (c4.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (c4.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w5 = s5;
    gSoundFalloffs[4].mMaxVolume = w5.mUnk_10;
    gSoundFalloffs[4].mOuterDistance = w5.mUnk_00;
    gSoundFalloffs[4].mUnk_04 = w5.mUnk_04;
    gSoundFalloffs[4].mUnk_08 = w5.mUnk_08;
    gSoundFalloffs[4].mInnerDistance = w5.mUnk_0c;
    gSoundFalloffs[4].mUnk_14 = DivFixed12((w5.mUnk_08 - w5.mUnk_10) << 12, (w5.mUnk_04 - w5.mUnk_0c) << 12);
    gSoundFalloffs[4].mUnk_18 = DivFixed12(w5.mUnk_08 << 12, (w5.mUnk_04 - w5.mUnk_00) << 12);
    gSoundFalloffs[4].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[4].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[4].mUnk_20 = (((s32) ((((s64) (w5.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w5.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w6 = s6;
    gSoundFalloffs[5].mMaxVolume = w6.mUnk_10;
    gSoundFalloffs[5].mOuterDistance = w6.mUnk_00;
    gSoundFalloffs[5].mUnk_04 = w6.mUnk_04;
    gSoundFalloffs[5].mUnk_08 = w6.mUnk_08;
    gSoundFalloffs[5].mInnerDistance = w6.mUnk_0c;
    gSoundFalloffs[5].mUnk_14 = DivFixed12((w6.mUnk_08 - w6.mUnk_10) << 12, (w6.mUnk_04 - w6.mUnk_0c) << 12);
    gSoundFalloffs[5].mUnk_18 = DivFixed12(w6.mUnk_08 << 12, (w6.mUnk_04 - w6.mUnk_00) << 12);
    gSoundFalloffs[5].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[5].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[5].mUnk_20 = (((s32) ((((s64) (w6.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w6.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w7 = s7;
    gSoundFalloffs[6].mMaxVolume = w7.mUnk_10;
    gSoundFalloffs[6].mOuterDistance = w7.mUnk_00;
    gSoundFalloffs[6].mUnk_04 = w7.mUnk_04;
    gSoundFalloffs[6].mUnk_08 = w7.mUnk_08;
    gSoundFalloffs[6].mInnerDistance = w7.mUnk_0c;
    gSoundFalloffs[6].mUnk_14 = DivFixed12((w7.mUnk_08 - w7.mUnk_10) << 12, (w7.mUnk_04 - w7.mUnk_0c) << 12);
    gSoundFalloffs[6].mUnk_18 = DivFixed12(w7.mUnk_08 << 12, (w7.mUnk_04 - w7.mUnk_00) << 12);
    gSoundFalloffs[6].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[6].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[6].mUnk_20 = (((s32) ((((s64) (w7.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w7.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w8 = s8;
    gSoundFalloffs[7].mMaxVolume = w8.mUnk_10;
    gSoundFalloffs[7].mOuterDistance = w8.mUnk_00;
    gSoundFalloffs[7].mUnk_04 = w8.mUnk_04;
    gSoundFalloffs[7].mUnk_08 = w8.mUnk_08;
    gSoundFalloffs[7].mInnerDistance = w8.mUnk_0c;
    gSoundFalloffs[7].mUnk_14 = DivFixed12((w8.mUnk_08 - w8.mUnk_10) << 12, (w8.mUnk_04 - w8.mUnk_0c) << 12);
    gSoundFalloffs[7].mUnk_18 = DivFixed12(w8.mUnk_08 << 12, (w8.mUnk_04 - w8.mUnk_00) << 12);
    gSoundFalloffs[7].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[7].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[7].mUnk_20 = (((s32) ((((s64) (w8.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w8.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w9 = s9;
    gSoundFalloffs[8].mMaxVolume = w9.mUnk_10;
    gSoundFalloffs[8].mOuterDistance = w9.mUnk_00;
    gSoundFalloffs[8].mUnk_04 = w9.mUnk_04;
    gSoundFalloffs[8].mUnk_08 = w9.mUnk_08;
    gSoundFalloffs[8].mInnerDistance = w9.mUnk_0c;
    gSoundFalloffs[8].mUnk_14 = DivFixed12((w9.mUnk_08 - w9.mUnk_10) << 12, (w9.mUnk_04 - w9.mUnk_0c) << 12);
    gSoundFalloffs[8].mUnk_18 = DivFixed12(w9.mUnk_08 << 12, (w9.mUnk_04 - w9.mUnk_00) << 12);
    gSoundFalloffs[8].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[8].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[8].mUnk_20 = (((s32) ((((s64) (w9.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w9.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w10 = s10;
    gSoundFalloffs[9].mMaxVolume = w10.mUnk_10;
    gSoundFalloffs[9].mOuterDistance = w10.mUnk_00;
    gSoundFalloffs[9].mUnk_04 = w10.mUnk_04;
    gSoundFalloffs[9].mUnk_08 = w10.mUnk_08;
    gSoundFalloffs[9].mInnerDistance = w10.mUnk_0c;
    gSoundFalloffs[9].mUnk_14 = DivFixed12((w10.mUnk_08 - w10.mUnk_10) << 12, (w10.mUnk_04 - w10.mUnk_0c) << 12);
    gSoundFalloffs[9].mUnk_18 = DivFixed12(w10.mUnk_08 << 12, (w10.mUnk_04 - w10.mUnk_00) << 12);
    gSoundFalloffs[9].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[9].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[9].mUnk_20 = (((s32) ((((s64) (w10.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w10.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w11 = s11;
    gSoundFalloffs[10].mMaxVolume = w11.mUnk_10;
    gSoundFalloffs[10].mOuterDistance = w11.mUnk_00;
    gSoundFalloffs[10].mUnk_04 = w11.mUnk_04;
    gSoundFalloffs[10].mUnk_08 = w11.mUnk_08;
    gSoundFalloffs[10].mInnerDistance = w11.mUnk_0c;
    gSoundFalloffs[10].mUnk_14 = DivFixed12((w11.mUnk_08 - w11.mUnk_10) << 12, (w11.mUnk_04 - w11.mUnk_0c) << 12);
    gSoundFalloffs[10].mUnk_18 = DivFixed12(w11.mUnk_08 << 12, (w11.mUnk_04 - w11.mUnk_00) << 12);
    gSoundFalloffs[10].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[10].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[10].mUnk_20 = (((s32) ((((s64) (w11.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w11.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w12 = s12;
    gSoundFalloffs[11].mMaxVolume = w12.mUnk_10;
    gSoundFalloffs[11].mOuterDistance = w12.mUnk_00;
    gSoundFalloffs[11].mUnk_04 = w12.mUnk_04;
    gSoundFalloffs[11].mUnk_08 = w12.mUnk_08;
    gSoundFalloffs[11].mInnerDistance = w12.mUnk_0c;
    gSoundFalloffs[11].mUnk_14 = DivFixed12((w12.mUnk_08 - w12.mUnk_10) << 12, (w12.mUnk_04 - w12.mUnk_0c) << 12);
    gSoundFalloffs[11].mUnk_18 = DivFixed12(w12.mUnk_08 << 12, (w12.mUnk_04 - w12.mUnk_00) << 12);
    gSoundFalloffs[11].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[11].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[11].mUnk_20 = (((s32) ((((s64) (w12.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w12.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w13 = s13;
    gSoundFalloffs[12].mMaxVolume = w13.mUnk_10;
    gSoundFalloffs[12].mOuterDistance = w13.mUnk_00;
    gSoundFalloffs[12].mUnk_04 = w13.mUnk_04;
    gSoundFalloffs[12].mUnk_08 = w13.mUnk_08;
    gSoundFalloffs[12].mInnerDistance = w13.mUnk_0c;
    gSoundFalloffs[12].mUnk_14 = DivFixed12((w13.mUnk_08 - w13.mUnk_10) << 12, (w13.mUnk_04 - w13.mUnk_0c) << 12);
    gSoundFalloffs[12].mUnk_18 = DivFixed12(w13.mUnk_08 << 12, (w13.mUnk_04 - w13.mUnk_00) << 12);
    gSoundFalloffs[12].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[12].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[12].mUnk_20 = (((s32) ((((s64) (w13.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w13.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w14 = s14;
    gSoundFalloffs[13].mMaxVolume = w14.mUnk_10;
    gSoundFalloffs[13].mOuterDistance = w14.mUnk_00;
    gSoundFalloffs[13].mUnk_04 = w14.mUnk_04;
    gSoundFalloffs[13].mUnk_08 = w14.mUnk_08;
    gSoundFalloffs[13].mInnerDistance = w14.mUnk_0c;
    gSoundFalloffs[13].mUnk_14 = DivFixed12((w14.mUnk_08 - w14.mUnk_10) << 12, (w14.mUnk_04 - w14.mUnk_0c) << 12);
    gSoundFalloffs[13].mUnk_18 = DivFixed12(w14.mUnk_08 << 12, (w14.mUnk_04 - w14.mUnk_00) << 12);
    gSoundFalloffs[13].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[13].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[13].mUnk_20 = (((s32) ((((s64) (w14.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w14.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w15 = s15;
    gSoundFalloffs[14].mMaxVolume = w15.mUnk_10;
    gSoundFalloffs[14].mOuterDistance = w15.mUnk_00;
    gSoundFalloffs[14].mUnk_04 = w15.mUnk_04;
    gSoundFalloffs[14].mUnk_08 = w15.mUnk_08;
    gSoundFalloffs[14].mInnerDistance = w15.mUnk_0c;
    gSoundFalloffs[14].mUnk_14 = DivFixed12((w15.mUnk_08 - w15.mUnk_10) << 12, (w15.mUnk_04 - w15.mUnk_0c) << 12);
    gSoundFalloffs[14].mUnk_18 = DivFixed12(w15.mUnk_08 << 12, (w15.mUnk_04 - w15.mUnk_00) << 12);
    gSoundFalloffs[14].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[14].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[14].mUnk_20 = (((s32) ((((s64) (w15.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w15.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w16 = s16;
    gSoundFalloffs[15].mMaxVolume = w16.mUnk_10;
    gSoundFalloffs[15].mOuterDistance = w16.mUnk_00;
    gSoundFalloffs[15].mUnk_04 = w16.mUnk_04;
    gSoundFalloffs[15].mUnk_08 = w16.mUnk_08;
    gSoundFalloffs[15].mInnerDistance = w16.mUnk_0c;
    gSoundFalloffs[15].mUnk_14 = DivFixed12((w16.mUnk_08 - w16.mUnk_10) << 12, (w16.mUnk_04 - w16.mUnk_0c) << 12);
    gSoundFalloffs[15].mUnk_18 = DivFixed12(w16.mUnk_08 << 12, (w16.mUnk_04 - w16.mUnk_00) << 12);
    gSoundFalloffs[15].mUnk_1c = DivFixed12(0x666, (gSoundFalloffs[15].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[15].mUnk_20 = (((s32) ((((s64) (w16.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w16.mUnk_00 << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
}

s32 ComputeSoundVolume(Unk0210bcf4 *p) {
    Kart *k;
    SoundFalloff *e;
    s32 v;
    s32 a;

    k = (Kart *) p->mUnk_00;
    v = 0;
    if (k != NULL) {
        if (k != NULL && k->mSoundSource.mFalloffIndex == 0 && k->mIndex != data_021759c0->mEntryIndex) {
            e = &gOtherKartSoundFalloff;
        } else {
            e = &gSoundFalloffs[k->mSoundSource.mFalloffIndex];
        }
    } else {
        e = &gSoundFalloffs[p->mUnk_20->mUnk_08];
    }
    a = p->mUnk_10;
    if (a <= e->mInnerDistance) {
        v = e->mMaxVolume;
    } else if (a <= e->mUnk_04) {
        v = e->mMaxVolume + (((s32) ((((s64) e->mUnk_14 * ((a - e->mInnerDistance) << 12)) + 0x800) >> 12)) >> 12);
    } else if (a < e->mOuterDistance) {
        v = ((s32) ((((s64) e->mUnk_18 * ((a - e->mOuterDistance) << 12)) + 0x800) >> 12)) >> 12;
    }
    a = p->mUnk_08;
    if (a < 0x36) {
        if (a > -e->mInnerDistance) {
            a = ((s32) ((((s64) e->mUnk_1c * ((a - 0x36) << 12)) + 0x800) >> 12)) + 0x1000;
            v = ((s32) ((((s64) a * (v << 12)) + 0x800) >> 12)) >> 12;
        } else {
            v = ((s32) ((((s64) (v << 12) * 0x99a) + 0x800) >> 12)) >> 12;
        }
    }
    if (v < 0) {
        return 0;
    }
    if (v > e->mMaxVolume) {
        return e->mMaxVolume;
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
        a = ((Kart *) p->mUnk_00)->mSoundSource.mDistanceSquared;
    } else {
        a = p->mUnk_20->mUnk_0c;
    }
    reg_CP_SQRTCNT = 0;
    *(vu32 *) 0x040002b8 = a;
    b = p->mUnk_04;
    p->mUnk_08 = GetCameraForwardDistance(b) >> 12;
    p->mUnk_0c = GetCameraSideDistance(b) >> 12;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return reg_CP_SQRT_RESULT;
}
