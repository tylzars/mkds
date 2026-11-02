#include "Main/Unknown/code_0211de00.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0211de34.h"

#pragma thumb on
void func_0211de34(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d36c;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void func_0211de00(u32 a, void *b, void *c, u32 d, u32 e) {
    func_02124748(data_0215ced4[a], data_0217d36c->mUnk_04, data_0217d36c->mUnk_00, data_0217d36c->mUnk_08, e, d, b, c);
}

#pragma thumb off
