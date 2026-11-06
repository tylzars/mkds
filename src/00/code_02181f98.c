#include "00/code_02181f98.h"

#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "code_0214a390.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02125f88.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_0212630c.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020ee684.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02122ae4.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"

BOOL func_ov000_021832f0(void) {
    if (func_0205e548() != 0) {
        return TRUE;
    }
    return FALSE;
}

void InitWiFiVSSetting(void *heap) {
    s32 i;

    gWiFiVSSetting = HeapAlloc(heap, 0x1060);
    gWiFiVSSetting->mHeap = heap;
    gWiFiVSSetting->mState = 0;
    gWiFiVSSetting->mNextState = 0;
    gWiFiVSSetting->mRow = 1;
    gWiFiVSSetting->mPendingWiFiState = -1;
    gWiFiVSSetting->mStateFrames = 0;
    gWiFiVSSetting->mUnk_24 = TRUE;
    func_ov000_02180638(0);
    func_ov000_02182e18();
    func_0212b928(heap, gWiFiVSSetting->mWiFiVSSettingSONclr, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b060c[i][0], 1, gWiFiVSSetting->mWiFiVSSettingSNcer,
                      gWiFiVSSetting->mWiFiVSSettingBncl);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(heap, gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingBnll,
                  &gWiFiVSSetting->mWiFiVSSettingTable);
    gWiFiVSSetting->mWiFiMessages = FindSceneFile("wifi.bmg");
    gWiFiVSSetting->mCommonMessages = func_02047a28("common.bmg");
    {
        s32 v = GX_GetSizeOfSubOBJ();
        u8 a[1] = {1};
        u8 b[1][2] = {{0xc8, 0x10}};
        u32 c[1] = {1};

        for (i = 0; i < 1; i++) {
            v -= func_021243ac(heap, a[i], gWiFiVSSetting->mWiFiVSSettingBnll, b[i][0], b[i][1],
                               data_ov000_021b060c[i][11], gWiFiVSSetting->mWiFiVSSettingSNcer,
                               gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable, v);
            func_0212426c(1, a[i], gWiFiVSSetting->mWiFiVSSettingBnll, GetBmgEntry(gWiFiVSSetting->mWiFiMessages, c[i]),
                          gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
        }
        {
            u8 d[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 k;
            void *t;

            for (i = 0; i < 3; i++) {
                k = 0;
                if (i == 1) {
                    gWiFiVSSetting->mSettingIndex = data_ov000_021b05f0[data_0217b488->mUnk_54];
                    if (gWiFiVSSetting->mSettingIndex == 0 && !func_ov000_021832f0()) {
                        gWiFiVSSetting->mSettingIndex = 2;
                    }
                    k = gWiFiVSSetting->mSettingIndex;
                }
                v -= func_021243ac(heap, data_ov000_021b05e8[i], gWiFiVSSetting->mWiFiVSSettingBnll, d[i][0], d[i][1],
                                   data_ov000_021b060c[i][1], gWiFiVSSetting->mWiFiVSSettingSNcer,
                                   gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable, v);
                if (i == 2) {
                    t = GetBmgEntry(gWiFiVSSetting->mCommonMessages, data_ov000_021b0628[i][k]);
                } else if (i == 1) {
                    t = GetBmgEntry(gWiFiVSSetting->mWiFiMessages,
                                    LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex));
                } else {
                    t = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, data_ov000_021b0628[i][k]);
                }
                func_0212426c(1, data_ov000_021b05e8[i], gWiFiVSSetting->mWiFiVSSettingBnll, t,
                              gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingTable);
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            gWiFiVSSetting->mUnk_14[i][0] = 0;
            gWiFiVSSetting->mUnk_14[i][1] = 0x28;
        } else if (i == 1) {
            gWiFiVSSetting->mUnk_14[i][0] = -0x100;
            gWiFiVSSetting->mUnk_14[i][1] = 0;
        } else {
            gWiFiVSSetting->mUnk_14[i][0] = 0x100;
            gWiFiVSSetting->mUnk_14[i][1] = 0;
        }
    }
    gWiFiVSSetting->mIndexDecrementTimer = 0;
    gWiFiVSSetting->mIndexIncrementTimer = 0;
    func_0212a910(1, 1);
    func_021281c8(0xe);
}

void func_ov000_02182f88(void) {
    u32 a;

    a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    a &= ~8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (a << 8);
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0xf00;
    func_0212b91c();
    gWiFiVSSetting = NULL;
}

void func_ov000_02182e18(void) {
    Ncgr *v1;
    Nscr *v2;
    Nclr *v3;
    vu16 v4;

    LocateNcgr(&v1, FindSceneFile("WiFi_VS_setting_s_b.ncgr"));
    LocateNscr(&v2, FindSceneFile("WiFi_VS_s_setting.nscr"));
    LocateNclr(&v3, FindSceneFile("WiFi_VS_setting_s_b.nclr"));
    gWiFiVSSetting->mWiFiVSSettingBncl = FindSceneFile("WiFi_VS_setting.bncl");
    gWiFiVSSetting->mWiFiVSSettingBnbl = FindSceneFile("WiFi_VS_setting.bnbl");
    gWiFiVSSetting->mWiFiVSSettingBnll = FindSceneFile("WiFi_VS_setting.bnll");
    LocateNcgr2(&gWiFiVSSetting->mWiFiVSSettingSNcgr, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LocateNcer(&gWiFiVSSetting->mWiFiVSSettingSNcer, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LocateNclr(&gWiFiVSSetting->mWiFiVSSettingSONclr, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x4400;
    v4 = 0;
    MIi_CpuClear16(v4, gWiFiVSSetting->mNscrCopy, 0x1000);
    MIi_CpuCopy16(v2->mData, gWiFiVSSetting->mNscrCopy, 0x800);
    CallQueueAppend(0x17, 0, v1->mData, v1->mDataSize);
    CallQueueAppend(0x1b, 0, gWiFiVSSetting->mNscrCopy, 0x1000);
    CallQueueAppend(0x1f, 0, v3->mData, 0x80);
    CallQueueAppend(0x23, 0, gWiFiVSSetting->mWiFiVSSettingSNcgr->mData,
                    gWiFiVSSetting->mWiFiVSSettingSNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, gWiFiVSSetting->mWiFiVSSettingSONclr->mData,
                    gWiFiVSSetting->mWiFiVSSettingSONclr->mDataSize);
}

void func_ov000_02182de8(void) {
    void *v1;
    v1 = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0);
    func_02126638(v1, 0, 0, 1, 0, 0, 0);
}

void AdvanceWiFiVSSettingState0(void) {
    if (func_02036d08() != 0) {
        func_02037288(10);
    }
    if (func_02036c5c() != 0) {
        if (func_02122ae4() != 0) {
            gWiFiVSSetting->mNextState = 1;
            func_02126638(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x1b), 0, 0, 1, 0, 0, 0);
            func_02122ab0();
            func_0211fe44();
            return;
        }
        gWiFiVSSetting->mNextState = 2;
        func_ov000_02182de8();
        func_0211fe44();
    }
}

void AdvanceWiFiVSSettingState1(void) {
    int v1;
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    v1 = func_02125fa4();
    if ((v1 != 0) && (0x78 < gWiFiVSSetting->mStateFrames)) {
        func_02125fc0();
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        gWiFiVSSetting->mNextState = 2;
        func_ov000_02182de8();
        gWiFiVSSetting->mStateFrames = 0;
    }
    return;
}

void AdvanceWiFiVSSettingState2(void) {
    s32 v;
    s32 i;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    v = func_020ae4c0(1, 0x100, 0, gWiFiVSSetting->mStateFrames, 10);
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gWiFiVSSetting->mUnk_14[i][0] = v;
        } else {
            gWiFiVSSetting->mUnk_14[i][0] = -v;
        }
    }
    if (gWiFiVSSetting->mStateFrames >= 10) {
        gWiFiVSSetting->mNextState = 3;
        gWiFiVSSetting->mStateFrames = 0;
        func_02128374();
    }
}

