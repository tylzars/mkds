#include "01/code_0219d5dc.h"
#include "registers.h"

#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02056d40.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02125f6c.h"

OptionEmbremSelect *gOptionEmbremSelect;

void InitOptionEmbremSelect(void *a) {
    s32 i;
    OptionEmbremSelect *p;
    void *ptr;

    gOptionEmbremSelect = HeapAlloc(a, 0x58);
    gOptionEmbremSelect->mUnk_30 = a;
    gOptionEmbremSelect->mState = 0;
    gOptionEmbremSelect->mNextState = 0;
    gOptionEmbremSelect->mUnk_08 = 0;
    gOptionEmbremSelect->mStateFrames = 0;
    gOptionEmbremSelect->mUnk_24 = TRUE;
    LocateAndQueueOptionEmbremSelect();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6c38[i][0], 1, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                      gOptionEmbremSelect->mOptionEmbremSelectSBncl);
    }
    func_020ae6d4(GetOptionFirstBuffer(), GetOptionSecondBuffer());
    func_02124ed0(a, gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                  &gOptionEmbremSelect->mOptionEmbremSelectSTable);
    gOptionEmbremSelect->mOptionMessages = FindSceneFile("option.bmg");
    gOptionEmbremSelect->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    func_021243ac(a, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, 0xa0, 0xe, 9,
                  gOptionEmbremSelect->mOptionEmbremSelectSNcer, gOptionEmbremSelect->mOptionEmbremSelectSBncl,
                  gOptionEmbremSelect->mOptionEmbremSelectSTable, 0x4000);
    p = gOptionEmbremSelect;
    ptr = GetBmgEntry(p->mOptionMessages, 8);
    func_0212426c(1, 0, gOptionEmbremSelect->mOptionEmbremSelectSBnll, ptr, p->mOptionEmbremSelectSBncl,
                  p->mOptionEmbremSelectSTable);
    for (i = 0; i < 2; i++) {
        gOptionEmbremSelect->mUnk_18[i].mUnk_00 = 250;
        gOptionEmbremSelect->mUnk_18[i].mUnk_02 = 0;
    }
    gOptionEmbremSelect->mUnk_0c = func_ov001_0219de38();
    gOptionEmbremSelect->mUnk_10 = gOptionEmbremSelect->mUnk_0c;
    func_ov001_0219d858();
    func_ov001_0219d810();
    gOptionEmbremSelect->mOffsetTimers[0] = 0;
    gOptionEmbremSelect->mOffsetTimers[1] = 0;
    func_021281c8(0xe);
}

void ReleaseOptionEmbremSelect(void) {
    gOptionEmbremSelect = NULL;
}

void LocateAndQueueOptionEmbremSelect(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile(gOptionTopMenuMBNcgrName));
    LocateNscr(&b, FindSceneFile(gOptionTopMenuMNscrName));
    LocateNclr(&c, FindSceneFile(gOptionTopMenuMBNclrName));
    gOptionEmbremSelect->mOptionEmbremSelectSBncl = FindSceneFile(gOptionEmbremSelectSBnclName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnbl = FindSceneFile(gOptionEmbremSelectSBnblName);
    gOptionEmbremSelect->mOptionEmbremSelectSBnll = FindSceneFile(gOptionEmbremSelectSBnllName);
    LocateNcgr2(&gOptionEmbremSelect->mOptionEmbremSelectSNcgr, FindSceneFile(gOptionEmbremSelectSNcgrName));
    LocateNcer(&gOptionEmbremSelect->mOptionEmbremSelectSNcer, FindSceneFile(gOptionEmbremSelectSNcerName));
    LocateNclr(&gOptionEmbremSelect->mOptionEmbremSelectSONclr, FindSceneFile(gOptionEmbremSelectSONclrName));
    CallQueueAppend(4, 0, a->mData, a->mDataSize);
    CallQueueAppend(8, 0, b->mData, b->mDataSize);
    CallQueueAppend(0xf, 0, c->mData, 0x100);
    CallQueueAppend(0x23, 0, gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mData,
                    gOptionEmbremSelect->mOptionEmbremSelectSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, gOptionEmbremSelect->mOptionEmbremSelectSONclr->mData,
                    gOptionEmbremSelect->mOptionEmbremSelectSONclr->mDataSize);
}

