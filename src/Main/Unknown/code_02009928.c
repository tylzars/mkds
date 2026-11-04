#include "Main/Unknown/code_02009928.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02142eac.h"

#include "Main/Unknown/code_0200ad00.h"

#pragma thumb on

u32 func_020099cc(void) {
    return data_0216fda8->mUnk_008;
}

u16 func_020099c0(void) {
    return data_0216fda8->mUnk_00c;
}

#pragma thumb off

#pragma thumb on

u8 func_02009974(void) {
    Unk0216fda8 *v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    v1 = data_0216fda8;
    if (v1->mUnk_012 != 0) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    if (v1->mUnk_00e != 0) {
        v3 = 1;
    } else {
        v3 = 0;
    }
    if (v1->mUnk_014 != 0) {
        v4 = 4;
    } else {
        v4 = 0;
    }
    if (v1->mUnk_016 != 0) {
        v5 = 8;
    } else {
        v5 = 0;
    }
    return v5 | (v4 | (v3 | v2));
}

#pragma thumb off

#pragma thumb on

u32 func_02009958(void) {
    if (data_0216fda8->mUnk_50d == 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02009928(u16 a, s32 b) {
    u16 v[2];
    if (b != 2 && b != 0) {
        v[0] = a;
        v[1] = b;
        data_0216fda8->mUnk_51c(0xff, (Unk021425e8 *) v);
    }
}

#pragma thumb off
