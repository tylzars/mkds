#include "03/code_021cfa68.h"

#include "03/code_021d0000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_021453ec.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_021445e0.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"

void func_ov003_021d0810(Unk021da2a8 *a) {
    data_ov003_021da2a8 = a;
    a->mUnk_40 = 0;
    data_ov003_021da2a8->mUnk_13a8 = 0;
    data_ov003_021da2a8->mUnk_13ac = NULL;
    data_ov003_021da2a8->mUnk_13b0 = 0;
}

void func_ov003_021d07b0(u32 v1) {
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7bc8, data_ov003_021d79a8[data_ov003_021da2a8->mUnk_40]);
    }
    data_ov003_021da2a8->mUnk_40 = v1;
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7bd0, data_ov003_021d79a8[data_ov003_021da2a8->mUnk_40]);
    }
}

void func_ov003_021d079c(s32 value) {
    if ((u32) (data_ov003_021da2a8->mUnk_40 - 9) > 1) {
        data_ov003_021da2a8->mUnk_54 = value;
    }
}

BOOL func_ov003_021d0760(void) {
    s32 r;

    func_ov003_021d07b0(3);
    r = WM_SetParentParameter(func_ov003_021d0708, (Unk02143c30 *) data_ov003_021da2a8);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d0708(Unk021425e8 *v1) {
    if (v1->mResultCode != 0) {
        func_ov003_021d079c(v1->mResultCode);
        func_ov003_021d07b0(9);
        return;
    }
    if (data_ov003_021da2a8->mUnk_13ac != NULL) {
        if (func_ov003_021d06b0() == FALSE) {
            func_ov003_021d07b0(9);
        }
    } else if (func_ov003_021d0630() == FALSE) {
        func_ov003_021d07b0(9);
    }
}

BOOL func_ov003_021d06b0(void) {
    u32 a;
    s32 r;

    func_ov003_021d07b0(3);
    a = data_ov003_021da2a8->mUnk_13ac(data_ov003_021da2a8->mUnk_13c0, data_ov003_021da2a8);
    r = WM_SetWEPKey(func_ov003_021d0680, a, data_ov003_021da2a8->mUnk_13c0);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d0680(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        func_ov003_021d079c(event->mResultCode);
        func_ov003_021d07b0(9);
    } else {
        if (func_ov003_021d0630() == FALSE) {
            func_ov003_021d07b0(9);
        }
    }
}

BOOL func_ov003_021d0630(void) {
    s32 r;

    if ((u32) (data_ov003_021da2a8->mUnk_40 - 4) <= 2) {
        return TRUE;
    }
    r = WM_StartParent(func_ov003_021d0530);
    if (r != 2) {
        func_ov003_021d079c(r);
        return FALSE;
    }
    data_ov003_021da2a8->mUnk_50 = 0;
    data_ov003_021da2a8->mUnk_52 = 1;
    return TRUE;
}

void func_ov003_021d0530(Unk021425e8 *v1) {
    u16 v2;
    s32 r;

    v2 = 1 << v1->mUnk_10;
    if (v1->mResultCode != 0) {
        func_ov003_021d079c(v1->mResultCode);
        func_ov003_021d07b0(9);
        return;
    }
    switch (v1->mUnk_08_0) {
        case 7:
            if (data_ov003_021da2a4 != NULL) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7b70, v1->mUnk_10);
            }
            if (data_ov003_021da2a8->mUnk_4c != NULL && data_ov003_021da2a8->mUnk_4c(v1) == 0) {
                r = WM_Disconnect(NULL, v1->mUnk_10);
                if (r == 2) {
                    return;
                }
                func_ov003_021d079c(r);
                func_ov003_021d07b0(9);
                return;
            }
            data_ov003_021da2a8->mUnk_52 = data_ov003_021da2a8->mUnk_52 | v2;
            return;
        case 9:
            if (data_ov003_021da2a4 != NULL) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7b9c, v1->mUnk_10);
            }
            data_ov003_021da2a8->mUnk_52 = data_ov003_021da2a8->mUnk_52 & ~v2;
            return;
        case 0:
            if (func_ov003_021d04a8() == FALSE) {
                func_ov003_021d07b0(9);
            }
            return;
        case 2:
            return;
        default:
            if (data_ov003_021da2a4 != NULL) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7af8, v1->mUnk_08_0);
            }
            return;
    }
}

