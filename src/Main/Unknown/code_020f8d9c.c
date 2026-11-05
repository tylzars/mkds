#include "Main/Unknown/code_020f8d9c.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109110.h"

#pragma thumb on

void InitItemObject(ItemObject *a, u32 b, int c) {
    a->mUnk_48 = b;
    func_020e0650((u32 *) &a->mUnk_104);
    InitSoundSource(&a->mSoundSource, gItemKinds[c].mUnk_a0, &a->mPos);
    func_02109054(&a->mSoundSource);
}

#pragma thumb off
