#include "Main/Unknown/code_0203a908.h"
#include "00/code_02182fdc.h"
#include "01/code_021956dc.h"
#include "code_0200d118.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02043a34.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046c10.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0204a5f8.h"
#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056144.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02059be4.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_021458c4.h"

static inline u32 func_0203a908_inline(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u32 b = 1;
    u32 c = 0;
    u16 x = data_02175628[i].mUnk_4c;
    if (x == 0 && data_02175628[i].mUnk_58 < 5) {
        c = 1;
    }
    if (c == 0 && x == 0) {
        b = 0;
    }
    return b;
}

BOOL func_0203b018(u32 a, void *b, u32 c) {
    int v = func_0204684c(a);
    if (v == -1) {
        return FALSE;
    }
    func_0200d9e0(b, c, data_usa_02164754, v & 0xff);
    return TRUE;
}

static inline u32 func_0203a9ec_inline(void) {
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

u32 func_0203afe4(u32 a) {
    if (data_021759c0->mUnk_00c != 6) {
        return 1;
    }
    return a >= 0x708;
}

void func_0203ad58(void *a) {
    Unk021755a0 *b;
    b = func_02038d88(a, data_usa_02164718[data_021759c0->mUnk_00c]);
    func_02038c9c(b, 1, 1);
    func_02038d58(&b->mUnk_28, 1, 0, 0, 1, 0, 0, 0);
    switch (data_021759c0->mUnk_00c) {
        case 0:
        case 2:
        case 6:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038d58(&b->mUnk_70, 0, 0, 0, 0, 0xd, 0, 0);
            func_02038d28(&b->mUnk_70, 1, 0, 0, 0, 0xe, 0, 0);
            func_02038d00(&b->mUnk_70, 2, 0, 0, 0, 0xf, 0);
            func_02056114(0);
            break;
        case 1:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038d58(&b->mUnk_70, 0, 0, 0, 0, 0xd, 0, 0);
            func_02038d28(&b->mUnk_70, 1, 0, 0, 0, 0xe, 0, 0);
            func_02038d00(&b->mUnk_70, 2, 0, 0, 0, 0xf, 0);
            func_02056114(0);
            break;
        case 3:
        case 5:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038cb0(&b->mUnk_70, 0, 0, 1, 0, 0);
            func_02038c94(b, 0x20);
            func_02056114(1);
            break;
        case 4:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02056114(0);
            break;
    }
    func_02037abc(b);
    func_02055f68();
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 2;
}

void func_0203abdc(void) {
    void *p;
    s32 x;
    Unk0217d384 *q;
    BOOL f;
    p = func_020364e0(func_020364e8());
    func_02059dc8();
    if (data_021759c0->mUnk_00c == 3 || data_021759c0->mUnk_00c == 5) {
        func_020399a8();
    } else {
        func_02039a1c();
        func_02053e74();
    }
    func_02062860();
    func_02047b6c(7);
    func_02056158(p);
    func_0203ad58(p);
    func_020431e4();
    func_02047b6c(9);
    func_02062b50();
    func_02047b6c(5);
    InitChoisesS();
    func_020b03bc();
    if (data_021759c0->mUnk_00c != 3) {
        func_020af99c();
    }
    func_02047b6c(8);
    x = data_021759c0->mUnk_57;
    if (x == 0 && data_021759c0->mUnk_08 == 4) {
        if ((data_021759c0->mUnk_044 & 0x10) != 0) {
            x = 1;
        }
    }
    func_02043a9c(x);
    func_02047b6c(9);
    if (data_021759c0->mUnk_08 != 2) {
        if (data_021759c0->mUnk_08 == 5) {
            f = FALSE;
            q = data_0217d384;
            if (q != NULL) {
                if (q->mUnk_1f30 != 0) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                Unk0217d384_08 *p;
                q->mUnk_1f38 = 1;
                p = &data_0217d384->mUnk_0008;
                p->mUnk_10 = 5;
                p->mUnk_12 = 1;
            }
        }
    } else {
        if (data_021759c0->mUnk_18 == 0) {
            func_02046fb4(func_020364e0(func_020364e8()));
        }
    }
}

void func_0203aacc(void) {
    Unk021759c0 *p;
    Unk0217d384 *q;
    s32 t;
    BOOL f;
    if (data_021759c0->mUnk_08 == 5) {
        f = FALSE;
        q = data_0217d384;
        if (q != NULL) {
            if (q->mUnk_1f30 != 0) {
                f = TRUE;
            }
        }
        if (f != FALSE) {
            Unk0217d384_08 *p;
            q->mUnk_1f38 = 0;
            p = &data_0217d384->mUnk_0008;
            p->mUnk_10 = 4;
            p->mUnk_12 = 1;
        }
    }
    p = data_021759c0;
    if (p->mUnk_00c == 6) {
        t = 0x18;
        if (p->mUnk_08 != 0) {
            if (p->mUnk_08 == 4) {
                t = 0x1a;
            }
        } else {
            if (p->mUnk_00 == 0x36) {
                t = 0x19;
            }
        }
        if (func_02056dec(t) == 0) {
            func_02056e24(t);
            func_02056d40();
            func_02057d9c();
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
        }
    }
    func_02046ee4();
    func_020b1de4();
    func_02062004();
    func_020af86c();
    func_02056144();
    func_02053e54();
    func_02059d80();
}

void func_0203aaa8(void) {
    func_02055cbc(func_020b2e58());
    func_02062000();
    func_020b0b8c();
}

u32 func_0203a9ec(u32 a) {
    if (a > 0x564) {
        return 1;
    }
    if (func_02036c5c() == 0) {
        return 0;
    }
    if (func_0203a9ec_inline() != 0) {
        Unk02175628Index i = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_0203a908(u32 a) {
    u32 r;
    s32 t = 0x18;
    if (data_021759c0->mUnk_08 != 0) {
        if (data_021759c0->mUnk_08 == 4) {
            t = 0x1a;
        }
    } else {
        if (data_021759c0->mUnk_00 == 0x36) {
            t = 0x19;
        }
    }
    r = 0;
    if (func_02056dec(t) != 0 && a > 0xb4) {
        Unk02175628Index i = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[i].mUnk_02 & 0xc0f) != 0 || func_0203a908_inline() != 0) {
            r = 1;
        }
    }
    return r;
}
