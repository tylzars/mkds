#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_0203033c.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

void func_020302f0(u32 a, u32 b, u32 c, u32 d) {
    *(u16 *) 0x4001040 = ((a << 8) & 0xff00) | (c & 0xff);
    *(u16 *) 0x4001044 = ((b << 8) & 0xff00) | (d & 0xff);
}

#pragma thumb on

void func_020302a0(void) {
    Unk02174e54 *o;

    func_020303a8(0x16);
    o = data_02174e54;
    if (o->mUnk_38 != 0) {
        func_0203038c(1);
        func_02030364(0x1f, 1);
        func_0203033c(7, 1);
        func_020302f0(0, 0, 0xff, data_02174e54->mUnk_38 + 0xc0);
    } else {
        func_0203038c(0);
    }
}

#pragma thumb off
