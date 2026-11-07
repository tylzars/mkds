#include "00/code_021832d8.h"

#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02029890.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"

void func_ov000_02184670(void) {
    s32 n;
    u32 q;
    s32 i;

    n = GX_GetSizeOfSubOBJ();
    {
        u8 b[3][2] = {{0x78, 0x10}, {0x78, 0x10}, {0x78, 0x10}};
        u8 *t1 = &b[0][0];
        u8 *t2;
        u8 *t3;

        for (i = 0, t2 = data_ov000_021b066c, t3 = data_ov000_021b0664; i < 3; i++) {
            n -= func_021243ac(gWiFiVSMatching->mHeap, *t3, gWiFiVSMatching->mWiFiVSMatchingBnll, t1[0], t1[1], *t2,
                               gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                               gWiFiVSMatching->mWiFiVSMatchingTable, n);
            t2++;
            t1 += 2;
            t3++;
        }
    }
    {
        s32 j;
        u8 e[3][2][2] = {{{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}};

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2; j++) {
                n -= func_021243ac(gWiFiVSMatching->mHeap, data_ov000_021b0670[i][j],
                                   gWiFiVSMatching->mWiFiVSMatchingBnll, e[i][j][0], e[i][j][1],
                                   data_ov000_021b0678[i][j], gWiFiVSMatching->mWiFiVSMatchingSNcer,
                                   gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable, n);
            }
        }
    }
    {
        void *p;
        WiFiVSMatching *g;
        u8 c[3][2] = {{0x78, 0x20}, {0x78, 0x20}, {0x78, 0x20}};
        u8 *w = &c[0][0];
        u8 *t1;
        u8 *t2;

        for (i = 0, t1 = data_ov000_021b0668, t2 = data_ov000_021b0660; i < 3; i++) {
            n -= func_021243ac(gWiFiVSMatching->mHeap, *t2, gWiFiVSMatching->mWiFiVSMatchingBnll, w[0], w[1], *t1,
                               gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                               gWiFiVSMatching->mWiFiVSMatchingTable, n);
            g = gWiFiVSMatching;
            p = GetBmgEntry(g->mWiFiMessages, 9);
            func_0212426c(1, *t2, gWiFiVSMatching->mWiFiVSMatchingBnll, p, g->mWiFiVSMatchingBncl,
                          g->mWiFiVSMatchingTable);
            t1++;
            w += 2;
            t2++;
        }
    }
    {
        u8 a[2] = {0xa0, 0x10};

        q = LookupWiFiVSSettingMessageIndex(GetWiFiVSSettingIndex());
        func_021243ac(gWiFiVSMatching->mHeap, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll, a[0], a[1],
                      gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                      gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable, n);
        func_0212426c(1, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll, GetBmgEntry(gWiFiVSMatching->mWiFiMessages, q),
                      gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
    }
}

void func_ov000_021845ac(void) {
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;
    s32 x;
    u8 *r;

    x = gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06;
    i = 0;
    r = &data_ov000_021b0678[0][0];
    p = &data_ov000_021b0670[0][0];
    q = data_ov000_021b0668;
    for (; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[r[j]].mUnk_10 = 1;
            gWiFiVSMatching->mWiFiVSMatchingTable[x + p[j]].mUnk_10 = 1;
            func_02124b1c(&gWiFiVSMatching->mWiFiVSMatchingTable[r[j]], 0, 0x1000);
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*q].mUnk_10 = 1;
        func_02124b1c(&gWiFiVSMatching->mWiFiVSMatchingTable[*q], 0, 0x1000);
        r += 2;
        p += 2;
        q++;
    }
}

