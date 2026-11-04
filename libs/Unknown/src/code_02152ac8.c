#include "code_021519d4.h"
#include "code_02152490.h"
#include "code_02152ac8.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02151f88.h"
#include "Main/Unknown/code_02152000.h"

#pragma thumb on

u32 func_02152b08(u8 *a) {
    u32 r;
    s32 s;

    r = 0;
    func_02000b44(0x2000b88);
    s = func_02151b38(a);
    if (func_02151da8() != 0) {
        func_02151f88((u32) a);
        r = 1;
    }
    if (s < 0) {
        if (r != 0) {
            return 2;
        }
        return 3;
    }
    if (r != 0) {
        return 1;
    }
    return 0;
}

u32 BitFieldInsert(u32 *a, u32 b, u32 c, u32 d) {
    if ((b & ~d) != 0) {
        return 0;
    }
    *a = *a & ~(d << c) | b << c;
    return 1;
}

u64 func_02152ac8(const Unk02152490 *a) {
    return (u64) (a->mUnk_00 & 0x7ff) << 32 | a->mUnk_04;
}

#pragma thumb off
