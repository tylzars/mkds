#include "Main/Unknown/code_02035d18.h"

#include "registers.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0203606c.h"
#include "Main/Unknown/code_020360e4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "00/code_02181f98.h"

void func_02036058(u32 p0) {
    data_0217b488->mUnk_04 = p0;
}

void func_02036044(u32 p0) {
    data_0217b488->mUnk_08 = p0;
}

#pragma thumb on

s32 func_02035f5c(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mState) {
        case 0:
            if (func_0205579c(0, 1) == 1) {
                data_02174e6c->mState = 2;
            }
            break;
        case 2:
            r = func_02055730(0);
            switch (r) {
                case 1:
                    func_0204aa28(func_020360e4());
                    data_02174e6c->mState = 4;
                    break;
                case 2:
                    break;
            }
            break;
        case 4:
            r = func_02058cac();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    func_0205e5c4(1);
                    data_02174e6c->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            if (func_0203606c() == 0) {
                func_02036058(1);
                func_02036044(4);
                if (a != 0) {
                    func_02035e30(a, 1);
                }
                data_02174e6c->mState = 11;
            }
            break;
    }
    o = data_02174e6c;
    o->mBg3Offset = (o->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 func_02035ee0(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mState) {
        case 9:
            r = func_020591c4();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    data_02174e6c->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (a != 0) {
                func_02035e30(a, 2);
            }
            data_02174e6c->mState = 11;
            break;
    }
    o = data_02174e6c;
    o->mBg3Offset = (o->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 func_02035e64(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mState) {
        case 9:
            r = func_02058f20();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    data_02174e6c->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (a != 0) {
                func_02035e30(a, 10);
            }
            data_02174e6c->mState = 11;
            break;
    }
    o = data_02174e6c;
    o->mBg3Offset = (o->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

u32 func_02035e44(void) {
    return data_0217aa00->mUnk_0457 != 0;
}

void func_02035e38(void) {
    u32 value12;
    func_02108d80();
}

void func_02035e30(u32 p0, u32 p1) {
    *OFFSET_PTR(u16, p0, 4) = p1;
}

#pragma thumb on

s32 func_02035db4(u32 a) {
    s32 r;
    Unk02174e6c *o;

    switch (data_02174e6c->mState) {
        case 9:
            r = func_020591bc();
            switch (r) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    data_02174e6c->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (a != 0) {
                func_02035e30(a, 1);
            }
            data_02174e6c->mState = 11;
            break;
    }
    o = data_02174e6c;
    o->mBg3Offset = (o->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

#pragma thumb on

void func_02035d90(void) {
    HeapDestroy(data_02174e6c->mHeap);
    *&data_02174e6c = NULL;
}

#pragma thumb off

void WriteSubDispcntBits(int arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = *(const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
}

void WriteSubBg3Offset(u32 a, int b) {
    reg_G2S_DB_BG3OFS = (a & 0x1ff) | ((b << 16) & 0x01ff0000);
}

#pragma thumb on

void func_02035d20(void) {
    WriteSubDispcntBits(10);
    WriteSubBg3Offset(-data_02174e6c->mBg3Offset, 0);
}

#pragma thumb off

#pragma thumb on
void func_02035d18(void) {
    u32 value3;
    func_02035d20();
}
#pragma thumb off
