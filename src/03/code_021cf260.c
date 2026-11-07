#include "03/code_021cf260.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009adc.h"

#include "03/unk_021da000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02007624.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200a000.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_02009cc8.h"
#include "Main/Unknown/code_02007ec4.h"
#include "code_02003be0.h"
#include "03/code_021cfa68.h"
#include "Main/Unknown/code_02008570.h"

void func_ov003_021cfa30(u8 *a) {
    data_ov003_021da288 = (Unk021cf260 *) a;
    func_ov003_021d0810((Unk021da2a8 *) (a + 0x1b160));
    data_ov003_021da288->mUnk_1b140 = NULL;
    data_ov003_021da288->mUnk_1b144 = NULL;
}

void func_ov003_021cf978(u32 a, u32 b) {
    Unk0200fddc s;
    Unk02009ff4 x;
    Unk021cf5ac z;

    OS_GetOwnerInfo(&s);
    x.mUnk_00 = (x.mUnk_00 & ~0xf) | (s.mUnk_01 & 0xf);
    x.mUnk_01 = s.mUnk_18;
    MI_CpuCopy8(s.mUnk_04, x.mUnk_02, s.mUnk_18 * 2);
    x.mUnk_00 &= ~0xf0;
    {
        u16 *p = (u16 *) &z;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
    }
    *(Unk021cf5ac *) data_ov003_021da288 = z;
    data_ov003_021da288->mUnk_1b140 = data_ov003_021da288->mUnk_10040;
    if (InitWirelessWork(data_ov003_021da288->mUnk_1b140, &x, a, b, 2) != 0) {
        OS_Terminate();
    }
    SetMPLimits(0x100, 1);
    func_02007ea0(func_ov003_021cf378);
    func_ov003_021cf36c(1);
}

void func_ov003_021cf93c(Unk021cf8ac *a, u16 b) {
    func_ov003_021cf36c(2);
    if (func_02009cc8(b) != 0) {
        func_ov003_021cf36c(7);
        return;
    }
    if (func_ov003_021cf8ac(a) == 0) {
        OS_Terminate();
    }
}

u32 func_ov003_021cf8ac(Unk021cf8ac *a) {
    FSFile *q;
    FSFile s;
    u32 r;

    r = 0;
    if (a->mUnk_00 == NULL) {
        q = NULL;
    } else {
        FS_InitFile(&s);
        if (FS_OpenFile(&s, a->mUnk_00) == 0) {
            return r;
        }
        q = &s;
    }
    if (func_02008880(q) != 0) {
        data_ov003_021da288->mUnk_1b144 = (u8 *) data_ov003_021da288 + 0x2c;
        if (data_ov003_021da288->mUnk_1b144 != NULL) {
            if (func_02008570(q, data_ov003_021da288->mUnk_1b144, 0x10000) != 0) {
                if (func_02008310(a, data_ov003_021da288->mUnk_1b144) != 0) {
                    r = 1;
                }
            }
        }
    }
    if (q == &s) {
        FS_CloseFile(&s);
    }
    return r;
}

void func_ov003_021cf844(u32 a) {
    u16 m;
    u32 t;

    if (func_02007d50(a, 1) == 0) {
        m = ~(1 << a);
        t = OS_DisableInterrupts();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        OS_RestoreInterrupts(t);
        DisconnectChild(a);
    }
}

void func_ov003_021cf7b8(u32 a) {
    u16 m;
    u32 t;
    s32 v1;

    if (func_02007d50(a, 0) == 0) {
        m = ~(1 << a);
        t = OS_DisableInterrupts();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        OS_RestoreInterrupts(t);
        DisconnectChild(a);
    } else {
        t = OS_DisableInterrupts();
        v1 = 1 << a;
        data_ov003_021da288->mUnk_04 &= ~v1;
        data_ov003_021da288->mMask &= ~v1;
        OS_RestoreInterrupts(t);
    }
}

