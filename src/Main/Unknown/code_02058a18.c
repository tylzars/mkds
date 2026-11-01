#include "Main/Unknown/code_02058a18.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_0205955c.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline u32 func_02058a40_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_02058aa0(void) {
    u8 v;
    u16 w;

    if (func_02058a40_inline() == 1) {
        v = data_0217aa00->mUnk_15f6;
        if (func_02059784() != 0) {
            if (func_02050320(1, v, v) != 0) {
                func_02050034(v);
            }
        } else {
            w = data_0217aa00->mUnk_1608.mUnk_14;
            if (w > 0xe10) {
                func_02050e60(7);
                return;
            }
            data_0217aa00->mUnk_1608.mUnk_14 = w + 1;
        }
    }
}

void func_02058a40(void) {
    Unk0217aa00_1608 *p;

    if (func_02058a40_inline() == 1 && (data_0217aa00->mUnk_0454 & 1)) {
        if (func_02050320(2, data_0217aa00->mUnk_0044.mUnk_43, data_0217aa00->mUnk_0457) != 0) {
            p = &data_0217aa00->mUnk_1608;
            p->mUnk_10 = 1;
            p->mUnk_12 = 1;
        }
    }
}

void func_02058a18(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
}

#pragma thumb off
