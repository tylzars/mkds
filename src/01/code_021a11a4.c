#include "01/code_021a11a4.h"

#include "types.h"
#include "01/unk_021ca000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "01/code_021a6430.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_021a1000.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "registers.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02116000.h"
#include "00/code_02181f98.h"
#include "01/code_02185000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02029440.h"

void func_ov001_021a1f60(void) {
    Ncgr *l0 = NULL;
    Unk02021dc8 *l1 = NULL;
    Nclr *l2 = NULL;
    Ncgr *l3 = NULL;
    Unk02021dc8 *l4 = NULL;
    Nclr *l5 = NULL;
    Ncgr *l6 = NULL;
    Nscr *l7 = NULL;
    Nclr *l8 = NULL;

    LoadNcgrData(&l6, FindSceneFile(data_ov001_021a94ec));
    LoadNclrData(&l8, FindSceneFile(data_ov001_021a9508));
    LoadNscrData(&l7, FindSceneFile(data_ov001_021a94f0));
    LoadNcgrData2(&l0, FindSceneFile(data_ov001_021a94dc));
    LoadNcerData(&l1, FindSceneFile(data_ov001_021a94e4));
    LoadNclrData(&l2, FindSceneFile(data_ov001_021a950c));
    LoadNcgrData2(&l3, FindSceneFile(data_ov001_021a94f4));
    LoadNcerData(&l4, FindSceneFile(data_ov001_021a94f8));
    LoadNclrData(&l5, FindSceneFile(data_ov001_021a94fc));
}

void func_ov001_021a1d78(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Ncgr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    u16 *h;

    LocateNcgr(&e, FindSceneFile(data_ov001_021a94ec));
    LocateNclr(&g, FindSceneFile(data_ov001_021a9508));
    LocateNscr(&f, FindSceneFile(data_ov001_021a94f0));
    data_ov001_021ca418->mUnk_1c = HeapAlloc(data_ov001_021ca418->mHeap, 0x800);
    data_ov001_021ca418->mUnk_04 = FindSceneFile(data_ov001_021a9504);
    LocateNcgr2(&a, FindSceneFile(data_ov001_021a94dc));
    LocateNcer(&data_ov001_021ca418->mUnk_00, FindSceneFile(data_ov001_021a94e4));
    LocateNclr(&b, FindSceneFile(data_ov001_021a950c));
    LocateNcgr2(&c, FindSceneFile(data_ov001_021a94f4));
    LocateNcer(&data_ov001_021ca418->mUnk_08, FindSceneFile(data_ov001_021a94f8));
    LocateNclr(&d, FindSceneFile(data_ov001_021a94fc));
    if (func_02056dec(0x10) != 0) {
        data_ov001_021ca418->mUnk_0c = FindSceneFile(data_ov001_021a94e8);
        data_ov001_021ca418->mUnk_10 = FindSceneFile(data_ov001_021a9510);
    } else {
        data_ov001_021ca418->mUnk_0c = FindSceneFile(data_ov001_021a9500);
        data_ov001_021ca418->mUnk_10 = FindSceneFile(data_ov001_021a94e0);
    }
    h = b->mData;
    CallQueueAppend(4, 0, e->mData, e->mDataSize);
    CallQueueAppend(0xf, 0, g->mData, 0x100);
    CallQueueAppend(8, 0, f->mData, f->mDataSize);
    CallQueueAppend(8, 0x800, data_ov001_021ca418->mUnk_1c, 0x800);
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, (u8 *) h + 0x1c0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

void func_ov001_021a1cb0(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
        for (j = 0; j < 3; j++) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_00 = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_00 = 1;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_00 = 1;
    data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[data_ov001_021ca418->mUnk_34]].mUnk_00 = 1;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][0]].mUnk_00 = 1;
        func_02124a98(data_ov001_021a6fa0[i][0], 1, data_ov001_021ca418->mUnk_08, data_ov001_021ca418->mUnk_0c);
    }
    func_02124a98(2, 1, data_ov001_021ca418->mUnk_00, data_ov001_021ca418->mUnk_04);
}