BOOL func_ov003_021d04a8(void) {
    s32 r;

    if ((u32) (data_ov003_021da2a8->mUnk_40 - 4) <= 2) {
        return TRUE;
    }
    func_ov003_021d07b0(4);
    r = WM_StartMPEx(func_ov003_021d03c0, (u32) data_ov003_021da2a8->mUnk_1060, data_ov003_021da2a8->mUnk_12a4,
                     (u32) data_ov003_021da2a8->mUnk_f80, data_ov003_021da2a8->mUnk_12a0, 1, 0, 0, 0, 0, 0);
    if (r != 2) {
        func_ov003_021d079c(r);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d03c0(Unk021425e8 *v1) {
    s32 r;

    if (v1->mResultCode != 0) {
        func_ov003_021d079c(v1->mResultCode);
        func_ov003_021d07b0(9);
        return;
    }
    switch (v1->mUnk_04) {
        case 0xa:
            if (data_ov003_021da2a8->mUnk_44 == 2) {
                if (data_ov003_021da2a8->mUnk_40 == 4) {
                    if (func_ov003_021d0388() != FALSE) {
                        return;
                    }
                    if (data_ov003_021da2a4 != NULL) {
                        data_ov003_021da2a4(0x08000000, data_ov003_021d7b40);
                    }
                    func_ov003_021d07b0(9);
                    return;
                }
                if (data_ov003_021da2a8->mUnk_40 == 6) {
                    return;
                }
            } else if (data_ov003_021da2a8->mUnk_44 == 4) {
                r = WM_StartDataSharing(&data_ov003_021da2a8->mUnk_13e0, 0xd, 7, 0x44, 1);
                if (r != 0) {
                    func_ov003_021d079c(r);
                    func_ov003_021d07b0(9);
                    return;
                }
                func_ov003_021d07b0(5);
                return;
            }
            func_ov003_021d07b0(4);
            return;
        case 0xb:
            break;
        case 0xc:
        case 0xd:
        default:
            if (data_ov003_021da2a4 != NULL) {
                data_ov003_021da2a4(0x08000000, data_ov003_021d7af8, v1->mUnk_04);
            }
            break;
    }
}

BOOL func_ov003_021d0388(void) {
    s32 r;

    func_ov003_021d07b0(6);
    r = WM_StartKeySharing(&data_ov003_021da2a8->mUnk_1e00, 0xd);
    if (r != 2) {
        func_ov003_021d079c(r);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov003_021d0358(void) {
    s32 result = WM_EndKeySharing(&data_ov003_021da2a8->mUnk_1e00);
    if (result != 2) {
        func_ov003_021d079c(result);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov003_021d032c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = WM_EndMP(func_ov003_021d02e8);
    if (result != 2) {
        func_ov003_021d079c(result);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d02e8(Unk021425e8 *v1) {
    if (v1->mResultCode != 0) {
        func_ov003_021d079c(v1->mResultCode);
        func_ov003_021cfb80();
    } else if (func_ov003_021d02c0() == FALSE) {
        if (data_ov003_021da2a4 != NULL) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7b18);
        }
        func_ov003_021cfb80();
    }
}

BOOL func_ov003_021d02c0(void) {
    s32 result = WM_EndParent(func_ov003_021d02a0);
    if (result != 2) {
        func_ov003_021d079c(result);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d02a0(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        func_ov003_021d079c(event->mResultCode);
    } else {
        func_ov003_021d07b0(1);
    }
}

BOOL func_ov003_021d0258(void) {
    s32 r;

    if (data_ov003_021da2a8->mUnk_40 != 6) {
        return FALSE;
    }
    func_ov003_021d07b0(3);
    r = WM_EndKeySharing(&data_ov003_021da2a8->mUnk_1e00);
    if (r != 2) {
        func_ov003_021d079c(r);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov003_021d022c(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = WM_EndMP(func_ov003_021d0200);
    if (result != 2) {
        func_ov003_021d079c(result);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d0200(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        func_ov003_021d079c(event->mResultCode);
        func_ov003_021cfaa8();
    } else {
        if (func_ov003_021d01cc() == FALSE) {
            func_ov003_021d07b0(9);
        }
    }
}

BOOL func_ov003_021d01cc(void) {
    s32 r;

    func_ov003_021d07b0(3);
    r = WM_Disconnect(func_ov003_021d01ac, 0);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021cfb80();
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d01ac(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        func_ov003_021d079c(event->mResultCode);
    } else {
        func_ov003_021d07b0(1);
    }
}

BOOL func_ov003_021d0180(void) {
    s32 result;
    func_ov003_021d07b0(3);
    result = WM_Reset(func_ov003_021d0158);
    if (result != 2) {
        func_ov003_021d079c(result);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021d0158(Unk021425e8 *event) {
    if (event->mResultCode != 0) {
        func_ov003_021d07b0(9);
        func_ov003_021d079c(event->mResultCode);
    } else {
        func_ov003_021d07b0(1);
    }
}

void func_ov003_021d0134(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        func_ov003_021d07b0(10);
        return;
    }
    func_ov003_021d07b0(0);
}

void func_ov003_021d0128(u32 a) {
    data_ov003_021da2a8->mUnk_08 = a;
}

u16 func_ov003_021d0118(void) {
    return data_ov003_021da2a8->mUnk_52;
}

u32 func_ov003_021d010c(void) {
    return data_ov003_021da2a8->mUnk_40;
}

BOOL func_ov003_021d0078(void) {
    u16 a[3];
    u32 r;
    u32 t;

    OS_GetMacAddress(a);
    t = *(u32 *) 0x27ffc3c;
    t = a[0] + t + a[1] + a[2];
    data_ov003_021da2a8->mUnk_58 = t;
    data_ov003_021da2a8->mUnk_58 = data_ov003_021da2a8->mUnk_58 * 0x10dcd + 0x3039;
    data_ov003_021da2a8->mUnk_5c = 0;
    data_ov003_021da2a8->mUnk_5e = 0x65;
    func_ov003_021d07b0(3);
    r = func_ov003_021cfff8(1);
    if (r == 0x18) {
        func_ov003_021d079c(0x18);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(9);
        return FALSE;
    }
    return TRUE;
}

u32 func_ov003_021cfff8(u16 param_1) {
    u16 r = WM_GetAllowedChannel();
    if (r == 0x8000) {
        func_ov003_021d079c(3);
        func_ov003_021d07b0(9);
        return 3;
    }
    if (r == 0) {
        func_ov003_021d079c(0x16);
        func_ov003_021d07b0(9);
        return 0x18;
    }
    while (((1 << (param_1 - 1)) & r) == 0) {
        param_1++;
        if (param_1 > 0x10) {
            return 0x18;
        }
    }
    return (u16) func_ov003_021cff38(func_ov003_021cff50, param_1);
}

void func_ov003_021cff50(Unk021425e8 *param_1) {
    u16 a;
    u16 b;
    u32 r;

    if (param_1->mResultCode != 0) {
        func_ov003_021d079c(param_1->mResultCode);
        func_ov003_021d07b0(9);
        return;
    }
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7ae0, param_1->mUnk_08_0, param_1->mUnk_08_2);
    }
    a = param_1->mUnk_08_0;
    b = param_1->mUnk_08_2;
    if (data_ov003_021da2a8->mUnk_5e > b) {
        data_ov003_021da2a8->mUnk_5e = b;
        data_ov003_021da2a8->mUnk_60 = 1 << (a - 1);
    } else if (data_ov003_021da2a8->mUnk_5e == b) {
        data_ov003_021da2a8->mUnk_60 = data_ov003_021da2a8->mUnk_60 | (1 << (a - 1));
    }
    r = func_ov003_021cfff8(a + 1);
    if (r == 0x18) {
        func_ov003_021d07b0(7);
        return;
    }
    if (r != 2) {
        func_ov003_021d07b0(9);
    }
}

int func_ov003_021cff38(Unk021425e8Func a, u16 b) {
    return WM_MeasureChannel(a, 3, 0x11, b, 0x1e);
}

u16 func_ov003_021cfed8(void) {
    Unk021da2a8 **v1;
    u16 v2;
    if (data_ov003_021da2a8->mUnk_40 != 7) {
        OS_Terminate();
    }
    func_ov003_021d07b0(1);
    v2 = func_ov003_021cfe40((u32) (data_ov003_021da2a8->mUnk_60));
    v1 = &data_ov003_021da2a8;
    data_ov003_021da2a8->mUnk_5c = v2;
    if ((UnkFunc *) (*(u32 *) &data_ov003_021da2a4) != NULL) {
        (*(UnkFunc *) (*(u32 *) &data_ov003_021da2a4))((0x08000000u), (u32) &data_ov003_021d7ac8, (*v1)->mUnk_5c);
    }
    return data_ov003_021da2a8->mUnk_5c;
}

int func_ov003_021cfe40(u16 c) {
    s16 a;
    s16 i;
    u16 b;
    u16 n;
    s16 j;

    a = 0;
    b = 0;
    for (i = 0; i < 16; i++) {
        if ((c & (1 << i)) != 0) {
            a = i + 1;
            b++;
        }
    }
    if (b > 1) {
        data_ov003_021da2a8->mUnk_58 = data_ov003_021da2a8->mUnk_58 * 0x10dcd + 0x3039;
        n = (b * (data_ov003_021da2a8->mUnk_58 & 0xff)) >> 8;
        for (j = 0; j < 16; j++) {
            if ((c & 1) != 0) {
                if (n == 0) {
                    return (s16) (j + 1);
                }
                n--;
            }
            c = c >> 1;
        }
        return 0;
    }
    return a;
}

BOOL func_ov003_021cfde4(void) {
    data_ov003_021da2a8->mUnk_12a4 = 0;
    data_ov003_021da2a8->mUnk_12a0 = 0;
    data_ov003_021da2a8->mUnk_48 = 0;
    data_ov003_021da2a8->mUnk_50 = 0;
    data_ov003_021da2a8->mUnk_52 = 1;
    data_ov003_021da2a8->mUnk_54 = 0;
    data_ov003_021da2a8->mUnk_00 = NULL;
    data_ov003_021da2a8->mUnk_04 = 0;
    data_ov003_021da2a8->mUnk_4c = NULL;
    if (func_ov003_021cfd88() != FALSE) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021cfdc8(Unk021425e8 *event) {
    if (event->mResultCode == 8) {
        func_ov003_021d07b0(9);
        OS_Terminate();
    }
}

BOOL func_ov003_021cfd88(void) {
    s32 r;
    func_ov003_021d07b0(3);
    r = WM_Initialize(data_ov003_021da2a8->mUnk_80, func_ov003_021cfd44, 2);
    if (r != 2) {
        func_ov003_021d079c(r);
        func_ov003_021d07b0(10);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021cfd44(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        func_ov003_021d079c(a->mResultCode);
        func_ov003_021d07b0(10);
    } else {
        s32 r = WM_SetIndCallback(func_ov003_021cfdc8);
        if (r != 0) {
            func_ov003_021d079c(r);
            func_ov003_021d07b0(10);
        } else {
            func_ov003_021d07b0(1);
        }
    }
}

BOOL func_ov003_021cfc4c(u32 a, u16 b, u16 c) {
    if (data_ov003_021da2a8->mUnk_40 != 1) {
        OS_Terminate();
    }
    data_ov003_021da2a8->mUnk_12a4 = 0x180;
    data_ov003_021da2a8->mUnk_12a0 = 0xe0;
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a7c, data_ov003_021da2a8->mUnk_12a4);
    }
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7a94, data_ov003_021da2a8->mUnk_12a0);
    }
    data_ov003_021da2a8->mUnk_44 = a;
    func_ov003_021d07b0(3);
    data_ov003_021da2a8->mUnk_0c = b;
    data_ov003_021da2a8->mUnk_32 = c;
    data_ov003_021da2a8->mUnk_18 = WM_GetDispersionBeaconPeriod();
    data_ov003_021da2a8->mUnk_34 = 0xd0;
    data_ov003_021da2a8->mUnk_36 = 0x44;
    data_ov003_021da2a8->mUnk_10 = 2;
    data_ov003_021da2a8->mUnk_16 = 0;
    data_ov003_021da2a8->mUnk_12 = 0;
    data_ov003_021da2a8->mUnk_0e = 1;
    data_ov003_021da2a8->mUnk_14 = a == 2 ? 1 : 0;
    if (a == 0 || a == 2 || a == 4) {
        return func_ov003_021d0760();
    }
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d7aac, a);
    }
    return FALSE;
}

void func_ov003_021cfc40(u32 a) {
    data_ov003_021da2a8->mUnk_4c = (s32(*)(Unk021425e8 *)) a;
    return;
}

u8 *func_ov003_021cfc1c(u32 a) {
    return WM_GetSharedDataAddress(&data_ov003_021da2a8->mUnk_13e0, &data_ov003_021da2a8->mUnk_1c00, a);
}

BOOL func_ov003_021cfb98(void *a) {
    s32 r = WM_StepDataSharing(&data_ov003_021da2a8->mUnk_13e0, a, &data_ov003_021da2a8->mUnk_1c00);
    if (r == 7) {
        if (data_ov003_021da2a4 != NULL) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a18);
        }
        return FALSE;
    }
    if (r == 5) {
        if (data_ov003_021da2a4 != NULL) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a48);
        }
        func_ov003_021d079c(r);
        return FALSE;
    }
    if (r != 0) {
        func_ov003_021d079c(r);
        return FALSE;
    }
    return TRUE;
}

