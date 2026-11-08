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

void StopKartSoundWhileRequested(Kart *a) {
    if (a->mUnk_488 == 0xffff) {
        return;
    }
    StopSoundEx(&a->mSoundSource, 0, a->mUnk_488, 0);
    a->mUnk_488 = 0xffff;
}

void InitSoundFalloffs(void) {
    BOOL f;
    SoundFalloffSettings t0;
    SoundFalloffSettings t1;
    SoundFalloffSettings t2;
    SoundFalloffSettings t3;
    SoundFalloffSettings t4;
    SoundFalloffSettings b0;
    SoundFalloffSettings c0;
    SoundFalloffSettings b1;
    SoundFalloffSettings c1;
    SoundFalloffSettings b2;
    SoundFalloffSettings c2;
    SoundFalloffSettings b3;
    SoundFalloffSettings c3;
    SoundFalloffSettings b4;
    SoundFalloffSettings c4;
    SoundFalloffSettings w5;
    SoundFalloffSettings w6;
    SoundFalloffSettings w7;
    SoundFalloffSettings w8;
    SoundFalloffSettings w9;
    SoundFalloffSettings w10;
    SoundFalloffSettings w11;
    SoundFalloffSettings w12;
    SoundFalloffSettings w13;
    SoundFalloffSettings w14;
    SoundFalloffSettings w15;
    SoundFalloffSettings w16;
    static SoundFalloffSettings s14 = {1400, 750, 55, 100, 110};
    static SoundFalloffSettings s3 = {380, 304, 66, 150, 95};
    static SoundFalloffSettings s4 = {800, 500, 57, 150, 95};
    static SoundFalloffSettings s6 = {3000, 1500, 52, 150, 95};
    static SoundFalloffSettings s5 = {1100, 550, 47, 150, 95};
    static SoundFalloffSettings s7 = {600, 400, 47, 150, 95};
    static SoundFalloffSettings s8 = {1500, 900, 69, 150, 115};
    static SoundFalloffSettings s9 = {1200, 600, 47, 150, 95};
    static SoundFalloffSettings s10 = {5000, 4000, 88, 150, 127};
    static SoundFalloffSettings s11 = {1100, 550, 62, 150, 95};
    static SoundFalloffSettings s2 = {1100, 500, 71, 150, 95};
    static SoundFalloffSettings s13 = {1000, 650, 55, 300, 110};
    static SoundFalloffSettings s12 = {800, 400, 47, 54, 95};
    static SoundFalloffSettings s15 = {1100, 600, 55, 100, 110};
    static SoundFalloffSettings s16 = {950, 525, 55, 100, 110};
    static SoundFalloffSettings s0 = {800, 500, 47, 150, 127};
    static SoundFalloffSettings s1 = {800, 500, 47, 150, 95};

    if (GetCurrentSceneNumber() == 2 && gRaceSetup->mRaceKind == 2) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    t0 = s0;
    if (f != FALSE) {
        b0 = t0;
        b0.mOuterDistance = 0x44c;
        b0.mUnk_04 = 0x226;
        b0.mUnk_08 = 0x2f;
        b0.mMaxVolume = 0x5f;
        t0 = b0;
    }
    c0 = t0;
    gSoundFalloffs[0].mMaxVolume = c0.mMaxVolume;
    gSoundFalloffs[0].mOuterDistance = c0.mOuterDistance;
    gSoundFalloffs[0].mUnk_04 = c0.mUnk_04;
    gSoundFalloffs[0].mUnk_08 = c0.mUnk_08;
    gSoundFalloffs[0].mInnerDistance = c0.mInnerDistance;
    gSoundFalloffs[0].mUnk_14 = FX_Div((c0.mUnk_08 - c0.mMaxVolume) << 12, (c0.mUnk_04 - c0.mInnerDistance) << 12);
    gSoundFalloffs[0].mUnk_18 = FX_Div(c0.mUnk_08 << 12, (c0.mUnk_04 - c0.mOuterDistance) << 12);
    gSoundFalloffs[0].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[0].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[0].mUnk_20 = (((s32) ((((s64) (c0.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (c0.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t1 = s1;
    if (f != FALSE) {
        b1 = t1;
        b1.mOuterDistance = 0x44c;
        b1.mUnk_04 = 0x226;
        b1.mUnk_08 = 0x2f;
        b1.mMaxVolume = 0x5f;
        t1 = b1;
    }
    c1 = t1;
    gOtherKartSoundFalloff.mMaxVolume = c1.mMaxVolume;
    gOtherKartSoundFalloff.mOuterDistance = c1.mOuterDistance;
    gOtherKartSoundFalloff.mUnk_04 = c1.mUnk_04;
    gOtherKartSoundFalloff.mUnk_08 = c1.mUnk_08;
    gOtherKartSoundFalloff.mInnerDistance = c1.mInnerDistance;
    gOtherKartSoundFalloff.mUnk_14 = FX_Div((c1.mUnk_08 - c1.mMaxVolume) << 12, (c1.mUnk_04 - c1.mInnerDistance) << 12);
    gOtherKartSoundFalloff.mUnk_18 = FX_Div(c1.mUnk_08 << 12, (c1.mUnk_04 - c1.mOuterDistance) << 12);
    gOtherKartSoundFalloff.mUnk_1c = FX_Div(0x666, (gOtherKartSoundFalloff.mInnerDistance << 12) + 0x36000);
    gOtherKartSoundFalloff.mUnk_20 = (((s32) ((((s64) (c1.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                     (((s32) ((((s64) (c1.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t2 = s2;
    if (f != FALSE) {
        b2 = t2;
        b2.mOuterDistance = 0x514;
        b2.mUnk_04 = 0x28a;
        b2.mUnk_08 = 0x2f;
        b2.mMaxVolume = 0x5f;
        t2 = b2;
    }
    c2 = t2;
    gSoundFalloffs[1].mMaxVolume = c2.mMaxVolume;
    gSoundFalloffs[1].mOuterDistance = c2.mOuterDistance;
    gSoundFalloffs[1].mUnk_04 = c2.mUnk_04;
    gSoundFalloffs[1].mUnk_08 = c2.mUnk_08;
    gSoundFalloffs[1].mInnerDistance = c2.mInnerDistance;
    gSoundFalloffs[1].mUnk_14 = FX_Div((c2.mUnk_08 - c2.mMaxVolume) << 12, (c2.mUnk_04 - c2.mInnerDistance) << 12);
    gSoundFalloffs[1].mUnk_18 = FX_Div(c2.mUnk_08 << 12, (c2.mUnk_04 - c2.mOuterDistance) << 12);
    gSoundFalloffs[1].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[1].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[1].mUnk_20 = (((s32) ((((s64) (c2.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (c2.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t3 = s3;
    if (f != FALSE) {
        b3 = t3;
        b3.mOuterDistance = 0x44c;
        b3.mUnk_04 = 0x226;
        b3.mUnk_08 = 0x2f;
        b3.mMaxVolume = 0x5f;
        t3 = b3;
    }
    c3 = t3;
    gSoundFalloffs[2].mMaxVolume = c3.mMaxVolume;
    gSoundFalloffs[2].mOuterDistance = c3.mOuterDistance;
    gSoundFalloffs[2].mUnk_04 = c3.mUnk_04;
    gSoundFalloffs[2].mUnk_08 = c3.mUnk_08;
    gSoundFalloffs[2].mInnerDistance = c3.mInnerDistance;
    gSoundFalloffs[2].mUnk_14 = FX_Div((c3.mUnk_08 - c3.mMaxVolume) << 12, (c3.mUnk_04 - c3.mInnerDistance) << 12);
    gSoundFalloffs[2].mUnk_18 = FX_Div(c3.mUnk_08 << 12, (c3.mUnk_04 - c3.mOuterDistance) << 12);
    gSoundFalloffs[2].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[2].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[2].mUnk_20 = (((s32) ((((s64) (c3.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (c3.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    t4 = s4;
    if (f != FALSE) {
        b4 = t4;
        b4.mOuterDistance = 0x44c;
        b4.mUnk_04 = 0x226;
        b4.mUnk_08 = 0x2f;
        b4.mMaxVolume = 0x5f;
        t4 = b4;
    }
    c4 = t4;
    gSoundFalloffs[3].mMaxVolume = c4.mMaxVolume;
    gSoundFalloffs[3].mOuterDistance = c4.mOuterDistance;
    gSoundFalloffs[3].mUnk_04 = c4.mUnk_04;
    gSoundFalloffs[3].mUnk_08 = c4.mUnk_08;
    gSoundFalloffs[3].mInnerDistance = c4.mInnerDistance;
    gSoundFalloffs[3].mUnk_14 = FX_Div((c4.mUnk_08 - c4.mMaxVolume) << 12, (c4.mUnk_04 - c4.mInnerDistance) << 12);
    gSoundFalloffs[3].mUnk_18 = FX_Div(c4.mUnk_08 << 12, (c4.mUnk_04 - c4.mOuterDistance) << 12);
    gSoundFalloffs[3].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[3].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[3].mUnk_20 = (((s32) ((((s64) (c4.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (c4.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w5 = s5;
    gSoundFalloffs[4].mMaxVolume = w5.mMaxVolume;
    gSoundFalloffs[4].mOuterDistance = w5.mOuterDistance;
    gSoundFalloffs[4].mUnk_04 = w5.mUnk_04;
    gSoundFalloffs[4].mUnk_08 = w5.mUnk_08;
    gSoundFalloffs[4].mInnerDistance = w5.mInnerDistance;
    gSoundFalloffs[4].mUnk_14 = FX_Div((w5.mUnk_08 - w5.mMaxVolume) << 12, (w5.mUnk_04 - w5.mInnerDistance) << 12);
    gSoundFalloffs[4].mUnk_18 = FX_Div(w5.mUnk_08 << 12, (w5.mUnk_04 - w5.mOuterDistance) << 12);
    gSoundFalloffs[4].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[4].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[4].mUnk_20 = (((s32) ((((s64) (w5.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w5.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w6 = s6;
    gSoundFalloffs[5].mMaxVolume = w6.mMaxVolume;
    gSoundFalloffs[5].mOuterDistance = w6.mOuterDistance;
    gSoundFalloffs[5].mUnk_04 = w6.mUnk_04;
    gSoundFalloffs[5].mUnk_08 = w6.mUnk_08;
    gSoundFalloffs[5].mInnerDistance = w6.mInnerDistance;
    gSoundFalloffs[5].mUnk_14 = FX_Div((w6.mUnk_08 - w6.mMaxVolume) << 12, (w6.mUnk_04 - w6.mInnerDistance) << 12);
    gSoundFalloffs[5].mUnk_18 = FX_Div(w6.mUnk_08 << 12, (w6.mUnk_04 - w6.mOuterDistance) << 12);
    gSoundFalloffs[5].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[5].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[5].mUnk_20 = (((s32) ((((s64) (w6.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w6.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w7 = s7;
    gSoundFalloffs[6].mMaxVolume = w7.mMaxVolume;
    gSoundFalloffs[6].mOuterDistance = w7.mOuterDistance;
    gSoundFalloffs[6].mUnk_04 = w7.mUnk_04;
    gSoundFalloffs[6].mUnk_08 = w7.mUnk_08;
    gSoundFalloffs[6].mInnerDistance = w7.mInnerDistance;
    gSoundFalloffs[6].mUnk_14 = FX_Div((w7.mUnk_08 - w7.mMaxVolume) << 12, (w7.mUnk_04 - w7.mInnerDistance) << 12);
    gSoundFalloffs[6].mUnk_18 = FX_Div(w7.mUnk_08 << 12, (w7.mUnk_04 - w7.mOuterDistance) << 12);
    gSoundFalloffs[6].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[6].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[6].mUnk_20 = (((s32) ((((s64) (w7.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w7.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w8 = s8;
    gSoundFalloffs[7].mMaxVolume = w8.mMaxVolume;
    gSoundFalloffs[7].mOuterDistance = w8.mOuterDistance;
    gSoundFalloffs[7].mUnk_04 = w8.mUnk_04;
    gSoundFalloffs[7].mUnk_08 = w8.mUnk_08;
    gSoundFalloffs[7].mInnerDistance = w8.mInnerDistance;
    gSoundFalloffs[7].mUnk_14 = FX_Div((w8.mUnk_08 - w8.mMaxVolume) << 12, (w8.mUnk_04 - w8.mInnerDistance) << 12);
    gSoundFalloffs[7].mUnk_18 = FX_Div(w8.mUnk_08 << 12, (w8.mUnk_04 - w8.mOuterDistance) << 12);
    gSoundFalloffs[7].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[7].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[7].mUnk_20 = (((s32) ((((s64) (w8.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w8.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w9 = s9;
    gSoundFalloffs[8].mMaxVolume = w9.mMaxVolume;
    gSoundFalloffs[8].mOuterDistance = w9.mOuterDistance;
    gSoundFalloffs[8].mUnk_04 = w9.mUnk_04;
    gSoundFalloffs[8].mUnk_08 = w9.mUnk_08;
    gSoundFalloffs[8].mInnerDistance = w9.mInnerDistance;
    gSoundFalloffs[8].mUnk_14 = FX_Div((w9.mUnk_08 - w9.mMaxVolume) << 12, (w9.mUnk_04 - w9.mInnerDistance) << 12);
    gSoundFalloffs[8].mUnk_18 = FX_Div(w9.mUnk_08 << 12, (w9.mUnk_04 - w9.mOuterDistance) << 12);
    gSoundFalloffs[8].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[8].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[8].mUnk_20 = (((s32) ((((s64) (w9.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w9.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w10 = s10;
    gSoundFalloffs[9].mMaxVolume = w10.mMaxVolume;
    gSoundFalloffs[9].mOuterDistance = w10.mOuterDistance;
    gSoundFalloffs[9].mUnk_04 = w10.mUnk_04;
    gSoundFalloffs[9].mUnk_08 = w10.mUnk_08;
    gSoundFalloffs[9].mInnerDistance = w10.mInnerDistance;
    gSoundFalloffs[9].mUnk_14 = FX_Div((w10.mUnk_08 - w10.mMaxVolume) << 12, (w10.mUnk_04 - w10.mInnerDistance) << 12);
    gSoundFalloffs[9].mUnk_18 = FX_Div(w10.mUnk_08 << 12, (w10.mUnk_04 - w10.mOuterDistance) << 12);
    gSoundFalloffs[9].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[9].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[9].mUnk_20 = (((s32) ((((s64) (w10.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                (((s32) ((((s64) (w10.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w11 = s11;
    gSoundFalloffs[10].mMaxVolume = w11.mMaxVolume;
    gSoundFalloffs[10].mOuterDistance = w11.mOuterDistance;
    gSoundFalloffs[10].mUnk_04 = w11.mUnk_04;
    gSoundFalloffs[10].mUnk_08 = w11.mUnk_08;
    gSoundFalloffs[10].mInnerDistance = w11.mInnerDistance;
    gSoundFalloffs[10].mUnk_14 = FX_Div((w11.mUnk_08 - w11.mMaxVolume) << 12, (w11.mUnk_04 - w11.mInnerDistance) << 12);
    gSoundFalloffs[10].mUnk_18 = FX_Div(w11.mUnk_08 << 12, (w11.mUnk_04 - w11.mOuterDistance) << 12);
    gSoundFalloffs[10].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[10].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[10].mUnk_20 = (((s32) ((((s64) (w11.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w11.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w12 = s12;
    gSoundFalloffs[11].mMaxVolume = w12.mMaxVolume;
    gSoundFalloffs[11].mOuterDistance = w12.mOuterDistance;
    gSoundFalloffs[11].mUnk_04 = w12.mUnk_04;
    gSoundFalloffs[11].mUnk_08 = w12.mUnk_08;
    gSoundFalloffs[11].mInnerDistance = w12.mInnerDistance;
    gSoundFalloffs[11].mUnk_14 = FX_Div((w12.mUnk_08 - w12.mMaxVolume) << 12, (w12.mUnk_04 - w12.mInnerDistance) << 12);
    gSoundFalloffs[11].mUnk_18 = FX_Div(w12.mUnk_08 << 12, (w12.mUnk_04 - w12.mOuterDistance) << 12);
    gSoundFalloffs[11].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[11].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[11].mUnk_20 = (((s32) ((((s64) (w12.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w12.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w13 = s13;
    gSoundFalloffs[12].mMaxVolume = w13.mMaxVolume;
    gSoundFalloffs[12].mOuterDistance = w13.mOuterDistance;
    gSoundFalloffs[12].mUnk_04 = w13.mUnk_04;
    gSoundFalloffs[12].mUnk_08 = w13.mUnk_08;
    gSoundFalloffs[12].mInnerDistance = w13.mInnerDistance;
    gSoundFalloffs[12].mUnk_14 = FX_Div((w13.mUnk_08 - w13.mMaxVolume) << 12, (w13.mUnk_04 - w13.mInnerDistance) << 12);
    gSoundFalloffs[12].mUnk_18 = FX_Div(w13.mUnk_08 << 12, (w13.mUnk_04 - w13.mOuterDistance) << 12);
    gSoundFalloffs[12].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[12].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[12].mUnk_20 = (((s32) ((((s64) (w13.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w13.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w14 = s14;
    gSoundFalloffs[13].mMaxVolume = w14.mMaxVolume;
    gSoundFalloffs[13].mOuterDistance = w14.mOuterDistance;
    gSoundFalloffs[13].mUnk_04 = w14.mUnk_04;
    gSoundFalloffs[13].mUnk_08 = w14.mUnk_08;
    gSoundFalloffs[13].mInnerDistance = w14.mInnerDistance;
    gSoundFalloffs[13].mUnk_14 = FX_Div((w14.mUnk_08 - w14.mMaxVolume) << 12, (w14.mUnk_04 - w14.mInnerDistance) << 12);
    gSoundFalloffs[13].mUnk_18 = FX_Div(w14.mUnk_08 << 12, (w14.mUnk_04 - w14.mOuterDistance) << 12);
    gSoundFalloffs[13].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[13].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[13].mUnk_20 = (((s32) ((((s64) (w14.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w14.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w15 = s15;
    gSoundFalloffs[14].mMaxVolume = w15.mMaxVolume;
    gSoundFalloffs[14].mOuterDistance = w15.mOuterDistance;
    gSoundFalloffs[14].mUnk_04 = w15.mUnk_04;
    gSoundFalloffs[14].mUnk_08 = w15.mUnk_08;
    gSoundFalloffs[14].mInnerDistance = w15.mInnerDistance;
    gSoundFalloffs[14].mUnk_14 = FX_Div((w15.mUnk_08 - w15.mMaxVolume) << 12, (w15.mUnk_04 - w15.mInnerDistance) << 12);
    gSoundFalloffs[14].mUnk_18 = FX_Div(w15.mUnk_08 << 12, (w15.mUnk_04 - w15.mOuterDistance) << 12);
    gSoundFalloffs[14].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[14].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[14].mUnk_20 = (((s32) ((((s64) (w15.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w15.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
    w16 = s16;
    gSoundFalloffs[15].mMaxVolume = w16.mMaxVolume;
    gSoundFalloffs[15].mOuterDistance = w16.mOuterDistance;
    gSoundFalloffs[15].mUnk_04 = w16.mUnk_04;
    gSoundFalloffs[15].mUnk_08 = w16.mUnk_08;
    gSoundFalloffs[15].mInnerDistance = w16.mInnerDistance;
    gSoundFalloffs[15].mUnk_14 = FX_Div((w16.mUnk_08 - w16.mMaxVolume) << 12, (w16.mUnk_04 - w16.mInnerDistance) << 12);
    gSoundFalloffs[15].mUnk_18 = FX_Div(w16.mUnk_08 << 12, (w16.mUnk_04 - w16.mOuterDistance) << 12);
    gSoundFalloffs[15].mUnk_1c = FX_Div(0x666, (gSoundFalloffs[15].mInnerDistance << 12) + 0x36000);
    gSoundFalloffs[15].mUnk_20 = (((s32) ((((s64) (w16.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12) *
                                 (((s32) ((((s64) (w16.mOuterDistance << 12) * 0x16a1) + 0x800) >> 12)) >> 12);
}

s32 ComputeSoundVolume(SoundParams *p) {
    Kart *k;
    SoundFalloff *e;
    s32 v;
    s32 a;

    k = (Kart *) p->mSource;
    v = 0;
    if (k != NULL) {
        if (k != NULL && k->mSoundSource.mFalloffIndex == 0 && k->mIndex != gRaceSetup->mEntryIndex) {
            e = &gOtherKartSoundFalloff;
        } else {
            e = &gSoundFalloffs[k->mSoundSource.mFalloffIndex];
        }
    } else {
        e = &gSoundFalloffs[p->mUnk_20->mUnk_08];
    }
    a = p->mDistance;
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

// Returns the pan, from -0x80 to 0x7f.
s32 ComputeSoundPan(SoundParams *p) {
    u32 a;
    s32 v;

    a = FX_Atan2Idx(p->mUnk_08 << 12, -p->mUnk_0c << 12);
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

// Returns the distance to the camera; also stores the forward and side distance in the record.
u32 ComputeSoundDistanceAndOffsets(SoundParams *p) {
    u32 a;
    u32 b;

    if (p->mSource != NULL) {
        a = ((Kart *) p->mSource)->mSoundSource.mDistanceSquared;
    } else {
        a = p->mUnk_20->mUnk_0c;
    }
    reg_CP_SQRTCNT = 0;
    *(vu32 *) 0x040002b8 = a;
    b = p->mPositionSource;
    p->mUnk_08 = GetCameraForwardDistance(b) >> 12;
    p->mUnk_0c = GetCameraSideDistance(b) >> 12;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    return reg_CP_SQRT_RESULT;
}
