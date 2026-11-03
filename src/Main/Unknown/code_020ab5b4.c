#include "Main/Unknown/code_020ab058.h"
#include "Main/Unknown/code_020ab088.h"
#include "Main/Unknown/code_020ab5b4.h"

#include "Main/Unknown/code_020ab5bc.h"
#include "Main/Unknown/code_020ab5e4.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020ab660.h"
#include "Main/Unknown/code_020ab714.h"
#include "Main/Unknown/code_020ab72c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020a9ed8.h"
#include "Main/Unknown/code_020a9f40.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab194.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_020aba9c.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214d018.h"

#pragma thumb on

void func_020aba9c(void) {
    func_0200ee74(data_0217b334->mUnk_04, data_0217b334->mUnk_0c);
    func_0214bc34(data_0217b334->mUnk_04, 0, data_0217b334->mUnk_0c);
    func_0200ee74(data_0217b334->mUnk_00, data_0217b334->mUnk_08);
    func_0214b8f4(data_0217b334->mUnk_00, 0, data_0217b334->mUnk_08);
    return;
}

#pragma thumb off

#pragma thumb on
void func_020aba94(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ab07c;
    func_020ab07c(value0);
}
#pragma thumb off

#pragma thumb on

void func_020ab9d0(u32 a) {
    switch (a) {
        case 0:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 1:
            func_020a9ff4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 2:
            func_020a9fc4(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 3:
            func_020a9f98(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 4:
            func_020a9f6c(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
        case 5:
            func_020a9f40(data_0217b334->mUnk_28[a], data_0217b334->mUnk_10[a], data_usa_021567fc[a]);
            break;
    }
    data_0217b334->mUnk_4c = a;
}

void func_020ab94c(s32 a, s32 b) {
    data_0217b334->mUnk_50 = a;
    data_0217b334->mUnk_54 = b;
    func_020ab194(data_0217b334->mUnk_50, data_0217b334->mUnk_54);
    *(vu32 *) 0x4001018 = (-data_0217b334->mUnk_50 & 0x1ff) | ((-data_0217b334->mUnk_54 << 16) & 0x1ff0000);
    func_020a9efc(data_0217b334->mUnk_50 + data_0217b334->mUnk_58, data_0217b334->mUnk_54 + data_0217b334->mUnk_5c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_60, data_0217b334->mUnk_54 + data_0217b334->mUnk_64);
    func_020a9ed8(data_0217b334->mUnk_50 + data_0217b334->mUnk_68, data_0217b334->mUnk_54 + data_0217b334->mUnk_6c,
                  data_0217b334->mUnk_50 + data_0217b334->mUnk_70, data_0217b334->mUnk_54 + data_0217b334->mUnk_74);
}

#pragma thumb off

#pragma thumb on

void func_020ab910(u32 a, u32 b, u32 c, u32 d) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_58 = a;
    (*v1)->mUnk_5c = b;
    (*v1)->mUnk_60 = c;
    (*v1)->mUnk_64 = d;
    v2 = *v1;
    func_020a9efc((u32) (v2->mUnk_50 + v2->mUnk_58), (u32) (v2->mUnk_54 + v2->mUnk_5c),
                  (u32) (v2->mUnk_50 + v2->mUnk_60), (u32) (v2->mUnk_54 + v2->mUnk_64));
}

void func_020ab8d4(u32 a, u32 b, u32 c, u32 d) {
    Unk0217b334 **v1;
    Unk0217b334 *v2;
    v1 = &data_0217b334;
    data_0217b334->mUnk_68 = a;
    (*v1)->mUnk_6c = b;
    (*v1)->mUnk_70 = c;
    (*v1)->mUnk_74 = d;
    v2 = *v1;
    func_020a9ed8((u32) (v2->mUnk_50 + v2->mUnk_68), (u32) (v2->mUnk_54 + v2->mUnk_6c),
                  (u32) (v2->mUnk_50 + v2->mUnk_70), (u32) (v2->mUnk_54 + v2->mUnk_74));
}

#pragma thumb off

#pragma thumb on

void func_020ab8cc(u16 a) {
    func_020a9ea0(a);
}

u32 func_020ab8c4(void) {
    return func_020a9e90();
}

#pragma thumb off

#pragma thumb on

void func_020ab848(s32 *a, s32 *b, s32 *c, s32 *d) {
    s32 value;
    func_020ab11c(a, b, c, d);
    *a = *a - data_0217b334->mUnk_50;
    *b = *b - data_0217b334->mUnk_54;
    *c = *c - data_0217b334->mUnk_50;
    *d = *d - data_0217b334->mUnk_54;
    value = *a;
    if (value < 0) {
        value += 0x100;
    }
    *a = value;
    value = *b;
    if (value < 0) {
        value += 0x100;
    }
    *b = value;
    value = *c;
    if (value < 0) {
        value += 0x100;
    }
    *c = value;
    value = *d;
    if (value < 0) {
        value += 0x100;
    }
    *d = value;
}

#pragma thumb off

#pragma thumb on

void func_020ab7a4(const u16 *a) {
    s32 i;

    for (i = 0; i < data_0217b334->mUnk_44; i++) {
        data_0217b334->mUnk_40[i] = 0;
    }
    for (i = 0; i < data_0217b334->mUnk_4a; i++) {
        data_0217b334->mUnk_40[i] = *a;
        if (*a == 0) {
            data_0217b334->mUnk_46 = i;
            data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
            return;
        }
        a++;
    }
    data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
    data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
    data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
}

#pragma thumb off

#pragma thumb on

u16 *func_020ab798(void) {
    return data_0217b334->mUnk_40;
}

#pragma thumb off

#pragma thumb on

void func_020ab758(u16 a) {
    data_0217b334->mUnk_4a = a;
    if (data_0217b334->mUnk_46 >= data_0217b334->mUnk_4a - 1) {
        data_0217b334->mUnk_46 = data_0217b334->mUnk_4a - 1;
        data_0217b334->mUnk_48 = data_0217b334->mUnk_46;
        data_0217b334->mUnk_40[data_0217b334->mUnk_4a] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u16 func_020ab748(void) {
    return data_0217b334->mUnk_46;
}

#pragma thumb off

#pragma thumb on

void func_020ab72c(void) {
    func_0214d05c_inline(&data_0217b2d8, 0x28);
}

#pragma thumb off

#pragma thumb on

void func_020ab714(void) {
    func_020ab72c();
    data_0217b2d8.mUnk_24 = 1;
}

#pragma thumb off

#pragma thumb on

void func_020ab660(u16 a, volatile Unk0214e334_b b) {
    u32 t;
    u16 v;

    t = a ^ data_0217b2d8.mUnk_06;
    data_0217b2d8.mUnk_04 = a & t;
    data_0217b2d8.mUnk_08 = ~a & t;
    data_0217b2d8.mUnk_06 = a;
    if ((data_0217b2d8.mUnk_06 & data_0217b2d8.mUnk_0a) != 0) {
        data_0217b2d8.mUnk_00++;
    } else {
        data_0217b2d8.mUnk_00 = 0;
    }
    if (data_0217b2d8.mUnk_24 != 0) {
        if (b.mUnk_06 != 0) {
            b.mUnk_00 = data_0217b2d8.mUnk_0c[0];
            b.mUnk_02 = data_0217b2d8.mUnk_0c[1];
            b.mUnk_04 = data_0217b2d8.mUnk_0c[2];
            b.mUnk_06 = data_0217b2d8.mUnk_0c[3];
            b.mUnk_04 = 0;
        }
        v = b.mUnk_04;
        if (v != data_0217b2d8.mUnk_0c[2]) {
            data_0217b2d8.mUnk_1c = v != 0 ? 1 : 3;
            data_0217b2d8.mUnk_18 = 0;
        } else if (v != 0) {
            data_0217b2d8.mUnk_1c = 2;
            data_0217b2d8.mUnk_18++;
        } else {
            data_0217b2d8.mUnk_1c = 0;
        }
        if (v != 0) {
            data_0217b2d8.mUnk_14 = b.mUnk_00;
            data_0217b2d8.mUnk_16 = b.mUnk_02;
        }
        data_0217b2d8.mUnk_20 = v;
        data_0217b2d8.mUnk_0c[0] = b.mUnk_00;
        data_0217b2d8.mUnk_0c[1] = b.mUnk_02;
        data_0217b2d8.mUnk_0c[2] = b.mUnk_04;
        data_0217b2d8.mUnk_0c[3] = b.mUnk_06;
    }
}

#pragma thumb off

#pragma thumb on
u32 func_020ab650(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b2d8;
    value1 = (u32) * (const u16 *) ((value1) + 4u);
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab640(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b2d8;
    value1 = (u32) * (const u16 *) ((value1) + 6u);
    value1 = (value1) & (value0);
    value0 = (value1) + (0u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab634(void) {
    u32 value0;
    value0 = (u32) &data_0217b2d8;
    value0 = (u32) * (const u16 *) ((value0) + 32u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab628(void) {
    u32 value0;
    value0 = (u32) &data_0217b2d8;
    value0 = (u32) * (const u32 *) ((value0) + 28u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab61c(void) {
    u32 value0;
    value0 = (u32) &data_0217b2d8;
    value0 = (u32) * (const u16 *) ((value0) + 20u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab610(void) {
    u32 value0;
    value0 = (u32) &data_0217b2d8;
    value0 = (u32) * (const u16 *) ((value0) + 22u);
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_020ab604(void) {
    u32 value0;
    value0 = (u32) &data_0217b2d8;
    value0 = (u32) * (const u32 *) ((value0) + 36u);
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_020ab5f4(Unk0217b278_34 *p0) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
    p0->mUnk_02 = (u16) 0x28u;
    p0->mUnk_04 = (u16) 0x2du;
}

void func_020ab5e4(Unk0217b278_34 *p0, u32 p1, u32 p2) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
    p0->mUnk_02 = (u16) p1;
    p0->mUnk_04 = (u16) (((p1) + (p2)));
}

#pragma thumb off

#pragma thumb on

void func_020ab5bc(Unk0217b278_34 *p) {
    p->mUnk_00 = p->mUnk_00 + 1;
    if (p->mUnk_00 == p->mUnk_02 || p->mUnk_00 == p->mUnk_04) {
        p->mUnk_06 = 1;
    }
    if (p->mUnk_00 > p->mUnk_04) {
        p->mUnk_00 = p->mUnk_02 + 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_020ab5b4(Unk0217b278_34 *p0) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_06 = (u16) 0x0u;
}

#pragma thumb off
