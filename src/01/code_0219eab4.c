#include "01/code_0219eab4.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_021055b0.h"
#include "Main/Unknown/code_02105980.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0201ea58.h"
#include "code_02148950.h"
#include "01/unk_021a9000.h"
#include "01/unk_021ca000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "registers.h"

MissionRunLVsel *gMissionRunLVsel;

void LoadMissionRunLVselData(void) {
    Ncgr *v1 = NULL;
    Unk02021dc8 *v2 = NULL;
    Nclr *v3 = NULL;
    Ncgr *v4 = NULL;
    Nscr *v5 = NULL;
    Nclr *v6 = NULL;

    LoadNcgrData(&v4, FindSceneFile(gMissionRunLVselMBNcgrName));
    LoadNscrData(&v5, FindSceneFile(gMissionRunLVselMNscrName));
    LoadNclrData(&v6, FindSceneFile(gMissionRunLVselMBNclrName));
    LoadNcgrData2(&v1, FindSceneFile(gMissionRunLVselSNcgrName));
    LoadNcerData(&v2, FindSceneFile(gMissionRunLVselSNcerName));
    LoadNclrData(&v3, FindSceneFile(gMissionRunLVselSONclrName));
}

void LocateAndQueueMissionRunLVsel(void) {
    Ncgr *v1 = NULL;
    Nclr *v2 = NULL;
    Ncgr *v3 = NULL;
    Nscr *v4 = NULL;
    Nclr *v5 = NULL;

    LocateNcgr(&v3, FindSceneFile(gMissionRunLVselMBNcgrName));
    LocateNscr(&v4, FindSceneFile(gMissionRunLVselMNscrName));
    LocateNclr(&v5, FindSceneFile(gMissionRunLVselMBNclrName));
    if (gMissionRunLVsel->mUnk_4a >= 6) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Bncl = FindSceneFile(gMissionRunLVselS7BnclName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl = FindSceneFile(gMissionRunLVselS7BnblName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnll = FindSceneFile(gMissionRunLVselS7BnllName);
    } else {
        gMissionRunLVsel->mMissionRunLVselS7Or6Bncl = FindSceneFile(gMissionRunLVselS6BnclName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl = FindSceneFile(gMissionRunLVselS6BnblName);
        gMissionRunLVsel->mMissionRunLVselS7Or6Bnll = FindSceneFile(gMissionRunLVselS6BnllName);
    }
    LocateNcgr2(&v1, FindSceneFile(gMissionRunLVselSNcgrName));
    LocateNcer(&gMissionRunLVsel->mMissionRunLVselSNcer, FindSceneFile(gMissionRunLVselSNcerName));
    LocateNclr(&v2, FindSceneFile(gMissionRunLVselSONclrName));
    gMissionRunLVsel->mUnk_14 = HeapAlloc(gMissionRunLVsel->mHeap, 0x800);
    CallQueueAppend(4, 0, v3->mData, v3->mDataSize);
    CallQueueAppend(8, 0, v4->mData, v4->mDataSize);
    CallQueueAppend(8, 0x800, gMissionRunLVsel->mUnk_14, 0x800);
    CallQueueAppend(0xf, 0, v5->mData, 0x40);
    CallQueueAppend(0x23, 0, v1->mData, v1->mDataSize);
    CallQueueAppend(0x1e, 0, v2->mData, v2->mDataSize);
}

s32 func_ov001_0219f6a0(s16 a) {
    s32 i;
    s32 result;
    s32 out;
    u8 next;

    result = 8;
    i = 0;
    next = a + 1;

    for (; i < 9; i++) {
        if (GetMissionRecordValue(next, (u8) (i + 1), &out)) {
            if (out < result) {
                result = out;
            }
        } else {
            result = 9;
        }
    }
    return result;
}

u32 func_ov001_0219f688(int a) {
    if (gMissionRunLVsel->mUnk_4a >= a) {
        return 1;
    }
    return 0;
}

void func_ov001_0219f4f8(void) {
    s32 i;
    u16 cnt;
    s32 r;
    cnt = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mUnk_06;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][0]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][4]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][5]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][6]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][7]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][8]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][9]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][10]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[cnt + data_ov001_021a6c60[i]].mVisible = 0;
        if (func_ov001_0219f688((s16) i)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][1]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][5]].mVisible = 1;
            r = func_ov001_0219f6a0(i);
            if (r <= 4) {
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][7]].mVisible = 1;
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[cnt + data_ov001_021a6c60[i]].mVisible = 1;
                func_0212426c(1, data_ov001_021a6c60[i], gMissionRunLVsel->mMissionRunLVselS7Or6Bnll,
                              data_ov001_021a90e8[r], gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
                              gMissionRunLVsel->mMissionRunLVselS7Or6Table);
            } else if (r <= 7) {
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][r + 3]].mVisible = 1;
            }
        } else if (i != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][0]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][4]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][6]].mVisible = 1;
        }
        func_02124a98(data_ov001_021a6ce0[i][0], 1, gMissionRunLVsel->mMissionRunLVselSNcer,
                      gMissionRunLVsel->mMissionRunLVselS7Or6Bncl);
    }
}

