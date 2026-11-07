#include "Main/Unknown/code_0202ccc0.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02036000.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02108c04.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0204ee64.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02025cd0.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204ea94.h"
#include "Main/Unknown/code_0204f240.h"
#include "registers.h"

#pragma thumb on

void func_0202d868(s32 a, s32 b, s32 c, s32 d) {
    Unk0202de00_g t;
    s16 s[10];
    Unk02174e14_00 *p;
    s32 i;
    s32 j;
    s32 k;
    p = &gTimeAttackGhostSend->mUnk_050[1];
    if (a == 1) {
        func_0212426c(1, b, p->mUnk_14,
                      GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, func_02025d74(func_0202db04(c))), p->mUnk_0c,
                      p->mUnk_18);
        func_0202dcf4(c, &t);
        func_02025cd0(s, t.mUnk_02, t.mUnk_03, t.mUnk_00);
        func_02124224(1, b + 7, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 7);
        j = func_0202dd80(c) == 0;
        p->mUnk_18[b].mUnk_00 = j;
        k = j == 0;
        p->mUnk_18[b + 7].mUnk_00 = k;
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            j = i + 7;
            if (i == d) {
                k = 0xe;
            } else {
                k = 0xf;
            }
            func_02124100(i, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
            func_02124100(j, k, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
    } else if (a == 2) {
        if (c >= 0 && c < (s32) func_0202ddc4()) {
            j = func_0202dd80(c) == 0;
            p->mUnk_18[b].mUnk_00 = j;
            k = j == 0;
            p->mUnk_18[b + 7].mUnk_00 = k;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_0202d82c(void) {
    void *v1;
    void *v2;
    v1 = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0xd);
    v2 = GetBmgEntry(gTimeAttackGhostSend->mCommonMessages, 4);
    gTimeAttackGhostSend->mState = 8;
    func_02126230(v1, v2);
}

#pragma thumb off

#pragma thumb on

void func_0202d720(void) {
    u16 s[6];
    Unk02174e14_00 *p;
    s32 n;
    p = &gTimeAttackGhostSend->mUnk_050[1];
    func_0212426c(1, 0xe, p->mUnk_14, GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x56), p->mUnk_0c, p->mUnk_18);
    func_0212426c(1, 0xf, p->mUnk_14, GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x57), p->mUnk_0c, p->mUnk_18);
    n = func_0202ddb0();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '3';
    s[4] = '2';
    s[5] = 0;
    func_02124224(1, 0x10, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
    n = func_0202dd9c();
    if (n < 10) {
        s[0] = ' ';
    } else {
        s[0] = n / 10 % 10 + '0';
    }
    s[1] = n % 10 + '0';
    s[2] = '/';
    s[3] = '1';
    s[4] = '0';
    s[5] = 0;
    func_02124224(1, 0x11, p->mUnk_14, s, p->mUnk_0c, p->mUnk_18, 6);
}

void func_0202d6a0(void) {
    Unk0202de00_g t;
    u16 n[10];
    u16 m[11];
    s32 a;
    s32 b;
    func_0202dcf4(gTimeAttackGhostSend->mUnk_0a4, &t);
    func_0202dc68(gTimeAttackGhostSend->mUnk_0a4, n);
    MIi_CpuCopy16(n, m, 0x14);
    m[10] = 0;
    a = func_0202dbe8(gTimeAttackGhostSend->mUnk_0a4);
    b = func_0202db68(gTimeAttackGhostSend->mUnk_0a4);
    func_0202de00((Unk02174e14 *) gTimeAttackGhostSend->mUnk_050, data_usa_02153bec, m, a, b,
                  func_0202db04(gTimeAttackGhostSend->mUnk_0a4), &t);
}

#pragma thumb off

#pragma thumb on

void func_0202d674(void) {
    void *v1;
    v1 = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0);
    func_0212658c(v1, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void func_0202d5f8(s32 a, s32 b) {
    u16 x[11];
    u16 y[0x100];
    void *r;
    r = GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, a);
    MIi_CpuCopy16(gTimeAttackGhostSend->mUnk_0b8, x, 0x14);
    x[10] = 0;
    func_0212513c(x, r, y, 0x100);
    if (b != 0) {
        func_02126230(y, GetBmgEntry(gTimeAttackGhostSend->mCommonMessages, 4));
    } else {
        SetupTxtSystemSubText(y);
    }
}

void func_0202d5c0(void) {
    func_0202daa4(gTimeAttackGhostSend->mUnk_0a4);
    SetupTxtSystemSubText(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 9));
    SetSelectReturnSoundId(0xe);
    RequestSelectReturnState4();
}

void func_0202d554(void) {
    Unk02174e14_00 *p;
    Unk02174e14_00 *q;
    s32 n;
    s32 m;
    s32 i;
    s16 k;
    p = &gTimeAttackGhostSend->mUnk_050[0];
    q = &gTimeAttackGhostSend->mUnk_050[1];
    n = p->mUnk_0c->mUnk_06 + p->mUnk_14->mUnk_06;
    m = q->mUnk_0c->mUnk_06 + q->mUnk_14->mUnk_06;
    k = func_02025ebc(&gTimeAttackGhostSend->mUnk_0cc);
    for (i = 0; i < n; i++) {
        p->mUnk_18[i].mUnk_06 = -k;
    }
    for (i = 0; i < m; i++) {
        q->mUnk_18[i].mUnk_06 = k;
    }
}

void InitTimeAttackGhostSend(void *a, void *b, void *c) {
    s16 r[4];
    s32 j;
    s32 k;
    Unk02124b1c *u;
    Unk02174e14_00 *p;
    Unk02174e14_00 *q;
    void *h;
    s32 i;
    s32 n;
    s32 w;
    s32 m;
    h = CreateFrmHeapFromMaxFree(a);
    gTimeAttackGhostSend = HeapAlloc(h, 0xe0);
    MemFillWordsByBlock_inline(gTimeAttackGhostSend, 0xe0);
    gTimeAttackGhostSend->mHeap = h;
    gTimeAttackGhostSend->mUnk_048[0] = b;
    gTimeAttackGhostSend->mUnk_048[1] = c;
    gTimeAttackGhostSend->mCommonMessages = FindFileInLoadedArchives(data_usa_02162d04);
    gTimeAttackGhostSend->mGhostMessages = FindSceneFile(gGhostBmgName);
    func_0204f240(gTimeAttackGhostSend->mHeap, 2);
    func_020258d4(0, gTimeAttackGhostSend, gTimeAttackGhostSendMBNcgrName, gTimeAttackGhostSendMBNclrName,
                  gTimeAttackGhostSendMNscrName, 0, FindSceneFile);
    p = &gTimeAttackGhostSend->mUnk_050[0];
    n = GX_GetSizeOfOBJ();
    func_02025b20(p, gTimeAttackGhostSendMNcgrName, gTimeAttackGhostSendMNcerName, gTimeAttackGhostSendMONclrName,
                  gTimeAttackGhostSendMBnclName, gTimeAttackGhostSendMBnllName, NULL, FindSceneFile);
    func_02025a50(0, gTimeAttackGhostSend->mHeap, p);
    for (i = 0; i < p->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(0, gTimeAttackGhostSend->mHeap, p, data_usa_02153bec[i], n);
    }
    func_020258d4(1, &gTimeAttackGhostSend->mUnk_024, gTimeAttackGhostSendSBNcgrName, gTimeAttackGhostSendSBNclrName,
                  gTimeAttackGhostSendSNscrName, 3, FindSceneFile);
    q = &gTimeAttackGhostSend->mUnk_050[1];
    n = GX_GetSizeOfSubOBJ();
    m = 0;
    func_02025b20(q, gTimeAttackGhostSendSNcgrName, gTimeAttackGhostSendSNcerName, gTimeAttackGhostSendSONclrName,
                  gTimeAttackGhostSendSBnclName, gTimeAttackGhostSendSBnllName, gTimeAttackGhostSendSBnblName,
                  FindSceneFile);
    func_02025a50(1, gTimeAttackGhostSend->mHeap, q);
    w = q->mUnk_0c->mUnk_06;
    for (i = 0; i < q->mUnk_14->mUnk_06; i++) {
        if (data_usa_02162c74[i][3] < 0) {
            data_usa_02162c74[i][3] = w + m++;
        }
        n -= func_02025a00(1, gTimeAttackGhostSend->mHeap, q, (s16(*)[4]) data_usa_02162c74 + i, n);
    }
    func_0202d720();
    for (i = 0; i < 0xf; i++) {
        func_021249a8(i, 3, q->mUnk_08, q->mUnk_0c);
    }
    for (i = 0; i < 0xe; i++) {
        func_02124094(i, 2, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
    }
    for (i = 0; i < 0xe; i++) {
        j = data_usa_02162c74[i][3];
        k = data_usa_02162c74[i][0];
        u = q->mUnk_18;
        func_02025c1c(j, &u[j], q->mUnk_0c);
        func_02025bf0(k, u + w + k, q->mUnk_14);
    }
    func_02025c1c(0xe, (u8 *) q->mUnk_18 + 0x380, q->mUnk_0c);
    if (func_0202ddc4() != 0) {
        Unk02174e40_24 *s = &gTimeAttackGhostSend->mUnk_024;
        r[0] = 0;
        r[1] = 7;
        r[2] = w;
        r[3] = w + 7;
        func_0202e530(gTimeAttackGhostSend->mHeap, 4, r, 0xe, 0xf, 0x7c, q->mUnk_18, q->mUnk_10, s->mUnk_20 + 0xc, 0, 1,
                      2, func_0202ddc4(), func_0202d868);
    } else {
        for (i = 0; i < w; i++) {
            q->mUnk_18[i].mUnk_00 = 0;
        }
        for (i = 0; i < 0xe; i++) {
            q->mUnk_18[w + i].mUnk_00 = 0;
        }
    }
    func_02025b84(0, &gTimeAttackGhostSend->mUnk_050[2]);
    func_02025f80(&gTimeAttackGhostSend->mUnk_0cc, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    func_0204f804();
    gTimeAttackGhostSend->mState = 1;
    FrmHeapShrinkInParent(gTimeAttackGhostSend->mHeap);
}

s32 AdvanceTimeAttackGhostSend(Unk0202cdf4 *p) {
    u16 e;
    s32 b;
    s32 a;
    s32 c;
    s32 x;
    u16 t;
    Unk021759d4 *d;
    Unk02174e14_00 *q;
    s32 i;
    e = func_020435bc();
    c = 0;
    func_02025edc(&gTimeAttackGhostSend->mUnk_0cc);
    b = c;
    a = b;
    x = data_02175628[e].mHasPair;
    if (x == 0 && data_02175628[e].mNoPairCount < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[e].mPrevHasPair == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        c = IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[e].mUnk_48, data_02175628[e].mUnk_4a);
    }
    switch (gTimeAttackGhostSend->mState) {
        case 0:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (p != NULL) {
                    p->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 1:
            if (AreBrightnessFadesClear() == 0) {
                if (func_0202ddc4() == 0) {
                    func_02126230(GetBmgEntry(gTimeAttackGhostSend->mGhostMessages, 0x53),
                                  GetBmgEntry(gTimeAttackGhostSend->mCommonMessages, 4));
                    gTimeAttackGhostSend->mState = 0;
                } else {
                    func_0202d6a0();
                    func_0202d674();
                    RequestSelectReturnState1();
                    func_02025f14(&gTimeAttackGhostSend->mUnk_0cc, 0);
                    gTimeAttackGhostSend->mState = 2;
                }
            }
            break;
        case 2:
            if (gTimeAttackGhostSend->mUnk_0cc.mUnk_00 == 1) {
                gTimeAttackGhostSend->mUnk_0b4 = 0;
                gTimeAttackGhostSend->mState = 3;
            } else {
                func_0202d554();
            }
            break;
        case 3:
            if (func_02125fa4() != 0) {
                func_0202e4b0();
                i = func_0202e4a4();
                if (gTimeAttackGhostSend->mUnk_0a4 != i) {
                    gTimeAttackGhostSend->mUnk_0a4 = i;
                    func_0202d6a0();
                }
                if (func_0202e468() != 0) {
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                }
                if (func_0202e47c() != 0) {
                    func_0202d5c0();
                    func_02108c1c();
                    gTimeAttackGhostSend->mState = 4;
                } else {
                    t = data_02175628[e].mUnk_00 & 2;
                    if (t != 0 || c != 0) {
                        data_0217b488->mUnk_08 = 5;
                        if (p != NULL) {
                            p->mUnk_04 = 1;
                        }
                        gTimeAttackGhostSend->mState = 0xe;
                        RequestSelectReturnState3WithSound(0);
                    }
                }
            }
            break;
        case 4:
            d = data_021759d4;
            if (d->mUnk_0c != 0) {
                i = d->mUnk_10;
            } else {
                i = 0;
            }
            if (i == 0 && d->mUnk_04 == NULL) {
                if (func_0202dd80(gTimeAttackGhostSend->mUnk_0a4) == 0) {
                    func_0203bf04(func_0202ddec(), (void *) func_0202ddd8());
                }
                gTimeAttackGhostSend->mState = 5;
            }
            break;
        case 5:
            i = func_02054c98(1, (void *) func_0202ddd8());
            switch (i) {
                case 1:
                    func_0204f5e4();
                    func_0204eeac((void *) func_0202ddd8(), 0x1000);
                    RequestSelectReturnState1();
                    gTimeAttackGhostSend->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            t = data_02175628[e].mUnk_00 & 2;
            if (t != 0 || c != 0) {
                RequestSelectReturnState3WithSound(0);
                SetSelectReturnSoundId(0xf);
                func_02108c04();
                gTimeAttackGhostSend->mState = 0xb;
            } else if (func_0204eb08(gTimeAttackGhostSend->mUnk_0b8) != 0) {
                RequestSelectReturnState4();
                func_02108c04();
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 9);
                NNS_SndArcSetCurrent(&data_0217d0a0);
                func_0202d5f8(0xb, 0);
                gTimeAttackGhostSend->mState = 7;
            }
            break;
        case 7:
            i = func_0205465c();
            switch (i) {
                case 1:
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xa);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    gTimeAttackGhostSend->mState = 0xa;
                    break;
                case 2:
                    func_0202d82c();
                    break;
            }
            break;
        case 8:
            if (func_02125f6c() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                gTimeAttackGhostSend->mState = 9;
            }
            break;
        case 9:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_0217b488->mUnk_08 = 5;
                if (p != NULL) {
                    p->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
        case 10:
            if (func_02054f58() == 1) {
                func_0204f804();
                func_0202d5f8(0xc, 1);
                gTimeAttackGhostSend->mState = 0xd;
            }
            break;
        case 11:
            if (func_02054f58() == 1) {
                func_0204f804();
                func_0202d674();
                gTimeAttackGhostSend->mState = 3;
            }
            break;
        case 13:
            if (func_02125f54() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (p != NULL) {
                    p->mUnk_04 = 1;
                }
                gTimeAttackGhostSend->mState = 0xe;
            }
            break;
    }
    func_02054aa0();
    for (i = 0; i < 2; i++) {
        q = gTimeAttackGhostSend->mUnk_050;
        func_02124c30(q[i].mUnk_0c, q[i].mUnk_08, q[i].mUnk_14, gTimeAttackGhostSend->mUnk_048[i], q[i].mUnk_18);
    }
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseTimeAttackGhostSend(void) {
    HeapDestroy(gTimeAttackGhostSend->mHeap);
    *(int *) &gTimeAttackGhostSend = 0;
}

#pragma thumb off

#pragma thumb on

void func_0202ccc0(void) {
    s16 a = func_02025ebc(&gTimeAttackGhostSend->mUnk_0cc);
    int b;
    reg_G2_BG0OFS = ((a << 16) & 0x1ff0000);
    b = -a;
    reg_G2S_DB_BG3OFS = ((b << 16) & 0x1ff0000);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    if (a != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((b << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (a + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
