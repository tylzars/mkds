#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050034.h"

u32 func_02050064(u32 p0) {
    return ((u32) data_0217aa00->mUnk_1e9c[p0]);
}

void func_02050034(u8 arg0) {
    u32 value0 = (u32) arg0;
    data_0217aa00->mUnk_15f6 = (u8) value0;
    func_02050080();
    func_02058b10();
}
