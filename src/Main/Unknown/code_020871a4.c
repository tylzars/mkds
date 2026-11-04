#include "Main/Unknown/code_020871a4.h"
#include "Main/Unknown/code_02087228.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_020871c0(Unk02086098 *a, u32 b) {
    u16 v1;
    u16 *v2;
    u32 v3;
    v3 = *(u32 *) &data_0217aec4;
    v2 = (u16 *) (u32) data_0217aec8;
    *v2 = (0x00007c00u);
    v1 = func_020873e4(b);
    v2[1] = v1;
    v2[2] = 0;
    v2[3] = 0x1f;
    func_0200ee74(v2, 8);
    MemFill((void *) ((u32 *) v3), (u8) 0, (u32) (a->mUnk_04));
    func_020adddc(b, v3, (u32) 1, (u32) 2);
    func_0200ee74((const void *) v3, (0x00000100u));
    a->mUnk_0c = (void *) v3;
    a->mUnk_10 = v2;
}

void func_020871a4(Unk02086098 *a, u32 b) {
    u16 v1;
    u16 *v2;
    v2 = a->mUnk_10;
    v1 = func_020873e4(b);
    v2[1] = v1;
    func_0200ee74(v2, 8);
}

#pragma thumb off
