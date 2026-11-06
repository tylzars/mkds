#include "Main/Unknown/code_0212775c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_02127a38.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "code_02023374.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021285b0.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02128570.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"

#pragma thumb on
s32 InitSelectReturn(void *heap, s32 b) {
    u32 t;
    gSelectReturn = HeapAlloc(heap, 0x828);
    if (*(vu16 *) 0x27ffc40 != 2) {
        InitSelectReturnDisplay();
        b = func_021286a0(b);
        gSelectReturn->mDisplayBitOn = TRUE;
    } else {
        gSelectReturn->mDisplayBitOn = FALSE;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~4;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    gSelectReturn->mEnabled = TRUE;
    gSelectReturn->mState = 0;
    gSelectReturn->mNextState = 0;
    gSelectReturn->mStateFrames = 0;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState4Requested = FALSE;
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
    DC_FlushRange(ncgr->mData, ncgr->mDataSize);
    GXS_LoadBG2Char(ncgr->mData, a, ncgr->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(gSelectReturn->mUnk_10 + i * 0x20 + j) = (a >> 5) + *((u16 *) nscr->mData + i * 0x20 + j);
        }
    }
    DC_FlushRange(gSelectReturn->mUnk_10, nscr->mDataSize);
    GXS_LoadBG2Scr(gSelectReturn->mUnk_10, 0, nscr->mDataSize);
    DC_FlushRange(nclr->mData, 0x180);
    GXS_LoadBGPltt(nclr->mData + 0xc0, 0x180, 0x40);
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
        CallQueueAppend(0x1a, 0x4c0, &gSelectReturn->mUnk_10[0x260], 0x200);
    }
}

void AdvanceSelectReturnState0(void) {
    if (gSelectReturn->mState1Requested != FALSE) {
        gSelectReturn->mNextState = 1;
        gSelectReturn->mStateFrames = 0;
        func_02128624(1);
    }
}

