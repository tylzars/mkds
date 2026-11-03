#include "01/code_ov001_02197b34.h"

#include "01/code_021956dc.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/code_02198000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02116000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov001_021984ac(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Nclr *e = NULL;
    Nscr *f = NULL;

    LoadNcgrData(&d, FindSceneFile(data_ov001_021a835c));
    LoadNclrData(&e, FindSceneFile(data_ov001_021a8360));
    LoadNscrData(&f, FindSceneFile(data_ov001_021a8354));
    LoadNcgrData2(&a, FindSceneFile(data_ov001_021a8350));
    LoadNcerData(&b, FindSceneFile(data_ov001_021a834c));
    LoadNclrData(&c, FindSceneFile(data_ov001_021a8364));
}

void func_ov001_02198384(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Nscr *e = NULL;

    LocateNcgr(&c, FindSceneFile(data_ov001_021a835c));
    LocateNclr(&d, FindSceneFile(data_ov001_021a8360));
    LocateNscr(&e, FindSceneFile(data_ov001_021a8354));
    data_ov001_021a9be0->mUnk_10 = func_02036bec(data_ov001_021a9be0->mUnk_14, 0x800);
    data_ov001_021a9be0->mUnk_04 = FindSceneFile(data_ov001_021a8358);
    data_ov001_021a9be0->mUnk_08 = FindSceneFile(data_ov001_021a8348);
    LocateNcgr2(&a, FindSceneFile(data_ov001_021a8350));
    LocateNcer(&data_ov001_021a9be0->mUnk_00, FindSceneFile(data_ov001_021a834c));
    LocateNclr(&b, FindSceneFile(data_ov001_021a8364));
    func_02016468(4, 0, c->mData, c->mDataSize);
    func_02016468(0xf, 0, d->mData, 0x20);
    func_02016468(8, 0, &e->mData, e->mDataSize);
    func_02016468(8, 0x800, data_ov001_021a9be0->mUnk_10, 0x800);
    func_02016468(0x23, 0, a->mData, a->mDataSize);
    func_02016468(0x1e, 0, b->mData, b->mDataSize);
}

void func_ov001_02198368(void) {
    data_ov001_021a9be0->mUnk_1c = 0;
    data_ov001_021a9be0->mUnk_20 = 0;
    data_ov001_021a9be0->mUnk_24 = -192;
}

void func_ov001_02198354(void) {
    data_ov001_021a9be0->mUnk_1c = 1;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_02198338(void) {
    data_ov001_021a9be0->mUnk_1c = 2;
    data_ov001_021a9be0->mUnk_20 = 0;
    func_02128374();
}

void func_ov001_02198324(void) {
    data_ov001_021a9be0->mUnk_1c = 3;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_021982e8(void) {
    data_ov001_021a9be0->mUnk_1c = 4;
    data_ov001_021a9be0->mUnk_20 = 0;
    switch (data_ov001_021a9be0->mUnk_28) {
        case 1:
        case 2:
            func_021282c8();
            break;
    }
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_021982d4(void) {
    data_ov001_021a9be0->mUnk_1c = 5;
    data_ov001_021a9be0->mUnk_20 = 0;
}

void func_ov001_0219829c(s32 a) {
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6a18[a], 0xe, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
}

void func_ov001_02198264(s32 a) {
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6a18[a], 0xf, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
}

void func_ov001_02198100(void *a, void *b, s32 c) {
    void *heap;
    s32 i;

    *(u16 *) 0x4000008 = (*(u16 *) 0x4000008 & 0x43) | 0x9004;
    heap = func_02036948(a);
    data_ov001_021a9be0 = func_02036bec(heap, 0x38);
    data_ov001_021a9be0->mUnk_14 = heap;
    data_ov001_021a9be0->mUnk_18 = 0;
    data_ov001_021a9be0->mUnk_2c = b;
    data_ov001_021a9be0->mUnk_30 = c;
    data_ov001_021a9be0->mUnk_34 = 0;
    func_ov001_02198368();
    if (func_020cccb4() == 0x1f) {
        if (data_0217b488->mUnk_0c == 0) {
            data_ov001_021a9be0->mUnk_28 = 1;
        } else {
            data_ov001_021a9be0->mUnk_28 = 2;
        }
    } else {
        data_ov001_021a9be0->mUnk_28 = 0;
    }
    func_ov001_02198384();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6a10[i], 1, data_ov001_021a9be0->mUnk_00, data_ov001_021a9be0->mUnk_04);
    }
    func_020ae6d4(data_ov001_021a9be0->mUnk_2c, (void *) data_ov001_021a9be0->mUnk_30);
    func_02124ed0(data_ov001_021a9be0->mUnk_14, data_ov001_021a9be0->mUnk_04, NULL, &data_ov001_021a9be0->mUnk_0c);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = 0xe0;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = 0xe0;
        func_ov001_02198264(i);
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = 0xe0;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = 0xe0;
    func_ov001_0219829c(data_ov001_021a9be0->mUnk_28);
    func_02036820(data_ov001_021a9be0->mUnk_14);
}

void func_ov001_021980e0(void) {
    func_02036ab0(data_ov001_021a9be0->mUnk_14);
    data_ov001_021a9be0 = NULL;
}

void func_ov001_02198014(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9be0->mUnk_20, 10);
    data_ov001_021a9be0->mUnk_24 = func_020ae4c0(1, -192, 0, data_ov001_021a9be0->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_02198354();
    }
}

