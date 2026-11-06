#include "03/code_021c7d30.h"

#include "03/code_021bf000.h"
#include "03/code_021c209c.h"
#include "03/code_021c7000.h"
#include "03/code_021c2000.h"
#include "03/code_021cd2e0.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021cef90.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c7844.h"
#include "03/code_021c8000.h"
#include "03/code_021c9000.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021cca74.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "code_021510a4.h"
#include "code_02133048.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021d2940.h"
#include "03/code_021cea3c.h"
#include "code_02147cd8.h"
#include "03/code_021cb11c.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cb8d8.h"
#include "03/code_021d1440.h"
#include "03/code_021d1c18.h"
#include "03/code_021c97c0.h"
#include "03/code_021cb000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214cfe4.h"
#include "03/code_021b94b8.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3254.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213c9f8.h"
#include "code_0214d018.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d3000.h"
#include "03/code_021bf810.h"
#include "03/code_021c6764.h"
#include "03/code_021c6f08.h"
#include "03/code_021cce78.h"
#include "registers.h"

void CreateJb3List(void) {
    int a;
    Unk021cd5e0_400 *b;
    int i;
    Jb3List *p;
    b = func_ov003_021cdb6c();
    p = func_ov003_021d283c(0x48, 4);
    gJb3List = p;
    p->mUnk_43 = b->mUnk_f6;
    gJb3List->mReturnId = 0xc;
    func_ov003_021c94c8();
    LoadJb3ListFilesAndSetBgCnt();
    if (*(u8 *) &gJb3ListMode == 0) {
        func_ov003_021bf43c(0x7c, data_ov003_021d6434[func_ov003_021c20d0()], b->mUnk_f4 + 1);
    } else {
        func_ov003_021bf43c(0x97, -1, 0);
    }
    func_ov003_021bf5ec(1);
    LoadHlListScr();
    func_ov003_021ccea4(2, 0x55, 0xf1, 0x41, _s32_div_f(*(u16 *) &gJb3ListScrollY * 0x37, 0x91));
    gJb3List->mUnk_14 = func_ov003_021d2288(0, 1);
    for (i = 0; i < 7; i++) {
        gJb3List->mUnk_18[i] = func_ov003_021d1c18(0, data_ov003_021d6478[0][1]);
    }
    switch (b->mUnk_00.mUnk_e7) {
        case 1:
            gJb3List->mUnk_34 = func_ov003_021d1c18(0, 0x50);
            gJb3List->mUnk_34->mUnk_04 = (gJb3List->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
        case 2:
            gJb3List->mUnk_34 = func_ov003_021d1c18(0, 0x51);
            gJb3List->mUnk_34->mUnk_04 = (gJb3List->mUnk_34->mUnk_04 & ~0xc00) | 0xc00;
            break;
    }
    gJb3List->mBgOffsetTask = func_ov003_021d3544(1, WriteJb3ListBgOffset, NULL, 0x6e);
    gJb3List->mIdTimerTask = func_ov003_021d3544(0, AdvanceJb3ListIdTimers, NULL, 0x78);
    RefreshJb3List();
    func_ov003_021c81b8();
    func_ov003_021c212c(func_ov003_021c948c);
}

void LoadJb3ListFilesAndSetBgCnt(void) {
    Unk021d7410 a;
    Unk021d73e0 b;
    Unk021d73f8 c;
    a = gJb3ListBackNscName;
    b = gYbBgStep2NclName;
    c = gYbBgStep21NclName;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0xe18;
    func_ov003_021bf620(gYbObjKbNclName3, GX_LoadOBJPltt);
    func_ov003_021bf620(gJbBgStep2NcgName, GX_LoadBG3Char);
    func_ov003_021bf620(gJbBgStep21NcgName, GX_LoadBG2Char);
    func_ov003_021bf620(&b, GX_LoadBGPltt);
    func_ov003_021bf620(gJb3ListNscName, GX_LoadBG3Scr);
    gJb3List->mJb3ListBackNsc = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &a), NULL, 4);
    func_ov003_021cca30(gJb3List->mJb3ListBackNsc);
    func_ov003_021cc9fc();
    gJb3List->mYbBgStep2NclFiles[0] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &b), NULL, 4);
    gJb3List->mYbBgStep2NclFiles[1] = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &c), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~0x3) | 0x3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~0x3) | 0x3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~0x3) | 0x3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~0x3) | 0x2;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~0x3) | 0x3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~0x3) | 0x2;
}

void func_ov003_021c94c8(void) {
    int v1[1];
    func_ov003_021cdb6c();
    func_ov003_021c20dc(NULL, v1);
    if (v1[0] == 0) {
        *(u16 *) &gJb3ListScrollY = 0;
        *(u8 *) &gJb3ListSelectedId = 0;
        *(u8 *) &gJb3ListSelectedRow = 0;
    }
    return;
}