void func_ov001_0219f430(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][1]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][2]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][3]].mVisible = 0;
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][4]].mVisible = 0;
        if (gMissionRunLVsel->mUnk_28[i] > 0) {
            gMissionRunLVsel->mUnk_28[i] = gMissionRunLVsel->mUnk_28[i] - 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][3]].mVisible = 1;
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][3]].mOffsetY =
                gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][2]].mOffsetY + 1;
        } else if (gMissionRunLVsel->mIndex == i) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][2]].mVisible = 1;
        } else if (func_ov001_0219f688((s16) i)) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][1]].mVisible = 1;
        } else if (i != 6) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][4]].mVisible = 1;
        }
    }
}

void func_ov001_0219f3a4(void) {
    BOOL all = TRUE;
    s32 i = 0;
    s32 ok;
    s32 j;
    s32 out;
    u8 x;
    gMissionRunLVsel->mUnk_4a = 0;
    for (i = 0; i < 7; i++) {
        ok = 1;
        j = 0;
        x = i + 1;
        for (; j < 9; j++) {
            ok &= GetMissionRecordValue(x, (u8) (j + 1), &out);
            if (!ok || out < 5) {
                all = FALSE;
            }
        }
        if (ok) {
            if (i == 5) {
                if (all) {
                    gMissionRunLVsel->mUnk_4a = i + 1;
                }
            } else {
                gMissionRunLVsel->mUnk_4a = i + 1;
            }
        }
    }
}

void func_ov001_0219f37c(void) {
    SetMissionTableRow((gMissionRunLVsel->mIndex + 1) * 0x1000000 >> 0x18);
    SetMissionTableColumn(1);
}

BOOL func_ov001_0219f31c(void) {
    s32 i;
    s32 ok = 1;
    s32 result;
    s32 out;

    for (i = 0; i < 8; i++) {
        ok &= GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), (u8) (i + 1), &out);
    }
    result = GetMissionRecordValue((u8) (gMissionRunLVsel->mIndex + 1), 9, &out);
    if (ok != 0 && result == 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov001_0219f2a4(void) {
    s32 i;
    s32 j;
    s32 count;

    count = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mUnk_06;
    i = 0;
    gMissionRunLVsel->mNextState = 0;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mBg0Offset = -192;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][j]].mOffsetX = 0x100;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[count + data_ov001_021a6c60[i]].mOffsetX = 0x100;
    }
}

void func_ov001_0219f260(void) {
    gMissionRunLVsel->mNextState = 1;
    gMissionRunLVsel->mStateFrames = 0;
    if (GetPreviousMenuScreenNumber() == SCREEN_MISSION_RUN_MSSEL) {
        gMissionRunLVsel->mUnk_48 = -256;
    } else {
        gMissionRunLVsel->mUnk_48 = 0x100;
    }
}

