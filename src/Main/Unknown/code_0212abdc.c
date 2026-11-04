#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b19a0.h"
#include "Main/Unknown/code_021205f4.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02024000.h"
#include "code_0200eddc.h"
#include "code_02023374.h"
#include "code_0214a390.h"
#include "code_0214cfe4.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0216e000.h"

#pragma thumb on
void func_0212b064(void) {
    volatile u16 a;
    a = 0;
    MemFillHalfwords(a, data_0217d408->mUnk_1444, 0x600);
}

void *func_0212afac(void) {
    void *a;
    s32 v;
    a = NULL;
    if (*(vu16 *) 0x27ffc40 != 2) {
        a = func_02047a28(data_0216ea6c);
    }
    v = data_0217d408->mUnk_0000;
    if (v == 4) {
        return GetBmgEntry(a, 0x86);
    }
    if (v == 5) {
        return GetBmgEntry(a, 0x87);
    }
    if (v == 6) {
        return GetBmgEntry(a, 0x88);
    }
    if (v == 1) {
        return GetBmgEntry(a, 0x83);
    }
    if (v == 2) {
        return GetBmgEntry(a, 0x84);
    }
    if (v == 3) {
        return GetBmgEntry(a, 0x85);
    }
    if (v == 0) {
        if (*(vu16 *) 0x27ffc40 == 2) {
            return GetBmgEntry(func_020d1630()->mUnk_20, 0);
        }
        return GetBmgEntry(a, 0x82);
    }
    return NULL;
}

void func_0212ae80(void) {
    s32 i;
    func_0212b09c();
    if (*(vu16 *) 0x27ffc40 == 2) {
        data_0217d408->mUnk_0034.mUnk_04 = &func_020d1630()->mUnk_14;
    } else {
        data_0217d408->mUnk_0034.mUnk_04 = func_020b403c(0);
    }
    func_02024340(&data_0217d408->mUnk_0034, 0x80, 0x14, 0xe, 0x412, data_0217d408->mUnk_0008);
    func_0212b064();
    for (i = 0; i < 0x300; i++) {
        if (i >= 0x120 && i < 0x1c0) {
            data_0217d408->mUnk_1444[i] = (i - 0x120) | 0xf000;
        } else {
            data_0217d408->mUnk_1444[i] = 0xf09f;
        }
    }
    *(vu16 *) 0x50001fc = 0xffff;
    *(vu16 *) 0x5000000 = 0;
    *(vu32 *) 0x4000014 = 0;
    *(vu16 *) 0x400000a = *(vu16 *) 0x400000a & ~3;
    *(vu16 *) 0x400000a = *(vu16 *) 0x400000a & ~0x40;
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & 0x43) | 0x400;
    func_0200ee74(data_0217d408->mUnk_0044, 0x1400);
    func_0200ee74(data_0217d408->mUnk_1444, 0x600);
    func_0214ba2c(data_0217d408->mUnk_0044, 0, 0x1400);
    func_0214bd6c(data_0217d408->mUnk_1444, 0, 0x600);
}

void func_0212ae2c(void) {
    u16 a[11];
    a[0] = 0;
    MemFillHalfwords(a[0], &a[1], 0x14);
    func_02124fac(func_021205f4(), &a[1]);
    func_0212513c(&a[1], data_0217d408->mUnk_0008, data_0217d408->mUnk_1444, 0x600);
    data_0217d408->mUnk_0008 = data_0217d408->mUnk_1444;
}

void func_0212ad28(s32 a, s32 b) {
    u32 t;
    if (data_0217d408->mUnk_000c == 0 && a != -1) {
        data_0217d408->mUnk_000c = 1;
        data_0217d408->mUnk_0004 = b;
        data_0217d408->mUnk_0000 = a;
        data_0217d408->mUnk_0008 = func_0212afac();
        if (data_0217d408->mUnk_0000 == 4) {
            func_0212ae2c();
        }
        func_0212ae80();
        if (func_0205e0a0() == 2) {
            if (func_020b19a0() == 0) {
                *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x200;
                *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffffe0ff;
                *(vu16 *) 0x5000400 = 0;
                *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
            } else {
                t = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
                t |= 2;
                *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (t << 8);
            }
            func_0214a390((u16 *) 0x4000050, 0x1d, 0, 8, 8, -11);
        } else {
            *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x200;
            *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffffe0ff;
            *(vu16 *) 0x5000400 = 0;
            *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
            *(vu16 *) 0x4000050 = 0;
            *(vu16 *) 0x4001050 = 0;
        }
    }
}

void func_0212abdc(void *a, void *b) {
    s32 i;
    Unk0217d404 *p;
    Unk0217d3fc_00_00 *q;
    data_0217d404 = HeapAlloc(a, 0x11c);
    data_0217d404->mUnk_038 = b;
    MemFill(data_0217d404->mUnk_03c, 0, 0x20);
    data_0217d404->mUnk_024 = 0;
    for (i = 0; i < 5; i++) {
        data_0217d404->mUnk_000[i] = 0;
    }
    switch (func_0205e0a0()) {
        case 1:
            if ((u32) (data_021759d0->mUnk_20 - 1) <= 1) {
                data_0217d404->mUnk_000[0] = 1;
            }
            break;
        case 6:
        case 13:
            data_0217d404->mUnk_000[0] = 1;
            break;
        case 12:
            data_0217d404->mUnk_000[4] = 1;
            break;
        case 10:
            if (data_021759d0->mUnk_20 == 3) {
                data_0217d404->mUnk_000[1] = 1;
                data_0217d404->mUnk_000[4] = 1;
            } else if ((u32) (data_021759d0->mUnk_20 - 1) <= 1) {
                data_0217d404->mUnk_000[0] = 1;
            }
            break;
        case 8:
            if (data_021759d0->mUnk_20 == 3) {
                data_0217d404->mUnk_000[1] = 1;
                data_0217d404->mUnk_000[4] = 1;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        data_0217d404->mUnk_014[i] = -1;
    }
    func_0212aaa4();
    for (i = 0; i < 2; i++) {
        p = data_0217d404;
        q = &p->mUnk_10c[i];
        q->mUnk_00 = ((p->mUnk_028[i].mUnk_00 & 0x1ff) << 16) | ((p->mUnk_028[i].mUnk_04 & 0xff) | 0x40000000);
        q->mUnk_04 = (0x400 - (i + 1) * 4) | 0xd000;
    }
}
#pragma thumb off
