#include "00/code_0218e2dc.h"
#include "00/unk_021b2000.h"
#include "code_0200f5ac.h"
#include "code_0213442c.h"

#pragma opt_propagation off

u32 func_ov000_0218e320(u32 *param_1) {
    u32 a;
    if (func_0200f6e4() != 1) {
        func_0213442c(data_ov000_021b23b0, data_ov000_021b23d0, NULL, 0x667);
    }
    a = (func_0200f5ac() << 6) / 0x1ff6210;
    if (param_1 != NULL) {
        *param_1 = a;
    }
    return a;
}

u32 func_ov000_0218e2dc(u32 param_1) {
    u32 a = (param_1 & 0xffff) * 0x41a7;
    u32 b = (param_1 >> 16) * 0x41a7;
    u32 c = a + ((b & 0x7fff) << 16);
    if (c > 0x7fffffff) {
        c = (c & 0x7fffffff) + 1;
    }
    c += b >> 15;
    if (c > 0x7fffffff) {
        c = (c & 0x7fffffff) + 1;
    }
    return c;
}
