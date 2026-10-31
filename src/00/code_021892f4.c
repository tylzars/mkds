#include "00/code_021892f4.h"

u32 func_ov000_021892f4(u8 *param_1) {
    u8 v1;
    int v2;
    v1 = *param_1;
    if (v1 <= 10) {
        v2 = func_ov000_02189280();
        if (v2 == 1) {
            *param_1 = 0;
            return 1;
        }
        if (v2 == -1) {
            *param_1 = 0x12;
            return 1;
        }
    } else if (v1 == 0xe) {
        func_ov000_02187fb8();
        func_ov000_02188068();
        *param_1 = 0xc;
    } else if ((v1 < 0x12) && (v2 = func_ov000_0218925c(), v2 == 1)) {
        *param_1 = 10;
    }
    return 0;
}