void func_ov003_021c948c(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x1d, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x1d);
    func_ov003_021c212c(func_ov003_021c9464);
    return;
}

void func_ov003_021c9464(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021c212c(UpdateJb3List);
    }
}

void UpdateJb3List(void) {
    UpdateJb3ListInput();
    UpdateJb3ListScrollInput();
    return;
}

void UpdateJb3ListInput(void) {
    Jb3List *s;
    s = gJb3List;
    if (s->mScrollTask != 0) {
        return;
    }
    if (s->mUnk_45 != 0) {
        return;
    }
    if (UpdateJb3ListHit() != 0) {
        return;
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021c90dc(gJb3ListSelectedId[0]);
        return;
    }
    if (func_ov003_021d2b04(2) != 0) {
        StartSoundSeq(7);
        gJb3List->mUnk_40 = 0xd;
        func_ov003_021c212c(func_ov003_021c8e80);
        return;
    }
    if (func_ov003_021d2ae8(0x200) != 0) {
        if (*(u16 *) &gJb3ListScrollY == 0x91) {
            if (gJb3List->mUnk_47 != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mUnk_47 = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
        return;
    }
    if (func_ov003_021d2acc(0x200) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x100) != 0) {
        if (*(u16 *) &gJb3ListScrollY == 0) {
            if (gJb3List->mUnk_47 != 0) {
                return;
            }
            StartSoundSeq(9);
            gJb3List->mUnk_47 = 1;
            return;
        }
        StartSoundSeq(0x13);
        gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
        return;
    }
    if (func_ov003_021d2acc(0x100) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        MoveJb3ListSelection(1);
        return;
    }
    if (func_ov003_021d2acc(0x40) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        MoveJb3ListSelection(3);
        return;
    }
    if (func_ov003_021d2acc(0x80) != 0) {
        gJb3List->mUnk_47 = 0;
        return;
    }
    if (func_ov003_021d2ae8(0x20) != 0) {
        MoveJb3ListSelection(0);
        return;
    }
    if (func_ov003_021d2ae8(0x10) != 0) {
        MoveJb3ListSelection(2);
    }
}

u32 UpdateJb3ListHit(void) {
    int v1;
    int v2;
    func_ov003_021cdb6c();
    v1 = GetJb3ListHitId();
    if (v1 == 0xe) {
        return 0;
    }
    v2 = IsJb3ListIdEnabled(v1);
    if (v2 == 0) {
        StartSoundSeq(9);
        return 1;
    }
    SetJb3ListSelectedId(v1);
    switch (v1) {
        case 2:
        case 3:
        case 7:
        case 8:
            StartJb3ListIdTimer();
    }
    func_ov003_021c90dc(v1);
    return 1;
}

void func_ov003_021c90dc(u32 param_1) {
    if (IsJb3ListIdEnabled(param_1) == 0) {
        StartSoundSeq(9);
        return;
    }
    switch (param_1) {
        case 2:
        case 3:
            StartSoundSeq(6);
            func_ov003_021c9084(((param_1 - 2) ^ 1) != 0);
            return;
        case 7:
        case 8:
            StartSoundSeq(6);
            func_ov003_021c9058(((param_1 - 7) ^ 1) != 0);
            return;
    }
    gJb3List->mUnk_40 = param_1;
    if (param_1 - 0xb <= 1) {
        func_ov003_021c7ec4();
        if (func_ov003_021c7d8c() == 0) {
            StartSoundSeq(9);
            func_ov003_021cefc0(0x2f, 1, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c7d58);
            return;
        }
        if (param_1 == 0xb) {
            StartSoundSeq(6);
        } else {
            StartSoundSeq(0xe);
        }
    } else if (param_1 == 0xd) {
        func_ov003_021c7ec4();
        StartSoundSeq(7);
    } else {
        StartSoundSeq(6);
        SetupJb3ListCell(0, 1, GetJb3ListRowOfEntryIndex(gJb3ListEntryIndexById[param_1]));
        RefreshJb3ListRowPositions();
    }
    func_ov003_021cce38();
    func_ov003_021c212c(func_ov003_021c8e80);
}

void func_ov003_021c9084(u32 param_1) {
    Unk021cd5e0_400 *r;
    BOOL a;
    r = func_ov003_021cdb6c();
    if (r->mUnk_f5 != param_1) {
        if (param_1 != 0) {
            if (gJb3List->mUnk_43 != 0) {
                a = TRUE;
            } else {
                a = FALSE;
            }
        } else {
            gJb3List->mUnk_43 = r->mUnk_f6;
            a = FALSE;
        }
        func_ov003_021cdb58(param_1);
        func_ov003_021cdb44(a);
        RefreshJb3List();
    }
}

void func_ov003_021c9058(u32 a) {
    Unk021cd5e0_400 *v1;
    v1 = func_ov003_021cdb6c();
    if (v1->mUnk_f6 != a) {
        gJb3List->mUnk_43 = (s8) a;
        func_ov003_021cdb44(a);
        RefreshJb3List();
    }
    return;
}

void UpdateJb3ListScrollInput(void) {
    int a;
    Jb3List *s;
    s = gJb3List;
    if (s->mScrollTask == 0) {
        if (s->mScrollTimer != 0) {
            s->mScrollTimer--;
        }
        switch (func_ov003_021cce60()) {
            case 1:
                gJb3List->mUnk_45 = 1;
                break;
            case 2:
                if (gJb3List->mScrollTimer != 0) {
                    return;
                }
                func_ov003_021bf698();
                *(u16 *) &gJb3ListScrollY = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                RefreshJb3List();
                gJb3List->mScrollTimer = 4;
                break;
            case 3:
                gJb3List->mUnk_45 = 0;
                *(u16 *) &gJb3ListScrollY = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                StartSoundSeq(0x13);
                RefreshJb3List();
                a = FX_ModS32(*(u16 *) &gJb3ListScrollY, 0x1d);
                if (a == 0) {
                    SetJb3ListSelectedIdFromRow();
                    return;
                }
                if (a < 0x10) {
                    gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                } else {
                    gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                }
                break;
            case 4:
                if (*(u16 *) &gJb3ListScrollY == 0) {
                    if (gJb3List->mUnk_46 != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mUnk_46 = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                }
                break;
            case 6:
                if (*(u16 *) &gJb3ListScrollY == 0x91) {
                    if (gJb3List->mUnk_46 != 0) {
                        return;
                    }
                    StartSoundSeq(9);
                    gJb3List->mUnk_46 = 1;
                } else {
                    StartSoundSeq(0x13);
                    gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                }
                break;
            case 5:
            case 7:
                gJb3List->mUnk_46 = 0;
                break;
        }
    }
}

void func_ov003_021c8e80(void) {
    func_ov003_021cce38();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c8e48);
    return;
}

void func_ov003_021c8e48(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x1d, 8);
        func_ov003_021c212c(func_ov003_021c8c14);
    }
    return;
}

