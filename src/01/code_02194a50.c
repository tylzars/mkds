#include "01/code_02194a50.h"
#include "01/code_02193b1c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02116000.h"

void func_ov001_021950fc(s32 a) {
    s32 i;
    s32 k;
    u32 y;
    s32 count;
    s32 z;
    u32 value;
    u16 buf[16];
    u8 *p;

    k = func_020603bc(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a]);
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[a]].mUnk_00 = 1;
    func_02124748((u32) (data_ov001_021a66a4[data_ov001_021a9bd8->mUnk_78]), (void *) (data_ov001_021a9bd8->mUnk_2c),
                  (void *) (data_ov001_021a9bd8->mUnk_28), (void *) (data_ov001_021a9bd8->mUnk_34), 1,
                  (u32) (data_ov001_021a666c[a]), (void *) (data_ov001_021a9bd8->mUnk_18),
                  (void *) (data_ov001_021a9bd8->mUnk_1c));
    func_02124a20(data_ov001_021a666c[a], (u8) data_ov001_021a6604[k], data_ov001_021a9bd8->mUnk_18,
                  data_ov001_021a9bd8->mUnk_1c);
    k = func_02060414(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a]);
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[a][0]].mUnk_00 = 1;
    func_02124748((u32) (data_ov001_021a66e4[k]), (void *) (data_ov001_021a9bd8->mUnk_3c),
                  (void *) (data_ov001_021a9bd8->mUnk_38), (void *) (data_ov001_021a9bd8->mUnk_44), 1,
                  (u32) (data_ov001_021a6674[a][0]), (void *) (data_ov001_021a9bd8->mUnk_18),
                  (void *) (data_ov001_021a9bd8->mUnk_1c));
    p = data_ov001_021a9bd8->mUnk_40->mUnk_0c;
    func_02016468(0x1e, data_ov001_021a6684[a] << 5,
                  p + (func_02124a68((u32) (data_ov001_021a66e4[k]), (void *) (data_ov001_021a9bd8->mUnk_3c),
                                     (void *) (data_ov001_021a9bd8->mUnk_44))
                       << 5),
                  0x20);
    k = func_020603e8(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a]);
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[a][1]].mUnk_00 = 1;
    func_021171a0(k, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c, data_ov001_021a6674[a][1],
                  data_ov001_021a668c[a], 1);
    count = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    func_02060318(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a], &value);
    func_02116b8c(&value, buf);
    data_ov001_021a9bd8->mUnk_54[count + data_ov001_021a6614[a]].mUnk_00 = 1;
    func_02124224(1, data_ov001_021a6614[a], data_ov001_021a9bd8->mUnk_24, buf, data_ov001_021a9bd8->mUnk_1c,
                  data_ov001_021a9bd8->mUnk_54, 7);
    y = (u16) func_02060390(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a]);
    func_02124fac(y, buf);
    data_ov001_021a9bd8->mUnk_54[count + data_ov001_021a662c[a]].mUnk_00 = 1;
    func_02124248(1, data_ov001_021a662c[a], data_ov001_021a9bd8->mUnk_24, buf, data_ov001_021a9bd8->mUnk_1c,
                  data_ov001_021a9bd8->mUnk_54, 7);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][i]].mUnk_00 = 0;
    }
    switch (y) {
        case 0:
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][0]].mUnk_00 = 1;
            break;
        case 1:
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][1]].mUnk_00 = 1;
            break;
        default:
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][2]].mUnk_00 = 1;
            break;
    }
    data_ov001_021a9bd8->mUnk_54[count + data_ov001_021a663c[a]].mUnk_00 = 0;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[a][i]].mUnk_00 = 0;
    }
    z = func_02060364(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[a]);
    if (z < 5) {
        data_ov001_021a9bd8->mUnk_54[count + data_ov001_021a663c[a]].mUnk_00 = 1;
        func_0212426c(1, data_ov001_021a663c[a], data_ov001_021a9bd8->mUnk_24, data_ov001_021a8280[z],
                      data_ov001_021a9bd8->mUnk_1c, data_ov001_021a9bd8->mUnk_54);
    } else {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[a][z - 5]].mUnk_00 = 1;
    }
}

void func_ov001_02194fd8(s32 a) {
    s32 i;

    data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[a]].mUnk_00 = 0;
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[a][0]].mUnk_00 = 0;
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[a][1]].mUnk_00 = 0;
    func_02124224(1, data_ov001_021a6614[a], data_ov001_021a9bd8->mUnk_24, L"--:--:---", data_ov001_021a9bd8->mUnk_1c,
                  data_ov001_021a9bd8->mUnk_54, 7);
    func_02124248(1, data_ov001_021a662c[a], data_ov001_021a9bd8->mUnk_24, L"--", data_ov001_021a9bd8->mUnk_1c,
                  data_ov001_021a9bd8->mUnk_54, 7);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][i]].mUnk_00 = 0;
    }
    if (a != 3 || func_ov001_02194d04(data_ov001_021a9bd8->mUnk_78) != 0) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[a][0]].mUnk_00 = 1;
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[a][i]].mUnk_00 = 0;
    }
    func_0212426c(1, data_ov001_021a663c[a], data_ov001_021a9bd8->mUnk_24, L"-", data_ov001_021a9bd8->mUnk_1c,
                  data_ov001_021a9bd8->mUnk_54);
}

