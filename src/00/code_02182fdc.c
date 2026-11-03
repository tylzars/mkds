#include "00/code_02182fdc.h"
#include "code_02148ca0.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_02125f6c.h"

void func_ov000_02184130(void) {
    Ncgr *chr;
    Nscr *scrn;
    Nclr *pltt;
    vu16 zero;
    u16 c;
    s32 i;

    LocateNcgr(&chr, FindSceneFile("WiFi_VS_matching_s_b.ncgr"));
    LocateNscr(&scrn, FindSceneFile("WiFi_VS_matching_s.nscr"));
    LocateNclr(&pltt, FindSceneFile("WiFi_VS_matching_s_b.nclr"));
    gWiFiVSMatching->mWiFiVSMatchingBncl = FindSceneFile("WiFi_VS_matching.bncl");
    gWiFiVSMatching->mWiFiVSMatchingBnbl = FindSceneFile("WiFi_VS_matching.bnbl");
    gWiFiVSMatching->mWiFiVSMatchingBnll = FindSceneFile("WiFi_VS_matching.bnll");
    LocateNcgr2(&gWiFiVSMatching->mWiFiVSMatchingSNcgr, FindSceneFile("WiFi_VS_matching_s.nce.ncgr"));
    LocateNcer(&gWiFiVSMatching->mWiFiVSMatchingSNcer, FindSceneFile("WiFi_VS_matching_s.nce.ncer"));
    LocateNclr(&gWiFiVSMatching->mWiFiVSMatchingSONclr, FindSceneFile("WiFi_VS_matching_s_o.nclr"));
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x4400;
    zero = 0;
    func_0214cfe4(zero, gWiFiVSMatching->mUnk_d4, 0x1000);
    func_0214cffc(scrn->mData, gWiFiVSMatching->mUnk_d4, 0x800);
    func_02016468(0x17, 0, chr->mData, chr->mDataSize);
    func_02016468(0x1b, 0, gWiFiVSMatching->mUnk_d4, 0x1000);
    func_02016468(0x1f, 0, pltt->mData, 0x80);
    func_02016468(0x23, 0, gWiFiVSMatching->mWiFiVSMatchingSNcgr->mData,
                  gWiFiVSMatching->mWiFiVSMatchingSNcgr->mDataSize);
    func_02016468(0x1e, 0, gWiFiVSMatching->mWiFiVSMatchingSONclr->mData,
                  gWiFiVSMatching->mWiFiVSMatchingSONclr->mDataSize);
    for (i = 0; i < 5; i++) {
        c = (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + data_ov000_021b0658[0])[i];
        gWiFiVSMatching->mUnk_58[i][0] = c & 0x1f;
        gWiFiVSMatching->mUnk_58[i][1] = (c & 0x3e0) >> 5;
        gWiFiVSMatching->mUnk_58[i][2] = (c & 0x7c00) >> 10;
    }
    for (i = 0; i < 5; i++) {
        c = (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + data_ov000_021b0658[1])[i];
        gWiFiVSMatching->mUnk_94[i][0] = c & 0x1f;
        gWiFiVSMatching->mUnk_94[i][1] = (c & 0x3e0) >> 5;
        gWiFiVSMatching->mUnk_94[i][2] = (c & 0x7c00) >> 10;
    }
}

void func_ov000_021840c8(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (gWiFiVSMatching->mUnk_24[i] == 0) {
            func_0212426c(1, data_ov000_021b0660[i], gWiFiVSMatching->mWiFiVSMatchingBnll,
                          GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 10), gWiFiVSMatching->mWiFiVSMatchingBncl,
                          gWiFiVSMatching->mUnk_10d4);
        }
    }
}

void func_ov000_0218401c(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mUnk_10 = func_020ae4c0(1, 0x100, 0, gWiFiVSMatching->mUnk_08, 10);
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        gWiFiVSMatching->mUnk_08 = 10;
    }
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        if (func_02125fa4() != 0) {
            gWiFiVSMatching->mNextState = 1;
            gWiFiVSMatching->mUnk_08 = 0;
            if (func_ov000_02180644() != 0) {
                func_02121190(data_0217b488->mUnk_54, 0, 0);
                gWiFiVSMatching->mUnk_3c = 0;
            } else {
                func_02121190(data_0217b488->mUnk_54, 1, 0);
                gWiFiVSMatching->mUnk_3c = 1;
            }
            func_02108b2c();
        }
    }
}