static inline void func_ov003_021c85a0_inline(Unk021da104_04 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021c8c14(void) {
    int i;
    u32 v;
    Unk021cd5e0_400 *r;
    if (func_ov003_021d1f70(1) != 0) {
        return;
    }
    if (func_ov003_021d1f70(0) != 0) {
        return;
    }
    func_ov003_021d34c0(0, gJb3List->mIdTimerTask);
    func_ov003_021d34c0(1, gJb3List->mBgOffsetTask);
    for (i = 0; i < 7; i++) {
        func_ov003_021d2f00((u32 *) gJb3List->mUnk_18[i]);
    }
    if (gJb3List->mUnk_34 != NULL) {
        func_ov003_021d2f00((u32 *) gJb3List->mUnk_34);
    }
    func_ov003_021cce78();
    func_ov003_021d2168(0);
    func_ov003_021bf698();
    if (gJb3List->mUnk_40 != 0xc) {
        func_ov003_021bf410();
    }
    func_ov003_021cca10();
    func_ov003_021d1490(gJb3List->mJb3ListBackNsc);
    for (i = 0; i < 2; i++) {
        func_ov003_021d1490(gJb3List->mYbBgStep2NclFiles[i]);
    }
    func_ov003_021bf620(gYbObjMainNclName4, GX_LoadOBJPltt);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x1d);
    reg_G2_BG0OFS = 0;
    reg_G2_BG2OFS = 0;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0xe10;
    v = gJb3List->mUnk_40;
    switch (v) {
        case 0:
        case 1:
            func_ov003_021c20f8(v, 0);
            func_ov003_021c2120(2, 0);
            func_ov003_021c212c(CreateEdit);
            break;
        case 4:
        case 5:
        case 6:
        case 9:
        case 10:
            i = v - 4;
            if (v >= 9) {
                i -= 2;
            }
            func_ov003_021c2120(2, 0);
            func_ov003_021c20f8(i, 0);
            func_ov003_021c212c(CreateEditAddr);
            break;
        case 11:
            r = func_ov003_021cdb6c();
            r->mUnk_00.mUnk_d0 = DWCi_BACKUPlConvMaskCidr(r->mUnk_f0);
            if (r->mUnk_f5 != 0) {
                MI_CpuFill8(r->mUnk_00.mUnk_c0, 0, 4);
                MI_CpuFill8(r->mUnk_00.mUnk_c4, 0, 4);
                MI_CpuFill8(r->mUnk_f0, 0, 4);
                r->mUnk_00.mUnk_d0 = 0;
            }
            if (r->mUnk_f6 != 0) {
                MI_CpuFill8(r->mUnk_00.mUnk_c8, 0, 8);
            }
            func_ov003_021c2120(2, 0);
            func_ov003_021c20f8(0, 0);
            func_ov003_021c212c(func_ov003_021cbb98);
            break;
        case 12:
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021c9944);
            break;
        case 13:
            if (*(u8 *) &gJb3ListMode == 0) {
                func_ov003_021c2120(2, 1);
                func_ov003_021c212c(CreateAp);
            } else {
                func_ov003_021cd790((func_ov003_021cdb6c())->mUnk_f4);
                func_ov003_021c2120(0, 1);
                func_ov003_021c212c(SetupWay);
            }
            break;
    }
    func_ov003_021d2808(&gJb3List);
}