void AdvanceWiFiVSSettingState3(void) {
    s16 v;

    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames < 3) {
        v = -func_0212825c(0);
    } else {
        v = -func_0212825c(gWiFiVSSetting->mStateFrames - 3);
    }
    gWiFiVSSetting->mUnk_14[2][1] = v;
    if (gWiFiVSSetting->mStateFrames >= 10 && gWiFiVSSetting->mStateFrames >= 13) {
        gWiFiVSSetting->mNextState = 4;
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingState4(void) {
    s32 v1 = gWiFiVSSetting->mRow;
    s32 prevSettingIndex = gWiFiVSSetting->mSettingIndex;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL v3 = FALSE;
    u32 v4 = -1;
    BOOL v5 = FALSE;
    BOOL v6;
    s32 v7;
    s32 v8;
    Unk02175628 *e;
    u32 messageIndex;

    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        v5 = TRUE;
    }
    if (v5 == FALSE && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        v3 = TRUE;
    }
    if (v3 != FALSE) {
        v4 = RectTableFindContaining(gWiFiVSSetting->mWiFiVSSettingBnbl, data_02175670[i].mUnk_00,
                                     data_02175672[i].mUnk_00);
    }
    e = &data_02175628[i];
    v8 = e->mUnk_00 & 2;
    if ((u16) v8 == 0) {
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
    gWiFiVSSetting->mNextState = 6;
    gWiFiVSSetting->mPendingWiFiState = 1;
    func_02128310(1);
    gWiFiVSSetting->mUnk_28 = TRUE;
    func_02125fc0();
    goto end;
next:
    v8 = e->mUnk_00 & 1;
    if (((u16) v8 != 0 && gWiFiVSSetting->mRow == 2) || v4 == 2) {
        gWiFiVSSetting->mNextState = 5;
        if (gWiFiVSSetting->mRow == 2) {
            gWiFiVSSetting->mUnk_24 = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = 3;
        gWiFiVSSetting->mRow = 2;
        data_0217b488->mUnk_54 = data_ov000_021b05ec[gWiFiVSSetting->mSettingIndex];
        if ((u16) (data_0217562a[i].mBits & 0x100) != 0) {
            func_ov000_02180638(1);
        }
        SetWiFiVSSettingIndex(gWiFiVSSetting->mSettingIndex);
        func_02105ac0(5);
    } else if (((u16) v8 != 0 && gWiFiVSSetting->mRow == 0) || v4 == 0) {
        gWiFiVSSetting->mNextState = 5;
        if (gWiFiVSSetting->mRow == 0) {
            gWiFiVSSetting->mUnk_24 = FALSE;
        }
        gWiFiVSSetting->mPendingWiFiState = 14;
        gWiFiVSSetting->mRow = 0;
        data_0217b488->mUnk_50 = 0;
        func_02125fc0();
        func_02105ac0(5);
        data_0217b488->mUnk_54 = data_ov000_021b05ec[gWiFiVSSetting->mSettingIndex];
        func_0211fe44();
    } else if (v4 == 1) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        func_02105ac0(1);
    } else if (func_020ae408(8, 0x40) != 0) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow - 1;
        if (gWiFiVSSetting->mRow < 0) {
            gWiFiVSSetting->mRow = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0 || (gWiFiVSSetting->mRow == 1 && (u16) (e->mUnk_00 & 1) != 0)) {
        gWiFiVSSetting->mRow = gWiFiVSSetting->mRow + 1;
        if (gWiFiVSSetting->mRow > 2) {
            gWiFiVSSetting->mRow = 0;
        }
        func_02105ac0(0);
    } else if (gWiFiVSSetting->mRow == 1 && func_020ae408(8, 0x20) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = 6;
        func_02105ac0(1);
    } else if (gWiFiVSSetting->mRow == 1 && func_020ae408(8, 0x10) != 0) {
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        if (func_020ae408(8, 0x10) != 0) {
            gWiFiVSSetting->mIndexIncrementTimer = 6;
        }
        func_02105ac0(1);
    } else if (v4 == 3) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex - 1;
        gWiFiVSSetting->mIndexDecrementTimer = 6;
        func_02105ac0(1);
    } else if (v4 == 4) {
        gWiFiVSSetting->mRow = 1;
        gWiFiVSSetting->mSettingIndex = gWiFiVSSetting->mSettingIndex + 1;
        gWiFiVSSetting->mIndexIncrementTimer = 6;
        func_02105ac0(1);
    }
end:
    if (gWiFiVSSetting->mSettingIndex < 0) {
        gWiFiVSSetting->mSettingIndex = 3;
    }
    if (gWiFiVSSetting->mSettingIndex > 3) {
        gWiFiVSSetting->mSettingIndex = 0;
    }
    if (prevSettingIndex != gWiFiVSSetting->mSettingIndex) {
        messageIndex = LookupWiFiVSSettingMessageIndex(gWiFiVSSetting->mSettingIndex);
        func_0212426c(1, data_ov000_021b05e8[1], gWiFiVSSetting->mWiFiVSSettingBnll,
                      GetBmgEntry(gWiFiVSSetting->mWiFiMessages, messageIndex), gWiFiVSSetting->mWiFiVSSettingBncl,
                      gWiFiVSSetting->mWiFiVSSettingTable);
    }
    if (gWiFiVSSetting->mRow == 2 && v1 != 2) {
        func_0212b7fc();
    }
}

