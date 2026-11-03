#include "Main/Unknown/code_020931ac.h"
#include "Main/Unknown/code_0209b000.h"

#include "Main/Unknown/code_02093270.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209bf70.h"

void func_02093234(void) {
    func_0209bf70(&func_02093754, NULL, NULL, 2, 0, ((u32) 0x0000018du));
}

void func_02093210(void) {
    func_0209bf1c(&func_02093708, &func_020935fc, &func_020936f0);
}

void func_020931f0(void) {
    func_0209bf48(&func_02093484, &func_02093270, NULL);
}

u16 func_020931ac(Unk0217b498_00 *a) {
    if (a->mUnk_a8 >= 0x1000) {
        return 3;
    }
    if (a->mUnk_a8 >= 0x99a) {
        return 2;
    }
    return a->mUnk_a8 >= 0x4cd;
}
