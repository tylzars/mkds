#include "00/code_02181714.h"
#include "registers.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "00/unk_021b0000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_0212a910.h"

#include "00/code_02180608.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02061250.h"

void InitWiFiTopMenu(void *heap) {
    s32 i;
    s32 j;
    s32 k;

    gWiFiTopMenu = HeapAlloc(heap, 0x40);
    gWiFiTopMenu->mHeap = heap;
    gWiFiTopMenu->mState = 0;
    gWiFiTopMenu->mNextState = 0;
    gWiFiTopMenu->mPendingWiFiState = -1;
    switch (GetWiFiPrevState()) {
        case 0:
        case 2:
            gWiFiTopMenu->mIndex = 0;
            break;
        case 8:
            gWiFiTopMenu->mIndex = 1;
            break;
        case 13:
            gWiFiTopMenu->mIndex = 2;
            break;
    }
    gWiFiTopMenu->mStateFrames = 0;
    gWiFiTopMenu->mUnk_18 = TRUE;
    gWiFiTopMenu->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiTopMenu->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    LocateAndQueueWiFiTopMenu();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov000_021b05c0[i], 1, gWiFiTopMenu->mWiFiTopMenuSNcer, gWiFiTopMenu->mWiFiTopMenuBncl);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    InitLayoutTable(heap, gWiFiTopMenu->mWiFiTopMenuBncl, NULL, &gWiFiTopMenu->mWiFiTopMenuTable);
    for (j = 0; j < 3; j++) {
        for (k = 0; k < data_ov000_021b05cc[j]; k++) {
            gWiFiTopMenu->mWiFiTopMenuTable[data_ov000_021b05d8[j][k]].mOffsetX = 0xdc;
        }
    }
    func_0212a910(1, 0);
    SetSelectReturnSoundId(0xf);
    func_0204f7f4();
}

void func_ov000_02181e8c(void) {
    gWiFiTopMenu = NULL;
}

void LocateAndQueueWiFiTopMenu(void) {
    void *v1;
    v1 = FindSceneFile(gWiFiTopMenuSBnclName);
    gWiFiTopMenu->mWiFiTopMenuBncl = v1;
    v1 = FindSceneFile(gWiFiTopMenuSBnblName);
    gWiFiTopMenu->mWiFiTopMenuBnbl = v1;
    v1 = FindSceneFile(gWiFiTopMenuSNcgrName);
    LocateNcgr2(&gWiFiTopMenu->mWiFiTopMenuSNcgr, v1);
    v1 = FindSceneFile(gWiFiTopMenuSNcerName);
    LocateNcer(&gWiFiTopMenu->mWiFiTopMenuSNcer, v1);
    v1 = FindSceneFile(gWiFiTopMenuSONclrName);
    LocateNclr(&gWiFiTopMenu->mWiFiTopMenuSONclr, v1);
    CallQueueAppend(0x23, 0, (gWiFiTopMenu->mWiFiTopMenuSNcgr->mData), gWiFiTopMenu->mWiFiTopMenuSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, (gWiFiTopMenu->mWiFiTopMenuSONclr->mData), gWiFiTopMenu->mWiFiTopMenuSONclr->mDataSize);
}

s32 func_ov000_02181df0(void) {
    return func_02061250();
}

void AdvanceWiFiTopMenuState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        gWiFiTopMenu->mNextState = 1;
    }
}

void AdvanceWiFiTopMenuState1(void) {
    s32 v = 0;
    s32 i;
    s32 j;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    if (gWiFiTopMenu->mStateFrames >= 20) {
        gWiFiTopMenu->mNextState = 2;
        gWiFiTopMenu->mStateFrames = v;
        RequestSelectReturnState1();
    } else if (gWiFiTopMenu->mStateFrames >= 10) {
        v = func_020ae488(gWiFiTopMenu->mStateFrames - 10);
    } else {
        v = InterpolateS16(1, 0xdc, v, gWiFiTopMenu->mStateFrames, 10);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            gWiFiTopMenu->mWiFiTopMenuTable[data_ov000_021b05d8[i][j]].mOffsetX = v;
        }
    }
}

void AdvanceWiFiTopMenuState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gWiFiTopMenu->mNextState = 3;
        SetSelectReturnSoundId(0xf);
    }
}