void func_ov000_02183b80(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    BOOL a;
    BOOL b;
    u16 v;
    u32 val;
    s32 j;
    s32 sh;
    s32 n;
    s32 i;
    BOOL flag;
    u16 name[11];
    u16 buf2[10];
    u16 buf3[10];
    u8 *dst;
    s32 k;

    if (gWiFiVSMatching->mUnk_08 >= 0x78) {
        gWiFiVSMatching->mUnk_08 = 0x78;
    }
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (func_021213a0() != 0) {
        func_02128374();
    } else {
        func_021282c8();
    }
    if (gWiFiVSMatching->mUnk_3c != 0) {
        if (func_02121434() == 0) {
            gWiFiVSMatching->mUnk_3c = 0;
            func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 12), 0, 0, 1, 0, 1, 0);
        }
    }
    if (func_02125fa4() != 0 && IsSelectReturnState2NoState3Or4Request() != 0 &&
        (u16) (data_02175628[idx].mUnk_00 & 2) != 0) {
        goto hit;
    }
    a = FALSE;
    b = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        b = TRUE;
    }
    if (b == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
        a = TRUE;
    }
    if (a != FALSE &&
        IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) != 0 &&
        func_021213a0() != 0) {
    hit:
        func_021213e8();
        func_02128310(0);
        gWiFiVSMatching->mNextState = 10;
        gWiFiVSMatching->mUnk_20 = 2;
        gWiFiVSMatching->mUnk_08 = 0;
        func_02125fc0();
        func_0210895c();
        return;
    }
    if (func_02125fa4() != 0 && gWiFiVSMatching->mUnk_08 >= 0x78 && func_0212111c() == -1) {
        func_ov000_021840c8();
        gWiFiVSMatching->mNextState = 9;
        gWiFiVSMatching->mUnk_40 = 1;
        gWiFiVSMatching->mUnk_08 = 0;
        for (i = 0; i < 3; i++) {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        func_02125fc0();
        func_02128374();
        func_02108990();
        return;
    }
    if (func_02125fa4() != 0 && func_0212111c() == 1) {
        k = 0;
        gWiFiVSMatching->mUnk_08 = 0;
        if (data_0217d384->mKartCount <= 1) {
            func_ov000_021840c8();
            gWiFiVSMatching->mNextState = 9;
            gWiFiVSMatching->mUnk_40 = 1;
            for (i = 0; i < 3; i++) {
                gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
            }
            func_02125fc0();
            func_02128374();
            func_02108990();
            return;
        }
        gWiFiVSMatching->mUnk_30 = data_0217d384->mKartCount - 1;
        for (j = 0; j < data_0217d384->mKartCount; j++) {
            if (j != func_ov000_0219bb50()) {
                gWiFiVSMatching->mUnk_34[k] = j;
                gWiFiVSMatching->mUnk_24[k] = 1;
                k++;
            }
        }
        for (i = 0; i < gWiFiVSMatching->mUnk_30; i++) {
            func_0214cffc(func_021202b0(gWiFiVSMatching->mUnk_34[i]), name, 0x14);
            name[10] = 0;
            func_0212426c(1, data_ov000_021b0664[i], gWiFiVSMatching->mWiFiVSMatchingBnll, name,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4);
            val = func_02120240(gWiFiVSMatching->mUnk_34[i]);
            if (val > 9999) {
                val = 9999;
            }
            func_02124fac(func_0212025c(gWiFiVSMatching->mUnk_34[i]), buf2);
            func_02124fac(val, buf3);
            func_0212426c(1, data_ov000_021b0670[i][0], gWiFiVSMatching->mWiFiVSMatchingBnll, buf2,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4);
            func_0212426c(1, data_ov000_021b0670[i][1], gWiFiVSMatching->mWiFiVSMatchingBnll, buf3,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4);
            dst = gWiFiVSMatching->mUnk_10d8[0];
            dst += i * 0x200;
            func_020ac2fc(func_02120294(gWiFiVSMatching->mUnk_34[i]), dst, 0x20);
            gWiFiVSMatching->mUnk_16d8[i] = func_02120278(gWiFiVSMatching->mUnk_34[i]);
        }
        for (i = 0; i < 3; i++) {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        for (i = 0; i < gWiFiVSMatching->mUnk_30; i++) {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 1;
        }
        gWiFiVSMatching->mNextState = 2;
        func_021282c8();
        func_02125fc0();
        func_0202b604();
        func_02108a40();
        gWiFiVSMatching->mUnk_44 = 0;
        return;
    }
    n = func_02121418() - 1;
    flag = FALSE;
    if (n > 3) {
        n = 3;
    }
    gWiFiVSMatching->mUnk_0c = gWiFiVSMatching->mUnk_0c + 1;
    if (gWiFiVSMatching->mUnk_0c >= 0x50) {
        gWiFiVSMatching->mUnk_0c = 0;
    }
    if (n > 0) {
        sh = 0x50 >> (n - 1);
        if (gWiFiVSMatching->mUnk_0c % sh >= sh / 2) {
            flag = TRUE;
        }
    }
    for (i = 0; i < 3; i++) {
        if (i < n && flag != FALSE) {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 1;
            if (i >= gWiFiVSMatching->mUnk_38) {
                func_02108adc();
                gWiFiVSMatching->mUnk_38 = gWiFiVSMatching->mUnk_38 + 1;
            }
        } else {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
    }
    sh = gWiFiVSMatching->mUnk_38;
    while (n < gWiFiVSMatching->mUnk_38) {
        func_02108a8c();
        sh--;
        n++;
    }
    gWiFiVSMatching->mUnk_38 = sh;
}

void func_ov000_02183a0c(void) {
    s32 t = gWiFiVSMatching->mUnk_08;
    u16 x = (t << 16) / 0x14;
    s32 y = ((0x13 - t) * 0xf33) / 0x14 + 0xcd;
    s32 i;
    Nclr *q;

    for (i = 0; i < 3; i++) {
        func_02124b1c(&gWiFiVSMatching->mUnk_10d4[data_ov000_021b0668[i]], x, y);
    }
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x14) {
        if (func_02125f88() != 0) {
            q = func_02077f00();
            for (i = 0; i < 3; i++) {
                gWiFiVSMatching->mUnk_10d4[data_ov000_021b0668[i]].mUnk_00 = 0;
            }
            func_ov000_021840c8();
            for (i = 0; i < gWiFiVSMatching->mUnk_30; i++) {
                if (gWiFiVSMatching->mUnk_16d8[i] != 0) {
                    func_02016468(0x23,
                                  func_0212497c(data_ov000_021b0668[i], gWiFiVSMatching->mWiFiVSMatchingSNcer,
                                                gWiFiVSMatching->mWiFiVSMatchingBncl)
                                      << 5,
                                  gWiFiVSMatching->mUnk_10d8[i], 0x200);
                    func_02016468(0x1e, (i + 3) << 5, q->mData, 0x20);
                }
                gWiFiVSMatching->mUnk_10d4[data_ov000_021b0660[i] + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06]
                    .mUnk_00 = 0;
            }
            func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 11), 0, 0, 1, 0, 0, 0);
            gWiFiVSMatching->mNextState = 3;
            gWiFiVSMatching->mUnk_08 = 0;
        }
    }
}