BOOL func_ov001_0219de38(void) {
    if (data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        return FALSE;
    }
    if (data_0217aa08->mUnk_00->mUnk_31_3 != 0) {
        return TRUE;
    }
    return TRUE;
}

void AdvanceOptionEmbremSelectState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        gOptionEmbremSelect->mNextState = 1;
    }
}

void AdvanceOptionEmbremSelectState1(void) {
    s32 i;
    s32 j;
    s16 v;

    gOptionEmbremSelect->mStateFrames++;
    v = InterpolateS16(1, 250, 0, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 1) {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = v;
            } else {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = -v;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        gOptionEmbremSelect->mNextState = 2;
        gOptionEmbremSelect->mStateFrames = 0;
        func_02128374();
    }
}

void AdvanceOptionEmbremSelectState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gOptionEmbremSelect->mNextState = 3;
    }
}

void AdvanceOptionEmbremSelectState3(void) {
    Unk02175628Index index = UNK_02175628_INDEX_8;
    s32 result = -1;
    BOOL cond2 = FALSE;
    BOOL cond1 = FALSE;
    u16 value;
    u16 flags;

    value = data_02175628[index].mHasPair;
    if (value == 0 && data_02175628[index].mNoPairCount < 5) {
        cond1 = TRUE;
    }
    if (cond1 == FALSE && data_02175628[index].mPrevHasPair == 0 && value != 0) {
        cond2 = TRUE;
    }
    if (cond2 != FALSE) {
        result = RectTableFindContaining(gOptionEmbremSelect->mOptionEmbremSelectSBnbl, data_02175628[index].mUnk_48,
                                         data_02175628[index].mUnk_4a);
    }
    flags = data_02175628[index].mUnk_00 & 2;
    if (flags != 0) {
        goto next;
    }
    cond2 = FALSE;
    cond1 = FALSE;
    value = data_02175628[index].mHasPair;
    if (value == 0 && data_02175628[index].mNoPairCount < 5) {
        cond1 = TRUE;
    }
    if (cond1 == FALSE && data_02175628[index].mPrevHasPair == 0 && value != 0) {
        cond2 = TRUE;
    }
    if (cond2 != FALSE && IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[index].mUnk_48,
                                                                          data_02175628[index].mUnk_4a) != FALSE) {
    next:
        gOptionEmbremSelect->mNextState = 5;
        gOptionEmbremSelect->mNextOptionState = 2;
        if (gOptionEmbremSelect->mUnk_0c != gOptionEmbremSelect->mUnk_10) {
            func_02128310(1);
        } else {
            func_02128310(0);
        }
        if (gOptionEmbremSelect->mUnk_0c == 0) {
            data_0217aa08->mUnk_00->mUnk_31_3 = 0;
        } else {
            data_0217aa08->mUnk_00->mUnk_31_3 = 1;
        }
        func_02056d40();
    } else {
        flags = data_02175628[index].mUnk_00 & 1;
        if ((flags != 0 && gOptionEmbremSelect->mUnk_08 == 0) || result == 0) {
            if (gOptionEmbremSelect->mUnk_08 == 0) {
                gOptionEmbremSelect->mUnk_24 = FALSE;
            }
            gOptionEmbremSelect->mNextState = 4;
            gOptionEmbremSelect->mNextOptionState = 6;
            gOptionEmbremSelect->mUnk_08 = 0;
            data_0217b488->mUnk_18 = TRUE;
            func_02105ac0(5);
        } else if (result == 1) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c++;
            func_02105ac0(1);
        } else if (func_020ae408(8, 0x40) != 0 && gOptionEmbremSelect->mUnk_08 > 0) {
            gOptionEmbremSelect->mUnk_08--;
            func_02105ac0(0);
        } else if (func_020ae408(8, 0x80) != 0 && gOptionEmbremSelect->mUnk_08 < 1) {
            gOptionEmbremSelect->mUnk_08++;
            func_02105ac0(0);
        } else if (gOptionEmbremSelect->mUnk_08 == 1 && func_020ae408(8, 0x20) != 0) {
            gOptionEmbremSelect->mUnk_0c--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            func_02105ac0(1);
        } else if (gOptionEmbremSelect->mUnk_08 == 1 && func_020ae408(8, 0x10) != 0) {
            gOptionEmbremSelect->mUnk_0c++;
            if (func_020ae408(8, 0x10) != 0) {
                gOptionEmbremSelect->mOffsetTimers[1] = 6;
            }
            func_02105ac0(1);
        } else if (result == 2) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c--;
            gOptionEmbremSelect->mOffsetTimers[0] = 6;
            func_02105ac0(1);
        } else if (result == 3) {
            gOptionEmbremSelect->mUnk_08 = 1;
            gOptionEmbremSelect->mUnk_0c++;
            gOptionEmbremSelect->mOffsetTimers[1] = 6;
            func_02105ac0(1);
        }
    }
    if (gOptionEmbremSelect->mUnk_0c < 0) {
        gOptionEmbremSelect->mUnk_0c = 1;
    }
    if (gOptionEmbremSelect->mUnk_0c > 1) {
        gOptionEmbremSelect->mUnk_0c = 0;
    }
}

