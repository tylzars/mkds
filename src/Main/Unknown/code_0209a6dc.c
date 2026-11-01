#include "Main/Unknown/code_0209a6dc.h"

#include "Main/Unknown/code_0209a7dc.h"
#include "Main/Unknown/code_0209af64.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b1f8.h"
#include "Main/Unknown/code_0209b1fc.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_0209a6dc(void *a) {
    func_0209bbd0(a, data_0217b150);
}

void func_0209a6f4(void *a) {
    data_0217b150 = func_0209bd08(a, "BeachTree1.nsbmd");
    func_0209b940(data_0217b150, 0x3f);
}

void func_0209a728(void) {
    Unk0209bf70 *o;

    o = (Unk0209bf70 *) func_0209bf8c();
    o->mUnk_24 = 0x84;
}

void *func_0209a748(void) {
    return (void *) func_0209bf48(func_0209af98, func_0209a7dc, 0);
}

void *func_0209a768(void) {
    return (void *) func_0209bef0(func_0209b1fc, func_0209b088, func_0209b1f8);
}

void func_0209a78c(void) {
    Unk0209bf70 *o;

    o = func_0209bf70(func_0209b344, func_0209b270, 0, 2, 1, 0x10e);
    o->mUnk_28 = 0x10f;
}
