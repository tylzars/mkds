#include "Main/Unknown/code_0212b5ec.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02016554.h"
#include "code_0214a034.h"
#include "code_0214a2f4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02023000.h"
#include "code_02016468.h"

#pragma thumb on
void func_0212b874(s32 a) {
    s32 i;
    Unk0217d410 *p;
    for (i = 0; i < 4; i++) {
        p = data_0217d410;
        (&p->mUnk_0a[1])[i] = ((((0x1000 - a) * p->mUnk_2c[i].mUnk_08 + a * p->mUnk_5c[i].mUnk_08) >> 12) << 10) |
                              ((((0x1000 - a) * p->mUnk_2c[i].mUnk_00 + a * p->mUnk_5c[i].mUnk_00) >> 12) |
                               ((((0x1000 - a) * p->mUnk_2c[i].mUnk_04 + a * p->mUnk_5c[i].mUnk_04) >> 12) << 5));
    }
    if (data_0217d410->mUnk_8c == 0) {
        func_02016468(0x1e, data_0217d410->mUnk_08 << 5, data_0217d410->mUnk_0a, 0x20);
    } else {
        data_0217d410->mUnk_8c = 0;
    }
}

void func_0212b80c(void) {
    s32 a;
    if (data_0217d410->mUnk_04 == 0) {
        data_0217d410->mUnk_00++;
        if (data_0217d410->mUnk_00 >= 0x5a) {
            data_0217d410->mUnk_00 = 0;
        }
    }
    a = data_0217d410->mUnk_00;
    if (a < 0x1e) {
        func_0212b874(((0x1e - a) << 12) / 0x1e);
    } else if (a < 0x3c) {
        func_0212b874(0);
    } else {
        func_0212b874(((a - 0x3c) << 12) / 0x1e);
    }
}

void func_0212b7fc(void) {
    data_0217d410->mUnk_00 = 0;
}

void func_0212b7e8(void) {
    data_0217d410->mUnk_00 = 0;
    data_0217d410->mUnk_04 = 1;
}

void func_0212b7d8(void) {
    data_0217d410->mUnk_04 = 0;
}
#pragma thumb off

void func_0212b5ec(void *a) {
    s32 i;
    s32 v;
    Unk020b4a44 *p;
    Unk0217d40c *d;
    Unk02180728 *q;
    void *t;
    data_0217d40c = func_02036bec(a, 0x85c);
    data_0217d40c->mUnk_858 = a;
    data_0217d40c->mUnk_000 = 0;
    data_0217d40c->mUnk_004 = 0;
    func_02016554(func_02036bec(a, 0xa0), 0xa);
    data_0217d40c->mUnk_008 = 0;
    data_0217d40c->mUnk_010 = 0;
    data_0217d40c->mUnk_014 = -1;
    data_0217d40c->mUnk_00c = 0x70a;
    data_0217d40c->mUnk_01c = 1;
    data_0217d40c->mUnk_850 = 1;
    data_0217d40c->mUnk_854 = 0x240;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | 0x100;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 1;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x1000;
    func_0214d05c_inline((void *) func_0214a034(), 0x8000);
    for (i = 0; i < 0x400; i++) {
        ((u16 *) func_0214a2f4())[i] = i | 0xf000;
    }
    LoadNclrData(&p, FindSceneFile(data_0216ea78));
    func_02016468(0x1f, 0x1e0, p->mUnk_0c + 0xf0, 0x20);
    func_02023408(data_0217d40c->mUnk_020, data_0217d40c->mUnk_050, 0x20, 2, 4);
    v = data_0217d40c->mUnk_01c;
    t = func_020b403c(2);
    d = data_0217d40c;
    q = &d->mUnk_040;
    d->mUnk_040.mUnk_00 = d->mUnk_020;
    q->mUnk_04 = t;
    q->mUnk_08 = v;
    q->mUnk_0c = 0;
    func_0214d168(data_0217d40c->mUnk_050, 0, 0x800);
    data_0217d40c->mUnk_018 = GetBmgEntry(FindSceneFile(data_0216ea94), 0);
}
