#include "01/code_02193c5c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111488.h"
#include "code_0201ea58.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/code_0211df38.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02117218.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0205f000.h"

void func_ov001_021953d0(void) {
    Unk020b4a44 *l0 = NULL;
    Unk020b4934 *l4 = NULL;
    Unk020b4a44 *l8 = NULL;
    Unk020b47d8 *lc = NULL;
    Unk020b4a44 *l10 = NULL;
    Unk020b4934 *l14 = NULL;
    Unk020b4a44 *l18 = NULL;
    u16 *x;

    LocateNcgr2(&data_ov001_021a9bd8->mUnk_00, FindSceneFile(data_0216cc98));
    LocateNcer(&data_ov001_021a9bd8->mUnk_04, FindSceneFile(data_0216ccd0));
    LocateNclr(&l0, FindSceneFile(data_0216ccec));
    data_ov001_021a9bd8->mUnk_08 = FindSceneFile(data_0216cca4);
    data_ov001_021a9bd8->mUnk_10 = FindSceneFile(data_0216cc80);
    LocateNcgr2(&data_ov001_021a9bd8->mUnk_14, FindSceneFile(data_0216cc94));
    LocateNcer(&data_ov001_021a9bd8->mUnk_18, FindSceneFile(data_0216cc70));
    LocateNclr(&l10, FindSceneFile(data_0216cc68));
    data_ov001_021a9bd8->mUnk_1c = FindSceneFile(data_0216cc7c);
    data_ov001_021a9bd8->mUnk_20 = FindSceneFile(data_0216cd34);
    data_ov001_021a9bd8->mUnk_24 = FindSceneFile(data_0216ccb0);
    LocateNcgr2(&data_ov001_021a9bd8->mUnk_28, FindSceneFile(data_0216cd18));
    LocateNcer(&data_ov001_021a9bd8->mUnk_2c, FindSceneFile(data_0216cd28));
    LocateNclr(&data_ov001_021a9bd8->mUnk_30, FindSceneFile(data_0216ccb8));
    data_ov001_021a9bd8->mUnk_34 = FindSceneFile(data_0216ccd8);
    data_ov001_021a9bd8->mUnk_38 = (void *) func_020b4018(0);
    data_ov001_021a9bd8->mUnk_3c = (void *) func_020b400c(0);
    data_ov001_021a9bd8->mUnk_40 = func_020b4030(0);
    data_ov001_021a9bd8->mUnk_44 = (void *) func_020b4000(0);
    LocateNcgr(&l4, FindSceneFile(data_0216cc6c));
    LocateNclr(&l8, FindSceneFile(data_0216ccc8));
    LocateNscr(&lc, FindSceneFile(data_0216cc9c));
    LocateNcgr(&l14, FindSceneFile(data_0216cd14));
    LocateNclr(&l18, FindSceneFile(data_0216ccbc));
    LocateNscr(&data_ov001_021a9bd8->mUnk_48, FindSceneFile(data_0216ccf8));
    x = l0->mUnk_0c;
    func_02016468(0x13, 0, data_ov001_021a9bd8->mUnk_00->mUnk_14, data_ov001_021a9bd8->mUnk_00->mUnk_10);
    func_02016468(0xe, 0, l0->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, (u8 *) x + 0x1c0, 0x40);
    func_02016468(0x23, 0, data_ov001_021a9bd8->mUnk_14->mUnk_14, data_ov001_021a9bd8->mUnk_14->mUnk_10);
    func_02016468(0x1e, 0, l10->mUnk_0c, l10->mUnk_08);
    func_02016468(4, 0, l4->mUnk_14, l4->mUnk_10);
    func_02016468(0xf, 0, l8->mUnk_0c, 0x40);
    func_02016468(8, 0, lc->mUnk_0c, lc->mUnk_08);
    func_02016468(0x17, 0, l14->mUnk_14, l14->mUnk_10);
    func_02016468(0x1f, 0, l18->mUnk_0c, 0x40);
    func_02016468(0x1b, 0, data_ov001_021a9bd8->mUnk_48->mUnk_0c, data_ov001_021a9bd8->mUnk_48->mUnk_08);
    x = data_ov001_021a9bd8->mUnk_30->mUnk_0c;
    func_02016468(0x1e, data_ov001_021a6604[0] << 5, (u8 *) x + (data_ov001_021a660c[0] << 5), 0x20);
    func_02016468(0x1e, data_ov001_021a6604[1] << 5, (u8 *) x + (data_ov001_021a660c[1] << 5), 0x20);
    func_02016468(0x1e, data_ov001_021a6604[2] << 5, (u8 *) x + (data_ov001_021a660c[2] << 5), 0x20);
}

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
    p = GetBmgEntry(d->mUnk_58, data_ov001_021a6720[d->mUnk_78]);
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

void func_ov001_02194a34(void) {
    data_ov001_021a9bd8->mUnk_64 = 1;
    data_ov001_021a9bd8->mUnk_68 = 0;
    func_ov001_02194d78();
}

