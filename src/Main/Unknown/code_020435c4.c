#include "Main/Unknown/code_020435c4.h"

#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a9e4.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02056284.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020470c4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "01/code_021956dc.h"
#include "code_021458c4.h"
#include "code_0214d018.h"

static inline void func_02043a34_inline(void) {
    if ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15) {
        data_02175624->mUnk_02 = 0;
    } else {
        data_02175624->mUnk_02 = ((*(vu16 *) 0x4000130 | *(vu16 *) 0x027fffa8) ^ 0x2fff) & 0x2fff;
    }
    func_02046d7c();
}

static inline void func_02043c14_inline(void) {
    s32 i;
    s32 k;
    Unk02175628 *p;
    Unk02175628 *q;

    for (i = 0; i < 10; i++) {
        p = &data_02175628[(u32) i];
        func_02039728(p);
        func_02039520(p, 0xff3, 0x1e, 0xa);
        p->mSourceKind = 0;
        p->mRequestedBits = 0;
        p->mUnk_44 = 0;
        p->mBitMask = 0x2fff;
        func_0204a9e4((Unk02175650 *) &p->mUnk_28);
        func_020470c4((Unk02175628_48 *) &p->mUnk_48);
    }
    data_02175628[8].mSourceKind = 5;
    data_02175628[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = FALSE;
    q = data_02175628;
    for (k = 0; k < 10; k++) {
        func_02039728(q);
        q->mRequestedBits = 0;
        func_02039520(q, 0xff3, 0x1e, 0xa);
        q++;
    }
}

static inline Unk021759c0 *func_02043f28_inline(void) {
    return data_021759c0;
}

void func_0204451c(u32 a) {
    s32 f;
    Unk021759c0 *q;

    f = 3;
    if (data_021759c0->mUnk_3d5[0] == -1) {
        f = 0;
    } else if (data_021759c0->mUnk_3d5[1] == -1) {
        f = 1;
    }
    func_020468b0(a, data_021759c0->mCurrentEntries[a].mCharacterIndex, data_021759c0->mCurrentEntries[a].mKartIndex, 1,
                  data_021759c0->mCurrentEntries[a].mPlayer.mTeamIndex, f);
    q = data_021759c0;
    q->mCurrentEntries[a] = q->mNextEntries[a];
    if (f < 2) {
        q->mUnk_3d5[f] = a;
    }
    data_021759c0->mNextEntries[a].mPlayer.mUnk_16 = data_021759c0->mUnk_3e1;
    data_021759c0->mUnk_3e1 = data_021759c0->mUnk_3e1 + 1;
}

void func_02044380(Unk02029930_f8 *a, u32 b, u32 c) {
    u8 i;

    data_021759c0->mNextHeader.mMissionFileRow = *a;
    data_021759c0->mNextHeader.mMissionTableRow = b;
    data_021759c0->mNextHeader.mMissionTableColumn = c;
    data_021759c0->mNextHeader.mMode = MODE_MISSION_RUN;
    data_021759c0->mNextHeader.mCourseId = a->mCourseId;
    data_021759c0->mNextHeader.mUnk_57 = (a->mUnk_1c & 0x10) != 0 ? 1 : 0;
    data_021759c0->mNextHeader.mUseTeams = 0;
    data_021759c0->mNextHeader.mUnk_1c = 0;
    data_021759c0->mNextHeader.mCourseListMode = 0;
    data_021759c0->mNextHeader.mUnk_18 = 0;
    data_021759c0->mUnk_3d8 = 0;
    data_021759c0->mNextHeader.mUnk_10 = a->mUnk_09;
    func_020468b0(0, a->mCharacterIndex0, a->mKartIndex0, 0, -1, 3);
    if (a->mCharacterIndex1 != 0xff && a->mKartIndex1 != 0xff) {
        func_020468b0(1, a->mCharacterIndex1, a->mKartIndex1, 1, -1, 3);
        data_021759c0->mNextHeader.mUnk_14 = 2;
    } else {
        func_020468b0(1, -1, -1, 4, -1, 3);
        data_021759c0->mNextHeader.mUnk_14 = 0;
    }
    for (i = 2; i < 8; i++) {
        func_020468b0(i, -1, -1, 4, -1, 3);
    }
}

void func_020442d0(u32 a) {
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
}

void func_0204419c(u32 a, u32 b) {
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
    func_02056670(b);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    }
}

