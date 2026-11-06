#include "00/code_021ad734.h"

#include "code_0214d018.h"
#include "00/code_021a9228.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "00/code_021ad018.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad36c.h"
#include "00/unk_021b6380.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "string.h"
#include "code_02134398.h"
#include "code_02133048.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/code_021a8878.h"
#include "03/code_021b94b8.h"
#include "02/unk_02180500.h"
#include "Main/Unknown/code_02000b44.h"

void func_ov000_021b04f8(u32 a) {
    u32 b;
    OSThread *c;
    Unk021b04f8 *d;
    s32 i;
    Unk021b69dc *e;

    if (data_ov000_021b63b4 != 0) {
        b = 1;
    } else {
        b = 0;
    }
    data_ov000_021b637c = a;
    data_ov000_021b63b4 = 0;
    data_ov000_021b6380 = 0;
    data_ov000_021b639c = 0;
    data_ov000_021b63d8[0] = 0;
    data_ov000_021b63d8[1] = 0;
    data_ov000_021b638c = 0;
    if (b != 0) {
        MI_CpuFill8(data_ov000_021b6434, 0, 0x60);
        c = data_0216ff5c.mListHead;
        if (c != NULL) {
            do {
                d = *(Unk021b04f8 **) c->mUnk_a4;
                if (d != NULL && d->mThread != NULL) {
                    if (d->mState != 10 && d->mState != 11) {
                        d->mState = 0;
                    }
                    if (d->mUnk_04 != 0) {
                        d->mUnk_04 = 0;
                        OS_WakeupThreadDirect(d->mThread);
                    }
                }
                c = c->mNext;
            } while (c != NULL);
        }
        i = 0;
        e = data_ov000_021b69dc;
        for (; i < 8; i++) {
            if (e->mUnk_04 != 0) {
                data_ov000_021b63ac(e->mUnk_34);
                e->mUnk_04 = 0;
            }
            e++;
        }
        func_ov000_021a91b4();
    }
}

void func_ov000_021b04d4(void) {
    if (data_ov000_021b6390 == 0) {
        OS_YieldThread();
    } else {
        OS_Sleep(data_ov000_021b6390);
    }
}

void func_ov000_021b04d0(void) {}

s32 func_ov000_021b04cc(void) {
    return 1;
}

void func_ov000_021b02fc(Unk021b5fa8 *a) {
    func_02000b44(0x2000bfc);
    if (*(u64 *) &a->mUnk_14 != 0) {
        data_ov000_021b63e0[0] = *(u64 *) &a->mUnk_14;
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    } else {
        data_ov000_021b63e0[0] = OS_GetTick();
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    }
    if (a->mUnk_04 != NULL && a->mUnk_08 != NULL) {
        data_ov000_021b63a4 = (u8 * (*) (u32)) a->mUnk_04;
        data_ov000_021b63ac = a->mUnk_08;
    } else {
        data_ov000_021b63a4 = (u8 * (*) (u32)) func_ov000_021b04d0;
        data_ov000_021b63ac = (void (*)(void *)) func_ov000_021b04d0;
    }
    data_ov000_021b6398 = a->mUnk_00;
    if (a->mUnk_24 != 0) {
        data_ov000_021b6370 = a->mUnk_24;
    } else {
        data_ov000_021b6370 = 0x5b4;
    }
    data_ov000_021b63bc = a->mUnk_28;
    data_ov000_021b6390 = a->mUnk_2c;
    if (a->mUnk_0c != NULL) {
        data_ov000_021b6384 = a->mUnk_0c;
    } else {
        data_ov000_021b6384 = func_ov000_021b04d0;
    }
    if (a->mUnk_10 != NULL) {
        data_ov000_021b6388 = a->mUnk_10;
    } else {
        data_ov000_021b6388 = (u32(*)(void)) func_ov000_021b04cc;
    }
    data_ov000_021b63c4 = a->mUnk_1c;
    data_ov000_021b63c8 = a->mUnk_20;
    data_ov000_021b63cc = 0;
    data_ov000_021b6394 = 0;
    data_ov000_021b63e0[0] = _ll_mul(data_ov000_021b63e0[1], data_ov000_021b63e0[0]) + data_ov000_021b63e0[2];
    data_ov000_021b6374 = (_ll_mul(data_ov000_021b63e0[0] >> 32, 0xf88) >> 32) + 0x400;
    OS_GetMacAddress(data_ov000_021b63d0);
    data_ov000_021b6368 = 0;
    OS_CreateThread(&data_ov000_021b661c, (void (*)(void *)) func_ov000_021ae3a4, NULL, data_ov002_021b7ba0, 0x800,
                    data_ov000_021b4c28);
    OS_CreateThread(&data_ov000_021b655c, (void (*)(void *)) func_ov000_021ad898, NULL, data_ov000_021b73a0, 0x800,
                    data_ov000_021b4c28);
    OS_WakeupThreadDirect(&data_ov000_021b661c);
    OS_WakeupThreadDirect(&data_ov000_021b655c);
}

s32 func_ov000_021b02bc(void) {
    u32 a;
    s32 b;

    a = OS_DisableInterrupts();
    b = OS_IsThreadTerminated(&data_ov000_021b655c);
    if (b == 0 && data_ov000_021b63b0 == 0) {
        data_ov000_021b63b0 = 1;
        OS_WakeupThreadDirect(&data_ov000_021b655c);
    }
    OS_RestoreInterrupts(a);
    return b;
}

void func_ov000_021b02b0(UnkFunc *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_ov000_021b63a8;
    *(u32 *) ((value1) + 0u) = value0;
}

void func_ov000_021b026c(void) {
    func_ov000_021b02bc();
    OS_JoinThread(&data_ov000_021b655c);
    OS_DestroyThread(&data_ov000_021b661c);
    data_ov000_021b63c0 = NULL;
    func_ov000_021b04f8(0);
    data_ov000_021b63c4 = NULL;
    data_ov000_021b63c8 = 0;
}

void func_ov000_021b0240(s32 a) {
    data_ov000_021b4c28 = a;
    OS_SetThreadPriority(&data_ov000_021b661c, a);
    OS_SetThreadPriority(&data_ov000_021b655c, a);
}

u32 func_ov000_021b01b4(const void *buffer, u32 length, u32 sum) {
    const u8 *bytes = buffer;

    if ((u32) bytes & 1) {
        while (length > 1) {
            sum += (u16) ((bytes[0] << 8) | bytes[1]);
            bytes += 2;
            length -= 2;
        }
    } else {
        u16 word = sum;

        sum = (u16) ((word >> 8) | (word << 8));
        while (length > 1) {
            sum += *(const u16 *) bytes;
            bytes += 2;
            length -= 2;
        }
        sum = ((sum >> 8) & 0x00ff00ff) | ((sum << 8) & 0xff00ff00);
        sum = (sum >> 16) | (sum << 16);
    }
    if (length != 0) {
        sum += *bytes << 8;
    }
    sum = (sum & 0xffff) + (sum >> 16);
    sum += sum >> 16;
    return (u16) sum;
}

u16 func_ov000_021b01a0(u16 sum) {
    sum ^= 0xffff;
    if (sum == 0) {
        sum = 0xffff;
    }
    return sum;
}

u16 func_ov000_021b0188(const void *buffer, u32 length) {
    return func_ov000_021b01a0(func_ov000_021b01b4(buffer, length, 0));
}

