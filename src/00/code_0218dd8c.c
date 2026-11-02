#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"

#include "code_02134d30.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "code_021382a8.h"
#include "00/code_0218d818.h"
#include "00/code_0218db48.h"
#include "00/code_021a3668.h"

Unk0218e004 *func_ov000_0218e004(s32 param_1, s32 param_2, s32 param_3, s32 (*param_4)(void *, s32),
                                 s32 (*param_5)(void *, void *), void (*param_6)(void *)) {
    Unk0218e004 *a;
    s32 b;
    if (param_4 == 0) {
        func_0213442c(data_ov000_021b236c, data_ov000_021b2358, 0, 0x38);
    }
    if (param_5 == 0) {
        func_0213442c(data_ov000_021b2374, data_ov000_021b2358, 0, 0x39);
    }
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b237c, data_ov000_021b2358, 0, 0x3a);
    }
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b2388, data_ov000_021b2358, 0, 0x3b);
    }
    a = func_ov000_021a3690(0x14);
    if (a == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x3e);
    }
    a->mUnk_00 = func_ov000_021a3690(param_2 * 4);
    if (a->mUnk_00 == 0) {
        func_0213442c(data_ov000_021b2394, data_ov000_021b2358, 0, 0x41);
    }
    for (b = 0; b < param_2; b++) {
        a->mUnk_00[b] = func_ov000_0218dc94(param_1, param_3, param_6);
    }
    a->mUnk_04 = param_2;
    a->mUnk_08 = param_6;
    a->mUnk_10 = param_5;
    a->mUnk_0c = param_4;
    return a;
}

void func_ov000_0218dfb4(void *param_1) {
    Unk0218e004 *a = param_1;
    s32 b;
    if (a == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x51);
    }
    if (a != 0) {
        for (b = 0; b < a->mUnk_04; b++) {
            func_ov000_0218dc48(a->mUnk_00[b]);
        }
        func_ov000_021a3668(a->mUnk_00);
        func_ov000_021a3668(a);
    }
}

s32 func_ov000_0218df5c(Unk0218e004 *param_1) {
    s32 a = 0;
    s32 b;
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x61);
    }
    if (param_1 == 0) {
        return 0;
    }
    for (b = 0; b < param_1->mUnk_04; b++) {
        a += func_ov000_0218dc44(param_1->mUnk_00[b]);
    }
    return a;
}

void func_ov000_0218def0(Unk0218e004 *param_1, void *param_2) {
    s32 a;
    s32 b;
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x71);
    }
    if (param_1 != 0) {
        a = param_1->mUnk_0c(param_2, param_1->mUnk_04);
        b = func_ov000_0218d980((int *) param_1->mUnk_00[a], param_2, (UnkCompare *) param_1->mUnk_10, 0, 0);
        if (b == -1) {
            func_ov000_0218dbc0(param_1->mUnk_00[a], param_2);
            return;
        }
        func_ov000_0218da1c(param_1->mUnk_00[a], param_2, b);
    }
}

s32 func_ov000_0218de8c(Unk0218e004 *param_1, void *param_2) {
    s32 a;
    s32 b;
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x82);
    }
    if (param_1 == 0) {
        return 0;
    }
    a = param_1->mUnk_0c(param_2, param_1->mUnk_04);
    b = func_ov000_0218d980((int *) param_1->mUnk_00[a], param_2, (UnkCompare *) param_1->mUnk_10, 0, 0);
    if (b != -1) {
        func_ov000_0218da5c(param_1->mUnk_00[a], b);
        return 1;
    }
    return 0;
}

void *func_ov000_0218de28(Unk0218e004 *param_1, void *param_2) {
    s32 a;
    s32 b;
    if (param_1 == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x94);
    }
    if (param_1 == 0) {
        return 0;
    }
    a = param_1->mUnk_0c(param_2, param_1->mUnk_04);
    b = func_ov000_0218d980((int *) param_1->mUnk_00[a], param_2, (UnkCompare *) param_1->mUnk_10, 0, 0);
    if (b != -1) {
        return func_ov000_0218dbf8(param_1->mUnk_00[a], b);
    }
    return 0;
}

void func_ov000_0218dddc(Unk0218e004 *param_1, void (*param_2)(void *, void *), void *param_3) {
    s32 a;
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xb6);
    }
    for (a = 0; a < param_1->mUnk_04; a++) {
        func_ov000_0218d938((int *) param_1->mUnk_00[a], (UnkCompare *) param_2, param_3);
    }
}

int func_ov000_0218dd8c(int *param_1, int param_2, u32 param_3) {
    int v1;
    int v2;
    int v3;
    if (param_2 == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xd3);
    }
    v3 = 0;
    if (0 < param_1[1]) {
        v2 = 0;
        do {
            v1 = (int) func_ov000_0218d8dc((int *) (u32) (*(u32 *) (*param_1 + v2)), (UnkCompare *) param_2,
                                           (void *) param_3);
            if (v1 != 0) {
                return v1;
            }
            v2 = v2 + 4;
            v3 = v3 + 1;
        } while (v3 < param_1[1]);
    }
    return 0;
}
