#include "00/code_0218db48.h"
#include "code_02134d30.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dc44.h"

void *func_ov000_0218dbf8(void *param_1, s32 param_2) {
    Unk0218dc94 *a = param_1;
    if (param_2 < 0 || param_2 >= a->mUnk_00) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0x94);
    }
    if (param_2 < 0 || param_2 >= a->mUnk_00) {
        return NULL;
    }
    return a->mUnk_14 + a->mUnk_08 * param_2;
}

void func_ov000_0218dbc0(void *param_1, void *param_2) {
    Unk0218dc94 *a = param_1;
    if (a == NULL) {
        func_0213442c(data_ov000_021b2334, data_ov000_021b22dc, NULL, 0xa0);
    }
    if (a != NULL) {
        func_ov000_0218db48(a, param_2, a->mUnk_00);
    }
}

void func_ov000_0218db48(void *param_1, void *param_2, s32 param_3) {
    Unk0218dc94 *a = param_1;
    s32 b;
    if (param_3 < 0 || param_3 > a->mUnk_00) {
        func_0213442c(data_ov000_021b2314, data_ov000_021b22dc, NULL, 0xa7);
    }
    if (a->mUnk_00 == a->mUnk_04) {
        func_ov000_0218dd38(a);
    }
    a->mUnk_00 = a->mUnk_00 + 1;
    b = a->mUnk_00 - 1;
    if (param_3 < b) {
        memmove(func_ov000_0218dbf8(a, param_3 + 1), func_ov000_0218dbf8(a, param_3), a->mUnk_08 * (b - param_3));
    }
    func_ov000_0218dd18(a, param_2, param_3);
}
