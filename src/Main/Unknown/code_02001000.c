#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0200104c(void) {
    data_0217aa00->mUnk_0004 = 2;
    data_0217aa00->mUnk_0044.mUnk_3e = 0;
    data_0217aa00->mUnk_008b &= ~8;
}

void func_02001000(void) {
    u8 v1;
    v1 = data_0217aa00->mUnk_008a;
    if (v1 == 0) {
        return;
    }
    if (QueueMPDataHalfwordAndWord(7, data_0217aa00->mUnk_0044.mUnk_43, v1) == FALSE) {
        return;
    }
    DisconnectChildren(v1);
}
