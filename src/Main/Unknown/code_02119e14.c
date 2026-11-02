#include "Main/Unknown/code_02119e14.h"
#include "registers.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211ac70.h"
#include "Main/Unknown/code_0211b224.h"
#include "Main/Unknown/code_0211d650.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124bc8.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_0211ac24(void) {
    if (func_02127788() != 0) {
        func_0211b9ec();
        switch (func_02127794()) {
            case 0:
                func_0212ecc0(&data_0217d068, 0, 7);
                break;
            case -1:
            case 1:
                func_0212ecc0(&data_0217d068, 0, 0x10);
                break;
        }
    }
}

void func_0211abd0(void) {
    if (func_021277ac() != 0) {
        switch (func_02127794()) {
            case 0:
                func_0211b9d8();
                data_0217d368->mUnk_b8 = 1;
                func_0202b7c0(3);
                func_021282c8();
                break;
            case -1:
            case 1:
                func_0211ba98();
                break;
        }
    }
}

void func_0211a9d8(void) {
    Unk0217d368 *p;
    s32 i;
    s16 a;
    s16 b;
    s32 j;
    s32 c;
    data_0217d368->mUnk_38++;
    p = data_0217d368;
    c = func_020ae4c0(1, 0, -192, p->mUnk_38, 10);
    b = p->mUnk_58 + c;
    a = -func_02128244(p->mUnk_38);
    data_0217d368->mUnk_5c = b;
    c = data_0217d368->mUnk_04->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    data_0217d368->mUnk_14[c + 10].mUnk_06 = b;
    data_0217d368->mUnk_14[c + 12].mUnk_06 = b;
    data_0217d368->mUnk_14[34].mUnk_06 = b;
    data_0217d368->mUnk_14[37].mUnk_06 = b;
    data_0217d368->mUnk_14[35].mUnk_06 = b;
    data_0217d368->mUnk_14[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        data_0217d368->mUnk_14[40].mUnk_06 = a;
        data_0217d368->mUnk_14[41].mUnk_06 = a;
        data_0217d368->mUnk_14[c + 13].mUnk_06 = a;
        c += 8;
        data_0217d368->mUnk_14[c].mUnk_06 = b;
        data_0217d368->mUnk_14[30].mUnk_06 = b;
        data_0217d368->mUnk_14[31].mUnk_06 = b;
    } else {
        data_0217d368->mUnk_14[42].mUnk_06 = a;
        c += 14;
        data_0217d368->mUnk_14[c].mUnk_06 = a;
    }
}

void func_0211a964(s32 a) {
    s32 b;
    b = data_0217d368->mUnk_04->mUnk_06 + a;
    data_0217d368->mUnk_14[b].mUnk_06++;
    func_02124100(a, 1, data_0217d368->mUnk_0c, data_0217d368->mUnk_14, data_0217d368->mUnk_04);
    func_02124bc8(b, data_0217d368->mUnk_04, data_0217d368->mUnk_00, data_0217d368->mUnk_0c, data_0217d368->mUnk_b4,
                  data_0217d368->mUnk_14);
    data_0217d368->mUnk_14[b].mUnk_06--;
    func_02124100(a, 0, data_0217d368->mUnk_0c, data_0217d368->mUnk_14, data_0217d368->mUnk_04);
}

void func_0211a908(s32 a) {
    if (a == 3) {
        if (data_021759d0->mUnk_20 != 2) {
            func_0211a964(data_0215cd4e[a * 2]);
        }
        func_0211a964(10);
    } else if (a == 4) {
        func_0211a964(data_0215cd4e[a * 2]);
        func_0211a964(12);
    } else {
        func_0211a964(data_0215cd4e[a * 2]);
    }
}

