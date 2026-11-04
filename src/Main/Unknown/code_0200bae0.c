#include "Main/Unknown/code_0200bae0.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_0200c3fc.h"
#include "code_0200eddc.h"

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
    func_0200ee74(c, 4);
    func_0200ee98();
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
