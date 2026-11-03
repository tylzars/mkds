#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281dc.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021285b0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_0200eddc.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02128570.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02016468.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on
s32 InitSelectReturn(void *heap, s32 b) {
    u32 t;
    gSelectReturn = HeapAlloc(heap, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectReturnDisplay();
        b = func_021286a0(b);
        gSelectReturn->mDisplayBitOn = 1;
    } else {
        gSelectReturn->mDisplayBitOn = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~4;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    gSelectReturn->mUnk_00 = 1;
    gSelectReturn->mState = 0;
    gSelectReturn->mUnk_08 = 0;
    gSelectReturn->mUnk_0c = 0;
    gSelectReturn->mState1Requested = 0;
    gSelectReturn->mState4Requested = 0;
    gSelectReturn->mBg2Offset = -0x28;
    gSelectReturn->mUnk_824 = 0xe;
    return b;
}
#pragma thumb off

#pragma thumb on
void func_021287c0(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gSelectReturn;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void InitSelectReturnDisplay(void) {
    u32 t;
    t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & ~3);
    *(vu16 *) 0x400100c = (*(vu16 *) 0x400100c & 0x43) | 0xe00;
}

s32 func_021286a0(s32 a) {
    Ncgr *ncgr;
    Nscr *nscr;
    Nclr *nclr;
    s32 i;
    s32 j;
    s32 k;
    LocateNcgr(&ncgr, func_02047a28("select_return_s_b_00.ncgr"));
    LocateNscr(&nscr, func_02047a28("select_return_s_bg_00.nscr"));
    LocateNclr(&nclr, func_02047a28("select_return_s_b_00.nclr"));
    a -= ncgr->mDataSize;
    func_0200ee74(ncgr->mData, ncgr->mDataSize);
    func_0214b8f4(ncgr->mData, a, ncgr->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(gSelectReturn->mUnk_10 + i * 0x20 + j) = (a >> 5) + *((u16 *) nscr->mData + i * 0x20 + j);
        }
    }
    func_0200ee74(gSelectReturn->mUnk_10, nscr->mDataSize);
    func_0214bc34(gSelectReturn->mUnk_10, 0, nscr->mDataSize);
    func_0200ee74(nclr->mData, 0x180);
    func_0214c0f8(nclr->mData + 0xc0, 0x180, 0x40);
    return a;
}

void func_02128624(s32 a) {
    s32 i;
    u16 v;
    v = 0xc000;
    if (a == 0) {
        v = 0xd000;
    }
    for (i = 0x260; i < 0x360; i++) {
        gSelectReturn->mUnk_10[i] &= ~0xf000;
        gSelectReturn->mUnk_10[i] |= v;
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_02016468(0x1a, 0x4c0, &gSelectReturn->mUnk_10[0x260], 0x200);
    }
}

void AdvanceSelectReturnState0(void) {
    if (gSelectReturn->mState1Requested != 0) {
        gSelectReturn->mUnk_08 = 1;
        gSelectReturn->mUnk_0c = 0;
        func_02128624(1);
    }
}

