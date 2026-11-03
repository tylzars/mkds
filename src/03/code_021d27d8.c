#include "03/code_021d27d8.h"

#include "code_0200c914.h"
#include "code_0200fd1c.h"
#include "code_020176c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov003_021d28b0(void *buffer) {
    func_0214d168(buffer, 0, 0x40000);
    data_ov003_021da2c8 = func_02017988(buffer, 0x40000, 0);
    if (data_ov003_021da2c8 == NULL) {
        func_0200fd1c();
    }
}

void func_ov003_021d2894(void) {
    func_0201797c(&data_ov003_021da2c8->mUnk_00);
    data_ov003_021da2c8 = NULL;
}

void *func_ov003_021d285c(u32 size, s32 alignment) {
    u32 interrupts = func_0200ca9c(1);
    void *block = func_02017938(data_ov003_021da2c8, size, alignment);

    if (block == NULL) {
        func_0200fd1c();
    }
    func_0200cae4(interrupts);
    return block;
}

void *func_ov003_021d283c(u32 size, s32 alignment) {
    void *block = func_ov003_021d285c(size, alignment);

    func_0214d168(block, 0, size);
    return block;
}

void func_ov003_021d2808(void *storage) {
    void **block = storage;
    u32 interrupts = func_0200ca9c(1);

    if (*block != NULL) {
        func_02017770(data_ov003_021da2c8, *block);
        func_0200cae4(interrupts);
        *block = NULL;
    }
}

void func_ov003_021d27d8(void *block) {
    u32 interrupts = func_0200ca9c(1);

    if (block != NULL) {
        func_02017770(data_ov003_021da2c8, block);
        func_0200cae4(interrupts);
    }
}
