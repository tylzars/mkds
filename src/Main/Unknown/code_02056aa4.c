#include "Main/Unknown/code_02056aa4.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02056aa4(Unk0217aa08_08_04 *a, Unk02056bc0 *b) {
    if (a->mUnk_00_0 != 0) {
        func_0214d1fc(a->mUnk_08, b->mUnk_04, 0x14);
        b->mUnk_19 = a->mUnk_00_1;
        b->mUnk_1a = a->mUnk_00_b[1];
        b->mUnk_02 = a->mUnk_04_8;
        b->mUnk_03 = a->mUnk_04_15;
        b->mUnk_00 = a->mUnk_04_22;
        b->mUnk_1e = a->mUnk_00_b[3];
        b->mUnk_1d = a->mUnk_00_b[2];
        b->mUnk_1c = a->mUnk_04_b[0];
        b->mUnk_18 = 1;
    } else {
        b->mUnk_18 = 0;
    }
}

#pragma thumb off
