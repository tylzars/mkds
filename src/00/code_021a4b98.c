#include "00/code_021a4b98.h"

#include "00/code_021a4b84.h"
#include "00/code_021a4000.h"
#include "00/code_021a5000.h"
#include "00/code_021a6000.h"
#include "00/unk_021b5000.h"
#include "code_02142eac.h"
#include "00/code_021a574c.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/code_021a6c08.h"
#include "00/code_021a6ce4.h"
#include "code_02133048.h"
#include "code_0214259c.h"
#include "code_021453ec.h"
#include "code_0200eddc.h"
#include "00/code_021a54b0.h"
#include "code_0200fc8c.h"
#include "00/code_021a5b3c.h"
#include "code_0214d018.h"
#include "00/code_021a666c.h"
#include "00/code_021a6d1c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200f5ac.h"
#include "code_0200f790.h"
#include "00/unk_021b0000.h"

Unk021b5f50_2270_0c *func_ov000_021a6614(const u8 *a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = NULL;
    if (a == NULL) {
        return NULL;
    }
    if (l != NULL && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != NULL; e = e->mUnk_0c) {
            if (func_ov000_021a6d1c((u8 *) (void *) e->mUnk_10 + 4, a) != 0) {
                break;
            }
        }
    }
    return e;
}

Unk021b5f50_2270_0c *func_ov000_021a65d8(u32 a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    e = NULL;
    if (l != NULL && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != NULL; e = e->mUnk_0c) {
            if (e->mUnk_04 == a) {
                break;
            }
        }
    }
    return e;
}

void func_ov000_021a6558(Unk021b5f50_2270_0c *a) {
    Unk021b5f50 *g;
    Unk021b5f50_2270 *l;
    Unk021b5f50_2270_0c *e;

    g = func_ov000_021a5b30();
    l = g->mUnk_2270;
    if (a != NULL && l != NULL && g->mUnk_2274 > 0xc) {
        for (e = l->mUnk_04; e != NULL; e = e->mUnk_0c) {
            if (e == a) {
                if (e->mUnk_08 != NULL) {
                    e->mUnk_08->mUnk_0c = e->mUnk_0c;
                } else {
                    l->mUnk_04 = e->mUnk_0c;
                }
                if (e->mUnk_0c != NULL) {
                    e->mUnk_0c->mUnk_08 = e->mUnk_08;
                } else {
                    l->mUnk_08 = e->mUnk_08;
                }
                break;
            }
        }
        a->mUnk_0c = NULL;
        a->mUnk_08 = l->mUnk_08;
        l->mUnk_08 = a;
        if (a->mUnk_08 != NULL) {
            a->mUnk_08->mUnk_0c = a;
        } else {
            l->mUnk_04 = a;
        }
        if (e == NULL) {
            a->mUnk_04 = l->mUnk_00;
            l->mUnk_00++;
        }
    }
}

s32 func_ov000_021a6470(Unk021b5f50 *a, u32 b) {
    u32 v1;

    v1 = IrqDisable();
    if (data_ov000_021b5f50 != NULL) {
        IrqRestore(v1);
        return 1;
    }
    if (a == NULL) {
        IrqRestore(v1);
        return 1;
    }
    if (((u32) a & 0x1f) != 0) {
        IrqRestore(v1);
        return 1;
    }
    if (b < sizeof(Unk021b5f50)) {
        IrqRestore(v1);
        return 6;
    }
    data_ov000_021b5f50 = a;
    a->mUnk_2260 = 1;
    data_ov000_021b5f50->mUnk_2280 = 0;
    data_ov000_021b5f50->mUnk_2268 = 0;
    data_ov000_021b5f50->mUnk_226a = 0;
    data_ov000_021b5f50->mUnk_226b = 0;
    data_ov000_021b5f50->mUnk_2282 = 0;
    data_ov000_021b5f50->mUnk_22f8 = 0;
    func_ov000_021a5930();
    func_ov000_021a6bdc();
    if (OS_IsTickAvailable() == 0) {
        OS_InitTick();
    }
    if (OS_IsAlarmAvailable() == 0) {
        OS_InitAlarm();
    }
    OS_CreateAlarm(&data_ov000_021b5f50->mUnk_22cc);
    IrqRestore(v1);
    return 0;
}

