#include "Main/Unknown/code_02043a34.h"
#include "Main/Unknown/code_02039520.h"
#include "Main/Unknown/code_02039708.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020435d4.h"
#include "Main/Unknown/code_0203b000.h"
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
        p->mUnk_3c = 0;
        p->mUnk_40 = 0;
        p->mUnk_44 = 0;
        p->mUnk_42 = 0x2fff;
        func_0204a9e4((u32) &p->mUnk_28);
        func_020470c4((u32) &p->mUnk_48);
    }
    data_02175628[8].mUnk_3c = 5;
    data_02175628[9].mUnk_3c = 6;
    data_02175624->mUnk_08 = 0;
    data_02175624->mUnk_0c = 0;
    q = data_02175628;
    for (k = 0; k < 10; k++) {
        func_02039728(q);
        q->mUnk_40 = 0;
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
        p->mUnk_40 = 0;
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

// non-matching: 0x220 bytes against 0x218; the inlined calls of the two helpers use a different literal order and the
// loop counter code differs.
void func_02043d10(void *a) {
    s32 i;
    Unk02175628 *p;

    func_02047178();
    func_02047104(a);
    p = data_02175628;
    for (i = 0; i < 2; i++) {
        func_0204aa04((u32) &p->mUnk_28, (u32) a);
        p++;
    }
    if (i < 10) {
        p = &data_02175628[(u32) i];
        for (; i < 10; i++) {
            func_0204a9f8((u32) &p->mUnk_28);
            p++;
        }
    }
    data_02175624 = func_02036bec(a, 0x10);
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
    for (; i < (u32) (q = func_02043f28_inline())->mUnk_3d0; i++) {
        if (a != 0) {
            r |= data_021540ec[q->mUnk_68[i].mUnk_00];
        } else {
            r |= data_021540ec[q->mUnk_250[i].mUnk_00];
        }
    }
    func_021087f4(r);
}

// non-matching: same size; the original keeps the address of data_0217aa08 in r1 and the loaded object in r2 and r3,
// here other registers.
void func_02043fb0(u32 a) {
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    func_02056700();
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != 0) {
        data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    }
}

// non-matching: same size; register choice differs in the repeated loads through data_0217aa08 (r0 here, r1 and r2 in
// the original).
void func_02044060(u32 a) {
    Unk0217aa08_14 *p;
    u8 v1[0x80];

    p = 0;
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    func_02056700();
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != 0) {
        data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    }
    if (func_0203b018(a, v1, 0x80) != 0) {
        p = func_02056284((u32) v1);
    }
    if (p != 0) {
        return;
    }
    func_0214d168(p, 0, 0x1000);
    p->mUnk_08_0 = 0;
}

// non-matching: same size; register choice differs in the repeated loads through data_0217aa08 (r0 here, r2 in the
// original).
void func_0204419c(u32 a, u32 b) {
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    func_02056700();
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != 0) {
        data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    }
    func_02056670(b);
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != 0) {
        data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    }
}

// non-matching: same size; the original keeps the address of data_0217aa08 in r1 and the loaded object in r2 and r3,
// here other registers.
void func_020442d0(u32 a) {
    data_0217aa08->mUnk_18->mUnk_08_0 = 0;
    data_0217aa08->mUnk_1c->mUnk_08_0 = 0;
    data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    func_02056700();
    func_02057d9c();
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    if (data_021759d4->mUnk_04 != 0) {
        data_0217aa08->mUnk_14->mUnk_08_0 = 0;
    }
}

void func_02044380(Unk02029930_f8 *a, u32 b, u32 c) {
    u8 i;

    data_021759c0->mUnk_1e8.mUnk_28 = *a;
    data_021759c0->mUnk_1e8.mUnk_54 = b;
    data_021759c0->mUnk_1e8.mUnk_55 = c;
    data_021759c0->mUnk_1e8.mUnk_08 = 4;
    data_021759c0->mUnk_1e8.mUnk_00 = a->mUnk_08;
    data_021759c0->mUnk_1e8.mUnk_57 = (a->mUnk_1c & 0x10) != 0 ? 1 : 0;
    data_021759c0->mUnk_1e8.mUnk_58 = 0;
    data_021759c0->mUnk_1e8.mUnk_1c = 0;
    data_021759c0->mUnk_1e8.mUnk_20 = 0;
    data_021759c0->mUnk_1e8.mUnk_18 = 0;
    data_021759c0->mUnk_3d8 = 0;
    data_021759c0->mUnk_1e8.mUnk_10 = a->mUnk_09;
    func_020468b0(0, a->mUnk_0a, a->mUnk_0b, 0, -1, 3);
    if (a->mUnk_1e != 0xff && a->mUnk_1f != 0xff) {
        func_020468b0(1, a->mUnk_1e, a->mUnk_1f, 1, -1, 3);
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
    func_020468b0(a, data_021759c0->mUnk_68[a].mUnk_00, data_021759c0->mUnk_68[a].mUnk_04, 1,
                  data_021759c0->mUnk_68[a].mUnk_08.mUnk_04, f);
    q = data_021759c0;
    q->mUnk_68[a] = q->mUnk_250[a];
    if (f < 2) {
        q->mUnk_3d5[f] = a;
    }
    data_021759c0->mUnk_250[a].mUnk_08.mUnk_16 = data_021759c0->mUnk_3e1;
    data_021759c0->mUnk_3e1 = data_021759c0->mUnk_3e1 + 1;
}
