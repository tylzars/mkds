#include "00/code_021a31d4.h"
#include "code_02139f70.h"
#include "00/unk_021b5000.h"

#include "00/unk_021b4000.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

void func_ov000_021a3250(u32 (*arg0)(void)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_ov000_021b5dd0;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x600u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}

void func_ov000_021a323c(void (*arg0)(u32, void *, u32)) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_ov000_021b5dd0;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x604u;
    *(u32 *) ((value2) + (value1)) = value0;
    return;
}

void func_ov000_021a321c(u32 *param_1, u16 param_2, u32 param_3) {
    strncpy((u8 *) ((u32 *) (u32) ((int) param_1 + 6)), (const u8 *) &data_ov000_021b41f0, 2);
    *(u16 *) (param_1 + 1) = param_2;
    *param_1 = param_3;
    return;
}

u16 func_ov000_021a31e8(const void *a) {
    Unk021a31e8 t;
    func_0214d1fc(a, &t, 8);
    if (memcmp(t.mUnk_06, data_ov000_021b41f0, 2) == 0) {
        return t.mUnk_04;
    }
    return 0;
}

s32 func_ov000_021a31d4(s32 value) {
    switch (value) {
        case 2:
        case 3:
        case 4:
            return 12;
        default:
            return 8;
    }
}
