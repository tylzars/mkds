#include "01/code_021804e0.h"
#include "01/code_02180af8.h"
#include "01/code_02180b14.h"
#include "01/code_02180c88.h"
#include "01/code_02180cb4.h"
#include "01/code_021a5140.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_020ca6b8.h"
#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02023374.h"
#include "code_021488e8.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020ca000.h"
#include "01/code_02180000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_020ae718.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_020ca820.h"

#pragma optimize_for_size on
#pragma thumb off

u32 func_ov001_02180ad0(Unk02180728 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u16 *p5) {
    return func_02024340(p0, p1, p2, p3, p4, p5);
}

#pragma thumb on

void func_ov001_02180800(void) {
    s32 mtx[4];

    if (data_ov001_021a99e4->mUnk_0008 != 0) {
        func_ov001_02180ca4();
        func_ov001_02180c88((u32) mtx);
        switch (data_ov001_021a99e4->mUnk_0004) {
            case 0:
                func_ov001_02180c6c((u32) 1);
                GxsDispCntBits0To2Write(0);
                func_ov001_02180c40((u32) 0, (u32) 0);
                func_ov001_02180c24((u32) 0);
                func_ov001_02180bf8((u32) 0);
                func_ov001_02180bc0((u32) 0, (u32) 0, (u32) 4, (u32) 4, (u32) 0);
                func_020ca688(1);
                func_020ca6a8();
                break;
            case 1:
            case 2:
            case 3:
                func_ov001_02180c6c((u32) 2);
                GxsDispCntBits0To2Write(0);
                func_ov001_02180b94((u32) 0, (u32) 0);
                func_ov001_02180b78((u32) 0);
                func_ov001_02180b4c((u32) 0);
                func_ov001_02180b14((u32) 0, (u32) 0, (u32) 4, (u32) 4, (u32) 0);
                *(u16 *) 0x5000400 = 0;
                *(u16 *) 0x5000402 = 0x1f;
                *(u16 *) 0x5000404 = 0x3e0;
                *(u16 *) 0x5000406 = 0x3fff;
                *(u16 *) 0x5000408 = 0x7c00;
                *(u16 *) 0x500040a = 0x7c1f;
                *(u16 *) 0x500040c = 0;
                *(u16 *) 0x500040e = 0xffff;
                func_ov001_02180ccc((u16 *) (data_ov001_021a99e4->mUnk_00a8));
                MemCopyHalfwordsToG2sBg1CntBits8To12Address((const void *) data_ov001_021a99e4->mUnk_60a8, 0, 0x600);
                break;
        }
    }
    if (data_ov001_021a99e4->mUnk_0004 == 0) {
        func_020ca9e4();
    } else if ((u32) (data_ov001_021a99e4->mUnk_0004 - 1) <= 2) {
        u32 keys;
        BOOL moved;
        int idx;
        int col;
        int row;
        int n;
        s32 tbl[8] = {0xe000, 0xe060, 0x20, 0x80, 0xa0, 0x100, 0x3040, 0x30a0};
        u16 chars[0x5f] = {0x20ac, 0x201a, 0x201e, 0x2026, 0x2c6,  0x152,  0x2018, 0x2019, 0x201c, 0x201d, 0x2022,
                           0x2dc,  0x2122, 0x203a, 0x153,  0x3000, 0x3001, 0x3002, 0xff0c, 0xff0e, 0x30fb, 0xff1a,
                           0xff1b, 0xff1f, 0xff01, 0x309b, 0x309c, 0xb4,   0xff40, 0xa8,   0xff3e, 0xffe3, 0xffef,
                           0x309d, 0x309e, 0x3005, 0x30fc, 0x2015, 0x2010, 0xff0f, 0xff3c, 0xff5e, 0xff5c, 0x2026,
                           0x2018, 0x2019, 0x201c, 0x201d, 0xff08, 0xff09, 0x3014, 0x3015, 0xff3b, 0xff3d, 0xff5b,
                           0xff5d, 0x3008, 0x3009, 0x300c, 0x300d, 0xff0b, 0xff0d, 0xb1,   0xd7,   0xf7,   0xff1d,
                           0x221e, 0x2234, 0xb0,   0x2032, 0x2033, 0xff06, 0x2606, 0x2605, 0x25cb, 0x25cf, 0x25ce,
                           0x25c7, 0x25c6, 0x25a1, 0x25a0, 0x25b3, 0x25b2, 0x25bd, 0x25bc, 0x203b, 0x3012, 0x2192,
                           0x2190, 0x2191, 0x2193, 0x266f, 0x266d, 0x266a, 0x0};
        keys = func_ov001_021805ec();
        moved = FALSE;
        if (data_ov001_021a99e4->mUnk_0004 == 1) {
            idx = 0;
        } else if (data_ov001_021a99e4->mUnk_0004 == 2) {
            idx = 1;
        } else if (data_ov001_021a99e4->mUnk_0004 == 3) {
            idx = 2;
        }
        if (func_ov001_021805bc(keys, 0x20) != 0) {
            data_ov001_021a99e8 = (data_ov001_021a99e8 + 8) % 9;
            func_ov001_02180af8(data_ov001_021a99e4->mUnk_0018[idx], 0);
            moved = TRUE;
        } else if (func_ov001_021805bc(keys, 0x10) != 0) {
            data_ov001_021a99e8 = (data_ov001_021a99e8 + 1) % 9;
            func_ov001_02180af8(data_ov001_021a99e4->mUnk_0018[idx], 0);
            moved = TRUE;
        }
        if (moved != FALSE) {
            n = 0;
            for (row = 0; row < 6; row++) {
                for (col = 0; col < 16; col++) {
                    if (data_ov001_021a99e8 != 8) {
                        data_ov001_021a99ec[n++] = row * 16 + col + tbl[data_ov001_021a99e8];
                    } else {
                        data_ov001_021a99ec[n++] = chars[row * 16 + col];
                    }
                }
                data_ov001_021a99ec[n++] = 0xa;
            }
            func_ov001_02180ad0(&data_ov001_021a99e4->mUnk_0078[idx], 0x80, 0x62,
                                data_ov001_021a99e4->mUnk_0004 == 3 ? 6 : 7, 0x412, data_ov001_021a99ec);
        }
        MemCopyWordsToG2sBg1CntBits2To5Address((const void *) data_ov001_021a99e4->mUnk_00a8, 0, 0x6000);
    }
    switch (data_ov001_021a99e4->mUnk_0008) {
        case 0:
            func_ov001_02180c40((u32) 0, (u32) 0);
            break;
        case 1:
        case 2:
        case 3:
            func_ov001_02180b94((u32) 0, (u32) 0);
            break;
    }
    data_ov001_021a99e4->mUnk_0008 = 0;
}