void AdvanceWiFiTopMenuState3(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL v1 = FALSE;
    u32 v2 = -1;
    BOOL v3 = FALSE;
    s32 v4;
    s32 v5;
    BOOL v6;
    s32 v7;

    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        v3 = TRUE;
    }
    if (v3 == FALSE && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        v1 = TRUE;
    }
    if (v1 != FALSE) {
        v2 =
            RectTableFindContaining(gWiFiTopMenu->mWiFiTopMenuBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    v5 = data_02175628[i].mUnk_00 & PAD_KEY_B;
    if ((u16) v5 == 0) {
        v7 = v6 = FALSE;
        if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
            v7 = 1;
        }
        if (v7 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
            v6 = TRUE;
        }
        if (v6 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00,
                                                                           data_02175672[i].mUnk_00) == FALSE) {
            goto next;
        }
    }
    gWiFiTopMenu->mNextState = 5;
    gWiFiTopMenu->mPendingWiFiState = 10;
    if (gWiFiTopMenu->mPendingWiFiState == 10) {
        RequestSelectReturnState3WithSound(1);
    }
    return;
next:
    v5 = data_02175628[i].mUnk_00 & PAD_KEY_A;
    if ((u16) v5 != 0 || v2 <= 2) {
        v4 = gWiFiTopMenu->mIndex;
        if ((u16) v5 == 0) {
            switch (v2) {
                case 0:
                    gWiFiTopMenu->mIndex = 0;
                    break;
                case 1:
                    gWiFiTopMenu->mIndex = 1;
                    break;
                case 2:
                    gWiFiTopMenu->mIndex = 2;
                    break;
            }
        }
        if (gWiFiTopMenu->mIndex == v4) {
            gWiFiTopMenu->mUnk_18 = FALSE;
        }
        gWiFiTopMenu->mNextState = 4;
        switch (gWiFiTopMenu->mIndex) {
            case 0:
                if (GetWiFiSessionLoginResult() == 1) {
                    gWiFiTopMenu->mPendingWiFiState = 2;
                } else {
                    gWiFiTopMenu->mPendingWiFiState = 0;
                }
                break;
            case 1:
                gWiFiTopMenu->mPendingWiFiState = 8;
                break;
            case 2:
                gWiFiTopMenu->mPendingWiFiState = 13;
                break;
        }
        StartSoundOncePerFrame(5);
    } else {
        if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
            gWiFiTopMenu->mIndex--;
            if (gWiFiTopMenu->mIndex < 0) {
                gWiFiTopMenu->mIndex = 2;
            }
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
            gWiFiTopMenu->mIndex++;
            if (gWiFiTopMenu->mIndex > 2) {
                gWiFiTopMenu->mIndex = 0;
            }
            StartSoundOncePerFrame(0);
        }
    }
}

void AdvanceWiFiTopMenuState4(void) {
    s32 i;
    s32 v;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    v = func_020ae488(gWiFiTopMenu->mStateFrames);
    for (i = 0; i < data_ov000_021b05cc[gWiFiTopMenu->mIndex]; i++) {
        gWiFiTopMenu->mWiFiTopMenuTable[data_ov000_021b05d8[gWiFiTopMenu->mIndex][i]].mOffsetX = v;
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        gWiFiTopMenu->mNextState = 5;
        if (gWiFiTopMenu->mIndex == 0 || gWiFiTopMenu->mIndex == 2) {
            RequestSelectReturnState4();
        }
        gWiFiTopMenu->mStateFrames = 0;
    } else if (gWiFiTopMenu->mStateFrames >= 5) {
        gWiFiTopMenu->mUnk_18 = TRUE;
    }
}

