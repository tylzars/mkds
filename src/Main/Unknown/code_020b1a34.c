#include "Main/Unknown/code_020b1a34.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0214d000.h"
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
#include "Main/Unknown/code_020b4000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma opt_arithtransformation off

// Absolute difference of two times (minutes, seconds, milliseconds) written to the out record (minutes capped to
// 99:59.999 from 100 minutes); returns non-zero when a >= b.
s32 ComputeTimeDifference(Unk020b1bf8 *a, Unk020b1bf8 *b, Unk020b1a34_0c *c) {
    s32 x;
    s32 y;
    s32 d;
    BOOL r;
    s32 m;
    s32 s;
    s32 n;

    x = (a->mUnk_00 * 60 + a->mUnk_04) * 1000 + a->mUnk_08;
    y = (b->mUnk_00 * 60 + b->mUnk_04) * 1000 + b->mUnk_08;
    r = x >= y;
    if (r != FALSE) {
        d = x - y;
    } else {
        d = y - x;
    }
    m = d / 60000;
    s = (d - m * 60000) / 1000;
    n = d % 1000;
    if (m < 100) {
        c->mUnk_02 = m;
        c->mUnk_03 = s;
        c->mUnk_00 = n;
    } else {
        c->mUnk_02 = 99;
        c->mUnk_03 = 59;
        c->mUnk_00 = 999;
    }
    return r;
}

void func_020b1a34(void) {
    Unk020b1a34_0c a;
    Unk020b1a34_0c b;
    Unk020b1a34_0c c;
    Unk020b1bf8 t[2];
    TimeDigits w;
    u8 i;
    u8 j;

    if (data_021759c0->mMode == 0 || data_021759c0->mMode == 1) {
        gRaceHud->mUnk_8dc = 1;
    }
    if (gRaceHud->mUseTimeDifference == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        t[i].mUnk_00 = 0;
        t[i].mUnk_04 = 0;
        t[i].mUnk_08 = 0;
    }
    for (j = 1; j <= func_020b4d2c(); j++) {
        if (data_021759c0->mMode == 1) {
            MemCopy(&data_021759c0->mUnk_3ec[j - 1], &a, 4);
        }
        t[0].mUnk_00 += a.mUnk_02;
        t[0].mUnk_04 += a.mUnk_03;
        t[0].mUnk_08 += a.mUnk_00;
        GetKartLapTime(func_020b4d9c(), j, &b.mUnk_02, &b.mUnk_03, &b.mUnk_00);
        t[1].mUnk_00 += b.mUnk_02;
        t[1].mUnk_04 += b.mUnk_03;
        t[1].mUnk_08 += b.mUnk_00;
    }
    gRaceHud->mTimeDifferenceSign = ComputeTimeDifference(&t[1], &t[0], &c);
    SplitTimeDigits(c.mUnk_02, c.mUnk_03, c.mUnk_00, &w);
    gRaceHud->mTimeDifferenceDigits = w;
}