void func_ov001_021a1c34(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 0;
        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 0;
        if (data_ov001_021ca418->mUnk_34 == i && data_ov001_021ca418->mUnk_38 != 0) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][2]].mUnk_00 = 1;
        } else {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][1]].mUnk_00 = 1;
        }
    }
    if (func_02056dec(0x10) == 0) {
        for (i = 0; i < 3; i++) {
            data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[3][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_021a1bf8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_00 = 0;
    }
    data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[data_ov001_021ca418->mUnk_34]].mUnk_00 = 1;
}

void func_ov001_021a1bb8(void) {
    if (data_ov001_021ca418->mUnk_34 == 3) {
        func_020295c0(data_ov001_021a6f90[2]);
        func_020295b0();
    } else {
        func_020295c0(data_ov001_021a6f90[data_ov001_021ca418->mUnk_34]);
        func_020295a0();
    }
    func_02029590(0);
}

u32 func_ov001_021a1ba0(void) {
    if (data_ov001_021ca418->mUnk_3c != 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021a1b08(void) {
    s32 i;
    s16 v;

    if (func_ov001_021a1ba0() != 0) {
        if (data_ov001_021ca418->mUnk_3c == 7) {
            data_ov001_021ca418->mUnk_40 = data_ov001_021ca418->mUnk_34;
            func_ov001_021a1bf8();
        } else {
            v = func_02116d10(7 - data_ov001_021ca418->mUnk_3c, 0);
            for (i = 0; i < 6; i++) {
                data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = v;
            }
            for (i = 0; i < 4; i++) {
                data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = v;
            }
        }
        data_ov001_021ca418->mUnk_3c -= 1;
    } else if (data_ov001_021ca418->mUnk_34 != data_ov001_021ca418->mUnk_40) {
        data_ov001_021ca418->mUnk_3c = 7;
    }
}

void func_ov001_021a1a04(void) {
    s32 i;
    s32 j;

    data_ov001_021ca418->mUnk_28 = 0;
    data_ov001_021ca418->mUnk_2c = 0;
    data_ov001_021ca418->mUnk_30 = 0xc0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = 0xc0;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = -0xc0;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = 0xc0;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = -0xe0;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void func_ov001_021a19f0(void) {
    data_ov001_021ca418->mUnk_28 = 1;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a19dc(void) {
    data_ov001_021ca418->mUnk_28 = 2;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a19c0(void) {
    data_ov001_021ca418->mUnk_28 = 3;
    data_ov001_021ca418->mUnk_2c = 0;
    func_02128374();
}

void func_ov001_021a19ac(void) {
    data_ov001_021ca418->mUnk_28 = 4;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a1978(void) {
    data_ov001_021ca418->mUnk_28 = 5;
    data_ov001_021ca418->mUnk_2c = 0;
    data_ov001_021ca418->mUnk_4c = 1;
    func_ov001_021a1bb8();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021a1964(void) {
    data_ov001_021ca418->mUnk_28 = 6;
    data_ov001_021ca418->mUnk_2c = 0;
}

void func_ov001_021a1858(s32 a, void *b, void *c) {
    void *heap;
    Unk021ca418 *p;
    vu16 *bg0 = (vu16 *) 0x4000008;
    vu16 *bg1 = (vu16 *) 0x400000a;

    *bg0 = (*bg0 & ~3) | 1;
    *bg1 = (*bg1 & ~3) | 1;
    *bg0 = (*bg0 & 0x43) | 0x9004;
    *bg1 = (*bg1 & 0x43) | 0x9204;
    *(vu32 *) 0x4000010 = 0xc00000;
    *(vu32 *) 0x4000014 = 0xc00000;
    heap = CreateFrmHeapFromMaxFree((void *) a);
    p = HeapAlloc(heap, 0x50);
    data_ov001_021ca418 = p;
    p->mHeap = heap;
    data_ov001_021ca418->mUnk_24 = 0;
    data_ov001_021ca418->mUnk_3c = 0;
    data_ov001_021ca418->mUnk_38 = 1;
    data_ov001_021ca418->mUnk_44 = b;
    data_ov001_021ca418->mUnk_48 = c;
    data_ov001_021ca418->mUnk_4c = 0;
    if (func_0202967c() != 0) {
        data_ov001_021ca418->mUnk_34 = 3;
    } else {
        data_ov001_021ca418->mUnk_34 = data_ov001_021a6f74[func_0202969c()];
    }
    data_ov001_021ca418->mUnk_40 = data_ov001_021ca418->mUnk_34;
    func_ov001_021a1d78();
    func_020ae6d4(data_ov001_021ca418->mUnk_44, data_ov001_021ca418->mUnk_48);
    func_02124ed0(data_ov001_021ca418->mHeap, data_ov001_021ca418->mUnk_04, NULL, &data_ov001_021ca418->mUnk_14);
    func_02124ed0(data_ov001_021ca418->mHeap, data_ov001_021ca418->mUnk_0c, NULL, &data_ov001_021ca418->mUnk_18);
    func_ov001_021a1cb0();
    func_ov001_021a1bf8();
    func_ov001_021a1a04();
    FrmHeapShrinkInParent((void *) data_ov001_021ca418->mHeap);
}

void func_ov001_021a1838(void) {
    HeapDestroy((void *) data_ov001_021ca418->mHeap);
    data_ov001_021ca418 = NULL;
}

void func_ov001_021a1820(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_ov001_021a19f0();
    }
    return;
}

void func_ov001_021a16e4(void) {
    s16 a;
    s16 b;
    s32 j;
    s32 i;
    data_ov001_021ca418->mUnk_2c = data_ov001_021ca418->mUnk_2c + 1;
    a = func_020ae4c0(1, 0xe0, 0, data_ov001_021ca418->mUnk_2c, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_ov001_021ca418->mUnk_2c, 10);
    data_ov001_021ca418->mUnk_30 = -b;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = -b;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = b;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = -b;
        if (func_02056dec(0x10)) {
            switch (i) {
                case 0:
                case 2:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (j = 0; j < 3; j++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = a;
                    }
                    break;
            }
        } else {
            for (j = 0; j < 3; j++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][j]].mUnk_04 = a;
            }
        }
    }
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        func_ov001_021a19dc();
    }
}

void func_ov001_021a1674(void) {
    s16 x;
    s32 j;
    data_ov001_021ca418->mUnk_2c = data_ov001_021ca418->mUnk_2c + 1;
    x = func_020ae488(data_ov001_021ca418->mUnk_2c);
    data_ov001_021ca418->mUnk_30 = x;
    for (j = 0; j < 6; j++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[j]].mUnk_06 = x;
    }
    for (j = 0; j < 4; j++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[j]].mUnk_06 = x;
    }
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        func_ov001_021a19c0();
    }
}

