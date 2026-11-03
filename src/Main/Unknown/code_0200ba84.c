#include "Main/Unknown/code_0200ba84.h"
#include "Main/Unknown/code_0200bae0.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

void func_0200bab0(void) {
    *(u16 *) &data_0216fde4 = 0;
    data_0216fde8->mUnk_5f04 = 0;
    func_0200bc0c();
    func_0200ba44((u32) 0x14, (u32) 0);
}

u32 func_0200baa8(void) {
    return 0x5f20u;
}

void func_0200ba84(UnkFunc *p0) {
    u32 v1 = (u32) p0;
    u32 v2 = ((u32) func_0200fca0());
    u32 v3 = ((u32) (&data_0216fde8));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v5 = 0x5e0u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = ((u32) func_0200fcb4(v2));
}

#pragma thumb off
