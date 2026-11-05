#include "Main/Unknown/code_020cb2cc.h"

#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void func_020cb2d4(void) {
    Unk0217b43c *v1;
    func_020cb340();
    v1 = data_0217b43c;
    func_02124c30(v1->mSinglePlaySelectModeMBncl, v1->mSinglePlaySelectModeMNcer, NULL, v1->mUnk_108, v1->mUnk_93c);
    v1 = data_0217b43c;
    func_02124c30(v1->mSinglePlaySelectModeSBncl, v1->mSinglePlaySelectModeSNcer, NULL, v1->mUnk_50c, v1->mUnk_948);
}

#pragma thumb off

#pragma thumb on
void func_020cb2cc(void) {
    u32 value3;
    func_020cb3e4();
}
#pragma thumb off
