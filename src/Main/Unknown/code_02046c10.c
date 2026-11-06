#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f068.h"
#include "Main/Unknown/code_0210f090.h"
#include "Main/Unknown/code_0210f130.h"
#include "code_0214e308.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02047054(void) {
    if (data_021759c4->mUnk_30_0 != 0) {
        return;
    }
    TP_RequestAutoSamplingStartAsync(0xa, 4, data_021759c4->mUnk_00, 5);
    TP_WaitBusy(2);
    TP_CheckError(2);
    data_021759c4->mUnk_30_0 = 1;
}

void func_02046fb4(void *a) {
    if (data_021759c4->mUnk_30_1 != 0) {
        return;
    }
    data_021759c4->mUnk_3c = HeapAllocAligned(a, 0x420, 0x20);
    func_0210f130(data_021759c4->mUnk_3c);
    func_0210f0f4(data_021759c4->mUnk_3c);
    data_021759c4->mUnk_30_1 = 1;
    data_021759c4->mUnk_30_2 = 0;
    data_021759c4->mUnk_30_3 = 0;
}

void func_02046f54(void) {
    if (data_021759c4->mUnk_30_0 == 0) {
        return;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    TP_CheckError(4);
    data_021759c4->mUnk_30_0 = 0;
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

void func_02046e84(void) {
    Unk021759c4 *p;

    p = data_021759c4;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2 == 0) {
        func_0210f07c(p->mUnk_3c);
    }
    data_021759c4->mUnk_30_2 = 1;
}

void func_02046e24(void) {
    Unk021759c4 *p;

    p = data_021759c4;
    if (p->mUnk_30_1 == 0) {
        return;
    }
    if (p->mUnk_30_2) {
        func_0210f068(p->mUnk_3c);
    }
    data_021759c4->mUnk_30_2 = 0;
}

void func_02046d7c(void) {
    Unk021759c4 *p;
    u32 i;

    i = TP_GetLatestIndexInAuto();
    p = data_021759c4;
    p->mUnk_28 = *(TPData *) &p->mUnk_00[i];
    TP_GetCalibratedPoint(&p->mUnk_28, &p->mUnk_28);
    if (data_021759c4->mUnk_30_1) {
        data_021759c4->mUnk_30_3 = func_0210f090(data_021759c4->mUnk_3c) > 0x14;
    }
}

void func_02046ca8(Unk02175628_48 *a, s32 b, s32 c) {
    TPData d;
    u32 e;
    s32 f;

    if (data_021759c4->mUnk_30_0) {
        f = (b >> 8) & 0xff;
        e = b & 0xff;
        if (e > 0xbf) {
            d.mY = 0;
            d.mX = 0;
            d.mTouch = 0;
        } else {
            d.mX = f;
            d.mY = e;
            d.mTouch = 1;
        }
        *(TPData *) &a->mUnk_08 = *(TPData *) a;
        *(TPData *) a = d;
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

void func_02046c74(void) {
    func_0210f114(data_021759c4->mUnk_3c);
    data_021759c4 = NULL;
}

u16 func_02046c10(void) {
    Unk021759c4 *p;
    TPData *q;
    u32 a;
    u32 b;

    p = data_021759c4;
    q = &p->mUnk_28;
    if (!p->mUnk_30_0 || q->mTouch == 0 || q->mValidity != 0) {
        a = 0xff;
        b = a;
    } else {
        a = q->mX & 0xff;
        b = q->mY & 0xff;
    }
    return b + (a << 8);
}
