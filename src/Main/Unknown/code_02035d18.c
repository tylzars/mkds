#include "Main/Unknown/code_02035d18.h"
#include "registers.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02108c1c.h"

#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02035e44.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"

void func_02035e38(void) {
    u32 value12;
    value12 = (u32) &func_02108d80;
    func_02108d80();
}

void func_02035e30(u32 p0, u32 p1) {
    *(u16 *) ((u8 *) p0 + 4) = (u16) p1;
}

#pragma thumb on

s32 func_02035db4(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mUnk_64c) {
        case 9:
            r = func_020591bc();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    data_02174e6c->mUnk_64c = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (a != 0) {
                func_02035e30(a, 1);
            }
            data_02174e6c->mUnk_64c = 11;
            break;
    }
    o = data_02174e6c;
    o->mUnk_640 = (o->mUnk_640 + 1) % 0x100;
    return -1;
}

#pragma thumb off

#pragma thumb on

void func_02035d90(void) {
    func_02036ab0((void *) (data_02174e6c->mUnk_650));
    *(int *) &data_02174e6c = 0;
}

#pragma thumb off

void func_02035d74(int arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
}

void func_02035d48(u32 a, int b) {
    reg_G2S_DB_BG3OFS = (a & 0x1ff) | ((b << 16) & 0x01ff0000);
}

#pragma thumb on

void func_02035d20(void) {
    func_02035d74(10);
    func_02035d48((u32) (-data_02174e6c->mUnk_640), 0);
}

#pragma thumb off

#pragma thumb on
void func_02035d18(void) {
    u32 value3;
    value3 = (u32) &func_02035d20;
    func_02035d20();
}
#pragma thumb off
