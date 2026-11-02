#include "00/code_0218a918.h"

void func_ov000_0218a98c(u32 a) {
    u32 v1;
    while ((*(s32 *) (a + 0x10) < *(s32 *) (a + 4) && (0 < *(s32 *) (a + 0x1c)))) {
        v1 = func_ov000_0218aea4((s32 *) (u32) (a + 0x14));
        func_ov000_0218ad44((Unk0218a9bc *) (a), (Unk0218af28 *) (v1));
    }
    return;
}

void func_ov000_0218a950(int a) {
    if (*(s32 *) (a + 0x10) != 0) {
        func_ov000_0218aa14((Unk0218a9bc *) (a), 0);
        func_ov000_0218a9bc((Unk0218a9bc *) (a));
        if (0 < *(s32 *) (a + 0x1c)) {
            func_ov000_0218a98c((u32) (a));
        }
        if (*(s32 *) (a + 0x10) == 0) {
            (**(UnkFunc **) (a + 0x44))(a, 2, 0, *(u32 *) (a + 0x48));
        }
    }
    return;
}

void func_ov000_0218a93c(u32 a, u8 b) {
    int v1;
    v1 = *(s32 *) (a + 0x40);
    if (v1 < 0x14) {
        *(s32 *) (a + 0x40) = v1 + 1;
        *(u8 *) (a + v1 + 0x2c) = b;
    }
    return;
}

void func_ov000_0218a918(int a, u32 b) {
    int v1;
    v1 = func_ov000_0218ae68((Unk0218ae68 *) (a + 8), (Unk0218af28 *) b);
    if (v1 == 0) {
        func_ov000_0218ae68((Unk0218ae68 *) (u32) (a + 0x14), (Unk0218af28 *) b);
    }
    return;
}