void AdvanceWiFiTopMenuState5(void) {
    s32 i;
    s32 j;
    s32 v;
    if (GetWiFiNextScene() == -1) {
        if (gWiFiTopMenu->mPendingWiFiState == 10 && GetWiFiSessionLoginResult() != 1) {
            SetWiFiNextScene(0);
        } else if (gWiFiTopMenu->mPendingWiFiState == 13) {
            data_021759d0->mUnk_20 = 4;
            SetWiFiNextScene(12);
        }
    }
    gWiFiTopMenu->mStateFrames++;
    v = gWiFiTopMenu->mStateFrames;
    if (v <= 10) {
        v = InterpolateS16(1, 0xdc, 0, 10 - v, 10);
    } else {
        v = 0xdc;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            gWiFiTopMenu->mWiFiTopMenuTable[data_ov000_021b05d8[i][j]].mOffsetX = v;
        }
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        if ((gWiFiTopMenu->mPendingWiFiState == 10 || gWiFiTopMenu->mPendingWiFiState == 13) &&
            IsSelectReturnState0NoState1Request() == 0) {
            return;
        }
        if (GetWiFiNextScene() == -1) {
            if (gWiFiTopMenu->mPendingWiFiState == 8 && func_ov000_02181df0() == 0) {
                gWiFiTopMenu->mNextState = 8;
                gWiFiTopMenu->mPendingWiFiState = -1;
                func_021266e4(GetBmgEntry(gWiFiTopMenu->mWiFiMessages, 0x12));
                gWiFiTopMenu->mStateFrames = 0;
                SetSelectReturnSoundId(0xe);
                return;
            }
            RequestWiFiState(gWiFiTopMenu->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiTopMenuState6(void) {
    int v1;
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        RequestTxtSystemClose();
        return;
    }
    v1 = IsTxtSystemState0NoOpenRequest();
    if (v1 != 0) {
        v1 = GetTxtSystemSelectedIndex();
        if (v1 == 0) {
            func_0211fd28();
            gWiFiTopMenu->mNextState = 7;
            return;
        }
        gWiFiTopMenu->mNextState = 1;
    }
}

void AdvanceWiFiTopMenuState7(void) {
    int v1;
    v1 = GetWiFiNextScene();
    if ((v1 == -1) && (gWiFiTopMenu->mPendingWiFiState == 10)) {
        SetWiFiNextScene(0);
    }
    v1 = GetWiFiSessionLoginResult();
    if (v1 != 1) {
        gWiFiTopMenu->mPendingWiFiState = 10;
    }
}

void AdvanceWiFiTopMenuState8(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    BOOL b;
    u32 v;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
    }
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_B) == 0) {
            a = b = FALSE;
            v = data_02175628[i].mHasPair;
            if (v == 0 && data_02175628[i].mNoPairCount < 5) {
                a = 1;
            }
            if (a == 0 && data_02175628[i].mPrevHasPair == 0 && v != 0) {
                b = TRUE;
            }
            if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                              data_02175628[i].mPairY) == FALSE) {
                return;
            }
        }
        gWiFiTopMenu->mNextState = 1;
        RequestSelectReturnState3WithSound(0);
        RequestTxtSystemClose();
    }
}

void func_ov000_021817e8(void) {
    s32 i = 0;
    BOOL v1 = FALSE;
    const u8 *p = data_ov000_021b05c4;
    const u8 *q = data_ov000_021b05c8;
    for (; i < 3; i++) {
        if (i == gWiFiTopMenu->mIndex && gWiFiTopMenu->mUnk_18 != FALSE) {
            gWiFiTopMenu->mWiFiTopMenuTable[*p].mVisible = 1;
            SetCellPaletteIndex(*q, 0xe, gWiFiTopMenu->mWiFiTopMenuSNcer, gWiFiTopMenu->mWiFiTopMenuBncl);
        } else {
            gWiFiTopMenu->mWiFiTopMenuTable[*p].mVisible = v1;
            SetCellPaletteIndex(*q, 0xf, gWiFiTopMenu->mWiFiTopMenuSNcer, gWiFiTopMenu->mWiFiTopMenuBncl);
        }
        p++;
        q++;
    }
}

void AdvanceWiFiTopMenu(void) {
    WiFiTopMenu *p;
    gWiFiTopMenu->mState = gWiFiTopMenu->mNextState;
    switch (gWiFiTopMenu->mState) {
        case 0:
            AdvanceWiFiTopMenuState0();
            break;
        case 1:
            AdvanceWiFiTopMenuState1();
            break;
        case 2:
            AdvanceWiFiTopMenuState2();
            break;
        case 3:
            AdvanceWiFiTopMenuState3();
            break;
        case 4:
            AdvanceWiFiTopMenuState4();
            break;
        case 5:
            AdvanceWiFiTopMenuState5();
            break;
        case 6:
            AdvanceWiFiTopMenuState6();
            break;
        case 7:
            AdvanceWiFiTopMenuState7();
            break;
        case 8:
            AdvanceWiFiTopMenuState8();
            break;
    }
    func_ov000_021817e8();
    p = gWiFiTopMenu;
    DrawLayoutTable(p->mWiFiTopMenuBncl, p->mWiFiTopMenuSNcer, NULL, func_ov000_021804e0(), p->mWiFiTopMenuTable);
}

void func_ov000_02181738(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterWiFiTopMenuCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiTopMenuCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