void func_ov003_021cfb80(void) {
    int v1;
    v1 = func_ov003_021d0180();
    if (v1 == 0) {
        func_ov003_021d07b0(10);
    }
    return;
}

void func_ov003_021cfaa8(void) {
    s32 a = data_ov003_021da2a8->mUnk_40;
    if (a == 1) {
        if (data_ov003_021da2a4 != NULL) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d79d0);
        }
        return;
    }
    if (data_ov003_021da2a4 != NULL) {
        data_ov003_021da2a4(0x08000000, data_ov003_021d79f4, a);
    }
    if (data_ov003_021da2a8->mUnk_40 != 6 && data_ov003_021da2a8->mUnk_40 != 5 && data_ov003_021da2a8->mUnk_40 != 4) {
        func_ov003_021d07b0(3);
        func_ov003_021cfb80();
        return;
    }
    func_ov003_021d07b0(3);
    switch (data_ov003_021da2a8->mUnk_44) {
        case 3:
            if (func_ov003_021d0258() == FALSE) {
                func_ov003_021cfb80();
            }
            break;
        case 1:
        case 5:
            if (func_ov003_021d022c() == FALSE) {
                func_ov003_021cfb80();
            }
            break;
        case 2:
            if (func_ov003_021d0358() == FALSE) {
                func_ov003_021cfb80();
            }
            break;
        case 0:
        case 4:
            if (func_ov003_021d032c() == FALSE) {
                func_ov003_021cfb80();
            }
            break;
    }
}

u32 func_ov003_021cfa68(void) {
    int v1;
    if (data_ov003_021da2a8->mUnk_40 != 1) {
        OS_Terminate();
    }
    func_ov003_021d07b0(3);
    v1 = WM_End(func_ov003_021d0134);
    if (v1 != 2) {
        func_ov003_021d07b0(9);
        return 0;
    }
    return 1;
}
