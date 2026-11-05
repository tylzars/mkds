#include "code_02142eac.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214259c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Unknown/unk_0216f000.h"

s32 WM_StartDCF(Unk021425e8Func a, void *b, u32 c) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(1, 8);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_010, 4);
    if (p->mStatusArea->mUnk_010 == 1) {
        return 3;
    }
    if (c < 0x10) {
        return 6;
    }
    if (b == 0) {
        return 6;
    }
    DC_StoreRange(b, c);
    SetCommandCallback(0x11, (u32) a);
    r = SendCommandMessage(0x11, 2, b, c);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_SetDCFData(Unk021425e8Func a, const void *b, void *c, u32 d) {
    Unk02142aa8 *p;
    s32 r;
    u32 w[2];

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(1, 11);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_010, 4);
    if (p->mStatusArea->mUnk_010 == 0) {
        return 3;
    }
    if (d > 0x5e4) {
        return 6;
    }
    DC_StoreRange(c, d);
    SetCommandCallback(0x12, (u32) a);
    MemCopy(b, w, 6);
    r = SendCommandMessage(0x12, 4, w[0], w[1], c, d);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_EndDCF(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(1, 11);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_010, 4);
    if (p->mStatusArea->mUnk_010 == 0) {
        return 3;
    }
    SetCommandCallback(0x13, (u32) a);
    r = SendCommandMessage(0x13, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_StartMPEx(Unk021425e8Func a, u32 b, s32 c, u32 d, u16 e, u16 f, u16 g, u32 h, u32 i, u32 j, u32 k) {
    Unk02142aa8 *p;
    s32 r;
    s32 w;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(2, 7, 8);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mOwnMemberIndex, 2);
    DC_InvalidateRange(&p->mStatusArea->mUnk_0c2, 2);
    if (p->mStatusArea->mOwnMemberIndex != 0) {
        if (p->mStatusArea->mUnk_0c2 != 1) {
            return 3;
        }
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_00c, 4);
    if (p->mStatusArea->mUnk_00c == 1) {
        return 3;
    }
    if (c < WM_GetMPReceiveBufferSize()) {
        return 6;
    }
    if ((c & 0x3f) != 0) {
        return 6;
    }
    w = e;
    if (w < WM_GetMPSendBufferSize()) {
        return 6;
    }
    if ((w & 0x1f) != 0) {
        return 6;
    }
    SetCommandCallback(0xe, (u32) a);
    r = SendCommandMessage(0xe, 10, b, (u32) c >> 1, d, e, f, g, h, i, j, k);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 func_021441d0(Unk021425e8Func a, u32 b) {
    s32 r;

    GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(1, 9);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0x23, (u32) a);
    r = SendCommandMessage(0x23, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_SetMPDataToPortEx(UnkFunc *a, Unk021450ec *b, void *c, s32 d, u16 e, u16 f, u16 g) {
    u16 v;
    u32 w;
    Unk02142988 *q;
    s32 r;
    s32 flag;

    w = 1;
    q = GetWorkBuffer()->mStatusArea;
    r = GetErrorUnlessStateIsOneOf(2, 9, 10);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&q->mUnk_18e, 2);
    v = q->mUnk_18e;
    DC_InvalidateRange(&q->mOwnMemberIndex, 2);
    flag = q->mOwnMemberIndex == 0 ? w : 0;
    if (flag == 1) {
        DC_InvalidateRange(&q->mConnectedChildren, 2);
        w = q->mConnectedChildren;
        DC_InvalidateRange(&q->mUnk_086, 2);
    }
    if (c == 0) {
        return 6;
    }
    if (w == 0) {
        return 7;
    }
    DC_InvalidateRange(&q->mUnk_050, 2);
    if (c == q->mUnk_050) {
        return 6;
    }
    if (d + (flag != 0 ? 4 : 2) > v) {
        return 6;
    }
    if (d == 0) {
        return 6;
    }
    DC_StoreRange(c, d);
    r = SendCommandMessage(0xf, 7, c, d, e, f, g, a, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_EndMP(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(2, 9, 10);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_00c, 4);
    if (p->mStatusArea->mUnk_00c == 0) {
        return 3;
    }
    SetCommandCallback(0x10, (u32) a);
    r = SendCommandMessage(0x10, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_Enable(Unk021425e8Func a) {
    Unk02142aa8 *p;
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 0);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(3, (u32) a);
    p = GetWorkBuffer();
    r = SendCommandMessage(3, 3, p->mUnk_000, p->mStatusArea, p->mMessageArea);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_Disable(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 1);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(4, (u32) a);
    r = SendCommandMessage(4, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_PowerOn(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 1);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(5, (u32) a);
    r = SendCommandMessage(5, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_PowerOff(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(6, (u32) a);
    r = SendCommandMessage(6, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_Initialize(void *a, Unk021425e8Func b, u32 c) {
    Unk02142aa8 *p;
    s32 r;

    r = WM_Init(a, c);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0, (u32) b);
    p = GetWorkBuffer();
    r = SendCommandMessage(0, 3, p->mUnk_000, p->mStatusArea, p->mMessageArea);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_Reset(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateAtLeast2();
    if (r != 0) {
        return r;
    }
    SetCommandCallback(1, (u32) a);
    r = SendCommandMessage(1, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_End(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(2, (u32) a);
    r = SendCommandMessage(2, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_SetParentParameter(Unk021425e8Func a, Unk02143c30 *b) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_04 != 0) {
        if (b->mUnk_00 == 0) {
            return 6;
        }
    }
    if (b->mUnk_34 + (b->mUnk_14 != 0 ? 0x2a : 0) > 0x200 || b->mUnk_36 + (b->mUnk_14 != 0 ? 6 : 0) > 0x200) {
        return 6;
    }
    IsParentParameterInRange(b);
    SetCommandCallback(7, (u32) a);
    DC_StoreRange(b, 0x40);
    if (b->mUnk_04 != 0) {
        DC_StoreRange(b->mUnk_00, b->mUnk_04);
    }
    r = SendCommandMessage(7, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

u32 IsParentParameterInRange(const Unk02143c30 *a) {
    if (a->mUnk_04 > 0x70) {
        return 0;
    }
    if (a->mUnk_18 < 10 || a->mUnk_18 > 0x3e8) {
        return 0;
    }
    if (a->mUnk_32 < 1 || a->mUnk_32 > 0xe) {
        return 0;
    }
    return 1;
}

s32 StartParentWithArgument(Unk021425e8Func a, u32 b) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(8, (u32) a);
    r = SendCommandMessage(8, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_StartParent(Unk021425e8Func a) {
    return StartParentWithArgument(a, 1);
}

s32 WM_EndParent(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 7);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(9, (u32) a);
    r = SendCommandMessage(9, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_StartScan(Unk021425e8Func a, Unk02143a78 *b) {
    Unk02143a78_0c *pk;
    s32 r;

    r = GetErrorUnlessStateIsOneOf(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_00 == 0) {
        return 6;
    }
    if (b->mUnk_04 < 1 || b->mUnk_04 > 0xe) {
        return 6;
    }
    SetCommandCallback(0xa, (u32) a);
    pk = (Unk02143a78_0c *) GetWorkBuffer()->mRequestArea;
    pk->mUnk_00 = 0xa;
    pk->mUnk_02 = b->mUnk_04;
    pk->mUnk_04 = b->mUnk_00;
    pk->mUnk_08 = b->mUnk_06;
    pk->mUnk_0a[0] = b->mUnk_08[0];
    pk->mUnk_0a[1] = b->mUnk_08[1];
    pk->mUnk_0a[2] = b->mUnk_08[2];
    pk->mUnk_0a[3] = b->mUnk_08[3];
    pk->mUnk_0a[4] = b->mUnk_08[4];
    pk->mUnk_0a[5] = b->mUnk_08[5];
    r = SendCommandMessage(0xa, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_StartScanEx(Unk021425e8Func a, Unk021438f0 *b) {
    Unk021438f0_0c *pk;
    s32 r;
    u16 t;

    r = GetErrorUnlessStateIsOneOf(3, 2, 3, 5);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (b->mUnk_00 == 0) {
        return 6;
    }
    if (b->mUnk_04 > 0x400) {
        return 6;
    }
    if (b->mUnk_12 > 0x20) {
        return 6;
    }
    t = b->mUnk_10;
    if (t != 0 && t != 1 && t != 2 && t != 3) {
        return 6;
    }
    if ((u16) (t + 0xfffe) <= 1) {
        if (b->mUnk_34 > 0x20) {
            return 6;
        }
    }
    SetCommandCallback(0x26, (u32) a);
    pk = (Unk021438f0_0c *) GetWorkBuffer()->mRequestArea;
    pk->mUnk_00 = 0x26;
    pk->mUnk_02 = b->mUnk_06;
    pk->mUnk_04 = b->mUnk_00;
    pk->mUnk_08 = b->mUnk_04;
    pk->mUnk_0a = b->mUnk_08;
    MemCopy(b->mUnk_0a, pk->mUnk_0c, 6);
    pk->mUnk_12 = b->mUnk_10;
    pk->mUnk_36 = b->mUnk_34;
    pk->mUnk_14 = b->mUnk_12;
    MemCopy(b->mUnk_14, pk->mUnk_16, 0x20);
    r = SendCommandMessage(0x26, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_EndScan(Unk021425e8Func a) {
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 5);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0xb, (u32) a);
    r = SendCommandMessage(0xb, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_StartConnectEx(Unk021425e8Func a, u16 *b, void *c, u32 d, u16 e) {
    Unk021437d8 *pk;
    s32 r;

    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    DC_StoreRange(b, b[0] * 2);
    SetCommandCallback(0xc, (u32) a);
    pk = (Unk021437d8 *) GetWorkBuffer()->mRequestArea;
    pk->mUnk_00 = 0xc;
    pk->mUnk_04 = b;
    if (c != 0) {
        MemCopy(c, pk->mUnk_08, 0x18);
    } else {
        MemFill(pk->mUnk_08, 0, 0x18);
    }
    pk->mUnk_20 = d;
    pk->mUnk_26 = e;
    r = SendCommandMessage(0xc, 0);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_Disconnect(Unk021425e8Func a, u32 b) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(5, 7, 9, 8, 10, 11);
    if (r != 0) {
        return r;
    }
    if (p->mStatusArea->mState == 7 || p->mStatusArea->mState == 9) {
        if (b < 1 || b > 0xf) {
            return 6;
        }
        DC_InvalidateRange(&p->mStatusArea->mConnectedChildren, 2);
        if ((p->mStatusArea->mConnectedChildren & (1 << b)) == 0) {
            return 7;
        }
    } else if (b != 0) {
        return 6;
    }
    SetCommandCallback(0xd, (u32) a);
    r = SendCommandMessage(0xd, 1, 1 << b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_DisconnectChildren(Unk021425e8Func a, u32 b) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(2, 7, 9);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&p->mStatusArea->mConnectedChildren, 2);
    if ((p->mStatusArea->mConnectedChildren & b & 0xfffe) == 0) {
        return 7;
    }
    SetCommandCallback(0xd, (u32) a);
    r = SendCommandMessage(0xd, 1, b);
    if (r == 0) {
        return 2;
    }
    return r;
}

s32 WM_SetIndCallback(Unk021425e8Func a) {
    u32 s;
    s32 r;

    s = IrqDisable();
    r = GetErrorUnlessInitialized();
    if (r != 0) {
        IrqRestore(s);
        return r;
    }
    GetWorkBuffer()->mIndicationCallback = a;
    IrqRestore(s);
    return 0;
}

s32 WM_SetPortCallback(u32 n, UnkFunc *f, Unk021450ec *arg) {
    u32 s;
    s32 r;
    Unk02142aa8 *p;

    s = IrqDisable();
    r = GetErrorUnlessInitialized();
    if (r != 0) {
        IrqRestore(s);
        return r;
    }
    p = GetWorkBuffer();
    p->mPortCallbacks[n] = f;
    p->mPortCallbackArgs[n] = arg;
    IrqRestore(s);
    return 0;
}

s32 WM_ReadStatus(void *a) {
    Unk02142aa8 *p;
    s32 r;

    p = GetWorkBuffer();
    r = GetErrorUnlessInitialized();
    if (r != 0) {
        return r;
    }
    if (a == 0) {
        return 6;
    }
    DC_InvalidateRange(p->mStatusArea, 0x7bc);
    MemCopyWordsByBlock(p->mStatusArea, a, 0x7bc);
    return 0;
}

s32 WM_GetMPSendBufferSize(void) {
    Unk02142aa8 *p;

    p = GetWorkBuffer();
    if (GetErrorUnlessStateIsOneOf(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_00c, 4);
    if (p->mStatusArea->mUnk_00c == 1) {
        return 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_18e, 4);
    return (p->mStatusArea->mUnk_18e + 0x1f) & ~0x1f;
}

s32 WM_GetMPReceiveBufferSize(void) {
    Unk02142aa8 *p;
    s32 f;
    u16 v;

    p = GetWorkBuffer();
    if (GetErrorUnlessStateIsOneOf(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_00c, 4);
    if (p->mStatusArea->mUnk_00c == 1) {
        return 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mOwnMemberIndex, 2);
    if (p->mStatusArea->mOwnMemberIndex == 0) {
        f = 1;
    } else {
        f = 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_190, 2);
    v = p->mStatusArea->mUnk_190;
    if (f != 1) {
        return ((v + 0x51) & ~0x1f) << 1;
    }
    DC_InvalidateRange(&p->mStatusArea->mUnk_0f4, 2);
    return (((v + 0xc) * p->mStatusArea->mUnk_0f4 + 0x29) & ~0x1f) << 1;
}

void *WM_ReadMPData(const Unk021432ac *a, u32 b) {
    Unk02142aa8 *p;
    u32 ptrs[16];
    s32 i;

    p = GetWorkBuffer();
    if (GetErrorUnlessInitialized() != 0) {
        return 0;
    }
    if (b < 1 || b > 0xf) {
        return 0;
    }
    DC_InvalidateRange(&p->mStatusArea->mConnectedChildren, 2);
    if ((p->mStatusArea->mConnectedChildren & (1 << b)) == 0) {
        return 0;
    }
    if (a->mUnk_04 == 0) {
        return 0;
    }
    ptrs[0] = (u32) a->mUnk_0a;
    i = 0;
    do {
        if (b == *(u16 *) (ptrs[i] + 4)) {
            return (void *) ptrs[i];
        }
        i++;
        ptrs[i] = a->mUnk_06 + ptrs[i - 1];
    } while (i < a->mUnk_04);
    return 0;
}

u16 WM_GetAllowedChannel(void) {
    if (GetErrorUnlessInitialized() != 0) {
        return 0x8000;
    }
    return *(u16 *) 0x27ffcfa;
}

u16 WM_GetLinkLevel(void) {
    Unk02142aa8 *p;

    p = GetWorkBuffer();
    if (GetErrorUnlessInitialized() != 0) {
        return 0;
    }
    DC_InvalidateRange(p->mStatusArea, 2);
    switch (p->mStatusArea->mState) {
        case 9:
            DC_InvalidateRange(&p->mStatusArea->mConnectedChildren, 2);
            if (p->mStatusArea->mConnectedChildren == 0) {
                return 0;
            }
        case 10:
        case 11:
            DC_InvalidateRange(&p->mStatusArea->mUnk_0b8, 2);
            return p->mStatusArea->mUnk_0b8;
        default:
            return 0;
    }
}

u16 WM_GetDispersionBeaconPeriod(void) {
    u8 buf[6];
    s32 i;
    u16 sum;

    OS_GetMacAddress(buf);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + buf[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 7;
    return sum % 20 + 200;
}

u16 WM_GetDispersionScanPeriod(void) {
    u8 buf[6];
    s32 i;
    u16 sum;

    OS_GetMacAddress(buf);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + buf[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 13;
    return sum % 10 + 30;
}

Unk02142f24 WM_GetOtherElements(const u16 *a) {
    Unk02142f24 s;
    const u8 *p;
    s32 i;
    u8 len;
    u8 sum;
    u8 n;

    if (a[0x1e] != 0) {
        s.mUnk_00 = 0;
        return s;
    }
    s.mUnk_00 = a[0x1f];
    if (s.mUnk_00 == 0) {
        return s;
    }
    if (s.mUnk_00 > 0x10) {
        s.mUnk_00 = 0x10;
    }
    p = (const u8 *) a + 0x40;
    len = a[0] * 2 - 0x40;
    sum = 0;
    for (i = 0; i < s.mUnk_00; i++) {
        s.mUnk_04[i].mUnk_00 = p[0];
        s.mUnk_04[i].mUnk_01 = p[1];
        s.mUnk_04[i].mUnk_04 = p + 2;
        n = s.mUnk_04[i].mUnk_01 + 2;
        sum = sum + n;
        if (sum > len) {
            s.mUnk_00 = 0;
            return s;
        }
        p = p + n;
    }
    return s;
}

u16 WM_GetNextTgid(void) {
    u32 buf[3];

    if (data_0216f06c == 0x10000) {
        RTC_Init();
        if (RTC_GetTime(buf) == 0) {
            data_0216f06c = (u16) (buf[2] + (buf[1] << 8));
        }
    }
    data_0216f06c = (u16) (data_0216f06c + 1);
    return data_0216f06c;
}
