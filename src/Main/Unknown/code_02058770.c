#include "Main/Unknown/code_02058770.h"
#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02142eac.h"

#pragma thumb on

static inline u32 func_02058820_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_020587d8_inline(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

void func_02058820(void) {
    s32 i;
    u32 j;
    u32 n;

    func_0214358c(14, (UnkFunc *) func_02059920, 0);
    if (func_02058820_inline() == 1) {
        func_020518c8(0);
    }
    for (i = 0; i < 8; i++) {
        if (func_02058820_inline() == 1) {
            n = 0x12;
        } else {
            n = 2;
        }
        for (j = 0; j < n; j++) {
            data_0217aa00->mUnk_162c[i][j] = 0;
        }
    }
    data_0217aa00->mUnk_162a = 0;
}

void func_020587d8(void) {
    if (data_0217aa00->mUnk_0010 == 0) {
        switch (data_0217aa00->mUnk_000c) {
            case 0xc:
                data_0217aa00->mUnk_000c = 0xb;
                break;
            case 0xb:
                func_020587d8_inline(8);
                break;
            default:
                func_02050e60(2);
                break;
        }
    }
}

void func_02058770(void) {
    u16 v;

    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
    func_02056464(&data_0217aa00->mUnk_045c[v]);
    data_0217aa00->mUnk_1608.mUnk_1a |= 1;
    data_0217aa00->mUnk_1628 = 0;
    data_0217aa00->mUnk_1608.mUnk_16 = 0;
}

#pragma thumb off
