#include "00/code_0218da9c.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02134d30.h"

void func_ov000_0218da9c(int *param_1, int param_2) {
    s32 v1;
    if (param_2 < 0 || param_2 >= *param_1) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, 0, 0xc0);
    }
    v1 = *param_1 - 1;
    if (param_2 < v1) {
        func_02134df8(func_ov000_0218dbf8(param_1, param_2), func_ov000_0218dbf8(param_1, param_2 + 1),
                      param_1[2] * (v1 - param_2));
    }
    *param_1 = *param_1 - 1;
}
