#include "Main/Unknown/code_020593dc.h"
#include "Main/Unknown/code_0205955c.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_020593dc_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_020593dc_inline2(void) {
    s32 r = 0;
    if (func_020593dc_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = 1;
    }
    return r;
}

static inline s32 func_020593dc_inline3(void) {
    s32 r = 0;
    if (func_020593dc_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = 1;
    }
    return r;
}

static inline s32 func_020593dc_inline4(void) {
    s32 r = 0;
    if (func_020593dc_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = 1;
    }
    return r;
}

void func_020594d4(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = 0x12;
    p->mUnk_12 = 1;
}

void func_0205949c(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = 0x15;
    p->mUnk_12 = 1;
}

u32 func_020593dc(void) {
    if (func_020593dc_inline4()) {
        return 3;
    }
    if (!func_020593dc_inline2()) {
        return 1;
    }
    switch (func_020593dc_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(1, data_0217aa00->mUnk_1650, data_0217aa00->mUnk_1654);
        default:
            return 3;
    }
}

#pragma thumb off