void RefreshJb3List(void) {
    int a;
    int i;
    int j;
    a = FX_DivS32(*(u16 *) &gJb3ListScrollY, 0x1d);
    func_ov003_021d2060(gJb3List->mUnk_14, 0);
    for (i = 0, j = a; i < 5; i++, j++) {
        PrintJb3ListEntryText(j, i);
    }
    func_ov003_021cc9c0((s32) (gJb3List->mJb3ListBackNsc + data_ov003_021d6488[a]), 0, 0x1e, 0x13);
    for (i = 0; i < 5; i++, a++) {
        SetupJb3ListEntryCells(a, i);
    }
    func_ov003_021cc9fc();
    func_ov003_021d1fd0(gJb3List->mUnk_14);
    RefreshJb3ListRowPositions();
}

void PrintJb3ListEntryText(u32 a, int b) {
    Unk021cd5e0_400 *r;
    int x;
    u8 y[0x21];
    r = func_ov003_021cdb6c();
    switch (a) {
        case 0:
            PrintJb3ListEntryString(r->mUnk_00.mUnk_40, b);
            return;
        case 1:
            switch (r->mUnk_00.mUnk_e6_0) {
                case 0:
                    return;
                case 1:
                    x = 10;
                    break;
                case 2:
                    x = 0x1a;
                    break;
                case 3:
                    x = 0x20;
                    break;
            }
            if (r->mUnk_00.mUnk_e6_2 == 1) {
                x = _s32_div_f(x, 2);
            }
            MI_CpuFill8(y, 0, 0x21);
            memset(y, 0x2a, x);
            PrintJb3ListEntryString(y, b);
            return;
        case 3:
            if (r->mUnk_f5 == 0) {
                PrintJb3ListEntryBytes(r->mUnk_00.mUnk_c0, b);
            }
            break;
        case 4:
            if (r->mUnk_f5 == 0) {
                PrintJb3ListEntryBytes(r->mUnk_f0, b);
            }
            break;
        case 5:
            if (r->mUnk_f5 == 0) {
                PrintJb3ListEntryBytes(r->mUnk_00.mUnk_c4, b);
            }
            break;
        case 7:
            if (r->mUnk_f6 == 0) {
                PrintJb3ListEntryBytes(r->mUnk_00.mUnk_c8, b);
            }
            break;
        case 8:
            if (r->mUnk_f6 == 0) {
                PrintJb3ListEntryBytes(&r->mUnk_00.mUnk_c8[4], b);
            }
            break;
    }
}

void SetupJb3ListEntryCells(u32 a, int b) {
    Unk021cd5e0_400 *r;
    int x;
    int y;
    BOOL z;
    int w;
    r = func_ov003_021cdb6c();
    switch (a) {
        case 0:
        case 1:
            x = 0;
            y = 0;
            if (IsJb3ListIdEnabled(x) == 0) {
                y = 2;
            }
            break;
        case 2:
            z = FALSE;
            y = 0;
            if (r->mUnk_f5 != 0) {
                x = 1;
                w = 4;
            } else {
                x = 2;
                w = 3;
            }
            if (gJb3List->mIdTimer[0] != 0) {
                y = 1;
            }
            if (gJb3List->mIdTimer[1] != 0) {
                z = TRUE;
            }
            SetupJb3ListCell(w, z, b);
            break;
        case 3:
        case 4:
        case 5:
            x = 0;
            if (r->mUnk_f5 != 0) {
                y = 2;
            } else {
                y = x;
            }
            break;
        case 6:
            z = FALSE;
            y = 0;
            if (r->mUnk_f6 != 0) {
                x = 1;
                w = 4;
            } else {
                if (r->mUnk_f5 == 0) {
                    y = 2;
                }
                x = 2;
                w = 3;
            }
            if (gJb3List->mIdTimer[2] != 0) {
                y = 1;
            }
            if (gJb3List->mIdTimer[3] != 0) {
                z = TRUE;
            }
            SetupJb3ListCell(w, z, b);
            break;
        case 7:
        case 8:
            x = 0;
            if (r->mUnk_f6 != 0) {
                y = 2;
            } else {
                y = x;
            }
            break;
        default:
            x = 0;
            y = 2;
            break;
    }
    SetupJb3ListCell(x, y, b);
}

