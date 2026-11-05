#include "Main/Unknown/code_0200b6e8.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020091e0.h"
#include "Main/Unknown/code_02008e10.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "03/code_021b94b8.h"

#pragma thumb on
u32 func_0200c0ac(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &data_0216fdec;
    *(u32 *) ((value2) + 0u) = value0;
    value1 = 0u;
    *(u32 *) ((value0) + 12u) = value1;
    data_0216fdec->mUnk_1a = (u16) value1;
    data_0216fdec->mUnk_1e = (u16) value1;
    data_0216fdec->mUnk_20 = (u16) value1;
    data_0216fdec->mUnk_1c = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 4u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 8u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0200c090(u32 p0) {
    u32 v1 = ((p0) + (0x0u));
    u32 v2 = ((u32) IrqDisable());
    u32 v3 = ((u32) (&data_0216fdec));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v6;
    *(u32 *) ((v4) + (0)) = v1;
    v6 = ((u32) IrqRestore(v2));
}

#pragma thumb off

#pragma thumb on

void func_0200c008(u8 *a) {
    s32 r;
    data_0216fdec->mUnk_1a = 0;
    data_0216fdec->mUnk_1c = 0;
    data_0216fdec->mUnk_10 = (*(u16 *) (a + 0x4e) + 0x21) & ~0x1f;
    data_0216fdec->mUnk_12 = ((*(u16 *) (a + 0x4c) + 0x55) & ~0x1f) * 2;
    data_0216fdec->mUnk_14 = *(u16 *) (a + 0x4c);
    data_0216fdec->mUnk_16 = *(u16 *) (a + 0x4e);
    data_0216fdec->mUnk_18 = data_0216fdec->mUnk_14 - 6;
    func_0200c448(data_0216fdec->mUnk_16);
    r = func_021437d8(func_0200bf90, (u16 *) a, NULL, 1, 0);
    if (r != 2) {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(11, 0);
        }
    }
}

void func_0200bf90(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(11, a);
        }
    } else {
        switch (a->mUnk_08_0) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
                break;
            case 9:
                if (data_0216fdec->mUnk_00 != NULL) {
                    data_0216fdec->mUnk_00(10, 0);
                }
                break;
            case 7:
                if (data_0216fdec->mUnk_00 != NULL) {
                    data_0216fdec->mUnk_00(6, a);
                }
                break;
        }
    }
}

void func_0200bef8(void *a, u8 *b) {
    Unk0200bd34 v;
    Unk0200bd34 w;
    s32 r;
    Unk0216fdec *p;
    data_0216fdec->mUnk_04 = a;
    data_0216fdec->mUnk_08 = b;
    r = func_0214358c(1, func_0200bcd8, NULL);
    if (r != 0) {
        p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            v.mUnk_00 = 14;
            v.mUnk_02 = r;
            p->mUnk_00(0xff, &v);
        }
        return;
    }
    p = data_0216fdec;
    r = func_02144230(func_0200be44, (u32) b, p->mUnk_12, (u32) a, p->mUnk_10, 1, 0, 0, 0, 1, 1);
    if (r != 2) {
        p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            w.mUnk_00 = 14;
            w.mUnk_02 = r;
            p->mUnk_00(0xff, &w);
        }
    }
}

void func_0200be44(Unk021425e8 *a) {
    Unk0200bd34 v;
    Unk0200bd34 w;
    Unk0216fdec *p;
    u16 c;
    u16 b = a->mUnk_02;
    if (b != 0) {
        if (b != 15 && b != 9 && b != 13) {
            c = a->mUnk_00;
            p = data_0216fdec;
            if (p->mUnk_00 != NULL) {
                v.mUnk_00 = c;
                v.mUnk_02 = b;
                p->mUnk_00(0x100, &v);
            }
        }
    } else {
        switch (a->mUnk_04) {
            case 10:
                data_0216fdec->mUnk_1a = 1;
                data_0216fdec->mUnk_20 = 0;
                data_0216fdec->mUnk_1e = 0;
                if (data_0216fdec->mUnk_00 != NULL) {
                    data_0216fdec->mUnk_00(20, 0);
                }
                if (data_0216fdec->mUnk_00 != NULL) {
                    data_0216fdec->mUnk_00(25, 0);
                }
                break;
            case 11:
            default:
                c = a->mUnk_00;
                p = data_0216fdec;
                if (p->mUnk_00 != NULL) {
                    w.mUnk_00 = c;
                    w.mUnk_02 = 1;
                    p->mUnk_00(0x100, &w);
                }
                break;
            case 12:
            case 13:
                break;
        }
    }
}

void func_0200be00(void) {
    Unk0200bd34 v;
    s32 r;
    data_0216fdec->mUnk_1c = 1;
    r = func_02143dd0(func_0200bdb4);
    if (r != 2) {
        Unk0216fdec *p;
        data_0216fdec->mUnk_1c = 0;
        p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            v.mUnk_00 = 1;
            v.mUnk_02 = r;
            p->mUnk_00(0xff, &v);
        }
    }
}

