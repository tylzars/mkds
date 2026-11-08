#include "Main/Unknown/code_0212898c.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_020ab748.h"
#include "Main/Unknown/code_020ab758.h"
#include "Main/Unknown/code_020ab8c4.h"
#include "Main/Unknown/code_020ab94c.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02129ea4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020ab798.h"
#include "code_0201ea58.h"
#include "code_0214cfe4.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020aba9c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ab7a4.h"
#include "Main/Unknown/code_020ab8d4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0212abd0.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "Main/Unknown/code_021262f0.h"
#include "code_0214a054.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020ab848.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_020aba94.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212a700.h"
#include "Main/Unknown/code_0212a724.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

#pragma thumb on

void SetKeyboardButtonCorners(void) {
    SetKeyboardButton0Corners(0x24, 0x7a, 0x7e, 0x8e);
    SetKeyboardButton1Corners(0x82, 0x7a, 0xdc, 0x8e);
}

#pragma thumb off

#pragma thumb on

void PrintKeyboardButtonTexts(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        Keyboard *p = gKeyboard;
        func_0212426c(1, data_0215d0e4[i][0], gKeyboard->mBnlls[i], GetBmgEntry(p->mCommonMessages, 4), p->mBncls[i],
                      p->mTables[i][1]);
        p = gKeyboard;
        func_0212426c(1, data_0215d0e4[i][1], gKeyboard->mBnlls[i], GetBmgEntry(p->mCommonMessages, 5), p->mBncls[i],
                      p->mTables[i][1]);
    }
}

void InitKeyboardCursorCorners(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 4; k++) {
                LayoutTableEntry *p = &gKeyboard->mTables[i][j][data_0215d0f8[i][k]];
                p->mUnk_08 = TRUE;
                p->mPositionX = 0;
                p->mPositionY = 0;
            }
        }
    }
}

void func_0212a4f4(void) {
    s32 i;
    s32 j;
    s32 k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                gKeyboard->mTables[i][0][data_0215d128[i][j][k]].mVisible = 0;
            }
            gKeyboard->mTables[i][0][data_0215d0e4[i][j] + gKeyboard->mBncls[i]->mUnk_06].mVisible = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < gKeyboardTextLimits[i]; j++) {
            gKeyboard->mTables[i][0][data_0215d14c[i][j]].mVisible = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (k = 0; k < 4; k++) {
            gKeyboard->mTables[i][0][data_0215d0f8[i][k]].mVisible = 0;
        }
    }
    for (j = 0; j < 10; j++) {
        gKeyboard->mTables[1][0][data_0215d110[j]].mVisible = 0;
    }
}

void SetKeyboardTextFromFriendKey(void) {
    u16 a[12];
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x1a);
    MIi_CpuCopy16(&gKeyboard->mUnk_2c[0], &a[1], 0x18);
    SetKeyboardText(&a[1]);
}

void SetKeyboardTextFromName(void) {
    u16 a[12];
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x16);
    MIi_CpuCopy16(&gKeyboard->mUnk_2c[1], &a[1], 0x14);
    SetKeyboardText(&a[1]);
}

void func_0212a448(void) {
    u16 a[12];
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x16);
    MIi_CpuCopy16(data_0217aa08->mUnk_00->mUnk_0c, &a[1], 0x14);
    SetKeyboardText(&a[1]);
}

void CopyKeyboardTextAsBytes(void) {
    s32 i;
    MI_CpuFill8(&gKeyboard->mUnk_2c[2], 0, 0xd);
    for (i = 0; i < 12; i++) {
        ((u8 *) &gKeyboard->mUnk_2c[2])[i] = gKeyboard->mUnk_2c[0].mChars[i];
    }
}

