#include "01/code_02184f7c.h"
#include "01/code_021a59cc.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "01/code_02180cb4.h"
#include "01/unk_021ca000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

void func_ov001_021a63d8(void) {
    s32 lo = 0;
    s32 hi = data_ov001_021ca420->mUnk_18 - 1;

    switch (data_ov001_021ca420->mUnk_04) {
        case 1:
            hi -= 1;
            break;
        case 2:
            lo += 1;
            hi -= 1;
            break;
    }
    data_ov001_021ca420->mUnk_34 = (data_ov001_021ca420->mUnk_34 > lo) ? data_ov001_021ca420->mUnk_34 : lo;
    data_ov001_021ca420->mUnk_34 = (data_ov001_021ca420->mUnk_34 < hi) ? data_ov001_021ca420->mUnk_34 : hi;
    data_ov001_021ca420->mUnk_38 = (data_ov001_021ca420->mUnk_38 > lo) ? data_ov001_021ca420->mUnk_38 : lo;
    data_ov001_021ca420->mUnk_38 = (data_ov001_021ca420->mUnk_38 < hi) ? data_ov001_021ca420->mUnk_38 : hi;
}

void func_ov001_021a63cc(s32 value) {
    data_ov001_021ca420->mUnk_0c = value;
}

void func_ov001_021a63c0(u8 value) {
    data_ov001_021ca420->mUnk_08 = value;
}

u8 func_ov001_021a63b4(void) {
    return data_ov001_021ca420->mUnk_08;
}

void func_ov001_021a63a8(s32 value) {
    data_ov001_021ca420->mUnk_00 = value;
}

s32 func_ov001_021a639c(void) {
    return data_ov001_021ca420->mUnk_00;
}

void func_ov001_021a6388(s32 value) {
    data_ov001_021ca420->mUnk_04 = value;
    func_ov001_021a63d8();
}

s32 func_ov001_021a637c(void) {
    return data_ov001_021ca420->mUnk_04;
}

void func_ov001_021a6350(s32 x, s32 y) {
    data_ov001_021ca420->mUnk_34 = (x - data_ov001_021ca420->mUnk_10) >> data_ov001_021ca420->mUnk_0c;
    data_ov001_021ca420->mUnk_38 = (y - data_ov001_021ca420->mUnk_14) >> data_ov001_021ca420->mUnk_0c;
    func_ov001_021a63d8();
}

s32 func_ov001_021a633c(void) {
    return data_ov001_021ca420->mUnk_10 + (data_ov001_021ca420->mUnk_34 << data_ov001_021ca420->mUnk_0c);
}

s32 func_ov001_021a6328(void) {
    return data_ov001_021ca420->mUnk_14 + (data_ov001_021ca420->mUnk_38 << data_ov001_021ca420->mUnk_0c);
}

s32 func_ov001_021a6314(void) {
    return data_ov001_021ca420->mUnk_10 + (data_ov001_021ca420->mUnk_3c << data_ov001_021ca420->mUnk_0c);
}

s32 func_ov001_021a6300(void) {
    return data_ov001_021ca420->mUnk_14 + (data_ov001_021ca420->mUnk_40 << data_ov001_021ca420->mUnk_0c);
}