#pragma thumb off

void *func_ov001_021807e4(void) {
    return GetHeap(func_020364e8());
}

void func_ov001_021807a8(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7) {
    func_02038d28(p0->mUnk_28, p1, p2, p3, p4, p5, p6, p7);
}

void func_ov001_02180774(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    func_02038d00(p0->mUnk_28, p1, p2, p3, p4, p5, p6);
}

void func_ov001_02180740(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    func_02038d00(p0->mUnk_70, p1, p2, p3, p4, p5, p6);
}

void func_ov001_02180728(Unk02180728 *p0, void *p1, void *p2, s32 p3, s32 p4) {
    p0->mUnk_00 = p1;
    p0->mUnk_04 = p2;
    p0->mUnk_08 = p3;
    p0->mUnk_0c = p4;
}

#pragma thumb on

void func_ov001_02180610(void) {
    Unk020391d4 v = {1, 0x16, 4, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 8, 0};
    void *x;
    int i;

    data_ov001_021a99e4 = HeapAlloc((void *) func_ov001_021807e4(), 0x66a8);
    data_ov001_021a99e4->mUnk_0000 = 0;
    data_ov001_021a99e4->mUnk_0004 = 1;
    data_ov001_021a99e4->mUnk_0008 = 1;
    func_ov001_02180ccc((u16 *) (data_ov001_021a99e4->mUnk_00a8));
    func_ov001_02180cb4((u16 *) (data_ov001_021a99e4->mUnk_60a8));
    x = func_02038d88((void *) func_ov001_021807e4(), &v);
    func_ov001_021807a8(x, 0, 0, 0, 0, 4, 0, 0);
    func_ov001_02180774(x, 2, 0, 0, 0, 0xe, 1);
    func_ov001_02180740(x, 2, 0, 0, 0, 4, 4);
    func_02037abc(x);
    data_ov001_021a99e4->mUnk_000c[0] = func_020b403c(0);
    data_ov001_021a99e4->mUnk_000c[1] = func_020b403c(1);
    data_ov001_021a99e4->mUnk_000c[2] = func_020b403c(2);
    for (i = 0; i < 3; i++) {
        func_02023408(data_ov001_021a99e4->mUnk_0018[i], data_ov001_021a99e4->mUnk_00a8, 0x20, 0x18, 4);
        func_ov001_02180728(&data_ov001_021a99e4->mUnk_0078[i], data_ov001_021a99e4->mUnk_0018[i],
                            data_ov001_021a99e4->mUnk_000c[i], 0, 0);
    }
    InitEmblemChoises();
}

void func_ov001_021805f4(void) {
    func_020364e8();
    func_020ca6b8();
    *(u32 *) &data_ov001_021a99e4 = 0;
}

#pragma thumb off

u32 func_ov001_021805ec(void) {
    return 0x8u;
}

u16 func_ov001_021805d8(Unk02175628 *p0, u32 p1) {
    return p0->mUnk_00 & p1;
}

u32 func_ov001_021805bc(u32 p0, u32 p1) {
    return func_ov001_021805d8(&data_02175628[p0], p1);
}

#pragma thumb on

void func_ov001_0218052c(Unk0218052c *p0) {
    u32 v;
    Unk021a99e4 *g;

    func_ov001_021805ec();
    func_020ae718();
    if (p0 != NULL) {
        v = func_ov001_021805ec();
        if (func_ov001_021805bc(v, 1) != 0) {
            p0->mUnk_04 = 0;
        }
        if (func_ov001_021805bc(v, 0x400) != 0) {
            g = data_ov001_021a99e4;
            g->mUnk_0004 = (g->mUnk_0004 + 1) % 4;
            data_ov001_021a99e4->mUnk_0008 = 1;
            if (data_ov001_021a99e4->mUnk_0004 == 1) {
                func_020ca688(0);
            }
        }
    }
    switch (data_ov001_021a99e4->mUnk_0004) {
        case 0:
            func_020ca844();
            func_020ca83c();
            break;
        case 1:
        case 2:
        case 3:
            break;
    }
}

void func_ov001_02180524(void) {
    func_ov001_02180610();
}

void func_ov001_0218051c(void) {
    func_ov001_021805f4();
}

void func_ov001_02180514(void) {
    func_ov001_02180800();
}

void func_ov001_0218050c(Unk0218052c *p0) {
    func_ov001_0218052c(p0);
}

int func_ov001_021804e0(void *p0) {
    Unk021a9034 v = {
        func_ov001_02180524, func_ov001_0218050c, func_ov001_0218051c, func_ov001_02180514, 0, 0, 0x1e, 0x1e, 0};

    func_020487fc(p0, &v);
    return 0;
}
