#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_02025000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"

#pragma thumb on

void func_0202a340(s16 *a, int index) {
    Unk0217aa1c_144_00 *entry;
    entry = &data_0217b488->mUnk_98[index];
    func_02025cd0((a), entry->mUnk_02, entry->mUnk_03, data_0217b488->mUnk_98[index].mUnk_00);
}

#pragma thumb off
