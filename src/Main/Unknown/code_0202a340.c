#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_0202a340(s16 *a, int b) {
    Unk0217aa1c_144_00 *v1;
    v1 = &data_0217b488->mUnk_98[b];
    func_02025cd0(((s16 *) a), v1->mUnk_02, v1->mUnk_03, (u32) (data_0217b488->mUnk_98[b].mUnk_00));
}

#pragma thumb off
