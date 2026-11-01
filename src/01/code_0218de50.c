#include "01/code_0218de50.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_02187cd4.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"

void func_ov001_0218de50(Unk0218d87c *param_1) {
    int i;
    Unk02188950 *p;
    Unk02188950_a0 *a0;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (p = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(p);
            }
            func_ov001_021870e4(param_1, p, (const char *) data_ov001_021a7da0, (const char *) data_ov001_021a7db4,
                                (const char *) data_ov001_021a7dc8);
            func_ov001_021870b0(param_1, p, (const char *) data_ov001_021a7dd8);
            a0 = p->mUnk_0a0;
            func_ov001_0218875c(p, (s32) (a0->mUnk_008), (s32) (a0->mUnk_00c), (s32) (a0->mUnk_240));
            func_ov001_021888a4(p, 0, 0x19000);
            func_ov001_02188200(p, func_ov001_0218f9a8);
            func_ov001_02187cd4((int) p, 0);
            p->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
            p->mUnk_2b8 = 3;
        }
    }
}