void InitKeyboard(void *a, s32 b) {
    volatile u16 d;
    Unk02125de0Arg c;
    s32 i;
    s32 j;
    gKeyboard = HeapAlloc(a, 0xc4);
    gKeyboard->mHeap = a;
    gKeyboard->mUnk_bc = func_021250b0(a);
    func_0212abdc(a, GetKeyboardFirstBuffer());
    c.mUnk_00 = 1;
    c.mUnk_04 = func_020b403c(1);
    c.mUnk_08 = 0;
    c.mUnk_0c = 1;
    c.mUnk_10 = 0;
    c.mUnk_14 = 0;
    c.mUnk_18 = NULL;
    c.mUnk_1c = 0;
    c.mUnk_20 = 1;
    if (b == 0xc) {
        c.mUnk_24 = 1;
    } else {
        c.mUnk_24 = 0;
    }
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &c);
    func_02129c18();
    LoadKeyboardFiles();
    func_020ae6d4(GetKeyboardFirstBuffer(), GetKeyboardSecondBuffer());
    InitKeyboardTextEntry(0x20, 0x40, 0xc);
    SetKeyboardOffset(0, 0x28);
    SetKeyboardButtonCorners();
    func_020aba94(0);
    gKeyboard->mUnk_2c[2].mMode = b;
    gKeyboard->mUnk_2c[2].mNextScene = -1;
    if (b == 0xc) {
        gKeyboard->mKind = 0;
        gKeyboard->mState = 0;
        gKeyboard->mButtonEnabled[0] = 0;
        gKeyboard->mButtonEnabled[1] = 1;
    } else {
        gKeyboard->mKind = 1;
        gKeyboard->mState = 5;
        gKeyboard->mButtonEnabled[0] = 1;
        if (b == 0xb) {
            gKeyboard->mButtonEnabled[1] = 0;
        } else {
            gKeyboard->mButtonEnabled[1] = 1;
        }
        func_0212a448();
    }
    if (gKeyboard->mKind == 0) {
        gKeyboard->mLayout = 0;
        SetKeyboardTextLimit(gKeyboardTextLimits[0]);
    } else {
        if (data_021759d0->mUnk_00 == 0) {
            gKeyboard->mLayout = 1;
        } else {
            gKeyboard->mLayout = 2;
        }
        SetKeyboardTextLimit(gKeyboardTextLimits[1]);
    }
    SelectKeyboardLayout(gKeyboard->mLayout);
    QueueKeyboardScreenMap();
    for (i = 0; i < 2; i++) {
        gKeyboard->mCursorOnButton[i] = 0;
    }
    gKeyboard->mTextEntryEnabled = FALSE;
    gKeyboard->mNextState = gKeyboard->mState;
    gKeyboard->mStateFrames = 0;
    gKeyboard->mOffsetY = 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gKeyboard->mTextOffsetY[i][j] = data_0215d108[i][j];
        }
    }
    gKeyboard->mCommonMessages = FindFileInLoadedArchives(data_0216ea60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            InitLayoutTable(a, gKeyboard->mBncls[i], gKeyboard->mBnlls[i], &gKeyboard->mTables[i][j]);
        }
    }
    InitKeyboardCursorCorners();
    for (i = 0; i < 2; i++) {
        d = 0;
        MIi_CpuClear16(d, &gKeyboard->mUnk_2c[i], 0x18);
    }
    func_0212a724();
    PrintKeyboardButtonTexts();
    func_0212a4f4();
    WriteKeyboardObjectOffsets();
}
#pragma thumb off

#pragma thumb on

void ReleaseKeyboard(void) {
    func_0212abd0();
    func_02125da0();
    *(u32 *) &gKeyboard = 0;
}

#pragma thumb off

#pragma thumb on
void WriteKeyboardObjectOffsets(void) {
    u16 e[2];
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s16 v;
    s16 w;
    for (i = 0; i < 2; i++) {
        e[i] = gKeyboard->mBncls[i]->mUnk_06;
        for (j = 0; j < 2; j++) {
            v = -500;
            if (i == 1 || gKeyboard->mUnk_2c[2].mMode == 0xc) {
                v = gKeyboard->mTextOffsetY[i][j];
            }
            for (k = 0; k < data_0215d0d8[i]; k++) {
                gKeyboard->mTables[i][j][data_0215d0dc[i][k]].mOffsetY = v;
            }
            for (k = 0; k < gKeyboardTextLimits[i]; k++) {
                gKeyboard->mTables[i][j][data_0215d14c[i][k]].mOffsetY = v;
                (gKeyboard->mTables[i][j] + e[i])[data_0215d134[i][k]].mOffsetY = v;
            }
            v = gKeyboard->mOffsetY;
            for (m = 0; m < 2; m++) {
                for (k = 0; k < 3; k++) {
                    gKeyboard->mTables[i][j][data_0215d128[i][m][k]].mOffsetY = v;
                }
                (gKeyboard->mTables[i][j] + e[i])[data_0215d0e4[i][m]].mOffsetY = v;
            }
            w = gKeyboard->mOffsetY;
            GetKeyboardCursorBoundsRelative(&a, &b, &c, &d);
            gKeyboard->mTables[i][j][data_0215d0f8[i][0]].mPositionX = a;
            gKeyboard->mTables[i][j][data_0215d0f8[i][0]].mPositionY = w + b + 0x28;
            gKeyboard->mTables[i][j][data_0215d0f8[i][1]].mPositionX = a;
            gKeyboard->mTables[i][j][data_0215d0f8[i][1]].mPositionY = w + d + 0x28;
            gKeyboard->mTables[i][j][data_0215d0f8[i][2]].mPositionX = c;
            gKeyboard->mTables[i][j][data_0215d0f8[i][2]].mPositionY = w + b + 0x28;
            gKeyboard->mTables[i][j][data_0215d0f8[i][3]].mPositionX = c;
            gKeyboard->mTables[i][j][data_0215d0f8[i][3]].mPositionY = w + d + 0x28;
        }
    }
    for (i = 0; i < 2; i++) {
        v = -500;
        if (gKeyboard->mKind == 1 && i == 1) {
            v = gKeyboard->mOffsetY;
        }
        for (k = 0; k < 10; k++) {
            gKeyboard->mTables[1][i][data_0215d110[k]].mOffsetY = v;
        }
        v = -500;
        if (gKeyboard->mKind == 1) {
            v = gKeyboard->mTextOffsetY[1][i];
        }
        for (k = 0; k < 6; k++) {
            gKeyboard->mTables[1][i][data_0215d0f0[k]].mOffsetY = v;
        }
    }
}
#pragma thumb off

