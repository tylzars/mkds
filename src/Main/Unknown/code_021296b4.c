#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020abae0.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_021296b4.h"

#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_0212898c.h"
#include "Main/Unknown/code_0212899c.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "code_0214a054.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02129ea4.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212a700.h"
#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

void func_0212a700(void) {
    func_020ab910((u32) 0x24, (u32) 0x7a, (u32) 0x7e, (u32) 0x8e);
    func_020ab8d4((u32) 0x82, (u32) 0x7a, (u32) 0xdc, (u32) 0x8e);
}

#pragma thumb off

#pragma thumb on

void func_0212a670(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Unk0217d400 *p = data_0217d400;
        func_0212426c(1, data_0215d0e4[i][0], data_0217d400->mUnk_ac[i], GetBmgEntry(p->mUnk_c0, 4), p->mUnk_9c[i],
                      p->mUnk_74[i][1]);
        p = data_0217d400;
        func_0212426c(1, data_0215d0e4[i][1], data_0217d400->mUnk_ac[i], GetBmgEntry(p->mUnk_c0, 5), p->mUnk_9c[i],
                      p->mUnk_74[i][1]);
    }
}

void func_0212a604(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                Unk02124b1c *p = &data_0217d400->mUnk_74[i][j][data_0215d0f8[i][k]];
                p->mUnk_08 = 1;
                p->mUnk_0c = 0;
                p->mUnk_0e = 0;
            }
        }
    }
}

void func_0212a4f4(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                data_0217d400->mUnk_74[i][0][data_0215d128[i][j][k]].mUnk_00 = 0;
            }
            data_0217d400->mUnk_74[i][0][data_0215d0e4[i][j] + data_0217d400->mUnk_9c[i]->mUnk_06].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_0215d0e0[i]; j++) {
            data_0217d400->mUnk_74[i][0][data_0215d14c[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 4; k++) {
            data_0217d400->mUnk_74[i][0][data_0215d0f8[i][k]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        data_0217d400->mUnk_74[1][0][data_0215d110[j]].mUnk_00 = 0;
    }
}

void func_0212a4bc(void) {
    u16 a[12];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x1a);
    MemCopyHalfwords(&data_0217d400->mUnk_2c[0], &a[1], 0x18);
    func_020ab7a4(&a[1]);
}

void func_0212a484(void) {
    u16 a[12];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x16);
    MemCopyHalfwords(&data_0217d400->mUnk_2c[1], &a[1], 0x14);
    func_020ab7a4(&a[1]);
}

void func_0212a448(void) {
    u16 a[12];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x16);
    MemCopyHalfwords(data_0217aa08->mUnk_00->mUnk_0c, &a[1], 0x14);
    func_020ab7a4(&a[1]);
}

void func_0212a410(void) {
    s32 i;
    MemFill(&data_0217d400->mUnk_2c[2], 0, 0xd);
    for (i = 0; i < 12; i++) {
        ((u8 *) &data_0217d400->mUnk_2c[2])[i] = data_0217d400->mUnk_2c[0].mUnk_00[i];
    }
}

