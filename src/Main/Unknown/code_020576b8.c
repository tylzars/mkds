#include "Main/Unknown/code_0204b418.h"
#include "Main/Unknown/code_0204b6cc.h"
#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02057710(void *a, s32 b) {
    s32 c = b * 0xb00;
    u32 *v;
    v = data_021759d4->mUnk_60;
    if (data_021759d4->mUnk_0c != 0) {
        func_0214d1fc(a, v, 0xb00);
        v[0] = 0x45464b4e;
        func_0204b430(c + 0x2b00, c + 0x33a00, v, 0xb00, NULL, 0);
    }
}

void func_020576b8(void *a, s32 b) {
    s32 c = b * 0xb00;
    if (data_021759d4->mUnk_0c != 0) {
        data_021759d4->mUnk_68 = a;
        data_021759d4->mUnk_5c = -1;
        func_0204b6cc(c + 0x2b00, c + 0x33a00, data_021759d4->mUnk_60, 0xb00, func_02057cfc, 0x45464b4e, 0);
    }
}

#pragma thumb off
