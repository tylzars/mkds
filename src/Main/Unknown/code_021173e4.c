#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_021173e4.h"

#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02117814.h"
#include "Main/Unknown/code_021177a4.h"
#include "Main/Unknown/code_02117be0.h"
#include "Main/Unknown/code_02117d98.h"
#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0215c000.h"
#include "00/code_02181f98.h"
#include "code_02016468.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_021189cc.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/unk_02175000.h"
#include "registers.h"
#include "Main/Unknown/code_02118054.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02118114.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

u32 func_021185d4(void) {
    if (data_0217d360->mUnk_6c != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_021184d4(void) {
    u16 v;
    s16 b;
    int i;

    if (func_021185d4() != 0) {
        if (data_0217d360->mUnk_6c == 7) {
            data_0217d360->mUnk_70 = data_0217d360->mIndex;
            func_02118624();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            v = data_0217d360->mSelectCupMBncl->mUnk_06;
            b = func_02116d10(7 - data_0217d360->mUnk_6c, 1);
            data_0217d360->mBg0Offset = b;
            data_0217d360->mSelectCupMTable[19].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[2].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[1].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mUnk_6c = data_0217d360->mUnk_6c - 1;
    } else if (data_0217d360->mIndex != data_0217d360->mUnk_70) {
        data_0217d360->mUnk_6c = 7;
    }
}

void func_02118458(void) {
    int i;

    if (*(vu16 *) 0x027ffc40 != 2) {
        for (i = 0; i < 4; i++) {
            if (data_0217d360->mUnk_78 == i) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_00 = 1;
                func_02124100(data_0215c7d8[i], 0xe, data_0217d360->mSelectCupMBnll, data_0217d360->mSelectCupMTable,
                              data_0217d360->mSelectCupMBncl);
            } else {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_00 = 0;
                func_02124100(data_0215c7d8[i], 0xf, data_0217d360->mSelectCupMBnll, data_0217d360->mSelectCupMTable,
                              data_0217d360->mSelectCupMBncl);
            }
        }
    }
}

void func_02118414(void) {
    data_0217d360->mUnk_74 = data_0217d360->mUnk_74 + 1;
    if (data_0217d360->mUnk_74 >= 0x4b) {
        data_0217d360->mUnk_78 = data_0217d360->mUnk_78 + 1;
        if (data_0217d360->mUnk_78 >= 4) {
            data_0217d360->mUnk_78 = 0;
        }
        data_0217d360->mUnk_74 = 0;
        func_021187d4();
    }
}

void func_02118400(void) {
    data_0217d360->mUnk_78 = 0;
    data_0217d360->mUnk_74 = 0;
}

void func_021181fc(void) {
    u16 v;
    s32 b;
    s32 c;
    int i;
    int j;

    data_0217d360->mNextState = 0;
    data_0217d360->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mSelectCupMBncl->mUnk_06;
        if (func_020cccb4() == 0x18 || func_020cccb4() == 0xc) {
            b = 0;
            data_0217d360->mBg0Offset = b;
            data_0217d360->mSelectCupMTable[20].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[19].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[2].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[1].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        } else {
            b = -192;
            data_0217d360->mBg0Offset = b;
            data_0217d360->mSelectCupMTable[20].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[19].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[2].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[1].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        b = -192;
        data_0217d360->mSelectCupMTable[20].mUnk_06 = b;
        c = -224;
        data_0217d360->mSelectCupSTable[0].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[1].mUnk_04 = 0xe0;
        data_0217d360->mSelectCupSTable[2].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[3].mUnk_04 = 0xe0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = c;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void func_021181e8(void) {
    data_0217d360->mNextState = 1;
    data_0217d360->mStateFrames = 0;
}

void func_021181cc(void) {
    data_0217d360->mNextState = 2;
    data_0217d360->mStateFrames = 0;
    func_02128374();
}

void func_021181b8(void) {
    data_0217d360->mNextState = 3;
    data_0217d360->mStateFrames = 0;
}

void func_02118184(void) {
    data_0217d360->mNextState = 4;
    data_0217d360->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02118148(void) {
    void *a;

    data_0217d360->mNextState = 5;
    data_0217d360->mStateFrames = 0;
    a = GetBmgEntry(data_0217d360->mCommonMessages, 4);
    func_021277f8(a, GetBmgEntry(data_0217d360->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void func_02118114(void) {
    data_0217d360->mNextState = 6;
    data_0217d360->mStateFrames = 0;
    func_0212775c(0, (u32) 7);
    func_0212775c(1, (u32) 0x10);
    func_0212775c(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void func_021180f8(void) {
    data_0217d360->mNextState = 7;
    data_0217d360->mStateFrames = 0;
    func_021277e4();
}

void func_02118088(void) {
    void *a;

    data_0217d360->mNextState = 8;
    data_0217d360->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        a = GetBmgEntry(data_0217d360->mCommonMessages, 0x5d);
        func_021277f8(a, GetBmgEntry(data_0217d360->mCommonMessages, 0x5f), 0);
    } else {
        a = GetBmgEntry(data_0217d360->mMenuMessages, 0x14);
        func_021277f8(a, GetBmgEntry(data_0217d360->mMenuMessages, 0x15), 0);
    }
}

#pragma thumb off

#pragma thumb on

void func_02118054(void) {
    data_0217d360->mNextState = 9;
    data_0217d360->mStateFrames = 0;
    func_0212775c(0, (u32) 5);
    func_0212775c(1, (u32) 0xf);
    func_0212775c(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void func_02118038(void) {
    data_0217d360->mNextState = 0xa;
    data_0217d360->mStateFrames = 0;
    func_021277e4();
}

void func_02118024(void) {
    data_0217d360->mNextState = 0xb;
    data_0217d360->mStateFrames = 0;
}

void func_02117e24(void *a, void *b, void *c, s32 d) {
    s32 rem;
    int i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    a = CreateFrmHeapFromMaxFree(a);
    data_0217d360 = HeapAlloc(a, 0x8c);
    data_0217d360->mHeap = a;
    data_0217d360->mState = 0;
    data_0217d360->mIndex = data_0215c8fc[func_0202968c()];
    data_0217d360->mUnk_68 = 1;
    data_0217d360->mUnk_6c = 0;
    data_0217d360->mMode = d;
    data_0217d360->mUnk_70 = data_0217d360->mIndex;
    data_0217d360->mUnk_7c = 0;
    data_0217d360->mUnk_80 = b;
    data_0217d360->mUnk_84 = c;
    data_0217d360->mResult = 0;
    func_02118400();
    func_021189cc();
    func_02118b48();
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        func_020ae6d4(data_0217d360->mUnk_80, data_0217d360->mUnk_84);
    }
    data_0217d360->mCommonMessages = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        data_0217d360->mMenuMessages = FindSceneFile("menu.bmg");
        func_02124ed0(data_0217d360->mHeap, data_0217d360->mSelectCupMBncl, data_0217d360->mSelectCupMBnll,
                      &data_0217d360->mSelectCupMTable);
        func_02124ed0(data_0217d360->mHeap, data_0217d360->mSelectCupSBncl, NULL, &data_0217d360->mSelectCupSTable);
        rem = 0x8000;
        for (i = 0; i < 4; i++) {
            rem -= func_021243ac(data_0217d360->mHeap, data_0215c7d8[i], data_0217d360->mSelectCupMBnll,
                                 data_0215c7e0[i], data_0215c7e8[i], data_0215c7d0[i], data_0217d360->mSelectCupMNcer,
                                 data_0217d360->mSelectCupMBncl, data_0217d360->mSelectCupMTable, rem);
        }
        func_0211de40(data_0217d360->mHeap);
        func_0211df44(data_0217d360->mHeap);
        func_0211f2b8(data_0217d360->mHeap);
    } else {
        func_0211f4b0(data_0217d360->mHeap, data_0217d360->mUnk_84);
        if (func_020cccb4() != 0xc) {
            func_0211f394();
        } else {
            func_0211f380();
        }
    }
    func_021188dc();
    func_02118624();
    func_021181fc();
    FrmHeapShrinkInParent(data_0217d360->mHeap);
    if (data_021759d0->mUnk_20 == 2) {
        ClearSelectReturnDisplayBitOn();
    }
}

void func_02117db0(void) {
    if ((data_0217d360->mMode == 0 && data_0217d360->mResult == 1) || data_0217d360->mResult == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0211de34();
        func_0211df38();
        func_0211f2ac();
    } else {
        func_0211f498();
    }
    HeapDestroy(data_0217d360->mHeap);
    data_0217d360 = NULL;
}

#pragma thumb off

#pragma thumb on

void func_02117d98(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_021181e8();
    }
}

#pragma thumb off

#pragma thumb on

void func_02117bf8(void) {
    u16 v;
    s16 a;
    s16 b;
    s16 c;
    int i;
    int j;

    data_0217d360->mStateFrames = data_0217d360->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mSelectCupMBncl->mUnk_06;
        a = func_020ae4c0(1, 0xe0, 0, data_0217d360->mStateFrames, 0xa);
        b = func_020ae4c0(1, -192, 0, data_0217d360->mStateFrames, 0xa);
        if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
            data_0217d360->mBg0Offset = b;
            data_0217d360->mSelectCupMTable[19].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[2].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[1].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mSelectCupMTable[20].mUnk_06 = b;
        c = -a;
        data_0217d360->mSelectCupSTable[0].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[1].mUnk_04 = a;
        data_0217d360->mSelectCupSTable[2].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
    if (data_0217d360->mStateFrames >= 0xa) {
        func_021181cc();
    }
}

#pragma thumb off

#pragma thumb on

void func_02117be0(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        func_021181b8();
    }
}

#pragma thumb off

#pragma thumb on

void func_021178b0(void) {
    Unk02175628Index n;
    s32 s;
    s32 t;
    s32 d;
    int b;
    int a;
    u16 x;
    Unk02175628 *p;
    Unk02175628 *q;

    s = -1;
    n = UNK_02175628_INDEX_8;
    func_021184d4();
    func_02118414();
    b = 0;
    a = 0;
    p = &data_02175674[n];
    x = data_02175674[n].mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        s = RectTableFindContaining(data_0217d360->mSelectCupSBnbl, data_02175670[n].mUnk_00, data_02175672[n].mUnk_00);
    }
    q = &data_02175628[n];
    if ((u16) (data_02175628[n].mUnk_00 & 2) != 0) {
        goto L1;
    }
    b = 0;
    a = 0;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b == 0) {
        goto L2;
    }
    if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[n].mUnk_00, data_02175672[n].mUnk_00) == 0) {
        goto L2;
    }
L1:
    if (func_021185d4() != 0) {
        return;
    }
    func_021281c8(0xe);
    switch (data_0217d360->mMode) {
        case 0:
        case 1:
            func_02118024();
            data_0217d360->mResult = 2;
            func_02128310(0);
            return;
        case 2:
        case 3:
        case 4:
            if (data_0217b488->mUnk_08 == 2 || data_0217b488->mUnk_08 == 3) {
                func_02118088();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_021281c8(-1);
                }
                func_02128310(0);
                return;
            }
            func_02118024();
            data_0217d360->mResult = 2;
            if (data_0217d360->mMode != 2) {
                func_02128310(1);
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
            } else {
                func_02128310(0);
            }
            return;
    }
    return;
L2:
    if ((u32) s <= 7) {
        d = data_0215c8dc[s];
        if (data_0217d360->mUnk_48[d] == 0) {
            if (*(vu16 *) 0x027ffc40 != 2) {
                func_0212ecc0(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (data_0217d360->mIndex == d) {
            data_0217d360->mUnk_68 = 0;
        }
        data_0217d360->mIndex = d;
        func_02118184();
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_02118184();
        data_0217d360->mUnk_68 = 0;
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        a = data_0217d360->mIndex;
        b = data_0215c84c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mIndex = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        a = data_0217d360->mIndex;
        b = data_0215c7fc[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mIndex = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        a = data_0217d360->mIndex;
        b = data_0215c80c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mIndex = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        a = data_0217d360->mIndex;
        b = data_0215c82c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mIndex = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    }
}

void func_0211784c(void) {
    func_021184d4();
    func_02118414();
    if (data_0217d360->mStateFrames == 5) {
        data_0217d360->mUnk_68 = 1;
    }
    data_0217d360->mStateFrames = data_0217d360->mStateFrames + 1;
    if (data_0217d360->mStateFrames >= 10 && func_021185d4() == 0) {
        if (data_0217d360->mMode == 0) {
            func_02118148();
            return;
        }
        func_021185ec();
        data_0217d360->mResult = 1;
        func_02118024();
    }
}

#pragma thumb off

#pragma thumb on

void func_02117830(void) {
    int v1;
    func_02118414();
    v1 = func_021277c8();
    if (v1 != 0) {
        func_02118114();
    }
}

void func_02117814(void) {
    int v1;
    func_02118414();
    v1 = func_02127788();
    if (v1 != 0) {
        func_021180f8();
    }
}

#pragma thumb off

#pragma thumb on

void func_021177c0(void) {
    s32 a;

    func_02118414();
    if (func_021277ac() != 0) {
        a = func_02127794();
        switch (a) {
            case 0:
                func_021185ec();
                data_0217d360->mResult = 1;
                func_02118024();
                func_021282c8();
                break;
            case -1:
            case 1:
                func_021181b8();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_021177a4(void) {
    int v1;
    func_02118414();
    v1 = func_021277c8();
    if (v1 != 0) {
        func_02118054();
    }
}

#pragma thumb off

#pragma thumb on

void func_0211775c(void) {
    s32 a;

    func_02118414();
    if (func_02127788() != 0) {
        func_02118038();
        if (*(vu16 *) 0x027ffc40 == 2) {
            a = func_02127794();
            switch (a) {
                case -1:
                case 0:
                    break;
                case 1:
                    func_0212ecc0(&data_0217d068, 0, 0xf);
                    break;
            }
        }
    }
}

void func_02117700(void) {
    s32 a;

    func_02118414();
    if (func_021277ac() != 0) {
        a = func_02127794();
        switch (a) {
            case -1:
            case 0:
                func_021181b8();
                break;
            case 1:
                data_0217d360->mResult = 3;
                func_02118024();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
                break;
        }
    }
}

void func_0211756c(void) {
    s16 a;
    s16 b;
    s16 c;
    u16 v;
    int i;
    int j;
    int k;

    data_0217d360->mStateFrames = data_0217d360->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mSelectCupMBncl->mUnk_06;
        a = func_020ae4c0(1, 0, 0xe0, data_0217d360->mStateFrames, 0xa);
        b = func_020ae4c0(1, 0, -192, data_0217d360->mStateFrames, 0xa);
        if (data_0217d360->mResult == 2 || data_0217d360->mResult == 3 || data_0217d360->mMode == 0) {
            data_0217d360->mBg0Offset = b;
            data_0217d360->mSelectCupMTable[19].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[2].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[1].mUnk_06 = b;
            data_0217d360->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                data_0217d360->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                data_0217d360->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                data_0217d360->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        data_0217d360->mSelectCupMTable[20].mUnk_06 = b;
        c = -a;
        data_0217d360->mSelectCupSTable[0].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[1].mUnk_04 = a;
        data_0217d360->mSelectCupSTable[2].mUnk_04 = c;
        data_0217d360->mSelectCupSTable[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                data_0217d360->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
}

s32 func_02117418(void) {
    int i;
    int n;
    u16 *p;

    data_0217d360->mState = data_0217d360->mNextState;
    switch (data_0217d360->mState) {
        case 0:
            func_02117d98();
            break;
        case 1:
            func_02117bf8();
            break;
        case 2:
            func_02117be0();
            break;
        case 3:
            func_021178b0();
            break;
        case 4:
            func_0211784c();
            break;
        case 5:
            func_02117830();
            break;
        case 6:
            func_02117814();
            break;
        case 7:
            func_021177c0();
            break;
        case 8:
            func_021177a4();
            break;
        case 9:
            func_0211775c();
            break;
        case 10:
            func_02117700();
            break;
        case 11:
            func_0211756c();
            break;
    }
    func_02118814();
    func_02118458();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (data_0217d360->mUnk_7c != 0 && func_020d0ec4() != 0) {
            p = func_020d0e58();
            CallQueueAppend(0xf, 0, func_020d0ea0(), 0xe0);
            CallQueueAppend(4, 0x20, func_020d0e7c(), 0xdc0);
            for (i = 0; i < 11; i++) {
                n = (i + 8) * 0x20 + 0x16;
                CallQueueAppend(8, n * 2, p + n, 0x14);
            }
            data_0217d360->mUnk_7c = 0;
        }
        func_02124c30(data_0217d360->mSelectCupMBncl, data_0217d360->mSelectCupMNcer, data_0217d360->mSelectCupMBnll,
                      data_0217d360->mUnk_80, data_0217d360->mSelectCupMTable);
        func_02124c30(data_0217d360->mSelectCupSBncl, data_0217d360->mSelectCupSNcer, NULL, data_0217d360->mUnk_84,
                      data_0217d360->mSelectCupSTable);
    } else {
        func_0211f39c();
    }
    if (data_0217d360->mState == 0xb && data_0217d360->mStateFrames >= 0xa) {
        return data_0217d360->mResult;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_021173e4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217d360;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 64u);
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = value1;
    value1 = 0x4000000u;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
}
#pragma thumb off
