#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02089e10.h"
#include "registers.h"

void func_02089d70(Unk0217b034_784 *a) {
    u32 *v1;
    u32 *v2;
    v1 = ((u32 *) 0x0400046cu);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | a->mUnk_02 << 0x10;
    *v1 = 0x8c000;
    *v1 = 0x6e000;
    v2 = ((u32 *) 0x04000500u);
    *v1 = 0xa000;
    *v2 = 1;
    reg_G3_COLOR = (u32) a->mUnk_04;
    func_02089e10(0);
    func_02089e10(1);
    func_02089e10(2);
    func_02089e10(3);
    reg_G3_END_VTXS = 0;
}
