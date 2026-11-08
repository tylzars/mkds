#include "01/code_0218b298.h"
#include "01/code_02188218.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d275c.h"

u16 func_ov001_0218b2d4(Unk02188950 *mapObject) {
    return func_ov001_02188220(mapObject);
}

void func_ov001_0218b2b8(Unk02188950 *mapObject) {
    mapObject->mUnk_2d8 = 0xb;
    mapObject->mUnk_000.mDistanceSquaredAndFlags |= data_ov001_021a6598;
}

void func_ov001_0218b2a8(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}

void func_ov001_0218b298(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}
