#include "01/code_021956dc.h"

#include "01/code_02193c5c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_02148ca0.h"
#include "code_0201ea58.h"
#include "registers.h"
#include "Main/Unknown/code_02126000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "00/code_02182fdc.h"
#include "03/code_021b94b8.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_020ae408.h"
#include "01/code_02198000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov001_021978b4(void) {
    Unk020b4a44 *l0 = NULL;
    Unk020b4934 *l4 = NULL;
    Unk020b4a44 *l8 = NULL;
    Unk020b47d8 *lc = NULL;
    Unk020b47d8 *l10 = NULL;
    Unk020b4a44 *l14 = NULL;
    Unk020b4934 *l18 = NULL;
    Unk020b4a44 *l1c = NULL;
    Unk020b47d8 *l20 = NULL;
    u16 *p;

    LocateNcgr2(&gRecordTAtt->mUnk_00, FindSceneFile(gRecordTAttMNcgrName));
    LocateNcer(&gRecordTAtt->mUnk_04, FindSceneFile(gRecordTAttMNcerName));
    LocateNclr(&l0, FindSceneFile(gRecordTAttMONclrName));
    gRecordTAtt->mUnk_08 = FindSceneFile(gRecordTAttMBnclName);
    gRecordTAtt->mUnk_10 = FindSceneFile(gRecordTAttMBnllName);
    LocateNcgr2(&gRecordTAtt->mUnk_14, FindSceneFile(gRecordTAttSNcgrName));
    LocateNcer(&gRecordTAtt->mUnk_18, FindSceneFile(gRecordTAttSNcerName));
    LocateNclr(&l14, FindSceneFile(gRecordTAttSONclrName));
    gRecordTAtt->mUnk_1c = FindSceneFile(gRecordTAttSBnclName);
    gRecordTAtt->mUnk_20 = FindSceneFile(gRecordTAttSBnblName);
    gRecordTAtt->mUnk_24 = FindSceneFile(gRecordTAttSBnllName);
    gRecordTAtt->mUnk_28 = func_020b4018(0);
    gRecordTAtt->mUnk_2c = func_020b400c(0);
    gRecordTAtt->mUnk_30 = func_020b4030(0);
    gRecordTAtt->mUnk_34 = func_020b4000(0);
    LocateNcgr(&l4, FindSceneFile(gRecordTAttMBNcgrName));
    LocateNscr(&lc, FindSceneFile(gRecordTAttMNscrName));
    LocateNscr(&l10, FindSceneFile(gRecordTAttMScoreNscrName));
    LocateNclr(&l8, FindSceneFile(gRecordTAttMBNclrName));
    LocateNcgr(&l18, FindSceneFile(gRecordTAttSBNcgrName));
    LocateNclr(&l1c, FindSceneFile(gRecordTAttSBNclrName));
    LocateNscr(&l20, FindSceneFile(gRecordTAttSNscrName));
    p = l0->mUnk_0c;
    func_02016468(0x13, 0, gRecordTAtt->mUnk_00->mUnk_14, gRecordTAtt->mUnk_00->mUnk_10);
    func_02016468(0xe, 0, l0->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, (u8 *) p + 0x1c0, 0x40);
    func_02016468(0x23, 0, gRecordTAtt->mUnk_14->mUnk_14, gRecordTAtt->mUnk_14->mUnk_10);
    func_02016468(0x1e, 0, l14->mUnk_0c, l14->mUnk_08);
    func_02016468(4, 0, l4->mUnk_14, l4->mUnk_10);
    func_02016468(8, 0, lc->mUnk_0c, lc->mUnk_08);
    func_02016468(9, 0, l10->mUnk_0c, l10->mUnk_08);
    func_02016468(0xf, 0, l8->mUnk_0c, 0x40);
    func_02016468(0x17, 0, l18->mUnk_14, l18->mUnk_10);
    func_02016468(0x1f, 0, l1c->mUnk_0c, 0x40);
    func_02016468(0x1b, 0, l20->mUnk_0c, l20->mUnk_08);
}

