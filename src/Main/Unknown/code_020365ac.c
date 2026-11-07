#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_02152ac8.h"

#include "Main/Unknown/code_02036c5c.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036c4c.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200f5ac.h"
#include "code_0200f790.h"
#include "gx.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"
#include "registers.h"

void func_020367c4(void) {
    if (gDisplaySettings != NULL) {
        ClearFrameFinishedFlag();
        if (gDisplaySettings->mIrqCallback != NULL) {
            gDisplaySettings->mIrqCallback();
        }
    }
    *OFFSET_PTR(u32, &data_027e0000, 0x3ff8) |= 1;
}

void func_02036778(void) {
    OS_SetIrqFunction(1, func_020367c4);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
}

void func_020366bc(void) {
    OS_DisableMainExArena();
    OS_Init();
    data_02174e78.mUnk_00 = 0;
    OS_InitTick();
    OS_InitAlarm();
    func_02148904();
    GX_Init();
    InitWvrState();
    ClearLcdcBanksByState();
    GX_DispOff();
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0x10000;
    OS_SetIrqFunction(1, func_020367c4);
    OS_EnableIrqMask(1);
    reg_OS_IME;
    reg_OS_IME = 1;
    OS_EnableInterrupts();
    GX_VBlankIntr(1);
    FS_Init(-1);
    func_02039774();
    data_usa_02174e54 = DWC_Init(data_usa_02174e80);
    ClearLcdcBankAndStartWvrAndWait();
}

void func_02036678(void) {
    OS_GetArenaLo(0);
    OS_GetArenaHi(0);
    OS_GetArenaLo(3);
    OS_GetArenaHi(3);
    OS_GetArenaLo(4);
    OS_GetArenaHi(4);
}

void func_020365f0(void) {
    u8 *a;
    func_020366bc();
    InitBrightnessFades();
    data_02174e78.mUnk_04 = (u32) ARM9_TEXT_START;
    data_02174e78.mUnk_08 = OS_GetArenaLo(0);
    func_02036678();
    a = OS_GetArenaLo(0);
    data_02174e78.mHeap = CreateExpHeapOverBlock(a, (u8 *) OS_GetArenaHi(0) - a);
    InitHeapCall(&gRootHeapCall, 0);
    data_02174e78.mUnk_10 = data_usa_021646ec;
    func_020394cc();
}

void func_020365bc(u32 a) {
    SetHeapCallFunc(&gRootHeapCall, a);
    RunHeapCall(&gRootHeapCall, 0xbeef);
}

void *func_020365ac(void) {
    return data_02174e78.mHeap;
}