void InitWiFiVSMatching(void *a) {
    s32 i;
    s32 k;
    void *b;
    u8 *r;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 c;

    func_02029930();
    gWiFiVSMatching = HeapAlloc(a, 0x170c);
    gWiFiVSMatching->mHeap = a;
    gWiFiVSMatching->mState = 0;
    gWiFiVSMatching->mNextState = 0;
    gWiFiVSMatching->mPendingWiFiState = -1;
    gWiFiVSMatching->mUnk_08 = 0;
    gWiFiVSMatching->mUnk_0c = 0;
    gWiFiVSMatching->mUnk_38 = 0;
    for (i = 0; i < 3; i++) {
        gWiFiVSMatching->mUnk_24[i] = 0;
    }
    gWiFiVSMatching->mUnk_40 = FALSE;
    LocateAndQueueWiFiVSMatching();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingBnll,
                  &gWiFiVSMatching->mWiFiVSMatchingTable);
    gWiFiVSMatching->mWiFiMessages = FindSceneFile(gWiFiBmgName2);
    gWiFiVSMatching->mCommonMessages = FindFileInLoadedArchives(gCommonBmgName4);
    func_ov000_02184670();
    i = 0;
    r = &data_ov000_021b068c[0][0];
    p1 = data_ov000_021b0668;
    p2 = data_ov000_021b0664;
    p3 = &data_ov000_021b0670[0][0];
    p4 = data_ov000_021b066c;
    for (; i < 3; i++) {
        for (k = 0; k < 5; k++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[r[k]].mUnk_00 = 0;
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*p1].mUnk_00 = 1;
        gWiFiVSMatching->mWiFiVSMatchingTable[*p2 + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06].mUnk_00 = 0;
        for (k = 0; k < 2; k++) {
            c = p3[k];
            gWiFiVSMatching->mWiFiVSMatchingTable[c + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06].mUnk_00 = 0;
        }
        gWiFiVSMatching->mWiFiVSMatchingTable[*p4].mUnk_00 = 1;
        r += 5;
        p1++;
        p2++;
        p3 += 2;
        p4++;
    }
    gWiFiVSMatching->mOffset = 0x100;
    for (i = 0; i < 3; i++) {
        gWiFiVSMatching->mUnk_12[i] = 0;
        gWiFiVSMatching->mUnk_18[i] = 0;
    }
    func_ov000_021845ac();
    if (func_ov000_02180644() != 0) {
        func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 12), 0, 0, 1, 0, 1, 0);
    } else {
        func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 8), 0, 0, 1, 0, 1, 0);
    }
    gWiFiVSMatching->mBlendFrames = 0;
}

void func_ov000_02184354(void) {
    u32 a;
    func_0210895c();
    a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((a & ~8) << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0xf00;
    gWiFiVSMatching = NULL;
}

void LocateAndQueueWiFiVSMatching(void) {
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
    MIi_CpuClear16(zero, gWiFiVSMatching->mNscrCopy, 0x1000);
    MIi_CpuCopy16(scrn->mData, gWiFiVSMatching->mNscrCopy, 0x800);
    CallQueueAppend(0x17, 0, chr->mData, chr->mDataSize);
    CallQueueAppend(0x1b, 0, gWiFiVSMatching->mNscrCopy, 0x1000);
    CallQueueAppend(0x1f, 0, pltt->mData, 0x80);
    CallQueueAppend(0x23, 0, gWiFiVSMatching->mWiFiVSMatchingSNcgr->mData,
                    gWiFiVSMatching->mWiFiVSMatchingSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, gWiFiVSMatching->mWiFiVSMatchingSONclr->mData,
                    gWiFiVSMatching->mWiFiVSMatchingSONclr->mDataSize);
    for (i = 0; i < 5; i++) {
        c = (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + data_ov000_021b0658[0])[i];
        gWiFiVSMatching->mFromChannels[i][0] = c & 0x1f;
        gWiFiVSMatching->mFromChannels[i][1] = (c & 0x3e0) >> 5;
        gWiFiVSMatching->mFromChannels[i][2] = (c & 0x7c00) >> 10;
    }
    for (i = 0; i < 5; i++) {
        c = (gWiFiVSMatching->mWiFiVSMatchingSONclr->mData + 0x60 + data_ov000_021b0658[1])[i];
        gWiFiVSMatching->mToChannels[i][0] = c & 0x1f;
        gWiFiVSMatching->mToChannels[i][1] = (c & 0x3e0) >> 5;
        gWiFiVSMatching->mToChannels[i][2] = (c & 0x7c00) >> 10;
    }
}

void func_ov000_021840c8(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (gWiFiVSMatching->mUnk_24[i] == 0) {
            func_0212426c(1, data_ov000_021b0660[i], gWiFiVSMatching->mWiFiVSMatchingBnll,
                          GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 10), gWiFiVSMatching->mWiFiVSMatchingBncl,
                          gWiFiVSMatching->mWiFiVSMatchingTable);
        }
    }
}

