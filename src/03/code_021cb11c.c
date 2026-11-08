#include "03/code_021cb11c.h"
#include "03/code_021c7d30.h"
#include "03/code_021ca56c.h"
#include "03/code_021c50f8.h"
#include "03/code_021ca20c.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c5000.h"
#include "03/code_021c9000.h"
#include "03/code_021ca000.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d7000.h"
#include "03/code_021ca940.h"
#include "03/code_021cb000.h"
#include "03/code_021cc000.h"
#include "os_printf.h"
#include "03/code_021cd2e0.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"
#include "03/code_021cc8d4.h"
#include "registers.h"

void func_ov003_021cb3d8(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021bf2f0() != 0) {
        ReleaseSelectionObjectSlots();
        func_ov003_021bf410();
        func_ov003_021d1490(gYbBgStep21Ncl);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da240[0] == 0) {
            func_ov003_021c2120(2, 0);
            func_ov003_021c212c(CreateAp);
        } else {
            switch (gWaySelectedIndex) {
                case 0:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021ca8e8);
                    break;
                case 1:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021c54dc);
                    break;
                case 2:
                    func_ov003_021c2120(2, 1);
                    func_ov003_021c212c(func_ov003_021ca504);
                    break;
                case 3:
                    func_ov003_021c2120(2, 0);
                    func_ov003_021c20f8(0, 0);
                    SetJb3ListMode(1);
                    func_ov003_021c212c(CreateJb3List);
                    break;
            }
        }
    }
}

void MoveWaySelection(int param_1) {
    s32 a = gWaySelectedIndex;
    s32 b = gWayMoveTargets[func_ov003_021c20a8(1)][a][param_1];
    if (b == -1) {
        return;
    }
    if (b == 0) {
        gWaySavedIndex = a;
    }
    if (b == -2) {
        gWaySelectedIndex = gWaySavedIndex;
    } else {
        gWaySelectedIndex = b;
    }
    StartSoundSeq(8);
    PlaceSelectionCorners(data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_00,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_04,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_02,
                          data_ov003_021d65e0[func_ov003_021c20a8(1)][gWaySelectedIndex].mUnk_06);
}

void func_ov003_021cb2e0(void) {
    Unk021d7650 a = data_ov003_021d7650;
    func_ov003_021cc948(gYbBgStep21Ncl, a.mUnk_00[gWaySelectedIndex], a.mUnk_00[gWaySelectedIndex]);
}

void CreateAp(void) {
    Ap *a = func_ov003_021d283c(0x20, 4);
    gAp = a;
    a->mUnk_1d = 0;
    LoadApFilesAndSetBgCnt();
    LoadHlScr(1);
    func_ov003_021bf43c(0x7b, -1, 0);
    func_ov003_021bf5ec(0);
    func_ov003_021cb11c();
    func_ov003_021caca8();
    func_ov003_021c212c(func_ov003_021cb0e0);
}

void LoadApFilesAndSetBgCnt(void) {
    Unk021d75c8 a = gYbBgStep11NclName2;
    LoadFileToVram(gYbObjWayNclName, GX_LoadOBJPltt);
    LoadFileToVram(gJbBgStep1NcgName3, GX_LoadBG2Char);
    LoadFileToVram(gJbBgStep1NclName3, GX_LoadBGPltt);
    LoadFileToVram(gJb2ApNscName, GX_LoadBG2Scr);
    gAp->mYbBgStep11Ncl = func_ov003_021d14b8(BuildFilePathWithLanguage((u8 *) &a), NULL, 4);
    func_ov003_021d2784(1, 0x10);
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
}

void func_ov003_021cb11c(void) {
    s32 i;
    u32 a;
    for (i = 0; i < 3; i++) {
        a = func_ov003_021cd844(i);
        if (a == 0xff) {
            a = 3;
        } else {
            gAp->mUnk_10[i] = func_ov003_021d1be4(0, 0x11, 1);
            func_ov003_021d17d4(gAp->mUnk_10[i], -1, data_ov003_021d64f0[i + 3].mUnk_00,
                                data_ov003_021d64f0[i + 3].mUnk_02);
            func_ov003_021d1790(gAp->mUnk_10[i], -1, 3);
        }
        gAp->mUnk_04[i] = func_ov003_021d1be4(0, data_ov003_021d64e4[a], 1);
        func_ov003_021d17d4(gAp->mUnk_04[i], -1, data_ov003_021d64f0[i].mUnk_00, data_ov003_021d64f0[i].mUnk_02);
        func_ov003_021d1790(gAp->mUnk_04[i], -1, 3);
    }
}
