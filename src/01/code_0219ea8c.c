#include "01/code_0219ea8c.h"
#include "01/code_0219f6a0.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"
#include "code_0201ea58.h"

void func_ov001_0219ec38(void) {
    u32 sel = -1;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 f2;
    s32 f1;
    s16 n;

    func_021059e0();
    f2 = 0;
    f1 = 0;
    if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
        f1 = 1;
    }
    if (f1 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
        f2 = 1;
    }
    if (f2 != 0) {
        sel = func_0201ea84(data_ov001_021ca410->mUnk_08, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        s32 g2 = 0;
        s32 g1 = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            g1 = 1;
        }
        if (g1 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            g2 = 1;
        }
        if (g2 == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(0xe);
    func_ov001_0219f198();
    data_ov001_021ca410->mUnk_48 = 0x100;
    data_ov001_021ca410->mUnk_58 = 2;
    func_02128310(0);
    return;
next:
    if (sel <= 6) {
        n = data_ov001_021a6c90[sel];
        if (func_ov001_0219f688(n) != 0) {
            data_ov001_021ca410->mUnk_4c = n;
            data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
            func_ov001_0219f1f4();
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
        data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
        func_ov001_0219f1f4();
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (data_ov001_021a6ca0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6ca0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        if (data_ov001_021a6cb0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cb0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        if (data_ov001_021a6cc0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cc0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (data_ov001_021a6cd0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cd0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    }
}

void func_ov001_0219ebfc(void) {
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    func_021059e0();
    if (data_ov001_021ca410->mUnk_24 >= 5) {
        func_ov001_0219f198();
        data_ov001_021ca410->mUnk_48 = -256;
        data_ov001_021ca410->mUnk_58 = 1;
    }
}

void func_ov001_0219eb60(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    value = func_020ae4c0(1, 0, data_ov001_021ca410->mUnk_48, data_ov001_021ca410->mUnk_24, 10);
    data_ov001_021ca410->mUnk_44 = func_020ae4c0(1, 0, -192, data_ov001_021ca410->mUnk_24, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = value;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = value;
    }
}

s32 func_ov001_0219ead4(void) {
    data_ov001_021ca410->mUnk_1c = data_ov001_021ca410->mUnk_20;
    switch (data_ov001_021ca410->mUnk_1c) {
        case 0:
            func_ov001_0219efd0();
            break;
        case 1:
            func_ov001_0219ef24();
            break;
        case 2:
            func_ov001_0219ef08();
            break;
        case 3:
            func_ov001_0219ec38();
            break;
        case 4:
            func_ov001_0219ebfc();
            break;
        case 5:
            func_ov001_0219eb60();
            break;
    }
    func_ov001_0219f430();
    func_02124c30(data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_0c,
                  data_ov001_021ca410->mUnk_54, data_ov001_021ca410->mUnk_10);
    if (data_ov001_021ca410->mUnk_1c == 5 && data_ov001_021ca410->mUnk_24 >= 10) {
        return data_ov001_021ca410->mUnk_58;
    }
    return 0;
}

void func_ov001_0219eab4(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021ca410->mUnk_44 << 16) & 0x1ff0000;
}

void func_ov001_0219ea8c(void) {
    void *heap = func_020364e0(func_020364e8());

    data_ov001_021ca40c = func_02036bec(heap, 4);
    func_ov001_0219e6ec(heap);
}
