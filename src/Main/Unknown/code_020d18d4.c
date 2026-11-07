#include "Main/Unknown/code_020d18d4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"

void DrawRaceMNumberPair(Unk020d029c *param_1) {
    s32 a;

    a = GetRaceStartSequenceFrames();
    if (data_021759c0->mUnk_00c == 4 || data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (a >= 0xb4) {
        return;
    }
    if (data_021759c0->mMode != 5 && (data_021759c0->mMode != MODE_VS || data_021759c0->mUnk_1c != 2)) {
        return;
    }
    func_020d1de8(param_1, a);
    if (gRaceMNumberPair->mUnk_1c == 0) {
        return;
    }
    if (gRaceMNumberPair->mCourseCount >= 10) {
        DrawRaceMNumberPairTwoDigit(param_1);
        return;
    }
    DrawRaceMNumberPairOneDigit(param_1);
}

void func_020d1de8(Unk020d029c *param_1, s32 param_2) {
    s32 t[20] = {0,    205,  410,  614,  819,  1638, 2253, 2867, 3891, 4506,
                 4710, 4915, 5120, 5325, 5325, 5120, 4915, 4710, 4506, 4096};
    s32 a;
    Unk020224e0_o *e;

    if (param_2 < 0) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mUnk_18 = NULL;
        gRaceMNumberPair->mUnk_1c = 0;
        gRaceMNumberPair->mUnk_20 = 0;
        return;
    }
    if (param_2 < 0x14) {
        s32 *p;

        a = t[param_2];
        Matrix2x2ReciprocalScale(gRaceMNumberPair->mUnk_08, a);
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mUnk_18 = gRaceMNumberPair->mUnk_08;
        gRaceMNumberPair->mUnk_1c = a;
        gRaceMNumberPair->mUnk_20 = func_020ae5c4(param_1);
        p = gRaceMNumberPair->mUnk_18;
        e = &param_1->mUnk_000[gRaceMNumberPair->mUnk_20 * 4];
        e[0].mUnk_00[3] = p[0] >> 4;
        e[1].mUnk_00[3] = p[1] >> 4;
        e[2].mUnk_00[3] = p[2] >> 4;
        e[3].mUnk_00[3] = p[3] >> 4;
        gRaceMNumberPair->mUnk_18[3] = gRaceMNumberPair->mUnk_1c;
        gRaceMNumberPair->mUnk_18[0] = gRaceMNumberPair->mUnk_18[3];
        gRaceMNumberPair->mUnk_18[2] = 0;
        gRaceMNumberPair->mUnk_18[1] = gRaceMNumberPair->mUnk_18[2];
        return;
    }
    if (param_2 < 0x78) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mUnk_18 = NULL;
        gRaceMNumberPair->mUnk_1c = 0x1000;
        gRaceMNumberPair->mUnk_20 = 0;
        return;
    }
    gRaceMNumberPair->mOffsetX = InterpolateS16(1, 0, 0x80, param_2 - 0x78, 0x14);
    gRaceMNumberPair->mUnk_18 = NULL;
    gRaceMNumberPair->mUnk_1c = 0x1000;
    gRaceMNumberPair->mUnk_20 = 0;
}

void DrawRaceMNumberPairTwoDigit(Unk020d029c *param_1) {
    s32 t[5] = {175, 190, 203, 216, 231};
    Unk020224e0_c *c;
    s32 *p = NULL;
    u16 a;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];

    if (gRaceMNumberPair->mCourseNumber / 10 != 0) {
        a = gRaceMNumberPair->mUnk_20;
        p = gRaceMNumberPair->mUnk_18;
        c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber / 10 + 0x2d);
        q0[0] = (t[0] + gRaceMNumberPair->mOffsetX) << 12;
        q0[1] = 0xb1000;
        param_1->mUnk_400 +=
            NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q0, a, 1);
    }
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber % 10 + 0x2d);
    q1[0] = (t[1] + gRaceMNumberPair->mOffsetX) << 12;
    q1[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q1, a, 1);
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(0x37);
    q2[0] = (t[2] + gRaceMNumberPair->mOffsetX) << 12;
    q2[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q2, a, 1);
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount / 10 + 0x2d);
    q3[0] = (t[3] + gRaceMNumberPair->mOffsetX) << 12;
    q3[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q3, a, 1);
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount % 10 + 0x2d);
    q4[0] = (t[4] + gRaceMNumberPair->mOffsetX) << 12;
    q4[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q4, a, 1);
}

void DrawRaceMNumberPairOneDigit(Unk020d029c *param_1) {
    s32 t[3] = {205, 218, 231};
    Unk020224e0_c *c;
    s32 *p;
    u16 a;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];

    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber + 0x2d);
    q0[0] = (t[0] + gRaceMNumberPair->mOffsetX) << 12;
    q0[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q0, a, 1);
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(0x37);
    q1[0] = (t[1] + gRaceMNumberPair->mOffsetX) << 12;
    q1[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q1, a, 1);
    a = gRaceMNumberPair->mUnk_20;
    p = gRaceMNumberPair->mUnk_18;
    c = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount + 0x2d);
    q2[0] = (t[2] + gRaceMNumberPair->mOffsetX) << 12;
    q2[1] = 0xb1000;
    param_1->mUnk_400 +=
        NNS_G2dMakeCellToOams(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q2, a, 1);
}
