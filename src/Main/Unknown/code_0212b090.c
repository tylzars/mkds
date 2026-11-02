#include "Main/Unknown/code_0212b090.h"

#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02023000.h"
#include "code_021488e8.h"

#pragma thumb on
void func_0212b158(void *a) {
    Unk0217d408 *p;
    Unk02180728 *q;
    p = func_02036bec(a, 0x1a44);
    data_0217d408 = p;
    func_02023408(p->mUnk_0014, p->mUnk_0044, 0x20, 5, 4);
    p = data_0217d408;
    q = &p->mUnk_0034;
    p->mUnk_0034.mUnk_00 = p->mUnk_0014;
    q->mUnk_04 = NULL;
    q->mUnk_08 = 1;
    q->mUnk_0c = 2;
    func_0212b144();
}

void func_0212b144(void) {
    data_0217d408->mUnk_000c = 0;
    data_0217d408->mUnk_0010 = -1;
}

s32 func_0212b0b8(void) {
    Unk0217d408 *p;
    if (data_0217d408->mUnk_000c == 0) {
        return -1;
    }
    func_02148908((u16 *) 0x400006c, 0);
    func_02148908((u16 *) 0x400106c, 0);
    if ((u16) (data_021755dc.mUnk_00 & 1) != 0) {
        p = data_0217d408;
        if (p->mUnk_0004 != 0) {
            if ((u32) (p->mUnk_0000 - 4) <= 1) {
                data_0217b488->mUnk_58 = 1;
                data_0217d408->mUnk_0010 = 1;
            } else if (p->mUnk_0000 == 6) {
                data_0217b488->mUnk_1c = 1;
                data_0217d408->mUnk_0010 = 1;
                func_02120610();
            } else {
                p->mUnk_0010 = 0;
            }
        }
    }
    return data_0217d408->mUnk_0010;
}
#pragma thumb off

#pragma thumb on
void func_0212b09c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value0 = (u32) &data_0217d408;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (value0) + 68u;
    value1 = 0u;
    value2 = 0x1400u;
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, value2);
}
#pragma thumb off

#pragma thumb on

void *func_0212b090(void) {
    return data_0217d408->mUnk_0044;
}

#pragma thumb off
