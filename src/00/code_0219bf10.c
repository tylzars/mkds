#include "00/code_0219bf10.h"
#include "00/code_0219b000.h"
#include "00/code_0219c000.h"
#include "00/code_0219c0c4.h"
#include "00/code_0219c9d8.h"
#include "00/code_0219b580.h"
#include "00/code_0219d6c4.h"
#include "00/code_0219c39c.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a3030.h"
#include "00/code_021a47ac.h"

void func_ov000_0219bf10(void) {
    if (func_ov000_0219c0c8() != 0) {
        func_ov000_0219c0c4();
    }
    if (data_ov000_021b54c8 == 0) {
        return;
    }
    if (data_ov000_021b54c8->mUnk_24 == 0) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    switch (data_ov000_021b54c8->mUnk_24) {
        case 1:
            switch (func_ov000_0218d574()) {
                case 1:
                    if (func_ov000_0219b77c(func_ov000_0218f2b8(&data_ov000_021b54c8->mUnk_1c,
                                                                data_ov000_021b54c8->mUnk_84.mUnk_08, 0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 0,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219b580,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 3,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219b4b4,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 1,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219d708,
                                                                0)) != 0) {
                        return;
                    }
                    if (func_ov000_0219b77c(func_ov000_0218f21c(&data_ov000_021b54c8->mUnk_1c, 2,
                                                                (void (*)(void *, void *, u32)) func_ov000_0219d674,
                                                                0)) != 0) {
                        return;
                    }
                    func_ov000_0219b8a8(2);
                    func_ov000_0219ca84();
                    break;
                case 2:
                    func_ov000_0219c990(3, -20110);
                    return;
                case 3:
                    func_ov000_0219c990(4, -20101);
                    return;
            }
            break;
        case 2:
            func_ov000_0219c9d8();
            break;
        case 3:
        case 4:
            func_ov000_0219d81c();
            func_ov000_021a1ef4(0);
            break;
        case 5:
            func_ov000_021a1ef4(1);
            func_ov000_0219d81c();
            break;
        case 6:
            func_ov000_021a3030();
            func_ov000_0219d81c();
            if (data_ov000_021b54c8->mUnk_33c.mUnk_15 == 2 || data_ov000_021b54c8->mUnk_33c.mUnk_15 == 3) {
                func_ov000_021a1ef4(1);
            } else if (data_ov000_021b54c8->mUnk_00 != 0) {
                func_ov000_021a1ef4(0);
            }
            break;
    }
    if (data_ov000_021b54c8->mUnk_33c.mUnk_18 == 1) {
        if (data_ov000_021b54c8->mUnk_33c.mUnk_10 != 0) {
            func_ov000_021a47ac(data_ov000_021b54c8->mUnk_33c.mUnk_10);
            data_ov000_021b54c8->mUnk_33c.mUnk_10 = 0;
        }
        data_ov000_021b54c8->mUnk_33c.mUnk_18 = 0;
    }
}
