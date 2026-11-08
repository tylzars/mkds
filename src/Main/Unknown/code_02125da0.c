#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02198854.h"

#pragma thumb on

void func_02125de0(void *heap, Unk02125de0Arg *config) {
    TxtSystemArgs txtConfig;

    data_0217d3ec = HeapAlloc(heap, 0x814);
    data_0217d3ec->mSubCharOffset = 0x5800;
    data_0217d3ec->mUseTxtSystem = FALSE;
    data_0217d3ec->mUseSelectChoises = FALSE;
    data_0217d3ec->mUnk_08 = FALSE;
    if (config->mUnk_00 != FALSE) {
        txtConfig.mFont = (u32) config->mUnk_04;
        txtConfig.mUseCanvas1 = config->mUnk_08;
        txtConfig.mUseCanvas2 = config->mUnk_0c;
        txtConfig.mUseCanvas3 = config->mUnk_10;
        txtConfig.mSubCharOffset = data_0217d3ec->mSubCharOffset;
        data_0217d3ec->mUseTxtSystem = TRUE;
        data_0217d3ec->mSubCharOffset = InitTxtSystem(heap, &txtConfig);
    }
    if (config->mUnk_14 != FALSE) {
        data_0217d3ec->mUseSelectChoises = TRUE;
        data_0217d3ec->mSubCharOffset = InitSelectChoises(heap, config->mUnk_18, data_0217d3ec->mSubCharOffset);
    }
    if (config->mUnk_1c != FALSE) {
        data_0217d3ec->mUnk_08 = TRUE;
        data_0217d3ec->mSubCharOffset = InitSelectReturn(heap, data_0217d3ec->mSubCharOffset);
    }
    if (config->mUnk_20 != FALSE) {
        data_0217d3ec->mBackScreenKind = config->mUnk_24;
        func_02125ba4();
        data_0217d3ec->mSubCharOffset = LoadBackScreen(data_0217d3ec->mSubCharOffset);
    }
}

#pragma thumb off

#pragma thumb on

void func_02125da0(void) {
    if (data_0217d3ec->mUseTxtSystem != FALSE) {
        ClearTxtSystemPointer();
    }
    if (data_0217d3ec->mUseSelectChoises != FALSE) {
        ClearSelectChoisesPointer();
    }
    if (data_0217d3ec->mUnk_08 != FALSE) {
        ClearSelectReturnPointer();
    }
    *&data_0217d3ec = NULL;
}

#pragma thumb off
