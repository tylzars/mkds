#include "01/code_0219f6a0.h"
#include "code_0201ea58.h"

void func_ov001_0219ff8c(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    if (func_02128294()) {
        func_ov001_021a04ac();
    }
}

void func_ov001_0219fc70(void) {
    u32 result = -1;
    Unk02175628Index slot = UNK_02175628_INDEX_8;
    s32 flag_b;
    s32 flag_a;
    u16 value;
    s16 current;
    s16 delta;
    s16 target;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    flag_b = 0;
    flag_a = 0;
    value = data_02175628[slot].mUnk_4c;
    if (value == 0 && data_02175628[slot].mUnk_58 < 5) {
        flag_a = 1;
    }
    if (flag_a == 0 && data_02175628[slot].mUnk_54 == 0 && value != 0) {
        flag_b = 1;
    }
    if (flag_b) {
        result = func_0201ea84(data_ov001_021ca414->mUnk_14, data_02175628[slot].mUnk_48, data_02175628[slot].mUnk_4a);
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 2) == 0) {
        flag_b = 0;
        flag_a = 0;
        value = data_02175628[slot].mUnk_4c;
        if (value == 0 && data_02175628[slot].mUnk_58 < 5) {
            flag_a = 1;
        }
        if (flag_a == 0 && data_02175628[slot].mUnk_54 == 0 && value != 0) {
            flag_b = 1;
        }
        if (!flag_b || func_02128210(data_02175628[slot].mUnk_48, data_02175628[slot].mUnk_4a) == 0) {
            goto skip;
        }
    }
    if (func_ov001_021a071c() != 0) {
        return;
    }
    func_021281c8(0xe);
    data_ov001_021ca414->mUnk_9c = 0x100;
    data_ov001_021ca414->mUnk_bc = 2;
    func_ov001_021a03a0();
    func_02128310(0);
    return;
