#include "Main/Unknown/code_02078ee0.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020790e0.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02078580.h"
#include "code_02012b30.h"

#pragma thumb on

void func_02079078(void *a, void *b, void *c, Unk020136f0 *d, Unk020136f0 *e, void *f) {
    u32 v2;
    u32 v3;
    void *v1;
    v2 = (u32) func_02084d3c(b, d, e);
    func_020849c0(b, 3);
    func_0207a14c((Unk0201290c *) v2, (u32) 1);
    func_0208823c(0, c, b, 1, a, NULL);
    v1 = func_02013a4c(func_02013a30(f), 0);
    v3 = func_0207b8dc(2);
    func_020881b0(c, 0, v1, v3, a);
    func_02087f84(c, 0);
}

void func_02079038(void *a, Unk020136f0 *b, Unk020136f0 *c) {
    Unk0201290c *v1;
    u32 v2;
    v1 = func_02084d3c(a, b, c);
    func_020849c0(a, 3);
    func_0207a14c(v1, 1);
    v2 = func_02013754((u8 *) v1 + v1->mEntriesOffset + 4, data_02155098);
    func_02013468(v1, v2, 0);
}

void func_02079014(void *a, Unk020136f0 *b, Unk020136f0 *c) {
    u32 v1;
    v1 = (u32) func_02084d3c(a, b, c);
    func_020849c0(a, 3);
    func_0207a14c((Unk0201290c *) v1, (u32) 1);
}

#pragma thumb off

#pragma thumb on

void *func_02079008(void *a, void *b) {
    return func_0207afa8(a, b, 3);
}

void func_02078f9c(void *c) {
    void *a;
    void *b;
    LoadKartModelMenuFile(c, data_usa_02165760, &a);
    LoadKartModelMenuFile(c, data_usa_0216577c, &b);
    data_0217ad08->mUnk_1cc = HeapAlloc(c, 0x6c);
    func_02084d3c(data_0217ad08->mUnk_1cc, a, b);
    func_020849c0(data_0217ad08->mUnk_1cc, 2);
    func_02012ffc(data_0217ad08->mUnk_1cc->mUnk_04, 1);
}

#pragma thumb off

#pragma thumb on

void func_02078f78(Unk020136f0 *a) {
    data_0217ad08->mUnk_1d4 = func_020136f0(a);
    func_02012cbc(a);
}

void func_02078f18(void *a, int b) {
    u32 v1;
    func_02079a3c((u32 *) ((u32 *) (u32) b));
    *(u32 *) (b + 0xb0) = (u32) data_021759d0->mUnk_00;
    *(u32 *) (b + 0xb4) = 0;
    v1 = ((u32) HeapAlloc(a, (u32) 0x6c));
    *(u32 *) (b + 0x10) = v1;
    v1 = ((u32) HeapAlloc(a, (u32) 0x6c));
    *(u32 *) (b + 0x14) = v1;
    v1 = ((u32) HeapAlloc(a, (u32) 0x6c));
    *(u32 *) (b + 0x18) = v1;
    v1 = ((u32) HeapAlloc(a, (u32) 0x74));
    *(u32 *) (b + 0x1c) = v1;
    v1 = ((u32) HeapAlloc(a, (u32) 0x38));
    *(u32 *) (b + 8) = v1;
}

void func_02078ee0(Unk0217ad08_024 *a, int b) {
    u32 v1;
    v1 = 0;
    a->mUnk_00 = 0xffffffff;
    a->mUnk_04 = 0xffffffff;
    a->mUnk_08 = 0x1000;
    a->mUnk_16 = 0xeaab;
    a->mUnk_14 = a->mUnk_16;
    a->mUnk_18 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0xffffff88;
    if (b != 0) {
        v1 = 0xffffff06;
    }
    a->mUnk_2c = v1;
    a->mUnk_30 = 0;
}

#pragma thumb off
