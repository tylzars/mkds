#include "Main/Unknown/code_020dbf7c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02146cbc.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020dc428.h"
#include "Main/Unknown/code_020dc448.h"
#include "Main/Unknown/code_020dc5dc.h"

#pragma thumb off

static inline s64 func_020dc354_inline(const Vec3 *v) {
    return (s64) v->x * v->x + (s64) v->z * v->z;
}

void func_020dc354(Unk020dc474 *p) {
    p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z;
    func_020d84e4(&p->mUnk_1a0);
    func_020d8b88(&p->mUnk_1a0.mUnk_00, &p->mUnk_00.mPos);
    p->mUnk_00.mUnk_10.x = p->mUnk_00.mPos.x - p->mUnk_00.mUnk_10.x;
    p->mUnk_00.mUnk_10.z = p->mUnk_00.mPos.z - p->mUnk_00.mUnk_10.z;
    if (func_020dc354_inline(&p->mUnk_00.mUnk_10) >= 0x10) {
        func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                              0x80000000000LL) >>
                             44),
                      &p->mUnk_d4);
    }
    if (p->mUnk_00.mUnk_80.mStateFrames < 0x40) {
        p->mUnk_ec = p->mUnk_ec + 0x1c;
    }
}

#pragma thumb on
void CreateWanwanAndRockShadow(void) {
    func_020ea588((void **) &gWanwan, FindCourseMapObjFile("wanwan.nsbmd"), NULL);
    func_020ea55c((void **) &gWanwanRockShadow, FindCourseMapObjFile("rock_shadow.nsbmd"), 0x3f);
    func_02084968(gWanwan, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void func_020dc1d8(Unk020dc474 *p, CourseMapRow *a) {
    p->mUnk_a0 = a->mUnk_00;
    p->mUnk_f0 = (s32) (((s64) p->mUnk_00.mScale.y * 0x1e000) >> 12);
    p->mUnk_f4 = 0xf000 - p->mUnk_f0;
    p->mUnk_f8 = (a->mUnk_28 * 0x3000) >> 2;
    p->mUnk_1dc = a->mUnk_2a << 12;
    p->mUnk_1ec = a->mUnk_28 << 12;
    p->mUnk_1fc = p->mUnk_f8 - (p->mUnk_f0 << 1);
    p->mUnk_fc = 0;
    p->mUnk_b0 = 0;
    p->mUnk_1d8 = (Unk020dc474_1d8 *) CreateMapObjectFromObject(&p->mUnk_00, 0x197);
    p->mUnk_ac = p->mUnk_a0.y;
    p->mUnk_a0.y = p->mUnk_a0.y + p->mUnk_f0;
    func_02046be8(&p->mUnk_00.mUnk_80, data_0216befc, 6, p);
    func_02046bcc(&p->mUnk_00.mUnk_80, 0);
    p->mUnk_200 = p->mUnk_00.mMatrix.mUnk_00[2];
    func_020dbf7c(p);
    p->mUnk_1fa = func_020d555c(&p->mUnk_00.mPos, p->mUnk_1ec, 0x400, p);
    p->mUnk_00.mUnk_70 = data_0217caec[12];
}
#pragma thumb off

#pragma thumb on
void func_020dc11c(Unk020dc474 *p, CourseMapRow *a) {
    p->mUnk_a0 = a->mUnk_00;
    p->mUnk_f0 = (s32) (((s64) p->mUnk_00.mScale.y * 0x1e000) >> 12);
    p->mUnk_f4 = 0xf000 - p->mUnk_f0;
    p->mUnk_fc = 1;
    p->mUnk_b0 = a->mUnk_2a;
    p->mUnk_ac = p->mUnk_a0.y;
    p->mUnk_a0.y = p->mUnk_a0.y + p->mUnk_f0;
    func_02046be8(&p->mUnk_00.mUnk_80, data_0216befc, 6, p);
    func_02046bcc(&p->mUnk_00.mUnk_80, 5);
    func_020d7d4c(&p->mUnk_1a0, a, data_02158908, a->mUnk_28);
    func_020dbf7c(p);
}
#pragma thumb off

#pragma thumb on
void func_020dbf7c(Unk020dc474 *p) {
    p->mUnk_00.mPos = p->mUnk_a0;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    p->mUnk_c4 = data_0216beec;
    func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                          0x80000000000LL) >>
                         44),
                  &p->mUnk_d4);
    func_020d7938(&p->mUnk_c4, &p->mUnk_d4, &p->mUnk_b4);
    func_01ffccd0(&p->mUnk_00.mMatrix, &p->mUnk_b4);
    p->mUnk_e4 = 0;
    if (p->mUnk_fc == 0) {
        func_020de184((Unk020de000 *) p->mUnk_1d8);
    }
    if (p->mUnk_fc == 0) {
        p->mUnk_160[0] = &p->mUnk_170[0];
        p->mUnk_160[1] = &p->mUnk_170[1];
        p->mUnk_160[2] = &p->mUnk_170[2];
        p->mUnk_160[3] = &p->mUnk_170[3];
        if (data_021759c0->mUnk_00c == 3) {
            Vec3AddScaled(0xf000, &p->mUnk_200, &p->mUnk_00.mPos, &p->mUnk_00.mPos);
            p->mUnk_00.mUnk_10.x = (s32) (((s64) p->mUnk_200.x * 0x400) >> 12);
            p->mUnk_00.mUnk_10.y = (s32) (((s64) p->mUnk_200.y * 0x400) >> 12);
            p->mUnk_00.mUnk_10.z = (s32) (((s64) p->mUnk_200.z * 0x400) >> 12);
            func_020d7b34((u16) ((((s64) func_02148538(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z) * 0x28be60db9391LL) +
                                  0x80000000000LL) >>
                                 44),
                          &p->mUnk_d4);
            p->mUnk_00.mUnk_80.mNextState = 4;
            p->mUnk_00.mUnk_80.mNextStateRequested = 1;
        } else {
            p->mUnk_00.mUnk_80.mNextState = 0;
            p->mUnk_00.mUnk_80.mNextStateRequested = 1;
        }
    }
}
#pragma thumb off

Unk020d7b88 data_0216beec = {{0, 0, 0, 0x1000}};
Unk0210b7a8 data_0216bedc = {0x12d, NULL, 2, 0};
UnkFunc *data_0216befc[] = {func_020dd0d8, func_020dccc8, func_020dcc0c, func_020dc7c0, func_020dc788, func_020dc608,
                            func_020dc5dc, func_020dc474, func_020dc448, func_020dc444, func_020dc428, func_020dc354};
