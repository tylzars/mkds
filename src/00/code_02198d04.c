#include "00/code_02198d04.h"

#pragma opt_common_subs off

u32 func_ov000_02198fdc(int param_1) {
    int v1;
    int *v2;
    v1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (param_1 + 0x60))));
    if (v1 <= 0) {
        func_0213442c(data_ov000_021b3fb0, data_ov000_021b3fb8, 0, 0x475);
    }
    v2 = (int *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 0x60))), (int) (v1 + -1));
    v1 = func_ov000_02198714((u32 *) ((u32 *) (u32) (param_1)), (u32) (*(int *) (param_1 + 0x50) + *v2), (u32) (v2[1]));
    if (v1 == 0) {
        return 0;
    }
    *(u32 *) (param_1 + 0x90) = 0;
    return 1;
}

u32 func_ov000_02198f80(int param_1, u32 param_2, int param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 0, param_3 + 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_2, param_3);
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198f24(int param_1, u32 param_2) {
    int v1;
    int v2;
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 1, 0x27, &v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2 != 0) {
        return 1;
    }
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_2, 0x20);
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198eb0(int param_1, u32 param_2, u32 param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 2, 0x47, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_2, 0x20);
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_3, 0x20);
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 == 0) {
        return 0;
    }
    *(u32 *) (param_1 + 0x8c) = *(u32 *) (param_1 + 0x88);
    return 1;
}

u32 func_ov000_02198e44(int param_1, u32 param_2, u32 param_3, int param_4) {
    int v1;
    int v2;
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 3, param_4 + 0x27, &v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2 != 0) {
        return 1;
    }
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_2, 0x20);
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_3, param_4);
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198df8(u32 param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 4, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d9c(int param_1, u32 param_2, int param_3) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 5, param_3 + 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    func_ov000_02197d84((int *) (u32) (param_1 + 0x50), param_2, param_3);
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d50(u32 param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 6, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov000_02198d04(u32 param_1) {
    int v1;
    int v2[2];
    v1 = func_ov000_0219903c((Unk02197fe8 *) param_1, 7, 7, v2);
    if (v1 == 0) {
        return 0;
    }
    if (v2[0] != 0) {
        return 1;
    }
    v1 = func_ov000_02198fdc((int) (param_1));
    if (v1 != 0) {
        return 1;
    }
    return 0;
}
