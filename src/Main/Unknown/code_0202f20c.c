#include "Main/Unknown/code_0202f20c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_0202f498.h"
#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"

#pragma thumb on

void func_0202f20c(void *a) {
    s32 v1 = data_02174e4c->mUnk_810;
    Unk02174e4c_80c *v2;

    if (data_02174e4c->mUnk_814 != v1) {
        v2 = data_02174e4c->mUnk_80c;
        data_02174e4c->mUnk_80c = data_02163260[v1];
        data_02174e4c->mUnk_814 = data_02174e4c->mUnk_810;
        v2->mUnk_08();
        data_02174e4c->mUnk_80c->mUnk_00(data_02174e4c->mUnk_808, data_02174e4c, data_02174e4c->mUnk_404);
    } else {
        func_020ae6ac(data_02174e4c, data_02174e4c->mUnk_404);
        v1 = data_02174e4c->mUnk_80c->mUnk_04(a);
        if (v1 != -1) {
            data_02174e4c->mUnk_810 = v1;
        }
        func_0212a920();
        func_020ae630(data_02174e4c, data_02174e4c->mUnk_404);
    }
    if (func_0202f19c() == 0) {
        func_02125928();
    }
}

void func_0202f2b4(void *a) {
    Unk02180774 *b;
    Unk02125de0 v1;

    data_02174e4c = HeapAllocAligned(a, 0x874, 0x20);
    func_0202f51c(data_02174e4c, 0x874);
    b = func_02038d88(a, data_02154818);
    func_0202f4e0(b, 0, 0, 0, 0, 0xc, 0, 0);
    func_0202f4ac(b, 2, 0, 0, 0, 0xf, 6);
    func_02037abc(b);
    if (func_0202f19c() == 0) {
        v1.mUnk_00 = 1;
        v1.mUnk_04 = func_020b403c(1);
        v1.mUnk_08 = 0;
        v1.mUnk_0c = 1;
        v1.mUnk_10 = 0;
        v1.mUnk_14 = 0;
        v1.mUnk_18 = NULL;
        v1.mUnk_1c = 1;
        v1.mUnk_20 = func_0202f498() == 0;
        v1.mUnk_24 = 0;
        LoadTxtSystemAndSelectChoisesAndSelectReturnData();
        func_02125de0(a, &v1);
    }
    func_0212abdc(a, data_02174e4c);
    switch (func_0202f498()) {
        case 0:
            data_02174e4c->mUnk_810 = func_0202f19c() != 0 ? 4 : 0;
            func_0203b0f8(a);
            func_02053d00();
            break;
        case 1:
            data_02174e4c->mUnk_810 = 5;
            func_0203b1fc(a);
            break;
        case 2:
            data_02174e4c->mUnk_810 = 6;
            func_0203b1c8(a);
            break;
        case 3:
            data_02174e4c->mUnk_810 = 7;
            func_0203b194(a);
            break;
    }
    data_02174e4c->mUnk_814 = data_02174e4c->mUnk_810;
    data_02174e4c->mUnk_80c = data_02163260[data_02174e4c->mUnk_810];
    data_02174e4c->mUnk_808 = CreateExpHeapFromMaxFree(a);
    if (func_0202f19c() == 0) {
        func_0202f554();
    }
    func_020ae6d4(data_02174e4c, data_02174e4c->mUnk_404);
    func_0202f478(0x10);
    func_0202f454(0x10);
    data_02174e4c->mUnk_80c->mUnk_00(data_02174e4c->mUnk_808, data_02174e4c, data_02174e4c->mUnk_404);
}

#pragma thumb off

void func_0202f454(u32 v) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | v;
}

void func_0202f478(u32 v) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | v;
}
