#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

static inline void func_0210d614_inline(Unk0217d070 *a, u32 b, NNSSndSeqPlayer **c) {
    if (c == NULL) {
        c = &data_0217d07c;
    }
    if (a->mUnk_0b == 0xff) {
        return;
    }
    func_0210d7dc(b, data_0216cb28, c);
}

void func_0210d6cc(Unk0217d070 *a) {
    a->mUnk_00 = 2;
    if (a->mUnk_0a != 2) {
        return;
    }
    func_0210d614_inline(a, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d65c(Unk0217d070 *a) {
    a->mUnk_00 = 3;
    if (a->mUnk_0a != 3) {
        return;
    }
    func_0210d614_inline(a, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d614(Unk0217d070 *a, u32 b, NNSSndSeqPlayer **c) {
    func_0210d614_inline(a, b, c);
}

void func_0210d5c0(Unk0217d070 *a) {
    func_0210d614_inline(a, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d590(Unk0217d070 *a, u32 b) {
    if (a->mUnk_0b == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&a->mUnk_0c, b);
}
