#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_0202f0a0(Unk02175628_48 *p0) {
    return p0->mPairX;
}

u32 func_0202f080(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_0202f0a0;
    value0 = (value1) + (0x48u);
    value0 = func_0202f0a0((Unk02175628_48 *) value0);
    return value0;
}

u32 func_0202f078(Unk02175628_48 *p0) {
    return p0->mPairY;
}

u32 func_0202f058(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_0202f078;
    value0 = (value1) + (0x48u);
    value0 = func_0202f078((Unk02175628_48 *) value0);
    return value0;
}