void func_ov000_021839d0(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x28) {
        gWiFiVSMatching->mNextState = 4;
        gWiFiVSMatching->mUnk_08 = 0;
        func_0212ecc0(&data_0217d068, 0, 0x20b);
    }
}

void func_ov000_02183858(void) {
    s32 orig;
    s32 i1;
    s32 i2;
    s32 cur;
    s32 a;
    s32 b;
    u32 base;
    u16 c;
    s32 j;
    u32 e;

    orig = gWiFiVSMatching->mUnk_08;
    i1 = orig;
    i2 = orig;
    cur = gWiFiVSMatching->mUnk_44;
    base = gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06;
    if (orig >= 0x1e) {
        i1 = 0x1d;
    }
    if (orig >= 0x28) {
        i2 = 0x27;
    }
    a = (data_ov000_021b0ce4[i1] << 12) / 100;
    b = (data_ov000_021b0d04[i2] << 12) / 100;
    if (orig < 0x20) {
        c = (i2 << 17) / 0x20;
    } else {
        c = 0;
    }
    gWiFiVSMatching->mUnk_10d4[base + data_ov000_021b0664[cur]].mUnk_00 = 1;
    for (j = 0; j < 2; j++) {
        gWiFiVSMatching->mUnk_10d4[(&data_ov000_021b0678[0][0] + cur * 2)[j]].mUnk_00 = 1;
        gWiFiVSMatching->mUnk_10d4[base + (&data_ov000_021b0670[0][0] + cur * 2)[j]].mUnk_00 = 1;
    }
    e = data_ov000_021b0668[cur] << 6;
    ((Unk02124b1c *) ((u32) gWiFiVSMatching->mUnk_10d4 + e))->mUnk_00 = 1;
    *(s16 *) ((u8 *) gWiFiVSMatching->mUnk_18 + cur * 2) = data_ov000_021b069c[i1];
    for (j = 0; j < 2; j++) {
        func_02124b1c(&gWiFiVSMatching->mUnk_10d4[(&data_ov000_021b0678[0][0] + cur * 2)[j]], 0, a);
    }
    func_02124b1c((Unk02124b1c *) ((u32) gWiFiVSMatching->mUnk_10d4 + e), c, b);
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x1e && gWiFiVSMatching->mUnk_08 >= 0x28) {
        gWiFiVSMatching->mUnk_08 = 0;
        if (gWiFiVSMatching->mUnk_44 == gWiFiVSMatching->mUnk_30 - 1) {
            gWiFiVSMatching->mNextState = 8;
            return;
        }
        gWiFiVSMatching->mUnk_44 = gWiFiVSMatching->mUnk_44 + 1;
        gWiFiVSMatching->mNextState = 5;
    }
}

