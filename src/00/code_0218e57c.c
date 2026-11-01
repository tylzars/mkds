#include "00/code_0218e57c.h"
#include "00/code_021a86e8.h"
#include "00/code_021a8f0c.h"
#include "00/code_021a8bb0.h"
#include "00/unk_021b2000.h"

Unk021a8f84 *func_ov000_0218e5e4(void) {
    data_ov000_021b4e0c.mUnk_00 = data_ov000_021b23dc;
    data_ov000_021b4e0c.mUnk_04 = data_ov000_021b4e04;
    data_ov000_021b4e0c.mUnk_08 = 2;
    data_ov000_021b4e0c.mUnk_0a = 0;
    data_ov000_021b4e0c.mUnk_0c = data_ov000_021b4e30;
    data_ov000_021b4e1c = 0;
    func_ov000_021a8bb0(func_ov000_021a8830(), (u8 *) &data_ov000_021b4e1c);
    if (data_ov000_021b4e1c == 0) {
        return 0;
    }
    data_ov000_021b4e30[0] = &data_ov000_021b4e1c;
    data_ov000_021b4e0c.mUnk_0a = 4;
    data_ov000_021b4e30[1] = 0;
    return &data_ov000_021b4e0c;
}

s32 func_ov000_0218e57c(u32 *param_1) {
    u32 a = *param_1;
    u32 b = ((a << 24) & 0xff000000) | (((a << 8) & 0xff0000) | (((a >> 24) & 0xff) | ((a >> 8) & 0xff00)));
    s32 c = (b >> 24) & 0xff;
    s32 d = (b >> 16) & 0xff;
    if (c == 10) {
        return 1;
    }
    if (c == 172 && d >= 16 && d <= 31) {
        return 1;
    }
    if (c == 192 && d == 168) {
        return 1;
    }
    return 0;
}
