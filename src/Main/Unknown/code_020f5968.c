#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f5968.h"

#include "Main/Unknown/code_020f5978.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f5b74.h"
#include "Main/Unknown/code_020f5b84.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f5d00.h"
#include "Main/Unknown/code_020f5d5c.h"

void func_020f5d5c(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_02046b40;
    value0 = (value0) + (0x23cu);
    func_02046b40((void *) value0);
}

void func_020f5d00(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
}

void func_020f5cc4(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 compareLeft0;
    u32 compareRight0;
    value4 = value0;
    value3 = (u32) * (const s16 *) ((value4) + (218));
    value2 = ~(0u);
    compareLeft0 = value3;
    compareRight0 = value2;
    if ((u32) compareLeft0 == (u32) compareRight0) {
    }
    if ((u32) compareLeft0 == (u32) compareRight0) {
        return;
    }
    func_020f1150(value0, value1);
    value0 = (value4) + (0x200u);
    value1 = 4u;
    *(u16 *) ((value0) + (76)) = (u16) value1;
    value1 = 1u;
    *(u16 *) ((value0) + (78)) = (u16) value1;
}

void func_020f5b84(Unk020f5d6c *a) {
    func_020f2228(&a->mUnk_000.mUnk_000, 0x8800);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x10) {
        if (func_020f11f0((u32) a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 4) {
        if (func_020f1180(a, 0) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}

void func_020f5b74(u32 p0) {
    *(u32 *) ((u8 *) p0 + 292) = (u32) (((u32) (&func_020f5f7c)));
}

void func_020f5978(Unk020f5d6c *a) {
    u16 x;
    u16 v;
    u16 n;

    x = (u16) (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & 0x8000)
                   ? (u16) (a->mUnk_000.mUnk_000.mUnk_000.mUnk_78 & ~0xff00)
                   : 8);
    if (x >= 8) {
        v = 8;
    } else {
        n = (u16) (func_0203c8dc(x) - 1);
        if (n < 1) {
            n = data_021759c0->mKartCount;
        }
        v = (u16) data_0217561c->mUnk_474[(u8) n - 1];
    }
    func_020ec918(&a->mUnk_000, 0xd000, 0x29, v, 0);
    if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1)) {
        func_0210ddf4(&data_0217d294, a->mUnk_000.mUnk_000.mUnk_000.mUnk_d4 & ~0xc000001f, func_020f5fb8, a, 0);
    }
    if (a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 1) {
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x708) {
        func_020f29e8((u32) a);
        a->mUnk_23c.mUnk_10 = 1;
        a->mUnk_23c.mUnk_12 = 1;
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 0x10) {
        if (func_020f11f0((u32) a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
        return;
    }
    if (a->mUnk_23c.mUnk_04 > 4) {
        if (func_020f1180(a, 1) == 0) {
            return;
        }
        a->mUnk_23c.mUnk_10 = 4;
        a->mUnk_23c.mUnk_12 = 1;
        if (!(a->mUnk_000.mUnk_000.mUnk_000.mUnk_74 & 0x8000000)) {
            return;
        }
        func_020fe71c(1, a->mUnk_228->mUnk_1f8, a->mUnk_000.mUnk_000.mUnk_000.mUnk_4e);
    }
}

void func_020f5968(u32 p0) {
    *(u32 *) ((u8 *) p0 + 292) = (u32) (((u32) (&func_020f5f7c)));
}