void func_ov001_021975f4(u16 a) {
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 value;
    s32 result;
    u16 tile;
    u16 index;
    u16 slot;
    u16 pal;
    u8 *palette;

    if (a == 0) {
        u16 cnt;

        value = data_ov001_021a6828[0];
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value);
        index = data_ov001_021a6850[0][0];
        gRecordTAtt->mUnk_38[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 0,
                      index, gRecordTAtt->mUnk_04, gRecordTAtt->mUnk_08);
        palette = (u8 *) ((Unk020b4a44 *) gRecordTAtt->mUnk_30)->mUnk_0c;
        func_02016468(0xe, data_ov001_021a683c[0] << 5,
                      palette + (func_02124a68(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value);
        slot = data_ov001_021a6850[0][1];
        gRecordTAtt->mUnk_38[slot].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mUnk_04, gRecordTAtt->mUnk_08, slot, data_ov001_021a683c[5],
                      0);
        cnt = gRecordTAtt->mUnk_08->mUnk_06;
        func_02060134(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[0];
        gRecordTAtt->mUnk_38[cnt + pal].mUnk_00 = 1;
        func_02124224(0, pal, gRecordTAtt->mUnk_10, str, gRecordTAtt->mUnk_08,
                      gRecordTAtt->mUnk_38, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        pal = data_ov001_021a6810[0];
        gRecordTAtt->mUnk_38[cnt + pal].mUnk_00 = 1;
        func_0212426c(0, pal, gRecordTAtt->mUnk_10, str, gRecordTAtt->mUnk_08,
                      gRecordTAtt->mUnk_38);
    } else {
        u16 cnt;

        value = data_ov001_021a6828[a];
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value);
        index = data_ov001_021a6850[a][0];
        gRecordTAtt->mUnk_3c[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_28, gRecordTAtt->mUnk_34, 1,
                      index, gRecordTAtt->mUnk_18, gRecordTAtt->mUnk_1c);
        palette = (u8 *) ((Unk020b4a44 *) gRecordTAtt->mUnk_30)->mUnk_0c;
        func_02016468(0x1e, data_ov001_021a683c[a] << 5,
                      palette + (func_02124a68(tile, gRecordTAtt->mUnk_2c, gRecordTAtt->mUnk_34) << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value);
        slot = data_ov001_021a6852[a][0];
        gRecordTAtt->mUnk_3c[slot].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mUnk_18, gRecordTAtt->mUnk_1c, slot, data_ov001_021a6846[a],
                      1);
        cnt = gRecordTAtt->mUnk_1c->mUnk_06;
        func_02060134(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[a];
        gRecordTAtt->mUnk_3c[cnt + pal].mUnk_00 = 1;
        func_02124224(1, pal, gRecordTAtt->mUnk_24, str, gRecordTAtt->mUnk_1c,
                      gRecordTAtt->mUnk_3c, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], value, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        pal = data_ov001_021a6810[a];
        gRecordTAtt->mUnk_3c[cnt + pal].mUnk_00 = 1;
        func_0212426c(1, pal, gRecordTAtt->mUnk_24, str, gRecordTAtt->mUnk_1c,
                      gRecordTAtt->mUnk_3c);
    }
}

void func_ov001_0219750c(u16 a) {
    u16 cnt;

    if (a == 0) {
        gRecordTAtt->mUnk_38[data_ov001_021a6850[0][0]].mUnk_00 = 0;
        gRecordTAtt->mUnk_38[data_ov001_021a6850[0][1]].mUnk_00 = 0;
        cnt = gRecordTAtt->mUnk_08->mUnk_06;
        gRecordTAtt->mUnk_38[cnt + data_ov001_021a67d4[0]].mUnk_00 = 1;
        func_02124224(0, data_ov001_021a67d4[0], gRecordTAtt->mUnk_10, L"--:--:---",
                      gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, 7);
        gRecordTAtt->mUnk_38[cnt + data_ov001_021a6810[0]].mUnk_00 = 0;
    } else {
        gRecordTAtt->mUnk_3c[data_ov001_021a6850[a][0]].mUnk_00 = 0;
        gRecordTAtt->mUnk_3c[data_ov001_021a6852[a][0]].mUnk_00 = 0;
        cnt = gRecordTAtt->mUnk_1c->mUnk_06;
        gRecordTAtt->mUnk_3c[cnt + data_ov001_021a67d4[a]].mUnk_00 = 1;
        func_02124224(1, data_ov001_021a67d4[a], gRecordTAtt->mUnk_24, L"--:--:---",
                      gRecordTAtt->mUnk_1c, gRecordTAtt->mUnk_3c, 7);
        gRecordTAtt->mUnk_3c[cnt + data_ov001_021a6810[a]].mUnk_00 = 0;
    }
}

void func_ov001_021972f4(void) {
    RecordTAtt *p;
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 i;
    s32 result;
    u16 tile;
    u8 *palette;
    u16 cnt;

    p = gRecordTAtt;
    func_0212426c(0, 0, gRecordTAtt->mUnk_10, GetBmgEntry(p->mUnk_40, data_ov001_021a6880[p->mUnk_6c]),
                  p->mUnk_08, p->mUnk_38);
    for (i = 0; i < 5; i++) {
        if (func_02060228(data_ov001_021a6900[gRecordTAtt->mUnk_6c], data_ov001_021a6828[i])) {
            func_ov001_021975f4(i);
        } else {
            func_ov001_0219750c(i);
        }
    }
    cnt = gRecordTAtt->mUnk_08->mUnk_06;
    if (func_02060228(data_ov001_021a6900[gRecordTAtt->mUnk_6c], 5)) {
        result = func_020601e4(data_ov001_021a6900[gRecordTAtt->mUnk_6c], 5);
        gRecordTAtt->mUnk_38[5].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748((u32) (tile), (void *) (gRecordTAtt->mUnk_2c), (void *) (gRecordTAtt->mUnk_28),
                      (void *) (gRecordTAtt->mUnk_34), 0, (u32) (5), (void *) (gRecordTAtt->mUnk_04),
                      (void *) (gRecordTAtt->mUnk_08));
        palette = (u8 *) ((Unk020b4a44 *) gRecordTAtt->mUnk_30)->mUnk_0c;
        func_02016468(0xe, 0x80,
                      palette + (func_02124a68((u32) (tile), (void *) (gRecordTAtt->mUnk_2c),
                                               (void *) (gRecordTAtt->mUnk_34))
                                 << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], 5);
        gRecordTAtt->mUnk_38[6].mUnk_00 = 1;
        func_021171a0(result, gRecordTAtt->mUnk_04, gRecordTAtt->mUnk_08, 6, 6, 0);
        func_02060134(data_ov001_021a6900[gRecordTAtt->mUnk_6c], 5, &time);
        func_02116b8c(&time, str);
        gRecordTAtt->mUnk_38[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, gRecordTAtt->mUnk_10, str, gRecordTAtt->mUnk_08,
                      gRecordTAtt->mUnk_38, 7);
        func_020600d0(data_ov001_021a6900[gRecordTAtt->mUnk_6c], 5, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        gRecordTAtt->mUnk_38[cnt + 4].mUnk_00 = 1;
        func_0212426c(0, 4, gRecordTAtt->mUnk_10, str, gRecordTAtt->mUnk_08,
                      gRecordTAtt->mUnk_38);
    } else {
        gRecordTAtt->mUnk_38[5].mUnk_00 = 0;
        gRecordTAtt->mUnk_38[6].mUnk_00 = 0;
        gRecordTAtt->mUnk_38[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, gRecordTAtt->mUnk_10, L"--:--:---", gRecordTAtt->mUnk_08,
                      gRecordTAtt->mUnk_38, 7);
        gRecordTAtt->mUnk_38[cnt + 4].mUnk_00 = 0;
    }
}

void func_ov001_021972b4(void) {
    gRecordTAtt->mUnk_6c++;
    if (gRecordTAtt->mUnk_6c >= 0x20) {
        gRecordTAtt->mUnk_6c = 0;
    }
    if (func_020600b4(data_ov001_021a6900[gRecordTAtt->mUnk_6c]) == 0) {
        func_ov001_021972b4();
    }
}

void func_ov001_02197274(void) {
    gRecordTAtt->mUnk_6c--;
    if (gRecordTAtt->mUnk_6c < 0) {
        gRecordTAtt->mUnk_6c = 0x1f;
    }
    if (func_020600b4(data_ov001_021a6900[gRecordTAtt->mUnk_6c]) == 0) {
        func_ov001_02197274();
    }
}

s32 func_ov001_02197210(void) {
    u8 buf[0x14];

    if (func_02060228(data_ov001_021a6900[gRecordTAtt->mUnk_6c], data_ov001_021a6828[0]) != 0) {
        if (func_0205fdb4(data_ov001_021a6900[gRecordTAtt->mUnk_6c], buf) != 0) {
            return 1;
        }
        func_0212ecc0(&data_0217d068, 0, 0x16);
        return 0;
    }
    return 0;
}

void func_ov001_02197058(void) {
    s32 i;
    s32 j;
    u16 n;
    u16 m;

    gRecordTAtt->mUnk_54 = 0;
    gRecordTAtt->mUnk_58 = 0;
    gRecordTAtt->mUnk_5c = -192;
    gRecordTAtt->mUnk_60 = -256;
    gRecordTAtt->mUnk_64 = -192;
    gRecordTAtt->mUnk_68 = -256;
    n = gRecordTAtt->mUnk_08->mUnk_06;
    m = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_38[0].mUnk_06 = -192;
    gRecordTAtt->mUnk_38[0].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[1].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[2].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[3].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[4].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[5].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[6].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[n].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[n + 1].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[n + 2].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[n + 3].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_38[n + 4].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = 0x100;
    gRecordTAtt->mUnk_3c[m + 8].mUnk_04 = 0x100;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = 0x100;
        gRecordTAtt->mUnk_3c[m + data_ov001_021a67d4[i]].mUnk_04 = 0x100;
        gRecordTAtt->mUnk_3c[m + data_ov001_021a6810[i]].mUnk_04 = 0x100;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = 0x100;
        }
    }
    for (j = 0; j < 2; j++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67c4[j]].mUnk_00 = 0;
    }
    gRecordTAtt->mUnk_3c[13].mUnk_00 = 0;
}