#pragma thumb on

void QueueKeyboardScreenMap(void) {
    Nscr *v1;
    v1 = gKeyboard->mNscrs[gKeyboard->mKind];
    CallQueueAppend(0x1b, 0, v1->mData, v1->mDataSize);
}

void LoadKeyboardFiles(void) {
    void *v1;
    Ncgr *v2;
    Nclr *v3;
    v1 = FindSceneFile(data_0216e940);
    gKeyboard->mBnbls[0] = v1;
    v1 = FindSceneFile(data_0216e958);
    gKeyboard->mBncls[0] = v1;
    v1 = FindSceneFile(data_0216e970);
    gKeyboard->mBnlls[0] = v1;
    v1 = FindSceneFile(data_0216e988);
    gKeyboard->mBnbls[1] = v1;
    v1 = FindSceneFile(data_0216e998);
    gKeyboard->mBncls[1] = v1;
    v1 = FindSceneFile(data_0216e9a8);
    gKeyboard->mBnlls[1] = v1;
    v1 = FindSceneFile(data_0216e9b8);
    LoadNcgrData2(&gKeyboard->mNcgr, v1);
    v1 = FindSceneFile(data_0216e9d0);
    LoadNcerData(&gKeyboard->mNcer, v1);
    v1 = FindSceneFile(data_0216e9e8);
    LoadNclrData(&gKeyboard->mNclr, v1);
    DC_FlushRange(gKeyboard->mNcgr->mData, gKeyboard->mNcgr->mDataSize);
    GX_LoadOBJ(gKeyboard->mNcgr->mData, 0, gKeyboard->mNcgr->mDataSize);
    GXS_LoadOBJ(gKeyboard->mNcgr->mData, 0, gKeyboard->mNcgr->mDataSize);
    DC_FlushRange(gKeyboard->mNclr->mData, gKeyboard->mNclr->mDataSize);
    GX_LoadOBJPltt(gKeyboard->mNclr->mData, 0, (0x000001a0u));
    GX_LoadOBJPltt(&gKeyboard->mNclr->mData[0xe0], 0x1c0, 0x40);
    GXS_LoadOBJPltt(gKeyboard->mNclr->mData, 0, gKeyboard->mNclr->mDataSize);
    v1 = FindSceneFile(data_0216e9fc);
    LoadNcgrData(&v2, v1);
    DC_FlushRange(v2->mData, v2->mDataSize);
    GXS_LoadBG3Char(v2->mData, 0, v2->mDataSize);
    v1 = FindSceneFile(data_0216ea14);
    LoadNscrData(&gKeyboard->mNscrs[0], v1);
    v1 = FindSceneFile(data_0216ea30);
    LoadNscrData(&gKeyboard->mNscrs[1], v1);
    v1 = FindSceneFile(data_0216ea4c);
    LoadNclrData(&v3, v1);
    DC_FlushRange(v3->mData, 0x80);
    GXS_LoadBGPltt(v3->mData, 0, 0x80);
}

#pragma thumb off

#pragma thumb on
void func_02129c18(void) {
    u32 t;
    reg_G2S_DB_BLDCNT = 0;
    t = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    t |= 0xc;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | (t << 8);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x8018;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x9010;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    MemFillWordsByBlock_inline((void *) G2_GetBG3ScrPtr(), 0x1000);
}