void func_ov001_021a165c(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        func_ov001_021a19ac();
    }
    return;
}

void func_ov001_021a13d8(void) {
    u32 r5 = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    BOOL b1;
    s32 a1;
    BOOL b2;
    s32 a2;
    u32 v;
    u32 w;
    s32 t;
    s32 s;
    Unk021ca418 *o;

    func_ov001_021a1b08();
    a1 = b1 = FALSE;
    v = data_02175628[idx].mHasPair;
    if (v == 0 && data_02175628[idx].mNoPairCount < 5) {
        a1 = 1;
    }
    if (a1 == 0 && data_02175628[idx].mPrevHasPair == 0 && v != 0) {
        b1 = TRUE;
    }
    if (b1 != FALSE) {
        r5 = RectTableFindContaining(data_ov001_021ca418->mUnk_10, data_02175628[idx].mUnk_48,
                                     data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        a2 = b2 = FALSE;
        w = data_02175628[idx].mHasPair;
        if (w == 0 && data_02175628[idx].mNoPairCount < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[idx].mPrevHasPair == 0 && w != 0) {
            b2 = TRUE;
        }
        if (b2 == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mUnk_48,
                                                                           data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    if (func_ov001_021a1ba0() != 0) {
        return;
    }
    func_021281c8(0xe);
    func_ov001_021a1964();
    data_ov001_021ca418->mUnk_4c = 2;
    func_02128310(0);
    return;
next:
    if (r5 <= 3) {
        s = data_ov001_021a6f80[r5];
        if (data_ov001_021ca418->mUnk_34 == s) {
            data_ov001_021ca418->mUnk_38 = 0;
        }
        data_ov001_021ca418->mUnk_34 = s;
        func_ov001_021a1978();
        return;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0) {
        data_ov001_021ca418->mUnk_38 = 0;
        func_ov001_021a1978();
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f20[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f40[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f30[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f48[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f38[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f50[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (func_02056dec(0x10) != 0) {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f60[t];
        } else {
            t = data_ov001_021ca418->mUnk_34;
            o = data_ov001_021ca418;
            s = data_ov001_021a6f58[t];
        }
        if (s != 0) {
            o->mUnk_34 = t + s;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void func_ov001_021a1398(void) {
    func_ov001_021a1b08();
    if (data_ov001_021ca418->mUnk_2c == 5) {
        data_ov001_021ca418->mUnk_38 = 1;
    }
    data_ov001_021ca418->mUnk_2c++;
    if (data_ov001_021ca418->mUnk_2c >= 10) {
        if (func_ov001_021a1ba0() == 0) {
            func_ov001_021a1964();
        }
    }
}

void func_ov001_021a126c(void) {
    s16 a;
    s16 b;
    s32 i;
    s32 k;

    data_ov001_021ca418->mUnk_2c++;
    a = func_020ae4c0(1, 0, 0xc0, data_ov001_021ca418->mUnk_2c, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_ov001_021ca418->mUnk_2c, 10);
    data_ov001_021ca418->mUnk_30 = -b;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f68[i]].mUnk_06 = -b;
    }
    data_ov001_021ca418->mUnk_14[6].mUnk_06 = b;
    for (i = 0; i < 4; i++) {
        data_ov001_021ca418->mUnk_14[data_ov001_021a6f28[i]].mUnk_06 = -b;
        if (func_02056dec(0x10) != 0) {
            switch (i) {
                case 0:
                case 2:
                    for (k = 0; k < 3; k++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = -a;
                    }
                    break;
                case 1:
                case 3:
                    for (k = 0; k < 3; k++) {
                        data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
                    }
                    break;
            }
        } else {
            for (k = 0; k < 3; k++) {
                data_ov001_021ca418->mUnk_18[data_ov001_021a6fa0[i][k]].mUnk_04 = a;
            }
        }
    }
}

int func_ov001_021a11c4(void) {
    data_ov001_021ca418->mUnk_24 = data_ov001_021ca418->mUnk_28;
    switch (data_ov001_021ca418->mUnk_24) {
        case 0:
            func_ov001_021a1820();
            break;
        case 1:
            func_ov001_021a16e4();
            break;
        case 2:
            func_ov001_021a1674();
            break;
        case 3:
            func_ov001_021a165c();
            break;
        case 4:
            func_ov001_021a13d8();
            break;
        case 5:
            func_ov001_021a1398();
            break;
        case 6:
            func_ov001_021a126c();
            break;
    }
    func_ov001_021a1c34();
    func_02124c30(data_ov001_021ca418->mUnk_04, data_ov001_021ca418->mUnk_00, NULL, data_ov001_021ca418->mUnk_44,
                  data_ov001_021ca418->mUnk_14);
    func_02124c30(data_ov001_021ca418->mUnk_0c, data_ov001_021ca418->mUnk_08, NULL, data_ov001_021ca418->mUnk_48,
                  data_ov001_021ca418->mUnk_18);
    if (data_ov001_021ca418->mUnk_24 == 6 && data_ov001_021ca418->mUnk_2c >= 10) {
        return data_ov001_021ca418->mUnk_4c;
    }
    return 0;
}

void func_ov001_021a11a4(void) {
    reg_G2_BG0OFS = (-data_ov001_021ca418->mUnk_30 << 16) & 0x01ff0000;
}
