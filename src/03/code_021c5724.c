#include "03/code_021c5724.h"

#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf698.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "registers.h"
#include "code_02147cd8.h"
#include "03/code_021d3254.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cbf60.h"
#include "03/code_021cef90.h"
#include "03/code_021d1440.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d6000.h"
#include "03/code_021c6000.h"
#include "03/code_021c2000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021c209c.h"
#include "03/code_021cb000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/code_021cd0d0.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021bf000.h"
#include "03/code_021c5000.h"
#include "03/code_021ce000.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c5548.h"
#include "03/code_021d2940.h"
#include "03/code_021bf810.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021d1c18.h"
#include "03/code_021c6764.h"
#include "03/code_021ca56c.h"
#include "03/code_021cce78.h"

void CreateApList(void) {
    s32 a;
    gApList = func_ov003_021d283c(0x5c, 4);
    func_ov003_021c20dc(&a, NULL);
    if (a == 0) {
        gApListSelectedRow = 0;
        *(u16 *) &gApListScrollY = 0;
    }
    gApList->mEntryCount = func_ov003_021cd0d0((s32 *) gApList);
    LoadApListFilesAndSetBgCnt();
    LoadHlSetScr();
    func_ov003_021bf43c(0x80, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021c6508();
    func_ov003_021c6400();
    gApList->mUnk_0c = func_ov003_021d2288(0, 0);
    gApList->mBgOffsetTask = func_ov003_021d3544(1, WriteApListBgOffset, NULL, 0x6e);
    RefreshApList();
    func_ov003_021c590c();
    func_ov003_021c212c(func_ov003_021c63c4);
}

void LoadApListFilesAndSetBgCnt(void) {
    u8 a[0x19] = "char/xb4ApListBack.nsc.l";
    u8 b[0x16] = "char/ybBgStep31.ncl.l";
    LoadFileToVram(gJb4ApListNscName, GX_LoadBG3Scr);
    gApList->mXb4ApListBackNsc = func_ov003_021d14b8(BuildFilePathWithLanguage(a), NULL, 4);
    func_ov003_021cca30(gApList->mXb4ApListBackNsc);
    func_ov003_021cc9fc();
    gApList->mYbBgStep31Ncl = func_ov003_021d14b8(BuildFilePathWithLanguage(b), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 2;
}

void func_ov003_021c6508(void) {
    int a;
    u32 b;
    b = 0;
    gApList->mScrollYMax = (gApList->mEntryCount - 4) * 0x1c;
    if (gApList->mEntryCount <= 4) {
        a = 0;
        gApList->mUnk_53 = 0;
    } else if (gApList->mEntryCount <= 8) {
        a = 1;
        gApList->mUnk_53 = 0x1f;
    } else {
        a = 2;
        gApList->mUnk_53 = 0x37;
    }
    if (a != 0) {
        b = FX_DivS32(*(u16 *) &gApListScrollY * gApList->mUnk_53, gApList->mScrollYMax);
    }
    func_ov003_021ccea4(a, 0x55, 0xec, 0x3f, b);
}

void func_ov003_021c6400(void) {
    int n;
    int i;
    u32 j;
    n = gApList->mEntryCount;
    if (n > 5) {
        n = 5;
    }
    for (i = 0; i < n; i++) {
        gApList->mUnk_10[i] = func_ov003_021d1c18(0, data_ov003_021d6388[0]);
        gApList->mUnk_24[i] = func_ov003_021d1c18(0, data_ov003_021d638c[0]);
    }
    for (j = 0; j < 3; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d6388[j], (u8 *) gApList->mUnk_10[0]);
        gApList->mUnk_42[j] = gApList->mUnk_10[0]->mUnk_04 & 0x3ff;
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d1c3c(0, data_ov003_021d638c[j], (u8 *) gApList->mUnk_24[0]);
        gApList->mUnk_48[j] = gApList->mUnk_24[0]->mUnk_04 & 0x3ff;
    }
    for (i = 0; i < n; i++) {
        Unk021da104_04 *q;
        q = gApList->mUnk_10[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
        q = gApList->mUnk_24[i];
        q->mUnk_04 = (q->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
}

void func_ov003_021c63c4(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x1d, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x1d);
    func_ov003_021c212c(func_ov003_021c6394);
}

void func_ov003_021c6394(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c6370);
    }
}

void func_ov003_021c6370(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateApList);
    }
}