void AdvanceKeyboardState0(void) {
    if (AreBrightnessFadesClear() != 0) {
        gKeyboard->mNextState = 1;
        func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
    }
}

void UpdateKeyboardFriendKeyButtons(void) {
    s32 n;
    n = gKeyboardTextLimits[0] - 1;
    if (n == GetKeyboardTextIndex() && gKeyboard->mUnk_2c[gKeyboard->mKind].mChars[n] != 0) {
        gKeyboard->mButtonEnabled[0] = 1;
    } else {
        gKeyboard->mButtonEnabled[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 1) {
        gKeyboard->mCursorOnButton[0] = 1;
    } else {
        gKeyboard->mCursorOnButton[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 2) {
        gKeyboard->mCursorOnButton[1] = 1;
    } else {
        gKeyboard->mCursorOnButton[1] = 0;
    }
}

void AdvanceKeyboardState1(void) {
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0xc0, 0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[0][1] =
        InterpolateS16(1, data_0215d108[0][1], data_0215d100[0][1], gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState2NoCloseRequest() != 0) {
        gKeyboard->mNextState = 2;
        gKeyboard->mTextEntryEnabled = TRUE;
        gKeyboard->mStateFrames = 0;
    }
    UpdateKeyboardFriendKeyButtons();
}

void AdvanceKeyboardState2(void) {
    InputSlotIndex i = UNK_02175628_INDEX_8;
    Keyboard *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    BOOL f;
    BOOL g;
    u16 c;
    f = FALSE;
    v = -1;
    g = FALSE;
    c = data_02175674[i].mUnk_00;
    if (c == 0 && data_02175680[i].mUnk_00 < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[i].mUnk_00 == 0 && c != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        v = RectTableFindContaining(gKeyboard->mBnbls[0], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = gKeyboard;
    q = &p->mUnk_2c[p->mKind];
    w = GetKeyboardText();
    MIi_CpuCopy16(w, q, 0x18);
    UpdateKeyboardFriendKeyButtons();
    if (v == 1 || (GetKeyboardCursorValueWrapper() == 1 && (u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0)) {
        p = gKeyboard;
        if (p->mButtonEnabled[0] != 0) {
            p->mNextState = 3;
            gKeyboard->mUnk_2c[2].mUnk_10 = 1;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(1);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
    } else if (v == 0 || (GetKeyboardCursorValueWrapper() == 2 && (u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0)) {
        gKeyboard->mNextState = 3;
        gKeyboard->mUnk_2c[2].mUnk_10 = 0;
        RequestTxtSystemClose();
        MoveKeyboardCursorToValueWrapper(2);
        gKeyboard->mTextEntryEnabled = FALSE;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xe);
    }
}

void AdvanceKeyboardState3(void) {
    Keyboard *p;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0, 0xc0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[0][1] =
        InterpolateS16(1, data_0215d100[0][1], data_0215d108[0][1], gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState0NoOpenRequest() != 0) {
        p = gKeyboard;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            CopyKeyboardTextAsBytes();
            switch (func_02061104(&gKeyboard->mUnk_2c[2])) {
                case 1:
                    gKeyboard->mNextState = 4;
                    SetupTxtSystemSubText(GetBmgEntry(gKeyboard->mCommonMessages, 0xa));
                    gKeyboard->mStateFrames = 0;
                    return;
                case 2:
                    gKeyboard->mNextState = 4;
                    SetupTxtSystemSubText(GetBmgEntry(gKeyboard->mCommonMessages, 0xb));
                    gKeyboard->mStateFrames = 0;
                    return;
                default:
                    gKeyboard->mNextState = 6;
                    func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 8), 0, 0, 0, 0, 0, 0);
                    gKeyboard->mStateFrames = 0;
                    gKeyboard->mKind = 1;
                    if (data_021759d0->mUnk_00 == 0) {
                        gKeyboard->mLayout = 1;
                    } else {
                        gKeyboard->mLayout = 2;
                    }
                    SelectKeyboardLayout(gKeyboard->mLayout);
                    SetKeyboardTextLimit(gKeyboardTextLimits[1]);
                    SetKeyboardTextFromName();
                    QueueKeyboardScreenMap();
                    ShowKeyboardLayoutObject();
                    return;
            }
        } else {
            p->mUnk_2c[2].mNextScene = 0xc;
        }
    }
}

void AdvanceKeyboardState4(void) {
    Keyboard *p;
    gKeyboard->mStateFrames++;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
    }
    p = gKeyboard;
    if (p->mStateFrames >= 0x78) {
        p->mNextState = 1;
        func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
        gKeyboard->mStateFrames = 0;
    }
}

void AdvanceKeyboardState5(void) {
    if (AreBrightnessFadesClear() != 0) {
        gKeyboard->mNextState = 6;
        func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 0xf), 0, 0, 0, 0, 0, 0);
        gKeyboard->mUnk_2c[2].mUnk_10 = 1;
    }
}
#pragma thumb off

