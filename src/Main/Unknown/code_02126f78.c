#include "Main/Unknown/code_02126f78.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214a054.h"

#pragma thumb on

void func_0212745c(void) {
    u32 a;
    u32 b;

    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((a | 4) << 8);
    *(vu16 *) 0x400000c &= ~3;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & 0x43) | 0x9e10;
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((b | 1) << 8);
    *(vu16 *) 0x4001008 &= ~3;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x8b00;
}

static inline void func_0212717c_inline(void *dst, u16 value) {
    vu16 v = value;

    func_0214cfe4(v, dst, 0x1000);
}

s32 func_0212717c(s32 param_1) {
    Unk020b4934 *a;
    Unk020b4934 *b;
    Unk020b4a44 *c;

    if (*(vu16 *) 0x27ffc40 == 2) {
        func_020b4934(&a, func_0204799c(data_0216e708));
        func_020b47d8(&data_0217d3f0->mUnk_225c[0], func_0204799c(data_0216e720));
        func_020b4a44(&c, func_0204799c(data_0216e738));
    } else {
        func_020b4934(&a, func_02047a28(data_0216e750));
        func_020b4934(&b, func_02047a28(data_0216e768));
        func_020b47d8(&data_0217d3f0->mUnk_225c[0], func_02047a28(data_0216e780));
        func_020b47d8(&data_0217d3f0->mUnk_225c[1], func_02047a28(data_0216e798));
        func_020b47d8(&data_0217d3f0->mUnk_225c[2], func_02047a28(data_0216e7b0));
        func_020b47d8(&data_0217d3f0->mUnk_225c[3], func_02047a28(data_0216e7c8));
        func_020b47d8(&data_0217d3f0->mUnk_225c[4], func_02047a28(data_0216e7e0));
        func_020b47d8(&data_0217d3f0->mUnk_225c[5], func_02047a28(data_0216e7f8));
        func_020b47d8(&data_0217d3f0->mUnk_225c[6], func_02047a28(data_0216e810));
        func_020b4a44(&c, func_02047a28(data_0216e828));
    }
    data_0217d3f0->mUnk_2220[0] = 0;
    func_0200ee74(a->mUnk_14, a->mUnk_10);
    func_0214b95c(a->mUnk_14, 0, a->mUnk_10);
    if (data_0217d3f0->mUnk_48 != 0) {
        param_1 = param_1 - a->mUnk_10;
        data_0217d3f0->mUnk_2220[2] = param_1 >> 5;
        func_0200ee74(a->mUnk_14, a->mUnk_10);
        func_0214ba94(a->mUnk_14, param_1, a->mUnk_10);
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        if (data_0217d3f0->mUnk_44 != 0) {
            data_0217d3f0->mUnk_2220[1] = 0;
        }
        data_0217d3f0->mUnk_223c[0] = a->mUnk_10 >> 5;
        func_0200ee74(b->mUnk_14, b->mUnk_10);
        func_0214b95c(b->mUnk_14, data_0217d3f0->mUnk_223c[0] << 5, b->mUnk_10);
        if (data_0217d3f0->mUnk_4c != 0) {
            data_0217d3f0->mUnk_2220[3] = data_0217d3f0->mUnk_2220[2];
        }
        param_1 = param_1 - b->mUnk_10;
        data_0217d3f0->mUnk_2220[4] = param_1 >> 5;
        data_0217d3f0->mUnk_2220[5] = param_1 >> 5;
        data_0217d3f0->mUnk_2220[6] = param_1 >> 5;
        data_0217d3f0->mUnk_223c[1] = param_1 >> 5;
        func_0200ee74(b->mUnk_14, b->mUnk_10);
        func_0214ba94(b->mUnk_14, param_1, b->mUnk_10);
    }
    func_0200ee74(c->mUnk_0c, 0x1c0);
    func_0214c160(c->mUnk_0c + 0xe0, 0x1c0, 0x40);
    func_0214c0f8(c->mUnk_0c + 0xe0, 0x1c0, 0x40);
    data_0217d3f0->mUnk_2244 = c->mUnk_0c[0xee];
    data_0217d3f0->mUnk_2246 = c->mUnk_0c[0xdf];
    func_0214d05c_inline((void *) func_0214a214(), 0x1000);
    func_0212717c_inline((void *) func_0214a2f4(), data_0217d3f0->mUnk_2220[4]);
    return param_1;
}

void func_021270bc(void) {
    s32 r;
    s32 i;
    s32 c;
    s32 n;
    u16 *d;

    n = data_0217d3f0->mUnk_14 + 4;
    for (i = 0; i < 2; i++) {
        if (data_0217d3f0->mUnk_18[i] != 0) {
            d = data_0217d3f0->mUnk_54;
            if (i == 1) {
                d = data_0217d3f0->mUnk_1054;
            }
            for (r = data_0215d080[n].mUnk_02; r <= data_0215d080[n].mUnk_03; r++) {
                for (c = data_0215d080[n].mUnk_00; c <= data_0215d080[n].mUnk_01; c++) {
                    *(d + r * 32 + c) =
                        data_0217d3f0->mUnk_223c[i] + *((u16 *) data_0217d3f0->mUnk_225c[n]->mUnk_0c + r * 32 + c);
                }
            }
        }
    }
}

void func_02126f78(u32 *param_1) {
    u8 a[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 i;
    s32 r;
    s32 c;
    s32 k;
    u16 *d;

    func_0214d05c_inline(data_0217d3f0->mUnk_54, 0x1000);
    func_0212717c_inline(&data_0217d3f0->mUnk_1054, data_0217d3f0->mUnk_2220[4]);
    for (i = 0; i < 9; i++) {
        if (*param_1 != 0) {
            if ((u32) (i - 7) <= 1) {
                func_021270bc();
            } else if (i != 6) {
                k = a[i];
                d = data_0217d3f0->mUnk_1054;
                if ((u32) i <= 1) {
                    d = data_0217d3f0->mUnk_54;
                }
                for (r = data_0215d080[k].mUnk_02; r <= data_0215d080[k].mUnk_03; r++) {
                    for (c = data_0215d080[k].mUnk_00; c <= data_0215d080[k].mUnk_01; c++) {
                        *(d + r * 32 + c) =
                            data_0217d3f0->mUnk_2220[i] + *((u16 *) data_0217d3f0->mUnk_225c[k]->mUnk_0c + r * 32 + c);
                    }
                }
            }
        }
        param_1++;
    }
}
#pragma thumb off