void UpdateApList(void) {
    func_ov003_021c6184();
    func_ov003_021c5f9c();
    func_ov003_021c5ec4();
}

void func_ov003_021c6184(void) {
    int i;
    Rect *p;
    if (gApList->mScrollTask != 0) {
        return;
    }
    if (gApList->mUnk_57 != 0) {
        return;
    }
    if (func_ov003_021d2a34(&data_ov003_021d67e8) != 0) {
        i = 0;
        gApList->mHitRow = -1;
        p = gApListRowRects;
        do {
            if (func_ov003_021d2a34(p) != 0) {
                if (i < 4) {
                    gApList->mHitRow = i;
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while ((u32) i < 5);
    }
    if (func_ov003_021d299c(&data_ov003_021d67e8) != 0) {
        i = 0;
        p = gApListRowRects;
        do {
            if (func_ov003_021d299c(p) != 0) {
                if (gApList->mHitRow != i) {
                    break;
                }
                if (i >= gApList->mEntryCount) {
                    StartSoundSeq(9);
                    break;
                }
                SetButtonResultIfNone(1);
                gApListSelectedRow = i;
                func_ov003_021c590c();
                return;
            }
            p++;
            i++;
        } while (i < 4);
    }
    if (func_ov003_021d2b04(1) != 0) {
        SetButtonResultIfNone(1);
        func_ov003_021cce38();
        return;
    }
    if (func_ov003_021d2b04(2) != 0) {
        SetButtonResultIfNone(0);
        return;
    }
    if (func_ov003_021d2ae8(0x200) != 0) {
        StartApListScrollYIncrease();
        return;
    }
    if (func_ov003_021d2acc(0x200) != 0) {
        gApList->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x100) != 0) {
        StartApListScrollYDecrease();
        return;
    }
    if (func_ov003_021d2acc(0x100) != 0) {
        gApList->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        MoveApListSelectedRow(1);
        return;
    }
    if (func_ov003_021d2acc(0x40) != 0) {
        gApList->mUnk_59 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        MoveApListSelectedRow(3);
        return;
    }
    if (func_ov003_021d2acc(0x80) != 0) {
        gApList->mUnk_59 = 0;
    }
}

void func_ov003_021c5f9c(void) {
    ApList *s;
    int a;
    s = gApList;
    if (s->mScrollTask != 0) {
        return;
    }
    if (s->mScrollTimer != 0) {
        s->mScrollTimer--;
    }
    switch (func_ov003_021cce60()) {
        case 1:
            gApList->mUnk_57 = 1;
            DisableButtonTouch();
            break;
        case 2:
            if (gApList->mScrollTimer == 0) {
                ReleaseSelectionObjectSlots();
                *(u16 *) &gApListScrollY = FX_DivS32(gApList->mScrollYMax * func_ov003_021cce6c(), gApList->mUnk_53);
                RefreshApList();
                gApList->mScrollTimer = 4;
            }
            break;
        case 3:
            gApList->mUnk_57 = 0;
            EnableButtonTouch();
            *(u16 *) &gApListScrollY = FX_DivS32(gApList->mScrollYMax * func_ov003_021cce6c(), gApList->mUnk_53);
            StartSoundSeq(0x13);
            RefreshApList();
            a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
            if (a == 0) {
                func_ov003_021c590c();
            } else if (a < 0xe) {
                gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            } else {
                gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 4:
            if (*(u16 *) &gApListScrollY == 0) {
                if (gApList->mUnk_58 == 0) {
                    StartSoundSeq(9);
                    gApList->mUnk_58 = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYDecrease, NULL, 0x78);
            }
            break;
        case 6:
            s = gApList;
            if (s->mEntryCount <= 4 || *(u16 *) &gApListScrollY == s->mScrollYMax) {
                if (s->mUnk_58 == 0) {
                    StartSoundSeq(9);
                    gApList->mUnk_58 = 1;
                }
            } else {
                StartSoundSeq(0x13);
                gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYIncrease, NULL, 0x78);
            }
            break;
        case 5:
        case 7:
            gApList->mUnk_58 = 0;
            break;
    }
}

void func_ov003_021c5ec4(void) {
    int b;
    if (gApList->mScrollTask == 0 && gApList->mUnk_57 == 0) {
        switch (GetButtonResult()) {
            case 0:
                StartSoundSeq(7);
                break;
            case 1:
                if (gApListSelectedRow == 4) {
                    gApList->mUnk_54 = 1;
                    StartSoundSeq(6);
                    func_ov003_021c5724();
                } else {
                    b = gApListSelectedRow + FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
                    if ((gApList->mEntries + b * 0x2a)[0x28] == 2) {
                        StartSoundSeq(9);
                        func_ov003_021cce38();
                        DisableButtonTouch();
                        func_ov003_021cefc0(0x42, 1, 1, -1, 0);
                        func_ov003_021c212c(func_ov003_021c56fc);
                        return;
                    }
                    gApList->mUnk_54 = 1;
                    gApList->mEntryIndex = b;
                    StartSoundSeq(6);
                }
                break;
            default:
                return;
        }
        func_ov003_021c212c(func_ov003_021c5ea4);
    }
}

void func_ov003_021c5ea4(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c5e54);
}

void func_ov003_021c5e54(void) {
    if (func_ov003_021d1f70(1) == 0) {
        if (gApList->mUnk_54 != 0) {
            StartSlideButtonsOut();
        } else {
            DisableButtonTouch();
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x1d, 8);
        func_ov003_021c212c(func_ov003_021c5cdc);
    }
}

void func_ov003_021c5cdc(void) {
    int i;
    ApList *s;
    if (func_ov003_021d1f70(1) != 0) {
        return;
    }
    if (func_ov003_021d1f70(0) != 0) {
        return;
    }
    if (func_ov003_021bf2f0() == 0) {
        return;
    }
    func_ov003_021d34c0(1, gApList->mBgOffsetTask);
    for (i = 0; i < 5; i++) {
        if (gApList->mUnk_10[i] != NULL) {
            func_ov003_021d2f00((u32 *) gApList->mUnk_10[i]);
        }
        if (gApList->mUnk_24[i] != NULL) {
            func_ov003_021d2f00((u32 *) gApList->mUnk_24[i]);
        }
    }
    func_ov003_021d2188(gApList->mUnk_0c);
    func_ov003_021cce78();
    ReleaseSelectionObjectSlots();
    func_ov003_021bf410();
    func_ov003_021cca10();
    func_ov003_021d1490(gApList->mXb4ApListBackNsc);
    func_ov003_021d1490(gApList->mYbBgStep31Ncl);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    s = gApList;
    if (s->mUnk_54 == 0) {
        func_ov003_021cd27c();
        func_ov003_021cd790(func_ov003_021cdb6c()->mUnk_f4);
        func_ov003_021c2120(2, 0);
        func_ov003_021c212c(SetupWay);
    } else if (gApListSelectedRow == 4) {
        func_ov003_021cd27c();
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021ca8e8);
    } else {
        func_ov003_021cdb14(s->mEntries + s->mEntryIndex * 0x2a);
        func_ov003_021c2120(0, 0);
        if ((gApList->mEntries + gApList->mEntryIndex * 0x2a)[0x28] != 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(1, 1);
            func_ov003_021c212c(CreateEdit);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(0, 1);
            func_ov003_021c212c(func_ov003_021cbf60);
        }
    }
    func_ov003_021d2808(&gApList);
}

