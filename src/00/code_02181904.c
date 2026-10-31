#include "00/code_02181904.h"
#include "Main/Unknown/code_02125f54.h"

void func_ov000_02181940(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125fc0();
        return;
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        v1 = func_02125f60();
        if (v1 == 0) {
            func_0211fd28();
            data_ov000_021b4c6c->mUnk_04 = 7;
            return;
        }
        data_ov000_021b4c6c->mUnk_04 = 1;
    }
}

void func_ov000_02181904(void) {
    int v1;
    v1 = func_ov000_021806c4();
    if ((v1 == -1) && (data_ov000_021b4c6c->mUnk_10 == 10)) {
        func_ov000_021806b8((u32) 0);
    }
    v1 = func_0211fd68();
    if (v1 != 1) {
        *(u32 *) ((int) data_ov000_021b4c6c + 0x10) = 10;
    }
}
