#include "01/code_02193b1c.h"
#include "Main/Unknown/code_02111488.h"
#include "code_0201ea58.h"

void func_ov001_021944e0(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    func_ov001_02194f20();
    data_ov001_021a9bd8->mUnk_68++;
    v = func_020ae4c0(1, 0x100, 0, data_ov001_021a9bd8->mUnk_68, 10);
    data_ov001_021a9bd8->mUnk_70 = v;
    a = data_ov001_021a9bd8->mUnk_08->mUnk_06;
    b = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    data_ov001_021a9bd8->mUnk_50[0].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[1].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[a].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_54[0x2c].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_54[0x2d].mUnk_04 = v;
    for (i = 0; i < 4; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_04 = v;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a6614[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a662c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a663c[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_04 = v;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_02194a20();
    }
}

void func_ov001_021942f8(void) {
    s32 a = -1;
    s32 b = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 x1, y1, x2, y2, x3, y3;

    func_ov001_02194f20();
    x1 = 1;
    y1 = 0;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        y1 = 1;
    }
    if (y1 == 0 && data_02175628[idx].mUnk_4c == 0) {
        x1 = 0;
    }
    if (x1 != 0) {
        a = func_0201ea84(data_ov001_021a9bd8->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    x2 = 0;
    y2 = 0;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        y2 = 1;
    }
    if (y2 == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
        x2 = 1;
    }
    if (x2 != 0) {
        b = func_0201ea84(data_ov001_021a9bd8->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if (a != 0) {
        data_ov001_021a9bd8->mUnk_88 = 0;
    }
    if (a != 1) {
        data_ov001_021a9bd8->mUnk_8c = 0;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        x3 = 0;
        y3 = 0;
        if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
            y3 = 1;
        }
        if (y3 == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
            x3 = 1;
        }
        if (x3 == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_ov001_021949c0();
    data_ov001_021a9bd8->mUnk_90 = 0;
    func_02128310(0);
    return;
next:
    if ((a == 0 && data_ov001_021a9bd8->mUnk_88 != 0) || (b == 0 && data_ov001_021a9bd8->mUnk_88 == 0) ||
        (u16) (data_02175628[idx].mUnk_02 & 0x20) != 0) {
        data_ov001_021a9bd8->mUnk_7c = 1;
        data_ov001_021a9bd8->mUnk_80[0] = 6;
        data_ov001_021a9bd8->mUnk_88 = 1;
        func_ov001_02194a0c();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 1 && data_ov001_021a9bd8->mUnk_8c != 0) || (b == 1 && data_ov001_021a9bd8->mUnk_8c == 0) ||
        (u16) (data_02175628[idx].mUnk_02 & 0x10) != 0) {
        data_ov001_021a9bd8->mUnk_7c = 0;
        data_ov001_021a9bd8->mUnk_80[1] = 6;
        data_ov001_021a9bd8->mUnk_8c = 1;
        func_ov001_02194a0c();
        func_0212ecc0(&data_0217d068, 0, 2);
    }
}

void func_ov001_02194148(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 x = 0;

    func_ov001_02194f20();
    switch (data_ov001_021a9bd8->mUnk_7c) {
        case 0:
            x = -256;
            break;
        case 1:
            x = 0x100;
            break;
    }
    data_ov001_021a9bd8->mUnk_68++;
    v = func_020ae4c0(1, 0, x, data_ov001_021a9bd8->mUnk_68, 10);
    data_ov001_021a9bd8->mUnk_70 = v;
    a = data_ov001_021a9bd8->mUnk_08->mUnk_06;
    b = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    data_ov001_021a9bd8->mUnk_50[0].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[1].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[a].mUnk_04 = v;
    for (i = 0; i < 4; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_04 = v;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a6614[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a662c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a663c[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_04 = v;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_021949d4();
    }
}

void func_ov001_02193f98(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 x = 0;

    func_ov001_02194f20();
    switch (data_ov001_021a9bd8->mUnk_7c) {
        case 0:
            x = 0x100;
            break;
        case 1:
            x = -256;
            break;
    }
    data_ov001_021a9bd8->mUnk_68++;
    v = func_020ae4c0(1, x, 0, data_ov001_021a9bd8->mUnk_68, 10);
    data_ov001_021a9bd8->mUnk_70 = v;
    a = data_ov001_021a9bd8->mUnk_08->mUnk_06;
    b = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    data_ov001_021a9bd8->mUnk_50[0].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[1].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[a].mUnk_04 = v;
    for (i = 0; i < 4; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_04 = v;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a6614[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a662c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a663c[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_04 = v;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_02194a20();
    }
}

void func_ov001_02193dec(void) {
    s16 v;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    data_ov001_021a9bd8->mUnk_68++;
    v = func_020ae4c0(1, 0, 0x100, data_ov001_021a9bd8->mUnk_68, 10);
    data_ov001_021a9bd8->mUnk_70 = v;
    a = data_ov001_021a9bd8->mUnk_08->mUnk_06;
    b = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    data_ov001_021a9bd8->mUnk_50[0].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[1].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_50[a].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_54[0x2c].mUnk_04 = v;
    data_ov001_021a9bd8->mUnk_54[0x2d].mUnk_04 = v;
    for (i = 0; i < 4; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_04 = v;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a6614[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a662c[i]].mUnk_04 = v;
        data_ov001_021a9bd8->mUnk_54[b + data_ov001_021a663c[i]].mUnk_04 = v;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_04 = v;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_021949ac();
    }
}

void func_ov001_02193da8(void) {
    data_ov001_021a9bd8->mUnk_68++;
    data_ov001_021a9bd8->mUnk_6c = func_020ae4c0(1, 0, -192, data_ov001_021a9bd8->mUnk_68, 10);
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_02111488(data_ov001_021a9bd8->mUnk_90);
    }
}

void func_ov001_02193d14(void) {
    Unk021a9bd8 *d;

    data_ov001_021a9bd8->mUnk_60 = data_ov001_021a9bd8->mUnk_64;
    switch (data_ov001_021a9bd8->mUnk_60) {
        case 0:
            func_ov001_02194690();
            break;
        case 1:
            func_ov001_021944e0();
            break;
        case 2:
            func_ov001_021942f8();
            break;
        case 3:
            func_ov001_02194148();
            break;
        case 4:
            func_ov001_02193f98();
            break;
        case 5:
            func_ov001_02193dec();
            break;
        case 6:
            func_ov001_02193da8();
            break;
    }
    d = data_ov001_021a9bd8;
    func_02124c30(d->mUnk_08, d->mUnk_04, d->mUnk_10, func_02111318(), d->mUnk_50);
    d = data_ov001_021a9bd8;
    func_02124c30(d->mUnk_1c, d->mUnk_18, d->mUnk_24, func_0211130c(), d->mUnk_54);
}

void func_ov001_02193ccc(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021a9bd8->mUnk_6c << 16) & 0x1ff0000;
    *(vu32 *) 0x400101c =
        ((-data_ov001_021a9bd8->mUnk_70) & 0x1ff) | ((-data_ov001_021a9bd8->mUnk_74 << 16) & 0x1ff0000);
    func_02111428();
}

void func_ov001_02193c84(void) {
    u32 a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    u32 b;

    a |= 0x11;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b |= 0x8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
}

void func_ov001_02193c5c(void) {
    Unk021a8294 local = data_ov001_021a8294;

    func_02111494(&local);
}

void func_ov001_02193b28(void *heap) {
    s32 i;
    s32 j;

    data_ov001_021a9bd4 = func_02036bec(heap, 0x40);
    data_ov001_021a9bd4->mUnk_1c = heap;
    data_ov001_021a9bd4->mUnk_00 = 0;
    data_ov001_021a9bd4->mUnk_04 = 0;
    switch (func_ov001_02192e94()) {
        case 1:
        case 4:
            data_ov001_021a9bd4->mUnk_08 = 0;
            break;
        case 2:
            data_ov001_021a9bd4->mUnk_08 = 1;
            break;
    }
    data_ov001_021a9bd4->mUnk_0c = 0;
    data_ov001_021a9bd4->mUnk_14 = 1;
    data_ov001_021a9bd4->mUnk_38 = func_0204799c(data_ov001_021a8254);
    data_ov001_021a9bd4->mUnk_3c = func_02047a28(data_ov001_021a8260);
    if (func_ov001_02192e94() == 1) {
        data_ov001_021a9bd4->mUnk_18 = 0x32;
    } else {
        data_ov001_021a9bd4->mUnk_18 = 0;
    }
    func_ov001_02193a20();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a65dc[i], 1, data_ov001_021a9bd4->mUnk_24, data_ov001_021a9bd4->mUnk_30);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(heap, data_ov001_021a9bd4->mUnk_30, 0, &data_ov001_021a9bd4->mUnk_20);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = 250;
            } else {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = -250;
            }
        }
    }
    func_021281c8(0xf);
}

void func_ov001_02193b1c(void) {
    data_ov001_021a9bd4 = 0;
}