#pragma thumb on

void UpdateKeyboardNameButtons(void) {
    s32 i;
    u8 n;
    i = 0;
    gKeyboard->mButtonEnabled[0] = 0;
    for (; i < GetKeyboardTextIndex(); i++) {
        if (GetKeyboardText()[i] != 0x20 && GetKeyboardText()[i] != 0x3000) {
            gKeyboard->mButtonEnabled[0] = 1;
        }
    }
    n = gKeyboardTextLimits[1];
    if (n - 1 == GetKeyboardTextIndex()) {
        if ((GetKeyboardText() + n)[-1] != 0x20 && (GetKeyboardText() + n)[-1] != 0x3000 &&
            (GetKeyboardText() + n)[-1] != 0) {
            gKeyboard->mButtonEnabled[0] = 1;
        }
    }
    if (GetKeyboardCursorValueWrapper() == 1) {
        gKeyboard->mCursorOnButton[0] = 1;
    } else {
        gKeyboard->mCursorOnButton[0] = 0;
    }
    if (GetKeyboardCursorValueWrapper() == 2) {
        gKeyboard->mCursorOnButton[1] = 1;
        return;
    }
    gKeyboard->mCursorOnButton[1] = 0;
}

#pragma thumb off

#pragma thumb on
void AdvanceKeyboardState6(void) {
    Keyboard *p;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0xc0, 0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][1] =
        InterpolateS16(1, data_0215d108[1][1], data_0215d100[1][1], gKeyboard->mStateFrames, 0xf);
    p = gKeyboard;
    if (p->mUnk_2c[2].mUnk_10 != 0) {
        gKeyboard->mTextOffsetY[0][0] =
            InterpolateS16(1, data_0215d108[0][0], data_0215d100[0][0], p->mStateFrames, 0xf);
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState2NoCloseRequest() != 0) {
        gKeyboard->mNextState = 7;
        gKeyboard->mTextEntryEnabled = TRUE;
        gKeyboard->mStateFrames = 0;
    }
    UpdateKeyboardNameButtons();
    ShowKeyboardLayoutObject();
}

void AdvanceKeyboardState7(void) {
    InputSlotIndex i = UNK_02175628_INDEX_8;
    Keyboard *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    BOOL f;
    BOOL g;
    s32 n;
    u16 c;
    f = FALSE;
    v = -1;
    g = FALSE;
    c = data_02175674[i].mUnk_00;
    if (c == 0 && data_02175680[i].mUnk_00 < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[i].mUnk_00 == 0 && c != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        v = RectTableFindContaining(gKeyboard->mBnbls[1], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = gKeyboard;
    q = &p->mUnk_2c[p->mKind];
    w = GetKeyboardText();
    MIi_CpuCopy16(w, q, 0x18);
    UpdateKeyboardNameButtons();
    if (v == 5 || (GetKeyboardCursorValueWrapper() == 1 && (u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0)) {
        p = gKeyboard;
        if (p->mButtonEnabled[0] != 0) {
            p->mNextState = 8;
            gKeyboard->mUnk_2c[2].mUnk_10 = 1;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(1);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
    } else if (v == 6 || (GetKeyboardCursorValueWrapper() == 2 && (u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0)) {
        p = gKeyboard;
        if (p->mButtonEnabled[1] != 0) {
            p->mNextState = 8;
            gKeyboard->mUnk_2c[2].mUnk_10 = 0;
            RequestTxtSystemClose();
            MoveKeyboardCursorToValueWrapper(2);
            gKeyboard->mTextEntryEnabled = FALSE;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xe);
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
    } else if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_Y) != 0) {
        if (data_021759d0->mUnk_00 == 0) {
            gKeyboard->mLayout = data_0215d11c[gKeyboard->mLayout];
        } else {
            gKeyboard->mLayout = data_0215d122[gKeyboard->mLayout];
        }
        SelectKeyboardLayout(gKeyboard->mLayout);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e5);
    } else {
        p = gKeyboard;
        n = p->mLayout;
        f = FALSE;
        switch (v) {
            case 0:
                p->mLayout = 1;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 1:
                p->mLayout = 2;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 2:
                p->mLayout = 3;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 3:
                p->mLayout = 4;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
            case 4:
                p->mLayout = 5;
                SelectKeyboardLayout(gKeyboard->mLayout);
                f = TRUE;
                break;
        }
        if (f != FALSE) {
            if (n != gKeyboard->mLayout) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1e5);
            } else {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1ed);
            }
        }
    }
    ShowKeyboardLayoutObject();
}

