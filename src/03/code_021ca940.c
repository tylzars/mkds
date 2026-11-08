#include "03/code_021ca940.h"
#include "03/code_021c2c94.h"
#include "03/code_021c7d30.h"
#include "03/code_021bf000.h"
#include "03/code_021cb4d0.h"
#include "03/code_021cdd28.h"
#include "03/code_021cef90.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/code_021c2000.h"

#include "03/unk_021d7000.h"
#include "os_printf.h"
#include "03/code_021cd2e0.h"
#include "03/code_021cea3c.h"
#include "03/code_021c209c.h"
#include "03/code_021c3000.h"
#include "03/code_021c9000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf698.h"
#include "03/code_021cb000.h"
#include "03/code_021cc144.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021ce000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "code_0214b824.h"
#include "03/code_021c2a74.h"
#include "03/code_021ca000.h"
#include "03/code_021cd000.h"
#include "03/unk_021d6000.h"
#include "03/code_021cc8d4.h"

void func_ov003_021cb0e0(void) {
    StartBlendBrightnessFade(2, 1, 1, 8);
    StartBlendBrightnessFade(2, 0, 0x14, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x14);
    SetUpdateFunction(func_ov003_021cb0b0);
}

void func_ov003_021cb0b0(void) {
    int v1;
    v1 = IsBlendBrightnessFadeSlotBusy(1);
    if ((v1 == 0) && (v1 = IsBlendBrightnessFadeSlotBusy(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        SetUpdateFunction(func_ov003_021cb084);
    }
}

void func_ov003_021cb084(void) {
    if (GetButtonResult() != -2 && func_ov003_021ce00c() != 1) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void UpdateAp(void) {
    UpdateApInput();
    func_ov003_021cafa0();
    func_ov003_021caeb8();
}

void UpdateApInput(void) {
    int v1;
    u32 v2;
    int v3;
    u8 *v4;
    v2 = 0;
    v4 = gApRects;
    do {
        v1 = IsTouchPressedInRect((const Rect *) v4);
        if (v1 != 0) {
            SetButtonResultIfNone((u8) 1);
            *(u8 *) &gApSelectedIndex = (s8) v2;
            func_ov003_021caca8();
            return;
        }
        v4 = v4 + 8;
        v2 = v2 + 1;
    } while (v2 < 7);
    v3 = AreKeysPressed(1);
    if (v3 != 0) {
        SetButtonResultIfNone((u8) 1);
        return;
    }
    v3 = AreKeysPressed(2);
    if (v3 != 0) {
        SetButtonResultIfNone((u8) 0);
        return;
    }
    v3 = AreKeysPressedOrRepeated(0x40);
    if (v3 != 0) {
        MoveApSelection(1);
        return;
    }
    v3 = AreKeysPressedOrRepeated(0x80);
    if (v3 != 0) {
        MoveApSelection(3);
        return;
    }
    v3 = AreKeysPressedOrRepeated(0x20);
    if (v3 != 0) {
        MoveApSelection(0);
        return;
    }
    v3 = AreKeysPressedOrRepeated(0x10);
    if (v3 != 0) {
        MoveApSelection(2);
    }
}

void func_ov003_021cafa0(void) {}

void func_ov003_021caeb8(void) {
    s32 a;
    u8 s;
    switch (GetButtonResult()) {
        case 0:
            switch (GetMode()) {
                case 0:
                    StartSoundSeq(7);
                    gAp->mUnk_1d = 2;
                    break;
                case 1:
                    DisableButtonTouch();
                    SetUpdateFunction(func_ov003_021c2a74);
                    return;
            }
            break;
        case 1:
            gAp->mUnk_1d = 1;
            s = gApSelectedIndex[0];
            if (s >= 4) {
                a = s - 4;
                if (func_ov003_021cd844(a) == 0xff) {
                    StartSoundSeq(9);
                    SetButtonResult(-1);
                    return;
                }
                StartSoundSeq(6);
                func_ov003_021cefc0(0x98, 0, 1, data_ov003_021d64e8[GetLanguageIndex()], a + 1);
                func_ov003_021caae0();
                DisableButtonTouch();
                SetUpdateFunction(func_ov003_021ca9e8);
                return;
            }
            if (s <= 2) {
                func_ov003_021cd790(s);
            }
            StartSoundSeq(6);
            func_ov003_021ca940();
            break;
        default:
            return;
    }
    SetUpdateFunction(func_ov003_021cae88);
}

void func_ov003_021cae88(void) {
    if (gAp->mUnk_1d == 2) {
        func_ov003_021ce0c4();
    }
    DisableButtonTouch();
    StartBlendBrightnessFadeWait(8);
    SetUpdateFunction(func_ov003_021cae28);
}

void func_ov003_021cae28(void) {
    if (IsBlendBrightnessFadeSlotBusy(1) == 0) {
        if (gAp->mUnk_1d == 1) {
            if (gApSelectedIndex[0] == 3 || func_ov003_021cdb6c()->mUnk_00.mUnk_e7 != 0xff) {
                StartSlideButtonsOut();
            }
        }
        StartBlendBrightnessFade(3, 1, 1, 8);
        StartBlendBrightnessFade(3, 0, 0x14, 8);
        SetUpdateFunction(func_ov003_021cacfc);
    }
}

void func_ov003_021cacfc(void) {
    u32 i;
    if (IsBlendBrightnessFadeSlotBusy(1) == 0 && IsBlendBrightnessFadeSlotBusy(0) == 0 && func_ov003_021cdd28() != 0 &&
        func_ov003_021bf2f0() != 0) {
        for (i = 0; i < 3; i++) {
            if (gAp->mUnk_04[i] != NULL) {
                DeleteOamRange(gAp->mUnk_04[i]);
            }
        }
        for (i = 0; i < 3; i++) {
            if (gAp->mUnk_10[i] != NULL) {
                DeleteOamRange(gAp->mUnk_10[i]);
            }
        }
        ReleaseSelectionObjectSlots();
        func_ov003_021bf410();
        func_ov003_021d1490(gAp->mYbBgStep11Ncl);
        LoadFileToVram(gYbObjMainNclName5, GX_LoadOBJPltt);
        ClearDispcntBits(1, 1);
        ClearDispcntBits(0, 0x14);
        if (gAp->mUnk_1d == 2) {
            func_ov003_021c2120(0, 0);
            SetUpdateFunction(SetupJb2Menu);
        } else {
            switch (gApSelectedIndex[0]) {
                case 0:
                case 1:
                case 2:
                    func_ov003_021c2120(2, 0);
                    if (func_ov003_021cdb6c()->mUnk_00.mUnk_e7 == 0xff) {
                        SetUpdateFunction(SetupWay);
                    } else {
                        func_ov003_021c20f8(0, 0);
                        SetJb3ListMode(0);
                        SetUpdateFunction(CreateJb3List);
                    }
                    break;
                case 3:
                    func_ov003_021c2120(2, 1);
                    SetUpdateFunction(SetupXb3Multi);
                    break;
            }
        }
        FreeExpHeapBlockAndClearPointer(&gAp);
    }
}

void func_ov003_021caca8(void) {
    u8 a = gApSelectedIndex[0];
    if (a < 4) {
        PlaceSelectionCorners(data_ov003_021d6540[a].mUnk_00, data_ov003_021d6540[a].mUnk_04,
                              data_ov003_021d6540[a].mUnk_02, data_ov003_021d6540[a].mUnk_06);
    } else {
        PlaceSelectionPair(0, data_ov003_021d6540[a].mUnk_00, data_ov003_021d6540[a].mUnk_04,
                           data_ov003_021d6540[a].mUnk_02);
    }
}

void MoveApSelection(int a) {
    u32 b = 1;
    switch (gApSelectedIndex[0]) {
        case 0:
            gAp->mUnk_1c = 0;
            if (a == 0) {
                gApSelectedIndex[0] = 2;
            } else if (a == 2) {
                gApSelectedIndex[0] = 1;
            } else if (a == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 4;
            }
            break;
        case 1:
            gAp->mUnk_1c = 1;
            if (a == 0) {
                gApSelectedIndex[0] = 0;
            } else if (a == 2) {
                gApSelectedIndex[0] = 2;
            } else if (a == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 5;
            }
            break;
        case 2:
            gAp->mUnk_1c = 2;
            if (a == 0) {
                gApSelectedIndex[0] = 1;
            } else if (a == 2) {
                gApSelectedIndex[0] = 0;
            } else if (a == 1) {
                gApSelectedIndex[0] = 3;
            } else {
                gApSelectedIndex[0] = 6;
            }
            break;
        case 3: {
            u8 c = gAp->mUnk_1c;
            s32 d = c + 4;
            if (a == 1) {
                gApSelectedIndex[0] = d;
            } else if (a == 3) {
                gApSelectedIndex[0] = c;
            } else {
                b = 0;
            }
            break;
        }
        case 4:
            gAp->mUnk_1c = 0;
            if (a == 0) {
                gApSelectedIndex[0] = 6;
            } else if (a == 2) {
                gApSelectedIndex[0] = 5;
            } else if (a == 1) {
                gApSelectedIndex[0] = 0;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
        case 5:
            gAp->mUnk_1c = 1;
            if (a == 0) {
                gApSelectedIndex[0] = 4;
            } else if (a == 2) {
                gApSelectedIndex[0] = 6;
            } else if (a == 1) {
                gApSelectedIndex[0] = 1;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
        case 6:
            gAp->mUnk_1c = 2;
            if (a == 0) {
                gApSelectedIndex[0] = 5;
            } else if (a == 2) {
                gApSelectedIndex[0] = 4;
            } else if (a == 1) {
                gApSelectedIndex[0] = 2;
            } else {
                gApSelectedIndex[0] = 3;
            }
            break;
    }
    if (b != 0) {
        StartSoundSeq(8);
        func_ov003_021caca8();
    }
}

void func_ov003_021caae0(void) {
    s32 a = gApSelectedIndex[0] - 4;
    CopyNceImageToOamEntries(0, 0x32, GetOamRangeEntry(gAp->mUnk_10[a], 0));
    SetOamRangePosition(gAp->mUnk_10[a], -1, data_ov003_021d64f0[a + 3].mUnk_00, data_ov003_021d64f0[a + 3].mUnk_02);
    func_ov003_021d1790(gAp->mUnk_10[a], -1, 3);
}

void func_ov003_021ca9e8(void) {
    s32 a = gApSelectedIndex[0] - 4;
    switch (func_ov003_021cef80()) {
        case 1:
            StartSoundSeq(0xe);
            func_ov003_021cd4ac(a);
            CopyNceImageToOamEntries(0, data_ov003_021d64e4[3], GetOamRangeEntry(gAp->mUnk_04[a], 0));
            SetOamRangePosition(gAp->mUnk_04[a], -1, data_ov003_021d64f0[a].mUnk_00, data_ov003_021d64f0[a].mUnk_02);
            func_ov003_021d1790(gAp->mUnk_04[a], -1, 3);
            DeleteOamRange(gAp->mUnk_10[a]);
            gAp->mUnk_10[a] = NULL;
            break;
        case 0:
            StartSoundSeq(7);
            CopyNceImageToOamEntries(0, 0x11, GetOamRangeEntry(gAp->mUnk_10[a], 0));
            SetOamRangePosition(gAp->mUnk_10[a], -1, data_ov003_021d64f0[a + 3].mUnk_00,
                                data_ov003_021d64f0[a + 3].mUnk_02);
            func_ov003_021d1790(gAp->mUnk_10[a], -1, 3);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    SetUpdateFunction(func_ov003_021ca9c8);
}

void func_ov003_021ca9c8(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        EnableButtonTouch();
        SetUpdateFunction(UpdateAp);
    }
}

void func_ov003_021ca940(void) {
    Unk021d6974 a;
    Unk021d6974 b;
    int c;
    a = data_ov003_021d75c0;
    b = data_ov003_021d75c4;
    if (*(u8 *) &gApSelectedIndex <= 3) {
        func_ov003_021cc948(gAp->mYbBgStep11Ncl, a.mUnk_00[*(u8 *) &gApSelectedIndex],
                            a.mUnk_00[*(u8 *) &gApSelectedIndex]);
        if (*(u8 *) &gApSelectedIndex != 3) {
            c = func_ov003_021cd844(*(u8 *) &gApSelectedIndex);
            if (c > 2) {
                c = 3;
            }
            func_ov003_021d1890(gAp->mUnk_04[*(u8 *) &gApSelectedIndex], -1, 0, b.mUnk_00[c]);
        }
    }
}
