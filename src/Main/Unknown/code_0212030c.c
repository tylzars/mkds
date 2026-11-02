#include "Main/Unknown/code_0212030c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211ffb0.h"
#include "Main/Unknown/code_02120610.h"
#include "00/unk_021b5000.h"
#include "00/code_021a369c.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02120044.h"
#include "Main/Unknown/code_02120048.h"
#include "Main/Unknown/code_02120054.h"
#include "Main/Unknown/code_021200a4.h"
#include "Main/Unknown/code_021200a8.h"
#include "00/code_0219daa8.h"
#include "00/code_0219c384.h"
#include "00/code_0219c39c.h"
#include "00/code_0219b000.h"
#include "00/code_021a3000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_020176c0.h"

UnkFunc *const data_0216e21c[14] = {
    0,
    0,
    func_02120144,
    func_021200fc,
    0,
    0,
    func_021200f0,
    func_021200a8,
    func_021200a4,
    func_02120098,
    func_02120054,
    func_02120048,
    0,
    func_02120044,
};

u32 func_021205e8(void) {
    return func_ov000_021a3758();
}

#pragma thumb on
void func_021205ac(void *a) {
    Unk0217d384_08 *p;

    data_0217d384 = func_02036b74(a, 0x1f58, 0x20);
    func_02046be8(&data_0217d384->mUnk_0008, data_0216e21c, 8, NULL);
    p = &data_0217d384->mUnk_0008;
    p->mUnk_10 = 0;
    p->mUnk_12 = 1;
}

void func_0212055c(void *a) {
    data_0217d384->mUnk_0004 = func_02036b74(a, 0x3e800, 0x20);
    data_0217d384->mUnk_0000 = func_02017988(data_0217d384->mUnk_0004, 0x3e800, 1);
    data_0217d384->mUnk_1f30 = 1;
    func_ov000_021a3744(func_0211fffc, func_0211ffb0);
}

void func_02120514(void) {
    Unk0217d384_08 *p;

    if (data_0217d384->mUnk_0000 != NULL) {
        func_0201797c(data_0217d384->mUnk_0000);
        func_02036b30(func_020364e0(func_020364e8()), data_0217d384->mUnk_0004);
    }
    data_0217d384->mUnk_1f30 = 0;
    p = &data_0217d384->mUnk_0008;
    p->mUnk_10 = 0;
    p->mUnk_12 = 1;
}
#pragma thumb off

void func_021204d0(void) {
    Unk0217d384_08 *p;

    func_02120714();
    data_0217d384->mUnk_1f34 = 1;
    p = &data_0217d384->mUnk_0008;
    p->mUnk_10 = 0;
    p->mUnk_12 = 1;
}

void func_02120404(void) {
    u8 n = 0;
    Unk0217d384 *d;
    Unk0217d384 *p;
    u8 i;

    if (data_0217d384->mUnk_1f57 >= 0x3c) {
        data_0217d384->mUnk_1f57 = 0;
    }
    d = data_0217d384;
    d->mUnk_1cc0[d->mUnk_1f57] = func_ov000_0219daa8(&d->mUnk_19f0[d->mUnk_1f57], NULL);
    data_0217d384->mUnk_1f57++;
    p = data_0217d384;
    i = 0;
    do {
        switch (p->mUnk_1cc0[i]) {
            case 2:
                break;
            case 4:
                n++;
                break;
        }
        i++;
    } while (i < 0x3c);
    p->mUnk_194d = n;
}

void func_0212034c(void) {
    if (data_0217d384 == NULL) {
        return;
    }
    if (data_0217aa10->mUnk_00 != 0) {
        return;
    }
    func_ov000_0219bf10();
    if (func_ov000_0219c3cc(NULL) != 0) {
        data_0217d384->mUnk_1f44 = func_ov000_0219c3cc(&data_0217d384->mUnk_1f48);
        func_ov000_0219c3b0();
    }
    if (data_0217d384->mUnk_0008.mUnk_0e != 0) {
        func_02120404();
    }
    func_02046b40(&data_0217d384->mUnk_0008);
}

s32 func_02120340(u32 a, void *b, s32 c, u32 (*d)(void)) {
    return func_ov000_021a32a0(a, b, c);
}

void *func_0212030c(u32 a) {
    Unk0217d384 *d = data_0217d384;

    if (d->mUnk_1f55 & (1 << a)) {
        return &d->mUnk_021c[a].mUnk_00c;
    }
    return NULL;
}
