#include "Main/Unknown/code_02029440.h"

#pragma thumb on

void func_0202949c(u32 p0) {
    data_02174e1c->mUnk_e0 = p0;
}

void func_0202948c(u32 p0) {
    data_02174e1c->mUnk_fc = (u8) p0;
}

void func_0202947c(u32 p0) {
    data_02174e1c->mUnk_fd = (u8) p0;
}

void func_02029468(u32 p0) {
    data_02174e1c->mUnk_104 = (u16) p0;
}

void func_02029454(u32 p0) {
    *(u8 *) ((u8 *) (u32) (((u32) data_02174e1c)) +
                        0 + (0x10cu)) = (u8) p0;
}

void func_02029440(u32 p0) {
    *(u8 *) ((u8 *) (u32) (((u32) data_02174e1c)) +
                        0 + (0x10du)) = (u8) p0;
}

#pragma thumb off