void RefreshApList(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = FX_DivS32(*(u16 *) &gApListScrollY, 0x1c);
    v4 = gApList->mEntryCount;
    func_ov003_021d2060(gApList->mUnk_0c, 0);
    if (5 < v4) {
        v4 = 5;
    }
    v2 = 0;
    v3 = v1;
    if (v4 > 0) {
        do {
            PrintApListEntryText(v3, v2);
            v2 = v2 + 1;
            v3 = v3 + 1;
        } while (v2 < v4);
    }
    v3 = 0;
    if (v4 > 0) {
        do {
            func_ov003_021c5b34(v1, v3);
            v3 = v3 + 1;
            v1 = v1 + 1;
        } while (v3 < v4);
    }
    func_ov003_021d1fd0(gApList->mUnk_0c);
    RefreshApListRowPositions();
}

void PrintApListEntryText(int param_0, int param_1) {
    u16 a[17];
    int b;
    int c;
    int i;
    int n;
    c = param_0 * 0x2a;
    b = func_ov003_021d3254(gApList->mEntries + c, 0x20);
    param_1 *= 0x1c;
    if (param_0 < gApList->mEntryCount) {
        if (b <= 0x10) {
            param_1 += 6;
        }
        MI_CpuFill8(a, 0, 0x22);
        if (b <= 0x10) {
            n = b;
        } else {
            n = 0x10;
        }
        for (i = 0; i < n; i++) {
            a[i] = (gApList->mEntries + c)[i];
        }
        func_ov003_021d2094(gApList->mUnk_0c, 0xa, param_1, 2, 0xa, a, 1);
        if (b > 0x10) {
            MI_CpuFill8(a, 0, 0x22);
            n = b - 0x10;
            for (i = 0; i < n; i++) {
                a[i] = (gApList->mEntries + c)[i + 0x10];
            }
            param_1 += 0xc;
            func_ov003_021d2094(gApList->mUnk_0c, 0xa, param_1, 2, 0xa, a, 1);
        }
    }
}