BOOL func_ov000_021a6428(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return TRUE;
    }
    if (g->mUnk_2260 != 1) {
        IrqRestore(v1);
        return TRUE;
    }
    data_ov000_021b5f50 = NULL;
    IrqRestore(v1);
    return FALSE;
}

s32 func_ov000_021a629c(Unk021a5a78 *a, void (*b)(Unk021a586c *)) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 1:
            func_ov000_021a5a78(a, b);
            break;
        case 2:
            IrqRestore(v1);
            return 2;
        case 3:
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
    }
    switch (WM_Init(data_ov000_021b5f50, (u16) data_ov000_021b5f50->mUnk_226c)) {
        case 3:
            func_ov000_021a57fc(0xb);
            IrqRestore(v1);
            return 7;
        case 4:
            IrqRestore(v1);
            return 5;
        case 1:
        case 2:
        case 5:
        case 6:
        default:
            func_ov000_021a57fc(0xb);
            IrqRestore(v1);
            return 7;
        case 0:
            break;
    }
    if (WM_GetAllowedChannel() == 0) {
        if (WM_Finish() != 0) {
            func_ov000_021a57fc(0xb);
            IrqRestore(v1);
            return 7;
        }
        IrqRestore(v1);
        return 5;
    }
    if (WM_SetIndCallback(func_ov000_021a56e4) != 0) {
        func_ov000_021a57fc(0xb);
        IrqRestore(v1);
        return 7;
    }
    r = WM_Enable(func_ov000_021a54b0);
    switch (r) {
        case 2:
            func_ov000_021a57fc(2);
            data_ov000_021b5f50->mUnk_2280 = 1;
            break;
        case 8:
            func_ov000_021a57fc(0xc);
            IrqRestore(v1);
            return 1;
        case 3:
        default:
            func_ov000_021a57fc(0xb);
            IrqRestore(v1);
            return 7;
    }
    IrqRestore(v1);
    return 3;
}

s32 func_ov000_021a61e4(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 4:
            IrqRestore(v1);
            return 2;
        case 1:
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
        case 3:
            r = WM_PowerOff(func_ov000_021a54b0);
            switch (r) {
                case 2:
                    func_ov000_021a57fc(4);
                    data_ov000_021b5f50->mUnk_2280 = 2;
                    break;
                case 8:
                    IrqRestore(v1);
                    return 4;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    IrqRestore(v1);
                    return 7;
            }
            IrqRestore(v1);
            return 3;
    }
}

s32 func_ov000_021a61c4(const void *a, const u8 *b, u32 c) {
    if (a == NULL || b == NULL) {
        return func_ov000_021a6024();
    }
    return func_ov000_021a60a4(a, b, c);
}

s32 func_ov000_021a60a4(const void *a, const u8 *b, u32 c) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 5:
            func_ov000_021a5948(a, b, c);
            IrqRestore(v1);
            return 2;
        case 6:
            func_ov000_021a5948(a, b, c);
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
        case 3:
            func_ov000_021a5948(a, b, c);
            DC_InvalidateRange(data_ov000_021b5f50->mUnk_2288.mUnk_00, data_ov000_021b5f50->mUnk_2288.mUnk_04);
            data_ov000_021b5f50->mUnk_2284++;
            r = WM_StartScanEx((Unk021425e8Func) func_ov000_021a52b0, &data_ov000_021b5f50->mUnk_2288);
            switch (r) {
                case 2:
                    func_ov000_021a57fc(5);
                    data_ov000_021b5f50->mUnk_2280 = 3;
                    break;
                case 8:
                    IrqRestore(v1);
                    return 4;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    IrqRestore(v1);
                    return 7;
            }
            IrqRestore(v1);
            return 3;
    }
}

s32 func_ov000_021a6024(void) {
    u32 v1;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 6:
            func_ov000_021a57fc(7);
            data_ov000_021b5f50->mUnk_2280 = 4;
            break;
        case 7:
            IrqRestore(v1);
            return 2;
        case 3:
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
    }
    IrqRestore(v1);
    return 3;
}