BOOL func_ov000_021b0138(const void *buffer, u32 length, const Unk021b0138 *header, u32 sum) {
    sum = func_ov000_021b01b4(buffer, length, sum);
    sum = func_ov000_021b01b4(header->mUnk_0c, 8, sum);
    sum += length;
    if (sum & 0x10000) {
        sum = (sum + 1) & 0xffff;
    }
    if (sum != 0xffff) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021b00fc(u32 address) {
    return address == 0xffffffff || address == 0x7f000001 ||
           (address & data_ov000_021b6380) == (data_ov000_021b63b4 & data_ov000_021b6380);
}

u32 func_ov000_021b00e0(u32 address) {
    if (func_ov000_021b00fc(address) == FALSE) {
        address = data_ov000_021b639c;
    }
    return address;
}

s32 func_ov000_021b00b0(u32 address) {
    BOOL result = FALSE;

    if (func_ov000_021b00fc(address) != FALSE && (address & ~data_ov000_021b6380) == ~data_ov000_021b6380) {
        result = TRUE;
    }
    return result;
}

BOOL func_ov000_021b0094(u32 address) {
    if ((address & 0xf0000000) == 0xe0000000) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_ov000_021b003c(u32 address) {
    return data_ov000_021b63b4 == 0 || address == data_ov000_021b63b4 || address == 0x7f000001 ||
           func_ov000_021b00b0(address) != 0 || func_ov000_021b0094(address) != FALSE;
}

BOOL func_ov000_021b0014(const u16 *first, const u16 *second) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (*first++ != *second++) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_ov000_021affcc(u8 *a, u32 b, const void *c, u32 d) {
    u8 e;

    if (a + b != c) {
        MI_CpuCopy8(c, a + b, d);
    }
    MI_CpuCopy8(data_ov000_021b4c40, a + 6, 6);
    if (func_ov000_021a6974(a, a + 6, b + d - 6) < 0) {
        e = 1;
    } else {
        e = 0;
    }
    data_ov000_021b6364 = e;
}

void func_ov000_021afe84(const void *a, const void *b, u8 *c, u32 d, void *e, u32 f) {
    u8 *g;
    u32 h;
    u32 i;
    u16 j;
    u32 k;
    u32 l;
    u32 m;

    g = data_ov000_021b63c4;
    if (g == NULL) {
        return;
    }
    h = data_ov000_021b63c8;
    if (h == 0) {
        return;
    }
    i = d + f;
    if (i < 8 || i > 0x5e4) {
        return;
    }
    if (c[0] != data_ov000_021b4c40[0] || c[1] != data_ov000_021b4c40[1] || c[2] != data_ov000_021b4c40[2]) {
        return;
    }
    if (c[6] != 8) {
        return;
    }
    if (c[7] != 0 && c[7] != 6) {
        return;
    }
    j = (i + 9) & ~1;
    k = data_ov000_021b6394;
    l = k + j;
    m = l;
    i = data_ov000_021b63cc;
    if (k < i && i <= l) {
        return;
    }
    if (l == h) {
        m = 0;
        if (i == 0) {
            return;
        }
    } else if (l > h) {
        m = j;
        if (i <= j) {
            return;
        }
    }
    if (l > h) {
        if (h - k >= 2) {
            g[k] = 0;
            (data_ov000_021b63c4 + data_ov000_021b6394)[1] = 0;
        }
        data_ov000_021b6394 = 0;
    }
    data_ov000_021b63c4[data_ov000_021b6394] = j;
    (data_ov000_021b63c4 + data_ov000_021b6394)[1] = j >> 8;
    MI_CpuCopy8(b, data_ov000_021b63c4 + data_ov000_021b6394 + 2, 6);
    MI_CpuCopy8(a, data_ov000_021b63c4 + data_ov000_021b6394 + 8, 6);
    MI_CpuCopy8(c + 6, data_ov000_021b63c4 + data_ov000_021b6394 + 0xe, d - 6);
    if (e != NULL && f != 0) {
        MI_CpuCopy8(e, data_ov000_021b63c4 + data_ov000_021b6394 + 8 + d, f);
    }
    data_ov000_021b6394 = m;
}

void func_ov000_021afe5c(void *a, void *b, void *c, u16 d) {
    func_ov000_021afe84(a, b, c, d, NULL, 0);
    if (data_ov000_021b63c0 != NULL) {
        OS_WakeupThreadDirect(data_ov000_021b63c0);
    }
}

u8 *func_ov000_021afdcc(u32 *a) {
    u16 b;
    u32 c;
    u8 *d;

    while (data_ov000_021b63cc == data_ov000_021b6394) {
        data_ov000_021b63c0 = data_0216ff5c.mCurrentThread;
        OS_SleepThread(NULL);
        data_ov000_021b63c0 = NULL;
    }
    c = data_ov000_021b63c8;
    d = data_ov000_021b63c4;
    do {
        if (c - data_ov000_021b63cc < 2) {
            data_ov000_021b63cc = 0;
        }
        b = d[data_ov000_021b63cc] + ((d + data_ov000_021b63cc)[1] << 8);
        if (b == 0) {
            data_ov000_021b63cc = 0;
        }
    } while (b == 0);
    *a = b - 2;
    return data_ov000_021b63c4 + data_ov000_021b63cc + 2;
}

void func_ov000_021afd8c(void) {
    u32 a;
    u32 b;
    u8 *c;

    a = OS_DisableInterrupts();
    b = data_ov000_021b63cc;
    c = data_ov000_021b63c4;
    data_ov000_021b63cc = b + (c[b] + ((c + b)[1] << 8));
    if (data_ov000_021b63cc >= data_ov000_021b63c8) {
        data_ov000_021b63cc = 0;
    }
    OS_RestoreInterrupts(a);
}

u8 *func_ov000_021afd00(u32 a) {
    u32 b;
    u8 *c;
    u32 d;
    u16 e;

    b = OS_DisableInterrupts();
    c = NULL;
    if (a == 0x7f000001 || a == data_ov000_021b63b4) {
        c = (u8 *) data_ov000_021b63d0;
    } else if (func_ov000_021b00b0(a) != 0 || func_ov000_021b0094(a) != FALSE) {
        c = data_ov000_021b4c2c;
    } else {
        for (d = 0; d < 8; d++) {
            if (a == data_ov000_021b6434[d].mUnk_00) {
                e = OS_GetTick() >> 16;
                data_ov000_021b6434[d].mUnk_0a = e;
                c = data_ov000_021b6434[d].mUnk_04;
                break;
            }
        }
    }
    OS_RestoreInterrupts(b);
    return c;
}

void func_ov000_021afc5c(u32 a) {
    Unk021afc5c b;

    MI_CpuFill8(&b, 0, 0x2a);
    MI_CpuFill8(&b, 0xff, 6);
    MI_CpuCopy8(data_ov000_021b63d0, b.mUnk_06, 6);
    b.mUnk_0c = 0x608;
    b.mUnk_0f = 1;
    b.mUnk_10 = 8;
    b.mUnk_12 = 0x406;
    b.mUnk_15 = 1;
    MI_CpuCopy8(data_ov000_021b63d0, b.mUnk_16, 6);
    b.mUnk_1c = ((u16) (*(u32 *) &data_ov000_021b63b4 >> 16) >> 8) | ((u16) (*(u32 *) &data_ov000_021b63b4 >> 16) << 8);
    b.mUnk_1e = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    b.mUnk_26 = ((u16) (a >> 16) >> 8) | ((u16) (a >> 16) << 8);
    b.mUnk_28 = ((u16) a >> 8) | ((u16) a << 8);
    func_ov000_021affcc((u8 *) &b, 0x2a, NULL, 0);
}

u8 *func_ov000_021afc20(u32 a) {
    u32 b;
    u32 c;
    u8 *d;

    for (b = 0; b < 8; b++) {
        func_ov000_021afc5c(a);
        for (c = 0; c < 0x14; c++) {
            OS_Sleep(100);
            d = func_ov000_021afd00(a);
            if (d != NULL) {
                return d;
            }
        }
    }
    return NULL;
}

void func_ov000_021afb58(u8 *a, u32 b, u32 c) {
    u16 d;
    u16 e;
    u32 f;
    u32 g;
    Unk021b6434 *p;

    if (b == 0x7f000001 || b == data_ov000_021b63b4 || func_ov000_021b00fc(b) == FALSE ||
        func_ov000_021b0094(b) != FALSE) {
        return;
    }
    d = OS_GetTick() >> 16;
    for (g = 0; g < 8; g++) {
        if (b == data_ov000_021b6434[g].mUnk_00) {
            data_ov000_021b6434[g].mUnk_0a = d;
            MI_CpuCopy8(a, data_ov000_021b6434[g].mUnk_04, 6);
            return;
        }
    }
    if (c != 0) {
        e = 0;
        f = 0;
        for (g = 0, p = data_ov000_021b6434; g < 8; g++) {
            if (p->mUnk_00 == 0) {
                f = g;
                break;
            }
            if ((s16) (d - p->mUnk_0a) > e) {
                e = d - p->mUnk_0a;
                f = g;
            }
            p++;
        }
        data_ov000_021b6434[f].mUnk_00 = b;
        MI_CpuCopy8(a, data_ov000_021b6434[f].mUnk_04, 6);
        data_ov000_021b6434[f].mUnk_0a = d;
    }
}

void func_ov000_021afaac(u8 *a, u32 b, void *c, u32 d, u32 e, u16 f) {
    u8 *g;

    *(u16 *) (a - 2) = (f >> 8) | (f << 8);
    if (func_ov000_021b0094(e) == FALSE) {
        e = func_ov000_021b00e0(e);
        if (e == 0) {
            return;
        }
        g = func_ov000_021afd00(e);
        if (g == NULL) {
            g = func_ov000_021afc20(e);
        }
        if (g == NULL) {
            return;
        }
        MI_CpuCopy8(g, a - 0xe, 6);
    } else {
        a[-0xe] = 1;
        a[-0xd] = 0;
        a[-0xc] = 0x5e;
        a[-0xb] = (e >> 16) & 0x7f;
        a[-0xa] = e >> 8;
        a[-9] = e;
    }
    MI_CpuCopy8(data_ov000_021b63d0, a - 8, 6);
    func_ov000_021affcc(a - 0xe, b + 0xe, c, d);
}

void func_ov000_021af9d0(u8 *a, u32 b, void *c, u32 d, u32 e, u32 f) {
    u16 g;
    u32 h;

    g = b + 0x14 + d;
    *(u16 *) (a - 0x12) = (g >> 8) | (g << 8);
    g = f;
    *(u16 *) (a - 0xe) = (g >> 8) | (g << 8);
    *(u16 *) (a - 0xa) = 0;
    g = func_ov000_021b0188(a - 0x14, 0x14);
    *(u16 *) (a - 0xa) = (g >> 8) | (g << 8);
    if (e != 0x7f000001 && e != data_ov000_021b63b4) {
        func_ov000_021afaac(a - 0x14, b + 0x14, c, d, e, 0x800);
    }
    if (e == 0x7f000001 || e == data_ov000_021b63b4 || func_ov000_021b0094(e) != FALSE) {
        MI_CpuCopy8(data_ov000_021b4c40, a - 0x1c, 8);
        h = OS_DisableInterrupts();
        func_ov000_021afe84(data_ov000_021b63d0, data_ov000_021b63d0, a - 0x1c, b + 0x1c, c, d);
        OS_RestoreInterrupts(h);
    }
}

void func_ov000_021af858(u8 *a, u32 b, u8 *c, u32 d, u32 e, u8 f) {
    u16 g;
    u8 *h;
    u32 i;

    a[-0x14] = 0x45;
    g = 0;
    a[-0x13] = 0;
    data_ov000_021b6378++;
    *(u16 *) (a - 0x10) = (data_ov000_021b6378 >> 8) | (data_ov000_021b6378 << 8);
    a[-0xc] = 0x80;
    a[-0xb] = f;
    *(u16 *) (a - 8) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (a - 6) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (a - 4) = ((u16) (e >> 16) >> 8) | ((u16) (e >> 16) << 8);
    *(u16 *) (a - 2) = ((u16) e >> 8) | ((u16) e << 8);
    if (b > 0x5c8) {
        h = a;
        while (b > 0x5c8) {
            func_ov000_021af9d0(a, 0, h, 0x5c8, e, g | 0x2000);
            h += 0x5c8;
            b -= 0x5c8;
            g += 0xb9;
        }
        if (b != 0) {
            if (d != 0) {
                func_ov000_021af9d0(a, 0, h, b, e, g | 0x2000);
            } else {
                func_ov000_021af9d0(a, 0, h, b, e, g);
            }
            g += b >> 3;
            b = 0;
        }
    }
    if (b + d > 0x5c8) {
        do {
            i = 0x5c8 - b;
            func_ov000_021af9d0(a, b, c, i, e, g | 0x2000);
            c += i;
            d -= i;
            g += 0xb9;
            b = 0;
        } while (d > 0x5c8);
    }
    if (b + d != 0) {
        func_ov000_021af9d0(a, b, c, d, e, g);
    }
}

void func_ov000_021af7e4(u8 *a, u32 b, Unk021a998c *c) {
    u32 e;
    u16 f;
    u16 h;
    u8 *g;
    u8 *d;

    g = c->mSendBuffer;
    d = g + 0x22;
    *(u16 *) (g + 0x22) = 8;
    *(u16 *) (d + 4) = (u32) data_0216ff5c.mCurrentThread;
    *(u16 *) (d + 2) = 0;
    h = data_ov000_021b636c;
    c->mUnk_0a = h;
    data_ov000_021b636c++;
    *(u16 *) (d + 6) = h;
    e = func_ov000_021b01b4(d, 8, 0);
    e = func_ov000_021b01b4(a, b, e);
    f = func_ov000_021b01a0(e);
    *(u16 *) (d + 2) = (f >> 8) | (f << 8);
    func_ov000_021af858(d, 8, a, b, c->mUnk_1c, 1);
}

void func_ov000_021af70c(u8 *a, u32 b, Unk021a998c *c) {
    u8 *g;
    u8 *d;
    u32 e;
    u16 f;

    g = c->mSendBuffer;
    d = g + 0x22;
    *(u16 *) (d - 0xc) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (d - 0xa) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (d - 8) = ((u16) (c->mUnk_1c >> 16) >> 8) | ((u16) (c->mUnk_1c >> 16) << 8);
    *(u16 *) (d - 6) = ((u16) c->mUnk_1c >> 8) | ((u16) c->mUnk_1c << 8);
    *(u16 *) (d - 4) = 0x1100;
    f = b + 8;
    *(u16 *) (d + 4) = (f >> 8) | (f << 8);
    *(u16 *) (d - 2) = *(u16 *) (d + 4);
    *(u16 *) (d + 2) = (c->mUnk_18 >> 8) | (c->mUnk_18 << 8);
    *(u16 *) (g + 0x22) = (c->mUnk_0a >> 8) | (c->mUnk_0a << 8);
    *(u16 *) (d + 6) = 0;
    e = func_ov000_021b01b4(d - 0xc, 0x14, 0);
    e = func_ov000_021b01b4(a, b, e);
    f = func_ov000_021b01a0(e);
    *(u16 *) (d + 6) = (f >> 8) | (f << 8);
    func_ov000_021af858(d, 8, a, b, c->mUnk_1c, 0x11);
}

void func_ov000_021af550(u8 *a, u32 b, Unk021a998c *c, u32 d, u16 e) {
    u8 *f;
    u32 g;
    u32 h;
    u16 i;

    if (c->mState == 0) {
        return;
    }
    if (data_0216ff5c.mCurrentThread == &data_ov000_021b661c) {
        f = data_ov000_021b641a;
    } else {
        f = c->mSendBuffer + 0x22;
    }
    if (d & 2) {
        g = 0x18;
    } else {
        g = 0x14;
    }
    *(u16 *) (f - 0xc) = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    *(u16 *) (f - 0xa) = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    *(u16 *) (f - 8) = ((u16) (c->mUnk_1c >> 16) >> 8) | ((u16) (c->mUnk_1c >> 16) << 8);
    *(u16 *) (f - 6) = ((u16) c->mUnk_1c >> 8) | ((u16) c->mUnk_1c << 8);
    *(u16 *) (f - 4) = 0x600;
    *(u16 *) (f - 2) = ((u16) (g + b) >> 8) | ((u16) (g + b) << 8);
    *(u16 *) f = (c->mUnk_0a >> 8) | (c->mUnk_0a << 8);
    *(u16 *) (f + 2) = (c->mUnk_18 >> 8) | (c->mUnk_18 << 8);
    *(u16 *) (f + 4) = ((u16) (c->mUnk_28 >> 16) >> 8) | ((u16) (c->mUnk_28 >> 16) << 8);
    *(u16 *) (f + 6) = ((u16) c->mUnk_28 >> 8) | ((u16) c->mUnk_28 << 8);
    *(u16 *) (f + 8) = ((u16) (c->mUnk_24 >> 16) >> 8) | ((u16) (c->mUnk_24 >> 16) << 8);
    *(u16 *) (f + 0xa) = ((u16) c->mUnk_24 >> 8) | ((u16) c->mUnk_24 << 8);
    f[0xc] = (g >> 2) << 4;
    f[0xd] = d;
    *(u16 *) (f + 0xe) = ((u16) (c->mReceiveBufferSize - c->mReceiveBufferLength) >> 8) |
                         ((u16) (c->mReceiveBufferSize - c->mReceiveBufferLength) << 8);
    *(u16 *) (f + 0x10) = 0;
    *(u16 *) (f + 0x12) = (e >> 8) | (e << 8);
    if (d & 2) {
        *(u16 *) (f + 0x14) = ((u16) ((data_ov000_021b6370 + 0x2040000U) >> 16) >> 8) |
                              ((u16) ((data_ov000_021b6370 + 0x2040000U) >> 16) << 8);
        *(u16 *) (f + 0x16) =
            ((u16) (data_ov000_021b6370 + 0x2040000U) >> 8) | ((u16) (data_ov000_021b6370 + 0x2040000U) << 8);
    }
    h = func_ov000_021b01b4(f - 0xc, g + 0xc, 0);
    h = func_ov000_021b01b4(a, b, h);
    i = func_ov000_021b01a0(h);
    *(u16 *) (f + 0x10) = (i >> 8) | (i << 8);
    func_ov000_021af858(f, g, a, b, c->mUnk_1c, 6);
    c->mUnk_28 += b;
    d &= 3;
    if (d != 0) {
        c->mUnk_28++;
    }
}

void func_ov000_021af4d4(Unk021af3e8 *a) {
    a->mUnk_06 = 0x200;
    MI_CpuCopy8(a->mUnk_08, a->mUnk_12, 10);
    MI_CpuCopy8(data_ov000_021b63d0, a->mUnk_08, 6);
    a->mUnk_0e = ((u16) (data_ov000_021b63b4 >> 16) >> 8) | ((u16) (data_ov000_021b63b4 >> 16) << 8);
    a->mUnk_10 = ((u16) data_ov000_021b63b4 >> 8) | ((u16) data_ov000_021b63b4 << 8);
    MI_CpuCopy8(a->mUnk_12, (u8 *) a - 0xe, 6);
    MI_CpuCopy8(data_ov000_021b63d0, (u8 *) a - 8, 6);
    func_ov000_021affcc((u8 *) a - 0xe, 0x2a, NULL, 0);
}

void func_ov000_021af3e8(Unk021af3e8 *f, u32 g) {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;

    if (g < 0x1c) {
        return;
    }
    if (func_ov000_021b0014(f->mUnk_08, data_ov000_021b63d0) == FALSE) {
        return;
    }
    if (data_ov000_021b63b4 == 0) {
        return;
    }
    if (f->mUnk_00 != 0x100) {
        return;
    }
    if (f->mUnk_02 != 8) {
        return;
    }
    if (f->mUnk_04 != 0x406) {
        return;
    }
    a = (u16) ((f->mUnk_06 >> 8) | (f->mUnk_06 << 8));
    if (a != 1 && a != 2) {
        return;
    }
    e = ((u16) ((f->mUnk_0e >> 8) | (f->mUnk_0e << 8)) << 16) | (u16) ((f->mUnk_10 >> 8) | (f->mUnk_10 << 8));
    d = data_ov000_021b63b4;
    if (e == d) {
        b = 1;
    } else {
        b = 0;
    }
    if (d ==
        (u32) (((u16) ((f->mUnk_18 >> 8) | (f->mUnk_18 << 8)) << 16) | (u16) ((f->mUnk_1a >> 8) | (f->mUnk_1a << 8)))) {
        c = 1;
    } else {
        c = 0;
    }
    if (b == 0) {
        func_ov000_021afb58((u8 *) f->mUnk_08, e, c);
    }
    if (a == 1 && c != 0) {
        func_ov000_021af4d4(f);
        return;
    }
    if (a == 2 && c != 0 && b != 0) {
        data_ov000_021b6368 = 1;
    }
}

void func_ov000_021af348(Unk021ae3f0 *d, Unk021af1e4 *e, u32 f) {
    u32 a;
    u32 b;
    u16 c;

    a = ((u16) ((d->mUnk_0c >> 8) | (d->mUnk_0c << 8)) << 16) | (u16) ((d->mUnk_0e >> 8) | (d->mUnk_0e << 8));
    if (func_ov000_021b0094(a) != FALSE) {
        return;
    }
    b = func_ov000_021b00e0(a);
    if (b == 0) {
        return;
    }
    if (func_ov000_021afd00(b) == NULL) {
        func_ov000_021afc5c(b);
        return;
    }
    e->mUnk_00 = 0;
    e->mUnk_02 = 0;
    c = func_ov000_021b0188(e, f);
    e->mUnk_02 = (c >> 8) | (c << 8);
    func_ov000_021af858(
        (u8 *) e, f, NULL, 0,
        ((u16) ((d->mUnk_0c >> 8) | (d->mUnk_0c << 8)) << 16) | (u16) ((d->mUnk_0e >> 8) | (d->mUnk_0e << 8)), 1);
}

void func_ov000_021af2a0(Unk021ae3f0 *c, Unk021af1e4 *d, u32 e) {
    OSThread *a;
    Unk021a998c *b;

    for (a = data_0216ff5c.mListHead; a != NULL; a = a->mNext) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == NULL || b->mThread == NULL || b->mState != 0xb || (u16) (u32) b->mThread != d->mUnk_04) {
            continue;
        }
        if (b->mUnk_0a != d->mUnk_06 || b->mReceiveBufferLength != 0) {
            continue;
        }
        if (b->mUnk_1c != (u32) (((u16) ((c->mUnk_0c >> 8) | (c->mUnk_0c << 8)) << 16) |
                                 (u16) ((c->mUnk_0e >> 8) | (c->mUnk_0e << 8)))) {
            continue;
        }
        e -= 8;
        if (e > b->mReceiveBufferSize) {
            b->mReceiveBufferLength = b->mReceiveBufferSize;
        } else {
            b->mReceiveBufferLength = e;
        }
        MI_CpuCopy8((u8 *) d + 8, b->mReceiveBuffer, b->mReceiveBufferLength);
        if (b->mUnk_04 == 3) {
            b->mUnk_04 = 0;
            OS_WakeupThreadDirect(b->mThread);
            return;
        }
        return;
    }
}

