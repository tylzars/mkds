#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_02125928(void) {
    if (data_0217d3ec->mUnk_00 != 0) {
        func_02126834();
    }
    if (data_0217d3ec->mUnk_04 != 0) {
        func_021279a0();
    }
    if (data_0217d3ec->mUnk_08 != 0) {
        AdvanceSelectReturn();
    }
}

void func_021258f0(void) {
    if (data_0217d3ec->mUnk_00 != 0) {
        func_02126730();
    }
    if (data_0217d3ec->mUnk_04 != 0) {
        func_021278f4();
    }
    if (data_0217d3ec->mUnk_08 != 0) {
        WriteSelectReturnRegisters();
    }
}

#pragma thumb off
