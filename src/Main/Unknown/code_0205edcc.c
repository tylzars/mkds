#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057764.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0205edf8(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217aa08;
    value12 = (u32) &func_020577b4;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (32));
    func_020577b4((void *) value0);
}

void func_0205edcc(void) {
    u32 value0;
    value0 = (u32) &data_0217aa08;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (32));
    func_020577b4((void *) value0);
    func_020574a0();
}
