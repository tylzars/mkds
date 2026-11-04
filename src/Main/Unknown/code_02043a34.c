#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203a908.h"
#include "Main/Unknown/code_02043a34.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046c10.h"
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
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
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
        func_0204a9e4((u32) &p->mUnk_28);
        func_020470c4((u32) &p->mUnk_48);
    }
    data_02175628[8].mSourceKind = 5;
    data_02175628[9].mSourceKind = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = 0;
    q = data_02175628;
    for (k = 0; k < 10; k++) {
        func_02039728(q);
        q->mRequestedBits = 0;
        func_02039520(q, 0xff3, 0x1e, 0xa);
        q++;
    }
}

void func_02043a34(void) {
    func_02043a34_inline();
}

void func_02043a9c(u32 a) {
    if (a != 0) {
        data_02175624->mUnk_04 |= 4;
    } else {
        data_02175624->mUnk_04 &= ~4;
    }
}

void func_02043ad4(void) {
    func_02046c74();
}

void func_02043ae0(void) {
    data_02175624->mUnk_04 |= 8;
    func_02043648();
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

void func_02043b3c(void) {
    func_02046f54();
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

void func_02043c14(void) {
    func_02043c14_inline();
}

void func_02043d10(void *a) {
    s32 i;

    func_02047178();
    func_02047104(a);
    for (i = 0; i <= 1; i++) {
        func_0204aa04((u32) &data_02175628[i].mUnk_28, (u32) a);
    }
    for (; i < 10; i++) {
        func_0204a9f8((u32) &data_02175628[i].mUnk_28);
    }
    data_02175624 = HeapAlloc(a, 0x10);
    func_02043c14_inline();
    func_02043a34_inline();
    func_02043a34_inline();
}

static inline Unk021759c0 *func_02043f28_inline(void) {
    return data_021759c0;
}

void func_02043f28(u32 a) {
    u16 i;
    Unk021759c0 *q;
    u32 r;

    r = 0;
    i = 0;
    for (; i < (u32) (q = func_02043f28_inline())->mKartCount; i++) {
        if (a != 0) {
            r |= data_021540ec[q->mUnk_68[i].mCharacterIndex];
        } else {
            r |= data_021540ec[q->mUnk_250[i].mCharacterIndex];
        }
    }
    func_021087f4(r);
}

void func_02043fb0(u32 a) {
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
}

void func_02044060(u32 a) {
    Unk0217aa08_14 *p;
    u8 v1[0x80];

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
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
    if (func_0203b018(a, v1, 0x80) != 0) {
        p = func_02056284((u32) v1);
    }
    if (p != NULL) {
        return;
    }
    MemFill(p, 0, 0x1000);
    p->mUnk_08_0 = 0;
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
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
    func_02056670(b);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    }
}

void func_020442d0(u32 a) {
    data_0217aa08->mUnk_14[1]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[2]->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    func_02056700(a);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != NULL) {
        data_0217aa08->mUnk_14[0]->mUnk_08_0 = 0;
    }
}

void func_02044380(Unk02029930_f8 *a, u32 b, u32 c) {
    u8 i;

    data_021759c0->mUnk_1e8.mMissionFileRow = *a;
    data_021759c0->mUnk_1e8.mMissionTableRow = b;
    data_021759c0->mUnk_1e8.mMissionTableColumn = c;
    data_021759c0->mUnk_1e8.mUnk_08 = 4;
    data_021759c0->mUnk_1e8.mCourseId = a->mCourseId;
    data_021759c0->mUnk_1e8.mUnk_57 = (a->mUnk_1c & 0x10) != 0 ? 1 : 0;
    data_021759c0->mUnk_1e8.mUseTeams = 0;
    data_021759c0->mUnk_1e8.mUnk_1c = 0;
    data_021759c0->mUnk_1e8.mCourseListMode = 0;
    data_021759c0->mUnk_1e8.mUnk_18 = 0;
    data_021759c0->mUnk_3d8 = 0;
    data_021759c0->mUnk_1e8.mUnk_10 = a->mUnk_09;
    func_020468b0(0, a->mCharacterIndex0, a->mKartIndex0, 0, -1, 3);
    if (a->mCharacterIndex1 != 0xff && a->mKartIndex1 != 0xff) {
        func_020468b0(1, a->mCharacterIndex1, a->mKartIndex1, 1, -1, 3);
        data_021759c0->mUnk_1e8.mUnk_14 = 2;
    } else {
        func_020468b0(1, -1, -1, 4, -1, 3);
        data_021759c0->mUnk_1e8.mUnk_14 = 0;
    }
    for (i = 2; i < 8; i++) {
        func_020468b0(i, -1, -1, 4, -1, 3);
    }
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
    func_020468b0(a, data_021759c0->mUnk_68[a].mCharacterIndex, data_021759c0->mUnk_68[a].mKartIndex, 1,
                  data_021759c0->mUnk_68[a].mUnk_08.mTeamIndex, f);
    q = data_021759c0;
    q->mUnk_68[a] = q->mUnk_250[a];
    if (f < 2) {
        q->mUnk_3d5[f] = a;
    }
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_16 = data_021759c0->mUnk_3e1;
    data_021759c0->mUnk_3e1 = data_021759c0->mUnk_3e1 + 1;
}