void func_ov001_0219703c(void) {
    gRecordTAtt->mUnk_54 = 1;
    gRecordTAtt->mUnk_58 = 0;
    func_ov001_021972f4();
}

void func_ov001_02197024(void) {
    gRecordTAtt->mUnk_54 = 2;
    gRecordTAtt->mUnk_58 = 0;
    gRecordTAtt->mUnk_74 = 0;
}

void func_ov001_02197010(void) {
    gRecordTAtt->mUnk_54 = 3;
    gRecordTAtt->mUnk_58 = 0;
}

void func_ov001_02196fd8(void) {
    gRecordTAtt->mUnk_54 = 4;
    gRecordTAtt->mUnk_58 = 0;
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            func_ov001_021972b4();
            break;
        case 1:
            func_ov001_02197274();
            break;
    }
    func_ov001_021972f4();
}

void func_ov001_02196fc4(void) {
    gRecordTAtt->mUnk_54 = 5;
    gRecordTAtt->mUnk_58 = 0;
}

void func_ov001_02196fb0(void) {
    gRecordTAtt->mUnk_54 = 6;
    gRecordTAtt->mUnk_58 = 0;
}

void func_ov001_02196f80(void) {
    gRecordTAtt->mUnk_54 = 7;
    gRecordTAtt->mUnk_58 = 0;
    gRecordTAtt->mUnk_3c[13].mUnk_00 = 1;
    func_0212ecc0(&data_0217d068, 0, 4);
}