skip:
    if (result <= 8) {
        target = data_ov001_021a6d98[result];
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            func_0212ecc0(&data_0217d068, 0, 0x16);
            return;
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_ov001_021a0488();
        return;
    }
    if ((u16) (data_02175628[slot].mUnk_00 & 1) != 0) {
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_ov001_021a0488();
        return;
    }
    if (func_020ae408(8, 0x40)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6de8[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6de8[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x80)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dac[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dac[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x20)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dc0[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dc0[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (func_020ae408(8, 0x10)) {
        current = data_ov001_021ca414->mUnk_9e;
        delta = data_ov001_021a6dfc[current];
        if (delta == 0) {
            return;
        }
        target = current + delta;
        if (target == 8 && data_ov001_021ca414->mUnk_a0 == 0) {
            target = target + data_ov001_021a6dfc[target];
        }
        data_ov001_021ca414->mUnk_9e = target;
        data_ov001_021ca414->mUnk_6c[data_ov001_021ca414->mUnk_9e] = 5;
        func_0212ecc0(&data_0217d068, 0, 0);
    }
}

void func_ov001_0219fc34(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    if (data_ov001_021ca414->mUnk_68 >= 5) {
        if (func_ov001_021a071c() == 0) {
            func_ov001_021a0428();
        }
    }
}

void func_ov001_0219fc08(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277c8()) {
        func_ov001_021a0414();
    }
}

void func_ov001_0219fbdc(void) {
    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_02127788()) {
        func_ov001_021a03f8();
    }
}

void func_ov001_0219fb5c(void) {
    s32 i;
    s32 r;

    func_021055b0(data_ov001_021ca414->mUnk_a8);
    func_ov001_021a0620();
    if (func_021277ac()) {
        r = func_02127794();
        switch (r) {
            case 0:
                func_ov001_021a0734();
                data_ov001_021ca414->mUnk_bc = 1;
                data_ov001_021ca414->mUnk_9c = -0x100;
                func_ov001_021a03a0();
                break;
            case -1:
            case 1:
                func_ov001_021a04ac();
                break;
        }
        for (i = 0; i < 9; i++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219f9f8(void) {
    s32 i;
    s32 j;
    s16 first;
    s16 second;
    u16 a;
    u16 b;

    a = data_ov001_021ca414->mUnk_04->mUnk_06;
    b = data_ov001_021ca414->mUnk_10->mUnk_06;
    data_ov001_021ca414->mUnk_68 = data_ov001_021ca414->mUnk_68 + 1;
    first = func_020ae4c0(1, 0, data_ov001_021ca414->mUnk_9c, data_ov001_021ca414->mUnk_68, 10);
    second = func_020ae4c0(1, 0, -0xc0, data_ov001_021ca414->mUnk_68, 10);
    data_ov001_021ca414->mUnk_90 = first;
    data_ov001_021ca414->mUnk_98 = second;
    data_ov001_021ca414->mUnk_40[0].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[1].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[9].mUnk_04 = first;
    data_ov001_021ca414->mUnk_40[18].mUnk_04 = first;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[i]].mUnk_04 = first;
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_04 = first;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_04 = first;
    }
    data_ov001_021ca414->mUnk_40[a].mUnk_04 = first;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_04 = first;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_04 = first;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[b + data_ov001_021a6e10[i][j]].mUnk_04 = first;
        }
    }
    if (data_ov001_021ca414->mUnk_68 == 5) {
        func_02016468(9, 0, data_ov001_021ca414->mUnk_48, 0x800);
    }
}

s32 func_ov001_0219f934(void) {
    data_ov001_021ca414->mUnk_60 = data_ov001_021ca414->mUnk_64;
    switch (data_ov001_021ca414->mUnk_60) {
        case 0:
            func_ov001_021a0118();
            break;
        case 1:
            func_ov001_0219ffb4();
            break;
        case 2:
            func_ov001_0219ff8c();
            break;
        case 3:
            func_ov001_0219fc70();
            break;
        case 4:
            func_ov001_0219fc34();
            break;
        case 5:
            func_ov001_0219fc08();
            break;
        case 6:
            func_ov001_0219fbdc();
            break;
        case 7:
            func_ov001_0219fb5c();
            break;
        case 8:
            func_ov001_0219f9f8();
            break;
    }
    func_ov001_021a08d8();
    func_ov001_021a09a4();
    func_02124c30(data_ov001_021ca414->mUnk_04, data_ov001_021ca414->mUnk_00, data_ov001_021ca414->mUnk_08,
                  data_ov001_021ca414->mUnk_b4, data_ov001_021ca414->mUnk_40);
    func_02124c30(data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_18,
                  data_ov001_021ca414->mUnk_b8, data_ov001_021ca414->mUnk_44);
    if (data_ov001_021ca414->mUnk_60 == 8 && data_ov001_021ca414->mUnk_68 >= 10) {
        return data_ov001_021ca414->mUnk_bc;
    }
    return 0;
}

void func_ov001_0219f8ec(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021ca414->mUnk_90 & 0x1ff) | ((-data_ov001_021ca414->mUnk_94 << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-data_ov001_021ca414->mUnk_98 << 16) & 0x1ff0000;
}

void func_ov001_0219f85c(void) {
    Unk020b4934 *v1 = 0;
    Unk02021dc8 *v2 = 0;
    Unk020b4a44 *v3 = 0;
    Unk020b4934 *v4 = 0;
    Unk020b47d8 *v5 = 0;
    Unk020b4a44 *v6 = 0;

    func_020b496c(&v4, func_0204799c(data_ov001_021a90a8));
    func_020b4810(&v5, func_0204799c(data_ov001_021a90e4));
    func_020b4a7c(&v6, func_0204799c(data_ov001_021a90cc));
    func_020b49f4(&v1, func_0204799c(data_ov001_021a90d4));
    func_020b48ec(&v2, func_0204799c(data_ov001_021a90c4));
    func_020b4a7c(&v3, func_0204799c(data_ov001_021a90c0));
}

void func_ov001_0219f6e0(void) {
    Unk020b4934 *v1 = 0;
    Unk020b4a44 *v2 = 0;
    Unk020b4934 *v3 = 0;
    Unk020b47d8 *v4 = 0;
    Unk020b4a44 *v5 = 0;

    func_020b4934(&v3, func_0204799c(data_ov001_021a90a8));
    func_020b47d8(&v4, func_0204799c(data_ov001_021a90e4));
    func_020b4a44(&v5, func_0204799c(data_ov001_021a90cc));
    if (data_ov001_021ca410->mUnk_4a >= 6) {
        data_ov001_021ca410->mUnk_04 = func_0204799c(data_ov001_021a90dc);
        data_ov001_021ca410->mUnk_08 = func_0204799c(data_ov001_021a90b8);
        data_ov001_021ca410->mUnk_0c = func_0204799c(data_ov001_021a90bc);
    } else {
        data_ov001_021ca410->mUnk_04 = func_0204799c(data_ov001_021a90c8);
        data_ov001_021ca410->mUnk_08 = func_0204799c(data_ov001_021a90a4);
        data_ov001_021ca410->mUnk_0c = func_0204799c(data_ov001_021a90d8);
    }
    func_020b49bc(&v1, func_0204799c(data_ov001_021a90d4));
    func_020b48b4(&data_ov001_021ca410->mUnk_00, func_0204799c(data_ov001_021a90c4));
    func_020b4a44(&v2, func_0204799c(data_ov001_021a90c0));
    data_ov001_021ca410->mUnk_14 = func_02036bec(data_ov001_021ca410->mUnk_18, 0x800);
    func_02016468(4, 0, v3->mUnk_14, v3->mUnk_10);
    func_02016468(8, 0, v4->mUnk_0c, v4->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021ca410->mUnk_14, 0x800);
    func_02016468(0xf, 0, v5->mUnk_0c, 0x40);
    func_02016468(0x23, 0, v1->mUnk_14, v1->mUnk_10);
    func_02016468(0x1e, 0, v2->mUnk_0c, v2->mUnk_08);
}

s32 func_ov001_0219f6a0(s16 param_1) {
    s32 i;
    s32 result;
    s32 out;
    u8 next;

    result = 8;
    i = 0;
    next = param_1 + 1;

    for (; i < 9; i++) {
        if (func_0205fd78(next, (u8) (i + 1), &out)) {
            if (out < result) {
                result = out;
            }
        } else {
            result = 9;
        }
    }
    return result;
}
