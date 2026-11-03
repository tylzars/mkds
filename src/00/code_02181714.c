#include "00/code_02181714.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "00/unk_021b0000.h"
#include "Main/Unknown/code_020472a8.h"
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
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02061250.h"

void InitWiFiTopMenu(void *heap) {
    s32 i;
    s32 j;
    s32 k;

    gWiFiTopMenu = func_02036bec(heap, 0x40);
    gWiFiTopMenu->mHeap = heap;
    gWiFiTopMenu->mUnk_00 = 0;
    gWiFiTopMenu->mUnk_04 = 0;
    gWiFiTopMenu->mPendingWiFiState = -1;
    switch (GetWiFiPrevState()) {
        case 0:
        case 2:
            gWiFiTopMenu->mUnk_08 = 0;
            break;
        case 8:
            gWiFiTopMenu->mUnk_08 = 1;
            break;
        case 13:
            gWiFiTopMenu->mUnk_08 = 2;
            break;
    }
    gWiFiTopMenu->mStateFrames = 0;
    gWiFiTopMenu->mUnk_18 = 1;
    gWiFiTopMenu->mUnk_38 = FindSceneFile("wifi.bmg");
    gWiFiTopMenu->mUnk_3c = func_02047a28("common.bmg");
    func_ov000_02181df8();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov000_021b05c0[i], 1, gWiFiTopMenu->mUnk_20, gWiFiTopMenu->mUnk_2c);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(heap, gWiFiTopMenu->mUnk_2c, NULL, &gWiFiTopMenu->mUnk_1c);
    for (j = 0; j < 3; j++) {
        for (k = 0; k < data_ov000_021b05cc[j]; k++) {
            gWiFiTopMenu->mUnk_1c[data_ov000_021b05d8[j][k]].mUnk_04 = 0xdc;
        }
    }
    func_0212a910(1, 0);
    func_021281c8(0xf);
    func_0204f7f4();
}

void func_ov000_02181e8c(void) {
    gWiFiTopMenu = NULL;
}

void func_ov000_02181df8(void) {
    void *v1;
    v1 = FindSceneFile(gWiFiTopMenuSBnclName);
    gWiFiTopMenu->mUnk_2c = v1;
    v1 = FindSceneFile(gWiFiTopMenuSBnblName);
    gWiFiTopMenu->mUnk_30 = v1;
    v1 = FindSceneFile(gWiFiTopMenuSNcgrName);
    LocateNcgr2(&gWiFiTopMenu->mUnk_24, v1);
    v1 = FindSceneFile(gWiFiTopMenuSNcerName);
    LocateNcer(&gWiFiTopMenu->mUnk_20, v1);
    v1 = FindSceneFile(gWiFiTopMenuSONclrName);
    LocateNclr(&gWiFiTopMenu->mUnk_28, v1);
    func_02016468(0x23, 0, (void *) (gWiFiTopMenu->mUnk_24->mData), (u32) (gWiFiTopMenu->mUnk_24->mDataSize));
    func_02016468(0x1e, 0, (void *) (gWiFiTopMenu->mUnk_28->mData), (u32) (gWiFiTopMenu->mUnk_28->mDataSize));
    return;
}

s32 func_ov000_02181df0(void) {
    return func_02061250();
}

void func_ov000_02181dd0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        gWiFiTopMenu->mUnk_04 = 1;
    }
    return;
}

void func_ov000_02181d44(void) {
    s32 v = 0;
    s32 i;
    s32 j;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    if (gWiFiTopMenu->mStateFrames >= 20) {
        gWiFiTopMenu->mUnk_04 = 2;
        gWiFiTopMenu->mStateFrames = v;
        func_02128374();
    } else if (gWiFiTopMenu->mStateFrames >= 10) {
        v = func_020ae488(gWiFiTopMenu->mStateFrames - 10);
    } else {
        v = func_020ae4c0(1, 0xdc, v, gWiFiTopMenu->mStateFrames, 10);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            gWiFiTopMenu->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
}

void func_ov000_02181d20(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gWiFiTopMenu->mUnk_04 = 3;
        func_021281c8(0xf);
    }
    return;
}

