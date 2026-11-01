#include "Main/Unknown/code_020019b0.h"

void func_02001d30(Unk02001d30 *a, s32 b, const char *c, const char *d, const char *e) {
    func_020b4a7c(&a->mUnk_00, func_0204799c(c));
    func_0200ee58(a->mUnk_00->mUnk_0c, a->mUnk_00->mUnk_08);
    if (b != 0) {
        func_0214c160(a->mUnk_00->mUnk_0c, 0, a->mUnk_00->mUnk_08);
    } else {
        func_0214c0f8(a->mUnk_00->mUnk_0c, 0, a->mUnk_00->mUnk_08);
    }
    func_020b49f4(&a->mUnk_04, func_0204799c(d));
    func_0200ee58(a->mUnk_04->mUnk_14, a->mUnk_04->mUnk_10);
    if (b != 0) {
        func_0214ba2c(a->mUnk_04->mUnk_14, 0, a->mUnk_04->mUnk_10);
    } else {
        func_0214b9c4(a->mUnk_04->mUnk_14, 0, a->mUnk_04->mUnk_10);
    }
    func_020b4810(&a->mUnk_08, func_0204799c(e));
    func_0200ee58(a->mUnk_08->mUnk_0c, a->mUnk_08->mUnk_08);
    if (b != 0) {
        func_0214bd6c(a->mUnk_08->mUnk_0c, 0, a->mUnk_08->mUnk_08);
    } else {
        func_0214bd04(a->mUnk_08->mUnk_0c, 0, a->mUnk_08->mUnk_08);
    }
}

void func_02001ba0(void *a) {
    Unk02125de0Arg v1;
    u8 *v2;
    data_usa_ov001_021a99c0 = func_02036bec(a, 60);
    v2 = func_02038d88(a, data_usa_021547c8);
    func_02038d28(v2 + 0x28, 1, 0, 0, 0, 0, 1, 0);
    func_02038d28(v2 + 0x70, 1, 0, 0, 0, 0, 2, 0);
    func_02037abc(v2);
    func_02001d30(&data_usa_ov001_021a99c0->mUnk_00, 1, data_usa_ov001_021a768c, data_usa_ov001_021a76a8,
                  data_usa_ov001_021a76c4);
    func_02001d30(&data_usa_ov001_021a99c0->mUnk_0c, 0, data_usa_ov001_021a76dc, data_usa_ov001_021a76f4,
                  data_usa_ov001_021a770c);
    func_02046be8(&data_usa_ov001_021a99c0->mUnk_18, (UnkFunc *const *) 0x02001080, 12, 0);
    data_usa_ov001_021a99c0->mUnk_2c_0 = 0;
    data_usa_ov001_021a99c0->mUnk_30 = 0;
    data_usa_ov001_021a99c0->mUnk_38 = func_02047a28(data_usa_ov001_021a7720);
    v1.mUnk_00 = 1;
    v1.mUnk_04 = func_020b403c(1);
    v1.mUnk_08 = 0;
    v1.mUnk_10 = 0;
    v1.mUnk_14 = 0;
    v1.mUnk_18 = 0;
    v1.mUnk_1c = 0;
    v1.mUnk_20 = 0;
    v1.mUnk_24 = 0;
    v1.mUnk_0c = 1;
    func_02125c2c();
    func_02125de0(a, &v1);
}

void func_02001b38(void) {
    s32 v1;
    s32 v2;
    v1 = 0;
    data_usa_ov001_021a99c0 = 0;
    v2 = data_0217aa08->mUnk_00->mUnk_31_1;
    switch (v2) {
        case 1:
            break;
        case 2:
            v1 = 2;
            break;
        case 0:
        default:
            v1 = 1;
            break;
    }
    func_02108e94(v1);
    func_02125da0();
}

void func_02001abc(void) {
    s32 v1;
    s32 v2;
    v1 = 0;
    func_021258f0();
    v2 = data_usa_ov001_021a99c0->mUnk_30;
    if (v2 > 90) {
        v1 = (-(v2 - 90) * 16) / 30;
    }
    func_0214a3e8((u16 *) 0x04000050, 2, v1);
    func_0214a3e8((u16 *) 0x04001050, 2, v1);
}

void func_02001a74(Unk02001a74 *a) {
    func_02046b40(&data_usa_ov001_021a99c0->mUnk_18);
    if (a != 0 && data_usa_ov001_021a99c0->mUnk_18.mUnk_0e == 11) {
        a->mUnk_04 = 0;
    }
    func_02125928();
}

void func_02001a44(void) {
    func_02056f98();
    data_usa_ov001_021a99c0->mUnk_2c_1 = 0;
}

void func_020019b0(void) {
    s32 v1;
    Unk021a99c0_18 *v2;
    data_usa_ov001_021a99c0->mUnk_30 = data_usa_ov001_021a99c0->mUnk_30 + 1;
    if (data_usa_ov001_021a99c0->mUnk_30 > 120) {
        v2 = &data_usa_ov001_021a99c0->mUnk_18;
        v2->mUnk_10 = 1;
        v2->mUnk_12 = 1;
    }
    v1 = func_020435bc();
    if ((data_02175628[v1].mUnk_02 & 0xf03) != 0xf03) {
        return;
    }
    data_usa_ov001_021a99c0->mUnk_2c_0 = 1;
}
