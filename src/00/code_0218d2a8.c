#include "00/code_0218d2a8.h"

int func_ov000_0218d300(u32 param_1, int param_2) {
    int v1;
    int *v2;
    int v3;
    v1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (param_1 + 4))));
    v3 = 0;
    if (0 < v1) {
        do {
            v2 = (int *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), (int) (v3));
            if (param_2 == *v2) {
                return v3;
            }
            v3 = v3 + 1;
        } while (v3 < v1);
    }
    return -1;
}

int func_ov000_0218d2a8(int param_1, int param_2, int param_3) {
    u32 v1;
    int v2;
    int v3;
    u32 *v4;
    int v5;
    v5 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (4 + param_1))));
    v2 = 0;
    if (0 < v5) {
        do {
            v4 = (u32 *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), (int) (v2));
            v1 = *v4;
            v3 = func_ov000_0218b27c((u32 *) ((u32 *) (u32) (v1)));
            if ((param_2 == v3) && (v3 = func_ov000_0218b25c((int) (v1)), param_3 == v3)) {
                return v2;
            }
            v2 = v2 + 1;
        } while (v2 < v5);
    }
    return -1;
}