void func_ov003_021c5b34(int param_0, int param_1) {
    Unk021da104_04 *p;
    int m;
    if (param_0 < gApList->mEntryCount) {
        p = gApList->mUnk_10[param_1];
        m = param_0 * 0x2a;
        p->mUnk_04 = (p->mUnk_04 & ~0x3ff) | gApList->mUnk_42[*(gApList->mEntries + m + 0x28)];
        p = gApList->mUnk_24[param_1];
        p->mUnk_04 = (p->mUnk_04 & ~0x3ff) | gApList->mUnk_48[*(u16 *) (gApList->mEntries + m + 0x26)];
    }
}

void RefreshApListRowPositions(void) {
    int a;
    int b;
    int i;
    a = 0x36 - FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    b = gApList->mEntryCount;
    if (b > 5) {
        b = 5;
    }
    for (i = 0; i < b; i++, a += 0x1c) {
        Unk021da104_04 *p;
        p = gApList->mUnk_10[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a - 2) & 0xff) | 0xb30000;
        p = gApList->mUnk_24[i];
        p->mUnk_00 = (p->mUnk_00 & 0xfe00ff00) | ((a + 1) & 0xff) | 0xd20000;
    }
    gApList->mBgOffsetPending = 1;
}

void AdvanceApListScrollYDecrease(u32 param_0) {
    int a;
    func_ov003_021cce38();
    ReleaseSelectionObjectSlots();
    if (*(u16 *) &gApListScrollY > 4) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - 4;
    } else {
        *(u16 *) &gApListScrollY = 0;
    }
    a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (a == 0x18) {
        RefreshApList();
        return;
    }
    if (a > 0x18) {
        *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + (0x1c - a);
        a = 0;
    }
    RefreshApListRowPositions();
    if (a == 0) {
        func_ov003_021cce58(FX_DivS32(*(u16 *) &gApListScrollY * gApList->mUnk_53, gApList->mScrollYMax));
        func_ov003_021cce48();
        func_ov003_021c590c();
        gApList->mScrollTask = 0;
        func_ov003_021d34c8(0, param_0);
    }
}

