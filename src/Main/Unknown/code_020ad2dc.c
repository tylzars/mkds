#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020ad2dc.h"

#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020ad820.h"
#include "Main/Unknown/code_020ad870.h"
#include "Main/Unknown/code_020ad8a4.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020ad9fc.h"
#include "Main/Unknown/code_020ada10.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"

u32 func_020ada10(void) {
    u32 value0;
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    return value0;
}

u32 func_020ad9fc(void) {
    return ((u32) data_0217b488->mUnk_00);
}

void func_020ad9c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    func_02038d28(a->mUnk_28, b, c, d, e, f, g, h);
}

void func_020ad98c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038d00(a->mUnk_28, b, c, d, e, f, g);
}

void func_020ad958(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038cd8(a->mUnk_28, b, c, d, e, f, g);
}

void func_020ad924(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_02038cd8(a->mUnk_70, b, c, d, e, f, g);
}

void func_020ad904(u32 a) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffcfffef) | a;
}

void func_020ad8e0(u32 a) {
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffcfffef) | a;
}

void func_020ad8a4(u32 a, u32 b, u32 c, u32 d) {
    func_0214a40c(((u32 *) 0x04001050u), a, b, c, d);
}

u32 func_020ad88c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4000000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_020ad870(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

void func_020ad85c(u32 p0) {
    data_0217b488->mUnk_04 = p0;
}

void func_020ad848(u32 p0) {
    data_0217b488->mUnk_08 = p0;
}

void func_020ad834(u32 p0) {
    data_0217b488->mUnk_10 = p0;
}

void func_020ad820(u32 p0) {
    data_0217b488->mUnk_14 = p0;
}

#pragma thumb on

void func_020ad344(void) {
    s32 r;
    s32 d;
    void *h;
    Unk02125de0 s;

    r = func_02090940();
    data_0217b340 = HeapAlloc((void *) func_020ada10(), 0x8bc);
    data_0217b340->mUnk_00 = 0;
    data_0217b340->mUnk_04 = 1;
    data_0217b340->mUnk_08 = 0;
    data_0217b340->mUnk_0c = 0;
    data_0217b340->mUnk_10 = 8;
    data_0217b340->mUnk_4c = 0;
    data_0217b340->mUnk_50 = func_020ad9fc() != 0;
    data_0217b340->mUnk_54 = 0;
    data_0217b340->mUnk_58 = 0;
    data_0217b340->mUnk_5c = 1;
    data_0217b340->mUnk_60 = 0;
    data_0217b340->mUnk_64 = func_020ad9fc() != 0 ? 0x6b : 0;
    func_020ad268();
    func_020adb04();
    func_020ae6d4(&data_0217b340->mUnk_b0, &data_0217b340->mUnk_4b4);
    LoadNclrData(&data_0217b340->mUnk_78, FindSceneFileWrapper(r != 0 ? data_02167e6c : data_02167e80));
    LoadNclrData(&data_0217b340->mUnk_80, FindSceneFileWrapper(data_02167e90));
    LoadNcgrData(&data_0217b340->mUnk_7c, FindSceneFileWrapper(r != 0 ? data_02167ea0 : data_02167eb4));
    LoadNcgrData(&data_0217b340->mUnk_84, FindSceneFileWrapper(data_02167ec4));
    LoadNscrData(&data_0217b340->mUnk_88, FindSceneFileWrapper(r != 0 ? data_02167ed4 : data_02167eec));
    LoadNscrData(&data_0217b340->mUnk_8c, FindSceneFileWrapper(r != 0 ? data_02167f00 : data_02167f14));
    LoadNscrData(&data_0217b340->mUnk_90, FindSceneFileWrapper(data_02167f24));
    LoadNclrData(&data_0217b340->mUnk_a0, FindSceneFileWrapper(data_02167f34));
    LoadNcgrData2(&data_0217b340->mUnk_a4, FindSceneFileWrapper(data_02167f44));
    LoadNcerData(&data_0217b340->mUnk_a8, FindSceneFileWrapper(data_02167f58));
    data_0217b340->mUnk_6c = FindSceneFileWrapper(data_02167f6c);
    data_0217b340->mUnk_70 = FindSceneFileWrapper(data_02167f7c);
    data_0217b340->mUnk_74 = FindSceneFileWrapper(data_02167f8c);
    h = func_02038d88((void *) func_020ada10(), data_02156840);
    func_020ad9c0(h, 0, 0, 0, 0, 2, 0, 0);
    func_020ad98c(h, 2, 0, 0, 1, 14, 4);
    func_020ad958(h, 3, 0, 0, 1, 15, 4);
    func_020ad924(h, 3, 0, 0, 0, 1, 6);
    func_02037abc(h);
    func_02124ed0((void *) func_020ada10(), data_0217b340->mUnk_6c, data_0217b340->mUnk_74, &data_0217b340->mUnk_68);
    func_02124a98(0, 1, data_0217b340->mUnk_a8, data_0217b340->mUnk_6c);
    func_02124a98(1, 1, data_0217b340->mUnk_a8, data_0217b340->mUnk_6c);
    func_02124a98(2, 1, data_0217b340->mUnk_a8, data_0217b340->mUnk_6c);
    func_02124a98(3, 1, data_0217b340->mUnk_a8, data_0217b340->mUnk_6c);
    func_02124a98(4, 1, data_0217b340->mUnk_a8, data_0217b340->mUnk_6c);
    d = func_02148ca0();
    d -= func_021243ac((void *) func_020ada10(), 0, data_0217b340->mUnk_74, 0x55, 0xd, 0xd, data_0217b340->mUnk_a8,
                       data_0217b340->mUnk_6c, data_0217b340->mUnk_68, d);
    func_021243ac((void *) func_020ada10(), 1, data_0217b340->mUnk_74, 0x55, 0xd, 0xe, data_0217b340->mUnk_a8,
                  data_0217b340->mUnk_6c, data_0217b340->mUnk_68, d);
    func_0212426c(1, 0, data_0217b340->mUnk_74, GetBmgEntry(FindSceneFileWrapper(data_02167f9c), 1),
                  data_0217b340->mUnk_6c, data_0217b340->mUnk_68);
    func_0212426c(1, 1, data_0217b340->mUnk_74, GetBmgEntry(FindSceneFileWrapper(data_02167fa8), 0),
                  data_0217b340->mUnk_6c, data_0217b340->mUnk_68);
    func_0214b720();
    func_0214b6a0(data_0217b340->mUnk_78->mData, 0x4000, data_0217b340->mUnk_78->mDataSize);
    func_0214b6a0(data_0217b340->mUnk_78->mData, 0x6000, data_0217b340->mUnk_78->mDataSize);
    func_0214b63c();
    func_0214b95c(data_0217b340->mUnk_7c->mData, 0, data_0217b340->mUnk_7c->mDataSize);
    func_0214bc9c(data_0217b340->mUnk_88->mData, 0, 0x800);
    func_0214bbcc(data_0217b340->mUnk_8c->mData, 0, 0x800);
    func_0214c0f8(data_0217b340->mUnk_80->mData, 0, data_0217b340->mUnk_80->mDataSize);
    func_0214b824(data_0217b340->mUnk_84->mData, 0, data_0217b340->mUnk_84->mDataSize);
    func_0214bb64(data_0217b340->mUnk_90->mData, 0, 0x800);
    func_0214c028(data_0217b340->mUnk_a0->mData, 0, data_0217b340->mUnk_a0->mDataSize);
    func_0214bea4(data_0217b340->mUnk_a4->mData, 0, data_0217b340->mUnk_a4->mDataSize);
    func_020ad904(0x10);
    func_020ad8e0(0x10);
    func_020ad2f0(4, 8, 0, 0x10);
    func_020ad8a4(0, 0x3f, 6, 10);
    func_020ad88c(0);
    func_020ad870(0);
    s.mUnk_00 = 0;
    s.mUnk_04 = NULL;
    s.mUnk_08 = 0;
    s.mUnk_0c = 0;
    s.mUnk_10 = 0;
    s.mUnk_14 = 0;
    s.mUnk_18 = func_020b403c(0);
    s.mUnk_1c = 0;
    s.mUnk_20 = 0;
    s.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0((void *) func_020ada10(), &s);
    data_0217b340->mUnk_8b8 = func_0203bedc((void *) func_020ada10());
    func_020acab8(0);
    func_0204aa28(0);
    func_020cee28();
    func_020ad85c(1);
    func_020ad848(0);
    func_020ad834(0);
    func_020ad820(0);
    func_02045590();
}

#pragma thumb off

#pragma thumb on

void func_020ad32c(void) {
    func_02125da0();
    data_0217b340 = NULL;
}

#pragma thumb off

void func_020ad2f0(u32 a, u32 b, u32 c, u32 d) {
    func_0214a40c(((u32 *) 0x04000050u), a, b, c, d);
}

void func_020ad2dc(u32 p0) {
    data_0217b488->mUnk_00 = p0;
}
