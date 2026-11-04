#include "00/code_021aa7b4.h"
#include "00/code_021aa7f8.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

void func_ov000_021aa7b4(Unk021a998c_0c *a) {
    u8 v1[16];
    u8 v2[16];
    u8 v3[16];
    func_ov000_021aa7f8(v1, data_ov000_021b4a58, a);
    func_ov000_021aa7f8(v2, data_ov000_021b4a5c, a);
    func_ov000_021aa7f8(v3, data_ov000_021b4a60, a);
    MemCopy(v1, a->mUnk_000->mUnk_20, 0x30);
    return;
}
