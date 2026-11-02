#include "Main/Unknown/code_021281dc.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021285b0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02128570.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02016468.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on
s32 func_021287cc(void *a, s32 b) {
    u32 t;
    data_0217d3f8 = func_02036bec(a, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02128778();
        b = func_021286a0(b);
        data_0217d3f8->mUnk_820 = 1;
    } else {
        data_0217d3f8->mUnk_820 = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~4;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    data_0217d3f8->mUnk_00 = 1;
    data_0217d3f8->mUnk_04 = 0;
    data_0217d3f8->mUnk_08 = 0;
    data_0217d3f8->mUnk_0c = 0;
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_818 = 0;
    data_0217d3f8->mUnk_81c = -0x28;
    data_0217d3f8->mUnk_824 = 0xe;
    return b;
}
#pragma thumb off

#pragma thumb on
void func_021287c0(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d3f8;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_02128778(void) {
    u32 t;
    t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & ~3);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & 0x43) | 0xe00;
}

s32 func_021286a0(s32 a) {
    Unk020b4934 *x;
    Unk020b47d8 *y;
    Unk020b4a44 *z;
    s32 i;
    s32 j;
    s32 k;
    LocateNcgr(&x, func_02047a28("select_return_s_b_00.ncgr"));
    LocateNscr(&y, func_02047a28("select_return_s_bg_00.nscr"));
    LocateNclr(&z, func_02047a28("select_return_s_b_00.nclr"));
    a -= x->mUnk_10;
    func_0200ee74(x->mUnk_14, x->mUnk_10);
    func_0214b8f4(x->mUnk_14, a, x->mUnk_10);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(data_0217d3f8->mUnk_10 + i * 0x20 + j) = (a >> 5) + *((u16 *) y->mUnk_0c + i * 0x20 + j);
        }
    }
    func_0200ee74(data_0217d3f8->mUnk_10, y->mUnk_08);
    func_0214bc34(data_0217d3f8->mUnk_10, 0, y->mUnk_08);
    func_0200ee74(z->mUnk_0c, 0x180);
    func_0214c0f8(z->mUnk_0c + 0xc0, 0x180, 0x40);
    return a;
}

void func_02128624(s32 a) {
    s32 i;
    u16 v;
    v = 0xc000;
    if (a == 0) {
        v = 0xd000;
    }
    for (i = 0x260; i < 0x360; i++) {
        data_0217d3f8->mUnk_10[i] &= ~0xf000;
        data_0217d3f8->mUnk_10[i] |= v;
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02016468(0x1a, 0x4c0, &data_0217d3f8->mUnk_10[0x260], 0x200);
    }
}

void func_021285f8(void) {
    if (data_0217d3f8->mUnk_810 != 0) {
        data_0217d3f8->mUnk_08 = 1;
        data_0217d3f8->mUnk_0c = 0;
        func_02128624(1);
    }
}

void func_021285b0(void) {
    Unk0217d3f8 *p;
    data_0217d3f8->mUnk_81c = func_0212825c(data_0217d3f8->mUnk_0c);
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 2;
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_810 = 0;
    }
}
#pragma thumb off

#pragma thumb on

void func_02128570(void) {
    int v1;
    v1 = *(int *) &data_0217d3f8;
    if (*(int *) (v1 + 0x814) != 0) {
        *(u32 *) (v1 + 8) = 3;
        func_02128624(0);
        return;
    }
    if (*(int *) (v1 + 0x818) != 0) {
        *(u32 *) (v1 + 8) = 4;
    }
}

#pragma thumb off

#pragma thumb on
void func_02128508(void) {
    Unk0217d3f8 *p;
    p = data_0217d3f8;
    p->mUnk_81c = data_0215d0b4[p->mUnk_0c];
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 9) {
        if (p->mUnk_818 != 0) {
            p->mUnk_08 = 4;
            func_02128624(0);
        } else {
            p->mUnk_08 = 2;
            func_02128624(1);
        }
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_814 = 0;
    }
}

void func_021284c0(void) {
    Unk0217d3f8 *p;
    data_0217d3f8->mUnk_81c = func_02128244(data_0217d3f8->mUnk_0c);
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 0;
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_818 = 0;
    }
}

void func_02128458(void) {
    Unk0217d3f8 *p;
    p = data_0217d3f8;
    if (p->mUnk_00 != 0) {
        p->mUnk_04 = p->mUnk_08;
        switch (data_0217d3f8->mUnk_04) {
            case 0:
                func_021285f8();
                break;
            case 1:
                func_021285b0();
                break;
            case 2:
                func_02128570();
                break;
            case 3:
                func_02128508();
                break;
            case 4:
                func_021284c0();
                break;
        }
    }
}

void func_021283bc(void) {
    Unk0217d3f8 *p;
    u32 t;
    p = data_0217d3f8;
    if (p->mUnk_00 != 0) {
        if (p->mUnk_820 != 0) {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) == 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
            }
        } else {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) != 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t & ~4) << 8);
            }
        }
        *(vu32 *) 0x4001018 = (data_0217d3f8->mUnk_81c << 16) & 0x1ff0000;
    }
}

void func_02128374(void) {
    if (func_02128294() != 0) {
        data_0217d3f8->mUnk_810 = 0;
    } else {
        data_0217d3f8->mUnk_810 = 1;
    }
    data_0217d3f8->mUnk_814 = 0;
    data_0217d3f8->mUnk_818 = 0;
}

void func_02128310(s32 a) {
    s32 v;
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_814 = 1;
    if (a != 0) {
        data_0217d3f8->mUnk_818 = 1;
    } else {
        data_0217d3f8->mUnk_818 = 0;
    }
    v = data_0217d3f8->mUnk_824;
    if (v != -1) {
        func_0212ecc0(&data_0217d068, 0, (u16) v);
    }
}

void func_021282c8(void) {
    if (func_02128274() != 0) {
        data_0217d3f8->mUnk_818 = 0;
    } else {
        data_0217d3f8->mUnk_818 = 1;
    }
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_814 = 0;
}

s32 func_02128294(void) {
    s32 r;
    s32 t;
    Unk0217d3f8 *p;
    r = 0;
    t = 0;
    p = data_0217d3f8;
    if (p->mUnk_04 == 2 && p->mUnk_818 == 0) {
        t = 1;
    }
    if (t != 0) {
        if (p->mUnk_814 == 0) {
            r = 1;
        }
    }
    return r;
}

s32 func_02128274(void) {
    s32 r;
    Unk0217d3f8 *p;
    r = 0;
    p = data_0217d3f8;
    if (p->mUnk_04 == 0 && p->mUnk_810 == 0) {
        r = 1;
    }
    return r;
}
#pragma thumb off

#pragma thumb on

int func_0212825c(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return (int) *(s8 *) (((int) (u32) (data_0215d0c0)) + a);
}

int func_02128244(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return (int) *(s8 *) (((int) (u32) (data_0215d0cc)) + a);
}

#pragma thumb off

#pragma thumb on
s32 func_02128210(s32 a, s32 b) {
    if (func_02128294() != 0 && a >= 0 && a <= 0x28 && b >= 0x98 && b <= 0xc0) {
        return 1;
    }
    return 0;
}
#pragma thumb off

#pragma thumb on
void func_021281fc(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0217d3f8;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x820u;
    *(u32 *) ((value1) + (value0)) = value2;
}
#pragma thumb off

#pragma thumb on
void func_021281dc(void) {
    if (*(vu16 *) 0x27ffc40 != 2) {
        data_0217d3f8->mUnk_820 = 1;
    }
}
#pragma thumb off
