#include "Main/Unknown/code_0202a658.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02032f94.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214a390.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void func_0202a658(void *a) {
    data_02174e24 = func_02036bec(a, 0x80c);
    func_0214d05c_inline(data_02174e24, 0x80c);
    func_020ae6d4(data_02174e24, data_02174e24->mUnk_404);
    data_02174e24->mUnk_808 = data_021759c0->mUnk_08;
    if (data_02174e24->mUnk_808 == 0) {
        func_02029dcc(a, data_02174e24, data_02174e24->mUnk_404);
    } else {
        func_02032f94(a, (s32) data_02174e24, (s32) data_02174e24->mUnk_404);
    }
    func_0212abdc(a, data_02174e24);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    func_0214a40c((u32 *) 0x04000050, 1, 0x3f, 8, 8);
    func_0214a40c((u32 *) 0x04001050, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
}

#pragma thumb off
