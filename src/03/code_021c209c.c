#include "03/code_021c209c.h"

#include "03/code_021d3000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d2d14.h"
#include "03/code_021d2d50.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"
#include "Main/Unknown/code_02148000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c2b28.h"
#include "03/code_021d3278.h"
#include "Main/Unknown/code_02000000.h"
#include "code_0200f6e4.h"
#include "code_0200fb18.h"
#include "code_0200fd1c.h"
#include "code_02004dc0.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "code_02148a10.h"
#include "code_02148a58.h"
#include "code_02148d34.h"
#include "code_0214a390.h"
#include "code_0214d964.h"
#include "code_0214e6e4.h"
#include "code_021519d4.h"

s32 func_ov003_021c2494(void *a, s32 b, u32 c) {
    data_ov003_021da174 = a;
    if (func_ov003_021c2440(b, c) == 0) {
        return -1;
    }
    data_ov003_021da170[0] = 0;
    func_ov003_021c2398();
    func_ov003_021c2188();
    func_ov003_021cdc4c();
    func_ov003_021c212c(func_ov003_021c2b28);
    do {
        func_ov003_021d2d14();
        data_ov003_021da17c();
        func_ov003_021d3558(0);
        func_ov003_021d28e0();
        func_ov003_021d3278();
        VBlankIntrWait();
    } while (data_ov003_021da170[0] == 0);
    func_ov003_021c2138();
    return 0;
}

u32 func_ov003_021c2440(s32 a, u32 b) {
    data_ov003_021da16c[0] = a;
    *(u32 *) &data_ov003_021da178 = b;
    if (a < 0 || a > 5) {
        return 0;
    }
    if ((u32) (b << 28) >> 28 > 1) {
        return 0;
    }
    if (a != 0 && ((b >> 4) & 1) != 0) {
        return 0;
    }
    if (a == 0 && ((*(u32 *) &data_ov003_021da178 >> 4) & 1) == 0) {
        return 0;
    }
    return 1;
}

void func_ov003_021c2398(void) {
    u8 *p;
    u16 q = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    func_02148a10();
    *(u32 *) 0x4001000 &= 0xfffeffff;
    if (func_0200f6e4() == 0) {
        func_0200fd1c();
    }
    if (func_0200fb18() == 0) {
        func_0200fd1c();
    }
    func_02148a58(0);
    func_02148904();
    func_02004dc0(-1);
    func_0214eb88();
    func_0214e0f4();
    func_02148a10();
    *(u32 *) 0x4001000 &= 0xfffeffff;
    func_ov003_021d3408();
    func_ov003_021d28b0(data_ov003_021da174);
    func_ov003_021d2dfc();
    func_ov003_021d35f4();
    func_ov003_021d1654();
    func_ov003_021d2d50();
    func_ov003_021d1f98();
    p = func_ov003_021d285c(0x700, 0x20);
    func_02151b38(p);
    func_ov003_021d2808(&p);
}

void func_ov003_021c2188(void) {
    volatile u32 *p;
    volatile u16 *q;
    func_02148a58(0);
    func_02149b20(1);
    func_021499b4(2);
    func_02148950(1, 0, 0);
    p = (u32 *) 0x4000000;
    *p = *p & 0xffffe0ff;
    func_02148908((u16 *) 0x400006c, 0);
    *(u32 *) 0x4000000 = (*(u32 *) 0x4000000 & 0xffcfffef) | 0x200010;
    *(u16 *) 0x4000008 &= ~0x40;
    *(u16 *) 0x400000a &= ~0x40;
    *(u16 *) 0x400000c &= ~0x40;
    *(u16 *) 0x400000e &= ~0x40;
    *(u32 *) 0x4000010 = 0;
    *(u32 *) 0x4000014 = 0;
    *(u32 *) 0x4000018 = 0;
    *(u32 *) 0x400001c = 0;
    func_0214a3e8((u16 *) 0x4000050, 0x3f, 0x10);
    func_0214922c(0x80);
    func_021491b0(0x100);
    func_02148934(0);
    p = (u32 *) 0x4001000;
    *p = *p & 0xffffe0ff;
    func_02148908((u16 *) 0x400106c, 0);
    *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffcfffef) | 0x10;
    *(u16 *) 0x4001008 &= ~0x40;
    *(u16 *) 0x400100a &= ~0x40;
    *(u16 *) 0x400100c &= ~0x40;
    *(u16 *) 0x400100e &= ~0x40;
    *(u32 *) 0x4001010 = 0;
    *(u32 *) 0x4001014 = 0;
    *(u32 *) 0x4001018 = 0;
    *(u32 *) 0x400101c = 0;
    func_0214a3e8((u16 *) 0x4001050, 0x3f, 0x10);
    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & 0x43) | 0xc00;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & 0x43) | 0xd08;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & 0x43) | 0xe10;
    *(u16 *) 0x400000e = (*(u16 *) 0x400000e & 0x43) | 0xf10;
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & 0x43) | 0xc00;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & 0x43) | 0xd00;
    *(u16 *) 0x400100c = (*(u16 *) 0x400100c & 0x43) | 0xe00;
    *(u16 *) 0x400100e = (*(u16 *) 0x400100e & 0x43) | 0xf00;
    q = (u16 *) 0x4000304;
    *q = *q & ~0x8000;
    func_ov003_021d2490();
    func_ov003_021d2fdc();
    func_ov003_021d31b0();
    func_ov003_021d1b3c();
    func_021489c4();
    *(u32 *) 0x4001000 = *(u32 *) 0x4001000 | 0x10000;
    func_02148a58(1);
}

void func_ov003_021c2138(void) {
    func_02148a10();
    *((u32 *) 0x04001000u) = *((u32 *) 0x04001000u) & ((u32) 0xfffeffffu);
    func_ov003_021d326c();
    func_ov003_021d2d28();
    func_ov003_021d2dcc();
    func_ov003_021cdc28();
    func_ov003_021d1af0();
    func_ov003_021d2f78();
    func_ov003_021d244c();
    func_ov003_021d1f88();
    func_ov003_021d15f4();
    func_ov003_021d35c0();
    func_ov003_021d2894();
    func_ov003_021d332c();
    return;
}

void func_ov003_021c212c(void (*callback)(void)) {
    data_ov003_021da17c = callback;
}

void func_ov003_021c2120(u32 param_1, u32 param_2) {
    u32 *v1;
    v1 = (u32 *) &data_ov003_021da180;
    *(u32 *) &data_ov003_021da180 = param_1;
    v1[1] = param_2;
    return;
}

void func_ov003_021c2104(s32 *first, s32 *second) {
    if (first != 0) {
        *first = data_ov003_021da180[0];
    }
    if (second != 0) {
        *second = data_ov003_021da180[1];
    }
}

void func_ov003_021c20f8(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_ov003_021da180;
    *(u32 *) ((value2) + 8u) = value0;
    *(u32 *) ((value2) + 12u) = value1;
    return;
}

void func_ov003_021c20dc(s32 *first, s32 *second) {
    if (first != 0) {
        *first = data_ov003_021da180[2];
    }
    if (second != 0) {
        *second = data_ov003_021da180[3];
    }
}

u8 func_ov003_021c20d0(void) {
    return *(u8 *) &data_ov003_021da16c;
}

u32 func_ov003_021c20c0(void) {
    return data_ov003_021da178.mUnk_00;
}

u32 func_ov003_021c20a8(u32 param_1) {
    if (((*(u32 *) &data_ov003_021da178) >> 4 & param_1) != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c209c(void) {
    *(u8 *) &data_ov003_021da170 = 1;
    return;
}