void func_02044060(u32 a) {
    Unk0217aa08_14 *p;
    char v1[0x80];

    p = NULL;
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
    if (func_0203b018(a, v1, 0x80) != FALSE) {
        p = func_02056284(v1);
    }
    if (p != NULL) {
        return;
    }
    MI_CpuFill8(p, 0, 0x1000);
    p->mUnk_08_0 = 0;
}

void func_02043fb0(u32 a) {
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        CARD_WaitBackupAsync();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
}

void func_02043f28(u32 a) {
    u16 i;
    Unk021759c0 *q;
    u32 r;

    r = 0;
    i = 0;
    for (; i < (u32) (q = func_02043f28_inline())->mKartCount; i++) {
        if (a != 0) {
            r |= data_021540ec[q->mCurrentEntries[i].mCharacterIndex];
        } else {
            r |= data_021540ec[q->mNextEntries[i].mCharacterIndex];
        }
    }
    LoadSndBanksAndWaveArcsIfChanged(r);
}

void func_02043d10(void *a) {
    s32 i;

    InitTouchPanelAndSetCalibration();
    func_02047104(a);
    for (i = 0; i <= 1; i++) {
        func_0204aa04((u32) &data_02175628[i].mUnk_28, (u32) a);
    }
    for (; i < 10; i++) {
        func_0204a9f8((Unk02175650 *) &data_02175628[i].mUnk_28);
    }
    data_02175624 = HeapAlloc(a, 0x10);
    func_02043c14_inline();
    func_02043a34_inline();
    func_02043a34_inline();
}

void func_02043c14(void) {
    func_02043c14_inline();
}

void func_02043b48(void) {
    s32 i;
    s32 j;
    Unk02175628 *p;
    Unk02175628 *q;

    p = data_02175628;
    for (i = 0; i < 10; i++) {
        func_02039728(p);
        p->mRequestedBits = 0;
        func_02039520(p, 0xff3, 0x1e, 0xa);
        p++;
    }
    func_02047054();
    func_02043648();
    q = data_02175628;
    for (j = 0; j < 10; j++) {
        q->mUnk_12 = 0;
        q->mUnk_14 = 0;
        func_02039520(q, 0xff3, 0x1e, 0xa);
        q++;
    }
    data_02175624->mUnk_02 = 0;
    data_02175624->mUnk_04 = 0;
}

void func_02043b3c(void) {
    func_02046f54();
}

void func_02043b04(void) {
    s32 i;
    Unk02175628 *p;

    p = data_02175628;
    for (i = 0; i < 10; i++) {
        func_02039708(p);
        p++;
    }
}

void func_02043ae0(void) {
    data_02175624->mUnk_04 |= 8;
    func_02043648();
}

void func_02043ad4(void) {
    func_02046c74();
}

void func_02043a9c(u32 a) {
    if (a != 0) {
        data_02175624->mUnk_04 |= 4;
    } else {
        data_02175624->mUnk_04 &= ~4;
    }
}

void func_02043a34(void) {
    func_02043a34_inline();
}

u32 func_02043a20(void) {
    return (data_02175624->mUnk_02);
}