void AdvanceWiFiVSMatchingState0(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mOffset = InterpolateS16(1, 0x100, 0, gWiFiVSMatching->mUnk_08, 10);
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        gWiFiVSMatching->mUnk_08 = 10;
    }
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        if (func_02125fa4() != 0) {
            gWiFiVSMatching->mNextState = 1;
            gWiFiVSMatching->mUnk_08 = 0;
            if (func_ov000_02180644() != 0) {
                func_02121190(data_0217b488->mUnk_54, 0, 0);
                gWiFiVSMatching->mUnk_3c = FALSE;
            } else {
                func_02121190(data_0217b488->mUnk_54, 1, 0);
                gWiFiVSMatching->mUnk_3c = TRUE;
            }
            func_02108b2c();
        }
    }
}

void AdvanceWiFiVSMatchingState1(void) {
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
    if (func_021213a0() != FALSE) {
        func_02128374();
    } else {
        func_021282c8();
    }
    if (gWiFiVSMatching->mUnk_3c != FALSE) {
        if (func_02121434() == FALSE) {
            gWiFiVSMatching->mUnk_3c = FALSE;
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
        IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) !=
            FALSE &&
        func_021213a0() != FALSE) {
    hit:
        func_021213e8();
        func_02128310(0);
        gWiFiVSMatching->mNextState = 10;
        gWiFiVSMatching->mPendingWiFiState = 2;
        gWiFiVSMatching->mUnk_08 = 0;
        RequestTxtSystemClose();
        func_0210895c();
        return;
    }
    if (func_02125fa4() != 0 && gWiFiVSMatching->mUnk_08 >= 0x78 && func_0212111c() == -1) {
        func_ov000_021840c8();
        gWiFiVSMatching->mNextState = 9;
        gWiFiVSMatching->mUnk_40 = TRUE;
        gWiFiVSMatching->mUnk_08 = 0;
        for (i = 0; i < 3; i++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        RequestTxtSystemClose();
        func_02128374();
        func_02108990();
        return;
    }
    if (func_02125fa4() != 0 && func_0212111c() == 1) {
        k = 0;
        gWiFiVSMatching->mUnk_08 = 0;
        if (gWiFiSession->mKartCount <= 1) {
            func_ov000_021840c8();
            gWiFiVSMatching->mNextState = 9;
            gWiFiVSMatching->mUnk_40 = TRUE;
            for (i = 0; i < 3; i++) {
                gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 0;
            }
            RequestTxtSystemClose();
            func_02128374();
            func_02108990();
            return;
        }
        gWiFiVSMatching->mOtherCount = gWiFiSession->mKartCount - 1;
        for (j = 0; j < gWiFiSession->mKartCount; j++) {
            if (j != func_ov000_0219bb50()) {
                gWiFiVSMatching->mOtherIndices[k] = j;
                gWiFiVSMatching->mUnk_24[k] = 1;
                k++;
            }
        }
        for (i = 0; i < gWiFiVSMatching->mOtherCount; i++) {
            MIi_CpuCopy16(func_021202b0(gWiFiVSMatching->mOtherIndices[i]), name, 0x14);
            name[10] = 0;
            func_0212426c(1, data_ov000_021b0664[i], gWiFiVSMatching->mWiFiVSMatchingBnll, name,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            val = func_02120240(gWiFiVSMatching->mOtherIndices[i]);
            if (val > 9999) {
                val = 9999;
            }
            func_02124fac(func_0212025c(gWiFiVSMatching->mOtherIndices[i]), buf2);
            func_02124fac(val, buf3);
            func_0212426c(1, data_ov000_021b0670[i][0], gWiFiVSMatching->mWiFiVSMatchingBnll, buf2,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            func_0212426c(1, data_ov000_021b0670[i][1], gWiFiVSMatching->mWiFiVSMatchingBnll, buf3,
                          gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingTable);
            dst = gWiFiVSMatching->mOtherEmblems[0];
            dst += i * 0x200;
            func_020ac2fc(func_02120294(gWiFiVSMatching->mOtherIndices[i]), dst, 0x20);
            gWiFiVSMatching->mUnk_16d8[i] = func_02120278(gWiFiVSMatching->mOtherIndices[i]);
        }
        for (i = 0; i < 3; i++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        for (i = 0; i < gWiFiVSMatching->mOtherCount; i++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 1;
        }
        gWiFiVSMatching->mNextState = 2;
        func_021282c8();
        RequestTxtSystemClose();
        func_0202b604();
        func_02108a40();
        gWiFiVSMatching->mCurrentOtherIndex = 0;
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
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 1;
            if (i >= gWiFiVSMatching->mUnk_38) {
                func_02108adc();
                gWiFiVSMatching->mUnk_38 = gWiFiVSMatching->mUnk_38 + 1;
            }
        } else {
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b065c[i]].mUnk_00 = 0;
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

void AdvanceWiFiVSMatchingState2(void) {
    s32 t = gWiFiVSMatching->mUnk_08;
    u16 x = (t << 16) / 0x14;
    s32 y = ((0x13 - t) * 0xf33) / 0x14 + 0xcd;
    s32 i;
    Nclr *q;

    for (i = 0; i < 3; i++) {
        func_02124b1c(&gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b0668[i]], x, y);
    }
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x14) {
        if (func_02125f88() != 0) {
            q = GetEmblemSBNclr();
            for (i = 0; i < 3; i++) {
                gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b0668[i]].mUnk_00 = 0;
            }
            func_ov000_021840c8();
            for (i = 0; i < gWiFiVSMatching->mOtherCount; i++) {
                if (gWiFiVSMatching->mUnk_16d8[i] != 0) {
                    CallQueueAppend(0x23,
                                    func_0212497c(data_ov000_021b0668[i], gWiFiVSMatching->mWiFiVSMatchingSNcer,
                                                  gWiFiVSMatching->mWiFiVSMatchingBncl)
                                        << 5,
                                    gWiFiVSMatching->mOtherEmblems[i], 0x200);
                    CallQueueAppend(0x1e, (i + 3) << 5, q->mData, 0x20);
                }
                gWiFiVSMatching
                    ->mWiFiVSMatchingTable[data_ov000_021b0660[i] + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06]
                    .mUnk_00 = 0;
            }
            func_02126638(GetBmgEntry(gWiFiVSMatching->mWiFiMessages, 11), 0, 0, 1, 0, 0, 0);
            gWiFiVSMatching->mNextState = 3;
            gWiFiVSMatching->mUnk_08 = 0;
        }
    }
}

void AdvanceWiFiVSMatchingState3(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x28) {
        gWiFiVSMatching->mNextState = 4;
        gWiFiVSMatching->mUnk_08 = 0;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x20b);
    }
}