s32 func_0211a7bc(void) {
    Unk0217d368 *p;
    s32 i;
    data_0217d368->mUnk_30 = data_0217d368->mUnk_34;
    data_0217d368->mUnk_64 = data_0217d368->mUnk_60;
    data_0217d368->mUnk_80 = data_0217d368->mUnk_7c;
    switch (data_0217d368->mUnk_30) {
        case 0:
            func_0211b224();
            break;
        case 1:
            func_0211b07c();
            break;
        case 2:
            func_0211afd0();
            break;
        case 3:
            func_0211acec();
            break;
        case 4:
            func_0211ac88();
            break;
        case 5:
            func_0211ac70();
            break;
        case 6:
            func_0211ac24();
            break;
        case 7:
            func_0211abd0();
            break;
        case 8:
            func_0211a9d8();
            break;
    }
    if (data_021759d0->mUnk_20 == 2) {
        func_02116d24();
    }
    switch (data_0217d368->mUnk_78) {
        case 0:
            func_0202b6f0(0);
            break;
        case 1:
        case 2:
            func_0202b6f0(1);
            break;
    }
    func_0202bb80();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b80c();
    }
    func_0211d9dc();
    func_0211d66c();
    func_0211c0cc();
    p = data_0217d368;
    func_02124c30(p->mUnk_04, p->mUnk_00, p->mUnk_0c, p->mUnk_b4, p->mUnk_14);
    for (i = 0; i < 5; i++) {
        func_0211a908(i);
    }
    p = data_0217d368;
    if (p->mUnk_30 == 8) {
        if (p->mUnk_b8 == 1 && (p->mUnk_2c == 3 || p->mUnk_68[2] == 1)) {
            if (p->mUnk_38 >= 10 && func_02128274() != 0) {
                return data_0217d368->mUnk_b8;
            }
        } else if (p->mUnk_38 >= 10) {
            return p->mUnk_b8;
        }
    }
    return 0;
}

void func_0211a794(void) {
    reg_G2S_DB_BG3OFS = (-data_0217d368->mUnk_5c << 16) & 0x1ff0000;
    func_0202ba14();
}

void func_0211a6bc(void) {
    Unk020b4934 *a = 0;
    Unk02021dc8 *b = 0;
    Unk020b4a44 *c = 0;
    Unk020b4934 *d = 0;
    Unk020b47d8 *e = 0;
    Unk020b4a44 *f = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LoadNcgrData(&d, FindSceneFile(data_0216d894));
        LoadNclrData(&f, FindSceneFile(data_0216d88c));
        LoadNscrData(&e, FindSceneFile(data_0216d8a4));
        LoadNcgrData(&d, FindSceneFile(data_0216d87c));
        LoadNclrData(&f, FindSceneFile(data_0216d86c));
        LoadNscrData(&e, FindSceneFile(data_0216d884));
        LoadNcgrData2(&a, FindSceneFile(data_0216d8a0));
        LoadNcerData(&b, FindSceneFile(data_0216d890));
        LoadNclrData(&c, FindSceneFile(data_0216d878));
    }
}

