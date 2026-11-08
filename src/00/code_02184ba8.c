#include "00/code_02184ba8.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0214a000.h"
#include "00/unk_021b0000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "code_0214a390.h"
#include "code_0214b824.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212630c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02047104.h"

void InitWiFiAikotoba(void *a) {
    s32 i;
    s32 j;
    u32 b;
    void *c;

    gWiFiAikotoba = HeapAlloc(a, 0x40);
    gWiFiAikotoba->mHeap = a;
    gWiFiAikotoba->mState = 0;
    gWiFiAikotoba->mNextState = 0;
    gWiFiAikotoba->mPendingWiFiState = -1;
    b = GetWiFiPrevState();
    switch (b) {
        case 1:
        case 11:
            gWiFiAikotoba->mUnk_08 = 0;
            break;
        case 9:
            gWiFiAikotoba->mUnk_08 = 1;
            break;
    }
    gWiFiAikotoba->mStateFrames = 0;
    gWiFiAikotoba->mUnk_14 = TRUE;
    LocateAndUploadWiFiAikotoba();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b06c0[i], 1, gWiFiAikotoba->mWiFiAikotobaSNcer, gWiFiAikotoba->mWiFiAikotobaBncl);
    }
    c = func_ov000_021804f4();
    func_020ae6d4(c, func_ov000_021804e0());
    InitLayoutTable(a, gWiFiAikotoba->mWiFiAikotobaBncl, NULL, &gWiFiAikotoba->mWiFiAikotobaTable);
    gWiFiAikotoba->mWiFiMessages = FindSceneFile(data_ov000_021b0ee8);
    gWiFiAikotoba->mCommonMessages = FindFileInLoadedArchives(data_ov000_021b0ef4);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06d0[i][j]].mOffsetX = 0xfa;
        }
    }
    SetSelectReturnSoundId(0xe);
}

void func_ov000_02185230(void) {
    gWiFiAikotoba = NULL;
}

void LocateAndUploadWiFiAikotoba(void) {
    void *v1;
    v1 = FindSceneFile(gWiFiAikotobaBnclName);
    gWiFiAikotoba->mWiFiAikotobaBncl = v1;
    v1 = FindSceneFile(gWiFiAikotobaBnblName);
    gWiFiAikotoba->mWiFiAikotobaBnbl = v1;
    v1 = FindSceneFile(gWiFiAikotobaSNcgrName);
    LocateNcgr2(&gWiFiAikotoba->mWiFiAikotobaSNcgr, v1);
    v1 = FindSceneFile(gWiFiAikotobaSNcerName);
    LocateNcer(&gWiFiAikotoba->mWiFiAikotobaSNcer, v1);
    v1 = FindSceneFile(gWiFiAikotobaSONclrName);
    LocateNclr(&gWiFiAikotoba->mWiFiAikotobaSONclr, v1);
    GXS_LoadOBJ(gWiFiAikotoba->mWiFiAikotobaSNcgr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSNcgr->mDataSize);
    GXS_LoadOBJPltt(gWiFiAikotoba->mWiFiAikotobaSONclr->mData, 0, gWiFiAikotoba->mWiFiAikotobaSONclr->mDataSize);
}

u32 func_ov000_02185184(void) {
    u32 v1;
    v1 = CountEmblemEntries();
    if (60 <= v1) {
        return 1;
    }
    return 0;
}

void AdvanceWiFiAikotobaState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        gWiFiAikotoba->mNextState = 1;
    }
}

void AdvanceWiFiAikotobaState1(void) {
    s32 a;
    s32 i;
    s32 j;

    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    a = InterpolateS16(1, 0xfa, 0, gWiFiAikotoba->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06d0[i][j]].mOffsetX = a;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06d0[i][j]].mOffsetX = -a;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = 2;
        gWiFiAikotoba->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceWiFiAikotobaState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gWiFiAikotoba->mNextState = 3;
    }
}

void AdvanceWiFiAikotobaState3(void) {
    InputSlotIndex i = UNK_02175628_INDEX_8;
    u32 a = -1;
    BOOL b;
    BOOL c;
    u16 d;
    s32 f;
    u32 e;
    WiFiAikotoba *p;

    b = FALSE;
    c = FALSE;
    d = data_02175628[i].mHasPair;
    if (d == 0 && data_02175628[i].mNoPairCount < 5) {
        c = TRUE;
    }
    if (c == FALSE && data_02175628[i].mPrevHasPair == 0 && d != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        a = RectTableFindContaining(gWiFiAikotoba->mWiFiAikotobaBnbl, data_02175628[i].mPairX, data_02175628[i].mPairY);
    }
    if ((u16) (data_02175628[i].mPressedBits & PAD_KEY_B) == 0) {
        b = FALSE;
        c = FALSE;
        d = data_02175628[i].mHasPair;
        if (d == 0 && data_02175628[i].mNoPairCount < 5) {
            c = TRUE;
        }
        if (c == FALSE && data_02175628[i].mPrevHasPair == 0 && d != 0) {
            b = TRUE;
        }
        if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                          data_02175628[i].mPairY) == FALSE) {
            goto next;
        }
    }
    gWiFiAikotoba->mNextState = 5;
    gWiFiAikotoba->mPendingWiFiState = 1;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    e = data_02175628[i].mPressedBits & PAD_KEY_A;
    if ((u16) e != 0 || a <= 1) {
        p = gWiFiAikotoba;
        f = p->mUnk_08;
        if ((u16) e == 0) {
            switch (a) {
                case 0:
                    p->mUnk_08 = 0;
                    break;
                case 1:
                    p->mUnk_08 = 1;
                    break;
            }
        }
        gWiFiAikotoba->mNextState = 4;
        switch (gWiFiAikotoba->mUnk_08) {
            case 0:
                gWiFiAikotoba->mPendingWiFiState = 11;
                break;
            case 1:
                gWiFiAikotoba->mPendingWiFiState = 9;
                break;
        }
        if (gWiFiAikotoba->mUnk_08 == f) {
            gWiFiAikotoba->mUnk_14 = FALSE;
        }
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0 && gWiFiAikotoba->mUnk_08 > 0) {
        gWiFiAikotoba->mUnk_08 = gWiFiAikotoba->mUnk_08 - 1;
        StartSoundOncePerFrame(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0 && gWiFiAikotoba->mUnk_08 < 1) {
        gWiFiAikotoba->mUnk_08 = gWiFiAikotoba->mUnk_08 + 1;
        StartSoundOncePerFrame(0);
    }
}

