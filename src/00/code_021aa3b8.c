#include "00/code_021aa3b8.h"

// non-matching: 44 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours `push {r4, r5, r6, r7, lr}`
void func_ov000_021aa3b8(int param_1, int param_2) {
    int v1;
    u8 v2[20];
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + 0x378)), (void *) ((u32 *) (u32) (param_1 + 0x3d0)),
                  (u32) 0x58);
    func_ov000_021aa50c((Unk021a998c_0c *) param_1, v2, (u32) 1);
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + 0x3d0)), (void *) ((u32 *) (u32) (param_1 + 0x378)),
                  (u32) 0x58);
    v1 = memcmp((const u8 *) param_2, (const u8 *) v2, 0x10);
    if (v1 != 0) {
        *(u8 *) (param_1 + 0x429) = 9;
        return;
    }
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + 0x2c0)), (void *) ((u32 *) (u32) (param_1 + 0x31c)),
                  (u32) 0x5c);
    func_ov000_021aa468((Unk021a998c_0c *) param_1, v2, (u32) 1);
    func_0214d1fc((const void *) ((u16 *) (u32) (param_1 + 0x31c)), (void *) ((u32 *) (u32) (param_1 + 0x2c0)),
                  (u32) 0x5c);
    v1 = memcmp((const u8 *) (param_2 + 0x10), (const u8 *) v2, 0x14);
    if (v1 != 0) {
        *(u8 *) (param_1 + 0x429) = 9;
        return;
    }
    *(u8 *) (param_1 + 0x429) = 6;
}
