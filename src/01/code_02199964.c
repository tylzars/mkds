#include "01/code_02199964.h"
#include "01/unk_021a6000.h"
#include "01/code_02198854.h"
#include "01/code_0219853c.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/code_0219e824.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02108000.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"

Unk021a9bec *data_ov001_021a9bec;

void func_ov001_02199f44(void *heap) {
    s32 i;
    s32 j;
    void *a;
    data_ov001_021a9bec = HeapAlloc(heap, 0x34);
    data_ov001_021a9bec->mUnk_18 = heap;
    data_ov001_021a9bec->mUnk_00 = 0;
    data_ov001_021a9bec->mUnk_04 = 0;
    switch (GetOptionPrevState()) {
        case 0:
        case 5:
            data_ov001_021a9bec->mUnk_08 = 0;
            break;
        case 3:
        case 6:
            data_ov001_021a9bec->mUnk_08 = 1;
            break;
    }
    data_ov001_021a9bec->mUnk_0c = 0;
    data_ov001_021a9bec->mUnk_14 = 1;
    func_ov001_02199e3c();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6a84[i], 1, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
    }
    a = func_ov001_0219e920();
    func_020ae6d4(a, func_ov001_0219e90c());
    func_02124ed0(heap, data_ov001_021a9bec->mUnk_2c, NULL, &data_ov001_021a9bec->mUnk_1c);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = 0xfa;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -0xfa;
            }
        }
    }
    func_021281c8(0xe);
}

void func_ov001_02199f38(void) {
    data_ov001_021a9bec = NULL;
}

void func_ov001_02199e3c(void) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;

    LocateNcgr(&a, FindSceneFile(data_ov001_021a866c));
    LocateNscr(&b, FindSceneFile(data_ov001_021a8688));
    LocateNclr(&c, FindSceneFile(data_ov001_021a86a0));
    data_ov001_021a9bec->mUnk_2c = FindSceneFile(data_ov001_021a86bc);
    data_ov001_021a9bec->mUnk_30 = FindSceneFile(data_ov001_021a86d8);
    LocateNcgr2(&data_ov001_021a9bec->mUnk_24, FindSceneFile(data_ov001_021a86f4));
    LocateNcer(&data_ov001_021a9bec->mUnk_20, FindSceneFile(data_ov001_021a8714));
    LocateNclr(&data_ov001_021a9bec->mUnk_28, FindSceneFile(data_ov001_021a8734));
    CallQueueAppend(4, 0, a->mData, a->mDataSize);
    CallQueueAppend(8, 0, b->mData, b->mDataSize);
    CallQueueAppend(15, 0, c->mData, 0x100);
    CallQueueAppend(0x23, 0, data_ov001_021a9bec->mUnk_24->mData, data_ov001_021a9bec->mUnk_24->mDataSize);
    CallQueueAppend(0x1e, 0, data_ov001_021a9bec->mUnk_28->mData, data_ov001_021a9bec->mUnk_28->mDataSize);
}

void func_ov001_02199e1c(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov001_021a9bec->mUnk_04 = 1;
    }
    return;
}

void func_ov001_02199d88(void) {
    s32 i;
    s32 j;
    s32 v;
    data_ov001_021a9bec->mUnk_0c++;
    v = func_020ae4c0(1, 0xfa, 0, data_ov001_021a9bec->mUnk_0c, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = v;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -v;
            }
        }
    }
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        data_ov001_021a9bec->mUnk_04 = 2;
        data_ov001_021a9bec->mUnk_0c = 0;
        func_02128374();
    }
}

void func_ov001_02199d68(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        data_ov001_021a9bec->mUnk_04 = 3;
    }
    return;
}

