#include "Main/Unknown/code_02077eb4.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "code_020176c0.h"

#pragma thumb on

void func_02077f48(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217ad08)) + 0 + (0x1d8u)) = p0;
}

void func_02077f0c(u16 *param_1, int param_2, u32 param_3) {
    u16 v1;
    int v2;
    int v3;
    v1 = *param_1;
    v3 = param_2 - (u32) v1;
    if (v3 < 0) {
        v3 = 0xffff - v3;
    }
    v2 = func_021488e8(v3, (int) param_3);
    *param_1 = *param_1 + v2;
    if ((int) ((*param_1 + 100) - param_2) < 0) {
        *param_1 = (u16) (*param_1 + 100);
        return;
    }
    *param_1 = v1;
}

#pragma thumb off

#pragma thumb on

Unk020b4a44 *func_02077f00(void) {
    return data_usa_0217ace4;
}

#pragma thumb off

#pragma thumb on

void func_02077eb4(void *param_1, u32 *param_2) {
    u32 v1;
    u32 v2;
    v1 = ((u32) func_02036bec(param_1, (u32) (((u32) 0x0000f000u))));
    v2 = (u32) func_02017988((void *) ((void *) v1), (u32) ((u32) (((u32) 0x0000f000u))), (u32) 0);
    param_2[1] = v2;
    *param_2 = v1;
    param_2[4] = 0;
    param_2[3] = param_2[4];
    param_2[2] = param_2[3];
    param_2[7] = 0;
    param_2[6] = param_2[7];
    param_2[5] = param_2[6];
    param_2[10] = 0;
    param_2[9] = param_2[10];
    param_2[8] = param_2[9];
    param_2[0xb] = 0;
    *(u16 *) (param_2 + 0xc) = 0;
}

#pragma thumb off
