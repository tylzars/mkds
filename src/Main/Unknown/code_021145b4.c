#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_02111494.h"

#include "Main/Unknown/code_02111000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02114c98.h"
#include "Main/Unknown/code_02114cb0.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_0211568c.h"
#include "Main/Unknown/code_021156d4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_0211606c.h"
#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02116844.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_02116888.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02047104.h"
#include "registers.h"

#pragma thumb on

u32 IsRecordVSEraseIndexChangeRunning(void) {
    if (gRecordVSErase->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseIndexChange(void) {
    s32 a;
    s32 b;
    s16 v;

    if (IsRecordVSEraseIndexChangeRunning()) {
        if (gRecordVSErase->mIndexChangeTimer == 7) {
            gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
            func_021162cc();
        } else {
            a = gRecordVSErase->mRecordVSMBncl->mUnk_06;
            b = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
            v = func_02116d10(7 - gRecordVSErase->mIndexChangeTimer, 0);
            gRecordVSErase->mBg0OffsetY = v;
            gRecordVSErase->mRecordVSMTable[3].mUnk_06 = v;
            gRecordVSErase->mRecordVSMTable[a].mUnk_06 = v;
            gRecordVSErase->mRecordVSMTransientTable[1].mUnk_06 = v;
            gRecordVSErase->mRecordVSMTransientTable[b].mUnk_06 = v;
        }
        gRecordVSErase->mIndexChangeTimer--;
    } else {
        if (gRecordVSErase->mIndex != 5 && gRecordVSErase->mIndex != gRecordVSErase->mShownIndex) {
            gRecordVSErase->mIndexChangeTimer = 7;
        }
    }
}

void func_02115e74(void) {
    s32 i;
    u16 n;

    i = 0;
    gRecordVSErase->mNextState = 0;
    gRecordVSErase->mStateFrames = 0;
    gRecordVSErase->mBg3Offset = ~0xbf;
    n = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mRecordVSSEraseTable[30].mUnk_04 = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[31].mUnk_04 = 0x100;
    gRecordVSErase->mRecordVSSEraseTable[n + 5].mUnk_06 = ~0xbf;
    for (; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = 0x100;
        gRecordVSErase->mRecordVSSEraseTable[n + data_0215c4b8[i]].mUnk_04 = 0x100;
    }
    func_021162cc();
    func_02126138(GetBmgEntry(gRecordVSErase->mRecordMessages, 4), GetBmgEntry(gRecordVSErase->mCommonMessages, 6), 0,
                  1, 1, 1);
    for (i = 0; i < 2; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4a8[i]].mUnk_00 = 0;
    }
}

void RequestRecordVSEraseState1(void) {
    gRecordVSErase->mNextState = 1;
    gRecordVSErase->mStateFrames = 0;
}

void func_02115e44(void) {
    gRecordVSErase->mNextState = 2;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
}

void func_02115e20(void) {
    gRecordVSErase->mNextState = 3;
    gRecordVSErase->mStateFrames = 0;
    func_02128374();
    func_02116244();
}

void RequestRecordVSEraseState4(void) {
    gRecordVSErase->mNextState = 4;
    gRecordVSErase->mStateFrames = 0;
}

void RequestRecordVSEraseState5(void) {
    gRecordVSErase->mNextState = 5;
    gRecordVSErase->mStateFrames = 0;
}

void func_02115dc0(void) {
    gRecordVSErase->mNextState = 6;
    gRecordVSErase->mStateFrames = 0;
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            IncrementRecordVSErasePageIndex();
            break;
        case 1:
            DecrementRecordVSErasePageIndex();
            break;
    }
    func_02116244();
}

void func_02115d90(void) {
    gRecordVSErase->mNextState = 7;
    gRecordVSErase->mStateFrames = 0;
    func_021282c8();
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
}