void AdvanceKeyboardState8(void) {
    u16 buf[10];
    u16 buf2[0xfe];
    Keyboard *p;
    s32 n;
    void *a;
    void *b;
    void *c;
    gKeyboard->mStateFrames++;
    gKeyboard->mOffsetY = InterpolateS16(1, 0, 0xc0, gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][1] =
        InterpolateS16(1, data_0215d100[1][1], data_0215d108[1][1], gKeyboard->mStateFrames, 0xf);
    p = gKeyboard;
    if (p->mUnk_2c[2].mUnk_10 == 0) {
        gKeyboard->mTextOffsetY[0][0] =
            InterpolateS16(1, data_0215d100[0][0], data_0215d108[0][0], p->mStateFrames, 0xf);
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf && IsTxtSystemState0NoOpenRequest() != 0) {
        p = gKeyboard;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            if (p->mUnk_2c[2].mMode == 0xc) {
                a = GetBmgEntry(p->mCommonMessages, 0x11);
                b = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                c = GetBmgEntry(p->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(a, b, c, 0, 0, 1, 1, 0);
            } else {
                a = GetBmgEntry(p->mCommonMessages, 0xe);
                n = func_020adc7c(gKeyboard->mUnk_2c[1].mChars, buf);
                buf[n] = 0;
                func_0212513c(buf, a, &buf2[1], 0x1f4);
                b = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                c = GetBmgEntry(gKeyboard->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(&buf2[1], b, c, 0, 0, 1, 1, 0);
            }
            gKeyboard->mNextState = 9;
            gKeyboard->mStateFrames = 0;
        } else if (p->mUnk_2c[2].mMode == 0xc) {
            p->mKind = 0;
            gKeyboard->mLayout = 0;
            SelectKeyboardLayout(gKeyboard->mLayout);
            SetKeyboardTextLimit(gKeyboardTextLimits[0]);
            QueueKeyboardScreenMap();
            SetKeyboardTextFromFriendKey();
            gKeyboard->mNextState = 1;
            gKeyboard->mStateFrames = 0;
            func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 7), 0, 0, 0, 0, 0, 0);
        } else {
            p->mUnk_2c[2].mNextScene = 7;
        }
    }
}

void AdvanceKeyboardState9(void) {
    s16 v;
    gKeyboard->mStateFrames++;
    v = data_0215d100[1][0];
    gKeyboard->mTextOffsetY[0][0] =
        InterpolateS16(1, data_0215d100[0][0], data_0215d100[0][0] - (0xc0 - v), gKeyboard->mStateFrames, 0xf);
    gKeyboard->mTextOffsetY[1][0] = InterpolateS16(1, data_0215d108[1][0], v, gKeyboard->mStateFrames, 0xf);
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (gKeyboard->mStateFrames >= 0xf) {
        if (IsTxtSystemState2NoCloseRequest() != 0) {
            gKeyboard->mNextState = 0xa;
            gKeyboard->mStateFrames = 0;
        }
    }
}

