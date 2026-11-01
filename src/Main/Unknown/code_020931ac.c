#include "Main/Unknown/code_020931ac.h"
#include "Main/Unknown/code_02093270.h"
#include "Main/Unknown/code_0209bef0.h"

void func_02093210(void) {
    func_0209bf1c(&func_02093708, &func_020935fc, &func_020936f0);
}

void func_020931f0(void) {
    func_0209bf48(&func_02093484, &func_02093270, 0);
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