void func_ov001_02196f64(void) {
    gRecordTAtt->mUnk_54 = 8;
    gRecordTAtt->mUnk_58 = 0;
    func_021282c8();
}

void func_ov001_02196ecc(void) {
    u16 buf[0x102];
    RecordTAtt *p;
    void *a;
    void *b;

    gRecordTAtt->mUnk_54 = 9;
    gRecordTAtt->mUnk_58 = 0;
    buf[0] = 0;
    func_0214cfe4(buf[0], &buf[1], 0x200);
    p = gRecordTAtt;
    a = GetBmgEntry(p->mUnk_44, data_ov001_021a6980[p->mUnk_6c]);
    func_0212513c(a, GetBmgEntry(p->mUnk_48, 10), &buf[1], 0x200);
    a = GetBmgEntry(gRecordTAtt->mUnk_40, 0);
    b = GetBmgEntry(gRecordTAtt->mUnk_40, 1);
    func_02125fd4((u32) &buf[1], (u32) a, (u32) b, 1, 0, 1, 1, 1);
}

void func_ov001_02196eb0(void) {
    gRecordTAtt->mUnk_54 = 10;
    gRecordTAtt->mUnk_58 = 0;
    func_02125ed0(0, 11);
}

void func_ov001_02196e88(void) {
    gRecordTAtt->mUnk_54 = 11;
    gRecordTAtt->mUnk_58 = 0;
    func_02125fc0();
    func_02125ed0(0, 5);
}

void func_ov001_02196e54(void) {
    gRecordTAtt->mUnk_54 = 12;
    gRecordTAtt->mUnk_58 = 0;
    func_02128374();
    func_ov001_021972f4();
    gRecordTAtt->mUnk_3c[13].mUnk_00 = 0;
}

void func_ov001_02196e30(void) {
    gRecordTAtt->mUnk_54 = 13;
    gRecordTAtt->mUnk_58 = 0;
    func_0212ecc0(&data_0217d068, 0, 6);
}

void func_ov001_02196dbc(void) {
    s32 i;
    s32 n;
    s32 k;
    u8 buf[0x10];
    u16 str[0x100];

    i = 0;
    n = 0;
    k = 0;
    gRecordTAtt->mUnk_54 = 14;
    gRecordTAtt->mUnk_58 = i;
    func_0205fdb4(data_ov001_021a6900[gRecordTAtt->mUnk_6c], buf);
    while (n < 19) {
        k++;
        if (k > 4) {
            k = 0;
            str[n] = ' ';
            n++;
        } else {
            str[n] = buf[i];
            n++;
            i++;
        }
    }
    str[n] = 0;
    func_02126248((u32) str, 0, 1, 0, 0, 0);
}

void func_ov001_02196da8(void) {
    gRecordTAtt->mUnk_54 = 15;
    gRecordTAtt->mUnk_58 = 0;
}

