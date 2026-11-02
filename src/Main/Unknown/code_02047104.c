#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_020cade8.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_0210f130.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020176c0.h"
#include "code_020182c0.h"
#include "code_0214e6e4.h"

void func_02047104(void *a) {
    data_021759c4 = func_02036bec(a, 0x40);
    data_021759c4->mUnk_30_0 = 0;
    data_021759c4->mUnk_30_1 = 0;
    data_021759c4->mUnk_30_2 = 0;
    data_021759c4->mUnk_30_3 = 0;
    data_021759c4->mUnk_3c = 0;
    func_0210f1d4();
}

void func_02047178(void) {
    Unk0214e334 v;

    func_0214eb88();
    if (func_0214eadc(&v) == 0) {
        return;
    }
    func_0214e994(&v);
}

#pragma thumb on

void func_020471b0(void *a) {
    u32 n;
    void *p;

    n = *func_020cade8() >> 8;
    data_021759c8->mUnk_8b8 = 0;
    p = func_02036b74(a, n, 0x20);
    func_020487e0(func_020cade8(), p, n);
    func_02018344(&data_021759c8->mUnk_850, (const u8 *) gArchiveNames[19], p);
    data_021759c8->mUnk_8bc = p;
    data_021759c8->mUnk_8b8 = 1;
    func_020d1640(a);
}

void func_02047220(void *a, u32 b) {
    void *p;

    p = data_021759c8->mUnk_84c;
    func_020177b0(func_020364e0(func_020364e8()), p, b + ((u32) a - (u32) p));
}

s32 func_02047250(void) {
    if (*(vu16 *) 0x027ffc40 == 2) {
        return data_021759c8->mUnk_9b0[7].mUnk_08 >> 31;
    }
    return 1;
}

void func_02047274(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        *(u32 *) ((u8 *) &data_021759c8->mUnk_9b0[0].mUnk_08 + i * 12) &= 0x7fffffff;
    }
}

#pragma thumb off
