#include "Main/Unknown/code_02009adc.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200a000.h"
#include "Main/Unknown/code_0200c3fc.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02142eac.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"

#pragma thumb on

void func_02009c04(void) {
    u32 v1;
    v1 = ((s64) func_0200fca0());
    if (data_0216fdac->mUnk_1320 == 0) {
        func_0200fd1c();
    }
    func_02009c34();
    func_0200fcb4(v1);
}

#pragma thumb off

#pragma thumb on

void func_02009ae8(u32 a) {
    u32 v1;
    u32 v2;
    s32 v3;
    u32 v4;
    func_021436d0(func_0200a7b0, a);
    if (a != 0 && a < 16) {
        v1 = a - 1;
        data_0216fdac->mUnk_148a[v1] = 0;
        func_0214d168(data_0216fdac->mUnk_14a8 + v1, 0, 4);
        func_0214d168(data_0216fdac->mUnk_1340 + v1 * 0x16, 0, 0x16);
        func_0200c3fc(a);
        v2 = 0;
        data_0216fdac->mUnk_1754[v1] = v2;
        v3 = data_0216fdac->mUnk_1526[v1];
        v2 = ~v2;
        if (v3 != v2) {
            v4 = 1 << a;
            v3 = (u8) v3;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d4e &= ~v4;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d50 |= v4;
            data_0216fdac->mUnk_1526[a - 1] = v2;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d4c &= ~v4;
        }
        if ((data_0216fdac->mUnk_1536 & (1 << a)) != 0) {
            data_0216fdac->mUnk_1535--;
            data_0216fdac->mUnk_1536 &= ~(1 << a);
        }
        data_0216fdac->mUnk_14e8[v1] = 0;
    }
}

#pragma thumb off

#pragma thumb on
void func_02009adc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0216fdc0;
    *(u16 *) ((value1) + 6u) = (u16) value0;
}
#pragma thumb off
