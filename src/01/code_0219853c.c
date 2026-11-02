#include "01/code_0219853c.h"
#include "01/code_02198854.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02128244.h"
#include "01/code_02192e78.h"
#include "01/code_02192000.h"
#include "01/code_02199000.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0212b000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125f54.h"

void func_ov001_021987d4(void *heap, s16 a) {
    Unk02125de0Arg arg;

    data_ov001_021a9be4 = func_02036bec(heap, 0x18);
    data_ov001_021a9be4->mUnk_08 = heap;
    data_ov001_021a9be4->mUnk_10 = func_021250b0(heap);
    arg.mUnk_00 = 1;
    arg.mUnk_04 = func_020b403c(1);
    arg.mUnk_08 = 0;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = 0;
    arg.mUnk_18 = 0;
    arg.mUnk_1c = 1;
    arg.mUnk_20 = 1;
    arg.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(heap, &arg);
    data_ov001_021a9be4->mUnk_0c = a;
    data_ov001_021a9be4->mUnk_0e = -1;
    data_ov001_021a9be4->mUnk_00 = 0;
    data_ov001_021a9be4->mUnk_04 = data_ov001_021a9be4->mUnk_00;
    data_ov001_021a9be4->mUnk_14 = func_02047a28("common.bmg");
}

void func_ov001_021987bc(void) {
    func_02125da0();
    *(u32 *) &data_ov001_021a9be4 = 0;
    return;
}

void func_ov001_02198768(void) {
    void *a;
    void *b;
    void *c;
    if (func_02036c5c() != 0) {
        data_ov001_021a9be4->mUnk_04 = 1;
        a = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0xc);
        b = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0);
        c = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 1);
        func_0212611c(a, b, c, 0);
    }
}

void func_ov001_021986e8(void) {
    void *a;
    void *b;
    void *c;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            data_ov001_021a9be4->mUnk_04 = 2;
            a = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0xd);
            b = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0);
            c = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 1);
            func_0212611c(a, b, c, 0);
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_02198624(void) {
    void *a;
    void *b;
    void *c;
    u8 *d;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            d = data_021759d0->mUnk_2a;
            data_0217aa08->mUnk_00->mUnk_31_0 = 1;
            func_0214d168(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
            func_0214d1fc(d, data_0217aa08->mUnk_00->mUnk_0c, 0x14);
            func_02056d40();
            data_ov001_021a9be4->mUnk_04 = 3;
            a = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0x13);
            b = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 0);
            c = GetBmgEntry(data_ov001_021a9be4->mUnk_14, 1);
            func_0212611c(a, b, c, 1);
        } else {
            data_ov001_021a9be4->mUnk_0e = 0xe;
        }
    }
}

void func_ov001_021985b0(void) {
    s32 v;
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                v = data_021759d4->mUnk_10;
            } else {
                v = 0;
            }
        } else {
            v = 1;
        }
        if (v == 0) {
            if (func_02125f60() == 0) {
                data_ov001_021a9be4->mUnk_0e = 3;
            } else {
                data_ov001_021a9be4->mUnk_0e = 0;
            }
        }
    }
}

void func_ov001_02198554(void) {
    func_02125928();
    data_ov001_021a9be4->mUnk_00 = data_ov001_021a9be4->mUnk_04;
    switch (data_ov001_021a9be4->mUnk_00) {
        case 0:
            func_ov001_02198768();
            break;
        case 1:
            func_ov001_021986e8();
            break;
        case 2:
            func_ov001_02198624();
            break;
        case 3:
            func_ov001_021985b0();
            break;
    }
}

void func_ov001_0219854c(void) {
    func_021258f0();
}

int func_ov001_0219853c(void) {
    return (int) data_ov001_021a9be4->mUnk_0e;
}
