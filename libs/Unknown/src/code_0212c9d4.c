#include "code_0212c9d4.h"

#include "code_0200eddc.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212bb50.h"
#include "code_0212f788.h"
#include "code_0212f864.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02188720.h"

s32 func_0212d154(u8 *a, u32 b, u32 c, u32 d, u32 e, UnkFunc *f, void *g) {
    volatile u32 v;

    func_0212d10c();
    if (data_0217ddd0.mUnk_00 != 0) {
        return 0;
    }
    v = 0;
    MIi_CpuClear32(v, a, b);
    DC_FlushRange(a, b);
    return func_0212ccd4(1, a, a + (b >> 1), b >> 1, c, 0, 0, 1, d, 0x7f, 0, 0x7f, e, f, g);
}

void func_0212d10c(void) {
    if (data_0217ddd0.mUnk_00 == 0) {
        return;
    }
    if (data_0217ddd0.mUnk_04 != 1) {
        return;
    }
    func_0212cbd8();
}

u32 func_0212d0ec(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = (u32) &data_0217dda8;
    value2 = 0u;
    value0 = (u32) &data_0217ddd0;
    *(u32 *) ((value1) + (0)) = value2;
    data_0217ddd0.mUnk_00 = value2;
    return value0;
}

void func_0212d03c(void) {
    Unk0212ccd4 *p = &data_0217ddd0;
    Interpolator *q;
    s32 v;

    if (p->mUnk_00 == 0) {
        return;
    }
    if (p->mUnk_04 != 0) {
        return;
    }
    q = &p->mUnk_3c;
    InterpolatorStep(q);
    if (p->mUnk_4c != 0 && InterpolatorIsDone(q) != 0) {
        func_0212cbd8();
        return;
    }
    v = InterpolatorGetValue(q) >> 8;
    if (v == p->mUnk_50) {
        return;
    }
    SND_SetChannelVolume(p->mUnk_24, v, 0);
    p->mUnk_50 = v;
}

s32 func_0212ccd4(u32 a, u8 *b, u8 *c, u32 d, u32 e, u32 f, u32 g, u32 h, s32 i, u32 j, u32 k, u32 l, u32 m, UnkFunc *n,
                  void *o) {
    s32 u;
    u32 x24;
    u32 x28;
    u32 x2c;
    u32 w;
    s32 s;
    s32 q;
    s32 r;
    u32 t;
    u32 z;
    Unk0212ccd4 *p;

    s = 0;
    x2c = 0;
    r = -1;
    p = &data_0217ddd0;
    DC_FlushRange(b, d);
    DC_FlushRange(c, d);
    q = e == 1;
    u = 0xffb0ff / i;
    if (n != 0) {
        z = d;
        if (q == 0) {
            z = d >> 1;
        }
        u = (u + 0x10) & ~0x1f;
        s = u >> 5;
        w = s * (z / m);
        t = 0x20;
        if (q == 0) {
            t = t >> 1;
        }
        t = t * s;
    }
    switch (q) {
        default:
            x28 = 0;
            break;
        case 0:
            x28 = 1;
            break;
    }
    if (q != 0) {
        x24 = 1;
    } else {
        x24 = 0;
    }
    if (a != 2) {
        x2c = 10;
    }
    if (n != 0) {
        r = func_0212bb9c();
        if (r < 0) {
            return 0;
        }
    }
    if (func_0212bbfc(3) == 0) {
        if (r >= 0) {
            func_0212bb7c(r);
        }
        return 0;
    }
    if (func_0212bc58(10) == 0) {
        if (r >= 0) {
            func_0212bb7c(r);
        }
        func_0212bbe0(3);
        return 0;
    }
    SND_SetupChannelPcm(1, x28, (u32) b, h != 0 ? 1 : 2, 0, d >> 2, j, 0, u, k);
    SND_SetupCapture(0, x24, (u32) b, d >> 2, h, f, g);
    SND_SetupChannelPcm(3, x28, (u32) c, h != 0 ? 1 : 2, 0, d >> 2, j, 0, u, l);
    SND_SetupCapture(1, x24, (u32) c, d >> 2, h, f, g);
    if (r >= 0) {
        SND_SetupAlarm(r, w + t, w, func_0212c9d4, p);
    }
    if (a == 1) {
        SND_SetOutputSelector(1, 2, 1, 1);
    }
    SND_StartTimer(x2c, 3, r >= 0 ? 1 << r : 0, 0);
    p->mUnk_00 = 1;
    p->mUnk_04 = a;
    p->mUnk_20 = 10;
    p->mUnk_24 = x2c;
    p->mUnk_28 = 3;
    p->mUnk_2c = r;
    p->mUnk_08 = e;
    p->mUnk_0c = b;
    p->mUnk_10 = c;
    p->mUnk_14 = d;
    p->mUnk_18 = d / m;
    p->mUnk_1c = 0;
    p->mUnk_30 = m;
    p->mUnk_34 = n;
    p->mUnk_38 = o;
    p->mUnk_50 = j;
    InterpolatorInit(&p->mUnk_3c);
    InterpolatorStart(&p->mUnk_3c, j << 8, 1);
    p->mUnk_4c = 0;
    return 1;
}

