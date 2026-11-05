#include "00/code_02184ba8.h"
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
    gWiFiAikotoba->mUnk_18 = a;
    gWiFiAikotoba->mState = 0;
    gWiFiAikotoba->mNextState = 0;
    gWiFiAikotoba->mUnk_10 = -1;
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
    gWiFiAikotoba->mUnk_0c = 0;
    gWiFiAikotoba->mUnk_14 = 1;
    func_ov000_021851a0();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b06c0[i], 1, gWiFiAikotoba->mUnk_20, gWiFiAikotoba->mUnk_2c);
    }
    c = func_ov000_021804f4();
    func_020ae6d4(c, func_ov000_021804e0());
    func_02124ed0(a, gWiFiAikotoba->mUnk_2c, NULL, &gWiFiAikotoba->mUnk_1c);
    gWiFiAikotoba->mUnk_38 = FindSceneFile(data_ov000_021b0ee8);
    gWiFiAikotoba->mUnk_3c = func_02047a28(data_ov000_021b0ef4);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            gWiFiAikotoba->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = 0xfa;
        }
    }
    func_021281c8(0xe);
}

void func_ov000_02185230(void) {
    gWiFiAikotoba = NULL;
}

void func_ov000_021851a0(void) {
    void *v1;
    v1 = FindSceneFile(data_ov000_021b0e70);
    gWiFiAikotoba->mUnk_2c = v1;
    v1 = FindSceneFile(data_ov000_021b0e84);
    gWiFiAikotoba->mUnk_30 = v1;
    v1 = FindSceneFile(data_ov000_021b0e98);
    LocateNcgr2(&gWiFiAikotoba->mUnk_24, v1);
    v1 = FindSceneFile(data_ov000_021b0eb4);
    LocateNcer(&gWiFiAikotoba->mUnk_20, v1);
    v1 = FindSceneFile(data_ov000_021b0ed0);
    LocateNclr(&gWiFiAikotoba->mUnk_28, v1);
    func_0214bea4((const void *) gWiFiAikotoba->mUnk_24->mData, 0, (u32) (gWiFiAikotoba->mUnk_24->mDataSize));
    func_0214c028((const void *) gWiFiAikotoba->mUnk_28->mData, 0, (u32) (gWiFiAikotoba->mUnk_28->mDataSize));
    return;
}

u32 func_ov000_02185184(void) {
    u32 v1;
    v1 = func_0205e548();
    if (60 <= v1) {
        return 1;
    }
    return 0;
}

void AdvanceWiFiAikotobaState0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        gWiFiAikotoba->mNextState = 1;
    }
    return;
}

void AdvanceWiFiAikotobaState1(void) {
    s32 a;
    s32 i;
    s32 j;

    gWiFiAikotoba->mUnk_0c = gWiFiAikotoba->mUnk_0c + 1;
    a = func_020ae4c0(1, 0xfa, 0, gWiFiAikotoba->mUnk_0c, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = a;
            } else {
                gWiFiAikotoba->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = -a;
            }
        }
    }
    if (gWiFiAikotoba->mUnk_0c >= 10) {
        gWiFiAikotoba->mNextState = 2;
        gWiFiAikotoba->mUnk_0c = 0;
        func_02128374();
    }
}

void AdvanceWiFiAikotobaState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gWiFiAikotoba->mNextState = 3;
    }
    return;
}

void AdvanceWiFiAikotobaState3(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u32 a = -1;
    BOOL b;
    BOOL c;
    u16 d;
    s32 f;
    u32 e;
    Unk021b4c84 *p;

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
        a = RectTableFindContaining(gWiFiAikotoba->mUnk_30, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        b = FALSE;
        c = FALSE;
        d = data_02175628[i].mHasPair;
        if (d == 0 && data_02175628[i].mNoPairCount < 5) {
            c = TRUE;
        }
        if (c == FALSE && data_02175628[i].mPrevHasPair == 0 && d != 0) {
            b = TRUE;
        }
        if (b == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    gWiFiAikotoba->mNextState = 5;
    gWiFiAikotoba->mUnk_10 = 1;
    func_02128310(0);
    return;
next:
    e = data_02175628[i].mUnk_00 & 1;
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
                gWiFiAikotoba->mUnk_10 = 11;
                break;
            case 1:
                gWiFiAikotoba->mUnk_10 = 9;
                break;
        }
        if (gWiFiAikotoba->mUnk_08 == f) {
            gWiFiAikotoba->mUnk_14 = 0;
        }
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0 && gWiFiAikotoba->mUnk_08 > 0) {
        gWiFiAikotoba->mUnk_08 = gWiFiAikotoba->mUnk_08 - 1;
        func_02105ac0(0);
        return;
    }
    if (func_020ae408(8, 0x80) != 0 && gWiFiAikotoba->mUnk_08 < 1) {
        gWiFiAikotoba->mUnk_08 = gWiFiAikotoba->mUnk_08 + 1;
        func_02105ac0(0);
    }
}

