#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0210f130.h"
#include "code_0214e308.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

u16 func_02046c10(void) {
    Unk021759c4 *p;
    Unk0214e334_b *q;
    u32 a;
    u32 b;

    p = data_021759c4;
    q = &p->mUnk_28;
    if (!p->mUnk_30_0 || q->mUnk_04 == 0 || q->mUnk_06 != 0) {
        a = 0xff;
        b = a;
    } else {
        a = q->mUnk_00 & 0xff;
        b = q->mUnk_02 & 0xff;
    }
    return b + (a << 8);
}

void func_02046c74(void) {
    func_0210f114(data_021759c4->mUnk_3c);
    data_021759c4 = NULL;
}

void func_02046ca8(Unk02175628_48 *a, s32 b, s32 c) {
    Unk0214e334_b d;
    u32 e;
    s32 f;

    if (data_021759c4->mUnk_30_0) {
        f = (b >> 8) & 0xff;
        e = b & 0xff;
        if (e > 0xbf) {
            d.mUnk_02 = 0;
            d.mUnk_00 = 0;
            d.mUnk_04 = 0;
        } else {
            d.mUnk_00 = f;
            d.mUnk_02 = e;
            d.mUnk_04 = 1;
        }
        *(Unk0214e334_b *) &a->mUnk_08 = *(Unk0214e334_b *) a;
        *(Unk0214e334_b *) a = d;
        if (a->mHasPair != 0) {
            a->mNoPairCount = 0;
        } else if (a->mNoPairCount <= 5) {
            a->mNoPairCount++;
        }
    }
    if (data_021759c4->mUnk_30_1) {
        a->mUnk_12[0] = c;
    }
}

void func_02046d7c(void) {
    Unk021759c4 *p;
    u32 i;

    i = func_0214e6d4();
    p = data_021759c4;
    p->mUnk_28 = *(Unk0214e334_b *) &p->mUnk_00[i];
    func_0214e334((Unk0214e334 *) &p->mUnk_28, &p->mUnk_28);
    if (data_021759c4->mUnk_30_1) {
        data_021759c4->mUnk_30_3 = func_0210f090(data_021759c4->mUnk_3c) > 0x14;
    }
}

void func_02046e24(void) {
    Unk021759c4 *p;

    p = data_021759c4;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2) {
        func_0210f068((u32) p->mUnk_3c);
    }
    data_021759c4->mUnk_30_2 = 0;
}

void func_02046e84(void) {
    Unk021759c4 *p;

    p = data_021759c4;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2 == 0) {
        func_0210f07c((u32) p->mUnk_3c);
    }
    data_021759c4->mUnk_30_2 = 1;
}

void func_02046ee4(void) {
    if (data_021759c4->mUnk_30_1 == 0) {
        return;
    }
    func_0210f0d8(data_021759c4->mUnk_3c);
    data_021759c4->mUnk_3c = NULL;
    data_021759c4->mUnk_30_1 = 0;
    data_021759c4->mUnk_30_2 = 0;
}

void func_02046f54(void) {
    if (data_021759c4->mUnk_30_0 == 0) {
        return;
    }
    func_0214e6e4();
    func_0214e31c(4);
    func_0214e308(4);
    data_021759c4->mUnk_30_0 = 0;
}

void func_02046fb4(void *a) {
    if (data_021759c4->mUnk_30_1 != 0) {
        return;
    }
    data_021759c4->mUnk_3c = HeapAllocAligned(a, 0x420, 0x20);
    func_0210f130(data_021759c4->mUnk_3c);
    func_0210f0f4((s32) data_021759c4->mUnk_3c);
    data_021759c4->mUnk_30_1 = 1;
    data_021759c4->mUnk_30_2 = 0;
    data_021759c4->mUnk_30_3 = 0;
}

void func_02047054(void) {
    if (data_021759c4->mUnk_30_0 != 0) {
        return;
    }
    func_0214e788(0xa, 4, data_021759c4->mUnk_00, 5);
    func_0214e31c(2);
    func_0214e308(2);
    data_021759c4->mUnk_30_0 = 1;
}