void func_ov001_02199bb0(void) {
    u32 r;
    BOOL b;
    BOOL a;
    u16 v;
    s32 oldv;
    Unk021a9bec *p;
    Unk02175628Index i;

    i = UNK_02175628_INDEX_8;
    r = -1;
    b = FALSE;
    a = FALSE;
    v = data_02175628[i].mHasPair;
    if (v == 0 && data_02175628[i].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && data_02175628[i].mPrevHasPair == 0 && v != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        r = RectTableFindContaining(data_ov001_021a9bec->mUnk_30, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        b = FALSE;
        a = FALSE;
        v = data_02175628[i].mHasPair;
        if (v == 0 && data_02175628[i].mNoPairCount < 5) {
            a = TRUE;
        }
        if (a == FALSE && data_02175628[i].mPrevHasPair == 0 && v != 0) {
            b = TRUE;
        }
        if (b != FALSE &&
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) != 0) {
            goto leave;
        }
    } else {
    leave:
        data_ov001_021a9bec->mUnk_04 = 5;
        data_ov001_021a9bec->mUnk_10 = 0;
        func_02128310(0);
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 1) != 0 || r <= 1) {
        p = data_ov001_021a9bec;
        oldv = p->mUnk_08;
        if ((u16) (data_02175628[i].mUnk_00 & 1) == 0) {
            switch (r) {
                case 0:
                    p->mUnk_08 = 0;
                    break;
                case 1:
                    p->mUnk_08 = 1;
                    break;
            }
        }
        data_ov001_021a9bec->mUnk_04 = 4;
        p = data_ov001_021a9bec;
        switch (p->mUnk_08) {
            case 0:
                p->mUnk_10 = 5;
                break;
            case 1:
                if (data_0217aa08->mUnk_04->mUnk_004 != 0) {
                    p->mUnk_10 = 3;
                } else {
                    p->mUnk_10 = 6;
                    data_0217b488->mUnk_18 = 0;
                }
                break;
        }
        if (data_ov001_021a9bec->mUnk_08 == oldv) {
            data_ov001_021a9bec->mUnk_14 = 0;
        }
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (data_ov001_021a9bec->mUnk_08 > 0) {
            data_ov001_021a9bec->mUnk_08--;
            func_02105ac0(0);
            return;
        }
    }
    if (func_020ae408(8, 0x80) != 0) {
        if (data_ov001_021a9bec->mUnk_08 < 1) {
            data_ov001_021a9bec->mUnk_08++;
            func_02105ac0(0);
        }
    }
}

void func_ov001_02199b6c(void) {
    data_ov001_021a9bec->mUnk_0c++;
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        data_ov001_021a9bec->mUnk_04 = 5;
        data_ov001_021a9bec->mUnk_0c = 0;
        if (data_ov001_021a9bec->mUnk_10 == 5) {
            func_021282c8();
        }
    } else if (data_ov001_021a9bec->mUnk_0c >= 5) {
        data_ov001_021a9bec->mUnk_14 = 1;
    }
}

void func_ov001_02199a8c(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov001_02192e84() == -1) {
        if (data_ov001_021a9bec->mUnk_10 == 5) {
            func_ov001_02192e78(0xe);
        } else if (data_ov001_021a9bec->mUnk_10 == 6) {
            func_ov001_02192e78(3);
        }
    }
    data_ov001_021a9bec->mUnk_0c++;
    if (data_ov001_021a9bec->mUnk_0c <= 10) {
        v = func_020ae4c0(1, 0, 0xfa, data_ov001_021a9bec->mUnk_0c, 10);
    } else {
        v = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = v;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -v;
            }
        }
    }
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        if (data_ov001_021a9bec->mUnk_10 == 0 || data_ov001_021a9bec->mUnk_10 == 3 ||
            IsSelectReturnState0NoState1Request() != 0) {
            if (func_ov001_02192e84() == -1) {
                RequestOptionState(data_ov001_021a9bec->mUnk_10);
            }
        }
    }
}

void func_ov001_02199a20(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (i == data_ov001_021a9bec->mUnk_08 && data_ov001_021a9bec->mUnk_14 != 0) {
            data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a88[i]].mUnk_00 = 1;
            func_02124a20(data_ov001_021a6a80[i], 0xe, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
        } else {
            data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a88[i]].mUnk_00 = 0;
            func_02124a20(data_ov001_021a6a80[i], 0xf, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
        }
    }
}

void func_ov001_021999a8(void) {
    Unk021a9bec *p;
    data_ov001_021a9bec->mUnk_00 = data_ov001_021a9bec->mUnk_04;
    switch (data_ov001_021a9bec->mUnk_00) {
        case 0:
            func_ov001_02199e1c();
            break;
        case 1:
            func_ov001_02199d88();
            break;
        case 2:
            func_ov001_02199d68();
            break;
        case 3:
            func_ov001_02199bb0();
            break;
        case 4:
            func_ov001_02199b6c();
            break;
        case 5:
            func_ov001_02199a8c();
            break;
    }
    func_ov001_02199a20();
    p = data_ov001_021a9bec;
    func_02124c30(p->mUnk_2c, p->mUnk_20, NULL, func_ov001_0219e90c(), p->mUnk_1c);
}

void func_ov001_02199988(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), 0, 2, 6, 10);
    return;
}

void func_ov001_02199964(void) {
    UnkFunc *tbl[4] = {func_ov001_02199f44, func_ov001_02199f38, func_ov001_021999a8, func_ov001_02199988};
    SetOptionStateCallbacks((UnkFunc **) (tbl));
}
