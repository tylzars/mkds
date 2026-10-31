#include "Main/Unknown/code_02029520.h"

#pragma thumb on

u32 func_020296e4(void) {
    return ((u32) data_02174e1c->mUnk_d0);
}

u32 func_020296d4(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mUnk_00);
}

u32 func_020296c0(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mUnk_04);
}

u32 func_020296ac(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mUnk_08);
}

u32 func_0202969c(void) {
    return ((u32) data_02174e1c->mUnk_d4);
}

u32 func_0202968c(void) {
    return ((u32) data_02174e1c->mUnk_cc);
}

u32 func_0202967c(void) {
    return ((u32) data_02174e1c->mUnk_d8);
}

u32 func_0202966c(void) {
    return ((u32) data_02174e1c->mUnk_c0);
}

u32 func_0202965c(void) {
    return ((u32) data_02174e1c->mUnk_f0);
}

u32 func_0202964c(void) {
    return ((u32) data_02174e1c->mUnk_e8);
}

u32 func_0202963c(void) {
    return ((u32) data_02174e1c->mUnk_ec);
}

u32 func_0202962c(void) {
    return ((u32) data_02174e1c->mUnk_dc);
}

u32 func_02029618(u16 p0) {
    return ((u32) data_02174e1c->mUnk_00[p0].mUnk_0c);
}

u32 func_02029608(void) {
    return ((u32) data_02174e1c->mUnk_fc);
}

u32 func_020295f8(void) {
    return ((u32) data_02174e1c->mUnk_fd);
}

u32 func_020295e4(void) {
    return ((u32) *(
        const u8 *) ((u8 *) (u32) (((u32) data_02174e1c)) +
                                0 + (0x10cu)));
}

u32 func_020295d0(void) {
    return ((u32) *(
        const u8 *) ((u8 *) (u32) (((u32) data_02174e1c)) +
                                0 + (0x10du)));
}

void func_020295c0(u32 p0) {
    data_02174e1c->mUnk_d4 = p0;
}

void func_020295b0(void) {
    *(u32 *) ((int) data_02174e1c + 0xd8) = 1;
}

void func_020295a0(void) {
    *(u32 *) ((int) data_02174e1c + 0xd8) = 0;
}

void func_02029590(u32 p0) {
    data_02174e1c->mUnk_cc = p0;
}

void func_02029580(u32 p0) {
    data_02174e1c->mUnk_d0 = p0;
}

void func_02029570(u32 p0) {
    data_02174e1c->mUnk_c0 = p0;
}

void func_02029560(u32 p0) {
    data_02174e1c->mUnk_f0 = p0;
}

void func_02029550(u16 p0) {
    data_02174e1c->mUnk_e8 = p0;
}

void func_02029540(u32 p0) {
    data_02174e1c->mUnk_ec = p0;
}

void func_02029530(void) {
    *(u32 *) ((int) data_02174e1c + 0xdc) = 1;
}

void func_02029520(void) {
    *(u32 *) ((int) data_02174e1c + 0xdc) = 0;
}

#pragma thumb off