void func_ov001_02194a20(void) {
    data_ov001_021a9bd8->mUnk_64 = 2;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_02194a0c(void) {
    data_ov001_021a9bd8->mUnk_64 = 3;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_021949d4(void) {
    data_ov001_021a9bd8->mUnk_64 = 4;
    data_ov001_021a9bd8->mUnk_68 = 0;
    switch (data_ov001_021a9bd8->mUnk_7c) {
        case 0:
            func_ov001_02194d48();
            break;
        case 1:
            func_ov001_02194d18();
            break;
    }
    func_ov001_02194d78();
}

void func_ov001_021949c0(void) {
    data_ov001_021a9bd8->mUnk_64 = 5;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_021949ac(void) {
    data_ov001_021a9bd8->mUnk_64 = 6;
    data_ov001_021a9bd8->mUnk_68 = 0;
}

void func_ov001_02194730(void *heap) {
    u32 acc = 0;
    s32 i;
    s32 rem;
    void *p;
    vu16 zero;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 1;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 1;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x8800;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & 0x43) | 0x1018;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x5810;
    data_ov001_021a9bd8 = func_02036bec(heap, 0x94);
    data_ov001_021a9bd8->mUnk_5c = heap;
    data_ov001_021a9bd8->mUnk_60 = 0;
    data_ov001_021a9bd8->mUnk_78 = 0;
    data_ov001_021a9bd8->mUnk_7c = 0;
    data_ov001_021a9bd8->mUnk_88 = 0;
    data_ov001_021a9bd8->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bd8->mUnk_80[i] = 0;
    }
    func_ov001_021953d0();
    func_021172a8(heap);
    func_0211dfb4((u32) heap);
    p = func_02111318();
    func_020ae6d4(p, func_0211130c());
    func_02124ed0(heap, data_ov001_021a9bd8->mUnk_08, data_ov001_021a9bd8->mUnk_10, &data_ov001_021a9bd8->mUnk_50);
    func_02124ed0(heap, data_ov001_021a9bd8->mUnk_1c, data_ov001_021a9bd8->mUnk_24, &data_ov001_021a9bd8->mUnk_54);
    data_ov001_021a9bd8->mUnk_58 = func_02047a28("common.bmg");
    func_021243ac(heap, 0, data_ov001_021a9bd8->mUnk_10, 200, 16, 0, data_ov001_021a9bd8->mUnk_04,
                  data_ov001_021a9bd8->mUnk_08, data_ov001_021a9bd8->mUnk_50, 0x8000);
    rem = func_02148ca0();
    for (i = 0; i < 4; i++) {
        rem -= func_021243ac(heap, data_ov001_021a6614[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a661c[i],
                             data_ov001_021a6624[i], i, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
        rem -= func_021243ac(heap, data_ov001_021a662c[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a6664[i],
                             data_ov001_021a6634[i], i + 4, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
        rem -= func_021243ac(heap, data_ov001_021a663c[i], data_ov001_021a9bd8->mUnk_24, data_ov001_021a6644[i],
                             data_ov001_021a664c[i], i + 12, data_ov001_021a9bd8->mUnk_18, data_ov001_021a9bd8->mUnk_1c,
                             data_ov001_021a9bd8->mUnk_54, rem);
    }
    data_ov001_021a9bd8->mUnk_74 = 0;
    for (i = 0; i < 8; i++) {
        acc |= func_ov001_02194d04(i);
    }
    if (acc == 0) {
        data_ov001_021a9bd8->mUnk_74 = 16;
    }
    data_ov001_021a9bd8->mUnk_4c = func_02036bec(heap, 0x134);
    zero = 0;
    func_0214cfe4(zero, data_ov001_021a9bd8->mUnk_4c, 0x134);
    func_ov001_02194a50();
}

void func_ov001_021946d0(void) {
    u32 v;

    func_02117218();
    func_0211df38();
    data_ov001_021a9bd8 = NULL;
    v = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    v &= ~0x11;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (v << 8);
    v = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    v &= ~0x8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (v << 8);
}

void func_ov001_02194690(void) {
    data_ov001_021a9bd8->mUnk_68++;
    data_ov001_021a9bd8->mUnk_6c = func_020ae4c0(1, -192, 0, data_ov001_021a9bd8->mUnk_68, 10);
    if (data_ov001_021a9bd8->mUnk_68 >= 10) {
        func_ov001_02194a34();
    }
}

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
    BOOL x1, y1, x2, y2, x3, y3;

    func_ov001_02194f20();
    x1 = TRUE;
    y1 = FALSE;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        y1 = TRUE;
    }
    if (y1 == FALSE && data_02175628[idx].mUnk_4c == 0) {
        x1 = FALSE;
    }
    if (x1 != FALSE) {
        a = func_0201ea84(data_ov001_021a9bd8->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    x2 = FALSE;
    y2 = FALSE;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        y2 = TRUE;
    }
    if (y2 == FALSE && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
        x2 = TRUE;
    }
    if (x2 != FALSE) {
        b = func_0201ea84(data_ov001_021a9bd8->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if (a != 0) {
        data_ov001_021a9bd8->mUnk_88 = 0;
    }
    if (a != 1) {
        data_ov001_021a9bd8->mUnk_8c = 0;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        x3 = FALSE;
        y3 = FALSE;
        if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
            y3 = TRUE;
        }
        if (y3 == FALSE && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
            x3 = TRUE;
        }
        if (x3 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                           data_02175628[idx].mUnk_4a) == 0) {
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
    s16 x = 0;

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
    s16 x = 0;

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