u8 data_ov000_021b0ce4[30] = {
    0x0a, 0x14, 0x1e, 0x28, 0x32, 0x3c, 0x46, 0x50, 0x5a, 0x64, 0x6e, 0x78, 0x82, 0x82, 0x82,
    0x78, 0x6e, 0x64, 0x5a, 0x5a, 0x64, 0x6e, 0x78, 0x78, 0x78, 0x6e, 0x64, 0x64, 0x64, 0x64,
};

u8 data_ov000_021b0d04[40] = {
    0x0a, 0x14, 0x1e, 0x28, 0x32, 0x3c, 0x46, 0x50, 0x5a, 0x64, 0x6e, 0x78, 0x82, 0x8c,
    0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x91, 0x8c, 0x87,
    0x82, 0x7d, 0x78, 0x73, 0x6e, 0x69, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64,
};

void AdvanceWiFiVSMatchingState4(void) {
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
    cur = gWiFiVSMatching->mCurrentOtherIndex;
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
    gWiFiVSMatching->mWiFiVSMatchingTable[base + data_ov000_021b0664[cur]].mUnk_00 = 1;
    for (j = 0; j < 2; j++) {
        gWiFiVSMatching->mWiFiVSMatchingTable[(&data_ov000_021b0678[0][0] + cur * 2)[j]].mUnk_00 = 1;
        gWiFiVSMatching->mWiFiVSMatchingTable[base + (&data_ov000_021b0670[0][0] + cur * 2)[j]].mUnk_00 = 1;
    }
    e = data_ov000_021b0668[cur] << 6;
    ((Unk02124b1c *) ((u32) gWiFiVSMatching->mWiFiVSMatchingTable + e))->mUnk_00 = 1;
    *(s16 *) ((u8 *) gWiFiVSMatching->mUnk_18 + cur * 2) = data_ov000_021b069c[i1];
    for (j = 0; j < 2; j++) {
        func_02124b1c(&gWiFiVSMatching->mWiFiVSMatchingTable[(&data_ov000_021b0678[0][0] + cur * 2)[j]], 0, a);
    }
    func_02124b1c((Unk02124b1c *) ((u32) gWiFiVSMatching->mWiFiVSMatchingTable + e), c, b);
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x1e && gWiFiVSMatching->mUnk_08 >= 0x28) {
        gWiFiVSMatching->mUnk_08 = 0;
        if (gWiFiVSMatching->mCurrentOtherIndex == gWiFiVSMatching->mOtherCount - 1) {
            gWiFiVSMatching->mNextState = 8;
            return;
        }
        gWiFiVSMatching->mCurrentOtherIndex = gWiFiVSMatching->mCurrentOtherIndex + 1;
        gWiFiVSMatching->mNextState = 5;
    }
}

