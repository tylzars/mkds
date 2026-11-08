#include "Main/Unknown/code_020caaac.h"
#include "registers.h"

#include "Main/Unknown/code_020caae8.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020cab8c.h"
#include "Main/Unknown/code_020caba4.h"

#pragma thumb on

void func_020cab8c(void) {
    func_020cac18();
    func_020caba4(MoveEmblemChoisesIndex(0));
}

#pragma thumb off

u32 func_020cab74(void) {
    return ((*(u32 *) (0x04001000u & 0xfffffffc) >> (0x04001000u & 3) * 8 | *(u32 *) (0x04001000u & 0xfffffffc)
                                                                                << (0x04001000u & 3) * -8 + 0x20) &
            0x1f00) >>
           8;
}

u32 func_020cab58(u32 bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
    return value0;
}

void func_020cab2c(u32 x, u32 y) {
    reg_G2S_DB_BG0OFS = (x & 0x1ff) | ((y << 16) & 0x1ff0000);
}

void func_020caae8(u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness) {
    G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2, brightness);
}

void func_020caaac(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}
