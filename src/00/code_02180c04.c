#include "00/code_02180c04.h"

#include "00/code_02180608.h"
#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_021205f4.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021089f4.h"
#include "Main/Unknown/code_02108b78.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_0212630c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02061250.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_02047104.h"

void func_ov000_021816b0(void *heap) {
    data_ov000_021b4c68 = HeapAlloc(heap, 0x40);
    data_ov000_021b4c68->mHeap = heap;
    data_ov000_021b4c68->mState = 0;
    data_ov000_021b4c68->mNextState = 0;
    data_ov000_021b4c68->mPendingWiFiState = -1;
    data_ov000_021b4c68->mUnk_08 = 0;
    data_ov000_021b4c68->mWiFiMessages = FindSceneFile("wifi.bmg");
    data_ov000_021b4c68->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    func_ov000_021816a0();
    func_0212a910(1, 1);
    SetSelectReturnSoundId(0xe);
    func_0204f804();
}

void func_ov000_021816a4(void) {
    data_ov000_021b4c68 = NULL;
}

void func_ov000_021816a0(void) {}

BOOL func_ov000_02181684(void) {
    if (func_02061250() == 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov000_0218167c(void) {
    return func_02061290();
}

u32 func_ov000_02181674(void) {
    u32 value0;
    u32 value3;
    value3 = (u32) &func_021205f4;
    value0 = func_021205f4();
    return value0;
}

Unk021b4c68 *data_ov000_021b4c68;

WiFiStateCallbacks data_ov000_021b0a98 = {func_ov000_021816b0, func_ov000_021816a4, func_ov000_02180c3c,
                                          (void (*)(void)) func_ov000_02180c28};

static inline s32 func_ov000_02180e58_inline(void) {
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mUnk_0c != 0) {
            return data_021759d4->mUnk_10;
        }
        return 0;
    }
    return 1;
}

s32 func_ov000_0218151c(s32 a, s32 b, s32 *c) {
    u8 t[9] = {2, 2, 1, 2, 2, 2, 1, 2, 2};
    u16 u[9][2] = {{0x15, 0x26}, {0x27, 0x26}, {0x28, 0},    {0x29, 0x16}, {0x15, 0x16},
                   {0x2a, 0x2b}, {0x2c, 0},    {0x2d, 0x2e}, {0x2f, 0x2e}};
    s32 i = 0;
    s32 v;
    if (a == 0x4e8c) {
        i = 1;
    } else if (a == 0x4e8e) {
        i = 2;
    } else if ((a >= 0xc79b && a <= 0xc79e) || (a >= 0xc7a0 && a <= 0xc7fe) || (a >= 0xc864 && a <= 0xc8c6)) {
        i = 3;
    } else if ((a >= 0xcb20 && a <= 0xcb23) || (a >= 0xcb84 && a <= 0xcb87) || (a >= 0xcbe8 && a <= 0xcbeb)) {
        i = 4;
    } else if (a == 0xc79f) {
        i = 5;
    } else if (a >= 0xc350 && a <= 0xc3b3) {
        i = 6;
    } else if (a == 0x4e85 || (a >= 0x59d8 && a <= 0x5dbf)) {
        i = 7;
    } else if (a >= 0xc800 && a <= 0xc863) {
        i = 8;
    }
    v = t[i];
    *c = v;
    if (b >= v) {
        return -1;
    }
    return u[i][b];
}

void func_ov000_02181458(void) {
    if (func_ov000_02181684() != FALSE) {
        data_ov000_021b4c68->mNextState = 1;
        SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x1c),
                                     GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
        data_ov000_021b4c68->mMessageTableIndex = 0;
        return;
    }
    if (func_ov000_0218167c() != 0) {
        data_ov000_021b4c68->mNextState = 6;
        SetupTxtSystemMainTextTwoButtons(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x13),
                                         GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 0),
                                         GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 1), 0);
        return;
    }
    data_ov000_021b4c68->mNextState = 2;
    SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x20),
                                 GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
}