void AdvanceWiFiAikotobaState4(void) {
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames >= 10) {
        gWiFiAikotoba->mNextState = 5;
        if (gWiFiAikotoba->mPendingWiFiState == 11) {
            RequestSelectReturnState4();
        }
        gWiFiAikotoba->mStateFrames = 0;
    } else if (gWiFiAikotoba->mStateFrames >= 5) {
        gWiFiAikotoba->mUnk_14 = TRUE;
    }
}

void AdvanceWiFiAikotobaState5(void) {
    s32 a;
    s32 i;
    s32 j;
    s32 b;
    void *c;

    if (GetWiFiNextScene() == -1 && func_ov000_02185184() == 0 && gWiFiAikotoba->mPendingWiFiState == 11) {
        SetWiFiNextScene(0xe);
    }
    gWiFiAikotoba->mStateFrames = gWiFiAikotoba->mStateFrames + 1;
    if (gWiFiAikotoba->mStateFrames <= 10) {
        a = InterpolateS16(1, 0, 0xfa, gWiFiAikotoba->mStateFrames, 10);
    } else {
        a = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06d0[i][j]].mOffsetX = a;
            } else {
                gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06d0[i][j]].mOffsetX = -a;
            }
        }
    }
    if (gWiFiAikotoba->mStateFrames >= 10) {
        if (func_ov000_02185184() != 0 && gWiFiAikotoba->mPendingWiFiState == 11) {
            gWiFiAikotoba->mNextState = 6;
            gWiFiAikotoba->mPendingWiFiState = -1;
            c = GetBmgEntry(gWiFiAikotoba->mWiFiMessages, 0xf);
            SetupTxtSystemMainTextButton(c, GetBmgEntry(gWiFiAikotoba->mCommonMessages, 6));
            gWiFiAikotoba->mStateFrames = 0;
            return;
        }
        if (GetWiFiNextScene() == -1) {
            RequestWiFiState(gWiFiAikotoba->mPendingWiFiState);
        }
    }
}

void AdvanceWiFiAikotobaState6(void) {
    void *a;
    void *b;

    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState0NoState1Request() != 0) {
        gWiFiAikotoba->mNextState = 7;
        a = GetBmgEntry(gWiFiAikotoba->mWiFiMessages, 0x10);
        b = GetBmgEntry(gWiFiAikotoba->mCommonMessages, 0);
        SetupTxtSystemMainTextTwoButtons(a, b, GetBmgEntry(gWiFiAikotoba->mCommonMessages, 1), 0);
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
}

void AdvanceWiFiAikotobaState7(void) {
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gWiFiAikotoba->mPendingWiFiState = 0xe;
            if (GetWiFiNextScene() == -1) {
                SetWiFiNextScene(8);
            }
            data_0217b488->mUnk_50 = 1;
            return;
        }
        gWiFiAikotoba->mNextState = 1;
        gWiFiAikotoba->mPendingWiFiState = -1;
        return;
    }
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
}

void func_ov000_02184c74(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == gWiFiAikotoba->mUnk_08 && gWiFiAikotoba->mUnk_14 != FALSE) {
            gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06c4[i]].mVisible = 1;
            SetCellPaletteIndex(data_ov000_021b06bc[i], 0xe, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        } else {
            gWiFiAikotoba->mWiFiAikotobaTable[data_ov000_021b06c4[i]].mVisible = 0;
            SetCellPaletteIndex(data_ov000_021b06bc[i], 0xf, gWiFiAikotoba->mWiFiAikotobaSNcer,
                                gWiFiAikotoba->mWiFiAikotobaBncl);
        }
    }
}

void AdvanceWiFiAikotoba(void) {
    WiFiAikotoba *p;

    gWiFiAikotoba->mState = gWiFiAikotoba->mNextState;
    switch (gWiFiAikotoba->mState) {
        case 0:
            AdvanceWiFiAikotobaState0();
            break;
        case 1:
            AdvanceWiFiAikotobaState1();
            break;
        case 2:
            AdvanceWiFiAikotobaState2();
            break;
        case 3:
            AdvanceWiFiAikotobaState3();
            break;
        case 4:
            AdvanceWiFiAikotobaState4();
            break;
        case 5:
            AdvanceWiFiAikotobaState5();
            break;
        case 6:
            AdvanceWiFiAikotobaState6();
            break;
        case 7:
            AdvanceWiFiAikotobaState7();
            break;
    }
    func_ov000_02184c74();
    p = gWiFiAikotoba;
    DrawLayoutTable(p->mWiFiAikotobaBncl, p->mWiFiAikotobaSNcer, NULL, func_ov000_021804e0(), p->mWiFiAikotobaTable);
}

void func_ov000_02184bcc(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterWiFiAikotobaCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiAikotobaCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
