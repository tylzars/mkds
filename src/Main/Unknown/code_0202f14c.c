#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_0202f000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_0212a000.h"

#include "Main/Unknown/code_0202f20c.h"

#pragma thumb on

void func_0202f1dc(void) {
    int v1;
    data_02174e4c->mUnk_80c->mUnk_08();
    v1 = func_0202f19c();
    if (v1 == 0) {
        func_02125da0();
    }
    func_0212abd0();
}

#pragma thumb off

u16 *func_0202f1d0(void) {
    return (u16 *) 0x027ffc40;
}

u32 func_0202f1a8(void) {
    return *func_0202f1d0() == 2;
}

u32 func_0202f19c(void) {
    return func_0202f1a8();
}

#pragma thumb on

void func_0202f160(void) {
    int v1;
    v1 = func_0202f19c();
    if (v1 == 0) {
        func_021258f0();
    }
    data_02174e4c->mUnk_80c->mUnk_0c();
    func_020ae5f0((void *) data_02174e4c, (void *) data_02174e4c->mUnk_404);
}

Unk02174e4c_818 *func_0202f14c(void) {
    return &data_02174e4c->mUnk_818;
}

#pragma thumb off