s32 func_ov000_021a5e84(Unk021a5e84 *a, Unk02188de4 *b, u32 c) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 3:
            if (a == NULL) {
                IrqRestore(v1);
                return 1;
            }
            if (a->mUnk_3c != 0) {
                IrqRestore(v1);
                return 1;
            }
            if (b != NULL) {
                if (b->mUnk_00 >= 4 || b->mUnk_01 >= 4) {
                    IrqRestore(v1);
                    return 1;
                }
                g->mUnk_2250 = b->mUnk_00;
                data_ov000_021b5f50->mUnk_2251 = b->mUnk_01;
                if (data_ov000_021b5f50->mUnk_2250 == 0) {
                    MemFill(data_ov000_021b5f50->mUnk_2200, 0, 0x50);
                } else {
                    MemCopy(b->mUnk_02, data_ov000_021b5f50->mUnk_2200, 0x50);
                }
            } else {
                MemFill(g->mUnk_2200, 0, 0x52);
            }
            MemCopy(a, data_ov000_021b5f50->mUnk_2140, 0xc0);
            data_ov000_021b5f50->mUnk_2170 = data_ov000_021b5f50->mUnk_216e | 3;
            func_ov000_021a5b3c(c);
            break;
        case 8:
            IrqRestore(v1);
            return 2;
        case 9:
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
    }
    r = WM_SetLifeTime(func_ov000_021a54b0, 0xffff, 0x50, 0xffff, 0xffff);
    switch (r) {
        case 2:
            func_ov000_021a57fc(8);
            data_ov000_021b5f50->mUnk_2280 = 5;
            break;
        case 8:
            IrqRestore(v1);
            return 4;
        case 3:
        default:
            func_ov000_021a57fc(0xb);
            IrqRestore(v1);
            return 7;
    }
    IrqRestore(v1);
    return 3;
}

s32 func_ov000_021a5db0(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 10:
            IrqRestore(v1);
            return 2;
        case 3:
            IrqRestore(v1);
            return 0;
        default:
            IrqRestore(v1);
            return 1;
        case 9:
            break;
    }
    if (g->mUnk_226b == 1) {
        func_ov000_021a57fc(0xa);
        data_ov000_021b5f50->mUnk_2280 = 6;
    } else {
        r = WM_EndDCF(func_ov000_021a4e28);
        switch (r) {
            case 2:
                func_ov000_021a57fc(0xa);
                data_ov000_021b5f50->mUnk_2280 = 6;
                break;
            case 8:
                IrqRestore(v1);
                return 4;
            case 3:
            default:
                func_ov000_021a57fc(0xb);
                IrqRestore(v1);
                return 7;
        }
    }
    IrqRestore(v1);
    return 3;
}

s32 func_ov000_021a5c24(void) {
    u32 v1;
    s32 r;
    Unk021b5f50 *g;
    Unk02142988 *p;

    v1 = IrqDisable();
    g = data_ov000_021b5f50;
    if (g == NULL) {
        IrqRestore(v1);
        return 1;
    }
    switch (g->mUnk_2260) {
        case 13:
            IrqRestore(v1);
            return 2;
        case 1:
            IrqRestore(v1);
            return 0;
        case 6:
            func_ov000_021a57fc(0xd);
            data_ov000_021b5f50->mUnk_2280 = 9;
            IrqRestore(v1);
            return 3;
        case 3:
        case 9:
        case 12:
            break;
        default:
            IrqRestore(v1);
            return 1;
    }
    if (g->mUnk_226b == 1) {
        func_ov000_021a57fc(0xd);
        data_ov000_021b5f50->mUnk_2280 = 9;
    } else {
        p = GetStatusArea();
        DC_InvalidateRange(p, 2);
        switch (p->mState) {
            case 0:
                r = WM_Finish();
                if (r == 0) {
                    func_ov000_021a57fc(1);
                    data_ov000_021b5f50->mUnk_2280 = 0;
                    IrqRestore(v1);
                    return 0;
                }
                break;
            case 1:
                r = WM_Disable(func_ov000_021a54b0);
                break;
            case 2:
                r = WM_PowerOff(func_ov000_021a54b0);
                break;
            default:
                data_ov000_021b5f50->mUnk_226b = 1;
                r = WM_Reset(func_ov000_021a4bc4);
                break;
        }
        switch (r) {
            case 2:
                func_ov000_021a57fc(0xd);
                data_ov000_021b5f50->mUnk_2280 = 9;
                break;
            case 8:
                IrqRestore(v1);
                return 4;
            case 3:
            default:
                func_ov000_021a57fc(0xb);
                IrqRestore(v1);
                return 7;
        }
    }
    IrqRestore(v1);
    return 3;
}

