#include "00/code_021ad734.h"
#include "code_0214d018.h"

u8 *func_ov000_021ad734(u8 a, u32 b, u8 *c, u32 d) {
    if (d < b) {
        func_0214d168(c, a, b - d);
        c = c + (b - d);
    }
    return c;
}