void func_0211a3bc(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk020b4934 *c = 0;
    Unk020b4a44 *d = 0;
    Unk020b4934 *e = 0;
    Unk020b47d8 *f = 0;
    Unk020b4a44 *g = 0;
    Unk020b4934 *h = 0;
    Unk020b47d8 *i = 0;
    Unk020b4a44 *j = 0;
    u16 *p;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_0217d364->mUnk_14 = FindSceneFile(data_0216d864);
        return;
    }
    if (data_0217d364->mUnk_40 == 0) {
        LocateNcgr(&e, FindSceneFile(data_0216d894));
        LocateNclr(&g, FindSceneFile(data_0216d88c));
        LocateNscr(&f, FindSceneFile(data_0216d8a4));
    } else {
        LocateNcgr(&e, FindSceneFile(data_0216d87c));
        LocateNclr(&g, FindSceneFile(data_0216d86c));
        LocateNscr(&f, FindSceneFile(data_0216d884));
    }
    LocateNcgr(&h, FindSceneFile(data_0216d874));
    LocateNclr(&j, FindSceneFile(data_0216d854));
    LocateNscr(&i, FindSceneFile(data_0216d858));
    data_0217d364->mUnk_24 = func_02036bec(data_0217d364->mUnk_30, 0x800);
    if (data_0217d364->mUnk_40 == 0) {
        data_0217d364->mUnk_04 = FindSceneFile(data_0216d880);
        data_0217d364->mUnk_08 = FindSceneFile(data_0216d89c);
    } else {
        data_0217d364->mUnk_04 = FindSceneFile(data_0216d868);
        data_0217d364->mUnk_08 = FindSceneFile(data_0216d870);
    }
    LocateNcgr2(&a, FindSceneFile(data_0216d8a0));
    LocateNcer(&data_0217d364->mUnk_00, FindSceneFile(data_0216d890));
    LocateNclr(&b, FindSceneFile(data_0216d878));
    data_0217d364->mUnk_10 = FindSceneFile(data_0216d888);
    data_0217d364->mUnk_14 = FindSceneFile(data_0216d864);
    data_0217d364->mUnk_18 = FindSceneFile(data_0216d860);
    LocateNcgr2(&c, FindSceneFile(data_0216d898));
    LocateNcer(&data_0217d364->mUnk_0c, FindSceneFile(data_0216d8a8));
    LocateNclr(&d, FindSceneFile(data_0216d85c));
    p = b->mUnk_0c;
    func_02016468(4, 0, e->mUnk_14, e->mUnk_10);
    func_02016468(0xf, 0, g->mUnk_0c, 0x140);
    func_02016468(8, 0, f->mUnk_0c, f->mUnk_08);
    func_02016468(8, 0x800, data_0217d364->mUnk_24, 0x800);
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        func_02016468(0x17, 0, h->mUnk_14, h->mUnk_10);
        func_02016468(0x1f, 0, j->mUnk_0c, 0x140);
        func_02016468(0x1b, 0, i->mUnk_0c, i->mUnk_08);
        func_02016468(0x1b, 0x800, data_0217d364->mUnk_24, 0x800);
    }
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0xe, 0, b->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, p + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, d->mUnk_0c, d->mUnk_08);
}

void func_0211a100(void) {
    s32 i;
    u32 a;
    u32 b;
    Unk0217d364 *p;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        a = data_0217d364->mUnk_04->mUnk_06;
        b = data_0217d364->mUnk_10->mUnk_06;
        for (i = 0; i < 8; i++) {
            data_0217d364->mUnk_20[data_0215cacc[i]].mUnk_00 = 0;
        }
        for (i = 0; i < 4; i++) {
            data_0217d364->mUnk_20[data_0215ca9c[i]].mUnk_00 = 0;
        }
        for (i = 0; i < 4; i++) {
            data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_00 = 0;
            data_0217d364->mUnk_20[b + data_0215cab4[i]].mUnk_00 = 1;
        }
        data_0217d364->mUnk_1c[0].mUnk_00 = 1;
        data_0217d364->mUnk_1c[2].mUnk_00 = 1;
        data_0217d364->mUnk_1c[1].mUnk_00 = 1;
        data_0217d364->mUnk_1c[4].mUnk_00 = 1;
        data_0217d364->mUnk_1c[3].mUnk_00 = 1;
        data_0217d364->mUnk_1c[5].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a + 1].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a + 2].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a + 3].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a + 4].mUnk_00 = 1;
        data_0217d364->mUnk_1c[a + 5].mUnk_00 = 1;
        data_0217d364->mUnk_20[0x14].mUnk_00 = 0;
        data_0217d364->mUnk_20[0x13].mUnk_00 = 1;
        p = data_0217d364;
        func_0211de00(data_0215cadc[func_0202968c()], p->mUnk_00, p->mUnk_04, 0, 0);
        p = data_0217d364;
        func_0211de00(data_0215cadc[func_0202968c()], p->mUnk_0c, p->mUnk_10, 0x13, 1);
        p = data_0217d364;
        i = func_0202968c();
        func_0211ded0(data_0215cadc[i], p->mUnk_00, p->mUnk_04, 5, func_02124a68(5, p->mUnk_00, p->mUnk_04), 0);
        for (i = 0; i < 4; i++) {
            p = data_0217d364;
            func_0212426c(1, data_0215cab4[i], data_0217d364->mUnk_18,
                          func_020b3f7c(data_0217d364->mUnk_28, data_0215cafc[data_0215cadc[func_0202968c()]][i]),
                          p->mUnk_10, p->mUnk_20);
        }
        p = data_0217d364;
        func_0212426c(0, 2, data_0217d364->mUnk_08, func_020b3f7c(p->mUnk_28, 0x73), p->mUnk_04, p->mUnk_1c);
        p = data_0217d364;
        func_0212426c(0, 4, data_0217d364->mUnk_08, func_020b3f7c(p->mUnk_28, 0x74), p->mUnk_04, p->mUnk_1c);
        func_02124140(0, 0, data_0217d364->mUnk_08, data_0217d364->mUnk_1c, data_0217d364->mUnk_04);
        func_02124140(1, 0, data_0217d364->mUnk_08, data_0217d364->mUnk_1c, data_0217d364->mUnk_04);
        func_02124140(2, 0, data_0217d364->mUnk_08, data_0217d364->mUnk_1c, data_0217d364->mUnk_04);
        func_02124140(4, 0, data_0217d364->mUnk_08, data_0217d364->mUnk_1c, data_0217d364->mUnk_04);
        p = data_0217d364;
        switch (p->mUnk_40) {
            case 1:
            case 2:
            case 3:
                p->mUnk_1c[a + 2].mUnk_00 = 0;
                data_0217d364->mUnk_1c[a + 3].mUnk_00 = 0;
                data_0217d364->mUnk_1c[a + 4].mUnk_00 = 0;
                data_0217d364->mUnk_1c[a + 5].mUnk_00 = 0;
                break;
        }
    }
}