void func_ov001_0219f244(void) {
    gMissionRunLVsel->mNextState = 2;
    gMissionRunLVsel->mStateFrames = 0;
    RequestSelectReturnState1();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceMissionRunLVsel call copies it to
// mState and runs AdvanceMissionRunLVselState3.
void RequestMissionRunLVselState3(void) {
    gMissionRunLVsel->mNextState = 3;
    gMissionRunLVsel->mStateFrames = 0;
}

void func_ov001_0219f1f4(void) {
    gMissionRunLVsel->mNextState = 4;
    gMissionRunLVsel->mStateFrames = 0;
    gMissionRunLVsel->mUnk_48 = 0x100;
    func_ov001_0219f37c();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void func_ov001_0219f198(void) {
    gMissionRunLVsel->mNextState = 5;
    gMissionRunLVsel->mStateFrames = 0;
    switch (gMissionRunLVsel->mResult) {
        case 1:
            if (func_ov001_0219f31c() != FALSE) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_02105980(4, 10);
            break;
    }
}

void InitMissionRunLVsel(void *a, void *b, void *c) {
    s32 i;
    s32 remaining;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    {
        void *heap = CreateFrmHeapFromMaxFree(a);

        gMissionRunLVsel = HeapAlloc(heap, 0x5c);
        gMissionRunLVsel->mHeap = heap;
    }
    gMissionRunLVsel->mState = 0;
    gMissionRunLVsel->mUnk_50 = b;
    gMissionRunLVsel->mUnk_54 = c;
    gMissionRunLVsel->mResult = 0;
    for (i = 0; i < 7; i++) {
        gMissionRunLVsel->mUnk_28[i] = 0;
    }
    if (data_0217b488->mUnk_14 != 0) {
        gMissionRunLVsel->mIndex = 6;
        data_0217b488->mUnk_14 = 0;
        func_02105a30(2);
    } else {
        gMissionRunLVsel->mIndex = GetMissionTableRow() - 1;
        if (GetPreviousMenuScreenNumber() == 0x1f) {
            func_02105a30(1);
        } else {
            func_02105a30(0);
        }
    }
    func_ov001_0219f3a4();
    LocateAndQueueMissionRunLVsel();
    func_020ae6d4(gMissionRunLVsel->mUnk_50, gMissionRunLVsel->mUnk_54);
    InitLayoutTable(gMissionRunLVsel->mHeap, gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, &gMissionRunLVsel->mMissionRunLVselS7Or6Table);
    remaining = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 7; i++) {
        remaining -= InitLabelCanvas(
            gMissionRunLVsel->mHeap, data_ov001_021a6c60[i], gMissionRunLVsel->mMissionRunLVselS7Or6Bnll,
            data_ov001_021a6c70[i], data_ov001_021a6c80[i], data_ov001_021a6ce0[i][7],
            gMissionRunLVsel->mMissionRunLVselSNcer, gMissionRunLVsel->mMissionRunLVselS7Or6Bncl,
            gMissionRunLVsel->mMissionRunLVselS7Or6Table, remaining);
    }
    func_ov001_0219f4f8();
    func_ov001_0219f2a4();
    FrmHeapShrinkInParent(gMissionRunLVsel->mHeap);
}

void ReleaseMissionRunLVsel(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    switch (gMissionRunLVsel->mResult) {
        case 1:
            if (func_ov001_0219f31c() != FALSE) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_0210593c(4);
            break;
    }
    HeapDestroy(gMissionRunLVsel->mHeap);
    gMissionRunLVsel = NULL;
}

void AdvanceMissionRunLVselState0(void) {
    int v1;
    func_021059e0();
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        func_ov001_0219f260();
    }
}

void AdvanceMissionRunLVselState1(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    func_021059e0();
    count = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mUnk_06;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    value = InterpolateS16(1, gMissionRunLVsel->mUnk_48, 0, gMissionRunLVsel->mStateFrames, 10);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, -192, 0, gMissionRunLVsel->mStateFrames, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][j]].mOffsetX = value;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[count + data_ov001_021a6c60[i]].mOffsetX = value;
    }
    if (gMissionRunLVsel->mStateFrames >= 10) {
        func_ov001_0219f244();
    }
}

void AdvanceMissionRunLVselState2(void) {
    int v1;
    func_021059e0();
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestMissionRunLVselState3();
    }
}

