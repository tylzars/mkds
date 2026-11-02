#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d8c.h"
#include "Main/Unknown/code_02027f68.h"
#include "Main/Unknown/code_02028ff8.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"

#pragma optimize_for_size on
#pragma thumb on
void func_02028fac(void) {
    Unk02174e50_24 *p;
    s32 i;
    s32 n;
    if (func_020280dc() == 0) {
        p = &data_02174e18->mUnk_064;
        n = func_02029000(p->mUnk_0c) + func_02028ff8(p->mUnk_14);
        for (i = 0; i < n; i++) {
            p->mUnk_18[i].mUnk_06 = func_02025ebc(&data_02174e18->mUnk_0ec);
        }
    }
}

u32 func_02028f84(void) {
    u32 r = 0;
    if (data_02174e18->mUnk_0fc != 0 && func_0202b8c0() != 0) {
        r = 1;
    }
    return r;
}

void func_02028f20(void) {
    s32 i;
    Unk02174e50_24 *p;
    void *v;
    if (func_020280dc() == 0) {
        v = func_020b3f7c(data_02174e18->mUnk_088, func_02025d98(data_02174e18->mUnk_0a8));
        p = &data_02174e18->mUnk_064;
        for (i = 8; i >= 7; i--) {
            func_0212426c(1, data_usa_021537f4[i].mUnk_00, p->mUnk_14, v, p->mUnk_0c, p->mUnk_18);
        }
    }
}
#pragma thumb off
