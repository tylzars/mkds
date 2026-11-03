#include "00/code_021aa004.h"
#include "00/code_021adbac.h"
#include "code_0214d018.h"

u32 func_ov000_021aa004(u8 *a, s32 b, Unk021a998c *c) {
    u8 *v1;
    u32 v2;
    do {
        v1 = func_ov000_021adfc8(&v2, c);
        if (v2 == 0) {
            return 0xffffffff;
        }
        if (v2 > b) {
            v2 = b;
        }
        func_0214d1fc(v1, a, v2);
        func_ov000_021adf30(v2, c);
        a = a + v2;
        b = b - v2;
    } while (0 < b);
    return 0;
}
