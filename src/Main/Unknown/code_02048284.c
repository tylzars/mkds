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

void func_02048324(u32 a) {
    u32 v1;
    v1 = func_02048474();
    func_0200d9e0((char *) a, 0x80, data_021650bc, v1, (u32) &data_021650d8);
}

void func_020482f0(u32 a, const char *b, int c) {
    if (*b != 0) {
        func_0200d9e0((char *) a, 0x80, data_021650a0, b, ((u32 *) &data_02164d28)[c], (u32) &data_021650b4);
    }
}

void func_020482ac(int a, u8 *b, int c) {
    u32 v1;
    if (*b != 0) {
        v1 = func_02048474();
        func_0200d9e0((char *) a, 0x80, data_02165080, b, ((u32 *) &data_02164d28)[c], v1, (u32) &data_02165098);
    }
}

void func_02048284(u32 a, u32 b) {
    u32 v1;
    v1 = func_02048474();
    func_0200d9e0((char *) b, 0x80, data_02165074, a, v1);
}

#pragma thumb off