u32 func_ov000_021af284(int a, int b) {
    if ((((a != 0) && (a != -1)) && (b != 0)) && (b != -1)) {
        return 1;
    }
    return 0;
}

void func_ov000_021af1e4(Unk021ae3f0 *a, Unk021af1e4 *b, u32 c) {
    if (func_ov000_021b0188(b, c) == 0xffff) {
        if (func_ov000_021af284((u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                       (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8))),
                                (u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                       (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)))) != 0) {
            switch (b->mUnk_00) {
                case 0:
                    func_ov000_021af2a0(a, b, c);
                    break;
                case 8:
                    if (data_ov000_021b4c24 != 0) {
                        func_ov000_021af348(a, b, c);
                    }
                    break;
            }
        }
    }
}

Unk021a998c *func_ov000_021af15c(const Unk021ae3f0 *c, const Unk021ae87c *d) {
    Unk021a998c *b;
    OSThread *a;

    for (a = data_0216ff5c.mListHead; a != NULL; a = a->mNext) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b == NULL || b->mThread == NULL || b->mState != 1 ||
            b->mUnk_0a != (u16) ((d->mUnk_02 >> 8) | (d->mUnk_02 << 8))) {
            continue;
        }
        if (b->mUnk_18 != 0 && b->mUnk_18 != (u16) ((d->mUnk_00 >> 8) | (d->mUnk_00 << 8))) {
            continue;
        }
        if (b->mUnk_1c != 0 && b->mUnk_1c != (u32) (((u16) ((c->mUnk_0c >> 8) | (c->mUnk_0c << 8)) << 16) |
                                                    (u16) ((c->mUnk_0e >> 8) | (c->mUnk_0e << 8)))) {
            continue;
        }
        return b;
    }
    return NULL;
}