void func_ov000_02181b4c(void) {
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
        v2 = func_0201ea84(gWiFiTopMenu->mUnk_30, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    v5 = data_02175628[i].mUnk_00 & 2;
    if ((u16) v5 == 0) {
        v7 = v6 = FALSE;
        if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
            v7 = 1;
        }
        if (v7 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
            v6 = TRUE;
        }
        if (v6 == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto next;
        }
    }
    gWiFiTopMenu->mUnk_04 = 5;
    gWiFiTopMenu->mPendingWiFiState = 10;
    if (gWiFiTopMenu->mPendingWiFiState == 10) {
        func_02128310(1);
    }
    return;
next:
    v5 = data_02175628[i].mUnk_00 & 1;
    if ((u16) v5 != 0 || v2 <= 2) {
        v4 = gWiFiTopMenu->mUnk_08;
        if ((u16) v5 == 0) {
            switch (v2) {
                case 0:
                    gWiFiTopMenu->mUnk_08 = 0;
                    break;
                case 1:
                    gWiFiTopMenu->mUnk_08 = 1;
                    break;
                case 2:
                    gWiFiTopMenu->mUnk_08 = 2;
                    break;
            }
        }
        if (gWiFiTopMenu->mUnk_08 == v4) {
            gWiFiTopMenu->mUnk_18 = 0;
        }
        gWiFiTopMenu->mUnk_04 = 4;
        switch (gWiFiTopMenu->mUnk_08) {
            case 0:
                if (func_0211fd68() == 1) {
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
        func_02105ac0(5);
    } else {
        if (func_020ae408(8, 0x40) != 0) {
            gWiFiTopMenu->mUnk_08--;
            if (gWiFiTopMenu->mUnk_08 < 0) {
                gWiFiTopMenu->mUnk_08 = 2;
            }
            func_02105ac0(0);
        } else if (func_020ae408(8, 0x80) != 0) {
            gWiFiTopMenu->mUnk_08++;
            if (gWiFiTopMenu->mUnk_08 > 2) {
                gWiFiTopMenu->mUnk_08 = 0;
            }
            func_02105ac0(0);
        }
    }
}

void func_ov000_02181ab8(void) {
    s32 i;
    s32 v;

    gWiFiTopMenu->mStateFrames = gWiFiTopMenu->mStateFrames + 1;
    v = func_020ae488(gWiFiTopMenu->mStateFrames);
    for (i = 0; i < data_ov000_021b05cc[gWiFiTopMenu->mUnk_08]; i++) {
        gWiFiTopMenu->mUnk_1c[data_ov000_021b05d8[gWiFiTopMenu->mUnk_08][i]].mUnk_04 = v;
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        gWiFiTopMenu->mUnk_04 = 5;
        if (gWiFiTopMenu->mUnk_08 == 0 || gWiFiTopMenu->mUnk_08 == 2) {
            func_021282c8();
        }
        gWiFiTopMenu->mStateFrames = 0;
    } else if (gWiFiTopMenu->mStateFrames >= 5) {
        gWiFiTopMenu->mUnk_18 = 1;
    }
}

void func_ov000_0218198c(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov000_021806c4() == -1) {
        if (gWiFiTopMenu->mPendingWiFiState == 10 && func_0211fd68() != 1) {
            func_ov000_021806b8(0);
        } else if (gWiFiTopMenu->mPendingWiFiState == 13) {
            data_021759d0->mUnk_20 = 4;
            func_ov000_021806b8(12);
        }
    }
    gWiFiTopMenu->mStateFrames++;
    v = gWiFiTopMenu->mStateFrames;
    if (v <= 10) {
        v = func_020ae4c0(1, 0xdc, 0, 10 - v, 10);
    } else {
        v = 0xdc;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            gWiFiTopMenu->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
    if (gWiFiTopMenu->mStateFrames >= 10) {
        if ((gWiFiTopMenu->mPendingWiFiState == 10 || gWiFiTopMenu->mPendingWiFiState == 13) &&
            IsSelectReturnState0NoState1Request() == 0) {
            return;
        }
        if (func_ov000_021806c4() == -1) {
            if (gWiFiTopMenu->mPendingWiFiState == 8 && func_ov000_02181df0() == 0) {
                gWiFiTopMenu->mUnk_04 = 8;
                gWiFiTopMenu->mPendingWiFiState = -1;
                func_021266e4(GetBmgEntry(gWiFiTopMenu->mUnk_38, 0x12));
                gWiFiTopMenu->mStateFrames = 0;
                func_021281c8(0xe);
                return;
            }
            RequestWiFiState(gWiFiTopMenu->mPendingWiFiState);
        }
    }
}

void func_ov000_02181940(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125fc0();
        return;
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        v1 = func_02125f60();
        if (v1 == 0) {
            func_0211fd28();
            gWiFiTopMenu->mUnk_04 = 7;
            return;
        }
        gWiFiTopMenu->mUnk_04 = 1;
    }
}

void func_ov000_02181904(void) {
    int v1;
    v1 = func_ov000_021806c4();
    if ((v1 == -1) && (gWiFiTopMenu->mPendingWiFiState == 10)) {
        func_ov000_021806b8((u32) 0);
    }
    v1 = func_0211fd68();
    if (v1 != 1) {
        gWiFiTopMenu->mPendingWiFiState = 10;
    }
}

void func_ov000_02181854(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    BOOL b;
    u32 v;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125fa4() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
            a = b = FALSE;
            v = data_02175628[i].mHasPair;
            if (v == 0 && data_02175628[i].mNoPairCount < 5) {
                a = 1;
            }
            if (a == 0 && data_02175628[i].mPrevHasPair == 0 && v != 0) {
                b = TRUE;
            }
            if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48,
                                                                              data_02175628[i].mUnk_4a) == 0) {
                return;
            }
        }
        gWiFiTopMenu->mUnk_04 = 1;
        func_02128310(0);
        func_02125fc0();
    }
}

