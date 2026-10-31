#include "00/code_021acfd8.h"

u32 func_ov000_021acfd8(const char *param_1, int param_2, u32 param_3) {
    u32 v1;
    if (param_2 == 0) {
        return 0xffffffff;
    }
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0, (u16) (0x35), (int) (param_2));
    v1 = func_ov000_021ad0a4(param_1, 1, (u32) (param_3));
    func_ov000_021ae258();
    return v1;
}