void AdvanceApListScrollYIncrease(u32 param_0) {
    int a;
    func_ov003_021cce38();
    ReleaseSelectionObjectSlots();
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY + 4;
    a = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
    if (a >= 4) {
        RefreshApListRowPositions();
        return;
    }
    *(u16 *) &gApListScrollY = *(u16 *) &gApListScrollY - a;
    RefreshApList();
    func_ov003_021cce58(FX_DivS32(*(u16 *) &gApListScrollY * gApList->mUnk_53, gApList->mScrollYMax));
    func_ov003_021cce48();
    func_ov003_021c590c();
    gApList->mScrollTask = 0;
    func_ov003_021d34c8(0, param_0);
}

void WriteApListBgOffset(void) {
    int v1;
    u32 v2;
    if (gApList->mBgOffsetPending != 0) {
        v1 = FX_ModS32(*(u16 *) &gApListScrollY, 0x1c);
        v2 = (v1 + -0x32) * 0x10000 & (0x01ff0000u);
        reg_G2_BG0OFS = v2;
        reg_G2_BG2OFS = v2;
        gApList->mBgOffsetPending = 0;
    }
}

void func_ov003_021c590c(void) {
    u8 a;
    int b;
    a = gApListSelectedRow;
    if (a < 4) {
        b = 2;
    } else {
        b = 3;
    }
    PlaceSelectionPair(b, data_ov003_021d63b8[a * 4], data_ov003_021d63bc[a * 4], data_ov003_021d63ba[a * 4]);
}

void MoveApListSelectedRow(int param_0) {
    BOOL a;
    u8 v;
    a = TRUE;
    v = gApListSelectedRow;
    switch (v) {
        case 0:
            if (param_0 == 1) {
                if (*(u16 *) &gApListScrollY == 0) {
                    gApListSelectedRow = 4;
                } else {
                    StartSoundSeq(0x13);
                    gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYDecrease, NULL, 0x78);
                    return;
                }
            } else if (gApList->mEntryCount > 1) {
                gApListSelectedRow = v + 1;
            } else {
                a = FALSE;
            }
            break;
        case 1:
        case 2:
            if (param_0 == 1) {
                gApListSelectedRow = v - 1;
            } else if (gApList->mEntryCount > v + 1) {
                gApListSelectedRow++;
            } else {
                a = FALSE;
            }
            break;
        case 3:
            if (param_0 == 1) {
                gApListSelectedRow = v - 1;
            } else {
                StartApListScrollYIncrease();
                return;
            }
            break;
        case 4:
            if (param_0 == 1) {
                a = FALSE;
            } else {
                *(u16 *) &gApListScrollY = 0;
                gApListSelectedRow = 0;
                RefreshApList();
                func_ov003_021cce58(0);
            }
            break;
    }
    if (a == FALSE) {
        if (gApList->mUnk_59 == 0) {
            StartSoundSeq(9);
            gApList->mUnk_59 = 1;
        }
    } else {
        StartSoundSeq(8);
        func_ov003_021c590c();
    }
}

void StartApListScrollYDecrease(void) {
    if (*(u16 *) &gApListScrollY == 0) {
        if (gApList->mUnk_59 == 0) {
            StartSoundSeq(9);
            gApList->mUnk_59 = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYDecrease, NULL, 0x78);
    }
}

void StartApListScrollYIncrease(void) {
    if (*(u16 *) &gApListScrollY == gApList->mScrollYMax || gApList->mEntryCount <= 4) {
        if (gApList->mUnk_59 == 0) {
            StartSoundSeq(9);
            gApList->mUnk_59 = 1;
        }
    } else {
        StartSoundSeq(0x13);
        gApList->mScrollTask = func_ov003_021d3544(0, AdvanceApListScrollYIncrease, NULL, 0x78);
    }
}

// placeholder: the original keeps the byte at a stack offset between its load and the call; the volatile
// local reproduces that.
void func_ov003_021c5724(void) {
    volatile u8 a;
    u8 b;
    a = data_ov003_021d7228[0];
    b = a;
    func_ov003_021cc948(gApList->mYbBgStep31Ncl, b, b);
}