void func_ov000_0218381c(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x50) {
        gWiFiVSMatching->mNextState = 4;
        gWiFiVSMatching->mUnk_08 = 0;
        func_0212ecc0(&data_0217d068, 0, 0x20b);
    }
}

void func_ov000_021837b8(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    // mUnk_30 is 1 to 3 here and indexes the table from 1.
    if (gWiFiVSMatching->mUnk_08 >= (data_ov000_021b0680 - 1)[gWiFiVSMatching->mUnk_30]) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            gWiFiVSMatching->mNextState = 11;
            gWiFiVSMatching->mUnk_20 = 4;
            gWiFiVSMatching->mUnk_08 = 0;
            func_02125fc0();
            func_02036f10((s16) (30));
            func_0212ecc0(&data_0217d068, 0, 0x20c);
        }
    }
}

void func_ov000_021836f4(void) {
    BOOL a;
    BOOL b;
    u16 v;
    Unk02175628Index idx = UNK_02175628_INDEX_8;

    if (func_02125f88() != 0) {
        func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 13), 0, 0, 1, 0, 0, 0);
    }
    if (func_02125fa4() != 0) {
        if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
            a = FALSE;
            b = FALSE;
            v = data_02175628[idx].mHasPair;
            if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
                b = TRUE;
            }
            if (b == FALSE && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
                a = TRUE;
            }
            if (a == FALSE) {
                return;
            }
            if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                data_02175628[idx].mUnk_4a) == 0) {
                return;
            }
        }
        gWiFiVSMatching->mNextState = 10;
        gWiFiVSMatching->mUnk_20 = 2;
        func_02128310(0);
        func_02125fc0();
    }
}

void func_ov000_02183674(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mUnk_10 = func_020ae4c0(1, 0, 0x100, gWiFiVSMatching->mUnk_08, 10);
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        gWiFiVSMatching->mUnk_08 = 10;
    }
    if (func_02125f88() != 0 && IsSelectReturnState2NoState3Or4Request() != 0 && gWiFiVSMatching->mUnk_08 >= 10) {
        if (gWiFiVSMatching->mUnk_40 != 0) {
            RequestWiFiState(gWiFiVSMatching->mUnk_20);
            return;
        }
        if (func_0212137c() != 0) {
            RequestWiFiState(gWiFiVSMatching->mUnk_20);
        }
    }
}