void func_ov000_021817e8(void) {
    s32 i = 0;
    BOOL v1 = FALSE;
    const u8 *p = data_ov000_021b05c4;
    const u8 *q = data_ov000_021b05c8;
    for (; i < 3; i++) {
        if (i == gWiFiTopMenu->mUnk_08 && gWiFiTopMenu->mUnk_18 != 0) {
            gWiFiTopMenu->mUnk_1c[*p].mUnk_00 = 1;
            func_02124a20(*q, 0xe, gWiFiTopMenu->mUnk_20, gWiFiTopMenu->mUnk_2c);
        } else {
            gWiFiTopMenu->mUnk_1c[*p].mUnk_00 = v1;
            func_02124a20(*q, 0xf, gWiFiTopMenu->mUnk_20, gWiFiTopMenu->mUnk_2c);
        }
        p++;
        q++;
    }
}

void AdvanceWiFiTopMenu(void) {
    Unk021b4c6c *p;
    gWiFiTopMenu->mUnk_00 = gWiFiTopMenu->mUnk_04;
    switch (gWiFiTopMenu->mUnk_00) {
        case 0:
            func_ov000_02181dd0();
            break;
        case 1:
            func_ov000_02181d44();
            break;
        case 2:
            func_ov000_02181d20();
            break;
        case 3:
            func_ov000_02181b4c();
            break;
        case 4:
            func_ov000_02181ab8();
            break;
        case 5:
            func_ov000_0218198c();
            break;
        case 6:
            func_ov000_02181940();
            break;
        case 7:
            func_ov000_02181904();
            break;
        case 8:
            func_ov000_02181854();
            break;
    }
    func_ov000_021817e8();
    p = gWiFiTopMenu;
    func_02124c30(p->mUnk_2c, p->mUnk_20, NULL, func_ov000_021804e0(), p->mUnk_1c);
}

void func_ov000_02181738(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), (u32) (0), 2, (u32) (6), 10);
    return;
}

void RegisterWiFiTopMenuCallbacks(void) {
    Unk021b0cd4 callbacks = gWiFiTopMenuCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