u32 func_ov000_021af0dc(const Unk021ae3f0 *e, const Unk021ae87c *f, const Unk021a998c *g) {
    u32 a = 0;
    u32 c = 0;
    u32 b = 0;
    u32 d = 0;

    if (g->mState != 0xa && g->mState != 0xb) {
        d = 1;
    }
    if (d != 0) {
        if (g->mUnk_0a == (u16) ((f->mUnk_02 >> 8) | (f->mUnk_02 << 8))) {
            b = 1;
        }
    }
    if (b != 0) {
        if (g->mUnk_18 == (u16) ((f->mUnk_00 >> 8) | (f->mUnk_00 << 8))) {
            c = 1;
        }
    }
    if (c != 0) {
        if (g->mUnk_1c == (u32) (((u16) ((e->mUnk_0c >> 8) | (e->mUnk_0c << 8)) << 16) |
                                 (u16) ((e->mUnk_0e >> 8) | (e->mUnk_0e << 8)))) {
            a = 1;
        }
    }
    return a;
}

Unk021a998c *func_ov000_021af090(const Unk021ae3f0 *c, const Unk021ae87c *d) {
    Unk021a998c *b;
    OSThread *a;

    a = data_0216ff5c.mListHead;
    while (a != NULL) {
        b = *(Unk021a998c **) a->mUnk_a4;
        if (b != NULL && b->mThread != NULL && func_ov000_021af0dc(c, d, b) != 0) {
            return b;
        }
        a = a->mNext;
    }
    return NULL;
}

void func_ov000_021af030(const Unk021ae87c *f, Unk021a998c *g) {
    const u8 *a;
    s32 b;
    s32 c;
    s32 e;
    u8 d;

    g->mUnk_2e = 0x218;
    b = (f->mUnk_0c & 0xf0) / 4 - 0x14;
    a = (const u8 *) f + 0x14;
    c = b - 1;
    if (b != 0) {
        do {
            d = *a++;
            if (d == 0) {
                break;
            }
            if (d != 1) {
                if (d == 2) {
                    g->mUnk_2e = (a[1] << 8) | a[2];
                    a += 3;
                    c -= 3;
                } else {
                    e = a[0] - 1;
                    c -= e;
                    a += e;
                }
            }
        } while (c-- != 0);
    }
}

u32 func_ov000_021af010(u32 b) {
    u32 a;

    a = func_ov000_021b00e0(b);
    if (a == 0) {
        return 1;
    }
    return (u32) func_ov000_021afd00(a);
}

void func_ov000_021aefc0(Unk021a998c *a, u32 b, u16 c) {
    if (func_ov000_021af010(a->mUnk_1c) != 0 || data_0216ff5c.mCurrentThread != &data_ov000_021b661c) {
        func_ov000_021af550(NULL, 0, a, b, c);
    } else {
        func_ov000_021afc5c(func_ov000_021b00e0(a->mUnk_1c));
    }
}

void func_ov000_021aefb4(void *object, u16 value) {
    func_ov000_021aefc0(object, 16, value);
}

void func_ov000_021aefa8(void *object, u16 value) {
    func_ov000_021aefc0(object, 17, value);
}

