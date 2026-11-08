#include "01/code_021932e4.h"
#include "code_0214a390.h"
#include "registers.h"

#include "01/code_02195000.h"
#include "01/code_0219e824.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"

OptionTopMenu *gOptionTopMenu;

void InitOptionTopMenu(void *heap) {
    s32 i;
    s32 j;

    gOptionTopMenu = HeapAlloc(heap, 0x40);
    gOptionTopMenu->mUnk_1c = heap;
    gOptionTopMenu->mState = 0;
    gOptionTopMenu->mNextState = 0;
    switch (GetOptionPrevState()) {
        case 1:
        case 4:
            gOptionTopMenu->mIndex = 0;
            break;
        case 2:
            gOptionTopMenu->mIndex = 1;
            break;
    }
    gOptionTopMenu->mStateFrames = 0;
    gOptionTopMenu->mUnk_14 = TRUE;
    gOptionTopMenu->mOptionMessages = FindSceneFile(data_ov001_021a8254);
    gOptionTopMenu->mCommonMessages = FindFileInLoadedArchives(data_ov001_021a8260);
    if (GetOptionPrevState() == 1) {
        gOptionTopMenu->mBg0Offset = 0x32;
    } else {
        gOptionTopMenu->mBg0Offset = 0;
    }
    LocateAndQueueOptionTopMenu();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a65dc[i], 1, gOptionTopMenu->mOptionTopMenuSNcer,
                      gOptionTopMenu->mOptionTopMenuSBncl);
    }
    func_020ae6d4(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    InitLayoutTable(heap, gOptionTopMenu->mOptionTopMenuSBncl, NULL, &gOptionTopMenu->mOptionTopMenuSTable);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = 250;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -250;
            }
        }
    }
    SetSelectReturnSoundId(0xf);
}

void ReleaseOptionTopMenu(void) {
    gOptionTopMenu = NULL;
}

void LocateAndQueueOptionTopMenu(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile(data_ov001_021a8180));
    LocateNscr(&b, FindSceneFile(data_ov001_021a819c));
    LocateNclr(&c, FindSceneFile(data_ov001_021a81b4));
    gOptionTopMenu->mOptionTopMenuSBncl = FindSceneFile(data_ov001_021a81d0);
    gOptionTopMenu->mOptionTopMenuSBnbl = FindSceneFile(data_ov001_021a81e8);
    LocateNcgr2(&gOptionTopMenu->mOptionTopMenuSNcgr, FindSceneFile(data_ov001_021a8200));
    LocateNcer(&gOptionTopMenu->mOptionTopMenuSNcer, FindSceneFile(data_ov001_021a821c));
    LocateNclr(&gOptionTopMenu->mOptionTopMenuSONclr, FindSceneFile(data_ov001_021a8238));
    CallQueueAppend(4, 0, a->mData, a->mDataSize);
    CallQueueAppend(8, 0, b->mData, b->mDataSize);
    CallQueueAppend(15, 0, c->mData, 0x100);
    CallQueueAppend(0x23, 0, gOptionTopMenu->mOptionTopMenuSNcgr->mData,
                    gOptionTopMenu->mOptionTopMenuSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, gOptionTopMenu->mOptionTopMenuSONclr->mData,
                    gOptionTopMenu->mOptionTopMenuSONclr->mDataSize);
}

void AdvanceOptionTopMenuState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        gOptionTopMenu->mNextState = 1;
    }
}

void AdvanceOptionTopMenuState1(void) {
    s32 amount;
    s32 i;
    s32 j;

    gOptionTopMenu->mStateFrames++;
    amount = InterpolateS16(1, 250, 0, gOptionTopMenu->mStateFrames, 10);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (GetOptionPrevState() == 1 && gOptionTopMenu->mIndex != 2) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 50, 0, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = 2;
        gOptionTopMenu->mStateFrames = 0;
        RequestSelectReturnState1();
    }
}

void AdvanceOptionTopMenuState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gOptionTopMenu->mNextState = 3;
    }
}