void AdvanceWiFiAikotobaState4(void) {
    gWiFiAikotoba->mUnk_0c = gWiFiAikotoba->mUnk_0c + 1;
    if (gWiFiAikotoba->mUnk_0c >= 10) {
        gWiFiAikotoba->mNextState = 5;
        if (gWiFiAikotoba->mUnk_10 == 11) {
            func_021282c8();
        }
        gWiFiAikotoba->mUnk_0c = 0;
    } else if (gWiFiAikotoba->mUnk_0c >= 5) {
        gWiFiAikotoba->mUnk_14 = 1;
    }
}

void AdvanceWiFiAikotobaState5(void) {
    s32 a;
    s32 i;
    s32 j;
    s32 b;
    void *c;

    if (func_ov000_021806c4() == -1 && func_ov000_02185184() == 0 && gWiFiAikotoba->mUnk_10 == 11) {
        func_ov000_021806b8(0xe);
    }
    gWiFiAikotoba->mUnk_0c = gWiFiAikotoba->mUnk_0c + 1;
    if (gWiFiAikotoba->mUnk_0c <= 10) {
        a = func_020ae4c0(1, 0, 0xfa, gWiFiAikotoba->mUnk_0c, 10);
    } else {
        a = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov000_021b06c8[i]; j++) {
            if (i == 1) {
                gWiFiAikotoba->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = a;
            } else {
                gWiFiAikotoba->mUnk_1c[data_ov000_021b06d0[i][j]].mUnk_04 = -a;
            }
        }
    }
    if (gWiFiAikotoba->mUnk_0c >= 10) {
        if (func_ov000_02185184() != 0 && gWiFiAikotoba->mUnk_10 == 11) {
            gWiFiAikotoba->mNextState = 6;
            gWiFiAikotoba->mUnk_10 = -1;
            c = GetBmgEntry(gWiFiAikotoba->mUnk_38, 0xf);
            func_02126570(c, GetBmgEntry(gWiFiAikotoba->mUnk_3c, 6));
            gWiFiAikotoba->mUnk_0c = 0;
            return;
        }
        if (func_ov000_021806c4() == -1) {
            RequestWiFiState(gWiFiAikotoba->mUnk_10);
        }
    }
}

void AdvanceWiFiAikotobaState6(void) {
    void *a;
    void *b;

    if (func_02125f88() != 0 && IsSelectReturnState0NoState1Request() != 0) {
        gWiFiAikotoba->mNextState = 7;
        a = GetBmgEntry(gWiFiAikotoba->mUnk_38, 0x10);
        b = GetBmgEntry(gWiFiAikotoba->mUnk_3c, 0);
        func_02126454(a, b, GetBmgEntry(gWiFiAikotoba->mUnk_3c, 1), 0);
        return;
    }
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
}

void AdvanceWiFiAikotobaState7(void) {
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            gWiFiAikotoba->mUnk_10 = 0xe;
            if (func_ov000_021806c4() == -1) {
                func_ov000_021806b8(8);
            }
            data_0217b488->mUnk_50 = 1;
            return;
        }
        gWiFiAikotoba->mNextState = 1;
        gWiFiAikotoba->mUnk_10 = -1;
        return;
    }
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
}

void func_ov000_02184c74(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (i == gWiFiAikotoba->mUnk_08 && gWiFiAikotoba->mUnk_14 != 0) {
            gWiFiAikotoba->mUnk_1c[data_ov000_021b06c4[i]].mUnk_00 = 1;
            func_02124a20(data_ov000_021b06bc[i], 0xe, gWiFiAikotoba->mUnk_20, gWiFiAikotoba->mUnk_2c);
        } else {
            gWiFiAikotoba->mUnk_1c[data_ov000_021b06c4[i]].mUnk_00 = 0;
            func_02124a20(data_ov000_021b06bc[i], 0xf, gWiFiAikotoba->mUnk_20, gWiFiAikotoba->mUnk_2c);
        }
    }
}

void AdvanceWiFiAikotoba(void) {
    Unk021b4c84 *p;

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
    func_02124c30(p->mUnk_2c, p->mUnk_20, NULL, func_ov000_021804e0(), p->mUnk_1c);
}

void func_ov000_02184bcc(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), (u32) (0), 2, (u32) (6), 10);
    return;
}

void RegisterWiFiAikotobaCallbacks(void) {
    Unk021b0cd4 callbacks = gWiFiAikotobaCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