void func_ov000_021aeed8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3, u16 param_4) {
    Unk021a998c *p;

    p = &data_ov000_021b64f8;
    MI_CpuFill8(p, 0, 0x64);
    p->mUnk_0a = (param_2->mUnk_02 >> 8) | (param_2->mUnk_02 << 8);
    p->mUnk_18 = (param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8);
    p->mUnk_1c = ((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                 (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8));
    if ((param_2->mUnk_0d & 0x10) != 0) {
        p->mUnk_28 = ((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) |
                     (u16) ((param_2->mUnk_0a >> 8) | (param_2->mUnk_0a << 8));
        func_ov000_021aefc0(p, 4, param_4);
        return;
    }
    p->mUnk_28 = 0;
    p->mUnk_24 = param_3 + (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                                  (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8)));
    if ((param_2->mUnk_0d & 3) != 0) {
        p->mUnk_24++;
    }
    func_ov000_021aefc0(p, 0x14, param_4);
}

void func_ov000_021aee38(Unk021ae3f0 *param_1, Unk021ae87c *param_2, Unk021a998c *param_3) {
    param_3->mState = 3;
    param_3->mStateStartTime = OS_GetTick() >> 16;
    param_3->mUnk_14 = ((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                       (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8));
    param_3->mUnk_18 = (param_2->mUnk_00 >> 8) | (param_2->mUnk_00 << 8);
    param_3->mUnk_1c = ((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                       (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8));
    param_3->mUnk_24 = (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                              (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8))) +
                       1;
    func_ov000_021af030(param_2, param_3);
    func_ov000_021aefc0(param_3, 0x12, (param_1->mUnk_05 << 8) + 1);
}

u32 func_ov000_021aedd8(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a != NULL) {
        if (a->mState == 1) {
            func_ov000_021aee38(param_1, param_2, a);
        } else if (a->mState == 3 || a->mState == 4) {
            a->mUnk_28--;
            func_ov000_021aee38(param_1, param_2, a);
        } else {
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 3);
        }
        return 1;
    }
    return 0;
}

void func_ov000_021aed3c(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    if (func_ov000_021af284((u32) (((u16) ((param_1->mUnk_0c >> 8) | (param_1->mUnk_0c << 8)) << 16) |
                                   (u16) ((param_1->mUnk_0e >> 8) | (param_1->mUnk_0e << 8))),
                            (u32) (((u16) ((param_1->mUnk_10 >> 8) | (param_1->mUnk_10 << 8)) << 16) |
                                   (u16) ((param_1->mUnk_12 >> 8) | (param_1->mUnk_12 << 8)))) != 0) {
        if (func_ov000_021aedd8(param_1, param_2, param_3) == 0) {
            a = func_ov000_021af15c(param_1, param_2);
            if (a != NULL) {
                func_ov000_021aee38(param_1, param_2, a);
                return;
            }
            OS_YieldThread();
            a = func_ov000_021af15c(param_1, param_2);
            if (a != NULL) {
                func_ov000_021aee38(param_1, param_2, a);
            }
        }
    }
}

void func_ov000_021aec84(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL || a->mState != 2) {
        func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 5);
        return;
    }
    OS_YieldThread();
    a->mUnk_24 = (u32) (((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) |
                        (u16) ((param_2->mUnk_06 >> 8) | (param_2->mUnk_06 << 8))) +
                 1;
    a->mUnk_30 = ((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) |
                 (u16) ((param_2->mUnk_0a >> 8) | (param_2->mUnk_0a << 8));
    a->mUnk_2c = (param_2->mUnk_0e >> 8) | (param_2->mUnk_0e << 8);
    func_ov000_021af030(param_2, a);
    func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 6);
    a->mState = 4;
    if (a->mUnk_04 == 1) {
        a->mUnk_04 = 0;
        OS_WakeupThreadDirect(a->mThread);
    }
}

void func_ov000_021aea34(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;
    u32 b;
    u32 c;
    s32 d;
    s32 e;
    u32 f;
    u32 g;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL) {
        func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 9);
        return;
    }
    b = param_2->mUnk_0d;
    d = param_2->mUnk_0a;
    a->mUnk_30 = ((u16) ((param_2->mUnk_08 >> 8) | (param_2->mUnk_08 << 8)) << 16) | (u16) ((d >> 8) | (d << 8));
    e = param_2->mUnk_06;
    c = ((u16) ((param_2->mUnk_04 >> 8) | (param_2->mUnk_04 << 8)) << 16) | (u16) ((e >> 8) | (e << 8));
    if (a->mState == 4 && a->mUnk_24 != c) {
        func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0xa);
        return;
    }
    a->mUnk_2c = (param_2->mUnk_0e >> 8) | (param_2->mUnk_0e << 8);
    switch (a->mState) {
        case 0:
        case 2:
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 0x63);
            break;
        case 3:
            a->mState = 4;
            if (a->mUnk_04 == 1) {
                a->mUnk_04 = 0;
                OS_WakeupThreadDirect(a->mThread);
            }
            if (param_3 == 0) {
                break;
            }
        case 4:
            a->mUnk_34++;
            f = a->mReceiveBufferSize - a->mReceiveBufferLength;
            if (param_3 > f) {
                param_3 = f;
                c = 0;
            } else {
                c = 1;
            }
            if (param_3 != 0) {
                g = OS_DisableInterrupts();
                MI_CpuCopy8((u8 *) param_2 + (param_2->mUnk_0c & 0xf0) / 4,
                            (u8 *) a->mReceiveBuffer + a->mReceiveBufferLength, param_3);
                a->mReceiveBufferLength += param_3;
                a->mUnk_24 += param_3;
                OS_RestoreInterrupts(g);
                if (a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    OS_WakeupThreadDirect(a->mThread);
                }
            }
            if (c != 0 && (b & 1) != 0) {
                a->mState = 6;
                a->mUnk_24++;
                func_ov000_021aefa8(a, (param_1->mUnk_05 << 8) + 0xb);
                if (param_3 == 0 && a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    OS_WakeupThreadDirect(a->mThread);
                }
                break;
            }
            if (param_3 != 0) {
                func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0xc);
            }
            break;
        case 7:
        case 8:
            if ((b & 1) != 0) {
                a->mUnk_24 = a->mUnk_24 + (param_3 + 1);
                func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0xd);
                a->mState = 0;
                if (a->mUnk_04 == 2) {
                    a->mUnk_04 = 0;
                    OS_WakeupThreadDirect(a->mThread);
                }
                break;
            }
            if (param_3 != 0) {
                a->mUnk_24 += param_3;
                func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0xe);
            }
            a->mState = 8;
            break;
        case 6:
        case 9:
            a->mState = 0;
            if (a->mUnk_04 == 2) {
                a->mUnk_04 = 0;
                OS_WakeupThreadDirect(a->mThread);
            }
            break;
        default:
            if ((b & 1) != 0) {
                a->mUnk_24++;
            }
            func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0x12);
            break;
    }
    OS_YieldThread();
}

void func_ov000_021ae984(Unk021ae3f0 *param_1, Unk021ae87c *param_2, u32 param_3) {
    Unk021a998c *a;

    a = func_ov000_021af090(param_1, param_2);
    if (a == NULL) {
        return;
    }
    switch (a->mState) {
        case 7:
            a->mUnk_24++;
            func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0x13);
            a->mState = 9;
            return;
        case 8:
            a->mUnk_24++;
            func_ov000_021aefb4(a, (param_1->mUnk_05 << 8) + 0x14);
            a->mState = 0;
            if (a->mUnk_04 == 2) {
                a->mUnk_04 = 0;
                OS_WakeupThreadDirect(a->mThread);
                return;
            }
            return;
        case 4:
            a->mUnk_24++;
            func_ov000_021aefa8(a, (param_1->mUnk_05 << 8) + 0x15);
            a->mState = 6;
            return;
        default:
            func_ov000_021aeed8(param_1, param_2, param_3, (param_1->mUnk_05 << 8) + 0x16);
            return;
    }
}

void func_ov000_021ae958(const Unk021ae3f0 *a, const Unk021ae87c *b) {
    Unk021a998c *p;

    p = func_ov000_021af090(a, b);
    if (p != NULL) {
        OS_YieldThread();
        p->mState = 0;
        if (p->mUnk_04 - 1 <= 1) {
            p->mUnk_04 = 0;
            OS_WakeupThreadDirect(p->mThread);
        }
    }
}

