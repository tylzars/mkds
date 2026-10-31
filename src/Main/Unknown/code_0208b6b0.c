#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0208aea8.h"

void func_0208b710(Unk0201ca6c *param_1) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    func_020184e4((Unk020184e4 *) v1, param_1);
}

void func_0208b6d0(Unk0201ca6c **param_1) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    func_020184e4((Unk020184e4 *) v1, *param_1);
    *param_1 = 0;
}

void func_0208b6b0(void **p0) {
    *(u32 *) ((u8 *) *p0 + 36) = (*(u32 *) ((u8 *) *p0 + 36) & ~0x1u) | 0x1u;
    *p0 = 0;
}
