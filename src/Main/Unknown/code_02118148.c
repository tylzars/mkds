#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_021184d4(void) {
    u16 v;
    s16 b;
    int i;

    if (func_021185d4() != 0) {
        if (data_0217d360->mUnk_6c == 7) {
            data_0217d360->mUnk_70 = data_0217d360->mUnk_44;
            func_02118624();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            v = data_0217d360->mUnk_04->mUnk_06;
            b = func_02116d10(7 - data_0217d360->mUnk_6c, 1);
            data_0217d360->mUnk_40 = b;
            data_0217d360->mUnk_18[19].mUnk_06 = b;
            data_0217d360->mUnk_18[2].mUnk_06 = b;
            data_0217d360->mUnk_18[1].mUnk_06 = b;
            data_0217d360->mUnk_18[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mUnk_18[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mUnk_18[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mUnk_6c = data_0217d360->mUnk_6c - 1;
    } else if (data_0217d360->mUnk_44 != data_0217d360->mUnk_70) {
        data_0217d360->mUnk_6c = 7;
    }
}

void func_02118458(void) {
    int i;

    if (*(vu16 *) 0x027ffc40 != 2) {
        for (i = 0; i < 4; i++) {
            if (data_0217d360->mUnk_78 == i) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_00 = 1;
                func_02124100(data_0215c7d8[i], 0xe, data_0217d360->mUnk_08, data_0217d360->mUnk_18,
                              data_0217d360->mUnk_04);
            } else {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_00 = 0;
                func_02124100(data_0215c7d8[i], 0xf, data_0217d360->mUnk_08, data_0217d360->mUnk_18,
                              data_0217d360->mUnk_04);
            }
        }
    }
}

void func_02118414(void) {
    data_0217d360->mUnk_74 = data_0217d360->mUnk_74 + 1;
    if (data_0217d360->mUnk_74 >= 0x4b) {
        data_0217d360->mUnk_78 = data_0217d360->mUnk_78 + 1;
        if (data_0217d360->mUnk_78 >= 4) {
            data_0217d360->mUnk_78 = 0;
        }
        data_0217d360->mUnk_74 = 0;
        func_021187d4();
    }
}

void func_02118400(void) {
    data_0217d360->mUnk_78 = 0;
    data_0217d360->mUnk_74 = 0;
}

void func_021181fc(void) {
    u16 v;
    s32 b;
    s32 c;
    int i;
    int j;

    data_0217d360->mUnk_34 = 0;
    data_0217d360->mUnk_38 = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mUnk_04->mUnk_06;
        if (func_020cccb4() == 0x18 || func_020cccb4() == 0xc) {
            b = 0;
            data_0217d360->mUnk_40 = b;
            data_0217d360->mUnk_18[20].mUnk_06 = b;
            data_0217d360->mUnk_18[19].mUnk_06 = b;
            data_0217d360->mUnk_18[2].mUnk_06 = b;
            data_0217d360->mUnk_18[1].mUnk_06 = b;
            data_0217d360->mUnk_18[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mUnk_18[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mUnk_18[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        } else {
            b = -192;
            data_0217d360->mUnk_40 = b;
            data_0217d360->mUnk_18[20].mUnk_06 = b;
            data_0217d360->mUnk_18[19].mUnk_06 = b;
            data_0217d360->mUnk_18[2].mUnk_06 = b;
            data_0217d360->mUnk_18[1].mUnk_06 = b;
            data_0217d360->mUnk_18[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mUnk_18[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mUnk_18[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mUnk_18[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        b = -192;
        data_0217d360->mUnk_18[20].mUnk_06 = b;
        c = -224;
        data_0217d360->mUnk_1c[0].mUnk_04 = c;
        data_0217d360->mUnk_1c[1].mUnk_04 = 0xe0;
        data_0217d360->mUnk_1c[2].mUnk_04 = c;
        data_0217d360->mUnk_1c[3].mUnk_04 = 0xe0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = c;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mUnk_1c[data_0215c9bc[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void func_021181e8(void) {
    data_0217d360->mUnk_34 = 1;
    data_0217d360->mUnk_38 = 0;
}

void func_021181cc(void) {
    data_0217d360->mUnk_34 = 2;
    data_0217d360->mUnk_38 = 0;
    func_02128374();
}

void func_021181b8(void) {
    data_0217d360->mUnk_34 = 3;
    data_0217d360->mUnk_38 = 0;
}

void func_02118184(void) {
    data_0217d360->mUnk_34 = 4;
    data_0217d360->mUnk_38 = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02118148(void) {
    void *a;

    data_0217d360->mUnk_34 = 5;
    data_0217d360->mUnk_38 = 0;
    a = func_020b3f7c(data_0217d360->mUnk_24, 4);
    func_021277f8(a, func_020b3f7c(data_0217d360->mUnk_24, 2), 0);
}

#pragma thumb off
