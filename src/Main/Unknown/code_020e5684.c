#include "Main/Unknown/code_020e5684.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020e57f4.h"
#include "Main/Unknown/code_020e57fc.h"
#include "Main/Unknown/code_020e5850.h"
#include "Main/Unknown/code_020e5854.h"
#include "Main/Unknown/code_020e58b8.h"
#include "Main/Unknown/code_020e58c4.h"
#include "Main/Unknown/code_020e58fc.h"
#include "Main/Unknown/code_020e5900.h"
#include "Main/Unknown/code_020e5950.h"

void func_020e5950(Unk020e5950 *p0) {
    p0->mUnk_c8 = (u32) 0x0u;
}

void func_020e5900(Unk020e43a8 *p) {
    p->mUnk_c8 = p->mUnk_c8 + p->mUnk_cc;
    p->mUnk_00.mUnk_7e = p->mUnk_00.mUnk_7e + (s16) (((s64) p->mUnk_c8 * p->mUnk_c6) >> 12);
    if (p->mUnk_00.mUnk_80.mUnk_04 > *(u16 *) &p->mUnk_a0.mUnk_18.z) {
        p->mUnk_00.mUnk_80.mUnk_10 = 1;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u32 func_020e58fc(u32 p0) {
    return p0;
}

void func_020e58c4(Unk020e43a8 *p) {
    p->mUnk_00.mUnk_7e = p->mUnk_00.mUnk_7e + p->mUnk_c6;
    if (*((u16 *) &p->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (p->mUnk_00.mUnk_80.mUnk_04 > *((u16 *) &p->mUnk_a0.mUnk_18.z + 1)) {
        p->mUnk_00.mUnk_80.mUnk_10 = 2;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

void func_020e58b8(Unk020e58b8 *p0) {
    p0->mUnk_c8 = (u32) 0x4000u;
}

void func_020e5854(Unk020e43a8 *p) {
    p->mUnk_c8 = p->mUnk_c8 - p->mUnk_cc;
    p->mUnk_00.mUnk_7e = p->mUnk_00.mUnk_7e + (s16) (((s64) p->mUnk_c8 * p->mUnk_c6) >> 12);
    if (p->mUnk_00.mUnk_80.mUnk_04 > *(u16 *) &p->mUnk_a0.mUnk_18.z) {
        p->mUnk_c6 = -p->mUnk_c6;
        p->mUnk_00.mUnk_80.mUnk_10 = 3;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u32 func_020e5850(u32 p0) {
    return p0;
}

void func_020e5830(Unk020e43a8 *p) {
    if (p->mUnk_00.mUnk_80.mUnk_04 > p->mUnk_c4) {
        p->mUnk_00.mUnk_80.mUnk_10 = 0;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

s32 func_020e57fc(Unk020e43a8 *p, Unk020e57fc *q, s32 a, u8 *b) {
    u32 x;

    x = q->mUnk_29c;
    if (x == 1 || x == 3) {
        p->mUnk_00.mUnk_78 |= data_021590e8;
    }
    return *b;
}

u32 func_020e57f4(u32 p0, u32 p1, u32 p2, u32 p3) {
    return ((u32) * (const u8 *) ((u8 *) p3 + 0));
}

void func_020e57a0(Unk020e43a8 *p, Vec3 *a, s32 b, Vec3 *c) {
    Vec3 s;
    s32 y;

    y = p->mUnk_00.mUnk_58.y;
    s.x = p->mUnk_00.mUnk_58.x;
    s.y = y;
    s.z = 0;
    func_020eafc4(a, &p->mUnk_00.mUnk_04, &p->mUnk_00.mUnk_28.mUnk_00[0], &p->mUnk_00.mUnk_58, &s, b, c);
}

#pragma thumb on

void CreateSecondHand(void) {
    func_020ea588(&gSecondHand, (void *) FindCourseMapObjFile(gSecondHandNsbmdName), NULL);
    func_02084968(gSecondHand, 0x3f, 2, 0x294a);
}

void func_020e5684(Unk020e43a8 *p, Unk020e5684 *q) {
    p->mUnk_00.mUnk_58.y = (s32) (((s64) p->mUnk_00.mUnk_1c.x * 0x4b000) >> 12);
    func_02046be8(&p->mUnk_00.mUnk_80, (UnkFunc *const *) data_0216c240, 4, p);
    func_020d720c((Vec3 *) &q->mUnk_0c, (u32 *) &p->mUnk_a0.mUnk_00);
    *(Unk020d7b88 *) &p->mUnk_a0.mUnk_0c.y = *(Unk020d7b88 *) &p->mUnk_a0.mUnk_00;
    *(s16 *) &p->mUnk_a0.mUnk_18.z = q->mUnk_2c;
    *((s16 *) &p->mUnk_a0.mUnk_18.z + 1) = q->mUnk_2a;
    p->mUnk_c4 = q->mUnk_2e;
    p->mUnk_c6 = (s16) ((q->mUnk_28 << 7) / 0x64);
    if (q->mUnk_30 != 0) {
        p->mUnk_c6 = -p->mUnk_c6;
    }
    p->mUnk_00.mUnk_7e = 0;
    if (*(u16 *) &p->mUnk_a0.mUnk_18.z != 0) {
        p->mUnk_cc = 0x1000 / *(u16 *) &p->mUnk_a0.mUnk_18.z;
    } else {
        p->mUnk_cc = 0;
    }
    p->mUnk_c8 = 0;
    p->mUnk_00.mUnk_80.mUnk_10 = 0;
    p->mUnk_00.mUnk_80.mUnk_12 = 1;
    p->mUnk_00.mUnk_02 |= data_021590b0;
}

#pragma thumb off
