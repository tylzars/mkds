#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_02036820.h"

#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_021144b4.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02111a98.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212a000.h"
#include "01/code_0219a050.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/code_021115b0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111684.h"
#include "Main/Unknown/code_021144c0.h"
#include "Main/Unknown/code_02125000.h"
#include "01/code_02198854.h"
#include "Main/Unknown/code_02111b40.h"
#include "Main/Unknown/code_02111b94.h"
#include "Main/Unknown/code_02112b48.h"
#include "registers.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021128b4.h"
#include "Main/Unknown/code_021128cc.h"
#include "Main/Unknown/code_02112b30.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_02113ef0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "01/code_02193c5c.h"
#include "01/code_021956dc.h"

#pragma thumb on

void AdvanceRecordVSState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestRecordVSState1AndPrintShownRecord();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState1(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, -192, 0, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetY = v;
    gRecordVS->mBg1OffsetY = v;
    a = gRecordVS->mRecordVSMBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[1].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[2].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[3].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 1].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 11].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    gRecordVS->mRecordVSMTransientTable[1].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[0].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b + 1].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState2AndRefreshPage();
    }
}

void AdvanceRecordVSState2(void) {
    s16 v;
    s32 i;
    u16 x;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, 0x100, 0, gRecordVS->mStateFrames, 10);
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        func_02113480();
    }
    if (gRecordVS->mStateFrames == 4) {
        gRecordVS->mRecordVSSTable[24].mUnk_00 = 1;
        gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState3(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestRecordVSState4();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceRecordVSState4(void) {
    s32 a;
    s32 b;
    Unk02175628Index i;
    BOOL g;
    BOOL f;
    u16 x;
    Unk02175628 *p;
    Unk02175628 *q;
    s16 t;
    a = -1;
    b = -1;
    i = UNK_02175628_INDEX_8;
    AdvanceRecordVSOffsetTimers();
    AdvanceRecordVSIndexChange();
    g = TRUE;
    f = FALSE;
    p = &data_02175674[i];
    x = data_02175674[i].mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        f = TRUE;
    }
    if (f == FALSE && x == 0) {
        g = FALSE;
    }
    if (g != FALSE) {
        a = RectTableFindContaining(gRecordVS->mRecordVSSBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    g = FALSE;
    f = FALSE;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        f = TRUE;
    }
    if (f == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
        g = TRUE;
    }
    if (g != FALSE) {
        b = RectTableFindContaining(gRecordVS->mRecordVSSBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    if (a != 10) {
        gRecordVS->mUnk_88 = FALSE;
    }
    if (a != 11) {
        gRecordVS->mUnk_8c = FALSE;
    }
    q = &data_02175628[i];
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        g = FALSE;
        f = FALSE;
        x = p->mUnk_00;
        if (x == 0 && data_02175680[i].mUnk_00 < 5) {
            f = TRUE;
        }
        if (f == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
            g = TRUE;
        }
        if (g == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00,
                                                                          data_02175672[i].mUnk_00) == FALSE) {
            goto l1;
        }
    }
    if (IsRecordVSIndexChangeRunning() != 0) {
        return;
    }
    RequestRecordVSState7();
    if (func_0211146c() == 12) {
        gRecordVS->mUnk_90 = 6;
        RequestSelectReturnState3WithSound(1);
        return;
    }
    gRecordVS->mUnk_90 = 0;
    RequestSelectReturnState3WithSound(0);
    return;
l1:
    if ((a == 10 && gRecordVS->mUnk_88 != FALSE) || (b == 10 && gRecordVS->mUnk_88 == FALSE) ||
        (u16) (data_0217562a[i].mBits & 0x20) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[20].mUnk_00 == 0) {
            return;
        }
        gRecordVS->mUnk_6c = 1;
        gRecordVS->mOffsetTimers[0] = 6;
        gRecordVS->mUnk_88 = TRUE;
        RequestRecordVSState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 11 && gRecordVS->mUnk_8c != FALSE) || (b == 11 && gRecordVS->mUnk_8c == FALSE) ||
        (u16) (data_0217562a[i].mBits & 0x10) != 0) {
        if (IsRecordVSIndexChangeRunning() != 0) {
            return;
        }
        if (gRecordVS->mRecordVSSTable[21].mUnk_00 == 0) {
            return;
        }
        gRecordVS->mUnk_6c = 0;
        gRecordVS->mOffsetTimers[1] = 6;
        gRecordVS->mUnk_8c = TRUE;
        RequestRecordVSState5();
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
        return;
    }
    if ((u32) (b - 5) <= 4) {
        t = data_0215c44c[b];
        if (IsRecordVSRowFilled(t) == 0) {
            return;
        }
        gRecordVS->mIndex = t;
        func_021137a8(t);
        return;
    }
    if ((u32) b <= 4) {
        t = data_0215c44c[b];
        if (t == gRecordVS->mIndex) {
            func_021137a8(t);
            return;
        }
        if (IsRecordVSRowFilled(t) == 0) {
            return;
        }
        gRecordVS->mIndex = t;
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        return;
    }
    if (b == 12 || (u16) (q->mUnk_00 & 0x400) != 0) {
        func_021132b4();
        gRecordVS->mUnk_90 = 4;
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_021137a8(gRecordVS->mIndex);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        DecrementRecordVSIndex();
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        IncrementRecordVSIndex();
    }
}

