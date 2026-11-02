#include "00/code_021ad36c.h"

u32 func_ov000_021ad36c(void) {
    u32 v1;
    int v2;
    int v3;
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0x44, (u16) (0x43), 0xffffffff);
    v3 = 0;
    do {
        v1 = func_ov000_021ad6c0();
        v2 = func_ov000_021ad3b8(v1, v3);
        if (v2 == 1) {
            break;
        }
        v3 = v3 + 1;
    } while (v3 < 4);
    func_ov000_021ae258();
    if (v2 == 1) {
        return 1;
    }
    return 0;
}