u32 IsJb3ListIdEnabled(u32 a) {
    Unk021cd5e0_400 *r;
    u32 v1;
    r = func_ov003_021cdb6c();
    v1 = 1;
    switch (a) {
        case 7:
            if (r->mUnk_f5 == 0) {
                v1 = 0;
            }
            break;
        case 0:
        case 1:
            if ((u8) (r->mUnk_00.mUnk_e7 + 0xff) <= 1) {
                v1 = 0;
            }
            break;
        case 4:
        case 5:
        case 6:
            if (r->mUnk_f5 != 0) {
                v1 = 0;
            }
            break;
        case 9:
        case 10:
            if (r->mUnk_f6 != 0) {
                v1 = 0;
            }
            break;
    }
    return v1;
}

void SetupJb3ListCell(int d, int e, int f) {
    u16 a[5];
    u16 b;
    u32 c;
    Unk021da104_04 **p;
    a[0] = gJb3ListCellRect.mUnk_00;
    b = data_ov003_021d644c.mUnk_00;
    a[1] = b;
    a[2] = b;
    b = data_ov003_021d6444.mUnk_00;
    a[3] = b;
    a[4] = b;
    p = &gJb3List->mUnk_18[f];
    if ((u32) (d - 1) <= 1) {
        if (GetJb3ListEntryIndexOfRow(f) == 2) {
            p = &gJb3List->mUnk_18[5];
        } else {
            p = &gJb3List->mUnk_18[6];
        }
    }
    if (data_ov003_021d6478[d][e] != 0) {
        func_ov003_021d1c3c(0, data_ov003_021d6478[d][e], (u8 *) *p);
        c = (a[d] & 0x1ff) << 16;
        (*p)->mUnk_00 = c | ((*p)->mUnk_00 & 0xfe00ff00);
        (*p)->mUnk_04 = ((*p)->mUnk_04 & ~0xc00) | 0xc00;
    } else {
        (*p)->mUnk_00 = ((*p)->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
}

void PrintJb3ListEntryString(const u8 *g, int h) {
    u16 f[17];
    int a;
    int b;
    int c;
    int i;
    int d;
    int e;
    MI_CpuFill8(f, 0, 0x22);
    a = func_ov003_021d3254(g, 0x20);
    if (a <= 0x10) {
        b = a;
    } else {
        b = 0x10;
    }
    for (i = 0; i < b; i++) {
        c = g[i];
        if (c == 0x20) {
            f[i] = 0xe01d;
        } else {
            f[i] = c;
        }
    }
    d = h * 0x1d + 2;
    if (a <= 0x10) {
        d += 5;
    }
    func_ov003_021d2094(gJb3List->mUnk_14, 0x48, d, 2, 8, f, 1);
    if (a > 0x10) {
        MI_CpuFill8(f, 0, 0x22);
        e = a - 0x10;
        for (i = 0; i < e; i++) {
            c = g[i + 0x10];
            if (c == 0x20) {
                f[i] = 0xe01d;
            } else {
                f[i] = c;
            }
        }
        func_ov003_021d2094(gJb3List->mUnk_14, 0x48, d + 0xc, 2, 8, f, 1);
    }
}

void PrintJb3ListEntryBytes(const u8 *b, int c) {
    u16 a[16];
    swprintf(a, 0x10, gDotSeparatedBytesFormat, b[0], b[1], b[2], b[3]);
    func_ov003_021d2094(gJb3List->mUnk_14, 0x5f, c * 0x1d + 8, 2, 7, a, 1);
}

void RefreshJb3ListRowPositions(void) {
    int a;
    int b;
    Unk021da104_04 *p;
    int c;
    int i;
    u32 x;
    u32 y;
    a = FX_DivS32(*(u16 *) &gJb3ListScrollY, 0x1d);
    b = 0x34 - FX_ModS32(*(u16 *) &gJb3ListScrollY, 0x1d);
    if (gJb3List->mUnk_34 != NULL) {
        if (a == 0) {
            x = 0x26;
        } else {
            x = 0x100;
        }
        gJb3List->mUnk_34->mUnk_00 = ((x & 0x1ff) << 16) | ((gJb3List->mUnk_34->mUnk_00 & 0xfe00ff00) | (b & 0xff));
    }
    for (i = 0, c = b; i < 5; i++, c += 0x1d) {
        func_ov003_021c85a0_inline(gJb3List->mUnk_18[i], (u32 *) &x, &y);
        p = gJb3List->mUnk_18[i];
        p->mUnk_00 = ((x & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (c & 0xff));
    }
    if (a <= 2) {
        func_ov003_021c85a0_inline(gJb3List->mUnk_18[5], &x, (u32 *) &y);
        gJb3List->mUnk_18[5]->mUnk_00 =
            ((x & 0x1ff) << 16) | ((gJb3List->mUnk_18[5]->mUnk_00 & 0xfe00ff00) | ((b + (2 - a) * 0x1d) & 0xff));
    } else {
        gJb3List->mUnk_18[5]->mUnk_00 = (gJb3List->mUnk_18[5]->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
    if (a >= 2 && a <= 6) {
        func_ov003_021c85a0_inline(gJb3List->mUnk_18[6], &x, (u32 *) &y);
        gJb3List->mUnk_18[6]->mUnk_00 =
            ((x & 0x1ff) << 16) | ((gJb3List->mUnk_18[6]->mUnk_00 & 0xfe00ff00) | ((b + (6 - a) * 0x1d) & 0xff));
    } else {
        gJb3List->mUnk_18[6]->mUnk_00 = (gJb3List->mUnk_18[6]->mUnk_00 & 0xfe00ff00) | 0x1000000;
    }
    gJb3List->mBgOffsetPending = 1;
}

u32 GetJb3ListHitId(void) {
    Unk021d299c a;
    Unk021d299c *b;
    s32 c;
    s32 d;
    s32 e;
    Unk021d299c *f;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return 0xe;
    }
    c = FX_DivS32(*(u16 *) gJb3ListScrollY, 0x1d);
    b = &a;
    a = gJb3ListCellRect;
    for (d = 0; d < 4; d++, c++, a.mUnk_02 += 0x1d) {
        if (c != 2 && c != 6) {
            if (func_ov003_021d2970(b) != 0) {
                return gJb3ListIdByEntryIndex[c];
            }
        }
    }
    e = FX_DivS32(*(u16 *) gJb3ListScrollY, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 2) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 2;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 3;
            }
            break;
        }
    }
    e = FX_DivS32(*(u16 *) gJb3ListScrollY, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 6) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 7;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 8;
            }
            break;
        }
    }
    d = 0;
    f = gJb3ListFixedRects;
    for (; d < 3; d++) {
        if (func_ov003_021d2a34(f) != 0) {
            return d + 0xb;
        }
        f++;
    }
    return 0xe;
}

