#include "00/code_02180c04.h"

#include "00/code_02180608.h"

u32 func_ov000_02180c28(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = 0x4001000u;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
    return value0;
}

void func_ov000_02180c04(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0a98;
    SetWiFiStateCallbacks(&callbacks);
}