void AdvanceOptionTopMenuState3(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u32 result = -1;
    BOOL b = FALSE;
    BOOL a = FALSE;
    u16 flagA;
    s32 old;
    s32 flagB;

    if (data_02175628[idx].mHasPair == 0 && data_02175628[idx].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && data_02175628[idx].mPrevHasPair == 0 && data_02175628[idx].mHasPair != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        result = RectTableFindContaining(gOptionTopMenu->mOptionTopMenuSBnbl, data_02175628[idx].mPairX,
                                         data_02175628[idx].mPairY);
    }
    flagA = data_02175628[idx].mUnk_00 & PAD_KEY_B;
    if (flagA == 0) {
        BOOL b2 = FALSE;
        BOOL a2 = FALSE;
        if (data_02175628[idx].mHasPair == 0 && data_02175628[idx].mNoPairCount < 5) {
            a2 = TRUE;
        }
        if (a2 == FALSE && data_02175628[idx].mPrevHasPair == 0 && data_02175628[idx].mHasPair != 0) {
            b2 = TRUE;
        }
        if (b2 != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mPairX,
                                                                           data_02175628[idx].mPairY) != FALSE) {
            goto leave;
        }
    } else {
    leave:
        gOptionTopMenu->mNextState = 5;
        gOptionTopMenu->mNextOptionState = 4;
        RequestSelectReturnState3WithSound(1);
        return;
    }
    flagB = data_02175628[idx].mUnk_00 & PAD_KEY_A;
    if ((u16) flagB != 0 || result <= 2) {
        old = gOptionTopMenu->mIndex;
        if ((u16) flagB == 0) {
            switch (result) {
                case 0:
                    gOptionTopMenu->mIndex = 0;
                    break;
                case 1:
                    gOptionTopMenu->mIndex = 1;
                    break;
                case 2:
                    gOptionTopMenu->mIndex = 2;
                    break;
            }
        }
        gOptionTopMenu->mNextState = 4;
        switch (gOptionTopMenu->mIndex) {
            case 0:
                gOptionTopMenu->mNextOptionState = 1;
                break;
            case 1:
                gOptionTopMenu->mNextOptionState = 2;
                break;
            case 2:
                break;
        }
        if (gOptionTopMenu->mIndex == old) {
            gOptionTopMenu->mUnk_14 = FALSE;
        }
        StartSoundOncePerFrame(5);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gOptionTopMenu->mIndex--;
        if (gOptionTopMenu->mIndex < 0) {
            gOptionTopMenu->mIndex = 2;
        }
        StartSoundOncePerFrame(0);
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gOptionTopMenu->mIndex++;
        if (gOptionTopMenu->mIndex > 2) {
            gOptionTopMenu->mIndex = 0;
        }
        StartSoundOncePerFrame(0);
    }
}

void AdvanceOptionTopMenuState4(void) {
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames >= 10) {
        gOptionTopMenu->mNextState = 5;
        gOptionTopMenu->mStateFrames = 0;
        if (gOptionTopMenu->mIndex == 2) {
            RequestSelectReturnState4();
        }
    } else if (gOptionTopMenu->mStateFrames >= 5) {
        gOptionTopMenu->mUnk_14 = TRUE;
    }
}

void AdvanceOptionTopMenuState5(void) {
    s32 amount;
    s32 i;
    s32 j;

    if (func_ov001_02192e84() == -1 && gOptionTopMenu->mNextOptionState == 4) {
        func_ov001_02192e78(0);
    }
    gOptionTopMenu->mStateFrames++;
    if (gOptionTopMenu->mStateFrames <= 10) {
        amount = InterpolateS16(1, 0, 250, gOptionTopMenu->mStateFrames, 10);
    } else {
        amount = 250;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = amount;
            } else {
                gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65f0[i][j]].mOffsetX = -amount;
            }
        }
    }
    if (gOptionTopMenu->mNextOptionState == 1) {
        gOptionTopMenu->mBg0Offset = InterpolateS16(1, 0, 50, gOptionTopMenu->mStateFrames, 10);
    }
    if (gOptionTopMenu->mStateFrames >= 10 &&
        (gOptionTopMenu->mIndex != 2 || IsSelectReturnState0NoState1Request() != 0) && func_ov001_02192e84() == -1) {
        if (gOptionTopMenu->mIndex == 2) {
            gOptionTopMenu->mNextState = 6;
            gOptionTopMenu->mStateFrames = 0;
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 3),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
        } else {
            RequestOptionState(gOptionTopMenu->mNextOptionState);
        }
    }
}

