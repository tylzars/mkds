#include "00/code_0219887c.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"

u16 func_ov000_021988e4(void *a) {
    return *(u16 *) ((u8 *) a + 8);
}

int func_ov000_021988dc(int a) {
    return *(s32 *) (a + 0x54) - *(s32 *) (a + 0x58);
}

u32 func_ov000_021988d8(u32 *a) {
    return *a;
}

void func_ov000_021988d4(int a, u32 b) {
    *(u32 *) (a + 0x30) = b;
    return;
}

void func_ov000_021988a4(Unk0219887c *a, void *b) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x19c);
    }
    a->mUnk_40 = b;
    return;
}

u8 *func_ov000_0219887c(Unk0219887c *object) {
    if (object == NULL) {
        func_0213442c(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x1a3);
    }
    return object->mUnk_40;
}