void func_0200bdb4(Unk021425e8 *a) {
    Unk0200bd34 v;
    u16 b;
    data_0216fdec->mUnk_1c = 0;
    b = a->mUnk_02;
    if (b != 0) {
        u16 c = a->mUnk_00;
        Unk0216fdec *p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            v.mUnk_00 = c;
            v.mUnk_02 = b;
            p->mUnk_00(0x100, &v);
        }
    } else {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(15, 0);
        }
    }
}

void func_0200bd7c(void) {
    Unk0200bd34 v;
    s32 r = func_02143dd0(func_0200bd34);
    if (r != 2) {
        Unk0216fdec *p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            v.mUnk_00 = 1;
            v.mUnk_02 = r;
            p->mUnk_00(0xff, &v);
        }
    }
}

void func_0200bd34(Unk021425e8 *a) {
    Unk0200bd34 v;
    u16 b = a->mUnk_02;
    if (b != 0) {
        u16 c = a->mUnk_00;
        Unk0216fdec *p = data_0216fdec;
        if (p->mUnk_00 != NULL) {
            v.mUnk_00 = c;
            v.mUnk_02 = b;
            p->mUnk_00(0x100, &v);
        }
    } else {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(15, 0);
        }
    }
}

u32 func_0200bd0c(void) {
    u32 r = 0;
    u32 v = 0;
    Unk0216fdec *p = data_0216fdec;
    if (p->mUnk_1a == 1 && p->mUnk_20 == 0) {
        v = 1;
    }
    if (v != 0 && p->mUnk_1c == 0) {
        r = 1;
    }
    return r;
}

void func_0200bcd8(Unk021425e8 *a) {
    if (a->mUnk_02 == 0) {
        switch (a->mUnk_04) {
            case 7:
            case 9:
                break;
            case 21:
                if (data_0216fdec->mUnk_00 != NULL) {
                    data_0216fdec->mUnk_00(9, a);
                }
                break;
        }
    }
}

s32 func_0200bc78(u32 a, u16 b, u8 *c) {
    s32 r;
    DC_FlushRange(c, 4);
    DC_WaitWriteBufferEmpty();
    if (func_0200bd0c() == 0) {
        return 1;
    }
    r = func_02144048(func_0200bc1c, NULL, c, (u16) a, b, 1, 3);
    if (r == 2) {
        data_0216fdec->mUnk_20 = 1;
        return 2;
    }
    return r;
}

void func_0200bc1c(Unk021425e8 *a) {
    data_0216fdec->mUnk_20 = 0;
    if (a->mUnk_02 == 0) {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(8, a);
        }
    } else if (a->mUnk_02 == 9) {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(0x29, a);
        }
    } else {
        if (data_0216fdec->mUnk_00 != NULL) {
            data_0216fdec->mUnk_00(0x12, a);
        }
    }
    if (data_0216fdec->mUnk_00 != NULL) {
        data_0216fdec->mUnk_00(0x19, 0);
    }
}

void func_0200bc0c(void) {
    func_0214358c(1, NULL, NULL);
}

void func_0200bb98(Unk0216fde8 *a, void *b) {
    if (*(u16 *) &data_0216fde4 == 0) {
        *(u16 *) &data_0216fde4 = 1;
        MemFill(a, 0, 0x5f20);
        data_0216fde8 = a;
        a->mUnk_5f0e = 0;
        MemCopy(b, data_0216fde8->mUnk_05c4, 0x16);
        func_0200991c(data_0216fde8->mUnk_05e8);
        func_020092a4();
        func_02009908((UnkFunc *) func_0200b7e0, (UnkFunc *) func_0200b7cc);
    }
}