void AdvanceSelectReturnState1(void) {
    SelectReturn *p;
    gSelectReturn->mBg2Offset = func_0212825c(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 10) {
        p->mNextState = 2;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState1Requested = FALSE;
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectReturnState2(void) {
    SelectReturn *v1;
    v1 = gSelectReturn;
    if (v1->mState3Requested != FALSE) {
        v1->mNextState = 3;
        func_02128624(0);
        return;
    }
    if (v1->mState4Requested != FALSE) {
        v1->mNextState = 4;
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectReturnState3(void) {
    SelectReturn *p;
    p = gSelectReturn;
    p->mBg2Offset = data_0215d0b4[p->mStateFrames];
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 9) {
        if (p->mState4Requested != FALSE) {
            p->mNextState = 4;
            func_02128624(0);
        } else {
            p->mNextState = 2;
            func_02128624(1);
        }
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState3Requested = FALSE;
    }
}

void AdvanceSelectReturnState4(void) {
    SelectReturn *p;
    gSelectReturn->mBg2Offset = func_02128244(gSelectReturn->mStateFrames);
    gSelectReturn->mStateFrames++;
    p = gSelectReturn;
    if (p->mStateFrames >= 10) {
        p->mNextState = 0;
        gSelectReturn->mStateFrames = 0;
        gSelectReturn->mState4Requested = FALSE;
    }
}

void AdvanceSelectReturn(void) {
    SelectReturn *p;
    p = gSelectReturn;
    if (p->mEnabled != FALSE) {
        p->mState = p->mNextState;
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
    SelectReturn *p;
    u32 t;
    p = gSelectReturn;
    if (p->mEnabled != FALSE) {
        if (p->mDisplayBitOn != FALSE) {
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
        gSelectReturn->mState1Requested = FALSE;
    } else {
        gSelectReturn->mState1Requested = TRUE;
    }
    gSelectReturn->mState3Requested = FALSE;
    gSelectReturn->mState4Requested = FALSE;
}

void func_02128310(s32 a) {
    s32 v;
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState3Requested = TRUE;
    if (a != 0) {
        gSelectReturn->mState4Requested = TRUE;
    } else {
        gSelectReturn->mState4Requested = FALSE;
    }
    v = gSelectReturn->mUnk_824;
    if (v != -1) {
        func_0212ecc0(&data_0217d068, 0, (u16) v);
    }
}

void func_021282c8(void) {
    if (IsSelectReturnState0NoState1Request() != 0) {
        gSelectReturn->mState4Requested = FALSE;
    } else {
        gSelectReturn->mState4Requested = TRUE;
    }
    gSelectReturn->mState1Requested = FALSE;
    gSelectReturn->mState3Requested = FALSE;
}

s32 IsSelectReturnState2NoState3Or4Request(void) {
    BOOL r;
    BOOL t;
    SelectReturn *p;
    r = FALSE;
    t = FALSE;
    p = gSelectReturn;
    if (p->mState == 2 && p->mState4Requested == FALSE) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (p->mState3Requested == FALSE) {
            r = TRUE;
        }
    }
    return r;
}

s32 IsSelectReturnState0NoState1Request(void) {
    BOOL r;
    SelectReturn *p;
    r = FALSE;
    p = gSelectReturn;
    if (p->mState == 0 && p->mState1Requested == FALSE) {
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
        gSelectReturn->mDisplayBitOn = TRUE;
    }
}
#pragma thumb off

#pragma thumb on
void func_021281c8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gSelectReturn;
    value2 = (u32) * (const u32 *) ((value1) + 0u);
    value1 = 0x824u;
    *(u32 *) ((value2) + (value1)) = value0;
}
#pragma thumb off

#pragma thumb on
u32 func_021281b4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0217d3f4;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x8a0u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on
s32 func_02128058(void *a, s32 b, s32 c) {
    s32 i;
    s32 r;
    Unk0217d3f0_2098 *q;
    Unk0217d3f0_2178 *e;
    u32 t;
    data_0217d3f4 = HeapAlloc(a, 0x8b4);
    if (*(vu16 *) 0x27ffc40 != 2) {
        func_0212802c();
        c = func_02127f14(c);
        data_0217d3f4->mUnk_8a4 = 1;
    } else {
        data_0217d3f4->mUnk_8a4 = 0;
        t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
        t &= ~1;
        *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (t << 8);
    }
    for (i = 0; i < 2; i++) {
        data_0217d3f4->mUnk_894[i] = HeapAlloc(a, 0x800);
        func_02023408(&data_0217d3f4->mUnk_834[i], data_0217d3f4->mUnk_894[i], 0x20, 2, 4);
        q = &data_0217d3f4->mUnk_834[i];
        q->mUnk_18(q, 0);
        r = func_020b4acc();
        e = &data_0217d3f4->mUnk_874[i];
        e->mUnk_00 = &data_0217d3f4->mUnk_834[i];
        e->mUnk_04 = b;
        e->mUnk_08 = r;
        e->mUnk_0c = 0;
    }
    func_021281b4();
    data_0217d3f4->mUnk_00 = 1;
    data_0217d3f4->mUnk_04 = 0;
    data_0217d3f4->mUnk_08 = 0;
    data_0217d3f4->mUnk_0c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 0;
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_20 = 0;
    data_0217d3f4->mUnk_8a8[0] = 7;
    data_0217d3f4->mUnk_8a8[1] = 0x10;
    data_0217d3f4->mUnk_8b0 = 0x10;
    return c;
}
#pragma thumb off

#pragma thumb on
void func_0212804c(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d3f4;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
u32 func_0212802c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0x4001008u;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 3u;
    value1 = (value1) & ~(value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    value1 = (u32) * (const u16 *) ((value2) + 0u);
    value0 = 67u;
    value1 = (value1) & (value0);
    value0 = 0xb00u;
    value1 = (value1) | (value0);
    *(u16 *) ((value2) + 0u) = (u16) value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

s32 func_02127f14(s32 d) {
    Ncgr *a;
    Nscr *b;
    Nclr *c;
    s32 s;
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    Unk0215d064 *e;

    LocateNcgr(&a, func_02047a28(data_0216e840));
    LocateNscr(&b, func_02047a28(data_0216e858));
    LocateNclr(&c, func_02047a28(data_0216e874));
    d = d - a->mDataSize;
    s = d >> 5;
    data_0217d3f4->mUnk_89c = s;
    DC_FlushRange(a->mData, a->mDataSize);
    GXS_LoadBG0Char(a->mData, d, a->mDataSize);
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 32; j++) {
            *(data_0217d3f4->mUnk_2c + i * 32 + j) = s + *((u16 *) b->mData + i * 32 + j);
        }
    }
    DC_FlushRange(data_0217d3f4->mUnk_2c, b->mDataSize);
    GXS_LoadBG0Scr(data_0217d3f4->mUnk_2c, 0, b->mDataSize);
    e = &data_0215d0a0;
    y = e->mUnk_02 * 32;
    x = e->mUnk_00;
    data_0217d3f4->mUnk_82c = data_0217d3f4->mUnk_89c + (x + y);
    data_0217d3f4->mUnk_830 = data_0217d3f4->mUnk_89c + (y + (x + 3));
    DC_FlushRange(c->mData, 0x1c0);
    GXS_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    return d;
}

void func_02127e30(void) {
    s32 c;
    s32 i;
    s32 r;
    BOOL f;
    Unk0215d064 *e;
    s32 w;
    s32 v;
    u8(*p)[2];
    s32 h;
    s32 q;

    i = 0;
    p = data_0215d09c;
    e = &data_0215d0a0;
    w = e->mUnk_01 - e->mUnk_00;
    h = e->mUnk_03 - e->mUnk_02;
    for (; i < 2; i++) {
        f = FALSE;
        if (i == data_0217d3f4->mUnk_18 && data_0217d3f4->mUnk_14 != 0) {
            f = TRUE;
        }
        for (r = 0; r <= h; r++) {
            for (c = 0; c <= w; c++) {
                q = c + (*p)[0] + ((r + (*p)[1]) << 5);
                v = r * 32 + (data_0217d3f4->mUnk_830 + c);
                if (f != FALSE) {
                    v = r * 32 + (data_0217d3f4->mUnk_82c + c);
                }
                if (f != FALSE) {
                    data_0217d3f4->mUnk_2c[q] = v + ((data_0217d3f4->mUnk_2c[q] & 0xffff0c00) + 0xe000);
                } else {
                    data_0217d3f4->mUnk_2c[q] = v + (data_0217d3f4->mUnk_2c[q] & 0xfffffc00);
                }
            }
        }
        p++;
    }
}

void func_02127db8(void) {
    s32 i;
    s32 r;
    s32 c;
    s32 v;
    s32 t;

    for (i = 0; i < 2; i++) {
        v = 0xe;
        if (data_0217d3f4->mUnk_18 != i) {
            v = 0xf;
        }
        for (r = data_0215d0ac[i].mUnk_02; r <= data_0215d0ac[i].mUnk_03; r++) {
            for (c = data_0215d0ac[i].mUnk_00; c <= data_0215d0ac[i].mUnk_01; c++) {
                t = data_0217d3f4->mUnk_2c[r * 32 + c];
                t &= 0xffff0fff;
                t += v << 12;
                data_0217d3f4->mUnk_2c[r * 32 + c] = t;
            }
        }
    }
}

void func_02127d74(void) {
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    func_02127db8();
    func_02127e30();
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
    }
}

void func_02127d28(void) {
    s32 a;

    a = data_0217d3f4->mUnk_18;
    data_0217d3f4->mUnk_18 = -1;
    func_02127db8();
    data_0217d3f4->mUnk_18 = a;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
    if (*(vu16 *) 0x27ffc40 != 2) {
        CallQueueAppend(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
    }
}

void func_02127c78(void) {
    s32 i;
    s32 j;
    s32 t;

    if (data_0217d3f4->mUnk_24 != 0) {
        func_02127d74();
        data_0217d3f4->mUnk_08 = 1;
        i = 0;
        data_0217d3f4->mUnk_24 = i;
        data_0217d3f4->mUnk_0c = i;
        data_0217d3f4->mUnk_20 = i;
        if (data_0217d3f4->mUnk_8a0 != 0) {
            for (i = 0; i < 2; i++) {
                for (j = 0; j < 2; j++) {
                    t = (j + i * 2) * 32 + 5;
                    if (*(vu16 *) 0x27ffc40 != 2) {
                        CallQueueAppend(0x14, (data_0217d3f4->mUnk_89c + t) << 5,
                                        data_0217d3f4->mUnk_894[i] + ((j * 32 + 5) << 5), 0x360);
                    }
                }
            }
        }
    }
}

static inline BOOL func_02127a84_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02127a84_inline2(u32 v) {
    BOOL r = FALSE;
    BOOL s = FALSE;
    u16 c = data_02175674[v].mUnk_00;

    if (c == 0 && data_02175680[v].mUnk_00 < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[v].mUnk_00 == 0 && c != 0) {
        r = TRUE;
    }
    return r;
}

void func_02127a84(void) {
    s32 hit;
    u16 x;
    u16 y;
    Unk02175628Index v;
    u16 w;

    v = UNK_02175628_INDEX_8;
    x = data_02175670[v].mUnk_00;
    y = data_02175672[v].mUnk_00;
    if (data_0217d3f4->mUnk_28 != 0) {
        data_0217d3f4->mUnk_08 = 0;
        data_0217d3f4->mUnk_28 = 0;
        return;
    }
    hit = -1;
    if (func_02127a84_inline2(v) != 0) {
        if (func_02127a84_inline(x, y, data_0215d0a4[0].mUnk_00, data_0215d0a4[0].mUnk_01, data_0215d0a4[0].mUnk_02,
                                 data_0215d0a4[0].mUnk_03) != FALSE) {
            hit = 0;
        }
        if (func_02127a84_inline(x, y, data_0215d0a4[1].mUnk_00, data_0215d0a4[1].mUnk_01, data_0215d0a4[1].mUnk_02,
                                 data_0215d0a4[1].mUnk_03) != FALSE) {
            hit = 1;
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & 1) != 0 || hit != -1) {
        if (hit == -1 || data_0217d3f4->mUnk_18 == hit) {
            func_02127d28();
        } else {
            data_0217d3f4->mUnk_18 = hit;
            func_02127d74();
        }
        data_0217d3f4->mUnk_08 = 2;
        if (data_0217d3f4->mUnk_8a4 != 0) {
            if (data_0217d3f4->mUnk_8a8[data_0217d3f4->mUnk_18] != -1) {
                func_02105ac0((u16) data_0217d3f4->mUnk_8a8[data_0217d3f4->mUnk_18]);
            }
        }
    } else {
        if ((u16) (w & 2) != 0) {
            data_0217d3f4->mUnk_20 = 1;
            data_0217d3f4->mUnk_0c = 0xb;
            data_0217d3f4->mUnk_08 = 2;
            if (data_0217d3f4->mUnk_8a4 != 0) {
                if (data_0217d3f4->mUnk_8b0 != -1) {
                    func_02105ac0((u16) data_0217d3f4->mUnk_8b0);
                }
            }
            return;
        }
        if ((u16) (w & 0x40) != 0 && data_0217d3f4->mUnk_18 == 1) {
            data_0217d3f4->mUnk_18 = 0;
            func_02127d74();
            if (data_0217d3f4->mUnk_8a4 != 0) {
                func_02105ac0(0);
            }
            return;
        }
        if ((u16) (w & 0x80) != 0 && data_0217d3f4->mUnk_18 == 0) {
            data_0217d3f4->mUnk_18 = 1;
            func_02127d74();
            if (data_0217d3f4->mUnk_8a4 != 0) {
                func_02105ac0(0);
            }
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_02127a38(void) {
    Unk0217d3f4 *v1;
    int v2;
    v1 = data_0217d3f4;
    if (v1->mUnk_28 != 0) {
        v1->mUnk_08 = 0;
        data_0217d3f4->mUnk_28 = 0;
        return;
    }
    v1->mUnk_0c = v1->mUnk_0c + 1;
    v2 = data_0217d3f4->mUnk_0c;
    if (15 <= v2) {
        data_0217d3f4->mUnk_1c = 1;
        data_0217d3f4->mUnk_0c = 0xf;
        return;
    }
    if (5 <= v2) {
        func_02127d74();
    }
}

#pragma thumb off

#pragma thumb on

void func_021279a0(void) {
    if (data_0217d3f4->mUnk_00 != 0) {
        data_0217d3f4->mUnk_04 = data_0217d3f4->mUnk_08;
        switch (data_0217d3f4->mUnk_04) {
            case 0:
                func_02127c78();
                break;
            case 1:
                func_02127a84();
                break;
            case 2:
                func_02127a38();
                break;
        }
        data_0217d3f4->mUnk_10++;
        if ((data_0217d3f4->mUnk_14 != 0 && data_0217d3f4->mUnk_10 > 0x1e) ||
            (data_0217d3f4->mUnk_14 == 0 && data_0217d3f4->mUnk_10 > 0x14)) {
            data_0217d3f4->mUnk_14 = data_0217d3f4->mUnk_14 == 0;
            data_0217d3f4->mUnk_10 = 0;
            func_02127e30();
            if (*(vu16 *) 0x27ffc40 != 2) {
                CallQueueAppend(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
            }
        }
    }
}

void func_021278f4(void) {
    u32 a;

    if (data_0217d3f4->mUnk_00 != 0) {
        *(vu32 *) 0x4001010 = 0;
        if (data_0217d3f4->mUnk_04 == 0 || data_0217d3f4->mUnk_8a4 == 0) {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, 0);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a & ~1) << 8);
        } else {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, -10);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a | 1) << 8);
        }
    }
}

void func_021278c8(void) {
    if ((data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 != 0) || data_0217d3f4->mUnk_04 == 1) {
        data_0217d3f4->mUnk_28 = 1;
    } else {
        data_0217d3f4->mUnk_28 = 0;
    }
    data_0217d3f4->mUnk_24 = 1;
}

void func_021277f8(void *a, void *b, s32 c) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f4->mUnk_834[0];
    p->mUnk_18(p, 5);
    p = &data_0217d3f4->mUnk_834[1];
    p->mUnk_18(p, 5);
    func_0212583c(&data_0217d3f4->mUnk_874[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, a);
    func_0212583c(&data_0217d3f4->mUnk_874[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, b);
    func_021281b4();
    data_0217d3f4->mUnk_8a0 = 1;
    func_021278c8();
    if (c == 0) {
        data_0217d3f4->mUnk_18 = 0;
    } else {
        data_0217d3f4->mUnk_18 = 1;
    }
    func_02127d74();
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
}

void func_021277e4(void) {
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 1;
}

u32 func_021277c8(void) {
    u32 r;

    r = 0;
    if (data_0217d3f4->mUnk_04 == 1 && data_0217d3f4->mUnk_28 == 0) {
        r = 1;
    }
    return r;
}

s32 func_021277ac(void) {
    BOOL r;

    r = FALSE;
    if (data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 == 0) {
        r = TRUE;
    }
    return r;
}
#pragma thumb off

#pragma thumb on

s32 func_02127794(void) {
    if (data_0217d3f4->mUnk_20 != 0) {
        return 0xffffffff;
    }
    return data_0217d3f4->mUnk_18;
}

u32 func_02127788(void) {
    return data_0217d3f4->mUnk_1c;
}

void func_0212775c(int a, u32 b) {
    if (a == -1) {
        data_0217d3f4->mUnk_8b0 = b;
        return;
    }
    data_0217d3f4->mUnk_8a8[a] = b;
}

#pragma thumb off
