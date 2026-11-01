#include "03/code_021d0c84.h"
#include "03/code_021cfa68.h"
#include "03/code_021cf5ac.h"
#include "03/code_021cf284.h"
#include "03/code_021cf360.h"
#include "03/code_021cf598.h"
#include "03/code_021cfaa8.h"
#include "03/code_021cfb80.h"
#include "03/code_021cfed8.h"
#include "03/code_021cff50.h"
#include "03/code_021d010c.h"
#include "03/code_021d0850.h"
#include "03/unk_021da000.h"
#include "code_0200fd1c.h"

void func_ov003_021d0df8(void) {
    switch (func_ov003_021d010c()) {
        case 1:
            func_ov003_021d0078();
            return;
        case 7:
            data_ov003_021da2ac->mUnk_64a = func_ov003_021cfed8();
            data_ov003_021da2ac->mUnk_a98 = 0;
            data_ov003_021da2ac->mUnk_a90 = 3;
            return;
        case 0:
            data_ov003_021da2ac->mUnk_a98 = 0;
            data_ov003_021da2ac->mUnk_a90 = 3;
            return;
        case 9:
            func_ov003_021cfb80();
            return;
        case 3:
            break;
        default:
            func_0200fd1c();
            break;
    }
}

void func_ov003_021d0dd8(void) {
    func_ov003_021cf978(data_ov003_021da2ac->mUnk_ac8, data_ov003_021da2ac->mUnk_648);
}

void func_ov003_021d0c84(void) {
    switch (func_ov003_021cf360()) {
        case 1:
            func_ov003_021cf93c((Unk021cf8ac *) &data_ov003_021da2ac->mUnk_ab4, data_ov003_021da2ac->mUnk_64a);
            return;
        case 2:
            if (func_ov003_021cf32c(2) != 0) {
                data_ov003_021da2ac->mUnk_a90 = 5;
                return;
            }
            if (func_ov003_021cf32c(3) != 0 || func_ov003_021cf32c(4) != 0) {
                data_ov003_021da2ac->mUnk_a90 = 6;
                return;
            }
            if (data_ov003_021da2ac->mUnk_a90 == 5) {
                if (func_ov003_021cf32c(2) == 0) {
                    data_ov003_021da2ac->mUnk_a90 = 0xd;
                    return;
                }
            }
            break;
        case 3:
            if (func_ov003_021cf64c() != 0) {
                func_ov003_021cf5ac();
                return;
            }
            if ((u8) (data_ov003_021da2ac->mUnk_a90 + 250) <= 1) {
                if (func_ov003_021cf32c(3) == 0) {
                    data_ov003_021da2ac->mUnk_a90 = 0x12;
                    return;
                }
            }
            break;
        case 5:
            data_ov003_021da2ac->mUnk_a90 = 7;
            return;
        case 7:
            func_ov003_021cf598();
            data_ov003_021da2ac->mUnk_a90 = 1;
            return;
        case 0:
            switch (func_ov003_021d010c()) {
                case 1:
                    func_ov003_021cfa68();
                    return;
                case 0:
                    data_ov003_021da2ac->mUnk_a90 = 0x1f;
                    return;
                case 3:
                    break;
                default:
                    data_ov003_021da2ac->mUnk_a90 = 0x1f;
                    break;
            }
            break;
    }
}