u32 func_ov000_021a5bfc(void) {
    u32 v1;
    u32 r;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    r = 0;
    g = data_ov000_021b5f50;
    if (g != NULL) {
        r = g->mUnk_2260;
    }
    IrqRestore(v1);
    return r;
}

u32 func_ov000_021a5b3c(u32 a) {
    u32 v1;
    u32 b;
    u32 v2;
    Unk021b5f50 *g;

    v1 = IrqDisable();
    b = 0;
    g = data_ov000_021b5f50;
    v2 = g->mUnk_2264;
    if (g == NULL) {
        IrqRestore(v1);
        return 0;
    }
    if (a & 0x8000) {
        b |= 0x3ffe;
        if ((a & 0x3ffe) == 0) {
            a |= 0xa082;
        }
    }
    if (a & 0x20000) {
        b |= 0x10000;
    }
    if (a & 0x80000) {
        b |= 0x40000;
    }
    if (a & 0x200000) {
        b |= 0x100000;
    }
    if (a & 0x800000) {
        b |= 0x400000;
    }
    g->mUnk_2264 = a | (v2 & ~b);
    IrqRestore(v1);
    return v2;
}

Unk021b5f50 *func_ov000_021a5b30(void) {
    return data_ov000_021b5f50;
}

void func_ov000_021a5a78(Unk021a5a78 *a, void (*b)(Unk021a586c *)) {
    u8 *p;

    if (a == NULL) {
        data_ov000_021b5f50->mUnk_226c = 3;
        data_ov000_021b5f50->mUnk_2270 = NULL;
        data_ov000_021b5f50->mUnk_2274 = 0;
        data_ov000_021b5f50->mUnk_2278 = 0;
    } else {
        data_ov000_021b5f50->mUnk_226c = a->mUnk_00 & 3;
        p = a->mUnk_04;
        if ((((4 - ((u32) p & 3)) & 3) + 0xc) > a->mUnk_08) {
            data_ov000_021b5f50->mUnk_2270 = NULL;
            data_ov000_021b5f50->mUnk_2274 = 0;
        } else {
            data_ov000_021b5f50->mUnk_2270 = (Unk021b5f50_2270 *) (((u32) p + 3) & ~3);
            data_ov000_021b5f50->mUnk_2274 = a->mUnk_08 - ((4 - ((u32) a->mUnk_04 & 3)) & 3);
            MemFill(data_ov000_021b5f50->mUnk_2270, 0, data_ov000_021b5f50->mUnk_2274);
        }
        data_ov000_021b5f50->mUnk_2278 = a->mUnk_0c;
    }
    data_ov000_021b5f50->mUnk_227c = b;
}