void func_ov001_02196d8c(void) {
    gRecordTAtt->mUnk_54 = 0x10;
    gRecordTAtt->mUnk_58 = 0;
    func_02125fc0();
}

void func_ov001_02196d78(void) {
    gRecordTAtt->mUnk_54 = 0x11;
    gRecordTAtt->mUnk_58 = 0;
}

void func_ov001_02196cd0(void) {
    s32 i;

    gRecordTAtt->mUnk_3c[data_ov001_021a67c4[0]].mUnk_04 = -func_020adc64(6 - gRecordTAtt->mUnk_78[0]);
    gRecordTAtt->mUnk_3c[data_ov001_021a67c4[1]].mUnk_04 = func_020adc64(6 - gRecordTAtt->mUnk_78[1]);
    for (i = 0; i < 2; i++) {
        if (gRecordTAtt->mUnk_78[i] > 0) {
            gRecordTAtt->mUnk_78[i]--;
            gRecordTAtt->mUnk_3c[data_ov001_021a67c0[i]].mUnk_00 = 0;
            gRecordTAtt->mUnk_3c[data_ov001_021a67c4[i]].mUnk_00 = 1;
        } else {
            gRecordTAtt->mUnk_3c[data_ov001_021a67c0[i]].mUnk_00 = 1;
            gRecordTAtt->mUnk_3c[data_ov001_021a67c4[i]].mUnk_00 = 0;
        }
    }
}

s32 func_ov001_02196c4c(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 m;

    m = data_02175628[idx].mUnk_00;
    if (m != 0) {
        if (data_ov001_021a681c[0] == (data_ov001_021a681c[0] | m)) {
            gRecordTAtt->mUnk_80 = 1;
            gRecordTAtt->mUnk_84 = 0;
        } else if (data_ov001_021a681c[gRecordTAtt->mUnk_80] ==
                   (data_ov001_021a681c[gRecordTAtt->mUnk_80] | m)) {
            gRecordTAtt->mUnk_80++;
            gRecordTAtt->mUnk_84 = 0;
            if (gRecordTAtt->mUnk_80 >= 6) {
                gRecordTAtt->mUnk_80 = 0;
                return 1;
            }
        } else {
            gRecordTAtt->mUnk_80 = 0;
        }
    }
    return 0;
}

void InitRecordTAtt(void *heap) {
    s32 i;
    s32 k;
    s32 rem;
    RecordTAtt *p;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~3) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~3) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~3) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & 0x43) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & 0x43) | 0xcc00;
    (reg_G2S_DB_BG1CNT) = ((reg_G2S_DB_BG1CNT) & 0x43) | 0x1018;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x5810;
    gRecordTAtt = func_02036bec(heap, 0x94);
    gRecordTAtt->mUnk_4c = heap;
    gRecordTAtt->mUnk_50 = 0;
    gRecordTAtt->mUnk_6c = 0;
    gRecordTAtt->mUnk_70 = 0;
    gRecordTAtt->mUnk_74 = 0;
    gRecordTAtt->mUnk_88 = 0;
    gRecordTAtt->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        gRecordTAtt->mUnk_78[i] = 0;
    }
    func_ov001_021978b4();
    func_021172a8(heap);
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_10, &gRecordTAtt->mUnk_38);
    func_02124ed0(heap, gRecordTAtt->mUnk_1c, gRecordTAtt->mUnk_24, &gRecordTAtt->mUnk_3c);
    gRecordTAtt->mUnk_40 = func_02047a28("common.bmg");
    gRecordTAtt->mUnk_44 = FindSceneFile("ghost.bmg");
    gRecordTAtt->mUnk_48 = FindSceneFile("record.bmg");
    rem = 0x8000;
    rem -= func_021243ac(heap, 0, gRecordTAtt->mUnk_10, 0xc8, 0x10, 0, gRecordTAtt->mUnk_04,
                         gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, rem);
    rem -= func_021243ac(heap, 1, gRecordTAtt->mUnk_10, 0x46, 0x10, 1, gRecordTAtt->mUnk_04,
                         gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, rem);
    rem -= func_021243ac(heap, 2, gRecordTAtt->mUnk_10, 0x46, 0x10, 2, gRecordTAtt->mUnk_04,
                         gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, rem);
    rem -= func_021243ac(heap, 3, gRecordTAtt->mUnk_10, 0x7c, 0x10, 3, gRecordTAtt->mUnk_04,
                         gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, rem);
    rem -= func_021243ac(heap, 4, gRecordTAtt->mUnk_10, 0x64, 0x10, 4, gRecordTAtt->mUnk_04,
                         gRecordTAtt->mUnk_08, gRecordTAtt->mUnk_38, rem);
    rem = func_02148ca0();
    for (k = 1; k < 5; k++) {
        rem -= func_021243ac(heap, data_ov001_021a67d4[k], gRecordTAtt->mUnk_24, data_ov001_021a67c8[k],
                             data_ov001_021a67e0[k], k, gRecordTAtt->mUnk_18, gRecordTAtt->mUnk_1c,
                             gRecordTAtt->mUnk_3c, rem);
        rem -= func_021243ac(heap, data_ov001_021a6810[k], gRecordTAtt->mUnk_24, data_ov001_021a6804[k],
                             data_ov001_021a67ec[k], k + 5, gRecordTAtt->mUnk_18, gRecordTAtt->mUnk_1c,
                             gRecordTAtt->mUnk_3c, rem);
    }
    func_021243ac(heap, 8, gRecordTAtt->mUnk_24, 0x98, 0x10, 0xd, gRecordTAtt->mUnk_18,
                  gRecordTAtt->mUnk_1c, gRecordTAtt->mUnk_3c, rem);
    p = gRecordTAtt;
    func_0212426c(1, 8, gRecordTAtt->mUnk_24, GetBmgEntry(p->mUnk_48, 3), p->mUnk_1c, p->mUnk_3c);
    func_ov001_02197058();
}

