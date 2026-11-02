#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_0204f148(void) {
    s32 v1 = data_0217aa00->mUnk_000c;
    u8 v;
    s32 s = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (s == 1) {
        v = data_0217aa00->mUnk_0044.mUnk_43;
    } else {
        v = 1;
    }
    data_0217aa00->mUnk_000c = 0x2a;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02006ddc(v, func_0204f100) == 0) {
        data_0217aa00->mUnk_0010 = 0;
        data_0217aa00->mUnk_000c = v1;
    }
}

void func_0204f100(Unk0216f3dc_9c *a) {
    if (a->mUnk_00 == 2) {
        if (a->mUnk_04 == 3) {
            data_0217aa00->mUnk_1d5e = *(s16 *) &a->mUnk_14;
            data_0217aa00->mUnk_0010 = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void func_0204f0b8(void) {
    s32 v1 = data_0217aa00->mUnk_000c;
    data_0217aa00->mUnk_000c = 0x2b;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02006db0(1, data_0217aa00->mUnk_1d5c, data_0217aa00->mUnk_1da0, func_0204f080) == 0) {
        data_0217aa00->mUnk_000c = v1;
        data_0217aa00->mUnk_0010 = 0;
    }
}

void func_0204f080(Unk0216f3dc_9c *a) {
    if (a->mUnk_00 == 6) {
        if (a->mUnk_04 == 7) {
            data_0217aa00->mUnk_0010 = 0;
        } else {
            func_0204f0b8();
        }
    } else {
        func_02050e60(8);
    }
}

void func_0204f008(void) {
    s32 v1 = data_0217aa00->mUnk_000c;
    data_0217aa00->mUnk_000c = 0x2c;
    data_0217aa00->mUnk_0010 = 1;
    data_0217aa00->mUnk_1d60 = data_0217aa00->mUnk_16a0[data_0217aa00->mUnk_1d5c].mUnk_74;
    if (func_02006d78(1, data_0217aa00->mUnk_1da0[0]->mUnk_00, &data_0217aa00->mUnk_1d60,
                      data_0217aa00->mUnk_1da0[0]->mUnk_04, data_0217aa00->mUnk_1de0, func_0204efcc) == 0) {
        data_0217aa00->mUnk_000c = v1;
        data_0217aa00->mUnk_0010 = 0;
    }
}

void func_0204efcc(Unk0216f3dc_9c *a) {
    if (a->mUnk_00 == 4) {
        if (a->mUnk_04 == 5) {
            data_0217aa00->mUnk_0010 = 0;
        } else {
            func_02050e60(8);
        }
    } else {
        func_02050e60(8);
    }
}

void func_0204ef88(void) {
    s32 v = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (v == 2) {
        if (data_0217aa00->mUnk_0432 == 0xffff) {
            func_02050e60(8);
            return;
        }
        func_02007008(data_0217aa00->mUnk_0432);
    }
}

void func_0204ef1c(void) {
    data_0217aa00->mUnk_000c = 0xb;
    data_0217aa00->mUnk_0010 = 1;
    if (func_02144230(func_02051958, (u32) data_0217aa00->mUnk_1e24, (u16) data_0217aa00->mUnk_1e2c,
                      (u32) data_0217aa00->mUnk_1e20, (u16) data_0217aa00->mUnk_1e28, 1, 0, 0, 0, 0, 0) != 2) {
        func_02050e60(2);
    }
}

void func_0204eeb4(u8 *a, u32 b) {
    u16 n = data_0217aa00->mUnk_1e40;
    func_02006e74(&data_0217aa00->mUnk_16a0[n].mUnk_00, (u16) (n + 0x3e8), data_02154768, a, b, 0);
    data_0217aa00->mUnk_16a0[n].mUnk_74 = (u32 *) a;
    data_0217aa00->mUnk_1e40++;
}

void func_0204eeac(u8 *a, u32 b) {
    func_0204eeb4(a, b);
}

void func_0204ee64(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        func_02006df8((u16) (i + 0x3e8));
        data_0217aa00->mUnk_16a0[i].mUnk_74 = 0;
    }
    data_0217aa00->mUnk_1e40 = 0;
}

#pragma thumb off
