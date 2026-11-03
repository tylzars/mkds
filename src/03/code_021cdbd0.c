#include "03/code_021cdbd0.h"
#include "code_0212bcac.h"
#include "03/code_021d3000.h"

#include "03/unk_021da000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021cdbc8.h"
#include "03/code_021d3488.h"
#include "code_0212ba68.h"
#include "code_0212d254.h"
#include "code_0212df7c.h"

void func_ov003_021cdc4c(void) {
    u32 a;
    data_ov003_021da274 = func_ov003_021d285c(0x9c, 4);
    data_ov003_021da274->mUnk_94 = func_ov003_021d14b8(data_ov003_021d77d4, &a, 0x20);
    func_0212baa8();
    func_0212d5f8(&data_ov003_021da274->mUnk_00, data_ov003_021da274->mUnk_94);
    func_0212edac(NULL);
    func_0212c6a0(&data_ov003_021da274->mUnk_90);
    data_ov003_021da274->mUnk_98 = func_ov003_021d3544(0, func_ov003_021cdbc8, NULL, 0xc8);
}

void func_ov003_021cdc28(void) {
    func_ov003_021d34c8(0, data_ov003_021da274->mUnk_98);
    func_ov003_021d2808(&data_ov003_021da274);
    return;
}

void func_ov003_021cdc10(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (value0) + (0u);
    value0 = (u32) &data_ov003_021da274;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value0) + 144u;
    value1 = 0u;
    value3 = (u32) &func_0212ecc0;
    value0 = (u32) func_0212ecc0((const void *) value0, value1, value2);
    return;
}

u32 func_ov003_021cdbfc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &data_ov003_021da274;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value0) + 144u;
    value3 = (u32) &func_0212c678;
    value0 = (u32) func_0212c678((Unk0212c400 **) value0, value1);
    return value0;
}

void func_ov003_021cdbe4(u32 first, u32 second) {
    func_0212c524((Unk0212c400 **) ((u8 *) data_ov003_021da274 + 0x90), first, second);
}

void func_ov003_021cdbd0(void) {
    func_0212c6f0((Unk0212c400 **) ((u8 *) data_ov003_021da274 + 0x90), 0);
}