void AdvanceWiFiVSMatchingState5(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    if (gWiFiVSMatching->mUnk_08 >= 0x50) {
        gWiFiVSMatching->mNextState = 4;
        gWiFiVSMatching->mUnk_08 = 0;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x20b);
    }
}

void AdvanceWiFiVSMatchingState8(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    // mUnk_30 is 1 to 3 here and indexes the table from 1.
    if (gWiFiVSMatching->mUnk_08 >= (data_ov000_021b0680 - 1)[gWiFiVSMatching->mOtherCount]) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            gWiFiVSMatching->mNextState = 11;
            gWiFiVSMatching->mPendingWiFiState = 4;
            gWiFiVSMatching->mUnk_08 = 0;
            RequestTxtSystemClose();
            StartFadeToFadedNegative(30);
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x20c);
        }
    }
}

void AdvanceWiFiVSMatchingState9(void) {
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
                                                                data_02175628[idx].mUnk_4a) == FALSE) {
                return;
            }
        }
        gWiFiVSMatching->mNextState = 10;
        gWiFiVSMatching->mPendingWiFiState = 2;
        func_02128310(0);
        RequestTxtSystemClose();
    }
}

void AdvanceWiFiVSMatchingState10(void) {
    gWiFiVSMatching->mUnk_08 = gWiFiVSMatching->mUnk_08 + 1;
    gWiFiVSMatching->mOffset = InterpolateS16(1, 0, 0x100, gWiFiVSMatching->mUnk_08, 10);
    if (gWiFiVSMatching->mUnk_08 >= 10) {
        gWiFiVSMatching->mUnk_08 = 10;
    }
    if (func_02125f88() != 0 && IsSelectReturnState2NoState3Or4Request() != 0 && gWiFiVSMatching->mUnk_08 >= 10) {
        if (gWiFiVSMatching->mUnk_40 != FALSE) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
            return;
        }
        if (func_0212137c() != FALSE) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiVSMatchingState11(void) {
    if (AreBrightnessFadesFaded() != 0) {
        if (func_02125f88() != 0) {
            RequestWiFiState(gWiFiVSMatching->mPendingWiFiState);
        }
    }
}

void func_ov000_02183548(void) {
    s32 i;
    u32 base = gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            gWiFiVSMatching->mWiFiVSMatchingTable[data_ov000_021b068c[i][j]].mUnk_04 = gWiFiVSMatching->mOffset;
        }
    }
    for (i = 0; i < 3; i++) {
        (gWiFiVSMatching->mWiFiVSMatchingTable + base)[data_ov000_021b0664[i]].mUnk_04 =
            gWiFiVSMatching->mOffset + gWiFiVSMatching->mUnk_18[i];
        (gWiFiVSMatching->mWiFiVSMatchingTable + base)[data_ov000_021b0660[i]].mUnk_04 = gWiFiVSMatching->mOffset;
        for (j = 0; j < 2; j++) {
            (gWiFiVSMatching->mWiFiVSMatchingTable + base)[data_ov000_021b0670[i][j]].mUnk_04 =
                gWiFiVSMatching->mOffset - gWiFiVSMatching->mUnk_18[i];
        }
    }
    (gWiFiVSMatching->mWiFiVSMatchingTable + base)[12].mUnk_04 = gWiFiVSMatching->mOffset;
}

