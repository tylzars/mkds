#include "Main/Unknown/code_02057a18.h"

#pragma thumb on

void func_02057c60(void *param_1) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = param_1;
        func_0204b6cc(0, 0x30f00, data_021759d4->mUnk_60, 0x100, func_02057cfc, 0x59534b4e, 1);
    }
}

void func_02057c14(void *param_1) {
    u32 *v1;
    v1 = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(param_1, v1, 0x300);
        *v1 = 0x4d454b4e;
        func_0204b430(0x100, 0x31000, v1, 0x300, 0, 0);
    }
}

void func_02057bcc(void *param_1) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = param_1;
        func_0204b6cc(0x100, 0x31000, data_021759d4->mUnk_60, 0x300, func_02057cfc, 0x4d454b4e, 0);
    }
}

void func_02057b84(void *param_1) {
    u32 *v1;
    v1 = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(param_1, v1, 0x400);
        *v1 = 0x50474b4e;
        func_0204b430(0x400, 0x31300, v1, 0x400, 0, 0);
    }
}

void func_02057b40(void *param_1) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = param_1;
        func_0204b6cc(0x400, 0x31300, data_021759d4->mUnk_60, 0x400, func_02057cfc, 0x50474b4e, 0);
    }
}

void func_02057af4(void *param_1) {
    u32 *v1;
    v1 = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(param_1, v1, 0x1600);
        *v1 = 0x41544b4e;
        func_0204b430(0x800, 0x31700, v1, 0x1600, 0, 0);
    }
}

void func_02057aac(void *param_1) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = param_1;
        func_0204b6cc(0x800, 0x31700, data_021759d4->mUnk_60, 0x1600, func_02057cfc, 0x41544b4e, 0);
    }
}

void func_02057a60(void *param_1) {
    u32 *v1;
    v1 = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(param_1, v1, 0x100);
        *v1 = 0x524d4b4e;
        func_0204b430(0x1e00, 0x32d00, v1, 0x100, 0, 0);
    }
}

void func_02057a18(void *param_1) {
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = param_1;
        func_0204b6cc(0x1e00, 0x32d00, data_021759d4->mUnk_60, 0x100, func_02057cfc, 0x524d4b4e, 0);
    }
}

#pragma thumb off