void func_0212a1e0(void *a, s32 b) {
    volatile u16 d;
    Unk0212a1e0 c;
    s32 i;
    s32 j;
    data_0217d400 = HeapAlloc(a, 0xc4);
    data_0217d400->mUnk_00 = a;
    data_0217d400->mUnk_bc = func_021250b0(a);
    func_0212abdc(a, func_02128898());
    c.mUnk_00 = 1;
    c.mUnk_04 = func_020b403c(1);
    c.mUnk_08 = 0;
    c.mUnk_0c = 1;
    c.mUnk_10 = 0;
    c.mUnk_14 = 0;
    c.mUnk_18 = 0;
    c.mUnk_1c = 0;
    c.mUnk_20 = 1;
    if (b == 0xc) {
        c.mUnk_24 = 1;
    } else {
        c.mUnk_24 = 0;
    }
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &c);
    func_02129c18();
    func_02129cbc();
    func_020ae6d4(func_02128898(), func_02128884());
    func_020abcf4(0x20, 0x40, 0xc);
    func_020ab94c(0, 0x28);
    func_0212a700();
    func_020aba94(0);
    data_0217d400->mUnk_2c[2].mUnk_14 = b;
    data_0217d400->mUnk_2c[2].mUnk_16 = -1;
    if (b == 0xc) {
        data_0217d400->mUnk_04 = 0;
        data_0217d400->mUnk_0c = 0;
        data_0217d400->mUnk_1c[0] = 0;
        data_0217d400->mUnk_1c[1] = 1;
    } else {
        data_0217d400->mUnk_04 = 1;
        data_0217d400->mUnk_0c = 5;
        data_0217d400->mUnk_1c[0] = 1;
        if (b == 0xb) {
            data_0217d400->mUnk_1c[1] = 0;
        } else {
            data_0217d400->mUnk_1c[1] = 1;
        }
        func_0212a448();
    }
    if (data_0217d400->mUnk_04 == 0) {
        data_0217d400->mUnk_08 = 0;
        func_020ab758(data_0215d0e0[0]);
    } else {
        if (data_021759d0->mUnk_00 == 0) {
            data_0217d400->mUnk_08 = 1;
        } else {
            data_0217d400->mUnk_08 = 2;
        }
        func_020ab758(data_0215d0e0[1]);
    }
    func_020ab9d0(data_0217d400->mUnk_08);
    func_02129e78();
    for (i = 0; i < 2; i++) {
        data_0217d400->mUnk_14[i] = 0;
    }
    data_0217d400->mUnk_24 = 0;
    data_0217d400->mUnk_10 = data_0217d400->mUnk_0c;
    data_0217d400->mUnk_28 = 0;
    data_0217d400->mUnk_84 = 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d400->mUnk_86[i][j] = data_0215d108[i][j];
        }
    }
    data_0217d400->mUnk_c0 = func_02047a28(data_0216ea60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02124ed0(a, data_0217d400->mUnk_9c[i], data_0217d400->mUnk_ac[i], &data_0217d400->mUnk_74[i][j]);
        }
    }
    func_0212a604();
    for (i = 0; i < 2; i++) {
        d = 0;
        MemFillHalfwords(d, &data_0217d400->mUnk_2c[i], 0x18);
    }
    func_0212a724();
    func_0212a670();
    func_0212a4f4();
    func_02129ea4();
}
#pragma thumb off

#pragma thumb on

void func_0212a1c4(void) {
    func_0212abd0();
    func_02125da0();
    *(u32 *) &data_0217d400 = 0;
}

#pragma thumb off