void func_ov000_021a5948(const void *a, const u8 *b, u32 c) {
    u16 v;
    s32 i;

    func_ov000_021a5b3c(c);
    data_ov000_021b5f50->mUnk_2288.mUnk_00 = data_ov000_021b5f50->mUnk_1500;
    data_ov000_021b5f50->mUnk_2288.mUnk_04 = 0x400;
    data_ov000_021b5f50->mUnk_2288.mUnk_06 = (1 << func_ov000_021a58dc(0)) >> 1;
    v = data_ov000_021b5f50->mUnk_2268;
    if (v == 0) {
        v = WM_GetDispersionScanPeriod();
    }
    data_ov000_021b5f50->mUnk_2288.mUnk_08 = v;
    data_ov000_021b5f50->mUnk_2288.mUnk_10 = (data_ov000_021b5f50->mUnk_2264 & 0x300000) != 0x300000;
    if (a == NULL) {
        MemCopy(data_ov000_021b07bc, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    } else {
        MemCopy(a, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    }
    if (b == NULL || b == data_ov000_021b07c4) {
        MemCopy(data_ov000_021b07c4, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = 0;
    } else {
        MemCopy(b, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        for (i = 0; i < 0x20; i++) {
            if (*b == 0) {
                break;
            }
            b++;
        }
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = i;
    }
    data_ov000_021b5f50->mUnk_2284 = 0;
}

void func_ov000_021a5930(void) {
    data_ov000_021b5f50->mUnk_2264 = 0xaaa082;
}

u16 func_ov000_021a58dc(u16 a) {
    s32 i;
    s32 j;
    u32 f;

    i = 0;
    j = a;
    f = data_ov000_021b5f50->mUnk_2264;
    do {
        if (f & (1 << (j % 13 + 1))) {
            break;
        }
        j++;
        i++;
    } while (i < 13);
    return (a + i) % 13 + 1;
}

void func_ov000_021a58a4(u32 b, const void *c, u32 d, u32 e) {
    s16 a;

    a = data_ov000_021b5f50->mUnk_2280;
    data_ov000_021b5f50->mUnk_2280 = 0;
    func_ov000_021a586c(a, b, c, d, e);
}

void func_ov000_021a586c(s16 a, u32 b, void *c, u32 d, u32 e) {
    Unk021a586c v;

    if (data_ov000_021b5f50->mUnk_227c != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        v.mUnk_04 = c;
        v.mUnk_08 = d;
        v.mUnk_0c = e;
        data_ov000_021b5f50->mUnk_227c(&v);
    }
}

void func_ov000_021a57fc(u32 a) {
    u32 b;

    b = IrqDisable();
    if (data_ov000_021b5f50->mUnk_2260 == 9 && a != 9) {
        OS_CancelAlarm(&data_ov000_021b5f50->mUnk_22cc);
    }
    if (data_ov000_021b5f50->mUnk_2260 != 0xb) {
        data_ov000_021b5f50->mUnk_2260 = a;
    }
    if (a == 9) {
        OS_SetAlarm(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, NULL);
    }
    IrqRestore(b);
}

void func_ov000_021a57a8(void) {
    u32 a;

    a = IrqDisable();
    OS_CancelAlarm(&data_ov000_021b5f50->mUnk_22cc);
    if (data_ov000_021b5f50->mUnk_2260 == 9) {
        OS_SetAlarm(&data_ov000_021b5f50->mUnk_22cc, 0x22f5341, func_ov000_021a5794, NULL);
    }
    IrqRestore(a);
}

void func_ov000_021a5794(void *a) {
    func_ov000_021a6b54();
    func_ov000_021a57a8();
    return;
}

void func_ov000_021a574c(void) {
    if (data_ov000_021b5f50->mUnk_226b == 0) {
        data_ov000_021b5f50->mUnk_226b = 1;
        if (WM_Reset(func_ov000_021a4bc4) != 2) {
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, NULL, 0, 0x611);
        }
    }
}

void func_ov000_021a56e4(Unk021425e8 *v1) {
    if (v1->mResultCode == 8 && v1->mUnk_04 == 0x16 && v1->mUnk_06 == 0x25) {
        switch (data_ov000_021b5f50->mUnk_2260) {
            case 8:
                func_ov000_021a57fc(0xc);
                return;
            case 9:
            case 12:
                func_ov000_021a574c();
                return;
            case 10:
                func_ov000_021a57fc(0xc);
                break;
        }
    }
}

void func_ov000_021a54b0(Unk021425e8 *v1) {
    Unk021b5f50 *g;
    s32 r = 0x14;

    switch (v1->mResultCode) {
        case 0:
            switch (v1->mCommand) {
                case 3:
                    r = WM_PowerOn(func_ov000_021a54b0);
                    break;
                case 4:
                    switch (WM_Finish()) {
                        case 0:
                            func_ov000_021a57fc(1);
                            func_ov000_021a58a4(0, NULL, 0, 0x663);
                            return;
                        case 4:
                        default:
                            func_ov000_021a57fc(0xb);
                            func_ov000_021a58a4(7, NULL, 0, 0x66a);
                            return;
                    }
                case 5:
                    func_ov000_021a57fc(3);
                    func_ov000_021a58a4(0, NULL, 0, 0x670);
                    return;
                case 6:
                    r = WM_Disable(func_ov000_021a54b0);
                    break;
                case 0x1d:
                    r = WM_SetBeaconIndication((Unk021425e8Func) func_ov000_021a54b0, 0);
                    break;
                case 0x19:
                    g = data_ov000_021b5f50;
                    r = WM_SetWEPKeyEx((u32) func_ov000_021a54b0, g->mUnk_2250, g->mUnk_2251, g->mUnk_2200);
                    break;
                case 0x27: {
                    u32 v;
                    u16 e;
                    u32 d;
                    g = data_ov000_021b5f50;
                    v = g->mUnk_2264;
                    e = (v & 0xc0000) == 0xc0000;
                    d = (v & 0x30000) != 0x30000 ? 1 : 0;
                    r = WM_StartConnectEx((Unk021425e8Func) func_ov000_021a5088, (u16 *) g->mUnk_2140, NULL, d, e);
                    break;
                }
            }
            if (r == 2) {
                return;
            }
            switch (r) {
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0,
                                        0x6a7);
                    return;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0,
                                        0x6b0);
                    return;
            }
            break;
        case 1:
            func_ov000_021a57fc(0xc);
            func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0, 0x6d0);
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2280 == 5 ? data_ov000_021b5f50->mUnk_2140 : 0, 0, 0x6da);
            return;
    }
}

