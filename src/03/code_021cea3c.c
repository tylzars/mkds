#include "03/code_021cea3c.h"

#include "03/unk_021d6000.h"
#include "03/code_021ce5b8.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1770.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "code_0214a348.h"
#include "registers.h"
#include "03/code_021d1790.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1970.h"
#include "03/code_021d250c.h"
#include "03/code_021d2940.h"
#include "03/types_021d299c.h"

int func_ov003_021cef80(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_ov003_021da284;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 27u;
    value0 = (u32) * (const s8 *) ((value1) + (value0));
    return value0;
}

u32 func_ov003_021cef6c(void) {
    if (data_ov003_021da284 != NULL) {
        return 1;
    }
    return 0;
}

void func_ov003_021cef28(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1a--;
    G2x_ChangeBlendBrightness_((u16 *) 0x04000050, data_ov003_021da284->mUnk_1a);
    if (data_ov003_021da284->mUnk_1a <= -12) {
        func_ov003_021d34e0(a, func_ov003_021cee98);
    }
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
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(0, func_ov003_021ced78, NULL, 0x78);
    } else {
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(0, func_ov003_021cedbc, NULL, 0x78);
    }
    func_ov003_021d34c8(1, a);
}

void func_ov003_021cedbc(void) {
    s32 i;
    s32 j;
    Unk021d299c v1;

    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        func_ov003_021d250c(
            data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][i]],
            data_ov003_021d6754[data_ov003_021da284->mUnk_1c], &v1);
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

void func_ov003_021ced78(u32 a) {
    data_ov003_021da284->mUnk_1b = -1;
    data_ov003_021da284->mUnk_18++;
    if (data_ov003_021da284->mUnk_18 >= 0x78) {
        func_ov003_021d34c8(0, a);
        data_ov003_021da284->mUnk_14 = func_ov003_021d3544(1, func_ov003_021ceb54, NULL, 0x78);
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

void func_ov003_021cec00(Unk021d1770 *a, s32 b) {
    s32 n;
    s32 i;
    u32 w;
    s32 h;
    s32 x;

    n = func_ov003_021d1970(a);
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

void func_ov003_021ceb80(s32 a) {
    func_ov003_021d1c3c(0, data_ov003_021d6748[data_ov003_021da284->mUnk_1c][a] + 1,
                        func_ov003_021d1974(data_ov003_021da284->mUnk_08[a], 0));
    func_ov003_021d17d4(
        data_ov003_021da284->mUnk_08[a], -1,
        data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][a]][0],
        data_ov003_021d67b0[data_ov003_021da284->mUnk_1c][data_ov003_021d6730[data_ov003_021da284->mUnk_1c][a]][1]);
    func_ov003_021d1790(data_ov003_021da284->mUnk_08[a], -1, 0);
}

void func_ov003_021ceb54(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1d++;
    if (data_ov003_021da284->mUnk_1d >= 8) {
        func_ov003_021d34e0(a, func_ov003_021ceaf8);
    }
}

void func_ov003_021ceaf8(Unk021d34e0 *a) {
    u32 w;
    s32 h;

    func_ov003_021d1770(data_ov003_021da284->mUnk_00, 0, &w, &h);
    h += 0xc;
    func_ov003_021cec50(h);
    if (h >= 192) {
        if (data_ov003_021da284->mUnk_1e != 0) {
            func_ov003_021d34e0(a, func_ov003_021ceab8);
            return;
        }
        func_ov003_021d34e0(a, func_ov003_021cea3c);
    }
}

void func_ov003_021ceab8(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1a++;
    G2x_ChangeBlendBrightness_((u16 *) 0x04000050, data_ov003_021da284->mUnk_1a);
    if (data_ov003_021da284->mUnk_1a >= 0) {
        func_ov003_021d34e0(a, func_ov003_021cea3c);
    }
}

void func_ov003_021cea3c(u32 a) {
    s32 i;

    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    func_ov003_021d197c(data_ov003_021da284->mUnk_00);
    func_ov003_021d197c(data_ov003_021da284->mUnk_04);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        if (data_ov003_021da284->mUnk_08[i] != NULL) {
            func_ov003_021d197c(data_ov003_021da284->mUnk_08[i]);
        }
    }
    func_ov003_021d2388(data_ov003_021da284->mUnk_10);
    func_ov003_021d34c8(1, a);
    func_ov003_021d2808(&data_ov003_021da284);
}
