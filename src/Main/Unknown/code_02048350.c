#include "Main/Unknown/code_02048350.h"
#include "code_0200d118.h"
#include "Main/Unknown/code_02048474.h"
#include "00/code_02182fdc.h"

#pragma thumb on

void func_020483a0(char *a) {
    const char *b;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_02165108;
    } else {
        b = data_usa_0216510c;
    }
    func_0200d9e0(a, 0x80, data_usa_02165110, data_usa_021541a8[10].mUnk_00, b, data_usa_02165124);
}

void func_02048350(char *a) {
    const char *b;
    u32 c;

    if (data_0217b488->mUnk_78 == 1) {
        b = data_usa_021650e0;
    } else {
        b = data_usa_021650e4;
    }
    c = func_02048474();
    func_0200d9e0(a, 0x80, data_usa_021650e8, data_usa_021541a8[10].mUnk_00, b, c, data_usa_02165100);
}

#pragma thumb off