// Not compiled code: the 1.2 compiler has no clz instruction.
// clang-format off
#pragma thumb off
asm u32 func_ov000_021a4b98(u32 a) {
    mov r1, r0
    mov r0, #0
    mov r3, #1
count_bits:
    clz r2, r1
    rsbs r2, r2, #31
    bxlo lr
    bic r1, r1, r3, lsl r2
    add r0, r0, #1
    b count_bits
}

asm u32 func_ov000_021a4bbc(u32 a) {
    clz r0, r0
    bx lr
}
#pragma thumb on
// clang-format on

void func_ov000_021a52b0(Unk021a5088 *v1) {
    s32 a;
    s32 b;
    u32 c;
    u32 d;
    u32 e;

    a = 0x14;
    switch (v1->mUnk_02) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 5) {
                func_ov000_021a57fc(6);
                func_ov000_021a58a4(0, 0, 0, 0x6f6);
            }
            switch (data_ov000_021b5f50->mUnk_2260) {
                case 6:
                    data_ov000_021b5f50->mUnk_2280 = 7;
                    if (v1->mUnk_08 == 5) {
                        DC_InvalidateRange(data_ov000_021b5f50->mUnk_2288.mUnk_00,
                                           data_ov000_021b5f50->mUnk_2288.mUnk_04);
                        for (b = 0; b < v1->mUnk_0e; b++) {
                            func_ov000_021a671c((Unk021a5e84 *) v1->mUnk_10[b], v1->mUnk_50[b]);
                            func_ov000_021a586c(7, 0, v1->mUnk_10[b], (u32) v1, 0x70b);
                        }
                    }
                    c = data_ov000_021b5f50->mUnk_2264;
                    if ((c & 0xc00000) == 0xc00000) {
                        d = func_ov000_021a4b98(c & 0x3ffe);
                        if (d != 0) {
                            e = data_ov000_021b5f50->mUnk_2284;
                            if (e % d == 0) {
                                func_ov000_021a586c(8, 0, (void *) e, 0, 0x718);
                            }
                        }
                    }
                    data_ov000_021b5f50->mUnk_2288.mUnk_06 =
                        (1 << func_ov000_021a58dc(32 - func_ov000_021a4bbc(v1->mUnk_0a))) >> 1;
                    DC_InvalidateRange(data_ov000_021b5f50->mUnk_2288.mUnk_00, data_ov000_021b5f50->mUnk_2288.mUnk_04);
                    data_ov000_021b5f50->mUnk_2284++;
                    a = WM_StartScanEx((Unk021425e8Func) func_ov000_021a52b0, &data_ov000_021b5f50->mUnk_2288);
                    break;
                case 7:
                    a = WM_EndScan((Unk021425e8Func) func_ov000_021a524c);
                    break;
                case 13:
                    func_ov000_021a574c();
                    return;
            }
            switch (a) {
                case 2:
                    return;
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, 0, 0, 0x743);
                    return;
                case 3:
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, 0, 0, 0x74c);
                    return;
            }
        case 1:
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, 0, 0, 0x75d);
            return;
    }
}