void AdvanceSelectReturnState1(void) {
    Unk0217d3f8 *p;
    gSelectReturn->mBg2Offset = func_0212825c(gSelectReturn->mUnk_0c);
    gSelectReturn->mUnk_0c++;
    p = gSelectReturn;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 2;
        gSelectReturn->mUnk_0c = 0;
        gSelectReturn->mState1Requested = 0;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnState2(void) {
    int v1;
    v1 = *(s32 *) &gSelectReturn;
    if (*(s32 *) (v1 + 0x814) != 0) {
        *(u32 *) (v1 + 8) = 3;
        func_02128624(0);
        return;
    }
    if (*(s32 *) (v1 + 0x818) != 0) {
        *(u32 *) (v1 + 8) = 4;
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectReturnState3(void) {
    Unk0217d3f8 *p;
    p = gSelectReturn;
    p->mBg2Offset = data_0215d0b4[p->mUnk_0c];
    gSelectReturn->mUnk_0c++;
    p = gSelectReturn;
    if (p->mUnk_0c >= 9) {
        if (p->mState4Requested != 0) {
            p->mUnk_08 = 4;
            func_02128624(0);
        } else {
            p->mUnk_08 = 2;
            func_02128624(1);
        }
        gSelectReturn->mUnk_0c = 0;
        gSelectReturn->mState3Requested = 0;
    }
}

void AdvanceSelectReturnState4(void) {
    Unk0217d3f8 *p;
    gSelectReturn->mBg2Offset = func_02128244(gSelectReturn->mUnk_0c);
    gSelectReturn->mUnk_0c++;
    p = gSelectReturn;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 0;
        gSelectReturn->mUnk_0c = 0;
        gSelectReturn->mState4Requested = 0;
    }
}

void AdvanceSelectReturn(void) {
    Unk0217d3f8 *p;
    p = gSelectReturn;
    if (p->mUnk_00 != 0) {
        p->mState = p->mUnk_08;
        switch (gSelectReturn->mState) {
            case 0:
                AdvanceSelectReturnState0();
                break;
            case 1:
                AdvanceSelectReturnState1();
                break;
            case 2:
                AdvanceSelectReturnState2();
                break;
            case 3:
                AdvanceSelectReturnState3();
                break;
            case 4:
                AdvanceSelectReturnState4();
                break;
        }
    }
}

void WriteSelectReturnRegisters(void) {
    Unk0217d3f8 *p;
    u32 t;
    p = gSelectReturn;
    if (p->mUnk_00 != 0) {
        if (p->mDisplayBitOn != 0) {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) == 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
            }
        } else {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) != 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t & ~4) << 8);
            }
        }
        *(vu32 *) 0x4001018 = (gSelectReturn->mBg2Offset << 16) & 0x1ff0000;
    }
}

void func_02128374(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        gSelectReturn->mState1Requested = 0;
    } else {
        gSelectReturn->mState1Requested = 1;
    }
    gSelectReturn->mState3Requested = 0;
    gSelectReturn->mState4Requested = 0;
}

void func_02128310(s32 a) {
    s32 v;
    gSelectReturn->mState1Requested = 0;
    gSelectReturn->mState3Requested = 1;
    if (a != 0) {
        gSelectReturn->mState4Requested = 1;
    } else {
        gSelectReturn->mState4Requested = 0;
    }
    v = gSelectReturn->mUnk_824;
    if (v != -1) {
        func_0212ecc0(&data_0217d068, 0, (u16) v);
    }
}

void func_021282c8(void) {
    if (IsSelectReturnState0NoState1Request() != 0) {
        gSelectReturn->mState4Requested = 0;
    } else {
        gSelectReturn->mState4Requested = 1;
    }
    gSelectReturn->mState1Requested = 0;
    gSelectReturn->mState3Requested = 0;
}

s32 IsSelectReturnState2NoState3Or4Request(void) {
    BOOL r;
    BOOL t;
    Unk0217d3f8 *p;
    r = FALSE;
    t = FALSE;
    p = gSelectReturn;
    if (p->mState == 2 && p->mState4Requested == 0) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (p->mState3Requested == 0) {
            r = TRUE;
        }
    }
    return r;
}

s32 IsSelectReturnState0NoState1Request(void) {
    BOOL r;
    Unk0217d3f8 *p;
    r = FALSE;
    p = gSelectReturn;
    if (p->mState == 0 && p->mState1Requested == 0) {
        r = TRUE;
    }
    return r;
}
#pragma thumb off

#pragma thumb on

int func_0212825c(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return data_0215d0c0[a];
}

int func_02128244(int a) {
    if (a < 0) {
        a = 0;
    }
    if (10 <= a) {
        a = 9;
    }
    return data_0215d0cc[a];
}

#pragma thumb off

#pragma thumb on
BOOL IsSelectReturnState2NoState3Or4RequestAndInRect(s32 a, s32 b) {
    if (IsSelectReturnState2NoState3Or4Request() != 0 && a >= 0 && a <= 0x28 && b >= 0x98 && b <= 0xc0) {
        return TRUE;
    }
    return FALSE;
}
#pragma thumb off

#pragma thumb on
void ClearSelectReturnDisplayBitOn(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &gSelectReturn;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x820u;
    *(u32 *) ((value1) + (value0)) = value2;
}
#pragma thumb off

#pragma thumb on
void SetSelectReturnDisplayBitOn(void) {
    if (*(vu16 *) 0x27ffc40 != 2) {
        gSelectReturn->mDisplayBitOn = 1;
    }
}
#pragma thumb off
