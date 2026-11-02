#include "00/code_02184aa4.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036bec.h"

#include "00/code_02180608.h"
#include "Main/Unknown/code_0202a820.h"
#include "00/code_02182fdc.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_0202a92c.h"
#include "Main/Unknown/code_02029758.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122ae4.h"
#include "Main/Unknown/code_02029890.h"

void func_ov000_02184b68(u32 param_1) {
    int v1;
    u32 v2;
    u32 v3;
    v1 = ((u32) func_02036bec((void *) (param_1), 8));
    *(int *) &data_ov000_021b4c80 = v1;
    *(u32 *) (v1 + 4) = param_1;
    func_ov000_02184b4c();
    v2 = ((u32) func_ov000_021804f4());
    v3 = ((int) func_ov000_021804e0());
    func_0202ab2c((u32) (param_1), (u32) (v2), (u32) (v3));
    func_0212a910(1, 1);
    return;
}

void func_ov000_02184b50(void) {
    func_0202a90c();
    *(u32 *) &data_ov000_021b4c80 = 0;
    return;
}

void func_ov000_02184b4c(void) {
    return;
}

void func_ov000_02184ad0(void) {
    s32 a;
    u8 b;

    a = func_0202a92c();
    if (func_ov000_021806c4() == -1 && (a == 1 || a == 2)) {
        if (func_02122ae4() != 0) {
            func_ov000_021806e0(7);
            return;
        }
        b = data_0217d384->mUnk_1f52;
        func_02029930()->mUnk_c4 = b;
        func_020297bc();
        if ((u32) data_0217b488->mUnk_1c <= 2) {
            func_02045ed0();
            func_020612b0();
            data_0217b488->mUnk_6c = 1;
        }
        func_02029758();
        func_ov000_021806b8(2);
        func_02122728();
    }
}

void func_ov000_02184ac8(void) {
    func_0202a820();
}

void func_ov000_02184aa4(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0e50;
    func_ov000_021806ec(&callbacks);
}
