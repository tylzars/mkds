#include "Main/Unknown/code_02024fc0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"

#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_02109054.h"
#include "code_02147cd8.h"

u32 func_020250a8(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_02161ae4;
    value0 = 0x1000u;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02161ae0;
    value2 = (u32) &data_02174e10;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02161adc;
    value2 = (u32) &data_02174e0c;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x1000u;
    value0 = (u32) func_02147f34((s32) value0, (s32) value1);
    value1 = (u32) &data_02174e08;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}

void func_0202506c(Unk0206bcb0 *a, Unk02024eec *b) {
    Unk0210bf24 *p;

    p = func_02109078(&a->mUnk_00, b->mUnk_00, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
    if (p != 0) {
        p->mUnk_19 |= 0x80;
    }
}

void func_02025030(Unk0206bcb0 *a, Unk02024eec *b) {
    Unk0210bf24 *p;

    p = func_02109078(&a->mUnk_00, b->mUnk_58, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
    if (p != 0) {
        p->mUnk_19 |= 0x80;
    }
}

void func_02024fe8(Unk0206bcb0 *a, Unk02024eec *b) {
    u32 v;

    v = func_0210bb74(3, a->mUnk_3e0, a->mUnk_3e4);
    func_02109078(&a->mUnk_00, v, b->mUnk_04, (b->mUnk_08 << 4) >> 16);
}

void func_02024fc0(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    value3 = (u32) * (const u32 *) ((value1) + (8));
    value2 = (u32) * (const u8 *) ((value1) + (4));
    compareLeft0 = value3;
    compareRight0 = 0x440000u;
    if ((s32) compareLeft0 > (s32) compareRight0) {
        value3 = 0x440000u;
    }
    value3 = (value3 << 4);
    value12 = (u32) &func_02109078;
    value1 = (u32) * (const u32 *) ((value1) + (92));
    value3 = ((u32) ((s32) value3 >> 16));
    func_02109078((Unk0210bfbc *) value0, value1, value2, value3);
}