void func_ov000_0218364c(void) {
    if (func_02036d08() != 0) {
        if (func_02125f88() != 0) {
            RequestWiFiState(gWiFiVSMatching->mUnk_20);
        }
    }
}

void func_ov000_02183548(void) {
    s32 i;
    u32 base = gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            gWiFiVSMatching->mUnk_10d4[data_ov000_021b068c[i][j]].mUnk_04 = gWiFiVSMatching->mUnk_10;
        }
    }
    for (i = 0; i < 3; i++) {
        (gWiFiVSMatching->mUnk_10d4 + base)[data_ov000_021b0664[i]].mUnk_04 =
            gWiFiVSMatching->mUnk_10 + gWiFiVSMatching->mUnk_18[i];
        (gWiFiVSMatching->mUnk_10d4 + base)[data_ov000_021b0660[i]].mUnk_04 = gWiFiVSMatching->mUnk_10;
        for (j = 0; j < 2; j++) {
            (gWiFiVSMatching->mUnk_10d4 + base)[data_ov000_021b0670[i][j]].mUnk_04 =
                gWiFiVSMatching->mUnk_10 - gWiFiVSMatching->mUnk_18[i];
        }
    }
    (gWiFiVSMatching->mUnk_10d4 + base)[12].mUnk_04 = gWiFiVSMatching->mUnk_10;
}

void func_ov000_021834b0(s32 t) {
    s32 i;

    for (i = 0; i < 5; i++) {
        Unk021b4c74 *p = gWiFiVSMatching;

        p->mUnk_4c[i] = ((((0x1000 - t) * p->mUnk_58[i][2] + t * p->mUnk_94[i][2]) >> 12) << 10) |
                        ((((0x1000 - t) * p->mUnk_58[i][0] + t * p->mUnk_94[i][0]) >> 12) |
                         ((((0x1000 - t) * p->mUnk_58[i][1] + t * p->mUnk_94[i][1]) >> 12) << 5));
    }
    func_02016468(0x1e, 0x36, gWiFiVSMatching->mUnk_4c, 10);
}

void func_ov000_02183444(void) {
    s32 t;

    if (gWiFiVSMatching->mState == 8 || gWiFiVSMatching->mState == 11) {
        gWiFiVSMatching->mUnk_48 = gWiFiVSMatching->mUnk_48 + 1;
        if (gWiFiVSMatching->mUnk_48 >= 0x3c) {
            gWiFiVSMatching->mUnk_48 = 0;
        }
        t = gWiFiVSMatching->mUnk_48;
        if (t < 0x14) {
            func_ov000_021834b0((t << 12) / 0x14);
            return;
        }
        if (t < 0x28) {
            func_ov000_021834b0(((0x28 - t) << 12) / 0x14);
            return;
        }
        func_ov000_021834b0(0);
    }
}

void AdvanceWiFiVSMatching(void) {
    gWiFiVSMatching->mState = gWiFiVSMatching->mNextState;
    switch (gWiFiVSMatching->mState) {
        case 0:
            func_ov000_0218401c();
            break;
        case 1:
            func_ov000_02183b80();
            break;
        case 2:
            func_ov000_02183a0c();
            break;
        case 3:
            func_ov000_021839d0();
            break;
        case 4:
            func_ov000_02183858();
            break;
        case 5:
            func_ov000_0218381c();
            break;
        case 8:
            func_ov000_021837b8();
            break;
        case 9:
            func_ov000_021836f4();
            break;
        case 10:
            func_ov000_02183674();
            break;
        case 11:
            func_ov000_0218364c();
            break;
    }
    func_ov000_02183548();
    func_ov000_02183444();
    func_02124c30(gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                  gWiFiVSMatching->mWiFiVSMatchingBnll, func_ov000_021804e0(), gWiFiVSMatching->mUnk_10d4);
}

void func_ov000_02183330(void) {
    s32 x;
    u32 plane;

    plane = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & 0xffffe0ff) | ((plane | 8) << 8);
    x = -gWiFiVSMatching->mUnk_10;
    if (x <= -0x100) {
        x = -0x100;
    }
    if (x >= 0x100) {
        x = 0x100;
    }
    (reg_G2S_DB_BG3OFS) = x & 0x1ff;
}

