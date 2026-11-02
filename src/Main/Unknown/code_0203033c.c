#include "Main/Unknown/code_0203033c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02030708.h"
#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02174000.h"

u32 func_02030700(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0));
}

u32 func_020306e0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_02030700;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_02030700(value0);
    return value0;
}

u32 func_020306d8(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 2));
}

u32 func_020306b8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020306d8;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020306d8(value0);
    return value0;
}

u16 func_020306a4(Unk02175628 *a, u32 b) {
    return a->mUnk_00 & b;
}

u32 func_02030688(u32 a, u32 b) {
    return func_020306a4(&data_02175628[a], b);
}

void func_02030654(u32 a) {
    func_0212d5e0((Unk0212d5f8 *) (((u32) (&data_0217c868))));
    func_0203063c(a, (u32) 0);
    func_0212d5e0((Unk0212d5f8 *) (((u32) (&data_0217d0a0))));
}

void func_0203063c(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_0212ecc0;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value0 = (u32) func_0212ecc0((const void *) value0, value1, value2);
}

void func_0203062c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value12;
    value12 = (u32) &func_0203063c;
    value1 = 0u;
    func_0203063c(value0, value1);
}

#pragma thumb on

s32 func_020303e8(void) {
    Unk02174e54 *o;
    s32 r;
    s32 a;
    s32 b;
    s32 c;
    u16 i;

    r = -1;
    i = func_020435bc();
    o = data_02174e54;
    switch (o->mUnk_30) {
        case 0:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 < 10) {
                data_02174e54->mUnk_38 = func_020ae4c0(1, -0xc0, 0, data_02174e54->mUnk_34, 10);
            } else {
                data_02174e54->mUnk_34 = 0;
                data_02174e54->mUnk_38 = 0;
                data_02174e54->mUnk_30 = 1;
            }
            func_020309d8();
            break;
        case 1:
            a = 0;
            b = -1;
            if (func_02030708(i) != 0) {
                b = func_020306e0(i);
                c = func_020306b8(i);
                a = func_02128210(b, c);
                b = func_020291c4(b, c, o->mUnk_10);
            }
            if (func_02030688(i, 1) != 0) {
                func_0204aa28(data_02174e54->mUnk_28 == 1 ? 1 : 0);
                data_02174e54->mUnk_2c = 2;
                data_02174e54->mUnk_30 = 2;
                func_02030954(0);
                func_02030654(4);
            } else if (func_02030688(i, 2) != 0 || a != 0) {
                data_02174e54->mUnk_2c = 0;
                data_02174e54->mUnk_30 = 3;
                func_02128310(0);
            } else if (func_02030688(i, 0x40) != 0 && data_02174e54->mUnk_28 > 0) {
                data_02174e54->mUnk_28--;
                func_02030954(1);
                func_0203062c(0);
            } else if (func_02030688(i, 0x80) != 0 && data_02174e54->mUnk_28 < 1) {
                data_02174e54->mUnk_28++;
                func_02030954(1);
                func_0203062c(0);
            } else if (b == 0) {
                data_02174e54->mUnk_30 = 2;
                func_02030954(data_02174e54->mUnk_28 != 0 ? 1 : 0);
                func_02030654(4);
                data_02174e54->mUnk_28 = 0;
                func_0204aa28(0);
                data_02174e54->mUnk_2c = 2;
            } else if (b == 1) {
                data_02174e54->mUnk_30 = 2;
                func_02030954(data_02174e54->mUnk_28 != 1 ? 1 : 0);
                func_02030654(4);
                data_02174e54->mUnk_28 = 1;
                func_0204aa28(1);
                data_02174e54->mUnk_2c = 2;
            }
            break;
        case 2:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 >= 5) {
                data_02174e54->mUnk_34 = 0;
                data_02174e54->mUnk_30 = 3;
                func_02030954(1);
            }
            break;
        case 3:
            o->mUnk_34++;
            if (data_02174e54->mUnk_34 < 10) {
                data_02174e54->mUnk_38 = func_020ae4c0(1, 0, -0xc0, data_02174e54->mUnk_34, 10);
            } else {
                data_02174e54->mUnk_38 = 0;
                data_02174e54->mUnk_30 = 4;
            }
            func_020309d8();
            break;
        case 4:
            r = o->mUnk_2c;
            break;
    }
    if (data_02174e54->mUnk_30 != 4) {
        func_02124c30(o->mUnk_0c, o->mUnk_08, o->mUnk_14, data_02174e54->mUnk_20, o->mUnk_18);
    }
    return r;
}

#pragma thumb off

#pragma thumb on

void func_020303c4(void) {
    func_0204f7f4();
    func_02036ab0((void *) (data_02174e54->mUnk_3c));
    data_02174e54 = 0;
    return;
}

#pragma thumb off

u32 func_020303a8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_0203038c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_02030364(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x4001048u;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x4001048u;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}

u32 func_0203033c(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x400104au;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x400104au;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}
