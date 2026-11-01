#include "00/code_021a8f0c.h"
#include "00/code_021a8db8.h"
#include "00/code_021a86e8.h"
#include "00/code_021a911c.h"
#include "00/unk_021b5000.h"
#include "code_0200c858.h"

Unk021a8f84 *func_ov000_021a8f84(const u8 *a) {
    u32 b = func_ov000_021a88e4(a);
    if (b == 0) {
        return 0;
    }
    func_0200c858(data_ov000_021b6078, (const s8 *) a, 0x101);
    data_ov000_021b6020.mUnk_00 = (u8 *) data_ov000_021b6078;
    data_ov000_021b6020.mUnk_04 = 0;
    data_ov000_021b6020.mUnk_08 = 2;
    data_ov000_021b6020.mUnk_0a = 4;
    data_ov000_021b6020.mUnk_0c = data_ov000_021b6018;
    data_ov000_021b6018[0] = &data_ov000_021b600c;
    data_ov000_021b6018[1] = 0;
    data_ov000_021b600c =
        ((b << 24) & 0xff000000) | (((b << 8) & 0xff0000) | (((b >> 24) & 0xff) | ((b >> 8) & 0xff00)));
    return &data_ov000_021b6020;
}

u32 func_ov000_021a8f0c(u32 param_1, u32 param_2) {
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    Unk021a8e18 *b = (Unk021a8e18 *) param_2;
    u32 c;
    u32 d;
    u16 e;
    if (a == 0) {
        return -0x27;
    }
    c = func_ov000_021a8830();
    if (a != 0) {
        d = a->mUnk_74;
    } else {
        d = 0;
    }
    if (c == 0) {
        d = 0;
    }
    b->mUnk_00 = 8;
    b->mUnk_01 = 2;
    e = d;
    b->mUnk_02 = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
    b->mUnk_04 = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    return 0;
}