void AdvanceRecordVSState5(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    s16 c;
    s16 v;
    c = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mUnk_6c) {
        case 0:
            c = -256;
            break;
        case 1:
            c = 0x100;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    a = gRecordVS->mRecordVSMBncl->mUnk_06;
    b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    v = InterpolateS16(1, 0, c, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetX = v;
    gRecordVS->mBg1OffsetX = v;
    gRecordVS->mRecordVSMTable[1].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[2].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[3].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 1].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 11].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b + 1].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState6AndChangePage();
    }
}

void AdvanceRecordVSState6(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    s16 c;
    s16 v;
    c = 0;
    AdvanceRecordVSOffsetTimers();
    switch (gRecordVS->mUnk_6c) {
        case 0:
            c = 0x100;
            break;
        case 1:
            c = -256;
            break;
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    a = gRecordVS->mRecordVSMBncl->mUnk_06;
    b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    v = InterpolateS16(1, c, 0, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetX = v;
    gRecordVS->mBg1OffsetX = v;
    gRecordVS->mRecordVSMTable[1].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[2].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[3].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 1].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 11].mUnk_04 = v;
    gRecordVS->mRecordVSMTable[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    gRecordVS->mRecordVSMTransientTable[1].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b + 1].mUnk_04 = v;
    gRecordVS->mRecordVSMTransientTable[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[l]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState4();
    }
}

void AdvanceRecordVSState7(void) {
    s16 v;
    s32 i;
    u16 x;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, 0, 0x100, gRecordVS->mStateFrames, 10);
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        func_021132e4();
    }
    if (gRecordVS->mStateFrames == 6) {
        gRecordVS->mRecordVSSTable[24].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    }
}

void AdvanceRecordVSState8(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    if (func_0211145c() == -1 && gRecordVS->mUnk_90 == 6) {
        func_02111450(12);
    }
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, 0, -192, gRecordVS->mStateFrames, 10);
    gRecordVS->mBg0OffsetY = v;
    gRecordVS->mBg1OffsetY = v;
    a = gRecordVS->mRecordVSMBncl->mUnk_06;
    gRecordVS->mRecordVSMTable[0].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[1].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[2].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[3].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 1].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 11].mUnk_06 = v;
    gRecordVS->mRecordVSMTable[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mRecordVSMTable[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = gRecordVS->mRecordVSMTransientBncl->mUnk_06;
    gRecordVS->mRecordVSMTransientTable[1].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[0].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b + 1].mUnk_06 = v;
    gRecordVS->mRecordVSMTransientTable[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mRecordVSMTransientTable[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (gRecordVS->mStateFrames >= 10 && gRecordVS->mUnk_90 != 6) {
        func_02111488(gRecordVS->mUnk_90);
    }
}

void AdvanceRecordVSState9(void) {
    s16 v;
    u16 i;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = func_020ae488(gRecordVS->mStateFrames);
    i = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[i + 5].mUnk_04 = v;
    if (gRecordVS->mStateFrames >= 10) {
        func_02113298();
    }
}

void AdvanceRecordVSState10(void) {
    s16 v;
    s32 i;
    u16 x;
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, 0, 0x100, gRecordVS->mStateFrames, 10);
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        func_02111488(gRecordVS->mUnk_90);
    }
    if (gRecordVS->mStateFrames == 6) {
        gRecordVS->mRecordVSSTable[24].mUnk_00 = 0;
        gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    }
}