void func_02115d08(void) {
    u16 buf[0x10];
    u16 buf2[0x100];
    u16 v;

    gRecordVSErase->mNextState = 8;
    gRecordVSErase->mStateFrames = 0;
    v = GetRecordVSEraseFirstRecordIndex();
    func_02114298(v + gRecordVSErase->mIndex, buf, 0x20);
    func_0212513c(buf, GetBmgEntry(gRecordVSErase->mRecordMessages, 5), buf2, 0x200);
    func_02125fd4(buf2, GetBmgEntry(gRecordVSErase->mCommonMessages, 0),
                  GetBmgEntry(gRecordVSErase->mCommonMessages, 1), 1, 0, 1, 1, 1);
}

void func_02115cec(void) {
    gRecordVSErase->mNextState = 9;
    gRecordVSErase->mStateFrames = 0;
    SetTxtSystemSoundId(0, 0xb);
}

void func_02115cc4(void) {
    gRecordVSErase->mNextState = 0xa;
    gRecordVSErase->mStateFrames = 0;
    RequestTxtSystemClose();
    SetTxtSystemSoundId(0, 5);
}

void func_02115ca0(void) {
    gRecordVSErase->mNextState = 0xb;
    gRecordVSErase->mStateFrames = 0;
    func_02128374();
    func_02116244();
}

void RequestRecordVSEraseState12(void) {
    gRecordVSErase->mNextState = 0xc;
    gRecordVSErase->mStateFrames = 0;
}