void func_0200bae0(void) {
    if (data_0216fde8->mUnk_5f04 == 0) {
        data_0216fde8->mUnk_5f04 = 1;
        switch (data_0216fde8->mUnk_5f0e) {
            case 0:
                if (data_0216fde8->mUnk_5ef8 != 0) {
                    data_0216fde8->mUnk_5ef8 = 0;
                    return;
                }
                if (data_0216fde8->mUnk_5efc == 0) {
                    func_0200bab0();
                    return;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 14:
            case 19:
                func_0200bd7c();
                break;
            case 5:
            case 7:
            case 8:
            case 9:
                func_0200be00();
                break;
            case 10:
                break;
            case 11:
            case 12:
                func_0200bab0();
                break;
            default:
                IrqDisableLoopForever();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_0200bab0(void) {
    *(u16 *) &data_0216fde4 = 0;
    data_0216fde8->mUnk_5f04 = 0;
    func_0200bc0c();
    func_0200ba44((u32) 0x14, (void *) 0);
}

u32 func_0200baa8(void) {
    return 0x5f20u;
}

void func_0200ba84(UnkFunc *p0) {
    u32 v1 = (u32) p0;
    u32 v2 = ((u32) IrqDisable());
    u32 v3 = ((u32) (&data_0216fde8));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v5 = 0x5e0u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = ((u32) IrqRestore(v2));
}

#pragma thumb off

#pragma thumb on

void func_0200ba44(u32 a, void *b) {
    u32 v1;
    v1 = IrqDisable();
    data_0216fde8->mUnk_5f0e = a;
    IrqRestore(v1);
    if (data_0216fde8->mUnk_05e0 != NULL) {
        data_0216fde8->mUnk_05e0(a, b);
    }
}

#pragma thumb off

#pragma thumb on

void func_0200b9e0(UnkFunc *a, u32 b) {
    data_0216fde8->mUnk_05dc = a;
    data_0216fde8->mUnk_05e4 = b;
    data_0216fde8->mUnk_0580.mUnk_04 = 0;
    data_0216fde8->mUnk_0580.mUnk_00 = data_0216fde8->mUnk_04c0;
    data_0216fde8->mUnk_5ef8 = 1;
    data_0216fde8->mUnk_5f00 = 0;
    data_0216fde8->mUnk_05ee = 0;
    func_0200b934();
}

#pragma thumb off

#pragma thumb on

void func_0200b934(void) {
    s32 r;
    Unk0216fde8 *d;
    u8 *p;
    u8 *q;
    d = data_0216fde8;
    if (d->mUnk_5f00 != 0) {
        d->mUnk_0580.mUnk_06 = 0xdc;
    } else {
        p = d->mUnk_0580.mUnk_08;
        q = data_usa_02152be4;
        p[0] = q[0];
        p[1] = q[1];
        p[2] = q[2];
        p[3] = q[3];
        p[4] = q[4];
        p[5] = q[5];
        data_0216fde8->mUnk_0580.mUnk_06 = 10;
        if (func_0200b72c() == 0) {
            func_0200b820(0x1e, 0);
            return;
        }
    }
    if (data_0216fde8->mUnk_0580.mUnk_04 == 0) {
        data_0216fde8->mUnk_0580.mUnk_04 = 1;
    }
    r = func_02143a78(func_0200b894, &data_0216fde8->mUnk_0580);
    if (r != 2) {
        func_0200b820(0xa, r);
    }
}

void func_0200b894(Unk021425e8 *a) {
    if (a->mUnk_02 != 0) {
        func_0200b820(0xa, a->mUnk_02);
        return;
    }
    switch (a->mUnk_08_0) {
        case 3:
            break;
        case 5:
            if (a->mUnk_38.mUnk_00[1] == data_0216fde8->mUnk_05e4) {
                DC_InvalidateRange(data_0216fde8->mUnk_04c0, 0xc0);
                func_0200921c(func_0200b794, a->mUnk_12, (Unk02007ec4 *) data_0216fde8->mUnk_04c0);
                func_02008f00(func_0200b794, 1);
            }
        case 4:
            func_02008f00(func_0200b794, 0);
            if (data_0216fde8->mUnk_5ef8 != 0) {
                func_0200b934();
            } else {
                func_0200b6e8();
            }
            break;
        default:
            func_0200b820(0xa, 1);
            break;
    }
}

void func_0200b850(u32 a, Unk02008934 *b, u32 c) {
    Unk0200b850 v;
    Unk0216fde8 *d;
    d = data_0216fde8;
    if (d->mUnk_05dc != NULL) {
        v.mUnk_00 = c;
        if (b != NULL) {
            v.mUnk_04 = b;
            v.mUnk_08 = b->mUnk_4c0;
        } else {
            v.mUnk_04 = NULL;
            v.mUnk_08 = NULL;
        }
        d->mUnk_05dc(a, &v);
    }
}

void func_0200b820(u16 a, u16 b) {
    Unk0200b820 v;
    if (data_0216fde8->mUnk_05dc != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        data_0216fde8->mUnk_05dc(2, &v);
    }
}

void func_0200b7e0(const u8 *a) {
    u8 *p;
    data_0216fde8->mUnk_5f00 = 1;
    p = data_0216fde8->mUnk_0580.mUnk_08;
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[3] = a[3];
    p[4] = a[4];
    p[5] = a[5];
}

#pragma thumb off

#pragma thumb on
u32 func_0200b7cc(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0216fde8;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x5f00u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0200b794(u32 a, void *b, u32 c) {
    switch (a) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            func_0200b850(0, b, c);
            break;
        case 3:
            func_0200b850(1, b, c);
            break;
    }
}

u32 func_0200b72c(void) {
    u16 a;
    a = func_02143280();
    if (a == 0x8000 || a == 0) {
        return 0;
    }
    data_0216fde8->mUnk_0580.mUnk_04++;
    do {
        data_0216fde8->mUnk_0580.mUnk_04++;
        if (data_0216fde8->mUnk_0580.mUnk_04 > 0x10) {
            data_0216fde8->mUnk_0580.mUnk_04 = 1;
        }
    } while ((a & (1 << (data_0216fde8->mUnk_0580.mUnk_04 - 1))) == 0);
    return 1;
}

void func_0200b70c(void) {
    data_0216fde8->mUnk_5ef8 = 0;
    data_0216fde8->mUnk_5efc = 1;
}

#pragma thumb off

#pragma thumb on

void func_0200b6e8(void) {
    u32 v1;
    v1 = func_021438a8(func_0200b698);
    if (v1 != 2) {
        func_0200b820((u16) 0xb, (u16) (v1 & 0xffff));
    }
}

#pragma thumb off