void func_ov001_02194f20(void) {
    s32 i;

    data_ov001_021a9bd8->mUnk_54[data_ov001_021a65fc[0]].mUnk_04 = -func_020adc64(6 - data_ov001_021a9bd8->mUnk_80[0]);
    data_ov001_021a9bd8->mUnk_54[data_ov001_021a65fc[1]].mUnk_04 = func_020adc64(6 - data_ov001_021a9bd8->mUnk_80[1]);
    for (i = 0; i < 2; i++) {
        if (data_ov001_021a9bd8->mUnk_80[i] > 0) {
            data_ov001_021a9bd8->mUnk_80[i]--;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6600[i]].mUnk_00 = 0;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a65fc[i]].mUnk_00 = 1;
        } else {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6600[i]].mUnk_00 = 1;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a65fc[i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_02194d78(void) {
    s32 i;
    s32 n;
    Unk021a9bd8 *d;
    void *p;
    u8 v;

    n = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    if (func_ov001_02194d04(data_ov001_021a9bd8->mUnk_78) != 0) {
        func_02016468(0x1b, 0x3c6, (u8 *) ((u8 *) data_ov001_021a9bd8->mUnk_48 + 0xc) + 0x3c6, 0x134);
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[3]].mUnk_00 = 1;
        for (i = 0; i < 3; i++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[3][i]].mUnk_00 = 1;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[3]].mUnk_00 = 1;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a6614[3]].mUnk_00 = 1;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a662c[3]].mUnk_00 = 1;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a663c[3]].mUnk_00 = 1;
    } else {
        func_02016468(0x1b, 0x3c6, (u8 *) data_ov001_021a9bd8->mUnk_4c + 0x3c6, 0x134);
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[3]].mUnk_00 = 0;
        for (i = 0; i < 3; i++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[3][i]].mUnk_00 = 0;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[3]].mUnk_00 = 0;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a6614[3]].mUnk_00 = 0;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a662c[3]].mUnk_00 = 0;
        data_ov001_021a9bd8->mUnk_54[n + data_ov001_021a663c[3]].mUnk_00 = 0;
    }
    d = data_ov001_021a9bd8;
    v = func_02124a68((u32) (1), (void *) (d->mUnk_04), (void *) (d->mUnk_08));
    func_0211ded0((u32) (d->mUnk_78), (void *) d->mUnk_04, (void *) d->mUnk_08, (u32) (1), (u16) (v), 0);
    d = data_ov001_021a9bd8;
    p = func_020b3f7c(d->mUnk_58, data_ov001_021a6720[d->mUnk_78]);
    func_0212426c(0, 0, data_ov001_021a9bd8->mUnk_10, p, d->mUnk_08, d->mUnk_50);
    for (i = 0; i < 4; i++) {
        if (func_02060440(data_ov001_021a6740[data_ov001_021a9bd8->mUnk_78], data_ov001_021a6694[i]) != 0) {
            func_ov001_021950fc(i);
        } else {
            func_ov001_02194fd8(i);
        }
    }
}

void func_ov001_02194d48(void) {
    s32 value;

    data_ov001_021a9bd8->mUnk_78++;
    value = data_ov001_021a9bd8->mUnk_78;
    if (value >= 8) {
        value = 0;
        data_ov001_021a9bd8->mUnk_78 = value;
    }
    if (func_ov001_02194c9c(value) == 0) {
        func_ov001_02194d48();
    }
}

void func_ov001_02194d18(void) {
    s32 value;

    data_ov001_021a9bd8->mUnk_78--;
    value = data_ov001_021a9bd8->mUnk_78;
    if (value < 0) {
        value = 7;
        data_ov001_021a9bd8->mUnk_78 = value;
    }
    if (func_ov001_02194c9c(value) == 0) {
        func_ov001_02194d18();
    }
}

u32 func_ov001_02194d04(s32 a) {
    return func_02056dec(data_ov001_021a6700[a]);
}

u32 func_ov001_02194c9c(u32 a) {
    u32 result;
    s32 i;

    result = 0;
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return 1;
        case 2:
        case 3:
        case 6:
        case 7:
            for (i = 0; i < 3; i++) {
                result |= func_02056dec(data_ov001_021a6760[a][i]);
            }
            result |= func_ov001_02194d04(a);
            break;
    }
    return result;
}

void func_ov001_02194a50(void) {
    s32 i;
    s32 j;
    s32 count0;
    s32 count1;

    data_ov001_021a9bd8->mUnk_64 = 0;
    data_ov001_021a9bd8->mUnk_68 = 0;
    data_ov001_021a9bd8->mUnk_6c = ~0xbf;
    data_ov001_021a9bd8->mUnk_70 = ~0xff;
    count0 = data_ov001_021a9bd8->mUnk_08->mUnk_06;
    count1 = data_ov001_021a9bd8->mUnk_1c->mUnk_06;
    data_ov001_021a9bd8->mUnk_50[0].mUnk_04 = 0x100;
    data_ov001_021a9bd8->mUnk_50[1].mUnk_04 = 0x100;
    data_ov001_021a9bd8->mUnk_50[count0].mUnk_04 = 0x100;
    data_ov001_021a9bd8->mUnk_54[44].mUnk_04 = 0x100;
    data_ov001_021a9bd8->mUnk_54[45].mUnk_04 = 0x100;
    for (i = 0; i < 4; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a666c[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a6654[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_04 = 0x100;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66cc[i][j]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        }
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a665c[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a6614[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a6614[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a662c[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a662c[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a663c[i]].mUnk_04 = 0x100;
        data_ov001_021a9bd8->mUnk_54[count1 + data_ov001_021a663c[i]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        for (j = 0; j < 3; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_04 = 0x100;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a66b4[i][j]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_04 = 0x100;
            data_ov001_021a9bd8->mUnk_54[data_ov001_021a6674[i][j]].mUnk_06 = data_ov001_021a9bd8->mUnk_74;
        }
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bd8->mUnk_54[data_ov001_021a65fc[i]].mUnk_00 = 0;
    }
}