void AdvanceRecordVSState11(void) {
    s16 v;
    s32 i;
    u16 x;
    AdvanceRecordVSOffsetTimers();
    gRecordVS->mStateFrames = gRecordVS->mStateFrames + 1;
    v = InterpolateS16(1, 0x100, 0, gRecordVS->mStateFrames, 10);
    x = gRecordVS->mRecordVSSBncl->mUnk_06;
    gRecordVS->mRecordVSSTable[20].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[21].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[24].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[25].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[26].mUnk_04 = v;
    gRecordVS->mRecordVSSTable[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mRecordVSSTable[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mRecordVSSTable[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mStateFrames >= 10) {
        RequestRecordVSState4();
    }
    if (gRecordVS->mStateFrames == 2) {
        gRecordVS->mRecordVSSTable[24].mUnk_00 = 1;
        gRecordVS->mRecordVSSTable[25].mUnk_00 = 0;
    }
}

void AdvanceRecordVS(void) {
    RecordVS *p;
    gRecordVS->mState = gRecordVS->mNextState;
    switch (gRecordVS->mState) {
        case 0:
            AdvanceRecordVSState0();
            break;
        case 1:
            AdvanceRecordVSState1();
            break;
        case 2:
            AdvanceRecordVSState2();
            break;
        case 3:
            AdvanceRecordVSState3();
            break;
        case 4:
            AdvanceRecordVSState4();
            break;
        case 5:
            AdvanceRecordVSState5();
            break;
        case 6:
            AdvanceRecordVSState6();
            break;
        case 7:
            AdvanceRecordVSState7();
            break;
        case 8:
            AdvanceRecordVSState8();
            break;
        case 9:
            AdvanceRecordVSState9();
            break;
        case 10:
            AdvanceRecordVSState10();
            break;
        case 11:
            AdvanceRecordVSState11();
            break;
    }
    func_02113d84();
    p = gRecordVS;
    switch (p->mUnk_40) {
        case 0:
            func_02124c30(p->mRecordVSMBncl, p->mRecordVSMNcer, p->mRecordVSMBnll, func_02111318(), p->mRecordVSMTable);
            break;
        case 1:
            func_02124c30(p->mRecordVSMTransientBncl, p->mRecordVSMNcer, p->mRecordVSMTransientBnll, func_02111318(),
                          p->mRecordVSMTransientTable);
            break;
    }
    p = gRecordVS;
    func_02124c30(p->mRecordVSSBncl, p->mRecordVSSNcer, p->mRecordVSSBnll, func_0211130c(), p->mRecordVSSTable);
}

#pragma thumb off

#pragma thumb on

void func_02111b40(void) {
    reg_G2_BG0OFS = (-gRecordVS->mBg0OffsetX & 0x1ff) | ((-gRecordVS->mBg0OffsetY << 16) & 0x1ff0000);
    reg_G2_BG1OFS = (-gRecordVS->mBg1OffsetX & 0x1ff) | ((-gRecordVS->mBg1OffsetY << 16) & 0x1ff0000);
    func_02111428();
}

#pragma thumb off

#pragma thumb on

void func_02111adc(void) {
    u32 v;
    if (func_0211146c() == 12) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1b00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    } else {
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v | 0x13) << 8);
    }
}

void func_02111ab4(void) {
    Unk0217d344_18 v = {InitRecordVS, func_02112b48, AdvanceRecordVS, func_02111b40, func_02111adc};
    func_02111494(&v);
}

void func_02111a98(void) {
    data_0217d344->mUnk_18.mUnk_00 = NULL;
    data_0217d344->mUnk_18.mUnk_04 = NULL;
    data_0217d344->mUnk_18.mUnk_08 = NULL;
    data_0217d344->mUnk_18.mUnk_0c = NULL;
}

#pragma thumb off

#pragma thumb on

void func_02111684(void) {
    void *v1;
    Unk02111684_v v2;
    v2.mNcgr = NULL;
    v1 = FindSceneFile(gRecordTopMenuMBNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTopMenuMBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTopMenuMNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordTopMenuMNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTopMenuMNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordTopMenuMONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTopMenuSNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTopMenuSNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordTopMenuSONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordGpxMNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordGpxMNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordGpxMONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordGpxMBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordGpxMBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordGpxMNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordGpxSNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordGpxSNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordGpxSONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordGpxSBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordGpxSBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordGpxSNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordTrophyONcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTrophyONcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordTrophySONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTAttMNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTAttMNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordTAttMONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTAttMBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTAttMNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordTAttMScoreNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordTAttMBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTAttSNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTAttSNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordTAttSONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTAttSBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordTAttSBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordTAttSNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordVSMNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordVSMNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordVSMONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordVSMBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordVSMNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordVSM02NscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordVSMBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordVSSNcgrName);
    LoadNcgrData(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordVSSNcerName);
    LoadNcerData(&v2.mNcer, v1);
    v1 = FindSceneFile(gRecordVSSONclrName);
    LoadNclrData(&v2.mNclr, v1);
    v1 = FindSceneFile(gRecordVSM03NscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordVSSBNcgrName);
    LoadNcgrData2(&v2.mNcgr, v1);
    v1 = FindSceneFile(gRecordVSSEraseNscrName);
    LoadNscrData(&v2.mNscr, v1);
    v1 = FindSceneFile(gRecordVSSBNclrName);
    LoadNclrData(&v2.mNclr, v1);
    LoadKartIconData();
    LoadCupMarkData();
}

