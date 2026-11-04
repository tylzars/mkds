#include "00/code_021acfd8.h"
#include "00/code_021ad018.h"
#include "00/code_021ad734.h"

u32 func_ov000_021acfd8(const char *a, int b, u32 c) {
    u32 v1;
    if (b == 0) {
        return 0xffffffff;
    }
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0, 0x35, b);
    v1 = func_ov000_021ad0a4(a, 1, (u32) (c));
    func_ov000_021ae258();
    return v1;
}