void func_ov000_0218134c(void) {
    Unk021b4c68 *p;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 a[2] = {0, 0x1d};
        if (data_ov000_021b4c68->mMessageTableIndex < 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextButton(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                         GetBmgEntry(p->mCommonMessages, 6));
            return;
        }
        if (data_ov000_021b4c68->mMessageTableIndex == 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextTwoButtons(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                             GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 0),
                                             GetBmgEntry(p->mCommonMessages, 1), 0);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            data_ov000_021b4c68->mNextState = 7;
            func_02126638(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            func_0211fe24();
            data_ov000_021b4c68->mUnk_14 = TRUE;
            func_02108bb4();
            return;
        }
        data_ov000_021b4c68->mPendingWiFiState = 1;
        RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
    }
}

void func_ov000_021812f4(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        data_ov000_021b4c68->mNextState = 3;
        SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x21),
                                     GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
        data_ov000_021b4c68->mMessageTableIndex = 0;
    }
}

void func_ov000_021811ec(void) {
    Unk021b4c68 *p;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 a[2] = {0, 0x22};
        if (data_ov000_021b4c68->mMessageTableIndex < 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextButton(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                         GetBmgEntry(p->mCommonMessages, 6));
            return;
        }
        if (data_ov000_021b4c68->mMessageTableIndex == 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextTwoButtons(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                             GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 0),
                                             GetBmgEntry(p->mCommonMessages, 1), 1);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            data_ov000_021b4c68->mNextState = 4;
            SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x23),
                                         GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
            data_ov000_021b4c68->mMessageTableIndex = 0;
            return;
        }
        data_ov000_021b4c68->mPendingWiFiState = 1;
        RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
    }
}

void func_ov000_021810dc(void) {
    Unk021b4c68 *p;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 a[3] = {0, 0x24, 0x25};
        if (data_ov000_021b4c68->mMessageTableIndex < 1) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextButton(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                         GetBmgEntry(p->mCommonMessages, 6));
            return;
        }
        if (data_ov000_021b4c68->mMessageTableIndex == 1) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextTwoButtons(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                             GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 0),
                                             GetBmgEntry(p->mCommonMessages, 1), 1);
            return;
        }
        if (GetTxtSystemSelectedIndex() == 0) {
            data_ov000_021b4c68->mNextState = 7;
            func_02126638(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            func_0211fe24();
            data_ov000_021b4c68->mUnk_14 = TRUE;
            func_02108bb4();
            return;
        }
        data_ov000_021b4c68->mPendingWiFiState = 1;
        RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
    }
}

void func_ov000_02180ffc(void) {
    Unk021b4c68 *p;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        u16 a[2] = {0, 0x1f};
        if (data_ov000_021b4c68->mMessageTableIndex < 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextButton(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                         GetBmgEntry(p->mCommonMessages, 6));
            return;
        }
        if (data_ov000_021b4c68->mMessageTableIndex == 0) {
            data_ov000_021b4c68->mMessageTableIndex++;
            p = data_ov000_021b4c68;
            SetupTxtSystemMainTextButton(GetBmgEntry(p->mWiFiMessages, a[p->mMessageTableIndex]),
                                         GetBmgEntry(p->mCommonMessages, 4));
            return;
        }
        if (func_ov000_02180e58_inline() == 0) {
            data_ov000_021b4c68->mPendingWiFiState = 2;
            RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
        }
    }
}

void func_ov000_02180f80(void) {
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (GetTxtSystemSelectedIndex() == 0) {
            data_ov000_021b4c68->mNextState = 7;
            func_02126638(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x14), 1, 1, 1, 0, 1, 0);
            func_0211fe24();
            data_ov000_021b4c68->mUnk_14 = FALSE;
            func_02108bb4();
            return;
        }
        data_ov000_021b4c68->mPendingWiFiState = 1;
        RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
    }
}

