#include "Main/Unknown/code_02048284.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02165000.h"

#include "code_0200d118.h"
#include "Main/Unknown/code_020483e4.h"
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

#pragma thumb on

void func_02048324(u32 param_1) {
    u32 v1;
    v1 = func_02048474();
    func_0200d9e0((char *) param_1, 0x80, (const char *) data_021650bc, v1, (u32) &data_021650d8);
}

void func_020482f0(u32 param_1, u8 *param_2, int param_3) {
    if (*param_2 != 0) {
        func_0200d9e0((char *) param_1, 0x80, (const char *) data_021650a0, param_2, ((u32 *) &data_02164d28)[param_3],
                      (u32) &data_021650b4);
    }
}

void func_020482ac(int param_1, u8 *param_2, int param_3) {
    u32 v1;
    if (*param_2 != 0) {
        v1 = func_02048474();
        func_0200d9e0((char *) param_1, 0x80, (const char *) data_02165080, param_2, ((u32 *) &data_02164d28)[param_3],
                      v1, (u32) &data_02165098);
    }
}

void func_02048284(u32 param_1, u32 param_2) {
    u32 v1;
    v1 = func_02048474();
    func_0200d9e0((char *) param_2, 0x80, (const char *) data_02165074, param_1, v1);
}

#pragma thumb off
