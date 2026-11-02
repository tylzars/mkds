#include "00/code_ov000_021804e0.h"

#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"

void func_ov000_021805cc(s16 *a) {
    void *b;
    b = func_020364e0(func_020364e8());
    data_ov000_021b4c60 = func_02036bec(b, 0x808);
    InitWiFiStates(b, *a);
}

void func_ov000_021805b4(void) {
    func_ov000_02180814();
    data_ov000_021b4c60 = 0;
}

void func_ov000_0218058c(void) {
    func_02077c1c();
    func_ov000_02180704();
    func_020ae5f0(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
}

void func_ov000_02180534(Unk020487fc *a) {
    func_020ae6ac(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    AdvanceWiFiStates();
    func_020ae630(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    if (a != 0) {
        if (func_ov000_021806c4() != -1) {
            if (func_ov000_021806c4() == 0) {
                data_021759d0->mUnk_20 = 0;
            }
            a->mUnk_04 = func_ov000_021806c4();
        }
    }
}

s32 func_ov000_02180500(Unk020487fc *a) {
    Unk021a9034 b = {
        func_ov000_021805cc, func_ov000_02180534, func_ov000_021805b4, func_ov000_0218058c, 0, 0, 10, 10, 0};
    func_020487fc(a, &b);
    return 0;
}

void *func_ov000_021804f4(void) {
    return data_ov000_021b4c60;
}

void *func_ov000_021804e0(void) {
    return data_ov000_021b4c60 + 0x404;
}
