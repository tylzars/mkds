#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_021053e4.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020de000.h"
#include "Main/Unknown/unk_021759c0.h"

Unk0215a680 data_0215a680 = {{0, 0, 0, 0xf000, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0}};

u32 func_02105504(void) {
    u32 r = 0;
    u32 f;
    if (func_0205e0a0() == 2) {
        s32 a = data_021759c0->mUnk_00c;
        f = 1;
        if (a != 0 && a != 2) {
            f = 0;
        }
        if (f != 0) {
            r = 1;
        }
    }
    return r;
}

u32 func_021054d0(void) {
    u32 r = 0;
    s32 a = data_021759c0->mUnk_08;
    if (a != 4) {
        return r;
    }
    a = a == 4 ? data_021759c0->mMissionTableColumn : -1;
    if (a == 9) {
        r = 1;
    }
    return r;
}

Unk0215a680 *func_02105480(void) {
    Unk0215a680 *p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_0215a680;
    return p;
}

void func_02105464(void *p, void *q) {
    func_020de6a8(p, q);
    func_020d2398(p);
}

u32 func_0210543c(void) {
    u32 i = data_0217c728;
    u32 *t = data_0217c72c;
    data_0217c728 = i + 1;
    return t[i];
}

void func_021053e4(Unk021052fc *p) {
    func_020d233c(&p->mUnk_00);
    p->mUnk_00.mUnk_66 = 0x1f;
    p->mUnk_00.mUnk_02 &= ~2;
    p->mUnk_00.mUnk_02 &= ~8;
    p->mUnk_00.mUnk_66 = 0x1f;
    p->mUnk_00.mUnk_1c.x = 0;
    p->mUnk_00.mUnk_1c.y = 0;
    p->mUnk_00.mUnk_1c.z = 0;
    p->mUnk_a0 = 0;
    p->mUnk_a2 = 0;
    p->mUnk_a4 = 0x80;
}