void func_0211a07c(void) {
    s32 i;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        for (i = 0; i < 4; i++) {
            if (data_0217d364->mUnk_50 == i && data_0217d364->mUnk_54 != 0) {
                data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_00 = 1;
                func_02124100(data_0215cab4[i], 0xe, data_0217d364->mUnk_18, data_0217d364->mUnk_20,
                              data_0217d364->mUnk_10);
            } else {
                data_0217d364->mUnk_20[data_0215caa4[i]].mUnk_00 = 0;
                func_02124100(data_0215cab4[i], 0xf, data_0217d364->mUnk_18, data_0217d364->mUnk_20,
                              data_0217d364->mUnk_10);
            }
        }
    }
}

void func_02119e88(void) {
    Unk0217d364 *p;
    u32 a;
    u8 b[0x24];
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = data_0217d364;
        func_0212426c(0, 0, data_0217d364->mUnk_08,
                      func_020b3f7c(data_0217d364->mUnk_28, data_0215cafc[data_0215cadc[func_0202968c()]][p->mUnk_50]),
                      p->mUnk_04, p->mUnk_1c);
        p = data_0217d364;
        func_0212426c(0, 1, data_0217d364->mUnk_08,
                      func_020b3f7c(data_0217d364->mUnk_28, data_0215cafc[data_0215cadc[func_0202968c()]][p->mUnk_50]),
                      p->mUnk_04, p->mUnk_1c);
        if (func_02060228(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50], 0)) {
            func_02060134(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50], 0, &a);
            func_02116b80(&a, b);
            p = data_0217d364;
            func_02124224(0, 3, p->mUnk_08, b, p->mUnk_04, p->mUnk_1c, 9);
        } else {
            p = data_0217d364;
            func_02124224(0, 3, p->mUnk_08, data_0216dbac, p->mUnk_04, p->mUnk_1c, 9);
        }
        if (func_02060228(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50], 5)) {
            func_02060134(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50], 5, &a);
            func_02116b80(&a, b);
            p = data_0217d364;
            func_02124224(0, 5, p->mUnk_08, b, p->mUnk_04, p->mUnk_1c, 9);
        } else {
            p = data_0217d364;
            func_02124224(0, 5, p->mUnk_08, data_0216dbc0, p->mUnk_04, p->mUnk_1c, 9);
        }
        func_020d0efc(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50]);
        data_0217d364->mUnk_60 = 1;
    }
}

void func_02119e50(void) {
    func_02029580(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50]);
}

void func_02119e14(void) {
    func_0211e418(data_0215cbec[data_0215cadc[func_0202968c()]][data_0217d364->mUnk_50]);
    func_0202949c(0);
}

#pragma thumb off
