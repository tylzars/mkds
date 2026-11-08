#include "03/code_021c2c94.h"
#include "03/code_021c2000.h"
#include "03/code_021bf000.h"
#include "03/code_021cb11c.h"
#include "03/code_021ce000.h"

#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/code_021bf698.h"
#include "03/code_021c209c.h"
#include "03/code_021c391c.h"
#include "03/code_021cb000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021c2a74.h"
#include "03/code_021d2940.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "code_0214b824.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cdcb8.h"
#include "registers.h"

void SetupJb2Menu(void) {
    LoadJb2MenuFilesAndSetBgCnt();
    LoadHlScr(0);
    func_ov003_021bf43c(0x7a, -1, 0);
    func_ov003_021cdcf0(4);
    PlaceSelectionCorners(
        data_ov003_021d6328[gJb2MenuSelectedIndex * 4], data_ov003_021d632c[gJb2MenuSelectedIndex * 4],
        data_ov003_021d632a[gJb2MenuSelectedIndex * 4], data_ov003_021d632e[gJb2MenuSelectedIndex * 4]);
    func_ov003_021c212c(func_ov003_021c2f98);
}

void LoadJb2MenuFilesAndSetBgCnt(void) {
    Unk021d6fd4 a;
    a = gYbBgStep11NclName;
    LoadFileToVram(gJbBgStep1NcgName2, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName2, GX_LoadBGPltt);
    LoadFileToVram(gJb2MenuNscName, GX_LoadBG2Scr);
    gYbBgStep11Ncl = func_ov003_021d14b8(BuildFilePathWithLanguage(a.mUnk_00), NULL, 4);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void func_ov003_021c2f98(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x14, 8);
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021c2f68);
}

void func_ov003_021c2f68(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021c2f44);
    }
}

void func_ov003_021c2f44(void) {
    if (GetButtonResult() != -2) {
        EnableButtonTouch();
        func_ov003_021c212c(UpdateJb2Menu);
    }
}

void UpdateJb2Menu(void) {
    UpdateJb2MenuInput();
    func_ov003_021c2e3c();
    func_ov003_021c2df4();
}

void UpdateJb2MenuInput(void) {
    u32 i;
    for (i = 0; i < 2; i++) {
        if (func_ov003_021d2a34(&gJb2MenuRects[i]) != 0) {
            SetButtonResultIfNone(1);
            gJb2MenuSelectedIndex = i;
            PlaceSelectionCorners(
                data_ov003_021d6328[gJb2MenuSelectedIndex * 4], data_ov003_021d632c[gJb2MenuSelectedIndex * 4],
                data_ov003_021d632a[gJb2MenuSelectedIndex * 4], data_ov003_021d632e[gJb2MenuSelectedIndex * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        SetButtonResultIfNone(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        SetButtonResultIfNone(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        MoveJb2MenuSelection(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        MoveJb2MenuSelection(3);
    } else if (func_ov003_021d2ae8(0x20) != 0) {
        MoveJb2MenuSelection(0);
    } else if (func_ov003_021d2ae8(0x10) != 0) {
        MoveJb2MenuSelection(2);
    }
}

void func_ov003_021c2e3c(void) {}

void func_ov003_021c2df4(void) {
    switch (GetButtonResult()) {
        case 0:
            StartSoundSeq(7);
            func_ov003_021c212c(func_ov003_021c2a74);
            break;
        case 1:
            StartSoundSeq(6);
            func_ov003_021c2c94();
            func_ov003_021c212c(func_ov003_021c2dd4);
            break;
    }
}

void func_ov003_021c2dd4(void) {
    DisableButtonTouch();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c2d9c);
}

void func_ov003_021c2d9c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x14, 8);
        func_ov003_021c212c(func_ov003_021c2d18);
    }
}

void func_ov003_021c2d18(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        ReleaseSelectionObjectSlots();
        func_ov003_021bf410();
        func_ov003_021d1490(gYbBgStep11Ncl);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        switch (gJb2MenuSelectedIndex) {
            case 0:
                func_ov003_021c2120(1, 0);
                func_ov003_021c212c(CreateAp);
                break;
            case 1:
                func_ov003_021c2120(0, 0);
                func_ov003_021c212c(SetupOptMenu);
                break;
        }
    }
}

void MoveJb2MenuSelection(s32 a) {
    if (a != 1 && a != 3) {
        gJb2MenuSelectedIndex ^= 1;
        StartSoundSeq(8);
        PlaceSelectionCorners(
            data_ov003_021d6328[gJb2MenuSelectedIndex * 4], data_ov003_021d632c[gJb2MenuSelectedIndex * 4],
            data_ov003_021d632a[gJb2MenuSelectedIndex * 4], data_ov003_021d632e[gJb2MenuSelectedIndex * 4]);
    }
}

void func_ov003_021c2c94(void) {
    Unk021d6fd0 a;
    u8 b;
    a = data_ov003_021d6fd0;
    b = a.mUnk_00[gJb2MenuSelectedIndex];
    func_ov003_021cc948(gYbBgStep11Ncl, b, b);
}