void AdvanceWiFiVSSettingState5(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames >= 10) {
        gWiFiVSSetting->mNextState = 6;
        gWiFiVSSetting->mStateFrames = 0;
        func_02125fc0();
        if (func_ov000_021832f0() != FALSE ||
            (gWiFiVSSetting->mPendingWiFiState == 3 && gWiFiVSSetting->mSettingIndex != 0)) {
            func_021282c8();
            gWiFiVSSetting->mUnk_28 = TRUE;
            return;
        }
        gWiFiVSSetting->mUnk_28 = FALSE;
    } else if (gWiFiVSSetting->mStateFrames >= 5) {
        gWiFiVSSetting->mUnk_24 = TRUE;
    }
}

void AdvanceWiFiVSSettingState6(void) {
    s32 v;
    s16 u;
    s32 i;

    if (GetWiFiNextScene() == -1 && gWiFiVSSetting->mPendingWiFiState == 14 && func_ov000_021832f0() != FALSE) {
        SetWiFiNextScene(8);
    }
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (gWiFiVSSetting->mStateFrames <= 10) {
        v = func_020ae4c0(1, 0, 0x100, gWiFiVSSetting->mStateFrames, 10);
    } else {
        v = 0x100;
    }
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            gWiFiVSSetting->mUnk_14[i][0] = v;
        } else {
            gWiFiVSSetting->mUnk_14[i][0] = -v;
        }
    }
    if (gWiFiVSSetting->mStateFrames < 3) {
        u = -func_020ae584(0);
    } else {
        u = -func_02128244(gWiFiVSSetting->mStateFrames - 3);
    }
    for (i = 0; i < data_ov000_021b0600[2]; i++) {
        gWiFiVSSetting->mUnk_14[2][1] = u;
    }
    if (gWiFiVSSetting->mStateFrames >= 10 && gWiFiVSSetting->mStateFrames >= 13 && func_02125f88() != 0 &&
        ((gWiFiVSSetting->mUnk_28 != FALSE && IsSelectReturnState0NoState1Request() != 0) ||
         IsSelectReturnState2NoState3Or4Request() != 0) &&
        GetWiFiNextScene() == -1) {
        if (gWiFiVSSetting->mPendingWiFiState == 14 && func_ov000_021832f0() == FALSE) {
            gWiFiVSSetting->mNextState = 7;
            gWiFiVSSetting->mPendingWiFiState = -1;
            func_021266e4(GetBmgEntry(gWiFiVSSetting->mCommonMessages, 0x76));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == 3 && gWiFiVSSetting->mSettingIndex == 0 &&
            func_ov000_021832f0() == FALSE) {
            gWiFiVSSetting->mNextState = 8;
            gWiFiVSSetting->mPendingWiFiState = -1;
            func_021266e4(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 14));
            gWiFiVSSetting->mStateFrames = 0;
            return;
        }
        if (gWiFiVSSetting->mPendingWiFiState == 1) {
            void *a;
            void *b;
            void *c;

            gWiFiVSSetting->mNextState = 9;
            gWiFiVSSetting->mStateFrames = 0;
            gWiFiVSSetting->mUnk_34 = FALSE;
            a = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x17);
            b = GetBmgEntry(gWiFiVSSetting->mCommonMessages, 0);
            c = GetBmgEntry(gWiFiVSSetting->mCommonMessages, 1);
            func_02126454(a, b, c, 0);
            return;
        }
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void AdvanceWiFiVSSettingState7(void) {
    Unk02175628Index v1 = UNK_02175628_INDEX_8;
    BOOL a;
    BOOL b;
    u16 v;

    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125f88() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        gWiFiVSSetting->mNextState = 2;
        func_ov000_02182de8();
        gWiFiVSSetting->mRow = 1;
        return;
    }
    if (func_02125fa4() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (data_02175628[v1].mUnk_00 & 2) == 0) {
            a = FALSE;
            b = FALSE;
            v = data_02175674[v1].mUnk_00;
            if (v == 0 && data_02175680[v1].mUnk_00 < 5) {
                b = TRUE;
            }
            if (b == FALSE && data_0217567c[v1].mUnk_00 == 0 && v != 0) {
                a = TRUE;
            }
            if (a == FALSE) {
                return;
            }
            if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[v1].mUnk_00, data_02175672[v1].mUnk_00) ==
                FALSE) {
                return;
            }
        }
        func_02125fc0();
        func_02128310(0);
    }
}

