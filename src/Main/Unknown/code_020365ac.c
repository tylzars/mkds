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
#include "code_021488e8.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02004dc0.h"

void func_020367c4(void) {
    if (data_021755a0 != NULL) {
        func_02037a04();
        if (data_021755a0->mUnk_b8 != NULL) {
            data_021755a0->mUnk_b8();
        }
    }
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= 1;
}

void func_02036778(void) {
    InterruptHandlerSet(1, func_020367c4);
    InterruptEnableSetBits(1);
    *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    IrqEnable();
    func_02148a58(1);
}

void func_020366bc(void) {
    func_0200ef10();
    func_0200eec0();
    data_02174e78.mUnk_00 = 0;
    func_0200f6f4();
    func_0200fb28();
    func_02148904();
    func_02148a88();
    func_02039c7c();
    func_02039bd4();
    func_02148a10();
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & ~0x10000;
    InterruptHandlerSet(1, func_020367c4);
    InterruptEnableSetBits(1);
    *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    IrqEnable();
    func_02148a58(1);
    FS_Init(-1);
    func_02039774();
    data_usa_02174e54 = func_02152b08(data_usa_02174e80);
    func_02039a1c();
}

void func_02036678(void) {
    func_0200f168(0);
    func_0200f17c(0);
    func_0200f168(3);
    func_0200f17c(3);
    func_0200f168(4);
    func_0200f17c(4);
}

void func_020365f0(void) {
    u32 a;
    func_020366bc();
    func_0203907c();
    data_02174e78.mUnk_04 = (u32) ARM9_TEXT_START;
    data_02174e78.mUnk_08 = func_0200f168(0);
    func_02036678();
    a = func_0200f168(0);
    data_02174e78.mHeap = func_02036c4c(a, func_0200f17c(0) - a);
    func_02036590(&data_02174e88, 0);
    data_02174e78.mUnk_10 = data_usa_021646ec;
    func_020394cc();
}

void func_020365bc(u32 a) {
    func_02036588(&data_02174e88, a);
    func_020364f8(&data_02174e88, 0xbeef);
}

void *func_020365ac(void) {
    return data_02174e78.mHeap;
}