void AdvanceKeyboardState10(void) {
    Keyboard *p;
    s16 v;
    void *a;
    void *b;
    if (gKeyboard->mStateFrames >= 0xf) {
        gKeyboard->mStateFrames = 0xf;
    }
    if (GetTxtSystemDone() != 0 && GetTxtSystemSelectedIndex() == 1) {
        v = data_0215d100[1][0];
        gKeyboard->mTextOffsetY[1][0] = InterpolateS16(1, v, data_0215d108[1][0], gKeyboard->mStateFrames, 0xf);
        gKeyboard->mTextOffsetY[0][0] =
            InterpolateS16(1, data_0215d100[0][0] - (0xc0 - v), data_0215d100[0][0], gKeyboard->mStateFrames, 0xf);
    }
    if (IsTxtSystemState0NoOpenRequest() != 0 && gKeyboard->mStateFrames >= 0xf) {
        if (GetTxtSystemSelectedIndex() == 0) {
            p = gKeyboard;
            if (p->mUnk_2c[2].mMode == 0xc) {
                func_02060cb4(&p->mUnk_2c[2], &p->mUnk_2c[1]);
                func_0205edf8();
                a = GetBmgEntry(gKeyboard->mCommonMessages, 0x81);
                SetupTxtSystemSubTextEx(a, 0, 1, 1, 0, 1);
                gKeyboard->mNextState = 0xb;
            } else {
                data_0217aa08->mUnk_00->mUnk_31_0 = 1;
                MI_CpuFill8(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
                MI_CpuCopy8(&p->mUnk_2c[1], data_0217aa08->mUnk_00->mUnk_0c, 0x14);
                func_02056d40();
                SetTxtSystemOpenSoundId(0x21);
                a = GetBmgEntry(gKeyboard->mCommonMessages, 0x10);
                b = GetBmgEntry(gKeyboard->mCommonMessages, 4);
                SetupTxtSystemSubTextButtonEx(a, b, 0, 1, 1, 0);
                gKeyboard->mNextState = 0xc;
            }
            gKeyboard->mStateFrames = 0;
        } else {
            gKeyboard->mNextState = 6;
            gKeyboard->mUnk_2c[2].mUnk_10 = 0;
            gKeyboard->mStateFrames = 0;
            func_02126638(GetBmgEntry(gKeyboard->mCommonMessages, 0xf), 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (GetTxtSystemDone() != 0 || IsTxtSystemState0NoOpenRequest() != 0) {
            RequestTxtSystemClose();
            gKeyboard->mStateFrames++;
        }
    }
}

void AdvanceKeyboardState11(void) {
    Keyboard *p;
    void *a;
    s32 w;
    void *b;
    if (IsTxtSystemState2AfterState1() != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x22);
    }
    gKeyboard->mStateFrames++;
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        p = gKeyboard;
        if (p->mStateFrames > 0x5a) {
            w = (data_0217aa08->mUnk_28 == 0)
                    ? (data_021759d4->mBackupEnabled != 0 ? data_021759d4->mCommandRunning : 0)
                    : 1;
            if (w == 0) {
                p->mNextState = 0xc;
                gKeyboard->mStateFrames = 0;
                SetTxtSystemOpenSoundId(0x21);
                a = GetBmgEntry(gKeyboard->mCommonMessages, 9);
                b = GetBmgEntry(gKeyboard->mCommonMessages, 4);
                SetupTxtSystemSubTextButtonEx(a, b, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState12(void) {
    void *a;
    s32 w;
    void *b;
    void *c;
    s32 v;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        w = (data_0217aa08->mUnk_28 == 0) ? (data_021759d4->mBackupEnabled != 0 ? data_021759d4->mCommandRunning : 0)
                                          : 1;
        if (w == 0) {
            SetTxtSystemOpenSoundId(0x23);
            v = gKeyboard->mUnk_2c[2].mMode;
            if (v == 0xc || v == 7) {
                gKeyboard->mUnk_2c[2].mNextScene = v;
                return;
            }
            if (v == 0xb) {
                gKeyboard->mNextState = 0xd;
                gKeyboard->mStateFrames = 0;
                a = GetBmgEntry(gKeyboard->mCommonMessages, 0x13);
                b = GetBmgEntry(gKeyboard->mCommonMessages, 0);
                c = GetBmgEntry(gKeyboard->mCommonMessages, 1);
                SetupTxtSystemSubTextTwoButtonsEx(a, b, c, 0, 0, 1, 1, 0);
            }
        }
    }
}

void AdvanceKeyboardState13(void) {
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            gKeyboard->mUnk_2c[2].mNextScene = 3;
        } else {
            gKeyboard->mUnk_2c[2].mNextScene = 0;
        }
    } else {
        if (GetTxtSystemDone() != 0) {
            RequestTxtSystemClose();
        }
    }
}

void PrintKeyboardTextChars(void) {
    s32 i;
    s32 j;
    s32 k;
    u16 buf[2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < gKeyboardTextLimits[i]; k++) {
                buf[0] = 0;
                buf[1] = 0;
                buf[0] = gKeyboard->mUnk_2c[i].mChars[k];
                func_0212426c(j, data_0215d134[i][k], gKeyboard->mBnlls[i], buf, gKeyboard->mBncls[i],
                              gKeyboard->mTables[i][j]);
            }
        }
    }
}

void ShowKeyboardCursorButtonObjects(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mCursorOnButton[i] != 0) {
            n = gKeyboard->mKind;
            gKeyboard->mTables[n][1][data_0215d128[n][i][0]].mVisible = 1;
        } else {
            n = gKeyboard->mKind;
            gKeyboard->mTables[n][1][data_0215d128[n][i][0]].mVisible = 0;
        }
    }
}