void func_ov000_021ae87c(Unk021ae3f0 *a, Unk021ae87c *b, u32 c) {
    if (func_ov000_021b0138(b, c, (const Unk021b0138 *) a, 6) != FALSE) {
        return;
    }
    c -= (b->mUnk_0c & 0xf0) / 4;
    switch (b->mUnk_0d & 0x17) {
        case 2:
            if (b->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aed3c(a, b, c);
            return;
        case 0x12:
            if (b->mUnk_0d & 0x28) {
                return;
            }
            func_ov000_021aec84(a, b, c);
            return;
        case 0x10:
        case 0x11:
            func_ov000_021aea34(a, b, c);
            return;
        case 1:
            func_ov000_021ae984(a, b, c);
            return;
        default:
            if (b->mUnk_0d & 4) {
                func_ov000_021ae958(a, b);
                return;
            }
            func_ov000_021aeed8(a, b, c, (a->mUnk_05 << 8) + 0x17);
            return;
    }
}

void func_ov000_021ae724(Unk021ae3f0 *a, Unk021ae724 *b, u32 c) {
    OSThread *t;
    Unk021a998c *s;

    if (b->mUnk_06 != 0 && func_ov000_021b0138(b, c, (const Unk021b0138 *) a, 0x11) != FALSE) {
        return;
    }
    for (t = data_0216ff5c.mListHead; t != NULL; t = t->mNext) {
        s = *(Unk021a998c **) t->mUnk_a4;
        if (s == NULL || s->mThread == NULL || s->mState != 0xa ||
            s->mUnk_0a != (u16) ((b->mUnk_02 >> 8) | (b->mUnk_02 << 8))) {
            continue;
        }
        if (s->mUnk_18 != 0 && s->mUnk_18 != (u16) ((b->mUnk_00 >> 8) | (b->mUnk_00 << 8))) {
            continue;
        }
        if (s->mUnk_1c != 0 && s->mUnk_1c != 0xffffffff &&
            s->mUnk_1c != (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                 (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)))) {
            continue;
        }
        s->mUnk_14 =
            ((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) | (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8));
        if (s->mUnk_1c == 0) {
            s->mUnk_1c =
                ((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) | (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8));
            s->mUnk_18 = (b->mUnk_00 >> 8) | (b->mUnk_00 << 8);
        }
        if (s->mReceiveBufferLength != 0) {
            return;
        }
        c -= 8;
        if (c > s->mReceiveBufferSize) {
            s->mReceiveBufferLength = s->mReceiveBufferSize;
        } else {
            s->mReceiveBufferLength = c;
        }
        MI_CpuCopy8((u8 *) b + 8, s->mReceiveBuffer, s->mReceiveBufferLength);
        if (s->mUnk_04 == 3) {
            s->mUnk_04 = 0;
            OS_WakeupThreadDirect(s->mThread);
            return;
        }
        if (s->mReceiveCallback != NULL && s->mReceiveCallback(s->mReceiveBuffer, s->mReceiveBufferLength, s) != 0) {
            s->mReceiveBufferLength = 0;
        }
        return;
    }
}

Unk021ae3f0 *func_ov000_021ae51c(Unk021ae3f0 *r, u32 *s) {
    u32 a;
    u32 d;
    u32 e;
    u32 b;
    u32 g;
    u32 f;
    u32 c;
    u32 h;
    u32 q;
    u32 j;
    Unk021b69dc *l;
    Unk021b69dc *k;
    u16 m;
    u32 n;
    u32 o;
    u32 i;

    *s = 0;
    a = (u16) ((r->mUnk_06 >> 8) | (r->mUnk_06 << 8));
    if ((a & 0x3fff) == 0) {
        return r;
    }
    b = (r->mUnk_00 & 0xf) << 2;
    m = *(u16 *) &r->mUnk_04;
    c = ((u16) ((r->mUnk_0c >> 8) | (r->mUnk_0c << 8)) << 16) | (u16) ((r->mUnk_0e >> 8) | (r->mUnk_0e << 8));
    l = NULL;
    k = data_ov000_021b69dc;
    for (n = 0; n < 8; k++, n++) {
        if (k->mUnk_04 != 0 && k->mUnk_00 == c && k->mUnk_06 == m) {
            break;
        }
        if (k->mUnk_04 == 0 && l == NULL) {
            l = k;
        }
    }
    d = (u16) ((r->mUnk_02 >> 8) | (r->mUnk_02 << 8)) - b;
    e = a & 0x1fff;
    f = e << 3;
    g = d + f;
    if (n == 8) {
        if (l == NULL || g > 0x1000) {
            return NULL;
        }
        k = l;
        l->mUnk_34 = data_ov000_021b63a4(b + 0x100e);
        if (l->mUnk_34 == NULL) {
            return NULL;
        }
        l->mUnk_00 = c;
        l->mUnk_06 = m;
        l->mUnk_08 = 0;
        l->mUnk_2c = OS_GetTick() >> 16;
        l->mUnk_30 = l->mUnk_34 + 0xe + b;
        MI_CpuCopy8(r, l->mUnk_34 + 0xe, b);
    }
    if (k->mUnk_04 == 8 || g > 0x1000) {
        k->mUnk_04 = 0;
        data_ov000_021b63ac(k->mUnk_34);
        return NULL;
    }
    h = e + ((d + 7) >> 3);
    a = a & 0x2000;
    if (a == 0) {
        k->mUnk_0a = g;
        k->mUnk_08 = h;
    }
    k->mUnk_0c[k->mUnk_04] = e;
    k->mUnk_1c[k->mUnk_04] = h;
    k->mUnk_04++;
    MI_CpuCopy8((u8 *) r + b, k->mUnk_30 + f, d);
    j = k->mUnk_08;
    if (j == 0) {
        return NULL;
    }
    i = 0;
    o = 0;
    q = k->mUnk_04;
    while (o < q) {
        if (k->mUnk_0c[o] <= i && i < k->mUnk_1c[o]) {
            i = k->mUnk_1c[o];
            o = 0;
        } else {
            o++;
        }
    }
    if (i < j) {
        return NULL;
    }
    {
        Unk021ae3f0 *p = (Unk021ae3f0 *) (k->mUnk_34 + 0xe);

        p->mUnk_02 = ((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) >> 8) |
                     ((u16) (k->mUnk_0a + ((p->mUnk_00 & 0xf) << 2)) << 8);
        k->mUnk_04 = 0;
        *s = 1;
        return p;
    }
}

void func_ov000_021ae3f0(Unk021ae3f0 *a, u32 f) {
    u32 b;

    if ((u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) | (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8))) !=
        (u32) (((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) | (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)))) {
        if (func_ov000_021b003c(((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8))) == FALSE) {
            return;
        }
        if (f < (u16) ((a->mUnk_02 >> 8) | (a->mUnk_02 << 8))) {
            return;
        }
        if (func_ov000_021b0188(a, (a->mUnk_00 & 0xf) << 2) != 0xffff) {
            return;
        }
        if (data_ov000_021b63b4 == (u32) (((u16) ((a->mUnk_10 >> 8) | (a->mUnk_10 << 8)) << 16) |
                                          (u16) ((a->mUnk_12 >> 8) | (a->mUnk_12 << 8)))) {
            func_ov000_021afb58((u8 *) a - 8,
                                ((u16) ((a->mUnk_0c >> 8) | (a->mUnk_0c << 8)) << 16) |
                                    (u16) ((a->mUnk_0e >> 8) | (a->mUnk_0e << 8)),
                                0);
        }
    }
    a = func_ov000_021ae51c(a, &b);
    if (a != NULL) {
        u32 c = (a->mUnk_00 & 0xf) << 2;
        void *p = (u8 *) a + c;
        u32 d = (u16) ((a->mUnk_02 >> 8) | (a->mUnk_02 << 8)) - c;
        u32 e = a->mUnk_09;

        if (e == 0x11) {
            func_ov000_021ae724(a, p, d);
        } else if (data_ov000_021b63b4 != 0) {
            if (e == 1) {
                func_ov000_021af1e4(a, p, d);
            } else if (e == 6) {
                func_ov000_021ae87c(a, p, d);
            }
        }
        if (b != 0) {
            data_ov000_021b63ac((u8 *) a - 0xe);
        }
    }
}

void func_ov000_021ae3a4(void) {
    u32 v1;
    Unk021ae3a4 *v2;

    for (;;) {
        v2 = (Unk021ae3a4 *) func_ov000_021afdcc(&v1);
        if (v1 > 0x22) {
            switch ((u16) ((v2->mUnk_0c >> 8) | (v2->mUnk_0c << 8))) {
                case 0x800:
                    func_ov000_021ae3f0((Unk021ae3f0 *) ((u8 *) v2 + 0xe), v1 - 0xe);
                    break;
                case 0x806:
                    func_ov000_021af3e8((Unk021af3e8 *) ((u8 *) v2 + 0xe), v1 - 0xe);
                    break;
            }
        }
        func_ov000_021afd8c();
    }
}

u16 func_ov000_021ae340(void) {
    u32 v1;
    OSThread *t;
    Unk021a998c *s;

    do {
        v1 = 0;
        data_ov000_021b6374++;
        if (data_ov000_021b6374 < 0x400 || data_ov000_021b6374 >= 0x1388) {
            data_ov000_021b6374 = 0x400;
        }
        for (t = data_0216ff5c.mListHead; t != NULL; t = t->mNext) {
            s = *(Unk021a998c **) t->mUnk_a4;
            if (s != NULL && s->mThread != NULL && s->mUnk_0a == data_ov000_021b6374) {
                v1 = 1;
                break;
            }
        }
    } while (v1 != 0);
    return data_ov000_021b6374;
}

u32 func_ov000_021ae314(void) {
    data_ov000_021b63e0[0] = data_ov000_021b63e0[2] + data_ov000_021b63e0[1] * data_ov000_021b63e0[0];
    return data_ov000_021b63e0[0] >> 32;
}

void func_ov000_021ae304(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0216ff5c;
    value1 = *(const u32 *) ((value1) + 4u);
    value1 = (value1) + 164u;
    *(u32 *) ((value1) + 0u) = value0;
}

void func_ov000_021ae2f4(void) {
    *(u32 *) data_0216ff5c.mCurrentThread->mUnk_a4 = 0;
}

void func_ov000_021ae2d8(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (v1 != NULL) {
        v1->mState = 10;
        v1->mReceiveBufferLength = 0;
    }
}

