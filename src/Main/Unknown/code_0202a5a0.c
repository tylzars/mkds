#include "Main/Unknown/code_0202a5a0.h"
#include "Main/Unknown/code_02029a90.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02032aa8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0212a000.h"

#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214a390.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void func_0202a658(void *a) {
    data_02174e24 = HeapAlloc(a, 0x80c);
    MemFillWordsByBlock_inline(data_02174e24, 0x80c);
    func_020ae6d4(data_02174e24, data_02174e24->mUnk_404);
    data_02174e24->mUnk_808 = data_021759c0->mMode;
    if (data_02174e24->mUnk_808 == 0) {
        func_02029dcc(a, data_02174e24, data_02174e24->mUnk_404);
    } else {
        func_02032f94(a, (s32) data_02174e24, (s32) data_02174e24->mUnk_404);
    }
    func_0212abdc(a, data_02174e24);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    G2x_SetBlendAlpha_((u32 *) 0x04000050, 1, 0x3f, 8, 8);
    G2x_SetBlendAlpha_((u32 *) 0x04001050, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
}

#pragma thumb off

#pragma thumb on

void func_0202a604(u32 a) {
    int v1;
    v1 = func_02049b6c();
    if (v1 == 0) {
        func_020ae6ac(data_02174e24, data_02174e24->mUnk_404);
        if (data_02174e24->mUnk_808 == 0) {
            func_02029aa0((Unk02029aa0 *) a);
        } else {
            func_02032ac4((Unk02032ac4 *) a);
        }
        func_020ae630(data_02174e24, data_02174e24->mUnk_404);
        func_0212a920();
    }
}

void func_0202a5d8(void) {
    if (data_02174e24->mUnk_808 == 0) {
        func_02029a98();
    } else {
        func_02032ab0();
    }
    func_0212abd0();
}

void func_0202a5a0(void) {
    if (data_02174e24->mUnk_808 == 0) {
        func_02029a90();
    } else {
        func_02032aa8();
    }
    func_020ae5f0(data_02174e24, data_02174e24->mUnk_404);
}

#pragma thumb off
