#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_020578fc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma thumb on

void func_02056a4c(Unk0217aa08_10_04 *a, Unk02056a2c *b) {
    if (b->mUnk_00 != 0) {
        a->mUnk_00_0 = 1;
        a->mUnk_00_1 = b->mUnk_01;
    } else {
        a->mUnk_00_0 = 0;
    }
}

void func_02056a2c(Unk0217aa08_10_04 *a, Unk02056a2c *b) {
    if (a->mUnk_00_0 != 0) {
        b->mUnk_00 = 1;
        b->mUnk_01 = a->mUnk_00_1;
    } else {
        b->mUnk_00 = 0;
    }
}

void func_02056a04(s32 a, s32 b, Unk02056a2c *c) {
    func_02056a4c(&data_0217aa08->mUnk_10->mUnk_04[(a - 1) * 9 + b - 1], c);
}

s32 func_020569dc(s32 a, s32 b, Unk02056a2c *c) {
    func_02056a2c(&data_0217aa08->mUnk_10->mUnk_04[(a - 1) * 9 + b - 1], c);
    return 1;
}

void func_020569a8(void *a) {
    MI_CpuCopy8(a, data_0217aa08->mUnk_04->mUnk_008, 0x200);
    data_0217aa08->mUnk_04->mUnk_004 = 1;
    func_02056430();
}

void func_02056750(s32 a, u16 b) {
    Unk0217aa08_14 *p;
    s32 k;
    s32 n;
    u8 m;
    u8 i;
    u8 j;
    s32 t[4];
    Unk02056750_c v;
    u8 v1[0xf];
    u32 w;

    n = func_0204684c();
    k = data_021759c0->mCurrentEntries[b].mPlayer.mIndex;
    p = data_0217aa08->mUnk_14[0];
    if (n == -1) {
        return;
    }
    MI_CpuFill8(p, 0, 0xe00);
    GetClockDateOrDefault(t);
    p->mUnk_04_16 = t[0];
    p->mUnk_04_23 = t[1];
    p->mUnk_04_27 = t[2];
    w = data_021759c0->mCurrentEntries[b].mCharacterIndex;
    p->mUnk_04_0 = (u8) w;
    w = data_021759c0->mCurrentEntries[b].mKartIndex;
    p->mUnk_04_4 = (u8) w;
    w = data_021759c0->mCourseId;
    p->mUnk_04_10 = (u8) w;
    p->mUnk_08_0 = 1;
    p->mUnk_08_1 = 0;
    p->mUnk_08_2 = data_021759d0->mUnk_00;
    p->mUnk_08_4 = 0;
    p->mUnk_2f_0 = func_02056208();
    GetKartFinishTime(b, &v.mUnk_00, &v.mUnk_01, &v.mUnk_02);
    p->mUnk_08_8 = v.mUnk_00;
    p->mUnk_08_15 = v.mUnk_01;
    p->mUnk_08_22 = v.mUnk_02;
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, p->mUnk_0c, 0x14);
    MI_CpuCopy8(data_02175628[k].mUnk_28, p->mUnk_30, 0xdcc);
    MI_CpuFill8(v1, 0, 0xf);
    for (i = 1; i <= GetLapCount(); i++) {
        j = (i - 1) * 3;
        GetKartLapTime(b, i, &v.mUnk_00, &v.mUnk_01, &v.mUnk_02);
        w = 0;
        w |= (v.mUnk_00 & 0x7f) << 17;
        w |= (v.mUnk_01 & 0x7f) << 10;
        w |= v.mUnk_02 & 0x3ff;
        v1[j] = w >> 16;
        v1[j + 1] = w >> 8;
        v1[j + 2] = w;
    }
    MI_CpuCopy8(v1, p->mUnk_20, 0xf);
    m = n;
    func_020579d0(m, p);
    if (func_020573f8(m) == 0) {
        func_0205746c(m, data_0217aa08->mUnk_00->mUnk_26, 4);
        func_020574a0();
    }
}

void func_02056700(u32 a) {
    s32 n;
    BOOL f;
    Unk0217aa08_14 *p;

    f = FALSE;
    n = func_0204684c(a);
    p = data_0217aa08->mUnk_14[0];
    if (n == -1) {
        f = TRUE;
    } else if (func_020573f8(n) == 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        p->mUnk_08_0 = 0;
    } else {
        func_0205798c(n, p);
    }
}

#pragma thumb off
