#include "Main/Unknown/code_02037a20.h"
#include "Main/Unknown/code_02039774.h"
#include "code_0200f5ac.h"
#include "code_0214a748.h"

void func_02037a94(void) {
    func_02039b24();
    data_021755a0 = 0;
}

void func_02037a40(void) {
    Unk021755a0 *p;
    u64 t;
    p = data_021755a0;
    t = func_0200f5ac();
    p->mUnk_bc = t;
    if (p->mUnk_0a == 1) {
        func_0214a9d0();
    }
    if (data_usa_02175584 != 0) {
        data_usa_02175584(0);
    }
}

u32 func_02037a20(void) {
    return (data_021755a0->mUnk_d8 & 2) ? 1 : 0;
}