void func_ov000_021ae290(int a, u16 b, int c) {
    u16 v1;
    Unk021a998c *v2;
    v2 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (v2 != NULL) {
        if (c == 0x7f000001) {
            c = *(s32 *) &data_ov000_021b63b4;
        }
        v2->mUnk_1a = b;
        v2->mUnk_18 = v2->mUnk_1a;
        v2->mUnk_20 = c;
        v2->mUnk_1c = v2->mUnk_20;
        if (a == 0) {
            v1 = func_ov000_021ae340();
            v2->mUnk_0a = v1;
            return;
        }
        v2->mUnk_0a = a;
    }
}

void func_ov000_021ae270(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (v1 != NULL) {
        v1->mThread = data_0216ff5c.mCurrentThread;
        v1->mState = 0;
        v1->mReceiveBufferLength = 0;
        v1->mUnk_60 = 0;
        v1->mReceiveCallback = NULL;
    }
}

void func_ov000_021ae258(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (v1 != NULL) {
        v1->mThread = NULL;
    }
}

void func_ov000_021ae244(OSThread *thread) {
    *(u32 *) thread->mUnk_a4 = *(u32 *) data_0216ff5c.mCurrentThread->mUnk_a4;
}

void func_ov000_021ae228(Unk021a998c *a) {
    u32 v1;
    v1 = func_ov000_021ae314();
    a->mUnk_28 = v1;
    a->mState = 1;
    a->mUnk_04 = 1;
    OS_SleepThread(NULL);
}

void func_ov000_021ae214(Unk021a78a4Func a) {
    u8 *v1;
    v1 = *(u8 **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (v1 != NULL) {
        *(Unk021a78a4Func *) (v1 + 0x38) = a;
    }
}

void func_ov000_021ae1e4(void) {
    Unk021a998c *a;

    a = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (a != NULL) {
        if (a->mUnk_09 != 0) {
            func_ov000_021a9534(a);
        } else {
            func_ov000_021ae228(a);
        }
    }
}

u32 func_ov000_021ae16c(Unk021a998c *b) {
    u32 a;
    u32 i;
    u32 s;

    a = func_ov000_021ae314();
    for (i = 0; i < 3; i++) {
        b->mUnk_28 = a;
        b->mState = 2;
        b->mStateStartTime = OS_GetTick() >> 16;
        func_ov000_021aefc0(b, 2, 24);
        s = OS_DisableInterrupts();
        if (data_ov000_021b63b4 != 0) {
            b->mUnk_04 = 1;
            OS_SleepThread(NULL);
        }
        OS_RestoreInterrupts(s);
        if (b->mState == 4) {
            return 0;
        }
        if (data_ov000_021b63b4 == 0) {
            break;
        }
    }
    return 1;
}

u32 func_ov000_021ae134(void) {
    Unk021a998c *a;

    a = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (a != NULL) {
        if (a->mUnk_09 != 0) {
            return func_ov000_021a943c(a);
        }
        return func_ov000_021ae16c(a);
    }
    return 1;
}

u32 func_ov000_021ae100(u16 *a, u32 *b) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if ((v1 != NULL) && ((v1->mState == 4 || (v1->mState == '\n')))) {
        if (a != NULL) {
            *a = v1->mUnk_18;
        }
        if (b != NULL) {
            *b = v1->mUnk_14;
        }
        return v1->mUnk_1c;
    }
    return 0;
}

void func_ov000_021ae0c4(Unk021a998c *a) {
    OS_YieldThread();
    if (a->mState == 3 || a->mState == 4) {
        func_ov000_021aefa8(a, 25);
        a->mState = 7;
        return;
    }
    if (a->mState != 0) {
        func_ov000_021aefb4(a, 26);
    }
}

void func_ov000_021ae094(void) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            func_ov000_021a9228(s);
        } else {
            func_ov000_021ae0c4(s);
        }
    }
}

void func_ov000_021ae048(void) {
    Unk021a998c *s;
    s32 t;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        t = OS_GetTick() >> 16;
        while (data_ov000_021b6388() != 0 && s->mState != 0 && (s32) (OS_GetTick() >> 16) - t < 0x27) {
            func_ov000_021b04d4();
        }
    }
}

u8 *func_ov000_021ae01c(u32 *a, Unk021a998c *b) {
    u32 v1;
    v1 = b->mReceiveBufferLength;
    while (v1 == 0) {
        b->mUnk_04 = 3;
        OS_SleepThread(0);
        v1 = b->mReceiveBufferLength;
    }
    *a = v1;
    return b->mReceiveBuffer;
}

u8 *func_ov000_021adfc8(u32 *a, Unk021a998c *b) {
    if (b->mReceiveBufferLength == 0 && b->mState == 4) {
        while (b->mReceiveBufferLength == 0 && b->mState == 4) {
            b->mUnk_04 = 2;
            OS_SleepThread(NULL);
        }
    } else {
        OS_YieldThread();
    }
    *a = b->mReceiveBufferLength;
    if (*a != 0) {
        return b->mReceiveBuffer;
    }
    return NULL;
}

u8 *func_ov000_021adf78(u32 *a) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        if ((u8) (s->mState + 0xf6) <= 1) {
            return func_ov000_021ae01c(a, s);
        }
        if (s->mUnk_09 != 0) {
            return func_ov000_021a93e0((s32 *) a, s);
        }
        return func_ov000_021adfc8(a, s);
    }
    *a = 0;
    return NULL;
}

void func_ov000_021adf30(u32 a, Unk021a998c *b) {
    u32 c;
    u32 d;
    u8 *e;
    u8 *f;

    c = OS_DisableInterrupts();
    d = b->mReceiveBufferLength;
    if (a >= d) {
        b->mReceiveBufferLength = 0;
    } else {
        e = b->mReceiveBuffer;
        f = e;
        f += a;
        b->mReceiveBufferLength = (d -= a);
        memmove(e, &(*f), d);
    }
    OS_RestoreInterrupts(c);
    if (b->mState != 0xa && b->mState != 0xb && b->mReceiveBufferLength == 0) {
        func_ov000_021aefb4(b, 0x1b);
    }
}

void func_ov000_021adf00(u32 a) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            func_ov000_021a9394(a, s);
        } else {
            func_ov000_021adf30(a, s);
        }
    }
}

s32 func_ov000_021ade6c(const u8 *a, s32 b, Unk021a998c *c, s32 d) {
    u32 e;
    u32 f;
    s32 g;
    s32 h;
    s32 i;

    if (d != 0) {
        e = 1;
    } else {
        e = c->mUnk_2c;
    }
    g = c->mUnk_34;
    h = g * 2 + 4;
    while (b != 0 && c->mState == 4) {
        f = c->mUnk_2e;
        if (f >= e) {
            f = e;
        }
        if (data_ov000_021b6370 < f) {
            f = data_ov000_021b6370;
        }
        if (d == 0) {
            f &= ~1;
        }
        if (b < f) {
            f = b;
        }
        i = h + (c->mUnk_34 - g);
        g = c->mUnk_34;
        h = i - 1;
        if (i == 0) {
            f = 0;
        }
        if (f == 0) {
            break;
        }
        e -= f;
        func_ov000_021af550((u8 *) a, f, c, 0x18, 0);
        OS_YieldThread();
        a += f;
        b -= f;
    }
    return f;
}

void func_ov000_021ade40(const u8 *a, s32 b, const u8 *c, s32 d, Unk021a998c *e, s32 f) {
    if (func_ov000_021ade6c(a, b, e, f) != 0 && d != 0) {
        func_ov000_021ade6c(c, d, e, 0);
    }
}

s32 func_ov000_021adcec(const u8 *a, u32 b, const u8 *c, s32 d, void *e) {
    Unk021a998c *s;
    s32 f;
    BOOL g;
    s32 h;
    u32 j;
    s32 i;
    u32 k;

    s = e;
    f = 0;
    s->mUnk_34 = 0;
    g = FALSE;
    j = OS_GetTick() >> 16;
    while (data_ov000_021b6388() != 0 && b != 0 && s->mState == 4 && (s32) ((u32) (OS_GetTick() >> 16) - j) < 0x9f) {
        h = s->mUnk_28;
        func_ov000_021ade40(a, b, c, d, s, g);
        k = OS_GetTick() >> 16;
        do {
            func_ov000_021b04d4();
        } while (data_ov000_021b6388() != 0 && s->mState == 4 && s->mUnk_28 != s->mUnk_30 &&
                 (s32) ((u32) (OS_GetTick() >> 16) - k) < 0xf && (g == FALSE || s->mUnk_2c == 0));
        i = s->mUnk_30 - h;
        f += i;
        if (i != 0) {
            j = OS_GetTick() >> 16;
        }
        s->mUnk_28 = s->mUnk_30;
        if (s->mState == 4 && s->mUnk_2c == 0 && i == 0) {
            if (g == FALSE) {
                k = OS_GetTick() >> 16;
                while (data_ov000_021b6388() != 0 && (s32) ((u32) (OS_GetTick() >> 16) - k) < 0xf) {
                    func_ov000_021b04d4();
                    if (s->mUnk_2c != 0) {
                        break;
                    }
                }
                if (s->mUnk_2c == 0) {
                    g = TRUE;
                }
            }
        } else {
            g = FALSE;
        }
        if (i >= b) {
            i -= b;
            a = c + i;
            b = d - i;
            c = NULL;
            d = 0;
        } else {
            a += i;
            b -= i;
        }
    }
    return f;
}