void AdvanceOptionTopMenuState6(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            SetupTxtSystemSubTextTwoButtons(GetBmgEntry(gOptionTopMenu->mOptionMessages, 4),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 0),
                                            GetBmgEntry(gOptionTopMenu->mCommonMessages, 1), 1);
            gOptionTopMenu->mNextState = 7;
        } else {
            gOptionTopMenu->mNextState = 1;
        }
    }
}

void AdvanceOptionTopMenuState7(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            func_02057130();
            gOptionTopMenu->mNextState = 8;
            SetupTxtSystemSubTextEx(GetBmgEntry(gOptionTopMenu->mOptionMessages, 5), 1, 1, 1, 0, 1);
        } else {
            gOptionTopMenu->mNextState = 1;
        }
    }
}

void AdvanceOptionTopMenuState8(void) {
    s32 flag;

    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x22);
    }
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mBackupEnabled != 0) {
            flag = data_021759d4->mCommandRunning;
        } else {
            flag = 0;
        }
    } else {
        flag = 1;
    }
    if (flag == 0 && IsTxtSystemState2NoCloseRequest() != 0) {
        gOptionTopMenu->mNextState = 9;
        SetTxtSystemOpenSoundId(0x21);
        SetupTxtSystemSubTextButton(GetBmgEntry(gOptionTopMenu->mOptionMessages, 6),
                                    GetBmgEntry(gOptionTopMenu->mCommonMessages, 4));
    }
}

void AdvanceOptionTopMenuState9(void) {
    int v1;
    v1 = func_ov001_02192e84();
    if ((v1 == -1) && (gOptionTopMenu->mNextOptionState == 4)) {
        func_ov001_02192e78(0);
    }
    v1 = GetTxtSystemDone();
    if (v1 != 0) {
        SetTxtSystemOpenSoundId(0x23);
        RequestTxtSystemClose();
        gOptionTopMenu->mNextOptionState = 4;
    }
}

void func_ov001_021933dc(void) {
    int i;
    BOOL zero = FALSE;

    for (i = 0; i < 3; i++) {
        if (i == gOptionTopMenu->mIndex && gOptionTopMenu->mUnk_14 != FALSE) {
            gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65e0[i]].mVisible = 1;
            func_02124a20(data_ov001_021a65d8[i], 14, gOptionTopMenu->mOptionTopMenuSNcer,
                          gOptionTopMenu->mOptionTopMenuSBncl);
        } else {
            gOptionTopMenu->mOptionTopMenuSTable[data_ov001_021a65e0[i]].mVisible = zero;
            func_02124a20(data_ov001_021a65d8[i], 15, gOptionTopMenu->mOptionTopMenuSNcer,
                          gOptionTopMenu->mOptionTopMenuSBncl);
        }
    }
}

void AdvanceOptionTopMenu(void) {
    OptionTopMenu *obj;

    gOptionTopMenu->mState = gOptionTopMenu->mNextState;
    switch (gOptionTopMenu->mState) {
        case 0:
            AdvanceOptionTopMenuState0();
            break;
        case 1:
            AdvanceOptionTopMenuState1();
            break;
        case 2:
            AdvanceOptionTopMenuState2();
            break;
        case 3:
            AdvanceOptionTopMenuState3();
            break;
        case 4:
            AdvanceOptionTopMenuState4();
            break;
        case 5:
            AdvanceOptionTopMenuState5();
            break;
        case 6:
            AdvanceOptionTopMenuState6();
            break;
        case 7:
            AdvanceOptionTopMenuState7();
            break;
        case 8:
            AdvanceOptionTopMenuState8();
            break;
        case 9:
            AdvanceOptionTopMenuState9();
            break;
    }
    func_ov001_021933dc();
    obj = gOptionTopMenu;
    DrawLayoutTable(obj->mOptionTopMenuSBncl, obj->mOptionTopMenuSNcer, NULL, GetOptionSecondBuffer(),
                    obj->mOptionTopMenuSTable);
}

void func_ov001_02193308(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG0OFS = gOptionTopMenu->mBg0Offset << 0x10 & (0x01ff0000u);
}

void RegisterOptionTopMenuCallbacks(void) {
    OptionStateCallbacks callbacks = gOptionTopMenuCallbacks;

    SetOptionStateCallbacks((UnkFunc **) &callbacks);
}
