#include "01/code_0219efec.h"
#include "01/code_0219f6a0.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02148ca0.h"

s32 func_ov001_0219f31c(void) {
    s32 i;
    s32 ok = 1;
    s32 result;
    s32 out;

    for (i = 0; i < 8; i++) {
        ok &= func_0205fd78((u8) (data_ov001_021ca410->mUnk_4c + 1), (u8) (i + 1), &out);
    }
    result = func_0205fd78((u8) (data_ov001_021ca410->mUnk_4c + 1), 9, &out);
    if (ok != 0 && result == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0219f2a4(void) {
    s32 i;
    s32 j;
    s32 count;

    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    i = 0;
    data_ov001_021ca410->mUnk_20 = 0;
    data_ov001_021ca410->mUnk_24 = 0;
    data_ov001_021ca410->mUnk_44 = -192;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = 0x100;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = 0x100;
    }
}

void func_ov001_0219f260(void) {
    data_ov001_021ca410->mUnk_20 = 1;
    data_ov001_021ca410->mUnk_24 = 0;
    if (func_020cccb4() == 0x13) {
        data_ov001_021ca410->mUnk_48 = -256;
    } else {
        data_ov001_021ca410->mUnk_48 = 0x100;
    }
}

void func_ov001_0219f244(void) {
    data_ov001_021ca410->mUnk_20 = 2;
    data_ov001_021ca410->mUnk_24 = 0;
    func_02128374();
}

void func_ov001_0219f230(void) {
    data_ov001_021ca410->mUnk_20 = 3;
    data_ov001_021ca410->mUnk_24 = 0;
}

void func_ov001_0219f1f4(void) {
    data_ov001_021ca410->mUnk_20 = 4;
    data_ov001_021ca410->mUnk_24 = 0;
    data_ov001_021ca410->mUnk_48 = 0x100;
    func_ov001_0219f37c();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_0219f198(void) {
    data_ov001_021ca410->mUnk_20 = 5;
    data_ov001_021ca410->mUnk_24 = 0;
    switch (data_ov001_021ca410->mUnk_58) {
        case 1:
            if (func_ov001_0219f31c() != 0) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_02105980(4, 10);
            break;
    }
}

void func_ov001_0219f058(void *param_1, void *param_2, void *param_3) {
    s32 i;
    s32 remaining;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x9004;
    {
        void *heap = func_02036948(param_1);

        data_ov001_021ca410 = func_02036bec(heap, 0x5c);
        data_ov001_021ca410->mUnk_18 = heap;
    }
    data_ov001_021ca410->mUnk_1c = 0;
    data_ov001_021ca410->mUnk_50 = param_2;
    data_ov001_021ca410->mUnk_54 = param_3;
    data_ov001_021ca410->mUnk_58 = 0;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_28[i] = 0;
    }
    if (data_0217b488->mUnk_14 != 0) {
        data_ov001_021ca410->mUnk_4c = 6;
        data_0217b488->mUnk_14 = 0;
        func_02105a30(2);
    } else {
        data_ov001_021ca410->mUnk_4c = func_02029608() - 1;
        if (func_020cccb4() == 0x1f) {
            func_02105a30(1);
        } else {
            func_02105a30(0);
        }
    }
    func_ov001_0219f3a4();
    func_ov001_0219f6e0();
    func_020ae6d4(data_ov001_021ca410->mUnk_50, data_ov001_021ca410->mUnk_54);
    func_02124ed0(data_ov001_021ca410->mUnk_18, data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_0c,
                  &data_ov001_021ca410->mUnk_10);
    remaining = func_02148ca0();
    for (i = 0; i < 7; i++) {
        remaining -= func_021243ac(data_ov001_021ca410->mUnk_18, data_ov001_021a6c60[i], data_ov001_021ca410->mUnk_0c,
                                   data_ov001_021a6c70[i], data_ov001_021a6c80[i], data_ov001_021a6ce0[i][7],
                                   data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_04,
                                   data_ov001_021ca410->mUnk_10, remaining);
    }
    func_ov001_0219f4f8();
    func_ov001_0219f2a4();
    func_02036820((void *) data_ov001_021ca410->mUnk_18);
}

void func_ov001_0219efec(void) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x1800;
    switch (data_ov001_021ca410->mUnk_58) {
        case 1:
            if (func_ov001_0219f31c() != 0) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_0210593c(4);
            break;
    }
    func_02036ab0((void *) data_ov001_021ca410->mUnk_18);
    data_ov001_021ca410 = 0;
}
