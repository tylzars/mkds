#include "Main/Unknown/code_020d1464.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "code_02021e8c.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"

void func_020d159c(void) {
    func_0200ee74(&data_0217b4ac->mUnk_10, 0x400);
    func_0214bfcc(&data_0217b4ac->mUnk_10, 0, 0x400);
    if (data_0217b4ac->mUnk_00 == 0x1a4) {
        func_02036fec(0x78, 1);
        return;
    }
    if (data_0217b4ac->mUnk_00 != 0x77a) {
        return;
    }
    func_020371a8(0x78, 1);
}

void func_020d1464(void) {
    s32 i;
    Unk02021dc8 *a;
    u32 *w;

    data_0217b4ac = func_02036bec(func_020364e0(func_020364e8()), 0x414);
    for (i = 0; i < 0x80; i++) {
        w = (u32 *) &data_0217b4ac->mUnk_10.mUnk_000[i];
        w[0] = (w[0] & ~0xc00) | 0xc00;
    }
    data_0217b4ac->mUnk_00 = 0;
    func_020b4a7c(&data_0217b4ac->mUnk_04, func_020b47c0("ending_staffRoll_m_o_00.NCLR"));
    func_020b49f4(&data_0217b4ac->mUnk_08, func_020b47c0("ending_staffRoll_m_00.nce.ncgr"));
    a = 0;
    func_020b48ec(&a, func_020b47c0("ending_staffRoll_m_00.nce.ncer"));
    data_0217b4ac->mUnk_0c = (Unk020224e0_c *) func_02021f1c(a, 0);
    func_0214c090(data_0217b4ac->mUnk_04->mUnk_0c, 0, data_0217b4ac->mUnk_04->mUnk_08);
    func_0214bf04(data_0217b4ac->mUnk_08->mUnk_14, 0, data_0217b4ac->mUnk_08->mUnk_10);
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffcfffef) | 0x10;
}
