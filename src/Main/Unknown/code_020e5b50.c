#include "Main/Unknown/code_020e5b50.h"

#include "Main/Unknown/code_020e5b88.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e5c6c.h"

void func_020e5c6c(u32 a, Unk020e43a8 *b, u32 c, u16 d) {
    Unk02012f58 *v1;
    data_0217b830->mUnk_18 = (short) ((int) (*(u16 *) &b->mUnk_a0.mUnk_18.x & 0x10) >> 4);
    if (b->mUnk_00.mUnk_80.mUnk_0e == 0) {
        v1 = func_020e6cbc(&b->mUnk_00.mUnk_04);
        func_020e67c4(data_0217b830, v1, &b->mUnk_00.mUnk_1c, 0, d);
        return;
    }
    v1 = func_020e6cbc(&b->mUnk_00.mUnk_04);
    func_020e66e4(data_0217b830, v1, *(u16 *) &b->mUnk_a0.mUnk_0c.x, &b->mUnk_00.mUnk_1c, 0, d);
}

void func_020e5bd4(u32 a, Unk020e43a8 *p) {
    Unk0210b7a8 s;
    s32 n;

    *(u16 *) &p->mUnk_a0.mUnk_18 = *(u16 *) &p->mUnk_a0.mUnk_18 + 1;
    if ((*(u16 *) &p->mUnk_a0.mUnk_18 & 0x1f) == 0 && (p->mUnk_00.mUnk_78 & 4) == 0) {
        if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
            n = 2;
        } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
            n = 3;
        } else {
            n = 4;
        }
        s.mUnk_00 = 0x163;
        s.mUnk_04 = &p->mUnk_00.mUnk_04;
        s.mUnk_08 = n;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mUnk_04);
        func_0210b7a8(&s);
    }
    func_02046b40(&p->mUnk_00.mUnk_80);
}

u8 func_020e5ba0(Unk020e43a8 *p, void *a, u8 *b, u8 *c) {
    if (func_020ec450(p, a, b) != 0) {
        func_020d26f8(&p->mUnk_00, a);
    }
    return *c;
}

u8 func_020e5b88(Unk020e43a8 *p, void *a, u8 *b, u8 *c) {
    func_020ec41c(p, a, b);
    return *c;
}

#pragma thumb on

void func_020e5b50(void) {
    u32 v1;
    u32 v2;
    v1 = (u32) func_020d21ec((const char *) data_0216c274);
    v2 = (u32) func_020d21ec((const char *) data_0216c288);
    func_020e6488((Unk020e6488 **) (((u32 *) &data_0217b830)), (void *) v1, v2, (u32) 0);
    func_020e6ab8((Unk020e6488 *) data_0217b830);
}

#pragma thumb off
