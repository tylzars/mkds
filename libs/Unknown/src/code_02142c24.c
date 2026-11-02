#include "code_02142c24.h"
#include "code_0214259c.h"
#include "code_02142eac.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214c778.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/unk_0217e000.h"

s32 func_02142e78(void *buf, u32 n) {
    s32 r;

    r = func_02142c98(buf, n, 0xf00);
    if (r == 0) {
        data_0217eed4->mUnk_016 = 0;
    }
    return r;
}

s32 func_02142c98(void *buf, u32 n, u32 size) {
    s32 i;
    s32 j;

    if (data_0217eed0 != 0) {
        return 3;
    }
    data_0217eed0 = 1;
    if (buf == 0) {
        data_0217eed0 = 0;
        return 6;
    }
    if (n > 3) {
        data_0217eed0 = 0;
        return 6;
    }
    if (((u32) buf & 0x1f) != 0) {
        data_0217eed0 = 0;
        return 6;
    }
    func_0214d5b8();
    if (func_0214d79c(0xa, 1) == 0) {
        data_0217eed0 = 0;
        return 4;
    }
    func_0200ee3c(buf, size);
    func_0214cc04(n, buf, 0, size);
    data_0217eed4 = buf;
    data_0217eed4->mUnk_000 = (u8 *) buf + 0x200;
    data_0217eed4->mUnk_004 = (Unk02142988 *) ((u8 *) data_0217eed4->mUnk_000 + 0x300);
    data_0217eed4->mUnk_00c = (u16 *) ((u8 *) data_0217eed4->mUnk_004 + 0x800);
    data_0217eed4->mUnk_010 = (Unk021425e8 *) ((u8 *) data_0217eed4->mUnk_00c + 0x100);
    func_021425cc();
    data_0217eed4->mUnk_014 = n;
    for (i = 0; i < 16; i++) {
        func_0214358c((u16) i, 0, 0);
    }
    func_0200eb90(&data_0217eed8, data_0217eef8, 10);
    for (j = 0; j < 10; j++) {
        *(u16 *) data_0217ef60[j] = 0x8000;
        func_0200ee58(data_0217ef60[j], 2);
        func_0200eae8(&data_0217eed8, data_0217ef60[j], 1);
    }
    func_0214d7c4(0xa, func_021425e8);
    return 0;
}

s32 func_02142c24(void) {
    s32 r;

    if (func_02142a8c() != 0) {
        return 3;
    }
    r = func_02142988(1, 0);
    if (r != 0) {
        return r;
    }
    func_021425cc();
    func_0214d7c4(0xa, 0);
    data_0217eed4 = 0;
    data_0217eed0 = 0;
    return 0;
}
