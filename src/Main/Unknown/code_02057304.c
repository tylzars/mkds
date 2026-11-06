#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_02057498.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_02152500.h"

#pragma thumb on

void func_0205746c(s32 a, u8 *b, s32 c) {
    u8 *p;

    p = func_02057498(a, b);
    *p |= 1 << (u8) (a % 8);
}

s32 func_0205743c(s32 a, u8 *b, s32 c) {
    u8 *p;

    p = func_02057498(a, b);
    return (*p & (1 << (u8) (a % 8))) != 0 ? 1 : 0;
}

void func_02057410(s32 a, u8 *b, s32 c) {
    u8 *p;

    p = func_02057498(a, b);
    *p &= ~(1 << (u8) (a % 8));
}

s32 func_020573f8(u8 a) {
    return func_0205743c(a, data_0217aa08->mUnk_00->mUnk_26, 4);
}

void func_020573e0(s32 a) {
    func_02057410(a, data_0217aa08->mUnk_00->mUnk_26, 4);
}

s32 func_020573c8(u32 a) {
    return func_0205743c(a, data_0217aa08->mUnk_00->mUnk_2a, 2);
}

void func_02057304(s32 a) {
    u16 n;
    u8 *p;

    MI_CpuFill8(data_0217aa08->mUnk_00, 0, 0x100);
    if (a != 0) {
        n = data_021759d0->mUnk_3e;
        p = data_021759d0->mUnk_2a;
        data_0217aa08->mUnk_00->mUnk_31_0 = 1;
        MI_CpuFill8(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
        MI_CpuCopy8(p, data_0217aa08->mUnk_00->mUnk_0c, ((u32) n << 17) >> 16);
    }
    data_0217aa08->mUnk_00->mUnk_31_1 = 0;
    data_0217aa08->mUnk_00->mUnk_31_3 = 0;
    data_0217aa08->mUnk_00->mUnk_31_4 = 0;
    data_0217aa08->mUnk_00->mUnk_24 = 0x1388;
    func_0209119c();
    DWC_CreateUserData((DWCAccUserData *) data_0217aa08->mUnk_00->mUnk_4c, 0x414d434a);
}

#pragma thumb off
