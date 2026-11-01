#include "01/code_021978b4.h"
#include "01/code_02195a6c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "code_0201ea58.h"

void func_ov001_02198014(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9be0->mUnk_20, 10);
    data_ov001_021a9be0->mUnk_24 = func_020ae4c0(1, -192, 0, data_ov001_021a9be0->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_02198354();
    }
}

void func_ov001_02197f6c(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae488(data_ov001_021a9be0->mUnk_20);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_02198338();
    }
}

void func_ov001_02197f54(void) {
    if (func_02128294() != 0) {
        func_ov001_02198324();
    }
}

void func_ov001_02197d58(void) {
    s32 flag2 = 0;
    u32 sel = -1;
    s32 dir = 3;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 flag1 = 0;
    Unk02175628 *e;
    s32 bits;
    s32 flag4;
    s32 flag3;

    if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
        flag1 = 1;
    }
    if (flag1 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
        flag2 = 1;
    }
    if (flag2 != 0) {
        sel = func_0201ea84(data_ov001_021a9be0->mUnk_08, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    e = &data_02175628[i];
    bits = e->mUnk_00 & 2;
    if ((u16) bits == 0) {
        flag3 = flag4 = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            flag4 = 1;
        }
        if (flag4 == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(0xe);
    func_ov001_021982d4();
    data_ov001_021a9be0->mUnk_34 = 4;
    func_02128310(0);
    return;
next:
    bits = e->mUnk_00 & 1;
    if ((u16) bits == 0 && sel > 2) {
        goto skip;
    }
    if ((u16) bits == 0) {
        func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
        switch (sel) {
            case 0:
                dir = 0;
                break;
            case 1:
                dir = 1;
                break;
            case 2:
                dir = 2;
                break;
        }
        if (data_ov001_021a9be0->mUnk_28 != dir) {
            data_ov001_021a9be0->mUnk_28 = dir;
            func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
        }
    } else {
        func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
    }
    switch (data_ov001_021a9be0->mUnk_28) {
        case 0:
            data_ov001_021a9be0->mUnk_34 = 1;
            break;
        case 1:
            data_ov001_021a9be0->mUnk_34 = 2;
            break;
        case 2:
            data_ov001_021a9be0->mUnk_34 = 3;
            break;
    }
    func_ov001_021982e8();
    return;
skip:
    if (func_020ae408(8, 0x40) != 0) {
        func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
        data_ov001_021a9be0->mUnk_28--;
        if (data_ov001_021a9be0->mUnk_28 < 0) {
            data_ov001_021a9be0->mUnk_28 = 2;
        }
        func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
        func_0212ecc0(&data_0217d068, 0, 0);
    } else if (func_020ae408(8, 0x80) != 0) {
        func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
        data_ov001_021a9be0->mUnk_28++;
        if (data_ov001_021a9be0->mUnk_28 >= 3) {
            data_ov001_021a9be0->mUnk_28 = 0;
        }
        func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_ov001_02197c9c(void) {
    s16 v;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae488(data_ov001_021a9be0->mUnk_20);
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    switch (data_ov001_021a9be0->mUnk_28) {
        case 1:
            data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
            break;
        case 2:
            data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
            break;
    }
    if (data_ov001_021a9be0->mUnk_20 == 5) {
        func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
    }
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_021982d4();
    }
}

void func_ov001_02197bdc(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9be0->mUnk_20, 10);
    data_ov001_021a9be0->mUnk_24 = func_020ae4c0(1, 0, -192, data_ov001_021a9be0->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
}

s32 func_ov001_02197b54(void) {
    data_ov001_021a9be0->mUnk_18 = data_ov001_021a9be0->mUnk_1c;
    switch (data_ov001_021a9be0->mUnk_18) {
        case 0:
            func_ov001_02198014();
            break;
        case 1:
            func_ov001_02197f6c();
            break;
        case 2:
            func_ov001_02197f54();
            break;
        case 3:
            func_ov001_02197d58();
            break;
        case 4:
            func_ov001_02197c9c();
            break;
        case 5:
            func_ov001_02197bdc();
            break;
    }
    func_02124c30(data_ov001_021a9be0->mUnk_04, data_ov001_021a9be0->mUnk_00, 0, (void *) data_ov001_021a9be0->mUnk_30,
                  data_ov001_021a9be0->mUnk_0c);
    if (data_ov001_021a9be0->mUnk_18 == 5 && data_ov001_021a9be0->mUnk_20 >= 10) {
        return data_ov001_021a9be0->mUnk_34;
    }
    return 0;
}

void func_ov001_02197b34(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021a9be0->mUnk_24 << 16) & 0x1ff0000;
}

void func_ov001_021978b4(void) {
    Unk020b4a44 *l0 = 0;
    Unk020b4934 *l4 = 0;
    Unk020b4a44 *l8 = 0;
    Unk020b47d8 *lc = 0;
    Unk020b47d8 *l10 = 0;
    Unk020b4a44 *l14 = 0;
    Unk020b4934 *l18 = 0;
    Unk020b4a44 *l1c = 0;
    Unk020b47d8 *l20 = 0;
    u16 *p;

    func_020b49bc(&data_ov001_021a9bdc->mUnk_00, func_0204799c(data_0216cca8));
    func_020b48b4(&data_ov001_021a9bdc->mUnk_04, func_0204799c(data_0216cc90));
    func_020b4a44(&l0, func_0204799c(data_0216cccc));
    data_ov001_021a9bdc->mUnk_08 = func_0204799c(data_0216cc84);
    data_ov001_021a9bdc->mUnk_10 = func_0204799c(data_0216cc78);
    func_020b49bc(&data_ov001_021a9bdc->mUnk_14, func_0204799c(data_0216ccc0));
    func_020b48b4(&data_ov001_021a9bdc->mUnk_18, func_0204799c(data_0216ccc4));
    func_020b4a44(&l14, func_0204799c(data_0216cc74));
    data_ov001_021a9bdc->mUnk_1c = func_0204799c(data_0216cd00);
    data_ov001_021a9bdc->mUnk_20 = func_0204799c(data_0216cd04);
    data_ov001_021a9bdc->mUnk_24 = func_0204799c(data_0216cc8c);
    data_ov001_021a9bdc->mUnk_28 = func_020b4018(0);
    data_ov001_021a9bdc->mUnk_2c = func_020b400c(0);
    data_ov001_021a9bdc->mUnk_30 = func_020b4030(0);
    data_ov001_021a9bdc->mUnk_34 = func_020b4000(0);
    func_020b4934(&l4, func_0204799c(data_0216cd2c));
    func_020b47d8(&lc, func_0204799c(data_0216cd1c));
    func_020b47d8(&l10, func_0204799c(data_0216cd0c));
    func_020b4a44(&l8, func_0204799c(data_0216ccfc));
    func_020b4934(&l18, func_0204799c(data_0216cd20));
    func_020b4a44(&l1c, func_0204799c(data_0216cce4));
    func_020b47d8(&l20, func_0204799c(data_0216ccd4));
    p = l0->mUnk_0c;
    func_02016468(0x13, 0, data_ov001_021a9bdc->mUnk_00->mUnk_14, data_ov001_021a9bdc->mUnk_00->mUnk_10);
    func_02016468(0xe, 0, l0->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, (u8 *) p + 0x1c0, 0x40);
    func_02016468(0x23, 0, data_ov001_021a9bdc->mUnk_14->mUnk_14, data_ov001_021a9bdc->mUnk_14->mUnk_10);
    func_02016468(0x1e, 0, l14->mUnk_0c, l14->mUnk_08);
    func_02016468(4, 0, l4->mUnk_14, l4->mUnk_10);
    func_02016468(8, 0, lc->mUnk_0c, lc->mUnk_08);
    func_02016468(9, 0, l10->mUnk_0c, l10->mUnk_08);
    func_02016468(0xf, 0, l8->mUnk_0c, 0x40);
    func_02016468(0x17, 0, l18->mUnk_14, l18->mUnk_10);
    func_02016468(0x1f, 0, l1c->mUnk_0c, 0x40);
    func_02016468(0x1b, 0, l20->mUnk_0c, l20->mUnk_08);
}
