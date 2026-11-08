#include "01/code_02188218.h"
#include "01/code_02188950.h"

u16 func_ov001_02188220(Unk02188950 *mapObject) {
    s32 counter;
    counter = mapObject->mUnk_0ac;
    if (counter < 0) {
        counter = -counter;
    }
    return counter & 0xffff;
}

void func_ov001_02188218(Unk02188950 *mapObject, s32 b) {
    mapObject->mUnk_0b4 = b;
}
