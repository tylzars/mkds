#include "00/code_02198714.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_02198714(u32 *param_1, u32 param_2, u32 param_3) {
    int v1;
    u32 v2;
    v1 = func_ov000_0219a110((u32 *) ((u32 *) (u32) (param_1[2])), (u32) (*param_1), (int) (*(u16 *) (param_1 + 1)),
                                (u32) (param_2), (u32) (param_3));
    if (v1 == 0) {
        return 0;
    }
    v2 = func_ov000_0218e8c4();
    param_1[0x22] = v2;
    return 1;
}
