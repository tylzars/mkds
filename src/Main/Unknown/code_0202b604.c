#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"

#include "Main/Unknown/code_0202cb2c.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202a92c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b47d8.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025ebc.h"

#pragma thumb on

void func_0202bb60(void) {
    func_02036ab0((void *) data_02174e3c->mUnk_03c);
    *&data_02174e3c = 0;
}

#pragma thumb off

#pragma thumb on

void func_0202ba14(void) {
    u32 a = 0x19;
    s32 b;
    s16 x;

    x = func_02025ebc(&data_02174e3c->mUnk_210[2]);
    if (data_02174e3c->mUnk_254 == 2) {
        b = 0;
        a |= 2;
        *(vu32 *) 0x4000010 = x & 0x1ff;
        *(vu32 *) 0x4000014 = -x & 0x1ff;
        *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
        *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 3;
    } else {
        b = 1;
    }
    if (data_02174e3c->mUnk_250 == 2) {
        a |= 2;
    }
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    func_02148950(1, 0, b);
    if (data_02174e3c->mUnk_254 == 2) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x6000;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & ~0x3f) | 0x1d) | 0x20;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & 0xffffc0ff) | 0x1e00) | 0x2000;
        *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0x1c) | 0x20;
        *(vu16 *) 0x4000040 = 0x80;
        *(vu16 *) 0x4000044 = 0xc0;
        *(vu16 *) 0x4000042 = 0x8000;
        *(vu16 *) 0x4000046 = 0xc0;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
    }
}

void func_0202b8d8(void) {
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk02021dc8 *c;
    Unk020b47d8 *d;

    if (*(vu16 *) 0x27ffc40 == 2) {
        LoadNcgrData(&a, FindSceneFile(data_usa_021626d0));
        LoadNcgrData2(&a, FindSceneFile(data_usa_021626f8));
        LoadNcerData(&c, FindSceneFile(data_usa_02162720));
        LoadNclrData(&b, FindSceneFile(data_usa_02162748));
        LoadNclrData(&b, FindSceneFile(data_usa_02162770));
        LoadNscrData(&d, FindSceneFile(data_usa_02162798));
        LoadNscrData(&d, FindSceneFile(data_usa_021627c4));
    } else {
        LoadNcgrData(&a, func_02047a28(data_usa_021627f0));
        LoadNcgrData2(&a, func_02047a28(data_usa_0216280c));
        LoadNcgrData2(&a, func_02047a28(data_usa_02162828));
        LoadNcerData(&c, func_02047a28(data_usa_0216284c));
        LoadNcerData(&c, func_02047a28(data_usa_02162868));
        LoadNclrData(&b, func_02047a28(data_usa_0216288c));
        LoadNclrData(&b, func_02047a28(data_usa_021628a8));
        LoadNscrData(&d, func_02047a28(data_usa_021628c4));
        LoadNscrData(&d, func_02047a28(data_usa_021628e4));
    }
}

#pragma thumb off

#pragma thumb on

u32 func_0202b8c0(void) {
    if (data_02174e3c->mUnk_040 == 0) {
        return 1;
    }
    return 0;
}

u32 func_0202b888(void) {
    u32 v1;
    int v2;
    int v3;
    int v4;
    v1 = 1;
    v2 = 0;
    if (0 < data_02174e3c->mUnk_048) {
        v3 = 0;
        do {
            v4 = ((u32) func_02029930());
            v1 = v1 & *(u32 *) (v4 + v3 + 0x14);
            v3 = v3 + 0x18;
            v2 = v2 + 1;
        } while (v2 < *(s32 *) (*(s32 *) &data_02174e3c + 0x48));
    }
    return v1;
}

#pragma thumb off

#pragma thumb on

void func_0202b7c0(s32 a) {
    s32 i;

    func_02025f14(&data_02174e3c->mUnk_210[0], 2);
    func_02025f14(&data_02174e3c->mUnk_210[3], 2);
    func_02025f14(&data_02174e3c->mUnk_210[2], 2);
    switch (a) {
        case 0:
        case 1:
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    func_0202cc18(i, 1);
                }
            }
            break;
        case 2:
            func_02025f14(&data_02174e3c->mUnk_210[1], 2);
            break;
        case 3:
            for (i = 0; i < 8; i++) {
                func_0202cb2c(i);
            }
            data_02174e3c->mUnk_20c = 1;
            break;
    }
}

void func_0202b6f0(s32 a) {
    s32 i;
    s32 k;

    if (data_02174e3c->mUnk_204 != a) {
        if (a != 0) {
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    if (data_02174e3c->mUnk_04c[i].mUnk_00 == 0) {
                        k = 1;
                    } else if (data_02174e3c->mUnk_04c[i].mUnk_00 == 1) {
                        k = 2;
                    }
                    func_0202cc18(i, k);
                }
            }
            func_02025f14(&data_02174e3c->mUnk_210[2], 0);
            func_02025f14(&data_02174e3c->mUnk_210[0], 2);
        } else {
            for (i = 0; i < 8; i++) {
                if (i < data_02174e3c->mUnk_048 || data_02174e3c->mUnk_208 != 0) {
                    func_0202cc18(i, 1);
                }
            }
            func_02025f14(&data_02174e3c->mUnk_210[2], 2);
            func_02025f14(&data_02174e3c->mUnk_210[0], 0);
        }
    }
    data_02174e3c->mUnk_204 = a;
}

#pragma thumb off

#pragma thumb on

void func_0202b6a0(int a, int b) {
    u32 v1;
    if ((data_02174e3c->mUnk_204 != 0) && (b != data_02174e3c->mUnk_04c[a].mUnk_00)) {
        if (b == 1) {
            v1 = 2;
        } else {
            v1 = 1;
        }
        func_0202cc18(a, v1);
    }
    data_02174e3c->mUnk_04c[a].mUnk_00 = b;
}

#pragma thumb off

#pragma thumb on

void func_0202b618(s32 a) {
    s32 i;
    s32 b;
    if (data_02174e3c->mUnk_208 != a) {
        if (a != 0) {
            for (i = data_02174e3c->mUnk_048; i < 8; i++) {
                if (data_02174e3c->mUnk_204 != 0) {
                    if (data_02174e3c->mUnk_04c[i].mUnk_00 == 1) {
                        b = 3;
                    } else {
                        b = 0;
                    }
                } else {
                    b = 0;
                }
                func_0202cc44(i, b);
                func_0202cb68(i);
            }
        } else {
            for (i = data_02174e3c->mUnk_048; i < 8; i++) {
                func_0202cb2c(i);
            }
        }
    }
    data_02174e3c->mUnk_208 = a;
}

#pragma thumb off

#pragma thumb on
void func_0202b604(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 1u;
    value0 = (u32) &data_02174e3c;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x1fcu;
    *(u32 *) ((value1) + (value0)) = value2;
}
#pragma thumb off
