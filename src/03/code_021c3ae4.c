#include "03/code_021c3ae4.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf334.h"
#include "03/code_021c2120.h"
#include "03/code_021c391c.h"
#include "03/code_021c3a7c.h"
#include "03/code_021cdc10.h"
#include "code_02151868.h"

void func_ov003_021c3ae4(void) {
    Unk021510a4 a;
    switch (func_ov003_021bf334()) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_02151910(&a);
            if (data_ov003_021da1ac != 0 && a.mUnk_00 == 0) {
                func_ov003_021cdc10(9);
                func_ov003_021bf310(-1);
                return;
            }
            func_ov003_021cdc10(6);
            func_ov003_021c391c();
            data_ov003_021da1b0[0] = 1;
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021c3ac4);
}
