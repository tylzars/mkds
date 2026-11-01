#include "03/code_021d1f70.h"
#include "03/code_021d1da8.h"

u8 func_ov003_021d1f70(int param_1) {
    Unk021d1da8 *v1;
    if (param_1 == 1) {
        v1 = data_ov003_021da2c0;
    } else {
        v1 = data_ov003_021da2c0 + 1;
    }
    return v1->mEnabled;
}
