#include "Main/Unknown/code_0208ec64.h"
#include "code_020172d0.h"

s32 func_0208ec64(u32 param_1) {
    Unk0208ec64 *p;
    p = func_020172d8(&data_0217b08c->mUnk_0c, 0);
    if (p != 0) {
        p->mUnk_14 = param_1;
        p->mUnk_18 = 0;
        p->mUnk_1c = 0x400;
        func_02017354(&data_0217b08c->mUnk_0c, p);
        func_020174a4(&data_0217b08c->mUnk_00, p);
    }
    return (s32) p;
}
