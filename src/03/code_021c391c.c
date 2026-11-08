#include "03/code_021c391c.h"
#include "03/types_021d299c.h"

#include "03/code_021bf000.h"
#include "03/code_021c3000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1440.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c2b28.h"
#include "03/code_021c2c94.h"
#include "03/code_021c30f0.h"
#include "03/code_021c38f0.h"
#include "03/code_021c43f0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2ecc.h"
#include "code_02147cd8.h"
#include "code_021510a4.h"
#include "code_02151868.h"
#include "03/code_021d2940.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "03/code_021d1c18.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"
#include "registers.h"

void SetupOptMenu(void) {
    Unk021da104_04 *a;
    data_ov003_021da1b0[0] = 0;
    LoadOptMenuFilesAndSetBgCnt();
    LoadHlScr(0x10);
    func_ov003_021cdcf0(3);
    func_ov003_021bf43c(0x88, -1, 0);
    data_ov003_021da1b8 = func_ov003_021d1c18(0, 0x5b);
    a = data_ov003_021da1b8;
    a->mUnk_00 =
        ((data_ov003_021d634c[0] & 0x1ff) << 16) | ((a->mUnk_00 & 0xfe00ff00) | (data_ov003_021d634c[1] & 0xff));
    a = data_ov003_021da1b8;
    a->mUnk_04 = (a->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021bf6c8(data_ov003_021d6368[gOptMenuSelectedIndex * 4], data_ov003_021d636c[gOptMenuSelectedIndex * 4],
                        data_ov003_021d636a[gOptMenuSelectedIndex * 4], data_ov003_021d636e[gOptMenuSelectedIndex * 4]);
    func_ov003_021c212c(func_ov003_021c3c88);
}

void LoadOptMenuFilesAndSetBgCnt(void) {
    u8 *a;
    Unk021d70f8 b;
    Unk021d7110 c;
    DWCWiFiInfo d;
    u8 *e;
    u8 *f;
    s32 i;
    b = gYbBgOptionNclName;
    c = gYbBgOption1NclName;
    func_ov003_021bf620(gJbBgOptionNcgName, GX_LoadBG2Char);
    func_ov003_021bf620(gJb5OptMenuNscName, GX_LoadBG2Scr);
    gYbBgOption1Ncl = func_ov003_021d14b8(func_ov003_021bf650(c.mUnk_00), NULL, 4);
    a = func_ov003_021d14b8(func_ov003_021bf650(b.mUnk_00), NULL, 4);
    DWCi_BM_GetWiFiInfo(&d);
    if (d.mAttestedUserId == 0) {
        e = a + 0xc0;
        f = a + 0x40;
        for (i = 0; i < 2; i++, e += 0x20, f += 0x20) {
            MI_CpuCopy8(e, f, 0x20);
        }
    }
    DC_FlushRange(a, 0x200);
    GX_LoadBGPltt(a, 0, 0x200);
    func_ov003_021d1490(a);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void func_ov003_021c3c88(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x14, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021c3c58);
}

void func_ov003_021c3c58(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c3c34);
    }
}

void func_ov003_021c3c34(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateOptMenu);
    }
}

void UpdateOptMenu(void) {
    UpdateOptMenuInput();
    func_ov003_021c3b5c();
    func_ov003_021c3ae4();
}

void UpdateOptMenuInput(void) {
    u32 i;
    for (i = 0; i < 3; i++) {
        if (func_ov003_021d2a34(&gOptMenuRects[i]) != 0) {
            SetButtonResultIfNone(1);
            gOptMenuSelectedIndex = i;
            func_ov003_021bf6c8(
                data_ov003_021d6368[gOptMenuSelectedIndex * 4], data_ov003_021d636c[gOptMenuSelectedIndex * 4],
                data_ov003_021d636a[gOptMenuSelectedIndex * 4], data_ov003_021d636e[gOptMenuSelectedIndex * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        MoveOptMenuSelection(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        MoveOptMenuSelection(3);
    }
}

void func_ov003_021c3b5c(void) {}

void func_ov003_021c3ae4(void) {
    DWCWiFiInfo a;
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            break;
        case 1:
            DWCi_BM_GetWiFiInfo(&a);
            if (gOptMenuSelectedIndex != 0 && a.mAttestedUserId == 0) {
                StartSoundSeq(9);
                SetButtonResult(-1);
                return;
            }
            StartSoundSeq(6);
            func_ov003_021c391c();
            data_ov003_021da1b0[0] = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021c3ac4);
}

void func_ov003_021c3ac4(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c3a7c);
}

void func_ov003_021c3a7c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da1b0) != 0) {
            StartSlideButtonsOut();
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021c39a4);
    }
}

void func_ov003_021c39a4(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021bf2f0() != 0) {
        func_ov003_021d2f00((u32 *) data_ov003_021da1b8);
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(gYbBgOption1Ncl);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da1b0[0] == 0) {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(SetupJb2Menu);
        } else {
            switch (gOptMenuSelectedIndex) {
                case 0:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(SetupJb5Info);
                    break;
                case 1:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(SetupYb5Multi);
                    break;
                case 2:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c4670);
                    break;
            }
        }
    }
}

void MoveOptMenuSelection(s32 a) {
    if (a == 1) {
        gOptMenuSelectedIndex = FX_ModS32(gOptMenuSelectedIndex + 2, 3);
    } else {
        gOptMenuSelectedIndex = FX_ModS32(gOptMenuSelectedIndex + 1, 3);
    }
    StartSoundSeq(8);
    func_ov003_021bf6c8(data_ov003_021d6368[gOptMenuSelectedIndex * 4], data_ov003_021d636c[gOptMenuSelectedIndex * 4],
                        data_ov003_021d636a[gOptMenuSelectedIndex * 4], data_ov003_021d636e[gOptMenuSelectedIndex * 4]);
}

void func_ov003_021c391c(void) {
    u8 a = data_ov003_021d6348[gOptMenuSelectedIndex];
    func_ov003_021cc948(gYbBgOption1Ncl, a, a);
}
