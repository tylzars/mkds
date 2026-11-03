#include "00/code_021a998c.h"
#include "00/code_021ae214.h"
#include "00/code_021ae314.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021ae228(Unk021a998c *a) {
    u32 v1;
    v1 = func_ov000_021ae314();
    a->mUnk_28 = v1;
    a->mState = 1;
    a->mUnk_04 = 1;
    func_0200e01c(NULL);
}

void func_ov000_021ae214(Unk021a78a4Func a) {
    u8 *v1;
    v1 = *(u8 **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != NULL) {
        *(Unk021a78a4Func *) (v1 + 0x38) = a;
    }
}
