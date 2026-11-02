#include "03/code_021d0680.h"
#include "03/code_021d079c.h"
#include "03/code_021d0388.h"

void func_ov003_021d0680(Unk021425e8 *event) {
    if (event->mUnk_02 != 0) {
        func_ov003_021d079c(event->mUnk_02);
        func_ov003_021d07b0(9);
    } else {
        if (func_ov003_021d0630() == 0) {
            func_ov003_021d07b0(9);
        }
    }
}
