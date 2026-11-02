#include "00/code_02181674.h"
#include "Main/Unknown/code_021205f4.h"

#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02061250.h"
#include "00/code_02180c3c.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov000_021816b0(void *a) {
    data_ov000_021b4c68 = func_02036bec(a, 0x40);
    data_ov000_021b4c68->mUnk_1c = a;
    data_ov000_021b4c68->mUnk_00 = 0;
    data_ov000_021b4c68->mUnk_04 = 0;
    data_ov000_021b4c68->mUnk_0c = -1;
    data_ov000_021b4c68->mUnk_08 = 0;
    data_ov000_021b4c68->mUnk_38 = FindSceneFile("wifi.bmg");
    data_ov000_021b4c68->mUnk_3c = func_02047a28("common.bmg");
    func_ov000_021816a0();
    func_0212a910(1, 1);
    func_021281c8(0xe);
    func_0204f804();
}

void func_ov000_021816a4(void) {
    data_ov000_021b4c68 = NULL;
}

void func_ov000_021816a0(void) {
    return;
}

BOOL func_ov000_02181684(void) {
    if (func_02061250() == 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov000_0218167c(void) {
    return func_02061290();
}

u32 func_ov000_02181674(void) {
    u32 value0;
    u32 value3;
    value3 = (u32) &func_021205f4;
    value0 = (u32) func_021205f4();
    return value0;
}
