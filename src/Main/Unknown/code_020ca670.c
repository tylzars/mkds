#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_021000d0.h"

#pragma thumb on
void func_020ca688(u32 a) {
    gEmblemChoises->mUnk_00 = a;
    func_020cac9c();
}
#pragma thumb off

s32 func_020ca670(void) {
    return func_020c0c2c(&data_0217b434, MAP_OBJECT_KIND_SHINE16);
}