#pragma thumb off

#pragma thumb on

void func_021115b0(void *a, s16 b) {
    Unk02125de0Arg v;
    data_0217d344 = HeapAlloc(a, 0x34);
    data_0217d344->mHeap = a;
    data_0217d344->mUnk_30 = 0;
    data_0217d344->mUnk_32 = 0;
    func_021250b0(a);
    func_0212abdc(a, func_02111318());
    v.mUnk_00 = TRUE;
    v.mUnk_04 = func_020b403c(1);
    v.mUnk_08 = 0;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = FALSE;
    v.mUnk_1c = TRUE;
    v.mUnk_20 = TRUE;
    v.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &v);
    func_021144c0(data_0217d344->mHeap);
    func_021143f4();
    data_0217d344->mStateHeap = CreateExpHeapFromMaxFree(data_0217d344->mHeap);
    func_02111684();
    func_02111a98();
    data_0217d344->mUnk_14 = b;
    data_0217d344->mUnk_16 = -1;
    data_0217d344->mUnk_0c = -1;
    data_0217d344->mUnk_2c = 2;
    if (data_0217d344->mUnk_14 == 12) {
        data_0217d344->mUnk_10 = 6;
        data_0217d344->mUnk_08 = 3;
        func_02111ab4();
    } else {
        data_0217d344->mUnk_10 = 5;
        data_0217d344->mUnk_08 = 0;
        RegisterRecordTopMenuCallbacks();
    }
    data_0217d344->mUnk_18.mUnk_00(data_0217d344->mStateHeap);
}

#pragma thumb off

#pragma thumb on

void func_02111584(void) {
    func_021144b4();
    data_0217d344->mUnk_18.mUnk_04();
    func_02111a98();
    func_0212abd0();
    func_02125da0();
    *&data_0217d344 = NULL;
}

#pragma thumb off

#pragma thumb on

void func_021114cc(void) {
    if (data_0217d344->mUnk_0c != -1) {
        data_0217d344->mUnk_18.mUnk_04();
        func_02111a98();
        HeapDestroy(data_0217d344->mStateHeap);
        data_0217d344->mStateHeap = CreateExpHeapFromMaxFree(data_0217d344->mHeap);
        switch (data_0217d344->mUnk_0c) {
            case 0:
                if (data_0217d344->mUnk_08 == 3) {
                    func_021143f4();
                }
                RegisterRecordTopMenuCallbacks();
                break;
            case 1:
                RegisterRecordGpxCallbacks();
                break;
            case 2:
                RegisterRecordTAttCallbacks();
                break;
            case 3:
                func_02111ab4();
                break;
            case 4:
                RegisterRecordVSEraseCallbacks();
                break;
        }
        data_0217d344->mUnk_10 = data_0217d344->mUnk_08;
        data_0217d344->mUnk_08 = data_0217d344->mUnk_0c;
        data_0217d344->mUnk_0c = -1;
        data_0217d344->mUnk_2c = 2;
        data_0217d344->mUnk_18.mUnk_00(data_0217d344->mStateHeap);
    }
    data_0217d344->mUnk_18.mUnk_08();
    func_02125928();
    func_0212a920();
}

#pragma thumb off

#pragma thumb on

void func_021114b0(void) {
    data_0217d344->mUnk_18.mUnk_0c();
    func_021258f0();
}

#pragma thumb off

#pragma thumb on

void func_02111494(const void *a) {
    data_0217d344->mUnk_18 = *(const Unk0217d344_18 *) a;
}

#pragma thumb off

#pragma thumb on
void func_02111488(s32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    data_0217d344->mUnk_0c = value0;
}
#pragma thumb off

#pragma thumb on

u32 func_0211147c(void) {
    return (data_0217d344->mUnk_10);
}

u32 func_0211146c(void) {
    return (data_0217d344->mUnk_14);
}

u32 func_0211145c(void) {
    return (data_0217d344->mUnk_16);
}

void func_02111450(u32 p0) {
    data_0217d344->mUnk_16 = (u16) p0;
}

#pragma thumb off

#pragma thumb on

void func_02111428(void) {
    if (data_0217d344->mUnk_2c > 0) {
        data_0217d344->mUnk_2c = data_0217d344->mUnk_2c - 1;
        if (data_0217d344->mUnk_2c == 0) {
            data_0217d344->mUnk_18.mUnk_10();
        }
    }
}

#pragma thumb off

#pragma thumb on
u32 func_02111418(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 48u;
    value0 = *(const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_02111408(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 50u;
    value0 = *(const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
void func_021113fc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    data_0217d344->mUnk_30 = (u16) value0;
}
#pragma thumb off

#pragma thumb on
void func_021113f0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    data_0217d344->mUnk_32 = (u16) value0;
}
#pragma thumb off
