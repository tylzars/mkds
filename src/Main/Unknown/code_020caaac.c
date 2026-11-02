#include "Main/Unknown/code_020caaac.h"

#include "Main/Unknown/code_020caae8.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020cab8c.h"

#pragma thumb on

void func_020cab8c(void) {
    func_020cac18();
    func_020caba4(func_020cadac(0));
}

#pragma thumb off

u32 func_020cab74(void) {
    return ((*(u32 *) (0x04001000u & 0xfffffffc) >> (0x04001000u & 3) * 8 | *(u32 *) (0x04001000u & 0xfffffffc)
                                                                                << (0x04001000u & 3) * -8 + 0x20) &
            0x1f00) >>
           8;
}

u32 func_020cab58(u32 arg0) {
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

void func_020cab2c(u32 a, u32 b) {
    *(vu32 *) 0x4001010 = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}

void func_020caae8(u32 a, u32 b, u32 c, u32 d, s32 e) {
    func_0214a390((u16 *) 0x4001050, a, b, c, d, e);
}

void func_020caaac(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    func_0214a40c((u32 *) ((u32 *) (u32) 0x04001050u), param_1, (int) param_2, param_3, (int) param_4);
}
