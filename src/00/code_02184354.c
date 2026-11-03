#include "00/code_02184354.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02029890.h"
#include "code_02148ca0.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "registers.h"

void func_ov000_02184354(void) {
    u32 a;
    func_0210895c();
    a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((a & ~8) << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0xf00;
    gWiFiVSMatching = NULL;
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
    gWiFiVSMatching = func_02036bec(a, 0x170c);
    gWiFiVSMatching->mUnk_d0 = a;
    gWiFiVSMatching->mState = 0;
    gWiFiVSMatching->mNextState = 0;
    gWiFiVSMatching->mUnk_20 = -1;
    gWiFiVSMatching->mUnk_08 = 0;
    gWiFiVSMatching->mUnk_0c = 0;
    gWiFiVSMatching->mUnk_38 = 0;
    for (i = 0; i < 3; i++) {
        gWiFiVSMatching->mUnk_24[i] = 0;
    }
    gWiFiVSMatching->mUnk_40 = 0;
    func_ov000_02184130();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mWiFiVSMatchingBnll,
                  &gWiFiVSMatching->mUnk_10d4);
    gWiFiVSMatching->mWiFiMessages = FindSceneFile(data_ov000_021b0e18);
    gWiFiVSMatching->mCommonMessages = func_02047a28(data_ov000_021b0e24);
    func_ov000_02184670();
    i = 0;
    r = &data_ov000_021b068c[0][0];
    p1 = data_ov000_021b0668;
    p2 = data_ov000_021b0664;
    p3 = &data_ov000_021b0670[0][0];
    p4 = data_ov000_021b066c;
    for (; i < 3; i++) {
        for (k = 0; k < 5; k++) {
            gWiFiVSMatching->mUnk_10d4[r[k]].mUnk_00 = 0;
        }
        gWiFiVSMatching->mUnk_10d4[*p1].mUnk_00 = 1;
        gWiFiVSMatching->mUnk_10d4[*p2 + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06].mUnk_00 = 0;
        for (k = 0; k < 2; k++) {
            c = p3[k];
            gWiFiVSMatching->mUnk_10d4[c + gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06].mUnk_00 = 0;
        }
        gWiFiVSMatching->mUnk_10d4[*p4].mUnk_00 = 1;
        r += 5;
        p1++;
        p2++;
        p3 += 2;
        p4++;
    }
    gWiFiVSMatching->mUnk_10 = 0x100;
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
    gWiFiVSMatching->mUnk_48 = 0;
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
            gWiFiVSMatching->mUnk_10d4[r[j]].mUnk_10 = 1;
            gWiFiVSMatching->mUnk_10d4[x + p[j]].mUnk_10 = 1;
            func_02124b1c(&gWiFiVSMatching->mUnk_10d4[r[j]], 0, 0x1000);
        }
        gWiFiVSMatching->mUnk_10d4[*q].mUnk_10 = 1;
        func_02124b1c(&gWiFiVSMatching->mUnk_10d4[*q], 0, 0x1000);
        r += 2;
        p += 2;
        q++;
    }
}

void func_ov000_02184670(void) {
    s32 n;
    u32 q;
    s32 i;

    n = func_02148ca0();
    {
        u8 b[3][2] = {{0x78, 0x10}, {0x78, 0x10}, {0x78, 0x10}};
        u8 *t1 = &b[0][0];
        u8 *t2;
        u8 *t3;

        for (i = 0, t2 = data_ov000_021b066c, t3 = data_ov000_021b0664; i < 3; i++) {
            n -= func_021243ac(gWiFiVSMatching->mUnk_d0, *t3, gWiFiVSMatching->mWiFiVSMatchingBnll, t1[0], t1[1], *t2,
                               gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                               gWiFiVSMatching->mUnk_10d4, n);
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
                n -= func_021243ac(gWiFiVSMatching->mUnk_d0, data_ov000_021b0670[i][j],
                                   gWiFiVSMatching->mWiFiVSMatchingBnll, e[i][j][0], e[i][j][1],
                                   data_ov000_021b0678[i][j], gWiFiVSMatching->mWiFiVSMatchingSNcer,
                                   gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4, n);
            }
        }
    }
    {
        void *p;
        Unk021b4c74 *g;
        u8 c[3][2] = {{0x78, 0x20}, {0x78, 0x20}, {0x78, 0x20}};
        u8 *w = &c[0][0];
        u8 *t1;
        u8 *t2;

        for (i = 0, t1 = data_ov000_021b0668, t2 = data_ov000_021b0660; i < 3; i++) {
            n -= func_021243ac(gWiFiVSMatching->mUnk_d0, *t2, gWiFiVSMatching->mWiFiVSMatchingBnll, w[0], w[1], *t1,
                               gWiFiVSMatching->mWiFiVSMatchingSNcer, gWiFiVSMatching->mWiFiVSMatchingBncl,
                               gWiFiVSMatching->mUnk_10d4, n);
            g = gWiFiVSMatching;
            p = GetBmgEntry(g->mWiFiMessages, 9);
            func_0212426c(1, *t2, gWiFiVSMatching->mWiFiVSMatchingBnll, p, g->mWiFiVSMatchingBncl, g->mUnk_10d4);
            t1++;
            w += 2;
            t2++;
        }
    }
    {
        u8 a[2] = {0xa0, 0x10};

        q = LookupWiFiVSSettingMessageIndex(GetWiFiVSSettingIndex());
        func_021243ac(gWiFiVSMatching->mUnk_d0, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll, a[0], a[1],
                      gWiFiVSMatching->mWiFiVSMatchingBncl->mUnk_06, gWiFiVSMatching->mWiFiVSMatchingSNcer,
                      gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4, n);
        func_0212426c(1, 0xc, gWiFiVSMatching->mWiFiVSMatchingBnll, GetBmgEntry(gWiFiVSMatching->mWiFiMessages, q),
                      gWiFiVSMatching->mWiFiVSMatchingBncl, gWiFiVSMatching->mUnk_10d4);
    }
}
