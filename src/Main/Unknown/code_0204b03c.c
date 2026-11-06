#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_0200cd1c.h"
#include "code_0200f5ac.h"
#include "code_0214578c.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0204984c.h"

#pragma thumb on

void func_0204b3dc(void) {
    s32 r;
    r = data_021759d4->mUnk_08;
    if (r != -3) {
        CARD_UnlockBackup(r);
        OS_ReleaseLockID(data_021759d4->mUnk_08);
        data_021759d4->mUnk_08 = -3;
    }
}

u32 func_0204b3a4(void) {
    s32 r;
    data_021759d4->mUnk_08 = OS_GetLockID();
    r = data_021759d4->mUnk_08;
    if (r == -3) {
        return 0;
    }
    CARD_LockBackup(r);
    return 1;
}

void func_0204b344(s32 a) {
    BOOL f;
    f = TRUE;
    switch (data_021759d4->mUnk_00) {
        case 1:
        case 2:
            f = FALSE;
    }
    data_021759d4->mUnk_00 = 4;
    data_021759d4->mUnk_04 = (void *) a;
    switch ((s32) data_021759d4->mUnk_04) {
        case 0:
            break;
        case 1:
        case 2:
            if (f != FALSE) {
                func_02049980(1);
            } else {
                func_02049980(2);
            }
            break;
        case 3:
        case 4:
            break;
    }
}

u16 func_0204b2cc(u8 *p, u32 n) {
    u16 v1;
    u16 i;
    u16 v2;
    u8 b;
    s32 k;
    i = 0;
    v1 = 0;
    if (i < n) {
        do {
            b = *p;
            for (k = 0; k < 8; k++) {
                if (v1 & 0x8000) {
                    v1 <<= 1;
                    v1 ^= data_usa_02154708;
                } else {
                    v1 <<= 1;
                }
                if (b & 0x80) {
                    v1 ^= 1;
                }
                b = b << 1;
            }
            p++;
            i++;
        } while (i < n);
    }
    return v1;
}

void func_0204b284(u8 *p, u32 n, u32 a) {
    u8 *e;
    u16 c;
    e = p + n - 4;
    if (a == 0) {
        e[0] = 0;
        e[1] = 0;
    }
    e[2] = 0;
    e[3] = 0;
    c = func_0204b2cc(p, n);
    if (a == 0) {
        e[0] = (OS_GetTick() >> 16) & 0xff;
        e[1] = (OS_GetTick() >> 32) & 0xff;
    }
    e[2] = c >> 8;
    e[3] = c;
}

u32 func_0204b258(u8 *p, u32 n, u32 a) {
    u8 *e;
    e = p + n - 4;
    if (a == 0) {
        e[0] = 0;
        e[1] = 0;
    }
    if (func_0204b2cc(p, n) == 0) {
        return 1;
    }
    return 0;
}

s32 func_0204b20c(u32 a, u32 b) {
    u16 i;
    s32 r;
    i = 0;
    r = -1;
    for (; i < 0x1d; i++) {
        if (b ==
            (a ^ (data_usa_02154694[i] + (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]))))) {
            r = i;
            break;
        }
    }
    return r;
}

void func_0204b138(u32 *p, u32 n) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    u32 *e;
    u32 m;
    j = 0;
    l = 0;
    k = 0;
    i = (OS_GetTick() >> 16) % 0x1d;
    m = data_usa_02154694[i] + (data_usa_02154648[0] + (data_usa_021545d8[0] + data_usa_02154604[0]));
    i = func_0204b20c(m ^ *p, *p);
    e = OFFSET_PTR(u32, p, n);
    do {
        *p ^= data_usa_02154694[i] + (data_usa_02154648[j] + (data_usa_021545d8[k] + data_usa_02154604[l]));
        p++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (p < e);
}

u32 func_0204b084(u32 *p, u32 n, u32 a) {
    u16 i;
    u16 j;
    u16 k;
    u16 l;
    s32 s;
    u32 *e;
    j = 0;
    l = 0;
    k = 0;
    s = func_0204b20c(*p, a);
    if (s == -1) {
        return 0;
    }
    i = s;
    e = OFFSET_PTR(u32, p, n);
    do {
        *p ^= data_usa_02154694[i] + (data_usa_02154648[j] + (data_usa_021545d8[k] + data_usa_02154604[l]));
        p++;
        k++;
        if (k >= 0xb) {
            k = 0;
            l++;
            if (l >= 0x11) {
                l = 0;
                j++;
                if (j >= 0x13) {
                    j = 0;
                    i++;
                    if (i >= 0x1d) {
                        i = 0;
                    }
                }
            }
        }
    } while (p < e);
    return 1;
}

#pragma thumb off

void func_0204b03c(void) {
    if (data_021759d0->mUnk_20 == 3) {
        func_02059c34();
        func_02059ea4(0);
        func_02059e1c();
    }
    func_0202f2b4(GetHeap(func_020364e8()));
}