static inline s32 func_02043648_inline(Unk0217aa00 *p) {
    BOOL r = FALSE;
    if ((p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

void func_02043648(void) {
    u8 i;
    u16 y;
    u16 a;
    u16 b;
    u16 x;
    s32 k;
    u16 m;
    u16 t;
    s32 n;
    Unk02175628 *p;
    s32 o;
    BOOL q;
    s32 c;
    s32 f;
    s32 s;
    u16 w;

    x = data_02175624->mUnk_02;
    y = func_02046c10();
    a = x;
    b = y;
    k = data_021759c4->mUnk_30_3;
    if (func_02043648_inline(data_0217aa00) != 0) {
        a = func_0204ffe8(func_02050064(data_02175624->mUnk_08));
        b = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(data_02175624->mUnk_08)].mUnk_00[2];
        func_02050064(data_02175624->mUnk_08);
    }
    for (i = 0; i < 10; i++) {
        m = 0;
        n = 0xffff;
        o = m;
        f = (data_02175624->mUnk_04 & 1) ? 1 : 0;
        q = FALSE;
        c = (GetCurrentSceneNumber() != 2 || (data_02175624->mUnk_04 & 2)) ? 1 : 0;
        p = &data_02175628[i];
        w = data_02175624->mUnk_04;
        if (!(w & 8)) {
            s = p->mSourceKind;
            if (f == 0) {
                f = p->mUnk_44;
            }
            switch (s) {
                case 1:
                    if (f == 0) {
                        if (c != 0) {
                            m = func_0204a664((Unk02175650 *) &p->mUnk_28);
                        }
                    } else {
                        q = TRUE;
                    }
                    n = 0xffff;
                    o = 0;
                    break;
                case 2:
                    if (f == 0) {
                        if (c != 0) {
                            m = x;
                            if (w & 4) {
                                m = x & 0xffcf;
                                if (x & 0x20) {
                                    m |= 0x10;
                                }
                                if (x & 0x10) {
                                    m |= 0x20;
                                }
                            }
                            func_0204a798((Unk02175650 *) &p->mUnk_28, m);
                        }
                    } else {
                        q = TRUE;
                    }
                    n = y;
                    o = k;
                    break;
                case 3:
                case 7:
                    if (f != 0) {
                        q = TRUE;
                    } else {
                        o = 0;
                        m = p->mRequestedBits;
                        n = 0xffff;
                        p->mRequestedBits = o;
                    }
                    break;
                case 5:
                    m = a;
                    n = b;
                    o = 0;
                    break;
                case 4:
                    if (f == 0) {
                        if (c != 0) {
                            m = func_0204ffe8(func_02050064(i));
                            if (data_02175624->mUnk_04 & 4) {
                                t = m & 0xffcf;
                                if (m & 0x20) {
                                    t |= 0x10;
                                }
                                if (m & 0x10) {
                                    t |= 0x20;
                                }
                                m = t;
                            }
                        }
                    } else {
                        q = TRUE;
                    }
                    n = *(u16 *) &data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(i)].mUnk_00[2];
                    o = data_0217aa00->mUnk_15bc_view.mUnk_0c[func_02050064(i)].mUnk_06_7;
                    break;
                case 6:
                    m = x;
                    n = y;
                    o = k;
                    break;
                case 0:
                    m = 0;
                    n = 0xffff;
                    o = m;
                    break;
            }
        }
        t = m & p->mBitMask;
        if (q == FALSE) {
            func_02039530(t, p);
        }
        func_02046ca8((Unk02175628_48 *) &p->mUnk_48, n, o);
    }
}

// Takes effect only for slots whose source kind is 3 or 7.
void RequestBits(s32 a, u32 b) {
    if (data_02175628[a].mSourceKind == 3 || data_02175628[a].mSourceKind == 7) {
        data_02175628[a].mRequestedBits |= b;
    }
}

void func_020435d4(u32 a) {
    if (a != 0) {
        data_02175624->mUnk_04 |= 1;
        return;
    }
    data_02175624->mUnk_04 &= ~1;
}

u32 func_020435c4(void) {
    u32 value0;
    value0 = (u32) &data_02175928;
    value0 = *(const u16 *) ((value0) + (78));
    return value0;
}