void AdvanceOptionEmbremSelectState4(void) {
    OptionEmbremSelect *v1;
    gOptionEmbremSelect->mStateFrames = gOptionEmbremSelect->mStateFrames + 1;
    v1 = gOptionEmbremSelect;
    if (10 <= v1->mStateFrames) {
        v1->mNextState = 5;
        gOptionEmbremSelect->mStateFrames = 0;
        func_021282c8();
        return;
    }
    if (5 <= v1->mStateFrames) {
        v1->mUnk_24 = TRUE;
    }
}

void AdvanceOptionEmbremSelectState5(void) {
    s32 i;
    s32 j;
    s32 value;

    if (func_ov001_02192e84() == -1 && gOptionEmbremSelect->mNextOptionState == 6) {
        func_ov001_02192e78(3);
    }
    gOptionEmbremSelect->mStateFrames++;
    value = InterpolateS16(1, 0, 250, gOptionEmbremSelect->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 0) {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = -value;
            } else {
                gOptionEmbremSelect->mUnk_18[i].mUnk_00 = value;
            }
        }
    }
    if (gOptionEmbremSelect->mStateFrames >= 10) {
        if (gOptionEmbremSelect->mStateFrames >= 10 &&
            (IsSelectReturnState2NoState3Or4Request() != 0 || IsSelectReturnState0NoState1Request() != 0)) {
            if (func_ov001_02192e84() == -1) {
                OptionEmbremSelect *obj = gOptionEmbremSelect;
                s32 arg;
                void *first;

                if (obj->mUnk_0c == obj->mUnk_10) {
                    RequestOptionState(obj->mNextOptionState);
                    return;
                }
                arg = 9;
                if (obj->mUnk_0c == 1) {
                    arg = 10;
                }
                obj->mNextState = 6;
                SetTxtSystemOpenSoundId(0x21);
                first = GetBmgEntry(gOptionEmbremSelect->mOptionMessages, arg);
                func_02126230(first, GetBmgEntry(gOptionEmbremSelect->mCommonMessages, 4));
                gOptionEmbremSelect->mStateFrames = 0;
            }
        }
    }
}

void AdvanceOptionEmbremSelectState6(void) {
    s32 value;

    if (func_02125f54() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                value = data_021759d4->mUnk_10;
            } else {
                value = 0;
            }
        } else {
            value = 1;
        }
        if (value == 0) {
            SetTxtSystemOpenSoundId(0x23);
            RequestTxtSystemClose();
            return;
        }
    }
    if (func_02125f88() != 0) {
        RequestOptionState(gOptionEmbremSelect->mNextOptionState);
    }
}