void func_ov000_021834b0(s32 t) {
    s32 i;

    for (i = 0; i < 5; i++) {
        WiFiVSMatching *p = gWiFiVSMatching;

        p->mBlendedColors[i] = ((((0x1000 - t) * p->mFromChannels[i][2] + t * p->mToChannels[i][2]) >> 12) << 10) |
                               ((((0x1000 - t) * p->mFromChannels[i][0] + t * p->mToChannels[i][0]) >> 12) |
                                ((((0x1000 - t) * p->mFromChannels[i][1] + t * p->mToChannels[i][1]) >> 12) << 5));
    }
    CallQueueAppend(0x1e, 0x36, gWiFiVSMatching->mBlendedColors, 10);
}

void func_ov000_02183444(void) {
    s32 t;

    if (gWiFiVSMatching->mState == 8 || gWiFiVSMatching->mState == 11) {
        gWiFiVSMatching->mBlendFrames = gWiFiVSMatching->mBlendFrames + 1;
        if (gWiFiVSMatching->mBlendFrames >= 0x3c) {
            gWiFiVSMatching->mBlendFrames = 0;
        }
        t = gWiFiVSMatching->mBlendFrames;
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
            AdvanceWiFiVSMatchingState0();
            break;
        case 1:
            AdvanceWiFiVSMatchingState1();
            break;
        case 2:
            AdvanceWiFiVSMatchingState2();
            break;
        case 3:
            AdvanceWiFiVSMatchingState3();
            break;
        case 4:
            AdvanceWiFiVSMatchingState4();
            break;
        case 5:
            AdvanceWiFiVSMatchingState5();
            break;
        case 8:
            AdvanceWiFiVSMatchingState8();
            break;
        case 9:
            AdvanceWiFiVSMatchingState9();
            break;
        case 10:
            AdvanceWiFiVSMatchingState10();
            break;
        case 11:
            AdvanceWiFiVSMatchingState11();
            break;
    }
    func_ov000_02183548();
    func_ov000_02183444();
    func_02124c30(gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                  gWiFiVSMatching->mWiFiVSMatchingBnll, func_ov000_021804e0(), gWiFiVSMatching->mWiFiVSMatchingTable);
}

void func_ov000_02183330(void) {
    s32 x;
    u32 plane;

    plane = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & 0xffffe0ff) | ((plane | 8) << 8);
    x = -gWiFiVSMatching->mOffset;
    if (x <= -0x100) {
        x = -0x100;
    }
    if (x >= 0x100) {
        x = 0x100;
    }
    (reg_G2S_DB_BG3OFS) = x & 0x1ff;
}

void RegisterWiFiVSMatchingCallbacks(void) {
    WiFiStateCallbacks x = {InitWiFiVSMatching, func_ov000_02184354, AdvanceWiFiVSMatching, func_ov000_02183330};

    SetWiFiStateCallbacks(&x);
}