void AdvanceMissionRunLVselState3(void) {
    u32 sel = -1;
    InputSlotIndex i = UNK_02175628_INDEX_8;
    BOOL f2;
    BOOL f1;
    s16 n;

    func_021059e0();
    f2 = FALSE;
    f1 = FALSE;
    if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
        f1 = TRUE;
    }
    if (f1 == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
        f2 = TRUE;
    }
    if (f2 != FALSE) {
        sel = RectTableFindContaining(gMissionRunLVsel->mMissionRunLVselS7Or6Bnbl, data_02175628[i].mPairX,
                                      data_02175628[i].mPairY);
    }
    if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_B) == 0) {
        BOOL g2 = FALSE;
        BOOL g1 = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            g1 = TRUE;
        }
        if (g1 == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            g2 = TRUE;
        }
        if (g2 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                           data_02175628[i].mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(0xe);
    func_ov001_0219f198();
    gMissionRunLVsel->mUnk_48 = 0x100;
    gMissionRunLVsel->mResult = 2;
    RequestSelectReturnState3WithSound(0);
    return;
next:
    if (sel <= 6) {
        n = data_ov001_021a6c90[sel];
        if (func_ov001_0219f688(n) != 0) {
            gMissionRunLVsel->mIndex = n;
            gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
            func_ov001_0219f1f4();
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0) {
        gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
        func_ov001_0219f1f4();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        if (data_ov001_021a6ca0[gMissionRunLVsel->mIndex] != 0) {
            n = gMissionRunLVsel->mIndex + data_ov001_021a6ca0[gMissionRunLVsel->mIndex];
            if (func_ov001_0219f688(n) != 0) {
                gMissionRunLVsel->mIndex = n;
                gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        if (data_ov001_021a6cb0[gMissionRunLVsel->mIndex] != 0) {
            n = gMissionRunLVsel->mIndex + data_ov001_021a6cb0[gMissionRunLVsel->mIndex];
            if (func_ov001_0219f688(n) != 0) {
                gMissionRunLVsel->mIndex = n;
                gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (data_ov001_021a6cc0[gMissionRunLVsel->mIndex] != 0) {
            n = gMissionRunLVsel->mIndex + data_ov001_021a6cc0[gMissionRunLVsel->mIndex];
            if (func_ov001_0219f688(n) != 0) {
                gMissionRunLVsel->mIndex = n;
                gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (data_ov001_021a6cd0[gMissionRunLVsel->mIndex] != 0) {
            n = gMissionRunLVsel->mIndex + data_ov001_021a6cd0[gMissionRunLVsel->mIndex];
            if (func_ov001_0219f688(n) != 0) {
                gMissionRunLVsel->mIndex = n;
                gMissionRunLVsel->mUnk_28[gMissionRunLVsel->mIndex] = 5;
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            }
        }
    }
}

void AdvanceMissionRunLVselState4(void) {
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    func_021059e0();
    if (gMissionRunLVsel->mStateFrames >= 5) {
        func_ov001_0219f198();
        gMissionRunLVsel->mUnk_48 = -256;
        gMissionRunLVsel->mResult = 1;
    }
}

void AdvanceMissionRunLVselState5(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    count = gMissionRunLVsel->mMissionRunLVselS7Or6Bncl->mUnk_06;
    gMissionRunLVsel->mStateFrames = gMissionRunLVsel->mStateFrames + 1;
    value = InterpolateS16(1, 0, gMissionRunLVsel->mUnk_48, gMissionRunLVsel->mStateFrames, 10);
    gMissionRunLVsel->mBg0Offset = InterpolateS16(1, 0, -192, gMissionRunLVsel->mStateFrames, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            gMissionRunLVsel->mMissionRunLVselS7Or6Table[data_ov001_021a6ce0[i][j]].mOffsetX = value;
        }
        gMissionRunLVsel->mMissionRunLVselS7Or6Table[count + data_ov001_021a6c60[i]].mOffsetX = value;
    }
}

s32 AdvanceMissionRunLVsel(void) {
    gMissionRunLVsel->mState = gMissionRunLVsel->mNextState;
    switch (gMissionRunLVsel->mState) {
        case 0:
            AdvanceMissionRunLVselState0();
            break;
        case 1:
            AdvanceMissionRunLVselState1();
            break;
        case 2:
            AdvanceMissionRunLVselState2();
            break;
        case 3:
            AdvanceMissionRunLVselState3();
            break;
        case 4:
            AdvanceMissionRunLVselState4();
            break;
        case 5:
            AdvanceMissionRunLVselState5();
            break;
    }
    func_ov001_0219f430();
    DrawLayoutTable(gMissionRunLVsel->mMissionRunLVselS7Or6Bncl, gMissionRunLVsel->mMissionRunLVselSNcer,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Bnll, gMissionRunLVsel->mUnk_54,
                    gMissionRunLVsel->mMissionRunLVselS7Or6Table);
    if (gMissionRunLVsel->mState == 5 && gMissionRunLVsel->mStateFrames >= 10) {
        return gMissionRunLVsel->mResult;
    }
    return 0;
}

void WriteMissionRunLVselBg0Offset(void) {
    reg_G2_BG0OFS = (-gMissionRunLVsel->mBg0Offset << 16) & 0x1ff0000;
}
