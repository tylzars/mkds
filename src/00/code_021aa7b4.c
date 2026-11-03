#include "00/code_021aa7b4.h"
#include "00/code_021aa7f8.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

void func_ov000_021aa7b4(int *a) {
    u8 v1[16];
    u8 v2[16];
    u8 v3[16];
    func_ov000_021aa7f8(v1, data_ov000_021b4a58, (Unk021a998c_0c *) (a));
    func_ov000_021aa7f8(v2, data_ov000_021b4a5c, (Unk021a998c_0c *) (a));
    func_ov000_021aa7f8(v3, data_ov000_021b4a60, (Unk021a998c_0c *) (a));
    func_0214d1fc((const void *) ((u16 *) (void *) (v1)), (void *) ((u32 *) (u32) (*a + 0x20)), 0x30);
    return;
}
