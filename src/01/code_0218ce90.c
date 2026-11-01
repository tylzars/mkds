#include "01/code_0218ce90.h"
#include "01/code_0218cfe8.h"
#include "01/code_0218d280.h"
#include "01/code_021864ac.h"
#include "01/code_02187098.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"

void func_ov001_0218cf94(Unk0218d87c *param_1) {
    int i;
    Unk02188950 *p;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (p = param_1->mUnk_00[i]) != 0; i++) {
            p->mUnk_2c4 = 1;
            if (func_02062ec4() != 0) {
                func_ov001_0218d188(p);
            } else {
                func_ov001_0218d1e0(p);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218d280);
}

void func_ov001_0218cedc(u32 param_1, Unk02188950 *param_2) {
    int r;

    if (data_021759c0->mUnk_08 == 4) {
        r = func_020a126c();
    } else {
        r = 0;
    }
    if (r != 0) {
        if (func_ov001_021871f8(param_2, 1) != 0) {
            if (data_021759c0->mUnk_08 == 4) {
                r = func_020a1084((u16) data_021759c0->mUnk_62);
            } else {
                r = 0;
            }
            if (r != 0) {
                func_ov001_0218d374(param_2);
            } else {
                func_ov001_0218d2c4(param_2);
            }
        }
    } else {
        if (func_ov001_021871f8(param_2, 1) != 0) {
            func_ov001_0218d3ec(param_2);
        }
    }
    if (func_020d2c2c((Vec3 *) &param_2->mUnk_238, &param_2->mUnk_000.mUnk_10, param_2->mUnk_0a0->mUnk_100,
                      param_2->mUnk_000.mUnk_64, 9, 0) == 2) {
        func_020d2774(&param_2->mUnk_000, (u32) (0x253));
    }
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218ce90(Unk0218d87c *param_1) {
    int i;
    Unk02188950 *p;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (p = param_1->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4() != 0) {
                func_ov001_0218d01c(p);
            } else if (i == 0) {
                func_ov001_0218d074(p);
            } else {
                func_ov001_0218cfe8((int) p);
            }
        }
    }
}