void func_0212cbd8(void) {
    Unk0212ccd4 *p = &data_0217ddd0;
    s32 f;
    u32 r;

    if (p->mUnk_00 == 0) {
        return;
    }
    f = p->mUnk_2c >= 0;
    SND_StopTimer(p->mUnk_24, p->mUnk_28, f != 0 ? 1 << p->mUnk_2c : 0, 0);
    if (f != 0) {
        r = SND_GetCurrentCommandTag();
        PxiCommandSendPending(1);
        PxiCommandWaitForSequence(r);
        while (OS_ReceiveMessage(&data_0217ddb0, 0, 0) != 0) {
        }
    }
    if (p->mUnk_28 != 0) {
        func_0212bbe0(p->mUnk_28);
    }
    if (p->mUnk_20 != 0) {
        func_0212bc20(p->mUnk_20);
    }
    if (f != 0) {
        func_0212bb7c(p->mUnk_2c);
    }
    if (p->mUnk_04 == 1) {
        SND_SetOutputSelector(0, 0, 0, 0);
    }
    p->mUnk_00 = 0;
}

void func_0212cb78(void) {
    Unk0212ccd4 *p = &data_0217ddd0;
    u32 r;

    if (p->mUnk_00 == 0) {
        return;
    }
    SND_StopTimer(p->mUnk_24, p->mUnk_28, p->mUnk_2c >= 0 ? 1 << p->mUnk_2c : 0, 0);
    r = SND_GetCurrentCommandTag();
    PxiCommandSendPending(1);
    PxiCommandWaitForSequence(r);
}

void func_0212cad8(void) {
    Unk0212ccd4 *p = &data_0217ddd0;
    volatile u32 v;
    volatile u32 w;

    if (p->mUnk_00 == 0) {
        return;
    }
    p->mUnk_1c = 0;
    v = 0;
    MIi_CpuClear32(v, p->mUnk_0c, p->mUnk_14);
    w = 0;
    MIi_CpuClear32(w, p->mUnk_10, p->mUnk_14);
    DC_FlushRange(p->mUnk_0c, p->mUnk_14);
    DC_FlushRange(p->mUnk_10, p->mUnk_14);
    SND_StartTimer(p->mUnk_24, p->mUnk_28, p->mUnk_2c >= 0 ? 1 << p->mUnk_2c : 0, 0);
}

void func_0212c9d4(Unk0212ccd4 *p) {
    u8 *a;
    u8 *b;
    u32 n;
    u32 off;
    Unk0212c9d4 *e;

    n = p->mUnk_18;
    off = n * p->mUnk_1c;
    a = p->mUnk_0c + off;
    b = p->mUnk_10 + off;
    if (data_0217dda8 != 0) {
        e = &data_0217de24[data_0217ddac];
        e->mUnk_00 = p;
        e->mUnk_04 = n;
        e->mUnk_08 = off;
        e->mUnk_0c = a;
        e->mUnk_10 = b;
        OS_SendMessage(&data_0217ddb0, e, 0);
        data_0217ddac++;
        if (data_0217ddac >= 8) {
            data_0217ddac = 0;
        }
    } else {
        DC_InvalidateRange(a, n);
        DC_InvalidateRange(b, n);
        p->mUnk_34(a, b, n, p->mUnk_08, p->mUnk_38);
    }
    p->mUnk_1c++;
    if (p->mUnk_1c >= p->mUnk_30) {
        p->mUnk_1c = 0;
    }
}
