#include "00/code_021ab548.h"

void func_ov000_021ab594(u32 param_1, u32 param_2) {
    int v1;
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if ((v1 != 0) && (v1 = *(int *) (v1 + 0xc), v1 != 0)) {
        *(u32 *) (v1 + 0x7e8) = param_1;
        *(u32 *) (v1 + 0x7ec) = param_2;
    }
}

u32 func_ov000_021ab548(int param_1, u32 param_2) {
    int v1;
    int v2;
    u32 *v3;
    u32 *v4;
    int v5;
    v2 = 0;
    v1 = *(int *) (param_1 + 0x7ec);
    if (0 < v1) {
        v4 = *(u32 **) (param_1 + 0x7e8);
        v3 = v4;
        do {
            v5 = func_0213a074((const u8 *) (*(u32 *) *v3), (const u8 *) param_2);
            if (v5 == 0) {
                return v4[v2];
            }
            v3 = v3 + 1;
            v2 = v2 + 1;
        } while (v2 < v1);
    }
    return 0;
}