void func_ov003_021cf72c(u32 a) {
    u16 m;
    u32 t;
    s32 v1;

    if (func_02007d50(a, 2) == 0) {
        m = ~(1 << a);
        t = OS_DisableInterrupts();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        OS_RestoreInterrupts(t);
        DisconnectChild(a);
    } else {
        t = OS_DisableInterrupts();
        v1 = 1 << a;
        data_ov003_021da288->mUnk_06 &= ~v1;
        data_ov003_021da288->mUnk_08 |= v1;
        OS_RestoreInterrupts(t);
    }
}

void func_ov003_021cf69c(void) {
    u16 i;
    s32 v1;
    u16 m;
    u32 t;

    func_ov003_021cf36c(3);
    for (i = 1; i < 16; i++) {
        v1 = 1 << i;
        if ((data_ov003_021da288->mMask & v1) != 0) {
            if ((data_ov003_021da288->mUnk_04 & v1) == 0) {
                if ((data_ov003_021da288->mUnk_06 & v1) == 0) {
                    m = ~v1;
                    t = OS_DisableInterrupts();
                    data_ov003_021da288->mMask &= m;
                    data_ov003_021da288->mUnk_04 &= m;
                    data_ov003_021da288->mUnk_06 &= m;
                    data_ov003_021da288->mUnk_08 &= m;
                    data_ov003_021da288->mUnk_0a &= m;
                    data_ov003_021da288->mUnk_0c &= m;
                    OS_RestoreInterrupts(t);
                    DisconnectChild(i);
                } else {
                    func_ov003_021cf72c(i);
                }
            }
        }
    }
}

