#include "code_021453ec.h"
#include "code_0200eddc.h"
#include "code_021445e0.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214259c.h"
#include "code_0214cfe4.h"

u8 data_0217f960[0x80];

int WM_SetWEPKey(u32 a, u32 b, void *c) {
    int r;

    r = GetErrorUnlessStateAtLeast2();
    if (r != 0) {
        return r;
    }
    if (b > 3) {
        return 6;
    }
    if (b != 0) {
        if (c == 0) {
            return 6;
        }
        DC_StoreRange(c, 0x50);
    }
    SetCommandCallback(0x14, a);
    r = SendCommandMessage(0x14, 2, b, c);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_SetWEPKeyEx(u32 a, u32 b, u32 c, void *d) {
    int r;

    r = GetErrorUnlessStateAtLeast2();
    if (r != 0) {
        return r;
    }
    if (b > 3) {
        return 6;
    }
    if (b != 0) {
        if (d == 0) {
            return 6;
        }
        DC_StoreRange(d, 0x50);
    }
    SetCommandCallback(0x27, a);
    r = SendCommandMessage(0x27, 3, b, d, c);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_SetGameInfo(Unk021425e8Func a, const void *b, u32 c, u32 d, u16 e, u8 f) {
    int r;

    r = GetErrorUnlessStateIsOneOf(2, 7, 9);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (c > 0x70) {
        return 6;
    }
    MIi_CpuCopy16(b, data_0217f960, c);
    DC_StoreRange(data_0217f960, c);
    SetCommandCallback(0x18, (u32) a);
    r = SendCommandMessage(0x18, 5, data_0217f960, c, d, e, f);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_SetBeaconIndication(Unk021425e8Func a, u32 b) {
    int r;

    r = GetErrorUnlessStateAtLeast2();
    if (r != 0) {
        return r;
    }
    if (b != 0 && b != 1) {
        return 6;
    }
    SetCommandCallback(0x19, (u32) a);
    r = SendCommandMessage(0x19, 1, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_SetLifeTime(Unk021425e8Func a, u32 b, u32 c, u32 d, u16 e) {
    int r;

    r = GetErrorUnlessStateAtLeast2();
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0x1d, (u32) a);
    r = SendCommandMessage(0x1d, 4, b, c, d, e);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_MeasureChannel(Unk021425e8Func a, u16 b, u16 c, u16 d, u16 e) {
    Unk02142aa8 *p;
    u16 *q;
    int r;

    p = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(1, 2);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0x1e, (u32) a);
    q = p->mRequestArea;
    q[0] = 0x1e;
    q[1] = b;
    q[2] = c;
    q[3] = d;
    q[4] = e;
    r = SendCommandMessage(0x1e, 0);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int WM_SetEntry(Unk021425e8Func a, u32 b) {
    int r;

    r = GetErrorUnlessStateIsOneOf(2, 7, 9);
    if (r != 0) {
        return r;
    }
    SetCommandCallback(0x21, (u32) a);
    r = SendCommandMessage(0x21, 1, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}