void func_ov001_0219d858(void) {
    s32 i;
    s32 j;
    s32 index;
    s32 k;

    index = gOptionEmbremSelect->mOptionEmbremSelectSBncl->mUnk_06;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][j]].mUnk_04 =
                gOptionEmbremSelect->mUnk_18[i].mUnk_00;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][j]].mUnk_06 =
                gOptionEmbremSelect->mUnk_18[i].mUnk_02;
        }
    }
    gOptionEmbremSelect->mOptionEmbremSelectSTable[index].mUnk_04 = gOptionEmbremSelect->mUnk_18[1].mUnk_00;
    gOptionEmbremSelect->mOptionEmbremSelectSTable[index].mUnk_06 = gOptionEmbremSelect->mUnk_18[1].mUnk_02;
    for (k = 0; k < 3; k++) {
        gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[k][0]].mUnk_04 -=
            func_020adc64(6 - gOptionEmbremSelect->mOffsetTimers[0]);
        gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[k][1]].mUnk_04 +=
            func_020adc64(6 - gOptionEmbremSelect->mOffsetTimers[1]);
    }
}

void func_ov001_0219d810(void) {
    s32 i;

    for (i = 0; i < data_ov001_021a6c30[1]; i++) {
        if (i == gOptionEmbremSelect->mUnk_0c) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c1c[1][i]].mUnk_00 = 1;
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c1c[1][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219d730(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        if (i == gOptionEmbremSelect->mUnk_08 && gOptionEmbremSelect->mUnk_24 != FALSE) {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][1]].mUnk_00 = 1;
            if (i == 1) {
                func_02124100(0, 14, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                              gOptionEmbremSelect->mOptionEmbremSelectSTable,
                              gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 14, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                              gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c38[i][1]].mUnk_00 = 0;
            if (i == 1) {
                func_02124100(0, 15, gOptionEmbremSelect->mOptionEmbremSelectSBnll,
                              gOptionEmbremSelect->mOptionEmbremSelectSTable,
                              gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 15, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                              gOptionEmbremSelect->mOptionEmbremSelectSBncl);
            }
        }
    }
}

void func_ov001_0219d6ac(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (gOptionEmbremSelect->mUnk_08 == 1) {
            if (gOptionEmbremSelect->mOffsetTimers[i] > 0) {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mUnk_00 = 1;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
                gOptionEmbremSelect->mOffsetTimers[i]--;
            } else {
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
                gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
            }
        } else {
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
            gOptionEmbremSelect->mOptionEmbremSelectSTable[data_ov001_021a6c20[1][i]].mUnk_00 = 0;
        }
    }
}

void AdvanceOptionEmbremSelect(void) {
    gOptionEmbremSelect->mState = gOptionEmbremSelect->mNextState;
    switch (gOptionEmbremSelect->mState) {
        case 0:
            AdvanceOptionEmbremSelectState0();
            break;
        case 1:
            AdvanceOptionEmbremSelectState1();
            break;
        case 2:
            AdvanceOptionEmbremSelectState2();
            break;
        case 3:
            AdvanceOptionEmbremSelectState3();
            break;
        case 4:
            AdvanceOptionEmbremSelectState4();
            break;
        case 5:
            AdvanceOptionEmbremSelectState5();
            break;
        case 6:
            AdvanceOptionEmbremSelectState6();
            break;
    }
    func_ov001_0219d858();
    func_ov001_0219d810();
    func_ov001_0219d730();
    func_ov001_0219d6ac();
    func_02124c30(gOptionEmbremSelect->mOptionEmbremSelectSBncl, gOptionEmbremSelect->mOptionEmbremSelectSNcer,
                  gOptionEmbremSelect->mOptionEmbremSelectSBnll, GetOptionSecondBuffer(),
                  gOptionEmbremSelect->mOptionEmbremSelectSTable);
}

void func_ov001_0219d600(void) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
}

void RegisterOptionEmbremSelectCallbacks(void) {
    Unk021a8cd0 local = gOptionEmbremSelectCallbacks;

    SetOptionStateCallbacks(local.mUnk_00);
}
