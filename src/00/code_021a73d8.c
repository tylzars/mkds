#include "00/code_021a6d6c.h"
#include "00/code_021a72c4.h"
#include "00/code_021a73d8.h"

s32 func_ov000_021a73d8(Unk021b49b8 *a) {
    Unk021a6fa8 *v1;
    Unk021a7064 *v2;
    v1 = func_ov000_021a732c(a);
    if (v1 == NULL) {
        return -0x31;
    }
    v2 = func_ov000_021a7064(func_ov000_021a7378, v1, 1);
    func_ov000_021a6f84(v1, v2);
    return (s32) v1;
}