void func_ov001_02196904(void) {
    u32 a;
    u32 b;

    func_02117218();
    gRecordTAtt = NULL;
    a = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~0x1f00) | ((a & ~0x13) << 8);
    b = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~0x1f00) | ((b & ~9) << 8);
}

void func_ov001_021968bc(void) {
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, -0xc0, 0, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_5c = v;
    gRecordTAtt->mUnk_64 = v;
    gRecordTAtt->mUnk_38[0].mUnk_06 = v;
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_0219703c();
    }
}

void func_ov001_02196724(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_60 = v;
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_08->mUnk_06;
    y = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_38[0].mUnk_04 = v;
    gRecordTAtt->mUnk_38[1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[4].mUnk_04 = v;
    gRecordTAtt->mUnk_38[5].mUnk_04 = v;
    gRecordTAtt->mUnk_38[6].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 4].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_02197024();
    }
}

void func_ov001_02196514(void) {
    s32 a = -1;
    s32 b = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 x;
    s32 y;
    u16 v;

    func_ov001_02196cd0();
    x = 1;
    y = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        y = 1;
    }
    if (y == 0 && v == 0) {
        x = 0;
    }
    if (x != 0) {
        a = func_0201ea84(gRecordTAtt->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    x = 0;
    y = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        y = 1;
    }
    if (y == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
        x = 1;
    }
    if (x != 0) {
        b = func_0201ea84(gRecordTAtt->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if (a != 0) {
        gRecordTAtt->mUnk_88 = 0;
    }
    if (a != 1) {
        gRecordTAtt->mUnk_8c = 0;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        x = 0;
        y = 0;
        v = data_02175628[idx].mUnk_4c;
        if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
            y = 1;
        }
        if (y == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
            x = 1;
        }
        if (x == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto other;
        }
    }
    func_ov001_02196fc4();
    gRecordTAtt->mUnk_90 = 0;
    func_02128310(0);
    goto done;
other:
    if (b == 2 || (u16) (data_02175628[idx].mUnk_00 & 0x400) != 0) {
        func_ov001_02196f80();
    } else if ((a == 0 && gRecordTAtt->mUnk_88 != 0) || (b == 0 && gRecordTAtt->mUnk_88 == 0) ||
               (u16) (data_02175628[idx].mUnk_02 & 0x20) != 0) {
        gRecordTAtt->mUnk_70 = 1;
        gRecordTAtt->mUnk_78[0] = 6;
        gRecordTAtt->mUnk_88 = 1;
        func_ov001_02197010();
        func_0212ecc0(&data_0217d068, 0, 2);
    } else if ((a == 1 && gRecordTAtt->mUnk_8c != 0) || (b == 1 && gRecordTAtt->mUnk_8c == 0) ||
               (u16) (data_02175628[idx].mUnk_02 & 0x10) != 0) {
        gRecordTAtt->mUnk_70 = 0;
        gRecordTAtt->mUnk_78[1] = 6;
        gRecordTAtt->mUnk_8c = 1;
        func_ov001_02197010();
        func_0212ecc0(&data_0217d068, 0, 2);
    }
done:
    if (func_ov001_02196c4c() != 0) {
        if (func_ov001_02197210() != 0) {
            func_ov001_02196e30();
        }
    }
}

void func_ov001_021963a8(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            k = -0x100;
            break;
        case 1:
            k = 0x100;
            break;
    }
    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0, k, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_60 = v;
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_08->mUnk_06;
    y = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_38[0].mUnk_04 = v;
    gRecordTAtt->mUnk_38[1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[4].mUnk_04 = v;
    gRecordTAtt->mUnk_38[5].mUnk_04 = v;
    gRecordTAtt->mUnk_38[6].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_02196fd8();
    }
}