void InitRecordVSErase(void *a) {
    s32 v;
    u16 *p;
    s32 w;
    u16 n;
    u16 z;
    s32 j;
    s32 i;
    u32 p0;
    u32 p1;
    u32 p2;
    u32 p3;
    u32 p4;

    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0x1018;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x9810;
    gRecordVSErase = HeapAlloc(a, 0xa4);
    gRecordVSErase->mHeap = a;
    gRecordVSErase->mState = 3;
    gRecordVSErase->mPageIndex = func_02111418();
    gRecordVSErase->mIndex = func_02111408();
    gRecordVSErase->mPageDecrement = 0;
    gRecordVSErase->mIndexChangeTimer = 0;
    gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    gRecordVSErase->mTransientDrawn = 0;
    gRecordVSErase->mErased = 0;
    gRecordVSErase->mUnk_98 = FALSE;
    gRecordVSErase->mUnk_9c = FALSE;
    for (i = 0; i < 2; i++) {
        gRecordVSErase->mOffsetTimers[i] = 0;
    }
    LoadEmblemSBNclr(a);
    LocateAndQueueRecordVSErase();
    func_02124ed0(a, gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMBnll, &gRecordVSErase->mRecordVSMTable);
    func_02124ed0(a, gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientBnll,
                  &gRecordVSErase->mRecordVSMTransientTable);
    func_02124ed0(a, gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseBnll,
                  &gRecordVSErase->mRecordVSSEraseTable);
    gRecordVSErase->mCommonMessages = func_02047a28(data_0216d4a4);
    gRecordVSErase->mRecordMessages = FindSceneFile(data_0216d4b0);
    v = 0x8000;
    v -= func_021243ac(a, 0, gRecordVSErase->mRecordVSMBnll, 0x8c, 0x10, 0, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, v);
    v -= func_021243ac(a, 1, gRecordVSErase->mRecordVSMBnll, 0xaa, 0xe, 1, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, v);
    func_0212426c(0, 1, gRecordVSErase->mRecordVSMBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0),
                  gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
    v -= func_021243ac(a, 0xb, gRecordVSErase->mRecordVSMBnll, 0x96, 0xe, 2, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, v);
    func_0212426c(0, 0xb, gRecordVSErase->mRecordVSMBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 1),
                  gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable);
    v -= func_021243ac(a, 0xc, gRecordVSErase->mRecordVSMBnll, 0x46, 0x10, 3, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMTable, v);
    z = 4;
    n = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            v -= func_021243ac(a, data_0215c530[i][j], gRecordVSErase->mRecordVSMBnll, data_0215c544[i][j],
                               data_0215c558[i][j], z, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMBncl,
                               gRecordVSErase->mRecordVSMTable, v);
            z = n + data_0215c530[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c530[0][i], gRecordVSErase->mRecordVSMBnll,
                      GetBmgEntry(gRecordVSErase->mRecordMessages, data_0215c4b0[i]), gRecordVSErase->mRecordVSMBncl,
                      gRecordVSErase->mRecordVSMTable);
    }
    v -= func_021243ac(a, 0, gRecordVSErase->mRecordVSMTransientBnll, 0x8c, 0x10, 0, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, v);
    v -= func_021243ac(a, 1, gRecordVSErase->mRecordVSMTransientBnll, 0x70, 0x10, 1, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, v);
    func_0212426c(0, 1, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xb),
                  gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    v -= func_021243ac(a, 0xe, gRecordVSErase->mRecordVSMTransientBnll, 0xe0, 0x38, 2, gRecordVSErase->mRecordVSMNcer,
                       gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, v);
    func_0212426c(0, 0xe, gRecordVSErase->mRecordVSMTransientBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 0xc),
                  gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
    for (i = 0; i < 12; i++) {
        v -= func_021243ac(a, data_0215c584[i], gRecordVSErase->mRecordVSMTransientBnll, data_0215c59c[i],
                           data_0215c56c[i], i + 3, gRecordVSErase->mRecordVSMNcer,
                           gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable, v);
    }
    w = GX_GetSizeOfSubOBJ();
    for (i = 0, p = data_0215c50c; i < 5; i++) {
        w -= func_021243ac(a, data_0215c4b8[i], gRecordVSErase->mRecordVSSEraseBnll, data_0215c4c4[i], data_0215c4dc[i],
                           *p, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl,
                           gRecordVSErase->mRecordVSSEraseTable, w);
        p++;
    }
    func_021243ac(a, 5, gRecordVSErase->mRecordVSSEraseBnll, 0xfa, 0x10, 5, gRecordVSErase->mRecordVSSNcer,
                  gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable, w);
    func_0212426c(1, 5, gRecordVSErase->mRecordVSSEraseBnll, GetBmgEntry(gRecordVSErase->mRecordMessages, 2),
                  gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c4e8[i], p0, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c4f4[i], p1, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c500[i], p2, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124a98(data_0215c50c[i], p3, gRecordVSErase->mRecordVSSNcer, gRecordVSErase->mRecordVSSEraseBncl);
        func_02124140(data_0215c4b8[i], p4, gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                      gRecordVSErase->mRecordVSSEraseBncl);
    }
    func_02124140(5, 0, gRecordVSErase->mRecordVSSEraseBnll, gRecordVSErase->mRecordVSSEraseTable,
                  gRecordVSErase->mRecordVSSEraseBncl);
    gRecordVSErase->mUnk_88 = HeapAlloc(a, 0x201);
    gRecordVSErase->mUnk_8c = HeapAlloc(a, 0x200);
    func_02115e74();
}

void func_021156d4(void) {
    u32 v;

    func_021113fc(gRecordVSErase->mPageIndex);
    func_021113f0(gRecordVSErase->mIndex);
    gRecordVSErase = NULL;
    v = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    v &= ~9;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (v << 8);
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState0(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        RequestRecordVSEraseState1();
    }
}

void AdvanceRecordVSEraseState1(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02115e44();
    }
}