void AdvanceWiFiVSSettingState8(void) {
    Unk02175628Index v1 = UNK_02175628_INDEX_8;
    BOOL a;
    BOOL b;
    u16 v;

    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125f88() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        gWiFiVSSetting->mNextState = 2;
        func_ov000_02182de8();
        gWiFiVSSetting->mRow = 1;
        return;
    }
    if (func_02125fa4() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (data_02175628[v1].mUnk_00 & 2) == 0) {
            a = FALSE;
            b = FALSE;
            v = data_02175674[v1].mUnk_00;
            if (v == 0 && data_02175680[v1].mUnk_00 < 5) {
                b = TRUE;
            }
            if (b == FALSE && data_0217567c[v1].mUnk_00 == 0 && v != 0) {
                a = TRUE;
            }
            if (a == FALSE) {
                return;
            }
            if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[v1].mUnk_00, data_02175672[v1].mUnk_00) ==
                FALSE) {
                return;
            }
        }
        func_02125fc0();
        func_02128310(0);
    }
}

void AdvanceWiFiVSSettingState9(void) {
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            gWiFiVSSetting->mNextState = 10;
            func_02126638(GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x18), 1, 1, 1, 0, 1, 0);
            return;
        }
        gWiFiVSSetting->mNextState = 2;
        func_ov000_02182de8();
        gWiFiVSSetting->mRow = 1;
    }
}

