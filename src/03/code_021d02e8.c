#include "03/code_021d02e8.h"
#include "03/code_021cfb80.h"
#include "03/code_021d02c0.h"
#include "03/code_021d079c.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"

void func_ov003_021d02e8(Unk021425e8 *v1) {
    if (v1->mUnk_02 != 0) {
        func_ov003_021d079c(v1->mUnk_02);
        func_ov003_021cfb80();
    } else if (func_ov003_021d02c0() == 0) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7b18);
        }
        func_ov003_021cfb80();
    }
}
