#include "Main/Unknown/code_0205bc08.h"
#include "Main/Unknown/code_0205c7a0.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0205c7a0(u32 a) {
    u8 index;
    if (a == 0xffffffff) {
        return;
    }
    index = a;
    if (data_0217aa14->mUnk_749 & (1 << index)) {
        if (func_0205c340(index, 1, 8) != 0) {
            data_0217aa14->mUnk_0f8 = index;
        }
    }
}