void func_ov001_02197f6c(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae488(data_ov001_021a9be0->mUnk_20);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_02198338();
    }
}

void func_ov001_02197f54(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        func_ov001_02198324();
    }
}

void func_ov001_02197d58(void) {
    BOOL flag2 = FALSE;
    u32 sel = -1;
    s32 dir = 3;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    BOOL flag1 = FALSE;
    Unk02175628 *e;
    s32 bits;
    BOOL flag4;
    s32 flag3;

    if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
        flag1 = TRUE;
    }
    if (flag1 == FALSE && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
        flag2 = TRUE;
    }
    if (flag2 != FALSE) {
        sel = func_0201ea84(data_ov001_021a9be0->mUnk_08, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    e = &data_02175628[i];
    bits = e->mUnk_00 & 2;
    if ((u16) bits == 0) {
        flag3 = flag4 = FALSE;
        if (data_02175628[i].mHasPair == 0 && data_02175628[i].mNoPairCount < 5) {
            flag3 = 1;
        }
        if (flag3 == 0 && data_02175628[i].mPrevHasPair == 0 && data_02175628[i].mHasPair != 0) {
            flag4 = TRUE;
        }
        if (flag4 == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(0xe);
    func_ov001_021982d4();
    data_ov001_021a9be0->mUnk_34 = 4;
    func_02128310(0);
    return;
next:
    bits = e->mUnk_00 & 1;
    if ((u16) bits != 0 || sel <= 2) {
        if ((u16) bits == 0) {
            func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
            switch (sel) {
                case 0:
                    dir = 0;
                    break;
                case 1:
                    dir = 1;
                    break;
                case 2:
                    dir = 2;
                    break;
            }
            if (data_ov001_021a9be0->mUnk_28 != dir) {
                data_ov001_021a9be0->mUnk_28 = dir;
                func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
            }
        } else {
            func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
        }
        switch (data_ov001_021a9be0->mUnk_28) {
            case 0:
                data_ov001_021a9be0->mUnk_34 = 1;
                break;
            case 1:
                data_ov001_021a9be0->mUnk_34 = 2;
                break;
            case 2:
                data_ov001_021a9be0->mUnk_34 = 3;
                break;
        }
        func_ov001_021982e8();
    } else {
        if (func_020ae408(8, 0x40) != 0) {
            func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
            data_ov001_021a9be0->mUnk_28--;
            if (data_ov001_021a9be0->mUnk_28 < 0) {
                data_ov001_021a9be0->mUnk_28 = 2;
            }
            func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
            func_0212ecc0(&data_0217d068, 0, 0);
        } else if (func_020ae408(8, 0x80) != 0) {
            func_ov001_02198264((s32) (data_ov001_021a9be0->mUnk_28));
            data_ov001_021a9be0->mUnk_28++;
            if (data_ov001_021a9be0->mUnk_28 >= 3) {
                data_ov001_021a9be0->mUnk_28 = 0;
            }
            func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void func_ov001_02197c9c(void) {
    s16 v;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae488(data_ov001_021a9be0->mUnk_20);
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[data_ov001_021a9be0->mUnk_28]].mUnk_04 = v;
    switch (data_ov001_021a9be0->mUnk_28) {
        case 1:
            data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
            break;
        case 2:
            data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
            break;
    }
    if (data_ov001_021a9be0->mUnk_20 == 5) {
        func_ov001_0219829c((s32) (data_ov001_021a9be0->mUnk_28));
    }
    if (data_ov001_021a9be0->mUnk_20 >= 10) {
        func_ov001_021982d4();
    }
}

void func_ov001_02197bdc(void) {
    s16 v;
    s32 i;

    data_ov001_021a9be0->mUnk_20++;
    v = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9be0->mUnk_20, 10);
    data_ov001_021a9be0->mUnk_24 = func_020ae4c0(1, 0, -192, data_ov001_021a9be0->mUnk_20, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a08[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a10[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a00[i]].mUnk_04 = v;
        data_ov001_021a9be0->mUnk_0c[data_ov001_021a6a18[i]].mUnk_04 = v;
    }
    data_ov001_021a9be0->mUnk_0c[12].mUnk_04 = v;
    data_ov001_021a9be0->mUnk_0c[13].mUnk_04 = v;
}

s32 func_ov001_02197b54(void) {
    data_ov001_021a9be0->mUnk_18 = data_ov001_021a9be0->mUnk_1c;
    switch (data_ov001_021a9be0->mUnk_18) {
        case 0:
            func_ov001_02198014();
            break;
        case 1:
            func_ov001_02197f6c();
            break;
        case 2:
            func_ov001_02197f54();
            break;
        case 3:
            func_ov001_02197d58();
            break;
        case 4:
            func_ov001_02197c9c();
            break;
        case 5:
            func_ov001_02197bdc();
            break;
    }
    func_02124c30(data_ov001_021a9be0->mUnk_04, data_ov001_021a9be0->mUnk_00, NULL,
                  (void *) data_ov001_021a9be0->mUnk_30, data_ov001_021a9be0->mUnk_0c);
    if (data_ov001_021a9be0->mUnk_18 == 5 && data_ov001_021a9be0->mUnk_20 >= 10) {
        return data_ov001_021a9be0->mUnk_34;
    }
    return 0;
}

void func_ov001_02197b34(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021a9be0->mUnk_24 << 16) & 0x1ff0000;
}