void func_ov000_021a524c(Unk021425e8 *v1) {
    switch (v1->mResultCode) {
        case 0:
            func_ov000_021a57fc(3);
            func_ov000_021a58a4(0, 0, 0, 0x774);
            return;
        case 1:
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, 0, 0, 0x784);
            return;
    }
}

void func_ov000_021a5088(Unk021a5088 *v1) {
    u16 a;
    s32 b;

    switch (v1->mUnk_02) {
        case 0:
            switch (v1->mUnk_08) {
                case 8:
                case 9:
                    switch (data_ov000_021b5f50->mUnk_2260 - 8) {
                        case 2:
                            data_ov000_021b5f50->mUnk_2282 = 0;
                        case 0:
                            func_ov000_021a57fc(0xc);
                            return;
                        case 1:
                            data_ov000_021b5f50->mUnk_2282 = 0;
                            data_ov000_021b5f50->mUnk_2280 = 6;
                        case 4:
                            func_ov000_021a574c();
                            return;
                        default:
                            break;
                    }
                    break;
                case 7:
                    if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                        func_ov000_021a57fc(8);
                        func_ov000_021a574c();
                        return;
                    }
                    a = v1->mUnk_0a;
                    if (a >= 1 && a <= 0x7d7) {
                        data_ov000_021b5f50->mUnk_2282 = a;
                        b = WM_StartDCF((Unk021425e8Func) func_ov000_021a4f10, &data_ov000_021b5f50->mUnk_0000[0x1500],
                                        0x620);
                        switch (b) {
                            case 2:
                                return;
                            case 8:
                                func_ov000_021a57fc(0xc);
                                func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, 0, 0x7d7);
                                return;
                            case 3:
                            default:
                                func_ov000_021a57fc(0xb);
                                func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x7e0);
                                return;
                        }
                    }
                    func_ov000_021a574c();
                    return;
                case 6:
                    break;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, v1->mUnk_08, 0x7ee);
                    return;
            }
            break;
        case 1:
            data_ov000_021b5f50->mUnk_22f8 = v1->mUnk_0e;
        case 6:
        case 11:
        case 12:
            func_ov000_021a57fc(8);
            func_ov000_021a574c();
            return;
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        case 9:
        case 10:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x804);
            return;
    }
}

void func_ov000_021a4fe0(Unk021425e8 *v1) {
    switch (v1->mResultCode) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                func_ov000_021a57fc(0xa);
                func_ov000_021a574c();
                return;
            }
            data_ov000_021b5f50->mUnk_2282 = 0;
            func_ov000_021a57fc(3);
            func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x827);
            return;
        case 1:
        case 3:
            func_ov000_021a57fc(0xa);
            func_ov000_021a574c();
            return;
        case 2:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x839);
            return;
    }
}

void func_ov000_021a4f10(Unk021425e8 *v1) {
    switch (v1->mResultCode) {
        case 0:
            switch (v1->mUnk_04) {
                case 0xe:
                    if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                        func_ov000_021a57fc(8);
                        func_ov000_021a574c();
                        return;
                    }
                    func_ov000_021a57fc(9);
                    func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x85d);
                    return;
                case 0xf:
                    func_ov000_021a6c08(((u16 *) v1->mUnk_08)[7] >> 8);
                    DC_InvalidateRange(v1->mUnk_08, 0x620);
                    func_ov000_021a6bb4(v1->mUnk_08);
                    return;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, v1->mUnk_04, 0x86b);
                    return;
            }
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x877);
            return;
    }
}