u32 func_ov003_021cf64c(void) {
    u16 i;

    if (data_ov003_021da288->mMask == 0) {
        return 0;
    }
    for (i = 1; i < 16; i++) {
        if ((data_ov003_021da288->mMask & (1 << i)) != 0) {
            if (func_02007df8(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void func_ov003_021cf5ac(void) {
    u16 r;
    u16 i;
    s32 v1;
    u16 m;
    u32 t;

    r = 0;
    i = 1;
    for (; i < 16; i++) {
        v1 = 1 << i;
        if ((data_ov003_021da288->mUnk_0a & v1) != 0) {
            if (func_02007d50(i, 3) == 0) {
                m = ~v1;
                t = OS_DisableInterrupts();
                data_ov003_021da288->mMask &= m;
                data_ov003_021da288->mUnk_04 &= m;
                data_ov003_021da288->mUnk_06 &= m;
                data_ov003_021da288->mUnk_08 &= m;
                data_ov003_021da288->mUnk_0a &= m;
                data_ov003_021da288->mUnk_0c &= m;
                OS_RestoreInterrupts(t);
                DisconnectChild(i);
            } else {
                r |= v1;
            }
        }
    }
    if (r == 0) {
        func_ov003_021cf36c(7);
    } else {
        func_ov003_021cf36c(4);
    }
}

void func_ov003_021cf598(void) {
    func_ov003_021cf36c(6);
    func_02009c04();
}

void func_ov003_021cf378(u32 a, u32 b, Unk021425e8 *c) {
    Unk021cf260 *s;
    u32 t;
    u16 m;
    u8 *p;

    switch (b) {
        case 2:
            if (func_ov003_021cf360() == 2) {
                s = data_ov003_021da288;
                t = OS_DisableInterrupts();
                s->mMask |= 1 << a;
                OS_RestoreInterrupts(t);
                p = data_ov003_021da288->mRecords[a - 1].mUnk_16;
                p[0] = c->mUnk_0a[0];
                p[1] = c->mUnk_0a[1];
                p[2] = c->mUnk_0a[2];
                p[3] = c->mUnk_0a[3];
                p[4] = c->mUnk_0a[4];
                p[5] = c->mUnk_0a[5];
                data_ov003_021da288->mRecords[a - 1].mUnk_1c = a;
            }
            break;
        case 3:
            if (func_ov003_021cf284(a) != 6) {
                m = ~(1 << a);
                t = OS_DisableInterrupts();
                data_ov003_021da288->mMask &= m;
                data_ov003_021da288->mUnk_04 &= m;
                data_ov003_021da288->mUnk_06 &= m;
                data_ov003_021da288->mUnk_08 &= m;
                data_ov003_021da288->mUnk_0a &= m;
                data_ov003_021da288->mUnk_0c &= m;
                OS_RestoreInterrupts(t);
            }
            break;
        case 10:
            if (func_ov003_021cf360() != 2) {
                func_ov003_021cf7b8(a);
                break;
            }
            data_ov003_021da288->mUnk_04 |= 1 << a;
            func_ov003_021cf844(a);
            t = (u32) func_02007e38(a);
            if (t != 0) {
                MI_CpuCopy8((void *) t, &data_ov003_021da288->mRecords[a - 1], 0x16);
            }
            break;
        case 14:
            data_ov003_021da288->mUnk_04 &= ~(1 << a);
            data_ov003_021da288->mUnk_06 |= 1 << a;
            if (func_ov003_021cf360() == 3) {
                func_ov003_021cf72c(a);
            }
            break;
        case 7:
            data_ov003_021da288->mUnk_08 &= ~(1 << a);
            data_ov003_021da288->mUnk_0a |= 1 << a;
            break;
        case 9:
            data_ov003_021da288->mUnk_0a &= ~(1 << a);
            data_ov003_021da288->mUnk_0c |= 1 << a;
            if (data_ov003_021da288->mMask == data_ov003_021da288->mUnk_0c) {
                func_02009c04();
            }
            break;
        case 12:
            if (func_ov003_021cf360() == 4) {
                func_ov003_021cf36c(5);
            } else {
                func_ov003_021cf36c(0);
            }
            if (data_ov003_021da288->mUnk_1b144 != NULL) {
                data_ov003_021da288->mUnk_1b144 = NULL;
            }
            if (data_ov003_021da288->mUnk_1b140 != NULL) {
                data_ov003_021da288->mUnk_1b140 = NULL;
            }
            break;
        case 13:
            switch (c->mCommand) {
                case 1:
                case 2:
                case 9:
                    func_ov003_021cf36c(7);
                    break;
                case 8:
                    break;
            }
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 8:
        case 11:
            break;
        default:
            OS_Terminate();
            break;
    }
}

void func_ov003_021cf36c(u16 a) {
    *(u16 *) (*(u32 *) &data_ov003_021da288) = a;
}

u16 func_ov003_021cf360(void) {
    return *(u16 *) (u32) data_ov003_021da288;
}

u16 func_ov003_021cf32c(u32 a) {
    Unk021cf260 *s;

    s = data_ov003_021da288;
    data_ov003_021da28c[0] = &s->mMask;
    data_ov003_021da28c[1] = &s->mUnk_04;
    data_ov003_021da28c[2] = &s->mUnk_06;
    data_ov003_021da28c[3] = &s->mUnk_08;
    data_ov003_021da28c[4] = &s->mUnk_0a;
    data_ov003_021da28c[5] = &s->mUnk_0c;
    return *data_ov003_021da28c[a];
}

u32 func_ov003_021cf284(u32 a) {
    u32 t;
    u16 b;
    u16 s[7];

    t = OS_DisableInterrupts();
    b = 1 << a;
    if ((data_ov003_021da288->mMask & b) == 0) {
        OS_RestoreInterrupts(t);
        return 0;
    }
    MI_CpuCopy8(data_ov003_021da288, s, 0xe);
    OS_RestoreInterrupts(t);
    if ((s[2] & b) != 0) {
        return 2;
    }
    if ((s[3] & b) != 0) {
        return 3;
    }
    if ((s[4] & b) != 0) {
        return 4;
    }
    if ((s[5] & b) != 0) {
        return 5;
    }
    if ((s[6] & b) != 0) {
        return 6;
    }
    return 1;
}

void *func_ov003_021cf260(u32 index) {
    Unk021cf260 *state = data_ov003_021da288;
    if ((state->mMask & (1 << index)) != 0) {
        return &state->mRecords[index - 1];
    }
    return NULL;
}