int GetJb3ListRowOfEntryIndex(int a) {
    int v1;
    int v2;
    v1 = FX_DivS32((u32) ((*(u16 *) &gJb3ListScrollY)), 0x1d);
    v2 = 0;
    do {
        if (v1 == a) {
            return v2;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    return -1;
}

int GetJb3ListEntryIndexOfRow(int a) {
    int v1;
    v1 = FX_DivS32((u32) ((*(u16 *) &gJb3ListScrollY)), 0x1d);
    return v1 + a;
}

void AdvanceJb3ListScrollYDecrease(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    if (*(u16 *) gJb3ListScrollY > 6) {
        *(u16 *) gJb3ListScrollY = *(u16 *) gJb3ListScrollY - 6;
    } else {
        *(u16 *) gJb3ListScrollY = 0;
    }
    a = FX_ModS32(*(u16 *) gJb3ListScrollY, 0x1d);
    if (a == 0x17) {
        RefreshJb3List();
        return;
    }
    if (a > 0x17) {
        *(u16 *) gJb3ListScrollY = *(u16 *) gJb3ListScrollY + (0x1d - a);
        a = 0;
    }
    RefreshJb3ListRowPositions();
    if (a == 0) {
        func_ov003_021cce58(_s32_div_f(*(u16 *) gJb3ListScrollY * 0x37, 0x91));
        func_ov003_021cce48();
        SetJb3ListSelectedIdFromRow();
        gJb3List->mScrollTask = 0;
        func_ov003_021d34c8(0, b);
    }
}

void AdvanceJb3ListScrollYIncrease(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    *(u16 *) gJb3ListScrollY = *(u16 *) gJb3ListScrollY + 6;
    a = FX_ModS32(*(u16 *) gJb3ListScrollY, 0x1d);
    if (a >= 6) {
        RefreshJb3ListRowPositions();
        return;
    }
    *(u16 *) gJb3ListScrollY = *(u16 *) gJb3ListScrollY - a;
    RefreshJb3List();
    func_ov003_021cce58(_s32_div_f(*(u16 *) gJb3ListScrollY * 0x37, 0x91));
    func_ov003_021cce48();
    SetJb3ListSelectedIdFromRow();
    gJb3List->mScrollTask = 0;
    func_ov003_021d34c8(0, b);
}

void WriteJb3ListBgOffset(void) {
    u32 a;
    s32 b;
    if (gJb3List->mBgOffsetPending != 0) {
        a = FX_DivS32(*(u16 *) gJb3ListScrollY, 0x1d);
        b = FX_ModS32(*(u16 *) gJb3ListScrollY, 0x1d) - 0x33;
        reg_G2_BG0OFS = (b << 16) & 0x1ff0000;
        reg_G2_BG2OFS = ((b + data_ov003_021d6460[a]) << 16) & 0x1ff0000;
        gJb3List->mBgOffsetPending = 0;
    }
}

void func_ov003_021c81b8(void) {
    Unk021d73d0 a;
    Unk021d299c b;
    s32 d;
    a = data_ov003_021d73d0;
    d = a.mUnk_00[gJb3ListSelectedId[0]];
    if (d >= 3) {
        func_ov003_021bf760(3, data_ov003_021d64b4[d].mUnk_00, data_ov003_021d64b4[d].mUnk_04,
                            data_ov003_021d64b4[d].mUnk_02);
        return;
    }
    b = data_ov003_021d64b4[d];
    b.mUnk_02 = b.mUnk_02 + gJb3ListSelectedRow[0] * 0x1d;
    func_ov003_021bf760(1, b.mUnk_00, b.mUnk_04, b.mUnk_02);
}

void SetJb3ListSelectedIdFromRow(void) {
    Unk021cd5e0_400 *a;
    s32 b;
    if ((u8) (gJb3ListSelectedId[0] + 0xf5) <= 2) {
        func_ov003_021c81b8();
        return;
    }
    a = func_ov003_021cdb6c();
    b = gJb3ListSelectedRow[0] + FX_DivS32(*(u16 *) gJb3ListScrollY, 0x1d);
    switch (b) {
        case 2:
            if (a->mUnk_f5 != 0) {
                gJb3ListSelectedId[0] = 2;
            } else {
                gJb3ListSelectedId[0] = 3;
            }
            break;
        case 6:
            if (a->mUnk_f6 != 0) {
                gJb3ListSelectedId[0] = 7;
            } else {
                gJb3ListSelectedId[0] = 8;
            }
            break;
        default:
            gJb3ListSelectedId[0] = gJb3ListIdByEntryIndex[b];
            break;
    }
    func_ov003_021c81b8();
}

void SetJb3ListSelectedId(u32 a) {
    gJb3ListSelectedId[0] = a;
    gJb3ListSelectedRow[0] = GetJb3ListRowOfEntryIndex(gJb3ListEntryIndexById[a]);
    func_ov003_021c81b8();
}

void MoveJb3ListSelection(s32 d) {
    Unk021cd5e0_400 *a;
    s32 b;
    s32 c;
    a = func_ov003_021cdb6c();
    b = 0;
    c = gJb3ListSelectedId[0];
    if (c == 8 && a->mUnk_f5 == 0) {
        if (d == 0) {
            return;
        }
        if (d == 2) {
            return;
        }
    }
    switch (c) {
        case 0:
            if (d == 1) {
                gJb3ListSelectedId[0] = 0xb;
            } else if (d == 3) {
                gJb3ListSelectedRow[0] = gJb3ListSelectedRow[0] + 1;
            } else {
                b = 2;
            }
            break;
        case 0xa:
            if (d == 1) {
                gJb3ListSelectedRow[0] = gJb3ListSelectedRow[0] - 1;
            } else if (d == 3) {
                gJb3ListSelectedId[0] = gJb3List->mReturnId;
            } else {
                b = 2;
            }
            break;
        case 0xb:
            if (d == 1) {
                if (gJb3List->mUnk_47 != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mUnk_47 = 1;
                return;
            } else if (d == 3) {
                gJb3ListSelectedId[0] = 0;
                gJb3ListSelectedRow[0] = 0;
                *(u16 *) gJb3ListScrollY = 0;
                RefreshJb3List();
                func_ov003_021cce58(0);
            } else {
                b = 2;
            }
            break;
        case 0xc:
        case 0xd:
            gJb3List->mReturnId = c;
            if (d == 1) {
                gJb3ListSelectedId[0] = 0xa;
                gJb3ListSelectedRow[0] = 3;
                *(u16 *) gJb3ListScrollY = 0x91;
                RefreshJb3List();
                func_ov003_021cce58(0x37);
            } else if (d == 3) {
                if (gJb3List->mUnk_47 != 0) {
                    return;
                }
                StartSoundSeq(9);
                gJb3List->mUnk_47 = 1;
                return;
            } else if (c == 0xc) {
                gJb3ListSelectedId[0] = 0xd;
            } else {
                gJb3ListSelectedId[0] = 0xc;
            }
            break;
        default:
            if (d == 1) {
                if (gJb3ListSelectedRow[0] != 0) {
                    gJb3ListSelectedRow[0] = gJb3ListSelectedRow[0] - 1;
                    break;
                }
                StartSoundSeq(0x13);
                gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYDecrease, NULL, 0x78);
                return;
            } else if (d == 3) {
                if (gJb3ListSelectedRow[0] < 3) {
                    gJb3ListSelectedRow[0] = gJb3ListSelectedRow[0] + 1;
                    break;
                }
                StartSoundSeq(0x13);
                gJb3List->mScrollTask = func_ov003_021d3544(0, AdvanceJb3ListScrollYIncrease, NULL, 0x78);
                return;
            } else {
                b = 2;
                if (c == 2) {
                    gJb3ListSelectedId[0] = 3;
                } else if (c == 3) {
                    gJb3ListSelectedId[0] = b;
                } else if (c == 7) {
                    gJb3ListSelectedId[0] = 8;
                } else if (c == 8) {
                    gJb3ListSelectedId[0] = 7;
                } else {
                    break;
                }
                StartSoundSeq(8);
                func_ov003_021c81b8();
            }
            break;
    }
    if (b != 2) {
        StartSoundSeq(8);
        if (b == 0) {
            SetJb3ListSelectedIdFromRow();
        }
    }
}

void func_ov003_021c7ec4(void) {
    u8 a;
    a = data_ov003_021d6430[gJb3ListSelectedId[0] - 0xb];
    func_ov003_021cc948(gJb3List->mYbBgStep2NclFiles[1], a, a);
}

void AdvanceJb3ListIdTimers(void) {
    s32 a;
    for (a = 0; a < 4; a++) {
        if (gJb3List->mIdTimer[a] != 0) {
            gJb3List->mIdTimer[a] = gJb3List->mIdTimer[a] - 1;
            if (gJb3List->mIdTimer[a] == 0) {
                RefreshJb3List();
            }
        }
    }
}

void StartJb3ListIdTimer(void) {
    u8 a[4];
    s32 c;
    u8 *b;
    u8 d;
    b = a;
    a[0] = gJb3ListTimerIds[0];
    a[1] = gJb3ListTimerIds[1];
    a[2] = gJb3ListTimerIds[2];
    a[3] = gJb3ListTimerIds[3];
    c = 0;
    d = gJb3ListSelectedId[0];
    for (; c < 4; c++) {
        if (d == *b) {
            gJb3List->mIdTimer[c] = 0x14;
            if ((c & 1) != 0) {
                gJb3List->mIdTimer[c - 1] = 0;
            } else {
                gJb3List->mIdTimer[c + 1] = 0;
            }
            return;
        }
        b++;
    }
}

u32 func_ov003_021c7d8c(void) {
    Unk021cd5e0_400 *a;
    a = func_ov003_021cdb6c();
    if (a->mUnk_00.mUnk_40[0] == 0) {
        return 0;
    }
    if (a->mUnk_f6 == 0) {
        if (DWC_BACKUPlCheckAddress(a->mUnk_00.mUnk_c8) == 0 && DWC_BACKUPlCheckAddress(&a->mUnk_00.mUnk_c8[4]) == 0) {
            return 0;
        }
    }
    if (a->mUnk_f5 == 0) {
        if (DWC_BACKUPlCheckAddress(a->mUnk_00.mUnk_c0) == 0) {
            return 0;
        }
        if (DWC_BACKUPlCheckAddress(a->mUnk_00.mUnk_c4) == 0) {
            return 0;
        }
        if (DWC_BACKUPlCheckIp(a->mUnk_00.mUnk_c0, a->mUnk_f0) == 0) {
            return 0;
        }
    }
    return 1;
}

void func_ov003_021c7d58(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        StartSoundSeq(6);
        func_ov003_021cef90();
        func_ov003_021cc900((u32) gJb3List->mYbBgStep2NclFiles[0]);
        func_ov003_021c212c(func_ov003_021c7d3c);
    }
}

void func_ov003_021c7d3c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(UpdateJb3List);
    }
}

void SetJb3ListMode(u8 a) {
    *(u8 *) &gJb3ListMode = a;
}