#pragma thumb on
void func_02129ea4(void) {
    u16 e[2];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 v;
    s16 w;
    for (i = 0; i < 2; i++) {
        e[i] = data_0217d400->mUnk_9c[i]->mUnk_06;
        for (j = 0; j < 2; j++) {
            v = -500;
            if (i == 1 || data_0217d400->mUnk_2c[2].mUnk_14 == 0xc) {
                v = data_0217d400->mUnk_86[i][j];
            }
            for (k = 0; k < data_0215d0d8[i]; k++) {
                data_0217d400->mUnk_74[i][j][data_0215d0dc[i][k]].mUnk_06 = v;
            }
            for (k = 0; k < data_0215d0e0[i]; k++) {
                data_0217d400->mUnk_74[i][j][data_0215d14c[i][k]].mUnk_06 = v;
                (data_0217d400->mUnk_74[i][j] + e[i])[data_0215d134[i][k]].mUnk_06 = v;
            }
            v = data_0217d400->mUnk_84;
            for (m = 0; m < 2; m++) {
                for (k = 0; k < 3; k++) {
                    data_0217d400->mUnk_74[i][j][data_0215d128[i][m][k]].mUnk_06 = v;
                }
                (data_0217d400->mUnk_74[i][j] + e[i])[data_0215d0e4[i][m]].mUnk_06 = v;
            }
            w = data_0217d400->mUnk_84;
            func_020ab848(&a, &b, &c, &d);
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0c = a;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0e = w + b + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0c = a;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0e = w + d + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0c = c;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0e = w + b + 0x28;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0c = c;
            data_0217d400->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0e = w + d + 0x28;
        }
    }
    for (i = 0; i < 2; i++) {
        v = -500;
        if (data_0217d400->mUnk_04 == 1 && i == 1) {
            v = data_0217d400->mUnk_84;
        }
        for (k = 0; k < 10; k++) {
            data_0217d400->mUnk_74[1][i][data_0215d110[k]].mUnk_06 = v;
        }
        v = -500;
        if (data_0217d400->mUnk_04 == 1) {
            v = data_0217d400->mUnk_86[1][i];
        }
        for (k = 0; k < 6; k++) {
            data_0217d400->mUnk_74[1][i][data_0215d0f0[k]].mUnk_06 = v;
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_02129e78(void) {
    u8 *v1;
    v1 = data_0217d400->mUnk_b4[data_0217d400->mUnk_04];
    CallQueueAppend((u32) 0x1b, (u32) 0, v1 + 0xc, (u32) (*(u32 *) (v1 + 8)));
}

void func_02129cbc(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3;
    v1 = FindSceneFile(data_0216e940);
    data_0217d400->mUnk_a4[0] = v1;
    v1 = FindSceneFile(data_0216e958);
    data_0217d400->mUnk_9c[0] = v1;
    v1 = FindSceneFile(data_0216e970);
    data_0217d400->mUnk_ac[0] = v1;
    v1 = FindSceneFile(data_0216e988);
    data_0217d400->mUnk_a4[1] = v1;
    v1 = FindSceneFile(data_0216e998);
    data_0217d400->mUnk_9c[1] = v1;
    v1 = FindSceneFile(data_0216e9a8);
    data_0217d400->mUnk_ac[1] = v1;
    v1 = FindSceneFile(data_0216e9b8);
    LoadNcgrData2(&data_0217d400->mUnk_94, v1);
    v1 = FindSceneFile(data_0216e9d0);
    LoadNcerData(&data_0217d400->mUnk_90, v1);
    v1 = FindSceneFile(data_0216e9e8);
    LoadNclrData(&data_0217d400->mUnk_98, v1);
    func_0200ee74(data_0217d400->mUnk_94->mData, data_0217d400->mUnk_94->mDataSize);
    func_0214bf04((const void *) (data_0217d400->mUnk_94->mData), 0, (u32) (data_0217d400->mUnk_94->mDataSize));
    func_0214bea4((const void *) (data_0217d400->mUnk_94->mData), 0, (u32) (data_0217d400->mUnk_94->mDataSize));
    func_0200ee74(data_0217d400->mUnk_98->mData, data_0217d400->mUnk_98->mDataSize);
    func_0214c090((const void *) (data_0217d400->mUnk_98->mData), 0, (u32) (((u32) 0x000001a0u)));
    func_0214c090((const void *) (&data_0217d400->mUnk_98->mData[0xe0]), 0x1c0, (u32) 0x40);
    func_0214c028((const void *) (data_0217d400->mUnk_98->mData), 0, (u32) (data_0217d400->mUnk_98->mDataSize));
    v1 = FindSceneFile(data_0216e9fc);
    LoadNcgrData(&v2, v1);
    func_0200ee74(v2->mData, v2->mDataSize);
    MemCopyWordsToG2sBg3CntBits2To5Address(v2->mData, 0, v2->mDataSize);
    v1 = FindSceneFile(data_0216ea14);
    LoadNscrData((Nscr **) &data_0217d400->mUnk_b4[0], v1);
    v1 = FindSceneFile(data_0216ea30);
    LoadNscrData((Nscr **) &data_0217d400->mUnk_b4[1], v1);
    v1 = FindSceneFile(data_0216ea4c);
    LoadNclrData(&v3, v1);
    func_0200ee74(v3->mData, 0x80);
    func_0214c0f8(v3->mData, 0, (u32) 0x80);
}

#pragma thumb off

#pragma thumb on
void func_02129c18(void) {
    u32 t;
    *(vu16 *) 0x4001050 = 0;
    t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    t |= 0xc;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | (t << 8);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & 0x43) | 0x8018;
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & ~3) | 2;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x9010;
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & ~3) | 2;
    MemFillWordsByBlock_inline((void *) G2Bg2CntBits8To12Address(), 0x1000);
    MemFillWordsByBlock_inline((void *) G2Bg3CntBits8To12Address(), 0x1000);
}