void RegisterWiFiVSMatchingCallbacks(void) {
    Unk021b0cd4 x = {InitWiFiVSMatching, func_ov000_02184354, AdvanceWiFiVSMatching, func_ov000_02183330};

    SetWiFiStateCallbacks(&x);
}

BOOL func_ov000_021832f0(void) {
    if (func_0205e548() != 0) {
        return TRUE;
    }
    return FALSE;
}

void InitWiFiVSSetting(void *heap) {
    s32 i;

    gWiFiVSSetting = HeapAlloc(heap, 0x1060);
    gWiFiVSSetting->mHeap = heap;
    gWiFiVSSetting->mState = 0;
    gWiFiVSSetting->mNextState = 0;
    gWiFiVSSetting->mUnk_08 = 1;
    gWiFiVSSetting->mPendingWiFiState = -1;
    gWiFiVSSetting->mStateFrames = 0;
    gWiFiVSSetting->mUnk_24 = 1;
    func_ov000_02180638(0);
    func_ov000_02182e18();
    func_0212b928(heap, gWiFiVSSetting->mWiFiVSSettingSONclr, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b060c[i][0], 1, gWiFiVSSetting->mWiFiVSSettingSNcer,
                      gWiFiVSSetting->mWiFiVSSettingBncl);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(heap, gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingBnll,
                  &gWiFiVSSetting->mUnk_103c);
    gWiFiVSSetting->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiVSSetting->mCommonMessages = func_02047a28("common.bmg");
    {
        s32 v = func_02148ca0();
        u8 a[1] = {1};
        u8 b[1][2] = {{0xc8, 0x10}};
        u32 c[1] = {1};

        for (i = 0; i < 1; i++) {
            v -= func_021243ac(heap, a[i], gWiFiVSSetting->mWiFiVSSettingBnll, b[i][0], b[i][1],
                               data_ov000_021b060c[i][11], gWiFiVSSetting->mWiFiVSSettingSNcer,
                               gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mUnk_103c, v);
            func_0212426c(1, a[i], gWiFiVSSetting->mWiFiVSSettingBnll, GetBmgEntry(gWiFiVSSetting->mWiFiMessages, c[i]),
                          gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mUnk_103c);
        }
        {
            u8 d[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 k;
            void *t;

            for (i = 0; i < 3; i++) {
                k = 0;
                if (i == 1) {
                    gWiFiVSSetting->mSettingIndex = data_ov000_021b05f0[data_0217b488->mUnk_54];
                    if (gWiFiVSSetting->mSettingIndex == 0 && !func_ov000_021832f0()) {
                        gWiFiVSSetting->mSettingIndex = 2;
                    }
                    k = gWiFiVSSetting->mSettingIndex;
                }
                v -= func_021243ac(heap, data_ov000_021b05e8[i], gWiFiVSSetting->mWiFiVSSettingBnll, d[i][0], d[i][1],
                                   data_ov000_021b060c[i][1], gWiFiVSSetting->mWiFiVSSettingSNcer,
                                   gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mUnk_103c, v);
                if (i == 2) {
                    t = GetBmgEntry(gWiFiVSSetting->mCommonMessages, data_ov000_021b0628[i][k]);
                } else if (i == 1) {
                    t = GetBmgEntry(gWiFiVSSetting->mWiFiMessages,
                                    LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex));
                } else {
                    t = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, data_ov000_021b0628[i][k]);
                }
                func_0212426c(1, data_ov000_021b05e8[i], gWiFiVSSetting->mWiFiVSSettingBnll, t,
                              gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mUnk_103c);
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gWiFiVSSetting->mUnk_14[i][0] = 0;
            gWiFiVSSetting->mUnk_14[i][1] = 0x28;
        } else if (i == 1) {
            gWiFiVSSetting->mUnk_14[i][0] = -0x100;
            gWiFiVSSetting->mUnk_14[i][1] = 0;
        } else {
            gWiFiVSSetting->mUnk_14[i][0] = 0x100;
            gWiFiVSSetting->mUnk_14[i][1] = 0;
        }
    }
    gWiFiVSSetting->mIndexDecrementTimer = 0;
    gWiFiVSSetting->mIndexIncrementTimer = 0;
    func_0212a910(1, 1);
    func_021281c8(0xe);
}
