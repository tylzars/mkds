#include "Main/Unknown/code_021025d8.h"

void func_02102668(u32 p0) {
    *(u32 *) ((u8 *) p0 + 368) = (u32) 0x1u;
}

void func_021025d8(int param_1) {
    u32 v1;
    *(u32 *) (param_1 + 0x154) = 0x13;
    *(u32 *) (param_1 + 0x158) = 0;
    v1 = ((u32) (&data_0216c77c));
    *(u32 *) (param_1 + 0x15c) = 0;
    *(u32 *) (param_1 + 0x160) = 0xe;
    func_02046be8((void *) (param_1 + 300), (UnkFunc *const *) v1, 7, (void *) param_1);
    *(u32 *) (param_1 + 0x140) = 8;
    *(u32 *) (param_1 + 0x144) = 0;
    func_020f9c40(param_1);
    *(u32 *) (param_1 + 0x24c) = 0;
    *(u32 *) (param_1 + 0x250) = 0xffffffff;
    *(u32 *) (param_1 + 0x254) = 0x12;
    *(u32 *) (param_1 + 600) = 0xffffffff;
    *(u32 *) (param_1 + 0x25c) = 0x12;
    *(u32 *) (param_1 + 0x260) = 0xffffffff;
    *(u32 *) (param_1 + 0x264) = 0xffffffff;
    *(u32 *) (param_1 + 0x268) = 0;
    *(u32 *) (param_1 + 0x26c) = 0;
    *(u32 *) (param_1 + 0x270) = 0;
}
