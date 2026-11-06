#include "03/code_021c209c.h"
#include "registers.h"

#include "03/code_021d1440.h"
#include "03/code_021d197c.h"
#include "03/code_021d3000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d2940.h"
#include "03/code_021d2d50.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d326c.h"
#include "03/code_021d3298.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"
#include "Main/Unknown/code_02148000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c2b28.h"
#include "03/code_021d3278.h"
#include "Main/Unknown/code_02000000.h"
#include "code_0200f5ac.h"
#include "code_0200f790.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214d93c.h"
#include "code_0214e308.h"
#include "code_021519d4.h"
#include "03/code_021d28e0.h"

s32 func_ov003_021c2494(void *a, s32 b, u32 c) {
    data_ov003_021da174 = a;
    if (func_ov003_021c2440(b, c) == 0) {
        return -1;
    }
    data_ov003_021da170[0] = 0;
    func_ov003_021c2398();
    func_ov003_021c2188();
    CreateSoundData();
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
    u16 q = reg_OS_IME;
    reg_OS_IME = 0;
    GX_DispOff();
    reg_GXS_DB_DISPCNT &= 0xfffeffff;
    if (OS_IsTickAvailable() == 0) {
        OS_Terminate();
    }
    if (OS_IsAlarmAvailable() == 0) {
        OS_Terminate();
    }
    GX_VBlankIntr(0);
    func_02148904();
    FS_Init(-1);
    TP_Init();
    RTC_Init();
    GX_DispOff();
    reg_GXS_DB_DISPCNT &= 0xfffeffff;
    func_ov003_021d3408();
    func_ov003_021d28b0(data_ov003_021da174);
    func_ov003_021d2dfc();
    func_ov003_021d35f4();
    func_ov003_021d1654();
    func_ov003_021d2d50();
    func_ov003_021d1f98();
    p = func_ov003_021d285c(0x700, 0x20);
    DWC_BM_Init(p);
    func_ov003_021d2808(&p);
}

void func_ov003_021c2188(void) {
    volatile u32 *p;
    volatile u16 *q;
    GX_VBlankIntr(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_SetGraphicsMode(1, 0, 0);
    p = &reg_GX_DISPCNT;
    *p = *p & 0xffffe0ff;
    GXx_SetMasterBrightness_((u16 *) &reg_GX_MASTER_BRIGHT, 0);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x200010;
    reg_G2_BG0CNT &= ~0x40;
    reg_G2_BG1CNT &= ~0x40;
    reg_G2_BG2CNT &= ~0x40;
    reg_G2_BG3CNT &= ~0x40;
    reg_G2_BG0OFS = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG3OFS = 0;
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x3f, 0x10);
    GX_SetBankForSubBG(0x80);
    GX_SetBankForSubOBJ(0x100);
    GXS_SetGraphicsMode(0);
    p = &reg_GXS_DB_DISPCNT;
    *p = *p & 0xffffe0ff;
    GXx_SetMasterBrightness_((u16 *) &reg_GXS_DB_MASTER_BRIGHT, 0);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    reg_G2S_DB_BG0CNT &= ~0x40;
    reg_G2S_DB_BG1CNT &= ~0x40;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3f, 0x10);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0xc00;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0xd08;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0xe10;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0xf10;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0xc00;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xd00;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe00;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0xf00;
    q = &reg_GX_POWCNT;
    *q = *q & ~0x8000;
    func_ov003_021d2490();
    func_ov003_021d2fdc();
    func_ov003_021d31b0();
    func_ov003_021d1b3c();
    GX_DispOn();
    *(u32 *) 0x4001000 = *(u32 *) 0x4001000 | 0x10000;
    GX_VBlankIntr(1);
}

void func_ov003_021c2138(void) {
    GX_DispOff();
    *((u32 *) 0x04001000u) = *((u32 *) 0x04001000u) & (0xfffeffffu);
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

void func_ov003_021c2120(u32 a, u32 b) {
    u32 *v1;
    v1 = (u32 *) &data_ov003_021da180;
    *(u32 *) &data_ov003_021da180 = a;
    v1[1] = b;
    return;
}

void func_ov003_021c2104(s32 *first, s32 *second) {
    if (first != NULL) {
        *first = data_ov003_021da180[0];
    }
    if (second != NULL) {
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
    if (first != NULL) {
        *first = data_ov003_021da180[2];
    }
    if (second != NULL) {
        *second = data_ov003_021da180[3];
    }
}

u8 func_ov003_021c20d0(void) {
    return *(u8 *) &data_ov003_021da16c;
}

u32 func_ov003_021c20c0(void) {
    return data_ov003_021da178.mUnk_00;
}

u32 func_ov003_021c20a8(u32 a) {
    if (((*(u32 *) &data_ov003_021da178) >> 4 & a) != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c209c(void) {
    *(u8 *) &data_ov003_021da170 = 1;
    return;
}
