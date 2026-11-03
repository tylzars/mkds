#include "Main/Unknown/code_0202dec8.h"
#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_0202dfd4(void *a) {
    Unk02125de0 v;
    u8 *q;
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    data_02174e44 = func_02036bec(a, 0x8dc);
    func_0214d05c_inline(data_02174e44, 0x8dc);
    data_02174e44->mUnk_8d0 = func_02036b74(a, 0xe00, 0x20);
    data_02174e44->mUnk_8d4 = func_02036b74(a, 0x1000, 0x20);
    q = func_02038d88(a, data_usa_02154840);
    func_02038d58(q + 0x28, 1, 0, 0, 0, 0, 1, 0);
    func_02038cd8(q + 0x70, 2, 0, 0, 0, 0xf, 0);
    func_02037abc(q);
    func_0202e274();
    v.mUnk_00 = 1;
    v.mUnk_04 = func_020b403c(1);
    v.mUnk_08 = 1;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = 0;
    v.mUnk_18 = NULL;
    v.mUnk_1c = 1;
    v.mUnk_20 = 1;
    v.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &v);
    func_02125f2c(1);
    func_0212abdc(a, data_02174e44);
    func_021172a8(a);
    for (i = 0; i < 0x20; i++) {
        data_02174e44->mUnk_814[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        data_02174e44->mUnk_894[i] = -1;
    }
    data_02174e44->mUnk_8bc = (u8 *) func_02061644((u32) a);
    func_02061540(data_02174e44->mUnk_8bc);
    func_02057d9c();
    for (i = 0; i < 0x20; i++) {
        e = func_0202e43c(i);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        if (func_0206174c(p + n * 0x30) != 0) {
            data_02174e44->mUnk_814[data_02174e44->mUnk_80c] = i;
            data_02174e44->mUnk_808++;
            data_02174e44->mUnk_80c++;
        }
    }
    data_02174e44->mUnk_8c0 = (u8 *) func_0206152c((u32) a);
    func_02061428(data_02174e44->mUnk_8c0);
    func_02057d9c();
    for (i = 0; i < 10; i++) {
        if (func_0206174c(data_02174e44->mUnk_8c0 + (u8) i * 0x230) != 0) {
            data_02174e44->mUnk_894[data_02174e44->mUnk_810] = i;
            data_02174e44->mUnk_808++;
            data_02174e44->mUnk_810++;
        }
    }
    func_020ae6d4(data_02174e44, data_02174e44->mUnk_404);
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffcfffef) | 0x10;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffcfffef) | 0x10;
    switch (data_0217b488->mUnk_0c) {
        case 0:
            data_02174e44->mUnk_8c8 = 0;
            break;
        case 1:
            data_02174e44->mUnk_8c8 = 1;
            break;
    }
    data_02174e44->mUnk_8cc = data_02174e44->mUnk_8c8;
    data_02174e44->mUnk_8c4 = data_usa_02162f4c[data_02174e44->mUnk_8c8];
    data_02174e44->mUnk_8d8 = func_020369fc(a);
    data_02174e44->mUnk_8c4->mUnk_00(data_02174e44->mUnk_8d8, data_02174e44, data_02174e44->mUnk_404);
}

void func_0202df34(s32 a) {
    s32 b;
    s32 c;
    s32 r;
    Unk02162f4c *p;
    b = data_02174e44->mUnk_8c8;
    c = data_02174e44->mUnk_8cc;
    if (c != b) {
        p = data_02174e44->mUnk_8c4;
        data_02174e44->mUnk_8c4 = data_usa_02162f4c[b];
        data_02174e44->mUnk_8cc = data_02174e44->mUnk_8c8;
        p->mUnk_08();
        data_02174e44->mUnk_8c4->mUnk_00(data_02174e44->mUnk_8d8, data_02174e44, data_02174e44->mUnk_404);
    } else {
        func_020ae6ac(data_02174e44, data_02174e44->mUnk_404);
        r = data_02174e44->mUnk_8c4->mUnk_04(a);
        if (r != -1) {
            data_02174e44->mUnk_8c8 = r;
        }
        func_020ae630(data_02174e44, data_02174e44->mUnk_404);
    }
    func_02125928();
    func_0212a920();
}

void func_0202defc(void) {
    *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 & 0xffff1fff;
    func_02125da0();
    func_0212abd0();
    func_02117218();
    func_0204f7f4();
}

void func_0202dec8(void) {
    func_021258f0();
    data_02174e44->mUnk_8c4->mUnk_0c();
    func_020ae5f0(data_02174e44, data_02174e44->mUnk_404);
}

#pragma thumb off
