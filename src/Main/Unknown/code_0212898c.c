#include "Main/Unknown/code_0212898c.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02129ea4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020ab798.h"
#include "code_0201ea58.h"
#include "code_0214cfe4.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020aba9c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0212abd0.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "Main/Unknown/code_021262f0.h"
#include "code_0214a054.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212a700.h"
#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_02047104.h"

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
        Keyboard *p = gKeyboard;
        func_0212426c(1, data_0215d0e4[i][0], gKeyboard->mBnlls[i], GetBmgEntry(p->mUnk_c0, 4), p->mBncls[i],
                      p->mUnk_74[i][1]);
        p = gKeyboard;
        func_0212426c(1, data_0215d0e4[i][1], gKeyboard->mBnlls[i], GetBmgEntry(p->mUnk_c0, 5), p->mBncls[i],
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
                Unk02124b1c *p = &gKeyboard->mUnk_74[i][j][data_0215d0f8[i][k]];
                p->mUnk_08 = TRUE;
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
                gKeyboard->mUnk_74[i][0][data_0215d128[i][j][k]].mUnk_00 = 0;
            }
            gKeyboard->mUnk_74[i][0][data_0215d0e4[i][j] + gKeyboard->mBncls[i]->mUnk_06].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_0215d0e0[i]; j++) {
            gKeyboard->mUnk_74[i][0][data_0215d14c[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 4; k++) {
            gKeyboard->mUnk_74[i][0][data_0215d0f8[i][k]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        gKeyboard->mUnk_74[1][0][data_0215d110[j]].mUnk_00 = 0;
    }
}

void func_0212a4bc(void) {
    u16 a[12];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x1a);
    MemCopyHalfwords(&gKeyboard->mUnk_2c[0], &a[1], 0x18);
    func_020ab7a4(&a[1]);
}

void func_0212a484(void) {
    u16 a[12];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x16);
    MemCopyHalfwords(&gKeyboard->mUnk_2c[1], &a[1], 0x14);
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
    MemFill(&gKeyboard->mUnk_2c[2], 0, 0xd);
    for (i = 0; i < 12; i++) {
        ((u8 *) &gKeyboard->mUnk_2c[2])[i] = gKeyboard->mUnk_2c[0].mUnk_00[i];
    }
}

void InitKeyboard(void *a, s32 b) {
    volatile u16 d;
    Unk0212a1e0 c;
    s32 i;
    s32 j;
    gKeyboard = HeapAlloc(a, 0xc4);
    gKeyboard->mUnk_00 = a;
    gKeyboard->mUnk_bc = func_021250b0(a);
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
    gKeyboard->mUnk_2c[2].mUnk_14 = b;
    gKeyboard->mUnk_2c[2].mUnk_16 = -1;
    if (b == 0xc) {
        gKeyboard->mUnk_04 = 0;
        gKeyboard->mState = 0;
        gKeyboard->mUnk_1c[0] = 0;
        gKeyboard->mUnk_1c[1] = 1;
    } else {
        gKeyboard->mUnk_04 = 1;
        gKeyboard->mState = 5;
        gKeyboard->mUnk_1c[0] = 1;
        if (b == 0xb) {
            gKeyboard->mUnk_1c[1] = 0;
        } else {
            gKeyboard->mUnk_1c[1] = 1;
        }
        func_0212a448();
    }
    if (gKeyboard->mUnk_04 == 0) {
        gKeyboard->mUnk_08 = 0;
        func_020ab758(data_0215d0e0[0]);
    } else {
        if (data_021759d0->mUnk_00 == 0) {
            gKeyboard->mUnk_08 = 1;
        } else {
            gKeyboard->mUnk_08 = 2;
        }
        func_020ab758(data_0215d0e0[1]);
    }
    func_020ab9d0(gKeyboard->mUnk_08);
    func_02129e78();
    for (i = 0; i < 2; i++) {
        gKeyboard->mUnk_14[i] = 0;
    }
    gKeyboard->mUnk_24 = FALSE;
    gKeyboard->mNextState = gKeyboard->mState;
    gKeyboard->mUnk_28 = 0;
    gKeyboard->mUnk_84 = 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gKeyboard->mUnk_86[i][j] = data_0215d108[i][j];
        }
    }
    gKeyboard->mUnk_c0 = func_02047a28(data_0216ea60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02124ed0(a, gKeyboard->mBncls[i], gKeyboard->mBnlls[i], &gKeyboard->mUnk_74[i][j]);
        }
    }
    func_0212a604();
    for (i = 0; i < 2; i++) {
        d = 0;
        MemFillHalfwords(d, &gKeyboard->mUnk_2c[i], 0x18);
    }
    func_0212a724();
    func_0212a670();
    func_0212a4f4();
    func_02129ea4();
}
#pragma thumb off