void func_ov001_0219623c(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (gRecordTAtt->mUnk_70) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = -0x100;
            break;
    }
    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, k, 0, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_60 = v;
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_08->mUnk_06;
    y = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_38[0].mUnk_04 = v;
    gRecordTAtt->mUnk_38[1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[4].mUnk_04 = v;
    gRecordTAtt->mUnk_38[5].mUnk_04 = v;
    gRecordTAtt->mUnk_38[6].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_02197024();
    }
}

void func_ov001_021960a4(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_60 = v;
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_08->mUnk_06;
    y = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_38[0].mUnk_04 = v;
    gRecordTAtt->mUnk_38[1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[4].mUnk_04 = v;
    gRecordTAtt->mUnk_38[5].mUnk_04 = v;
    gRecordTAtt->mUnk_38[6].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 1].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 2].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 3].mUnk_04 = v;
    gRecordTAtt->mUnk_38[x + 4].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_02196fb0();
    }
}

void func_ov001_02196058(void) {
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0, -0xc0, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_5c = v;
    gRecordTAtt->mUnk_64 = v;
    gRecordTAtt->mUnk_38[0].mUnk_06 = v;
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_02111488(gRecordTAtt->mUnk_90);
    }
}

void func_ov001_02195ff8(void) {
    s16 v;
    u16 x;

    gRecordTAtt->mUnk_58++;
    v = func_020ae488(gRecordTAtt->mUnk_58);
    x = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[x + 8].mUnk_04 = v;
    if (gRecordTAtt->mUnk_58 >= 10) {
        func_ov001_02196f64();
    }
}

void func_ov001_02195eb8(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 > 10) {
        if (func_02128274() != 0) {
            func_ov001_02196ecc();
        }
    }
    if (gRecordTAtt->mUnk_58 == 7) {
        gRecordTAtt->mUnk_3c[12].mUnk_00 = 0;
        gRecordTAtt->mUnk_3c[13].mUnk_00 = 0;
    }
}

void func_ov001_02195ea0(void) {
    if (func_02125fa4() != 0) {
        func_ov001_02196eb0();
    }
}

void func_ov001_02195e38(void) {
    if (func_02125f54() != 0) {
        if (func_02125f60() == 0) {
            if (func_02060268(data_ov001_021a6900[gRecordTAtt->mUnk_6c]) == 0) {
                func_02060004(data_ov001_021a6900[gRecordTAtt->mUnk_6c]);
                func_02057d9c();
                if (data_021759d4->mUnk_0c != 0) {
                    func_02145d38();
                }
            }
            gRecordTAtt->mUnk_74 = 1;
        }
        func_ov001_02196e88();
    }
}

void func_ov001_02195d64(void) {
    s16 v;
    u16 w;

    gRecordTAtt->mUnk_58++;
    if (gRecordTAtt->mUnk_74 != 0) {
        v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mUnk_58, 10);
        gRecordTAtt->mUnk_60 = v;
        w = gRecordTAtt->mUnk_08->mUnk_06;
        gRecordTAtt->mUnk_38[0].mUnk_04 = v;
        gRecordTAtt->mUnk_38[1].mUnk_04 = v;
        gRecordTAtt->mUnk_38[2].mUnk_04 = v;
        gRecordTAtt->mUnk_38[3].mUnk_04 = v;
        gRecordTAtt->mUnk_38[4].mUnk_04 = v;
        gRecordTAtt->mUnk_38[5].mUnk_04 = v;
        gRecordTAtt->mUnk_38[6].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 1].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 2].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 3].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 4].mUnk_04 = v;
    }
    if (gRecordTAtt->mUnk_58 >= 10) {
        if (func_02125f88() != 0) {
            func_ov001_02196e54();
        }
    }
}

void func_ov001_02195ba4(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mUnk_58, 10);
    if (gRecordTAtt->mUnk_74 != 0) {
        u16 w;

        gRecordTAtt->mUnk_60 = v;
        w = gRecordTAtt->mUnk_08->mUnk_06;
        gRecordTAtt->mUnk_38[0].mUnk_04 = v;
        gRecordTAtt->mUnk_38[1].mUnk_04 = v;
        gRecordTAtt->mUnk_38[2].mUnk_04 = v;
        gRecordTAtt->mUnk_38[3].mUnk_04 = v;
        gRecordTAtt->mUnk_38[4].mUnk_04 = v;
        gRecordTAtt->mUnk_38[5].mUnk_04 = v;
        gRecordTAtt->mUnk_38[6].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 1].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 2].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 3].mUnk_04 = v;
        gRecordTAtt->mUnk_38[w + 4].mUnk_04 = v;
    }
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 > 10) {
        if (func_02128294() != 0) {
            func_ov001_02197024();
        }
    }
    if (gRecordTAtt->mUnk_58 == 2) {
        gRecordTAtt->mUnk_3c[12].mUnk_00 = 1;
    }
}

