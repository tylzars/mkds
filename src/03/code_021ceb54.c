#include "03/code_021ceb54.h"
#include "03/code_021ceaf8.h"
#include "03/code_021d1970.h"
#include "03/code_021d1000.h"
#include "03/code_021d250c.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2acc.h"
#include "03/code_021d3544.h"
#include "03/code_021d34c8.h"
#include "03/code_021d34e0.h"
#include "03/types_021d299c.h"
#include "code_0214a348.h"

void func_ov003_021ceb54(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1d++;
    if (data_ov003_021da284->mUnk_1d >= 8) {
        func_ov003_021d34e0(a, func_ov003_021ceaf8);
    }
}

void func_ov003_021ceb80(s32 a) {
    func_ov003_021d1c3c(0, data_ov003_021d6748[data_ov003_021da284->mUnk_1c][a] + 1,
                        (u8 *) func_ov003_021d1974((int) data_ov003_021da284->mUnk_08[a], 0));
    func_ov003_021d17d4(
        data_ov003_021da284->mUnk_08[a], -1,
        data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][a]][0],
        data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][a]][1]);
    func_ov003_021d1790(data_ov003_021da284->mUnk_08[a], -1, 0);
}

void func_ov003_021cec00(Unk021d1770 *a, s32 b) {
    s32 n;
    s32 i;
    u32 w;
    s32 h;
    s32 x;

    n = func_ov003_021d1970((int) a);
    for (i = 0; i < n; i++) {
        func_ov003_021d1770(a, i, &w, &h);
        if (h >= b && h < 0xc0) {
            x = 0;
        } else {
            x = 0x200;
        }
        func_ov003_021d18f0(a, i, x, 0);
    }
}

void func_ov003_021cec50(s32 a) {
    s32 i;
    u8 m;
    u16 v1[4];
    s32 x;
    s32 y;

    func_ov003_021d17d4(data_ov003_021da284->mUnk_00, -1, data_ov003_021d6780[data_ov003_021da284->mUnk_1c][0], a);
    func_ov003_021d17d4(data_ov003_021da284->mUnk_04, -1,
                        data_ov003_021d6714[0] + data_ov003_021d6780[data_ov003_021da284->mUnk_1c][0],
                        a + data_ov003_021d6714[1]);
    func_ov003_021cec00(data_ov003_021da284->mUnk_00, a);
    func_ov003_021cec00(data_ov003_021da284->mUnk_04, a);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        func_ov003_021d17d4(
            data_ov003_021da284->mUnk_08[i], -1,
            data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][i]][0],
            a +
                data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][i]]
                                   [1] -
                data_ov003_021d6780[data_ov003_021da284->mUnk_1c][1]);
        func_ov003_021cec00(data_ov003_021da284->mUnk_08[i], a);
    }
    m = data_ov003_021da284->mUnk_1c;
    y = a & 0xff;
    if (y >= 0xc0) {
        x = 0;
        y = 0;
    } else {
        x = y + data_ov003_021d6798[m][1];
    }
    if (x > 0xc0) {
        x = 0xc0;
    }
    func_ov003_021d2530(data_ov003_021d6780[m][0], y, data_ov003_021d6780[m][0] + data_ov003_021d6798[m][0], x, v1);
    func_ov003_021d2658(0, 0, v1);
}

void func_ov003_021ced78(u32 a) {
    data_ov003_021da284->mUnk_1b = -1;
    data_ov003_021da284->mUnk_18++;
    if (data_ov003_021da284->mUnk_18 >= 0x78) {
        func_ov003_021d34c8(0, a);
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(1, (u32) func_ov003_021ceb54, 0, 0x78);
    }
}

void func_ov003_021cedbc(void) {
    s32 i;
    s32 j;
    Unk021d299c v1;

    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        func_ov003_021d250c(
            data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][i]],
            data_ov003_021d6754[data_ov003_021da284->mUnk_1c], (short *) &v1);
        if (func_ov003_021d2a34(&v1) != 0) {
            data_ov003_021da284->mUnk_1b = i;
            break;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        data_ov003_021da284->mUnk_1b = data_ov003_021d673c[data_ov003_021da284->mUnk_1c][0];
    }
    if (func_ov003_021d2b04(2) != 0) {
        data_ov003_021da284->mUnk_1b = data_ov003_021d673c[data_ov003_021da284->mUnk_1c][1];
    }
    for (j = 0; j < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; j++) {
        if (j == data_ov003_021da284->mUnk_1b) {
            func_ov003_021ceb80(j);
            return;
        }
    }
    data_ov003_021da284->mUnk_1b = -1;
}

void func_ov003_021cee98(u32 a) {
    u32 w;
    s32 h;

    func_ov003_021d1770(data_ov003_021da284->mUnk_00, 0, &w, &h);
    h -= 0xc;
    if (h > data_ov003_021d6780[data_ov003_021da284->mUnk_1c][1]) {
        func_ov003_021cec50(h);
        return;
    }
    func_ov003_021cec50(data_ov003_021d6780[data_ov003_021da284->mUnk_1c][1]);
    if (data_ov003_021da284->mUnk_1c == 5) {
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(0, (u32) func_ov003_021ced78, 0, 0x78);
    } else {
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(0, (u32) func_ov003_021cedbc, 0, 0x78);
    }
    func_ov003_021d34c8(1, a);
}

void func_ov003_021cef28(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1a--;
    func_0214a348((u16 *) 0x04000050, data_ov003_021da284->mUnk_1a);
    if (data_ov003_021da284->mUnk_1a <= -12) {
        func_ov003_021d34e0(a, func_ov003_021cee98);
    }
}