#pragma thumb on

void ReleaseKeyboard(void) {
    func_0212abd0();
    func_02125da0();
    *(u32 *) &gKeyboard = 0;
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
        e[i] = gKeyboard->mBncls[i]->mUnk_06;
        for (j = 0; j < 2; j++) {
            v = -500;
            if (i == 1 || gKeyboard->mUnk_2c[2].mUnk_14 == 0xc) {
                v = gKeyboard->mUnk_86[i][j];
            }
            for (k = 0; k < data_0215d0d8[i]; k++) {
                gKeyboard->mUnk_74[i][j][data_0215d0dc[i][k]].mUnk_06 = v;
            }
            for (k = 0; k < data_0215d0e0[i]; k++) {
                gKeyboard->mUnk_74[i][j][data_0215d14c[i][k]].mUnk_06 = v;
                (gKeyboard->mUnk_74[i][j] + e[i])[data_0215d134[i][k]].mUnk_06 = v;
            }
            v = gKeyboard->mUnk_84;
            for (m = 0; m < 2; m++) {
                for (k = 0; k < 3; k++) {
                    gKeyboard->mUnk_74[i][j][data_0215d128[i][m][k]].mUnk_06 = v;
                }
                (gKeyboard->mUnk_74[i][j] + e[i])[data_0215d0e4[i][m]].mUnk_06 = v;
            }
            w = gKeyboard->mUnk_84;
            func_020ab848(&a, &b, &c, &d);
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0c = a;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][0]].mUnk_0e = w + b + 0x28;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0c = a;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][1]].mUnk_0e = w + d + 0x28;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0c = c;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][2]].mUnk_0e = w + b + 0x28;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0c = c;
            gKeyboard->mUnk_74[i][j][data_0215d0f8[i][3]].mUnk_0e = w + d + 0x28;
        }
    }
    for (i = 0; i < 2; i++) {
        v = -500;
        if (gKeyboard->mUnk_04 == 1 && i == 1) {
            v = gKeyboard->mUnk_84;
        }
        for (k = 0; k < 10; k++) {
            gKeyboard->mUnk_74[1][i][data_0215d110[k]].mUnk_06 = v;
        }
        v = -500;
        if (gKeyboard->mUnk_04 == 1) {
            v = gKeyboard->mUnk_86[1][i];
        }
        for (k = 0; k < 6; k++) {
            gKeyboard->mUnk_74[1][i][data_0215d0f0[k]].mUnk_06 = v;
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_02129e78(void) {
    Nscr *v1;
    v1 = gKeyboard->mNscrs[gKeyboard->mUnk_04];
    CallQueueAppend((u32) 0x1b, (u32) 0, v1->mData, (u32) v1->mDataSize);
}

void func_02129cbc(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3;
    v1 = FindSceneFile(data_0216e940);
    gKeyboard->mBnbls[0] = v1;
    v1 = FindSceneFile(data_0216e958);
    gKeyboard->mBncls[0] = v1;
    v1 = FindSceneFile(data_0216e970);
    gKeyboard->mBnlls[0] = v1;
    v1 = FindSceneFile(data_0216e988);
    gKeyboard->mBnbls[1] = v1;
    v1 = FindSceneFile(data_0216e998);
    gKeyboard->mBncls[1] = v1;
    v1 = FindSceneFile(data_0216e9a8);
    gKeyboard->mBnlls[1] = v1;
    v1 = FindSceneFile(data_0216e9b8);
    LoadNcgrData2(&gKeyboard->mNcgr, v1);
    v1 = FindSceneFile(data_0216e9d0);
    LoadNcerData(&gKeyboard->mNcer, v1);
    v1 = FindSceneFile(data_0216e9e8);
    LoadNclrData(&gKeyboard->mNclr, v1);
    DC_FlushRange(gKeyboard->mNcgr->mData, gKeyboard->mNcgr->mDataSize);
    GX_LoadOBJ(gKeyboard->mNcgr->mData, 0, (u32) (gKeyboard->mNcgr->mDataSize));
    GXS_LoadOBJ(gKeyboard->mNcgr->mData, 0, (u32) (gKeyboard->mNcgr->mDataSize));
    DC_FlushRange(gKeyboard->mNclr->mData, gKeyboard->mNclr->mDataSize);
    GX_LoadOBJPltt(gKeyboard->mNclr->mData, 0, (u32) (((u32) 0x000001a0u)));
    GX_LoadOBJPltt(&gKeyboard->mNclr->mData[0xe0], 0x1c0, (u32) 0x40);
    GXS_LoadOBJPltt(gKeyboard->mNclr->mData, 0, (u32) (gKeyboard->mNclr->mDataSize));
    v1 = FindSceneFile(data_0216e9fc);
    LoadNcgrData(&v2, v1);
    DC_FlushRange(v2->mData, v2->mDataSize);
    MemCopyWordsToG2sBg3CntBits2To5Address(v2->mData, 0, v2->mDataSize);
    v1 = FindSceneFile(data_0216ea14);
    LoadNscrData(&gKeyboard->mNscrs[0], v1);
    v1 = FindSceneFile(data_0216ea30);
    LoadNscrData(&gKeyboard->mNscrs[1], v1);
    v1 = FindSceneFile(data_0216ea4c);
    LoadNclrData(&v3, v1);
    DC_FlushRange(v3->mData, 0x80);
    GXS_LoadBGPltt(v3->mData, 0, (u32) 0x80);
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

void AdvanceKeyboardState0(void) {
    if (func_02036c5c() != 0) {
        gKeyboard->mNextState = 1;
        func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
    }
}

void func_02129b60(void) {
    s32 n;
    n = data_0215d0e0[0] - 1;
    if (n == func_020ab748() && gKeyboard->mUnk_2c[gKeyboard->mUnk_04].mUnk_00[n] != 0) {
        gKeyboard->mUnk_1c[0] = 1;
    } else {
        gKeyboard->mUnk_1c[0] = 0;
    }
    if (func_020ab8c4() == 1) {
        gKeyboard->mUnk_14[0] = 1;
    } else {
        gKeyboard->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        gKeyboard->mUnk_14[1] = 1;
    } else {
        gKeyboard->mUnk_14[1] = 0;
    }
}

void AdvanceKeyboardState1(void) {
    gKeyboard->mUnk_28++;
    gKeyboard->mUnk_84 = func_020ae4c0(1, 0xc0, 0, gKeyboard->mUnk_28, 0xf);
    gKeyboard->mUnk_86[0][1] = func_020ae4c0(1, data_0215d108[0][1], data_0215d100[0][1], gKeyboard->mUnk_28, 0xf);
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (gKeyboard->mUnk_28 >= 0xf && func_02125fa4() != 0) {
        gKeyboard->mNextState = 2;
        gKeyboard->mUnk_24 = TRUE;
        gKeyboard->mUnk_28 = 0;
    }
    func_02129b60();
}

void AdvanceKeyboardState2(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    Keyboard *p;
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
        v = RectTableFindContaining(gKeyboard->mBnbls[0], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = gKeyboard;
    q = &p->mUnk_2c[p->mUnk_04];
    w = func_020ab798();
    MemCopyHalfwords(w, q, 0x18);
    func_02129b60();
    if (v == 1 || (func_020ab8c4() == 1 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = gKeyboard;
        if (p->mUnk_1c[0] != 0) {
            p->mNextState = 3;
            gKeyboard->mUnk_2c[2].mUnk_10 = 1;
            func_02125fc0();
            func_020ab8cc(1);
            gKeyboard->mUnk_24 = FALSE;
            func_0212ecc0(&data_0217d068, 0, 4);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if (v == 0 || (func_020ab8c4() == 2 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        gKeyboard->mNextState = 3;
        gKeyboard->mUnk_2c[2].mUnk_10 = 0;
        func_02125fc0();
        func_020ab8cc(2);
        gKeyboard->mUnk_24 = FALSE;
        func_0212ecc0(&data_0217d068, 0, 0xe);
    }
}

void AdvanceKeyboardState3(void) {
    Keyboard *p;
    gKeyboard->mUnk_28++;
    gKeyboard->mUnk_84 = func_020ae4c0(1, 0, 0xc0, gKeyboard->mUnk_28, 0xf);
    gKeyboard->mUnk_86[0][1] = func_020ae4c0(1, data_0215d100[0][1], data_0215d108[0][1], gKeyboard->mUnk_28, 0xf);
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (gKeyboard->mUnk_28 >= 0xf && func_02125f88() != 0) {
        p = gKeyboard;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            func_0212a410();
            switch (func_02061104(&gKeyboard->mUnk_2c[2])) {
                case 1:
                    gKeyboard->mNextState = 4;
                    func_021262f0(GetBmgEntry(gKeyboard->mUnk_c0, 0xa));
                    gKeyboard->mUnk_28 = 0;
                    return;
                case 2:
                    gKeyboard->mNextState = 4;
                    func_021262f0(GetBmgEntry(gKeyboard->mUnk_c0, 0xb));
                    gKeyboard->mUnk_28 = 0;
                    return;
                default:
                    gKeyboard->mNextState = 6;
                    func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 8), 0, 0, 0, 0, 0, 0);
                    gKeyboard->mUnk_28 = 0;
                    gKeyboard->mUnk_04 = 1;
                    if (data_021759d0->mUnk_00 == 0) {
                        gKeyboard->mUnk_08 = 1;
                    } else {
                        gKeyboard->mUnk_08 = 2;
                    }
                    func_020ab9d0(gKeyboard->mUnk_08);
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

void AdvanceKeyboardState4(void) {
    Keyboard *p;
    gKeyboard->mUnk_28++;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    p = gKeyboard;
    if (p->mUnk_28 >= 0x78) {
        p->mNextState = 1;
        func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
        gKeyboard->mUnk_28 = 0;
    }
}

void AdvanceKeyboardState5(void) {
    if (func_02036c5c() != 0) {
        gKeyboard->mNextState = 6;
        func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 0xf), 0, 0, 0, 0, 0, 0);
        gKeyboard->mUnk_2c[2].mUnk_10 = 1;
    }
}
#pragma thumb off

#pragma thumb on

void func_021296b4(void) {
    s32 i;
    u8 n;
    i = 0;
    gKeyboard->mUnk_1c[0] = 0;
    for (; i < func_020ab748(); i++) {
        if (func_020ab798()[i] != 0x20 && func_020ab798()[i] != 0x3000) {
            gKeyboard->mUnk_1c[0] = 1;
        }
    }
    n = data_0215d0e0[1];
    if (n - 1 == func_020ab748()) {
        if ((func_020ab798() + n)[-1] != 0x20 && (func_020ab798() + n)[-1] != 0x3000 &&
            (func_020ab798() + n)[-1] != 0) {
            gKeyboard->mUnk_1c[0] = 1;
        }
    }
    if (func_020ab8c4() == 1) {
        gKeyboard->mUnk_14[0] = 1;
    } else {
        gKeyboard->mUnk_14[0] = 0;
    }
    if (func_020ab8c4() == 2) {
        gKeyboard->mUnk_14[1] = 1;
        return;
    }
    gKeyboard->mUnk_14[1] = 0;
}

#pragma thumb off

#pragma thumb on
void AdvanceKeyboardState6(void) {
    Keyboard *p;
    gKeyboard->mUnk_28++;
    gKeyboard->mUnk_84 = func_020ae4c0(1, 0xc0, 0, gKeyboard->mUnk_28, 0xf);
    gKeyboard->mUnk_86[1][1] = func_020ae4c0(1, data_0215d108[1][1], data_0215d100[1][1], gKeyboard->mUnk_28, 0xf);
    p = gKeyboard;
    if (p->mUnk_2c[2].mUnk_10 != 0) {
        gKeyboard->mUnk_86[0][0] = func_020ae4c0(1, data_0215d108[0][0], data_0215d100[0][0], p->mUnk_28, 0xf);
    }
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (gKeyboard->mUnk_28 >= 0xf && func_02125fa4() != 0) {
        gKeyboard->mNextState = 7;
        gKeyboard->mUnk_24 = TRUE;
        gKeyboard->mUnk_28 = 0;
    }
    func_021296b4();
    func_02128b0c();
}

void AdvanceKeyboardState7(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    Keyboard *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    BOOL f;
    BOOL g;
    s32 n;
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
        v = RectTableFindContaining(gKeyboard->mBnbls[1], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = gKeyboard;
    q = &p->mUnk_2c[p->mUnk_04];
    w = func_020ab798();
    MemCopyHalfwords(w, q, 0x18);
    func_021296b4();
    if (v == 5 || (func_020ab8c4() == 1 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = gKeyboard;
        if (p->mUnk_1c[0] != 0) {
            p->mNextState = 8;
            gKeyboard->mUnk_2c[2].mUnk_10 = 1;
            func_02125fc0();
            func_020ab8cc(1);
            gKeyboard->mUnk_24 = FALSE;
            func_0212ecc0(&data_0217d068, 0, 4);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if (v == 6 || (func_020ab8c4() == 2 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = gKeyboard;
        if (p->mUnk_1c[1] != 0) {
            p->mNextState = 8;
            gKeyboard->mUnk_2c[2].mUnk_10 = 0;
            func_02125fc0();
            func_020ab8cc(2);
            gKeyboard->mUnk_24 = FALSE;
            func_0212ecc0(&data_0217d068, 0, 0xe);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if ((u16) (data_02175628[i].mUnk_00 & 0x800) != 0) {
        if (data_021759d0->mUnk_00 == 0) {
            gKeyboard->mUnk_08 = data_0215d11c[gKeyboard->mUnk_08];
        } else {
            gKeyboard->mUnk_08 = data_0215d122[gKeyboard->mUnk_08];
        }
        func_020ab9d0(gKeyboard->mUnk_08);
        func_0212ecc0(&data_0217d068, 0, 0x1e5);
    } else {
        p = gKeyboard;
        n = p->mUnk_08;
        f = FALSE;
        switch (v) {
            case 0:
                p->mUnk_08 = 1;
                func_020ab9d0(gKeyboard->mUnk_08);
                f = TRUE;
                break;
            case 1:
                p->mUnk_08 = 2;
                func_020ab9d0(gKeyboard->mUnk_08);
                f = TRUE;
                break;
            case 2:
                p->mUnk_08 = 3;
                func_020ab9d0(gKeyboard->mUnk_08);
                f = TRUE;
                break;
            case 3:
                p->mUnk_08 = 4;
                func_020ab9d0(gKeyboard->mUnk_08);
                f = TRUE;
                break;
            case 4:
                p->mUnk_08 = 5;
                func_020ab9d0(gKeyboard->mUnk_08);
                f = TRUE;
                break;
        }
        if (f != FALSE) {
            if (n != gKeyboard->mUnk_08) {
                func_0212ecc0(&data_0217d068, 0, 0x1e5);
            } else {
                func_0212ecc0(&data_0217d068, 0, 0x1ed);
            }
        }
    }
    func_02128b0c();
}

void AdvanceKeyboardState8(void) {
    u16 buf[10];
    u16 buf2[0xfe];
    Keyboard *p;
    s32 n;
    void *a;
    void *b;
    void *c;
    gKeyboard->mUnk_28++;
    gKeyboard->mUnk_84 = func_020ae4c0(1, 0, 0xc0, gKeyboard->mUnk_28, 0xf);
    gKeyboard->mUnk_86[1][1] = func_020ae4c0(1, data_0215d100[1][1], data_0215d108[1][1], gKeyboard->mUnk_28, 0xf);
    p = gKeyboard;
    if (p->mUnk_2c[2].mUnk_10 == 0) {
        gKeyboard->mUnk_86[0][0] = func_020ae4c0(1, data_0215d100[0][0], data_0215d108[0][0], p->mUnk_28, 0xf);
    }
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (gKeyboard->mUnk_28 >= 0xf && func_02125f88() != 0) {
        p = gKeyboard;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            if (p->mUnk_2c[2].mUnk_14 == 0xc) {
                a = GetBmgEntry(p->mUnk_c0, 0x11);
                b = GetBmgEntry(gKeyboard->mUnk_c0, 0);
                c = GetBmgEntry(p->mUnk_c0, 1);
                func_02125fd4(a, b, c, 0, 0, 1, 1, 0);
            } else {
                a = GetBmgEntry(p->mUnk_c0, 0xe);
                n = func_020adc7c(gKeyboard->mUnk_2c[1].mUnk_00, buf);
                buf[n] = 0;
                func_0212513c(buf, (u16 *) a, &buf2[1], 0x1f4);
                b = GetBmgEntry(gKeyboard->mUnk_c0, 0);
                c = GetBmgEntry(gKeyboard->mUnk_c0, 1);
                func_02125fd4(&buf2[1], b, c, 0, 0, 1, 1, 0);
            }
            gKeyboard->mNextState = 9;
            gKeyboard->mUnk_28 = 0;
        } else if (p->mUnk_2c[2].mUnk_14 == 0xc) {
            p->mUnk_04 = 0;
            gKeyboard->mUnk_08 = 0;
            func_020ab9d0(gKeyboard->mUnk_08);
            func_020ab758(data_0215d0e0[0]);
            func_02129e78();
            func_0212a4bc();
            gKeyboard->mNextState = 1;
            gKeyboard->mUnk_28 = 0;
            func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
        } else {
            p->mUnk_2c[2].mUnk_16 = 7;
        }
    }
}

void AdvanceKeyboardState9(void) {
    s16 v;
    gKeyboard->mUnk_28++;
    v = data_0215d100[1][0];
    gKeyboard->mUnk_86[0][0] =
        func_020ae4c0(1, data_0215d100[0][0], data_0215d100[0][0] - (0xc0 - v), gKeyboard->mUnk_28, 0xf);
    gKeyboard->mUnk_86[1][0] = func_020ae4c0(1, data_0215d108[1][0], v, gKeyboard->mUnk_28, 0xf);
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (gKeyboard->mUnk_28 >= 0xf) {
        if (func_02125fa4() != 0) {
            gKeyboard->mNextState = 0xa;
            gKeyboard->mUnk_28 = 0;
        }
    }
}

void AdvanceKeyboardState10(void) {
    Keyboard *p;
    s16 v;
    void *a;
    void *b;
    if (gKeyboard->mUnk_28 >= 0xf) {
        gKeyboard->mUnk_28 = 0xf;
    }
    if (func_02125f54() != 0 && func_02125f60() == 1) {
        v = data_0215d100[1][0];
        gKeyboard->mUnk_86[1][0] = func_020ae4c0(1, v, data_0215d108[1][0], gKeyboard->mUnk_28, 0xf);
        gKeyboard->mUnk_86[0][0] =
            func_020ae4c0(1, data_0215d100[0][0] - (0xc0 - v), data_0215d100[0][0], gKeyboard->mUnk_28, 0xf);
    }
    if (func_02125f88() != 0 && gKeyboard->mUnk_28 >= 0xf) {
        if (func_02125f60() == 0) {
            p = gKeyboard;
            if (p->mUnk_2c[2].mUnk_14 == 0xc) {
                func_02060cb4(&p->mUnk_2c[2], &p->mUnk_2c[1]);
                func_0205edf8();
                a = GetBmgEntry(gKeyboard->mUnk_c0, 0x81);
                func_02126248(a, 0, 1, 1, 0, 1);
                gKeyboard->mNextState = 0xb;
            } else {
                data_0217aa08->mUnk_00->mUnk_31_0 = 1;
                MemFill(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
                MemCopy(&p->mUnk_2c[1], data_0217aa08->mUnk_00->mUnk_0c, 0x14);
                func_02056d40();
                func_02125ebc(0x21);
                a = GetBmgEntry(gKeyboard->mUnk_c0, 0x10);
                b = GetBmgEntry(gKeyboard->mUnk_c0, 4);
                func_02126138(a, b, 0, 1, 1, 0);
                gKeyboard->mNextState = 0xc;
            }
            gKeyboard->mUnk_28 = 0;
        } else {
            gKeyboard->mNextState = 6;
            gKeyboard->mUnk_2c[2].mUnk_10 = 0;
            gKeyboard->mUnk_28 = 0;
            func_02126638(GetBmgEntry(gKeyboard->mUnk_c0, 0xf), 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (func_02125f54() != 0 || func_02125f88() != 0) {
            func_02125fc0();
            gKeyboard->mUnk_28++;
        }
    }
}

void AdvanceKeyboardState11(void) {
    Keyboard *p;
    void *a;
    s32 w;
    void *b;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x22);
    }
    gKeyboard->mUnk_28++;
    if (func_02125fa4() != 0) {
        p = gKeyboard;
        if (p->mUnk_28 > 0x5a) {
            w = (data_0217aa08->mUnk_28 == 0) ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1;
            if (w == 0) {
                p->mNextState = 0xc;
                gKeyboard->mUnk_28 = 0;
                func_02125ebc(0x21);
                a = GetBmgEntry(gKeyboard->mUnk_c0, 9);
                b = GetBmgEntry(gKeyboard->mUnk_c0, 4);
                func_02126138(a, b, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState12(void) {
    void *a;
    s32 w;
    void *b;
    void *c;
    s32 v;
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
    if (func_02125f88() != 0) {
        w = (data_0217aa08->mUnk_28 == 0) ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1;
        if (w == 0) {
            func_02125ebc(0x23);
            v = gKeyboard->mUnk_2c[2].mUnk_14;
            if (v == 0xc || v == 7) {
                gKeyboard->mUnk_2c[2].mUnk_16 = v;
                return;
            }
            if (v == 0xb) {
                gKeyboard->mNextState = 0xd;
                gKeyboard->mUnk_28 = 0;
                a = GetBmgEntry(gKeyboard->mUnk_c0, 0x13);
                b = GetBmgEntry(gKeyboard->mUnk_c0, 0);
                c = GetBmgEntry(gKeyboard->mUnk_c0, 1);
                func_02125fd4(a, b, c, 0, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState13(void) {
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            gKeyboard->mUnk_2c[2].mUnk_16 = 3;
        } else {
            gKeyboard->mUnk_2c[2].mUnk_16 = 0;
        }
    } else {
        if (func_02125f54() != 0) {
            func_02125fc0();
        }
    }
}

void func_02128cfc(void) {
    s32 i;
    s32 j;
    s32 k;
    u16 buf[2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < data_0215d0e0[i]; k++) {
                buf[0] = 0;
                buf[1] = 0;
                buf[0] = gKeyboard->mUnk_2c[i].mUnk_00[k];
                func_0212426c(j, data_0215d134[i][k], gKeyboard->mBnlls[i], buf, gKeyboard->mBncls[i],
                              gKeyboard->mUnk_74[i][j]);
            }
        }
    }
}

void func_02128ca0(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mUnk_14[i] != 0) {
            n = gKeyboard->mUnk_04;
            gKeyboard->mUnk_74[n][1][data_0215d128[n][i][0]].mUnk_00 = 1;
        } else {
            n = gKeyboard->mUnk_04;
            gKeyboard->mUnk_74[n][1][data_0215d128[n][i][0]].mUnk_00 = 0;
        }
    }
}

void func_02128c40(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mUnk_1c[i] != 0) {
            n = gKeyboard->mUnk_04;
            gKeyboard->mUnk_74[n][1][data_0215d128[n][i][1]].mUnk_00 = 0;
        } else {
            n = gKeyboard->mUnk_04;
            gKeyboard->mUnk_74[n][1][data_0215d128[n][i][1]].mUnk_00 = 1;
        }
    }
}

void func_02128bd4(void) {
    s32 i;
    for (i = 0; i < data_0215d0e0[gKeyboard->mUnk_04]; i++) {
        gKeyboard->mUnk_74[gKeyboard->mUnk_04][1][data_0215d14c[gKeyboard->mUnk_04][i]].mUnk_00 = 0;
    }
    gKeyboard->mUnk_74[gKeyboard->mUnk_04][1][data_0215d14c[gKeyboard->mUnk_04][func_020ab748()]].mUnk_00 = 1;
}

void func_02128b54(void) {
    u16 buf[10];
    s32 n;
    s32 k;
    s32 l;
    s32 i;
    s32 j;
    u8 *q;
    if (gKeyboard->mUnk_04 == 1) {
        n = func_020adc7c(gKeyboard->mUnk_2c[1].mUnk_00, buf);
        k = 6;
        if (n > 4) {
            k = 10 - n;
        }
        i = 0;
        q = data_0215d0f0;
        l = 6 - k;
        for (; i < 6; i++) {
            for (j = 0; j < 2; j++) {
                if (i >= l && gKeyboard->mUnk_2c[2].mUnk_14 != 0xc) {
                    gKeyboard->mUnk_74[1][j][*q].mUnk_00 = 1;
                } else {
                    gKeyboard->mUnk_74[1][j][*q].mUnk_00 = 0;
                }
            }
            q++;
        }
    }
}

void func_02128b0c(void) {
    s32 i;
    BOOL z;
    u8 *q;
    u8 c;
    i = 0;
    q = data_0215d0e8;
    z = FALSE;
    for (; i < 6; i++) {
        c = *q;
        if (c != 0xff) {
            gKeyboard->mUnk_74[1][1][c].mUnk_00 = z;
        }
        q++;
    }
    gKeyboard->mUnk_74[1][1][data_0215d0e8[gKeyboard->mUnk_08]].mUnk_00 = 1;
}

void AdvanceKeyboard(void) {
    s32 i;
    Keyboard *p;
    func_0212a920();
    func_02125928();
    gKeyboard->mState = gKeyboard->mNextState;
    if (gKeyboard->mUnk_24 != FALSE) {
        func_020abae0();
    }
    switch (gKeyboard->mState) {
        case 0:
            AdvanceKeyboardState0();
            break;
        case 1:
            AdvanceKeyboardState1();
            break;
        case 2:
            AdvanceKeyboardState2();
            break;
        case 3:
            AdvanceKeyboardState3();
            break;
        case 4:
            AdvanceKeyboardState4();
            break;
        case 5:
            AdvanceKeyboardState5();
            break;
        case 6:
            AdvanceKeyboardState6();
            break;
        case 7:
            AdvanceKeyboardState7();
            break;
        case 8:
            AdvanceKeyboardState8();
            break;
        case 9:
            AdvanceKeyboardState9();
            break;
        case 10:
            AdvanceKeyboardState10();
            break;
        case 11:
            AdvanceKeyboardState11();
            break;
        case 12:
            AdvanceKeyboardState12();
            break;
        case 13:
            AdvanceKeyboardState13();
            break;
    }
    func_02128cfc();
    func_02128bd4();
    func_02128b54();
    func_02128ca0();
    func_02128c40();
    func_02129ea4();
    for (i = 0; i < 2; i++) {
        p = gKeyboard;
        func_02124c30(p->mBncls[i], p->mNcer, p->mBnlls[i], func_02128898(), p->mUnk_74[i][0]);
    }
    p = gKeyboard;
    func_02124c30(p->mBncls[p->mUnk_04], p->mNcer, p->mBnlls[p->mUnk_04], func_02128884(), p->mUnk_74[p->mUnk_04][1]);
}

void func_0212899c(void) {
    func_020ab94c(0, gKeyboard->mUnk_84 + 0x28);
    *(vu32 *) 0x400101c = (-gKeyboard->mUnk_84 << 16) & 0x1ff0000;
    func_020aba9c();
    func_021258f0();
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardNextScene(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gKeyboard;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 114u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off