BOOL func_ov001_021a62c4(s32 x, s32 y) {
    s32 px = (x - data_ov001_021ca420->mUnk_10) >> data_ov001_021ca420->mUnk_0c;
    s32 py = (y - data_ov001_021ca420->mUnk_14) >> data_ov001_021ca420->mUnk_0c;

    if (px >= 0 && px < data_ov001_021ca420->mUnk_18 && py >= 0 && py < data_ov001_021ca420->mUnk_18) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov001_021a62ac(void) {
    return func_ov001_02180ce8(data_ov001_021ca420->mUnk_34, data_ov001_021ca420->mUnk_38,
                               data_ov001_021ca420->mUnk_08);
}

BOOL func_ov001_021a6278(void) {
    u8 v = func_ov001_02181004(data_ov001_021ca420->mUnk_34, data_ov001_021ca420->mUnk_38);

    if (v != 0 && v != data_ov001_021ca420->mUnk_08) {
        data_ov001_021ca420->mUnk_08 = v;
        return TRUE;
    }
    return FALSE;
}

void func_ov001_021a6238(s32 a, s32 b, s32 c, s32 d, s32 e) {
    data_ov001_021ca420 = HeapAlloc((void *) GetHeap(func_020364e8()), 0x44);
    data_ov001_021ca420->mUnk_10 = a;
    data_ov001_021ca420->mUnk_14 = b;
    data_ov001_021ca420->mUnk_18 = c;
    func_ov001_02181274(c, d, e);
}

s32 func_ov001_021a5f70(s32 a, s32 x, s32 y, s32 d, s32 dx, s32 dy) {
    s32 result;
    s32 i;
    s32 j;
    u8 col;
    s32 saveX;
    s32 saveY;
    s32 ax;
    s32 ay;
    s32 bx;
    s32 by;
    s32 cx;
    s32 cy;
    s32 ex;
    s32 ey;
    s32 ox;
    s32 oy;
    s32 sh;
    BOOL in1;
    BOOL in2;

    saveX = data_ov001_021ca420->mUnk_34;
    saveY = data_ov001_021ca420->mUnk_38;
    ox = data_ov001_021ca420->mUnk_10;
    sh = data_ov001_021ca420->mUnk_0c;
    ax = (data_ov001_021ca420->mUnk_28 - ox) << 12;
    ax >>= sh;
    oy = data_ov001_021ca420->mUnk_14;
    ay = (data_ov001_021ca420->mUnk_2c - oy) << 12;
    ay >>= sh;
    bx = (x - ox) << 12;
    bx >>= sh;
    by = (y - oy) << 12;
    by >>= sh;
    cx = ax >> 12;
    cy = ay >> 12;
    ex = bx >> 12;
    ey = by >> 12;
    in1 = FALSE;
    if (cx >= 0 && cx < data_ov001_021ca420->mUnk_18 && cy >= 0 && cy < data_ov001_021ca420->mUnk_18) {
        in1 = TRUE;
    }
    in2 = FALSE;
    if (ex >= 0 && ex < data_ov001_021ca420->mUnk_18 && ey >= 0 && ey < data_ov001_021ca420->mUnk_18) {
        in2 = TRUE;
    }
    result = 0;
    data_ov001_021ca420->mUnk_34 += dx;
    data_ov001_021ca420->mUnk_38 += dy;
    if ((data_ov001_021ca420->mUnk_30 != 0 && in1 != FALSE) || (a != 0 && in2 != FALSE)) {
        if (data_ov001_021ca420->mUnk_00 == 1) {
            col = 0;
        } else {
            col = data_ov001_021ca420->mUnk_08;
        }
        data_ov001_021ca420->mUnk_34 = ex;
        data_ov001_021ca420->mUnk_38 = ey;
        switch (data_ov001_021ca420->mUnk_00) {
            case 0:
            case 1:
                if (data_ov001_021ca420->mUnk_30 != 0) {
                    switch (data_ov001_021ca420->mUnk_04) {
                        case 0:
                            if (func_ov001_02180eec(ax, ay, bx, by, col) != 0) {
                                result = 1;
                            } else {
                                result = 0;
                            }
                            break;
                        case 1:
                            for (i = 0; i < 0x2000; i += 0x1000) {
                                for (j = 0; j < 0x2000; j += 0x1000) {
                                    if (func_ov001_02180eec(ax + i, ay + j, bx + i, by + j, col) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                        case 2:
                            for (i = -0x1000; i < 0x2000; i += 0x1000) {
                                for (j = -0x1000; j < 0x2000; j += 0x1000) {
                                    if (func_ov001_02180eec(ax + i, ay + j, bx + i, by + j, col) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                d = result;
                break;
            case 2:
            case 3:
                d = 1;
                break;
        }
    }
    func_ov001_021a63d8();
    if (d != 0) {
        if (data_ov001_021ca420->mUnk_00 == 1) {
            col = 0;
        } else {
            col = data_ov001_021ca420->mUnk_08;
        }
        switch (data_ov001_021ca420->mUnk_00) {
            case 0:
            case 1:
                switch (data_ov001_021ca420->mUnk_04) {
                    case 0:
                        if (func_ov001_02181020(data_ov001_021ca420->mUnk_34, data_ov001_021ca420->mUnk_38, col) != 0) {
                            result = 1;
                        }
                        break;
                    case 1:
                        for (i = 0; i < 2; i++) {
                            for (j = 0; j < 2; j++) {
                                if (func_ov001_02181020(data_ov001_021ca420->mUnk_34 + i,
                                                        data_ov001_021ca420->mUnk_38 + j, col) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                    case 2:
                        for (i = -1; i < 2; i++) {
                            for (j = -1; j < 2; j++) {
                                if (func_ov001_02181020(data_ov001_021ca420->mUnk_34 + i,
                                                        data_ov001_021ca420->mUnk_38 + j, col) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                }
                break;
            case 2:
                result = func_ov001_021a62ac();
                break;
            case 3:
                result = func_ov001_021a6278();
                break;
        }
    }
    data_ov001_021ca420->mUnk_30 = a;
    data_ov001_021ca420->mUnk_28 = x;
    data_ov001_021ca420->mUnk_2c = y;
    data_ov001_021ca420->mUnk_3c = saveX;
    data_ov001_021ca420->mUnk_40 = saveY;
    if (a == 0 && d == 0) {
        func_ov001_0218107c();
    }
    return result;
}

BOOL func_ov001_021a5ef4(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 0);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) - 0x19a);
        if (func_ov001_02184fb0(entry) <= 0) {
            func_ov001_02184fb4(entry, 0);
            return TRUE;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02184fb4(entry, 0);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov001_021a5e60(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 0);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) + 0x19a);
        if (func_ov001_02184fb0(entry) >= 0x1000) {
            func_ov001_02184fb4(entry, 0x1000);
        }
        return FALSE;
    }
    func_ov001_02184fb4(entry, 0x1000);
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5df0(void *obj, s32 index) {
    void *a = func_ov001_02185160(obj, index);
    void *b = func_ov001_02185160(obj, 9);
    void *c = func_ov001_02185160(obj, 10);

    func_ov001_02184fd8(b, func_ov001_02184fc8(a), func_ov001_02184fb8(a));
    func_ov001_02184fd8(c, func_ov001_02184fc8(a), func_ov001_02184fb8(a));
    func_ov001_021850a4(b, (s32(*)(Unk021a5a58 *)) func_ov001_021a5ef4);
    func_ov001_021850a4(c, (s32(*)(Unk021a5a58 *)) func_ov001_021a5e60);
}

BOOL func_ov001_021a5d18(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 1);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) - 0x19a);
        if (func_ov001_02184fb0(entry) <= 0) {
            func_ov001_02184fb4(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) + 0x19a);
        if (func_ov001_02184fb0(entry) >= 0x1000) {
            func_ov001_02184fb4(entry, 0x1000);
        }
        return FALSE;
    }
    if (entry->mUnk_10 == 11) {
        if (gEmblem->mUnk_108c != NULL) {
            gEmblem->mUnk_108c();
            gEmblem->mUnk_108c = NULL;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 20) {
        return FALSE;
    }
    func_ov001_02185018(entry, 0);
    return TRUE;
}

void func_ov001_021a5d00(void *obj, s32 index) {
    func_ov001_021850a4(func_ov001_02185160(obj, index), (s32(*)(Unk021a5a58 *)) func_ov001_021a5d18);
}

BOOL func_ov001_021a5c40(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 1);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) - 0x19a);
        if (func_ov001_02184fb0(entry) <= 0) {
            func_ov001_02184fb4(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) + 0x19a);
        if (func_ov001_02184fb0(entry) >= 0x1000) {
            func_ov001_02184fb4(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    func_ov001_02185018(entry, 0);
    return TRUE;
}

void func_ov001_021a5c28(void *obj, s32 index) {
    func_ov001_021850a4(func_ov001_02185160(obj, index), (s32(*)(Unk021a5a58 *)) func_ov001_021a5c40);
}

BOOL func_ov001_021a5b70(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 0);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) - 0x19a);
        if (func_ov001_02184fb0(entry) <= 0) {
            func_ov001_02184fb4(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        func_ov001_02184fb4(entry, func_ov001_02184fb0(entry) + 0x19a);
        if (func_ov001_02184fb0(entry) >= 0x1000) {
            func_ov001_02184fb4(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5b4c(void *obj, s32 index) {
    Unk021a5a58 *entry = func_ov001_02185160(obj, index);

    func_ov001_021850a4(entry, NULL);
    func_ov001_02185018(entry, 0);
    entry->mUnk_18 = 0x1000;
}

void func_ov001_021a5ab0(void *obj, s32 index) {
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 14);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 15);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 16);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 17);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 18);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 19);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 20);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 21);
    func_ov001_021850a4(func_ov001_02185160(obj, index), (s32(*)(Unk021a5a58 *)) func_ov001_021a5b70);
}

BOOL func_ov001_021a5a58(Unk021a5a58 *entry) {
    if (entry->mUnk_10 <= 0) {
        func_ov001_02184fb4(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5a40(void *obj, s32 index) {
    func_ov001_021850a4(func_ov001_02185160(obj, index), (s32(*)(Unk021a5a58 *)) func_ov001_021a5a58);
}

void func_ov001_021a59cc(void *obj, s32 index) {
    void *a = func_ov001_02185160(obj, index);
    void *b = func_ov001_02185160(obj, 24);

    if (func_ov001_02184ff8(b) >= 0) {
        func_ov001_021850a4(a, (s32(*)(Unk021a5a58 *)) func_ov001_021a5d18);
        func_ov001_02185018(b, -5);
        func_0212ecc0(&data_0217d068, 0, 505);
    } else {
        func_ov001_021850a4(a, (s32(*)(Unk021a5a58 *)) func_ov001_021a5d18);
        func_ov001_02185018(b, 0);
        func_0212ecc0(&data_0217d068, 0, 506);
    }
}
