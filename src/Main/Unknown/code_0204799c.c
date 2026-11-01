#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_02047b30.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void *func_02047a28(const char *v1) {
    u32 r;

    r = 0;
    if (data_021759c8->mUnk_7d8 != 0) {
        r = func_02047b30(data_02164e04[17], v1);
    }
    if (r == 0 && data_021759c8->mUnk_768 != 0) {
        r = func_02047b30(data_02164e04[16], v1);
    }
    if (r == 0 && data_021759c8->mUnk_6f8 != 0) {
        r = func_02047b30(data_02164e04[15], v1);
    }
    if (r == 0 && data_021759c8->mUnk_688 != 0) {
        r = func_02047b30(data_02164e04[14], v1);
    }
    if (r == 0 && data_021759c8->mUnk_8b8 != 0) {
        r = func_02047b30(data_02164e04[19], v1);
    }
    if (r == 0 && data_021759c8->mUnk_148 != 0) {
        r = func_02047b30(data_02164e04[2], v1);
    }
    if (r == 0 && data_021759c8->mUnk_d8 != 0) {
        r = func_02047b30(data_02164e04[1], v1);
    }
    return (void *) r;
}

void *func_0204799c(const char *v1) {
    u32 r;

    r = func_02047b30(data_02164e04[5], v1);
    if (r == 0 && data_021759c8->mUnk_458 != 0) {
        r = func_02047b30(data_02164e04[9], v1);
    }
    if (func_0205e0a0() == 2) {
        if (r == 0 && data_021759c8->mUnk_538 != 0) {
            r = func_02047b30(data_02164e04[11], v1);
        }
        if (r == 0 && data_021759c8->mUnk_5a8 != 0) {
            r = func_02047b30(data_02164e04[12], v1);
        }
    }
    return (void *) r;
}

#pragma thumb off
