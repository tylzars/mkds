#include "Main/Unknown/code_0203a3a4.h"

#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "code_0200d118.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046c10.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/unk_02164000.h"
#include "code_021458c4.h"

static inline u32 func_0203a908_inline(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u32 b = 1;
    u32 c = 0;
    u16 x = data_02175628[i].mHasPair;
    if (x == 0 && data_02175628[i].mNoPairCount < 5) {
        c = 1;
    }
    if (c == 0 && x == 0) {
        b = 0;
    }
    return b;
}

BOOL func_0203b018(u32 a, void *b, u32 c) {
    int v = func_0204684c(a);
    if (v == -1) {
        return FALSE;
    }
    StringFormatBounded(b, c, data_usa_02164754, v & 0xff);
    return TRUE;
}

static inline u32 func_0203a9ec_inline(void) {
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

u32 func_0203afe4(u32 a) {
    if (data_021759c0->mUnk_00c != 6) {
        return 1;
    }
    return a >= 0x708;
}

void func_0203ad58(void *a) {
    Unk021755a0 *b;
    b = func_02038d88(a, data_usa_02164718[data_021759c0->mUnk_00c]);
    func_02038c9c(b, 1, 1);
    func_02038d58(&b->mUnk_28, 1, 0, 0, 1, 0, 0, 0);
    switch (data_021759c0->mUnk_00c) {
        case 0:
        case 2:
        case 6:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038d58(&b->mUnk_70, 0, 0, 0, 0, 0xd, 0, 0);
            func_02038d28(&b->mUnk_70, 1, 0, 0, 0, 0xe, 0, 0);
            func_02038d00(&b->mUnk_70, 2, 0, 0, 0, 0xf, 0);
            func_02056114(0);
            break;
        case 1:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038d58(&b->mUnk_70, 0, 0, 0, 0, 0xd, 0, 0);
            func_02038d28(&b->mUnk_70, 1, 0, 0, 0, 0xe, 0, 0);
            func_02038d00(&b->mUnk_70, 2, 0, 0, 0, 0xf, 0);
            func_02056114(0);
            break;
        case 3:
        case 5:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02038cb0(&b->mUnk_70, 0, 0, 1, 0, 0);
            func_02038c94(b, 0x20);
            func_02056114(1);
            break;
        case 4:
            func_02038d00(&b->mUnk_28, 1, 0, 0, 0, 7, 0);
            func_02056114(0);
            break;
    }
    func_02037abc(b);
    func_02055f68();
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 2;
}

void func_0203abdc(void) {
    void *p;
    s32 x;
    Unk0217d384 *q;
    BOOL f;
    p = GetHeap(func_020364e8());
    func_02059dc8();
    if (data_021759c0->mUnk_00c == 3 || data_021759c0->mUnk_00c == 5) {
        func_020399a8();
    } else {
        func_02039a1c();
        func_02053e74();
    }
    func_02062860();
    func_02047b6c(7);
    func_02056158(p);
    func_0203ad58(p);
    func_020431e4();
    func_02047b6c(9);
    InitRace();
    func_02047b6c(5);
    InitChoisesS();
    func_020b03bc();
    if (data_021759c0->mUnk_00c != 3) {
        func_020af99c();
    }
    func_02047b6c(8);
    x = data_021759c0->mUnk_57;
    if (x == 0 && data_021759c0->mMode == 4) {
        if ((data_021759c0->mUnk_044 & 0x10) != 0) {
            x = 1;
        }
    }
    func_02043a9c(x);
    func_02047b6c(9);
    if (data_021759c0->mMode != 2) {
        if (data_021759c0->mMode == 5) {
            f = FALSE;
            q = data_0217d384;
            if (q != NULL) {
                if (q->mHeapCreated != FALSE) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                Unk0217d384_08 *p;
                q->mUnk_1f38 = TRUE;
                p = &data_0217d384->mUnk_0008;
                p->mNextState = 5;
                p->mNextStateRequested = 1;
            }
        }
    } else {
        if (data_021759c0->mUnk_18 == 0) {
            func_02046fb4(GetHeap(func_020364e8()));
        }
    }
}

void func_0203aacc(void) {
    Unk021759c0 *p;
    Unk0217d384 *q;
    s32 t;
    BOOL f;
    if (data_021759c0->mMode == 5) {
        f = FALSE;
        q = data_0217d384;
        if (q != NULL) {
            if (q->mHeapCreated != FALSE) {
                f = TRUE;
            }
        }
        if (f != FALSE) {
            Unk0217d384_08 *p;
            q->mUnk_1f38 = FALSE;
            p = &data_0217d384->mUnk_0008;
            p->mNextState = 4;
            p->mNextStateRequested = 1;
        }
    }
    p = data_021759c0;
    if (p->mUnk_00c == 6) {
        t = 0x18;
        if (p->mMode != 0) {
            if (p->mMode == 4) {
                t = 0x1a;
            }
        } else {
            if (p->mCourseId == 0x36) {
                t = 0x19;
            }
        }
        if (func_02056dec(t) == 0) {
            func_02056e24(t);
            func_02056d40();
            func_02057d9c();
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
        }
    }
    func_02046ee4();
    func_020b1de4();
    func_02062004();
    func_020af86c();
    func_02056144();
    func_02053e54();
    func_02059d80();
}

void func_0203aaa8(void) {
    func_02055cbc(func_020b2e58());
    func_02062000();
    func_020b0b8c();
}

u32 func_0203a9ec(u32 a) {
    if (a > 0x564) {
        return 1;
    }
    if (func_02036c5c() == 0) {
        return 0;
    }
    if (func_0203a9ec_inline() != 0) {
        Unk02175628Index i = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_0203a908(u32 a) {
    u32 r;
    s32 t = 0x18;
    if (data_021759c0->mMode != 0) {
        if (data_021759c0->mMode == 4) {
            t = 0x1a;
        }
    } else {
        if (data_021759c0->mCourseId == 0x36) {
            t = 0x19;
        }
    }
    r = 0;
    if (func_02056dec(t) != 0 && a > 0xb4) {
        Unk02175628Index i = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[i].mBits & 0xc0f) != 0 || func_0203a908_inline() != 0) {
            r = 1;
        }
    }
    return r;
}

u32 func_0203a8f4(void) {
    return ((u32) data_021759c0->mMode);
}

void func_0203a8e0(u32 p0) {
    data_021759d0->mUnk_44 = p0;
}

void func_0203a520(Unk0203a0dc *a, u32 b) {
    s32 r;
    data_0217b488->mUnk_08 = 0;
    r = -1;
    switch (b) {
        case 10:
            func_02045a2c(0);
            r = 2;
            break;
        case 9:
            if (data_021759c0->mMode != 5) {
                u32 t;
                u32 f;
                Unk0217aa00 *q;
                f = 0;
                q = data_0217aa00;
                if (q == NULL) {
                    t = 0;
                } else {
                    t = q->mUnk_0000;
                }
                if (t != 0) {
                    if (q->mUnk_0004 != 0xd) {
                        f = 1;
                    }
                }
                if (f != 0) {
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        r = 6;
                        data_0217b488->mUnk_74 = 3;
                    } else {
                        r = 1;
                    }
                    data_0217b488->mUnk_08 = 4;
                    data_0217b488->mUnk_04 = 1;
                } else {
                    r = 0;
                }
                if (data_021759c0->mMode == 1) {
                    func_0204673c();
                }
            } else {
                r = 0xc;
                data_0217b488->mUnk_1c = 0;
            }
            break;
        case 1:
        case 3:
            r = 2;
            data_021759c0->mNextHeader.mUnk_0c = 0;
            break;
        case 8:
            r = 2;
            data_021759c0->mNextHeader.mUnk_0c = r;
            break;
        case 2:
            switch (data_021759c0->mMode) {
                case 0:
                    func_02046740();
                    r = 2;
                    break;
                case 3:
                    if (func_02045914() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mCourseListMode == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
                case 5:
                    if (func_02045874() != FALSE) {
                        r = 0xc;
                        data_0217b488->mUnk_1c = 3;
                    } else {
                        r = 0xa;
                        data_0217b488->mUnk_1c = 2;
                    }
                    break;
                case 2:
                    if (func_020458cc() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 2;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (data_021759c0->mCourseListMode == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            r = 1;
                        } else {
                            r = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (data_021759c0->mMode) {
                case 0:
                    if (func_02045bd4() != FALSE) {
                        r = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
                case 4:
                    r = 0;
                    break;
                case 2:
                case 3:
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        r = 6;
                        data_0217b488->mUnk_74 = 2;
                    } else {
                        r = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            r = 1;
            data_0217b488->mUnk_08 = r;
            break;
        case 4:
            data_0217b488->mUnk_08 = 2;
            r = 1;
            break;
        case 6:
            data_0217b488->mUnk_08 = 3;
            r = 1;
            break;
    }
    if (r != -1) {
        a->mUnk_04 = r;
    }
}

u32 func_0203a50c(void) {
    return data_021759c0->mUnk_00c;
}

void func_0203a4d4(u32 a) {
    if (a != 0) {
        data_021759d0->mUnk_50 |= 1;
    } else {
        data_021759d0->mUnk_50 &= ~1;
    }
}

u32 func_0203a4cc(void) {
    return 0x8u;
}

u16 func_0203a4a8(u32 a, u32 b) {
    u32 v;
    v = data_02175628[a].mBits;
    return v & b;
}

u32 func_0203a48c(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_0212ecc0;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value1 = 0u;
    value0 = (u32) func_0212ecc0((const void *) value0, value1, value2);
    return value0;
}

u32 func_0203a440(u32 a) {
    u32 r;
    u32 f;
    u16 x;
    r = 1;
    f = 0;
    x = data_02175628[a].mHasPair;
    if (x == 0 && data_02175628[a].mNoPairCount < 5) {
        f = 1;
    }
    if (f == 0 && x == 0) {
        r = 0;
    }
    return r;
}

u32 func_0203a42c(void) {
    return (u32) data_0217561c->mUnk_4d0;
}

u32 func_0203a3cc(u32 a) {
    u32 r;
    u32 f;
    r = 0;
    f = 0;
    if (data_02175628[a].mHasPair == 0 && data_02175628[a].mNoPairCount < 5) {
        f = 1;
    }
    if (f == 0 && data_02175628[a].mPrevHasPair == 0 && data_02175628[a].mHasPair != 0) {
        r = 1;
    }
    return r;
}

void func_0203a3b8(u32 p0) {
    data_021759c0->mNextHeader.mUnk_0c = p0;
}

u32 func_0203a3a4(void) {
    return ((u32) data_021759c0->mCourseId);
}
