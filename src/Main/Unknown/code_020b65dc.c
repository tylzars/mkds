#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b65dc.h"

#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b6a18.h"
#include "code_02147cd8.h"

const Vec3 data_02156874 = {0, 0, 0};

void func_020b65f0(void) {
    UnkPair020b502c a;
    UnkPair020b502c b;
    UnkPair020b502c c;
    UnkPair020b502c d;
    UnkPair020b502c e;
    UnkPair020b502c f;

    data_0217b3c0 = HeapAlloc(func_020b6800(), 0x9c);
    data_0217b3c0->mUnk_00.mUnk_00 = 0;
    data_0217b3c0->mUnk_00.mUnk_04 = 0;
    data_0217b3c0->mUnk_10.mUnk_00 = 0;
    data_0217b3c0->mUnk_10.mUnk_04 = 0;
    data_0217b3c0->mUnk_18 = 0;
    data_0217b3c0->mUnk_1c = 0;
    data_0217b3c0->mUnk_1e = 0;
    data_0217b3c0->mUnk_20 = 0;
    data_0217b3c0->mUnk_24 = 0;
    func_020b6b54(&a, &b);
    data_0217b3c0->mUnk_2c = a;
    data_0217b3c0->mUnk_34 = b;
    data_0217b3c0->mUnk_3c = func_02147edc(b.mUnk_00 - a.mUnk_00);
    data_0217b3c0->mUnk_44 = func_02147edc(b.mUnk_04 - a.mUnk_04);
    func_020b6a98(&c, &d);
    data_0217b3c0->mUnk_4c = c;
    data_0217b3c0->mUnk_54 = d;
    data_0217b3c0->mUnk_5c = func_02147edc(d.mUnk_00 - c.mUnk_00);
    data_0217b3c0->mUnk_64 = func_02147edc(d.mUnk_04 - c.mUnk_04);
    data_0217b3c0->mUnk_28 = func_020b502c(DivFixed12(d.mUnk_00 - c.mUnk_00, 0x200000), 0xb0000);
    func_020b681c(&e, &f);
    data_0217b3c0->mUnk_6c = e;
    data_0217b3c0->mUnk_74 = f;
    data_0217b3c0->mUnk_7c = func_02147edc(f.mUnk_00 - e.mUnk_00);
    data_0217b3c0->mUnk_84 = func_02147edc(f.mUnk_04 - e.mUnk_04);
    data_0217b3c0->mUnk_8c = 0;
    data_0217b3c0->mUnk_90 = data_02156874;
}

u32 func_020b65dc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3c0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
