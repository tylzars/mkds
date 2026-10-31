#include "00/code_0218d180.h"

void func_ov000_0218d1a0(u32 param_1) {
    int v1;
    u32 *v2;
    int v3;
    v1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (param_1 + 4))));
    v3 = 0;
    if (0 < v1) {
        do {
            v2 = (u32 *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), v3);
            func_ov000_0218d278((Unk021b4d24 *) param_1, (u32) (*v2));
            v3 = v3 + 1;
        } while (v3 < v1);
    }
    func_ov000_0218d8b4((int *) (*(u32 *) (param_1 + 4)));
    func_ov000_0218d1dc((Unk021b4d24 *) param_1);
}

void func_ov000_0218d180(u32 p0) {
    u32 v1 = ((p0) + (0x0u));
    u32 v5 = (u32) func_ov000_0218dc94((u32) 0x4u, (u32) 0x64u, (u32) 0x0u);
    u32 v8;
    *(u32 *) ((v1) + (4)) = v5;
    v8 = 0x5d0u;
    *(u32 *) ((v1) + (0 + (v8))) = (u32) 0x0u;
}
