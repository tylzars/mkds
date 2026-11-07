#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ccc74(s32 a, s32 b) {
    data_0217b43c->mUnk_000 = 0;
    data_0217b43c->mUnk_004 = 1;
    data_0217b43c->mUnk_008 = data_0217b43c->mScreenNumber;
    data_0217b43c->mScreenNumber = a;
    data_0217b43c->mUnk_010 = b;
}
#pragma thumb off