void AdvanceWiFiVSSettingState10(void) {
    gWiFiVSSetting->mStateFrames = gWiFiVSSetting->mStateFrames + 1;
    if (func_02125fa4() != 0 && gWiFiVSSetting->mUnk_34 == FALSE) {
        gWiFiVSSetting->mUnk_34 = TRUE;
        func_0211fe18();
    }
    if (gWiFiVSSetting->mUnk_34 != FALSE && func_0211fda8() != 0 && gWiFiVSSetting->mStateFrames > 90 &&
        func_02125fa4() != 0) {
        void *t;

        gWiFiVSSetting->mNextState = 11;
        t = GetBmgEntry(gWiFiVSSetting->mWiFiMessages, 0x19);
        func_02126570(t, GetBmgEntry(gWiFiVSSetting->mCommonMessages, 4));
        gWiFiVSSetting->mStateFrames = 0;
    }
}

void AdvanceWiFiVSSettingState11(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125fc0();
        return;
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        RequestWiFiState(gWiFiVSSetting->mPendingWiFiState);
    }
}

void func_ov000_02182270(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 v;

    v = gWiFiVSSetting->mWiFiVSSettingBncl->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b0600[i]; j++) {
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b060c[i][j]].mUnk_04 = gWiFiVSSetting->mUnk_14[i][0];
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b060c[i][j]].mUnk_06 = gWiFiVSSetting->mUnk_14[i][1];
        }
    }
    for (i = 0; i < 3; i++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[data_ov000_021b05e8[i]].mUnk_04 = gWiFiVSSetting->mUnk_14[i][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[data_ov000_021b05e8[i]].mUnk_06 = gWiFiVSSetting->mUnk_14[i][1];
    }
    for (k = 0; k < 3; k++) {
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[1].mUnk_04 = gWiFiVSSetting->mUnk_14[1][0];
        (gWiFiVSSetting->mWiFiVSSettingTable + v)[1].mUnk_06 = gWiFiVSSetting->mUnk_14[1][1];
    }
    for (i = 0; i < 3; i++) {
        gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[i][0]].mUnk_04 -=
            func_020adc64(6 - gWiFiVSSetting->mIndexDecrementTimer);
        gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[i][1]].mUnk_04 +=
            func_020adc64(6 - gWiFiVSSetting->mIndexIncrementTimer);
    }
}

