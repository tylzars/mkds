#include "01/code_0219a950.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02124000.h"
#include "01/code_0219a000.h"
#include "01/code_0219b000.h"
#include "01/code_02195a6c.h"
#include "00/code_02182fdc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

void func_ov001_0219ae10(void) {
    data_ov001_021a9bf0->mUnk_34 = 5;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_0219adfc(void) {
    data_ov001_021a9bf0->mUnk_34 = 6;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ade8(void) {
    data_ov001_021a9bf0->mUnk_34 = 7;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219adbc(void) {
    data_ov001_021a9bf0->mUnk_34 = 8;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_021262f0(func_020b3f7c(data_ov001_021a9bf0->mUnk_20, 0x76));
}

void func_ov001_0219ad98(void) {
    data_ov001_021a9bf0->mUnk_34 = 9;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_0212ecc0(&data_0217d068, 0, 0x15);
}

void func_ov001_0219ad7c(void) {
    data_ov001_021a9bf0->mUnk_34 = 10;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_02125fc0();
}

void func_ov001_0219ad68(void) {
    data_ov001_021a9bf0->mUnk_34 = 11;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ad3c(void) {
    data_ov001_021a9bf0->mUnk_40++;
    if (data_ov001_021a9bf0->mUnk_40 >= 3) {
        data_ov001_021a9bf0->mUnk_40 = 0;
    }
    func_0212ecc0(&data_0217d068, 0, 0);
}

void func_ov001_0219ad10(void) {
    data_ov001_021a9bf0->mUnk_40--;
    if (data_ov001_021a9bf0->mUnk_40 < 0) {
        data_ov001_021a9bf0->mUnk_40 = 2;
    }
    func_0212ecc0(&data_0217d068, 0, 0);
}

void func_ov001_0219ac98(void) {
    s32 best = 7;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j)) {
                s32 v = func_02060364(i, j);
                if (best > v) {
                    best = v;
                }
            } else {
                best = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_00 = 0;
    }
    if (best > 4) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[best - 5]].mUnk_00 = 1;
    }
}

void func_ov001_0219a9a0(void *heap) {
    u32 scores[3][3] = {0};
    u16 buf[16];
    s32 rem;
    u16 x;
    u16 base;
    s32 i;
    s32 j;
    Unk0217aa08_00 **pp;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 1;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x8800;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & 0x43) | 0x1018;
    data_ov001_021a9bf0 = func_02036bec(heap, 0x48);
    data_ov001_021a9bf0->mUnk_2c = heap;
    data_ov001_021a9bf0->mUnk_30 = 0;
    switch (func_0211147c()) {
        case 1:
        case 5:
            data_ov001_021a9bf0->mUnk_40 = 0;
            break;
        case 2:
            data_ov001_021a9bf0->mUnk_40 = 1;
            break;
        case 3:
            if (func_021143b4()) {
                data_ov001_021a9bf0->mUnk_40 = 2;
            } else {
                data_ov001_021a9bf0->mUnk_40 = 0;
            }
            break;
    }
    func_ov001_0219b000();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6ac4[i], 1, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
    }
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_08, &data_ov001_021a9bf0->mUnk_18);
    func_02124ed0(heap, data_ov001_021a9bf0->mUnk_10, 0, &data_ov001_021a9bf0->mUnk_1c);
    data_ov001_021a9bf0->mUnk_20 = func_02047a28("common.bmg");
    data_ov001_021a9bf0->mUnk_24 = func_0204799c("record.bmg");
    rem = 0x8000;
    rem -= func_021243ac(heap, 0, data_ov001_021a9bf0->mUnk_08, 0xaa, 0xe, 0, data_ov001_021a9bf0->mUnk_00,
                         data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18, rem);
    func_0212426c(0, 0, data_ov001_021a9bf0->mUnk_08, func_020b3f7c(data_ov001_021a9bf0->mUnk_24, 9),
                  data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18);
    x = 1;
    base = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            rem -= func_021243ac(heap, data_ov001_021a6ae4[i][j], data_ov001_021a9bf0->mUnk_08,
                                 data_ov001_021a6af8[i][j], data_ov001_021a6b0c[i][j], x, data_ov001_021a9bf0->mUnk_00,
                                 data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18, rem);
            x = base + data_ov001_021a6ae4[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_ov001_021a6ae4[0][i], data_ov001_021a9bf0->mUnk_08,
                      func_020b3f7c(data_ov001_021a9bf0->mUnk_24, data_ov001_021a6abc[i]), data_ov001_021a9bf0->mUnk_04,
                      data_ov001_021a9bf0->mUnk_18);
    }
    pp = &data_0217aa08->mUnk_00;
    scores[1][0] = (*pp)->mUnk_34;
    scores[2][0] = (*pp)->mUnk_38;
    scores[1][1] = (*pp)->mUnk_3c;
    scores[2][1] = (*pp)->mUnk_40;
    scores[1][2] = (*pp)->mUnk_44;
    scores[2][2] = (*pp)->mUnk_48;
    for (i = 1; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (scores[i][j] > 9999) {
                scores[i][j] = 9999;
            }
            func_02124fac(scores[i][j], buf);
            func_02124248(0, data_ov001_021a6ae4[i][j], data_ov001_021a9bf0->mUnk_08, buf, data_ov001_021a9bf0->mUnk_04,
                          data_ov001_021a9bf0->mUnk_18, 6);
        }
    }
    func_ov001_0219ac98();
    func_ov001_0219ae88();
    func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
}

void func_ov001_0219a950(void) {
    u32 a;
    u32 b;

    data_ov001_021a9bf0 = 0;
    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    a &= ~0x11;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b &= ~0x1;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
}