void func_02129bdc(void) {
    if (func_02036c5c() != 0) {
        data_0217d400->mUnk_10 = 1;
        func_02126638(GetBmgEntry(data_0217d400->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
    }
}

void func_02129b60(void) {
    s32 n;
    n = data_0215d0e0[0] - 1;
    if (n == func_020ab748() && data_0217d400->mUnk_2c[data_0217d400->mUnk_04].mUnk_00[n] != 0) {
        data_0217d400->mUnk_1c[0] = 1;
    } else {
        data_0217d400->mUnk_1c[0] = 0;
    }
    if (func_020ab8c4() == 1) {
        data_0217d400->mUnk_14[0] = 1;
    } else {
        data_0217d400->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        data_0217d400->mUnk_14[1] = 1;
    } else {
        data_0217d400->mUnk_14[1] = 0;
    }
}

void func_02129acc(void) {
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0xc0, 0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[0][1] =
        func_020ae4c0(1, data_0215d108[0][1], data_0215d100[0][1], data_0217d400->mUnk_28, 0xf);
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125fa4() != 0) {
        data_0217d400->mUnk_10 = 2;
        data_0217d400->mUnk_24 = 1;
        data_0217d400->mUnk_28 = 0;
    }
    func_02129b60();
}

void func_02129994(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    Unk0217d400 *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    BOOL f;
    BOOL g;
    u16 c;
    f = FALSE;
    v = -1;
    g = FALSE;
    c = data_02175674[i].mUnk_00;
    if (c == 0 && data_02175680[i].mUnk_00 < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[i].mUnk_00 == 0 && c != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        v = RectTableFindContaining(data_0217d400->mUnk_a4[0], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = data_0217d400;
    q = &p->mUnk_2c[p->mUnk_04];
    w = func_020ab798();
    MemCopyHalfwords(w, q, 0x18);
    func_02129b60();
    if (v == 1 || (func_020ab8c4() == 1 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = data_0217d400;
        if (p->mUnk_1c[0] != 0) {
            p->mUnk_10 = 3;
            data_0217d400->mUnk_2c[2].mUnk_10 = 1;
            func_02125fc0();
            func_020ab8cc(1);
            data_0217d400->mUnk_24 = 0;
            func_0212ecc0(&data_0217d068, 0, 4);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if (v == 0 || (func_020ab8c4() == 2 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        data_0217d400->mUnk_10 = 3;
        data_0217d400->mUnk_2c[2].mUnk_10 = 0;
        func_02125fc0();
        func_020ab8cc(2);
        data_0217d400->mUnk_24 = 0;
        func_0212ecc0(&data_0217d068, 0, 0xe);
    }
}

void func_0212982c(void) {
    Unk0217d400 *p;
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0, 0xc0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[0][1] =
        func_020ae4c0(1, data_0215d100[0][1], data_0215d108[0][1], data_0217d400->mUnk_28, 0xf);
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125f88() != 0) {
        p = data_0217d400;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            func_0212a410();
            switch (func_02061104(&data_0217d400->mUnk_2c[2])) {
                case 1:
                    data_0217d400->mUnk_10 = 4;
                    func_021262f0(GetBmgEntry(data_0217d400->mUnk_c0, 0xa));
                    data_0217d400->mUnk_28 = 0;
                    return;
                case 2:
                    data_0217d400->mUnk_10 = 4;
                    func_021262f0(GetBmgEntry(data_0217d400->mUnk_c0, 0xb));
                    data_0217d400->mUnk_28 = 0;
                    return;
                default:
                    data_0217d400->mUnk_10 = 6;
                    func_02126638(GetBmgEntry(data_0217d400->mUnk_c0, 8), 0, 0, 0, 0, 0, 0);
                    data_0217d400->mUnk_28 = 0;
                    data_0217d400->mUnk_04 = 1;
                    if (data_021759d0->mUnk_00 == 0) {
                        data_0217d400->mUnk_08 = 1;
                    } else {
                        data_0217d400->mUnk_08 = 2;
                    }
                    func_020ab9d0(data_0217d400->mUnk_08);
                    func_020ab758(data_0215d0e0[1]);
                    func_0212a484();
                    func_02129e78();
                    func_02128b0c();
                    return;
            }
        } else {
            p->mUnk_2c[2].mUnk_16 = 0xc;
        }
    }
}

void func_021297cc(void) {
    Unk0217d400 *p;
    data_0217d400->mUnk_28++;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    p = data_0217d400;
    if (p->mUnk_28 >= 0x78) {
        p->mUnk_10 = 1;
        func_02126638(GetBmgEntry(data_0217d400->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
        data_0217d400->mUnk_28 = 0;
    }
}

void func_02129788(void) {
    if (func_02036c5c() != 0) {
        data_0217d400->mUnk_10 = 6;
        func_02126638(GetBmgEntry(data_0217d400->mUnk_c0, 0xf), 0, 0, 0, 0, 0, 0);
        data_0217d400->mUnk_2c[2].mUnk_10 = 1;
    }
}
#pragma thumb off

#pragma thumb on

void func_021296b4(void) {
    s32 i;
    u8 n;
    i = 0;
    data_0217d400->mUnk_1c[0] = 0;
    for (; i < func_020ab748(); i++) {
        if (func_020ab798()[i] != 0x20 && func_020ab798()[i] != 0x3000) {
            data_0217d400->mUnk_1c[0] = 1;
        }
    }
    n = data_0215d0e0[1];
    if (n - 1 == func_020ab748()) {
        if ((func_020ab798() + n)[-1] != 0x20 && (func_020ab798() + n)[-1] != 0x3000 &&
            (func_020ab798() + n)[-1] != 0) {
            data_0217d400->mUnk_1c[0] = 1;
        }
    }
    if (func_020ab8c4() == 1) {
        data_0217d400->mUnk_14[0] = 1;
    } else {
        data_0217d400->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        data_0217d400->mUnk_14[1] = 1;
        return;
    }
    data_0217d400->mUnk_14[1] = 0;
}

#pragma thumb off
