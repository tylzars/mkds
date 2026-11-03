#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020e595c.h"

#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_020ea000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec884.h"

#pragma thumb on

void func_020e5aec(Unk020e43a8 *p) {
    p->mUnk_00.mUnk_04.y = p->mUnk_00.mUnk_04.y + (s32) (((s64) p->mUnk_00.mUnk_1c.y * 0xa000) >> 12);
    *(u16 *) &p->mUnk_a0.mUnk_18.x = 0;
    func_020ec854(p, p->mUnk_00.mUnk_04.y - 0x18000, 0x400, 0x800, 0x4000, 0x1800);
    func_020ec884(p);
}

#pragma thumb off

Unk020e5a9c *func_020e5a9c(void) {
    Unk020e5a9c *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = *(Unk020e5a9c *) data_02159140;
    return p;
}

Unk020e5a40 *func_020e5a40(void) {
    Unk020e5a40 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217b824 = p;
    *p = *(Unk020e5a40 *) data_02159114;
    func_020d49d8(&data_0217b824);
    return data_0217b824;
}

Unk020e59e4 *func_020e59e4(void) {
    Unk020e59e4 *p;
    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b81c = p;
    *p = *(Unk020e59e4 *) data_021590ec;
    func_020e6f50(&data_0217b81c);
    return data_0217b81c;
}

void func_020e5990(u32 a, Unk020e43a8 *p, u32 b, u32 c) {
    p->mUnk_00.mUnk_28.mUnk_00[3].x = p->mUnk_00.mUnk_04.x >> 4;
    p->mUnk_00.mUnk_28.mUnk_00[3].y = p->mUnk_00.mUnk_04.y >> 4;
    p->mUnk_00.mUnk_28.mUnk_00[3].z = p->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(gSecondHand, &p->mUnk_00.mUnk_28, &p->mUnk_00.mUnk_1c, c);
}

void func_020e595c(u32 a, Unk020e43a8 *p) {
    func_02046b40(&p->mUnk_00.mUnk_80);
    func_020d77e0(&p->mUnk_a0.mUnk_0c.y, p->mUnk_00.mUnk_7e, &p->mUnk_a0);
    func_01ffccd0(&p->mUnk_00.mUnk_28, &p->mUnk_a0);
}
