#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02119a90.h"
#include "Main/Unknown/code_021189f4.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211952c.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "registers.h"

#pragma thumb on
static inline s32 func_02119340_inline(Unk02175628Index i) {
    BOOL g;
    BOOL f;
    u16 v;

    g = FALSE;
    f = FALSE;
    v = data_02175674[i].mUnk_00;
    if (v == 0 && data_02175680[i].mUnk_00 < 5) {
        f = TRUE;
    }
    if (f == FALSE && data_0217567c[i].mUnk_00 == 0 && v != 0) {
        g = TRUE;
    }
    return g;
}

void AdvanceSelectCupState3(void) {
    s32 a;
    Unk02175628Index i;
    s16 w;

    a = -1;
    i = UNK_02175628_INDEX_8;
    func_02119d78();
    if (func_02119340_inline(i) != 0) {
        a = RectTableFindContaining(gSelectCup->mUnk_14, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00 + 0x20);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) != 0 ||
        (func_02119340_inline(i) != 0 &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) != 0)) {
        if (func_02119dfc() == 0) {
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_021281c8(-1);
            } else {
                func_021281c8(0xe);
            }
            func_021199f8();
            gSelectCup->mResult = 2;
            func_02128310(0);
        }
        return;
    }
    if ((u32) a <= 3) {
        w = data_0215caac[a];
        if (gSelectCup->mIndex == w) {
            gSelectCup->mUnk_54 = 0;
        }
        gSelectCup->mIndex = w;
        func_02119ba8();
        return;
    }
    if (a == 4) {
        func_02119ba8();
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
        func_02119ba8();
        gSelectCup->mUnk_54 = 0;
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        gSelectCup->mIndex = gSelectCup->mIndex - 1;
        if (gSelectCup->mIndex < 0) {
            gSelectCup->mIndex = 3;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            func_0212ecc0(&data_0217d068, 0, 0);
        }
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        gSelectCup->mIndex = gSelectCup->mIndex + 1;
        if (gSelectCup->mIndex >= 4) {
            gSelectCup->mIndex = 0;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceSelectCupState4(void) {
    func_02119d78();
    if (gSelectCup->mStateFrames == 5) {
        gSelectCup->mUnk_54 = 1;
    }
    gSelectCup->mStateFrames++;
    if (gSelectCup->mStateFrames >= 10) {
        if (func_02119dfc() == 0) {
            if (gSelectCup->mMode == 0) {
                func_02119e14();
                if (func_0211e130() != 0) {
                    func_0211e0c4(0);
                    func_02119ac4();
                    return;
                }
                func_02119e50();
                gSelectCup->mResult = 1;
                func_021199f8();
                return;
            }
            func_02119ac4();
        }
    }
}

void AdvanceSelectCupState5(void) {
    switch (gSelectCup->mMode) {
        case 0:
        case 1:
        case 3:
            if (func_021277c8() != 0) {
                func_02119a90();
            }
            break;
        case 2:
            gSelectCup->mStateFrames++;
            if (gSelectCup->mStateFrames >= 0xf) {
                if (func_021277c8() != 0 || func_02127788() != 0) {
                    func_02119a90();
                }
            }
            break;
    }
}

void AdvanceSelectCupState6(void) {
    s32 v;

    if (func_02127788() != 0) {
        func_02119a38();
        if (*(vu16 *) 0x027ffc40 == 2) {
            v = func_02127794();
            switch (v) {
                case 0:
                    func_0212ecc0(&data_0217d068, 0, 7);
                    break;
                case -1:
                case 1:
                    func_0212ecc0(&data_0217d068, 0, 0x10);
                    break;
            }
        }
    }
}

void AdvanceSelectCupState7(void) {
    s32 v;

    switch (gSelectCup->mMode) {
        case 0:
        case 1:
        case 3:
            if (func_021277ac() != 0) {
                v = func_02127794();
                switch (v) {
                    case 0:
                        func_02119e50();
                        gSelectCup->mResult = 1;
                        func_021199f8();
                        break;
                    case -1:
                    case 1:
                        func_02119bdc();
                        break;
                }
            }
            break;
        case 2:
            gSelectCup->mStateFrames++;
            if (gSelectCup->mStateFrames >= 0xf) {
                if (func_021277ac() != 0) {
                    v = func_02127794();
                    switch (v) {
                        case 0:
                            func_02119e50();
                            gSelectCup->mResult = 1;
                            func_021199f8();
                            if (*(vu16 *) 0x027ffc40 == 2) {
                                func_0211f378();
                            }
                            break;
                        case -1:
                        case 1:
                            func_02119bdc();
                            break;
                    }
                }
            }
            break;
    }
}

void AdvanceSelectCupState8(void) {
    BOOL a;
    s16 v;
    s32 w;
    s32 i;

    gSelectCup->mStateFrames++;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    if (gSelectCup->mMode == 0) {
        if (gSelectCup->mResult == 1) {
            if (func_0211e130() != 0) {
                a = TRUE;
            } else {
                a = FALSE;
            }
        } else {
            a = TRUE;
        }
    } else {
        a = TRUE;
    }
    func_020ae4c0(1, 0, 0x100, gSelectCup->mStateFrames, 10);
    v = func_020ae4c0(1, 0, -0xc0, gSelectCup->mStateFrames, 10);
    if (a != FALSE) {
        w = gSelectCup->mUnk_04->mUnk_06;
        gSelectCup->mBg0Offset = v;
        gSelectCup->mUnk_1c[0].mUnk_06 = v;
        gSelectCup->mUnk_1c[2].mUnk_06 = v;
        gSelectCup->mUnk_1c[1].mUnk_06 = v;
        gSelectCup->mUnk_1c[4].mUnk_06 = v;
        gSelectCup->mUnk_1c[3].mUnk_06 = v;
        gSelectCup->mUnk_1c[5].mUnk_06 = v;
        gSelectCup->mUnk_1c[w].mUnk_06 = v;
        gSelectCup->mUnk_1c[w + 1].mUnk_06 = v;
        gSelectCup->mUnk_1c[w + 2].mUnk_06 = v;
        gSelectCup->mUnk_1c[w + 3].mUnk_06 = v;
        gSelectCup->mUnk_1c[w + 4].mUnk_06 = v;
        gSelectCup->mUnk_1c[w + 5].mUnk_06 = v;
    }
    if (gSelectCup->mResult != 2) {
        w = gSelectCup->mUnk_10->mUnk_06;
        gSelectCup->mBg3Offset = v - 0x20;
        gSelectCup->mUnk_20[0x14].mUnk_06 = v - 0x20;
        gSelectCup->mUnk_20[0x13].mUnk_06 = v - 0x20;
        gSelectCup->mUnk_20[2].mUnk_06 = v - 0x20;
        gSelectCup->mUnk_20[1].mUnk_06 = v - 0x20;
        gSelectCup->mUnk_20[0].mUnk_06 = v - 0x20;
        for (i = 0; i < 8; i++) {
            gSelectCup->mUnk_20[data_0215cacc[i]].mUnk_06 = v - 0x20;
        }
        v -= 0x20;
        for (i = 0; i < 4; i++) {
            gSelectCup->mUnk_20[data_0215caa4[i]].mUnk_06 = v;
            gSelectCup->mUnk_20[w + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

s32 AdvanceSelectCup(void) {
    s32 i;
    u16 *p;

    gSelectCup->mState = gSelectCup->mNextState;
    switch (gSelectCup->mState) {
        case 0:
            AdvanceSelectCupState0();
            break;
        case 1:
            AdvanceSelectCupState1();
            break;
        case 2:
            AdvanceSelectCupState2();
            break;
        case 3:
            AdvanceSelectCupState3();
            break;
        case 4:
            AdvanceSelectCupState4();
            break;
        case 5:
            AdvanceSelectCupState5();
            break;
        case 6:
            AdvanceSelectCupState6();
            break;
        case 7:
            AdvanceSelectCupState7();
            break;
        case 8:
            AdvanceSelectCupState8();
            break;
    }
    func_0211a07c();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (gSelectCup->mUnk_60 != 0 && func_020d0ec4() != 0) {
            p = GetCupPictureNscrData();
            CallQueueAppend(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                CallQueueAppend(0x1b, ((i + 8) * 0x20 + 0x16) * 2, p + ((i + 8) * 0x20 + 0x16), 0x14);
            }
            gSelectCup->mUnk_60 = 0;
        }
        func_02124c30(gSelectCup->mUnk_04, gSelectCup->mUnk_00, gSelectCup->mUnk_08, gSelectCup->mUnk_64,
                      gSelectCup->mUnk_1c);
        func_02124c30(gSelectCup->mUnk_10, gSelectCup->mUnk_0c, gSelectCup->mUnk_18, gSelectCup->mUnk_68,
                      gSelectCup->mUnk_20);
    } else {
        func_0211f39c();
    }
    if (gSelectCup->mState == 8 && gSelectCup->mStateFrames >= 10) {
        return gSelectCup->mResult;
    }
    return 0;
}

void func_02118e30(void) {
    reg_G2_BG0OFS = (-gSelectCup->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCup->mBg3Offset << 16) & 0x1ff0000;
}

void func_02118d44(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Unk02021dc8 *e = NULL;
    Nclr *f = NULL;
    Ncgr *g = NULL;
    Nscr *h = NULL;
    Nclr *i = NULL;

    if (*(vu16 *) 0x027ffc40 != 2) {
        LoadNcgrData(&g, FindSceneFile(data_0216d690));
        LoadNclrData(&i, FindSceneFile(data_0216d6b8));
        LoadNscrData(&h, FindSceneFile(data_0216d6bc));
        LoadNcgrData2(&a, FindSceneFile(data_0216d6ac));
        LoadNcerData(&b, FindSceneFile(data_0216d694));
        LoadNclrData(&c, FindSceneFile(data_0216d6a0));
        LoadNcgrData2(&d, FindSceneFile(data_0216d69c));
        LoadNcerData(&e, FindSceneFile(data_0216d6b4));
        LoadNclrData(&f, FindSceneFile(data_0216d68c));
        func_0211de98();
        func_0211e024();
        func_0211f328();
    }
}

void func_02118b48(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Ncgr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    u16 *p;

    if (*(vu16 *) 0x027ffc40 == 2) {
        data_0217d360->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
        return;
    }
    LocateNcgr(&e, FindSceneFile(data_0216d690));
    LocateNclr(&g, FindSceneFile(data_0216d6b8));
    LocateNscr(&f, FindSceneFile(data_0216d6bc));
    data_0217d360->mUnk_20 = HeapAlloc(data_0217d360->mHeap, 0x800);
    data_0217d360->mSelectCupMBncl = FindSceneFile(data_0216d698);
    data_0217d360->mSelectCupMBnll = FindSceneFile(data_0216d6a8);
    LocateNcgr2(&a, FindSceneFile(data_0216d6ac));
    LocateNcer(&data_0217d360->mSelectCupMNcer, FindSceneFile(data_0216d694));
    LocateNclr(&b, FindSceneFile(data_0216d6a0));
    data_0217d360->mSelectCupSBncl = FindSceneFile(data_0216d6b0);
    data_0217d360->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
    LocateNcgr2(&c, FindSceneFile(data_0216d69c));
    LocateNcer(&data_0217d360->mSelectCupSNcer, FindSceneFile(data_0216d6b4));
    LocateNclr(&d, FindSceneFile(data_0216d68c));
    p = b->mData;
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        CallQueueAppend(4, 0, e->mData, e->mDataSize);
        CallQueueAppend(0xf, 0, g->mData, 0x100);
        CallQueueAppend(8, 0, &f->mData, f->mDataSize);
        CallQueueAppend(8, 0x800, data_0217d360->mUnk_20, 0x800);
    }
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, p + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

u32 func_021189f4(u32 a) {
    u32 r;
    s32 i;

    r = 0;
    switch (data_0217d360->mMode) {
        case 0:
        case 2:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    if (func_0202967c() != 0) {
                        r = func_02056dec(data_0215c8bc[a]);
                    } else {
                        r = func_02056dec(data_0215c95c[a][data_0215c7f0[func_0202969c()]]);
                    }
                    break;
            }
            break;
        case 1:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    r = 0;
                    for (i = 0; i < 4; i++) {
                        if (i == 3) {
                            r |= func_02056dec(data_0215c8bc[a]);
                        } else {
                            r |= func_02056dec(data_0215c95c[a][i]);
                        }
                    }
                    break;
            }
            break;
        case 3:
            if (a == 0 || a == 4) {
                r = 1;
            }
            break;
        case 4:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    if (func_0202967c() != 0) {
                        r = func_0205fbb8(data_0215c8bc[a]);
                    } else {
                        r = func_0205fbb8(data_0215c95c[a][data_0215c7f0[func_0202969c()]]);
                    }
                    break;
            }
            break;
    }
    return r;
}
#pragma thumb off