void AdvanceRecordVSEraseState2(void) {
    int v1;
    v1 = func_02125f88();
    if (v1 != 0) {
        func_02115e20();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState3(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    AdvanceRecordVSEraseOffsetTimers();
    gRecordVSErase->mStateFrames++;
    v = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 0xa);
    w = InterpolateS16(1, ~0xbf, 0, gRecordVSErase->mStateFrames, 0xa);
    n = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = w;
    gRecordVSErase->mRecordVSSEraseTable[30].mUnk_04 = v;
    gRecordVSErase->mRecordVSSEraseTable[31].mUnk_04 = v;
    gRecordVSErase->mRecordVSSEraseTable[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        if (IsSelectReturnState2NoState3Or4Request() != 0) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState4(void) {
    s32 s;
    s32 v;
    u32 w;
    Unk02175628Index i;
    BOOL n;

    v = -1;
    w = v;
    i = UNK_02175628_INDEX_8;
    AdvanceRecordVSEraseOffsetTimers();
    AdvanceRecordVSEraseIndexChange();
    s = GetRecordVSEraseFirstRecordIndex();
    n = (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) || data_02175674[i].mUnk_00 != 0;
    if (n) {
        v = RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, data_02175670[i].mUnk_00,
                                    data_02175672[i].mUnk_00);
    }
    n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
        (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0);
    if (n) {
        w = RectTableFindContaining(gRecordVSErase->mRecordVSSEraseBnbl, data_02175670[i].mUnk_00,
                                    data_02175672[i].mUnk_00);
    }
    if (v != 5) {
        gRecordVSErase->mUnk_98 = FALSE;
    }
    if (v != 6) {
        gRecordVSErase->mUnk_9c = FALSE;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) != 0 ||
        ((n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
              (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0)) &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) !=
             FALSE)) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        RequestRecordVSEraseState12();
        gRecordVSErase->mUnk_a0 = 3;
        func_02128310(0);
        return;
    }
    if ((v == 5 && gRecordVSErase->mUnk_98 != FALSE) || (w == 5 && gRecordVSErase->mUnk_98 == FALSE) ||
        (u16) (data_0217562a[i].mBits & 0x20) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[30].mUnk_00 == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 1;
        gRecordVSErase->mOffsetTimers[0] = 6;
        gRecordVSErase->mUnk_98 = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((v == 6 && gRecordVSErase->mUnk_9c != FALSE) || (w == 6 && gRecordVSErase->mUnk_9c == FALSE) ||
        (u16) (data_0217562a[i].mBits & 0x10) != 0) {
        if (IsRecordVSEraseIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVSErase->mRecordVSSEraseTable[31].mUnk_00 == 0) {
            return;
        }
        gRecordVSErase->mPageDecrement = 0;
        gRecordVSErase->mOffsetTimers[1] = 6;
        gRecordVSErase->mUnk_9c = TRUE;
        RequestRecordVSEraseState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if (w <= 4) {
        i = data_0215c4d0[w];
        if (i == gRecordVSErase->mIndex) {
            if (func_02114398(s + i) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (IsRecordVSEraseRowFilled(i) != 0) {
            gRecordVSErase->mIndex = i;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else {
        if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
            if (func_02114398(s + gRecordVSErase->mIndex) == 0) {
                if (IsRecordVSEraseIndexChangeRunning() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (IsRecordVSEraseIndexChangeRunning() == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (func_020ae408(8, 0x40) != 0) {
            DecrementRecordVSEraseIndex();
            return;
        }
        if (func_020ae408(8, 0x80) != 0) {
            IncrementRecordVSEraseIndex();
        }
    }
}

void AdvanceRecordVSEraseState5(void) {
    s16 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            k = ~0xff;
            break;
        case 1:
            k = 0x100;
            break;
    }
    gRecordVSErase->mStateFrames++;
    a = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    b = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    c = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    v = InterpolateS16(1, 0, k, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = v;
    gRecordVSErase->mBg1OffsetX = v;
    gRecordVSErase->mRecordVSMTable[1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[2].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[3].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 0xb].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVSErase->mRecordVSMTable[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b + 1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        gRecordVSErase->mRecordVSMTransientTable[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        func_02115dc0();
    }
}

void AdvanceRecordVSEraseState6(void) {
    s16 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    AdvanceRecordVSEraseOffsetTimers();
    switch (gRecordVSErase->mPageDecrement) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = ~0xff;
            break;
    }
    gRecordVSErase->mStateFrames++;
    a = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    b = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    c = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    v = InterpolateS16(1, k, 0, gRecordVSErase->mStateFrames, 0xa);
    gRecordVSErase->mBg0OffsetX = v;
    gRecordVSErase->mBg1OffsetX = v;
    gRecordVSErase->mRecordVSMTable[1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[2].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[3].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 0xb].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTable[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVSErase->mRecordVSMTable[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    gRecordVSErase->mRecordVSMTransientTable[1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b + 1].mUnk_04 = v;
    gRecordVSErase->mRecordVSMTransientTable[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        gRecordVSErase->mRecordVSMTransientTable[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (gRecordVSErase->mStateFrames >= 0xa) {
        RequestRecordVSEraseState4();
    }
}

void AdvanceRecordVSEraseState7(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    gRecordVSErase->mStateFrames++;
    v = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 0xa);
    w = InterpolateS16(1, 0, ~0xbf, gRecordVSErase->mStateFrames, 0xa);
    n = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = w;
    gRecordVSErase->mRecordVSSEraseTable[30].mUnk_04 = v;
    gRecordVSErase->mRecordVSSEraseTable[31].mUnk_04 = v;
    gRecordVSErase->mRecordVSSEraseTable[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = v;
        gRecordVSErase->mRecordVSSEraseTable[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (gRecordVSErase->mStateFrames > 0xa) {
        if (IsSelectReturnState0NoState1Request() != 0) {
            func_02115d08();
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState8(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        func_02115cec();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSEraseState9(void) {
    u16 a;

    a = GetRecordVSEraseFirstRecordIndex();
    if (func_02125f54()) {
        if (GetTxtSystemSelectedIndex() == 0) {
            func_02114174(a + gRecordVSErase->mIndex);
            gRecordVSErase->mErased = 1;
        } else {
            gRecordVSErase->mErased = 0;
        }
        func_02115cc4();
    }
}

void AdvanceRecordVSEraseState10(void) {
    s32 i;
    s32 j;
    s16 a;
    u16 x;
    u16 y;
    u16 v;

    gRecordVSErase->mStateFrames++;
    a = InterpolateS16(1, 0, -0x100, gRecordVSErase->mStateFrames, 10);
    x = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    y = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    if (func_021143b4() != 0 && gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = a;
        gRecordVSErase->mRecordVSMTable[1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[2].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[3].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 0xb].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                gRecordVSErase->mRecordVSMTable[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y + 1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            gRecordVSErase->mRecordVSMTransientTable[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    if (func_02125f88()) {
        v = GetRecordVSEraseFirstRecordIndex();
        if (func_021143b4() <= v) {
            gRecordVSErase->mPageIndex--;
        }
        if (gRecordVSErase->mPageIndex < 0) {
            gRecordVSErase->mUnk_a0 = 3;
            func_02111488(gRecordVSErase->mUnk_a0);
        } else {
            func_02115ca0();
        }
    }
}

void AdvanceRecordVSEraseState11(void) {
    s32 i;
    s32 j;
    s16 a;
    s16 b;
    u16 x;
    u16 y;
    u16 z;

    gRecordVSErase->mStateFrames++;
    a = InterpolateS16(1, 0x100, 0, gRecordVSErase->mStateFrames, 10);
    b = InterpolateS16(1, -0xc0, 0, gRecordVSErase->mStateFrames, 10);
    x = gRecordVSErase->mRecordVSMBncl->mUnk_06;
    y = gRecordVSErase->mRecordVSMTransientBncl->mUnk_06;
    z = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    if (gRecordVSErase->mErased != 0) {
        gRecordVSErase->mBg1OffsetX = a;
        gRecordVSErase->mRecordVSMTable[1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[2].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[3].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 0xb].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTable[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                gRecordVSErase->mRecordVSMTable[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        gRecordVSErase->mRecordVSMTransientTable[1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y + 1].mUnk_04 = a;
        gRecordVSErase->mRecordVSMTransientTable[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            gRecordVSErase->mRecordVSMTransientTable[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    gRecordVSErase->mBg3Offset = b;
    gRecordVSErase->mRecordVSSEraseTable[30].mUnk_04 = a;
    gRecordVSErase->mRecordVSSEraseTable[31].mUnk_04 = a;
    gRecordVSErase->mRecordVSSEraseTable[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (gRecordVSErase->mStateFrames > 10) {
        if (IsSelectReturnState2NoState3Or4Request()) {
            RequestRecordVSEraseState4();
        }
    }
}

void AdvanceRecordVSEraseState12(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 z;

    gRecordVSErase->mStateFrames++;
    a = InterpolateS16(1, 0, 0x100, gRecordVSErase->mStateFrames, 10);
    b = InterpolateS16(1, 0, -0xc0, gRecordVSErase->mStateFrames, 10);
    z = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    gRecordVSErase->mBg3Offset = b;
    gRecordVSErase->mRecordVSSEraseTable[30].mUnk_04 = a;
    gRecordVSErase->mRecordVSSEraseTable[31].mUnk_04 = a;
    gRecordVSErase->mRecordVSSEraseTable[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mUnk_04 = a;
        gRecordVSErase->mRecordVSSEraseTable[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (gRecordVSErase->mStateFrames >= 10) {
        func_02111488(gRecordVSErase->mUnk_a0);
    }
}

void AdvanceRecordVSErase(void) {
    gRecordVSErase->mState = gRecordVSErase->mNextState;
    switch (gRecordVSErase->mState) {
        case 0:
            AdvanceRecordVSEraseState0();
            break;
        case 1:
            AdvanceRecordVSEraseState1();
            break;
        case 2:
            AdvanceRecordVSEraseState2();
            break;
        case 3:
            AdvanceRecordVSEraseState3();
            break;
        case 4:
            AdvanceRecordVSEraseState4();
            break;
        case 5:
            AdvanceRecordVSEraseState5();
            break;
        case 6:
            AdvanceRecordVSEraseState6();
            break;
        case 7:
            AdvanceRecordVSEraseState7();
            break;
        case 8:
            AdvanceRecordVSEraseState8();
            break;
        case 9:
            AdvanceRecordVSEraseState9();
            break;
        case 10:
            AdvanceRecordVSEraseState10();
            break;
        case 11:
            AdvanceRecordVSEraseState11();
            break;
        case 12:
            AdvanceRecordVSEraseState12();
            break;
    }
    func_02116624();
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            func_02124c30(gRecordVSErase->mRecordVSMBncl, gRecordVSErase->mRecordVSMNcer,
                          gRecordVSErase->mRecordVSMBnll, func_02111318(), gRecordVSErase->mRecordVSMTable);
            break;
        case 1:
            func_02124c30(gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMNcer,
                          gRecordVSErase->mRecordVSMTransientBnll, func_02111318(),
                          gRecordVSErase->mRecordVSMTransientTable);
            break;
    }
    func_02124c30(gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSNcer,
                  gRecordVSErase->mRecordVSSEraseBnll, func_0211130c(), gRecordVSErase->mRecordVSSEraseTable);
}

void func_02114604(void) {
    reg_G2_BG0OFS = (-gRecordVSErase->mBg0OffsetX & 0x1ff) | ((-gRecordVSErase->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVSErase->mBg1OffsetX & 0x1ff) | ((-gRecordVSErase->mBg1OffsetY << 16) & 0x1ff0000);
    reg_G2S_DB_BG3OFS = (-gRecordVSErase->mBg3Offset << 16) & 0x1ff0000;
    func_02111428();
}

void func_021145dc(void) {
    u32 a;

    a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((a | 9) << 8);
}

void RegisterRecordVSEraseCallbacks(void) {
    void (*a[5])() = {InitRecordVSErase, func_021156d4, AdvanceRecordVSErase, func_02114604, func_021145dc};

    func_02111494(a);
}

#pragma thumb off
