#include "03/code_021cfaa8.h"
#include "03/code_021cfb80.h"
#include "03/code_021d022c.h"
#include "03/code_021d0258.h"
#include "03/code_021d032c.h"
#include "03/code_021d0358.h"
#include "03/code_021d07b0.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

void func_ov003_021cfaa8(void) {
    s32 a = data_ov003_021da2a8->mUnk_40;
    if (a == 1) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d79d0);
        }
        return;
    }
    if (data_ov003_021da2a4 != 0) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d79f4, a);
    }
    if (data_ov003_021da2a8->mUnk_40 != 6 && data_ov003_021da2a8->mUnk_40 != 5 && data_ov003_021da2a8->mUnk_40 != 4) {
        func_ov003_021d07b0(3);
        func_ov003_021cfb80();
        return;
    }
    func_ov003_021d07b0(3);
    switch (data_ov003_021da2a8->mUnk_44) {
        case 3:
            if (func_ov003_021d0258() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 1:
        case 5:
            if (func_ov003_021d022c() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 2:
            if (func_ov003_021d0358() == 0) {
                func_ov003_021cfb80();
            }
            break;
        case 0:
        case 4:
            if (func_ov003_021d032c() == 0) {
                func_ov003_021cfb80();
            }
            break;
    }
}
