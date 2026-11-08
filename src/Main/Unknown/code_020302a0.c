#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_0203033c.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"

#pragma optimize_for_size on

void func_020302f0(u32 startX, u32 startY, u32 endX, u32 endY) {
    reg_G2S_DB_WIN0H = ((startX << 8) & 0xff00) | (endX & 0xff);
    reg_G2S_DB_WIN0V = ((startY << 8) & 0xff00) | (endY & 0xff);
}

#pragma thumb on

void WriteMultiSelectNSRegisters(void) {
    MultiSelectNS *multiSelectNS;

    func_020303a8(0x16);
    multiSelectNS = gMultiSelectNS;
    if (multiSelectNS->mOffset != 0) {
        func_0203038c(1);
        func_02030364(0x1f, 1);
        func_0203033c(7, 1);
        func_020302f0(0, 0, 0xff, gMultiSelectNS->mOffset + 0xc0);
    } else {
        func_0203038c(0);
    }
}

#pragma thumb off
