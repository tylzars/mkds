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
#include "gx.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214d93c.h"
#include "tp.h"
#include "code_021519d4.h"
#include "03/code_021d28e0.h"

s32 func_ov003_021c2494(void *memoryBlock, s32 languageIndex, u32 modeAndFlags) {
    data_ov003_021da174 = memoryBlock;
    if (func_ov003_021c2440(languageIndex, modeAndFlags) == 0) {
        return -1;
    }
    data_ov003_021da170[0] = 0;
    func_ov003_021c2398();
    func_ov003_021c2188();
    CreateSoundData();
    SetUpdateFunction(func_ov003_021c2b28);
    do {
        UpdateKeyTouchInput();
        gUpdateFunction();
        func_ov003_021d3558(0);
        UpdateLcdPower();
        func_ov003_021d3278();
        VBlankIntrWait();
    } while (data_ov003_021da170[0] == 0);
    func_ov003_021c2138();
    return 0;
}

BOOL func_ov003_021c2440(s32 languageIndex, u32 modeAndFlags) {
    gLanguageIndex[0] = languageIndex;
    *(u32 *) &data_ov003_021da178 = modeAndFlags;
    if (languageIndex < 0 || languageIndex > 5) {
        return 0;
    }
    if ((u32) (modeAndFlags << 28) >> 28 > 1) {
        return 0;
    }
    if (languageIndex != 0 && ((modeAndFlags >> 4) & 1) != 0) {
        return 0;
    }
    if (languageIndex == 0 && ((*(u32 *) &data_ov003_021da178 >> 4) & 1) == 0) {
        return 0;
    }
    return 1;
}

void func_ov003_021c2398(void) {
    u8 *work;
    u16 imeValue = reg_OS_IME;
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
    CreateExpHeapOverBuffer(data_ov003_021da174);
    func_ov003_021d2dfc();
    func_ov003_021d35f4();
    func_ov003_021d1654();
    InitKeyTouchInput();
    InitBlendBrightnessFadeSlotsFaded();
    work = AllocExpHeapBlock(0x700, 0x20);
    DWC_BM_Init(work);
    FreeExpHeapBlockAndClearPointer(&work);
}

void func_ov003_021c2188(void) {
    volatile u32 *p;
    volatile u16 *powerControl;
    GX_VBlankIntr(0);
    GX_SetBankForBG(1);
    GX_SetBankForOBJ(2);
    GX_SetGraphicsMode(1, 0, 0);
    p = &reg_GX_DISPCNT;
    *p = *p & 0xffffe0ff;
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
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
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
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
    powerControl = &reg_GX_POWCNT;
    *powerControl = *powerControl & ~0x8000;
    InitTextCanvases();
    func_ov003_021d2fdc();
    func_ov003_021d31b0();
    InitOamRanges();
    GX_DispOn();
    *(u32 *) 0x4001000 = *(u32 *) 0x4001000 | 0x10000;
    GX_VBlankIntr(1);
}

void func_ov003_021c2138(void) {
    GX_DispOff();
    *((u32 *) 0x04001000u) = *((u32 *) 0x04001000u) & (0xfffeffffu);
    func_ov003_021d326c();
    ReleaseKeyTouchInput();
    func_ov003_021d2dcc();
    func_ov003_021cdc28();
    ReleaseOamRanges();
    func_ov003_021d2f78();
    ReleaseTextCanvases();
    FreeBlendBrightnessFadeSlots();
    func_ov003_021d15f4();
    func_ov003_021d35c0();
    ReleaseExpHeap();
    func_ov003_021d332c();
}

void SetUpdateFunction(void (*callback)(void)) {
    gUpdateFunction = callback;
}

void func_ov003_021c2120(u32 first, u32 second) {
    u32 *values;
    values = (u32 *) &data_ov003_021da180;
    *(u32 *) &data_ov003_021da180 = first;
    values[1] = second;
}

void func_ov003_021c2104(s32 *first, s32 *second) {
    if (first != NULL) {
        *first = data_ov003_021da180[0];
    }
    if (second != NULL) {
        *second = data_ov003_021da180[1];
    }
}

void func_ov003_021c20f8(u32 third, u32 fourth) {
    u32 thirdValue = third;
    u32 fourthValue = fourth;
    u32 valuesAddress;
    valuesAddress = (u32) &data_ov003_021da180;
    *(u32 *) ((valuesAddress) + 8u) = thirdValue;
    *(u32 *) ((valuesAddress) + 12u) = fourthValue;
}

void func_ov003_021c20dc(s32 *first, s32 *second) {
    if (first != NULL) {
        *first = data_ov003_021da180[2];
    }
    if (second != NULL) {
        *second = data_ov003_021da180[3];
    }
}

u8 GetLanguageIndex(void) {
    return *(u8 *) &gLanguageIndex;
}

u32 GetMode(void) {
    return data_ov003_021da178.mMode;
}

BOOL func_ov003_021c20a8(u32 mask) {
    if (((*(u32 *) &data_ov003_021da178) >> 4 & mask) != 0) {
        return 1;
    }
    return 0;
}

void func_ov003_021c209c(void) {
    *(u8 *) &data_ov003_021da170 = 1;
}