void func_ov000_02180e58(void) {
    s32 v1;
    s32 v;
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        if (func_ov000_02180e58_inline() == 0) {
            RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
            return;
        }
    }
    if (IsTxtSystemState2NoCloseRequest() != 0) {
        switch (func_0211fd68()) {
            case -1:
                data_ov000_021b4c68->mErrorCode = func_ov000_02181674();
                if (data_ov000_021b4c68->mErrorCode < 0) {
                    data_ov000_021b4c68->mErrorCode = -data_ov000_021b4c68->mErrorCode;
                }
                v = func_ov000_0218151c(data_ov000_021b4c68->mErrorCode, 0, &v1);
                data_ov000_021b4c68->mNextState = 8;
                SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, v),
                                             GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
                data_ov000_021b4c68->mMessageTableIndex = 0;
                func_021089f4();
                break;
            case 0:
                break;
            case 1:
                if (func_ov000_021806a0() != 0) {
                    if (data_ov000_021b4c68->mUnk_14 != FALSE) {
                        data_ov000_021b4c68->mNextState = 5;
                        SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x1e),
                                                     GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
                        data_ov000_021b4c68->mMessageTableIndex = 0;
                    } else {
                        data_ov000_021b4c68->mPendingWiFiState = 2;
                        RequestTxtSystemClose();
                    }
                }
                func_02108b78();
                break;
        }
    }
}

void func_ov000_02180d94(void) {
    vu16 v1;
    s32 v2;
    u16 v3[10];
    u16 v4[300];
    s32 v;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() != 0) {
        data_ov000_021b4c68->mMessageTableIndex++;
        v = func_ov000_0218151c(data_ov000_021b4c68->mErrorCode, data_ov000_021b4c68->mMessageTableIndex, &v2);
        if (v != -1) {
            SetupTxtSystemMainTextButton(GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, v),
                                         GetBmgEntry(data_ov000_021b4c68->mCommonMessages, 6));
            return;
        }
        v1 = 0;
        MIi_CpuClear16(v1, v3, 0x14);
        func_02124fac(data_ov000_021b4c68->mErrorCode, v3);
        func_0212513c(v3, GetBmgEntry(data_ov000_021b4c68->mWiFiMessages, 0x30), v4, 0x258);
        data_ov000_021b4c68->mNextState = 9;
        func_021266e4(v4);
        RequestSelectReturnState1();
    }
}

void func_ov000_02180cdc(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    BOOL b;
    u32 v;
    if (IsTxtSystemState2NoCloseRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
            a = b = FALSE;
            v = data_02175628[i].mHasPair;
            if (v == 0 && data_02175628[i].mNoPairCount < 5) {
                a = 1;
            }
            if (a == 0 && data_02175628[i].mPrevHasPair == 0 && v != 0) {
                b = TRUE;
            }
            if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mPairX,
                                                                              data_02175628[i].mPairY) == FALSE) {
                goto next;
            }
        }
        RequestSelectReturnState3WithSound(0);
        RequestTxtSystemClose();
        return;
    }
next:
    if (IsTxtSystemState0NoOpenRequest() != 0 && IsSelectReturnState2NoState3Or4Request() != 0) {
        data_ov000_021b4c68->mPendingWiFiState = 1;
        RequestWiFiState(data_ov000_021b4c68->mPendingWiFiState);
    }
}

void func_ov000_02180c3c(void) {
    data_ov000_021b4c68->mState = data_ov000_021b4c68->mNextState;
    switch (data_ov000_021b4c68->mState) {
        case 0:
            func_ov000_02181458();
            break;
        case 1:
            func_ov000_0218134c();
            break;
        case 2:
            func_ov000_021812f4();
            break;
        case 3:
            func_ov000_021811ec();
            break;
        case 4:
            func_ov000_021810dc();
            break;
        case 5:
            func_ov000_02180ffc();
            break;
        case 6:
            func_ov000_02180f80();
            break;
        case 7:
            func_ov000_02180e58();
            break;
        case 8:
            func_ov000_02180d94();
            break;
        case 9:
            func_ov000_02180cdc();
            break;
    }
}

u32 func_ov000_02180c28(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = 0x4001000u;
    value2 = *(const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
    return value0;
}

void func_ov000_02180c04(void) {
    WiFiStateCallbacks callbacks = data_ov000_021b0a98;
    SetWiFiStateCallbacks(&callbacks);
}
