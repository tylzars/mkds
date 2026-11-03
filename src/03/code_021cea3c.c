#include "03/code_021cea3c.h"
#include "03/code_021ce5b8.h"
#include "03/code_021ceb54.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1770.h"

#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "code_0214a348.h"
#include "registers.h"

void func_ov003_021ceaf8(Unk021d34e0 *a) {
    u32 w;
    s32 h;

    func_ov003_021d1770(data_ov003_021da284->mUnk_00, 0, &w, &h);
    h += 0xc;
    func_ov003_021cec50(h);
    if (h >= 192) {
        if (data_ov003_021da284->mUnk_1e != 0) {
            func_ov003_021d34e0(a, func_ov003_021ceab8);
            return;
        }
        func_ov003_021d34e0(a, func_ov003_021cea3c);
    }
}

void func_ov003_021ceab8(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1a++;
    func_0214a348((u16 *) 0x04000050, data_ov003_021da284->mUnk_1a);
    if (data_ov003_021da284->mUnk_1a >= 0) {
        func_ov003_021d34e0(a, func_ov003_021cea3c);
    }
}

void func_ov003_021cea3c(u32 a) {
    s32 i;

    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    func_ov003_021d197c(data_ov003_021da284->mUnk_00);
    func_ov003_021d197c(data_ov003_021da284->mUnk_04);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        if (data_ov003_021da284->mUnk_08[i] != NULL) {
            func_ov003_021d197c(data_ov003_021da284->mUnk_08[i]);
        }
    }
    func_ov003_021d2388((s32) data_ov003_021da284->mUnk_10);
    func_ov003_021d34c8(1, a);
    func_ov003_021d2808(&data_ov003_021da284);
}