void func_ov000_021a4e28(Unk021425e8 *v1) {
    s32 a;

    switch (v1->mResultCode) {
        case 0:
            if (data_ov000_021b5f50->mUnk_2260 == 0xc) {
                func_ov000_021a57fc(0xa);
                func_ov000_021a574c();
                return;
            }
            a = WM_Disconnect((Unk021425e8Func) func_ov000_021a4fe0, 0);
            switch (a) {
                case 2:
                    return;
                case 8:
                    func_ov000_021a57fc(0xc);
                    func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, 0, 0x8a0);
                    return;
                case 3:
                    func_ov000_021a57fc(0xa);
                    func_ov000_021a574c();
                    return;
                default:
                    func_ov000_021a57fc(0xb);
                    func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x8ac);
                    return;
            }
        case 1:
        case 3:
            func_ov000_021a57fc(0xa);
            func_ov000_021a574c();
            return;
        case 2:
        case 4:
        default:
            func_ov000_021a57fc(0xb);
            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, 0, 0x8bf);
            return;
    }
}

void func_ov000_021a4bc4(Unk021425e8 *v1) {
    u16 a;
    u32 b;
    u32 c;
    s32 e;
    u16 f;

    if (v1->mResultCode == 0) {
        data_ov000_021b5f50->mUnk_226b = 0;
        data_ov000_021b5f50->mUnk_2282 = 0;
        switch (data_ov000_021b5f50->mUnk_2260) {
            case 5:
            case 6:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(1, 0, 0, 0x8e1);
                return;
            case 7:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, 0, 0, 0x8e7);
                return;
            case 8:
                a = data_ov000_021b5f50->mUnk_22f8;
                data_ov000_021b5f50->mUnk_22f8 = 0;
                if (a == 0x12 && (data_ov000_021b5f50->mUnk_2170 & 0x24) != 0x24) {
                    data_ov000_021b5f50->mUnk_2170 |= 0x24;
                    b = 0;
                    if ((data_ov000_021b5f50->mUnk_2264 & 0xc0000) == 0xc0000) {
                        b = 1;
                    }
                    f = b;
                    if ((data_ov000_021b5f50->mUnk_2264 & 0x30000) == 0x30000) {
                        c = 0;
                    } else {
                        c = 1;
                    }
                    e = WM_StartConnectEx((Unk021425e8Func) func_ov000_021a5088, (u16 *) data_ov000_021b5f50->mUnk_2140,
                                          0, c, f);
                    switch (e) {
                        case 2:
                            return;
                        case 8:
                            func_ov000_021a57fc(0xc);
                            func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, a, 0x905);
                            return;
                        case 3:
                        default:
                            func_ov000_021a57fc(0xb);
                            func_ov000_021a58a4(7, data_ov000_021b5f50->mUnk_2140, a, 0x90c);
                            return;
                    }
                }
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(1, data_ov000_021b5f50->mUnk_2140, a, 0x913);
                return;
            case 9:
            case 12:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 1, 0x91b);
                return;
            case 10:
                func_ov000_021a57fc(3);
                func_ov000_021a58a4(0, data_ov000_021b5f50->mUnk_2140, 0, 0x922);
                return;
            case 13:
                e = WM_PowerOff((Unk021425e8Func) func_ov000_021a54b0);
                switch (e) {
                    case 2:
                        return;
                    case 8:
                        func_ov000_021a57fc(0xc);
                        func_ov000_021a58a4(1, 0, 0, 0x930);
                        return;
                    case 3:
                    default:
                        func_ov000_021a57fc(0xb);
                        func_ov000_021a58a4(7, 0, 0, 0x939);
                        return;
                }
            default:
                func_ov000_021a57fc(0xb);
                func_ov000_021a58a4(7, 0, data_ov000_021b5f50->mUnk_2260, 0x93f);
                return;
        }
    }
    func_ov000_021a57fc(0xb);
    func_ov000_021a58a4(7, 0, 0, 0x946);
}
