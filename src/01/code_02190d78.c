#include "01/code_02190d78.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_021882b8.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

void func_ov001_02190df0(void) {
    func_ov001_021882b8();
}

s32 func_ov001_02190d78(Unk02188950 *param_1) {
    Unk02188950 *v1;
    Unk02188950 *v2;

    v1 = data_021759c0->mUnk_08 == 4
             ? (Unk02188950 *) func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0;
    v2 =
        data_021759c0->mUnk_08 == 4
            ? (Unk02188950 *) func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
            : 0;
    if (func_ov001_021871f8(v1, 3) != 0 && func_ov001_021871f8(v2, 3) != 0) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}
