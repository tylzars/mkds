#include "01/code_021a1838.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02116000.h"
#include "00/code_02182fdc.h"
#include "01/code_021a1ba0.h"
#include "01/code_021a1bb8.h"
#include "01/code_02185000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"

void func_ov001_021a1b08(void) {
    s32 i;
    s16 v;

    if (func_ov001_021a1ba0() != 0) {
        if (data_ov001_021ca418->mUnk_3c == 7) {
            data_ov001_021ca418->mUnk_40 = data_ov001_021ca418->mUnk_34;
            func_ov001_021a1bf8();
        } else {
            v = func_02116d10(7 - data_ov001_021ca418->mUnk_3c, 0);
            for (i = 0; i < 6; i++) {
                data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = v;
            }
            for (i = 0; i < 4; i++) {
                data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = v;
            }
        }
        data_ov001_021ca418->mUnk_3c -= 1;
    } else if (data_ov001_021ca418->mUnk_34 != data_ov001_021ca418->mUnk_40) {
        data_ov001_021ca418->mUnk_3c = 7;
    }
}

void func_ov001_021a1a04(void) {
    s32 i;
    s32 j;

    data_ov001_021ca418->mUnk_28 = 0;
    data_ov001_021ca418->mUnk_2c = 0;
    data_ov001_021ca418->mUnk_30 = 0xc0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = 0xc0;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = -0xc0;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = 0xc0;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = -0xe0;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void func_ov001_021a19f0(void) {
    data_ov001_021ca418->mUnk_28 = 1;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a19dc(void) {
    data_ov001_021ca418->mUnk_28 = 2;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a19c0(void) {
    data_ov001_021ca418->mUnk_28 = 3;
    data_ov001_021ca418->mUnk_2c = 0;
    func_02128374();
}

void func_ov001_021a19ac(void) {
    data_ov001_021ca418->mUnk_28 = 4;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a1978(void) {
    data_ov001_021ca418->mUnk_28 = 5;
    data_ov001_021ca418->mUnk_2c = 0;
    data_ov001_021ca418->mUnk_4c = 1;
    func_ov001_021a1bb8();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a1964(void) {
    data_ov001_021ca418->mUnk_28 = 6;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a1858(s32 param_1, void *param_2, void *param_3) {
    void *heap;
    Unk021ca418 *p;
    vu16 *bg0 = (vu16 *) 0x4000008;
    vu16 *bg1 = (vu16 *) 0x400000a;

    *bg0 = (*bg0 & ~3) | 1;
    *bg1 = (*bg1 & ~3) | 1;
    *bg0 = (*bg0 & 0x43) | 0x9004;
    *bg1 = (*bg1 & 0x43) | 0x9204;
    *(vu32 *) 0x4000010 = 0xc00000;
    *(vu32 *) 0x4000014 = 0xc00000;
    heap = func_02036948((void *) param_1);
    p = func_02036bec(heap, 0x50);
    data_ov001_021ca418 = p;
    p->mUnk_20 = heap;
    data_ov001_021ca418->mUnk_24 = 0;
    data_ov001_021ca418->mUnk_3c = 0;
    data_ov001_021ca418->mUnk_38 = 1;
    data_ov001_021ca418->mUnk_44 = param_2;
    data_ov001_021ca418->mUnk_48 = param_3;
    data_ov001_021ca418->mUnk_4c = 0;
    if (func_0202967c() != 0) {
        data_ov001_021ca418->mUnk_34 = 3;
    } else {
        data_ov001_021ca418->mUnk_34 = data_ov001_021a6f74[func_0202969c()];
    }
    data_ov001_021ca418->mUnk_40 = data_ov001_021ca418->mUnk_34;
    func_ov001_021a1d78();
    func_020ae6d4(data_ov001_021ca418->mUnk_44, data_ov001_021ca418->mUnk_48);
    func_02124ed0(data_ov001_021ca418->mUnk_20, data_ov001_021ca418->mUnk_04, 0, &data_ov001_021ca418->mUnk_14);
    func_02124ed0(data_ov001_021ca418->mUnk_20, data_ov001_021ca418->mUnk_0c, 0, &data_ov001_021ca418->mUnk_18);
    func_ov001_021a1cb0();
    func_ov001_021a1bf8();
    func_ov001_021a1a04();
    func_02036820((void *) data_ov001_021ca418->mUnk_20);
}

void func_ov001_021a1838(void) {
    func_02036ab0((void *) data_ov001_021ca418->mUnk_20);
    data_ov001_021ca418 = 0;
}