void func_ov000_021821e0(void) {
    s32 i;
    BOOL z = FALSE;

    for (i = 0; i < 3; i++) {
        if (i == gWiFiVSSetting->mRow && gWiFiVSSetting->mUnk_24 != FALSE) {
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b060c[i][1]].mUnk_00 = 1;
            func_02124100(data_ov000_021b05e8[i], 14, gWiFiVSSetting->mWiFiVSSettingBnll,
                          gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b060c[i][1]].mUnk_00 = z;
            func_02124100(data_ov000_021b05e8[i], 15, gWiFiVSSetting->mWiFiVSSettingBnll,
                          gWiFiVSSetting->mWiFiVSSettingTable, gWiFiVSSetting->mWiFiVSSettingBncl);
        }
    }
}

void func_ov000_02182150(void) {
    s32 i;
    BOOL z = FALSE;
    BOOL y = FALSE;

    for (i = 0; i < 2; i++) {
        if (gWiFiVSSetting->mRow == 1) {
            if ((&gWiFiVSSetting->mIndexDecrementTimer)[i] > 0) {
                gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[0][i]].mUnk_00 = 1;
                gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
                (&gWiFiVSSetting->mIndexDecrementTimer)[i]--;
            } else {
                gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[0][i]].mUnk_00 = y;
                gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
            }
        } else {
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[0][i]].mUnk_00 = z;
            gWiFiVSSetting->mWiFiVSSettingTable[data_ov000_021b05f8[1][i]].mUnk_00 = z;
        }
    }
}

void AdvanceWiFiVSSetting(void) {
    gWiFiVSSetting->mState = gWiFiVSSetting->mNextState;
    switch (gWiFiVSSetting->mState) {
        case 0:
            AdvanceWiFiVSSettingState0();
            break;
        case 1:
            AdvanceWiFiVSSettingState1();
            break;
        case 2:
            AdvanceWiFiVSSettingState2();
            break;
        case 3:
            AdvanceWiFiVSSettingState3();
            break;
        case 4:
            AdvanceWiFiVSSettingState4();
            break;
        case 5:
            AdvanceWiFiVSSettingState5();
            break;
        case 6:
            AdvanceWiFiVSSettingState6();
            break;
        case 7:
            AdvanceWiFiVSSettingState7();
            break;
        case 8:
            AdvanceWiFiVSSettingState8();
            break;
        case 9:
            AdvanceWiFiVSSettingState9();
            break;
        case 10:
            AdvanceWiFiVSSettingState10();
            break;
        case 11:
            AdvanceWiFiVSSettingState11();
            break;
    }
    func_0212b80c();
    func_ov000_02182270();
    func_ov000_021821e0();
    func_ov000_02182150();
    func_02124c30(gWiFiVSSetting->mWiFiVSSettingBncl, gWiFiVSSetting->mWiFiVSSettingSNcer,
                  gWiFiVSSetting->mWiFiVSSettingBnll, func_ov000_021804e0(), gWiFiVSSetting->mWiFiVSSettingTable);
}

void func_ov000_02181ff0(void) {
    u32 a;
    u32 b;
    s32 v;

    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    a |= 4;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
    G2x_SetBlendAlpha_((u32 *) 0x4000050, 0, 2, 6, 10);
    v = -gWiFiVSSetting->mUnk_14[1][0];
    if (v <= -256) {
        v = -256;
    }
    if (v >= 0x100) {
        v = 0x100;
    }
    *(vu32 *) 0x400101c = v & 0x1ff;
}

WiFiStateCallbacks gWiFiVSSettingCallbacks = {InitWiFiVSSetting, func_ov000_02182f88, AdvanceWiFiVSSetting,
                                              func_ov000_02181ff0};

void RegisterWiFiVSSettingCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiVSSettingCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