void ShowKeyboardDisabledButtonObjects(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (gKeyboard->mButtonEnabled[i] != 0) {
            n = gKeyboard->mKind;
            gKeyboard->mTables[n][1][data_0215d128[n][i][1]].mVisible = 0;
        } else {
            n = gKeyboard->mKind;
            gKeyboard->mTables[n][1][data_0215d128[n][i][1]].mVisible = 1;
        }
    }
}

void ShowKeyboardTextIndexObject(void) {
    s32 i;
    for (i = 0; i < gKeyboardTextLimits[gKeyboard->mKind]; i++) {
        gKeyboard->mTables[gKeyboard->mKind][1][data_0215d14c[gKeyboard->mKind][i]].mVisible = 0;
    }
    gKeyboard->mTables[gKeyboard->mKind][1][data_0215d14c[gKeyboard->mKind][GetKeyboardTextIndex()]].mVisible = 1;
}

void func_02128b54(void) {
    u16 buf[10];
    s32 n;
    s32 k;
    s32 l;
    s32 i;
    s32 j;
    u8 *q;
    if (gKeyboard->mKind == 1) {
        n = func_020adc7c(gKeyboard->mUnk_2c[1].mChars, buf);
        k = 6;
        if (n > 4) {
            k = 10 - n;
        }
        i = 0;
        q = data_0215d0f0;
        l = 6 - k;
        for (; i < 6; i++) {
            for (j = 0; j < 2; j++) {
                if (i >= l && gKeyboard->mUnk_2c[2].mMode != 0xc) {
                    gKeyboard->mTables[1][j][*q].mVisible = 1;
                } else {
                    gKeyboard->mTables[1][j][*q].mVisible = 0;
                }
            }
            q++;
        }
    }
}

void ShowKeyboardLayoutObject(void) {
    s32 i;
    BOOL z;
    u8 *q;
    u8 c;
    i = 0;
    q = data_0215d0e8;
    z = FALSE;
    for (; i < 6; i++) {
        c = *q;
        if (c != 0xff) {
            gKeyboard->mTables[1][1][c].mVisible = z;
        }
        q++;
    }
    gKeyboard->mTables[1][1][data_0215d0e8[gKeyboard->mLayout]].mVisible = 1;
}

void AdvanceKeyboard(void) {
    s32 i;
    Keyboard *p;
    func_0212a920();
    func_02125928();
    gKeyboard->mState = gKeyboard->mNextState;
    if (gKeyboard->mTextEntryEnabled != FALSE) {
        AdvanceKeyboardTextEntry();
    }
    switch (gKeyboard->mState) {
        case 0:
            AdvanceKeyboardState0();
            break;
        case 1:
            AdvanceKeyboardState1();
            break;
        case 2:
            AdvanceKeyboardState2();
            break;
        case 3:
            AdvanceKeyboardState3();
            break;
        case 4:
            AdvanceKeyboardState4();
            break;
        case 5:
            AdvanceKeyboardState5();
            break;
        case 6:
            AdvanceKeyboardState6();
            break;
        case 7:
            AdvanceKeyboardState7();
            break;
        case 8:
            AdvanceKeyboardState8();
            break;
        case 9:
            AdvanceKeyboardState9();
            break;
        case 10:
            AdvanceKeyboardState10();
            break;
        case 11:
            AdvanceKeyboardState11();
            break;
        case 12:
            AdvanceKeyboardState12();
            break;
        case 13:
            AdvanceKeyboardState13();
            break;
    }
    PrintKeyboardTextChars();
    ShowKeyboardTextIndexObject();
    func_02128b54();
    ShowKeyboardCursorButtonObjects();
    ShowKeyboardDisabledButtonObjects();
    WriteKeyboardObjectOffsets();
    for (i = 0; i < 2; i++) {
        p = gKeyboard;
        DrawLayoutTable(p->mBncls[i], p->mNcer, p->mBnlls[i], GetKeyboardFirstBuffer(), p->mTables[i][0]);
    }
    p = gKeyboard;
    DrawLayoutTable(p->mBncls[p->mKind], p->mNcer, p->mBnlls[p->mKind], GetKeyboardSecondBuffer(),
                    p->mTables[p->mKind][1]);
}

void func_0212899c(void) {
    SetKeyboardOffset(0, gKeyboard->mOffsetY + 0x28);
    reg_G2S_DB_BG3OFS = (-gKeyboard->mOffsetY << 16) & 0x1ff0000;
    UploadKeyboardBg2Data();
    func_021258f0();
}
#pragma thumb off

#pragma thumb on
u32 GetKeyboardNextScene(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gKeyboard;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 114u;
    value0 = *(const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off