s32 func_ov000_021adc64(const u8 *a, s32 b, const u8 *c, s32 d) {
    Unk021a998c *s;
    u8 t;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        t = s->mState;
        if (t == 0xa) {
            if (b != 0) {
                func_ov000_021af70c((u8 *) a, b, s);
            }
            if (d != 0) {
                func_ov000_021af70c((u8 *) c, d, s);
            }
            r = b + d;
        } else if (t == 0xb) {
            if (b != 0) {
                func_ov000_021af7e4((u8 *) a, b, s);
            }
            if (d != 0) {
                func_ov000_021af7e4((u8 *) c, d, s);
            }
            r = b + d;
        } else if (s->mUnk_09 != 0) {
            r = func_ov000_021a9280((u8 *) a, b, (u8 *) c, d, s);
        } else {
            r = func_ov000_021adcec(a, b, c, d, s);
        }
        if (data_ov000_021b6364 == 0) {
            return r;
        }
    }
    return 0;
}

s32 func_ov000_021adbf4(const u8 *a, s32 b) {
    Unk021a998c *s;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_60 != 0) {
            r = func_ov000_021adc64(s->mUnk_5c, s->mUnk_60, a, b);
            if (r < s->mUnk_60) {
                memmove(s->mUnk_5c, s->mUnk_5c + r, s->mUnk_60 - r);
                s->mUnk_60 -= r;
                return 0;
            }
            r -= s->mUnk_60;
            s->mUnk_60 = 0;
            return r;
        }
        return func_ov000_021adc64(a, b, NULL, 0);
    }
    return 0;
}

s32 func_ov000_021adbac(void) {
    Unk021a998c *s;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            r = func_ov000_021a9358(s);
        } else {
            r = s->mReceiveBufferLength;
        }
        if (r == 0 && s->mState != 4 && (u8) (s->mState + 0xf6) > 1) {
            return -1;
        }
        return r;
    }
    return 0;
}

void func_ov000_021adb80(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mCurrentThread->mUnk_a4;
    if ((v1 != NULL) && (v1->mUnk_60 != 0)) {
        func_ov000_021adc64((v1->mUnk_5c), v1->mUnk_60, NULL, 0);
        v1->mUnk_60 = 0;
    }
}

void func_ov000_021adb00(void) {
    s32 a;

    data_ov000_021b6384();
    if (data_ov000_021b63b4 != 0) {
        func_ov000_021afc5c(data_ov000_021b63b4);
        OS_Sleep(100);
        func_ov000_021afc5c(data_ov000_021b63b4);
        a = OS_GetTick() >> 16;
        while (data_ov000_021b6388() != 0 && (s32) (OS_GetTick() >> 16) - a < 0x17) {
            if (data_ov000_021b6368 != 0) {
                func_ov000_021b04f8(4);
                return;
            }
            OS_Sleep(100);
        }
    }
}

void func_ov000_021ad898(void) {
    u32 a;
    u32 b;
    u32 c;
    BOOL d;
    s32 e;
    s32 i;
    OSThread *f;
    Unk021a998c *g;
    Unk021b6434 *h;
    Unk021b69dc *j;

    data_ov000_021b63b0 = 0;
    MI_CpuFill8(&data_ov000_021b6494, 0, 0x64);
    data_ov000_021b6494.mReceiveBufferSize = 0x180;
    data_ov000_021b6494.mReceiveBuffer = data_ov000_021b685c;
    data_ov000_021b6494.mSendBufferSize = 0x180;
    data_ov000_021b6494.mSendBuffer = data_ov000_021b66dc;
    func_ov000_021ae304(&data_ov000_021b6494);
    b = 0;
    d = TRUE;
    a = 1;
    data_ov000_021b637c = 1;
    while (1) {
        OS_Sleep(1000);
        if (data_ov000_021b63b0 != 0) {
            break;
        }
        c = OS_GetTick() >> 16;
        if (data_ov000_021b6388() != 0) {
            a--;
            if (a == 0) {
                if ((data_ov000_021b6398 & 1) != 0) {
                    if (b == 0) {
                        func_ov000_021adb00();
                        b = 1;
                    }
                } else {
                    switch (b) {
                        case 0:
                            if (d != FALSE) {
                                data_ov000_021b637c = 2;
                                d = FALSE;
                            }
                            if (func_ov000_021ad36c() == 0 || func_ov000_021ad2b8(&a, 0) == FALSE) {
                                func_ov000_021adb00();
                                b = 3;
                            } else {
                                b = 1;
                            }
                            break;
                        case 1:
                            if (func_ov000_021ad2b8(&a, 1) == FALSE && a < 0x3c) {
                                b = 2;
                            }
                            break;
                        case 2:
                            if (func_ov000_021ad2b8(&a, 2) != FALSE) {
                                b = 1;
                            } else if (a < 0x3c) {
                                func_ov000_021b04f8(3);
                                b = 0;
                                a = 1;
                            }
                            break;
                        case 3:
                            break;
                    }
                }
            }
        } else {
            func_ov000_021b04f8(1);
            b = 0;
            a = 1;
        }
        i = 0;
        h = data_ov000_021b6434;
        for (; i < 8; i++) {
            if (h->mUnk_00 != 0 && (s16) (c - h->mUnk_0a) > 0x3bd) {
                h->mUnk_00 = 0;
            }
            h++;
        }
        f = data_0216ff5c.mListHead;
        if (f != NULL) {
            do {
                g = *(Unk021a998c **) f->mUnk_a4;
                if (g != NULL && g->mThread != NULL) {
                    if (g->mState == 3 && (s32) (c - g->mStateStartTime) > 0x27) {
                        g->mState = 1;
                        g->mUnk_18 = g->mUnk_1a;
                        g->mUnk_1c = g->mUnk_20;
                    } else if (g->mState == 2 && (s32) (c - g->mStateStartTime) > 0x27 && g->mUnk_04 == 1) {
                        g->mState = 0;
                        g->mUnk_04 = 0;
                        OS_WakeupThreadDirect(g->mThread);
                    }
                }
                f = f->mNext;
            } while (f != NULL);
        }
        i = 0;
        j = data_ov000_021b69dc;
        for (; i < 8; i++) {
            if (j->mUnk_04 != 0 && (s32) (c - j->mUnk_2c) > 0xef) {
                data_ov000_021b63ac(j->mUnk_34);
                j->mUnk_04 = 0;
            }
            j++;
        }
        func_ov000_021a91cc(c);
        if (data_ov000_021b63a8 != NULL) {
            data_ov000_021b63a8();
        }
    }
    if ((data_ov000_021b6398 & 1) == 0 && b != 3) {
        func_ov000_021ad264();
    }
    func_ov000_021ae2f4();
}

u8 *func_ov000_021ad754(u8 *a, u8 b, u32 *c) {
    u32 d;

    MI_CpuFill8(a, 0, 0xec);
    *(u16 *) a = 0x101;
    a[2] = 6;
    data_ov000_021b63e0[0] = (s64) data_ov000_021b63e0[1] * (s64) data_ov000_021b63e0[0] + data_ov000_021b63e0[2];
    d = data_ov000_021b63e0[0] >> 32;
    if (c != NULL) {
        *c = d;
    }
    *(u16 *) (a + 4) = (u16) (d >> 16) >> 8 | (u16) (d >> 16) << 8;
    *(u16 *) (a + 6) = (u16) d >> 8 | (u16) d << 8;
    *(u16 *) (a + 0xc) = (u16) (data_ov000_021b63b4 >> 16) >> 8 | (u16) (data_ov000_021b63b4 >> 16) << 8;
    *(u16 *) (a + 0xe) = (u16) data_ov000_021b63b4 >> 8 | (u16) data_ov000_021b63b4 << 8;
    MI_CpuCopy8(data_ov000_021b63d0, a + 0x1c, 6);
    *(u16 *) (a + 0xec) = 0x8263;
    *(u16 *) (a + 0xee) = 0x6353;
    *(u16 *) (a + 0xf0) = 0x135;
    a[0xf2] = b;
    a[0xf3] = 0x3d;
    a[0xf4] = 7;
    a[0xf5] = 1;
    MI_CpuCopy8(data_ov000_021b63d0, a + 0xf6, 6);
    a[0xfc] = 0xc;
    a[0xfd] = 10;
    MI_CpuCopy8(data_ov000_021b4c34, a + 0xfe, 10);
    a[0x108] = 0x37;
    a[0x109] = 3;
    a[0x10a] = 1;
    a[0x10b] = 3;
    a[0x10c] = 6;
    return a + 0x10d;
}

u8 *func_ov000_021ad734(u8 a, u32 b, u8 *c, u32 d) {
    if (d < b) {
        MI_CpuFill8(c, a, b - d);
        c = c + (b - d);
    }
    return c;
}
