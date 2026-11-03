#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020be7e8.h"

#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020be930.h"

void func_020be930(int a) {
    data_0217b3d8->mUnk_0fc[a].mUnk_00 = 0;
}

void func_020be8e4(s32 i, s32 a, s32 b) {
    data_0217b3d8->mUnk_0fc[i].mUnk_00 = 1;
    data_0217b3d8->mUnk_0fc[i].mUnk_04 = a;
    data_0217b3d8->mUnk_0fc[i].mUnk_08 = b;
}

void func_020be7fc(void) {
    u8 i;

    data_0217b3d8 = HeapAlloc(GetHeap(func_020364e8()), 0x15c);
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        data_0217b3d8->mUnk_080[i] = 1;
        data_0217b3d8->mUnk_060[i] = data_0217b3d8->mUnk_080[i];
        data_0217b3d8->mUnk_0a0[i] = 0;
        data_0217b3d8->mUnk_0c0[i] = 0;
    }
    data_0217b3d8->mUnk_0e0 = 0;
    data_0217b3d8->mUnk_0e4 = 0;
    data_0217b3d8->mUnk_0e8[0] = 0xc4e;
    data_0217b3d8->mUnk_0e8[1] = 0;
    data_0217b3d8->mUnk_0e8[2] = 0;
    data_0217b3d8->mUnk_0e8[3] = 0xc4e;
    data_0217b3d8->mUnk_0f8 = 0;
}

u32 func_020be7e8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3d8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