void func_ov001_02195a6c(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_68 = v;
    x = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 > 10) {
        func_ov001_02196dbc();
    }
    if (gRecordTAtt->mUnk_58 == 7) {
        gRecordTAtt->mUnk_3c[12].mUnk_00 = 0;
        gRecordTAtt->mUnk_3c[13].mUnk_00 = 0;
    }
}

void func_ov001_02195a54(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        func_ov001_02196da8();
    }
    return;
}

void func_ov001_021959d8(void) {
    Unk02175628Index i;
    u16 f;
    s32 b;

    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 2;
    if (f == 0) {
        f = 0;
        b = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            b = 1;
        }
        if (b == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            f = 1;
        }
        if (f == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    func_ov001_02196d8c();
    func_02128310(0);
}

void func_ov001_021959c0(void) {
    int v1;
    v1 = func_02125f88();
    if (v1 != 0) {
        func_ov001_02196d78();
    }
    return;
}

void func_ov001_02195894(void) {
    s32 i;
    s32 j;
    u16 m;
    s16 v;

    gRecordTAtt->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, gRecordTAtt->mUnk_58, 10);
    gRecordTAtt->mUnk_68 = v;
    m = gRecordTAtt->mUnk_1c->mUnk_06;
    gRecordTAtt->mUnk_3c[15].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[16].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[12].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[13].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[14].mUnk_04 = v;
    gRecordTAtt->mUnk_3c[m + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        gRecordTAtt->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[m + data_ov001_021a67d4[i]].mUnk_04 = v;
        gRecordTAtt->mUnk_3c[m + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            gRecordTAtt->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (gRecordTAtt->mUnk_58 > 10) {
        func_ov001_02197024();
    }
    if (gRecordTAtt->mUnk_58 == 2) {
        gRecordTAtt->mUnk_3c[12].mUnk_00 = 1;
    }
}

void AdvanceRecordTAtt(void) {
    RecordTAtt *p;

    gRecordTAtt->mUnk_50 = gRecordTAtt->mUnk_54;
    switch (gRecordTAtt->mUnk_50) {
        case 0:
            func_ov001_021968bc();
            break;
        case 1:
            func_ov001_02196724();
            break;
        case 2:
            func_ov001_02196514();
            break;
        case 3:
            func_ov001_021963a8();
            break;
        case 4:
            func_ov001_0219623c();
            break;
        case 5:
            func_ov001_021960a4();
            break;
        case 6:
            func_ov001_02196058();
            break;
        case 7:
            func_ov001_02195ff8();
            break;
        case 8:
            func_ov001_02195eb8();
            break;
        case 9:
            func_ov001_02195ea0();
            break;
        case 10:
            func_ov001_02195e38();
            break;
        case 11:
            func_ov001_02195d64();
            break;
        case 12:
            func_ov001_02195ba4();
            break;
        case 13:
            func_ov001_02195a6c();
            break;
        case 14:
            func_ov001_02195a54();
            break;
        case 15:
            func_ov001_021959d8();
            break;
        case 16:
            func_ov001_021959c0();
            break;
        case 17:
            func_ov001_02195894();
            break;
    }
    p = gRecordTAtt;
    func_02124c30(p->mUnk_08, p->mUnk_04, p->mUnk_10, func_02111318(), p->mUnk_38);
    p = gRecordTAtt;
    func_02124c30(p->mUnk_1c, p->mUnk_18, p->mUnk_24, func_0211130c(), p->mUnk_3c);
}

void func_ov001_0219574c(void) {
    RecordTAtt *p;

    *(vu32 *) 0x4000010 = (-gRecordTAtt->mUnk_5c << 16) & 0x1ff0000;
    p = gRecordTAtt;
    *(vu32 *) 0x4000014 = (-p->mUnk_60 & 0x1ff) | ((-p->mUnk_64 << 16) & 0x1ff0000);
    *(vu32 *) 0x400101c = -gRecordTAtt->mUnk_68 & 0x1ff;
    func_02111428();
}

void func_ov001_02195704(void) {
    u32 t;
    u32 u;

    t = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    t |= 0x13;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (t << 8);
    u = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    u |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (u << 8);
}

void RegisterRecordTAttCallbacks(void) {
    Unk021a8294 a = data_ov001_021a82d4;

    func_02111494(&a);
}
